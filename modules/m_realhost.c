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
 *  $Id$
 *
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_stats.h"
#include "s_user.h"
#include "hash.h"
#include "whowas.h"
#include "s_serv.h"
#include "send.h"
#include "channel.h"
#include "s_log.h"
#include "resv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "common.h"
#include "packet.h"


static void ms_realhost(struct Client *, struct Client *, int, char**);

struct Message realhost_msgtab = {
      "REALHOST", 0, 0, 2, 0, MFLG_SLOW, 0,
        {m_ignore, m_ignore, ms_realhost, m_ignore}
};

const char *_version = "$Revision 0.1$";

void _modinit(void)
{
  mod_add_cmd(&realhost_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&realhost_msgtab);
}

static void ms_realhost(struct Client *source_p, struct Client *client_p, int parc, char **parv)
{
  struct Client *target_p;
  
  if ((target_p = find_person(parv[1])) == NULL)
    return;

  if(target_p->realhost[0] == '\0')
      strlcpy(target_p->realhost, parv[2], HOSTLEN);
}

