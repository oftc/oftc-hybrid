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
#include "sprintf_irc.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "s_misc.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "hash.h"

/* enable logging of OPERSPY functions */
#define OPERSPY_LOG

/* enable this to log all local/remote operspy usage to a logfile */
#define OPERSPY_LOGFILE

/* enable this to send incoming operspy usage to connected +y (UMODE_SPY) opers */
#define OPERSPY_NOTICE

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
static void m_operspy(struct Client *, struct Client *, int, char **);
static void ms_operspy(struct Client *, struct Client *, int, char **);
static void mo_operspy(struct Client *, struct Client *, int, char **);

/* extensions for OPERSPY WHO */
#ifdef OPERSPY_WHO
static void do_who(struct Client *source_p, struct Client *target_p,
                   char *chname, const char *op_flags);

static void who_global(struct Client *source_p, char *mask, int server_oper);

static void do_who_on_channel(struct Client *source_p, struct Channel *chptr,
                              char *chname);

#endif

struct Message operspy_msgtab = {
  "OPERSPY", 0, 0, 0, 0, MFLG_HIDDEN, 0,
  {m_ignore, m_operspy, ms_operspy, mo_operspy, m_ignore}
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

#ifdef OPERSPY_LOG
static void operspy_log(struct Client *, const char *, const char *);
#endif

/*
 * m_operspy
 *      parv[1] = operspy command
 *      parv[2] = command parameter
 */
static void
m_operspy(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  sendto_one(client_p, ":%s %d %s %s :Unknown command",
             me.name, ERR_UNKNOWNCOMMAND, client_p->name,
             parv[0]);
}

static void
ms_operspy(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
#ifdef OPERSPY_LOG
  operspy_log(source_p, parv[1], parv[2]);
#endif
}

/*
 * mo_operspy
 *	parv[1] = operspy command
 *	parv[2] = command parameter
 */
static
void mo_operspy(struct Client *client_p, struct Client *source_p,
		int parc, char *parv[])
{
  char *operspy = parv[0];
  dlink_node *ptr;
#ifdef OPERSPY_LOG
  /* "nick!user@host server\0" */
  char nuh[NICKLEN + 1 + USERLEN + 1 + HOSTLEN + 1 + HOSTLEN + 1];
#endif

#ifdef OPERSPY_LIST
  struct Channel *chptr_list = NULL;
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
  struct Channel        *chptr_names = NULL;
#endif

#ifdef OPERSPY_TOPIC
  struct Channel	*chptr_topic = NULL;
#endif

#ifdef OPERSPY_WHO
  char			*mask = parc > 2 ? parv[2] : NULL;
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
  if (irccmp(parv[1], "LIST") == 0)
  {
#ifdef OPERSPY_LOG
    operspy_log(client_p, "LIST", parv[2]);
#endif

    sendto_one(client_p, form_str(RPL_LISTSTART),
               me.name, client_p->name);

    DLINK_FOREACH(ptr, global_channel_list.head)
    {
      chptr_list = ptr->data;

      if (match(parv[2], chptr_list->chname))
      {
        sendto_one(client_p, form_str(RPL_LIST), me.name, client_p->name,
                   chptr_list->chname, dlink_list_length(&chptr_list->members),
                   chptr_list->topic == NULL ? "" : chptr_list->topic);
      }
    }

    sendto_one(client_p, form_str(RPL_LISTEND),
               me.name, client_p->name);

    return;
  }
#endif

#ifdef OPERSPY_MODE
  if (irccmp(parv[1], "MODE") == 0)
  {
    if (!IsChanPrefix(parv[2][0]) || !check_channel_name(parv[2]))
    {
      sendto_one(client_p, form_str(ERR_BADCHANNAME),
                 me.name, client_p->name, parv[2]);
      return;
    }

    if ((chptr_mode = hash_find_channel(parv[2])) == NULL)
    {
      /*
       * according to m_mode.c, the channel *could* exist on the uplink still,
       * but I don't see how.  Even if it does, we won't be able to spy without
       * info.
       */ 
      sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, client_p->name, parv[2]);
      return;
    }

#ifdef OPERSPY_LOG
    operspy_log(client_p, "MODE", parv[2]);
#endif

    /* this is a dirty nasty kludge to trick channel_modes() into giving us the key */
    c_status = client_p->status;
    client_p->status = STAT_SERVER;

    channel_modes(chptr_mode, client_p, modebuf, parabuf);
    client_p->status = c_status;

    sendto_one(client_p, form_str(RPL_CHANNELMODEIS),
               me.name, client_p->name, parv[2], modebuf, parabuf);
    sendto_one(client_p, form_str(RPL_CREATIONTIME),
               me.name, client_p->name, parv[2], chptr_mode->channelts);

    return;
  }
#endif

#ifdef OPERSPY_NAMES
  if (irccmp(parv[1], "NAMES") == 0)
  {
    if (!IsChanPrefix(parv[2][0]) || !check_channel_name(parv[2]))
    {
      sendto_one(client_p, form_str(ERR_BADCHANNAME),
                 me.name, client_p->name, parv[2]);
      return;
    }

    if ((chptr_names = hash_find_channel(parv[2])) == NULL)
    {
      sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, client_p->name, parv[2]);
      return;
    }

#ifdef OPERSPY_LOG
    operspy_log(client_p, "NAMES", parv[2]);
#endif

    /* the way to go with this, rather than temporarily setting -sp,
     * is to temporarily add our client to the member list.  then
     * we can also list +i users.  an unfortunate side-effect of this
     * is that your nickname shows up in the list.  for now, there is
     * no easy way around it.
     */ 
    add_user_to_channel(chptr_names, client_p, CHFL_CHANOP);
    channel_member_names(client_p, chptr_names, 1);
    remove_user_from_channel(find_channel_link(client_p, chptr_names));

    return;
  }
#endif

#ifdef OPERSPY_TOPIC
  if (irccmp(parv[1], "TOPIC") == 0)
  {
    if ((chptr_topic = hash_find_channel(parv[2])) == NULL)
    {
      sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, client_p->name, parv[2]);
      return;
    }

#ifdef OPERSPY_LOG
    operspy_log(client_p, "TOPIC", parv[2]);
#endif

    if (chptr_topic->topic == NULL)
      sendto_one(client_p, form_str(RPL_NOTOPIC),
                 me.name, client_p->name, parv[2]);
    else
    {
      sendto_one(client_p, form_str(RPL_TOPIC), me.name, client_p->name,
                 chptr_topic->chname, chptr_topic->topic);
      sendto_one(client_p, form_str(RPL_TOPICWHOTIME), me.name,
                 client_p->name, chptr_topic->chname, chptr_topic->topic_info,
                 chptr_topic->topic_time);
    }

    return;
  }
#endif

#ifdef OPERSPY_WHO
  if (irccmp(parv[1], "WHO") == 0)
  {
    if (mask != NULL)
    {
      collapse(mask);

      if (*mask == '\0')
      {
        sendto_one(client_p, form_str(RPL_ENDOFWHO),
                   me.name, client_p->name, "*");
        return;
      }
    }
    else
    {
#ifdef OPERSPY_LOG
      operspy_log(client_p, "WHO", "*");
#endif
      who_global(client_p, NULL, server_oper);
      sendto_one(client_p, form_str(RPL_ENDOFWHO),
                 me.name, client_p->name, "*");
      return;
    }

    /* /who #channel */
    if (IsChannelName(mask))
    {
      if ((chptr_who = hash_find_channel(mask)) != NULL)
      {
#ifdef OPERSPY_LOG
        operspy_log(client_p, "WHO", mask);
#endif
        do_who_on_channel(client_p, chptr_who, chptr_who->chname);
      }

      sendto_one(client_p, form_str(RPL_ENDOFWHO),
                 me.name, client_p->name, mask);
      return;
    }

    /* /who nick */
    if (((target_p_who = find_client(mask)) != NULL) && 
        IsPerson(target_p_who))
    {
#ifdef OPERSPY_LOG
      ircsprintf(nuh, "%s!%s@%s %s",
                 target_p_who->name, target_p_who->username, target_p_who->host,
                 target_p_who->user->server->name);
      operspy_log(client_p, "WHO", nuh);
#endif

      if (target_p_who->user->channel.head != NULL)
      {
        chptr_who =
          ((struct Membership *)target_p_who->user->channel.head->data)->chptr;

        do_who(client_p, target_p_who, chptr_who->chname,
               get_member_status(target_p_who->user->channel.head->data, NO));
      }
      else
      {
        do_who(client_p, target_p_who, NULL, "");
      }

      sendto_one(client_p, form_str(RPL_ENDOFWHO),
                 me.name, client_p->name, mask);
      return;
    }

#ifdef OPERSPY_LOG
    operspy_log(client_p, "WHO", parv[2]);
#endif

    /* /who 0 */
    if ((*(mask+1) == '\0') && (*mask == '0'))
      who_global(client_p, NULL, server_oper);
    else
      who_global(client_p, mask, server_oper);

    /* nothing else? end of /who. */
    sendto_one(client_p, form_str(RPL_ENDOFWHO),
               me.name, client_p->name, mask);

    return;
  }
#endif

#ifdef OPERSPY_WHOIS
  if (irccmp(parv[1], "WHOIS") == 0)
  {
    if (strchr(parv[2], '?') || strchr(parv[2], '*'))
    {
      sendto_one(client_p, ":%s NOTICE %s :Do not use wildcards with this.",
                 me.name, client_p->name);
      return;
    }

    if ((target_p = find_client(parv[2])) == NULL || !IsClient(target_p))
    {
      sendto_one(client_p, form_str(ERR_NOSUCHNICK),
                 me.name, client_p->name, parv[2]);
      return;
    }

    assert(target_p->user != NULL);

#ifdef OPERSPY_LOG
    ircsprintf(nuh, "%s!%s@%s %s",
               target_p->name, target_p->username, target_p->host,
               target_p->user->server->name);
    operspy_log(client_p, "WHOIS", nuh);
#endif

    a2client_p = target_p->user->server;

    sendto_one(client_p, form_str(RPL_WHOISUSER), me.name,
               client_p->name, target_p->name, target_p->username,
               target_p->host, target_p->info);
    ircsprintf(buf, form_str(RPL_WHOISCHANNELS), me.name,
               client_p->name, target_p->name, "");

    mlen = strlen(buf);
    cur_len = mlen;
    t = buf + mlen;

    DLINK_FOREACH(lp, target_p->user->channel.head)
    {
      chptr_whois = ((struct Membership *)lp->data)->chptr;

      if ((cur_len + strlen(chptr_whois->chname) + 2) > (BUFSIZE - 4))
      {
        sendto_one(client_p, "%s", buf);
        cur_len = mlen;
        t = buf + mlen;
      }

      ircsprintf(t, "%s%s%s ",
                 ShowChannel(client_p, chptr_whois) ? "" : "%",
                 get_member_status((struct Membership *)lp->data, YES),
                 chptr_whois->chname);
      tlen = strlen(t);
      t += tlen;
      cur_len += tlen;
      reply_to_send = YES;
    }

    if (reply_to_send == YES)
      sendto_one(client_p, "%s", buf);

    sendto_one(client_p, form_str(RPL_WHOISSERVER), me.name,
               client_p->name, target_p->name, a2client_p->name,
               a2client_p->info);

    if (IsOper(target_p))
      sendto_one(client_p, form_str(RPL_WHOISOPERATOR),
                 me.name, client_p->name, target_p->name);

    if (MyConnect(target_p))
      sendto_one(client_p, form_str(RPL_WHOISIDLE), me.name,
                 client_p->name, target_p->name, CurrentTime - target_p->user->last,
                 target_p->firsttime);
    sendto_one(client_p, form_str(RPL_ENDOFWHOIS),
               me.name, client_p->name, parv[2]);

    return;
  }
#endif
  sendto_one(client_p, ":%s NOTICE %s :%s is not a valid option.  Choose from LIST, MODE, NAMES, WHO, WHOIS",
             me.name, client_p->name, parv[1]);
}

/* extensions for OPERSPY WHO */
#ifdef OPERSPY_WHO
static void
do_who(struct Client *source_p, struct Client *target_p,
       char *chname, const char *op_flags)
{
  char status[5];

  ircsprintf(status,"%c%s%s", target_p->user->away ? 'G' : 'H',
             IsOper(target_p) ? "*" : "", op_flags);
  sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
             (chname) ? (chname) : "*",
             target_p->username,
             target_p->host,  target_p->user->server->name, target_p->name,
             status, target_p->hopcount, target_p->info);
}

static void
who_global(struct Client *source_p, char *mask, int server_oper)
{
  struct Client *target_p;
  dlink_node *lp;
  int maxmatches = 500;
                        
  /* list all matching visible clients */
  DLINK_FOREACH(lp, global_client_list.head)
  {
    target_p = lp->data;

    if (!IsPerson(target_p))
      continue;

    if (server_oper && !IsOper(target_p))
      continue;

    if (!mask ||
        match(mask, target_p->name) || match(mask, target_p->username) ||
        match(mask, target_p->host) || match(mask, target_p->user->server->name) ||
        match(mask, target_p->info) ||
        (MyClient(target_p) && match(mask, target_p->localClient->sockhost)))
    {
      do_who(source_p, target_p, NULL, "");

      if (maxmatches > 0)
      {
        if (--maxmatches == 0)
          return;
      }
    }
  }
}

static void
do_who_on_channel(struct Client *source_p, struct Channel *chptr,
		  char *chname)
{
  dlink_node *ptr;
  struct Membership *ms;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;
    do_who(source_p, ms->client_p, chname, get_member_status(ms, NO));
  }
}
#endif /* OPERSPY_WHO */

#ifdef OPERSPY_LOG
static void
operspy_log(struct Client *source_p, const char *command, const char *target)
{
  struct ConfItem *conf;
#ifdef OPERSPY_LOGFILE
  FBFILE *operspy_fb;
  dlink_node *cnode;
  const char *opername = source_p->name;
  char linebuf[BUFSIZE], logfile[BUFSIZE];
#endif

  assert(source_p != NULL);

#ifdef OPERSPY_LOGFILE
  if (IsOper(source_p) && MyClient(source_p))
  {
    DLINK_FOREACH(cnode, source_p->localClient->confs.head)
    {
      conf = cnode->data;
      if (conf->type == OPER_TYPE)
      {
	opername = conf->name;
      }
    }
  }
  else if (!MyClient(source_p))
    opername = "remote";

  ircsprintf(logfile, "%s/operspy.%s.log", LOGPATH, opername);
  if ((operspy_fb = fbopen(logfile, "a")) == NULL)
    return;

  ircsprintf(linebuf, "[%s] OPERSPY %s %s %s\n",
             smalldate(CurrentTime),
             get_oper_name(source_p),
             command, target);
  fbputs(linebuf, operspy_fb);
  fbclose(operspy_fb);
#endif

#ifdef OPERSPY_NOTICE
  sendto_realops_flags(UMODE_SPY, L_ALL, "OPERSPY %s %s %s",
                       get_oper_name(source_p), command, target);
#endif

  if (MyClient(source_p))
    sendto_match_servs(source_p, "*", CAP_ENCAP, "ENCAP * OPERSPY %s :%s",
                       command, target);
}
#endif /* OPERSPY_LOG */
