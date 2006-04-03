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
#include "client.h"
#include "common.h"
#include "dbuf.h"
#include "irc_string.h"
#include "ircd.h"
#include "handlers.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "sprintf_irc.h"
#include "s_conf.h"
#include "list.h"
#include "s_log.h"
#include "memory.h"
#include "hook.h"

#define LOG_BUFSIZE 2048

static void send_message(struct Client *, char *, int);
static void send_message_remote(struct Client *, struct Client *, char *, int);

/* global for now *sigh* */
unsigned long current_serial = 0L;

/* send_format()
 *
 * inputs	- buffer to format into
 *              - size of the buffer
 *		- format pattern to use
 *		- var args
 * output	- number of bytes formatted output
 * side effects	- modifies sendbuf
 */
static inline int
send_format(char *lsendbuf, int bufsize, const char *pattern, va_list args)
{
  int len;

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
  len = vsnprintf(lsendbuf, bufsize - 1, pattern, args);
  if (len > bufsize - 2)
    len = bufsize - 2;  /* required by some versions of vsnprintf */

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
   * Exactly, vsnprintf() does the job and we don't need to check
   * whether len > 510. We also don't need to terminate the buffer
   * with a '\0', since the dbuf code is raw-oriented. --adx
   */

  lsendbuf[len++] = '\r';
  lsendbuf[len++] = '\n';
  return (len);
}

/*
 ** send_message
 **      Internal utility which appends given buffer to the sockets
 **      sendq.
 */
static void
send_message(struct Client *to, char *buf, int len)
{
#ifdef INVARIANTS
  if (IsMe(to))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Trying to send message to myself!");
    return;
  }
#endif

  if (dbuf_length(&to->localClient->buf_sendq) + len > get_sendq(to))
  {
    if (IsServer(to))
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                           "Max SendQ limit exceeded for %s: %u > %lu",
                           get_client_name(to, HIDE_IP),
                           dbuf_length(&to->localClient->buf_sendq) + len,
                           get_sendq(to));
    if (IsClient(to))
      SetSendQExceeded(to);
    dead_link_on_write(to, 0);
    return;
  }

  dbuf_put(&to->localClient->buf_sendq, buf, len);

  /*
   ** Update statistics. The following is slightly incorrect
   ** because it counts messages even if queued, but bytes
   ** only really sent. Queued bytes get updated in SendQueued.
   */
  to->localClient->sendM += 1;
  me.localClient->sendM += 1;

  if (dbuf_length(&to->localClient->buf_sendq) >
      (IsServer(to) ? 1024 : 4096))
    send_queued_write(to);
}

/* send_message_remote()
 *
 * inputs	- pointer to client from message is being sent
 * 		- pointer to client to send to
 *		- pointer to preformatted buffer
 *		- length of input buffer
 * output	- none
 * side effects	- Despite the function name, this only sends to directly
 *		  connected clients.
 * 
 */
static void
send_message_remote(struct Client *to, struct Client *from,
                    char *buf, int len)
{
  if (!MyConnect(to))
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
			 "server send message to %s [%s] dropped from %s(Not local server)",
			 to->name, to->from->name, from->name);
    return;
  }

  if (ServerInfo.hub && IsCapable(to, CAP_LL))
  {
    if (((from->lazyLinkClientExists &
          to->localClient->serverMask) == 0))
      client_burst_if_needed(to, from);
  }

  /* Optimize by checking if (from && to) before everything */
  /* we set to->from up there.. */

  if (!MyClient(from) && IsPerson(to) && (to == from->from))
  {
    if (IsServer(from))
    {
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                           "Send message to %s [%s] dropped from %s(Fake Dir)",
                           to->name, to->from->name, from->name);
      return;
    }

    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                         "Ghosted: %s[%s@%s] from %s[%s@%s] (%s)",
                         to->name, to->username, to->host,
                         from->name, from->username, from->host,
                         to->from->name);

    sendto_server(NULL, to, NULL, NOCAPS, NOCAPS, NOFLAGS,
                  ":%s KILL %s :%s (%s[%s@%s] Ghosted %s)",
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

  send_message(to, buf, len);
}

/*
 ** sendq_unblocked
 **      Called when a socket is ready for writing.
 */
static void
sendq_unblocked(int fd, struct Client *client_p)
{
  ClearSendqBlocked(client_p);
  /* let send_queued_write be executed by send_queued_all */
}

/*
 ** slinkq_unblocked
 **      Called when a server control socket is ready for writing.
 */
static void
slinkq_unblocked(int fd, struct Client *client_p)
{
  ClearSlinkqBlocked(client_p);
  send_queued_slink_write(client_p);
}

/*
 ** send_queued_write
 **      This is called when there is a chance that some output would
 **      be possible. This attempts to empty the send queue as far as
 **      possible, and then if any data is left, a write is rescheduled.
 */
void
send_queued_write(struct Client *to)
{
  int retlen;
  int fd;
#ifdef HAVE_LIBCRYPTO
  fde_t *F;
#endif
#ifndef NDEBUG
  struct hook_io_data hdata;
#endif
  struct dbuf_block *first;
  
  /*
   ** Once socket is marked dead, we cannot start writing to it,
   ** even if the error is removed...
   */
  if (IsDead(to) || IsSendqBlocked(to))
    return;  /* no use calling send() now */

  /* get the file descriptor from the client structure */
  fd = to->localClient->fd;

  /* Next, lets try to write some data */

  if (dbuf_length(&to->localClient->buf_sendq))
  {
#ifndef NDEBUG
    hdata.connection = to;
#endif
    do {
      first = to->localClient->buf_sendq.blocks.head->data;
#ifdef HAVE_LIBCRYPTO
      
      F = (fd > -1)? &fd_table[fd] : NULL;

      if (F && F->ssl)
      {
         ilog(L_DEBUG, "send_queued_write: calling SSL_write");
         if ((retlen = sendSSL(F, first->data, first->size)) <= 0)
            break;
      }
      else
      {
#endif
         ilog(L_DEBUG, "send_queued_write: calling normal send");
         if ((retlen = send(fd, first->data,
                            first->size, 0)) <= 0)
            break;
#ifdef HAVE_LIBCRYPTO
      }
#endif

#ifndef NDEBUG
      hdata.data = ((struct dbuf_block *)
                    to->localClient->buf_sendq.blocks.head->data)->data;
      hdata.len = retlen;
      hook_call_event("iosend", &hdata);
#endif
      dbuf_delete(&to->localClient->buf_sendq, retlen);

      /* We have some data written .. update counters */
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
    } while (dbuf_length(&to->localClient->buf_sendq));

    if ((retlen < 0) && (ignoreErrno(errno)))
    {
      /* we have a non-fatal error, reschedule a write */
      SetSendqBlocked(to);
      comm_setselect(fd, FDLIST_IDLECLIENT, COMM_SELECT_WRITE,
                     (PF *)sendq_unblocked, (void *)to, 0);
    }
    else if (retlen <= 0)
    {
      dead_link_on_write(to, errno);
      return;
    }
  }
}

/*
 ** send_queued_slink_write
 **      This is called when there is a chance the some output would
 **      be possible. This attempts to empty the send queue as far as
 **      possible, and then if any data is left, a write is rescheduled.
 */
void
send_queued_slink_write(struct Client *to)
{
  int retlen;
#ifdef HAVE_LIBCRYPTO
  fde_t *F;
#endif
  int ctrlfd;

  /*
   ** Once socket is marked dead, we cannot start writing to it,
   ** even if the error is removed...
   */
  if (IsDead(to) || IsSlinkqBlocked(to))
    return;  /* no use calling send() now */

  /* get the file descriptor from the client structure */
  ctrlfd = to->localClient->ctrlfd;

  /* Next, lets try to write some data */
  if (to->localClient->slinkq != NULL)
  {
#ifdef HAVE_LIBCRYPTO
     F = (ctrlfd > -1)? &fd_table[ctrlfd] : NULL;

     if (F && F->ssl)
     {
        ilog(L_DEBUG, "send_queued_slink_write: calling SSL_write");
        retlen = sendSSL(
           F, to->localClient->slinkq + to->localClient->slinkq_ofs,
           to->localClient->slinkq_len);
     }
     else
     {
#endif
        ilog(L_DEBUG, "send_queued_slink_write: calling normal send");
        retlen = send(ctrlfd,
                      to->localClient->slinkq + to->localClient->slinkq_ofs,
                      to->localClient->slinkq_len, 0);
#ifdef HAVE_LIBCRYPTO
     }
#endif
    if (retlen < 0)
    {
      /* If we have a fatal error */
      if (!ignoreErrno(errno))
      {
	dead_link_on_write(to, errno);
	return;
      }
    }
    else if (retlen == 0)
    {
      /* 0 bytes is an EOF .. */
      dead_link_on_write(to, 0);
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

    /* Finally, if we have any more data, reschedule a write */
    if (to->localClient->slinkq_len)
    {
      SetSlinkqBlocked(to);
      comm_setselect(ctrlfd, FDLIST_IDLECLIENT, COMM_SELECT_WRITE, 
                     (PF *)slinkq_unblocked, (void *)to, 0);
    }
  }
}

/* send_queued_all()
 *
 * input        - NONE
 * output       - NONE
 * side effects - try to flush sendq of each client
 */
void
send_queued_all(void)
{
  dlink_node *ptr;

  /* Servers are processed first, mainly because this can generate
   * a notice to opers, which is to be delivered by this function.
   */
  DLINK_FOREACH(ptr, serv_list.head)
    send_queued_write((struct Client *) ptr->data);

  DLINK_FOREACH(ptr, unknown_list.head)
    send_queued_write((struct Client *) ptr->data);

  DLINK_FOREACH(ptr, local_client_list.head)
    send_queued_write((struct Client *) ptr->data);

  /* NOTE: This can still put clients on aborted_list; unfortunately,
   * exit_aborted_clients takes precedence over send_queued_all,
   * because exiting clients can generate server/oper traffic.
   * The easiest approach is dealing with aborted clients in the next I/O lap.
   * -adx
   */
}

/* sendto_one()
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
  char buffer[IRCD_BUFSIZE];
  int len;

  if (to->from != NULL)
    to = to->from;
  if (IsDead(to))
    return; /* This socket has already been marked as dead */

  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  send_message(to, buffer, len);
}

/* sendto_one_prefix()
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
  char buffer[IRCD_BUFSIZE];
  int len;

  if (to->from != NULL)
    to = to->from;
  if (IsDead(to))
    return; /* This socket has already been marked as dead */

  len = ircsprintf(buffer, ":%s ", (IsServer(to) && IsCapable(to, CAP_SID)) ?
                                   ID(prefix) : prefix->name);

  va_start(args, pattern);
  len += send_format(&buffer[len], IRCD_BUFSIZE - len, pattern, args);
  va_end(args);

  send_message(to, buffer, len);
}

/* sendto_channel_butone()
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
                      struct Channel *chptr, const char *command,
                      const char *pattern, ...)
{
  va_list alocal, aremote, auid;
  char local_buf[IRCD_BUFSIZE];
  char remote_buf[IRCD_BUFSIZE];
  char uid_buf[IRCD_BUFSIZE];
  int local_len, remote_len, uid_len;
  dlink_node *ptr;
  dlink_node *ptr_next;
  struct Client *target_p;

  if (IsServer(from))
    local_len = ircsprintf(local_buf, ":%s %s %s ",
                           from->name, command, chptr->chname);
  else
    local_len = ircsprintf(local_buf, ":%s!%s@%s %s %s ",
                           from->name, from->username, from->host,
                           command, chptr->chname);
  remote_len = ircsprintf(remote_buf, ":%s %s %s ",
                          from->name, command, chptr->chname);
  uid_len = ircsprintf(uid_buf, ":%s %s %s ",
                       ID(from), command, chptr->chname);

  va_start(alocal, pattern);
  va_start(aremote, pattern);
  va_start(auid, pattern);
  local_len += send_format(&local_buf[local_len], IRCD_BUFSIZE - local_len,
                           pattern, alocal);
  remote_len += send_format(&remote_buf[remote_len], IRCD_BUFSIZE - remote_len,
                            pattern, aremote);
  uid_len += send_format(&uid_buf[uid_len], IRCD_BUFSIZE - uid_len, pattern,
                         auid);
  va_end(auid);
  va_end(aremote);
  va_end(alocal);

  ++current_serial;

  DLINK_FOREACH_SAFE(ptr, ptr_next, chptr->members.head)
  {
    target_p = ((struct Membership *)ptr->data)->client_p;
    assert(target_p != NULL);

    if (IsDefunct(target_p) || target_p->from == one)
      continue;

    if (MyConnect(target_p) && IsRegisteredUser(target_p))
    {
      if (target_p->serial != current_serial)
      {
        send_message(target_p, local_buf, local_len);
        target_p->serial = current_serial;
      }
    }
    else
    {
      /* Now check whether a message has been sent to this
       * remote link already
       */
      if (target_p->from->serial != current_serial)
      {
        if (IsCapable(target_p->from, CAP_SID))
          send_message_remote(target_p->from, from, uid_buf, uid_len);
        else
          send_message_remote(target_p->from, from, remote_buf, remote_len);
        target_p->from->serial = current_serial;
      }
    }
  }
}

/* sendto_server()
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
  char buffer[IRCD_BUFSIZE];
  int len;

  if (chptr != NULL)
  {
    if (chptr->chname[0] != '#')
      return;
  }

  va_start(args, format);
  len = send_format(buffer, IRCD_BUFSIZE, format, args);
  va_end(args);

  DLINK_FOREACH(ptr, serv_list.head)
  {
    client_p = ptr->data;

    /* If dead already skip */
    if (IsDead(client_p))
      continue;
    /* check against 'one' */
    if (one != NULL && (client_p == one->from))
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
      if (chptr != NULL &&
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
    send_message(client_p, buffer, len);
  }
}

/* sendto_common_channels_local()
 *
 * inputs	- pointer to client
 *		- pattern to send
 * output	- NONE
 * side effects	- Sends a message to all people on local server who are
 * 		  in same channel with user. 
 *		  used by m_nick.c and exit_one_client.
 */
void
sendto_common_channels_local(struct Client *user, int touser,
                             const char *pattern, ...)
{
  va_list args;
  dlink_node *uptr;
  dlink_node *cptr;
  struct Channel *chptr;
  struct Membership *ms;
  struct Client *target_p;
  char buffer[IRCD_BUFSIZE];
  int len;

  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  ++current_serial;

  DLINK_FOREACH(cptr, user->user->channel.head)
  {
    chptr = ((struct Membership *) cptr->data)->chptr;
    assert(chptr != NULL);

    DLINK_FOREACH(uptr, chptr->locmembers.head)
    {
      ms = uptr->data;
      target_p = ms->client_p;
      assert(target_p != NULL);

      if (target_p == user || IsDefunct(target_p) ||
          target_p->serial == current_serial)
        continue;

      target_p->serial = current_serial;
      send_message(target_p, buffer, len);
    }
  }

  if (touser && MyConnect(user) && !IsDead(user) &&
      user->serial != current_serial)
    send_message(user, buffer, len);
}

/* sendto_channel_local()
 *
 * inputs	- member status mask, e.g. CHFL_CHANOP | CHFL_VOICE
 *              - pointer to channel to send to
 *              - var args pattern
 * output	- NONE
 * side effects - Send a message to all members of a channel that are
 *		  locally connected to this server.
 */
void
sendto_channel_local(int type, struct Channel *chptr, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;
  dlink_node *ptr;
  struct Membership *ms;
  struct Client *target_p;

  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  /* Serial number checking isn't strictly necessary, but won't hurt */
  ++current_serial;

  DLINK_FOREACH(ptr, chptr->locmembers.head)
  {
    ms = ptr->data;
    target_p = ms->client_p;

    if (type != 0 && (ms->flags & type) == 0)
      continue;

    if (IsDefunct(target_p) || target_p->serial == current_serial)
      continue;

    target_p->serial = current_serial;

    send_message(target_p, buffer, len);
  }
}

/* sendto_channel_local_butone()
 *
 * inputs       - pointer to client to NOT send message to
 *              - member status mask, e.g. CHFL_CHANOP | CHFL_VOICE
 *              - pointer to channel to send to
 *              - var args pattern
 * output       - NONE
 * side effects - Send a message to all members of a channel that are
 *                locally connected to this server except one.
 */
void       
sendto_channel_local_butone(struct Client *one, int type,
			    struct Channel *chptr, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;
  struct Client *target_p;
  struct Membership *ms;
  dlink_node *ptr;

  va_start(args, pattern); 
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  /* Serial number checking isn't strictly necessary, but won't hurt */
  ++current_serial;

  DLINK_FOREACH(ptr, chptr->locmembers.head)       
  {   
    ms = ptr->data;
    target_p = ms->client_p;

    if (type != 0 && (ms->flags & type) == 0)
      continue;

    if (target_p == one || IsDefunct(target_p) ||
        target_p->serial == current_serial)
      continue;

    target_p->serial = current_serial;

    send_message(target_p, buffer, len);
  }
}


/* sendto_channel_remote()
 *
 * inputs	- Client not to send towards
 *		- Client from whom message is from
 *		- member status mask, e.g. CHFL_CHANOP | CHFL_VOICE
 *              - pointer to channel to send to
 *              - var args pattern
 * output	- NONE
 * side effects - Send a message to all members of a channel that are
 *		  remote to this server.
 */
void
sendto_channel_remote(struct Client *one, struct Client *from, int type, int caps,
                      int nocaps, struct Channel *chptr, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;
  dlink_node *ptr;
  struct Client *target_p;
  struct Membership *ms;


  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  /* Serial number checking isn't strictly necessary, but won't hurt */
  ++current_serial;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;
    target_p = ms->client_p;

    if (type != 0 && (ms->flags & type) == 0)
      continue;

    if (MyConnect(target_p))
      continue;
    target_p = target_p->from;

    if (target_p == one->from ||
        ((target_p->from->localClient->caps & caps) != caps) ||
        ((target_p->from->localClient->caps & nocaps) != 0) ||
        target_p->from->serial == current_serial)
      continue;

    target_p->serial = current_serial;

    send_message(target_p, buffer, len);
  } 
}

/*
 ** match_it() and sendto_match_butone() ARE only used
 ** to send a msg to all ppl on servers/hosts that match a specified mask
 ** (used for enhanced PRIVMSGs) for opers
 **
 ** addition -- Armin, 8jun90 (gruner@informatik.tu-muenchen.de)
 **
 */

/* match_it()
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
  if (what == MATCH_HOST)
    return(match(mask, one->host));

  return(match(mask, one->user->server->name));
}

/* sendto_match_butone()
 *
 * Send to all clients which match the mask in a way defined on 'what';
 * either by user hostname or user servername.
 *
 * ugh. ONLY used by m_message.c to send an "oper magic" message. ugh.
 */
void
sendto_match_butone(struct Client *one, struct Client *from, char *mask,
                    int what, const char *pattern, ...)
{
  va_list alocal, aremote;
  struct Client *client_p;
  dlink_node *ptr, *ptr_next;
  char local_buf[IRCD_BUFSIZE], remote_buf[IRCD_BUFSIZE];
  int local_len = ircsprintf(local_buf, ":%s!%s@%s ", from->name,
                             from->username, from->host);
  int remote_len = ircsprintf(remote_buf, ":%s ", from->name);

  va_start(alocal, pattern);
  va_start(aremote, pattern);
  local_len += send_format(&local_buf[local_len], IRCD_BUFSIZE - local_len,
                           pattern, alocal);
  remote_len += send_format(&remote_buf[remote_len], IRCD_BUFSIZE - remote_len,
                            pattern, aremote);
  va_end(aremote);
  va_end(alocal);

  /* scan the local clients */
  DLINK_FOREACH(ptr, local_client_list.head)
  {
    client_p = ptr->data;

    if (client_p != one && !IsDefunct(client_p) &&
        match_it(client_p, mask, what))
      send_message(client_p, local_buf, local_len);
  }

  /* Now scan servers */
  DLINK_FOREACH_SAFE(ptr, ptr_next, serv_list.head)
  {
    client_p = ptr->data;

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
    if (client_p != one && !IsDefunct(client_p))
      send_message_remote(client_p, from, remote_buf, remote_len);
  }
}

/* sendto_match_servs()
 *
 * inputs       - source client
 *              - mask to send to
 *              - capab needed
 *              - data
 * outputs	- none
 * side effects	- data sent to servers matching with capab
 */
void
sendto_match_servs(struct Client *source_p, const char *mask, int cap,
                   const char *pattern, ...)
{
  va_list args;
  struct Client *target_p;
  dlink_node *ptr;
  char buffer[BUFSIZE];
  int found = 0;

  va_start(args, pattern);
  send_format(&buffer[0], IRCD_BUFSIZE, pattern, args);
  va_end(args);

  current_serial++;

  DLINK_FOREACH(ptr, global_serv_list.head)
  {
    target_p = ptr->data;

    /* Do not attempt to send to ourselves, or the source */
    if (IsMe(target_p) || target_p->from == source_p->from)
      continue;

    if (target_p->from->serial == current_serial)
      continue;

    if (match(mask, target_p->name))
    {
      /*
       * if we set the serial here, then we'll never do a
       * match() again, if !IsCapable()
       */
      target_p->from->serial = current_serial;
      found++;

      if (!IsCapable(target_p->from, cap))
        continue;

      sendto_anywhere(target_p, source_p, buffer);
    }
  }

  if (!found && IsClient(source_p) && !match(mask, me.name))
    sendto_one(source_p, form_str(ERR_NOSUCHSERVER),
               me.name, source_p->name, mask);
}

/* sendto_anywhere()
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
  char buffer[IRCD_BUFSIZE];
  int len;
  struct Client *send_to = (to->from != NULL ? to->from : to);

  if (IsDead(send_to))
    return;

  if (MyClient(to))
  {
    if (IsServer(from))
      len = ircsprintf(buffer, ":%s ", from->name);
    else
      len = ircsprintf(buffer, ":%s!%s@%s ",
                       from->name, from->username, from->host);
  }
  else len = ircsprintf(buffer, ":%s ",
                        IsCapable(send_to, CAP_SID) ? ID(from) : from->name);

  va_start(args, pattern);
  len += send_format(&buffer[len], IRCD_BUFSIZE - len, pattern, args);
  va_end(args);

  if(MyClient(to))
    send_message(send_to, buffer, len);
  else
    send_message_remote(send_to, from, buffer, len);
}

/* sendto_realops_flags()
 *
 * inputs	- flag types of messages to show to real opers
 *		- flag indicating opers/admins
 *		- var args input message
 * output	- NONE
 * side effects	- Send to *local* ops only but NOT +s nonopers.
 */
void
sendto_realops_flags(unsigned int flags, int level, const char *pattern, ...)
{
  struct Client *client_p;
  char nbuf[IRCD_BUFSIZE];
  dlink_node *ptr;
  va_list args;

  va_start(args, pattern);
  vsnprintf(nbuf, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  DLINK_FOREACH(ptr, oper_list.head)
  {
    client_p = ptr->data;
    assert(client_p->umodes & UMODE_OPER);

    /* If we're sending it to opers and theyre an admin, skip.
     * If we're sending it to admins, and theyre not, skip.
     */
    if (((level == L_ADMIN) && !IsAdmin(client_p)) ||
	((level == L_OPER) && IsAdmin(client_p)))
      continue;

    if (client_p->umodes & flags)
      sendto_one(client_p, ":%s NOTICE %s :*** Notice -- %s",
                 me.name, client_p->name, nbuf);
  }
}

/* sendto_wallops_flags()
 *
 * inputs       - flag types of messages to show to real opers
 *              - client sending request
 *              - var args input message
 * output       - NONE
 * side effects - Send a wallops to local opers
 */
void
sendto_wallops_flags(unsigned int flags, struct Client *source_p,
                     const char *pattern, ...)
{
  struct Client *client_p;
  dlink_node *ptr;
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;

  if (IsPerson(source_p))
    len = ircsprintf(buffer, ":%s!%s@%s WALLOPS :",
                     source_p->name, source_p->username, source_p->host); 
  else
    len = ircsprintf(buffer, ":%s WALLOPS :", source_p->name); 

  va_start(args, pattern);
  len += send_format(&buffer[len], IRCD_BUFSIZE - len, pattern, args);
  va_end(args);

  switch(flags)
  {
      case UMODE_OPERWALL:
        DLINK_FOREACH(ptr, oper_list.head)
        {
          client_p = ptr->data;
          assert(client_p->umodes & UMODE_OPER);

          if ((client_p->umodes & flags) && !IsDefunct(client_p))
            send_message(client_p, buffer, len);
        }
        break;
      case UMODE_WALLOP:
        DLINK_FOREACH(ptr, local_client_list.head)
        {
            client_p = ptr->data;
            if((client_p->umodes & flags) && !IsDefunct(client_p))
              send_message(client_p, buffer, len);
        }
        break;
  }
}

void
sendto_gnotice_flags(int flags, int level, char *origin,
        struct Client *source_p, struct Client *client_p,
        const char *pattern, ...)
{
  struct Client *target_p;
  dlink_node *ptr;
  dlink_node *ptr_next;
  va_list args;
  char nbuf[IRCD_BUFSIZE*2];

  va_start(args, pattern);
  vsnprintf(nbuf, IRCD_BUFSIZE, pattern, args);
  va_end(args);
  
  DLINK_FOREACH(ptr, oper_list.head)
  {
    ptr_next = ptr->next;
    target_p = ptr->data;

    if(target_p->umodes & flags)
    {
      /* If we're sending it to opers and theyre an admin, skip.
       * If we're sending it to admins, and theyre not, skip.
       * Note that this wont make a difference at the other end because I
       * cocked up when i first did gnotices
       */
      if (((level == L_ADMIN) && !IsAdmin(target_p)) ||
              ((level == L_OPER) && IsAdmin(target_p)))
        continue;

      sendto_one(target_p, ":%s NOTICE %s :%s", origin, target_p->name, nbuf);
    }
  }
  sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, NOFLAGS,
    ":%s GNOTICE %s %d :%s", me.name, origin, flags, nbuf);
}


/* ts_warn()
 *
 * inputs	- var args message
 * output	- NONE
 * side effects	- Call sendto_realops_flags, with some flood checking
 *		  (at most 5 warnings every 5 seconds)
 */
void
ts_warn(const char *pattern, ...)
{
  va_list args;
  char buffer[LOG_BUFSIZE];
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
  vsprintf_irc(buffer, pattern, args);
  va_end(args);

  sendto_gnotice_flags(UMODE_ALL, L_ALL,  me.name, &me, NULL, "%s", buffer);
  ilog(L_CRIT, "%s", buffer);
}

/* kill_client()
 *
 * inputs	- client to send kill towards
 * 		- pointer to client to kill
 * 		- reason for kill
 * output	- NONE
 * side effects	- NONE
 */
void
kill_client(struct Client *client_p, struct Client *diedie,
            const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;

  if (client_p->from != NULL)
    client_p = client_p->from;
  if (IsDead(client_p))
    return;

  len = ircsprintf(buffer, ":%s KILL %s :", me.name,
                   IsCapable(client_p, CAP_SID) ? ID(diedie) : diedie->name);

  va_start(args, pattern);
  len += send_format(&buffer[len], IRCD_BUFSIZE - len, pattern, args);
  va_end(args);

  send_message(client_p, buffer, len);
}

/* kill_client_ll_serv_butone()
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
  char buf_uid[IRCD_BUFSIZE], buf_nick[IRCD_BUFSIZE];
  int len_uid = 0, len_nick;

  if (HasID(source_p))
  {
    va_start(args, pattern);
    have_uid = 1;
    len_uid = ircsprintf(buf_uid, ":%s KILL %s :", me.name, ID(source_p));
    len_uid += send_format(&buf_uid[len_uid], IRCD_BUFSIZE - len_uid, pattern,
                           args);
    va_end(args);
  }
  va_start(args, pattern);
  len_nick = ircsprintf(buf_nick, ":%s KILL %s :", me.name, source_p->name);
  len_nick += send_format(&buf_nick[len_nick], IRCD_BUFSIZE - len_nick, pattern,
                          args);
  va_end(args);

  DLINK_FOREACH(ptr, serv_list.head)
  {
    client_p = ptr->data;

    if (one != NULL && (client_p == one->from))
      continue;
    if (IsDefunct(client_p))
      continue;

    /* XXX perhaps IsCapable should test for localClient itself ? -db */
    if (client_p->localClient == NULL || !IsCapable(client_p, CAP_LL) ||
        !ServerInfo.hub ||
        (source_p->lazyLinkClientExists & client_p->localClient->serverMask))
    {
      if (have_uid && IsCapable(client_p, CAP_SID))
        send_message(client_p, buf_uid, len_uid);
      else
        send_message(client_p, buf_nick, len_nick);
    }
  }
} 

#ifdef HAVE_LIBCRYPTO
int sendSSL(fde_t *F, const char* data, const size_t length)
{
   extern char *get_ssl_error(int);
   int retval = -1;
   int alerted = 0;

   ilog(L_DEBUG, "sendSSL called");

   if (F->flags.accept_write) {
      int ret;
      ilog(L_DEBUG, "accept_write true");
      if ((ret = SSL_accept(F->ssl)) > 0) {
         if (!alerted)
            ilog(L_DEBUG, 
                 "SSL_accept() for %s (socket %d) wanting WRITE succeeded!",
                 inetntoa((char *)&(F->connect.hostaddr)), F->fd);
         F->flags.accept_write = 0;
      } else if (F->accept_failures < 4) {
         int val = SSL_get_error(F->ssl, ret);  		
         ilog(L_DEBUG, 
              "SSL_accept() for %s (socket %d) wanting WRITE error! -- %s",
              inetntoa((char *)&(F->connect.hostaddr)), F->fd,
              (val == SSL_ERROR_SSL)?
              ERR_error_string(ERR_get_error(), NULL) :
              get_ssl_error(val));
         ilog(L_DEBUG, "BIO_sock_should_retry(): %d", 
              BIO_sock_should_retry(ret));
         if (val == SSL_ERROR_SYSCALL) {
            int err = ERR_get_error();
            if (err)
               ilog(L_DEBUG, "ERR_get_error() -- %s",
                    ERR_error_string(err, NULL));
            else
               ilog(L_DEBUG, "more error info -- %s",
                    (ret == -1)? strerror(errno) : "got EOF, protocol violation");  
         }
         ilog(L_DEBUG, 
              "SSL_state_string_long(): %s",
              SSL_state_string_long(F->ssl));
         F->accept_failures++;
      }
      retval = -1;
      errno = EAGAIN;
   } 
   else 
   {
      retval = SSL_write(F->ssl, data, length);
      
      if (retval <= 0 && !alerted) {
         int val = SSL_get_error(F->ssl, retval);
         ilog(L_DEBUG, "SSL_write() for %s (socket %d) ERROR! -- %s",
              inetntoa((char *)&(F->connect.hostaddr)), F->fd,
              (val == SSL_ERROR_SSL)?
              ERR_error_string(ERR_get_error(), NULL) :
              get_ssl_error(val));
         if (val == SSL_ERROR_SYSCALL) {
            int err = ERR_get_error();
            if (err)
               ilog(L_DEBUG, "ERR_get_error() -- %s",
                    ERR_error_string(err, NULL));
            else
               ilog(L_DEBUG, "more error info -- %s",
                    (retval == -1)? strerror(errno) : "got EOF, protocol violation");  
         } else {
            errno = EAGAIN;
         }
      }
   }

   ilog(L_DEBUG, "sendSSL returning %d", retval);

   return retval;
}
#endif
