/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_svsmode.c: Sets a user or channel mode.
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
#include "common.h"

static void m_svsmode(struct Client*, struct Client*, int, char**);

struct Message mode_msgtab = {
  "SVSMODE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, m_svsmode, m_ignore}
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
 * m_svsmode - MODE command handler
 * parv[0] - sender
 * parv[1] - channel or user
 * parv[2] - modes
 */
static void m_svsmode(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{

  struct Client *target_p;
  int badflag = NO;
  int what, svs_stamp;
  char **p, *m;

  what = MODE_ADD;
  
  /* Return quietly if this
   * is a non service 
   */

  if(!IsService(source_p))
    return; 

  if (parc < 3)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
        me.name, parv[0], "MODE");
    return;
  }

  if ((target_p = find_person(parv[1])) == NULL)
  {
    if (MyConnect(source_p))
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL), me.name, parv[0], 
            parv[1]);
    return;
  }

  for(p = &parv[2]; p && *p; p++)
    for(m = *p; *m; m++)
      switch(*m)
      {
        case '+':
          what = MODE_ADD;
          break;
        case '-':
          what = MODE_DEL;
          break;
        case 'R':
          if(what == MODE_ADD)
          {
            target_p->umodes |= FLAGS_NICKSERVREG;
            if(MyClient(target_p))
              sendto_one(target_p, ":%s MODE %s :+R", target_p->name, 
                    target_p->name);
          }
          else
            target_p->umodes &= ~FLAGS_NICKSERVREG;
        break;
       }
  /* Propogate the SVSMODE to other servers */
  sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, NOFLAGS,
                 ":%s SVSMODE %s %s :%s", parv[0], parv[1],
                  parv[2], (parc >= 4) ? parv[3] : "");
}
