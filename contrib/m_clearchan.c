/*
 *   IRC - Internet Relay Chat, contrib/m_clearchan.c
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
#include "sprintf_irc.h"
#include "hash.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "list.h"
#include "s_conf.h"


extern BlockHeap *ban_heap;

static char *mbuf;
static void mo_clearchan(struct Client *, struct Client *, int, char **);
static void kick_list(struct Client *, struct Client *, struct Channel *, char *);
static void remove_our_modes(struct Channel *, struct Client *);
static void remove_a_mode(struct Channel *, int, char);

struct Message clearchan_msgtab = {
  "CLEARCHAN", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, mo_clearchan, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&clearchan_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&clearchan_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
** mo_clearchan
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void
mo_clearchan(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  struct Channel *chptr;

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
               me.name, parv[0], parv[1]);
    return;
  }

  if (IsMember(source_p, chptr))
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Please part %s before using CLEARCHAN",
               me.name, source_p->name, parv[1]);
    return;
  }

  sendto_wallops_flags(UMODE_WALLOP, &me, "CLEARCHAN called for [%s] by %s!%s@%s",
                       parv[1], source_p->name, source_p->username, source_p->host);
  sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                ":%s WALLOPS :CLEARCHAN called for [%s] by %s!%s@%s",
                me.name, parv[1], source_p->name, source_p->username,
                source_p->host);
  ilog(L_NOTICE, "CLEARCHAN called for [%s] by %s!%s@%s",
       parv[1], source_p->name, source_p->username, source_p->host);

  /* Kill all the modes we have about the channel..
   * making everyone a peon
   */  
  remove_our_modes(chptr, source_p);

  /* SJOIN the user to give them ops, and lock the channel */
  sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS,
                LL_ICLIENT, ":%s SJOIN %lu %s +ntsi :@%s",
                me.name, (unsigned long)(chptr->channelts - 1),
                chptr->chname, source_p->name);
  sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN %s",
                       source_p->name, source_p->username,
                       source_p->host, chptr->chname);
  sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s +o %s",
                       me.name, chptr->chname, source_p->name);


  /* Take the TS down by 1, so we don't see the channel taken over
   * again. */
  if (chptr->channelts)
    chptr->channelts--;

  chptr->mode.mode =
    MODE_SECRET | MODE_TOPICLIMIT | MODE_INVITEONLY | MODE_NOPRIVMSGS;
  free_topic(chptr);
  chptr->mode.key[0] = '\0';

  /* Kick the users out and join the oper */
  kick_list(client_p, source_p, chptr, chptr->chname);
}

static void
kick_list(struct Client *client_p, struct Client *source_p,
          struct Channel *chptr, char *chname)
{
  dlink_node *m, *next_m;
  struct Membership *ms;

  DLINK_FOREACH(m, chptr->members.head)
  {
    ms = m->data;
    sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s KICK %s %s :CLEARCHAN",
                         source_p->name, source_p->username, source_p->host,
                         chname, ms->client_p->name);
    sendto_server(NULL, source_p, chptr, NOCAPS, NOCAPS, LL_ICLIENT,
                  ":%s KICK %s %s :CLEARCHAN", source_p->name,
                  chname, ms->client_p->name);
  }

  /* Join the user themselves to the channel down here, so they dont see a nicklist 
   * or people being kicked */
  add_user_to_channel(chptr, source_p, CHFL_CHANOP);

  DLINK_FOREACH_SAFE(m, next_m, chptr->members.head)
  {
    ms = m->data;
    if (ms->client_p != source_p)
      remove_user_from_channel(ms);
  }

  sendto_one(source_p, ":%s!%s@%s JOIN %s",
             source_p->name, source_p->username,
             source_p->host, chname);
  channel_member_names(source_p, chptr, 1);
}

/* remove_our_modes()
 *
 * inputs       - hide from ops or not int flag
 *              - pointer to channel to remove modes from
 *              - client pointer
 * output       - NONE
 * side effects - Go through the local members, remove all their
 *                chanop modes etc., this side lost the TS.
 */
static void
remove_our_modes(struct Channel *chptr, struct Client *source_p)
{
  remove_a_mode(chptr, CHFL_CHANOP, 'o');
  remove_a_mode(chptr, CHFL_VOICE, 'v');

  /* Clear all +beI modes */
  free_channel_list(&chptr->banlist);
  free_channel_list(&chptr->exceptlist);
  free_channel_list(&chptr->invexlist);
  chptr->banlist.head = chptr->exceptlist.head = chptr->invexlist.head = NULL;
  chptr->banlist.tail = chptr->exceptlist.tail = chptr->invexlist.tail = NULL;
}

/* remove_a_mode()
 *
 * inputs	-
 * output	- NONE
 * side effects	- remove ONE mode from a channel
 */
static void
remove_a_mode(struct Channel *chptr, int mask, char flag)
{
  dlink_node *ptr;
  struct Membership *ms;
  char lmodebuf[MODEBUFLEN];
  char *lpara[4];
  int count = 0;

  mbuf = lmodebuf;
  *mbuf++ = '-';

  lpara[0] = lpara[1] = lpara[2] = lpara[3] = "";

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;
    if ((ms->flags & mask) == 0)
      continue;

    ms->flags &= ~mask;

    lpara[count++] = ms->client_p->name;

    *mbuf++ = flag;

    if (count >= 4)
    {
      *mbuf = '\0';
      sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s %s %s %s %s %s",
                           me.name, chptr->chname, lmodebuf, lpara[0],
                           lpara[1], lpara[2], lpara[3]);

      mbuf = lmodebuf;
      *mbuf++ = '-';
      count = 0;
      lpara[0] = lpara[1] = lpara[2] = lpara[3] = "";
    }
  }

  if (count != 0)
  {
    *mbuf = '\0';
    sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s %s %s %s %s %s",
                         me.name, chptr->chname, lmodebuf, lpara[0],
                         lpara[1], lpara[2], lpara[3]);
  }
}
