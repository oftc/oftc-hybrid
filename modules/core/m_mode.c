/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_mode.c: Sets a user or channel mode.
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
#include "vchannel.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_user.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"

static void m_mode(struct Client*, struct Client*, int, char**);

struct Message mode_msgtab = {
  "MODE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_mode, m_mode, m_mode}
};
#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&mode_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&mode_msgtab);
}


const char *_version = "$Revision$";
#endif
/*
 * m_mode - MODE command handler
 * parv[0] - sender
 * parv[1] - channel
 */
static void m_mode(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{
  struct Channel* chptr=NULL;
  struct Channel* root;
  static char     modebuf[MODEBUFLEN];
  static char     parabuf[MODEBUFLEN];
  dlink_node	*ptr;
  int n = 2;
#ifdef VCHANS
  struct Channel* vchan;
#endif

  /* Now, try to find the channel in question */
  if (!IsChanPrefix(parv[1][0]))
    {
      /* if here, it has to be a non-channel name */
      user_mode(client_p, source_p, parc, parv);
      return;
    }

  if (!check_channel_name(parv[1]))
    { 
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
		 me.name, parv[0], (unsigned char *)parv[1]);
      return;
    }
	  
  chptr = hash_find_channel(parv[1]);

  if (chptr == NULL)
    {
      /* if chptr isn't found locally, it =could= exist
       * on the uplink. So ask.
       */
      
      /* LazyLinks */
      /* this was segfaulting if we had no servers linked.
       *  -pro
       */
      /* only send a mode upstream if a local client sent this request
       * -davidt
       */
      if (MyClient(source_p) && !ServerInfo.hub && uplink &&
	   IsCapable(uplink, CAP_LL))
	{
#if 0
	  /* cache the channel if it exists on uplink
	   * If the channel as seen by the uplink, has vchans,
	   * the uplink will have to SJOIN all of those.
	   */
	  /* Lets not for now -db */

	  sendto_one(uplink, ":%s CBURST %s",
                     me.name, parv[1]);
	  
#endif
	  sendto_one(uplink, ":%s MODE %s %s",
		     source_p->name, parv[1], (parv[2] ? parv[2] : ""));
	  return;
	}
      else
	{
	  sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
		     me.name, parv[0], parv[1]);
	  return;
	}
    }
  
  /* Now known the channel exists */

  root = chptr;

#ifdef VCHANS
  if ((parc > 2) && parv[2][0] == '!')
    {
     struct Client *target_p;
     if (!(target_p = find_client(++parv[2])))
       {
        sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name,
                   parv[0], root->chname);
        return;
       }
     if ((chptr = map_vchan(root, target_p)) == NULL)
       {
        sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name,
                   parv[0], root->chname);
        return;
       }
     n++;
    }

  else
    {
      if (HasVchans(chptr))
        {
          if ((vchan = map_vchan(chptr,source_p)) != NULL)
            chptr = vchan; /* root = chptr, chptr = vchan */

          /* XXX - else? the user isn't on any vchan, so we
           *       end up giving them the mode of the root
           *       channel.  MODE #vchan !nick ? (ugh)
           */
        }
      else if (IsVchan(chptr))
        {
          vchan = find_bchan(chptr);
          root = vchan;  /* root = vchan, chptr = chptr */

          /* XXX - else? the user isn't on any vchan,
           *       but they asked for MODE ##vchan_12345
           *       we send MODE #vchan
           */
        }
    }
#endif

  if (parc < n+1)
    {
      channel_modes(chptr, source_p, modebuf, parabuf);
      sendto_one(source_p, form_str(RPL_CHANNELMODEIS),
		 me.name, parv[0], parv[1],
		 modebuf, parabuf);
      
      /* Let opers see the "true" TS everyone else see's
       * the top root chan TS
       */
      if (!IsOper(source_p))
	sendto_one(source_p, form_str(RPL_CREATIONTIME),
		   me.name, parv[0],
		   parv[1], root->channelts);
      else
	sendto_one(source_p, form_str(RPL_CREATIONTIME),
		   me.name, parv[0],
		   parv[1], chptr->channelts);
    }
  /* bounce all modes from people we deop on sjoin */
  else if((ptr = find_user_link(&chptr->deopped, source_p)) == NULL)
  {
    /* Finish the flood grace period... */
    if(MyClient(source_p) && !IsFloodDone(source_p))
    {
      if((parc == n) && (parv[n-1][0] == 'b') && (parv[n-1][1] == '\0'))
        ;
      else
        flood_endgrace(source_p);
    }

    set_channel_mode(client_p, source_p, chptr, parc - n, parv + n, 
                     root->chname);
  }
}




