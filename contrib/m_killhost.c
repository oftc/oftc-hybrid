/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_killhost.c: Kills a users with agree host.
 *
 *  Copyright (C) 2002 by Ilya Shtift.
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
 *
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_log.h"
#include "s_serv.h"
#include "s_conf.h"
#include "send.h"
#include "whowas.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static char bufhost[BUFSIZE];

static void mo_killhost(struct Client*, struct Client*, int, char**);
static void kh_relay_kill(struct Client *, struct Client *, struct Client *,
                const char *, const char *);

struct Message killhost_msgtab = {
  "KILLHOST", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, m_ignore, mo_killhost,  m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&killhost_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&killhost_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
** mo_killhost
** Created May 5, 2003
** common (Ilya Shtift) ishtift@tagil.svrw.ru
**
**      parv[0] = sender prefix
**      parv[1] = host
**      parv[2] = [reason]
*/
static void mo_killhost(struct Client *client_p,
                 struct Client *source_p,
                 int parc,
                 char *parv[])
{
  dlink_node *ptr;
  dlink_node *ptr_next;
  struct Client *target_p;
  const char* inpath = client_p->name;
  char *host, *reason;
  int count = 0;

  host = parv[1];
  reason = parv[2];

  if (!EmptyString(reason))
  {
    if (strlen(reason) > (size_t) KILLLEN)
      reason[KILLLEN] = '\0';
  }
  else
    reason = "<No reason given>";

  sendto_wallops_flags(UMODE_OPERWALL, source_p, "OPERWALL - KILLHOST %s %s", host, reason);

  DLINK_FOREACH_SAFE(ptr, ptr_next, global_client_list.head)
  {
    target_p = ptr->data;

    if (!IsPerson(target_p) || IsServer(target_p) || IsMe(target_p))
      continue;

    if (!MyConnect(target_p) && (!IsOperGlobalKill(source_p)))
      continue;
      
    if (!strcmp(host, target_p->host))
    {
      count++;
    
      if (MyConnect(target_p))
        sendto_one(target_p, ":%s!%s@%s KILL %s :%s",
                   source_p->name, source_p->username, source_p->host,
                   target_p->name, reason);

      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "Received KILL message for %s. From %s Path: %s (%s)",
                           target_p->name, parv[0], me.name, reason);

      ilog(L_INFO,"KILL From %s For %s Path %s (%s)",
           parv[0], target_p->name, me.name, reason);

      if (!MyConnect(target_p))
      {
        kh_relay_kill(client_p, source_p, target_p, inpath, reason);
	SetKilled(target_p);
      }

      ircsprintf(bufhost, "Killed (%s (%s))", source_p->name, reason);
      exit_client(client_p, target_p, source_p, bufhost);
    }
  }
  sendto_one(source_p,":%s NOTICE %s :%d clients killed",me.name, parv[0], count);
}

static void kh_relay_kill(struct Client *one, struct Client *source_p,
                       struct Client *target_p,
                       const char *inpath,
		       const char *reason)
{
  dlink_node *ptr;
  struct Client *client_p;
  int introduce_killed_client;
  char* user; 
  
  /* LazyLinks:
   * Check if each lazylink knows about target_p.
   *   If it does, send the kill, introducing source_p if required.
   *   If it doesn't either:
   *     a) don't send the kill (risk ghosts)
   *     b) introduce the client (and source_p, if required)
   *        [rather redundant]
   *
   * Use a) if IsServer(source_p), but if an oper kills someone,
   * ensure we blow away any ghosts.
   *
   * -davidt
   */

  if(IsServer(source_p))
    introduce_killed_client = 0;
  else
    introduce_killed_client = 1;

  DLINK_FOREACH(ptr, serv_list.head)
  {
    client_p = ptr->data;
    
    if(client_p == one)
      continue;

    if( !introduce_killed_client )
    {
      if( ServerInfo.hub && IsCapable(client_p, CAP_LL) )
      {
        if(((client_p->localClient->serverMask &
             target_p->lazyLinkClientExists) == 0))
        {
          /* target isn't known to lazy leaf, skip it */
          continue;
        }
      }
    }
    /* force introduction of killed client but check that
     * its not on the server we're bursting too.. */
    else if(strcmp(target_p->user->server->name,client_p->name))
      client_burst_if_needed(client_p, target_p);

    /* introduce source of kill */
    client_burst_if_needed(client_p, source_p);

    /* check the server supports SID */
    if (IsCapable(client_p, CAP_SID))
      user = ID(target_p);
    else
      user = target_p->name;

    if(MyClient(source_p))
      {
        sendto_one(client_p, ":%s KILL %s :%s!%s!%s!%s (%s)",
                   source_p->name, user,
                   me.name, source_p->host, source_p->username,
                   source_p->name, reason);
      }
    else
      {
        sendto_one(client_p, ":%s KILL %s :%s %s",
                   source_p->name, user,
                   inpath, reason);
      }
  }
}
