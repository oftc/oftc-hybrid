/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  channel.c: Controls channels.
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
#include "client.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "s_serv.h"             /* captab */
#include "s_user.h"
#include "send.h"
#include "whowas.h"
#include "s_conf.h"             /* ConfigFileEntry, ConfigChannel */
#include "event.h"
#include "memory.h"
#include "balloc.h"
#include "resv.h"
#include "fdlist.h"


struct config_channel_entry ConfigChannel;
dlink_list global_channel_list = { NULL, NULL, 0 };
dlink_list lazylink_channels = { NULL, NULL, 0 };
BlockHeap *channel_heap;
BlockHeap *ban_heap;

static BlockHeap *topic_heap;
static BlockHeap *member_heap;

static void destroy_channel(struct Channel *);
static void send_mode_list(struct Client *client_p, const char *chname,
                           dlink_list *top, char flag, int clear);
static int check_banned(struct Channel *chptr, const char *s, const char *s2);
static const char *channel_pub_or_secret(struct Channel *chptr);

static char buf[BUFSIZE];
static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];

/* init_channels()
 *
 * inputs	- none
 * output	- none
 * side effects	- Initializes the channel blockheap,
 *		  adds known channel CAPAB
 */
void
init_channels(void)
{
  /* XXX */
  add_capability("EX", CAP_EX, 1);
  add_capability("IE", CAP_IE, 1);
  add_capability("CHW", CAP_CHW, 1);

  channel_heap = BlockHeapCreate(sizeof(struct Channel), CHANNEL_HEAP_SIZE);
  ban_heap = BlockHeapCreate(sizeof(struct Ban), BAN_HEAP_SIZE);
  topic_heap = BlockHeapCreate(TOPICLEN+1 + USERHOST_REPLYLEN, TOPIC_HEAP_SIZE);
  member_heap = BlockHeapCreate(sizeof(struct Membership), CHANNEL_HEAP_SIZE /* XXX */ );
}

/* add_user_to_channel()
 *
 * inputs       - pointer to channel to add client to
 *              - pointer to client (who) to add
 *              - flags for chanops etc
 * output       - NONE
 * side effects - adds a user to a channel by adding another link to the
 *                channels member chain.
 */
void
add_user_to_channel(struct Channel *chptr, struct Client *who,
                    unsigned int flags)
{
  struct Membership *ms;

  assert(who->user != NULL);

  ms = BlockHeapAlloc(member_heap);
  memset(ms, 0, sizeof(struct Membership));

  ms->client_p = who;
  ms->chptr = chptr;
  ms->flags = flags;

  dlinkAdd(ms, &ms->channode, &chptr->members);

  if (MyConnect(who))
    dlinkAdd(ms, &ms->locchannode, &chptr->locmembers);

  dlinkAdd(ms, &ms->usernode, &who->user->channel);
}

/* remove_user_from_channel()
 *
 * inputs       - pointer to membership
 * output       - NONE
 * side effects - deletes an user from a channel by removing a link in the
 *                channels member chain.
 */
void
remove_user_from_channel(struct Membership *member)
{
  struct Client *client_p = member->client_p;
  struct Channel *chptr = member->chptr;

  dlinkDelete(&member->channode, &chptr->members);

  if (MyConnect(client_p))
    dlinkDelete(&member->locchannode, &chptr->locmembers);

  dlinkDelete(&member->usernode, &client_p->user->channel);

  BlockHeapFree(member_heap, member);

  if (dlink_list_length(&chptr->members) == 0)
  {
    assert(dlink_list_length(&chptr->locmembers) == 0);
    destroy_channel(chptr);
  }
}

/* send_members()
 *
 * inputs       -
 * output       - NONE
 * side effects -
 */
static void
send_members(struct Client *client_p, struct Channel *chptr,
             char *lmodebuf, char *lparabuf)
{
  struct Membership *ms;
  dlink_node *ptr;
  int tlen;              /* length of text to append */
  char *t, *start;       /* temp char pointer */

  start = t = buf + ircsprintf(buf, ":%s SJOIN %lu %s %s %s:", me.name,
                               (unsigned long) chptr->channelts,
                               chptr->chname, lmodebuf, lparabuf);

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;

    tlen = strlen(ms->client_p->name) + 1;  /* nick + space */
    if (ms->flags & CHFL_CHANOP)
      tlen++;
    if (ms->flags & CHFL_HALFOP)
      tlen++;
    if (ms->flags & CHFL_VOICE)
      tlen++;

    if (t + tlen - buf > IRCD_BUFSIZE)
    {
      *(t - 1) = '\0';  /* kill the space and terminate the string */
      sendto_one(client_p, "%s", buf);
      t = start;
    }

    strcpy(t, get_member_status(ms, YES));
    t += strlen(t);
    strcpy(t, ms->client_p->name);
    t += strlen(t);
    *t++ = ' ';
  }

  /* should always be non-NULL unless we have a kind of persistent channels */
  if (chptr->members.head != NULL)
    t--;  /* take the space out */
  *t = '\0';
  sendto_one(client_p, "%s", buf);
}

/* send_channel_modes()
 *
 * inputs       - pointer to client client_p
 *              - pointer to channel pointer
 * output       - NONE
 * side effects - send "client_p" a full list of the modes for channel chptr.
 */
void
send_channel_modes(struct Client *client_p, struct Channel *chptr)
{
  if (*chptr->chname != '#')
    return;

  *modebuf = *parabuf = '\0';
  channel_modes(chptr, client_p, modebuf, parabuf);
  send_members(client_p, chptr, modebuf, parabuf);

  send_mode_list(client_p, chptr->chname, &chptr->banlist, 'b', 0);
  if (IsCapable(client_p, CAP_EX))
    send_mode_list(client_p, chptr->chname, &chptr->exceptlist, 'e', 0);
  if (IsCapable(client_p, CAP_IE))
    send_mode_list(client_p, chptr->chname, &chptr->invexlist, 'I', 0);
}

/* send_mode_list()
 *
 * inputs       - client pointer to server
 *              - pointer to channel
 *              - pointer to top of mode link list to send
 *              - char flag flagging type of mode i.e. 'b' 'e' etc.
 *              - clear (remove all current modes, for ophiding, etc)
 * output       - NONE
 * side effects - sends +b/+e/+I
 *
 */
static void
send_mode_list(struct Client *client_p, const char *chname, dlink_list *top,
               char flag, int clear)
{
  dlink_node *lp;
  struct Ban *banptr;
  char mbuf[MODEBUFLEN];
  char pbuf[MODEBUFLEN];
  int tlen;
  int mlen;
  int cur_len;
  char *mp;
  char *pp;
  int count;

  ircsprintf(buf, ":%s MODE %s ", me.name, chname);
  cur_len = mlen = (strlen(buf) + 2);
  count = 0;
  mp = mbuf;
  *mp++ = (clear ? '-' : '+');
  *mp = '\0';
  pp = pbuf;

  DLINK_FOREACH(lp, top->head)
  {
    banptr = lp->data;
    tlen = strlen(banptr->banstr);
    tlen++;

    if ((count >= MAXMODEPARAMS) || ((cur_len + tlen + 2) > MODEBUFLEN))
    {
      sendto_one(client_p, "%s%s %s", buf, mbuf, pbuf);
      mp = mbuf;
      *mp++ = (clear ? '-' : '+');
      *mp = '\0';
      pp = pbuf;
      cur_len = mlen;
      count = 0;
    }

    *mp++ = flag;
    *mp = '\0';
    ircsprintf(pp, "%s ", banptr->banstr);
    pp += tlen;
    cur_len += tlen;
    count++;
  }

  if (count != 0)
    sendto_one(client_p, "%s%s %s", buf, mbuf, pbuf);
}

/* check_channel_name()
 *
 * inputs       - channel name
 * output       - true  (1) if name ok,
 *              - false (0) otherwise
 * side effects - check channel name for
 *                invalid characters
 */
int
check_channel_name(const char *name)
{
  assert(name != NULL);

  if (name == NULL)
    return(0);

  for (; *name; ++name)
  {
    if (!IsChanChar(*name))
      return(0);
  }

  return(1);
}

/* free_channel_list()
 *
 * inputs       - pointer to dlink_list
 * output       - NONE
 * side effects -
 */
void
free_channel_list(dlink_list *list)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct Ban *actualBan;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
  {
    actualBan = ptr->data;

    MyFree(actualBan->banstr);
    MyFree(actualBan->who);
    dlinkDelete(&actualBan->node, list);
    BlockHeapFree(ban_heap, actualBan);
  }
}

/* destroy_channel()
 *
 * inputs       - channel pointer
 * output       - NONE
 * side effects - walk through this channel, and destroy it.
 */
static void
destroy_channel(struct Channel *chptr)
{
  dlink_node *m;
  dlink_node *ptr;
  dlink_node *ptr_next;

  DLINK_FOREACH_SAFE(ptr, ptr_next, chptr->invites.head)
    del_invite(chptr, ptr->data);

  /* free all bans/exceptions/denies */
  free_channel_list(&chptr->banlist);
  free_channel_list(&chptr->exceptlist);
  free_channel_list(&chptr->invexlist);

  /* Free the topic */
  free_topic(chptr);

  /* This should be redundant at this point but JIC */
  chptr->banlist.head = chptr->exceptlist.head = chptr->invexlist.head = NULL;
  chptr->banlist.tail = chptr->exceptlist.tail = chptr->invexlist.tail = NULL;

  dlinkDelete(&chptr->node, &global_channel_list);
  hash_del_channel(chptr);

  if (ServerInfo.hub == 1)
  {
    DLINK_FOREACH(m, lazylink_channels.head)
    {
      if (m->data != chptr)
        continue;
      dlinkDelete(m, &lazylink_channels);
      free_dlink_node(m);
      break;
    }
  }

  BlockHeapFree(channel_heap, chptr);
}

/* channel_member_names()
 *
 * inputs       - pointer to client struct requesting names
 *              - pointer to channel block
 *              - pointer to name of channel
 *              - show ENDOFNAMES numeric or not
 *                (don't want it with /names with no params)
 * output       - none
 * side effects - lists all names on given channel
 */
void
channel_member_names(struct Client *source_p, struct Channel *chptr,
                     int show_eon)
{
  struct Client *target_p;
  struct Membership *ms;
  dlink_node *ptr;
  char lbuf[IRCD_BUFSIZE + 1];
  char *t, *start;
  int tlen;
  int is_member;

  if (ShowChannel(source_p, chptr) || IsGod(source_p))
  {
    is_member = IsMember(source_p, chptr);
    t = lbuf + ircsprintf(lbuf, form_str(RPL_NAMREPLY),
                          me.name, source_p->name,
                          channel_pub_or_secret(chptr),
                          chptr->chname);
    start = t;
    tlen = 0;

    DLINK_FOREACH(ptr, chptr->members.head)
    {
      ms       = ptr->data;
      target_p = ms->client_p;

      if (IsInvisible(target_p) && !is_member && !IsGod(source_p))
        continue;

      tlen = strlen(target_p->name) + 1;  /* nick + space */
      if (ms->flags & (CHFL_CHANOP | CHFL_HALFOP | CHFL_VOICE))
        tlen++;
      if (t + tlen - lbuf > IRCD_BUFSIZE)
      {
        *(t - 1) = '\0';
	sendto_one(source_p, "%s", lbuf);
	t = start;
      }

      t += ircsprintf(t, "%s%s ", get_member_status(ms, NO),
                      target_p->name); /* XXX */
    }

    if (tlen != 0)
      sendto_one(source_p, "%s", lbuf);
  }

  if (show_eon)
    sendto_one(source_p, form_str(RPL_ENDOFNAMES),
               me.name, source_p->name, chptr->chname);
}

/* channel_pub_or_secret()
 *
 * inputs       - pointer to channel
 * output       - string pointer "=" if public, "@" if secret else "*"
 * side effects - NONE
 */
static const char *
channel_pub_or_secret(struct Channel *chptr)
{
  if (PubChannel(chptr))
    return("=");
  else if (SecretChannel(chptr))
    return("@");
  return("*");
}

/* add_invite()
 *
 * inputs       - pointer to channel block
 *              - pointer to client to add invite to
 * output       - NONE
 * side effects - adds client to invite list
 *
 * This one is ONLY used by m_invite.c
 */
void
add_invite(struct Channel *chptr, struct Client *who)
{
  del_invite(chptr, who);
  /*
   * delete last link in chain if the list is max length
   */
  if (dlink_list_length(&who->user->invited) >=
      (unsigned int)ConfigChannel.max_chans_per_user)
  {
    del_invite(chptr, who);
  }

  /* add client to channel invite list */
  dlinkAdd(who, make_dlink_node(), &chptr->invites);

  /* add channel to the end of the client invite list */
  dlinkAdd(chptr, make_dlink_node(), &who->user->invited);
}

/* del_invite()
 *
 * inputs       - pointer to dlink_list
 *              - pointer to client to remove invites from
 * output       - NONE
 * side effects - Delete Invite block from channel invite list
 *                and client invite list
 *
 */
void
del_invite(struct Channel *chptr, struct Client *who)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, chptr->invites.head)
  {
    if (ptr->data == who)
    {
      dlinkDelete(ptr, &chptr->invites);
      free_dlink_node(ptr);
      break;
    }
  }

  DLINK_FOREACH(ptr, who->user->invited.head)
  {
    if (ptr->data == chptr)
    {
      dlinkDelete(ptr, &who->user->invited);
      free_dlink_node(ptr);
      break;
    }
  }
}

/* get_member_status()
 *
 * inputs       - pointer to struct Membership
 *              - YES if we can combine different flags
 * output       - string either @, +, % or "" depending on whether
 *                chanop, voiced or user
 * side effects -
 *
 * NOTE: Returned string is usually a static buffer
 * (like in get_client_name)
 */
const char *
get_member_status(struct Membership *ms, int combine)
{
  static char buffer[4];
  char *p;

  if (ms == NULL)
    return("");
  p = buffer;

  if (ms->flags & CHFL_CHANOP)
  {
    if (!combine)
      return "@";
    *p++ = '@';
  }

  if (ms->flags & CHFL_HALFOP)
  {
    if (!combine)
      return "%";
    *p++ = '%';
  }

  if (ms->flags & CHFL_VOICE)
    *p++ = '+';
  *p = '\0';

  return(buffer);
}

/* is_banned()
 *
 * inputs       - pointer to channel block
 *              - pointer to client to check access fo
 * output       - returns an int 0 if not banned,
 *                CHFL_BAN if banned
 *
 * IP_BAN_ALL from comstud
 * always on...
 *
 * +e code from orabidoo
 */
int
is_banned(struct Channel *chptr, struct Client *who)
{
  char src_host[NICKLEN + USERLEN + HOSTLEN + 6];
  char src_iphost[NICKLEN + USERLEN + HOSTLEN + 6];

  if (!IsPerson(who))
    return(0);

  ircsprintf(src_host,"%s!%s@%s", who->name, who->username, who->host);
  ircsprintf(src_iphost,"%s!%s@%s", who->name, who->username,
	     who->localClient->sockhost);

  return(check_banned(chptr, src_host, src_iphost));
}

/* check_banned()
 *
 * inputs       - pointer to channel block
 *              - pointer to client to check access fo
 *              - pointer to pre-formed nick!user@host
 *              - pointer to pre-formed nick!user@ip
 * output       - returns an int 0 if not banned,
 *                CHFL_BAN if banned
 *
 * IP_BAN_ALL from comstud
 * always on...
 *
 * +e code from orabidoo
 */
static int
check_banned(struct Channel *chptr, const char *s, const char *s2)
{
  dlink_node *ban;
  dlink_node *except;
  struct Ban *actualBan = NULL;
  struct Ban *actualExcept = NULL;

  DLINK_FOREACH(ban, chptr->banlist.head)
  {
    actualBan = ban->data;

    if (match(actualBan->banstr,  s) || 
    	match(actualBan->banstr, s2) ||
        match_cidr(actualBan->banstr, s2))
      break;
    else
      actualBan = NULL;
  }

  if ((actualBan != NULL) && ConfigChannel.use_except)
  {
    DLINK_FOREACH(except, chptr->exceptlist.head)
    {
      actualExcept = except->data;

      if (match(actualExcept->banstr,  s) || 
          match(actualExcept->banstr, s2) ||
          match_cidr(actualExcept->banstr, s2))
      {
        return(CHFL_EXCEPTION);
      }
    }
  }

  return((actualBan ? CHFL_BAN : 0));
}

/* can_join()
 *
 * inputs       -
 * output       -
 * side effects - NONE
 */
int
can_join(struct Client *source_p, struct Channel *chptr, const char *key)
{
  dlink_node *lp;
  dlink_node *ptr;
  struct Ban *invex = NULL;
  char src_host[NICKLEN + USERLEN + HOSTLEN + 6];
  char src_iphost[NICKLEN + USERLEN + HOSTLEN + 6];

  assert(source_p->localClient != NULL);

  ircsprintf(src_host, "%s!%s@%s", source_p->name, source_p->username,
             source_p->host);
  ircsprintf(src_iphost, "%s!%s@%s", source_p->name, source_p->username,
	     source_p->localClient->sockhost);

  if ((check_banned(chptr, src_host, src_iphost)) == CHFL_BAN)
    return(ERR_BANNEDFROMCHAN);

  if (chptr->mode.mode & MODE_INVITEONLY)
  {
    DLINK_FOREACH(lp, source_p->user->invited.head)
      if (lp->data == chptr)
        break;

    if (lp == NULL)
    {
      if (!ConfigChannel.use_invex)
        return(ERR_INVITEONLYCHAN);
      DLINK_FOREACH(ptr, chptr->invexlist.head)
      {
        invex = ptr->data;

        if (match(invex->banstr, src_host) || match(invex->banstr, src_iphost) ||
            match_cidr(invex->banstr, src_iphost))
          break;
      }
      if (ptr == NULL)
        return(ERR_INVITEONLYCHAN);
    }
  }

  if (*chptr->mode.key && (EmptyString(key) || irccmp(chptr->mode.key, key)))
    return(ERR_BADCHANNELKEY);

  if (chptr->mode.limit && dlink_list_length(&chptr->members) >=
      chptr->mode.limit)
    return(ERR_CHANNELISFULL);

  if(RegOnlyChannel(chptr) && !IsNickServReg(source_p))
      return(ERR_REGONLYCHAN);


  if (SSLonlyChannel(chptr)) 
  {
#ifdef HAVE_LIBCRYPTO
      if (MyClient(source_p)) {
          int fd = source_p->localClient->fd;
          fde_t *F = (fd > -1)? &fd_table[fd] : NULL;
          
          if (F && !F->ssl)
              return (ERR_SSLONLYCHAN);
      }
#else
      return (ERR_SSLONLYCHAN);	/* deny everyone on a non SSL-enabled server */
#endif  
  }

  return(0);
}

int
has_member_flags(struct Membership *ms, unsigned int flags)
{
  if (ms != NULL)
    return(ms->flags & flags);

  return(0);
}

struct Membership *
find_channel_link(struct Client *client_p, struct Channel *chptr)
{
  dlink_node *ptr;

  if (!IsClient(client_p))
    return(NULL);

  DLINK_FOREACH(ptr, client_p->user->channel.head)
    if (((struct Membership *)ptr->data)->chptr == chptr)
      return((struct Membership *)ptr->data);

  return(NULL);
}

/* can_send()
 *
 * inputs       - pointer to channel
 *              - pointer to client
 * outputs      - CAN_SEND_OPV if op or voiced on channel
 *              - CAN_SEND_NONOP if can send to channel but is not an op
 *                CAN_SEND_NO if they cannot send to channel
 *                Just means they can send to channel.
 * side effects - NONE
 */
int
can_send(struct Channel *chptr, struct Client *source_p)
{
  struct Membership *ms;

  if (IsServer(source_p))
    return(CAN_SEND_OPV);

  if (MyClient(source_p) &&
     (find_channel_resv(chptr->chname) &&
      !(IsOper(source_p)) && ConfigFileEntry.oper_pass_resv))
    return(CAN_SEND_NO);

  ms = find_channel_link(source_p, chptr);

  if ((ms != NULL) && ms->flags & (CHFL_CHANOP|CHFL_HALFOP|CHFL_VOICE))
     return(CAN_SEND_OPV);

  if (chptr->mode.mode & MODE_MODERATED)
    return(CAN_SEND_NO);

  if (ConfigChannel.quiet_on_ban && MyClient(source_p) &&
      (is_banned(chptr, source_p) == CHFL_BAN))
  {
    return(CAN_SEND_NO);
  }

  if (chptr->mode.mode & MODE_NOPRIVMSGS && ms == NULL)
    return(CAN_SEND_NO);

  if(SpeakOnlyIfReg(chptr) && !IsNickServReg(source_p))
      return(CAN_SEND_ONLY_IF_REG);

  return(CAN_SEND_NONOP);
}

int
can_send_part(struct Membership *member, struct Channel *chptr,
              struct Client *source_p)
{
  if (has_member_flags(member, CHFL_CHANOP|CHFL_HALFOP))
    return(CAN_SEND_OPV);

  if (chptr->mode.mode & MODE_MODERATED)
    return(CAN_SEND_NO);

  if (ConfigChannel.quiet_on_ban && MyClient(source_p) &&
      (is_banned(chptr, source_p) == CHFL_BAN))
  {
    return(CAN_SEND_NO);
  }

  return(CAN_SEND_NONOP);
}

/* check_spambot_warning()
 *
 * inputs       - Client to check, channel name or NULL if this is a part.
 * output       - NONE
 * side effects - Updates the client's oper_warn_count_down, warns the
 *                IRC operators if necessary, and updates
 *                join_leave_countdown as needed.
 */
void
check_spambot_warning(struct Client *source_p, const char *name)
{
  int t_delta;
  int decrement_count;

  if ((GlobalSetOptions.spam_num &&
       (source_p->localClient->join_leave_count >=
        GlobalSetOptions.spam_num)))
  {
    if (source_p->localClient->oper_warn_count_down > 0)
      source_p->localClient->oper_warn_count_down--;
    else
      source_p->localClient->oper_warn_count_down = 0;
    if (source_p->localClient->oper_warn_count_down == 0)
    {
      /* Its already known as a possible spambot */
      if (name != NULL)
        sendto_gnotice_flags(UMODE_BOTS, L_ALL, me.name, &me, NULL,
                             "User %s (%s@%s) trying to join %s is a possible spambot",
                             source_p->name, source_p->username,
                             source_p->host, name);
      else
        sendto_gnotice_flags(UMODE_BOTS, L_ALL, me.name, &me, NULL,
                             "User %s (%s@%s) is a possible spambot",
                             source_p->name, source_p->username,
                             source_p->host);
      source_p->localClient->oper_warn_count_down = OPER_SPAM_COUNTDOWN;
    }
  }
  else
  {
    if ((t_delta = (CurrentTime - source_p->localClient->last_leave_time)) >
         JOIN_LEAVE_COUNT_EXPIRE_TIME)
    {
      decrement_count = (t_delta / JOIN_LEAVE_COUNT_EXPIRE_TIME);
      if (decrement_count > source_p->localClient->join_leave_count)
        source_p->localClient->join_leave_count = 0;
      else
        source_p->localClient->join_leave_count -= decrement_count;
    }
    else
    {
      if ((CurrentTime - (source_p->localClient->last_join_time)) <
          GlobalSetOptions.spam_time)
      {
        /* oh, its a possible spambot */
        source_p->localClient->join_leave_count++;
      }
    }
    if (name != NULL)
      source_p->localClient->last_join_time = CurrentTime;
    else
      source_p->localClient->last_leave_time = CurrentTime;
  }
}

/* check_splitmode()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - compares usercount and servercount against their split
 *                values and adjusts splitmode accordingly
 */
void
check_splitmode(void *unused)
{
  if (splitchecking && (ConfigChannel.no_join_on_split ||
      ConfigChannel.no_create_on_split))
  {
    const unsigned int server = dlink_list_length(&global_serv_list);

    if (!splitmode && ((server < split_servers) || (Count.total < split_users)))
    {
      splitmode = 1;

      sendto_gnotice_flags(UMODE_ALL,L_ALL, me.name, &me, NULL,
                         "Network split, activating splitmode");
      eventAddIsh("check_splitmode", check_splitmode, NULL, 10);
    }
    else if (splitmode && (server > split_servers) && (Count.total > split_users))
    {
      splitmode = 0;
    
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                           "Network rejoined, deactivating splitmode");
      eventDelete(check_splitmode, NULL);
    }
  }
}

/* allocate_topic()
 *
 * inputs       - Channel to allocate a new topic for
 * output       - Success or failure
 * side effects - Allocates a new topic
 */
static void
allocate_topic(struct Channel *chptr)
{
  void *ptr;

  if (chptr == NULL)
    return;

  ptr = BlockHeapAlloc(topic_heap);  

  /* Basically we allocate one large block for the topic and
   * the topic info.  We then split it up into two and shove it
   * in the chptr 
   */
  chptr->topic       = ptr;
  chptr->topic_info  = (char *)ptr + TOPICLEN+1;
  *chptr->topic      = '\0';
  *chptr->topic_info = '\0';
}

void
free_topic(struct Channel *chptr)
{
  void *ptr;
  
  if (chptr == NULL || chptr->topic == NULL)
    return;

  /* This is safe for now - If you change allocate_topic you
   * MUST change this as well
   */
  ptr = chptr->topic; 
  BlockHeapFree(topic_heap, ptr);    
  chptr->topic      = NULL;
  chptr->topic_info = NULL;
}

/*
 * set_channel_topic - Sets the channel topic
 */
void
set_channel_topic(struct Channel *chptr, const char *topic,
		  const char *topic_info, time_t topicts)
{
  if(strlen(topic) > 0)
  {
    if(chptr->topic == NULL)
      allocate_topic(chptr);
    strlcpy(chptr->topic, topic, TOPICLEN+1);
    strlcpy(chptr->topic_info, topic_info,  USERHOST_REPLYLEN);
    chptr->topic_time = topicts; 
  }
  else
  {
    if(chptr->topic != NULL)
      free_topic(chptr);
    chptr->topic_time = 0;
  }
}

int msg_has_colors(char *msg)
{

    char *c;
    if (msg == NULL) 
        return 0;
    c = msg;
    
    while(*c) 
    {   
        if(*c == '\003' || *c == '\033')
            break;
    else       
        c++;
    }   

    if(*c)
        return 1;
    return 0;
}

char *strip_color(char* string)
{
    char *source = string;
    char *dest = string;
    char *last_non_space = NULL;

    for (; source && *source; source++)
        switch(*source)
        {
        case 3:
            if (isdigit(source[1]))
            {
                source++;
                if (isdigit(source[1]))
                    source++;
                if (source[1] == ',' && isdigit(source[2]))
                {
                    source+=2;
                    if (isdigit(source[1]))
                        source++;
                }
            }
            break;
        case 2: case 6: case 7: case 22: case 23: case 27: case 31:
            break;
        case 32:
            *dest++ = *source;
            break;
        default:
            *dest++ = *source;
            last_non_space = dest;
            break;
        }
    *dest = '\0';
    if (last_non_space)
        *last_non_space = '\0';
    return string;
}
