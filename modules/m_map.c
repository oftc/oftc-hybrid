/************************************************************************
 *   IRC - Internet Relay Chat, modules/m_map.c
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
#include "tools.h"
#include "common.h"
#include "handlers.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "vchannel.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "list.h"
#include "irc_string.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

#define MAX_MAP_DEPTH 10


static void m_map(struct Client *client_p, struct Client *source_p, int parc, char *parv[]);

const char* _version = "$Revision 0.4$";

struct Message map_msgtab = {
      "MAP", 0, 0, 0, 0, MFLG_SLOW, 0,
        {m_unregistered, m_not_oper, m_map, m_map}
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



static char header[(MAX_MAP_DEPTH*2) + 4 + 1];
static int header_length;

static void map_send_server(struct Client* source_p, char* sender_prefix, 
        struct Client* current)
{
  struct Client* target_p;

  if (!current->serv)
    return; /* this should never happen, but let's be safe... */

  /* header should be formatted for us already */
  sendto_one(source_p, form_str(RPL_MAP), me.name, sender_prefix, header, 
          current->name, (current->ping_time.tv_sec * 1000) + 
          (current->ping_time.tv_usec / 1000));

  /* Now, iterate over it's children */
  if (current->serv->servers)
    {
      /* Is this a child? */
      if (header_length > 0)
	{
	  /* OK, was our parent a tail? */
	  if (header[header_length - 2] == '`')
	    /* Yes, remove that from the string, it's no longer needed */
	    header[header_length - 2] = ' ';
	  /* Regardless, remove the - from it's current position */
	  header[header_length - 1] = ' ';
	}
      /* Add the marker for "more children" */
      strcat(header, "|-");
      header_length += 2;
      for (target_p = current->serv->servers; target_p->lnext; target_p = target_p->lnext) /* Break one hop early to get tail right */
	{
	  /* Some of these calls might eat this, add it back */
	  header[header_length - 1] = '-';
	  map_send_server(source_p, sender_prefix, target_p);
	}
      /* Convert | to ` in this one, it's my last child */
      header[header_length - 2] = '`';
      header[header_length - 1] = '-';
      map_send_server(source_p, sender_prefix, target_p);
      /* Remove the trailing "  " from the string now */
      header[header_length - 2] = '\0';
      header_length -= 2;
    }
}

static void m_map(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct ConfItem* conf;

  if (parc > 1)
    if (hunt_server(client_p, source_p, ":%s MAP %s", 1, parc, parv) != HUNTED_ISME)
      return;

  header_length = 0;
  header[0] = '\0';
  map_send_server(source_p, parv[0], &me);
  for (conf = ConfigItemList; conf; conf = conf->next)
    {
        if (conf->status != CONF_SERVER)
            continue;
      if (strcmp(conf->name, me.name) == 0)
	continue;
      if (!find_server(conf->name))
	sendto_one(source_p, form_str(RPL_MAP), me.name, parv[0], "** ", conf->name, -1);
    }
  sendto_one(source_p,form_str(RPL_MAPEND),me.name,parv[0]);

  return;
} 
