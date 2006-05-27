/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_xline.c: xlines an user.
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
#include "s_log.h"
#include "s_misc.h"
#include "send.h"
#include "hash.h"
#include "handlers.h"
#include "s_serv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "cluster.h"
#include "resv.h"

static void mo_xline(struct Client *, struct Client *, int, char **);
static void ms_xline(struct Client *, struct Client *, int, char **);

static void mo_unxline(struct Client *, struct Client *, int, char **);
static void ms_unxline(struct Client *, struct Client *, int, char **);

static int valid_xline(struct Client *, char *, char *, int);
static void write_xline(struct Client *, char *, char *, int);
static void remove_xline(struct Client *, char *, int);

struct Message xline_msgtab = {
  "XLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_xline, mo_xline, m_ignore}
};

struct Message unxline_msgtab = {
  "UNXLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_unxline, mo_unxline, m_ignore}
};


#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&xline_msgtab);
  mod_add_cmd(&unxline_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&xline_msgtab);
  mod_del_cmd(&unxline_msgtab);
}

const char *_version = "$Revision: 259 $";
#endif


/* mo_xline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - x line is added
 *
 */
static void
mo_xline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct ConfItem *conf;
  struct MatchItem *match_item;
  char *reason, *pattern, *target_server;
  const char *type;
  int type_i = 1;
  char def_reason[] = "No Reason";

  type = reason = pattern = target_server = NULL;

  if (!IsOperX(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if (parc < 3)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "XLINE");
    return;
  }

  if ((conf = find_matching_name_conf(XLINE_TYPE, parv[1],
				      NULL, NULL, 0)) != NULL)
  {
    match_item = (struct MatchItem *)map_to_conf(conf);

    sendto_one(source_p, ":%s NOTICE %s :[%s] already X-Lined by [%s] - %s",
               me.name, source_p->name, parv[1],
	       conf->name, match_item->reason);
    return;
  }

  /* XLINE <gecos> <type> ON <server> :reason */
  if (parc > 5)
  {
    if (irccmp(parv[3], "ON") == 0)
    {
      target_server = parv[4];
      reason = parv[5];
      type = parv[2];
    }
    else
    {
      /* perhaps we should show usage here?  also,
       * this may be a bit nitpicky, but we are being
       * painfully inconsistent by sending 'XLINE'
       * rather than duplicating the case with which
       * the command was issued.
       */
      sendto_one(source_p, form_str(ERR_NORECIPIENT),
                 me.name, source_p->name, "XLINE");
      return;
    }
  }
  /* XLINE <gecos> <type> ON <server> */
  else if (parc == 5)
  {
    if (irccmp(parv[3], "ON") == 0)
    {
      target_server = parv[4];
      type = parv[2];
    }
    else
    {
      sendto_one(source_p, form_str(ERR_NORECIPIENT),
                 me.name, source_p->name, "XLINE");
      return;
    }
  }
  /* XLINE <gecos> <type> :<reason> */
  else if (parc == 4)
  {
    reason = parv[3];
    type = parv[2];
  }
  /* XLINE <gecos> :<reason> */
  else if (parc == 3)
  {
    reason = parv[2];
    type = "REJECT";
  }

  if (irccmp(type,"WARN") == 0)
    type_i = 0;
  else if (irccmp(type,"REJECT") == 0)
    type_i = 1;
  else if (irccmp(type,"SILENT") == 0)
    type_i = 2;
  else
    type_i = atoi(type);

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_CLUSTER,
                       "XLINE %s %s %d :%s",
                       target_server, parv[1], type_i, reason);
    if (!match(target_server, me.name))
      return;
  }
  else if (dlink_list_length(&cluster_items))
    cluster_xline(source_p, parv[1], type_i, reason);

  if (EmptyString(reason))
    reason = def_reason;

  write_xline(source_p, parv[1], reason, type_i);
} /* mo_xline() */

/* ms_xline()
 *
 * inputs	- oper, target server, xline, type, reason
 * outputs	- none
 * side effects	- propogates xline, applies it if we are a target
 */
static void
ms_xline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct ConfItem *conf;
  struct MatchItem *match_item;

  if (parc != 5 || EmptyString(parv[4]))
    return;

  if (!IsPerson(source_p))
    return;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "XLINE %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4]);

  if (!match(parv[1], me.name))
    return;

  if (find_matching_name_conf(CLUSTER_TYPE, source_p->user->server->name,
                              NULL, NULL, CLUSTER_XLINE))
  {
    if (!valid_xline(source_p, parv[2], parv[4], 0))
      return;

    if ((find_matching_name_conf(XLINE_TYPE, parv[1],
				NULL, NULL, 0)) != NULL)
      return;

    write_xline(source_p, parv[2], parv[4], atoi(parv[3]));
  }
  else if (find_matching_name_conf(ULINE_TYPE,
		       source_p->user->server->name,
                       source_p->username, source_p->host,
                       SHARED_XLINE))
  {
    if (!valid_xline(source_p, parv[2], parv[4], 1))
      return;

    if ((conf = find_matching_name_conf(XLINE_TYPE, parv[2],
					NULL, NULL, 0)) != NULL)
    {
      match_item = (struct MatchItem *)map_to_conf(conf);
      sendto_one(source_p, ":%s NOTICE %s :[%s] already X-Lined by [%s] - %s",
                 me.name, source_p->name, parv[1],
                 conf->name, match_item->reason);
      return;
    }

    write_xline(source_p, parv[2], parv[4], atoi(parv[3]));
  }
}

/* mo_unxline()
 *
 * inputs	- pointer to server
 *		- pointer to client
 *		- parameter count
 *		- parameter list
 * output	-
 * side effects - removes a xline
 */
static void
mo_unxline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (!IsOperX(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if (parc < 1)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "UNXLINE");
    return;
  }

  /* UNXLINE bill ON irc.server.com */
  if ((parc > 3) && (irccmp(parv[2], "ON") == 0))
  {
    sendto_match_servs(source_p, parv[3], CAP_CLUSTER,
                       "UNXLINE %s %s",
                       parv[3], parv[1]);

    if (match(parv[3], me.name) == 0)
      return;
  }
  /* UNXLINE bill */
  else if (parc >= 2)
  {
    if (dlink_list_length(&cluster_items))
      cluster_unxline(source_p, parv[1]);
    remove_xline(source_p, parv[1], 0);
  }
} /* mo_unxline() */

/* ms_unxline()
 *
 * inputs	- oper, target server, gecos
 * outputs	- none
 * side effects	- propogates unxline, applies it if we are a target
 */
static void
ms_unxline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (parc != 3)
    return;

  if (EmptyString(parv[2]))
    return;

  sendto_match_servs(source_p, parv[1], CAP_CLUSTER,
                     "UNXLINE %s %s",
                     parv[1], parv[2]);

  if (!match(parv[1], me.name))
    return;

  if (!IsPerson(source_p))
    return;

  if (find_matching_name_conf(CLUSTER_TYPE, source_p->user->server->name,
                              NULL, NULL, CLUSTER_UNXLINE))
    remove_xline(source_p, parv[2], 1);
  else if (find_matching_name_conf(ULINE_TYPE,
		       source_p->user->server->name,
                       source_p->username, source_p->host,
                       SHARED_UNXLINE))
  {
    if (remove_conf_line(XLINE_TYPE, source_p, parv[2], NULL) > 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :X-Line for [%s] is removed",
                 me.name, parv[0], parv[2]);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has removed the X-Line for: [%s]",
                           get_oper_name(source_p), parv[2]);
      ilog(L_NOTICE, "%s removed X-Line for [%s]", get_oper_name(source_p),
           parv[2]);
    }
    else
      sendto_one(source_p, ":%s NOTICE %s :No X-Line for %s",
                 me.name, source_p->name, parv[2]);
  }
}

/* valid_xline()
 *
 * inputs	- client to complain to, gecos, reason, whether to complain
 * outputs	- 1 for valid, else 0
 * side effects	- complains to client, when warn != 0
 */
static int
valid_xline(struct Client *source_p, char *gecos, char *reason, int warn)
{
  if (EmptyString(reason))
  {
    if (warn)
      sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
                 me.name, source_p->name, "XLINE");
    return(0);
  }

  if (strchr(reason, ':') != NULL)
  {
    if (warn)
      sendto_one(source_p, ":%s NOTICE %s :Invalid character ':' in comment",
                 me.name, source_p->name);
    return(0);
  }

  if (!valid_wild_card_simple(gecos))
  {
    if (warn)
      sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the xline",
                 me.name, source_p->name, ConfigFileEntry.min_nonwildcard_simple);

    return(0);
  }

  return(1);
}

/* write_xline()
 *
 * inputs	- client taking credit for xline, gecos, reason, xline type
 * outputs	- none
 * side effects	- when succesful, adds an xline to the conf
 */
static void
write_xline(struct Client *source_p, char *gecos, char *reason, int type)
{
  struct ConfItem *conf;
  struct MatchItem *match_item;
  const char *current_date;
  time_t cur_time;

  conf = make_conf_item(XLINE_TYPE);
  match_item = (struct MatchItem *)map_to_conf(conf);
  match_item->action = type;

  collapse(gecos);
  DupString(conf->name, gecos);
  DupString(match_item->reason, reason);
  DupString(match_item->oper_reason, "");	/* XXX */
  set_time();
  cur_time = CurrentTime;
  current_date = smalldate(cur_time);
  write_conf_line(source_p, conf, current_date, cur_time);
  rehashed_xlines = 1;
}

static void
remove_xline(struct Client *source_p, char *gecos, int cluster)
{
  if (remove_conf_line(XLINE_TYPE, source_p, gecos, NULL) > 0)
  {
    if (!cluster)
      sendto_one(source_p, ":%s NOTICE %s :X-Line for [%s] is removed",
                 me.name, source_p->name, gecos);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the X-Line for: [%s]",
                         get_oper_name(source_p), gecos);
    ilog(L_NOTICE, "%s removed X-Line for [%s]",
         get_oper_name(source_p), gecos);
  }
  else if (!cluster)
    sendto_one(source_p, ":%s NOTICE %s :No X-Line for %s",
               me.name, source_p->name, gecos);
}
