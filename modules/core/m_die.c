/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_die.c: Kills off this server.
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
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_log.h"
#include "s_conf.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static void mo_die(struct Client*, struct Client*, int, char**);

struct Message die_msgtab = {
  "DIE", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_die}
};
#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&die_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&die_msgtab);
}

const char *_version = "$Revision$";
#endif
/*
 * mo_die - DIE command handler
 */
static void mo_die(struct Client *client_p, struct Client *source_p,
                  int parc, char *parv[])
{
  struct Client* target_p;
  dlink_node *ptr;

  if (!IsOperDie(source_p))
    {
      sendto_one(source_p,":%s NOTICE %s :You need die = yes;", me.name, parv[0]);
      return;
    }

  if (parc < 2)
    {
      sendto_one(source_p,":%s NOTICE %s :Need server name /die %s",
                 me.name,source_p->name,me.name);
      return;
    }
  else
    {
      if (irccmp(parv[1], me.name))
        {
          sendto_one(source_p,":%s NOTICE %s :Mismatch on /die %s",
                     me.name,source_p->name,me.name);
          return;
        }
    }

  for(ptr = lclient_list.head; ptr; ptr = ptr->next)
    {
      target_p = ptr->data;

      sendto_one(target_p,
		 ":%s NOTICE %s :Server Terminating. %s",
		 me.name, target_p->name,
		 get_client_name(source_p, HIDE_IP));
    }

  for(ptr = serv_list.head; ptr; ptr = ptr->next)
    {
      target_p = ptr->data;

      sendto_one(target_p, ":%s ERROR :Terminated by %s",
		 me.name, get_client_name(source_p, HIDE_IP));
    }

  /*
   * XXX we called flush_connections() here. Read server_reboot()
   * for an explanation as to what we should do.
   *     -- adrian
   */
  ilog(L_NOTICE, "Server terminated by %s", get_oper_name(source_p));
  /* 
   * this is a normal exit, tell the os it's ok 
   */
  exit(0);
  /* NOT REACHED */
}

