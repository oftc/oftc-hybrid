/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  parse_aline.c: All the functions needed for klining etc.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
 *  $Id: parse_aline.c 91 2005-10-08 03:46:09Z db $
 */

#include "stdinc.h"
#include "ircd_defs.h"
#include "s_conf.h"
#include "parse_aline.h"
#include "s_serv.h"
#include "resv.h"
#include "s_stats.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "ircd.h"
#include "listener.h"
#include "hostmask.h"
#include "modules.h"
#include "numeric.h"
#include "send.h"
#include "s_gline.h"
#include "userhost.h"
#include "s_user.h"

static void expire_tklines(dlink_list *);
static int find_user_host(struct Client *, char *, char *, char *, unsigned int);


dlink_list temporary_klines  = { NULL, NULL, 0 };
dlink_list temporary_dlines  = { NULL, NULL, 0 };
dlink_list temporary_xlines  = { NULL, NULL, 0 };
dlink_list temporary_rklines = { NULL, NULL, 0 };
dlink_list temporary_glines  = { NULL, NULL, 0 };
dlink_list temporary_rxlines = { NULL, NULL, 0 };
dlink_list temporary_resv = { NULL, NULL, 0 };

/* parse_aline
 *
 * input        - pointer to cmd name being used
 *              - pointer to client using cmd
 *              - parc parameter count
 *              - parv[] list of parameters to parse
 *		- parse_flags bit map of things to test
 *		- pointer to user or string to parse into
 *              - pointer to host or NULL to parse into if non NULL
 *              - pointer to optional tkline time or NULL 
 *              - pointer to target_server to parse into if non NULL
 *              - pointer to reason to parse into
 *
 * output       - 1 if valid, -1 if not valid
 * side effects - A generalised k/d/x etc. line parser,
 *               "ALINE [time] user@host|string [ON] target :reason"
 *                will parse returning a parsed user, host if
 *                h_p pointer is non NULL, string otherwise.
 *                if tkline_time pointer is non NULL a tk line will be set
 *                to non zero if found.
 *                if tkline_time pointer is NULL and tk line is found,
 *                error is reported.
 *                if target_server is NULL and an "ON" is found error
 *                is reported.
 *                if reason pointer is NULL ignore pointer,
 *                this allows usee of parse_a_line in unkline etc.
 *
 * - Dianora
 */
int
parse_aline(const char *cmd, struct Client *source_p,
	    int parc, char **parv,
	    int parse_flags, char **up_p, char **h_p, time_t *tkline_time, 
	    char **target_server, char **reason)
{
  int found_tkline_time=0;
  static char def_reason[] = "No Reason";
  static char user[USERLEN*4+1];
  static char host[HOSTLEN*4+1];

  parv++;
  parc--;

  found_tkline_time = valid_tkline(*parv, TK_MINUTES);

  if (found_tkline_time != 0)
  {
    parv++;
    parc--;

    if (tkline_time != NULL)
      *tkline_time = found_tkline_time;
    else
    {
      sendto_one(source_p, ":%s NOTICE %s :temp_line not supported by %s",
		 me.name, source_p->name, cmd);
      return -1;
    }
  }

  if (parc == 0)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, cmd);
    return -1;
  }

  if (h_p == NULL)
    *up_p = *parv;
  else
  {
    if (find_user_host(source_p, *parv, user, host, parse_flags) == 0)
      return -1;

    *up_p = user;
    *h_p = host;
  }
 
  parc--;
  parv++;

  if (parc != 0)
  {
    if (irccmp(*parv, "ON") == 0)
    {
      parc--;
      parv++;

      if (target_server == NULL)
      {
        sendto_one(source_p, ":%s NOTICE %s :ON server not supported by %s",
            me.name, source_p->name, cmd);
        return -1;
      }

      if (!IsOperRemoteBan(source_p))
      {
        sendto_one(source_p, form_str(ERR_NOPRIVS),
                   me.name, source_p->name, "remoteban");
        return -1;
      }

      if (parc == 0 || EmptyString(*parv))
      {
        sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
            me.name, source_p->name, cmd);
        return -1;
      }

      *target_server = *parv;
      parc--;
      parv++;
    }
    else
    {
      /* Make sure target_server *is* NULL if no ON server found
       * caller probably NULL'd it first, but no harm to do it again -db
       */
      if (target_server != NULL)
        *target_server = NULL;
    }
  }

  if (h_p != NULL)
  {
    if (strchr(user, '!') != NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :Invalid character '!' in kline",
                 me.name, source_p->name);
      return -1;
    }

    if ((parse_flags & AWILD) && !valid_wild_card(source_p, YES, 2, *up_p, *h_p))
      return -1;
  }
  else
    if ((parse_flags & AWILD) && !valid_wild_card(source_p, YES, 1, *up_p))
      return -1;

  if (reason != NULL)
  {
    if (parc != 0)
    {
      *reason = *parv;
      if (!valid_comment(source_p, *reason, YES))
        return -1;
    }
    else
      *reason = def_reason;
  }

  return 1;
}

/*
 * cluster_a_line
 *
 * inputs	- client sending the cluster
 *		- command name "KLINE" "XLINE" etc.
 *		- capab -- CAP_KLN etc. from s_serv.h
 *		- cluster type -- CLUSTER_KLINE etc. from s_conf.h
 *		- pattern and args to send along
 * output	- none
 * side effects	- Take source_p send the pattern with args given
 *		  along to all servers that match capab and cluster type
*/
void
cluster_a_line(struct Client *source_p, const char *command,
	       int capab, int cluster_type, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  struct ConfItem *conf;
  dlink_node *ptr;

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;

    if (conf->flags & cluster_type)
    {
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER|capab,
			 "%s %s %s", command, conf->name, buffer);
    }
  }
}

/* valid_comment()
 *
 * inputs	- pointer to client
 *              - pointer to comment
 * output       - 0 if no valid comment,
 *              - 1 if valid
 * side effects - truncates reason where necessary
 */
int
valid_comment(struct Client *source_p, char *comment, int warn)
{
  if (strchr(comment, '"'))
  {
    if (warn)
      sendto_one(source_p, ":%s NOTICE %s :Invalid character '\"' in comment",
                 me.name, source_p->name);
    return 0;
  }

  if (strlen(comment) > REASONLEN)
    comment[REASONLEN-1] = '\0';

  return 1;
}

/* find_user_host()
 *
 * inputs	- pointer to client placing kline
 *              - pointer to user_host_or_nick
 *              - pointer to user buffer
 *              - pointer to host buffer
 * output	- 0 if not ok to kline, 1 to kline i.e. if valid user host
 * side effects -
 */
static int
find_user_host(struct Client *source_p, char *user_host_or_nick,
               char *luser, char *lhost, unsigned int flags)
{
  struct Client *target_p = NULL;
  char *hostp = NULL;

  if (lhost == NULL)
  {
    strlcpy(luser, user_host_or_nick, USERLEN*4 + 1);
    return 1;
  }

  if ((hostp = strchr(user_host_or_nick, '@')) || *user_host_or_nick == '*')
  {
    /* Explicit user@host mask given */

    if(hostp != NULL)                            /* I'm a little user@host */
    {
      *(hostp++) = '\0';                       /* short and squat */
      if (*user_host_or_nick)
	strlcpy(luser, user_host_or_nick, USERLEN*4 + 1); /* here is my user */
      else
	strcpy(luser, "*");
      if (*hostp)
	strlcpy(lhost, hostp, HOSTLEN + 1);    /* here is my host */
      else
	strcpy(lhost, "*");
    }
    else
    {
      luser[0] = '*';             /* no @ found, assume its *@somehost */
      luser[1] = '\0';	  
      strlcpy(lhost, user_host_or_nick, HOSTLEN*4 + 1);
    }
    
    return 1;
  }
  else if (!(flags & NOUSERLOOKUP))
  {
    /* Try to find user@host mask from nick */
    /* Okay to use source_p as the first param, because source_p == client_p */
    if ((target_p = 
        find_chasing(source_p, source_p, user_host_or_nick, NULL)) == NULL)
      return 0;

    if (IsExemptKline(target_p))
    {
      if (!IsServer(source_p))
	sendto_one(source_p,
		   ":%s NOTICE %s :%s is E-lined",
		   me.name, source_p->name, target_p->name);
      return 0;
    }

    /*
     * turn the "user" bit into "*user", blow away '~'
     * if found in original user name (non-idented)
     */
    strlcpy(luser, target_p->username, USERLEN*4 + 1);

    if (target_p->username[0] == '~')
      luser[0] = '*';

    if (target_p->sockhost[0] == '\0' ||
        (target_p->sockhost[0] == '0' && target_p->sockhost[1] == '\0'))
      strlcpy(lhost, target_p->host, HOSTLEN*4 + 1);
    else
      strlcpy(lhost, target_p->sockhost, HOSTLEN*4 + 1);
    return 1;
  }

  return 0;
}

/*
 * valid_tkline()
 * 
 * inputs       - pointer to ascii string to check
 *              - whether the specified time is in seconds or minutes
 * output       - -1 not enough parameters
 *              - 0 if not an integer number, else the number
 * side effects - none
 * Originally written by Dianora (Diane, db@db.net)
 */
time_t
valid_tkline(char *p, int minutes)
{
  time_t result = 0;

  while (*p)
  {
    if (IsDigit(*p))
    {
      result *= 10;
      result += ((*p) & 0xF);
      p++;
    }
    else
      return 0;
  }

  /* in the degenerate case where oper does a /quote kline 0 user@host :reason 
   * i.e. they specifically use 0, I am going to return 1 instead
   * as a return value of non-zero is used to flag it as a temporary kline
   */

  if (result == 0)
    result = 1;

  /* 
   * If the incoming time is in seconds convert it to minutes for the purpose
   * of this calculation
   */
  if (!minutes)
    result = result / (time_t)60; 

  if (result > MAX_TDKLINE_TIME)
    result = MAX_TDKLINE_TIME;

  result = result * (time_t)60;  /* turn it into seconds */

  return result;
}

/* valid_wild_card()
 *
 * input        - pointer to client
 *		- int flag, 0 for no warning oper 1 for warning oper
 *		- count of following varargs to check
 * output       - 0 if not valid, 1 if valid
 * side effects - NOTICE is given to source_p if warn is 1
 */
int
valid_wild_card(struct Client *source_p, int warn, int count, ...)
{
  char *p;
  char tmpch;
  int nonwild = 0;
  int anywild = 0;
  va_list args;

  /*
   * Now we must check the user and host to make sure there
   * are at least NONWILDCHARS non-wildcard characters in
   * them, otherwise assume they are attempting to kline
   * *@* or some variant of that. This code will also catch
   * people attempting to kline *@*.tld, as long as NONWILDCHARS
   * is greater than 3. In that case, there are only 3 non-wild
   * characters (tld), so if NONWILDCHARS is 4, the kline will
   * be disallowed.
   * -wnder
   */

  va_start(args, count);

  while (count--)
  {
    p = va_arg(args, char *);
    if (p == NULL)
      continue;

    while ((tmpch = *p++))
    {
      if (!IsKWildChar(tmpch))
      {
        /*
         * If we find enough non-wild characters, we can
         * break - no point in searching further.
         */
        if (++nonwild >= ConfigFileEntry.min_nonwildcard)
          return 1;
      }
      else
        anywild = 1;
    }
  }

  /* There are no wild characters in the ban, allow it */
  if(!anywild)
    return 1;

  if (warn)
    sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the mask",
               me.name, source_p->name, ConfigFileEntry.min_nonwildcard);
  return 0;
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
  struct AccessItem *aconf = NULL;
  const char *uhi[3];

  uhi[0] = client_p->username;
  uhi[1] = client_p->host;
  uhi[2] = client_p->sockhost;

  assert(client_p != NULL);

  aconf = find_kline_conf(client_p->host, client_p->username,
			  &client_p->localClient->ip,
			  client_p->localClient->aftype);
  if (aconf == NULL)
    aconf = find_regexp_kline(uhi);

  if (aconf && (aconf->status & CONF_KLINE))
    return aconf;

  return NULL;
}

struct AccessItem *
find_gline(struct Client *client_p)
{
  struct AccessItem *aconf;

  assert(client_p != NULL);

  aconf = find_gline_conf(client_p->host, client_p->username,
                          &client_p->localClient->ip,
                          client_p->localClient->aftype);

  if (aconf && (aconf->status & CONF_GLINE))
    return aconf;

  return NULL;
}

/* add_temp_line()
 *
 * inputs        - pointer to struct ConfItem
 * output        - none
 * Side effects  - links in given struct ConfItem into 
 *                 temporary *line link list
 */
void
add_temp_line(struct ConfItem *conf)
{
  struct AccessItem *aconf;

  if (conf->type == DLINE_TYPE)
  {
    aconf = &conf->conf.AccessItem;
    SetConfTemporary(aconf);
    dlinkAdd(conf, &conf->node, &temporary_dlines);
    MyFree(aconf->user);
    aconf->user = NULL;
    add_conf_by_address(CONF_DLINE, aconf);
  }
  else if (conf->type == KLINE_TYPE)
  {
    aconf = &conf->conf.AccessItem;
    SetConfTemporary(aconf);
    dlinkAdd(conf, &conf->node, &temporary_klines);
    add_conf_by_address(CONF_KILL, aconf);
  }
  else if (conf->type == GLINE_TYPE)
  {
    aconf = &conf->conf.AccessItem;
    SetConfTemporary(aconf);
    dlinkAdd(conf, &conf->node, &temporary_glines);
    add_conf_by_address(CONF_GLINE, aconf);
  }
  else if (conf->type == XLINE_TYPE)
  {
    conf->flags |= CONF_FLAGS_TEMPORARY;
    dlinkAdd(conf, make_dlink_node(), &temporary_xlines);
  }
  else if (conf->type == RXLINE_TYPE)
  {
    conf->flags |= CONF_FLAGS_TEMPORARY;
    dlinkAdd(conf, make_dlink_node(), &temporary_rxlines);
  }
  else if (conf->type == RKLINE_TYPE)
  {
    conf->flags |= CONF_FLAGS_TEMPORARY;
    dlinkAdd(conf, make_dlink_node(), &temporary_rklines);
  }
  else if ((conf->type == NRESV_TYPE) || (conf->type == CRESV_TYPE))
  {
    conf->flags |= CONF_FLAGS_TEMPORARY;
    dlinkAdd(conf, make_dlink_node(), &temporary_resv);
  }
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
  expire_tklines(&temporary_glines);
  expire_tklines(&temporary_klines);
  expire_tklines(&temporary_dlines);
  expire_tklines(&temporary_xlines);
  expire_tklines(&temporary_rxlines);
  expire_tklines(&temporary_rklines);
  expire_tklines(&temporary_resv);
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
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct MatchItem *xconf;
  struct MatchItem *nconf;
  struct AccessItem *aconf;
  struct ResvChannel *cconf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, tklist->head)
  {
    conf = ptr->data;
    if (conf->type == GLINE_TYPE ||
        conf->type == KLINE_TYPE ||
        conf->type == DLINE_TYPE)
    {
      aconf = &conf->conf.AccessItem;
      if (aconf->hold <= CurrentTime)
      {
        /* XXX - Do we want GLINE expiry notices?? */
	/* Alert opers that a TKline expired - Hwy */
        if (ConfigFileEntry.tkline_expire_notices)
        {
	  if (aconf->status & CONF_KILL)
	  {
	    sendto_realops_flags(UMODE_ALL, L_ALL,
				 "Temporary K-line for [%s@%s] expired",
				 (aconf->user) ? aconf->user : "*",
				 (aconf->host) ? aconf->host : "*");
	  }
	  else if (conf->type == DLINE_TYPE)
	  {
	    sendto_realops_flags(UMODE_ALL, L_ALL,
				 "Temporary D-line for [%s] expired",
				 (aconf->host) ? aconf->host : "*");
	  }
        }

	delete_one_address_conf(aconf->host, aconf);
	dlinkDelete(ptr, tklist);
      }
    }
    else if (conf->type == XLINE_TYPE ||
	     conf->type == RXLINE_TYPE)
    {
      xconf = &conf->conf.MatchItem;
      if (xconf->hold <= CurrentTime)
      {
        if (ConfigFileEntry.tkline_expire_notices)
	  sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Temporary X-line for [%s] %sexpired", conf->name,
                               conf->type == RXLINE_TYPE ? "(REGEX) " : "");
	dlinkDelete(ptr, tklist);
        free_dlink_node(ptr);
	delete_conf_item(conf);
      }
    }
    else if (conf->type == RKLINE_TYPE)
    {
      aconf = &conf->conf.AccessItem;
      if (aconf->hold <= CurrentTime)
      {
        if (ConfigFileEntry.tkline_expire_notices)
           sendto_realops_flags(UMODE_ALL, L_ALL,
                                "Temporary K-line for [%s@%s] (REGEX) expired",
                                (aconf->user) ? aconf->user : "*",
                                (aconf->host) ? aconf->host : "*");
        dlinkDelete(ptr, tklist);
        free_dlink_node(ptr);
        delete_conf_item(conf);
      }
    }
    else if (conf->type == NRESV_TYPE)
    {
      nconf = &conf->conf.MatchItem;
      if (nconf->hold <= CurrentTime)
      {
        if (ConfigFileEntry.tkline_expire_notices)
	  sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Temporary RESV for [%s] expired", conf->name);
	dlinkDelete(ptr, tklist);
        free_dlink_node(ptr);
	delete_conf_item(conf);
      }
    }
    else if (conf->type == CRESV_TYPE)
    {
      cconf = &conf->conf.ResvChannel;
      if (cconf->hold <= CurrentTime)
      {
        if (ConfigFileEntry.tkline_expire_notices)
	  sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Temporary RESV for [%s] expired", cconf->name);
	dlinkDelete(ptr, tklist);
        free_dlink_node(ptr);
	delete_conf_item(conf);
      }
    }
  }
}

/*
 * find_regexp_kline
 *
 * inputs	- 
 * output	- return a pointer to an AccessItem if present
 *		  NULL if not
 * side effects	- none
 */
struct AccessItem *
find_regexp_kline(const char *uhi[])
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, rkconf_items.head)
  {
    struct AccessItem *aptr = &((struct ConfItem *)ptr->data)->conf.AccessItem;

    assert(aptr->regexuser);
    assert(aptr->regexhost);

    if (!ircd_pcre_exec(aptr->regexuser, uhi[0]) &&
        (!ircd_pcre_exec(aptr->regexhost, uhi[1]) ||
         !ircd_pcre_exec(aptr->regexhost, uhi[2])))
      return aptr;
  }

  return NULL;
}
