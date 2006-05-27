/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_kline.c: Bans a user.
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
#include "tools.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "list.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_misc.h"
#include "send.h"
#include "hash.h"
#include "handlers.h"
#include "s_serv.h"
#include "msg.h"
#include "s_gline.h"
#include "parse.h"
#include "modules.h"
#include "cluster.h"
#include "tools.h"

static void mo_kline(struct Client *, struct Client *, int, char **);
static void ms_kline(struct Client *, struct Client *, int, char **);
static void mo_dline(struct Client *, struct Client *, int, char **);
static void mo_unkline(struct Client *, struct Client *, int, char **);
static void ms_unkline(struct Client *, struct Client *, int, char **);
static void mo_undline(struct Client *, struct Client *, int, char **);

#ifndef IPV6
static char *make_cidr(char *dlhost, struct Client *);
#endif

static int remove_tkline_match(const char *, const char *);
static int remove_tdline_match(const char *);

struct Message kline_msgtab = {
  "KLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, ms_kline, mo_kline, m_ignore}
};

struct Message dline_msgtab = {
  "DLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, m_error, mo_dline, m_ignore}
};

struct Message unkline_msgtab = {
  "UNKLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, ms_unkline, mo_unkline, m_ignore}
};

struct Message undline_msgtab = {
  "UNDLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, m_error, mo_undline, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&kline_msgtab);
  mod_add_cmd(&unkline_msgtab);
  mod_add_cmd(&dline_msgtab);
  mod_add_cmd(&undline_msgtab);
  add_capability("KLN", CAP_KLN, 1);
  add_capability("UNKLN", CAP_UNKLN, 1);
}

void
_moddeinit(void)
{
  mod_del_cmd(&kline_msgtab);
  mod_del_cmd(&unkline_msgtab);
  mod_del_cmd(&dline_msgtab);
  mod_del_cmd(&undline_msgtab);
  delete_capability("UNKLN");
  delete_capability("KLN");
}

const char *_version = "$Revision: 474 $";
#endif

/* Local function prototypes */

static time_t valid_tkline(char *string);
static char *cluster(char *);
static int find_user_host(struct Client *source_p,
                          char *user_host_or_nick, char *user, char *host);

static int valid_comment(struct Client *source_p, char *comment);
static int valid_user_host(struct Client *source_p, char *user, char *host);
static int valid_wild_card(char *user, char *host);
static int already_placed_kline(struct Client *, const char *, const char *);
static void apply_kline(struct Client *source_p, struct ConfItem *conf,
			const char *, time_t);
static void apply_tkline(struct Client *source_p, struct ConfItem *conf,
                         int temporary_kline_time);


char buffer[IRCD_BUFSIZE];

/*
 * mo_kline
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - k line is added
 *
 */
static void
mo_kline(struct Client *client_p, struct Client *source_p,
	 int parc, char **parv)
{
  char def_reason[] = "No Reason";
  char *reason = def_reason;
  char *oper_reason;
  char user[USERLEN+2];
  char host[HOSTLEN+2];
  const char *current_date;
  const char *target_server=NULL;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  time_t tkline_time = 0;
  time_t cur_time;

  if (!IsOperK(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  parv++;
  parc--;

  tkline_time = valid_tkline(*parv);

  if (tkline_time != 0)
  {
    parv++;
    parc--;
  }

  if (parc == 0)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "KLINE");
    return;
  }

  if (find_user_host(source_p, *parv, user, host) == 0)
    return;

  parc--;
  parv++;

  if (parc != 0)
  {
    if (irccmp(*parv,"ON") == 0)
    {
      parc--;
      parv++;
      if(parc == 0)
      {
	sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
		   me.name, source_p->name, "KLINE");
	return;
      }
      target_server = *parv;
      parc--;
      parv++;
    }
  }

  if (parc != 0)
    reason = *parv;

  if (!valid_user_host(source_p, user,host))
    return;

  if (!valid_wild_card(user,host))
  {
    sendto_one(source_p, 
	   ":%s NOTICE %s :Please include at least %d non-wildcard characters with the user@host",
	       me.name, source_p->name, ConfigFileEntry.min_nonwildcard);
    return;
  }

  if (!valid_comment(source_p, reason))
    return;

  if (target_server != NULL)
  {
    sendto_server(NULL, source_p, NULL, CAP_KLN, NOCAPS, LL_ICLIENT,
                  ":%s KLINE %s %lu %s %s :%s",
                  source_p->name, target_server, (unsigned long)tkline_time,
                  user, host, reason);

    /* If we are sending it somewhere that doesnt include us, we stop
     * else we apply it locally too
     */
    if (!match(target_server, me.name))
      return;
  }
  /* only send the kline to cluster servers if the target was not specified */
  else if (dlink_list_length(&cluster_items))
    cluster_kline(source_p, tkline_time, user, host, reason);

  if (already_placed_kline(source_p, user, host))
    return;

  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
  {
    *oper_reason = '\0';
    oper_reason++;
  }

  set_time();
  cur_time = CurrentTime;
  current_date = smalldate(cur_time);
  conf = make_conf_item(KLINE_TYPE);
  aconf = (struct AccessItem *)map_to_conf(conf);
  DupString(aconf->host, host);
  DupString(aconf->user, user);
  aconf->port = 0;

  if (tkline_time != 0)
  {
    ircsprintf(buffer,
	       "Temporary K-line %d min. - %s (%s)",
	       (int)(tkline_time/60), reason, current_date);
    DupString(aconf->reason, buffer);
    if (oper_reason != NULL)
      DupString(aconf->oper_reason, oper_reason);
    apply_tkline(source_p, conf, tkline_time);
  }
  else
  {
    ircsprintf(buffer, "%s (%s)", reason, current_date);
    DupString(aconf->reason, buffer);
    if (oper_reason != NULL)
      DupString(aconf->oper_reason, oper_reason);
    apply_kline(source_p, conf, current_date, cur_time);
  }
} /* mo_kline() */

/*
 * ms_kline()
 *
 *
 */
static void
ms_kline(struct Client *client_p, struct Client *source_p,
	 int parc, char *parv[])
{
  struct ConfItem *conf=NULL;
  struct AccessItem *aconf=NULL;
  int    tkline_time;
  const char* current_date;
  time_t cur_time;
  char *kuser;
  char *khost;
  char *kreason;

  if (parc != 6)
    return;

  /* parv[0]  parv[1]        parv[2]      parv[3]  parv[4]  parv[5] */
  /* oper     target_server  tkline_time  user     host     reason */
  sendto_server(client_p, source_p, NULL, CAP_KLN, NOCAPS, LL_ICLIENT,
                ":%s KLINE %s %s %s %s :%s",
                parv[0], parv[1], parv[2], parv[3], parv[4], parv[5]);


  kuser   = parv[3];
  khost   = parv[4];
  kreason = parv[5];

  if (!match(parv[1],me.name))
    return;

  if (!IsPerson(source_p))
    return;

  if (find_matching_name_conf(CLUSTER_TYPE, source_p->user->server->name,
                              NULL, NULL, CLUSTER_KLINE))
  {
    if (!valid_user_host(source_p, kuser, khost) || !valid_wild_card(kuser, khost) ||
        !valid_comment(source_p, kreason) || already_placed_kline(source_p, kuser, khost))
      return;

    tkline_time = atoi(parv[2]);

    set_time();
    cur_time = CurrentTime;
    current_date = smalldate(cur_time);

    conf = make_conf_item(KLINE_TYPE);
    aconf = (struct AccessItem *)map_to_conf(conf);
    DupString(aconf->user, kuser);
    DupString(aconf->host, khost);
    DupString(aconf->reason, kreason);

    if (tkline_time != 0)
      apply_tkline(source_p, conf, tkline_time);
    else
      apply_kline(source_p, conf, current_date, cur_time);
  }
  else if (find_matching_name_conf(ULINE_TYPE,
				  source_p->user->server->name,
				  source_p->username, source_p->host,
				  SHARED_KLINE))
  {
    if (!valid_user_host(source_p, kuser, khost))
      return;

    if (!valid_wild_card(kuser, khost))
    {
      sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the user@host",
                 me.name, source_p->name, ConfigFileEntry.min_nonwildcard);
      return;
    }

    if (!valid_comment(source_p, kreason))
      return;

    /* We check if the kline already exists after we've announced its
     * arrived, to avoid confusing opers - fl
     */
    if (already_placed_kline(source_p, kuser, khost))
      return;

    tkline_time = atoi(parv[2]);

    set_time();
    cur_time = CurrentTime;
    current_date = smalldate(cur_time);

    conf = make_conf_item(KLINE_TYPE);
    aconf = (struct AccessItem *)map_to_conf(conf);
    DupString(aconf->host, khost);
    DupString(aconf->reason, kreason);
    DupString(aconf->user, kuser);

    if (tkline_time != 0)
      apply_tkline(source_p, conf, tkline_time);
    else
      apply_kline(source_p, conf, current_date, cur_time);
  }

} /* ms_kline() */

/* apply_kline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- kline as given, is added to the hashtable
 *		  and conf file
 */
static void 
apply_kline(struct Client *source_p, struct ConfItem *conf,
	    const char *current_date, time_t cur_time)
{
  struct AccessItem *aconf;

  aconf = (struct AccessItem *)map_to_conf(conf);
  add_conf_by_address(CONF_KILL, aconf);
  write_conf_line(source_p, conf, current_date, cur_time);
  /* Now, activate kline against current online clients */
  rehashed_klines = 1;
}

/* apply_tkline()
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_tkline(struct Client *source_p, struct ConfItem *conf,
             int tkline_time)
{
  struct AccessItem *aconf;

  aconf = (struct AccessItem *)map_to_conf(conf);
  aconf->hold = CurrentTime + tkline_time;
  add_temp_kline(aconf);
  sendto_realops_flags(UMODE_ALL, L_ALL,
		       "%s added temporary %d min. K-Line for [%s@%s] [%s]",
		       get_oper_name(source_p), tkline_time/60,
		       aconf->user, aconf->host,
		       aconf->reason);
  sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. K-Line [%s@%s]",
	     me.name, source_p->name, tkline_time/60,
	     aconf->user, aconf->host);
  ilog(L_TRACE, "%s added temporary %d min. K-Line for [%s@%s] [%s]",
       source_p->name, tkline_time/60,
       aconf->user, aconf->host, aconf->reason);
  rehashed_klines = 1;
}

/*
 * apply_tdline
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_tdline(struct Client *source_p, struct ConfItem *conf,
	     const char *current_date, int tkline_time)
{
  struct AccessItem *aconf;

  aconf = (struct AccessItem *)map_to_conf(conf);
  aconf->hold = CurrentTime + tkline_time;

  add_temp_dline(aconf);
  sendto_realops_flags(UMODE_ALL, L_ALL,
		       "%s added temporary %d min. D-Line for [%s] [%s]",
		       get_oper_name(source_p), tkline_time/60,
		       aconf->host, aconf->reason);

  sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. D-Line [%s]",
	     me.name, source_p->name, tkline_time/60, aconf->host);
  ilog(L_TRACE, "%s added temporary %d min. D-Line for [%s] [%s]",
       source_p->name, tkline_time/60, aconf->host, aconf->reason);
  rehashed_klines = 1;
}

/*
 * valid_tkline()
 * 
 * inputs       - pointer to ascii string to check
 * output       - -1 not enough parameters
 *              - 0 if not an integer number, else the number
 * side effects - none
 */
static time_t
valid_tkline(char *p)
{
  time_t result = 0;

  while(*p)
  {
    if(IsDigit(*p))
    {
      result *= 10;
      result += ((*p) & 0xF);
      p++;
    }
    else
      return(0);
  }
  /* in the degenerate case where oper does a /quote kline 0 user@host :reason 
   * i.e. they specifically use 0, I am going to return 1 instead
   * as a return value of non-zero is used to flag it as a temporary kline
   */

  if(result == 0)
    result = 1;

  if(result > MAX_TDKLINE_TIME)
    result = MAX_TDKLINE_TIME;

  result = (time_t)result * (time_t)60;  /* turn it into seconds */

  return(result);
}

/*
 * cluster()
 *
 * inputs       - pointer to a hostname
 * output       - pointer to a static of the hostname masked
 *                for use in a kline.
 * side effects - NONE
 *
 */
static char *
cluster(char *hostname)
{
  static char result[HOSTLEN + 1];      /* result to return */
  char        temphost[HOSTLEN + 1];    /* work place */
  char        *ipp;             /* used to find if host is ip # only */
  char        *host_mask;       /* used to find host mask portion to '*' */
  char        *zap_point = NULL; /* used to zap last nnn portion of an ip # */
  char        *tld;             /* Top Level Domain */
  int         is_ip_number;     /* flag if its an ip # */             
  int         number_of_dots;   /* count number of dots for both ip# and
                                   domain klines */
  if (hostname == NULL)
    return(NULL);       /* EEK! */

  /* If a '@' is found in the hostname, this is bogus
   * and must have been introduced by server that doesn't
   * check for bogus domains (dns spoof) very well. *sigh* just return it...
   * I could also legitimately return (char *)NULL as above.
   */

  if(strchr(hostname,'@'))      
    {
      strlcpy(result, hostname, sizeof(result));
      return(result);
    }

  strlcpy(temphost, hostname, sizeof(temphost));

  is_ip_number = YES;   /* assume its an IP# */
  ipp = temphost;
  number_of_dots = 0;

  while (*ipp)
    {
      if(*ipp == '.')
        {
          number_of_dots++;

          if(number_of_dots == 3)
            zap_point = ipp;
          ipp++;
        }
      else if(!IsDigit(*ipp))
        {
          is_ip_number = NO;
          break;
        }
      ipp++;
    }

  if (is_ip_number && (number_of_dots == 3))
    {
      zap_point++;
      *zap_point++ = '*';               /* turn 111.222.333.444 into */
      *zap_point = '\0';                /*      111.222.333.*        */
      strlcpy(result, temphost, sizeof(result));
      return(result);
    }
  else
    {
      tld = strrchr(temphost, '.');
      if(tld)
        {
          number_of_dots = 2;
          if(tld[3])                     /* its at least a 3 letter tld
                                            i.e. ".com" tld[3] = 'm' not 
                                            '\0' */
                                         /* 4 letter tld's are coming */
            number_of_dots = 1;

          if(tld != temphost)           /* in these days of dns spoofers ...*/
            host_mask = tld - 1;        /* Look for host portion to '*' */
          else
            host_mask = tld;            /* degenerate case hostname is
                                           '.com' etc. */

          while (host_mask != temphost)
            {
              if(*host_mask == '.')
                number_of_dots--;
              if(number_of_dots == 0)
                {
                  result[0] = '*';
                  strlcpy(result + 1, host_mask, sizeof(result) - 1);
                  return(result);
                }
              host_mask--;
            }
          result[0] = '*';                      /* foo.com => *foo.com */
          strlcpy(result + 1, temphost, sizeof(result) - 1);
        }
      else      /* no tld found oops. just return it as is */
        {
          strlcpy(result, temphost, sizeof(result));
          return(result);
        }
    }

  return(result);
}

/* mo_dline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - D line is added
 *
 */
static void
mo_dline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char def_reason[] = "No Reason";
  char *dlhost, *oper_reason, *reason;
  const char *creason;
#ifndef IPV6
  struct Client *target_p;
#endif
  struct irc_ssaddr daddr;
  struct ConfItem *conf=NULL;
  struct AccessItem *aconf=NULL;
  time_t tkline_time=0;
  int bits, t;
  const char* current_date;
  time_t cur_time;

  if (!IsOperK(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  parv++;
  parc--;

  tkline_time = valid_tkline(*parv);

  if (tkline_time > 0)
  {
    parv++;
    parc--;
  }

  if (parc == 0)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "DLINE");
    return;
  }

  dlhost = *parv;

  if ((t=parse_netmask(dlhost, NULL, &bits)) == HM_HOST)
  {
#ifdef IPV6 
   sendto_one(source_p, ":%s NOTICE %s :Sorry, please supply an address.",
              me.name, parv[0]);
   return;
#else
   if ((target_p = find_chasing(source_p, dlhost, NULL)) == NULL)
     return;

   if(target_p->user == NULL)
     return;
   t = HM_IPV4;
   if (IsServer(target_p))
   {
     sendto_one(source_p,
		":%s NOTICE %s :Can't DLINE a server silly",
		me.name, source_p->name);
     return;
   }
              
   if (!MyConnect(target_p))
   {
     sendto_one(source_p,
		":%s NOTICE %s :Can't DLINE nick on another server",
		me.name, source_p->name);
     return;
   }

   if (IsExemptKline(target_p))
   {
     sendto_one(source_p,
		":%s NOTICE %s :%s is E-lined",me.name,
		source_p->name,	target_p->name);
     return;
   }

   if ((dlhost = make_cidr(dlhost, target_p)) == NULL)
     return;

   bits = 0xFFFFFF00UL;
#endif
    }

  parc--;
  parv++;

  if (parc != 0) /* host :reason */
  {
    if (valid_comment(source_p, *parv) == 0)
      return;

    if (*parv[0] != '\0')
      reason = *parv;
    else
      reason = def_reason;
  }
  else
    reason = def_reason;

  if (bits < 8)
  {
    sendto_one(source_p,
	":%s NOTICE %s :For safety, bitmasks less than 8 require conf access.",
	       me.name, source_p->name);
    return;
  }


#ifdef IPV6
  if (t == HM_IPV6)
    t = AF_INET6;
  else
#endif
    t = AF_INET;

  (void)parse_netmask(dlhost, &daddr, NULL);

  if ((aconf = find_dline_conf(&daddr, t)) != NULL)
  {
    creason = aconf->reason ? aconf->reason : def_reason;
    if (IsConfExemptKline(aconf))
      sendto_one(source_p,
		 ":%s NOTICE %s :[%s] is (E)d-lined by [%s] - %s",
		 me.name, source_p->name, dlhost, aconf->host, creason);
    else
      sendto_one(source_p,
		 ":%s NOTICE %s :[%s] already D-lined by [%s] - %s",
		 me.name, source_p->name, dlhost, aconf->host, creason);
    return;
  }

  set_time();
  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
  {
    *oper_reason = '\0';
    oper_reason++;
  }

  if (!valid_comment(source_p, reason))
    return;

  conf = make_conf_item(DLINE_TYPE);
  aconf = (struct AccessItem *)map_to_conf(conf);
  DupString(aconf->host, dlhost);

  if (tkline_time != 0)
  {
    ircsprintf(buffer, "Temporary D-line %d min. - %s (%s)",
	       (int)(tkline_time/60), reason, current_date);
    DupString(aconf->reason, buffer);
    apply_tdline(source_p, conf, current_date, tkline_time);
  }
  else
  {
    ircsprintf(buffer, "%s (%s)", reason, current_date);
    DupString(aconf->reason, buffer);
    add_conf_by_address(CONF_DLINE, aconf);
    write_conf_line(source_p, conf, current_date, cur_time);
  }

  rehashed_klines = 1;
} /* mo_dline() */

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
               char *luser, char *lhost)
{
  struct Client *target_p;
  char *hostp;

  if ((hostp = strchr(user_host_or_nick, '@')) || *user_host_or_nick == '*')
  {
    /* Explicit user@host mask given */

    if(hostp != NULL)                            /* I'm a little user@host */
    {
      *(hostp++) = '\0';                       /* short and squat */
      if (*user_host_or_nick)
	strlcpy(luser,user_host_or_nick,USERLEN + 1); /* here is my user */
      else
	strcpy(luser,"*");
      if (*hostp)
	strlcpy(lhost, hostp, HOSTLEN + 1);    /* here is my host */
      else
	strcpy(lhost,"*");
    }
    else
    {
      luser[0] = '*';             /* no @ found, assume its *@somehost */
      luser[1] = '\0';	  
      strlcpy(lhost, user_host_or_nick, HOSTLEN + 1);
    }
    
    return(1);
  }
  else
  {
    /* Try to find user@host mask from nick */
    
    if (!(target_p = find_chasing(source_p, user_host_or_nick, NULL)))
      return(0);

    if (target_p->user == NULL)
      return(0);

    if (IsServer(target_p))
    {
      sendto_one(source_p,
	   ":%s NOTICE %s :Can't KLINE a server, use @'s where appropriate",
		 me.name, source_p->name);
      return(0);
    }

    if(IsExemptKline(target_p))
    {
      if(!IsServer(source_p))
	sendto_one(source_p,
		   ":%s NOTICE %s :%s is E-lined",
		   me.name, source_p->name, target_p->name);
      return(0);
    }

    /* turn the "user" bit into "*user", blow away '~'
     * if found in original user name (non-idented)
     */

    strlcpy(luser, target_p->username, USERLEN + 1);
    if (*target_p->username == '~')
      luser[0] = '*';

    strlcpy(lhost,cluster(target_p->host), HOSTLEN + 1);
  }

  return(1);
}

/* valid_user_host()
 *
 * inputs       - pointer to source
 *              - pointer to user buffer
 *              - pointer to host buffer
 * output	- 1 if valid user or host, 0 if invalid
 * side effects -
 */
static int
valid_user_host(struct Client *source_p, char *luser, char *lhost)
{
  /*
   * Check for # in user@host
   */
  if (strchr(lhost, '#') || strchr(luser, '#'))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid character '#' in kline",
               me.name, source_p->name);		    
    return(0);
  }

  /* Dont let people kline *!ident@host, as the ! is invalid.. */
  if (strchr(luser, '!'))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid character '!' in kline",
               me.name, source_p->name);
    return(0);
  }

  return(1);
}

/* valid_wild_card()
 *
 * input        - pointer to client
 *              - pointer to user to check
 *              - pointer to host to check
 * output       - 0 if not valid, 1 if valid
 * side effects -
 */
static int
valid_wild_card(char *luser, char *lhost)
{
  char *p;
  char tmpch;
  int nonwild;

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

  nonwild = 0;
  p = luser;
  while ((tmpch = *p++))
  {
    if (!IsKWildChar(tmpch))
    {
      /*
       * If we find enough non-wild characters, we can
       * break - no point in searching further.
       */
      if (++nonwild >= ConfigFileEntry.min_nonwildcard)
        break;
    }
  }

  if (nonwild < ConfigFileEntry.min_nonwildcard)
  {
    /*
     * The user portion did not contain enough non-wild
     * characters, try the host.
     */
    p = lhost;
    while ((tmpch = *p++))
    {
      if (!IsKWildChar(tmpch))
        if (++nonwild >= ConfigFileEntry.min_nonwildcard)
          break;
    }
  }

  if (nonwild < ConfigFileEntry.min_nonwildcard)
    return(0);
  else
    return(1);
}

/* valid_comment()
 *
 * inputs	- pointer to client
 *              - pointer to comment
 * output       - 0 if no valid comment,
 *              - 1 if valid
 * side effects - truncates reason where necessary
 */
static int
valid_comment(struct Client *source_p, char *comment)
{
  if (strchr(comment, '"'))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid character '\"' in comment",
               me.name, source_p->name);
    return(0);
  }

  if (strlen(comment) > REASONLEN)
    comment[REASONLEN-1] = '\0';

  return(1);
}

/* already_placed_kline()
 * inputs	- user to complain to, username & host to check for
 * outputs	- returns 1 on existing K-line, 0 if doesn't exist
 * side effects	- notifies source_p if the K-line already exists
 */
/*
 * Note: This currently works if the new K-line is a special case of an
 *       existing K-line, but not the other way round. To do that we would
 *       have to walk the hash and check every existing K-line. -A1kmm.
 */
static int
already_placed_kline(struct Client *source_p, const char *luser, const char *lhost)
{
  const char *reason;
  struct irc_ssaddr iphost, *piphost;
  struct AccessItem *aconf;
  int t;

  if ((t=parse_netmask(lhost, &iphost, &t)) != HM_HOST)
  {
#ifdef IPV6
    if (t == HM_IPV6)
      t = AF_INET6;
    else
#endif
      t = AF_INET;
    piphost = &iphost;
  }
  else
  {
    t = 0;
    piphost = NULL;
  }

  if ((aconf = find_conf_by_address(lhost, piphost, CONF_KILL, t, luser, NULL)))
  {
    reason = aconf->reason ? aconf->reason : "No Reason";

    sendto_one(source_p,
               ":%s NOTICE %s :[%s@%s] already K-Lined by [%s@%s] - %s",
               me.name, source_p->name, luser, lhost, aconf->user,
               aconf->host, reason);
    return(1);
  }

  return(0);
}

#ifndef IPV6 
static char *
make_cidr(char *dlhost, struct Client *target_p)
{
  static char cidr_form_host[HOSTLEN + 2];
  char *p;

  strlcpy(cidr_form_host, inetntoa((const char *)&target_p->localClient->ip),
          sizeof(cidr_form_host));

  if ((p = strchr(cidr_form_host,'.')) == NULL)
    return(NULL);

  /* 192. <- p */
   p++;
   if ((p = strchr(p,'.')) == NULL)
     return(NULL);

   /* 192.168. <- p */
   p++;
   if ((p = strchr(p,'.')) == NULL)
     return(NULL);

   /* 192.168.0. <- p */
   p++;
   *p++ = '0';
   *p++ = '/';
   *p++ = '2';
   *p++ = '4';
   *p++ = '\0';

   return(cidr_form_host);
}
#endif

/*
** mo_unkline
** Added Aug 31, 1997 
** common (Keith Fralick) fralick@gate.net
**
**      parv[0] = sender
**      parv[1] = address to remove
*
*
*/
static void
mo_unkline(struct Client *client_p,struct Client *source_p,
           int parc, char *parv[])
{
  char star[] = "*";
  char *user, *host;

  if (!IsOperUnkline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if (parc < 2)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "UNKLINE");
    return;
  }

  if ((host = strchr(parv[1], '@')) || *parv[1] == '*')
  {
    /* Explicit user@host mask given */
    if (host)                  /* Found user@host */
    {
          user = parv[1];       /* here is user part */
          *(host++) = '\0';     /* and now here is host */
    }
    else
    {
      user = star;           /* no @ found, assume its *@somehost */
      host = parv[1];
    }
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid parameters",
               me.name, source_p->name);
    return;
  }

  /* UNKLINE bill@mu.org ON irc.mu.org */
  if ((parc > 3) && (irccmp(parv[2], "ON") == 0))
  {
    sendto_match_servs(source_p, parv[3], CAP_UNKLN,
                       "UNKLINE %s %s %s",
                       parv[3], user, host);

    if (!match(parv[3], me.name))
      return;
  }
  else if (dlink_list_length(&cluster_items))
    cluster_unkline(source_p, user, host);

  if (remove_tkline_match(host, user))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Un-klined [%s@%s] from temporary K-Lines",
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary K-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed temporary K-Line for [%s@%s]",
         source_p->name, user, host);
    return;
  }

  if (remove_conf_line(KLINE_TYPE, source_p, user, host) > 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :K-Line for [%s@%s] is removed", 
	       me.name, source_p->name, user,host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
			 "%s has removed the K-Line for: [%s@%s]",
			 get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed K-Line for [%s@%s]",
	 source_p->name, user, host);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No K-Line for [%s@%s] found", 
	       me.name, source_p->name, user, host);
}

/* ms_unkline()
 *
 * inputs	- server
 *		- client
 *		- parc
 *		- parv
 * outputs	- none
 * side effects	- if server is authorized, kline is removed
 */
static void
ms_unkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char *kuser, *khost;

  if (parc != 4)
    return;

  sendto_match_servs(source_p, parv[1], CAP_UNKLN,
                     "UNKLINE %s %s %s",
                     parv[1], parv[2], parv[3]);

  kuser = parv[2];
  khost = parv[3];

  if (!match(parv[1], me.name))
    return;

  if (!IsPerson(source_p))
    return;
  if (find_matching_name_conf(CLUSTER_TYPE, source_p->user->server->name,
                              NULL, NULL, CLUSTER_UNKLINE))
  {
    if (remove_tkline_match(khost, kuser))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has removed the temporary K-Line for: [%s@%s]",
                           get_oper_name(source_p), kuser, khost);
      ilog(L_NOTICE, "%s removed temporary K-Line for [%s@%s]",
           source_p->name, kuser, khost);
      return;
    }

    if (remove_conf_line(KLINE_TYPE, source_p, kuser, khost))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has removed the K-Line for: [%s@%s]",
                           get_oper_name(source_p), kuser, khost);

      ilog(L_NOTICE, "%s removed K-Line for [%s@%s]",
           source_p->name, kuser, khost);
    }
  }
  else if (find_matching_name_conf(ULINE_TYPE,
				   source_p->user->server->name,
				   source_p->username, source_p->host,
				   SHARED_UNKLINE))
  {
    if (remove_tkline_match(khost, kuser))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Un-klined [%s@%s] from temporary K-Lines",
                 me.name, source_p->name, kuser, khost);
      sendto_realops_flags(UMODE_ALL, L_ALL,  
                           "%s has removed the temporary K-Line for: [%s@%s]",
                           get_oper_name(source_p), kuser, khost);
      ilog(L_NOTICE, "%s removed temporary K-Line for [%s@%s]",
           source_p->name, kuser, khost);
      return;
    }

    if (remove_conf_line(KLINE_TYPE, source_p, kuser, khost) > 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :K-Line for [%s@%s] is removed",
                 me.name, source_p->name, kuser, khost);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has removed the K-Line for: [%s@%s]",
                         get_oper_name(source_p), kuser, khost);

      ilog(L_NOTICE, "%s removed K-Line for [%s@%s]",
           source_p->name, kuser, khost);
    }
    else
      sendto_one(source_p, ":%s NOTICE %s :No K-Line for [%s@%s] found",
                 me.name, source_p->name, kuser, khost);
  }
}

/* static int remove_tkline_match(const char *host, const char *user)
 * Input: A hostname, a username to unkline.
 * Output: returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static int
remove_tkline_match(const char *host, const char *user)
{
  struct AccessItem *tk_c;
  dlink_node *tk_n;
  struct irc_ssaddr addr, caddr;
  int nm_t, cnm_t, bits, cbits;
  nm_t = parse_netmask(host, &addr, &bits);

  for (tk_n=temporary_klines.head; tk_n; tk_n=tk_n->next)
  {
    tk_c = (struct AccessItem*)tk_n->data;
    cnm_t = parse_netmask(tk_c->host, &caddr, &cbits);
    if (cnm_t != nm_t || irccmp(user, tk_c->user))
      continue;
    if ((nm_t==HM_HOST && !irccmp(tk_c->host, host)) ||
	(nm_t==HM_IPV4 && bits==cbits && match_ipv4(&addr, &caddr, bits))
#ifdef IPV6
	|| (nm_t==HM_IPV6 && bits==cbits && match_ipv6(&addr, &caddr, bits))
#endif
	)
      {
	dlinkDelete(tk_n, &temporary_klines);
	free_dlink_node(tk_n);
	delete_one_address_conf(tk_c->host, tk_c);
	return(YES);
      }
  }

  return(NO);
}

/* static int remove_tdline_match(const char *host, const char *user)
 * Input: An ip to undline.
 * Output: returns YES on success, NO if no tdline removed.
 * Side effects: Any matching tdlines are removed.
 */
static int
remove_tdline_match(const char *cidr)
{
  struct AccessItem *td_conf;
  dlink_node *td_node;
  struct irc_ssaddr addr, caddr;
  int nm_t, cnm_t, bits, cbits;
  nm_t = parse_netmask(cidr, &addr, &bits);

  for (td_node = temporary_dlines.head; td_node; td_node = td_node->next)
  {
    td_conf = (struct AccessItem *)td_node->data;
    cnm_t   = parse_netmask(td_conf->host, &caddr, &cbits);

    if (cnm_t != nm_t)
      continue;

    if((nm_t==HM_HOST && !irccmp(td_conf->host, cidr)) ||
       (nm_t==HM_IPV4 && bits==cbits && match_ipv4(&addr, &caddr, bits))
#ifdef IPV6
       || (nm_t==HM_IPV6 && bits==cbits && match_ipv6(&addr, &caddr, bits))
#endif
      )
    {
      dlinkDelete(td_node, &temporary_dlines);
      free_dlink_node(td_node);
      delete_one_address_conf(td_conf->host, td_conf);
      return(YES);
    }
  }

  return(NO);
}

/*
** m_undline
** added May 28th 2000 by Toby Verrall <toot@melnet.co.uk>
** based totally on m_unkline
** added to hybrid-7 7/11/2000 --is
**
**      parv[0] = sender nick
**      parv[1] = dline to remove
*/
static void
mo_undline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char  *cidr;

  if (!IsOperUnkline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  cidr = parv[1];

  if (remove_tdline_match(cidr))
  {
    sendto_one(source_p,
              ":%s NOTICE %s :Un-Dlined [%s] from temporary D-Lines",
              me.name, source_p->name, cidr);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary D-Line for: [%s]",
                         get_oper_name(source_p), cidr);
    ilog(L_NOTICE, "%s removed temporary D-Line for [%s]", source_p->name, cidr);
    return;
  }

  if (remove_conf_line(DLINE_TYPE, source_p, cidr, NULL) > 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :D-Line for [%s] is removed",
               me.name, source_p->name, cidr);
    sendto_realops_flags(UMODE_ALL, L_ALL,
			 "%s has removed the D-Line for: [%s]",
			 get_oper_name(source_p), cidr);
    ilog(L_NOTICE, "%s removed D-Line for [%s]",
         get_oper_name(source_p), cidr);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No D-Line for [%s] found",
               me.name, source_p->name, cidr);
}
