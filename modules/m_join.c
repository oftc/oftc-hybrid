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
#include "vchannel.h"
#include "client.h"
#include "common.h"   /* bleah */
#include "resv.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void m_join(struct Client*, struct Client*, int, char**);
static void ms_join(struct Client*, struct Client*, int, char**);

struct Message join_msgtab = {
  "JOIN", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_join, ms_join, m_join}
};

#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&join_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&join_msgtab);
}
const char *_version = "$Revision$";

#endif
static void do_join_0(struct Client *client_p, struct Client *source_p);
void check_spambot_warning(struct Client *source_p, const char *name);


/*
 * m_join
 *      parv[0] = sender prefix
 *      parv[1] = channel
 *      parv[2] = channel password (key) (or vkey for vchans)
 *      parv[3] = vkey
 *
 */
static void
m_join(struct Client *client_p,
       struct Client *source_p,
       int parc,
       char *parv[])
{
  struct Channel *chptr = NULL;
  struct Channel *root_chptr = NULL;
  int joining_vchan = 0;
  char  *name, *key = NULL;
  char *vkey = NULL; /* !key for vchans */
  int   i, flags = 0;
  char  *p = NULL, *p2 = NULL, *p3 = NULL;
  int   successful_join_count = 0; /* Number of channels successfully joined */
  int   burst_modes = NO;
#ifdef VCHANS
  struct Channel *vchan_chptr = NULL;
  char *pvc = NULL;
  int   vc_ts;
#endif
  char modebuf[MODEBUFLEN];
  char parabuf[MODEBUFLEN];

  if (*parv[1] == '\0')
    {
      sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
                 me.name, parv[0], "JOIN");
      return;
    }

#ifdef VCHANS
  if (parc > 3)
    {
      key = strtoken(&p2, parv[3], ",");
      vkey = strtoken(&p3, parv[2], ",");
    }
  else 
#endif
  if (parc > 2)
    {
      key = strtoken(&p2, parv[2], ",");
      vkey = key;
    }


  for (name = strtoken(&p, parv[1], ","); name;
         key = (key) ? strtoken(&p2, NULL, ",") : NULL,
         vkey = (parc>3) ? ((vkey) ? strtoken(&p3, NULL, ",") : NULL) : key,
         name = strtoken(&p, NULL, ","))
    {
      modebuf[0] = '+';
      modebuf[1] = '\0';
      parabuf[0] = '\0';
      burst_modes = NO;

      if(!check_channel_name(name))
      {
        sendto_one(source_p, form_str(ERR_BADCHANNAME),
	           me.name, source_p->name, (unsigned char*)name);
        continue;
      }

      /*
      ** JOIN 0 sends out a part for all channels a user
      ** has joined.
      **
      ** this should be either disabled or selectable in
      ** config file .. it's abused a lot more than it's
      ** used these days :/ --is
      */
      if (*name == '0' && !atoi(name))
      {
        if (source_p->user->channel.head == NULL)
          continue;
	  
        do_join_0(&me,source_p);
	continue;
      }
      
      /* check it begins with # or & */
      else if(!IsChannelName(name))
      {
        sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
	           me.name, source_p->name, name);
	continue;
      }

      if(ConfigServerHide.disable_local_channels && (*name == '&'))
      {
        sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
	           me.name, source_p->name, name);
        continue;
      }

      /* check the length */
      if (strlen(name) > CHANNELLEN)
      {
        sendto_one(source_p, form_str(ERR_BADCHANNAME),
	           me.name, source_p->name, name);
	continue;
      }
      
      /* see if its resv'd */
      if(find_channel_resv(name))
	{
	  sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
		     me.name, source_p->name, name);
          sendto_gnotice_flags(FLAGS_SPY, L_OPER, me.name, &me, NULL,
                   "User %s (%s@%s) is attempting to join locally juped channel %s",
                   source_p->name, source_p->username, source_p->host, name);
	  continue;
	}

      if ((source_p->user->joined >= ConfigChannel.max_chans_per_user) &&
         (!IsOper(source_p) || (source_p->user->joined >=
	                        ConfigChannel.max_chans_per_user*3)))
	{
	  sendto_one(source_p, form_str(ERR_TOOMANYCHANNELS),
		     me.name, parv[0], name);
	  if(successful_join_count != 0)
	    source_p->localClient->last_join_time = CurrentTime;
	  return;
	}

      /* look for the channel */
      if((chptr = hash_find_channel(name)) != NULL)
	{
          if(IsMember(source_p, chptr))
            return;
	  if(splitmode && !IsOper(source_p) && (*name != '&') && 
             ConfigChannel.no_join_on_split)
	  {
	    sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                       me.name, source_p->name, name);
	    continue;
	  }

#ifdef VCHANS
          /* Check if they want to join a subchan or something */
	  if((vchan_chptr = select_vchan(chptr, source_p, vkey, name)) == NULL)
            continue;

          if(vchan_chptr != chptr)
          {
            joining_vchan = 1;
            root_chptr = chptr;
            chptr = vchan_chptr;
          }
          else
#endif
          {
            joining_vchan = 0;
            root_chptr = chptr;
          }
          
	  /* save the expense of calling channel_modes()
	   * if zero users on channel, then I have to call channel_modes().
	   * (N.B. if channel_modes() was rewritten to be sane and fast
	   * this check wouldn't be worth the bother.)
	   * Just because client ends up a chanop, doesn't mean
	   * channel_modes() has to be called. 
	   * -Dianora
	   */
	  if (chptr->users == 0)
	  {
	    flags = CHFL_CHANOP;
	    burst_modes = YES;
	  }
	  else
	    flags = 0;
	}
      else	/* channel does NOT exist, so create it */
	{
	  if(splitmode && !IsOper(source_p) && (*name != '&') && 
            (ConfigChannel.no_create_on_split || ConfigChannel.no_join_on_split))
	  {
	    sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
	               me.name, source_p->name, name);
	    continue;
	  }
	  
	  flags = CHFL_CHANOP;
	  if(!ServerInfo.hub)
	    {
	      /* LazyLinks */
	      if((*name != '&') && uplink && IsCapable(uplink, CAP_LL))
		{
		  sendto_one(uplink,":%s CBURST %s %s %s",
			     me.name,name,source_p->name, key ? key: "" );
		  /* And wait for LLJOIN */
		  return;
		}
	    }

	  /* So create it */
	  if ((chptr = get_or_create_channel(source_p, name, NULL)) == NULL)
	  {
	    sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
		       me.name, parv[0], name);
	    continue;
	  }
	  else
	    root_chptr = chptr;
	}

    if (!IsOper(source_p))
     check_spambot_warning(source_p, name);
      
      /*
       * can_join checks for +i key, bans.
       */

      if ((i = can_join(source_p, chptr, key)) && !IsGod(source_p))
	{
	  sendto_one(source_p, form_str(i), me.name, parv[0], name);
	  successful_join_count++;
	  continue;
	}

      if(i != 0 && IsGod(source_p) && MyClient(source_p))
      {
        char tmp[512];
        snprintf(tmp, 512, "%s is using God mode: JOIN %s",
            source_p->name, chptr->chname);
        sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
        oftc_log(tmp);
      } 

      /* add the user to the channel */
      
      add_user_to_channel(chptr, source_p, flags);

#ifdef VCHANS
      if (joining_vchan)
	add_vchan_to_client_cache(source_p,root_chptr,chptr);
#endif

      /*
      **  Set timestamp if appropriate, and propagate
      */

      if (flags & CHFL_CHANOP)
	{
	  chptr->channelts = CurrentTime;

	  /* detected a persistent channel, so
	   * have to call channel_modes() here.
	   */
	  if (burst_modes)
	  {
	    channel_modes(chptr, client_p, modebuf, parabuf);
	  }
	  else /* Otherwise, its a stock +nt */
	  {
	    chptr->mode.mode |= MODE_TOPICLIMIT;
	    chptr->mode.mode |= MODE_NOPRIVMSGS;
	    modebuf[0] = '+';
	    modebuf[1] = 'n';
	    modebuf[2] = 't';
	    modebuf[3] = '\0';
	  }

          /*
           * XXX - this is a rather ugly hack.
           *
           * Unfortunately, there's no way to pass
           * the fact that it is a vchan through SJOIN...
           */
#ifdef VCHANS
          /* Prevent users creating a fake vchan */
          if (name[0] == '#' && name[1] == '#')
            {
              if ((pvc = strrchr(name+3, '_'))) 
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

	  sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS,
                        LL_ICLIENT,
                        ":%s SJOIN %lu %s %s %s:@%s",
                        me.name, (unsigned long) chptr->channelts,
                        chptr->chname, modebuf, parabuf, parv[0]);
	  /*
	   * notify all other users on the new channel
	   */
	  /* XXX just exactly who is going to be =on= this new channel
	   * other than just the creator at this time? ? ?
	   */
	  sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN :%s",
			       source_p->name, source_p->username,
			       source_p->host, root_chptr->chname);
      
	  sendto_channel_local(ONLY_CHANOPS_HALFOPS,chptr,
			       ":%s MODE %s %s %s",
			       me.name, root_chptr->chname,
			       modebuf, parabuf);
	}
      else
	{
	  sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS,
                        LL_ICLIENT,
                        ":%s SJOIN %lu %s %s %s:%s",
                        me.name, (unsigned long) chptr->channelts,
                        chptr->chname, modebuf, parabuf, parv[0]);

	  sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN :%s",
			       source_p->name, source_p->username,
			       source_p->host, root_chptr->chname);
        }


      del_invite(chptr, source_p);
      
      if (chptr->topic != NULL)
	{
	  sendto_one(source_p, form_str(RPL_TOPIC), me.name,
		     parv[0], root_chptr->chname, chptr->topic);

          if (!(chptr->mode.mode & MODE_HIDEOPS) ||
              (flags & CHFL_CHANOP) || (flags & CHFL_HALFOP))
            {
              sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
                         me.name, parv[0], root_chptr->chname,
                         chptr->topic_info, chptr->topic_time);
            }
          else /* Hide from nonops */
            {
               sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
                         me.name, parv[0], root_chptr->chname,
                         me.name, chptr->topic_time);
            }
	}

      channel_member_names(source_p, chptr, root_chptr->chname, 1);

      if(successful_join_count != 0)
	source_p->localClient->last_join_time = CurrentTime;
    }
}

/*
 * ms_join
 *
 * inputs	-
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
  char *name;
  int new_ts;

  if ((source_p->user) == NULL)
    return;
  
  name = parv[1];

  /*
   * stupid legacy here. If remote server joins someone to "0"
   * thats a signal to remove this client from all channels.
   * note, the string "0" is simply '0' '\0' this following "if"
   * is faster then a strcmp.
   */
  if ((name[0] == '0') && (name[1] == '\0'))
    {
      do_join_0(client_p, source_p);
    }
  else
    {
      if(parc > 2)
	{
	  new_ts = atoi(parv[2]);
	}
      else
	{
	  ts_warn("User on %s remotely JOINing new channel with no TS", 
		  source_p->user->server);
	}
    }
}

/*
 * do_join_0
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
  struct Channel *chptr=NULL;
  dlink_node   *lp;

  sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, NOFLAGS,
                ":%s JOIN 0", source_p->name);

  if (source_p->user->channel.head &&
      MyConnect(source_p) && !IsOper(source_p))
   check_spambot_warning(source_p, NULL);

  while ((lp = source_p->user->channel.head))
    {
      chptr = lp->data;
      sendto_channel_local(ALL_MEMBERS,chptr, ":%s!%s@%s PART %s",
			   source_p->name, source_p->username,
			   source_p->host, RootChan(chptr)->chname);
      remove_user_from_channel(chptr, source_p);
    }
}
