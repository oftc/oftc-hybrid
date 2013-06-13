/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_certfp.c: Sets a users certificate fingerprint
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
 *
 */

#include "stdinc.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_misc.h"
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

static void ms_certfp(struct Client *source_p, struct Client *client_p,
                      int parc, char **parv)
{
  struct Client *target_p;

  if ((target_p = find_person(client_p, parv[1])) == NULL)
    return;

  strlcpy(target_p->certfp, parv[2], sizeof(target_p->certfp));

  sendto_server(client_p, NOCAPS, NOCAPS, NOFLAGS,
                ":%s CERTFP %s %s", parv[0], parv[1], parv[2]);
}

struct Message certfp_msgtab =
{
  "CERTFP", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_certfp, m_ignore}
};

void module_init()
{
  mod_add_cmd(&certfp_msgtab);
}

void
module_exit()
{
  mod_del_cmd(&certfp_msgtab);
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
