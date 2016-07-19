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
 *  $Id: m_realhost.c 612 2006-06-09 00:11:27Z stu $
 *
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_misc.h"
#include "s_stats.h"
#include "s_user.h"
#include "hash.h"
#include "whowas.h"
#include "s_serv.h"
#include "send.h"
#include "channel.h"
#include "resv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "common.h"
#include "packet.h"
#include "irc_string.h"


static void ms_certfp(struct Client *, struct Client *, int, char**);

struct Message certfp_msgtab = {
      "CERTFP", 0, 0, 2, 0, MFLG_SLOW, 0,
        {m_ignore, m_ignore, ms_certfp, m_ignore}
};

const char *_version = "$Revision 0.1$";

void _modinit(void)
{
  mod_add_cmd(&certfp_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&certfp_msgtab);
}

static void ms_certfp(struct Client *source_p, struct Client *client_p, int parc, char **parv)
{
  struct Client *target_p;

  if ((target_p = find_person(client_p, parv[1])) == NULL)
    return;

  strlcpy(target_p->certfp, parv[2], sizeof(target_p->certfp));

  sendto_server(client_p, NULL, NOCAPS, NOCAPS, NOFLAGS,
      ":%s CERTFP %s %s", parv[0], parv[1], parv[2]);
}
