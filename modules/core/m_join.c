/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_join.c: Joins a channel.
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
#include "channel_mode.h"
#include "client.h"
#include "common.h"   /* bleah */
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_log.h"


static void m_join(struct Client *, struct Client *, int, char **);
static void ms_join(struct Client *, struct Client *, int, char **);
static void ms_svsjoin(struct Client *, struct Client *, int, char **);
static void do_join_0(struct Client *client_p, struct Client *source_p);

static void set_final_mode(struct Mode *, struct Mode *);
static void remove_our_modes(struct Channel *, struct Client *);
static void remove_a_mode(struct Channel *, struct Client *, int, char);

static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];
static char sendbuf[MODEBUFLEN];
static char *mbuf;

struct Message join_msgtab = {
  "JOIN", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_join, ms_join, m_ignore, m_join, m_ignore}
};

struct Message svsjoin_msgtab = {
  "SVSJOIN", 0, 0, 3, 0, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_svsjoin, ms_svsjoin, m_ignore, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&join_msgtab);
  mod_add_cmd(&svsjoin_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&svsjoin_msgtab);
  mod_del_cmd(&join_msgtab);
}

const char *_version = "$Revision$";
#endif

/* last0() stolen from ircu */
static char *
last0(struct Client *client_p, struct Client *source_p, char *chanlist)
{
  char *p;
  int join0 = 0;

  for (p = chanlist; *p; ++p) /* find last "JOIN 0" */
  {
    if (*p == '0' && (*(p + 1) == ',' || *(p + 1) == '\0'))
    {
      if ((*p + 1) == ',')
        ++p;

      chanlist = p + 1;
      join0 = 1;
    }
    else
    {
      while (*p != ',' && *p != '\0') /* skip past channel name */
        ++p;

      if (*p == '\0') /* hit the end */
        break;
    }
  }

  if (join0)
    do_join_0(client_p, source_p);

  return chanlist;
}

/* m_join()
 *      parv[0] = sender prefix
 *      parv[1] = channel
 *      parv[2] = channel password (key)
 */
static void
m_join(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char *p = NULL;
  char *key_list = NULL;
  char *chan_list = NULL;
  char *chan = NULL;
  struct Channel *chptr = NULL;
  int i = 0;
  unsigned int flags = 0;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "JOIN");
    return;
  }

  assert(client_p == source_p);

  key_list = parv[2];
  chan_list = last0(client_p, source_p, parv[1]);

  for (chan = strtoken(&p, chan_list, ","); chan;
       chan = strtoken(&p, NULL,      ","))
  {
    char *key = NULL;

    /* If we have any more keys, take the first for this channel. */
    if (!EmptyString(key_list) && (key_list = strchr(key = key_list, ',')))
      *key_list++ = '\0';

    /* Empty keys are the same as no keys. */
    if (key && *key == '\0')
      key = NULL;

    if (!check_channel_name(chan, 1))
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
                 me.name, source_p->name, chan);
      continue;
    }

    if (ConfigChannel.disable_local_channels && (*chan == '&'))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, source_p->name, chan);
      continue;
    }

    if (!IsExemptResv(source_p) &&
        !(IsOper(source_p) && ConfigFileEntry.oper_pass_resv) &&
        ((!hash_find_resv(chan)) == ConfigChannel.restrict_channels))
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
                 me.name, source_p->name, chan);
      sendto_gnotice_flags(UMODE_SPY, L_ALL, me.name, &me, NULL,
                           "User %s (%s@%s) is attempting to join locally juped channel %s",
                           source_p->name, source_p->username, source_p->host, chan);
      continue;
    }

    if ((chptr = hash_find_channel(chan)) != NULL)
    {
      if (IsMember(source_p, chptr))
        continue;

      if (splitmode && !IsOper(source_p) && (*chan != '&') &&
          ConfigChannel.no_join_on_split)
      {
        sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                   me.name, source_p->name, chan);
        continue;
      }

      /*
       * This should never be the case unless there is some sort of
       * persistant channels.
       */
      if (dlink_list_length(&chptr->members) == 0)
        flags = CHFL_CHANOP;
      else
        flags = 0;
    }
    else
    {
      if (splitmode && !IsOper(source_p) && (*chan != '&') &&
          (ConfigChannel.no_create_on_split || ConfigChannel.no_join_on_split))
      {
        sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                   me.name, source_p->name, chan);
        continue;
      }

      flags = CHFL_CHANOP;
      chptr = make_channel(chan);
      if(MyClient(source_p))
        sendto_gnotice_flags(UMODE_SPY, L_ALL, me.name, &me, NULL,
            "Channel %s created by %s!%s@%s", chan, source_p->name,
            source_p->username, source_p->host);
    }

    if (!IsOper(source_p))
      check_spambot_warning(source_p, chptr->chname);

    /*
     * can_join checks for +i key, bans.
     */
    if (((i = can_join(source_p, chptr, key)) && !IsGod(source_p)))
    {
      switch (i)
      {
#define NORMAL_NUMERIC(i)                            \
        case i:                                      \
          sendto_one(source_p, form_str(i), me.name, \
                     source_p->name, chptr->chname); \
          break

        NORMAL_NUMERIC(ERR_TOOMANYCHANNELS);
        NORMAL_NUMERIC(ERR_BANNEDFROMCHAN);
        NORMAL_NUMERIC(ERR_INVITEONLYCHAN);
        NORMAL_NUMERIC(ERR_BADCHANNELKEY);
        NORMAL_NUMERIC(ERR_CHANNELISFULL);
        NORMAL_NUMERIC(ERR_REGONLYCHAN);
        NORMAL_NUMERIC(ERR_SSLONLYCHAN);
      }
      if(i == ERR_TOOMANYCHANNELS)
          break;
      else
          continue;
    }

    if(i != 0 && IsGod(source_p) && MyClient(source_p))
    {
      char tmp[IRCD_BUFSIZE];
      ircsprintf(tmp, "%s is using God mode: JOIN %s", source_p->name,
          chptr->chname);
      sendto_gnotice_flags(UMODE_SERVNOTICE, L_ALL, me.name, &me, NULL,
          "%s", tmp);
      oftc_log("%s", tmp);
    }

    add_user_to_channel(chptr, source_p, flags, YES);

    /*
     *  Set timestamp if appropriate, and propagate
     */
    if (flags & CHFL_CHANOP)
    {
      chptr->channelts = CurrentTime;
      chptr->mode.mode |= MODE_TOPICLIMIT;
      chptr->mode.mode |= MODE_NOPRIVMSGS;

      sendto_server(client_p, source_p, chptr, CAP_TS6, NOCAPS, LL_ICLIENT,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.id, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->id);
      sendto_server(client_p, source_p, chptr, NOCAPS, CAP_TS6, LL_ICLIENT,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.name, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->name);
      /*
       * notify all other users on the new channel
       */
      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname);
      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s MODE %s +nt",
                           me.name, chptr->chname);
    }
    else
    {
      sendto_server(client_p, source_p, chptr, CAP_TS6, NOCAPS, LL_ICLIENT,
                    ":%s JOIN %lu %s +",
                    source_p->id, (unsigned long)chptr->channelts,
                    chptr->chname);
      sendto_server(client_p, source_p, chptr, NOCAPS, CAP_TS6, LL_ICLIENT,
                    ":%s SJOIN %lu %s + :%s",
                    me.name, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->name);

      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname);
    }

    del_invite(chptr, source_p);

    if (chptr->topic != NULL)
    {
      sendto_one(source_p, form_str(RPL_TOPIC), me.name,
                 source_p->name, chptr->chname, chptr->topic);

      sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
                 me.name, source_p->name, chptr->chname,
                 chptr->topic_info, chptr->topic_time);
    }

    channel_member_names(source_p, chptr, 1);

    source_p->localClient->last_join_time = CurrentTime;
  }
}

/* ms_join()
 *
 * inputs	- parv[0] = uid
 *		  parv[1] = ts
 *		  parv[2] = channel name
 *		  parv[3] = modes (Deprecated)
 * output	- none
 * side effects	- handles remote JOIN's sent by servers. In TSora
 *		  remote clients are joined using SJOIN, hence a 
 *		  JOIN sent by a server on behalf of a client is an error.
 *		  here, the initial code is in to take an extra parameter
 *		  and use it for the TimeStamp on a new channel.
 */
static void 
ms_join(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  time_t newts = 0;
  time_t oldts = 0;
  int keep_our_modes = 1;
  int keep_new_modes = 1;
  int isnew = 0;
  const char *servername = NULL;
  struct Channel *chptr = NULL;
  struct Mode mode, *oldmode;

  if (parc == 2 && !irccmp(parv[1], "0"))
  {
    do_join_0(client_p, source_p);
    return;
  }

  if (parc < 4 || *parv[2] == '&')
    return;

  if (!check_channel_name(parv[2], 0))
  {
    sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL,
                         "*** Too long or invalid channel name from %s: %s",
                         client_p->name, parv[2]);
    return;
  }

  mbuf = modebuf;
  mode.mode = mode.limit = 0;
  mode.key[0] = '\0';

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    isnew = 1;
    chptr = make_channel(parv[2]);
    if(MyClient(source_p))
      sendto_gnotice_flags(UMODE_SPY, L_ALL, me.name, &me, NULL,
          "Channel %s created by %s!%s@%s", parv[2], source_p->name,
          source_p->username, source_p->host);
  }

  newts   = atol(parv[1]);
  oldts   = chptr->channelts;
  oldmode = &chptr->mode;

  if (ConfigFileEntry.ignore_bogus_ts)
  {
    if (newts < 800000000)
    {
      sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL,
                           "*** Bogus TS %lu on %s ignored from %s",
                           (unsigned long)newts, chptr->chname,
                           client_p->name);

      newts = (oldts == 0) ? 0 : 800000000;
    }
  }
  else
  {
    if (!newts && !isnew && oldts)
    {
      sendto_channel_local(ALL_MEMBERS, NO, chptr,
                             ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to 0",
                             me.name, chptr->chname, chptr->chname, (unsigned long)oldts);
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                           "Server %s changing TS on %s from %lu to 0",
                           source_p->name, chptr->chname, (unsigned long)oldts);
    }
  }

  if (isnew)
    chptr->channelts = newts;
  else if (newts == 0 || oldts == 0)
    chptr->channelts = 0;
  else if (newts == oldts)
    ;
  else if (newts < oldts)
  {
    keep_our_modes = NO;
    chptr->channelts = newts;
  }
  else
    keep_new_modes = NO;

  if (!keep_new_modes)
    mode = *oldmode;
  else if (keep_our_modes)
  {
    mode.mode |= oldmode->mode;
    if (oldmode->limit > mode.limit)
      mode.limit = oldmode->limit;
    if (strcmp(mode.key, oldmode->key) < 0)
      strcpy(mode.key, oldmode->key);
  }

  set_final_mode(&mode, oldmode);
  chptr->mode = mode;

  /* Lost the TS, other side wins, so remove modes on this side */
  if (!keep_our_modes)
  {
    remove_our_modes(chptr, source_p);
    sendto_channel_local(ALL_MEMBERS, NO, chptr,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to %lu",
                          me.name, chptr->chname, chptr->chname,
                         (unsigned long)oldts, (unsigned long)newts);
  }
   
  if (*modebuf != '\0')
  {
    servername = (ConfigServerHide.hide_servers || IsHidden(source_p)) ?
                  me.name : source_p->name;

    /* This _SHOULD_ be to ALL_MEMBERS
     * It contains only +imnpstlk, etc */
    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s MODE %s %s %s",
                         servername, chptr->chname, modebuf, parabuf);
  }

  if (!IsMember(source_p, chptr))
  {
    add_user_to_channel(chptr, source_p, 0, YES);
    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname);
  }

  sendto_server(client_p, NULL, chptr, CAP_TS6, NOCAPS, NOFLAGS,
                ":%s JOIN %lu %s +",
                ID(source_p), (unsigned long)chptr->channelts, chptr->chname);
  sendto_server(client_p, NULL, chptr, NOCAPS, CAP_TS6, NOFLAGS,
                ":%s SJOIN %lu %s + :%s",
                source_p->servptr->name, (unsigned long)chptr->channelts,
                chptr->chname, source_p->name);
}

/* m_svsjoin()
 *  parv[0] = sender prefix
 *  parv[1] = user to force
 *  parv[2] = channel to force them into
 *  parv[3] = key for the channel
 */
static void
ms_svsjoin(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *newparv[] = { NULL, parv[2], parv[3], NULL};

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return;

  if (!MyConnect(target_p))
  {
    if (target_p->from != client_p)
    {
      char *key;
      char *seperator;

      if(parv[3] == NULL)
      {
          key = "";
          seperator = "";
      }
      else
      {
          key = parv[3];
          seperator = " ";
      }

      if (IsCapable(target_p->from, CAP_ENCAP))
        sendto_one(target_p, ":%s ENCAP %s SVSJOIN %s %s%s%s",
                   source_p->name, target_p->from->name,
                   target_p->name, parv[2], seperator, key);
      else
        sendto_one(target_p, ":%s SVSJOIN %s %s%s%s",
                   source_p->name, target_p->name, parv[2], seperator, key);
    }

    return;
  }

  /* Fake call to m_join as if the user did it */
  m_join(target_p, target_p, parc - 1, newparv);
}

/* do_join_0()
 *
 * inputs	- pointer to client doing join 0
 * output	- NONE
 * side effects	- Use has decided to join 0. This is legacy
 *		  from the days when channels were numbers not names. *sigh*
 *		  There is a bunch of evilness necessary here due to
 * 		  anti spambot code.
 */
static void
do_join_0(struct Client *client_p, struct Client *source_p)
{
  struct Channel *chptr = NULL;
  dlink_node *ptr = NULL, *ptr_next = NULL;

  if (source_p->channel.head && MyConnect(source_p) && !IsOper(source_p))
    check_spambot_warning(source_p, NULL);

  DLINK_FOREACH_SAFE(ptr, ptr_next, source_p->channel.head)
  {
    chptr = ((struct Membership *)ptr->data)->chptr;

    sendto_server(client_p, NULL, chptr, CAP_TS6, NOCAPS, NOFLAGS,
                  ":%s PART %s", ID(source_p), chptr->chname);
    sendto_server(client_p, NULL, chptr, NOCAPS, CAP_TS6, NOFLAGS,
                  ":%s PART %s", source_p->name, chptr->chname);
    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s PART %s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname);

    remove_user_from_channel(ptr->data);
  }
}

/* set_final_mode()
 *
 * inputs       - pointer to mode to setup
 *              - pointer to old mode
 * output       - NONE
 * side effects -
 */
static const struct mode_letter
{
  unsigned int mode;
  unsigned char letter;
} flags[] = {
  { MODE_NOPRIVMSGS, 'n' },
  { MODE_TOPICLIMIT, 't' },
  { MODE_SECRET,     's' },
  { MODE_MODERATED,  'm' },
  { MODE_INVITEONLY, 'i' },
  { MODE_PRIVATE,    'p' },
  { 0, '\0' }
};

static void
set_final_mode(struct Mode *mode, struct Mode *oldmode)
{
  char *pbuf = parabuf;
  int what   = 0;
  int len;
  int i;

  for (i = 0; flags[i].letter; i++)
  {
    if ((flags[i].mode & mode->mode) &&
        !(flags[i].mode & oldmode->mode))
    {
      if (what != 1)
      {
        *mbuf++ = '+';
        what = 1;
      }
      *mbuf++ = flags[i].letter;
    }
  }

  for (i = 0; flags[i].letter; i++)
  {
    if ((flags[i].mode & oldmode->mode) &&
        !(flags[i].mode & mode->mode))
    {
      if (what != -1)
      {
        *mbuf++ = '-';
        what = -1;
      }
      *mbuf++ = flags[i].letter;
    }
  }

  if (oldmode->limit != 0 && mode->limit == 0)
  {
    if (what != -1)
    {
      *mbuf++ = '-';
      what = -1;
    }
    *mbuf++ = 'l';
  }

  if (oldmode->key[0] && !mode->key[0])
  {
    if (what != -1)
    {
      *mbuf++ = '-';
      what = -1;
    }
    *mbuf++ = 'k';
    len = ircsprintf(pbuf, "%s ", oldmode->key);
    pbuf += len;
  }

  if (mode->limit != 0 && oldmode->limit != mode->limit)
  {
    if (what != 1)
    {
      *mbuf++ = '+';
      what = 1;
    }
    *mbuf++ = 'l';
    len = ircsprintf(pbuf, "%d ", mode->limit);
    pbuf += len;
  }

  if (mode->key[0] && strcmp(oldmode->key, mode->key))
  {
    if (what != 1)
    {
      *mbuf++ = '+';
      what = 1;
    }
    *mbuf++ = 'k';
    len = ircsprintf(pbuf, "%s ", mode->key);
    pbuf += len;
  }
  *mbuf = '\0';
}

/* remove_our_modes()
 *
 * inputs       - pointer to channel to remove modes from
 *              - client pointer
 * output       - NONE
 * side effects - Go through the local members, remove all their
 *                chanop modes etc., this side lost the TS.
 */
static void
remove_our_modes(struct Channel *chptr, struct Client *source_p)
{
  remove_a_mode(chptr, source_p, CHFL_CHANOP, 'o');
#ifdef HALFOPS
  remove_a_mode(chptr, source_p, CHFL_HALFOP, 'h');
#endif
  remove_a_mode(chptr, source_p, CHFL_VOICE, 'v');
}

/* remove_a_mode()
 *
 * inputs       -
 * output       - NONE
 * side effects - remove ONE mode from a channel
 */
static void
remove_a_mode(struct Channel *chptr, struct Client *source_p,
              int mask, char flag)
{
  dlink_node *ptr;
  struct Membership *ms;
  char lmodebuf[MODEBUFLEN];
  const char *lpara[MAXMODEPARAMS];
  int count = 0;
  int lcount;

  mbuf = lmodebuf;
  *mbuf++ = '-';

  for (lcount = 0; lcount < MAXMODEPARAMS; lcount++)
    lpara[lcount] = "";
  sendbuf[0] = '\0';

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;

    if ((ms->flags & mask) == 0)
      continue;

    ms->flags &= ~mask;

    lpara[count++] = ms->client_p->name;

    *mbuf++ = flag;

    if (count >= MAXMODEPARAMS)
    {
      for (lcount = 0; lcount < MAXMODEPARAMS; lcount++)
      {
        if (*lpara[lcount] == '\0')
          break;

        strlcat(sendbuf, " ", sizeof(sendbuf));
        strlcat(sendbuf, lpara[lcount], sizeof(sendbuf));
        lpara[lcount] = "";
      }

      *mbuf = '\0';
      sendto_channel_local(ALL_MEMBERS, NO, chptr,
                           ":%s MODE %s %s%s",
                           (IsHidden(source_p) ||
                           ConfigServerHide.hide_servers) ?
                           me.name : source_p->name,
                           chptr->chname, lmodebuf, sendbuf);
      mbuf = lmodebuf;
      *mbuf++ = '-';
      count = 0;
      sendbuf[0] = '\0';
    }
  }

  if (count != 0)
  {
    *mbuf = '\0';
    for (lcount = 0; lcount < MAXMODEPARAMS; lcount++)
    {
      if (*lpara[lcount] == '\0')
        break;

      strlcat(sendbuf, " ", sizeof(sendbuf));
      strlcat(sendbuf, lpara[lcount], sizeof(sendbuf));
    }
    sendto_channel_local(ALL_MEMBERS, NO, chptr,
                         ":%s MODE %s %s%s",
                         (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
                         me.name : source_p->name,
                         chptr->chname, lmodebuf, sendbuf);
  }
}

