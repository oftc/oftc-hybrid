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
#include "s_serv.h"
#include "ircd.h"
#include "sprintf_irc.h"

extern struct Client me;
extern struct Counter Count;

static void ms_map(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[]);
static void mo_map(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[]);

static void dump_map(struct Client *client_p,struct Client *root, char *pbuf);

struct Message map_msgtab = {
  "MAP", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_map, mo_map}
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

static char buf[BUFSIZE];

/*
** mo_map
**      parv[0] = sender prefix
*/
static void mo_map(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  struct ConfItem *conf;
  struct AccessItem *aconf;
  dlink_node *ptr;
  
  dump_map(client_p, &me, buf);
  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;
    aconf = (struct AccessItem *)map_to_conf(conf);
    if (aconf->status != CONF_SERVER)
      continue;
    if (strcmp(conf->name, me.name) == 0)
      continue;
    if (!find_server(conf->name))
    {
      char buffer[BUFSIZE];
      ircsprintf(buffer, "** %s (Not Connected)", conf->name);
      sendto_one(client_p, form_str(RPL_MAP), me.name, client_p->name, buffer);
    }
  }
  sendto_one(client_p, form_str(RPL_MAPEND), me.name, client_p->name);
}


static void ms_map(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  struct ConfItem *conf;
  struct AccessItem *aconf;
  dlink_node *ptr;

  if (parc > 1)
    if (hunt_server(client_p, source_p, ":%s MAP %s", 1, parc, parv) 
            != HUNTED_ISME)
      return;
  dump_map(source_p,&me,buf);
  
  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;
    aconf = (struct AccessItem *)map_to_conf(conf);

    if (aconf->status != CONF_SERVER)
      continue;
    if (strcmp(conf->name, me.name) == 0)
      continue;
    if (!find_server(conf->name))
    {
      char buffer[BUFSIZE];
      ircsprintf(buffer, "** %s (Not Connected)", conf->name);
      sendto_one(source_p, form_str(RPL_MAP), me.name, source_p->name, buffer);
    }
  }
  sendto_one(source_p, form_str(RPL_MAPEND), me.name, source_p->name);
}

/*
** dump_map
**    dumps server map, called recursively.
*/
static void dump_map(struct Client *client_p,struct Client *root_p, char *pbuf)
{
  int cnt = 0, i = 0, len;
  int users = 0;
  struct Client *server_p;
  dlink_node *ptr;
        
  *pbuf= '\0';
       
  strncat(pbuf,root_p->name,BUFSIZE - ((size_t) pbuf - (size_t) buf));
  len = strlen(buf);
  buf[len] = ' ';
	
  DLINK_FOREACH(ptr, root_p->serv->users.head)
    users++;
        
  snprintf(buf+len, BUFSIZE," (Users: %d [%.1f%%]; Ping: %lums)", users,
           100 * (float) users / (float) Count.total,
           (root_p->ping_time.tv_usec / 1000));
        
  sendto_one(client_p, form_str(RPL_MAP),me.name,client_p->name,buf);
        
  DLINK_FOREACH(ptr, root_p->serv->servers.head)
    cnt++;
    
  if (cnt)
  {
    if (pbuf > buf + 3)
    {
      pbuf[-2] = ' ';
      if (pbuf[-3] == '`')
        pbuf[-3] = ' ';
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
    dump_map(client_p, server_p, pbuf + 4);
 
    i++;
   }
}

