/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_kline.c: Bans a user.
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
#include "list.h"
#include "channel.h"
#include "client.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "conf.h"
#include "log.h"
#include "s_misc.h"
#include "send.h"
#include "hash.h"
#include "s_serv.h"
#include "parse.h"
#include "modules.h"


static int already_placed_kline(struct Client *, const char *, const char *,
                                int);

static char buffer[IRCD_BUFSIZE];
static bool remove_tkline_match(const char *, const char *);


/* mo_kline()
 *
 * inputs  - pointer to server
 *    - pointer to client
 *    - parameter count
 *    - parameter list
 * output  -
 * side effects - k line is added
 */
static void
mo_kline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *reason = NULL;
  char *oper_reason;
  char *user = NULL;
  char *host = NULL;
  char *p;
  char *target_server = NULL;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  time_t tkline_time = 0;

  if (!HasOFlag(source_p, OPER_FLAG_K))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "kline");
    return;
  }

  if (parse_aline("KLINE", source_p, parc, parv,
                  AWILD, &user, &host, &tkline_time, &target_server, &reason) < 0)
    return;

  if ((p = strchr(host, '/')) != NULL)
  {
    int bitlen = strtol(++p, NULL, 10);
    int min_bitlen = strchr(host, ':') ? ConfigFileEntry.kline_min_cidr6 :
                     ConfigFileEntry.kline_min_cidr;

    if (bitlen < min_bitlen)
    {
      sendto_one(source_p, ":%s NOTICE %s :Cannot set K-Lines with CIDR length "
                 "< %d", me.name, source_p->name, min_bitlen);
      return;
    }
  }

  if (target_server != NULL)
  {
    if (HasID(source_p))
    {
      sendto_server(NULL, CAP_KLN | CAP_TS6, NOCAPS,
                    ":%s KLINE %s %lu %s %s :%s",
                    source_p->id, target_server, (unsigned long)tkline_time,
                    user, host, reason);
      sendto_server(NULL, CAP_KLN, CAP_TS6,
                    ":%s KLINE %s %lu %s %s :%s",
                    source_p->name, target_server, (unsigned long)tkline_time,
                    user, host, reason);
    }
    else
      sendto_server(NULL, CAP_KLN, NOCAPS,
                    ":%s KLINE %s %lu %s %s :%s",
                    source_p->name, target_server, (unsigned long)tkline_time,
                    user, host, reason);

    /* Allow ON to apply local kline as well if it matches */
    if (!match(target_server, me.name))
      return;
  }
  else
    cluster_a_line(source_p, "KLINE", CAP_KLN, SHARED_KLINE,
                   "%d %s %s :%s", tkline_time, user, host, reason);

  if (already_placed_kline(source_p, user, host, 1))
    return;

  /* Look for an oper reason */
  if ((oper_reason = strchr(reason, '|')) != NULL)
    * oper_reason++ = '\0';

  conf = make_conf_item(KLINE_TYPE);
  aconf = map_to_conf(conf);

  DupString(aconf->host, host);
  DupString(aconf->user, user);
  ircsprintf(buffer, "%s (%s)", reason, smalldate(CurrentTime));
  DupString(aconf->reason, buffer);

  if (oper_reason != NULL)
    DupString(aconf->oper_reason, oper_reason);

  apply_conf_ban(source_p, KLINE_TYPE, user, host, reason, oper_reason,
                 tkline_time);
}

/* me_kline - handle remote kline. no propagation */
static void
me_kline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  int tkline_time;
  char *kuser, *khost, *kreason, *oper_reason;

  if (parc != 6 || EmptyString(parv[5]))
    return;

  if (!match(parv[1], me.name))
    return;

  tkline_time = valid_tkline(parv[2], TK_SECONDS);
  kuser = parv[3];
  khost = parv[4];
  kreason = parv[5];

  if ((oper_reason = strchr(kreason, '|')) != NULL)
    * oper_reason++ = '\0';

  if (HasFlag(source_p, FLAGS_SERVICE)
      || find_matching_name_conf(ULINE_TYPE, source_p->servptr->name,
                                 source_p->username, source_p->host,
                                 SHARED_KLINE))
  {
    if (!IsClient(source_p) ||
        already_placed_kline(source_p, kuser, khost, 1))
      return;

    apply_conf_ban(source_p, KLINE_TYPE, kuser, khost, kreason, oper_reason,
                   tkline_time);
  }
}

static void
ms_kline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (parc != 6 || EmptyString(parv[5]))
    return;

  /* parv[0]  parv[1]        parv[2]      parv[3]  parv[4]  parv[5] */
  /* oper     target_server  tkline_time  user     host     reason */
  sendto_match_servs(source_p, parv[1], CAP_KLN,
                     "KLINE %s %s %s %s :%s",
                     parv[1], parv[2], parv[3], parv[4], parv[5]);

  me_kline(client_p, source_p, parc, parv);
}

/* already_placed_kline()
 * inputs  - user to complain to, username & host to check for
 * outputs  - returns 1 on existing K-line, 0 if doesn't exist
 * side effects  - notifies source_p if the K-line already exists
 */
/*
 * Note: This currently works if the new K-line is a special case of an
 *       existing K-line, but not the other way round. To do that we would
 *       have to walk the hash and check every existing K-line. -A1kmm.
 */
static int
already_placed_kline(struct Client *source_p, const char *luser,
                     const char *lhost, int warn)
{
  const char *reason;
  struct irc_ssaddr iphost, *piphost;
  struct AccessItem *aconf;
  int t;

  if ((t = parse_netmask(lhost, &iphost, &t)) != HM_HOST)
  {
    if (t == HM_IPV6)
      t = AF_INET6;
    else
      t = AF_INET;

    piphost = &iphost;
  }
  else
  {
    t = 0;
    piphost = NULL;
  }

  if ((aconf = find_conf_by_address(lhost, piphost, CONF_KLINE, t, luser, NULL, 0,
                                    NULL)))
  {
    if (warn)
    {
      reason = aconf->reason ? aconf->reason : CONF_NOREASON;
      sendto_one(source_p,
                 ":%s NOTICE %s :[%s@%s] already K-Lined by [%s@%s] - %s",
                 me.name, source_p->name, luser, lhost, aconf->user,
                 aconf->host, reason);
    }

    return 1;
  }

  return 0;
}

/*
** mo_unkline
** Added Aug 31, 1997
** common (Keith Fralick) fralick@gate.net
**
**      parv[0] = sender
**      parv[1] = address to remove
*
*
*/
static void
mo_unkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char *target_server = NULL;
  char *user, *host;

  if (!HasOFlag(source_p, OPER_FLAG_UNKLINE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "unkline");
    return;
  }

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "UNKLINE");
    return;
  }

  if (parse_aline("UNKLINE", source_p, parc, parv, 0, &user,
                  &host, NULL, &target_server, NULL) < 0)
    return;

  if (target_server != NULL)
  {
    sendto_match_servs(source_p, target_server, CAP_UNKLN,
                       "UNKLINE %s %s %s",
                       target_server, user, host);

    /* Allow ON to apply local unkline as well if it matches */
    if (!match(target_server, me.name))
      return;
  }
  else
    cluster_a_line(source_p, "UNKLINE", CAP_UNKLN, SHARED_UNKLINE,
                   "%s %s", user, host);

  if (remove_tkline_match(host, user))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Un-klined [%s@%s] from temporary K-Lines",
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the temporary K-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(LOG_TYPE_KLINE, "%s removed temporary K-Line for [%s@%s]",
         source_p->name, user, host);
    remove_conf_line(KLINE_TYPE, source_p, user, host);
    return;
  }

  if (remove_conf_line(KLINE_TYPE, source_p, user, host) > 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :K-Line for [%s@%s] is removed",
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the K-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(LOG_TYPE_KLINE, "%s removed K-Line for [%s@%s]",
         source_p->name, user, host);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :No K-Line for [%s@%s] found",
               me.name, source_p->name, user, host);
}

/* me_unkline()
 *
 * inputs  - server
 *    - client
 *    - parc
 *    - parv
 * outputs  - none
 * side effects  - if server is authorized, kline is removed
 *                does not propagate message
 */
static void
me_unkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char *kuser, *khost;

  if (parc != 4)
    return;

  kuser = parv[2];
  khost = parv[3];

  if (!IsClient(source_p) || !match(parv[1], me.name))
    return;

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(ULINE_TYPE,
      source_p->servptr->name,
      source_p->username, source_p->host,
      SHARED_UNKLINE))
  {
    if (remove_tkline_match(khost, kuser))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Un-klined [%s@%s] from temporary K-Lines",
                 me.name, source_p->name, kuser, khost);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has removed the temporary K-Line for: [%s@%s]",
                           get_oper_name(source_p), kuser, khost);
      ilog(LOG_TYPE_KLINE, "%s removed temporary K-Line for [%s@%s]",
           source_p->name, kuser, khost);
      remove_conf_line(KLINE_TYPE, source_p, kuser, khost);
      return;
    }

    if (remove_conf_line(KLINE_TYPE, source_p, kuser, khost) > 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :K-Line for [%s@%s] is removed",
                 me.name, source_p->name, kuser, khost);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "%s has removed the K-Line for: [%s@%s]",
                           get_oper_name(source_p), kuser, khost);

      ilog(LOG_TYPE_KLINE, "%s removed K-Line for [%s@%s]",
           source_p->name, kuser, khost);
    }
    else
      sendto_one(source_p, ":%s NOTICE %s :No K-Line for [%s@%s] found",
                 me.name, source_p->name, kuser, khost);
  }
}

/* ms_unkline - propagates and handles a remote unkline message */
static void
ms_unkline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (parc != 4)
    return;

  sendto_match_servs(source_p, parv[1], CAP_UNKLN,
                     "UNKLINE %s %s %s",
                     parv[1], parv[2], parv[3]);

  me_unkline(client_p, source_p, parc, parv);
}

/* static int remove_tkline_match(const char *host, const char *user)
 * Input: A hostname, a username to unkline.
 * Output: returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static bool
remove_tkline_match(const char *host, const char *user)
{
  struct irc_ssaddr iphost, *piphost;
  struct AccessItem *aconf;
  int t;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
    if (t == HM_IPV6)
      t = AF_INET6;
    else
      t = AF_INET;

    piphost = &iphost;
  }
  else
  {
    t = 0;
    piphost = NULL;
  }

  if ((aconf = find_conf_by_address(host, piphost, CONF_KLINE, t, user, NULL, 0,
                                    NULL)))
  {
    if (IsConfTemporary(aconf))
    {
      delete_one_address_conf(host, aconf);
      return true;
    }
  }

  return false;
}

static struct Message kline_msgtab =
{
  "KLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_kline, me_kline, mo_kline, m_ignore}
};

static struct Message unkline_msgtab =
{
  "UNKLINE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_unkline, me_unkline, mo_unkline, m_ignore}
};

static void
module_init()
{
  mod_add_cmd(&kline_msgtab);
  mod_add_cmd(&unkline_msgtab);
  add_capability("KLN", CAP_KLN, 1);
  add_capability("UNKLN", CAP_UNKLN, 1);
}

static void
module_exit()
{
  mod_del_cmd(&kline_msgtab);
  mod_del_cmd(&unkline_msgtab);
  delete_capability("UNKLN");
  delete_capability("KLN");
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
