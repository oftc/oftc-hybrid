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
#include "ircd_defs.h"
#include "tools.h"
#include "s_conf.h"
#include "s_serv.h"
#include "resv.h"
#include "s_stats.h"
#include "channel.h"
#include "class.h"
#include "client.h"
#include "common.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "listener.h"
#include "hostmask.h"
#include "modules.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_log.h"
#include "send.h"
#include "s_gline.h"
#include "s_debug.h"
#include "fileio.h"
#include "memory.h"

struct config_server_hide ConfigServerHide;

extern int yyparse(); /* defined in y.tab.c */
extern int lineno;
extern char linebuf[];
extern char conffilebuf[IRCD_BUFSIZE];
int scount = 0;       /* used by yyparse(), etc */

#ifndef INADDR_NONE
#define INADDR_NONE ((unsigned int) 0xffffffff)
#endif


/* internally defined functions */

static void lookup_confhost(struct ConfItem* aconf);
static int  SplitUserHost(struct ConfItem *aconf);

static void     set_default_conf(void);
static void     validate_conf(void);
static void     read_conf(FBFILE*);
static void     clear_out_old_conf(void);
static void     flush_deleted_I_P(void);
static void     expire_tklines(dlink_list *);
static int 	is_attached(struct Client *client_p, struct ConfItem *aconf);

FBFILE* conf_fbfile_in;
extern char yytext[];

/* address of class 0 conf */
static struct   Class* class0;

static  int     verify_access(struct Client *client_p, const char *username);
static  int     attach_iline(struct Client *, struct ConfItem *);

static void clear_special_conf(struct ConfItem **);

/* usually, with hash tables, you use a prime number...
 * but in this case I am dealing with ip addresses, not ascii strings.
 */

#define IP_HASH_SIZE 0x1000

typedef struct ip_entry
{
#ifndef IPV6
  u_int32_t ip;
#else
  struct irc_inaddr ip;
#endif
  int        count;
  time_t last_attempt;
  struct ip_entry *next;
} IP_ENTRY;

static IP_ENTRY *ip_hash_table[IP_HASH_SIZE];

static int hash_ip(struct irc_inaddr *);

static IP_ENTRY *find_or_add_ip(struct irc_inaddr*);

/* general conf items link list root */
struct ConfItem* ConfigItemList = NULL;

/* conf xline link list root */
struct ConfItem        *x_conf = ((struct ConfItem *)NULL);

/* conf uline link list root */
struct ConfItem        *u_conf = ((struct ConfItem *)NULL);

/* conf services root */
struct ConfItem        *services_conf = ((struct ConfItem *)NULL);

/*
 * conf_dns_callback
 * inputs	- pointer to struct ConfItem
 *		- pointer to adns reply
 * output	- none
 * side effects	- called when resolver query finishes
 * if the query resulted in a successful search, hp will contain
 * a non-null pointer, otherwise hp will be null.
 * if successful save hp in the conf item it was called with
 */
static void 
conf_dns_callback(void* vptr, adns_answer *reply)
{
  struct ConfItem *aconf = (struct ConfItem *) vptr;

  if (reply && reply->status == adns_s_ok)
  {
#ifdef IPV6
    copy_s_addr(IN_ADDR(aconf->ipnum),
                reply->rrs.addr->addr.inet6.sin6_addr.s6_addr);
#else
    copy_s_addr(IN_ADDR(aconf->ipnum),
                reply->rrs.addr->addr.inet.sin_addr.s_addr);
#endif
    MyFree(reply);
  }

  MyFree(aconf->dns_query);
  aconf->dns_query = NULL;
}

/*
 * conf_dns_lookup - do a nameserver lookup of the conf host
 * if the conf entry is currently doing a ns lookup do nothing, otherwise
 * allocate a dns_query and start ns lookup.
 */
static void
conf_dns_lookup(struct ConfItem* aconf)
{
  if (aconf->dns_query == NULL)
    {
      aconf->dns_query = MyMalloc(sizeof(struct DNSQuery));
      aconf->dns_query->ptr = aconf;
      aconf->dns_query->callback = conf_dns_callback;
      adns_gethost(aconf->host, aconf->aftype, aconf->dns_query);
    }
}

/*
 * make_conf
 *
 * inputs	- none
 * output	- pointer to new conf entry
 * side effects	- none
 */
struct ConfItem* 
make_conf()
{
  struct ConfItem* aconf;

  aconf = (struct ConfItem*) MyMalloc(sizeof(struct ConfItem));
  aconf->status       = CONF_ILLEGAL;
  aconf->aftype       = AF_INET;
  return(aconf);
}

/*
 * free_conf
 *
 * inputs	- pointer to conf to free
 * output	- none
 * side effects	- crucial password fields are zeroed, conf is freed
 */
void 
free_conf(struct ConfItem* aconf)
{
  assert(aconf != NULL);
  if(aconf == NULL)
    return;
  assert(!(aconf->status & CONF_CLIENT) ||
         (aconf->host && strcmp(aconf->host, "NOMATCH")) ||
         (aconf->clients == -1));
  delete_adns_queries(aconf->dns_query);
  MyFree(aconf->host);
  if (aconf->passwd)
    memset(aconf->passwd, 0, strlen(aconf->passwd));
  MyFree(aconf->passwd);
  if (aconf->spasswd)
    memset(aconf->spasswd, 0, strlen(aconf->spasswd));
  MyFree(aconf->spasswd);
  MyFree(aconf->name);
  MyFree(aconf->className);
  MyFree(aconf->user);
#ifdef HAVE_LIBCRYPTO
  if (aconf->rsa_public_key)        { RSA_free(aconf->rsa_public_key); }
  if (aconf->rsa_public_key_file)   { MyFree(aconf->rsa_public_key_file); }
#endif
  MyFree((char*) aconf);
}

/*
 * remove all conf entries from the client except those which match
 * the status field mask.
 */
void
det_confs_butmask(struct Client *client_p, int mask)
{
  dlink_node *dlink;
  dlink_node *link_next;
  struct ConfItem *aconf;

  DLINK_FOREACH_SAFE(dlink, link_next, client_p->localClient->confs.head)
  {
    aconf = dlink->data;

    if ((aconf->status & mask) == 0)
    {
      detach_conf(client_p, aconf);
    }
  }
}

static struct LinkReport {
  int conf_type;
  int rpl_stats;
  int conf_char;
} report_array[] = {
  { CONF_SERVER,           RPL_STATSCLINE, 'C'},
  { CONF_LEAF,             RPL_STATSLLINE, 'L'},
  { CONF_OPERATOR,         RPL_STATSOLINE, 'O'},
  { CONF_HUB,              RPL_STATSHLINE, 'H'},
  { 0, 0, '\0' }
};

/*
 * report_configured_links
 *
 * inputs	- pointer to client to report to
 *		- type of line to report
 * output	- NONE
 * side effects	-
 */
void 
report_configured_links(struct Client* source_p, int mask)
{
  struct ConfItem*   tmp;
  struct LinkReport* p;
  char*              host;
  char*              pass;
  char*              user;
  char*              name;
  char*		     classname;
  int                port;

  for (tmp = ConfigItemList; tmp; tmp = tmp->next) {
    if (tmp->status & mask)
      {
        for (p = &report_array[0]; p->conf_type; p++)
          if (p->conf_type == tmp->status)
            break;
	    
        if(p->conf_type == 0)
	  return;

        get_printable_conf(tmp, &name, &host, &pass, &user, &port,&classname);

        if(mask & CONF_SERVER)
          {
            char c;
	    char buf[20];
	    char *s = buf;
	    
	    buf[0] = '\0';
            c = p->conf_char;
	    
	    if (tmp->flags & CONF_FLAGS_ALLOW_AUTO_CONN)
	      *s++ = 'A';
	    if (tmp->flags & CONF_FLAGS_CRYPTLINK)
	      *s++ = 'C';
	    if (tmp->flags & CONF_FLAGS_LAZY_LINK)
	      *s++ = 'L';
	    if (tmp->flags & CONF_FLAGS_COMPRESSED)
	      *s++ = 'Z';
	    if (tmp->fakename)
	      *s++ = 'M';
	    
	    if (!buf[0])
              *s++ = '*';
	      
	    *s++ = '\0';

            /* Allow admins to see actual ips */
            /* except if HIDE_SERVERS_IPS is defined */
#ifndef HIDE_SERVERS_IPS
            if(IsOperAdmin(source_p))
              sendto_one(source_p, form_str(p->rpl_stats), me.name,
                         source_p->name, c,
                         host,
			 buf,
                         name,
                         port,
                         classname,
                         oper_flags_as_string((int)tmp->hold));
            else
#endif
              sendto_one(source_p, form_str(p->rpl_stats), me.name,
                         source_p->name, c,
                         "*@127.0.0.1",
			 buf,
                         name,
                         port,
                         classname);

          }
        else if(mask & (CONF_OPERATOR))
          {
            /* Don't allow non opers to see oper privs */
            if(IsOper(source_p))
              sendto_one(source_p, form_str(p->rpl_stats), me.name,
                         source_p->name,
                         p->conf_char,
                         user, host, name,
                         oper_privs_as_string((struct Client *)NULL,port),
                         classname,
                         oper_flags_as_string((int)tmp->hold));
            else
              sendto_one(source_p, form_str(p->rpl_stats), me.name,
                         source_p->name, p->conf_char,
                         user, host, name,
                         "0",
                         classname,
                         "");
          }
        else
          sendto_one(source_p, form_str(p->rpl_stats), me.name,
                     source_p->name, p->conf_char,
                     host, name, port,
                     classname);
      }
  }
}

/*
 * report_specials - report special conf entries
 *
 * inputs       - struct Client pointer to client to report to
 *              - int flags type of special struct ConfItem to report
 *              - int numeric for struct ConfItem to report
 * output       - none
 * side effects -
 */
void 
report_specials(struct Client* source_p, int flags, int numeric)
{
  struct ConfItem* this_conf;
  struct ConfItem* aconf;
  char*            name;
  char*            host;
  char*            pass;
  char*            user;
  char*       classname;
  int              port;

  if (flags & CONF_XLINE)
    this_conf = x_conf;
  else if (flags & CONF_ULINE)
    this_conf = u_conf;
  else return;

  for (aconf = this_conf; aconf; aconf = aconf->next)
    if (aconf->status & flags)
      {
        get_printable_conf(aconf, &name, &host, &pass,
                           &user, &port, &classname);

        sendto_one(source_p, form_str(numeric),
                   me.name,
                   source_p->name,
                   name,
                   pass);
      }
}

/*
 * check_client
 *
 * inputs	- pointer to client
 * output	- 0 = Success
 * 		  NOT_AUTHORIZED (-1) = Access denied (no I line match)
 * 		  SOCKET_ERROR   (-2) = Bad socket.
 * 		  I_LINE_FULL    (-3) = I-line is full
 *		  TOO_MANY       (-4) = Too many connections from hostname
 * 		  BANNED_CLIENT  (-5) = K-lined
 * side effects - Ordinary client access check.
 *		  Look for conf lines which have the same
 * 		  status as the flags passed.
 */
int 
check_client(struct Client *client_p, struct Client *source_p, char *username)
{
  static char     sockname[HOSTLEN + 1];
  int             i;
 
  ClearAccess(source_p);

  if ((i = verify_access(source_p, username)))
    {
      ilog(L_INFO, "Access denied: %s[%s]", source_p->name, sockname);
    }

  switch( i )
    {
    case SOCKET_ERROR:
      (void)exit_client(client_p, source_p, &me, "Socket Error");
      break;

    case TOO_MANY:
      sendto_gnotice_flags(FLAGS_FULL, L_OPER, me.name, &me, NULL, 
                           "Too many on IP for %s (%s).",
			   get_client_name(source_p, SHOW_IP),
			   source_p->localClient->sockhost);
			   
      ilog(L_INFO,"Too many connections on IP from %s.",
	   get_client_name(source_p, SHOW_IP));
      
      ServerStats->is_ref++;
      (void)exit_client(client_p, source_p, &me, 
			"No more connections allowed on that IP" );
      break;

    case I_LINE_FULL:
      sendto_gnotice_flags(FLAGS_FULL, L_OPER, me.name, &me, NULL,
                           "I-line is full for %s (%s).",
			   get_client_name(source_p, SHOW_IP),
			   source_p->localClient->sockhost);
			   
      ilog(L_INFO,"Too many connections from %s.",
	   get_client_name(source_p, SHOW_IP));
      
      ServerStats->is_ref++;
      (void)exit_client(client_p, source_p, &me, 
		"No more connections allowed in your connection class" );
      break;

    case NOT_AUTHORIZED:
    {
      static char ipaddr[HOSTIPLEN];
      ServerStats->is_ref++;
      /* jdc - lists server name & port connections are on */
      /*       a purely cosmetical change */
      inetntop(source_p->localClient->aftype, &IN_ADDR(source_p->localClient->ip), ipaddr, HOSTIPLEN);
      sendto_gnotice_flags(FLAGS_UNAUTH, L_ALL, me.name, &me, NULL,
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
	  
      (void)exit_client(client_p, source_p, &me,
			"You are not authorized to use this server");
      break;
    }
    case BANNED_CLIENT:
      (void)exit_client(client_p,client_p, &me, "*** Banned ");
      ServerStats->is_ref++;
      break;

    case 0:
    default:
      break;
    }
  return(i);
}

/*
 * verify_access
 *
 * inputs	- pointer to client to verify
 *		- pointer to proposed username
 * output	- 0 if success -'ve if not
 * side effect	- find the first (best) I line to attach.
 */
static int 
verify_access(struct Client* client_p, const char* username)
{
  struct ConfItem* aconf;
  struct ConfItem* gkill_conf;
  char non_ident[USERLEN + 1];

  if (IsGotId(client_p))
    {
      aconf = find_address_conf(client_p->host,client_p->username,
				&client_p->localClient->ip,
				client_p->localClient->aftype);
    }
  else
    {
      strlcpy(non_ident, "~", sizeof(non_ident));
      strlcat(non_ident, username, USERLEN + 1);
      aconf = find_address_conf(client_p->host,non_ident,
				&client_p->localClient->ip,
				client_p->localClient->aftype);
    }

  if (aconf != NULL)
    {
      if (aconf->status & CONF_CLIENT)
	{
	  if (aconf->flags & CONF_FLAGS_REDIR)
	    {
	      sendto_one(client_p, form_str(RPL_REDIR), me.name, client_p->name,
			 aconf->name ? aconf->name : "", aconf->port);
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

		  if (gkill_conf)
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
#ifndef HIDE_SPOOF_IPS
	      if (IsConfSpoofNotice(aconf))
		{
		  sendto_gnotice_flags(FLAGS_ALL, L_ADMIN, me.name, &me, NULL,
				       "%s spoofing: %s as %s", client_p->name,
				       client_p->host, aconf->name);
		}
#endif
	      strlcpy(client_p->host, aconf->name, sizeof(client_p->host));
	      SetIPSpoof(client_p);
	    }
	  return(attach_iline(client_p, aconf));
	}
      else if (aconf->status & CONF_KILL)
	{
	  if (ConfigFileEntry.kline_with_reason)
	    {
	      sendto_one(client_p, ":%s NOTICE %s :*** Banned %s",
			 me.name,client_p->name,aconf->passwd);
	    }
	  return(BANNED_CLIENT);
	}
    }
 return(NOT_AUTHORIZED);
}

/*
 * attach_iline
 *
 * inputs	- client pointer
 *		- conf pointer
 * output	-
 * side effects	- do actual attach
 */
static 
int attach_iline(struct Client *client_p, struct ConfItem *aconf)
{
  IP_ENTRY *ip_found;
  ip_found = find_or_add_ip(&client_p->localClient->ip);

  SetIpHash(client_p);
  ip_found->count++;

  /* only check it if its non zero */
  if ( aconf->c_class /* This should never non NULL *grin* */ &&
       ConfConFreq(aconf) && ip_found->count > ConfConFreq(aconf))
    {
      if(!IsConfExemptLimits(aconf))
        return(TOO_MANY); /* Already at maximum allowed ip#'s */
      else
        {
          sendto_one(client_p,
       ":%s NOTICE %s :*** :I: line is full, but you have an >I: line!",
                     me.name,client_p->name);
        }
    }

  return(attach_conf(client_p, aconf));
}

/* link list of free IP_ENTRY's */

static IP_ENTRY *free_ip_entries;

/*
 * clear_ip_hash_table()
 *
 * input                - NONE
 * output               - NONE
 * side effects         - clear the ip hash table
 *
 */

void 
clear_ip_hash_table()
{
  void *block_IP_ENTRIES;        /* block of IP_ENTRY's */
  IP_ENTRY *new_IP_ENTRY;        /* new IP_ENTRY being made */
  IP_ENTRY *last_IP_ENTRY;        /* last IP_ENTRY in chain */
  int size;
  int n_left_to_allocate = MAXCONNECTIONS;

  size = sizeof(IP_ENTRY) + (sizeof(IP_ENTRY) & (sizeof(void*) - 1) );

  block_IP_ENTRIES = (void *)MyMalloc((size * n_left_to_allocate));  

  free_ip_entries = (IP_ENTRY *)block_IP_ENTRIES;
  last_IP_ENTRY = free_ip_entries;

  /* *shudder* pointer arithmetic */
  while(--n_left_to_allocate)
    {
      block_IP_ENTRIES = (void *)((unsigned long)block_IP_ENTRIES + 
                        (unsigned long) size);
      new_IP_ENTRY = (IP_ENTRY *)block_IP_ENTRIES;
      last_IP_ENTRY->next = new_IP_ENTRY;
      new_IP_ENTRY->next = (IP_ENTRY *)NULL;
      last_IP_ENTRY = new_IP_ENTRY;
    }
  memset((void *)ip_hash_table, 0, sizeof(ip_hash_table));
}

/* 
 * find_or_add_ip()
 *
 * inputs       - client_p
 *              - name
 *
 * output       - pointer to an IP_ENTRY element
 * side effects -
 *
 * If the ip # was not found, a new IP_ENTRY is created, and the ip
 * count set to 0.
 * XXX: Broken for IPv6
 */

static IP_ENTRY *
find_or_add_ip(struct irc_inaddr *ip_in)
{
  int hash_index;
  IP_ENTRY *ptr, *newptr;

  for(ptr = ip_hash_table[hash_index = hash_ip(ip_in)]; ptr;
      ptr = ptr->next)
  {
   if(!memcmp(&ptr->ip, ip_in, sizeof(struct irc_inaddr)))
   {
    return(ptr);
   }
  }
  if ((ptr = ip_hash_table[hash_index]) != (IP_ENTRY *)NULL)
    {
      if( free_ip_entries == (IP_ENTRY *)NULL)
	outofmemory();

      newptr = ip_hash_table[hash_index] = free_ip_entries;
      free_ip_entries = newptr->next;

      memcpy(&newptr->ip, ip_in, sizeof(struct irc_inaddr));
      newptr->count = 0;
      newptr->last_attempt = 0;
      newptr->next = ptr;
      return(newptr);
    }

  if (free_ip_entries == (IP_ENTRY *)NULL)
    outofmemory();

  ptr = ip_hash_table[hash_index] = free_ip_entries;
  free_ip_entries = ptr->next;
  memcpy(&ptr->ip, ip_in, sizeof(struct irc_inaddr));
  ptr->count = 0;
  ptr->next = (IP_ENTRY *)NULL;
  return(ptr);
}

/* 
 * remove_one_ip
 *
 * inputs        - unsigned long IP address value
 * output        - NONE
 * side effects  - ip address listed, is looked up in ip hash table
 *                 and number of ip#'s for that ip decremented.
 *                 if ip # count reaches 0, the IP_ENTRY is returned
 *                 to the free_ip_enties link list.
 */

void 
remove_one_ip(struct irc_inaddr *ip_in)
{
  IP_ENTRY *ptr, **lptr;
  int hash_index = hash_ip(ip_in);
  for (lptr = ip_hash_table+hash_index, ptr = *lptr;
       ptr;
       lptr=&ptr->next, ptr=*lptr)
  {
#ifndef IPV6
   if (ptr->ip != PIN_ADDR(ip_in))
    continue;
#else
   if (memcmp(&IN_ADDR(ptr->ip), &PIN_ADDR(ip_in),
              sizeof(struct irc_inaddr)))
    continue;
#endif
  if (ptr->count != 0)
   ptr->count--;
  if (ptr->count != 0 ||
      (CurrentTime-ptr->last_attempt)<=ConfigFileEntry.throttle_time)
   continue;
  *lptr = ptr->next;
  ptr->next = free_ip_entries;
  free_ip_entries = ptr;
  return;
 }
}

/*
 * hash_ip()
 * 
 * input        - pointer to an irc_inaddr
 * output       - integer value used as index into hash table
 * side effects - hopefully, none
 */

#ifndef IPV6
static int  
hash_ip(struct irc_inaddr *addr)
{
  int hash;
  u_int32_t ip;

  ip = ntohl(PIN_ADDR(addr));
  hash = ((ip >> 12) + ip) & (IP_HASH_SIZE-1);
  return(hash);
}
#else /* IPV6 */
static int
hash_ip(struct irc_inaddr *addr)
{
  int hash;
  u_int32_t *ip = (u_int32_t *)&PIN_ADDR(addr);

  if(IN6_IS_ADDR_V4MAPPED((struct in6_addr *)ip))
  {
     hash = ((ip[3] >> 12) + ip[3]) & (IP_HASH_SIZE-1);
     return(hash);
  } 
    
  hash = ip[0] ^ ip[3];
  hash ^= hash >> 16;  
  hash ^= hash >> 8;   
  hash = hash & (IP_HASH_SIZE - 1);
  return(hash);
}
#endif /* IPV6 */


/*
 * count_ip_hash
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
count_ip_hash(int *number_ips_stored,u_long *mem_ips_stored)
{
  IP_ENTRY *ip_hash_ptr;
  int i;

  *number_ips_stored = 0;
  *mem_ips_stored = 0;

  for (i = 0; i < IP_HASH_SIZE ;i++)
    {
      ip_hash_ptr = ip_hash_table[i];
      while(ip_hash_ptr)
        {
          *number_ips_stored = *number_ips_stored + 1;
          *mem_ips_stored = *mem_ips_stored +
             sizeof(IP_ENTRY);

          ip_hash_ptr = ip_hash_ptr->next;
        }
    }
}

/*
 * iphash_stats()
 *
 * input	- 
 * output	-
 * side effects	-
 */
void 
iphash_stats(struct Client *client_p, struct Client *source_p,
		  int parc, char *parv[],FBFILE* out)
{
  IP_ENTRY *ip_hash_ptr;
  int i;
  int collision_count;
  char result_buf[256];

  if(out == NULL)
    sendto_one(source_p,":%s NOTICE %s :*** hash stats for iphash",
               me.name,client_p->name);
  else
    {
      (void)sprintf(result_buf,"*** hash stats for iphash\n");
      (void)fbputs(result_buf,out);
    }

  for(i = 0; i < IP_HASH_SIZE ;i++)
    {
      ip_hash_ptr = ip_hash_table[i];

      collision_count = 0;
      while(ip_hash_ptr)
        {
          collision_count++;
          ip_hash_ptr = ip_hash_ptr->next;
        }
      if(collision_count)
        {
          if(out == NULL)
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

/*
 * detach_conf
 *
 * inputs	- pointer to client to detach
 * 		- pointer to conf item to detach
 * output	- 0 for success, -1 for failure
 * side effects	- Disassociate configuration from the client.
 *		  Also removes a class from the list if marked for deleting.
 */
int 
detach_conf(struct Client* client_p,struct ConfItem* aconf)
{
  dlink_node *ptr;

  if(aconf == NULL)
    return(-1);

  DLINK_FOREACH(ptr, client_p->localClient->confs.head)
  {
    if (ptr->data == aconf)
    {
      if ((aconf) && (ClassPtr(aconf)))
      {
	if (aconf->status & CONF_CLIENT_MASK)
	{
	  if (ConfLinks(aconf) > 0)
	    --ConfLinks(aconf);
	}
	if (ConfMaxLinks(aconf) == -1 && ConfLinks(aconf) == 0)
	{
	  free_class(ClassPtr(aconf));
	  ClassPtr(aconf) = NULL;
	}
      }
      if (aconf && !--aconf->clients && IsIllegal(aconf))
      {
	free_conf(aconf);
      }
      dlinkDelete(ptr, &client_p->localClient->confs);
      free_dlink_node(ptr);
      return(0);
    }
  }
  return(-1);
}

/*
 * is_attached
 *
 * inputs	- pointer to client to check
 * 		- pointer to conf item to check
 * output	- 1 if attached, 0 if not
 * side effects	- 
 */
static int 
is_attached(struct Client *client_p, struct ConfItem *aconf)
{
  dlink_node *ptr=NULL;

  DLINK_FOREACH(ptr, client_p->localClient->confs.head)
  {
    if (ptr->data == aconf)
      break;
  }
  return((ptr != NULL) ? 1 : 0);
}

/*
 * attach_conf
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
attach_conf(struct Client *client_p,struct ConfItem *aconf)
{
  dlink_node *lp;

  if (is_attached(client_p, aconf))
  {
    return(1);
  }
  if (IsIllegal(aconf))
  {
    return(NOT_AUTHORIZED);
  }

  if ((aconf->status & CONF_OPERATOR) == 0)
  {
    if ((aconf->status & CONF_CLIENT) &&
	ConfLinks(aconf) >= ConfMaxLinks(aconf) && ConfMaxLinks(aconf) > 0)
    {
      if (!IsConfExemptLimits(aconf))
      {
	return(I_LINE_FULL); 
      }
      else
      {
	send(client_p->localClient->fd,
	     "NOTICE FLINE :I: line is full, but you have an >I: line!\n",
	     56, 0);
	SetExemptLimits(client_p);
      }
    }
  }

  if(aconf->status & FLAGS2_RESTRICTED)
    SetRestricted(client_p);

  lp = make_dlink_node();

  dlinkAdd(aconf, lp, &client_p->localClient->confs);

  aconf->clients++;
  if (aconf->status & CONF_CLIENT_MASK)
    ConfLinks(aconf)++;
  return(0);
}

/*
 * attach_confs - Attach all possible CONF lines to a client
 * if the name passed matches that for the conf file (for non-C/N lines) 
 * or is an exact match (C/N lines only).  The difference in behaviour 
 * is to stop C:*::* and N:*::*.
 * returns count of conf entries attached if successful, 0 if none are found
 *
 * NOTE: this will allow C:::* and N:::* because the match mask is the
 * conf line and not the name
 */
int 
attach_confs(struct Client* client_p, const char* name, int statmask)
{
  struct ConfItem* tmp;
  int conf_counter = 0;
  
  for (tmp = ConfigItemList; tmp; tmp = tmp->next)
    {
      if ((tmp->status & statmask) && !IsIllegal(tmp) &&
          tmp->name && match(tmp->name, name))
        {
          if (-1 < attach_conf(client_p, tmp))
            ++conf_counter;
        }
      else if ((tmp->status & statmask) && !IsIllegal(tmp) &&
               tmp->name && !irccmp(tmp->name, name))
        {
          if (-1 < attach_conf(client_p, tmp))
            ++conf_counter;
        }
    }
  return(conf_counter);
}

/*
 * attach_connect_block
 *
 * inputs	- pointer to server to attach
 * 		- name of server
 *		- hostname of server
 * output	- true (1) if both are found, otherwise return false (0)
 * side effects - find connect block and attach them to connecting client
 */
int 
attach_connect_block(struct Client *client_p,
		     const char* name,
		     const char* host)
{
  struct ConfItem* ptr;

  assert(client_p != NULL);
  assert(host != NULL);
  if(client_p == NULL || host == NULL)
    return(0);

  for (ptr = ConfigItemList; ptr; ptr = ptr->next)
    {
     if (IsIllegal(ptr))
       continue;
     if (ptr->status != CONF_SERVER)
       continue;
     if ((match(name, ptr->name) == 0) || (match(ptr->host, host) == 0))
       continue;
     attach_conf(client_p, ptr);
     return(-1);
    }
  return(0);
}

/*
 * find_conf_exact
 *
 * inputs	- pointer to name to find
 *		- pointer to username to find
 *		- pointer to host to find
 *		- int mask of type of conf to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the hostname
 *		  and has the same name.
 */
struct ConfItem* 
find_conf_exact(const char* name, const char* user, 
		const char* host, int statmask)
{
  struct ConfItem *tmp;

  for (tmp = ConfigItemList; tmp; tmp = tmp->next)
    {
      if (!(tmp->status & statmask) || !tmp->name || !tmp->host ||
          irccmp(tmp->name, name))
        continue;
      /*
      ** Accept if the *real* hostname (usually sockethost)
      ** socket host) matches *either* host or name field
      ** of the configuration.
      */
      if (!match(tmp->host, host) || !match(tmp->user,user)
          || irccmp(tmp->name, name) )
        continue;
      if (tmp->status & CONF_OPERATOR)
        {
          if (tmp->clients < ConfMaxLinks(tmp))
            return(tmp);
          else
            continue;
        }
      else
        return(tmp);
    }
  return(NULL);
}

/*
 * find_conf_name
 *
 * inputs	- pointer to conf link list to search
 *		- pointer to name to find
 *		- int mask of type of conf to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the name
 *		  and has the given mask.
 */
struct ConfItem* 
find_conf_name(dlink_list *list, const char* name, int statmask)
{
  dlink_node *ptr;
  struct ConfItem* aconf;
  
  DLINK_FOREACH(ptr, list->head)
  {
    aconf = ptr->data;
    if ((aconf->status & statmask) && aconf->name && 
	(!irccmp(aconf->name, name) || match(aconf->name, name)))
      return(aconf);
  }
  return(NULL);
}


/*
 * find_conf_by_name
 *
 * inputs	- pointer to name to match on
 *		- int mask of type of conf to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the name
 *		  and has the given mask.
 *
 */
struct ConfItem* 
find_conf_by_name(const char* name, int status)
{
  struct ConfItem* conf;
  assert(name != NULL);
  if(name == NULL)
    return NULL;
  for (conf = ConfigItemList; conf; conf = conf->next)
    {
      if (conf->status == status && conf->name &&
          match(name, conf->name))
        return conf;
    }
  return NULL;
}

/*
 * find_conf_by_host
 *
 * inputs	- pointer to hostname to match on
 *		- int mask of type of conf to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the host
 *		  and has the given mask.
 *
 */
struct ConfItem* 
find_conf_by_host(const char* host, int status)
{
  struct ConfItem* conf;
  assert(host != NULL);
  if(host == NULL)
    return(NULL);
  for (conf = ConfigItemList; conf; conf = conf->next)
    {
      if (conf->status == status && conf->host &&
          match(host, conf->host))
        return(conf);
    }
  return(NULL);
}

/*
 * find_x_conf
 *
 * inputs       - pointer to char string to find
 * output       - NULL or pointer to found struct ConfItem
 * side effects - looks for a match on name field
 */
struct ConfItem *
find_x_conf(char *to_find)
{
  struct ConfItem *aconf;

  for (aconf = x_conf; aconf; aconf = aconf->next)
    {
      if (BadPtr(aconf->name))
          continue;

      if(match_esc(aconf->name,to_find))
        return(aconf);

    }
  return(NULL);
}

/*
 * find_u_conf
 *
 * inputs       - pointer to servername
 *		- pointer to user of oper
 *		- pointer to host of oper
 * output       - NULL or pointer to found struct ConfItem
 * side effects - looks for a matches on all fields
 */
int 
find_u_conf(char *server,char *user,char *host)
{
  struct ConfItem *aconf;

  for (aconf = u_conf; aconf; aconf = aconf->next)
    {
      if (BadPtr(aconf->name))
          continue;

      if (match(aconf->name,server))
	{
	  if (BadPtr(aconf->user) || BadPtr(aconf->host))
	    return(YES);
	  if(match(aconf->user,user) && match(aconf->host,host))
	    return(YES);

	}
    }
  return(NO);
}


/*
 * find_services_conf
 *
 * inputs       - pointer to servername
 * output       - NULL or pointer to found struct ConfItem
 * side effects - None
 */

int
find_services_conf(char *server)
{
  struct ConfItem *aconf;

  for (aconf = services_conf; aconf; aconf = aconf->next)
    {
      if (BadPtr(aconf->name))
          continue;

      if(match(aconf->name,server))
          return YES;
    }
  return NO;
}


/*
 * clear_special_conf
 * 
 * inputs       - pointer to pointer of root of special conf link list
 * output       - none
 * side effects - clears given special conf lines
 */
static void 
clear_special_conf(struct ConfItem **this_conf)
{
  struct ConfItem *aconf;
  struct ConfItem *next_aconf;

  for (aconf = *this_conf; aconf; aconf = next_aconf)
    {
      next_aconf = aconf->next;
      free_conf(aconf);
    }
  *this_conf = (struct ConfItem *)NULL;
  return;
}

/*
 * rehash
 *
 * Actual REHASH service routine. Called with sig == 0 if it has been called
 * as a result of an operator issuing this command, else assume it has been
 * called as a result of the server receiving a HUP signal.
 */
int
rehash(int sig)
{
  if (sig != 0)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
			   "Got signal SIGHUP, reloading ircd conf. file");
    }

  restart_resolver();
  /* don't close listeners until we know we can go ahead with the rehash */
  read_conf_files(NO);

  if (ServerInfo.description != NULL)
    {
      strlcpy(me.info, ServerInfo.description, sizeof(me.info));
    }

  flush_deleted_I_P();
  check_klines();
  reopen_log(logFileName);
  return(0);
}

/*
 * set_default_conf()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- Set default values here.
 *		  This is called **PRIOR** to parsing the
 *		  configuration file.  If you want to do some validation
 *		  of values later, put them in validate_conf().
 */

#define YES     1
#define NO      0
#define UNSET  -1

static void 
set_default_conf(void)
{
  class0 = find_class("default");       /* which one is the default class ? */

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

  ServerInfo.max_clients = MAX_CLIENTS;  /* XXX - these don't seem to */
  ServerInfo.max_buffer = MAX_BUFFER;    /*       actually do anything! */
  /* Don't reset hub, as that will break lazylinks */
  /* ServerInfo.hub = NO; */
  ServerInfo.dns_host.sin_addr.s_addr = 0;
  ServerInfo.dns_host.sin_port = 0;
  AdminInfo.name = NULL;
  AdminInfo.email = NULL;
  AdminInfo.description = NULL;

  set_log_level(L_NOTICE);
  
  ConfigFileEntry.failed_oper_notice = YES;
  ConfigFileEntry.anti_nick_flood = NO;
  ConfigFileEntry.max_nick_time = 20;
  ConfigFileEntry.max_nick_changes = 5;
  ConfigFileEntry.max_accept = 20;
  ConfigFileEntry.anti_spam_exit_message_time = 0;
  ConfigFileEntry.ts_warn_delta = TS_WARN_DELTA_DEFAULT;
  ConfigFileEntry.ts_max_delta = TS_MAX_DELTA_DEFAULT;
  ConfigFileEntry.kline_with_reason = YES;
  ConfigFileEntry.client_exit = YES;
  ConfigFileEntry.kline_with_connection_closed = NO;
  ConfigFileEntry.warn_no_nline = YES;
  ConfigFileEntry.non_redundant_klines = YES;
  ConfigFileEntry.stats_o_oper_only = NO;
  ConfigFileEntry.stats_k_oper_only = 1; /* masked */
  ConfigFileEntry.stats_i_oper_only = 1; /* masked */
  ConfigFileEntry.stats_P_oper_only = NO;
  ConfigFileEntry.pace_wait = 10;
  ConfigFileEntry.caller_id_wait = 60;
  ConfigFileEntry.pace_wait_simple = 1;
  ConfigFileEntry.short_motd = NO;
  ConfigFileEntry.no_oper_flood = NO;
  ConfigFileEntry.true_no_oper_flood = NO;
  ConfigFileEntry.fname_userlog[0] = '\0';
  ConfigFileEntry.fname_foperlog[0] = '\0';
  ConfigFileEntry.fname_operlog[0] = '\0';
  ConfigFileEntry.glines = NO;
  ConfigFileEntry.use_egd = NO;
  /* don't reset msglocale setting -- we'd overwrite then env string */
  ConfigFileEntry.gline_time = 12 * 3600;
  ConfigFileEntry.idletime = 0;
  ConfigFileEntry.dots_in_ident = 0;
  ConfigFileEntry.maximum_links = MAXIMUM_LINKS_DEFAULT;
  ConfigFileEntry.max_targets = MAX_TARGETS_DEFAULT;
  DupString(ConfigFileEntry.servlink_path, SLPATH);
  ConfigFileEntry.egdpool_path = NULL;
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
#ifdef HAVE_LIBZ
  ConfigFileEntry.compression_level = 0;
#endif

  ConfigFileEntry.oper_umodes = FLAGS_LOCOPS | FLAGS_SERVNOTICE |
    FLAGS_OPERWALL | FLAGS_WALLOP;
  ConfigFileEntry.oper_only_umodes = FLAGS_DEBUG;
  ConfigFileEntry.throttle_time = 10;

  ConfigChannel.vchans_oper_only = NO;

  ConfigChannel.use_except  = YES;
  ConfigChannel.use_invex   = YES;
  ConfigChannel.use_knock   = YES;
  ConfigChannel.use_vchans = NO;
  ConfigChannel.knock_delay = 300;
  ConfigChannel.knock_delay_channel = 60;
  ConfigChannel.max_chans_per_user = 15;
  ConfigChannel.max_bans = 25;

  ConfigChannel.default_split_user_count = 0;
  ConfigChannel.default_split_server_count = 0;
  ConfigChannel.no_join_on_split = NO;
  ConfigChannel.no_create_on_split = NO;
  ConfigChannel.oper_pass_resv = YES;

  ConfigServerHide.flatten_links = 0;
  ConfigServerHide.hide_servers = 0;
  ConfigServerHide.disable_remote = 0;
  ConfigServerHide.links_delay = 300;
  ConfigServerHide.hidden = 0;
  ConfigServerHide.disable_hidden = 0;

  ConfigFileEntry.min_nonwildcard = 4;
  ConfigFileEntry.default_floodcount = 8;
  ConfigFileEntry.client_flood = CLIENT_FLOOD_DEFAULT;

#ifdef IPV6  
  ConfigFileEntry.fallback_to_ip6_int = 1;
#endif

#ifdef EFNET
  ConfigFileEntry.use_help = 0;
#else
  ConfigFileEntry.use_help = 1;
#endif
}
#undef YES
#undef NO

/*
 * read_conf() 
 *
 *
 * inputs       - file descriptor pointing to config file to use
 * output       - None
 * side effects	- Read configuration file.
 */
static void 
read_conf(FBFILE* file)
{
  scount = lineno = 0;

  set_default_conf(); /* Set default values prior to conf parsing */
  yyparse();          /* Load the values from the conf */
  validate_conf();    /* Check to make sure some values are still okay. */
                      /* Some global values are also loaded here. */
  check_class();      /* Make sure classes are valid */
}

static void 
validate_conf(void)
{
  if(ConfigFileEntry.ts_warn_delta < TS_WARN_DELTA_MIN)
    ConfigFileEntry.ts_warn_delta = TS_WARN_DELTA_DEFAULT;

  if(ConfigFileEntry.ts_max_delta < TS_MAX_DELTA_MIN)
    ConfigFileEntry.ts_max_delta = TS_MAX_DELTA_DEFAULT;

  if(ConfigFileEntry.servlink_path == NULL)
    DupString(ConfigFileEntry.servlink_path, SLPATH);

  if(ServerInfo.network_name == NULL)
    DupString(ServerInfo.network_name,NETWORK_NAME_DEFAULT);

  if(ServerInfo.network_desc == NULL)
    DupString(ServerInfo.network_desc,NETWORK_DESC_DEFAULT);

  if ((ConfigFileEntry.client_flood < CLIENT_FLOOD_MIN) ||
      (ConfigFileEntry.client_flood > CLIENT_FLOOD_MAX))
     ConfigFileEntry.client_flood = CLIENT_FLOOD_MAX;

  /* Hasn't been set yet, so set it now */
  if(ConfigChannel.use_halfops == -1)
#ifdef HALFOPS
    ConfigChannel.use_halfops = 1;
#else
    ConfigChannel.use_halfops = 0;
#endif

  /* hasnt been set, disable it by default */
  if(ConfigChannel.use_anonops == -1)
    ConfigChannel.use_anonops = 0;

  GlobalSetOptions.idletime = (ConfigFileEntry.idletime * 60);
}

/*
 * conf_add_conf
 * Inputs	- ConfItem
 * Output	- none
 * Side effects	- add given conf to link list
 */
void 
conf_add_conf(struct ConfItem *aconf)
{
  (void)collapse(aconf->host);
  (void)collapse(aconf->user);
  Debug((DEBUG_NOTICE,
	 "Read Init: (%d) (%s) (%s) (%s) (%d) (%d)",
	 aconf->status, 
	 aconf->host ? aconf->host : "<NULL>",
	 aconf->passwd ? aconf->passwd : "<NULL>",
	 aconf->user ? aconf->user : "<NULL>",
	 aconf->port,
	 aconf->c_class ? ConfClassType(aconf): 0 ));

  aconf->next = ConfigItemList;
  ConfigItemList = aconf;
}

/*
 * SplitUserHost
 *
 * inputs	- struct ConfItem pointer
 * output	- return 1/0 true false or -1 for error
 * side effects - splits user@host found in a name field of conf given
 *		  stuff the user into ->user and the host into ->host
 */
static int 
SplitUserHost(struct ConfItem *aconf)
{
  char *p;
  char *new_user;
  char *new_host;

  if ( (p = strchr(aconf->host, '@')) )
    {
      *p = '\0';
      DupString(new_user, aconf->host);
      MyFree(aconf->user);
      aconf->user = new_user;
      p++;
      DupString(new_host,p);
      MyFree(aconf->host);
      aconf->host = new_host;
    }
  else
    {
      DupString(aconf->user, "*");
    }
  return(1);
}

/*
 * lookup_confhost - start DNS lookups of all hostnames in the conf
 * line and convert an IP addresses in a.b.c.d number for to IP#s.
 *
 */
static void 
lookup_confhost(struct ConfItem* aconf)
{
  if (BadPtr(aconf->host) || BadPtr(aconf->name))
    {
      ilog(L_ERROR, "Host/server name error: (%s) (%s)",
          aconf->host, aconf->name);
      return;
    }

  if (strchr(aconf->host, '*') || strchr(aconf->host, '?'))
    return;
  /*
  ** Do name lookup now on hostnames given and store the
  ** ip numbers in conf structure.
  */
  if (inetpton(DEF_FAM, aconf->host, &IN_ADDR(aconf->ipnum)) <= 0)
    {
      conf_dns_lookup(aconf);
    }
}

/*
 * conf_connect_allowed
 *
 * inputs	- pointer to inaddr
 *		- int type ipv4 or ipv6
 * output	- BANNED or accepted
 * side effects	- none
 */
int 
conf_connect_allowed(struct irc_inaddr *addr, int aftype)
{
  IP_ENTRY *ip_found;
  struct ConfItem *aconf = find_dline_conf(addr,aftype);
 
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
      ip_found->count--;
      return(TOO_FAST);
    }
  ip_found->last_attempt = CurrentTime;
  return(0);
}

/*
 * find_kill
 *
 * inputs	- pointer to client structure
 * output	- pointer to struct ConfItem if found
 * side effects	- See if this user is klined already,
 *		  and if so, return struct ConfItem pointer
 */
struct ConfItem *
find_kill(struct Client* client_p)
{
  struct ConfItem *aconf;
  assert(client_p != NULL);
  if(client_p == NULL)
    return NULL;

  aconf = find_kline_conf(client_p->host, client_p->username,
			  &client_p->localClient->ip,
			  client_p->localClient->aftype);
  if (aconf == NULL)
    return aconf;
  if(aconf->status & CONF_KILL)
    return aconf;
  return(NULL);
}

/* add_temp_kline
 *
 * inputs        - pointer to struct ConfItem
 * output        - none
 * Side effects  - links in given struct ConfItem into 
 *                 temporary kline link list
 */
void
add_temp_kline(struct ConfItem *aconf)
{
  dlink_node *kill_node;
  kill_node = make_dlink_node();
  dlinkAdd(aconf, kill_node, &temporary_klines);
  aconf->flags |= CONF_FLAGS_TEMPORARY;
  add_conf_by_address(aconf->host, CONF_KILL, aconf->user, aconf);
}

/*
 * cleanup_tklines
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - call function to expire tklines
 *                This is an event started off in ircd.c
 */
void
cleanup_tklines(void *notused)
{
  expire_tklines(&temporary_klines);
}

/*
 * expire_tklines
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
  struct ConfItem *kill_ptr;
  DLINK_FOREACH_SAFE(kill_node, next_node, tklist->head)
    {
      kill_ptr = kill_node->data;

      if (kill_ptr->hold <= CurrentTime)
	{
          /* Alert opers that a TKline expired - Hwy */
          sendto_realops_flags(FLAGS_ALL, L_ALL,
			       "Temporary K-line for [%s@%s] expired",
			       (kill_ptr->user) ? kill_ptr->user : "*",
			       (kill_ptr->host) ? kill_ptr->host : "*");

	  delete_one_address_conf(kill_ptr->host, kill_ptr);
	  dlinkDelete(kill_node, tklist);
	  free_dlink_node(kill_node);
	}
    }
}

/*
 * oper_privs_as_string
 *
 * inputs        - pointer to client_p or NULL
 * output        - pointer to static string showing oper privs
 * side effects  -
 * return as string, the oper privs as derived from port
 * also, set the oper privs if given client_p non NULL
 */

char *
oper_privs_as_string(struct Client *client_p,int port)
{
  static char privs_out[16];
  char *privs_ptr;

  privs_ptr = privs_out;
  *privs_ptr = '\0';

  if (port & CONF_OPER_GLINE)
    {
      if(client_p)
        SetOperGline(client_p);
      *privs_ptr++ = 'G';
    }
  else
    *privs_ptr++ = 'g';

  if(port & CONF_OPER_K)
    {
      if(client_p)
        SetOperK(client_p);
      *privs_ptr++ = 'K';
    }
  else
    *privs_ptr++ = 'k';

  if(port & CONF_OPER_N)
    {
      if(client_p)
        SetOperN(client_p);
      *privs_ptr++ = 'N';
    }
  else
    *privs_ptr++ = 'n';

  if(port & CONF_OPER_GLOBAL_KILL)
    {
      if(client_p)
        SetOperGlobalKill(client_p);
      *privs_ptr++ = 'O';
    }
  else
    *privs_ptr++ = 'o';

  if(port & CONF_OPER_REMOTE)
    {
      if(client_p)
        SetOperRemote(client_p);
      *privs_ptr++ = 'R';
    }
  else
    *privs_ptr++ = 'r';
  
  if(port & CONF_OPER_UNKLINE)
    {
      if(client_p)
        SetOperUnkline(client_p);
      *privs_ptr++ = 'U';
    }
  else
    *privs_ptr++ = 'u';

  if(port & CONF_OPER_REHASH)
    {
      if(client_p)
        SetOperRehash(client_p);
      *privs_ptr++ = 'H';
    }
  else
    *privs_ptr++ = 'h';

  if(port & CONF_OPER_DIE)
    {
      if(client_p)
        SetOperDie(client_p);
      *privs_ptr++ = 'D';
    }
  else
    *privs_ptr++ = 'd';

  if (port & CONF_OPER_ADMIN)
    {
      if (client_p)
	SetOperAdmin(client_p);
      *privs_ptr++ = 'A';
    }
  else
    *privs_ptr++ = 'a';
  
  *privs_ptr = '\0';

  return(privs_out);
}


/* oper_flags_as_string
 *
 * inputs        - oper flags as bit mask
 * output        - oper flags as as string
 * side effects -
 *
 */
char *
oper_flags_as_string(int flags)
{
  /* This MUST be extended if we add any more modes... -Hwy */
  static char flags_out[18];
  char *flags_ptr;

  flags_ptr = flags_out;
  *flags_ptr = '\0';

  if(flags & FLAGS_INVISIBLE)
    *flags_ptr++ = 'i';
  if(flags & FLAGS_WALLOP)
    *flags_ptr++ = 'w';
  if(flags & FLAGS_SERVNOTICE)
    *flags_ptr++ = 's';
  if(flags & FLAGS_CCONN)
    *flags_ptr++ = 'c';
  if(flags & FLAGS_REJ)
    *flags_ptr++ = 'r';
  if(flags & FLAGS_SKILL)
    *flags_ptr++ = 'k';
  if(flags & FLAGS_FULL)
    *flags_ptr++ = 'f';
  if(flags & FLAGS_SPY)
    *flags_ptr++ = 'y';
  if(flags & FLAGS_DEBUG)
    *flags_ptr++ = 'd';
  if(flags & FLAGS_NCHANGE)
    *flags_ptr++ = 'n';
  if(flags & FLAGS_ADMIN)
    *flags_ptr++ = 'a';
  if(flags & FLAGS_EXTERNAL)
    *flags_ptr++ = 'x';
  if(flags & FLAGS_UNAUTH)
    *flags_ptr++ = 'u';
  if(flags & FLAGS_BOTS)
    *flags_ptr++ = 'b';
  if(flags & FLAGS_LOCOPS)
    *flags_ptr++ = 'l';
  if(flags & FLAGS_CALLERID)
    *flags_ptr++ = 'g';
  *flags_ptr = '\0';

  return(flags_out);
}


/* const char* get_oper_name(struct Client *client_p)
 * Input: A client to find the active oper{} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
char*
get_oper_name(struct Client *client_p)
{
  dlink_node *cnode;

  /* +5 for !,@,{,} and null */
  static char buffer[NICKLEN+USERLEN+HOSTLEN+HOSTLEN+5];

  if (MyConnect(client_p))
  {
    DLINK_FOREACH(cnode, client_p->localClient->confs.head)
    {
      if (((struct ConfItem*)cnode->data)->status & CONF_OPERATOR)
      {
	ircsprintf(buffer, "%s!%s@%s{%s}", client_p->name,
		   client_p->username, client_p->host,
		   ((struct ConfItem*)cnode->data)->name);
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

/*
 * get_printable_conf
 *
 * inputs        - struct ConfItem
 *
 * output         - name 
 *                - host
 *                - pass
 *                - user
 *                - port
 *
 * side effects        -
 * Examine the struct struct ConfItem, setting the values
 * of name, host, pass, user to values either
 * in aconf, or "<NULL>" port is set to aconf->port in all cases.
 */

void 
get_printable_conf(struct ConfItem *aconf, char **name, char **host,
                           char **pass, char **user,int *port,char **classname)
{
  static  char        null[] = "<NULL>";
  static  char        zero[] = "default";

  *name = BadPtr(aconf->name) ? null : aconf->name;
  *host = BadPtr(aconf->host) ? null : aconf->host;
  *pass = BadPtr(aconf->passwd) ? null : aconf->passwd;
  *user = BadPtr(aconf->user) ? null : aconf->user;
  *classname = BadPtr(aconf->className) ? zero : aconf->className;
  *port = (int)aconf->port;
}

/*
 * read_conf_files
 *
 * inputs       - cold start YES or NO
 * output       - none
 * side effects - read all conf files needed, ircd.conf kline.conf etc.
 */
void 
read_conf_files(int cold)
{
  FBFILE *file;
  const char *filename, *kfilename, *dfilename; /* kline or conf filename */

  conf_fbfile_in = NULL;

  filename = get_conf_name(CONF_TYPE);

  /* We need to know the initial filename for the yyerror() to report
     FIXME: The full path is in conffilenamebuf first time since we
             dont know anything else

     - Gozem 2002-07-21 
  */
  strlcpy(conffilebuf, filename, sizeof(conffilebuf));

  if ((conf_fbfile_in = fbopen(filename,"r")) == NULL)
    {
      if(cold)
        {
          ilog(L_CRIT, "Failed in reading configuration file %s", filename);
          exit(-1);
        }
      else
        {
          sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
			       "Can't open file '%s' - aborting rehash!",
			       filename );
          return;
        }
    }

  if (cold)
  {
    /* set to 'undefined' */
    ConfigChannel.use_halfops = -1;
    ConfigChannel.use_anonops = -1;
  }
  else
  {
    clear_out_old_conf();
  }

  read_conf(conf_fbfile_in);
  fbclose(conf_fbfile_in);

  kfilename = get_conf_name(KLINE_TYPE);
  if (irccmp(filename, kfilename))
    {
      if((file = fbopen(kfilename,"r")) == NULL)
        {
	  if (cold)
	    ilog(L_ERROR, "Failed reading kline file %s", filename);
	  else
	    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
				 "Can't open %s file klines could be missing!",
				 kfilename);
	}
      else
	{
	  parse_k_file(file);
	  fbclose(file);
	}
    }

  dfilename = get_conf_name(DLINE_TYPE);
  if (irccmp(filename, dfilename) && irccmp(kfilename, dfilename))
    {
      if ((file = fbopen(dfilename,"r")) == NULL)
	{
	  if(cold)
	    ilog(L_ERROR, "Failed reading dline file %s", dfilename);
	  else
	    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
				 "Can't open %s file dlines could be missing!",
				 dfilename);
	}
      else
	{
	  parse_d_file(file);
	  fbclose(file);
	}
    }
}

/*
 * clear_out_old_conf
 *
 * inputs       - none
 * output       - none
 * side effects - Clear out the old configuration
 */
static 
void clear_out_old_conf(void)
{
  struct ConfItem **tmp = &ConfigItemList;
  struct ConfItem *tmp2;
  struct Class    *cltmp;

  /*
   * We only need to free anything allocated by yyparse() here.
   * Reseting structs, etc, is taken care of by set_default_conf().
   */
  while ((tmp2 = *tmp))
  {
    if (tmp2->clients)
    {
      /*
       ** Configuration entry is still in use by some
       ** local clients, cannot delete it--mark it so
       ** that it will be deleted when the last client
       ** exits...
       */
      if (!(tmp2->status & CONF_CLIENT))
      {
        *tmp = tmp2->next;
        tmp2->next = NULL;
      }
      else
        tmp = &tmp2->next;
      tmp2->status |= CONF_ILLEGAL;
    }
    else
    {
      *tmp = tmp2->next;
      free_conf(tmp2);
    }
  }

  /*
   * don't delete the class table, rather mark all entries
   * for deletion. The table is cleaned up by check_class. - avalon
   */
  assert(ClassList != NULL);
  
  for (cltmp = ClassList->next; cltmp; cltmp = cltmp->next)
    MaxLinks(cltmp) = -1;

  clear_out_address_conf();
  clear_special_conf(&x_conf);
  clear_special_conf(&u_conf);

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
#ifdef HAVE_LIBCRYPTO
  if (ServerInfo.rsa_private_key != NULL)
  {
    RSA_free(ServerInfo.rsa_private_key);
    ServerInfo.rsa_private_key = NULL;
  }
  if (ServerInfo.rsa_private_key_file != NULL)
  {
    MyFree(ServerInfo.rsa_private_key_file);
    ServerInfo.rsa_private_key_file = NULL;
  }
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

  /* auth{}, quarantine{}, shared{}, connect{}, kill{}, deny{}, exempt{}
   * and gecos{} blocks are freed above too
   */

  /* clean out general */
  MyFree(ConfigFileEntry.servlink_path);
  ConfigFileEntry.servlink_path = NULL;
#ifdef HAVE_LIBCRYPTO
  ConfigFileEntry.default_cipher_preference = NULL;
#endif /* HAVE_LIBCRYPTO */

  /* OK, that should be everything... */
}

/*
 * flush_deleted_I_P
 *
 * inputs       - none
 * output       - none
 * side effects - This function removes I/P conf items
 */

static 
void flush_deleted_I_P(void)
{
  struct ConfItem **tmp = &ConfigItemList;
  struct ConfItem *tmp2;

  /*
   * flush out deleted I and P lines although still in use.
   */
  for (tmp = &ConfigItemList; (tmp2 = *tmp); )
    {
      if (!(tmp2->status & CONF_ILLEGAL))
        tmp = &tmp2->next;
      else
        {
          *tmp = tmp2->next;
          tmp2->next = NULL;
          if (!tmp2->clients)
            free_conf(tmp2);
        }
    }
}

/*
 * WriteKlineOrDline
 *
 * inputs       - kline or dline type flag
 *              - client pointer to report to
 *              - user name of target
 *              - host name of target
 *              - reason for target
 *              - time_t cur_time
 * output       - NONE
 * side effects - This function takes care of
 *                finding right kline or dline conf file, writing
 *                the right lines to this file, 
 *                notifying the oper that their kline/dline is in place
 *                notifying the opers on the server about the k/d line
 *                forwarding the kline onto the next U lined server
 *                
 */
void 
WriteKlineOrDline( KlineType type,
		   struct Client *source_p,
		   char *user,
		   char *host,
		   const char *reason,
		   const char *oper_reason,
		   const char *current_date,
		   time_t cur_time)
{
  char buffer[1024];
  FBFILE *out;
  const char *filename;         /* filename to use for kline */

  filename = get_conf_name(type);

  if(type == DLINE_TYPE)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
			   "%s added D-Line for [%s] [%s]",
			   get_oper_name(source_p), host, reason);
      sendto_one(source_p, ":%s NOTICE %s :Added D-Line [%s] to %s",
		 me.name, source_p->name, host, filename);

    }
  else
    {
      sendto_realops_flags(FLAGS_ALL, L_OPER, "%s added K-Line for [%s@%s]"
              " [%s]", get_oper_name(source_p), user, host, reason);
      sendto_one(source_p, ":%s NOTICE %s :Added K-Line [%s@%s]",
		 me.name, source_p->name, user, host);
    }

  if ( (out = fbopen(filename, "a")) == NULL )
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
			   "*** Problem opening %s ", filename);
      return;
    }

  if (oper_reason == NULL)
    oper_reason = "";

  if(type==KLINE_TYPE)
    ircsprintf(buffer, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%ld\n",
               user,
	       host,
               reason,
	       oper_reason,
	       current_date,
	       get_oper_name(source_p),
               (long) cur_time);
  else
    ircsprintf(buffer, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%ld\n",
               host,
               reason,
	       oper_reason,
	       current_date,
	       get_oper_name(source_p),
               (long) cur_time);


  if (fbputs(buffer,out) == -1)
    {
      sendto_realops_flags(FLAGS_ALL, L_OPER, "*** Problem writing to %s",
              filename);
      fbclose(out);
      return;
    }
      
  fbclose(out);

  if(type==KLINE_TYPE)
    ilog(L_TRACE, "%s added K-Line for [%s@%s] [%s]",
        source_p->name, user, host, reason);
  else
    ilog(L_TRACE, "%s added D-Line for [%s] [%s]",
           get_oper_name(source_p), host, reason);
}

/* get_conf_name
 *
 * inputs       - type of conf file to return name of file for
 * output       - pointer to filename for type of conf
 * side effects - none
 */
const char *
get_conf_name(KlineType type)
{
  if(type == CONF_TYPE)
    {
      return(ConfigFileEntry.configfile);
    }
  else if(type == KLINE_TYPE)
    {
      return(ConfigFileEntry.klinefile);
    }

  return(ConfigFileEntry.dlinefile);
}

/*
 * conf_add_class_to_conf
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a class pointer to a conf 
 */

void 
conf_add_class_to_conf(struct ConfItem *aconf)
{
  if(aconf->className == NULL)
    {
      DupString(aconf->className,"default");
      ClassPtr(aconf) = class0;
      return;
    }

  ClassPtr(aconf) = find_class(aconf->className);

  if(ClassPtr(aconf) == class0)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
	   "Warning *** Defaulting to default class for missing class \"%s\"",
			   aconf->className);
      MyFree(aconf->className);
      DupString(aconf->className,"default");
      return;
    }

  if (ConfMaxLinks(aconf) < 0)
    {
      ClassPtr(aconf) = find_class(0);
      MyFree(aconf->className);
      DupString(aconf->className,"default");
      return;
    }
}

#define MAXCONFLINKS 150

/*
 * conf_add_server
 *
 * inputs       - pointer to config item
 *		- pointer to link count already on this conf
 * output       - NONE
 * side effects - Add a connect block
 */
int 
conf_add_server(struct ConfItem *aconf, int lcount)
{
  conf_add_class_to_conf(aconf);

  if (lcount > MAXCONFLINKS || !aconf->host || !aconf->name)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
	                   "Bad connect block");
      ilog(L_WARN, "Bad connect block");
      return(-1);
    }

  if (BadPtr(aconf->passwd) && !(aconf->flags & CONF_FLAGS_CRYPTLINK))
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,"Bad connect block, name %s",
			   aconf->name);
      ilog(L_WARN, "Bad connect block, host %s",aconf->name);
      return(-1);
    }
          
  if (SplitUserHost(aconf) < 0)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
	                   "Bad connect block, name %s", aconf->name);
      ilog(L_WARN, "Bad connect block, name %s",aconf->name);
      return(-1);
    }
  lookup_confhost(aconf);
  return(0);
}

/*
 * conf_add_d_conf
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a d/D line
 */
void
conf_add_d_conf(struct ConfItem *aconf)
{
  if (aconf->host == NULL)
    return;

  aconf->user = NULL;

  /* XXX - Should 'd' ever be in the old conf? For new conf we don't
   *       need this anyway, so I will disable it for now... -A1kmm
   */

  if (parse_netmask(aconf->host, NULL, NULL) == HM_HOST)
    {
      ilog(L_WARN,"Invalid Dline %s ignored",aconf->host);
      free_conf(aconf);
    }
  else
    {
      add_conf_by_address(aconf->host, CONF_DLINE, NULL, aconf);
    }
}

/*
 * conf_add_x_conf
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a X line
 */

void 
conf_add_x_conf(struct ConfItem *aconf)
{
  aconf->next = x_conf;
  x_conf = aconf;
}

/*
 * conf_add_u_conf
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add an U line
 */

void 
conf_add_u_conf(struct ConfItem *aconf)
{
  aconf->next = u_conf;
  u_conf = aconf;
}

/*
 * conf_add_serv_conf
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Make a services line (df/bahamut u line)
 */
void
conf_add_services_conf(struct ConfItem *aconf)
{
   aconf->next = services_conf;
   services_conf = aconf;
}

/*
 * conf_add_fields
 * inputs       - pointer to config item
 *              - pointer to host_field
 *		- pointer to pass_field
 *              - pointer to user_field
 *              - pointer to port_field
 *		- pointer to class_field
 * output       - NONE
 * side effects - update host/pass/user/port fields of given aconf
 */

void 
conf_add_fields(struct ConfItem *aconf,
		char *host_field,
		char *pass_field,
		char *user_field,
		char *port_field,
		char *class_field)
{
  if (host_field != NULL)
    DupString(aconf->host, host_field);
  if (pass_field != NULL)
    DupString(aconf->passwd, pass_field);
  if (user_field != NULL)
    DupString(aconf->user, user_field);
  if (port_field != NULL)
    aconf->port = atoi(port_field);
  if (class_field != NULL)
    DupString(aconf->className, class_field);
}

/*
 * yyerror
 *
 * inputs	- message from parser
 * output	- none
 * side effects	- message to opers and log file entry is made
 */
void 
yyerror(char *msg)
{
  char newlinebuf[BUFSIZE];

  strip_tabs(newlinebuf, (const unsigned char *)linebuf, strlen(linebuf));

  sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
                       "\"%s\", line %d: %s: %s",
		       conffilebuf, lineno + 1, msg, newlinebuf);

  ilog(L_WARN, "\"%s\", line %d: %s: %s",
		       conffilebuf, lineno + 1, msg, newlinebuf);
}

int 
conf_fbgets(char *lbuf,int max_size, FBFILE *fb)
{
  char* buff;

  if ((buff = fbgets(lbuf,max_size,fb)) == NULL)
    return(0);

  return(strlen(lbuf));
}

int 
conf_yy_fatal_error(char *msg)
{
  return(0);
}


/* void flush_expired_ips(void *unused)
 *
 * inputs	- none.
 * output	- none.
 * side effects	- Deletes all IP address entries which should have expired.
 */
void
flush_expired_ips(void *unused)
{
  int i;
  time_t expire_before = CurrentTime - ConfigFileEntry.throttle_time;
  IP_ENTRY *ie, **iee;

  for (i=0; i<IP_HASH_SIZE; i++)
    {
      for (iee=ip_hash_table+i, ie=*iee; ie; ie=*iee)
	{
	  if (ie->count == 0 && ie->last_attempt <= expire_before)
	    {
	      *iee=ie->next;
	      ie->next = free_ip_entries;
	      free_ip_entries = ie;
	    }
	  else
	    iee = &ie->next;
	}
      *iee = NULL;
    }
}
