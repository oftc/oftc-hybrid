/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_topic.c: Sets a channel topic.
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
#include "common.h" /* IRCD_BUFSIZE */
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "s_serv.h"
#include "s_log.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"

static void m_topic(struct Client *, struct Client *, int, char **);
static void ms_topic(struct Client *, struct Client *, int, char **);

struct Message topic_msgtab = {
  "TOPIC", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_topic, ms_topic, m_topic, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&topic_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&topic_msgtab);
}

const char *_version = "$Revision$";
#endif

/* m_topic()
 *  parv[0] = sender prefix
 *  parv[1] = channel name
 *  parv[2] = new topic, if setting topic
 */
static void
m_topic(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  char *p;
  struct Membership *ms;

  if ((p = strchr(parv[1], ',')) != NULL)
    *p = '\0';

  if (parv[1][0] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "TOPIC");
    return;
  }

  if (MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  if (IsChannelName(parv[1]))
  {
    if ((chptr = hash_find_channel(parv[1])) == NULL)
    {
      /* if chptr isn't found locally, it =could= exist
       * on the uplink. so forward reqeuest
       */
      if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
      {
        sendto_one(uplink, ":%s TOPIC %s %s",
                   source_p->name, parv[1],
                   ((parc > 2) ? parv[2] : ""));
        return;
      }
      else
      {
        sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                   me.name, source_p->name, parv[1]);
        return;
      }
    }

    /* setting topic */
    if (parc > 2)
    {
      if ((ms = find_channel_link(source_p, chptr)) == NULL)
      {
        sendto_one(source_p, form_str(ERR_NOTONCHANNEL), me.name,
                   source_p->name, parv[1]);
        return;
      }
      if ((chptr->mode.mode & MODE_TOPICLIMIT) == 0 ||
          has_member_flags(ms, CHFL_CHANOP|CHFL_HALFOP))
      {
        char topic_info[USERHOST_REPLYLEN]; 
        if(!has_member_flags(ms, CHFL_CHANOP|CHFL_HALFOP) && 
                IsGod(source_p) && MyClient(source_p))
        {              
          char tmp[IRCD_BUFSIZE];           
          ircsprintf(tmp, "%s is using God mode: TOPIC %s %s", source_p->name, 
                  chptr->chname, parv[2]);              
          sendto_gnotice_flags(UMODE_SERVNOTICE, L_OPER, me.name, &me, NULL, 
                  tmp);
          oftc_log(tmp);
        }
        ircsprintf(topic_info, "%s!%s@%s",
                   source_p->name, source_p->username, source_p->host);
        set_channel_topic(chptr, parv[2], topic_info, CurrentTime);
	      
        sendto_server(client_p, NULL, chptr, NOCAPS, NOCAPS, NOFLAGS,
                      ":%s TOPIC %s :%s",
                      parv[0], chptr->chname,
                      chptr->topic == NULL ? "" : chptr->topic);
        sendto_channel_local(ALL_MEMBERS,
                             chptr, ":%s!%s@%s TOPIC %s :%s",
                             source_p->name,
                             source_p->username,
                             source_p->host,
                             chptr->chname, chptr->topic == NULL ?
                             "" : chptr->topic);
      }
      else
        sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED),
                   me.name, source_p->name, parv[1]);
    }
    else /* only asking for topic */
    {
      if (!SecretChannel(chptr) || IsMember(source_p, chptr))
      {
        if (chptr->topic == NULL)
          sendto_one(source_p, form_str(RPL_NOTOPIC),
                     me.name, source_p->name, parv[1]);
        else
        {
          sendto_one(source_p, form_str(RPL_TOPIC),
                     me.name, source_p->name,
                     chptr->chname, chptr->topic);

          /* client on LL needing the topic - if we have serverhide, say
           * its the actual LL server that set the topic, not us the
           * uplink -- fl_
           */
          if (ConfigServerHide.hide_servers && !MyClient(source_p)
              && IsCapable(client_p, CAP_LL) && ServerInfo.hub)
          {
            sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
  	               me.name, source_p->name, chptr->chname,
                       client_p->name, chptr->topic_time);
          }
          else
          {
            sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
                       me.name, source_p->name, chptr->chname,
                       chptr->topic_info,
                       chptr->topic_time);
          }
        }
      }
      else
      {
        sendto_one(source_p, form_str(ERR_NOTONCHANNEL),
                   me.name, source_p->name, parv[1]);
        return;
      }
    }
  }
  else
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, parv[1]);
  }
}

/*
 * ms_topic
 *      parv[0] = sender prefix
 *      parv[1] = channel name
 *	parv[2] = topic_info
 *	parv[3] = topic_info time
 *	parv[4] = new channel topic
 *
 * Let servers always set a topic
 */
static void
ms_topic(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Channel *chptr = NULL;

  if (!IsServer(source_p))
  {
    m_topic(client_p, source_p, parc, parv);
    return;
  }

  if (parc < 5)
    return;

  if (parv[1] && IsChannelName(parv[1]))
  {
    if ((chptr = hash_find_channel(parv[1])) == NULL)
      return;
    
    if(chptr->mode.mode & MODE_NOCOLOR && msg_has_colors(parv[4])) 
        parv[4] = strip_color(parv[4]);
    set_channel_topic(chptr, parv[4], parv[2], atoi(parv[3]));

    if (ConfigServerHide.hide_servers)
    {
      sendto_channel_local(ALL_MEMBERS,
                           chptr, ":%s TOPIC %s :%s",
                           me.name,
                           parv[1],
                           chptr->topic == NULL ? "" : chptr->topic);

    }
    else
    {
      sendto_channel_local(ALL_MEMBERS,
                           chptr, ":%s TOPIC %s :%s",
                           source_p->name,
                           parv[1], chptr->topic == NULL ? "" : chptr->topic);
    }
  }
}
