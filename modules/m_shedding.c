/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_shedding.c: Enables/disables user shedding.
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
#include "channel.h"
#include "client.h"
#include "common.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "s_conf.h"
#include "send.h"
#include "hash.h"
#include "handlers.h"
#include "s_serv.h"
#include "msg.h"
#include "s_gline.h"
#include "parse.h"
#include "modules.h"
#include "event.h"
#include "irc_string.h"

static void mo_shedding(struct Client *, struct Client *, int, char **);
void user_shedding_main(void *rate);
void user_shedding_shed(void *unused);

struct Message shedding_msgtab = {
  "shedding", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, m_ignore, mo_shedding, m_ignore}
};

static int rate = 60;
static int operstoo = 0;

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&shedding_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&shedding_msgtab);
  eventDelete(user_shedding_main, NULL);
  eventDelete(user_shedding_shed, NULL);
}

const char *_version = "$Revision: 472 $";
#endif

/* Local function prototypes */

char buffer[IRCD_BUFSIZE];

/*
 * mo_shedding
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - user shedding is enabled or disabled
 * 
 * SHEDDING OFF - disable shedding
 * SHEDDING :reason
 * SHEDDING approx_seconds_per_userdrop :reason
 * SHEDDING approx_seconds_per_userdrop opers_too?[0|1] :reason
 * 
 */
static void
mo_shedding(struct Client *client_p, struct Client *source_p,
	 int parc, char **parv)
{
  if(irccmp(parv[1], "OFF") == 0)
  {
      eventDelete(user_shedding_main, NULL);
      eventDelete(user_shedding_shed, NULL);
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
              "User shedding DISABLED by %s", source_p->name);
      return;
  }

  if(parc < 2) {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
        me.name, source_p->name, "SHEDDING");
    return;
  }

  if (parc > 1) 
    rate = atoi(parv[1]);
    
  if (parc > 2)
    operstoo = atoi(parv[2]);
    
  sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, 
          "User shedding ENABLED by %s (%s). Shedding interval: %d seconds (Opers too: %s)", 
          source_p->name, parv[parc], rate, operstoo == 0 ? "No" : "Yes");
  /* Set a minimum because we need to do a bit of variance */
  rate -= (rate/5);

  eventAdd("user shedding main event", user_shedding_main, NULL, rate);
}

void user_shedding_main(void *unused)
{
  int deviation = (rate / (3+(int) (7.0f*rand()/(RAND_MAX+1.0f))));

  eventAddIsh("user shedding shed event", user_shedding_shed, NULL, rate+deviation);
}

void user_shedding_shed(void *unused)
{
  dlink_node *ptr, *next_ptr;
  struct Client *client_p;
  
  DLINK_FOREACH_SAFE(ptr, next_ptr, local_client_list.head)
  {
      client_p = ptr->data;

      if(MyClient(client_p) && ((!IsOper(client_p)) || (operstoo == 0) ))
      {
          exit_client(client_p, &me, "Server closed connection");
          break;
      }
  }
  eventDelete(user_shedding_shed, NULL);
}
