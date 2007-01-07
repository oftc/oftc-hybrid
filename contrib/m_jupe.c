/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_jupe.c: Jupes a server.
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
 *  $Id: m_jupe.c 605 2006-06-08 21:26:01Z stu $
 */

#include "stdinc.h"
#include "tools.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "handlers.h"
#include "channel.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "hash.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "common.h"
#include "event.h"
#include "fdlist.h"
#include "list.h"
#include "s_conf.h"

static void mo_jupe(struct Client *, struct Client *, int, char *[]);
static int bogus_host(char *);

struct Message jupe_msgtab = {
  "JUPE", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_jupe, m_ignore, mo_jupe, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&jupe_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&jupe_msgtab);
}

const char *_version = "$Revision: 605 $";
#endif

/*
 * mo_jupe()
 *      parv[0] = sender prefix
 *      parv[1] = server we're juping
 *      parv[2] = reason for jupe
 */
static void
mo_jupe(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Client *ajupe = NULL;
  dlink_node *m = NULL;
  char reason[REALLEN + 1];

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if (*parv[2] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "JUPE");
    return;
  }

  if (!ServerInfo.hub)
  {
    sendto_one(source_p, ":%s NOTICE %s :Must be used from a hub server",
               me.name, source_p->name);
    return;
  }

  if (bogus_host(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid servername: %s",
               me.name, source_p->name, parv[1]);
    return;
  }

  if (match(parv[1], me.name))
  {
    sendto_one(source_p, ":%s NOTICE %s :I can't jupe myself!",
               me.name, source_p->name);
    return;
  }

  /* we need to give 7 chars to prepend "JUPED: " */
  if (strlen(parv[2]) > (REALLEN - 7))
    parv[2][REALLEN - 7] = '\0';

  sendto_wallops_flags(UMODE_WALLOP, &me,
                       "JUPE for %s requested by %s: %s",
                       parv[1], get_oper_name(source_p), parv[2]);

  sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                ":%s WALLOPS :JUPE for %s requested by %s!%s@%s: %s",
                me.name, parv[1], source_p->name, 
                source_p->username, source_p->host, parv[2]);
  ilog(L_NOTICE, "JUPE for %s requested by %s: %s",
       parv[1], get_oper_name(source_p), parv[2]);

  if ((target_p = find_server(parv[1])) != NULL)
    exit_client(target_p, &me, parv[2]);

  sendto_server(NULL, NULL, NULL, NOCAPS, NOCAPS, NOFLAGS,
                ":%s SERVER %s 1 :JUPED: %s",
                me.name, parv[1], parv[2]);

  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "Link with %s established: (JUPED) link",
                       parv[1]);

  ajupe = make_client(NULL);

  /* make_client() adds client to unknown_list */
  if ((m = dlinkFindDelete(&unknown_list, ajupe)) != NULL)
    free_dlink_node(m);

  make_server(ajupe);

  strlcpy(ajupe->name, parv[1], sizeof(ajupe->name));
  ircsprintf(reason, "JUPED: %s", parv[2]);
  strlcpy(ajupe->info, reason, sizeof(ajupe->info));

  ajupe->servptr  = &me;
  ajupe->hopcount = 1;

  SetServer(ajupe);
  SetDead(ajupe);

  Count.myserver++;

  hash_add_client(ajupe);
  dlinkAdd(ajupe, &ajupe->lnode, &ajupe->servptr->serv->servers);
  dlinkAdd(ajupe, make_dlink_node(), &global_serv_list);

  /* XXX is this really necessary? 
   * for now, 'cause of the way squit works
   */
  dlinkAdd(ajupe, &ajupe->node, &global_client_list);
}

/* bogus_host()
 *
 * inputs       - hostname
 * output       - 1 if a bogus hostname input,
 *              - 0 if its valid
 * side effects - none
 */
static int
bogus_host(char *host)
{
  unsigned int length = 0;
  unsigned int dots   = 0;
  char *s = host;

  for (; *s; s++)
  {
    if (!IsServChar(*s))  
      return 1;

    ++length;

    if ('.' == *s)
      ++dots;
  }

  return !dots || length > HOSTLEN;
}
