/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  resv.c: Functions to reserve(jupe) a nick/channel.
 *
 *  Copyright (C) 2001-2002 Hybrid Development Team
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
#include "restart.h"
#include "common.h"
#include "fdlist.h"
#include "ircd.h"
#include "send.h"
#include "s_debug.h"
#include "numeric.h"
#include "s_log.h"
#include "client.h"   
#include "memory.h"
#include "resv.h"
#include "hash.h"
#include "ircd_defs.h"

struct ResvChannel *ResvChannelList;
struct ResvNick *ResvNickList;

struct ResvChannel *
create_channel_resv(char *name, char *reason, int conf)
{
  struct ResvChannel *resv_p = NULL;
  int len;

  if(find_channel_resv(name))
    return NULL;

  if((len = strlen(reason)) > TOPICLEN)
  {
    reason[TOPICLEN] = '\0';
    len = TOPICLEN;
  }

  resv_p = (struct ResvChannel *)MyMalloc(sizeof(struct ResvChannel));

  strlcpy(resv_p->name, name, CHANNELLEN+1);
  DupString(resv_p->reason, reason);
  resv_p->conf = conf;

  if(ResvChannelList != NULL)
    ResvChannelList->prev = resv_p;

  resv_p->next = ResvChannelList;
  resv_p->prev = NULL;

  ResvChannelList = resv_p;

  add_to_resv_hash_table(resv_p->name, resv_p);

  return resv_p;
}

struct ResvNick *
create_nick_resv(char *name, char *reason, int conf)
{
  struct ResvNick *resv_p = NULL;
  int len;

  if(find_nick_resv(name))
    return NULL;

  if((len = strlen(reason)) > TOPICLEN)
  {
    reason[TOPICLEN] = '\0';
    len = TOPICLEN;
  }

  resv_p = (struct ResvNick *)MyMalloc(sizeof(struct ResvNick));

  strlcpy(resv_p->name, name, RESVNICKLEN);
  DupString(resv_p->reason, reason);
  resv_p->conf = conf;

  if(ResvNickList)
    ResvNickList->prev = resv_p;

  resv_p->next = ResvNickList;
  resv_p->prev = NULL;

  ResvNickList = resv_p;

  return resv_p;
}

int 
clear_conf_resv()
{
  struct ResvChannel *resv_cp;
  struct ResvChannel *next_cp;
  struct ResvNick *resv_np;
  struct ResvNick *next_np;

  for(resv_cp = ResvChannelList; resv_cp; resv_cp = next_cp)
  {
    next_cp = resv_cp->next;

    if(resv_cp->conf)
      delete_channel_resv(resv_cp);
  }

  for(resv_np = ResvNickList; resv_np; resv_np = next_np)
  {
    next_np = resv_np->next;

    if(resv_np->conf)
      delete_nick_resv(resv_np);
  }
  
  return 0;
}

int 
delete_channel_resv(struct ResvChannel *resv_p)
{
  if(!(resv_p))
    return 0;

  del_from_resv_hash_table(resv_p->name, resv_p);

  if(resv_p->prev)
    resv_p->prev->next = resv_p->next;
  else
    ResvChannelList = resv_p->next;

  if(resv_p->next)
    resv_p->next->prev = resv_p->prev;

  MyFree((char *)resv_p);

  return 1;
}

int 
delete_nick_resv(struct ResvNick *resv_p)
{
  if(!(resv_p))
    return 0;

  if(resv_p->prev)
    resv_p->prev->next = resv_p->next;
  else
    ResvNickList = resv_p->next;

  if(resv_p->next)
    resv_p->next->prev = resv_p->prev;

  MyFree((char *)resv_p);

  return 1;
}

int
find_channel_resv(char *name)
{
  struct ResvChannel *resv_p;

  resv_p = (struct ResvChannel *)hash_find_resv(name);

  if (resv_p == NULL)
    return 0;

  return 1;
}

int 
find_nick_resv(char *name)
{
  struct ResvNick *resv_p;

  for(resv_p = ResvNickList; resv_p; resv_p = resv_p->next)
  {
    if(match(resv_p->name, name))
      return 1;
  }
  
  return 0;
}

struct ResvNick *
return_nick_resv(char *name)
{
  struct ResvNick *resv_p;

  for(resv_p = ResvNickList; resv_p; resv_p = resv_p->next)
  {
    if(!(irccmp(resv_p->name, name)))
      return resv_p;
  }

  return NULL;
}

void 
report_resv(struct Client *source_p)
{
  struct ResvChannel *resv_cp;
  struct ResvNick *resv_np;

  for(resv_cp = ResvChannelList; resv_cp; resv_cp = resv_cp->next)
    sendto_one(source_p, form_str(RPL_STATSQLINE),
               me.name, source_p->name,
	       resv_cp->conf ? 'Q' : 'q',
	       resv_cp->name, resv_cp->reason);

  for(resv_np = ResvNickList; resv_np; resv_np = resv_np->next)
    sendto_one(source_p, form_str(RPL_STATSQLINE),
               me.name, source_p->name,
	       resv_np->conf ? 'Q' : 'q',
	       resv_np->name, resv_np->reason);
}	       

int
clean_resv_nick(char *nick)
{
  char tmpch;
  int as=0;
  int q=0;
  int ch=0;

  if(*nick == '-' || IsDigit(*nick))
    return 0;
    
  while((tmpch = *nick++))
  {
    if(tmpch == '?')
      q++;
    else if(tmpch == '*')
      as++;
    else if(IsNickChar(tmpch))
      ch++;
    else
      return 0;
  }

  if(!ch && as)
    return 0;

  return 1;
}
    
