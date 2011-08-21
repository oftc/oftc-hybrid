/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_accept.c: Allows a user to talk to a +g user.
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
#include "handlers.h"
#include "client.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "hash.h"       /* for find_client() */
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "s_user.h"
#include "modules.h"
#include "conf_general.h"

static void m_accept(struct Client *, struct Client *, int, char *[]);
static void list_accepts(struct Client *);

struct Message accept_msgtab = {
  "ACCEPT", 0, 0, 0, 0, MFLG_SLOW, 0, 
  { m_unregistered, m_accept, m_ignore, m_ignore, m_accept, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&accept_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&accept_msgtab);
}

const char *_version = "$Revision$";
#endif


/* add_accept()
 *
 * input        - pointer to preallocated nick
 *              - pointer to preallocated username
 *              - pointer to preallocated host
 *              - pointer to client to add to acceptlist
 * output       - none
 * side effects - target is added to clients list
 */
static void
add_accept(const struct split_nuh_item *nuh, struct Client *source_p)
{
  struct split_nuh_item *accept_p = MyMalloc(sizeof(*accept_p));

  DupString(accept_p->nickptr, nuh->nickptr);
  DupString(accept_p->userptr, nuh->userptr);
  DupString(accept_p->hostptr, nuh->hostptr);

  dlinkAdd(accept_p, &accept_p->node, &source_p->localClient->acceptlist);

  list_accepts(source_p);
}

/*! \brief ACCEPT command handler
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = list of masks to be accepted or removed (optional)
 */
static void
m_accept(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *mask = NULL;
  char *p = NULL;
  char nick[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  struct split_nuh_item nuh;
  struct split_nuh_item *accept_p = NULL;

  if (EmptyString(parv[1]) || !irccmp(parv[1], "*"))
  {
    list_accepts(source_p);
    return;
  }

  for (mask = strtoken(&p, parv[1], ","); mask != NULL;
       mask = strtoken(&p,    NULL, ","))
  {
    if (*mask == '-' && *++mask != '\0')
    {
      nuh.nuhmask  = mask;
      nuh.nickptr  = nick;
      nuh.userptr  = user;
      nuh.hostptr  = host;

      nuh.nicksize = sizeof(nick);
      nuh.usersize = sizeof(user);
      nuh.hostsize = sizeof(host);

      split_nuh(&nuh);

      if ((accept_p = find_accept(nick, user, host, source_p, 0)) == NULL)
      {
        sendto_one(source_p, form_str(ERR_ACCEPTNOT),
                   me.name, source_p->name, nick, user, host);
        continue;
      }

      del_accept(accept_p, source_p);
    }
    else if (*mask != '\0')
    {
      if (dlink_list_length(&source_p->localClient->acceptlist) >=
          general_config.max_accept)
      {
        sendto_one(source_p, form_str(ERR_ACCEPTFULL),
                   me.name, source_p->name);
        return;
      }

      nuh.nuhmask  = mask;
      nuh.nickptr  = nick;
      nuh.userptr  = user;
      nuh.hostptr  = host;

      nuh.nicksize = sizeof(nick);
      nuh.usersize = sizeof(user);
      nuh.hostsize = sizeof(host);

      split_nuh(&nuh);

      if ((accept_p = find_accept(nick, user, host, source_p, 0)) != NULL)
      {
        sendto_one(source_p, form_str(ERR_ACCEPTEXIST),
                   me.name, source_p->name, nick, user, host);
        continue;
      }

      add_accept(&nuh, source_p);
    }
  }
}

/* list_accepts()
 *
 * input 	- pointer to client
 * output	- none
 * side effects	- print accept list to client
 */
static void
list_accepts(struct Client *source_p)
{
  int len = 0;
  char nicks[IRCD_BUFSIZE] = { '\0' };
  char *t = nicks;
  const dlink_node *ptr = NULL;

  len = strlen(me.name) + strlen(source_p->name) + 12;

  DLINK_FOREACH(ptr, source_p->localClient->acceptlist.head)
  {
    const struct split_nuh_item *accept_p = ptr->data;
    size_t masklen = strlen(accept_p->nickptr) +
                     strlen(accept_p->userptr) +
                     strlen(accept_p->hostptr) + 2 /* !@ */ ;

    if ((t - nicks) + masklen + len  > IRCD_BUFSIZE)
    {
      *(t - 1) = '\0';
      sendto_one(source_p, form_str(RPL_ACCEPTLIST),
                 me.name, source_p->name, nicks);
      t = nicks;
    }

    t += ircsprintf(t, "%s!%s@%s ",
                    accept_p->nickptr,
                    accept_p->userptr, accept_p->hostptr);
  }

  if (nicks[0] != '\0')
  {
    *(t - 1) = '\0';
    sendto_one(source_p, form_str(RPL_ACCEPTLIST),
               me.name, source_p->name, nicks);
  }

  sendto_one(source_p, form_str(RPL_ENDOFACCEPT),
             me.name, source_p->name);
}
