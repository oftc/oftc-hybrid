/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  cluster.c: Code for handling kline/dline/xline/resv clusters
 *
 *  Copyright (C) 2003 Hybrid Development Team
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

#include "cluster.h"
#include "tools.h"
#include "s_conf.h"
#include "s_serv.h"
#include "memory.h"
#include "irc_string.h"
#include "send.h"
#include "list.h"


void
cluster_kline(struct Client *source_p, int tkline_time, const char *user,
              const char *host, const char *reason)
{
  struct ConfItem *conf;
  struct MatchItem *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;
    cptr = (struct MatchItem *)map_to_conf(conf);

    if (IsClusterKline(cptr))
      sendto_match_servs(source_p, conf->name, CAP_KLN,
                         "KLINE %s %d %s %s :%s",
                         conf->name, tkline_time, user, host, reason);
  }
}

void
cluster_unkline(struct Client *source_p, const char *user, const char *host)
{
  struct ConfItem *conf;
  struct MatchItem *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;
    cptr = (struct MatchItem *)map_to_conf(conf);

    if (IsClusterUnkline(cptr))
      sendto_match_servs(source_p, conf->name, CAP_UNKLN,
                         "UNKLINE %s %s %s",
                         conf->name, user, host);
  }
}

void
cluster_xline(struct Client *source_p, const char *gecos,
              int xtype, const char *reason)
{
  struct ConfItem *conf;
  struct MatchItem *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;
    cptr = (struct MatchItem *)map_to_conf(conf);

    if (IsClusterXline(cptr))
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER,
                         "XLINE %s %s %d :%s",
                         conf->name, gecos, xtype, reason);
  }
}

void
cluster_unxline(struct Client *source_p, const char *gecos)
{
  struct ConfItem *conf;
  struct MatchItem *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;
    cptr = (struct MatchItem *)map_to_conf(conf);

    if (IsClusterUnxline(cptr))
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER,
                         "UNXLINE %s %s",
                         conf->name, gecos);
  }
}

void
cluster_resv(struct Client *source_p, const char *name, const char *reason)
{
  struct ConfItem *conf;
  struct MatchItem *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;
    cptr = (struct MatchItem *)map_to_conf(conf);

    if (IsClusterResv(cptr))
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER,
                         "RESV %s %s :%s",
                         conf->name, name, reason);
  }
}

void
cluster_unresv(struct Client *source_p, const char *name)
{
  struct ConfItem *conf;
  struct MatchItem *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;
    cptr = (struct MatchItem *)map_to_conf(conf);

    if (IsClusterUnresv(cptr))
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER,
                         "UNRESV %s %s", conf->name, name);
  }
}

void
cluster_locops(struct Client *source_p, const char *message)
{
  struct ConfItem *conf;
  struct MatchItem *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    conf = ptr->data;
    cptr = (struct MatchItem *)map_to_conf(conf);

    if (IsClusterLocops(cptr))
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER,
                         "LOCOPS %s :%s", conf->name, message);
  }
}
