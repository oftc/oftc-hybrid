/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_gline.c: GLine global ban functions.
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
#include "channel.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_misc.h"
#include "send.h"
#include "msg.h"
#include "fileio.h"
#include "s_serv.h"
#include "s_gline.h"
#include "hash.h"
#include "event.h"
#include "list.h"
#include "memory.h"

dlink_list pending_glines = { NULL, NULL, 0 };

static void expire_glines(void);
static void expire_pending_glines(void);


/* find_gkill()
 *
 * inputs       - pointer to a Client struct
 * output       - struct AccessItem pointer if a gline was found for this client
 * side effects - NONE
 */
struct AccessItem *
find_gkill(struct Client *client_p, const char *username)
{
  assert(client_p != NULL);

  if (client_p == NULL)
    return(NULL);
  return((IsExemptKline(client_p)) ? NULL : find_is_glined(client_p->host, username));
}

/* XXX need CIDR support */

/* find_is_glined()
 *
 * inputs       - hostname
 *              - username
 * output       - pointer to struct AccessItem if user@host glined
 * side effects -
 */
struct AccessItem *
find_is_glined(const char *host, const char *user)
{
  dlink_node *ptr;
  struct AccessItem *kill_ptr; 

  DLINK_FOREACH(ptr, gline_items.head)
  {
    kill_ptr = map_to_conf(ptr->data);

    if ((kill_ptr->user && (!user || match(kill_ptr->user, user))) &&
        (kill_ptr->host && (!host || match(kill_ptr->host, host))))
    {
      return(kill_ptr);
    }
  }

  return(NULL);
}

/* remove_gline_match()
 *
 * inputs       - user@host
 * output       - 1 if successfully removed, otherwise 0
 * side effects -
 */
int
remove_gline_match(const char *user, const char *host)
{
  dlink_node *ptr;
  struct ConfItem *conf;
  struct AccessItem *kill_ptr;

  DLINK_FOREACH(ptr, gline_items.head)
  {
    conf = ptr->data;
    kill_ptr = (struct AccessItem *)map_to_conf(conf);

    if (irccmp(kill_ptr->host, host) == 0 &&
        irccmp(kill_ptr->user, user) == 0)
    {
      delete_conf_item(conf);
      return(1);
    }
  }

  return(0);
}

/* cleanup_glines()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects - expire gline lists
 *                This is an event started off in ircd.c
 */
void
cleanup_glines(void *unused)
{
  expire_glines();
  expire_pending_glines();
}

/* expire_glines()
 * 
 * inputs       - NONE
 * output       - NONE
 * side effects -
 *
 * Go through the gline list, expire any needed.
 */
static void
expire_glines(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct AccessItem *kill_ptr;

  DLINK_FOREACH_SAFE(ptr, next_ptr, gline_items.head)
  {
    conf = ptr->data;
    kill_ptr = (struct AccessItem *)map_to_conf(conf);

    if (kill_ptr->hold <= CurrentTime)
    {
      delete_conf_item(conf);
    }
  }
}

/* expire_pending_glines()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects -
 *
 * Go through the pending gline list, expire any that haven't had
 * enough "votes" in the time period allowed
 */
static void
expire_pending_glines(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct gline_pending *glp_ptr;

  DLINK_FOREACH_SAFE(ptr, next_ptr, pending_glines.head)
  {
    glp_ptr = ptr->data;

    if (((glp_ptr->last_gline_time + GLINE_PENDING_EXPIRE) <= CurrentTime) ||
        find_is_glined(glp_ptr->host, glp_ptr->user))
    {
      dlinkDelete(&glp_ptr->node, &pending_glines);
      MyFree(glp_ptr);
    }
  }
}
