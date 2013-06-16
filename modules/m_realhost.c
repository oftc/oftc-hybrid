/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_realhost.c: Sets a users real host(after cloaking).
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
 */

#include "stdinc.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_user.h"
#include "hash.h"
#include "whowas.h"
#include "s_serv.h"
#include "send.h"
#include "channel.h"
#include "resv.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"
#include "irc_string.h"

static void ms_realhost(struct Client *source_p, struct Client *client_p,
                        int parc, char **parv)
{
  if (source_p->realhost[0] == '\0')
    strlcpy(source_p->realhost, parv[1], sizeof(source_p->realhost));

  sendto_server(client_p, CAP_TS6, NOCAPS, ":%s REALHOST :%s", ID(source_p), 
                parv[1]);
  sendto_server(client_p, NOCAPS, CAP_TS6, ":%s REALHOST :%s", source_p->name, 
                parv[1]);
}

struct Message realhost_msgtab =
{
  "REALHOST", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_realhost, m_ignore}
};

void
module_init()
{
  mod_add_cmd(&realhost_msgtab);
}

void
module_exit()
{
  mod_del_cmd(&realhost_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
