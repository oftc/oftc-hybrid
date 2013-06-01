/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_gnotice.c: Sends a NOTICE to all opers on the network
 *
 *  Copyright (C) 2002 Stuart Walsh
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
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "send.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "packet.h"
#include "irc_string.h"

static void
me_gnotice(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  char *message;
  int flags, level;

  message = parv[3];
  level = atoi(parv[2]);
  flags = atoi(parv[1]);

  if(EmptyString(message))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), me.name, parv[0], "GNOTICE");
    return;
  }

  sendto_realops_remote(source_p, flags, level, message);
}

static void 
ms_gnotice(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  char* message;
  
  message = parv[3];
  
  if (EmptyString(message) || EmptyString(parv[1]))
  { 
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
        me.name, parv[0], "GNOTICE");
    return;
  }
}

struct Message gnotice_msgtab = {
  "GNOTICE", 0, 0, 3, 0, MFLG_SLOW, 0L,
  { m_ignore, m_ignore, ms_gnotice, me_gnotice, m_ignore, m_ignore }
};

void
module_init(void)
{
  mod_add_cmd(&gnotice_msgtab);
}

void
module_exit(void)
{
  mod_del_cmd(&gnotice_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
