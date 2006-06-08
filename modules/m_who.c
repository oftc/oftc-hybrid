/*   m_who.c - basically adapted from the bahamut who
 *   Copyright (C) 1990 Jarkko Oikarinen and
 *                      University of Oulu, Computing Center
 *
 *   See file AUTHORS in IRC package for additional names of
 *   the programmers.
 *
 *   This program is free softwmare; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* $Id$*/


#include "stdinc.h"
#include "common.h"
#include "handlers.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"

static void m_who(struct Client*, struct Client*, int, char**);
  
struct Message who2_msgtab = {
  "WHO", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_who, m_who, m_who}
};

struct flag_item
{
  int mode;
  char letter;
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&who2_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&who2_msgtab);
}
const char *_version = "$Revision$";
#endif

/* Internally defined stuffs */
typedef struct SearchOptions
{
    int umodes;
    char *nick;
    char *user;
    char *host;
    char *gcos;
/*    char *ip; not atm */
    struct Channel *channel;
    struct Client *server;
    char umode_plus:1;
    char nick_plus:1;
    char user_plus:1;
    char host_plus:1;
    char gcos_plus:1;
/*    char ip_plus:1;*/
    char chan_plus:1;
    char serv_plus:1;
    char away_plus:1;
    char check_away:1;
    char check_umode:1;
    char show_chan:1;
    char search_chan:1;
    char spare:3; /* spare space for more stuff(?) */
} SOpts;


SOpts wsopts;
int build_searchopts(struct Client *, int, char **);
int chk_who(struct Client *, int);

/* Externally defined stuffs */
static struct flag_item who_user_modes[] = 
{
  {UMODE_ADMIN, 'a'},
  {UMODE_BOTS,  'b'},
  {UMODE_CCONN, 'c'},
  {UMODE_DEBUG, 'd'},
  {UMODE_FULL,  'f'},
  {UMODE_CALLERID, 'g'},
  {UMODE_INVISIBLE, 'i'},
  {UMODE_SKILL, 'k'},
  {UMODE_LOCOPS, 'l'},
  {UMODE_NCHANGE, 'n'},
  {UMODE_OPER, 'o'},
  {UMODE_REJ, 'r'},
  {UMODE_SERVNOTICE, 's'},
  {UMODE_UNAUTH, 'u'},
  {UMODE_WALLOP, 'w'},
  {UMODE_EXTERNAL, 'x'},
  {UMODE_SPY, 'y'},
  {UMODE_OPERWALL, 'z'},
  {UMODE_GOD, 'G'},
  {0, 0}
};

int
build_searchopts(struct Client *source_p, int parc, char *parv[])
{
  static char *who_help[] =
  {
      "/WHO [+|-][acghimnsuCM] [args]",
      "Flags are specified like channel modes,",
      "The flags cgh"/*i*/"mnsu all have arguments",
      "Flags are set to a positive check by +, a negative check by -",
      "The flags work as follows:",
      "Flag a: user is away",
      "Flag c <channel>: user is on <channel>,",
      "                  no wildcards accepted",
      "Flag g <gcos/realname>: user has string <gcos> in their GCOS,",
      "                        wildcards accepted, oper only",
      "Flag h <host>: user has string <host> in their hostname,",
      "               wildcards accepted",
/* 
 * We dont support this yet 
 * "Flag i <ip>: user is from <ip> wildcards accepted,", 
 * */
      "Flag m <usermodes>: user has <usermodes> set on them,",
      "                    only o/A/a for nonopers",
      "Flag n <nick>: user has string <nick> in their nickname,",
      "               wildcards accepted",
      "Flag s <server>: user is on server <server>,",
      "                 wildcards not accepted",
      "Flag u <user>: user has string <user> in their username,",
      "               wildcards accepted",
      "Behavior flags:",
      "Flag C: show first visible channel user is in",
      "Flag M: check for user in channels I am a member of",
      NULL
  };
  char *flags, change=1, *s;
  int args=1, i;

  memset((char *)&wsopts, '\0', sizeof(SOpts));
  /* if we got no extra arguments, send them the help. yeech. */
  /* if it's /who ?, send them the help */
  if(parc < 1 || parv[0][0] == '?')
  {
    char **ptr = who_help;
    for (; *ptr; ptr++)
	  sendto_one(source_p, form_str(RPL_WHOHELP), me.name,
		     source_p->name, *ptr);
    sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name, "?");
    return 0;
  }
  /* backwards compatibility */
  else if(parv[0][0] =='0' && parv[0][1] == 0)
  {
    if(parc > 1 && *parv[1] == 'o')
    {
	  wsopts.check_umode=1;
	  wsopts.umode_plus=1;
	  wsopts.umodes=UMODE_OPER;
    }
    wsopts.host_plus=1;
    wsopts.host="*";
    return 1;
  }
  /* if the first argument isn't a list of stuff */
  else if(parv[0][0] != '+' && parv[0][0] != '-')
  {
    if(parv[0][0] == '#' || parv[0][0] == '&')
    {
	  wsopts.channel = hash_find_channel(parv[0]);
	  if(wsopts.channel == NULL)
	  {
	    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name,
            source_p->name, parv[0]);
	    return 0;
	  }
    }
    else
    {
	  /* If the arguement has a . in it, treat it as an
	   * address. Otherwise treat it as a nick. -Rak */
	  if (strchr(parv[0], '.'))
	  {
	    wsopts.host_plus=1;
	    wsopts.host=parv[0];
	  }
	  else
	  {
	    wsopts.nick_plus=1;
	    wsopts.nick=parv[0];
	  }
    }
  return 1;
  }
  /* now walk the list (a lot like set_mode) and set arguments
   * as appropriate. */
  flags = parv[0];
  while(*flags)
  {
    switch(*flags)
    {
      case '+':
      case '-':
	    change=(*flags=='+' ? 1 : 0);
	    break;
      case 'a':
	    if(change)
	      wsopts.away_plus = 1; /* they want here people */
	    else
	      wsopts.away_plus = 0;
	    wsopts.check_away = 1;
	    break;
      case 'C':
	    wsopts.show_chan = change;
	    break;
      case 'M':
	    wsopts.search_chan = change;
	    break;
      case 'c':
	    if(parv[args] == NULL || !change)
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    wsopts.channel = hash_find_channel(parv[args]);
	    if(wsopts.channel == NULL)
	    {
	      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name,
			 source_p->name, parv[args]);
	      return 0;
	    }
	    wsopts.chan_plus = change;
	    args++;
	    break;
      case 'g':
	    if(parv[args] == NULL || !IsOper(source_p))
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    wsopts.gcos = parv[args];
	    wsopts.gcos_plus = change;
	    args++;
	    break;
      case 'h':
	    if(parv[args]==NULL)
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    wsopts.host = parv[args];
	    wsopts.host_plus = change;
	    args++;
	    break;
/* XXX Disabled: WE CAN NOT LOOK UP REMOTE IPS AT THIS TIME
        case 'i':
	    if(parv[args] == NULL || !IsOper(source_p))
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    wsopts.ip = parv[args];
	    wsopts.ip_plus = change;
	    args++;
	    break;
    */
      case 'm':
	    if(parv[args] == NULL)
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    s = parv[args];
	    while(*s)
	    {
	      for(i = 1; who_user_modes[i].mode != 0; i += 2)
	      {
		    if(*s == (char)who_user_modes[i].letter)
		    {
		      wsopts.umodes |= who_user_modes[i-1].mode;
		      break;
		    }
	      }
	      s++;
	    }
	    if(!IsOper(source_p)) /* only let users search for +/-oOaA */
	      wsopts.umodes = (wsopts.umodes&(UMODE_OPER|UMODE_ADMIN));
	    wsopts.umode_plus = change;
	    if(wsopts.umodes)
	      wsopts.check_umode = 1;
	    args++;
	    break;
      case 'n':
	    if(parv[args] == NULL)
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    wsopts.nick = parv[args];
	    wsopts.nick_plus = change;
	    args++;
	    break;
      case 's':
	    if(parv[args] == NULL || !change)
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    wsopts.server = find_server(parv[args]);
	    if(wsopts.server == NULL)
	    {
	      sendto_one(source_p, form_str(ERR_NOSUCHSERVER), me.name,
			 source_p->name, parv[args]);
	      return 0;
	    }
	    wsopts.serv_plus = change;
	    args++;
	    break;
      case 'u':
	    if(parv[args] == NULL)
	    {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	    }
	    wsopts.user = parv[args];
	    wsopts.user_plus = change;
	    args++;
	    break;
    }
    flags++;
  }
  
  /* if we specified search_chan, we _must_ specify something useful 
   * to go with it. Specifying a channel makes no sense, and no params make no 
   * sense either, as does specifying a nick.
   */
  
  if(wsopts.search_chan && !(wsopts.check_away || wsopts.gcos || wsopts.host ||
			     wsopts.check_umode || wsopts.server ||
			     wsopts.user))
  {
    if(parv[args]==NULL || wsopts.channel || wsopts.nick ||
	 parv[args][0] == '#' || parv[args][0] == '&')
      {
	  sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
 	  source_p->name);
	  return 0;
      }

      if (strchr(parv[args], '.'))
      {
	  wsopts.host_plus=1;
	  wsopts.host=parv[args];
      }
      else
      {
	  sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
 	  source_p->name);
	  return 0;
      }
  } 
  else /* can't show_chan if nothing else is set! */
      if(wsopts.show_chan && !(wsopts.check_away || wsopts.gcos ||
			       wsopts.host || wsopts.check_umode ||
			       wsopts.server || wsopts.user || wsopts.nick ||
			       /*wsopts.ip ||*/ wsopts.channel))
      {
	  if(parv[args]==NULL)
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name, source_p->name);
	      return 0;
	  }
	  
	  if (strchr(parv[args], '.'))
	  {
	      wsopts.host_plus=1;
	      wsopts.host=parv[args];
	  }
	  else
	  {
	      wsopts.nick_plus=1;
	      wsopts.nick=parv[args];
	  }
      }

  /* hey cool, it all worked! */
  return 1;
}

/* these four are used by chk_who to check gcos/nick/user/host
 * respectively */
int (*gchkfn)(const char *, const char *);
int (*nchkfn)(const char *, const char *);
int (*uchkfn)(const char *, const char *);
int (*hchkfn)(const char *, const char *);
int (*ichkfn)(const char *, const char *);

int
chk_who(struct Client *target_p, int showall)
{
  if(!IsClient(target_p))
    return 0;
  if(IsInvisible(target_p) && !showall)
    return 0;
  if(wsopts.check_umode)
    if((wsopts.umode_plus && 
        !((target_p->umodes&wsopts.umodes)==wsopts.umodes)) ||
        (!wsopts.umode_plus && ((target_p->umodes&wsopts.umodes)==wsopts.umodes)))
      return 0;
  if(wsopts.check_away)
    if((wsopts.away_plus && target_p->away==NULL) ||
        (!wsopts.away_plus && target_p->away!=NULL))
      return 0;
    /* while this is wasteful now, in the future
     * when clients contain pointers to their servers
     * of origin, this'll become a 4 byte check instead of a irccmp
     * -wd */
    /* welcome to the future... :) - lucas */
  if(wsopts.serv_plus)
    if(wsopts.server != target_p->servptr)
      return 0;
    /* we only call match once, since if the first condition
     * isn't true, most (all?) compilers will never try the
     * second...phew :) */
  if(wsopts.user!=NULL)
  {
    if(uchkfn == match)
    {
      if((wsopts.user_plus && !uchkfn(wsopts.user, target_p->username)) ||
              (!wsopts.user_plus && uchkfn(wsopts.user, target_p->username)))
      return 0;
    }
    else
    {
      if((wsopts.user_plus && uchkfn(wsopts.user, target_p->username)) ||
              (!wsopts.user_plus && !uchkfn(wsopts.user, target_p->username)))
          return 0;
    }
  }

  if(wsopts.nick!=NULL)
  {
    if(nchkfn == match)
    {
      if((wsopts.nick_plus && !nchkfn(wsopts.nick, target_p->name)) ||
              (!wsopts.nick_plus && nchkfn(wsopts.nick, target_p->name)))
       return 0;
    }
    else
    {
        if((wsopts.nick_plus && nchkfn(wsopts.nick, target_p->name)) ||
                (!wsopts.nick_plus && !nchkfn(wsopts.nick, target_p->name)))
            return 0;
    }
  }
    
  if(wsopts.host!=NULL)
  {
    if(hchkfn == match)
    {
      if((wsopts.host_plus && !hchkfn(wsopts.host, target_p->host)) ||
                (!wsopts.host_plus && hchkfn(wsopts.host, target_p->host)))
      return 0;
    }
    else
    {
      if((wsopts.host_plus && hchkfn(wsopts.host, target_p->host)) ||
              (!wsopts.host_plus && !hchkfn(wsopts.host, target_p->host)))
          return 0;
    }
  }
    
/* 
 * we don't do ips atm 
 * if(wsopts.ip!=NULL)
    if((wsopts.ip_plus && ichkfn(wsopts.ip, target_p->localClient->sockhost)) ||
        (!wsopts.ip_plus && !ichkfn(wsopts.ip, target_p->localClient->sockhost)))
      return 0;
 */   
  if(wsopts.gcos!=NULL)
  {
    if(gchkfn == match)
    {
      if((wsopts.gcos_plus && !gchkfn(wsopts.gcos, target_p->info)) ||
              (!wsopts.gcos_plus && gchkfn(wsopts.gcos, target_p->info)))
          return 0;
    }
    else
    {
      if((wsopts.gcos_plus && gchkfn(wsopts.gcos, target_p->info)) ||
              (!wsopts.gcos_plus && !gchkfn(wsopts.gcos, target_p->info)))
	  return 0;
    }
  }
  return 1;
}

inline char *
first_visible_channel(struct Client *client_p, struct Client *source_p)
{
  dlink_node *ptr;
        
  struct Membership *mb;
  struct Channel *chptr = NULL;

  DLINK_FOREACH(ptr, client_p->channel.head)
  {
    mb = ptr->data;
    chptr = mb->chptr;
    if(ShowChannel(source_p, chptr))
      break;
  }

  if(chptr != NULL)
    return chptr->chname;
  
  return "*";
}
#define MAXWHOREPLIES 200
#define WHO_HOPCOUNT(s, a) (a->hopcount)

int
do_who_channel(struct Client *source_p, struct Channel *chptr, int showall)
{
  struct Client *target_p;
  struct Membership *ms;
  dlink_node *ptr;
  int shown;
  int i;
  char status[4];

  shown = 0;
  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;
    target_p = ms->client_p;
    i = 0;
    if(!chk_who(target_p, showall))
      continue;
     
    /* Whomever wrote the original code here is an incompetent
     * nincompoop the original was donkey doo doo, and you can
     * quote me on that. sheesh - Dianora
     */
    if (target_p->away == NULL)
      status[i++] = 'H';
    else
      status[i++] = 'G';
    
    if (IsOper(target_p))
      status[i++] = '*';
    else if(IsOper(source_p) && IsInvisible(target_p))
        status[i++] = '%';

    if (target_p->flags & CHFL_CHANOP)
      status[i++] = '@';
    else if (target_p->flags & CHFL_VOICE)
      status[i++] = '%';
    
    status[i] = '\0';
    sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
           chptr->chname, target_p->username, target_p->host,
           target_p->servptr->name, target_p->name, status,
           WHO_HOPCOUNT(source_p, target_p), target_p->info);
    shown++;
  }
  return shown;
}

/* allow lusers only 200 replies from /who */
static void
m_who(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p;
  dlink_node *ptr;
  int shown = 0, showall = IsOper(source_p);
  char status[4];
  static int last_used = 0;

  /* drop nonlocal clients */
  if(!MyClient(source_p))
	return;
    
  if(!build_searchopts(source_p, parc-1, parv+1))
	return; /* /who was no good */
    
  if(wsopts.gcos!=NULL && (strchr(wsopts.gcos, '?'))==NULL &&
        (strchr(wsopts.gcos, '*'))==NULL)
    gchkfn=irccmp;
  else
	gchkfn=match;
  
  if(wsopts.nick!=NULL && (strchr(wsopts.nick, '?'))==NULL &&
        (strchr(wsopts.nick, '*'))==NULL)
	nchkfn=irccmp;
  else
	nchkfn=match;

  if(wsopts.user!=NULL && (strchr(wsopts.user, '?'))==NULL &&
        (strchr(wsopts.user, '*'))==NULL)
	uchkfn=irccmp;
  else
	uchkfn=match;
  
  if(wsopts.host!=NULL && (strchr(wsopts.host, '?'))==NULL &&
        (strchr(wsopts.host, '*'))==NULL)
	hchkfn=irccmp;
  else
	hchkfn=match;

/*  if(wsopts.ip!=NULL && (strchr(wsopts.ip, '?'))==NULL &&
        (strchr(wsopts.ip, '*'))==NULL)
	ichkfn=irccmp;
  else
	ichkfn=match;
*/

  if(wsopts.channel!=NULL)
  {
	if(IsMember(source_p,wsopts.channel))
	  showall=1;
	else if(SecretChannel(wsopts.channel) && IsAdmin(source_p))
	  showall=1;
	else if(!SecretChannel(wsopts.channel) && IsOper(source_p))
	  showall=1;
	else
	  showall=0;
	if(showall || !SecretChannel(wsopts.channel))
	{
      do_who_channel(source_p, wsopts.channel, showall);
	}
	sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
		   wsopts.channel->chname);
	return;
  }
    /* if (for whatever reason) they gave us a nick with no
    /
     * wildcards, just do a find_person, bewm! */
  else if(nchkfn == irccmp)
  {
	target_p = find_person(client_p, wsopts.nick);
	if(target_p != NULL)
	{
      if(!chk_who(target_p,1))
	  {
		sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
			   wsopts.host!=NULL ? wsopts.host : wsopts.nick);
		return;
	  }
	  else
	  {
		status[0]=(target_p->away==NULL ? 'H' : 'G');
		status[1]=(IsOper(target_p) ? '*' : (IsInvisible(target_p) &&
						 IsOper(source_p) ? '%' : 0));
		status[2]=0;
		sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
			   wsopts.show_chan ? first_visible_channel(target_p, source_p)
			   : "*", target_p->username, target_p->host,
			   target_p->servptr->name, target_p->name, status,
			   WHO_HOPCOUNT(source_p, target_p),
			   target_p->info);
		sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
			   wsopts.host!=NULL ? wsopts.host : wsopts.nick);
		return;
	  }
	}
	sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
		   wsopts.host!=NULL ? wsopts.host : wsopts.nick);
	return;
  }
    /* if HTM, drop this too */
  if((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime && !IsOper(source_p))
  {
	sendto_one(source_p, form_str(RPL_LOAD2HI), me.name, source_p->name);
	return;
  }
    
  if(wsopts.search_chan)
  {
    dlink_node *ptr;
    struct Membership *m;
    struct Channel *chan_p;

    DLINK_FOREACH(ptr, source_p->channel.head)
	{
      m = ptr->data;
      chan_p = m->chptr;
      if(shown >= MAXWHOREPLIES && !IsOper(source_p))
      {
        sendto_one(source_p, form_str(ERR_WHOLIMEXCEED), me.name,
                source_p->name, MAXWHOREPLIES);
        break;
      }
       
      shown += do_who_channel(source_p, chan_p, 1);
    }
  }
  else
  {
    DLINK_FOREACH(ptr, global_client_list.head)
	{
      target_p = ptr->data;
	  if(!chk_who(target_p, showall))
		continue;
	    /* wow, they passed it all, give them the reply...
	     * IF they haven't reached the max, or they're an oper */
	  if(shown >= MAXWHOREPLIES && !IsOper(source_p))
	  {
		sendto_one(source_p, form_str(ERR_WHOLIMEXCEED), me.name, 
			   source_p->name, MAXWHOREPLIES);
		break; /* break out of loop so we can send end of who */
      }
	  status[0]=(target_p->away==NULL ? 'H' : 'G');
	  status[1]=(IsOper(target_p) ? '*' : (IsInvisible(target_p) && 
                  IsOper(source_p) ? '%' : 0));
	  status[2]=0;
	  sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
              wsopts.show_chan ? first_visible_channel(target_p, source_p) :
		      "*", target_p->username, target_p->host,
		      target_p->servptr->name, target_p->name, status,
		      WHO_HOPCOUNT(source_p, target_p), target_p->info);
      shown++;
    }
  }
  sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
          (wsopts.host!=NULL ? wsopts.host :
           (wsopts.nick!=NULL ? wsopts.nick :
            (wsopts.user!=NULL ? wsopts.user :
             (wsopts.gcos!=NULL ? wsopts.gcos :
              (wsopts.server!=NULL ? wsopts.server->name : "*"))))));
  return;
}

