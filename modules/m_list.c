/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_links.c: Shows what servers are currently connected.
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
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "vchannel.h"
#include "list.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void m_list(struct Client*, struct Client*, int, char**);
static void ms_list(struct Client*, struct Client*, int, char**);
static void mo_list(struct Client*, struct Client*, int, char**);
static int list_all_channels(struct Client *, int, int);
static void list_one_channel(struct Client *,struct Channel *);

struct Message list_msgtab = {
  "LIST", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_list, ms_list, mo_list}
};
#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&list_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&list_msgtab);
}
const char *_version = "$Revision$";
#endif
static int list_all_channels(struct Client *source_p, int, int);
static int list_named_channel(struct Client *source_p,char *name);


/*
** m_list
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void m_list(struct Client *client_p,
                  struct Client *source_p,
                  int parc,
                  char *parv[])
{
  static time_t last_used=0L;

  /* If not a LazyLink connection, see if its still paced */
  /* If we're forwarding this to uplinks.. it should be paced due to the
   * traffic involved in /list.. -- fl_ */
  if( ( (last_used + ConfigFileEntry.pace_wait) > CurrentTime) )
    {
      sendto_one(source_p,form_str(RPL_LOAD2HI),me.name,parv[0]);
      return;
    }
  else
    last_used = CurrentTime;


  /* If its a LazyLinks connection, let uplink handle the list */
  if( uplink && IsCapable(uplink,CAP_LL) )
    {
      if(parc < 2)
	sendto_one( uplink, ":%s LIST", source_p->name );
      else
	sendto_one( uplink, ":%s LIST %s", source_p->name, parv[1] );
      return;
    }

  /* If no arg, do all channels *whee*, else just one channel */
  if (parc < 2 || BadPtr(parv[1])) 
    {
      list_all_channels(source_p, -1, -1);
    }
  else if (parv[1][0] == '<')
    {
      list_all_channels(source_p, -1, atoi(parv[1]+1));
    }
  else if (parv[1][0] == '>')
    {
      list_all_channels(source_p, atoi(parv[1]+1), -1);
    }
  else
    {
      list_named_channel(source_p,parv[1]);
    }
}


/*
** mo_list
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void mo_list(struct Client *client_p,
                   struct Client *source_p,
                   int parc,
                   char *parv[])
{

  /* If its a LazyLinks connection, let uplink handle the list
   * even for opers!
   */

  if( uplink && IsCapable( uplink, CAP_LL) )
    {
      if(parc < 2)
	sendto_one( uplink, ":%s LIST", source_p->name );
      else
	sendto_one( uplink, ":%s LIST %s", source_p->name, parv[1] );
      return;
    }

  /* If no arg, do all channels *whee*, else just one channel */
  if (parc < 2 || BadPtr(parv[1]))
    {     
      list_all_channels(source_p, -1, -1);
    } 
  else if (parv[1][0] == '<')
    {
      list_all_channels(source_p, -1, atoi(parv[1]+1));
    } 
  else if (parv[1][0] == '>')
    {
      list_all_channels(source_p, atoi(parv[1]+1), -1);
    } 
  else
    {
      list_named_channel(source_p,parv[1]);
    } 
}

/*
** ms_list
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void ms_list(struct Client *client_p,
                   struct Client *source_p,
                   int parc,
                   char *parv[])
{
  /* Only allow remote list if LazyLink request */

  if( ServerInfo.hub )
    {
      if(!IsCapable(client_p->from,CAP_LL) && !MyConnect(source_p))
	return;

  if (parc < 2 || BadPtr(parv[1]))
    {     
      list_all_channels(source_p, -1, -1);
    } 
  else if (parv[1][0] == '<')
    {
      list_all_channels(source_p, -1, atoi(parv[1]+1));
    } 
  else if (parv[1][0] == '>')
    {
      list_all_channels(source_p, atoi(parv[1]+1), -1);
    } 
  else
    {
      list_named_channel(source_p,parv[1]);
    } 

    }
}

/*
 * list_all_channels
 * inputs	- pointer to client requesting list
 * output	- 0/1
 * side effects	- list all channels to source_p
 */
static int list_all_channels(struct Client *source_p, int min, int max)
{
  struct Channel *chptr;

  sendto_one(source_p, form_str(RPL_LISTSTART), me.name, source_p->name);

  for ( chptr = GlobalChannelList; chptr; chptr = chptr->nextch )
    {
      if ( !IsOper(source_p) && ( !source_p->user ||
	   (SecretChannel(chptr) && !IsMember(source_p, chptr))) && !IsGod(source_p))
	continue;
      if(min == -1 && chptr->users <= max)
        list_one_channel(source_p,chptr);
      else if(max == -1 && chptr->users >= min)
        list_one_channel(source_p,chptr);
      else if(max == -1 && min == -1)
        list_one_channel(source_p,chptr);
    }

  sendto_one(source_p, form_str(RPL_LISTEND), me.name, source_p->name);
  return 0;
}   
          
/*
 * list_named_channel
 * inputs       - pointer to client requesting list
 * output       - 0/1
 * side effects	- list all channels to source_p
 */
static int list_named_channel(struct Client *source_p,char *name)
{
  struct Channel *chptr;
  char id_and_topic[TOPICLEN+NICKLEN+6]; /* <!!>, space and null */
  char *p;
#ifdef VCHANS
  dlink_node *ptr;
  struct Channel *root_chptr;
  struct Channel *tmpchptr;
#endif

  sendto_one(source_p, form_str(RPL_LISTSTART), me.name, source_p->name);

  while (*name == ',')
    name++;
  if ((p = strchr(name,',')) != NULL)
    *p = '\0';
  if (!*name)
    return;

  chptr = hash_find_channel(name);
  if (chptr == NULL)
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),me.name, source_p->name, name);
      sendto_one(source_p, form_str(RPL_LISTEND), me.name, source_p->name);
      return 0;
    }

#ifdef VCHANS
  if (HasVchans(chptr))
    ircsprintf(id_and_topic, "<!%s> %s", pick_vchan_id(chptr), chptr->topic == NULL ? "" : chptr->topic );
  else
#endif
    ircsprintf(id_and_topic, "%s", chptr->topic == NULL ? "" : chptr->topic);

  if (ShowChannel(source_p, chptr))
    sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
               chptr->chname, chptr->users, id_and_topic);
      
  /* Deal with subvchans */
 
#ifdef VCHANS
  for (ptr = chptr->vchan_list.head; ptr; ptr = ptr->next)
    {
      tmpchptr = ptr->data;

      if (ShowChannel(source_p, tmpchptr))
	{
          root_chptr = find_bchan(tmpchptr);
          ircsprintf(id_and_topic, "<!%s> %s", pick_vchan_id(tmpchptr), tmpchptr->topic == NULL ? "" : chptr->topic);
          sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
                     root_chptr->chname, tmpchptr->users, id_and_topic);
        }
    }
#endif
  
  sendto_one(source_p, form_str(RPL_LISTEND), me.name, source_p->name);
  return 0;
}

/*
 * list_one_channel
 *
 * inputs       - client pointer to return result to
 *              - pointer to channel to list
 * ouput	- none
 * side effects -
 */
static void list_one_channel(struct Client *source_p, struct Channel *chptr)
{
  static char channel_name_buffer[BUFSIZE];

#ifdef VCHANS
  struct Channel *root_chptr;
  char  id_and_topic[TOPICLEN+NICKLEN+6]; /* <!!>, plus space and null */

  if(IsVchan(chptr) || HasVchans(chptr))
    {
      root_chptr = find_bchan(chptr);
      
      if (!ShowChannel(source_p, chptr) && IsGod(source_p))
	{
	  channel_name_buffer[0] = '%'; channel_name_buffer[1] = '\0';
	}
      else
	  channel_name_buffer[0] = '\0';
	
      if(root_chptr != NULL)
        {
	  strlcat(channel_name_buffer, root_chptr->chname, BUFSIZE - 2);
          ircsprintf(id_and_topic, "<!%s> %s", pick_vchan_id(chptr), chptr->topic == NULL ? "" : chptr->topic );
          sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
                     channel_name_buffer, chptr->users, id_and_topic);
        }
      else
        {
	  strlcat(channel_name_buffer, chptr->chname, BUFSIZE - 2);
          ircsprintf(id_and_topic, "<!%s> %s", pick_vchan_id(chptr), chptr->topic == NULL ? "" : chptr->topic );
          sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
                     channel_name_buffer, chptr->users, id_and_topic);     
        }
    }
  else
#endif
    {
      if (!ShowChannel(source_p, chptr) && IsGod(source_p)) {
	channel_name_buffer[0] = '%';
	channel_name_buffer[1] = '\0';
        strlcat(channel_name_buffer, chptr->chname, BUFSIZE - 2);
	sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
		    channel_name_buffer, chptr->users, chptr->topic == NULL ? "" : chptr->topic );
      } else {
      sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
                 chptr->chname, chptr->users, chptr->topic == NULL ? "" : chptr->topic );
      };
    }
}
