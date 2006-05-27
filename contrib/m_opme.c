/*   contrib/m_opme.c
 *   Copyright (C) 2002 Hybrid Development Team
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */
#include "stdinc.h"
#include "tools.h"
#include "handlers.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "irc_string.h"
#include "hash.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void mo_opme(struct Client *client_p, struct Client *source_p, int parc, char *parv[]);
static int chan_is_opless(struct Channel *chptr);

struct Message opme_msgtab = {
  "OPME", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_opme, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&opme_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&opme_msgtab);
}

const char *_version = "$Revision: 229 $";

#endif

static int
chan_is_opless(struct Channel *chptr)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, chptr->members.head)
    if (((struct Membership *)ptr->data)->flags & CHFL_CHANOP)
      return(0);

  return(1);
}

/*
** mo_opme
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void
mo_opme(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Channel *chptr;
  struct Membership *member;

  /* admins only */
  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  /* XXX - we might not have CBURSTed this channel if we are a lazylink
   * yet. */
  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, parv[1]);
    return;
  }

  if ((member = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOTONCHANNEL),
               me.name, source_p->name, parv[1]);
    return;
  }

  if (chan_is_opless(chptr) == 0)
  {
    sendto_one(source_p, ":%s NOTICE %s :%s Channel is not opless",
               me.name, source_p->name, parv[1]);
    return;
  }

  AddMemberFlag(member, CHFL_CHANOP);

  if (parv[1][0] == '&')
  {
    sendto_wallops_flags(UMODE_LOCOPS, &me,
                         "OPME called for [%s] by %s!%s@%s",
                         parv[1], source_p->name, source_p->username,
                         source_p->host);
  }
  else
  {
    sendto_wallops_flags(UMODE_WALLOP, &me,
                         "OPME called for [%s] by %s!%s@%s",
                         parv[1], source_p->name, source_p->username,
                         source_p->host);
    sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                  ":%s WALLOPS :OPME called for [%s] by %s!%s@%s",
                  me.name, parv[1], source_p->name, source_p->username,
                  source_p->host);
  }

  ilog(L_NOTICE, "OPME called for [%s] by %s!%s@%s",
       parv[1], source_p->name, source_p->username,
       source_p->host);

  sendto_server(NULL, source_p, chptr, CAP_SID, NOCAPS, NOFLAGS,
                 ":%s PART %s", ID(source_p), parv[1]);
  sendto_server(NULL, source_p, chptr, NOCAPS, CAP_SID, NOFLAGS,
                ":%s PART %s", source_p->name, parv[1]);
  sendto_server(NULL, source_p, chptr, CAP_SID, NOCAPS, NOFLAGS,
                ":%s SJOIN %ld %s + :@%s",
                me.name, (unsigned long)chptr->channelts,
                parv[1],
                source_p->name /* XXX ID(source_p) */ );
  sendto_server(NULL, source_p, chptr, NOCAPS, CAP_SID, NOFLAGS,
                ":%s SJOIN %ld %s + :@%s",
                me.name, (unsigned long)chptr->channelts,
                parv[1], source_p->name);

  sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s +o %s",
                       me.name, parv[1], source_p->name);
}
