/*   contrib/m_ojoin.c
 *   Copyright (C) 2002 Hybrid Development Team
 *
 *   This program is free software; you can redistribute it and/or modify
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
 *
 *   $Id$
 */

#include "stdinc.h"
#include "tools.h"
#include "handlers.h"
#include "channel.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "irc_string.h"
#include "hash.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "vchannel.h"
#include "list.h"
#include "channel_mode.h"

static void mo_ojoin(struct Client *client_p, struct Client *source_p,
                         int parc, char *parv[]);

struct Message ojoin_msgtab = {
  "OJOIN", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_ojoin}
};

void
_modinit(void)
{
  mod_add_cmd(&ojoin_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&ojoin_msgtab);
}

char *_version = "$Revision$";

/*
** mo_ojoin
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void mo_ojoin(struct Client *client_p, struct Client *source_p,
                        int parc, char *parv[])
{
  struct Channel *chptr, *root_chptr;
  int move_me = 0;
#ifdef VCHANS
  int on_vchan = 0;
#endif

  /* admins only */
  if (!IsOperAdmin(source_p))
    {
      sendto_one(source_p, ":%s NOTICE %s :You have no A flag", me.name, parv[0]);
      return;
    }

  /* XXX - we might not have CBURSTed this channel if we are a lazylink
   * yet. */
  if (*parv[1] == '@' || *parv[1] == '%' || *parv[1] == '+')
    {
      parv[1]++;
      move_me = 1;
    }

  chptr= hash_find_channel(parv[1]);
  root_chptr = chptr;

#ifdef VCHANS
  if (chptr && parc > 2 && parv[2][0] == '!')
    {
      chptr = find_vchan(chptr, parv[2]);
      if (root_chptr != chptr)
        on_vchan++;
    }
#endif

  if( chptr == NULL )
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
		 me.name, parv[0], parv[1]);
      return;
    }

  if(IsMember(source_p, chptr))
    {
      sendto_one(source_p, ":%s NOTICE %s :Please part %s before using OJOIN",
                 me.name, source_p->name, parv[1]);
      return;
    }

  if (move_me == 1)
    parv[1]--;

  if (*parv[1] == '@') 
    {
       add_user_to_channel(chptr, source_p, CHFL_CHANOP);
       if (chptr->chname[0] != '&')
         sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS, LL_ICLIENT, 
                 ":%s SJOIN %lu %s + :@%s", me.name, chptr->channelts,
                 chptr->chname, source_p->name);
       sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN %s",
                       source_p->name,
                       source_p->username,
                       source_p->host,
                       root_chptr->chname);
       sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s +o %s",
                       me.name, chptr->chname, source_p->name);

    }
#ifdef HALFOPS
  else if (*parv[1] == '%')
    {
       add_user_to_channel(chptr, source_p, CHFL_HALFOP);
       if (chptr->chname[0] != '&')
         sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS, LL_ICLIENT, 
                 ":%s SJOIN %lu %s + :%%%s", me.name, chptr->channelts,
                 chptr->chname, source_p->name);
       sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN %s",
                       source_p->name,
                       source_p->username,
                       source_p->host,
                       root_chptr->chname);
       sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s +h %s",
                       me.name, chptr->chname, source_p->name);
    }
#endif
  else if (*parv[1] == '+')
    {
       add_user_to_channel(chptr, source_p, CHFL_VOICE);
       if (chptr->chname[0] != '&')
         sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS, LL_ICLIENT, 
                 ":%s SJOIN %lu %s + :+%s", me.name, chptr->channelts,
                 chptr->chname, source_p->name);
       sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN %s",
                       source_p->name,
                       source_p->username,
                       source_p->host,
                       root_chptr->chname);
       sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s +v %s",
                       me.name, chptr->chname, source_p->name);
    }
  else
    {
       add_user_to_channel(chptr, source_p, CHFL_PEON);
       if (chptr->chname[0] != '&')
         sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS, LL_ICLIENT, 
                       ":%s SJOIN %lu %s + :%s",
                       me.name, chptr->channelts,
		       chptr->chname, source_p->name);
       sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN %s",
                       source_p->name,
                       source_p->username,
                       source_p->host,
                       root_chptr->chname);
    }

  /* send the topic... */
  if (chptr->topic != NULL)
  {
    sendto_one(source_p, form_str(RPL_TOPIC), me.name,
	       source_p->name, chptr->chname, chptr->topic);
    sendto_one(source_p, form_str(RPL_TOPICWHOTIME), me.name,
	       source_p->name, chptr->chname, chptr->topic_info,
	       chptr->topic_time);
  }

  /* XXX - check this isn't too big above... */
#ifdef VCHANS
  if (on_vchan)
    add_vchan_to_client_cache(source_p,root_chptr,chptr);
#endif

  source_p->localClient->last_join_time = CurrentTime;
  channel_member_names(source_p, chptr, chptr->chname, 1);
}

