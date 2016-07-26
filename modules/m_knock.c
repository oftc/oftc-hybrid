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

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"
#include "handlers.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "modules.h"
#include "msg.h"
#include "numeric.h"
#include "parse.h"
#include "s_conf.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "sprintf_irc.h"
#include "stdinc.h"
#include "tools.h"

static void m_knock(struct Client *, struct Client *, int, char **);

struct Message knock_msgtab = {
    "KNOCK", 0,
    0,       2,
    0,       MFLG_SLOW,
    0,       {m_unregistered, m_knock, m_knock, m_ignore, m_knock, m_ignore}};

#ifndef STATIC_MODULES

void
_modinit(void)
{
    mod_add_cmd(&knock_msgtab);
    add_capability("KNOCK", CAP_KNOCK, 1);
    add_isupport("KNOCK", NULL, -1);
}

void
_moddeinit(void)
{
    mod_del_cmd(&knock_msgtab);
    delete_capability("KNOCK");
    delete_isupport("KNOCK");
}

const char *_version = "$Revision$";
#endif

/* m_knock
 *    parv[0] = sender prefix
 *    parv[1] = channel
 *
 *  The KNOCK command has the following syntax:
 *   :<sender> KNOCK <channel>
 *
 *  If a user is not banned from the channel they can use the KNOCK
 *  command to have the server NOTICE the channel operators notifying
 *  they would like to join.  Helpful if the channel is invite-only, the
 *  key is forgotten, or the channel is full (INVITE can bypass each one
 *  of these conditions.  Concept by Dianora <db@db.net> and written by
 *  <anonymous>
 *
 */
static void
m_knock(struct Client *client_p, struct Client *source_p, int parc,
        char *parv[])
{
    struct Channel *chptr = NULL;

    if(EmptyString(parv[1]))
    {
        sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), me.name,
                   source_p->name, "KNOCK");
        return;
    }

    if((ConfigChannel.use_knock == 0) && MyClient(source_p))
    {
        sendto_one(source_p, form_str(ERR_KNOCKDISABLED), me.name,
                   source_p->name);
        return;
    }

    if((chptr = hash_find_channel(parv[1])) == NULL)
    {
        sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name,
                   source_p->name, parv[1]);

        return;
    }

    /* Normal channel, just be sure they aren't on it */
    if(IsMember(source_p, chptr))
    {
        sendto_one(source_p, form_str(ERR_KNOCKONCHAN), me.name, source_p->name,
                   parv[1]);
        return;
    }

    if(!((chptr->mode.mode & MODE_INVITEONLY) || (*chptr->mode.key) ||
         (chptr->mode.limit &&
          dlink_list_length(&chptr->members) >= chptr->mode.limit)))
    {
        sendto_one(source_p, form_str(ERR_CHANOPEN), me.name, source_p->name,
                   parv[1]);
        return;
    }

    /* don't allow a knock if the user is banned, or the channel is secret */
    if((chptr->mode.mode & MODE_PRIVATE) || is_banned(chptr, source_p))
    {
        sendto_one(source_p, form_str(ERR_CANNOTSENDTOCHAN), me.name,
                   source_p->name, parv[1]);
        return;
    }

    /* flood protection:
     * allow one knock per user per knock_delay
     * allow one knock per channel per knock_delay_channel
     *
     * we only limit local requests..
     */
    if(MyClient(source_p) &&
       (source_p->localClient->last_knock + ConfigChannel.knock_delay) >
           CurrentTime)
    {
        sendto_one(source_p, form_str(ERR_TOOMANYKNOCK), me.name,
                   source_p->name, parv[1], "user");
        return;
    }
    else if(chptr->last_knock + ConfigChannel.knock_delay_channel > CurrentTime)
    {
        sendto_one(source_p, form_str(ERR_TOOMANYKNOCK), me.name,
                   source_p->name, parv[1], "channel");
        return;
    }
}
