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
#include "common.h"
#include "handlers.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "whowas.h" /* off_history */
#include "userhost.h"

/* $Id$ */

void m_svscloak(struct Client *client_p, struct Client *source_p, int parc, char *parv[]);

struct Message map_msgtab = {
  "SVSCLOAK", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, m_svscloak, m_ignore, m_ignore}
};

void _modinit(void)
{
  mod_add_cmd(&map_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&map_msgtab);
}

const char* _version = "$Revision: 396 $";


/* m_svscloak - Cloaks a user - stu
 * parv[1] - Nick to cloak
 * parv[2] - Hostname to cloak to
 *
 * We receive the Message that a client will be cloaked
 * 1) check message for correctness
 * 2) If the client is ours, notify of cloaking
 * 3) pass the message down to other servers
 * 4) modify the local clients structure
 * 5) remove the whowas entry with the real hostname
 * -mc
 */

void m_svscloak(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p;
  char *hostname, *target;

  if(parc < 3 || EmptyString(parv[2]))
  {   
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), me.name, parv[0]);
    return;
  }
  target = parv[1];
  hostname = parv[2];

  if ((target_p = find_person(client_p, target)))
  {   
    if(MyClient(target_p) && irccmp(target_p->host, hostname) != 0)
    {   
      sendto_one(target_p, ":%s NOTICE %s :Activating Cloak: %s",
          me.name, target_p->name, hostname);
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
          "Activating Cloak: %s -> %s for %s", target_p->host, hostname,
          target_p->name);
    }

    /* Send to all Servers but the one WE got the SVSCLOAK from */
    sendto_server(client_p, NULL, NULL, NOCAPS, NOCAPS, NOFLAGS, 
          ":%s SVSCLOAK %s :%s", parv[0], parv[1], parv[2]);

    /* locally modify the clients structure */
    if(target_p->realhost[0] == '\0')
        strncpy(target_p->realhost, target_p->host, HOSTLEN);
    if(IsUserHostIp(target_p))
    {
      delete_user_host(target_p->username, target_p->host, !MyConnect(target_p));
      add_user_host(target_p->username, hostname, !MyConnect(target_p));
    }
    strncpy(target_p->host, hostname, HOSTLEN);
    off_history(target_p);

    rehashed_klines = 1;
  }
  else
  {   
    sendto_one(source_p, form_str(ERR_NOSUCHNICK), me.name, source_p->name, target);
    return;
  }
  return;
}

