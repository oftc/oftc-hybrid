/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_lljoin.c: Joins a user on a lazy-link to a channel.
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
#include "channel_mode.h"
#include "vchannel.h"
#include "client.h"
#include "hash.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "s_serv.h"
#include "s_conf.h"
#include "send.h"
#include "handlers.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void ms_lljoin(struct Client *,struct Client *,int,char **);

struct Message lljoin_msgtab = {
  "LLJOIN", 0, 0, 3, 0, MFLG_SLOW | MFLG_UNREG, 0L,
  {m_unregistered, m_ignore, ms_lljoin, m_ignore}
};
#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&lljoin_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&lljoin_msgtab);
}

const char *_version = "$Revision$";
#endif
/*
 * m_lljoin
 *      parv[0] = sender prefix
 *      parv[1] = channel
 *      parv[2] = nick ("!nick" == cjoin)
 *      parv[3] = vchan/key (optional)
 *      parv[4] = key (optional)
 *
 * If a lljoin is received, from our uplink, join
 * the requested client to the given channel, or ignore it
 * if there is an error.
 *
 *   Ok, the way this works. Leaf client tries to join a channel, 
 * it doesn't exist so the join does a cburst request on behalf of the
 * client, and aborts that join. The cburst sjoin's the channel if it
 * exists on the hub, and sends back an LLJOIN to the leaf. Thats where
 * this is now..
 *
 */
static void ms_lljoin(struct Client *client_p,
                     struct Client *source_p,
                     int parc,
                     char *parv[])
{
  char *chname = NULL;
  char *nick = NULL;
  char *key = NULL;
  char *vkey = NULL;
  int  flags;
  int  i;
  struct Client *target_p;
  struct Channel *chptr, *vchan_chptr, *root_vchan;
#ifdef VCHANS
  int cjoin = 0;
  int  vc_ts;
  char *pvc = NULL;
#endif

  if(uplink && !IsCapable(uplink,CAP_LL))
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
			   "*** LLJOIN requested from non LL server %s",
			   client_p->name);
      return;
    }

  chname = parv[1];
  if(chname == NULL)
    return;

  nick = parv[2];
  if(nick == NULL)
    return;

#ifdef VCHANS
  if (nick[0] == '!')
  {
    cjoin = 1;
    nick++;
  }
 
  if(parc > 4)
  {
    key = parv[4];
    vkey = parv[3];
  }
#endif
  else if(parc >3)
  {
    key = vkey = parv[3];
  }

  flags = 0;

  target_p = find_client(nick);

  if( !target_p || !target_p->user )
    return;

  if( !MyClient(target_p) )
    return;

  chptr = hash_find_channel(chname);

#ifdef VCHANS
  if (cjoin)
  {
    if(!chptr) /* Uhm, bad! */
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "LLJOIN %s %s called by %s, but root chan doesn't exist!",
        chname, nick, client_p->name);
      return;
    }
    flags = CHFL_CHANOP;

    if(! (vchan_chptr = cjoin_channel(chptr, target_p, chname)))
      return;

    root_vchan = chptr;
    chptr = vchan_chptr;
  }
  else
#endif
  {
#ifdef VCHANS
    if (chptr)
    {
      vchan_chptr = select_vchan(chptr, target_p, vkey, chname);
    }
    else
#endif
    {
      chptr = vchan_chptr = get_or_create_channel(target_p, chname, NULL);
      flags = CHFL_CHANOP;
    }
   
#ifdef VCHANS
    if (vchan_chptr != chptr)
    {
      root_vchan = chptr;
      chptr = vchan_chptr;
    }
    else
#endif
      root_vchan = chptr;

    if(!chptr || !root_vchan)
      return;

    if (chptr->users == 0)
      flags = CHFL_CHANOP;
    else
      flags = 0;

    /* XXX in m_join.c :( */
    /* check_spambot_warning(target_p, chname); */

    /* They _could_ join a channel twice due to lag */
    if(chptr)
    {
      if (IsMember(target_p, chptr))    /* already a member, ignore this */
        return;
    }
    else
    {
      sendto_one(target_p, form_str(ERR_UNAVAILRESOURCE),
                 me.name, nick, root_vchan->chname);
      return;
    }

    if( (i = can_join(target_p, chptr, key)) )
    {
      sendto_one(target_p,
                 form_str(i), me.name, nick, root_vchan->chname);
      return;
    }
  }

  if ((target_p->user->joined >= ConfigChannel.max_chans_per_user) &&
      (!IsOper(target_p) || (target_p->user->joined >= 
                             ConfigChannel.max_chans_per_user*3)))
    {
      sendto_one(target_p, form_str(ERR_TOOMANYCHANNELS),
		 me.name, nick, root_vchan->chname );
      return; 
    }
  
  if(flags == CHFL_CHANOP)
    {
      chptr->channelts = CurrentTime;
      /*
       * XXX - this is a rather ugly hack.
       *
       * Unfortunately, there's no way to pass
       * the fact that it is a vchan through SJOIN...
       */
      /* Prevent users creating a fake vchan */
#ifdef VCHANS
      if (chname[0] == '#' && chname[1] == '#')
        {
          if ((pvc = strrchr(chname+3, '_')))
          {
            /*
             * OK, name matches possible vchan:
             * ##channel_blah
             */
            pvc++; /*  point pvc after last _ */
            vc_ts = atol(pvc);
            /*
             * if blah is the same as the TS, up the TS
             * by one, to prevent this channel being
             * seen as a vchan
             */
            if (vc_ts == CurrentTime)
              chptr->channelts++;
          }
        }
#endif

      sendto_one(uplink,
		 ":%s SJOIN %lu %s + :@%s",
		 me.name,
		 (unsigned long) chptr->channelts,
		 chptr->chname,
		 nick);
    }

  /* a user can create a channel with halfops..? */
#if 0
  else if ((flags == CHFL_HALFOP) && (IsCapable(uplink, CAP_HOPS)))
    {
      sendto_one(uplink,
		 ":%s SJOIN %lu %s + :%%%s",
		 me.name,
		 (unsigned long) chptr->channelts,
		 chptr->chname,
		 nick);
    }
#endif
  else
    {
      sendto_one(uplink,
		 ":%s SJOIN %lu %s + :%s",
		 me.name,
		 (unsigned long) chptr->channelts,
		 chptr->chname,
		 nick);
    }

  add_user_to_channel(chptr, target_p, flags);

#ifdef VCHANS
  if ( chptr != root_vchan )
    add_vchan_to_client_cache(target_p,root_vchan,chptr);
#endif
 
  sendto_channel_local(ALL_MEMBERS, chptr,
		       ":%s!%s@%s JOIN :%s",
		       target_p->name,
		       target_p->username,
		       target_p->host,
		       root_vchan->chname);
  
  if( flags & CHFL_CHANOP )
  {
    chptr->mode.mode |= MODE_TOPICLIMIT;
    chptr->mode.mode |= MODE_NOPRIVMSGS;
      
    sendto_channel_local(ALL_MEMBERS,chptr,
                         ":%s MODE %s +nt",
                         me.name, root_vchan->chname);
    sendto_one(uplink, 
               ":%s MODE %s +nt",
               me.name, chptr->chname);
  }

  channel_member_names(target_p, chptr, chname, 1);
}
