/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_cjoin.c: Creates a vchan.
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


#ifdef VCHANS
static void m_cjoin(struct Client*, struct Client*, int, char**);

struct Message cjoin_msgtab = {
  "CJOIN", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_cjoin, m_ignore, m_cjoin}
};
#endif

#ifndef STATIC_MODULES
void
_modinit(void)
{
#ifdef VCHANS
  mod_add_cmd(&cjoin_msgtab);
#endif
}

void
_moddeinit(void)
{
#ifdef VCHANS
  mod_del_cmd(&cjoin_msgtab);
#endif
}

const char *_version = "$Revision$";
#endif /* STATIC_MODULES */

#ifdef VCHANS
/*
** m_cjoin
**      parv[0] = sender prefix
**      parv[1] = channel
**      parv[2] = channel password (key)
*/
static void m_cjoin(struct Client *client_p,
                   struct Client *source_p,
                   int parc,
                   char *parv[])
{
  static char   jbuf[BUFSIZE];
  struct Channel *chptr = NULL;
  struct Channel *vchan_chptr = NULL;
  struct Channel *root_vchan = NULL;
  char  *name;
  char  *p = NULL;

  if (!(source_p->user))
    {
      /* something is *fucked* - bail */
      return;
    }

  if(ConfigChannel.use_vchans == 0)
  {
    sendto_one(source_p, form_str(ERR_VCHANDISABLED),
               me.name, parv[0]);
    return;
  }
  
  if (ConfigChannel.vchans_oper_only && !IsOper(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, parv[0]);
    return;
  }

  if (*parv[1] == '\0')
    {
      sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
                 me.name, parv[0], "CJOIN");
      return;
    }


  /* Ok, only allowed to CJOIN already existing channels
   * so first part simply verifies the "root" channel exists first
   */

  *jbuf = '\0';

  name = parv[1];
  while (*name == ',')
    name++;
  if ((p = strchr(name,',')) != NULL)
    *p = '\0';
  if (!*name)
    return;

  if (!check_channel_name(name))
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
		 me.name, parv[0], (unsigned char*) name);
      return;
    }

  if (*name == '&')
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
		 me.name, parv[0], (unsigned char*) name);
      return;
    }

  if (!IsChannelName(name))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
		 me.name, parv[0], name);
      return;
    }

  strlcpy(jbuf, name, sizeof(jbuf));

  if ((chptr = hash_find_channel(name)) == NULL)
    {
      /* if chptr isn't found locally, it =could= exist
       * on the uplink. So ask.
       */
      if ( !ServerInfo.hub && uplink &&
           IsCapable(uplink, CAP_LL))
        {
          /* cache the channel if it exists on uplink
           * If the channel as seen by the uplink, has vchans,
           * the uplink will have to SJOIN all of those.
           */
          sendto_one(uplink, ":%s CBURST %s !%s",
                     me.name, parv[1], source_p->name);

          return;
        }
      else
        {
          sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                     me.name, source_p->name, name);
        }
      return;
    }

  if (! (vchan_chptr = cjoin_channel(chptr, source_p, name)) )
    return;

  root_vchan = chptr;
  chptr = vchan_chptr;
  
  /*
  **  Complete user entry to the new channel
  */
  add_user_to_channel(chptr, source_p, CHFL_CHANOP);

  sendto_channel_local(ALL_MEMBERS, chptr,
			":%s!%s@%s JOIN :%s",
			source_p->name,
			source_p->username,
			source_p->host,
			root_vchan->chname);

  sendto_server(client_p, NULL, chptr, NOCAPS, NOCAPS, NOFLAGS,
                ":%s SJOIN %lu %s + :@%s",
                me.name,
                (unsigned long) chptr->channelts,
                chptr->chname,
                source_p->name);

  vchan_chptr->mode.mode |= MODE_TOPICLIMIT;
  vchan_chptr->mode.mode |= MODE_NOPRIVMSGS;

  sendto_channel_local(ALL_MEMBERS,chptr,
			":%s MODE %s +nt",
			me.name,
			root_vchan->chname);

  sendto_server(source_p, NULL, vchan_chptr, NOCAPS, NOCAPS, NOFLAGS,
                ":%s MODE %s +nt",
                me.name,
                vchan_chptr->chname);

  del_invite(vchan_chptr, source_p);
  channel_member_names(source_p, vchan_chptr, root_vchan->chname, 1);
}

#endif /* VCHANS */
