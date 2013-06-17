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
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "ircd.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "parse.h"
#include "hash.h"


static char buf[IRCD_BUFSIZE];
static int line_counter;

/* dump_map()
 *   dumps server map, called recursively.
 */
static void
dump_map(struct Client *client_p, const struct Client *root_p,
         int start_len, char *pbuf)
{
  int cnt = 0, i = 0, l = 0, len = start_len;
  int users, dashes;
  const dlink_node *ptr = NULL;
  char *pb;
  int print_dashes;

  *pbuf = '\0';
  pb = pbuf;

  l = ircsprintf(pb, "%s", root_p->name);
  pb += l;
  len += l;

  print_dashes = ((line_counter - 1) % 3 == 0);
  line_counter++;

  /* IsOper isn't called *that* often. */
  if (HasUMode(client_p, UMODE_OPER))
  {
    l = ircsprintf(pb, "[%s]", root_p->id);
    pb += l;
    len += l;
  }

  *pb++ = ' ';
  len++;
  dashes = 46 - len;

  for (i = 0; i < dashes; i++)
  {
    *pb++ = print_dashes ? '-' : ' ';
  }

  users = dlink_list_length(&root_p->serv->client_list);

  sprintf(pb, "%5d [%4.1f%%]", users,
          100 * (float)users / (float)Count.total);

  if (print_dashes)  /* make the leading spaces of the usercount dashes too, if required */
    while (*(pb + 1) == ' ') *pb++ = '-';

  sendto_one(client_p, form_str(RPL_MAP), me.name, client_p->name, buf);

  if (root_p->serv->server_list.head)
  {
    cnt += dlink_list_length(&root_p->serv->server_list);

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

  DLINK_FOREACH(ptr, root_p->serv->server_list.head)
  {
    const struct Client *server_p = ptr->data;

    *pbuf = ' ';

    if (i < cnt)
      *(pbuf + 1) = '|';
    else
      *(pbuf + 1) = '`';

    *(pbuf + 2) = '-';
    *(pbuf + 3) = ' ';
    dump_map(client_p, server_p, start_len + 4, pbuf + 4);

    ++i;
  }
}

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
    aconf = (struct AccessItem *)map_to_conf(conf);

    if (aconf->status != CONF_SERVER)
      continue;

    if (strcmp(conf->name, me.name) == 0)
      continue;

    if (!hash_find_server(conf->name))
    {
      char buffer[IRCD_BUFSIZE];
      ircsprintf(buffer, "** %s (Not Connected)", conf->name);
      sendto_one(client_p, form_str(RPL_MAP), me.name, client_p->name, buffer);
    }
  }

  sendto_one(client_p, form_str(RPL_MAPEND), me.name, client_p->name);
}

static struct Message map_msgtab =
{
  "MAP", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_map, m_ignore }
};

static void
module_init()
{
  mod_add_cmd(&map_msgtab);
}

static void
module_exit()
{
  mod_del_cmd(&map_msgtab);
}

IRCD_EXPORT struct module module_entry =
{
  { NULL, NULL, NULL },
  NULL,
  "$Revision$",
  NULL,
  module_init,
  module_exit,
  0
};
