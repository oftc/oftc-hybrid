/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_invite.c: Invites the user to join a channel.
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
#include "common.h"
#include "channel.h"
#include "channel_mode.h"
#include "list.h"
#include "vchannel.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "s_serv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"

static void m_invite(struct Client *, struct Client *, int, char **);

struct Message invite_msgtab = {
  "INVITE", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_unregistered, m_invite, m_invite, m_invite}
};
#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&invite_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&invite_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
** m_invite
**      parv[0] - sender prefix
**      parv[1] - user to invite
**      parv[2] - channel number
*/
static void
m_invite(struct Client *client_p,
         struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p;
  struct Channel *chptr, *vchan;
  int chop;                     /* Is channel op */
#ifdef VCHANS
  struct Channel *vchan2;
#endif

  if (*parv[2] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, parv[0], "INVITE");
    return;
  }

  if(!IsClient(source_p))
    return;

  if(MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((target_p = find_person(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK), me.name, parv[0], parv[1]);
    return;
  }

  if(check_channel_name(parv[2]) == 0)
  {
    sendto_one(source_p, form_str(ERR_BADCHANNAME),
               me.name, parv[0], (unsigned char *)parv[2]);
    return;
  }

  if (!IsChannelName(parv[2]))
  {
    if (MyClient(source_p))
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, parv[0], parv[2]);
    return;
  }

  /* Do not send local channel invites to users if they are not on the
   * same server as the person sending the INVITE message. 
   */
  /* Possibly should be an error sent to source_p */
  /* done .. there should be no problem because MyConnect(source_p) should
   * always be true if parse() and such is working correctly --is
   */

  if (!MyConnect(target_p) && (parv[2][0] == '&'))
  {
    if (ConfigServerHide.hide_servers == 0)
      sendto_one(source_p, form_str(ERR_USERNOTONSERV),
                 me.name, parv[0], parv[1]);
    return;
  }

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    if (MyClient(source_p))
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, parv[0], parv[2]);
    return;
  }

  /* By this point, chptr is non NULL */

#ifdef VCHANS
  if (!(HasVchans(chptr) && (vchan = map_vchan(chptr, source_p))))
    vchan = chptr;
  if (IsVchan(chptr))
    chptr = chptr->root_chptr;
#else
  vchan = chptr;
#endif
  
  if (MyClient(source_p) && !IsMember(source_p, vchan))
  {
    sendto_one(source_p, form_str(ERR_NOTONCHANNEL), me.name, parv[0],
               parv[2]);
    return;
  }

#ifdef VCHANS
  if ((vchan2 = map_vchan(chptr, target_p)))
  {
    if (MyClient(source_p) && ((vchan2->mode.mode & MODE_SECRET) == 0))
      sendto_one(source_p, form_str(ERR_USERONCHANNEL), me.name, parv[0],
                 parv[1], parv[2]);
    return;
  }
#endif

  if (IsMember(target_p, vchan))
  {
    if (MyClient(source_p))
      sendto_one(source_p, form_str(ERR_USERONCHANNEL),
                 me.name, parv[0], parv[1], parv[2]);
    return;
  }

  chop = is_chan_op(chptr, source_p);

  if (chptr && (vchan->mode.mode & MODE_INVITEONLY))
  {
    if (!chop)
    {
      if (MyClient(source_p))
        sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED),
                   me.name, parv[0], parv[2]);
      return;
    }
  }
  else
    /* Don't save invite even if from an op otherwise... */
    chop = 0;

  if (MyConnect(source_p))
  {
    sendto_one(source_p, form_str(RPL_INVITING), me.name, parv[0],
               target_p->name, parv[2]);
    if (target_p->user->away)
      sendto_one(source_p, form_str(RPL_AWAY), me.name, parv[0],
                 target_p->name, target_p->user->away);
  }

  if (!MyConnect(target_p) && ServerInfo.hub &&
      IsCapable(target_p->from, CAP_LL))
  {
    /* target_p is connected to a LL leaf, connected to us */
    if (IsPerson(source_p))
      client_burst_if_needed(target_p->from, source_p);

    if ((chptr->lazyLinkChannelExists &
         target_p->from->localClient->serverMask) == 0)
      burst_channel(target_p->from, vchan);
  }

  if (MyConnect(target_p))
  {
    if (chop)
      add_invite(vchan, target_p);
    sendto_one(target_p, ":%s!%s@%s INVITE %s :%s", source_p->name,
               source_p->username, source_p->host, target_p->name,
               chptr->chname);
  }

  /* if the channel is +pi, broadcast everywhere thats CAP_PARA, send to
   * target if target isnt CAP_PARA capable, else just send to target
   */
  if(ParanoidChannel(vchan))
  {
    sendto_channel_remote(source_p, client_p,
  		  	  ONLY_CHANOPS_HALFOPS, CAP_PARA, NOCAPS,
                          chptr, ":%s INVITE %s :%s", parv[0], 
                          target_p->name, vchan->chname);
			  
    if(!MyConnect(target_p) && (target_p->from != client_p) &&
       !IsCapable(target_p->from, CAP_PARA))
      sendto_one(target_p->from, ":%s INVITE %s :%s", parv[0],
                 target_p->name, vchan->chname);

    sendto_channel_local(ONLY_CHANOPS_HALFOPS, vchan,
                         ":%s NOTICE %s :%s is inviting %s to %s.",
			 me.name, chptr->chname, source_p->name,
			 target_p->name, chptr->chname);
  }
  else if(!MyConnect(target_p) && (target_p->from != client_p))
  {
    sendto_one(target_p->from, ":%s INVITE %s :%s", parv[0],
               target_p->name, vchan->chname);
  }
}
