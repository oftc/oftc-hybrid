/* m_who.c - Because s_user.c was just crazy.
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


#include "stdinc.h"
#include "tools.h"
#include "common.h"
#include "handlers.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "vchannel.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "list.h"
#include "irc_string.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static void m_who2(struct Client*, struct Client*, int, char**);
  
struct Message who2_msgtab = {
  "SPIF", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_who2, m_who2, m_who2}
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
    char *ip;
    struct Channel *channel;
    struct Client *server;
    char umode_plus:1;
    char nick_plus:1;
    char user_plus:1;
    char host_plus:1;
    char gcos_plus:1;
    char ip_plus:1;
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
static struct flag_item user_modes[] = 
{
  {FLAGS_ADMIN, 'a'},
  {FLAGS_BOTS,  'b'},
  {FLAGS_CCONN, 'c'},
  {FLAGS_DEBUG, 'd'},
  {FLAGS_FULL,  'f'},
  {FLAGS_CALLERID, 'g'},
  {FLAGS_INVISIBLE, 'i'},
  {FLAGS_SKILL, 'k'},
  {FLAGS_LOCOPS, 'l'},
  {FLAGS_NCHANGE, 'n'},
  {FLAGS_OPER, 'o'},
  {FLAGS_REJ, 'r'},
  {FLAGS_SERVNOTICE, 's'},
  {FLAGS_UNAUTH, 'u'},
  {FLAGS_WALLOP, 'w'},
  {FLAGS_EXTERNAL, 'x'},
  {FLAGS_SPY, 'y'},
  {FLAGS_OPERWALL, 'z'},
  {FLAGS_GOD, 'G'},
  {0, 0}
};

extern struct Link *find_channel_link(struct Link *, struct Channel *);

int build_searchopts(struct Client *source_p, int parc, char *parv[])
{
  static char *who_help[] =
  {
      "/WHO [+|-][acghimnsuCM] [args]",
      "Flags are specified like channel modes,",
      "The flags cghimnsu all have arguments",
      "Flags are set to a positive check by +, a negative check by -",
      "The flags work as follows:",
      "Flag a: user is away",
      "Flag c <channel>: user is on <channel>,",
      "                  no wildcards accepted",
      "Flag g <gcos/realname>: user has string <gcos> in their GCOS,",
      "                        wildcards accepted, oper only",
      "Flag h <host>: user has string <host> in their hostname,",
      "               wildcards accepted",
      "Flag i <ip>: user is from <ip> wildcards accepted,",
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
  if(parc < 1 || parv[0][0]=='?')
  {
      char **ptr = who_help;
      for (; *ptr; ptr++)
	  sendto_one(source_p, form_str(RPL_WHOHELP), me.name,
		     source_p->name, *ptr);
      sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name, "?");
      return 0;
  }
  /* backwards compatibility */
  else if(parv[0][0]=='0' && parv[0][1]==0)
  {
      if(parc>1 && *parv[1]=='o')
      {
	  wsopts.check_umode=1;
	  wsopts.umode_plus=1;
	  wsopts.umodes=FLAGS_OPER;
      }
      wsopts.host_plus=1;
      wsopts.host="*";
      return 1;
  }
  /* if the first argument isn't a list of stuff */
  else if(parv[0][0]!='+' && parv[0][0]!='-')
  {
      if(parv[0][0]=='#' || parv[0][0]=='&')
      {
	  wsopts.channel=hash_find_channel(parv[0]);
	  if(wsopts.channel==NULL)
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
  flags=parv[0];
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
	      wsopts.away_plus=1; /* they want here people */
	  else
	      wsopts.away_plus=0;
	  wsopts.check_away=1;
	  break;
      case 'C':
	  wsopts.show_chan = change;
	  break;
      case 'M':
	  wsopts.search_chan = change;
	  break;
      case 'c':
	  if(parv[args]==NULL || !change)
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  wsopts.channel=hash_find_channel(parv[args]);
	  if(wsopts.channel==NULL)
	  {
	      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name,
			 source_p->name, parv[args]);
	      return 0;
	  }
	  wsopts.chan_plus=change;
	  args++;
	  break;
      case 'g':
	  if(parv[args]==NULL || !IsOper(source_p))
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  wsopts.gcos=parv[args];
	  wsopts.gcos_plus=change;
	  args++;
	  break;
      case 'h':
	  if(parv[args]==NULL)
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  wsopts.host=parv[args];
	  wsopts.host_plus=change;
	  args++;
	  break;
      case 'i':
	  if(parv[args]==NULL || !IsOper(source_p))
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  wsopts.ip=parv[args];
	  wsopts.ip_plus=change;
	  args++;
	  break;
      case 'm':
	  if(parv[args]==NULL)
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  s=parv[args];
	  while(*s)
	  {
	      for(i=1;user_modes[i].mode!=0;i+=2)
	      {
		  if(*s==(char)user_modes[i].letter)
		  {
		      wsopts.umodes|=user_modes[i-1].mode;
		      break;
		  }
	      }
	      s++;
	  }
	  if(!IsOper(source_p)) /* only let users search for +/-oOaA */
	      wsopts.umodes=(wsopts.umodes&(FLAGS_OPER|FLAGS_ADMIN));
	  wsopts.umode_plus=change;
	  if(wsopts.umodes)
	      wsopts.check_umode=1;
	  args++;
	  break;
      case 'n':
	  if(parv[args]==NULL)
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  wsopts.nick=parv[args];
	  wsopts.nick_plus=change;
	  args++;
	  break;
      case 's':
	  if(parv[args]==NULL || !change)
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  wsopts.server=find_server(parv[args]);
	  if(wsopts.server==NULL)
	  {
	      sendto_one(source_p, form_str(ERR_NOSUCHSERVER), me.name,
			 source_p->name, parv[args]);
	      return 0;
	  }
	  wsopts.serv_plus=change;
	  args++;
	  break;
      case 'u':
	  if(parv[args]==NULL)
	  {
	      sendto_one(source_p, form_str(ERR_WHOSYNTAX), me.name,
			 source_p->name);
	      return 0;
	  }
	  wsopts.user=parv[args];
	  wsopts.user_plus=change;
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
			       wsopts.ip || wsopts.channel))
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

int chk_who(struct Client *ac, int showall)
{
    if(!IsClient(ac))
	return 0;
    if(IsInvisible(ac) && !showall)
	return 0;
    if(wsopts.check_umode)
	if((wsopts.umode_plus && 
	    !((ac->umodes&wsopts.umodes)==wsopts.umodes)) ||
	   (!wsopts.umode_plus && ((ac->umodes&wsopts.umodes)==wsopts.umodes)))
	    return 0;
    if(wsopts.check_away)
	if((wsopts.away_plus && ac->user->away==NULL) ||
	   (!wsopts.away_plus && ac->user->away!=NULL))
	    return 0;
    /* while this is wasteful now, in the future
     * when clients contain pointers to their servers
     * of origin, this'll become a 4 byte check instead of a irccmp
     * -wd */
    /* welcome to the future... :) - lucas */
    if(wsopts.serv_plus)
	if(wsopts.server != ac->servptr)
	    return 0;
    /* we only call match once, since if the first condition
     * isn't true, most (all?) compilers will never try the
     * second...phew :) */
    if(wsopts.user!=NULL)
	if((wsopts.user_plus && uchkfn(wsopts.user, ac->username)) ||
	   (!wsopts.user_plus && !uchkfn(wsopts.user, ac->username)))
	    return 0;

    if(wsopts.nick!=NULL)
	if((wsopts.nick_plus && nchkfn(wsopts.nick, ac->name)) ||
	   (!wsopts.nick_plus && !nchkfn(wsopts.nick, ac->name)))
	    return 0;
    
    if(wsopts.host!=NULL)
	if((wsopts.host_plus && hchkfn(wsopts.host, ac->host)) ||
	   (!wsopts.host_plus && !hchkfn(wsopts.host, ac->host)))
	    return 0;
    
    if(wsopts.ip!=NULL)
	if((wsopts.ip_plus && ichkfn(wsopts.ip, ac->localClient->sockhost)) ||
	   (!wsopts.ip_plus && !ichkfn(wsopts.ip, ac->localClient->sockhost)))
	    return 0;
    
    if(wsopts.gcos!=NULL)
	if((wsopts.gcos_plus && gchkfn(wsopts.gcos, ac->info)) ||
	   (!wsopts.gcos_plus && !gchkfn(wsopts.gcos, ac->info)))
	    return 0;
    return 1;
}

inline char *first_visible_channel(struct Client *client_p, 
        struct Client *source_p)
{
    struct Link *lp;
    dlink_node *ptr;
    dlink_node *next_ptr;
        
    int secret = 0;
    struct Channel *chptr = NULL;
    static char chnbuf[CHANNELLEN + 2];

    if(client_p->user->channel.head)
    {
	if(IsAdmin(source_p))
	{
	    chptr = client_p->user->channel.head->data;
	    if(!(ShowChannel(source_p, chptr)))
		secret = 1;
	}
	else
	{
	    for(ptr = client_p->user->channel.head; ptr; ptr = next_ptr)
	    {
		if(ShowChannel(source_p, (struct Channel*)ptr->data))
		    break;
	    }
	    if(lp)
		chptr = ptr->data;
        next_ptr = ptr->next;
	}

	if(chptr)
	{
	    if(!secret)
		return chptr->chname;
	    ircsprintf(chnbuf, "%%%s", chptr->chname);
	    return chnbuf;
	}
    }
    return "*";
}

/* allow lusers only 200 replies from /who */
#define MAXWHOREPLIES 200
#define WHO_HOPCOUNT(s, a) (a->hopcount)
static void m_who2(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
    struct Client *ac;
    dlink_node *cm;
    dlink_node *lp;
    int shown=0, i=0, showall=IsOper(source_p);
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

    if(wsopts.ip!=NULL && (strchr(wsopts.ip, '?'))==NULL &&
       (strchr(wsopts.ip, '*'))==NULL)
	ichkfn=irccmp;
    else
	ichkfn=match;


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
	    for(cm=wsopts.channel->peons.head; cm; cm=cm->next)
	    {
		ac=cm->data;
		i=0;
		if(!chk_who(ac,showall))
		    continue;
		/* get rid of the pidly stuff first */
		/* wow, they passed it all, give them the reply...
		 * IF they haven't reached the max, or they're an oper */
		status[i++]=(ac->user->away==NULL ? 'H' : 'G');
		status[i]=(IsOper(ac) ? '*' : ((IsInvisible(ac) &&
						  IsOper(source_p)) ? '%' : 0));
		status[((status[i]) ? ++i : i)]=((ac->flags&CHFL_CHANOP) ? '@'
						 : ((ac->flags&CHFL_VOICE) ? 
						    '+' : 0));
		status[++i]=0;
		sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
			   wsopts.channel->chname, ac->username,
			   ac->host,ac->user->server, ac->name, status,
			   WHO_HOPCOUNT(source_p, ac),
			   ac->info);
	    }
	}
	sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
		   wsopts.channel->chname);
	return;
    }
    /* if (for whatever reason) they gave us a nick with no
     * wildcards, just do a find_person, bewm! */
    else if(nchkfn==irccmp)
    {
	ac=find_person(wsopts.nick);
	if(ac!=NULL)
	{
	    if(!chk_who(ac,1))
	    {
		sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
			   wsopts.host!=NULL ? wsopts.host : wsopts.nick);
		return;
	    }
	    else
	    {
		status[0]=(ac->user->away==NULL ? 'H' : 'G');
		status[1]=(IsOper(ac) ? '*' : (IsInvisible(ac) &&
						 IsOper(source_p) ? '%' : 0));
		status[2]=0;
		sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
			   wsopts.show_chan ? first_visible_channel(ac, source_p)
			   : "*", ac->username, ac->host,
			   ac->user->server, ac->name, status,
			   WHO_HOPCOUNT(source_p, ac),
			   ac->info);
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
	for(lp = source_p->user->channel.head; lp; lp = lp->next)
	{
	    for(cm = ((struct Channel*)lp->data)->peons.head; cm; cm = cm->next)
	    {
		ac = cm->data;
		if(!chk_who(ac, 1))
		    continue;
		
		if(shown==MAXWHOREPLIES && !IsOper(source_p))
		{
		    sendto_one(source_p, form_str(ERR_WHOLIMEXCEED), me.name,
			       source_p->name, MAXWHOREPLIES);
		    break;
		}
		
		i = 0;
		status[i++]=(ac->user->away==NULL ? 'H' : 'G');
		status[i]=(IsOper(ac) ? '*' : ((IsInvisible(ac) &&
						  IsOper(source_p)) ? '%' : 0));
		status[((status[i]) ? ++i : i)]=((ac->flags&CHFL_CHANOP) ? 
						 '@' : ((ac->flags&CHFL_VOICE)
							? '+' : 0));
		status[++i]=0;
		sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
			   ((struct Channel*)lp->data)->chname, ac->username,
			   ac->host,ac->user->server, ac->name,
			   status, WHO_HOPCOUNT(source_p, ac), ac->info);
		shown++;
	    }
	}
    }
    else
    {
	for(ac=client_p;ac;ac=ac->next)
	{
	    if(!chk_who(ac,showall))
		continue;
	    /* wow, they passed it all, give them the reply...
	     * IF they haven't reached the max, or they're an oper */
	    if(shown==MAXWHOREPLIES && !IsOper(source_p))
	    {
		sendto_one(source_p, form_str(ERR_WHOLIMEXCEED), me.name, 
			   source_p->name, MAXWHOREPLIES);
		break; /* break out of loop so we can send end of who */
	    }
	    status[0]=(ac->user->away==NULL ? 'H' : 'G');
	    status[1]=(IsOper(ac) ? '*' : (IsInvisible(ac) && 
					     IsOper(source_p) ? '%' : 0));
	    status[2]=0;
	    sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
		       wsopts.show_chan ? first_visible_channel(ac, source_p) :
		       "*", ac->username, ac->host,
		       ac->user->server, ac->name, status,
		       WHO_HOPCOUNT(source_p, ac), ac->info);
	    shown++;
	}
   }
    sendto_one(source_p, form_str(RPL_ENDOFWHO), me.name, source_p->name,
	       (wsopts.host!=NULL ? wsopts.host :
		(wsopts.nick!=NULL ? wsopts.nick :
		 (wsopts.user!=NULL ? wsopts.user :
		  (wsopts.gcos!=NULL ? wsopts.gcos :
		   (wsopts.server!=NULL ? wsopts.server->name :
		    "*"))))));
    return;
}
