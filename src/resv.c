/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  resv.c: Functions to reserve(jupe) a nick/channel.
 *
 *  Copyright (C) 2001-2002 Hybrid Development Team
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
#include "common.h"
#include "ircd.h"
#include "send.h"
#include "client.h"   
#include "numeric.h"
#include "resv.h"
#include "hash.h"
#include "ircd_defs.h"
#include "s_conf.h"

dlink_list resv_channel_list = { NULL, NULL, 0 };


/* create_channel_resv()
 *
 * inputs	- name of channel to create resv for
 *		- reason for resv
 *		- flag, 1 for from ircd.conf 0 from elsehwere
 * output	- pointer to struct ResvChannel
 * side effects	-
 */
struct ConfItem *
create_channel_resv(char *name, char *reason, int in_conf)
{
  struct ConfItem *conf;
  struct ResvChannel *resv_p;

  if (name == NULL || reason == NULL)
    return(NULL);

  if (find_channel_resv(name))
    return(NULL);

  if (strlen(reason) > TOPICLEN)
    reason[TOPICLEN] = '\0';

  conf = make_conf_item(CRESV_TYPE);
  resv_p = (struct ResvChannel *)map_to_conf(conf);

  strlcpy(resv_p->name, name, sizeof(resv_p->name));
  DupString(resv_p->reason, reason);
  resv_p->conf = in_conf;

  dlinkAdd(resv_p, &resv_p->node, &resv_channel_list);
  hash_add_resv(resv_p);

  return(conf);
}

/* create_nick_resv()
 *
 * inputs	- name of nick to create resv for
 *		- reason for resv
 *		- 1 if from ircd.conf, 0 if from elsewhere
 * output	- pointer to struct ResvNick
 * side effects	-
 */
struct ConfItem *
create_nick_resv(char *name, char *reason, int in_conf)
{
  struct ConfItem *conf;
  struct MatchItem *resv_p;

  if (name == NULL || reason == NULL)
    return(NULL);

  if (find_matching_name_conf(NRESV_TYPE, name,
			      NULL, NULL, 0))
    return(NULL);

  if (strlen(reason) > TOPICLEN)
    reason[TOPICLEN] = '\0';

  conf = make_conf_item(NRESV_TYPE);
  resv_p = (struct MatchItem *)map_to_conf(conf);

  DupString(conf->name, name);
  DupString(resv_p->reason, reason);
  resv_p->action = in_conf;

  return(conf);
}

/* clear_conf_resv()
 *
 * inputs	- none
 * output	- none
 * side effects	- All resvs are cleared out
 */
void
clear_conf_resv(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ResvChannel *resv_cp;

  DLINK_FOREACH_SAFE(ptr, next_ptr, resv_channel_list.head)
  {
    resv_cp = ptr->data;
    delete_channel_resv(resv_cp);
  }
}

/* delete_channel_resv()
 *
 * inputs	- pointer to channel resv to delete
 * output	- none
 * side effects	- given struct ResvChannel * is removed
 */
int
delete_channel_resv(struct ResvChannel *resv_p)
{
  struct ConfItem *conf;
  assert(resv_p != NULL);

  if (resv_p == NULL)
    return(0);

  hash_del_resv(resv_p);
  dlinkDelete(&resv_p->node, &resv_channel_list);
  MyFree(resv_p->reason);
  conf = unmap_conf_item(resv_p);
  delete_conf_item(conf);

  return(1);
}

int
find_channel_resv(const char *name)
{
  struct ResvChannel *resv_p;

  if ((resv_p = hash_find_resv(name)) != NULL)
    return(1);

  return(0);
}

#if 0
struct ResvNick *
return_nick_resv(const char *name)
{
  dlink_node *ptr;
  struct ResvNick *resv_p;

  DLINK_FOREACH(ptr, resv_nick_list.head)
  {
    resv_p = ptr->data;

    if (0 == irccmp(resv_p->name, name))
      return(resv_p);
  }

  return(NULL);
}
#endif

void
report_resv(struct Client *source_p)
{
  dlink_node *ptr;
  struct ConfItem *conf;
  struct ResvChannel *resv_cp;
  struct MatchItem *resv_np;

  DLINK_FOREACH(ptr, resv_channel_list.head)
  {
    resv_cp = ptr->data;
    sendto_one(source_p, form_str(RPL_STATSQLINE),
               me.name, source_p->name,
	       resv_cp->conf ? 'Q' : 'q',
	       resv_cp->name, resv_cp->reason);
  }

  DLINK_FOREACH(ptr, nresv_items.head)
  {
    conf = ptr->data;
    resv_np = (struct MatchItem *)map_to_conf(conf);

    sendto_one(source_p, form_str(RPL_STATSQLINE),
               me.name, source_p->name,
	       resv_np->action ? 'Q' : 'q',
	       conf->name, resv_np->reason);
  }
}

int
clean_resv_nick(char *nick)
{
  char tmpch;
  int as = 0;
  int q  = 0;
  int ch = 0;

  if (*nick == '-' || IsDigit(*nick))
    return(0);

  while ((tmpch = *nick++))
  {
    if (tmpch == '?')
      q++;
    else if (tmpch == '*')
      as++;
    else if (IsNickChar(tmpch))
      ch++;
    else
      return(0);
  }

  if (!ch && as)
    return(0);

  return(1);
}

/* valid_wild_card_simple()
 *
 * inputs	- data to check for sufficient non-wildcard characters
 * outputs	- 1 if valid, else 0
 * side effects	- none
 */
int
valid_wild_card_simple(char *data)
{
  char *p = data, tmpch;
  int nonwild = 0;

  while ((tmpch = *p++))
  {
    if (!IsMWildChar(tmpch))
    {
      if (++nonwild >= ConfigFileEntry.min_nonwildcard_simple)
        break;
    }
  }

  if (nonwild < ConfigFileEntry.min_nonwildcard_simple)
    return 0;
  else
    return 1;
}
