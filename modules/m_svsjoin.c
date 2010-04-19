/* m_svsjoin.c - A way to force users to join channels, for services autojoin
 * Copyright (C) 2002, 2003, 2004, 2005 Hybrid Development Team
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *  1.Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  2.Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  3.The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 *  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id: m_force.c 989 2007-11-06 14:37:58Z swalsh $
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "common.h"     /* FALSE bleah */
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "hash.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "channel.h"
#include "channel_mode.h"

static void ms_svsjoin(struct Client *, struct Client *, int parc, char *[]);

struct Message svsjoin_msgtab = {
  "SVSJOIN", 0, 0, 3, 0, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_svsjoin, m_ignore, m_ignore, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&svsjoin_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&svsjoin_msgtab);
}

const char *_version = "$Revision: 989 $";
#endif

/* m_svsjoin()
 *  parv[0] = sender prefix
 *  parv[1] = user to force
 *  parv[2] = channel to force them into
 */
static void
ms_svsjoin(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  unsigned int type = 0;
  char mode = '\0';
  char sjmode = '\0';
  char *newch = NULL;
  dlink_node *ptr = NULL;

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return;

  if (!MyConnect(target_p))
  {
    if (target_p->from != client_p)
    {
      if (IsCapable(target_p->from, CAP_ENCAP))
        sendto_one(target_p, ":%s ENCAP %s SVSJOIN %s %s",
                   source_p->name, target_p->from->name,
                   target_p->name, parv[2]);
      else
        sendto_one(target_p, ":%s SVSJOIN %s %s",
                   source_p->name, target_p->name, parv[2]);
    }

    return;
  }

  /* select our modes from parv[2] if they exist... (chanop)*/
  switch (*parv[2])
  {
    case '@':
      type = CHFL_CHANOP;
      mode = 'o';
      sjmode = '@';
      parv[2]++;
      break;
#ifdef HALFOPS
    case '%':
      type = CHFL_HALFOP;
      mode = 'h';
      sjmode = '%';
      parv[2]++;
      break;
#endif
    case '+':
      type = CHFL_VOICE;
      mode = 'v';
      sjmode = '+';
      parv[2]++;
      break;
    default:
      type = 0;
      mode = sjmode = '\0'; /* make sure sjmode is 0. sjoin depends on it */
      break;
  }

  if ((chptr = hash_find_channel(parv[2])) != NULL)
  {
    if (IsMember(target_p, chptr))
      return;

    add_user_to_channel(chptr, target_p, type, NO);

    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                         target_p->name, target_p->username,
                         target_p->host, chptr->chname);

    if (sjmode)
      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s MODE %s +%c %s",
                           me.name, chptr->chname, mode, target_p->name);

    if (chptr->chname[0] == '#')
    {
      if (sjmode)
      {
        DLINK_FOREACH (ptr, serv_list.head)
        {
          struct Client *serv_p = ptr->data;
          if (serv_p == target_p->from || IsDead(serv_p))
            continue;

          sendto_one(serv_p, ":%s SJOIN %lu %s + :%c%s",
                     ID_or_name(&me, serv_p), (unsigned long)chptr->channelts,
                     chptr->chname, (sjmode == '%' &&
                     !IsCapable(serv_p, CAP_HOPS)) ? '@' : sjmode,
                     ID_or_name(target_p, serv_p));
        }
      }
      else
      {
        sendto_server(target_p, chptr, CAP_TS6, NOCAPS,
                      ":%s SJOIN %lu %s + :%s",
                      me.id, (unsigned long)chptr->channelts,
                      chptr->chname, target_p->id);
        sendto_server(target_p, chptr, NOCAPS, CAP_TS6,
                      ":%s SJOIN %lu %s + :%s",
                      me.name, (unsigned long)chptr->channelts,
                      chptr->chname, target_p->name);
      }
    }

    if (chptr->topic != NULL)
    {
      sendto_one(target_p, form_str(RPL_TOPIC),
                 me.name, target_p->name,
                 chptr->chname, chptr->topic);
      sendto_one(target_p, form_str(RPL_TOPICWHOTIME),
                 me.name, target_p->name, chptr->chname,
                 chptr->topic_info, chptr->topic_time);
    }

    target_p->localClient->last_join_time = CurrentTime;
    channel_member_names(target_p, chptr, 1);
  }
  else
  {
    newch = parv[2];

    if (!check_channel_name(newch, 1))
      return;

    /*
     * it would be interesting here to allow an oper
     * to force target_p into a channel that doesn't exist
     * even more so, into a local channel when we disable
     * local channels... but...
     * I don't want to break anything - scuzzy
     */
    if (ConfigChannel.disable_local_channels && (*newch == '&'))
      return;

    chptr = make_channel(newch);
    if(MyClient(target_p))
      sendto_gnotice_flags(UMODE_SPY, L_ALL, me.name, &me, NULL,
          "Channel %s created by %s!%s@%s", chptr->chname, target_p->name,
          target_p->username, target_p->host);

    add_user_to_channel(chptr, target_p, CHFL_CHANOP, NO);

    /* send out a join, make target_p join chptr */
    if (chptr->chname[0] == '#')
    {
      sendto_server(target_p, chptr, CAP_TS6, NOCAPS,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.id, (unsigned long)chptr->channelts,
                    chptr->chname, ID(target_p));
      sendto_server(target_p, chptr, NOCAPS, CAP_TS6,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.name, (unsigned long)chptr->channelts,
                    chptr->chname, target_p->name);
    }

    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                         target_p->name, target_p->username,
                         target_p->host, chptr->chname);

    chptr->mode.mode |= MODE_TOPICLIMIT | MODE_NOPRIVMSGS;

    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s MODE %s +nt",
                         me.name, chptr->chname);

    target_p->localClient->last_join_time = CurrentTime;
    channel_member_names(target_p, chptr, 1);
  }
}
