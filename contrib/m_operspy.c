/************************************************************************
 *   IRC - Internet Relay Chat, contrib/m_operspy.c
 *   Copyright (C) 2002 Bill Jonus and the Hybrid Development Team
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

/***  PLEASE READ ME  ***/
/*
 *  This module gives an extraordinary amount of power to the opers
 *  who have the access to use it.  It allows for users' privacy to
 *  be pretty much obliterated.  The Hybrid Team assumes absolutely
 *  no responsibility for this file's (mis)use.
 *
 *    - billy-jon
 */

#include "stdinc.h"
#include "tools.h"
#include "irc_string.h"
#include "handlers.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"     /* FALSE bleah */
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

/* enable OPERSPY version of LIST */
#define OPERSPY_LIST

/* enable OPERSPY version of MODE */
#define OPERSPY_MODE

/* enable OPERSPY version of NAMES */
#define OPERSPY_NAMES

/* enable OPERSPY version of WHO */
#define OPERSPY_WHO

/* enable OPERSPY version of WHOIS */
#define OPERSPY_WHOIS

/* enable OPERSPY version of TOPIC */
#define OPERSPY_TOPIC

#define IsOperspy(x) (IsOper(x) && MyClient(x) && IsAdmin(x))

/*
 * The commands we will add
 */
static void m_operspy(struct Client *client_p, struct Client *source_p,
                       int parc, char *parv[]);
static void mo_operspy(struct Client *client_p, struct Client *source_p,
                       int parc, char *parv[]);

/* extensions for OPERSPY WHO */
#ifdef OPERSPY_WHO
static void do_who(struct Client *source_p,
                   struct Client *target_p,
                   char *chname,
                   char *op_flags);

static void do_who_list(struct Client *source_p, struct Channel *chptr,
                        dlink_list *peons_list, dlink_list *chanops_list,
#ifdef REQUIRE_OANDV
                        dlink_list *chanops_voiced_list,
#endif
#ifdef HALFOPS
                        dlink_list *halfops_list,
#endif
                        dlink_list *voiced_list,
                        char *chanop_flag,
                        char *halfop_flag,
                        char *voiced_flag,
                        char *chname);


static void who_global(struct Client *source_p, char *mask, int server_oper);

static void do_who_on_channel(struct Client *source_p,
                              struct Channel *chptr, char *real_name,
                              int server_oper);

#endif

struct Message operspy_msgtab = {
  "OPERSPY", 0, 0, 0, 0, MFLG_SLOW|MFLG_HIDDEN, 0,
  {m_ignore, m_operspy, m_operspy, mo_operspy}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&operspy_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&operspy_msgtab);
}
const char *_version = "$Revision$";
#endif

/*
 * m_operspy
 *      parv[1] = operspy command
 *      parv[2] = command parameter
 */
static void m_operspy(struct Client *client_p, struct Client *source_p,
                      int parc, char *parv[])
{
  char *operspy = (parc > 1) ? parv[1]-1 : NULL;

  if (operspy != NULL)
    while (*operspy != 'o' && *operspy != 'O') --operspy;
  else
    operspy = "OPERSPY";

  sendto_one(client_p, ":%s %d %s %s :Unknown command",
             me.name, ERR_UNKNOWNCOMMAND, client_p->name,
             operspy);
}

/*
 * mo_operspy
 *	parv[1] = operspy command
 *	parv[2] = command parameter
 */
static void mo_operspy(struct Client *client_p, struct Client *source_p,
                       int parc, char *parv[])
{
  char *operspy = (parc > 1) ? parv[1]-1 : NULL;

#ifdef OPERSPY_LIST
  struct Channel	*chptr_list = NULL;
#endif

#ifdef OPERSPY_MODE
  /* needed to preserve actual client status */
  int			c_status = 0;

  static char		modebuf[MODEBUFLEN];
  static char		parabuf[MODEBUFLEN];
  struct Channel	*chptr_mode = NULL;
#endif

#ifdef OPERSPY_NAMES
  /* as with mode, must preserve channel modes */
  int                   c_modes = 0;
  struct Channel        *chptr_names = NULL;
#endif

#ifdef OPERSPY_TOPIC
  struct Channel	*chptr_topic = NULL;
#endif

#ifdef OPERSPY_WHO
  char			*mask = parc > 2 ? parv[2] : NULL;
  char			flags[NUMLISTS][2];
  int			server_oper = parc > 3 ? (*parv[3] == 'o') : 0;
  struct Channel	*chptr_who = NULL;
  struct Client		*target_p_who = NULL;
#endif

#ifdef OPERSPY_WHOIS
  dlink_node		*lp;
  struct Channel	*chptr_whois = NULL;
  struct Client		*a2client_p;
  struct Client		*target_p = NULL;
  char			buf[BUFSIZE];
  char			*t;
  int			mlen, tlen;
  int			cur_len = 0;
  int			reply_to_send = NO;
#endif

  if (operspy != NULL)
    while (*operspy != 'o' && *operspy != 'O') --operspy;
  else
    operspy = "OPERSPY";

  if (parc != 3)
  {
    sendto_one(client_p, ":%s %d %s %s :Unknown command",
               me.name, ERR_UNKNOWNCOMMAND, client_p->name,
               operspy);
    return;
  }

  if (!IsOperspy(client_p))
  {
    sendto_one(client_p, ":%s %d %s %s :Unknown command",
               me.name, ERR_UNKNOWNCOMMAND, client_p->name,
               operspy);
    return;
  }

#ifdef OPERSPY_LIST
  if (strcasecmp(parv[1], "LIST") == 0)
  {
    sendto_one(client_p, form_str(RPL_LISTSTART), me.name, client_p->name);

    for (chptr_list = GlobalChannelList; chptr_list; chptr_list = chptr_list->nextch)
    {
      if (match(parv[2], chptr_list->chname))
      {
        sendto_one(client_p, form_str(RPL_LIST), me.name, client_p->name,
                   chptr_list->chname, chptr_list->users, chptr_list->topic == NULL ? "" : chptr_list->topic);
      }
    }

    sendto_one(client_p, form_str(RPL_LISTEND), me.name, client_p->name);
    return;
  }
#endif

#ifdef OPERSPY_MODE
  if (strcasecmp(parv[1], "MODE") == 0)
  {
    if (!IsChanPrefix(parv[2][0]) || !check_channel_name(parv[2]))
    {
      sendto_one(client_p, form_str(ERR_BADCHANNAME),
                 me.name, parv[0], (unsigned char *)parv[2]);
      return;
    }

    if ((chptr_mode = (struct Channel *)hash_find_channel(parv[2])) == NULL)
    {
      /*
       * according to m_mode.c, the channel *could* exist on the uplink still,
       * but I don't see how.  Even if it does, we won't be able to spy without
       * info.
       */ 
      sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, parv[0], parv[2]);
      return;
    }

    /* this is a dirty nasty kludge to trick channel_modes() into giving us the key */
    c_status = client_p->status;
    client_p->status = STAT_SERVER;

    channel_modes(chptr_mode, client_p, modebuf, parabuf);
    client_p->status = c_status;

    sendto_one(client_p, form_str(RPL_CHANNELMODEIS),
               me.name, parv[0], parv[2], modebuf, parabuf);
    sendto_one(client_p, form_str(RPL_CREATIONTIME),
               me.name, parv[0], parv[2], chptr_mode->channelts);
    return;
  }
#endif

#ifdef OPERSPY_NAMES
  if (strcasecmp(parv[1], "NAMES") == 0)
  {
    if (!IsChanPrefix(parv[2][0]) || !check_channel_name(parv[2]))
    {
      sendto_one(client_p, form_str(ERR_BADCHANNAME),
                 me.name, parv[0], (unsigned char *)parv[2]);
      return;
    }

    if ((chptr_names = (struct Channel *)hash_find_channel(parv[2])) == NULL)
    {
      sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, parv[0], parv[2]);
      return;
    }

    /* 
     * the way to go with this, rather than temporarily setting -sp,
     * is to temporarily add our client to the member list.  then
     * we can also list +i users.  an unfortunate side-effect of this
     * is that your nickname shows up in the list.  for now, there is
     * no easy way around it.
     */ 

    add_user_to_channel(chptr_names, client_p, MODE_CHANOP);
    channel_member_names(client_p, chptr_names, parv[2], 1);
    remove_user_from_channel(chptr_names, client_p);
    return;
  }
#endif

#ifdef OPERSPY_TOPIC
  if (strcasecmp(parv[1], "TOPIC") == 0)
  {
    if ((chptr_topic = (struct Channel *)hash_find_channel(parv[2])) == NULL)
    {
      sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL), me.name,
                 parv[0], parv[2]);
      return;
    }

    if (chptr_topic->topic == NULL)
      sendto_one(client_p, form_str(RPL_NOTOPIC), me.name, parv[0],
                 parv[2]);
    else
    {
      sendto_one(client_p, form_str(RPL_TOPIC), me.name, parv[0],
                 chptr_topic->chname, chptr_topic->topic);
      sendto_one(client_p, form_str(RPL_TOPICWHOTIME), me.name,
                 parv[0], chptr_topic->chname, chptr_topic->topic_info,
                 chptr_topic->topic_time);
    }
    return;
  }
#endif

#ifdef OPERSPY_WHO
  if (strcasecmp(parv[1], "WHO") == 0)
  {
    if (mask != NULL)
    {
      collapse(mask);
      if (*mask == '\0')
      {
        sendto_one(client_p, form_str(RPL_ENDOFWHO), me.name, parv[0], "*");
        return;
      }
    }
    else
    {
      who_global(client_p, NULL, server_oper);
      sendto_one(client_p, form_str(RPL_ENDOFWHO), me.name, parv[0], "*");
      return;
    }

    /* /who #channel */

    if (IsChannelName(mask))
    {
      if ((chptr_who = (struct Channel *)hash_find_channel(mask)) != NULL)
        do_who_on_channel(client_p, chptr_who, chptr_who->chname, server_oper);

      sendto_one(client_p, form_str(RPL_ENDOFWHO), me.name, parv[0], mask);
      return;
    }

    /* /who nick */

    if (((target_p_who = (struct Client *)find_client(mask)) != NULL) && 
        IsPerson(target_p_who))
    {
      char *chname = NULL;

      chptr_who = NULL;

      if (target_p_who->user->channel.head != NULL)
      {
        chptr_who = target_p_who->user->channel.head->data;
        chname = chptr_who->chname;
      }

      if (chptr_who != NULL)
      {
        set_channel_mode_flags(flags, chptr_who, client_p);
        do_who(client_p, target_p_who, chname, flags[0]);
      }
      else
        do_who(client_p, target_p_who, NULL, "");

      sendto_one(client_p, form_str(RPL_ENDOFWHO), me.name, parv[0], mask);
      return;
    }

    /* /who 0 */

    if ((*(mask+1) == '\0') && (*mask == '0'))
      who_global(client_p, NULL, server_oper);
    else
      who_global(client_p, mask, server_oper);

    /* nothing else? end of /who. */
    sendto_one(client_p, form_str(RPL_ENDOFWHO), me.name, parv[0], mask);

    return;
  }
#endif

#ifdef OPERSPY_WHOIS
  if (strcasecmp(parv[1], "WHOIS") == 0)
  {
    if (strchr(parv[2], '?') || strchr(parv[2], '*'))
    {
      sendto_one(client_p, ":%s NOTICE %s :Do not use wildcards with this.", me.name, parv[0]);
      return;
    }

    if ((target_p = (struct Client *)find_client(parv[2])) == NULL || !IsClient(target_p))
    {
      sendto_one(client_p, form_str(ERR_NOSUCHNICK), me.name, parv[0], parv[2]);
      return;
    }

    a2client_p = (struct Client *)find_server(target_p->user->server);

    sendto_one(client_p, form_str(RPL_WHOISUSER), me.name,
               client_p->name, target_p->name, target_p->username,
               target_p->host, target_p->info);
    ircsprintf(buf, form_str(RPL_WHOISCHANNELS), me.name,
               client_p->name, target_p->name, "");

    mlen = strlen(buf);
    cur_len = mlen;
    t = buf + mlen;

    for (lp = target_p->user->channel.head; lp; lp = lp->next)
    {
      chptr_whois = lp->data;
      if ((cur_len + strlen(chptr_whois->chname) + 2) > (BUFSIZE - 4))
      {
        sendto_one(client_p, "%s", buf);
        cur_len = mlen;
        t = buf + mlen;
      }

      ircsprintf(t, "%s%s ", channel_chanop_or_voice(chptr_whois, target_p),
                 chptr_whois->chname);
      tlen = strlen(t);
      t += tlen;
      cur_len += tlen;
      reply_to_send = YES;
    }

    if (reply_to_send == YES)
      sendto_one(client_p, "%s", buf);

    sendto_one(client_p, form_str(RPL_WHOISSERVER), me.name,
               client_p->name, target_p->name, target_p->user->server,
               a2client_p ? a2client_p->info : "*Not On This Net*");

    if (IsOper(target_p))
      sendto_one(client_p, form_str(RPL_WHOISOPERATOR), me.name,
                 client_p->name, target_p->name);

    if (MyConnect(target_p))
      sendto_one(client_p, form_str(RPL_WHOISIDLE), me.name,
                 client_p->name, target_p->name, CurrentTime - target_p->user->last,
                 target_p->firsttime);
    sendto_one(client_p, form_str(RPL_ENDOFWHOIS), me.name, parv[0], parv[2]);
    return;
  }
#endif

  sendto_one(client_p, ":%s NOTICE %s :%s is not a valid option.  Choose from LIST, MODE, NAMES, WHO, WHOIS",
             me.name, parv[0], parv[1]);
}

/* extensions for OPERSPY WHO */
#ifdef OPERSPY_WHO
static void do_who(struct Client *source_p,
                   struct Client *target_p,
                   char *chname,
                   char *op_flags)
{
  char  status[5];

  ircsprintf(status,"%c%s%s",
             target_p->user->away ? 'G' : 'H',
             IsOper(target_p) ? "*" : "", op_flags );

#ifdef ANONOPS
  if(ConfigServerHide.hide_servers)
    {
      sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
                 (chname) ? (chname) : "*",
                 target_p->username,
                 target_p->host, IsOper(source_p) ? target_p->user->server : "*",
                 target_p->name,
                 status, 0, target_p->info);
    }
  else
#endif
    {
      sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
                 (chname) ? (chname) : "*",
                 target_p->username,
                 target_p->host,  target_p->user->server, target_p->name,
                 status, target_p->hopcount, target_p->info);
    }
}

static void
who_common_channel(struct Client *source_p,dlink_list chain,
                   char *mask,int server_oper, int *maxmatches)
{
  dlink_node *clp;
  struct Client *target_p;

  DLINK_FOREACH(clp, chain.head)
  {
    target_p = clp->data;

    if (IsMarked(target_p))
      continue;

    if (server_oper && !IsOper(target_p))
      continue;

    SetMark(target_p);

    if ((mask == NULL) ||
        match(mask, target_p->name) ||
        match(mask, target_p->username) ||
        match(mask, target_p->host) ||
        match(mask, target_p->user->server) ||
        (MyClient(target_p) && match(mask, target_p->localClient->sockhost)) ||
        match(mask, target_p->info))
    {
       
      do_who(source_p, target_p, NULL, "");

      if (*maxmatches > 0)
      {
        --(*maxmatches);
        if(*maxmatches == 0)
          return;
      }
    }
  }
}

static void
who_global(struct Client *source_p,char *mask, int server_oper)
{
  struct Channel *chptr=NULL;
  struct Client *target_p;
  dlink_node  *lp;
  int   maxmatches = 500;
                        
  /* first, list all matching INvisible clients on common channels */
  DLINK_FOREACH(lp, source_p->user->channel.head)
  {
     chptr = lp->data;
     who_common_channel(source_p,chptr->chanops,mask,server_oper,&maxmatches);
#ifdef REQUIRE_OANDV
     who_common_channel(source_p,chptr->chanops_voiced,mask,server_oper,&maxmatches);
#endif
#ifdef HALFOPS
     who_common_channel(source_p,chptr->halfops,mask,server_oper,&maxmatches);
#endif
     who_common_channel(source_p,chptr->voiced,mask,server_oper,&maxmatches);
     who_common_channel(source_p,chptr->peons,mask,server_oper,&maxmatches);
  }

  /* second, list all matching visible clients */
  for (target_p = GlobalClientList; target_p; target_p = target_p->next)
  {
    if (!IsPerson(target_p))
      continue;

    if (IsMarked(target_p))
    {
      ClearMark(target_p);
      continue;
    }

    if (server_oper && !IsOper(target_p))
      continue;

    if (!mask ||
        match(mask, target_p->name) || match(mask, target_p->username) ||
        match(mask, target_p->host) || match(mask, target_p->user->server) ||
        match(mask, target_p->info) ||
        (MyClient(target_p) && match(mask, target_p->localClient->sockhost)))
    {
       
      do_who(source_p, target_p, NULL, "");
      if (maxmatches > 0)
      {
        --maxmatches;
        if( maxmatches == 0 )
          return;
      }

    }

  }
}

static void
do_who_on_channel(struct Client *source_p, struct Channel *chptr,
                              char *chname, int server_oper)
{
  char flags[NUMLISTS][2];

  /* jdc -- Check is_any_op() for +o > +h > +v priorities */
  set_channel_mode_flags( flags, chptr, source_p );

  do_who_list(source_p, chptr, &chptr->peons, &chptr->chanops,
#ifdef REQUIRE_OANDV
              &chptr->chanops_voiced,
#endif
#ifdef HALFOPS
              &chptr->halfops,
#endif
              &chptr->voiced, flags[0], flags[1], flags[2], chname);

}

struct who_member
{
  dlink_node *ptr;
  char *flag;
  int voiced;
};
 
struct who_member who_list[NUMLISTS];

static void
do_who_list(struct Client *source_p, struct Channel *chptr,
            dlink_list *peons_list, dlink_list *chanops_list,
#ifdef REQUIRE_OANDV
            dlink_list *chanops_voiced_list,
#endif
#ifdef HALFOPS
            dlink_list *halfops_list,
#endif
            dlink_list *voiced_list, char *chanop_flag,
            char *halfop_flag, char *voiced_flag,
            char *chname)
{
#ifndef ANONOPS
  dlink_node *ptr;
#endif
  struct Client *target_p;
  int done=0;
  int i=0;

  if(peons_list != NULL)
    who_list[i].ptr = peons_list->head;
  else
    who_list[i].ptr = NULL;
  who_list[i].voiced = 0;
  who_list[i++].flag = "";

  if(voiced_list != NULL)
    who_list[i].ptr = voiced_list->head;
  else
    who_list[i].ptr = NULL;
  who_list[i].voiced = 1;
  who_list[i++].flag = voiced_flag;

  if(chanops_list != NULL)
    who_list[i].ptr = chanops_list->head;
  else
    who_list[i].ptr = NULL;
  who_list[i].voiced = 0;
  who_list[i++].flag = chanop_flag;

#ifdef REQUIRE_OANDV
  if(chanops_voiced_list != NULL)
    who_list[i].ptr = chanops_voiced_list->head;
  else
    who_list[i].ptr = NULL;
  who_list[i].voiced = 0;
  who_list[i++].flag = chanop_flag;
#endif

#ifdef HALFOPS
  if(halfops_list != NULL)
    who_list[i].ptr = halfops_list->head;
  else
    who_list[i].ptr = NULL;
  who_list[i].voiced = 0;
  who_list[i++].flag = halfop_flag;
#endif

#ifdef ANONOPS
  while(done != NUMLISTS)
  {
    done = 0;

    for(i = 0; i < NUMLISTS; i++)
    {
      if(who_list[i].ptr != NULL)
      {
        target_p = who_list[i].ptr->data;

        if(who_list[i].voiced)
          do_who(source_p, target_p, chname, voiced_flag);
        else
          do_who(source_p, target_p, chname, who_list[i].flag);
        who_list[i].ptr = who_list[i].ptr->next;
      }
      else
        done++;
    }
  }

#else /* ANONOPS */

    for(i = 0; i < NUMLISTS; i++)
    {
      DLINK_FOREACH(ptr, who_list[i].ptr)
      {
        target_p = ptr->data;
        do_who(source_p, target_p, chname, who_list[i].flag);
      }
    }

#endif /* ANONOPS */
}
#endif /* OPERSPY_WHO */
