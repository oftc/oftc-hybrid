/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_motd.c: Shows the current message of the day.
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
#include "client.h"
#include "tools.h"
#include "motd.h"
#include "ircd.h"
#include "send.h"
#include "numeric.h"
#include "handlers.h"
#include "hook.h"
#include "msg.h"
#include "s_serv.h"     /* hunt_server */
#include "parse.h"
#include "modules.h"
#include "s_conf.h"


static void mr_motd(struct Client *, struct Client *, int, char **);
static void m_motd(struct Client*, struct Client*, int, char**);
static void mo_motd(struct Client*, struct Client*, int, char**);

static void motd_spy(struct Client *);

struct Message motd_msgtab = {
  "MOTD", 0, 0, 0, 1, MFLG_SLOW, 0,
  {mr_motd, m_motd, mo_motd, mo_motd}
};
#ifndef STATIC_MODULES
void
_modinit(void)
{
  hook_add_event("doing_motd");
  mod_add_cmd(&motd_msgtab);
}

void
_moddeinit(void)
{
  hook_del_event("doing_motd");
  mod_del_cmd(&motd_msgtab);
}

const char *_version = "$Revision$";
#endif

/* mr_motd()
 *
 * parv[0] = sender prefix
 */
static void mr_motd(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  /* allow unregistered clients to see the motd, but exit them */
  SendMessageFile(source_p,&ConfigFileEntry.motd);
  exit_client(client_p, source_p, source_p, "Client Exit after MOTD");
}

/*
** m_motd
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static void m_motd(struct Client *client_p, struct Client *source_p,
                  int parc, char *parv[])
{
  static time_t last_used = 0;

  if((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
    {
      /* safe enough to give this on a local connect only */
      sendto_one(source_p,form_str(RPL_LOAD2HI),me.name,source_p->name);
      return;
    }
  else
    last_used = CurrentTime;

  /* This is safe enough to use during non hidden server mode */
  if(!ConfigServerHide.disable_remote)
    {
      if (hunt_server(client_p, source_p, ":%s MOTD :%s", 1,parc,parv)!=HUNTED_ISME)
	return;
    }

  motd_spy(source_p);
  
  SendMessageFile(source_p,&ConfigFileEntry.motd);
}

/*
** mo_motd
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static void mo_motd(struct Client *client_p, struct Client *source_p,
                   int parc, char *parv[])
{
  if(!IsClient(source_p))
    return;

  if (hunt_server(client_p, source_p, ":%s MOTD :%s", 1,parc,parv)!=HUNTED_ISME)
    return;

  motd_spy(source_p);
  
  SendMessageFile(source_p,&ConfigFileEntry.motd);
}

/* motd_spy()
 *
 * input        - pointer to client
 * output       - none
 * side effects - hook doing_motd is called
 */
static void motd_spy(struct Client *source_p)
{
  struct hook_spy_data data;

  data.source_p = source_p;

  hook_call_event("doing_motd", &data);
}

