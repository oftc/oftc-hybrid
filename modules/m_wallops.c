/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_wallops.c: Sends a message to all operators.
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
 *  $Id: m_wallops.c 681 2006-07-31 11:56:54Z stu $
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "send.h"
#include "s_user.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_serv.h"

static void ms_wallops(struct Client *, struct Client *, int, char **);
static void mo_wallops(struct Client *, struct Client *, int, char **);

struct Message wallops_msgtab = {
  "WALLOPS", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_wallops, m_ignore, mo_wallops, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&wallops_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&wallops_msgtab);
}
 
const char *_version = "$Revision: 681 $";
#endif

/*
 * mo_wallops (write to *all* opers currently online)
 *      parv[0] = sender prefix
 *      parv[1] = message text
 */
static void
mo_wallops(struct Client *client_p, struct Client *source_p,
	   int parc, char *parv[])
{ 
  const char *message = parv[1];

  if (EmptyString(message))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "WALLOPS");
    return;
  }

  sendto_wallops_flags(UMODE_OPERWALL, source_p, "%s", message);
  sendto_server(NULL, source_p, NULL, CAP_TS6, NOCAPS, LL_ICLIENT,
                ":%s WALLOPS :%s", ID(source_p), message);
  sendto_server(NULL, source_p, NULL, NOCAPS, CAP_TS6, LL_ICLIENT,
                ":%s WALLOPS :%s", source_p->name, message);
}

/*
 * ms_wallops (write to *all* opers currently online)
 *      parv[0] = sender prefix
 *      parv[1] = message text
 */
static void
ms_wallops(struct Client *client_p, struct Client *source_p,
	   int parc, char *parv[])
{ 
  const char *message = parv[1];

  if (EmptyString(message))
    return;

  if (IsClient(source_p))
    sendto_wallops_flags(UMODE_WALLOP, source_p, "%s", message);
  else
    sendto_wallops_flags(UMODE_WALLOP, source_p, "%s", message); 

  sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS, LL_ICLIENT,
                ":%s WALLOPS :%s", ID(source_p), message);
  sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6, LL_ICLIENT,
                ":%s WALLOPS :%s", source_p->name, message);
}

