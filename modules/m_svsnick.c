/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_svsnick.c: Sets a user or channel mode.
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
#include "s_user.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"
#include "common.h"

static void m_svsnick(struct Client*, struct Client*, int, char**);

struct Message mode_msgtab = {
  "SVSNICK", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_svsnick, m_svsnick, m_svsnick, m_ignore}
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
 * m_svsnick - MODE command handler
 * parv[0] - sender
 * parv[1] - nick
 * parv[2] - newnick
 */
static void m_svsnick(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{

  struct Client *target_p;

  
  /* Return quietly if this
   * is a non service 
   */

  if(!IsService(source_p))
     return; 

  if (parc < 3)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), me.name, parv[0], 
        "SVSNICK");
    return;
  }

  if((target_p = find_chasing(source_p, parv[1], NULL)) == NULL)
    return;

  if(MyClient(target_p))
  {
    /* Prevent flood checks */
    target_p->localClient->number_of_nick_changes = 0;
    /* Start NICK change as though it originated from this server */
    change_local_nick(target_p->servptr, target_p, parv[2]);
  } 
  else
    sendto_server(client_p, NULL, NULL, NOCAPS, NOCAPS, NOFLAGS,
        ":%s SVSNICK %s %s", parv[0], parv[1], parv[2]);
}
