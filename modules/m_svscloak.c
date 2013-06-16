/************************************************************************
 *   IRC - Internet Relay Chat, src/m_svscloak.c
 *   This file is copyright (C) 2002 Stuart Walsh
 *                                    <stu@ipng.org.uk>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#include "stdinc.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "whowas.h" /* off_history */
#include "userhost.h"

/* m_svscloak - Cloaks a user
 * parv[1] - Hostname to cloak to
 *
 * We receive the Message that a client will be cloaked
 * 1) check message for correctness
 * 2) If the client is ours, notify of cloaking
 * 3) pass the message down to other servers
 * 4) modify the local clients structure
 * 5) remove the whowas entry with the real hostname
 * -mc
 */

void m_svscloak(struct Client *client_p, struct Client *source_p, int parc,
                char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), me.name, parv[0]);
    return;
  }

  if (MyClient(source_p) && irccmp(source_p->host, parv[1]) != 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :Activating Cloak: %s",
               me.name, source_p->name, parv[1]);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Activating Cloak: %s -> %s for %s", source_p->host, 
                         parv[1], source_p->name);
  }

  sendto_server(client_p, CAP_TS6, NOCAPS, ":%s SVSCLOAK :%s", ID(source_p), 
                parv[1]);
  sendto_server(client_p, NOCAPS, CAP_TS6, ":%s SVSCLOAK :%s", source_p->name,
                parv[1]);

  if (source_p->realhost[0] == '\0')
    strncpy(source_p->realhost, source_p->host, sizeof(source_p->realhost));

  if (IsUserHostIp(source_p))
  {
    delete_user_host(source_p->username, source_p->host, !MyConnect(source_p));
    add_user_host(source_p->username, parv[1], !MyConnect(source_p));
  }

  strlcpy(source_p->host, parv[1], sizeof(source_p->host));
  off_history(source_p);

  rehashed_klines = 1;
}

struct Message map_msgtab =
{
  "SVSCLOAK", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, m_svscloak, m_ignore, m_ignore}
};

void
module_init()
{
  mod_add_cmd(&map_msgtab);
}

void
module_exit()
{
  mod_del_cmd(&map_msgtab);
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
