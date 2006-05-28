/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_conf.c: Configuration file functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#include "stdinc.h"
#include "balloc.h"
#include "ircd_defs.h"
#include "tools.h"
#include "s_conf.h"
#include "s_serv.h"
#include "resv.h"
#include "s_stats.h"
#include "channel.h"
#include "client.h"
#include "cluster.h"
#include "common.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "s_bsd.h"
#include "irc_getnameinfo.h"
#include "irc_getaddrinfo.h"
#include "ircd.h"
#include "list.h"
#include "listener.h"
#include "hostmask.h"
#include "modules.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_log.h"
#include "send.h"
#include "s_gline.h"
#include "fileio.h"
#include "memory.h"
#include "irc_res.h"
#include "userhost.h"

struct config_server_hide ConfigServerHide;

/* general conf items link list root, other than k lines etc. */
dlink_list server_items  = { NULL, NULL, 0 };
dlink_list cluster_items = { NULL, NULL, 0 };
dlink_list hub_items     = { NULL, NULL, 0 };
dlink_list leaf_items    = { NULL, NULL, 0 };
dlink_list oconf_items   = { NULL, NULL, 0 };
dlink_list uconf_items   = { NULL, NULL, 0 };
dlink_list xconf_items   = { NULL, NULL, 0 };
dlink_list nresv_items   = { NULL, NULL, 0 };
dlink_list class_items   = { NULL, NULL, 0 };
dlink_list gline_items   = { NULL, NULL, 0 };

dlink_list temporary_klines = { NULL, NULL, 0 };
dlink_list temporary_dlines = { NULL, NULL, 0 };
dlink_list temporary_ip_klines = { NULL, NULL, 0 };

extern int yyparse(); /* defined in y.tab.c */
extern int lineno;
extern char linebuf[];
extern char conffilebuf[IRCD_BUFSIZE];
int scount = 0; /* used by yyparse(), etc */
int ypass  = 1; /* used by yyparse()      */

/* internally defined functions */
static void lookup_confhost(struct ConfItem *aconf);
static void set_default_conf(void);
static void validate_conf(void);
static void read_conf(FBFILE *);
static void clear_out_old_conf(void);
static void flush_deleted_I_P(void);
static void expire_tklines(dlink_list *);
static void garbage_collect_ip_entries(void);
static int hash_ip(struct irc_ssaddr *);
static int verify_access(struct Client *client_p, const char *username);
static int attach_iline(struct Client *, struct ConfItem *conf);
static struct ip_entry *find_or_add_ip(struct irc_ssaddr *);
static void parse_conf_file(int type, int cold);
static dlink_list *map_to_list(ConfType conf);

FBFILE *conf_fbfile_in;
extern char yytext[];

/* address of default class conf */
static struct ConfItem *class_default;

/* usually, with hash tables, you use a prime number...
 * but in this case I am dealing with ip addresses,
 * not ascii strings.
 */
#define IP_HASH_SIZE 0x1000

struct ip_entry
{
  struct irc_ssaddr ip;
  int count;
  time_t last_attempt;
  struct ip_entry *next;
};

static struct ip_entry *ip_hash_table[IP_HASH_SIZE];
static BlockHeap *ip_entry_heap = NULL;
static int ip_entries_count = 0;


/* conf_dns_callback()
 *
 * inputs	- pointer to struct AccessItem
 *		- pointer to DNSReply reply
 * output	- none
 * side effects	- called when resolver query finishes
 * if the query resulted in a successful search, hp will contain
 * a non-null pointer, otherwise hp will be null.
 * if successful save hp in the conf item it was called with
 */
static void
conf_dns_callback(void *vptr, struct DNSReply *reply)
{
  struct AccessItem *aconf = (struct AccessItem *)vptr;

  if (reply != NULL)
    memcpy(&aconf->ipnum, &reply->addr, sizeof(reply->addr));

  aconf->dns_query = NULL;
}

/* conf_dns_lookup()
 *
 * do a nameserver lookup of the conf host
 * if the conf entry is currently doing a ns lookup do nothing, otherwise
 * allocate a dns_query and start ns lookup.
 */
static void
conf_dns_lookup(struct AccessItem *aconf)
{
  if (aconf->dns_query == NULL)
  {
    aconf->dns_query = MyMalloc(sizeof(struct DNSQuery));
    aconf->dns_query->ptr = aconf;
    aconf->dns_query->callback = conf_dns_callback;
    gethost_byname(aconf->host, aconf->dns_query);
  }
}

inline void *
map_to_conf(struct ConfItem *aconf)
{
  void *conf;
  conf = (void *)((unsigned long)aconf +
		  (unsigned long)sizeof(struct ConfItem));
  return(conf);
}

inline struct ConfItem *
unmap_conf_item(void *aconf)
{
  struct ConfItem *conf;

  conf = (struct ConfItem *)((unsigned long)aconf -
			     (unsigned long)sizeof(struct ConfItem));
  return(conf);
}

/* make_conf_item()
 *
 * inputs	- type of item
 * output	- pointer to new conf entry
 * side effects	- none
 */
struct ConfItem *
make_conf_item(ConfType type)
{
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct ClassItem *aclass;
  int status = 0;

  switch(type)
  {
  case DLINE_TYPE:
  case EXEMPTDLINE_TYPE:
  case GLINE_TYPE:
  case KLINE_TYPE:
  case CLIENT_TYPE:
  case OPER_TYPE:
  case SERVER_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct AccessItem));
    aconf = (struct AccessItem *)map_to_conf(conf);
    aconf->aftype = AF_INET;

    /* Yes, sigh. switch on type again */
    switch(type)
    {
    case EXEMPTDLINE_TYPE:
      status = CONF_EXEMPTDLINE;
      break;

    case DLINE_TYPE:
      status = CONF_DLINE;
      break;

    case GLINE_TYPE:
      status = CONF_KILL;
      dlinkAdd(conf, &conf->node, &gline_items);
      break;

    case KLINE_TYPE:
      status = CONF_KILL;
      break;

    case CLIENT_TYPE:
      status = CONF_CLIENT;
      break;

    case OPER_TYPE:
      status = CONF_OPERATOR;
      dlinkAdd(conf, &conf->node, &oconf_items);
      break;

    case SERVER_TYPE:
      status = CONF_SERVER;
      dlinkAdd(conf, &conf->node, &server_items);
      break;

    default:
      break;
    }
    aconf->status = status;
    break;

  case LEAF_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &leaf_items);
    break;

  case HUB_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &hub_items);
    break;

  case ULINE_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &uconf_items);
    break;

  case XLINE_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &xconf_items);
    break;

  case CLUSTER_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &cluster_items);
    break;

  case CRESV_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct ResvChannel));
    break;

  case NRESV_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &nresv_items);
    break;

  case CLASS_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct ClassItem));
    dlinkAdd(conf, &conf->node, &class_items);
    aclass = (struct ClassItem *)map_to_conf(conf);
    ConFreq(aclass)  = DEFAULT_CONNECTFREQUENCY;
    PingFreq(aclass) = DEFAULT_PINGFREQUENCY;
    MaxTotal(aclass) = ConfigFileEntry.maximum_links;
    MaxSendq(aclass) = DEFAULT_SENDQ;
    CurrUserCount(aclass) = 0;
    break;

  default:

    conf = NULL;
    break;
  }

  /* XXX Yes, this will core if default is hit. I want it to for now - db */
  conf->type = type;

  return(conf);
}

void
delete_conf_item(struct ConfItem *conf)
{
  struct MatchItem *match_item;
  struct AccessItem *aconf;
  ConfType type = conf->type;

  MyFree(conf->name);

  switch(type)
  {
  case DLINE_TYPE:
  case EXEMPTDLINE_TYPE:
  case KLINE_TYPE:
  case CLIENT_TYPE:
  case OPER_TYPE:
  case SERVER_TYPE:
    aconf = (struct AccessItem *)map_to_conf(conf);
    if (aconf->dns_query != NULL)
      delete_resolver_queries(aconf->dns_query);
    if (aconf->passwd != NULL)
      memset(aconf->passwd, 0, strlen(aconf->passwd));
    if (aconf->spasswd != NULL)
      memset(aconf->spasswd, 0, strlen(aconf->spasswd));
    aconf->class_ptr = NULL;

    MyFree(aconf->passwd);
    MyFree(aconf->spasswd);
    MyFree(aconf->reason);
    MyFree(aconf->oper_reason);
    MyFree(aconf->user);
    MyFree(aconf->host);
    MyFree(aconf->fakename);
#ifdef HAVE_LIBCRYPTO
    if (aconf->rsa_public_key)
      RSA_free(aconf->rsa_public_key);
    MyFree(aconf->rsa_public_key_file);
#endif

    /* Yes, sigh. switch on type again */
    switch(type)
    {
    case EXEMPTDLINE_TYPE:
    case DLINE_TYPE:
    case GLINE_TYPE:
    case KLINE_TYPE:
    case CLIENT_TYPE:
      MyFree(conf);
      break;

    case OPER_TYPE:
      aconf = (struct AccessItem *)map_to_conf(conf);
      if (!IsConfIllegal(aconf))
	dlinkDelete(&conf->node, &oconf_items);
      MyFree(conf);
      break;

    case SERVER_TYPE:
      aconf = (struct AccessItem *)map_to_conf(conf);
      if (!IsConfIllegal(aconf))
	dlinkDelete(&conf->node, &server_items);
      MyFree(conf);
      break;

    default:
      break;
    }
    break;

  case HUB_TYPE:
    match_item = (struct MatchItem *)map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    MyFree(match_item->oper_reason);
    /* If marked illegal, its already been pulled off of the hub_items list */
    if (!match_item->illegal)
      dlinkDelete(&conf->node, &hub_items);
    MyFree(conf);
    break;

  case LEAF_TYPE:
    match_item = (struct MatchItem *)map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    MyFree(match_item->oper_reason);
    /* If marked illegal, its already been pulled off of the leaf_items list */
    if (!match_item->illegal)
      dlinkDelete(&conf->node, &leaf_items);
    MyFree(conf);
    break;

  case ULINE_TYPE:
    match_item = (struct MatchItem *)map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    MyFree(match_item->oper_reason);
    dlinkDelete(&conf->node, &uconf_items);
    MyFree(conf);
    break;

  case XLINE_TYPE:
    match_item = (struct MatchItem *)map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    MyFree(match_item->oper_reason);
    dlinkDelete(&conf->node, &xconf_items);
    MyFree(conf);
    break;

  case NRESV_TYPE:
    match_item = (struct MatchItem *)map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    MyFree(match_item->oper_reason);
    dlinkDelete(&conf->node, &nresv_items);
    MyFree(conf);
    break;

  case CLUSTER_TYPE:
    match_item = (struct MatchItem *)map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    MyFree(match_item->oper_reason);
    dlinkDelete(&conf->node, &cluster_items);
    MyFree(conf);
    break;

  case GLINE_TYPE:
    aconf = (struct AccessItem *)map_to_conf(conf);
    MyFree(aconf->user);
    MyFree(aconf->host);
    MyFree(aconf->reason);
    MyFree(aconf->oper_reason);
    dlinkDelete(&conf->node, &gline_items);
    MyFree(conf);
    break;

  case CRESV_TYPE:
    MyFree(conf);
    break;

  case CLASS_TYPE:
    dlinkDelete(&conf->node, &class_items);
    MyFree(conf);
    break;

  default:
    break;
  }
}

/* free_access_item()
 *
 * inputs	- pointer to conf to free
 * output	- none
 * side effects	- crucial password fields are zeroed, conf is freed
 */
void
free_access_item(struct AccessItem *aconf)
{
  struct ConfItem *conf;

  if (aconf == NULL)
    return;
  conf = unmap_conf_item(aconf);
  delete_conf_item(conf);
}

/* report_confitem_types()
 *
 * inputs	- pointer to client requesting confitem report
 *		- ConfType to report
 * output	- none
 * side effects	-
 */
void
report_confitem_types(struct Client *source_p, ConfType type)
{
  dlink_node *ptr;
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf;
  struct MatchItem *matchitem;
  struct ClassItem *classitem;
  char *host, *reason, *user, *classname;
  int port;

  switch (type)
  {
  case XLINE_TYPE:
    DLINK_FOREACH(ptr, xconf_items.head)
    {
      conf = ptr->data;
      matchitem = (struct MatchItem *)map_to_conf(conf);
      sendto_one(source_p, form_str(RPL_STATSXLINE),
		 me.name, source_p->name, matchitem->action,
		 conf->name, matchitem->reason);
    }
    break;

  case ULINE_TYPE:
    DLINK_FOREACH(ptr, uconf_items.head)
    {
      conf = ptr->data;
      matchitem = (struct MatchItem *)map_to_conf(conf);
      sendto_one(source_p, form_str(RPL_STATSULINE),
		 me.name, source_p->name,
		 conf->name, matchitem->user);
    }
    break;

  case CLUSTER_TYPE:
    DLINK_FOREACH(ptr, cluster_items.head)
    {
      conf = ptr->data;
      matchitem = (struct MatchItem *)map_to_conf(conf);
      sendto_one(source_p, form_str(RPL_STATSULINE),
                 me.name, source_p->name,
                 conf->name, "*"); /* XXX cluster type */
    }
    break;

  case OPER_TYPE:
    DLINK_FOREACH(ptr, oconf_items.head)
    {
      conf = ptr->data;
      aconf = (struct AccessItem *)map_to_conf(conf);
      get_printable_conf(conf, &host, &reason, &user, &port, &classname);

      /* Don't allow non opers to see oper privs */
      if (IsOper(source_p))
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', user, host,
		   conf->name, oper_privs_as_string(port), classname);
      else
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', user, host,
		   conf->name, "0", classname);
    }
    break;

  case CLASS_TYPE:
    DLINK_FOREACH(ptr, class_items.head)
    {
      conf = ptr->data;
      classitem = (struct ClassItem *)map_to_conf(conf);
      sendto_one(source_p, form_str(RPL_STATSYLINE),
		 me.name, source_p->name, 'Y',
		 conf->name, PingFreq(classitem),
		 ConFreq(classitem),
		 MaxTotal(classitem), MaxSendq(classitem));
    }
    break;

  case CONF_TYPE:
  case CLIENT_TYPE:
    break;

  case SERVER_TYPE:
    DLINK_FOREACH(ptr, server_items.head)
    {
      char buf[20];
      char *s = buf;

      conf = ptr->data;
      aconf = (struct AccessItem *)map_to_conf(conf);
      get_printable_conf(conf, &host, &reason, &user, &port, &classname);

      buf[0] = '\0';

      if (IsConfAllowAutoConn(aconf))
	*s++ = 'A';
      if (IsConfCryptLink(aconf))
	*s++ = 'C';
      if (IsConfLazyLink(aconf))
	*s++ = 'L';
      if (IsConfCompressed(aconf))
	*s++ = 'Z';
      if (aconf->fakename)
	*s++ = 'M';
      if (buf[0] == '\0')
	*s++ = '*';

      *s++ = '\0';

      /* Allow admins to see actual ips
       * unless hide_server_ips is enabled
       */
      if (!ConfigServerHide.hide_server_ips && IsAdmin(source_p))
	sendto_one(source_p, form_str(RPL_STATSCLINE),
		   me.name, source_p->name, 'C', host,
		   buf, conf->name, port, classname);
        else
          sendto_one(source_p, form_str(RPL_STATSCLINE),
                     me.name, source_p->name, 'C',
		     "*@127.0.0.1", buf, conf->name, port, classname);
    }
    break;

  case HUB_TYPE:
    DLINK_FOREACH(ptr, hub_items.head)
    {
      conf = ptr->data;
      matchitem = (struct MatchItem *)map_to_conf(conf);
      sendto_one(source_p, form_str(RPL_STATSHLINE), me.name,
		 source_p->name, 'H', matchitem->host, conf->name, 0, "*");
    }
    break;

  case LEAF_TYPE:
    DLINK_FOREACH(ptr, leaf_items.head)
    {
      conf = ptr->data;
      matchitem = (struct MatchItem *)map_to_conf(conf);
      sendto_one(source_p, form_str(RPL_STATSLLINE), me.name,
		 source_p->name, 'L', matchitem->host, conf->name, 0, "*");
    }
    break;

  case KLINE_TYPE:
  case DLINE_TYPE:
  case EXEMPTDLINE_TYPE:
  case GLINE_TYPE:
  case CRESV_TYPE:
  case NRESV_TYPE:
    break;
  }
}

/* check_client()
 *
 * inputs	- pointer to client
 * output	- 0 = Success
 * 		  NOT_AUTHORIZED    (-1) = Access denied (no I line match)
 * 		  IRCD_SOCKET_ERROR (-2) = Bad socket.
 * 		  I_LINE_FULL       (-3) = I-line is full
 *		  TOO_MANY          (-4) = Too many connections from hostname
 * 		  BANNED_CLIENT     (-5) = K-lined
 * side effects - Ordinary client access check.
 *		  Look for conf lines which have the same
 * 		  status as the flags passed.
 */
int
check_client(struct Client *client_p, struct Client *source_p, const char *username)
{
  int i;
 
  ClearAccess(source_p);

  /* I'm already in big trouble if source_p->localClient is NULL -db */
  if ((i = verify_access(source_p, username)))
  {
    ilog(L_INFO, "Access denied: %s[%s]", 
         source_p->name, source_p->localClient->sockhost);
  }

  switch (i)
  {
    case IRCD_SOCKET_ERROR:
      exit_client(client_p, source_p, &me, "Socket Error");
      break;

    case TOO_MANY:
      sendto_gnotice_flags(UMODE_FULL, L_ALL, me.name, &me, NULL,
                           "Too many on IP for %s (%s).",
			   get_client_name(source_p, SHOW_IP),
			   source_p->localClient->sockhost);
      ilog(L_INFO,"Too many connections on IP from %s.",
	   get_client_name(source_p, SHOW_IP));
      ServerStats->is_ref++;
      exit_client(client_p, source_p, &me, 
			"No more connections allowed on that IP");
      break;

    case I_LINE_FULL:
      sendto_gnotice_flags(UMODE_FULL, L_ALL, me.name, &me, NULL,
                           "I-line is full for %s (%s).",
			   get_client_name(source_p, SHOW_IP),
			   source_p->localClient->sockhost);
      ilog(L_INFO,"Too many connections from %s.",
	   get_client_name(source_p, SHOW_IP));
       ServerStats->is_ref++;
      exit_client(client_p, source_p, &me, 
		"No more connections allowed in your connection class");
      break;

    case NOT_AUTHORIZED:
    {
      static char ipaddr[HOSTIPLEN];
      ServerStats->is_ref++;
      /* jdc - lists server name & port connections are on */
      /*       a purely cosmetical change */
      irc_getnameinfo((struct sockaddr*)&source_p->localClient->ip,
            source_p->localClient->ip.ss_len, ipaddr, HOSTIPLEN, NULL, 0,
            NI_NUMERICHOST);
      sendto_gnotice_flags(UMODE_UNAUTH, L_ALL, me.name, &me, NULL,
			   "Unauthorized client connection from %s [%s] on [%s/%u].",
			   get_client_name(source_p, SHOW_IP),
			   ipaddr,
			   source_p->localClient->listener->name,
			   source_p->localClient->listener->port);
      ilog(L_INFO,
	  "Unauthorized client connection from %s on [%s/%u].",
	  get_client_name(source_p, SHOW_IP),
	  source_p->localClient->listener->name,
	  source_p->localClient->listener->port);
      exit_client(client_p, source_p, &me,
		  "You are not authorized to use this server");
      break;
    }
 
   case BANNED_CLIENT:
      exit_client(client_p, source_p, &me, "*** Banned ");
      ServerStats->is_ref++;
      break;

   case 0:
   default:
     break;
  }

  return(i);
}

/* verify_access()
 *
 * inputs	- pointer to client to verify
 *		- pointer to proposed username
 * output	- 0 if success -'ve if not
 * side effect	- find the first (best) I line to attach.
 */
static int
verify_access(struct Client *client_p, const char *username)
{
  struct AccessItem *aconf;
  struct ConfItem *conf;
  struct AccessItem *gkill_conf;
  char non_ident[USERLEN + 1];

  if (IsGotId(client_p))
  {
    aconf = find_address_conf(client_p->host, client_p->username,
			     &client_p->localClient->ip,
			     client_p->localClient->aftype,
                             client_p->localClient->passwd);
  }
  else
  {
    strlcpy(non_ident, "~", sizeof(non_ident));
    strlcat(non_ident, username, sizeof(non_ident));
    aconf = find_address_conf(client_p->host,non_ident,
			     &client_p->localClient->ip,
			     client_p->localClient->aftype,
	                     client_p->localClient->passwd);
  }
  
  if (aconf != NULL)
  {
    if (IsConfClient(aconf))
    {
      conf = unmap_conf_item(aconf);

      if (IsConfRedir(aconf))
      {
        sendto_one(client_p, form_str(RPL_REDIR),
                   me.name, client_p->name,
                   conf->name ? conf->name : "",
                   aconf->port);
        return(NOT_AUTHORIZED);
      }

      if (ConfigFileEntry.glines)
      {
	if (!IsConfExemptKline(aconf) && !IsConfExemptGline(aconf))
	{
	  if (IsGotId(client_p))
	    gkill_conf = find_gkill(client_p, client_p->username);
	  else
	    gkill_conf = find_gkill(client_p, non_ident);
	  
	  if (gkill_conf != NULL)
	  {
	    sendto_one(client_p, ":%s NOTICE %s :*** G-lined", me.name,
		       client_p->name);
	    sendto_one(client_p, ":%s NOTICE %s :*** Banned %s",
		       me.name, client_p->name, 
		       gkill_conf->passwd);
	    return(BANNED_CLIENT);
	  }
	}
      }

      if (IsConfDoIdentd(aconf))
	SetNeedId(client_p);
      if (IsConfRestricted(aconf))
	SetRestricted(client_p);

      /* Thanks for spoof idea amm */
      if (IsConfDoSpoofIp(aconf))
      {
	conf = unmap_conf_item(aconf);

        if (ConfigFileEntry.hide_spoof_ips && IsConfSpoofNotice(aconf))
          sendto_gnotice_flags(UMODE_ALL, L_ADMIN, me.name, &me, NULL, "%s spoofing: %s as %s",
                               client_p->name, client_p->host, conf->name);
        strlcpy(client_p->host, conf->name, sizeof(client_p->host));
        SetIPSpoof(client_p);
      }

      return(attach_iline(client_p, conf));
    }
    else if (IsConfKill(aconf))
    {
      if (ConfigFileEntry.kline_with_reason)
        sendto_one(client_p, ":%s NOTICE %s :*** Banned %s", 
                  me.name, client_p->name, aconf->reason);
      return(BANNED_CLIENT);
    }
  }

  return(NOT_AUTHORIZED);
}

/* attach_iline()
 *
 * inputs	- client pointer
 *		- conf pointer
 * output	-
 * side effects	- do actual attach
 */
static int
attach_iline(struct Client *client_p, struct ConfItem *conf)
{
  struct AccessItem *aconf;
  struct ClassItem *aclass;
  struct ip_entry *ip_found;
  int a_limit_reached = 0;
  int max_limit_reached = 0;
  int local;
  int global;
  int ident;

  ip_found = find_or_add_ip(&client_p->localClient->ip);

  SetIpHash(client_p);
  ip_found->count++;

  aconf = (struct AccessItem *)map_to_conf(conf);
  /* only check it if its non zero */
  if (aconf->class_ptr != NULL)
  {
    aclass = (struct ClassItem *)map_to_conf(aconf->class_ptr);

    count_user_host(client_p->username, client_p->host,
		    &global, &local, &ident);

    /* XXX blah. go down checking the various silly limits
     * setting a_limit_reached if any limit is reached.
     * - Dianora
     */
    if ((MaxTotal(aclass) != 0) &&
	(CurrUserCount(aclass) > MaxTotal(aclass)))
      {
	max_limit_reached = 1;
	a_limit_reached = 1;
      }
    if ((MaxPerIp(aclass) != 0) && (ip_found->count > MaxPerIp(aclass)))
      a_limit_reached = 1;
    else if ((MaxLocal(aclass) != 0) && (local > MaxLocal(aclass)))
      a_limit_reached = 1;
    else if ((MaxGlobal(aclass) != 0) && (global > MaxGlobal(aclass)))
      a_limit_reached = 1;

    /* XXX I am not sure of the logic here. This allows a client onto a server
     * if it is idented, but has not exceed the max ident limit for 
     * this class. But deny if it has exceed the max possible limit
     * for this class. Is this what is wanted? *sigh*
     * - Dianora
     */

    if ((MaxIdent(aclass) != 0) && ((*client_p->username != '~') &&
				    ident < MaxIdent(aclass)) &&
	!max_limit_reached)
      a_limit_reached = 0;

    if (a_limit_reached)
    {
      if (!IsConfExemptLimits(aconf))
	return(TOO_MANY); /* Already at maximum allowed */
      else
      {
	sendto_one(client_p,
		   ":%s NOTICE %s :*** Your connection class is full, "
		   "but you have exceed_limit=yes;", me.name, client_p->name);
      }
    }
  }
  else
    return(NOT_AUTHORIZED);	/* If class is missing, this is best */

  return(attach_conf(client_p, conf));
}

/* init_ip_hash_table()
 *
 * inputs               - NONE
 * output               - NONE
 * side effects         - allocate memory for ip_entry(s)
 *			- clear the ip hash table
 */
void
init_ip_hash_table(void)
{
  ip_entry_heap = BlockHeapCreate(sizeof(struct ip_entry), 2*HARD_FDLIMIT);
  memset((void *)ip_hash_table, 0, sizeof(ip_hash_table));
}

/* find_or_add_ip()
 *
 * inputs       - pointer to struct irc_ssaddr
 * output       - pointer to a struct ip_entry
 * side effects -
 *
 * If the ip # was not found, a new struct ip_entry is created, and the ip
 * count set to 0.
 */
static struct ip_entry *
find_or_add_ip(struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr, *newptr;
  int hash_index = hash_ip(ip_in), res;
  struct sockaddr_in *v4 = (struct sockaddr_in *)ip_in, *ptr_v4;
#ifdef IPV6
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)ip_in, *ptr_v6;
#endif

  for (ptr = ip_hash_table[hash_index]; ptr; ptr = ptr->next)
  {
#ifdef IPV6
    if (ptr->ip.ss.ss_family != ip_in->ss.ss_family)
      continue;
    if (ip_in->ss.ss_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&ptr->ip;
      res = memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr));
    }
    else
#endif
    {
      ptr_v4 = (struct sockaddr_in *)&ptr->ip;
      res = memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr));
    }
    if (res == 0)
    {
      /* Found entry already in hash, return it. */
      return(ptr);
    }
  }

  if (ip_entries_count >= (2*HARD_FDLIMIT))
    garbage_collect_ip_entries();

  newptr = BlockHeapAlloc(ip_entry_heap);
  ip_entries_count++;
  memcpy(&newptr->ip, ip_in, sizeof(struct irc_ssaddr));
  newptr->count = 0;
  newptr->last_attempt = 0;

  if ((ptr = ip_hash_table[hash_index]) != NULL)
    newptr->next = ptr;
  else
    newptr->next = NULL;

  ip_hash_table[hash_index] = newptr;
  return(newptr);
}

/* remove_one_ip()
 *
 * inputs        - unsigned long IP address value
 * output        - NONE
 * side effects  - The ip address given, is looked up in ip hash table
 *                 and number of ip#'s for that ip decremented.
 *                 If ip # count reaches 0 and has expired,
 *		   the struct ip_entry is returned to the ip_entry_heap
 */
void
remove_one_ip(struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr;
  struct ip_entry *last_ptr = NULL;
  int hash_index = hash_ip(ip_in), res;
  struct sockaddr_in *v4 = (struct sockaddr_in *)ip_in, *ptr_v4;
#ifdef IPV6
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)ip_in, *ptr_v6;
#endif

  for (ptr = ip_hash_table[hash_index]; ptr; ptr = ptr->next)
  {
#ifdef IPV6
    if (ptr->ip.ss.ss_family != ip_in->ss.ss_family)
      continue;
    if (ip_in->ss.ss_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&ptr->ip;
      res = memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr));
    }
    else
#endif
    {
      ptr_v4 = (struct sockaddr_in *)&ptr->ip;
      res = memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr));
    }
    if (res)
      continue;
    if (ptr->count > 0)
      ptr->count--;
    if (ptr->count == 0 &&
	(CurrentTime-ptr->last_attempt) >= ConfigFileEntry.throttle_time)
    {
      if (last_ptr != NULL)
	last_ptr->next = ptr->next;
      else
	ip_hash_table[hash_index] = ptr->next;

      BlockHeapFree(ip_entry_heap, ptr);
      ip_entries_count--;
      return;
    }
    last_ptr = ptr;
  }
}

/* hash_ip()
 *
 * input        - pointer to an irc_inaddr
 * output       - integer value used as index into hash table
 * side effects - hopefully, none
 */
static int
hash_ip(struct irc_ssaddr *addr)
{
  if (addr->ss.ss_family == AF_INET)
  {
    struct sockaddr_in *v4 = (struct sockaddr_in *)addr;
    int hash;
    u_int32_t ip;

    ip   = ntohl(v4->sin_addr.s_addr);
    hash = ((ip >> 12) + ip) & (IP_HASH_SIZE-1);
    return(hash);
  }
#ifdef IPV6
  else
  {
    int hash;
    struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)addr;
    u_int32_t *ip = (u_int32_t *)&v6->sin6_addr.s6_addr;

    hash  = ip[0] ^ ip[3];
    hash ^= hash >> 16;  
    hash ^= hash >> 8;   
    hash  = hash & (IP_HASH_SIZE - 1);
    return(hash);
  }
#else
  return(0);
#endif
}

/* count_ip_hash()
 *
 * inputs        - pointer to counter of number of ips hashed 
 *               - pointer to memory used for ip hash
 * output        - returned via pointers input
 * side effects  - NONE
 *
 * number of hashed ip #'s is counted up, plus the amount of memory
 * used in the hash.
 */
void
count_ip_hash(int *number_ips_stored, unsigned long *mem_ips_stored)
{
  struct ip_entry *ptr;
  int i;

  *number_ips_stored = 0;
  *mem_ips_stored    = 0;

  for (i = 0; i < IP_HASH_SIZE; i++)
  {
    for (ptr = ip_hash_table[i]; ptr; ptr = ptr->next)
    {
      *number_ips_stored += 1;
      *mem_ips_stored += sizeof(struct ip_entry);
    }
  }
}

/* garbage_collect_ip_entries()
 *
 * input	- NONE
 * output	- NONE
 * side effects	- free up all ip entries with no connections
 */
static void
garbage_collect_ip_entries(void)
{
  struct ip_entry *ptr;
  struct ip_entry *last_ptr;
  struct ip_entry *next_ptr;
  int i;

  for (i = 0; i < IP_HASH_SIZE; i++)
  {
    last_ptr = NULL;

    for (ptr = ip_hash_table[i]; ptr; ptr = next_ptr)
    {
      next_ptr = ptr->next;

      if (ptr->count == 0)
      {
	if (last_ptr != NULL)
	  last_ptr->next = ptr->next;
	else
	  ip_hash_table[i] = ptr->next;
	BlockHeapFree(ip_entry_heap, ptr);
	ip_entries_count--;
      }
      else
	last_ptr = ptr;
    }
  }
}

#if 0
/*
 * iphash_stats()
 *
 * input	- 
 * output	-
 * side effects	-
 */
void 
iphash_stats(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[], FBFILE *out)
{
  struct ip_entry *ptr;
  int i;
  int collision_count;
  char result_buf[256];

  if (out == NULL)
    sendto_one(source_p,":%s NOTICE %s :*** hash stats for iphash",
               me.name,client_p->name);
  else
  {
    (void)sprintf(result_buf,"*** hash stats for iphash\n");
    (void)fbputs(result_buf,out);
  }

  for(i = 0; i < IP_HASH_SIZE ;i++)
  {
    collision_count = 0;
    for (ptr = ip_hash_table[i]; ptr; ptr = ptr->next)
      collision_count++;

    if (collision_count != 0)
    {
      if (out == NULL)
      {
	sendto_one(source_p,":%s NOTICE %s :Entry %d (0x%X) Collisions %d",
		   me.name,client_p->name,i,i,collision_count);
      }
      else
      {
	(void)sprintf(result_buf,"Entry %d (0x%X) Collisions %d\n",
		      i,i,collision_count);
	(void)fbputs(result_buf,out);
      }
    }
  }
}
#endif

/* detach_conf()
 *
 * inputs	- pointer to client to detach
 *		- type of conf to detach
 * output	- 0 for success, -1 for failure
 * side effects	- Disassociate configuration from the client.
 *		  Also removes a class from the list if marked for deleting.
 */
int
detach_conf(struct Client *client_p, ConfType type)
{
  dlink_node *ptr;
  struct ConfItem *conf;
  struct ClassItem *aclass;
  struct AccessItem *aconf;
  struct ConfItem *aclass_conf;
  struct MatchItem *match_item;

  DLINK_FOREACH(ptr, client_p->localClient->confs.head)
  {
    conf = ptr->data;

    if (conf->type == type)
    {
      dlinkDelete(&conf->conf_node, &client_p->localClient->confs);

      switch (conf->type)
      {
      case CLIENT_TYPE:
      case OPER_TYPE:
      case SERVER_TYPE:
	aconf = (struct AccessItem *)map_to_conf(conf);

	if ((aclass_conf = ClassPtr(aconf)) != NULL)
	{
	  aclass = (struct ClassItem *)map_to_conf(aclass_conf);
	  if (CurrUserCount(aclass) > 0)
	    aclass->curr_user_count--;

	  if (MaxTotal(aclass) < 0 && CurrUserCount(aclass) <= 0)
	  {
	    delete_conf_item(aclass_conf);
	  }
	}

	/* Please, no ioccc entries - Dianora */
	if (aconf->clients > 0)
	  --aconf->clients;
	if (aconf->clients == 0 && IsConfIllegal(aconf))
	  delete_conf_item(conf);
	break;
      case LEAF_TYPE:
      case HUB_TYPE:
	match_item = (struct MatchItem *)map_to_conf(conf);
	if ((match_item->ref_count == 0) && (match_item->illegal))
	  delete_conf_item(conf);
	break;
      default:
	break;
      }

      return(0);
    }
  }
  return(-1);
}

/* detach_all_confs()
 *
 * inputs	- pointer to client to detach
 * output	- NONE
 * side effects	- Disassociate all configuration from the client.
 *		  Also removes a class from the list if marked for deleting.
 */
void
detach_all_confs(struct Client *client_p)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct ClassItem *aclass;
  struct AccessItem *aconf;
  struct ConfItem *aclass_conf;
  struct MatchItem *match_item;

  DLINK_FOREACH_SAFE(ptr, next_ptr, client_p->localClient->confs.head)
  {
    conf = ptr->data;

    dlinkDelete(&conf->conf_node, &client_p->localClient->confs);

    switch(conf->type)
    {
    case CLIENT_TYPE:
    case OPER_TYPE:
    case SERVER_TYPE:
      aconf = (struct AccessItem *)map_to_conf(conf);

      if ((aclass_conf = ClassPtr(aconf)) != NULL)
      {
	aclass = (struct ClassItem *)map_to_conf(aclass_conf);
	if (CurrUserCount(aclass) > 0)
	  aclass->curr_user_count--;

	if (MaxTotal(aclass) < 0 && CurrUserCount(aclass) <= 0)
	{
	  delete_conf_item(aclass_conf);
	}
      }

      /* Please, no ioccc entries - Dianora */
      if (aconf->clients > 0)
	--aconf->clients;
      if (aconf->clients == 0 && IsConfIllegal(aconf))
	delete_conf_item(conf);
      break;
    case LEAF_TYPE:
    case HUB_TYPE:
      match_item = (struct MatchItem *)map_to_conf(conf);
      if ((match_item->ref_count == 0) && (match_item->illegal))
	delete_conf_item(conf);
      break;
    default:
      break;
    }
  }
}

/* attach_conf()
 *
 * inputs	- client pointer
 * 		- conf pointer
 * output	-
 * side effects - Associate a specific configuration entry to a *local*
 *                client (this is the one which used in accepting the
 *                connection). Note, that this automatically changes the
 *                attachment if there was an old one...
 */
int
attach_conf(struct Client *client_p, struct ConfItem *conf)
{
  struct AccessItem *aconf;
  struct MatchItem *match_item;

  if (dlinkFind(&client_p->localClient->confs, conf) != NULL)
    return(1);

  if ((conf->type == CLIENT_TYPE) ||
      (conf->type == SERVER_TYPE) ||
      (conf->type == OPER_TYPE))
  {
    struct ClassItem *aclass;

    aconf = (struct AccessItem *)map_to_conf(conf);

    if (IsConfIllegal(aconf))
      return(NOT_AUTHORIZED);

    aclass = (struct ClassItem *)map_to_conf(aconf->class_ptr);

    if (MaxTotal(aclass) > 0)
    {
      if (CurrUserCount(aclass) >= MaxTotal(aclass))
      {
        if (!IsConfExemptLimits(aconf))
          return(I_LINE_FULL); 
        else
        {
          sendto_one(client_p, ":%s NOTICE %s :*** Your connection class is "
              "full, but you have exceed_limit=yes;",
              me.name, client_p->name);
          SetExemptLimits(client_p);
        }
      }
      CurrUserCount(aclass)++;
    }
    else
      return(NOT_AUTHORIZED);

    aconf->clients++;
  } 
  else if ((conf->type == HUB_TYPE) || (conf->type == LEAF_TYPE))
  {   
    match_item = (struct MatchItem *)map_to_conf(conf);
    match_item->ref_count++;
  }

  dlinkAdd(conf, &conf->conf_node, &client_p->localClient->confs);

  return(0);
}

/* attach_connect_block()
 *
 * inputs	- pointer to server to attach
 * 		- name of server
 *		- hostname of server
 * output	- true (1) if both are found, otherwise return false (0)
 * side effects - find connect block and attach them to connecting client
 */
int
attach_connect_block(struct Client *client_p, const char *name,
                     const char *host)
{
  dlink_node *ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;

  assert(client_p != NULL);
  assert(host != NULL);

  if (client_p == NULL || host == NULL)
    return(0);

  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;
    aconf = (struct AccessItem *)map_to_conf(conf);

    if ((match(conf->name, name) == 0) ||
        (match(aconf->host, host) == 0))
      continue;

    attach_conf(client_p, conf);
    return(-1);
  }

  return(0);
}

/* find_conf_exact()
 *
 * inputs	- type of ConfItem
 *		- pointer to name to find
 *		- pointer to username to find
 *		- pointer to host to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the hostname
 *		  and has the same name.
 */
struct ConfItem *
find_conf_exact(ConfType type, const char *name, const char *user, 
                const char *host)
{
  dlink_node *ptr;
  dlink_list *list_p;
  struct ConfItem *conf=NULL;
  struct AccessItem *aconf;

  /* Only valid for OPER_TYPE and ...? */
  list_p = map_to_list(type);

  DLINK_FOREACH(ptr, (*list_p).head)
  {
    conf = ptr->data;

    if (conf->name == NULL)
      continue;
    aconf = (struct AccessItem *)map_to_conf(conf);
    if (aconf->host == NULL)
      continue;
    if (irccmp(conf->name, name) != 0)
      continue;

    /*
    ** Accept if the *real* hostname (usually sockethost)
    ** socket host) matches *either* host or name field
    ** of the configuration.
    */
    if (!match(aconf->host, host) || !match(aconf->user,user)
	|| irccmp(conf->name, name) )
      continue;
    if (type == OPER_TYPE)
    {
      struct ClassItem *aclass;

      aclass = (struct ClassItem *)aconf->class_ptr;
      if (aconf->clients < MaxTotal(aclass))
	return(conf);
      else
	continue;
    }
    else
      return(conf);
  }
  return(NULL);
}

/* find_conf_name()
 *
 * inputs	- pointer to conf link list to search
 *		- pointer to name to find
 *		- int mask of type of conf to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the name
 *		  and has the given mask.
 */
struct ConfItem *
find_conf_name(dlink_list *list, const char *name, ConfType type)
{
  dlink_node *ptr;
  struct ConfItem* conf;

  DLINK_FOREACH(ptr, list->head)
  {
    conf = ptr->data;
    
    if (conf->type == type)
    {
      if (conf->name && (irccmp(conf->name, name) == 0 ||
          match(conf->name, name)))
      return(conf);
    }
  }

  return(NULL);
}

/* map_to_list()
 *
 * inputs	- ConfType conf
 * output	- pointer to dlink_list to use
 * side effects	- none
 */
static dlink_list *
map_to_list(ConfType type)
{
  switch(type)
  {
  case XLINE_TYPE:
    return(&xconf_items);
    break;
  case ULINE_TYPE:
    return(&uconf_items);
    break;
  case NRESV_TYPE:
    return(&nresv_items);
    break;
  case OPER_TYPE:
    return(&oconf_items);
    break;
  case CLASS_TYPE:
    return(&class_items);
    break;
  case SERVER_TYPE:
    return(&server_items);
    break;
  case CLUSTER_TYPE:
    return(&cluster_items);
    break;
  case CONF_TYPE:
  case KLINE_TYPE:
  case DLINE_TYPE:
  case CRESV_TYPE:
  case GLINE_TYPE:
  default:
    return(NULL);
  }
}

/* find_matching_name_conf()
 *
 * inputs       - type of link list to look in
 *		- pointer to name string to find
 *		- pointer to user
 *		- pointer to host
 *		- optional action to match on as well
 * output       - NULL or pointer to found struct MatchItem
 * side effects - looks for a match on name field
 */
struct ConfItem *
find_matching_name_conf(ConfType type, const char *name, const char *user,
                        const char *host, int action)
{
  dlink_node *ptr=NULL;
  struct ConfItem *conf=NULL;
  struct AccessItem *aconf=NULL;
  struct MatchItem *match_item=NULL;
  dlink_list *list_p = map_to_list(type);

  switch (type)
  {
  case XLINE_TYPE:
  case ULINE_TYPE:
  case NRESV_TYPE:
  case CLUSTER_TYPE:

    DLINK_FOREACH(ptr, (*list_p).head)
    {
      conf = ptr->data;

      match_item = map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
      if ((name != NULL) && match_esc(conf->name, name))
      {
	if ((user == NULL && (host == NULL)))
	  return(conf);
	if ((match_item->action & action) != action)
          continue;
	if (EmptyString(match_item->user) || EmptyString(match_item->host))
	  return(conf);
	if (match(match_item->user, user) && match(match_item->host, host))
	  return(conf);
      }
    }
      break;

  case OPER_TYPE:
    DLINK_FOREACH(ptr, (*list_p).head)
    {
      conf = ptr->data;

      if ((name != NULL) && (irccmp(name, conf->name) == 0))
      {
	if ((user == NULL && (host == NULL)))
	  return (conf);

	aconf = map_to_conf(conf);
	if (EmptyString(aconf->user) || EmptyString(aconf->host))
	  return (conf);
	if (match(aconf->user, user) && match(aconf->host, host))
	  return (conf);
      }
    }
    break;

  case SERVER_TYPE:
    DLINK_FOREACH(ptr, (*list_p).head)
    {
      conf = ptr->data;
      aconf = map_to_conf(conf);

      if ((name != NULL) && match_esc(name, conf->name))
        return(conf);
      else if ((host != NULL) && match_esc(host, aconf->host))
        return(conf);
    }
    break;
  
  default:
    break;
  }
  return(NULL);
}

/* find_exact_name_conf()
 *
 * inputs       - type of link list to look in
 *		- pointer to name string to find
 *		- pointer to user
 *		- pointer to host
 * output       - NULL or pointer to found struct MatchItem
 * side effects - looks for an exact match on name field
 */
struct ConfItem *
find_exact_name_conf(ConfType type, 
		     const char *name, const char *user, const char *host)
{
  dlink_node *ptr=NULL;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct MatchItem *match_item;
  struct ClassItem *aclass;
  dlink_list *list_p;

  list_p = map_to_list(type);

  switch(type)
  {
  case XLINE_TYPE:
  case ULINE_TYPE:
  case NRESV_TYPE:

    DLINK_FOREACH(ptr, (*list_p).head)
    {
      conf = ptr->data;
      match_item = (struct MatchItem *)map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
    
      if (irccmp(conf->name, name) == 0)
      {
	if ((user == NULL && (host == NULL)))
	  return (conf);
	if (EmptyString(match_item->user) || EmptyString(match_item->host))
	  return (conf);
	if (match(match_item->user, user) && match(match_item->host, host))
	  return (conf);
      }
    }
    break;

  case OPER_TYPE:
    DLINK_FOREACH(ptr, (*list_p).head)
    {
      conf = ptr->data;
      aconf = (struct AccessItem *)map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
    
      if (irccmp(conf->name, name) == 0)
      {
	if ((user == NULL && (host == NULL)))
	  return (conf);
	if (EmptyString(aconf->user) || EmptyString(aconf->host))
	  return (conf);
	if (match(aconf->user, user) && match(aconf->host, host))
	  return (conf);
      }
    }
    break;

  case SERVER_TYPE:
    DLINK_FOREACH(ptr, (*list_p).head)
    {
      conf = ptr->data;
      aconf = (struct AccessItem *)map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
    
      if (name == NULL)
      {
	if (EmptyString(aconf->host))
	  continue;
	if (irccmp(aconf->host, host) == 0)
	  return(conf);
      }
      else if (irccmp(conf->name, name) == 0)
      {
	  return (conf);
      }
    }
    break;

  case CLASS_TYPE:
    DLINK_FOREACH(ptr, (*list_p).head)
    {
      conf = ptr->data;
      aclass = (struct ClassItem *)map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
    
      if (irccmp(conf->name, name) == 0)
	return (conf);
    }
    break;

  default:
    break;
  }
  return(NULL);
}

/* rehash()
 *
 * Actual REHASH service routine. Called with sig == 0 if it has been called
 * as a result of an operator issuing this command, else assume it has been
 * called as a result of the server receiving a HUP signal.
 */
int
rehash(int sig)
{
  if (sig != 0)
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                         "Got signal SIGHUP, reloading ircd.conf file");

  restart_resolver();
  /* don't close listeners until we know we can go ahead with the rehash */

  /* Check to see if we magically got(or lost) IPv6 support */
  ServerInfo.can_use_v6 = check_can_use_v6();

  read_conf_files(0);

  if (ServerInfo.description != NULL)
    strlcpy(me.info, ServerInfo.description, sizeof(me.info));

  flush_deleted_I_P();

  rehashed_klines = 1;
  rehashed_xlines = 1;

  if (use_logging)
    reopen_log(logFileName);

  return(0);
}

/* set_default_conf()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- Set default values here.
 *		  This is called **PRIOR** to parsing the
 *		  configuration file.  If you want to do some validation
 *		  of values later, put them in validate_conf().
 */
static void
set_default_conf(void)
{
  /* verify init_class() ran, this should be an unnecessary check
   * but its not much work.
   */
  assert(class_default == (struct ConfItem *) class_items.tail->data);

#ifdef HAVE_LIBCRYPTO
  ServerInfo.rsa_private_key = NULL;
  ServerInfo.rsa_private_key_file = NULL;
#endif

  /* ServerInfo.name is not rehashable */
  /* ServerInfo.name = ServerInfo.name; */
  ServerInfo.description = NULL;
  DupString(ServerInfo.network_name, NETWORK_NAME_DEFAULT);
  DupString(ServerInfo.network_desc, NETWORK_DESC_DEFAULT);

  memset(&ServerInfo.ip, 0, sizeof(ServerInfo.ip));
  ServerInfo.specific_ipv4_vhost = 0;
  memset(&ServerInfo.ip6, 0, sizeof(ServerInfo.ip6));
  ServerInfo.specific_ipv6_vhost = 0;

  ServerInfo.max_clients = MAXCONN;
  /* Don't reset hub, as that will break lazylinks */
  /* ServerInfo.hub = NO; */
  ServerInfo.dns_host.sin_addr.s_addr = 0;
  ServerInfo.dns_host.sin_port = 0;
  AdminInfo.name = NULL;
  AdminInfo.email = NULL;
  AdminInfo.description = NULL;

  set_log_level(L_NOTICE);
  use_logging = YES;
  fuserlog[0] = '\0';
  ffailed_operlog[0] = '\0';
  foperlog[0] = '\0';
  
  ConfigChannel.disable_local_channels = NO;
  ConfigChannel.use_invex = YES;
  ConfigChannel.use_except = YES;
  ConfigChannel.use_knock = YES;
  ConfigChannel.knock_delay = 300;
  ConfigChannel.knock_delay_channel = 60;
  ConfigChannel.max_chans_per_user = 15;
  ConfigChannel.quiet_on_ban = YES;
  ConfigChannel.max_bans = 25;
  ConfigChannel.default_split_user_count = 0;
  ConfigChannel.default_split_server_count = 0;
  ConfigChannel.no_join_on_split = NO;
  ConfigChannel.no_create_on_split = NO;

  ConfigServerHide.flatten_links = NO;
  ConfigServerHide.links_delay = 300;
  ConfigServerHide.hidden = NO;
  ConfigServerHide.disable_hidden = NO;
  ConfigServerHide.hide_servers = NO;
  ConfigServerHide.hide_server_ips = NO;

  ConfigFileEntry.hide_spoof_ips = YES;
  ConfigFileEntry.ignore_bogus_ts = NO;
  ConfigFileEntry.disable_auth = NO;
  ConfigFileEntry.disable_remote = NO;
  ConfigFileEntry.default_floodcount = 8; /* XXX */
  ConfigFileEntry.failed_oper_notice = YES;
  ConfigFileEntry.dots_in_ident = 0;      /* XXX */
  ConfigFileEntry.dot_in_ip6_addr = YES;
  ConfigFileEntry.min_nonwildcard = 4;
  ConfigFileEntry.min_nonwildcard_simple = 3;
  ConfigFileEntry.max_accept = 20;
  ConfigFileEntry.anti_nick_flood = NO;   /* XXX */
  ConfigFileEntry.max_nick_time = 20;
  ConfigFileEntry.max_nick_changes = 5;
  ConfigFileEntry.anti_spam_exit_message_time = 0;  /* XXX */
  ConfigFileEntry.ts_warn_delta = TS_WARN_DELTA_DEFAULT;
  ConfigFileEntry.ts_max_delta = TS_MAX_DELTA_DEFAULT;  /* XXX */
  ConfigFileEntry.kline_with_reason = YES;
  ConfigFileEntry.kline_with_connection_closed = NO;
  ConfigFileEntry.warn_no_nline = YES;
  ConfigFileEntry.stats_o_oper_only = NO; /* XXX */
  ConfigFileEntry.stats_k_oper_only = 1;  /* masked */
  ConfigFileEntry.stats_i_oper_only = 1;  /* masked */
  ConfigFileEntry.stats_P_oper_only = NO;
  ConfigFileEntry.caller_id_wait = 60;
  ConfigFileEntry.pace_wait = 10;
  ConfigFileEntry.pace_wait_simple = 1;
  ConfigFileEntry.short_motd = NO;
  ConfigFileEntry.ping_cookie = NO;
  ConfigFileEntry.no_oper_flood = NO;     /* XXX */
  ConfigFileEntry.true_no_oper_flood = NO;  /* XXX */
  ConfigFileEntry.oper_pass_resv = YES;
  ConfigFileEntry.glines = NO;            /* XXX */
  ConfigFileEntry.gline_time = 12 * 3600; /* XXX */
  ConfigFileEntry.idletime = 0;
  ConfigFileEntry.maximum_links = MAXIMUM_LINKS_DEFAULT;
  ConfigFileEntry.max_targets = MAX_TARGETS_DEFAULT;
  ConfigFileEntry.client_flood = CLIENT_FLOOD_DEFAULT;
  ConfigFileEntry.oper_only_umodes = UMODE_DEBUG;  /* XXX */
  ConfigFileEntry.oper_umodes = UMODE_LOCOPS | UMODE_SERVNOTICE |
    UMODE_OPERWALL | UMODE_WALLOP;        /* XXX */
  ConfigFileEntry.crypt_oper_password = YES;
  DupString(ConfigFileEntry.servlink_path, SLPATH);
#ifdef HAVE_LIBCRYPTO
  /* jdc -- This is our default value for a cipher.  According to the
   *        CRYPTLINK document (doc/cryptlink.txt), BF/128 must be supported
   *        under all circumstances if cryptlinks are enabled.  So,
   *        this will be our default.
   *
   *        NOTE: I apologise for the hard-coded value of "1" (BF/128).
   *              This should be moved into a find_cipher() routine.
   */
  ConfigFileEntry.default_cipher_preference = &CipherTable[1];
#endif
  ConfigFileEntry.use_egd = NO;
  ConfigFileEntry.egdpool_path = NULL;
#ifdef HAVE_LIBZ
  ConfigFileEntry.compression_level = 0;
#endif
  ConfigFileEntry.throttle_time = 10;
}

/* read_conf() 
 *
 * inputs       - file descriptor pointing to config file to use
 * output       - None
 * side effects	- Read configuration file.
 */
static void
read_conf(FBFILE *file)
{
  scount = lineno = 0;

  set_default_conf(); /* Set default values prior to conf parsing */
  ypass = 1;
  yyparse();	      /* pick up the classes first */
  (void)fbrewind(file);
  ypass = 2;
  yyparse();          /* Load the values from the conf */
  validate_conf();    /* Check to make sure some values are still okay. */
                      /* Some global values are also loaded here. */
  check_class();      /* Make sure classes are valid */
}

static void
validate_conf(void)
{
  if (ConfigFileEntry.ts_warn_delta < TS_WARN_DELTA_MIN)
    ConfigFileEntry.ts_warn_delta = TS_WARN_DELTA_DEFAULT;

  if (ConfigFileEntry.ts_max_delta < TS_MAX_DELTA_MIN)
    ConfigFileEntry.ts_max_delta = TS_MAX_DELTA_DEFAULT;

  if (ConfigFileEntry.servlink_path == NULL)
    DupString(ConfigFileEntry.servlink_path, SLPATH);

  if (ServerInfo.network_name == NULL)
    DupString(ServerInfo.network_name,NETWORK_NAME_DEFAULT);

  if (ServerInfo.network_desc == NULL)
    DupString(ServerInfo.network_desc,NETWORK_DESC_DEFAULT);

  if ((ConfigFileEntry.client_flood < CLIENT_FLOOD_MIN) ||
      (ConfigFileEntry.client_flood > CLIENT_FLOOD_MAX))
    ConfigFileEntry.client_flood = CLIENT_FLOOD_MAX;

  GlobalSetOptions.idletime = (ConfigFileEntry.idletime * 60);
}

/* split_user_host()
 *
 * inputs	- pointer to original string of form "user@host"
 *		- pointer to new user part
 *		- pointer to new host part
 * output	- NONE
 * side effects - splits user@host found in a name field of conf given
 *		  stuff the user into ->user and the host into ->host
 */
void
split_user_host(char *user_host, char **user_p, char **host_p)
{
  char *p;
  char *new_user;
  char *new_host;

  if ((p = strchr(user_host, '@')) != NULL)
  {
    *p = '\0';
    DupString(new_user, user_host);
    p++;
    DupString(new_host, p);
    MyFree(user_host);
    *user_p = new_user;
    *host_p = new_host;
  }
  else
  {
    DupString(*user_p, "*");
  }
}

/* lookup_confhost()
 *
 * start DNS lookups of all hostnames in the conf
 * line and convert an IP addresses in a.b.c.d number for to IP#s.
 */
static void
lookup_confhost(struct ConfItem *conf)
{
  struct AccessItem *aconf;
  struct addrinfo hints, *res;
  int ret;

  aconf = map_to_conf(conf);

  if (EmptyString(aconf->host) ||
      EmptyString(aconf->user))
  {
    ilog(L_ERROR, "Host/server name error: (%s) (%s)",
         aconf->host, conf->name);
    return;
  }

  if (strchr(aconf->host, '*') ||
      strchr(aconf->host, '?'))
    return;

  /* Do name lookup now on hostnames given and store the
   * ip numbers in conf structure.
   */
  memset(&hints, 0, sizeof(hints));

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  /* Get us ready for a bind() and don't bother doing dns lookup */
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  if ((ret = irc_getaddrinfo(aconf->host, NULL, &hints, &res)))
  {
    conf_dns_lookup(aconf);
    return;
  }

  assert(res != NULL);

  memcpy(&aconf->ipnum, res->ai_addr, res->ai_addrlen);
  aconf->ipnum.ss_len = res->ai_addrlen;
  aconf->ipnum.ss.ss_family = res->ai_family;
  irc_freeaddrinfo(res);
}

/* conf_connect_allowed()
 *
 * inputs	- pointer to inaddr
 *		- int type ipv4 or ipv6
 * output	- BANNED or accepted
 * side effects	- none
 */
int
conf_connect_allowed(struct irc_ssaddr *addr, int aftype)
{
  struct ip_entry *ip_found;
  struct AccessItem *aconf = find_dline_conf(addr, aftype);

  /* DLINE exempt also gets you out of static limits/pacing... */
  if (aconf && (aconf->status & CONF_EXEMPTDLINE))
    return(0);

  if (aconf != NULL)
    return(BANNED_CLIENT);

  ip_found = find_or_add_ip(addr);

  if ((CurrentTime - ip_found->last_attempt) <
      ConfigFileEntry.throttle_time)
  {
    ip_found->last_attempt = CurrentTime;
    return(TOO_FAST);
  }

  ip_found->last_attempt = CurrentTime;
  return(0);
}

/* find_kill()
 *
 * inputs	- pointer to client structure
 * output	- pointer to struct AccessItem if found
 * side effects	- See if this user is klined already,
 *		  and if so, return struct AccessItem pointer
 */
struct AccessItem *
find_kill(struct Client *client_p)
{
  struct AccessItem *aconf;

  assert(client_p != NULL);

  if (client_p == NULL)
    return(NULL);

  aconf = find_kline_conf(client_p->host, client_p->username,
			  &client_p->localClient->ip,
			  client_p->localClient->aftype);
  if (aconf == NULL)
    return(NULL);
  if (aconf->status & CONF_KILL)
    return(aconf);

  return(NULL);
}

/* add_temp_kline()
 *
 * inputs        - pointer to struct AccessItem
 * output        - none
 * Side effects  - links in given struct AccessItem into 
 *                 temporary kline link list
 */
void
add_temp_kline(struct AccessItem *aconf)
{
  dlinkAdd(aconf, make_dlink_node(), &temporary_klines);
  SetConfTemporary(aconf);
  add_conf_by_address(CONF_KILL, aconf);
}

/* add_temp_dline()
 *
 * inputs        - pointer to struct AccessItem
 * output        - none
 * Side effects  - links in given struct AccessItem into 
 *                 temporary dline link list
 */
void
add_temp_dline(struct AccessItem *aconf)
{
  dlinkAdd(aconf, make_dlink_node(), &temporary_dlines);
  SetConfTemporary(aconf);
  /* XXX ensure user is NULL */
  MyFree(aconf->user);
  aconf->user = NULL;
  add_conf_by_address(CONF_DLINE, aconf);
}

/* cleanup_tklines()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - call function to expire temporary k/d lines
 *                This is an event started off in ircd.c
 */
void
cleanup_tklines(void *notused)
{
  expire_tklines(&temporary_klines);
  expire_tklines(&temporary_dlines);
}

/* expire_tklines()
 *
 * inputs       - tkline list pointer
 * output       - NONE
 * side effects - expire tklines
 */
static void
expire_tklines(dlink_list *tklist)
{
  dlink_node *kill_node;
  dlink_node *next_node;
  struct AccessItem *kill_ptr;

  DLINK_FOREACH_SAFE(kill_node, next_node, tklist->head)
  {
    kill_ptr = kill_node->data;

    if (kill_ptr->hold <= CurrentTime)
    {
      /* Alert opers that a TKline expired - Hwy */
      if (kill_ptr->status & CONF_KILL)
      {
	sendto_realops_flags(UMODE_ALL, L_ALL,
			     "Temporary K-line for [%s@%s] expired",
			     (kill_ptr->user) ? kill_ptr->user : "*",
			     (kill_ptr->host) ? kill_ptr->host : "*");
      }
      else
      {
	sendto_realops_flags(UMODE_ALL, L_ALL,
			     "Temporary D-line for [%s] expired",
			     (kill_ptr->host) ? kill_ptr->host : "*");
      }

      delete_one_address_conf(kill_ptr->host, kill_ptr);
      dlinkDelete(kill_node, tklist);
      free_dlink_node(kill_node);
    }
  }
}

/* oper_privs_as_string()
 *
 * inputs        - pointer to client_p
 * output        - pointer to static string showing oper privs
 * side effects  - return as string, the oper privs as derived from port
 */
static const struct oper_privs
{
  const unsigned int oprivs;
  const unsigned int hidden;
  const unsigned char c;
} flag_list[] = {
  { OPER_FLAG_ADMIN,       OPER_FLAG_HIDDEN_ADMIN,  'A' },
  { OPER_FLAG_REMOTEBAN,   0,                       'B' },
  { OPER_FLAG_DIE,         0,                       'D' },
  { OPER_FLAG_GLINE,       0,                       'G' },
  { OPER_FLAG_REHASH,      0,                       'H' },
  { OPER_FLAG_K,           0,                       'K' },
  { OPER_FLAG_OPERWALL,    0,                       'L' },
  { OPER_FLAG_N,           0,                       'N' },
  { OPER_FLAG_GLOBAL_KILL, 0,                       'O' },
  { OPER_FLAG_REMOTE,      0,                       'R' },
  { OPER_FLAG_OPER_SPY,    0,                       'S' },
  { OPER_FLAG_UNKLINE,     0,                       'U' },
  { OPER_FLAG_X,           0,                       'X' },
  { 0, 0, '\0' }
};

char *
oper_privs_as_string(const unsigned int port)
{
  static char privs_out[16];
  char *privs_ptr = privs_out;
  unsigned int i = 0;

  for (; flag_list[i].oprivs; ++i)
  {
    if ((port & flag_list[i].oprivs) &&
        (port & flag_list[i].hidden) == 0)
      *privs_ptr++ = flag_list[i].c;
    else
      *privs_ptr++ = ToLowerTab[flag_list[i].c];
  }

  *privs_ptr = '\0';

  return privs_out;
}

/* const char* get_oper_name(struct Client *client_p)
 * Input: A client to find the active oper{} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
char *
get_oper_name(struct Client *client_p)
{
  dlink_node *cnode;
  struct ConfItem *conf;
  struct AccessItem *aconf;

  /* +5 for !,@,{,} and null */
  static char buffer[NICKLEN+USERLEN+HOSTLEN+HOSTLEN+5];

  if (MyConnect(client_p))
  {
    DLINK_FOREACH(cnode, client_p->localClient->confs.head)
    {
      conf = cnode->data;
      aconf = (struct AccessItem *)map_to_conf(conf);

      if (IsConfOperator(aconf))
      {
	ircsprintf(buffer, "%s!%s@%s{%s}", client_p->name,
		   client_p->username, client_p->host,
		   conf->name);
	return(buffer);
      }
    }

    /* Probably should assert here for now. If there is an oper out there 
     * with no oper{} conf attached, it would be good for us to know...
     */
    assert(0); /* Oper without oper conf! */
  }
  ircsprintf(buffer, "%s!%s@%s{%s}", client_p->name,
	     client_p->username, client_p->host, client_p->servptr->name);
  return(buffer);
}

/* get_printable_conf()
 *
 * inputs        - struct ConfItem
 *
 * output         - host
 *                - reason
 *                - user
 *                - port
 *
 * side effects        -
 * Examine the struct ConfItem *conf, setting the values
 * of host, pass, user to values either
 * in aconf, or "<NULL>" port is set to aconf->port in all cases.
 */
void
get_printable_conf(struct ConfItem *conf, char **host,
		   char **reason, char **user, int *port, char **classname)
{
  struct AccessItem *aconf;
  static char null[] = "<NULL>";
  static char zero[] = "default";

  aconf = (struct AccessItem *)map_to_conf(conf);

  *host = EmptyString(aconf->host) ? null : aconf->host;
  *reason = EmptyString(aconf->reason) ? null : aconf->reason;
  *user = EmptyString(aconf->user) ? null : aconf->user;
  *classname = aconf->class_ptr == NULL ? zero : aconf->class_ptr->name;
  *port = (int)aconf->port;
}

/* read_conf_files()
 *
 * inputs       - cold start YES or NO
 * output       - none
 * side effects - read all conf files needed, ircd.conf kline.conf etc.
 */
void
read_conf_files(int cold)
{
  const char *filename;

  conf_fbfile_in = NULL;

  filename = get_conf_name(CONF_TYPE);

  /* We need to know the initial filename for the yyerror() to report
     FIXME: The full path is in conffilenamebuf first time since we
             dont know anything else

     - Gozem 2002-07-21 
  */
  strlcpy(conffilebuf, filename, sizeof(conffilebuf));

  if ((conf_fbfile_in = fbopen(filename, "r")) == NULL)
  {
    if (cold)
    {
      ilog(L_CRIT, "Failed in reading configuration file %s", filename);
      exit(-1);
    }
    else
    {
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
			   "Can't open file '%s' - aborting rehash!",
			   filename );
      return;
    }
  }

  if (!cold)
    clear_out_old_conf();

  read_conf(conf_fbfile_in);
  fbclose(conf_fbfile_in);

  parse_conf_file(KLINE_TYPE, cold);
  parse_conf_file(DLINE_TYPE, cold);
  parse_conf_file(XLINE_TYPE, cold);
  parse_conf_file(NRESV_TYPE, cold);
  parse_conf_file(CRESV_TYPE, cold);
}

/* parse_conf_file()
 *
 * inputs	- type of conf file to parse 
 * output	- none
 * side effects	- conf file for givenconf type is opened and read then parsed
 */
static void
parse_conf_file(int type, int cold)
{
  const char *filename;
  FBFILE *file;

  filename = get_conf_name(type);

  if ((file = fbopen(filename, "r")) == NULL)
  {
    if (cold)
      ilog(L_ERROR, "Failed reading file %s", filename);
    else
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Can't open %s file ", filename);
  }
  else
  {
    parse_csv_file(file, type);
    fbclose(file);
  }
}

/* clear_out_old_conf()
 *
 * inputs       - none
 * output       - none
 * side effects - Clear out the old configuration
 */
static void
clear_out_old_conf(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct ClassItem *cltmp;
  struct MatchItem *match_item;
  dlink_list * free_items [] = {
    &server_items, &oconf_items, &hub_items, &leaf_items, &uconf_items,
    &xconf_items, &nresv_items, &cluster_items, NULL
  };

  dlink_list ** iterator = free_items; /* C is dumb */

  /* We only need to free anything allocated by yyparse() here.
   * Resetting structs, etc, is taken care of by set_default_conf().
   */
  
  for (; *iterator != NULL; iterator++)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, (*iterator)->head)
    {
      conf = ptr->data;
      /* XXX This is less than pretty */
      if (conf->type == SERVER_TYPE)
      {
	aconf = (struct AccessItem *)map_to_conf(conf);
	if (aconf->clients != 0)
        {
	  SetConfIllegal(aconf);
	  dlinkDelete(&conf->node, &server_items);
	}
	else
	{
	  delete_conf_item(conf);
	}
      }
      else if (conf->type == OPER_TYPE)
      {
	aconf = (struct AccessItem *)map_to_conf(conf);
	if (aconf->clients != 0)
        {
	  SetConfIllegal(aconf);
	  dlinkDelete(&conf->node, &oconf_items);
	}
	else
	{
	  delete_conf_item(conf);
	}
      }
      else if (conf->type == CLIENT_TYPE)
      {
	aconf = (struct AccessItem *)map_to_conf(conf);
	if (aconf->clients != 0)
        {
	  SetConfIllegal(aconf);
	}
	else
	{
	  delete_conf_item(conf);
	}
      }
      else
      {
	if ((conf->type == LEAF_TYPE) || (conf->type == HUB_TYPE))
	{
	  match_item = (struct MatchItem *)map_to_conf(conf);
	  if ((match_item->ref_count <= 0))
	    delete_conf_item(conf);
	  else
	  {
	    match_item->illegal = 1;
	    dlinkDelete(&conf->node, *iterator);
	  }
	}
	else
	  delete_conf_item(conf);
      }
    }
  }

  /* don't delete the class table, rather mark all entries
   * for deletion. The table is cleaned up by check_class. - avalon
   */
  DLINK_FOREACH(ptr, class_items.head)
  {
    conf = ptr->data;
    cltmp = (struct ClassItem *)map_to_conf(conf);
    if (ptr != class_items.tail)  /* never mark the "default" class */
      MaxTotal(cltmp) = -1;
  }

  clear_out_address_conf();

  /* clean out module paths */
#ifndef STATIC_MODULES
  mod_clear_paths();
#endif

  /* clean out ServerInfo */
  MyFree(ServerInfo.description);
  ServerInfo.description = NULL;
  MyFree(ServerInfo.network_name);
  ServerInfo.network_name = NULL;
  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = NULL;
  MyFree(ConfigFileEntry.egdpool_path);
  ConfigFileEntry.egdpool_path = NULL;
#ifdef HAVE_LIBCRYPTO
  if (ServerInfo.rsa_private_key != NULL)
  {
    RSA_free(ServerInfo.rsa_private_key);
    ServerInfo.rsa_private_key = NULL;
  }

  MyFree(ServerInfo.rsa_private_key_file);
  ServerInfo.rsa_private_key_file = NULL;
#endif

  /* clean out old resvs from the conf */
  clear_conf_resv();

  /* clean out AdminInfo */
  MyFree(AdminInfo.name);
  AdminInfo.name = NULL;
  MyFree(AdminInfo.email);
  AdminInfo.email = NULL;
  MyFree(AdminInfo.description);
  AdminInfo.description = NULL;

  /* operator{} and class{} blocks are freed above */
  /* clean out listeners */
  close_listeners();

  /* auth{}, quarantine{}, shared{}, connect{}, kill{}, deny{},
   * exempt{} and gecos{} blocks are freed above too
   */

  /* clean out general */
  MyFree(ConfigFileEntry.servlink_path);
  ConfigFileEntry.servlink_path = NULL;
#ifdef HAVE_LIBCRYPTO
  ConfigFileEntry.default_cipher_preference = NULL;
#endif /* HAVE_LIBCRYPTO */
}

/* flush_deleted_I_P()
 *
 * inputs       - none
 * output       - none
 * side effects - This function removes I/P conf items
 */
static void
flush_deleted_I_P(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  dlink_list * free_items [] = {
    &server_items, &oconf_items, &hub_items, &leaf_items, NULL
  };
  dlink_list ** iterator = free_items; /* C is dumb */

  /* flush out deleted I and P lines
   * although still in use.
   */
  for (; *iterator != NULL; iterator++)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, (*iterator)->head)
    {
      conf = ptr->data;
      aconf = (struct AccessItem *)map_to_conf(conf);

      if (IsConfIllegal(aconf))
      {
	dlinkDelete(ptr, *iterator);

	if (aconf->clients == 0)
	  delete_conf_item(conf);
      }
    }
  }
}

/* get_conf_name()
 *
 * inputs       - type of conf file to return name of file for
 * output       - pointer to filename for type of conf
 * side effects - none
 */
const char *
get_conf_name(ConfType type)
{
  switch (type)
  {
    case CONF_TYPE:
      return(ConfigFileEntry.configfile);
      break;
    case KLINE_TYPE:
      return(ConfigFileEntry.klinefile);
      break;
    case DLINE_TYPE:
      return(ConfigFileEntry.dlinefile);
      break;
    case XLINE_TYPE:
      return(ConfigFileEntry.xlinefile);
      break;
    case CRESV_TYPE:
      return(ConfigFileEntry.cresvfile);
      break;
    case NRESV_TYPE:
      return(ConfigFileEntry.nresvfile);
      break;
    case GLINE_TYPE:
      return(ConfigFileEntry.glinefile);
      break;

    default:
      return(NULL); /* This should NEVER HAPPEN since we call this function
                       only with the above values, this will cause us to core
                       at some point if this happens so we know where it was */
      break;
  }
}

#define BAD_PING (-1)

/* get_conf_ping()
 *
 * inputs       - pointer to struct AccessItem
 * output       - ping frequency
 * side effects - NONE
 */
static int
get_conf_ping(struct ConfItem *conf)
{
  struct ClassItem *aclass;
  struct AccessItem *aconf;

  if (conf != NULL)
  {
    aconf = (struct AccessItem *)map_to_conf(conf);
    if (aconf->class_ptr != NULL)
    {
      aclass = (struct ClassItem *)map_to_conf(aconf->class_ptr);
      return(PingFreq(aclass));
    }
  }
  return(BAD_PING);
}

/* get_client_class()
 *
 * inputs	- pointer to client struct
 * output	- pointer to name of class
 * side effects - NONE
 */
const char *
get_client_class(struct Client *target_p)
{
  dlink_node *ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;

  if (target_p != NULL && !IsMe(target_p) &&
      target_p->localClient->confs.head != NULL)
  {
    DLINK_FOREACH(ptr, target_p->localClient->confs.head)
    {
      conf = ptr->data;

      if (conf->type == CLIENT_TYPE || conf->type == SERVER_TYPE ||
          conf->type == OPER_TYPE)
      {
        aconf = (struct AccessItem *) map_to_conf(conf);
	if (aconf->class_ptr != NULL)
	  return aconf->class_ptr->name;
      }
    }
  }

  return "default";
}

/* get_client_ping()
 *
 * inputs	- pointer to client struct
 * output	- ping frequency
 * side effects - NONE
 */
int
get_client_ping(struct Client *target_p)
{
  int ping;
  struct ConfItem *conf;
  dlink_node *nlink;

  if (target_p->localClient->confs.head != NULL)
    DLINK_FOREACH(nlink, target_p->localClient->confs.head)
    {
      conf = nlink->data;

      if ((conf->type == CLIENT_TYPE) || (conf->type == SERVER_TYPE) ||
	  (conf->type == OPER_TYPE))
      {
        ping = get_conf_ping(conf);
        if (ping > 0)
          return ping;
      }
    }

  return DEFAULT_PINGFREQUENCY;
}

/* get_con_freq()
 *
 * inputs	- pointer to class struct
 * output	- connection frequency
 * side effects - NONE
 */
int
get_con_freq(struct ClassItem *clptr)
{
  if (clptr != NULL)
    return(ConFreq(clptr));

  return(DEFAULT_CONNECTFREQUENCY);
}

/* find_class()
 *
 * inputs	- string name of class
 * output	- corresponding Class pointer
 * side effects	- NONE
 */
struct ConfItem *
find_class(const char *classname)
{
  struct ConfItem *conf;

  if ((conf = find_exact_name_conf(CLASS_TYPE, classname, NULL, NULL)) != NULL)
    return(conf);

  return class_default;
}

/* check_class()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects	- 
 */
void
check_class(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct ClassItem *aclass;

  DLINK_FOREACH_SAFE(ptr, next_ptr, class_items.head)
  {
    conf = ptr->data;
    aclass = (struct ClassItem *)map_to_conf(conf);

    if (MaxTotal(aclass) < 0)
    {
      if (CurrUserCount(aclass) > 0)
        dlinkDelete(&conf->node, &class_items);
      else
        delete_conf_item(conf);
    }
  }
}

/* init_class()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects	- 
 */
void
init_class(void)
{
  struct ClassItem *aclass;

  class_default = make_conf_item(CLASS_TYPE);
  aclass = (struct ClassItem *)map_to_conf(class_default);
  DupString(class_default->name, "default");
  ConFreq(aclass)  = DEFAULT_CONNECTFREQUENCY;
  PingFreq(aclass) = DEFAULT_PINGFREQUENCY;
  MaxTotal(aclass) = ConfigFileEntry.maximum_links;
  MaxSendq(aclass) = DEFAULT_SENDQ;
  CurrUserCount(aclass) = 0;
}

/* get_sendq()
 *
 * inputs       - pointer to client
 * output       - sendq for this client as found from its class
 * side effects	- NONE
 */
unsigned long
get_sendq(struct Client *client_p)
{
  unsigned long sendq = DEFAULT_SENDQ;
  dlink_node *ptr;
  struct ConfItem *conf;
  struct ConfItem *class_conf;
  struct ClassItem *aclass;
  struct AccessItem *aconf;

  if (client_p && !IsMe(client_p) && (client_p->localClient->confs.head))
  {
    DLINK_FOREACH(ptr, client_p->localClient->confs.head)
    {
      conf = ptr->data;
      if ((conf->type == SERVER_TYPE) || (conf->type == OPER_TYPE)
	  || (conf->type == CLIENT_TYPE))
      {
	aconf = (struct AccessItem *)map_to_conf(conf);
	if ((class_conf = aconf->class_ptr) == NULL)
	  continue;
	aclass = (struct ClassItem *)map_to_conf(class_conf);
	sendq = MaxSendq(aclass);
	return(sendq);
      }
    }
  }
  /* XXX return a default?
   * if here, then there wasn't an attached conf with a sendq
   * that is very bad -Dianora
   */
  return(DEFAULT_SENDQ);
}

/* conf_add_class_to_conf()
 *
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a class pointer to a conf 
 */
void
conf_add_class_to_conf(struct ConfItem *conf, const char *class_name)
{
  struct AccessItem *aconf;
  struct ClassItem *aclass;

  aconf = (struct AccessItem *)map_to_conf(conf);

  if (class_name == NULL) 
  {
    aconf->class_ptr = class_default;
    if (conf->type == CLIENT_TYPE)
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
			   "Warning *** Defaulting to default class for %s@%s",
			   aconf->user, aconf->host);
    else
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
			   "Warning *** Defaulting to default class for %s",
			   conf->name);
  }
  else
  {
    aconf->class_ptr = find_class(class_name);
  }

  if (aconf->class_ptr == NULL)
  {
    if (conf->type == CLIENT_TYPE)
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
			   "Warning *** Defaulting to default class for %s@%s",
			   aconf->user, aconf->host);
    else
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
			   "Warning *** Defaulting to default class for %s",
			   conf->name);
    aconf->class_ptr = class_default;
  }
  else
  {
    aclass = (struct ClassItem *)map_to_conf(aconf->class_ptr);
    if (MaxTotal(aclass) < 0)
    {
      aconf->class_ptr = class_default;
    }
  }
}

#define MAXCONFLINKS 150

/* conf_add_server()
 *
 * inputs       - pointer to config item
 *		- pointer to link count already on this conf
 * output       - NONE
 * side effects - Add a connect block
 */
int
conf_add_server(struct ConfItem *conf, unsigned int lcount, const char *class_name)
{
  struct AccessItem *aconf;

  aconf = map_to_conf(conf);

  conf_add_class_to_conf(conf, class_name);

  if (lcount > MAXCONFLINKS || !aconf->host || !conf->name)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Bad connect block");
    ilog(L_WARN, "Bad connect block");
    return(-1);
  }

  if (EmptyString(aconf->passwd) && !IsConfCryptLink(aconf))
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Bad connect block, name %s",
                         conf->name);
    ilog(L_WARN, "Bad connect block, host %s", conf->name);
    return(-1);
  }

  split_user_host(aconf->host, &aconf->user, &aconf->host);
  lookup_confhost(conf);

  return(0);
}

/* conf_add_d_conf()
 *
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a d/D line
 */
void
conf_add_d_conf(struct AccessItem *aconf)
{
  if (aconf->host == NULL)
    return;

  aconf->user = NULL;

  /* XXX - Should 'd' ever be in the old conf? For new conf we don't
   *       need this anyway, so I will disable it for now... -A1kmm
   */
  if (parse_netmask(aconf->host, NULL, NULL) == HM_HOST)
  {
    ilog(L_WARN, "Invalid Dline %s ignored", aconf->host);
    free_access_item(aconf);
  }
  else
  {
    /* XXX ensure user is NULL */
    MyFree(aconf->user);
    aconf->user = NULL;
    add_conf_by_address(CONF_DLINE, aconf);
  }
}

/* yyerror()
 *
 * inputs	- message from parser
 * output	- NONE
 * side effects	- message to opers and log file entry is made
 */
void
yyerror(const char *msg)
{
  char newlinebuf[BUFSIZE];

  if (ypass != 1)
    return;

  strip_tabs(newlinebuf, (const unsigned char *)linebuf, strlen(linebuf));
  sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "\"%s\", line %d: %s: %s",
                       conffilebuf, lineno + 1, msg, newlinebuf);
  ilog(L_WARN, "\"%s\", line %d: %s: %s",
       conffilebuf, lineno + 1, msg, newlinebuf);
}

int
conf_fbgets(char *lbuf, int max_size, FBFILE *fb)
{
  char *buff;

  if ((buff = fbgets(lbuf, max_size, fb)) == NULL)
    return(0);

  return(strlen(lbuf));
}

int
conf_yy_fatal_error(const char *msg)
{
  return(0);
}
