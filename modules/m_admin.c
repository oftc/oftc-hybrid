/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_admin.c: Sends administrative information to a user.
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
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "hook.h"
#include "modules.h"

static void m_admin(struct Client*, struct Client*, int, char**);
static void mr_admin(struct Client*, struct Client*, int, char**);
static void ms_admin(struct Client*, struct Client*, int, char**);
static void do_admin( struct Client *source_p );

static void admin_spy(struct Client *);

struct Message admin_msgtab = {
  "ADMIN", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0, 
  {mr_admin, m_admin, ms_admin, ms_admin}
};
#ifndef STATIC_MODULES
void
_modinit(void)
{
  hook_add_event("doing_admin");
  mod_add_cmd(&admin_msgtab);
}

void
_moddeinit(void)
{
  hook_del_event("doing_admin");
  mod_del_cmd(&admin_msgtab);
}
const char *_version = "$Revision$";
#endif
/*
 * mr_admin - ADMIN command handler
 *      parv[0] = sender prefix   
 *      parv[1] = servername   
 */
static void mr_admin(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  static time_t last_used=0L;
 
  if((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
    {
      sendto_one(source_p,form_str(RPL_LOAD2HI), me.name, 
                 BadPtr(parv[0]) ? "*" : parv[0]);
      return;
    }
  else
    last_used = CurrentTime;

  do_admin(source_p);
}

/*
 * m_admin - ADMIN command handler
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void m_admin(struct Client *client_p, struct Client *source_p, int parc,
                   char *parv[])
{
  static time_t last_used=0L;

  if((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
    {
      sendto_one(source_p,form_str(RPL_LOAD2HI),me.name,parv[0]);
      return;
    }
  else
    last_used = CurrentTime;

  if (!ConfigServerHide.disable_remote)
    {
      if (hunt_server(client_p,source_p,":%s ADMIN :%s",1,parc,parv) != HUNTED_ISME)
        return;
    }

  do_admin(source_p);
}


/*
 * ms_admin - ADMIN command handler, used for OPERS as well
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void ms_admin(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  if (hunt_server(client_p,source_p,":%s ADMIN :%s",1,parc,parv) != HUNTED_ISME)
    return;

  if(IsClient(source_p))
    do_admin(source_p);
}


/*
 * do_admin
 *
 * inputs	- pointer to client to report to
 * output	- none
 * side effects	- admin info is sent to client given
 */
static void do_admin( struct Client *source_p )
{

  char *nick;

  if (IsPerson(source_p))
    admin_spy(source_p);

  nick = BadPtr(source_p->name) ? "*" : source_p->name;

  sendto_one(source_p, form_str(RPL_ADMINME),
	     me.name, nick, me.name);
  if (AdminInfo.name != NULL)
    sendto_one(source_p, form_str(RPL_ADMINLOC1),
	       me.name, nick, AdminInfo.name);
  if (AdminInfo.description != NULL)
    sendto_one(source_p, form_str(RPL_ADMINLOC2),
	       me.name, nick, AdminInfo.description);
  if (AdminInfo.email != NULL)
    sendto_one(source_p, form_str(RPL_ADMINEMAIL),
	       me.name, nick, AdminInfo.email);
}

/* admin_spy()
 *
 * input	- pointer to client
 * output	- none
 * side effects - event doing_admin is called
 */
static void admin_spy(struct Client *source_p)
{
  struct hook_spy_data data;

  data.source_p = source_p;

  hook_call_event("doing_admin", &data);
}
