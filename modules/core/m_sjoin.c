/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_sjoin.c: Joins a user to a channel.
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
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "send.h"
#include "common.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_serv.h"
#include "s_conf.h"

static void ms_sjoin(struct Client *, struct Client *, int, char **);

struct Message sjoin_msgtab = {
  "SJOIN", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ignore, ms_sjoin, m_ignore, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&sjoin_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&sjoin_msgtab);
}

const char *_version = "$Revision$";
#endif

/* ms_sjoin()
 *
 * parv[0] - sender
 * parv[1] - TS
 * parv[2] - channel
 * parv[3] - modes + n arguments (key and/or limit)
 * parv[4+n] - flags+nick list (all in one parameter)
 * 
 * process a SJOIN, taking the TS's into account to either ignore the
 * incoming modes or undo the existing ones or merge them, and JOIN
 * all the specified users while sending JOIN/MODEs to local clients
 */

static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];
static char *para[MAXMODEPARAMS];
static char *mbuf;
static int pargs;

static void set_final_mode(struct Mode *, struct Mode *);
static void remove_our_modes(struct Channel *, struct Client *);
static void remove_a_mode(struct Channel *, struct Client *, int, char);

static void
ms_sjoin(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Channel *chptr;
  struct Client  *target_p, *lclient_p;
  time_t         newts;
  time_t         oldts;
  time_t         tstosend;
  static         struct Mode mode, *oldmode;
  int            args = 0;
  int            keep_our_modes = 1;
  int            keep_new_modes = 1;
  int            fl;
  int            people = 0;
  int		 num_prefix=0;
  int            isnew;
  int		 buflen = 0;
  char           *s, *nhops;
  static         char buf[2*BUFSIZE]; /* buffer for modes and prefix */
  static         char sjbuf_nhops[BUFSIZE]; /* buffer with halfops as @ */
  char           *p; /* pointer used making sjbuf */
  int            i;
  dlink_node     *m;
  const char *servername;

  *buf = '\0';
  *sjbuf_nhops = '\0';

  if (IsClient(source_p) || parc < 5)
    return;
  /* SJOIN's for local channels can't happen. */
  if (*parv[2] != '#')
    return;
  if (!check_channel_name(parv[2]))
    return;

  servername = (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
                me.name : source_p->name;

  mbuf = modebuf;
  *mbuf = '\0';
  pargs = 0;
  newts = atol(parv[1]);

  mode.mode = 0;
  mode.limit = 0;
  mode.key[0] = '\0';
  s = parv[3];

  while (*s)
  {
    switch (*(s++))
    {
      case 't':
        mode.mode |= MODE_TOPICLIMIT;
        break;
      case 'n':
        mode.mode |= MODE_NOPRIVMSGS;
        break;
      case 'i':
        mode.mode |= MODE_INVITEONLY;
        break;
      case 'p':
        mode.mode |= MODE_PRIVATE;
        break;
      case 's':
        mode.mode |= MODE_SECRET;
        break;
      case 'm':
        mode.mode |= MODE_MODERATED;
        break;
      case 'c':
        mode.mode |= MODE_NOCOLOR;
        break;
      case 'M':
        mode.mode |= MODE_SPEAKONLYIFREG;
        break;
      case 'R':
        mode.mode |= MODE_REGONLY;
        break;
      case 'k':
        strlcpy(mode.key, parv[4 + args], sizeof(mode.key));
        args++;
        if (parc < 5+args)
          return;
        break;
      case 'l':
        mode.limit = atoi(parv[4 + args]);
        args++;
        if (parc < 5+args)
          return;
        break;
    }
  }

  *parabuf = '\0';

  if ((chptr = get_or_create_channel(source_p, parv[2], &isnew)) == NULL)
    return; /* channel name too long? */

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

      newts = (oldts == 0) ? oldts : 800000000;
    }
  }
  else
  {
    if (!isnew && !newts && oldts)
    {
      sendto_channel_local(ALL_MEMBERS, chptr,
 		  	   ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to 0",
		  	   me.name, chptr->chname, chptr->chname, (unsigned long)oldts);
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
		           "Server %s changing TS on %s from %lu to 0",
			   source_p->name, chptr->chname, (unsigned long)oldts);
    }
  }
  if (isnew)
    chptr->channelts = tstosend = newts;
  else if (newts == 0 || oldts == 0)
    chptr->channelts = tstosend = 0;
  else if (newts == 0)
    chptr->channelts = tstosend = oldts;
  else if (newts == oldts)
    tstosend = oldts;
  else if (newts < oldts)
  {
    keep_our_modes = NO;
    chptr->channelts = tstosend = newts;
  }
  else
  {
    keep_new_modes = NO;
    tstosend = oldts;
  }

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
    sendto_channel_local(ALL_MEMBERS, chptr,
   		         ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to %lu",
	 		 me.name, chptr->chname, chptr->chname,
			 (unsigned long)oldts, (unsigned long)newts);
  }
   
  if (*modebuf != '\0')
  {
    /* This _SHOULD_ be to ALL_MEMBERS
     * It contains only +imnpstlk, etc */
    sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s %s %s",
	                 servername, chptr->chname, modebuf, parabuf);
  }

  *modebuf = *parabuf = '\0';
  if (parv[3][0] != '0' && keep_new_modes)
  {
    channel_modes(chptr, source_p, modebuf, parabuf);
  }
  else
  {
    modebuf[0] = '0';
    modebuf[1] = '\0';
  }

  buflen = ircsprintf(buf, ":%s SJOIN %lu %s %s %s:",
		      parv[0], (unsigned long)tstosend,
		      parv[2], modebuf, parabuf);

  /* check we can fit a nick on the end, as well as \r\n and a prefix "
   * @+".
   */
  if (buflen >= (IRCD_BUFSIZE - 2 - NICKLEN))
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
			 "Long SJOIN from server: %s(via %s) (ignored)",
			 source_p->name, client_p->name);
    return;
  }

  mbuf = modebuf;
  para[0] = para[1] = para[2] = para[3] = "";
  pargs = 0;

  *mbuf++ = '+';

  nhops = sjbuf_nhops;

  s = parv[args + 4];

  /* remove any leading spaces */
  while (*s == ' ')
    s++;
   
  /* if theres a space, theres going to be more than one nick, change the
   * first space to \0, so s is just the first nick, and point p to the
   * second nick
   */
  if ((p = strchr(s, ' ')) != NULL)
    *p++ = '\0';

  while (s != NULL)
  {
    fl = 0;
    num_prefix = 0;

    /* XXXXXXXX THIS IS JUST DUMB */
#ifdef USE_HALFOPS
    for (i = 0; i < 3; i++)
#else
    for (i = 0; i < 2; i++)
#endif
    {
      if (*s == '@')
      {
        fl |= CHFL_CHANOP;
        if (keep_new_modes)
        {
	  *nhops++ = *s;
	  num_prefix++;
        }
	s++;
      }
#ifdef USE_HALFOPS
      else if (*s == '%')
      {
        fl |= CHFL_HALFOP;
        if (keep_new_modes)
        {
          *nhops++ = *s;
          num_prefix++;
        }
        s++;
      }
#endif
      else if (*s == '+')
      {
        fl |= CHFL_VOICE;
        if (keep_new_modes)
        {
	  *nhops++ = *s;
          num_prefix++;
        }
        s++;
      }
    }
    /* if the client doesnt exist, backtrack over the prefix (@%+) that we
     * just added and skip to the next nick
     *
     * also do this if its fake direction or a server
     */
    if (!(target_p = find_client(s)) ||
        (target_p->from != client_p) || !IsPerson(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, s);

      nhops -= num_prefix;
      *nhops = '\0';
      goto nextnick;
    }

    /* copy the nick to the two buffers */
    nhops += ircsprintf(nhops, "%s ", s);
    assert((nhops-sjbuf_nhops) < sizeof(sjbuf_nhops));

    if (!keep_new_modes)
    {
      if (fl & (CHFL_CHANOP|CHFL_HALFOP))
        fl = CHFL_DEOPPED;
      else
        fl = 0;
    }
    people++;

    /* LazyLinks - Introduce unknown clients before sending the sjoin */
    if (ServerInfo.hub)
    {
      DLINK_FOREACH(m, serv_list.head)
      {
        lclient_p = m->data;

        /* Hopefully, the server knows about it's own clients. */
        if (client_p == lclient_p)
	  continue;

        /* Ignore non lazylinks */
        if (!IsCapable(lclient_p,CAP_LL))
	  continue;

        /* Ignore servers we won't tell anyway */
        if (!chptr->lazyLinkChannelExists &
            (lclient_p->localClient->serverMask))
          continue;

        /* Ignore servers that already know target_p */
        if (!(target_p->lazyLinkClientExists &
	    lclient_p->localClient->serverMask))
        {
	  /* Tell LazyLink Leaf about client_p,
	   * as the leaf is about to get a SJOIN */
	  sendnick_TS(lclient_p, target_p);
          add_lazylinkclient(lclient_p,target_p);
        }
      }
    }

    if (!IsMember(target_p, chptr))
    {
      add_user_to_channel(chptr, target_p, fl);
      sendto_channel_local(ALL_MEMBERS,chptr, ":%s!%s@%s JOIN :%s",
                           target_p->name, target_p->username,
                           target_p->host, parv[2]);
    }

    if (fl & CHFL_CHANOP)
    {
      *mbuf++ = 'o';
      para[pargs++] = s;

      if (pargs >= MAXMODEPARAMS)
      {
        *mbuf = '\0';
        sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s %s %s %s %s %s",
                             servername, chptr->chname, modebuf, para[0],
                             para[1], para[2], para[3]);
        mbuf = modebuf;
        *mbuf++ = '+';

        para[0] = para[1] = para[2] = para[3] = "";
        pargs = 0;
      }
    }
#ifdef USE_HALFOPS
    if (fl & CHFL_HALFOP)
    {
      *mbuf++ = 'h';
      para[pargs++] = s;

      if (pargs >= MAXMODEPARAMS)
      {
        *mbuf = '\0';
        sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s %s %s %s %s %s",
                             servername, chptr->chname, modebuf, para[0],
                             para[1], para[2], para[3]);
        mbuf = modebuf;
        *mbuf++ = '+';

        para[0] = para[1] = para[2] = para[3] = "";
        pargs = 0;
      }
    }
#endif
    if (fl & CHFL_VOICE)
    {
      *mbuf++ = 'v';
      para[pargs++] = s;

      if (pargs >= MAXMODEPARAMS)
      {
        *mbuf = '\0';
        sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s %s %s %s %s %s",
                             servername, chptr->chname, modebuf, para[0],
                             para[1], para[2], para[3]);
        mbuf = modebuf;
        *mbuf++ = '+';

        para[0] = para[1] = para[2] = para[3] = "";
        pargs = 0;
      }
    }

nextnick:
    /* p points to the next nick */
    s = p;

    /* if there was a trailing space and p was pointing to it, then we
     * need to exit.. this has the side effect of breaking double spaces
     * in an sjoin.. but that shouldnt happen anyway
     */
    if (s && (*s == '\0'))
      s = p = NULL;

    /* if p was NULL due to no spaces, s wont exist due to the above, so
     * we cant check it for spaces.. if there are no spaces, then when
     * we next get here, s will be NULL
     */
    if (s != NULL && ((p = strchr(s, ' ')) != NULL))
      *p++ = '\0';
  }

  *mbuf = '\0';

  if (pargs != 0)
  {
    sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s %s %s %s %s %s",
                         servername, chptr->chname, modebuf, para[0],
                         para[1], para[2], para[3]);
  }

  if (people == 0)
    return;

  /* relay the SJOIN to other servers */
  DLINK_FOREACH(m, serv_list.head)
  {
    target_p = m->data;

    if (target_p == client_p->from)
      continue;

    /* skip lazylinks that don't know about this server */
    if (ServerInfo.hub && IsCapable(target_p,CAP_LL))
    {
      if (!(chptr->lazyLinkChannelExists &
          target_p->localClient->serverMask))
        continue;
    }

    /* Its a blank sjoin, ugh */
    if (!parv[4 + args][0])
      return;

    sendto_one(target_p, "%s%s",
               buf, sjbuf_nhops);
  }
}

/* set_final_mode()
 *
 * inputs	- pointer to mode to setup
 *		- pointer to old mode
 * output	- NONE
 * side effects	- 
 */
static const struct mode_letter
{
  unsigned int mode;
  unsigned char letter;
} flags[] = { 
  { MODE_NOCOLOR,        'c' },
  { MODE_NOPRIVMSGS,     'n' },
  { MODE_TOPICLIMIT,     't' },
  { MODE_SECRET,         's' },
  { MODE_MODERATED,      'm' },
  { MODE_INVITEONLY,     'i' },
  { MODE_PRIVATE,        'p' },
  { MODE_SPEAKONLYIFREG, 'M' },
  { MODE_REGONLY,        'R' },
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
    pargs++;
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
    pargs++;
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
    pargs++;
  }
  *mbuf = '\0';
}

/* remove_our_modes()
 *
 * inputs	- pointer to channel to remove modes from
 *		- client pointer
 * output	- NONE
 * side effects	- Go through the local members, remove all their
 *		  chanop modes etc., this side lost the TS.
 */
static void
remove_our_modes(struct Channel *chptr, struct Client *source_p)
{
  remove_a_mode(chptr, source_p, CHFL_CHANOP, 'o');
#ifdef USE_HALFOPS
  remove_a_mode(chptr, source_p, CHFL_HALFOP, 'h');
#endif
  remove_a_mode(chptr, source_p, CHFL_VOICE, 'v');
}

/* remove_a_mode()
 *
 * inputs	-
 * output	- NONE
 * side effects	- remove ONE mode from a channel
 */
static
void remove_a_mode(struct Channel *chptr, struct Client *source_p,
                   int mask, char flag)
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
      sendto_channel_local(ALL_MEMBERS, chptr,
		           ":%s MODE %s %s %s %s %s %s",
			   (IsHidden(source_p) ||
			   ConfigServerHide.hide_servers) ?
			   me.name : source_p->name,
			   chptr->chname, lmodebuf,
			   lpara[0], lpara[1], lpara[2], lpara[3]);

      mbuf = lmodebuf;
      *mbuf++ = '-';
      count = 0;
      lpara[0] = lpara[1] = lpara[2] = lpara[3] = "";
    }
  }

  if (count != 0)
  {
    *mbuf = '\0';
    sendto_channel_local(ALL_MEMBERS, chptr,
			 ":%s MODE %s %s %s %s %s %s",
			 (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
			 me.name : source_p->name,
			 chptr->chname, lmodebuf,
			 lpara[0], lpara[1], lpara[2], lpara[3]);
  }
}
