/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  send.c: Functions for sending messages.
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
#include "send.h"
#include "channel.h"
#include "class.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircd.h"
#include "handlers.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "sprintf_irc.h"
#include "s_conf.h"
#include "linebuf.h"
#include "list.h"
#include "s_debug.h"
#include "s_log.h"
#include "vchannel.h"
#include "memory.h"
#include "hook.h"

#define LOG_BUFSIZE 2048

static  int
_send_linebuf(struct Client *, buf_head_t *);

static void
send_linebuf_remote(struct Client *, struct Client *, buf_head_t *);

/* send the message to the link the target is attached to */
#define send_linebuf(a,b) _send_linebuf((a->from?a->from:a),b)

/* global for now *sigh* */
unsigned long current_serial=0L;

static void
sendto_list_local(dlink_list *list, buf_head_t *linebuf);
static void
sendto_list_local_butone(struct Client *one, dlink_list *list,
                         buf_head_t *linebuf);

static void
sendto_list_remote(struct Client *one,
		   struct Client *from, dlink_list *list, int caps,
                   int nocaps, buf_head_t *linebuf);

static void
sendto_list_anywhere(struct Client *one, struct Client *from,
                     dlink_list *list, buf_head_t *local_linebuf,
                     buf_head_t *remote_linebuf, buf_head_t *uid_linebuf);


/*
 * send_trim
 *
 * inputs	- pointer to buffer to trim
 *		- length of buffer
 * output	- new length of buffer if modified otherwise original len
 * side effects	- input buffer is trimmed if needed
 */
static inline int
send_trim(char *lsendbuf,int len)
{
  /*
   * from rfc1459
   *
   * IRC messages are always lines of characters terminated with a CR-LF
   * (Carriage Return - Line Feed) pair, and these messages shall not
   * exceed 512 characters in length,  counting all characters 
   * including the trailing CR-LF.
   * Thus, there are 510 characters maximum allowed
   * for the command and its parameters.  There is no provision for
   * continuation message lines.  See section 7 for more details about
   * current implementations.
   */

  /*
   * We have to get a \r\n\0 onto sendbuf[] somehow to satisfy
   * the rfc. We must assume sendbuf[] is defined to be 513
   * bytes - a maximum of 510 characters, the CR-LF pair, and
   * a trailing \0, as stated in the rfc. Now, if len is greater
   * than the third-to-last slot in the buffer, an overflow will
   * occur if we try to add three more bytes, if it has not
   * already occured. In that case, simply set the last three
   * bytes of the buffer to \r\n\0. Otherwise, we're ok. My goal
   * is to get some sort of vsnprintf() function operational
   * for this routine, so we never again have a possibility
   * of an overflow.
   * -wnder
   */

  if(len > 510)
  {
    lsendbuf[IRCD_BUFSIZE-2] = '\r';
    lsendbuf[IRCD_BUFSIZE-1] = '\n';
    lsendbuf[IRCD_BUFSIZE] = '\0';
    return(IRCD_BUFSIZE);
  }
  return len;
}

/*
 * send_format
 *
 * inputs	- buffer to format into
 *		- format pattern to use
 *		- var args
 * output	- number of bytes formatted output
 * side effects	- modifies sendbuf
 */
static inline int
send_format(char *lsendbuf, const char *pattern, va_list args)
{
  int len; /* used for the length of the current message */

  len = vsprintf_irc(lsendbuf, pattern, args);

  return (send_trim(lsendbuf,len));
}


/*
 ** send_linebuf
 **      Internal utility which attaches one linebuf to the sockets
 **      sendq.
 */
static int
_send_linebuf(struct Client *to, buf_head_t *linebuf)
{
#ifdef INVARIANTS
  if (IsMe(to))
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                         "Trying to send message to myself!");
    return 0;
  }
#endif
  if (IsDead(to))
    return 0; 

  if (linebuf_len(&to->localClient->buf_sendq) > get_sendq(to))
  {
    if (IsServer(to))
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                           "Max SendQ limit exceeded for %s: %u > %lu",
                           get_client_name(to, HIDE_IP),
                           linebuf_len(&to->localClient->buf_sendq),
                           get_sendq(to));
    if (IsClient(to))
      to->flags |= FLAGS_SENDQEX;
    dead_link(to);
    return -1;
  }
  else
  {
    /* just attach the linebuf to the sendq instead of
     * generating a new one */
    linebuf_attach(&to->localClient->buf_sendq, linebuf);
  }
  /*
   ** Update statistics. The following is slightly incorrect
   ** because it counts messages even if queued, but bytes
   ** only really sent. Queued bytes get updated in SendQueued.
   */
  to->localClient->sendM += 1;
  me.localClient->sendM += 1;

  send_queued_write(to->localClient->fd, to);	
  return 0;
} /* send_linebuf() */

/*
 * send_linebuf_remote
 * 
 */
static void
send_linebuf_remote(struct Client *to, struct Client *from,
                    buf_head_t *linebuf)
{
  if(to->from)
    to = to->from;

  if(ServerInfo.hub && IsCapable(to, CAP_LL))
  {
    if(((from->lazyLinkClientExists &
         to->localClient->serverMask) == 0))
      client_burst_if_needed(to, from);
  }

  /* Optimize by checking if (from && to) before everything */
  /* we set to->from up there.. */

  if (!MyClient(from) && IsPerson(to) && (to == from->from))
  {
    if (IsServer(from))
    {
      sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
                           "Send message to %s [%s] dropped from %s(Fake Dir)",
                           to->name, to->from->name, from->name);
      return;
    }

    sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
                         "Ghosted: %s [%s@%s] from %s [%s@%s] (%s)",
                         to->name, to->username, to->host,
                         from->name, from->username, from->host,
                         to->from->name);

    sendto_server(NULL, to, NULL, NOCAPS, NOCAPS, NOFLAGS,
                  ":%s KILL %s :%s (%s [%s@%s] Ghosted %s)",
                  me.name, to->name, me.name, to->name,
                  to->username, to->host, to->from->name);

    SetKilled(to);

    if (IsPerson(from))
      sendto_one(from, form_str(ERR_GHOSTEDCLIENT),
                 me.name, from->name, to->name, to->username,
                 to->host, to->from);

    exit_client(NULL, to, &me, "Ghosted client");

    return;
  } 

  _send_linebuf(to, linebuf);
  return;
} /* send_linebuf_remote() */

/*
 ** send_queued_write
 **      This is called when there is a chance the some output would
 **      be possible. This attempts to empty the send queue as far as
 **      possible, and then if any data is left, a write is rescheduled.
 */
void
send_queued_write(int fd, void *data)
{
  struct Client *to = data;
  int retlen;
#ifndef NDEBUG
  struct hook_io_data hdata;
#endif
  
  /*
   ** Once socket is marked dead, we cannot start writing to it,
   ** even if the error is removed...
   */
#ifdef INVARIANTS
  if (IsDead(to))
  {
    /*
     * Actually, we should *NEVER* get here--something is
     * not working correct if send_queued is called for a
     * dead socket... --msa
     */
    return;
  } /* if (IsDead(to)) */
#endif

  /* Next, lets try to write some data */
#ifndef NDEBUG
  hdata.connection = to;
  if (to->localClient->buf_sendq.list.head)
    hdata.data =
      ((buf_line_t *)to->localClient->buf_sendq.list.head->data)->buf +
      to->localClient->buf_sendq.writeofs;
#endif
  
  if (linebuf_len(&to->localClient->buf_sendq))
  {
    while((retlen = linebuf_flush(to->localClient->fd, &to->localClient->buf_sendq)) > 0)
    {
      /* We have some data written .. update counters */
#ifndef NDEBUG
      hdata.len = retlen;
      hook_call_event("iosend", &hdata);
      if (to->localClient->buf_sendq.list.head)
        hdata.data = 
          ((buf_line_t *)to->localClient->buf_sendq.list.head->data)->buf +
          to->localClient->buf_sendq.writeofs;
#endif
      to->localClient->sendB += retlen;
      me.localClient->sendB += retlen;
      if (to->localClient->sendB > 1023)
      { 
        to->localClient->sendK += (to->localClient->sendB >> 10);
        to->localClient->sendB &= 0x03ff;        /* 2^10 = 1024, 3ff = 1023 */
      }
      else if (me.localClient->sendB > 1023)
      { 
        me.localClient->sendK += (me.localClient->sendB >> 10);
        me.localClient->sendB &= 0x03ff;
      }
    }
    if ((retlen < 0) && (ignoreErrno(errno)))
    {
      /* we have a non-fatal error, so just continue */
    }
    else if (retlen <= 0)
    {
      dead_link(to);
      return;
    }
  }

  /* Finally, if we have any more data, reschedule a write */
  if (linebuf_len(&to->localClient->buf_sendq))
    comm_setselect(fd, FDLIST_IDLECLIENT, COMM_SELECT_WRITE,
                   send_queued_write, to, 0);
} /* send_queued_write() */

/*
 ** send_queued_slink_write
 **      This is called when there is a chance the some output would
 **      be possible. This attempts to empty the send queue as far as
 **      possible, and then if any data is left, a write is rescheduled.
 */
void
send_queued_slink_write(int fd, void *data)
{
  struct Client *to = data;
  int retlen;

  /*
   ** Once socket is marked dead, we cannot start writing to it,
   ** even if the error is removed...
   */
#ifdef INVARIANTS
  if (IsDead(to)) {
    /*
     * Actually, we should *NEVER* get here--something is
     * not working correct if send_queued is called for a
     * dead socket... --msa
     */
    return;
  } /* if (IsDead(to)) */
#endif

  /* Next, lets try to write some data */
  if (to->localClient->slinkq)
  {
    retlen = send(to->localClient->ctrlfd,
                   to->localClient->slinkq + to->localClient->slinkq_ofs,
                   to->localClient->slinkq_len, 0);
    if (retlen < 0)
    {
      /* If we have a fatal error */
      if (!ignoreErrno(errno))
      {
	dead_link(to);
	return;
      }
    }
    else if (retlen == 0)
    {
      /* 0 bytes is an EOF .. */
      dead_link(to);
      return;
    }
    else
    {
      to->localClient->slinkq_len -= retlen;

      assert(to->localClient->slinkq_len >= 0);
      if (to->localClient->slinkq_len)
        to->localClient->slinkq_ofs += retlen;
      else
      {
        to->localClient->slinkq_ofs = 0;
        MyFree(to->localClient->slinkq);
        to->localClient->slinkq = NULL;
      }
    }
  }

  /* Finally, if we have any more data, reschedule a write */
  if (to->localClient->slinkq_len)
    comm_setselect(to->localClient->ctrlfd, FDLIST_IDLECLIENT,
                   COMM_SELECT_WRITE, send_queued_slink_write,
                   to, 0);
} /* send_queued_slink_write() */

/*
 * sendto_one
 *
 * inputs	- pointer to destination client
 *		- var args message
 * output	- NONE
 * side effects	- send message to single client
 */
void
sendto_one(struct Client *to, const char *pattern, ...)
{
  va_list args;
  buf_head_t linebuf;

  if (IsDead(to))
    return; /* This socket has already been marked as dead */

  /* send remote if to->from non NULL */
  if (to->from)
    to = to->from;

  linebuf_newbuf(&linebuf);

  va_start(args, pattern);
  linebuf_putmsg(&linebuf, pattern, &args, NULL);
  va_end(args);

  send_linebuf(to, &linebuf);

  linebuf_donebuf(&linebuf);

} /* sendto_one() */

/*
 * sendto_one_prefix
 *
 * inputs	- pointer to destination client
 *		- pointer to client to form prefix from
 *		- var args message
 * output	- NONE
 * side effects	- send message to single client
 */
void
sendto_one_prefix(struct Client *to, struct Client *prefix,
                  const char *pattern, ...)
{
  va_list args;
  struct Client *to_sendto;
  buf_head_t linebuf;

  if (IsDead(to))
    return; /* This socket has already been marked as dead */

  /* send remote if to->from non NULL */
  if (to->from)
    to_sendto = to->from;
  else
    to_sendto = to;

#ifdef INVARIANTS
  if (IsMe(to))
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                         "Trying to send to myself!");
    return;
  }
#endif

  linebuf_newbuf(&linebuf);
  va_start(args, pattern);

  if (IsServer(to_sendto) && IsCapable(to->from, CAP_UID))
    linebuf_putmsg(&linebuf, pattern, &args, ":%s ", ID(prefix));
  else
    linebuf_putmsg(&linebuf, pattern, &args, ":%s ", prefix->name);

  va_end(args);
  send_linebuf(to_sendto, &linebuf);
  linebuf_donebuf(&linebuf);
} /* sendto_one() */

/*
 * sendto_channel_butone
 *
 * inputs	- pointer to client(server) to NOT send message to
 *		- pointer to client that is sending this message
 *		- pointer to channel being sent to
 *		- vargs message
 * output	- NONE
 * side effects	- message as given is sent to given channel members.
 */
void
sendto_channel_butone(struct Client *one, struct Client *from,
                      struct Channel *chptr, char *command,
                      const char *pattern, ...)
{
  va_list    args;
  buf_head_t local_linebuf;
  buf_head_t remote_linebuf;
  buf_head_t uid_linebuf;

  linebuf_newbuf(&local_linebuf);
  linebuf_newbuf(&remote_linebuf);
  linebuf_newbuf(&uid_linebuf);
  va_start(args, pattern);

  if(IsServer(from))
    linebuf_putmsg(&local_linebuf, pattern, &args, ":%s %s %s ",
                   from->name, command, RootChan(chptr)->chname);
  else
    linebuf_putmsg(&local_linebuf, pattern, &args, ":%s!%s@%s %s %s ",
                   from->name, from->username, from->host,
                   command, RootChan(chptr)->chname);

  linebuf_putmsg(&remote_linebuf, pattern, &args, ":%s %s %s ",
                 from->name, command, chptr->chname);

  linebuf_putmsg(&uid_linebuf, pattern, &args, ":%s %s %s ",
                 ID(from), command, chptr->chname);

  va_end(args);

  ++current_serial;

  sendto_list_anywhere(one, from, &chptr->chanops,
                       &local_linebuf, &remote_linebuf, &uid_linebuf);

#ifdef REQUIRE_OANDV
  sendto_list_anywhere(one, from, &chptr->chanops_voiced,
                       &local_linebuf, &remote_linebuf, &uid_linebuf);
#endif

  sendto_list_anywhere(one, from, &chptr->voiced,
                       &local_linebuf, &remote_linebuf, &uid_linebuf);

#ifdef HALFOPS
  sendto_list_anywhere(one, from, &chptr->halfops,
                       &local_linebuf, &remote_linebuf, &uid_linebuf);
#endif

  sendto_list_anywhere(one, from, &chptr->peons,
                       &local_linebuf, &remote_linebuf, &uid_linebuf);

  linebuf_donebuf(&local_linebuf);
  linebuf_donebuf(&remote_linebuf);
  linebuf_donebuf(&uid_linebuf);
} /* sendto_channel_butone() */

/*
 * sendto_list_anywhere
 *
 * inputs	- pointer to client NOT to send back towards
 *		- pointer to client from where message is coming from
 *		- pointer to channel list to send
 *		- pointer to sendbuf to use for local clients
 *		- length of local_sendbuf
 *		- pointer to sendbuf to use for remote clients
 *		- length of remote_sendbuf
 */
static void
sendto_list_anywhere(struct Client *one, struct Client *from,
                     dlink_list *list, buf_head_t *local_linebuf,
                     buf_head_t *remote_linebuf, buf_head_t *uid_linebuf)
{
  dlink_node *ptr;
  dlink_node *ptr_next;
  struct Client *target_p;

  DLINK_FOREACH_SAFE(ptr, ptr_next, list->head)
  {
    target_p = ptr->data;

    if (target_p->from == one)
      continue;

    if (MyConnect(target_p) && IsRegisteredUser(target_p) && !IsDead(target_p))
    {
      if(target_p->serial != current_serial)
      {
        send_linebuf(target_p, local_linebuf);
        target_p->serial = current_serial;
      }
    }
    else
    {
      /*
       * Now check whether a message has been sent to this
       * remote link already
       */
      if(target_p->from->serial != current_serial)
      {
        if(IsCapable(target_p->from, CAP_UID))
          send_linebuf_remote(target_p, from, uid_linebuf);
        else
          send_linebuf_remote(target_p, from, remote_linebuf);
        target_p->from->serial = current_serial;
      }
    }
  }
}

/*
 * sendto_server
 * 
 * inputs       - pointer to client to NOT send to
 *              - pointer to source client required by LL (if any)
 *              - pointer to channel required by LL (if any)
 *              - caps or'd together which must ALL be present
 *              - caps or'd together which must ALL NOT be present
 *              - LL flags: LL_ICLIENT | LL_ICHAN
 *              - printf style format string
 *              - args to format string
 * output       - NONE
 * side effects - Send a message to all connected servers, except the
 *                client 'one' (if non-NULL), as long as the servers
 *                support ALL capabs in 'caps', and NO capabs in 'nocaps'.
 *                If the server is a lazylink client, then it must know
 *                about source_p if non-NULL (unless LL_ICLIENT is specified,
 *                when source_p will be introduced where required) and
 *                chptr if non-NULL (unless LL_ICHANNEL is specified, when
 *                chptr will be introduced where required).
 *                Note: nothing will be introduced to a LazyLeaf unless
 *                the message is actually sent.
 *            
 * This function was written in an attempt to merge together the other
 * billion sendto_*serv*() functions, which sprung up with capabs,
 * lazylinks, uids, etc.
 * -davidt
 */
void 
sendto_server(struct Client *one, struct Client *source_p,
                   struct Channel *chptr, unsigned long caps,
                   unsigned long nocaps, unsigned long llflags,
                   const char *format, ...)
{
  va_list args;
  struct Client *client_p;
  dlink_node *ptr;
  dlink_node *ptr_next;
  buf_head_t linebuf;

  if (chptr != NULL)
    if (*chptr->chname == '&')
      return;

  linebuf_newbuf(&linebuf);
  va_start(args, format);
  linebuf_putmsg(&linebuf, format, &args, NULL);
  va_end(args);

  DLINK_FOREACH_SAFE(ptr, ptr_next, serv_list.head)
  {
    client_p = ptr->data;

    /* check against 'one' */
    if (one && (client_p == one->from))
      continue;
    /* check we have required capabs */
    if ((client_p->localClient->caps & caps) != caps)
      continue;
    /* check we don't have any forbidden capabs */
    if ((client_p->localClient->caps & nocaps) != 0)
      continue;

    if (ServerInfo.hub && IsCapable(client_p, CAP_LL))
    {
      /* check LL channel */
      if (chptr &&
          ((chptr->lazyLinkChannelExists &
            client_p->localClient->serverMask) == 0))
      {
        /* Only introduce the channel if we really will send this message */
        if (!(llflags & LL_ICLIENT) && source_p &&
            ((source_p->lazyLinkClientExists &
              client_p->localClient->serverMask) == 0))
          continue; /* we can't introduce the unknown source_p, skip */

        if (llflags & LL_ICHAN)
          burst_channel(client_p, chptr);
        else
          continue; /* we can't introduce the unknown chptr, skip */
      }
      /* check LL client */
      if (source_p &&
          ((source_p->lazyLinkClientExists &
            client_p->localClient->serverMask) == 0))
      {
        if (llflags & LL_ICLIENT)
          client_burst_if_needed(client_p,source_p);
        else
          continue; /* we can't introduce the unknown source_p, skip */
      }
    }
    send_linebuf(client_p, &linebuf);
  }
  linebuf_donebuf(&linebuf);
}

/*
 * sendto_common_channels_local()
 *
 * inputs	- pointer to client
 *		- pattern to send
 * output	- NONE
 * side effects	- Sends a message to all people on local server who are
 * 		  in same channel with user. 
 *		  used by m_nick.c and exit_one_client.
 */
void
sendto_common_channels_local(struct Client *user, const char *pattern, ...)
{
  va_list args;
  dlink_node *ptr;
  dlink_node *ptr_next;
  struct Channel *chptr;
  buf_head_t linebuf;

  linebuf_newbuf(&linebuf);
  va_start(args, pattern);
  linebuf_putmsg(&linebuf, pattern, &args, NULL);
  va_end(args);

  ++current_serial;

  if (user->user != NULL)
  {
    DLINK_FOREACH_SAFE(ptr, ptr_next, user->user->channel.head)
    {
      chptr = ptr->data;

      sendto_list_local(&chptr->locchanops, &linebuf);
#ifdef REQUIRE_OANDV
      sendto_list_local(&chptr->locchanops_voiced, &linebuf);
#endif
#ifdef HALFOPS
      sendto_list_local(&chptr->lochalfops, &linebuf);
#endif
      sendto_list_local(&chptr->locvoiced, &linebuf);
      sendto_list_local(&chptr->locpeons, &linebuf);
    }

    if (MyConnect(user) && (user->serial != current_serial))
      send_linebuf(user, &linebuf);
  }

  linebuf_donebuf(&linebuf);
} /* sendto_common_channels() */

/*
 * sendto_channel_local
 *
 * inputs	- int type, i.e. ALL_MEMBERS, NON_CHANOPS,
 *                ONLY_CHANOPS_VOICED, ONLY_CHANOPS
 *              - pointer to channel to send to
 *              - var args pattern
 * output	- NONE
 * side effects - Send a message to all members of a channel that are
 *		  locally connected to this server.
 */
void
sendto_channel_local(int type,
                     struct Channel *chptr,
                     const char *pattern, ...)
{
  va_list args;
  buf_head_t linebuf;

  linebuf_newbuf(&linebuf);
  va_start(args, pattern);
  linebuf_putmsg(&linebuf, pattern, &args, NULL);
  va_end(args);

  /* Serial number checking isn't strictly necessary, but won't hurt */
  ++current_serial;

  switch(type)
  {
    case NON_CHANOPS:
      sendto_list_local(&chptr->locvoiced, &linebuf);
      sendto_list_local(&chptr->locpeons, &linebuf);
      break;

    default:
    case ALL_MEMBERS:
      sendto_list_local(&chptr->locpeons, &linebuf);
    case ONLY_CHANOPS_HALFOPS_VOICED:
      sendto_list_local(&chptr->locvoiced, &linebuf);
#ifdef HALFOPS
    case ONLY_CHANOPS_HALFOPS:
      sendto_list_local(&chptr->lochalfops, &linebuf);
#endif
    case ONLY_CHANOPS:
      sendto_list_local(&chptr->locchanops, &linebuf);
#ifdef REQUIRE_OANDV
      sendto_list_local(&chptr->locchanops_voiced, &linebuf);
#endif
  }
  linebuf_donebuf(&linebuf);
} /* sendto_channel_local() */

/*
 * sendto_channel_local_butone
 *
 * inputs       - pointer to client to NOT send message to
 *              - int type, i.e. ALL_MEMBERS, NON_CHANOPS,
 *                ONLY_CHANOPS_VOICED, ONLY_CHANOPS
 *              - pointer to channel to send to
 *              - var args pattern
 * output       - NONE
 * side effects - Send a message to all members of a channel that are
 *                locally connected to this server except one.
 */
void       
sendto_channel_local_butone(struct Client *one, int type,
                            struct Channel *chptr,
                            const char *pattern, ...)
{
  va_list args;
  buf_head_t linebuf;

  linebuf_newbuf(&linebuf);
  va_start(args, pattern); 
  linebuf_putmsg(&linebuf, pattern, &args, NULL);
  va_end(args);

  /* Serial number checking isn't strictly necessary, but won't hurt */
  ++current_serial;

  switch(type)
  {
    case NON_CHANOPS:
      sendto_list_local_butone(one, &chptr->locvoiced, &linebuf);
      sendto_list_local_butone(one, &chptr->locpeons, &linebuf);
      break;
                     
    default:
    case ALL_MEMBERS:
      sendto_list_local_butone(one, &chptr->locpeons, &linebuf);
    case ONLY_CHANOPS_HALFOPS_VOICED:
      sendto_list_local_butone(one, &chptr->locvoiced, &linebuf);
#ifdef HALFOPS
    case ONLY_CHANOPS_HALFOPS:
      sendto_list_local_butone(one, &chptr->lochalfops, &linebuf);
#endif
    case ONLY_CHANOPS:
      sendto_list_local_butone(one, &chptr->locchanops, &linebuf);
#ifdef REQUIRE_OANDV
      sendto_list_local_butone(one, &chptr->locchanops_voiced, &linebuf);
#endif
  }
  linebuf_donebuf(&linebuf);
} /* sendto_channel_local_butone() */

/*
 * sendto_channel_remote
 *
 * inputs	- Client not to send towards
 *		- Client from whom message is from
 *		- int type, i.e. ALL_MEMBERS, NON_CHANOPS,
 *                ONLY_CHANOPS_VOICED, ONLY_CHANOPS
 *              - pointer to channel to send to
 *              - var args pattern
 * output	- NONE
 * side effects - Send a message to all members of a channel that are
 *		  remote to this server.
 */
void
sendto_channel_remote(struct Client *one,
		      struct Client *from, int type, int caps,
                      int nocaps, struct Channel *chptr, const char *pattern,
                      ...)
{
  va_list args;
  buf_head_t linebuf;

  linebuf_newbuf(&linebuf);
  va_start(args, pattern);
  linebuf_putmsg(&linebuf, pattern, &args, NULL);
  va_end(args);

  /* Serial number checking isn't strictly necessary, but won't hurt */
  ++current_serial;

  switch(type)
  {
    case NON_CHANOPS:
      sendto_list_remote(one, from, &chptr->voiced, caps, nocaps, &linebuf);
      sendto_list_remote(one, from, &chptr->peons, caps, nocaps, &linebuf);
      break;

    /* Fall through to accumulate lists... */
    default:
    case ALL_MEMBERS:
      sendto_list_remote(one, from, &chptr->peons, caps, nocaps, &linebuf);
    case ONLY_CHANOPS_HALFOPS_VOICED:
      sendto_list_remote(one, from, &chptr->voiced, caps, nocaps, &linebuf);
#ifdef HALFOPS
    case ONLY_CHANOPS_HALFOPS:
      sendto_list_remote(one, from, &chptr->halfops, caps, nocaps, &linebuf);
#endif
    case ONLY_CHANOPS:
      sendto_list_remote(one, from, &chptr->chanops, caps, nocaps, &linebuf);
#ifdef REQUIRE_OANDV
      sendto_list_remote(one, from, &chptr->chanops_voiced, caps, nocaps,
                         &linebuf);
#endif
  }
  linebuf_donebuf(&linebuf);
} /* sendto_channel_remote() */

/*
 * sendto_list_local
 *
 * inputs	- pointer to all members of this list
 *		- buffer to send
 *		- length of buffer
 * output	- NONE
 * side effects	- all members who are locally on this server on given list
 *		  are sent given message. Right now, its always a channel list
 *		  but there is no reason we could not use another dlink
 *		  list to send a message to a group of people.
 */
static void
sendto_list_local(dlink_list *list, buf_head_t *linebuf_ptr)
{
  dlink_node *ptr;
  dlink_node *ptr_next;
  struct Client *target_p;

  DLINK_FOREACH_SAFE(ptr, ptr_next, list->head)
  {
    if ((target_p = ptr->data) == NULL)
      continue;

    if (!MyConnect(target_p) || IsDead(target_p))
      continue;

    if (target_p->serial == current_serial)
      continue;

    target_p->serial = current_serial;

    send_linebuf(target_p, linebuf_ptr);
  } 
} /* sendto_list_local() */

/*
 * sendto_list_local_butone
 *
 * inputs       - pointer to client not to send to
 *              - pointer to all members of this list
 *              - buffer to send
 *              - length of buffer
 * output       - NONE
 * side effects - all members who are locally on this server on given list
 *                are sent given message, except one. Right now, its always
 *                a channel list but there is no reason we could not use
 *                another dlink list to send a message to a group of people.
 */
static void 
sendto_list_local_butone(struct Client *one, dlink_list *list,
                         buf_head_t *linebuf_ptr)
{
  dlink_node *ptr;
  dlink_node *ptr_next;
  struct Client *target_p;
    
  DLINK_FOREACH_SAFE(ptr, ptr_next, list->head)       
  {   
    if ((target_p = ptr->data) == NULL)
      continue;

    if (target_p == one)
      continue;

    if (!MyConnect(target_p) || IsDead(target_p))
      continue;
   
    if (target_p->serial == current_serial)
      continue;

    target_p->serial = current_serial;

    send_linebuf(target_p, linebuf_ptr);
  }
} /* sendto_list_local_butone() */

/*
 * sendto_list_remote(struct Client *one,
 *		      struct Client *from, dlink_list *list, int caps,
 *                    int nocaps, buf_head_t *linebuf)
 *
 * Input: one  => Client not to send towards
 *	  from => The client who sent this to us.
 *        list => The list of clients to check.
 *        caps => The capabilities servers we send this to must have.
 *      nocaps => The capabilities servers we send this to must lack.
 *     linebuf => The buffer to send.
 * Output: None.
 * Side-effects: Sends a linebuf to all the servers of all the users on
 *               the list.
 */
static void
sendto_list_remote(struct Client *one,
		   struct Client *from, dlink_list *list, int caps,
                   int nocaps, buf_head_t *linebuf)
{
  dlink_node *ptr;
  dlink_node *ptr_next;
  struct Client *target_p;

  DLINK_FOREACH_SAFE(ptr, ptr_next, list->head)
  {
    if ((target_p = ptr->data) == NULL)
      continue;

    if (MyConnect(target_p))
      continue;

    if (target_p->from == one->from) /* must skip the origin! */
      continue;

    if (((target_p->from->localClient->caps & caps) != caps) ||
        ((target_p->from->localClient->caps & nocaps) != 0))
      continue;
    if (target_p->from->serial == current_serial)
      continue;

    target_p->from->serial = current_serial;
    send_linebuf(target_p, linebuf);
  } 
} /* sendto_list_remote() */

/*
 ** match_it() and sendto_match_butone() ARE only used
 ** to send a msg to all ppl on servers/hosts that match a specified mask
 ** (used for enhanced PRIVMSGs) for opers
 **
 ** addition -- Armin, 8jun90 (gruner@informatik.tu-muenchen.de)
 **
 */

/*
 * match_it
 *
 * inputs	- client pointer to match on
 *		- actual mask to match
 *		- what to match on, HOST or SERVER
 * output	- 1 or 0 if match or not
 * side effects	- NONE
 */
static int
match_it(const struct Client *one, const char *mask, int what)

{
  if(what == MATCH_HOST)
    return match(mask, one->host);

  return match(mask, one->user->server);
} /* match_it() */

/*
 * sendto_match_butone
 *
 * Send to all clients which match the mask in a way defined on 'what';
 * either by user hostname or user servername.
 *
 * ugh. ONLY used by m_message.c to send an "oper magic" message. ugh.
 */
void
sendto_match_butone(struct Client *one, struct Client *from,
                    char *mask, int what,
                    const char *pattern, ...)
{
  va_list args;
  struct Client *client_p;
  dlink_node *ptr;
  dlink_node *ptr_next;
  buf_head_t local_linebuf;
  buf_head_t remote_linebuf;

  linebuf_newbuf(&local_linebuf);
  linebuf_newbuf(&remote_linebuf);
  va_start(args, pattern);

  linebuf_putmsg(&remote_linebuf, pattern, &args, ":%s ", from->name);
  linebuf_putmsg(&local_linebuf, pattern, &args, ":%s!%s@%s ", from->name,
		 from->username, from->host);

  va_end(args);

  /* scan the local clients */
  DLINK_FOREACH_SAFE(ptr, ptr_next, lclient_list.head)
  {
    client_p = ptr->data;

    if (client_p == one)  /* must skip the origin !! */
      continue;

    if (match_it(client_p, mask, what))
      send_linebuf(client_p, &local_linebuf);
  }

  /* Now scan servers */
  DLINK_FOREACH_SAFE(ptr, ptr_next, serv_list.head)
  {
    client_p = ptr->data;

    if (client_p == one) /* must skip the origin !! */
      continue;

    /*
     * The old code looped through every client on the
     * network for each server to check if the
     * server (client_p) has at least 1 client matching
     * the mask, using something like:
     *
     * for (target_p = GlobalClientList; target_p; target_p = target_p->next)
     *        if (IsRegisteredUser(target_p) &&
     *                        match_it(target_p, mask, what) &&
     *                        (target_p->from == client_p))
     *   vsendto_prefix_one(client_p, from, pattern, args);
     *
     * That way, we wouldn't send the message to
     * a server who didn't have a matching client.
     * However, on a network such as EFNet, that
     * code would have looped through about 50
     * servers, and in each loop, loop through
     * about 50k clients as well, calling match()
     * in each nested loop. That is a very bad
     * thing cpu wise - just send the message
     * to every connected server and let that
     * server deal with it.
     * -wnder
     */

    send_linebuf_remote(client_p, from, &remote_linebuf);
  }
  linebuf_donebuf(&local_linebuf);
  linebuf_donebuf(&remote_linebuf);

} /* sendto_match_butone() */


/*
 * sendto_anywhere
 *
 * inputs	- pointer to dest client
 * 		- pointer to from client
 * 		- varags
 * output	- NONE
 * side effects	- less efficient than sendto_remote and sendto_one
 * 		  but useful when one does not know where target "lives"
 */
void
sendto_anywhere(struct Client *to, struct Client *from,
                const char *pattern, ...)
{
  va_list args;
  buf_head_t linebuf;

  linebuf_newbuf(&linebuf);
  va_start(args, pattern);

  if (IsDead(to))
    return;

  if(MyClient(to))
  {
    if(IsServer(from))
      linebuf_putmsg(&linebuf, pattern, &args, ":%s ", from->name);
    else
      linebuf_putmsg(&linebuf, pattern, &args, ":%s!%s@%s ", from->name,
                     from->username, from->host);
  }
  else
  {
    if(IsCapable(to->from, CAP_UID))
      linebuf_putmsg(&linebuf, pattern, &args, ":%s ", ID(from));
    else
      linebuf_putmsg(&linebuf, pattern, &args, ":%s ", from->name);
  }
  va_end(args);

  if(MyClient(to))
    send_linebuf(to, &linebuf);
  else
    send_linebuf_remote(to, from, &linebuf);

  linebuf_donebuf(&linebuf);
}

/*
 * sendto_realops_flags
 *
 * inputs	- flag types of messages to show to real opers
 *		- flag indicating opers/admins
 *		- var args input message
 * output	- NONE
 * side effects	- Send to *local* ops only but NOT +s nonopers.
 */

void
sendto_realops_flags(int flags, int level, const char *pattern, ...)

{
  struct Client *client_p;
  char nbuf[IRCD_BUFSIZE*2];
  dlink_node *ptr;
  dlink_node *ptr_next;
  va_list args;
  buf_head_t linebuf;

  va_start(args, pattern);
  send_format(nbuf, pattern, args);
  va_end(args);

  DLINK_FOREACH_SAFE(ptr, ptr_next, oper_list.head)
  {
    client_p = ptr->data;

    /* If we're sending it to opers and theyre an admin, skip.
     * If we're sending it to admins, and theyre not, skip.
     */
    if(((level == L_ADMIN) && !IsAdmin(client_p)) ||
       ((level == L_OPER) && IsAdmin(client_p)))
      continue;

    if(client_p->umodes & flags)
    {
      linebuf_newbuf(&linebuf);
      linebuf_putmsg(&linebuf, NULL, NULL,
                     ":%s NOTICE %s :*** Notice -- %s", me.name,
                     client_p->name, nbuf);

      send_linebuf(client_p, &linebuf);

      linebuf_donebuf(&linebuf);
    }
  }
} /* sendto_realops_flags() */

/*
 * sendto_wallops_flags
 *
 * inputs       - flag types of messages to show to real opers
 *              - client sending request
 *              - var args input message
 * output       - NONE
 * side effects - Send a wallops to local opers
 */

void
sendto_wallops_flags(int flags, struct Client *source_p,
                     const char *pattern, ...)
{
  struct Client *client_p;
  dlink_node *ptr;
  dlink_node *ptr_next;
  va_list args;
  buf_head_t linebuf;

  linebuf_newbuf(&linebuf);
  
  va_start(args, pattern);

  if(IsPerson(source_p))
    linebuf_putmsg(&linebuf, pattern, &args, ":%s!%s@%s WALLOPS :",
                   source_p->name, source_p->username, source_p->host);
  else
    linebuf_putmsg(&linebuf, pattern, &args, ":%s WALLOPS :", source_p->name);

  va_end(args);

  switch(flags)
  {
    case FLAGS_OPERWALL:
      for (ptr = oper_list.head; ptr; ptr = ptr_next)
      {
        ptr_next = ptr->next;
        client_p = ptr->data;

        if(client_p->umodes & flags)
          send_linebuf(client_p, &linebuf);
      }
      break;
    case FLAGS_WALLOP:
    default:
      for (ptr = lclient_list.head; ptr; ptr = ptr_next)
      {
        ptr_next = ptr->next;
        client_p = ptr->data;

        if(client_p->umodes & flags)
            send_linebuf(client_p, &linebuf);
      }
  }
  linebuf_donebuf(&linebuf);
}


void sendto_gnotice_flags(int flags, int level, char *origin, 
        struct Client *source_p, struct Client *client_p, 
        const char *pattern, ...)
{
  struct Client *target_p;
  dlink_node *ptr;
  dlink_node *ptr_next;
  va_list args;
  buf_head_t linebuf;
  char nbuf[IRCD_BUFSIZE*2];

  va_start(args, pattern);

  send_format(nbuf, pattern, args);
  
  va_end(args);
  for (ptr = oper_list.head; ptr; ptr = ptr_next)
  {
    ptr_next = ptr->next;
    target_p = ptr->data;

    if(target_p->umodes & flags)
    {
      linebuf_newbuf(&linebuf);
      linebuf_putmsg(&linebuf, pattern, &args, ":%s NOTICE %s :",
              origin, target_p->name); 
      send_linebuf(target_p, &linebuf);
      linebuf_donebuf(&linebuf);
    }
  }
  sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, NOFLAGS,
    ":%s GNOTICE %s %d :%s", me.name, origin, flags, nbuf);
    
}


/*
 * ts_warn
 * inputs	- var args message
 * output	- NONE
 * side effects	- Call sendto_realops_flags, with some flood checking
 *		  (at most 5 warnings every 5 seconds)
 */

void
ts_warn(const char *pattern, ...)
{
  va_list args;
  char lbuf[LOG_BUFSIZE];
  static time_t last = 0;
  static int warnings = 0;

  /*
   ** if we're running with TS_WARNINGS enabled and someone does
   ** something silly like (remotely) connecting a nonTS server,
   ** we'll get a ton of warnings, so we make sure we don't send
   ** more than 5 every 5 seconds.  -orabidoo
   */

  if (CurrentTime - last < 5)
  {
    if (++warnings > 5)
      return;
  }
  else
  {
    last = CurrentTime;
    warnings = 0;
  }

  va_start(args, pattern);
  (void)send_format(lbuf, pattern, args);
  va_end(args);

  sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,"%s",lbuf);
  ilog(L_CRIT, "%s", lbuf);
} /* ts_warn() */




/*
 * kill_client
 *
 * inputs	- client to send kill towards
 * 		- pointer to client to kill
 * 		- reason for kill
 * output	- NONE
 * side effects	- NONE
 */

void
kill_client(struct Client *client_p,
            struct Client *diedie, const char *pattern, ...)
{
  va_list args;
  buf_head_t linebuf;

  linebuf_newbuf(&linebuf);
  
  va_start(args, pattern);

  /* XXX perhaps IsCapable should test for localClient itself ? -db */
  if(HasID(diedie) && client_p->localClient && IsCapable(client_p, CAP_UID))
    linebuf_putmsg(&linebuf, pattern, &args, ":%s KILL %s :",
                   me.name, ID(diedie));
  else
    linebuf_putmsg(&linebuf, pattern, &args, ":%s KILL %s :",
                   me.name, diedie->name);

  va_end(args);

  send_linebuf(client_p, &linebuf);
  linebuf_donebuf(&linebuf);
}


/*
 * kill_client_ll_serv_butone
 *
 * inputs	- pointer to client to not send to
 *		- pointer to client to kill
 * output	- NONE
 * side effects	- Send a KILL for the given client
 *		  message to all connected servers
 *                except the client 'one'. Also deal with
 *		  client being unknown to leaf, as in lazylink...
 */
void
kill_client_ll_serv_butone(struct Client *one, struct Client *source_p,
                           const char *pattern, ...)
{
  va_list args;
  int have_uid = 0;
  struct Client *client_p;
  dlink_node *ptr;
  dlink_node *ptr_next;
  buf_head_t linebuf_uid;
  buf_head_t linebuf_nick;

  va_start(args, pattern);

  if(HasID(source_p))
  {
    have_uid = 1;
    linebuf_newbuf(&linebuf_uid);
    linebuf_putmsg(&linebuf_uid, pattern, &args, ":%s KILL %s :",
                   me.name, ID(source_p));
  }

  linebuf_newbuf(&linebuf_nick);
  linebuf_putmsg(&linebuf_nick, pattern, &args, ":%s KILL %s :",
                 me.name, source_p->name);

  va_end(args);

  for(ptr = serv_list.head; ptr; ptr = ptr_next)
  {
    ptr_next = ptr->next;
    client_p = ptr->data;

    if (one && (client_p == one->from))
      continue;

    /* XXX perhaps IsCapable should test for localClient itself ? -db */
    if (client_p->localClient && IsCapable(client_p,CAP_LL) && ServerInfo.hub)
    {
      if((source_p->lazyLinkClientExists &
          client_p->localClient->serverMask) != 0)
      {
        if (have_uid && IsCapable(client_p, CAP_UID))
          send_linebuf(client_p, &linebuf_uid);
        else
          send_linebuf(client_p, &linebuf_nick);
      }
    }
    else
    {
      /* XXX perhaps IsCapable should test for localClient itself ? -db */
      if (have_uid && client_p->localClient && IsCapable(client_p, CAP_UID))
        send_linebuf(client_p, &linebuf_uid);
      else
        send_linebuf(client_p, &linebuf_nick);
    }
  }

  if (have_uid)
    linebuf_donebuf(&linebuf_uid);
  linebuf_donebuf(&linebuf_nick);
} 
