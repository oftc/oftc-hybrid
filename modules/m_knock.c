/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_knock.c: Requests to be invited to a channel.
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
#include "handlers.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "vchannel.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_serv.h"


static void m_knock(struct Client*, struct Client*, int, char**);
static void ms_knock(struct Client *, struct Client *, int, char**);

static void parse_knock_local(struct Client *, struct Client *,
                              int, char **, char *);
static void parse_knock_remote(struct Client *, struct Client *,
                               int, char **);

static void send_knock(struct Client *, struct Client *,
                       struct Channel *, char *, char *, int);

static int is_banned_knock(struct Channel *, struct Client *, char *);
static int check_banned_knock(struct Channel *, struct Client *,
                              char *, char *);

struct Message knock_msgtab = {
  "KNOCK", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_knock, ms_knock, m_knock}
};
struct Message knockll_msgtab = {
  "KNOCKLL", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, m_knock, m_ignore}
};

#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&knock_msgtab);
  mod_add_cmd(&knockll_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&knock_msgtab);
  mod_del_cmd(&knockll_msgtab);
}

const char *_version = "$Revision$";
#endif

/* m_knock
 *    parv[0] = sender prefix
 *    parv[1] = channel
 *    parv[2] = 'key' (for vchan)
 *
 *  The KNOCK command has the following syntax:
 *   :<sender> KNOCK <channel> <vchan id>
 *
 *  If a user is not banned from the channel they can use the KNOCK
 *  command to have the server NOTICE the channel operators notifying
 *  they would like to join.  Helpful if the channel is invite-only, the
 *  key is forgotten, or the channel is full (INVITE can bypass each one
 *  of these conditions.  Concept by Dianora <db@db.net> and written by
 *  <anonymous>
 *
 *  This function is also used for LL servers forwarding knock requests they
 *  dont know about, for us to answer.
 */

static void
m_knock(struct Client *client_p, struct Client *source_p, int parc,
	char *parv[])
{
  char *sockhost = NULL;
  
  if((ConfigChannel.use_knock == 0) && MyClient(source_p))
    {
      sendto_one(source_p, form_str(ERR_KNOCKDISABLED),
		 me.name, source_p->name);
      return;
    }

  /* a remote KNOCKLL request, check we're capable of handling it.. */
  if(!MyConnect(source_p))
  {
    if(!ServerInfo.hub || !IsCapable(client_p, CAP_LL) || parc < 3)
      return;
    else
    {
      /* set sockhost to parv[2], then shift the vchan id down if it
       * exists.. done here to save messing in parse_knock_local()
       */
      sockhost = parv[2];
      
      if(parc > 3)
      {
        parv[2] = parv[3];
        parv[3] = NULL;
      }
      else
        parv[2] = NULL;

      parc--;
    }
  }
    
  if(IsClient(source_p))
    parse_knock_local(client_p, source_p, parc, parv, sockhost);
}

/* 
 * ms_knock()
 *	parv[0] = sender prefix
 *	parv[1] = channel
 *	parv[2] = vchan id
 */
 
static void
ms_knock(struct Client *client_p, struct Client *source_p,
		     int parc, char *parv[])
{
  if(IsClient(source_p))
    parse_knock_remote(client_p, source_p, parc, parv);
}


/*
 * parse_knock_local()
 *
 * input        - pointer to physical struct client_p
 *              - pointer to source struct source_p
 *              - number of args
 *              - pointer to array of args
 *		- clients sockhost (if remote)
 * output       -
 * side effects - sets name to name of base channel
 *                or sends failure message to source_p
 */

static void
parse_knock_local(struct Client *client_p, struct Client *source_p,
                              int parc, char *parv[], char *sockhost)
{
  /* We will cut at the first comma reached, however we will not *
   * process anything afterwards.                                */

  struct Channel *chptr;
  char *p, *name, *key;
#ifdef VCHANS
  struct Channel *vchan_chptr;
#endif

  name = parv[1];
  key = (parc > 2) ? parv[2] : NULL;

  if((p = strchr(name,',')) != NULL)
    *p = '\0';

  if(!IsChannelName(name))
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, parv[0], name);
    return;
  }

  if(!(chptr = hash_find_channel(name)))
  {
    if(!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
    {
      sendto_one(uplink, ":%s KNOCKLL %s %s %s",
                 source_p->name, parv[1],
		 IsIPSpoof(source_p) ? "255.255.255.255" :
		 source_p->localClient->sockhost,
		 (parc > 2) ? parv[2] : "");
    }
    else
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name, parv[0],
                 name);
    }

    return;
  }

#ifdef VCHANS
  if (IsVchanTop(chptr))
  {
    /* They specified a vchan basename */
    if(on_sub_vchan(chptr,source_p))
    {
      sendto_one(source_p, form_str(ERR_KNOCKONCHAN),
		 me.name, source_p->name, name);
      return;
    }
    if (key && key[0] == '!')
    {
      /* Make "KNOCK #channel !" work like JOIN */
      if (!key[1])
      {
	show_vchans(source_p, chptr, "knock");
	return;
      }

      /* Find a matching vchan */
      if ((vchan_chptr = find_vchan(chptr, key)))
      {
	chptr = vchan_chptr;
      }
      else
      {
	sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
		   me.name, parv[0], name);
	return;
      }
    }
    else
    {
      /* No key specified */
      show_vchans(source_p, chptr, "knock");
      return;
    }
  }
  else if (IsVchan(chptr))
  {
    /* Don't allow KNOCK'ing a vchans 'real' name */
    sendto_one(source_p, form_str(ERR_BADCHANNAME), me.name, parv[0],
	       name);
    return;
  }
  else
#endif
  {
    /* Normal channel, just be sure they aren't on it */
    if (IsMember(source_p, chptr))
    {
      sendto_one(source_p, form_str(ERR_KNOCKONCHAN),
		 me.name, source_p->name, name);
      return;
    }
  }

  if(!((chptr->mode.mode & MODE_INVITEONLY) ||
       (*chptr->mode.key) || (sockhost && is_banned_knock(chptr, source_p, sockhost)) ||
       (!sockhost && is_banned(chptr, source_p)) ||
       (chptr->mode.limit && chptr->users >= chptr->mode.limit )
       ))
  {
    sendto_one(source_p, form_str(ERR_CHANOPEN),
	       me.name, source_p->name, name);
    return;
  }

  /* don't allow a knock if the user is banned, or the channel is secret */
  if ((chptr->mode.mode & MODE_PRIVATE) ||
      (sockhost && is_banned_knock(chptr, source_p, sockhost)) ||
      (!sockhost && is_banned(chptr, source_p)))
  {
    sendto_one(source_p, form_str(ERR_CANNOTSENDTOCHAN), me.name, parv[0],
	       name);
    return;
  }

  /* flood protection:
   * allow one knock per user per knock_delay
   * allow one knock per channel per knock_delay_channel
   *
   * we only limit local requests..
   */
  if(MyClient(source_p) &&
    (source_p->localClient->last_knock + ConfigChannel.knock_delay) > CurrentTime)
  {
    sendto_one(source_p, form_str(ERR_TOOMANYKNOCK),
               me.name, source_p->name, parv[1], "user");
    return;
  }
  else if((chptr->last_knock +
         ConfigChannel.knock_delay_channel) > CurrentTime)
  {
    sendto_one(source_p, form_str(ERR_TOOMANYKNOCK),
               me.name, source_p->name, parv[1], "channel");
    return;
  }

  /* pass on the knock */
  send_knock(client_p, source_p, chptr, name, key,
             MyClient(source_p) ? 0 : 1);
}

/*
 * parse_knock_remote
 *
 * input	- pointer to client
 *		- pointer to source
 *		- number of args
 *		- pointer to array of args
 * output	- none
 * side effects - knock is checked for validity, if valid send_knock() is
 * 		  called
 */
static void
parse_knock_remote(struct Client *client_p, struct Client *source_p,
		   int parc, char *parv[])
{
  struct Channel *chptr;
  char *p, *name, *key;
#ifdef VCHANS
  struct Channel *vchan_chptr;
#endif

  name = parv[1];
  key = (parc > 2) ? parv[2] : NULL;

  if((p = strchr(name,',')) != NULL)
    *p = '\0';

  if(!IsChannelName(name) || !(chptr = hash_find_channel(name)))
    return;

#ifdef VCHANS
  if(IsVchanTop(chptr))
  {
    if(on_sub_vchan(chptr,source_p))
      return;

    if(key && (key[0] == '!') && (vchan_chptr = find_vchan(chptr, key)))
      chptr = vchan_chptr;
    else
      return;
  }
  else if(IsVchan(chptr))
    return;
#endif

  if(IsMember(source_p, chptr))
    return;
  
  if(!((chptr->mode.mode & MODE_INVITEONLY) ||
     (*chptr->mode.key) ||
     (chptr->mode.limit && chptr->users >= chptr->mode.limit)))
    return;

  if(chptr)
    send_knock(client_p, source_p, chptr, name, key, 0);

  return;
}

/*
 * send_knock
 *
 * input        - pointer to physical struct client_p
 *              - pointer to source struct source_p
 *              - pointer to channel struct chptr
 *              - pointer to base channel name
 * output       -
 * side effects - knock is sent locally (if enabled) and propagated
 */

static void
send_knock(struct Client *client_p, struct Client *source_p,
	   struct Channel *chptr, char *name, char *key, int llclient)
{
  chptr->last_knock = CurrentTime;

  if(MyClient(source_p))
  {
    source_p->localClient->last_knock = CurrentTime;

    sendto_one(source_p, form_str(RPL_KNOCKDLVR),
               me.name, source_p->name, name);
  }
  else if(llclient == 1)
    sendto_one(source_p, form_str(RPL_KNOCKDLVR),
               me.name, source_p->name, name);

  if(source_p->user != NULL)
    {
      if(ConfigChannel.use_knock)
        sendto_channel_local(ONLY_CHANOPS_HALFOPS,
  			     chptr, form_str(RPL_KNOCK),
			     me.name, name, name,
			     source_p->name, source_p->username,
			     source_p->host);
      
      sendto_server(client_p, source_p, chptr, CAP_KNOCK, NOCAPS, LL_ICLIENT,
                    ":%s KNOCK %s %s",
		    source_p->name, name, key ? key : "");
    }

  return;
}

/* is_banned_knock()
 * 
 * input	- pointer to channel
 *		- pointer to client
 *		- clients sockhost
 * output	- 
 * side effects - return check_banned_knock()
 */
static int
is_banned_knock(struct Channel *chptr, struct Client *who, char *sockhost)
{
  char src_host[NICKLEN + USERLEN + HOSTLEN + 6];
  char src_iphost[NICKLEN + USERLEN + HOSTLEN + 6];

  if(!IsPerson(who))
    return 0;

  ircsprintf(src_host,"%s!%s@%s", who->name, who->username, who->host);
  ircsprintf(src_iphost,"%s!%s@%s", who->name, who->username, sockhost);

  return (check_banned_knock(chptr, who, src_host, src_iphost));
}

/* check_banned_knock()
 *
 * input	- pointer to channel
 * 		- pointer to client
 *		- preformed nick!user@host
 *		- preformed nick!user@ip
 * output	- 
 * side effects - return CHFL_EXCEPTION, CHFL_BAN or 0
 */
static int
check_banned_knock(struct Channel *chptr, struct Client *who,
		   char *s, char *s2)
{
  dlink_node *ban;
  dlink_node *except;
  struct Ban *actualBan = NULL;
  struct Ban *actualExcept = NULL;

  DLINK_FOREACH(ban, chptr->banlist.head)
  {
    actualBan = ban->data;

    if (match(actualBan->banstr, s) || match(actualBan->banstr, s2))
      break;
    else
      actualBan = NULL;
  }

  if ((actualBan != NULL) && ConfigChannel.use_except)
  {
    DLINK_FOREACH(except, chptr->exceptlist.head)
    {
      actualExcept = except->data;

      if (match(actualExcept->banstr, s) || match(actualExcept->banstr, s2))
        return CHFL_EXCEPTION;
    }
  }

  return ((actualBan ? CHFL_BAN : 0));
}
