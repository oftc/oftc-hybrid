/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_spingtime.c: Sets the ping time for a server(for MAP).
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

static void ms_spingtime(struct Client*, struct Client*, int, char**);

struct Message mode_msgtab = {
  "SPINGTIME", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_spingtime, m_ignore}
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
 * m_spingtime - SPINGTIME
 * parv[0] - sender
 * parv[1] - server to set ping time for
 * parv[2] - ping time
 */
static void ms_spingtime(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{

  struct Client *target_p;

  if ((target_p = find_server(parv[1])) == NULL)
      return;

  target_p->ping_time.tv_sec = 0;
  target_p->ping_time.tv_usec = atol(parv[2]);
  
  sendto_server(client_p, NULL, NULL, NOCAPS, NOCAPS, NOFLAGS,
                    ":%s SPINGTIME %s %s", parv[0], parv[1],
                  parv[2]);
}
