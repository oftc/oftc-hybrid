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
#include "m_kline.h"
#include "channel.h"
#include "class.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
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
#include "parse.h"
#include "modules.h"

static void mo_kline(struct Client *,struct Client *,int,char **);
static void ms_kline(struct Client *,struct Client *,int,char **);
static void mo_dline(struct Client *,struct Client *,int,char **);

struct Message kline_msgtab = {
  "KLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_kline, mo_kline}
};

struct Message dline_msgtab = {
  "DLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_error, mo_dline}
};

#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&kline_msgtab);
  mod_add_cmd(&dline_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&kline_msgtab);
  mod_del_cmd(&dline_msgtab);
}
const char *_version = "$Revision$";
#endif

/* Local function prototypes */

static time_t  valid_tkline(struct Client *source_p, char *string);
static char *cluster(char *);
static int find_user_host(struct Client *source_p,
                          char *user_host_or_nick, char *user, char *host);

/* needed to remove unused definition warning */
static int valid_comment(struct Client *source_p, char *comment);
static int valid_user_host(struct Client *source_p, char *user, char *host);
static int valid_wild_card(char *user, char *host);
static int already_placed_kline(struct Client*, char*, char*);
static void apply_kline(struct Client *source_p, struct ConfItem *aconf,
                        const char *reason, const char *oper_reason,
			const char *current_date, time_t cur_time);

static void apply_tkline(struct Client *source_p, struct ConfItem *aconf,
                         const char *current_date, int temporary_kline_time);


char buffer[IRCD_BUFSIZE];
char user[USERLEN+2];
char host[HOSTLEN+2];

#define MAX_EXT_REASON 100


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
  char *reason = "No Reason";
  char *oper_reason;
  const char* current_date;
  const char* target_server=NULL;
  struct ConfItem *aconf;
  time_t tkline_time=0;
  time_t cur_time;

  if (!IsOperK(source_p))
    {
      sendto_one(source_p,":%s NOTICE %s :You need kline = yes;",
		 me.name,source_p->name);
      return;
    }

  parv++;
  parc--;

  tkline_time = valid_tkline(source_p,*parv);

  if (tkline_time > 0)
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

  if(parc != 0)
    reason = *parv;

  if (valid_user_host(source_p, user,host))
     return;

  if (valid_wild_card(user,host))
    {
       sendto_one(source_p, 
          ":%s NOTICE %s :Please include at least %d non-wildcard characters with the user@host",
           me.name,
           source_p->name,
           ConfigFileEntry.min_nonwildcard);
       return;
    }

  if (!valid_comment(source_p, reason))
    return;

  set_time();  
  cur_time = CurrentTime;
  current_date = smalldate(cur_time);
  aconf = make_conf();
  aconf->status = CONF_KILL;
  DupString(aconf->host, host);
  DupString(aconf->user, user);
  aconf->port = 0;

  if (target_server != NULL)
    {
      sendto_server(NULL, source_p, NULL, CAP_KLN, NOCAPS, LL_ICLIENT,
                    ":%s KLINE %s %lu %s %s :%s",
                    source_p->name,
                    target_server,
                    (unsigned long) tkline_time,
                    user, host, reason);

      /* If we are sending it somewhere that doesnt include us, we stop
       * else we apply it locally too
       */
      if (!match(target_server, me.name))
	   return;
    }

  if (already_placed_kline(source_p, user, host))
   return;


  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
    {
      *oper_reason = '\0';
      oper_reason++;
    }

  if (tkline_time)
    {
      ircsprintf(buffer,
		 "Temporary K-line %d min. - %s (%s)",
		 (int)(tkline_time/60),
		 reason,
		 current_date);
      DupString(aconf->passwd, buffer);
      apply_tkline(source_p, aconf, current_date, tkline_time);
    }
  else
    {
      ircsprintf(buffer, "%s (%s)",
		 reason,
		 current_date);
      DupString(aconf->passwd, buffer);
      apply_kline(source_p, aconf, reason, oper_reason,
		  current_date, cur_time);
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
  const char *current_date;
  struct ConfItem *aconf=NULL;
  int    tkline_time;
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


  kuser = parv[3];
  khost = parv[4];
  kreason = parv[5];

  if (!match(parv[1],me.name))
    return;

  if (!IsPerson(source_p))
    return;

  if (valid_user_host(source_p, kuser, khost))
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
             "*** %s!%s@%s on %s is requesting an Invalid K-Line for [%s@%s] [%s]",
             source_p->name, source_p->username, source_p->host, source_p->user->server,
             kuser, khost, kreason);
      return;
    }

  if (valid_wild_card(kuser, khost))
    {
       sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL, 
             "*** %s!%s@%s on %s is requesting a K-Line without %d wildcard chars for [%s@%s] [%s]",
             source_p->name, source_p->username, source_p->host, source_p->user->server,
             ConfigFileEntry.min_nonwildcard, kuser, khost, kreason);
       return;
     }

  if(!valid_comment(source_p, kreason))
    return;

  tkline_time = atoi(parv[2]);

/* We don't care about this on oftc - stu 
 * if (find_u_conf((char *)source_p->user->server,
		  source_p->username, source_p->host))
          */
  sendto_realops_flags(FLAGS_ALL, L_OPER, 
        "*** Received K-Line for [%s@%s] [%s], from %s!%s@%s on %s",
        kuser, khost, kreason,
        source_p->name, source_p->username,
        source_p->host, source_p->user->server);

      /* We check if the kline already exists after we've announced its 
       * arrived, to avoid confusing opers - fl
       */
  if (already_placed_kline(source_p, kuser, khost))
    return;

  aconf = make_conf();

  aconf->status = CONF_KILL;
  DupString(aconf->user, kuser);
  DupString(aconf->host, khost);
  DupString(aconf->passwd, kreason);
  current_date = smalldate((time_t) 0);
  set_time();
  cur_time = CurrentTime;

  if (tkline_time)
	apply_tkline(source_p, aconf, current_date, tkline_time);
  else
	apply_kline(source_p, aconf, aconf->passwd, NULL,
		    current_date, cur_time);

} /* ms_kline() */

/*
 * apply_kline
 *
 * inputs	-
 * output	- NONE
 * side effects	- kline as given, is added to the hashtable
 *		  and conf file
 */
static void 
apply_kline(struct Client *source_p, struct ConfItem *aconf,
	    const char *reason, const char *oper_reason,
	    const char *current_date, time_t cur_time)
{
  add_conf_by_address(aconf->host, CONF_KILL, aconf->user, aconf);
  WriteKlineOrDline(KLINE_TYPE, source_p, aconf->user, aconf->host,
		    reason, oper_reason, current_date, cur_time);
  /* Now, activate kline against current online clients */
  check_klines();
}

/*
 * apply_tkline
 *
 * inputs	-
 * output	- NONE
 * side effects	- tkline as given is placed
 */
static void
apply_tkline(struct Client *source_p, struct ConfItem *aconf,
                         const char *current_date, int tkline_time)
{
  aconf->hold = CurrentTime + tkline_time;
  add_temp_kline(aconf);
  sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
		       "%s added temporary %d min. K-Line for [%s@%s] [%s]",
		       get_oper_name(source_p), tkline_time/60,
		       aconf->user, aconf->host,
		       aconf->passwd);
  sendto_one(source_p, ":%s NOTICE %s :Added temporary %d min. K-Line [%s@%s]",
	     me.name, source_p->name, tkline_time/60,
	     aconf->user, aconf->host);
  ilog(L_TRACE, "%s added temporary %d min. K-Line for [%s@%s] [%s]",
       source_p->name, tkline_time/60,
       aconf->user, aconf->host, aconf->passwd);
  check_klines();
}

/*
 * valid_tkline()
 * 
 * inputs       - pointer to client requesting kline
 *              - argument count
 *              - pointer to ascii string in
 * output       - -1 not enough parameters
 *              - 0 if not an integer number, else the number
 * side effects - none
 */
static time_t
valid_tkline(struct Client *source_p, char *p)
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

  if(result > (24*60))
    result = (24*60); /* Max it at 24 hours */

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
  if (!hostname)
    return (char *) NULL;       /* EEK! */

  /* If a '@' is found in the hostname, this is bogus
   * and must have been introduced by server that doesn't
   * check for bogus domains (dns spoof) very well. *sigh* just return it...
   * I could also legitimately return (char *)NULL as above.
   */

  if(strchr(hostname,'@'))      
    {
      strlcpy(result, hostname, HOSTLEN + 1);
      return(result);
    }

  strlcpy(temphost, hostname, HOSTLEN + 1);

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
      strlcpy(result, temphost, HOSTLEN + 1);
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
                  strlcpy(result + 1, host_mask, HOSTLEN + 1);
                  return(result);
                }
              host_mask--;
            }
          result[0] = '*';                      /* foo.com => *foo.com */
          strlcpy(result + 1, temphost, HOSTLEN + 1);
        }
      else      /* no tld found oops. just return it as is */
        {
          strlcpy(result, temphost, HOSTLEN + 1);
          return(result);
        }
    }

  return (result);
}

/*
 * mo_dline
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
  char *dlhost, *reason, *oper_reason;
#ifndef IPV6
  char *p;
  struct Client *target_p;
#endif
  struct irc_inaddr daddr;
  char cidr_form_host[HOSTLEN + 1];
  struct ConfItem *aconf;
  int bits, t;
  char dlbuffer[1024];
  const char* current_date;
  time_t cur_time;

  if (!IsOperK(source_p))
    {
      sendto_one(source_p,":%s NOTICE %s :You need kline = yes;",
		 me.name, parv[0]);
      return;
    }

  dlhost = parv[1];
  strlcpy(cidr_form_host, dlhost, HOSTLEN + 1);
  cidr_form_host[HOSTLEN] = '\0';

  if ((t=parse_netmask(dlhost, NULL, &bits)) == HM_HOST)
  {
#ifdef IPV6
   sendto_one(source_p, ":%s NOTICE %s :Sorry, please supply an address.",
              me.name, parv[0]);
   return;
#else
      if (!(target_p = find_chasing(source_p, parv[1], NULL)))
        return;

      if(!target_p->user)
        return;
      t = HM_IPV4;
      if (IsServer(target_p))
        {
          sendto_one(source_p,
                     ":%s NOTICE %s :Can't DLINE a server silly",
                     me.name, parv[0]);
          return;
        }
              
      if (!MyConnect(target_p))
        {
          sendto_one(source_p,
                     ":%s NOTICE :%s :Can't DLINE nick on another server",
                     me.name, parv[0]);
          return;
        }

      if (IsExemptKline(target_p))
        {
          sendto_one(source_p,
                     ":%s NOTICE %s :%s is E-lined",me.name,parv[0],
                     target_p->name);
          return;
        }

      /*
       * XXX - this is always a fixed length output, we can get away
       * with strcpy here
       *
       * strncpy_irc(cidr_form_host, inetntoa((char *)&target_p->ip), 32);
       * cidr_form_host[32] = '\0';
       */
       strcpy(cidr_form_host, inetntoa((char*) &target_p->localClient->ip));
      
       if ((p = strchr(cidr_form_host,'.')) == NULL)
        return;
      /* 192. <- p */

      p++;
      if ((p = strchr(p,'.')) == NULL)
        return;
      /* 192.168. <- p */

      p++;
      if ((p = strchr(p,'.')) == NULL)
        return;
      /* 192.168.0. <- p */

      p++;
      *p++ = '0';
      *p++ = '/';
      *p++ = '2';
      *p++ = '4';
      *p++ = '\0';
      dlhost = cidr_form_host;

      bits = 0xFFFFFF00UL;
/* XXX: Fix me for IPV6 */
#endif
    }


  if (parc > 2) /* host :reason */
    {
      if (valid_comment(source_p,parv[2]) == 0)
	return;

      if(*parv[2])
        reason = parv[2];
      else
        reason = "No reason";
    }
  else
    reason = "No reason";


  if (IsOperAdmin(source_p))
    {
      if (bits < 8)
	{
	  sendto_one(source_p,
	":%s NOTICE %s :For safety, bitmasks less than 8 require conf access.",
		     me.name, parv[0]);
	  return;
	}
    }
  else
    {
      if (bits < 24)
	{
	  sendto_one(source_p,
	     ":%s NOTICE %s :Dline bitmasks less than 24 are for admins only.",
		     me.name, parv[0]);
	  return;
	}
    }

#ifdef IPV6
  if (t == HM_IPV6)
    t = AF_INET6;
  else
#endif
  t = AF_INET;
  if (ConfigFileEntry.non_redundant_klines)
    {
      char *creason;
      (void)parse_netmask(dlhost, &daddr, NULL);

      if((aconf = find_dline(&daddr, t)) != NULL)
	{
	  creason = aconf->passwd ? aconf->passwd : "<No Reason>";
	  if (IsConfExemptKline(aconf))
	    sendto_one(source_p,
		       ":%s NOTICE %s :[%s] is (E)d-lined by [%s] - %s",
		       me.name, parv[0], dlhost, aconf->host, creason);
	  else
	    sendto_one(source_p,
		       ":%s NOTICE %s :[%s] already D-lined by [%s] - %s",
		       me.name, parv[0], dlhost, aconf->host, creason);
	  return;
	}
    }

  set_time();
  cur_time = CurrentTime;
  current_date = smalldate(cur_time);

  aconf = make_conf();

  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
    {
      *oper_reason = '\0';
      oper_reason++;
    }

  ircsprintf(dlbuffer, "%s (%s)",reason, current_date);

  aconf->status = CONF_DLINE;
  DupString(aconf->host, dlhost);
  DupString(aconf->passwd, dlbuffer);

  add_conf_by_address(aconf->host, CONF_DLINE, NULL, aconf);
  /*
   * Write dline to configuration file
   */
  WriteKlineOrDline(DLINE_TYPE, source_p, NULL, dlhost, reason,
		    oper_reason, current_date, cur_time);
  check_klines();
} /* m_dline() */

/*
 * find_user_host
 * inputs	- pointer to client placing kline
 *              - pointer to user_host_or_nick
 *              - pointer to user buffer
 *              - pointer to host buffer
 * output	- 0 if not ok to kline, 1 to kline i.e. if valid user host
 * side effects -
 */
static int
find_user_host(struct Client *source_p,
	       char *user_host_or_nick, char *luser, char *lhost)
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

      return 1;
    }
  else
    {
      /* Try to find user@host mask from nick */

      if (!(target_p = find_chasing(source_p, user_host_or_nick, NULL)))
        return 0;

      if(!target_p->user)
        return 0;

      if (IsServer(target_p))
        {
	  sendto_one(source_p,
	     ":%s NOTICE %s :Can't KLINE a server, use @'s where appropriate",
		     me.name, source_p->name);
          return 0;
        }

      if(IsExemptKline(target_p))
        {
          if(!IsServer(source_p))
            sendto_one(source_p,
                       ":%s NOTICE %s :%s is E-lined",me.name,source_p->name,
                       target_p->name);
          return 0;
        }

      /* turn the "user" bit into "*user", blow away '~'
       * if found in original user name (non-idented)
       */

      strlcpy(luser, target_p->username, USERLEN + 1);
      if (*target_p->username == '~')
        luser[0] = '*';

      strlcpy(lhost,cluster(target_p->host), HOSTLEN + 1);
    }

  return 1;
}

/*
 * valid_user_host
 * inputs       - pointer to source
 *              - pointer to user buffer
 *              - pointer to host buffer
 * output	- 1 if not valid user or host, 0 if valid
 * side effects -
 */
static int
valid_user_host(struct Client *source_p, char *luser, char *lhost)
{
  /*
   * Check for # in user@host
   */

  if(strchr(lhost, '#') || strchr(luser, '#'))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid character '#' in kline",
               me.name, source_p->name);		    
    return 1;
  }

  /* Dont let people kline *!ident@host, as the ! is invalid.. */
  if(strchr(luser, '!'))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid character '!' in kline",
               me.name, source_p->name);
    return 1;
  }

  return 0;
}

/*
 * valid_wild_card
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
    return 1;
  else
    return 0;
}

/*
 * valid_comment
 * inputs	- pointer to client
 *              - pointer to comment
 * output       - 0 if no valid comment, 1 if valid
 * side effects - NONE
 */
static int
valid_comment(struct Client *source_p, char *comment)
{
  if(strchr(comment, '"'))
    {
      sendto_one(source_p,
		   ":%s NOTICE %s :Invalid character '\"' in comment",
		   me.name, source_p->name);
      return 0;
    }

  return 1;
}

/* static int already_placed_kline(source_p, luser, lhost)
 * Input: user to complain to, username & host to check for.
 * Output: returns 1 on existing K-line, 0 if doesn't exist.
 * Side-effects: Notifies source_p if the K-line already exists.
 * Note: This currently works if the new K-line is a special case of an
 *       existing K-line, but not the other way round. To do that we would
 *       have to walk the hash and check every existing K-line. -A1kmm.
 */
static int
already_placed_kline(struct Client *source_p, char *luser, char *lhost)
{
 char *reason;
 struct irc_inaddr iphost, *piphost;
 struct ConfItem *aconf;
 int t;
 if (ConfigFileEntry.non_redundant_klines) 
 {
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
  if ((aconf = find_conf_by_address(lhost, piphost, CONF_KILL, t, luser)))
  {
   reason = aconf->passwd ? aconf->passwd : "<No Reason>";

   /* Remote servers can set klines, so if its a dupe we warn all 
    * local opers and leave it at that
    */
   /* they can?  here was me thinking it was only remote clients :P */
   if(!MyClient(source_p))
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL, 
             "*** Remote K-Line [%s@%s] already K-Lined by [%s@%s] - %s",
             luser, lhost, aconf->user, aconf->host, reason);
   else
    sendto_one(source_p,
             ":%s NOTICE %s :[%s@%s] already K-Lined by [%s@%s] - %s",
              me.name, source_p->name, luser, lhost, aconf->user,
              aconf->host, reason);
     return 1;
  }
 }
 return 0;
}
