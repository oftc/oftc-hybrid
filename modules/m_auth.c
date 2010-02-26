/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_auth.c: Authenticate the user with services
 *
 *  Copyright (C) 2010 by the past and present ircd coders, and others.
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
 *  $Id: m_auth.c 978 2007-11-05 23:51:42Z swalsh $
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_auth.h"
#include "s_user.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "hash.h"

static void ms_auth(struct Client *, struct Client *, int, char *[]);

struct Message user_msgtab = {
  "AUTH", 0, 0, 4, 0, MFLG_SLOW, 0L,
  { m_ignore, m_ignore, ms_auth, m_ignore, m_ignore, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&user_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&user_msgtab);
}

const char *_version = "$Revision: 978 $";
#endif

/*
** ms_auth
**      parv[0] = sender prefix
**      parv[1] = nickname authenticating for
**      parv[2] = account(username) authenticating for
**      parv[3] = result
**      parv[4] = reason
*/
static void
ms_auth(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p;

  target_p = find_client(parv[1]);

  if(target_p == NULL)
    return;

  if(MyConnect(target_p))
  {
    if(*parv[3] == '1')
    {
      target_p->umodes |= UMODE_NICKSERVREG;
      if(target_p->localClient->registration & REG_NEED_USER)
      {
        do_local_user(parv[1], target_p, target_p,
            parv[2], /* username */
            "*", /* host     */
            "*", /* server   */
            target_p->info  /* users real name */ );
      }
      else
        register_local_user(target_p, target_p, parv[1], parv[2]);
    }
    else
      exit_client(target_p, &me, parv[4]);
  }
  else
  {
    // send on
  }
}
