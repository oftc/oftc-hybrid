/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_names.c: Shows the users who are online.
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


static void names_all_visible_channels(struct Client *source_p);
static void names_non_public_non_secret(struct Client *source_p);

static void m_names(struct Client*, struct Client*, int, char**);
static void ms_names(struct Client*, struct Client*, int, char**);

struct Message names_msgtab = {
  "NAMES", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_names, ms_names, m_names}
};
#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&names_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&names_msgtab);
}

const char *_version = "$Revision$";
#endif

/************************************************************************
 * m_names() - Added by Jto 27 Apr 1989
 ************************************************************************/

/*
** m_names
**      parv[0] = sender prefix
**      parv[1] = channel
**      parv[2] = vkey
*/
static void m_names(struct Client *client_p,
                    struct Client *source_p,
                    int parc,
                    char *parv[])
{ 
  struct Channel *ch2ptr = NULL;
  char *s;
  char *para = parc > 1 ? parv[1] : NULL;
#ifdef VCHANS
  struct Channel *vchan = NULL;
  char *vkey = NULL;
#endif

  if (!BadPtr(para))
    {
      while (*para == ',')
        para++;
      if ((s = strchr(para, ',')) != NULL)
        *s = '\0';
      if (!*para)
        return;

#ifdef VCHANS
      if (parc > 2)
        vkey = parv[2];
#endif

      if (!check_channel_name(para))
        { 
          sendto_one(source_p, form_str(ERR_BADCHANNAME),
                     me.name, parv[0], (unsigned char *)para);
          return;
        }

      if ((ch2ptr = hash_find_channel(para)) != NULL)
        {
#ifdef VCHANS
          if (HasVchans(ch2ptr))
            {
              vchan = map_vchan(ch2ptr, source_p);

              if ((vkey && !vkey[1]) || (!vchan && !vkey))
                {
                  show_vchans(source_p, ch2ptr, "names");
                  return;
                }
              else if (vkey && vkey[1])
                {
                  vchan = find_vchan(ch2ptr, vkey);
                  if(!vchan)
                    return;
                }
              channel_member_names(source_p, vchan, ch2ptr->chname, 1);
            }
          else
#endif
            {
              channel_member_names(source_p, ch2ptr, ch2ptr->chname, 1);
            }
        }
      else
        sendto_one(source_p, form_str(RPL_ENDOFNAMES), me.name,
                   parv[0], para);
    }
  else
    {
      names_all_visible_channels(source_p);
      names_non_public_non_secret(source_p);
      sendto_one(source_p, form_str(RPL_ENDOFNAMES), me.name, parv[0],
                 "*");
    }
}

/*
 * names_all_visible_channels
 *
 * inputs       - pointer to client struct requesting names
 * output       - none
 * side effects - lists all visible channels whee!
 */

static void names_all_visible_channels(struct Client *source_p)
{
  struct Channel *chptr;
  char *chname=NULL;
#ifdef VCHANS
  struct Channel *bchan;
#endif

  /* 
   * First, do all visible channels (public and the one user self is)
   */

  for (chptr = GlobalChannelList; chptr; chptr = chptr->nextch)
    {
#ifdef VCHANS
      if (IsVchan(chptr))
        {
          bchan = find_bchan (chptr);
          if (bchan != NULL)
            chname = bchan->chname;
        }
      else
#endif
        chname = chptr->chname;

      /* Find users on same channel (defined by chptr) */

      channel_member_names( source_p, chptr, chname, 0);
    }
}

/*
 * names_non_public_non_secret
 *
 * inputs       - pointer to client struct requesting names
 * output       - none
 * side effects - lists all non public non secret channels
 */

static void names_non_public_non_secret(struct Client *source_p)
{
  int mlen;
  int tlen;
  int cur_len;
  int reply_to_send = NO;
  int dont_show = NO;
  dlink_node    *lp;
  struct Client *c2ptr;
  struct Channel *ch3ptr=NULL;
  char buf[BUFSIZE];
  char *t;

  ircsprintf(buf,form_str(RPL_NAMREPLY),
             me.name,source_p->name," * * :");

  mlen = strlen(buf);
  cur_len = mlen;
  t = buf + mlen;

  /* Second, do all non-public, non-secret channels in one big sweep */

  for (c2ptr = GlobalClientList; c2ptr; c2ptr = c2ptr->next)
    {
      if (!IsPerson(c2ptr) || IsInvisible(c2ptr))
        continue;
      /*
       * dont show a client if they are on a secret channel or
       * they are on a channel source_p is on since they have already
       * been shown earlier. -avalon
       */
      for( lp = c2ptr->user->channel.head; lp; lp = lp->next )
        {
          ch3ptr = lp->data;

          if ( (!PubChannel(ch3ptr) || IsMember(source_p, ch3ptr)) ||
               (SecretChannel(ch3ptr)))
          {
            dont_show = YES;
            break;
          }
        }
      if (dont_show) /* on any secret channels or shown already? */
        continue;

      if(lp == NULL)    /* Nothing to do. yay */
        continue;

      if ( (cur_len + NICKLEN + 2)  > (BUFSIZE - 3))
        {
          sendto_one(source_p, "%s", buf);
          cur_len = mlen;
          t = buf + mlen;
        }

      if(ch3ptr->mode.mode & MODE_HIDEOPS)
        ircsprintf(t," %s ", c2ptr->name);
      else
        ircsprintf(t,"%s%s ", channel_chanop_or_voice(ch3ptr, c2ptr),
                   c2ptr->name);

      tlen = strlen(t);
      cur_len += tlen;
      t += tlen;

      reply_to_send = YES;

    }

  if (reply_to_send)
    sendto_one(source_p, "%s", buf );
}

static void ms_names( struct Client *client_p,
                     struct Client *source_p,
                     int parc,
                     char *parv[])
{ 
  /* If its running as a hub, and linked with lazy links
   * then allow leaf to use normal client m_names()
   * other wise, ignore it.
   */

  if( ServerInfo.hub )
    {
      if(!IsCapable(client_p->from,CAP_LL))
        return;
    }

  if(IsClient(source_p))
    m_names(client_p,source_p,parc,parv);
}

