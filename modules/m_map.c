/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_map.c: Sends an Undernet compatible map to a user.
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
#include "modules.h"
#include "handlers.h"
#include "hash.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "ircd.h"
#include "irc_string.h"
#include "sprintf_irc.h"

static void mo_map(struct Client *, struct Client *, int, char *[]);
static void dump_map(struct Client *, struct Client *, int, char *);

struct Message map_msgtab = {
  "MAP", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_map, m_ignore}
};

#ifndef STATIC_MODULES
void _modinit(void)
{
  mod_add_cmd(&map_msgtab);
}

void _moddeinit(void)
{
  mod_del_cmd(&map_msgtab);
}

const char *_version = "$Revision$";
#endif

static char buf[IRCD_BUFSIZE];
static int line_counter;

/* mo_map()
 *      parv[0] = sender prefix
 */
static void
mo_map(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct ConfItem *conf;
  struct AccessItem *aconf;
  dlink_node *ptr;

  line_counter = 0;
  dump_map(client_p, &me, 0, buf);
  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;
    aconf = &conf->aconf;
    if (aconf->status != CONF_SERVER)
      continue;
    if (strcmp(conf->name, me.name) == 0)
      continue;
    if (!find_server(conf->name))
    {
      char buffer[IRCD_BUFSIZE];
      ircsprintf(buffer, "** %s (Not Connected)", conf->name);
      sendto_one(client_p, form_str(RPL_MAP), me.name, client_p->name, buffer);
    }
  }

  sendto_one(client_p, form_str(RPL_MAPEND), me.name, client_p->name);
}

/* dump_map()
 *   dumps server map, called recursively.
 */
static void
dump_map(struct Client *client_p, struct Client *root_p, int start_len,
	 char *pbuf)
{
  int cnt = 0, i = 0, l = 0, len = start_len;
  int users, dashes;
  dlink_node *ptr;
  struct Client *server_p;
  char *pb;
  int print_dashes;

  *pbuf= '\0';
  pb = pbuf;

  l = ircsprintf(pb, "%s", root_p->name);
  pb += l;
  len += l;

  print_dashes = ((line_counter - 1) % 3 == 0);
  line_counter++;

  /* IsOper isn't called *that* often. */
  if (IsOper(client_p))
  {
    if (root_p->id[0] != '\0')
    {
      l = ircsprintf(pb, "[%s]", root_p->id);
      pb += l;
      len += l;
    }
  }

  *pb++ = ' ';
  len++;
  dashes = 46 - len;
  for(i = 0; i < dashes; i++)
  {
    *pb++ = print_dashes ? '-' : ' ';
  }

  users = dlink_list_length(&root_p->serv->users);

  sprintf(pb, "%5d [%4.1f%%]", users,
	  100 * (float)users / (float)Count.total);
  if (print_dashes)  /* make the leading spaces of the usercount dashes too, if required */
      while(*(pb+1) == ' ') *pb++ = '-';

  sendto_one(client_p, form_str(RPL_MAP), me.name, client_p->name, buf);
        
  if (root_p->serv->servers.head)
  {
    cnt += dlink_list_length(&root_p->serv->servers);

    if (cnt)
    {
      if (pbuf > buf + 3)
      {
        pbuf[-2] = ' ';

        if (pbuf[-3] == '`')
          pbuf[-3] = ' ';
      }
    }
  }

  i = 1;

  DLINK_FOREACH(ptr, root_p->serv->servers.head)
  {
    server_p = ptr->data;

    *pbuf = ' ';
    if (i < cnt)
      *(pbuf + 1) = '|';
    else
      *(pbuf + 1) = '`';
      
    *(pbuf + 2) = '-';
    *(pbuf + 3) = ' ';
    dump_map(client_p, server_p, start_len+4, pbuf+4);
 
    ++i;
  }
}
