/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_auth.c: Functions for querying a users ident.
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

/*
 * Changes:
 *   July 6, 1999 - Rewrote most of the code here. When a client connects
 *     to the server and passes initial socket validation checks, it
 *     is owned by this module (auth) which returns it to the rest of the
 *     server when dns and auth queries are finished. Until the client is
 *     released, the server does not know it exists and does not process
 *     any messages from it.
 *     --Bleep  Thomas Helvey <tomh@inxpress.net>
 */
#include "stdinc.h"
#include "tools.h"
#include "list.h"
#include "fdlist.h"
#include "s_auth.h"
#include "s_conf.h"
#include "client.h"
#include "common.h"
#include "event.h"
#include "hook.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "packet.h"
#include "levent.h"
#include "s_bsd.h"
#include "s_log.h"
#include "send.h"
#include "memory.h"

static const char *HeaderMessages[] = {
  ":%s NOTICE AUTH :*** Looking up your hostname...",
  ":%s NOTICE AUTH :*** Found your hostname",
  ":%s NOTICE AUTH :*** Couldn't look up your hostname",
  ":%s NOTICE AUTH :*** Checking Ident",
  ":%s NOTICE AUTH :*** Got Ident response",
  ":%s NOTICE AUTH :*** No Ident response",
  ":%s NOTICE AUTH :*** Your forward and reverse DNS do not match, ignoring hostname.",
  ":%s NOTICE AUTH :*** Your hostname is too long, ignoring hostname"
};

enum {
  REPORT_DO_DNS,
  REPORT_FIN_DNS,
  REPORT_FAIL_DNS,
  REPORT_DO_ID,
  REPORT_FIN_ID,
  REPORT_FAIL_ID,
  REPORT_IP_MISMATCH,
  REPORT_HOST_TOOLONG
};

#define sendheader(c, i) sendto_one((c), HeaderMessages[(i)], me.name)

/*
 * Ok, the original was confusing.
 * Now there are two lists, an auth request can be on both at the same time
 * or only on one or the other.
 * - Dianora
 */
static dlink_list auth_doing_dns_list   = { NULL, NULL, 0 };
static dlink_list auth_doing_ident_list = { NULL, NULL, 0 };

static EVH timeout_auth_queries_event;

static PF read_auth_reply;
static CNCB auth_connect_callback;
static CBFUNC start_auth;

struct Callback *auth_cb = NULL;

/* init_auth()
 *
 * Initialise the auth code
 */
void
init_auth(void)
{
  auth_cb = register_callback("start_auth", start_auth);
  eventAddIsh("timeout_auth_queries_event", timeout_auth_queries_event, NULL, 1);
}

/*
 * make_auth_request - allocate a new auth request
 */
static struct AuthRequest *
make_auth_request(struct Client *client)
{
  struct AuthRequest *request = MyMalloc(sizeof(struct AuthRequest));

  request->client  = client;
  request->timeout = CurrentTime + CONNECTTIMEOUT;

  return request;
}

/*
 * release_auth_client - release auth client from auth system
 * this adds the client into the local client lists so it can be read by
 * the main io processing loop
 */
void
release_auth_client(struct Client *client)
{
  /*
   * When a client has auth'ed, we want to start reading what it sends
   * us. This is what read_packet() does.
   *     -- adrian
   */
  client->localClient->allow_read = MAX_FLOOD;
  comm_setflush(&client->localClient->fd, 1000, flood_recalc, client);

  if ((client->node.prev != NULL) || (client->node.next != NULL))
  {
    sendto_realops_flags(UMODE_ALL, L_OPER,
			 "already linked %s at %s:%d", client->name,
			 __FILE__, __LINE__);
    ilog(L_ERROR, "already linked %s at %s:%d", client->name,
	 __FILE__, __LINE__);
    assert(0==5);
  }
  else
    dlinkAdd(client, &client->node, &global_client_list);

  client->since  = client->lasttime = client->firsttime = CurrentTime;
  client->flags |= FLAGS_FINISHED_AUTH;

  read_packet(&client->localClient->fd, client);
}
 
/*
 * auth_dns_callback - called when resolver query finishes
 * if the query resulted in a successful search, hp will contain
 * a non-null pointer, otherwise hp will be null.
 * set the client on it's way to a connection completion, regardless
 * of success of failure
 */
static void
auth_dns_callback(void *vptr, struct DNSReply *reply)
{
  struct AuthRequest *auth = (struct AuthRequest *)vptr;

  dlinkDelete(&auth->dns_node, &auth_doing_dns_list);
  ClearDNSPending(auth);

  if (reply != NULL)
  {
    struct sockaddr_in *v4, *v4dns;
    struct sockaddr_in6 *v6, *v6dns;
    int good = 1;

    if (auth->client->ip.ss.ss_family == AF_INET6)
    {
      v6 = (struct sockaddr_in6 *)&auth->client->ip;
      v6dns = (struct sockaddr_in6 *)&reply->addr;
      if (memcmp(&v6->sin6_addr, &v6dns->sin6_addr, sizeof(struct in6_addr)) != 0)
      {
        sendheader(auth->client, REPORT_IP_MISMATCH);
        good = 0;
      }
    }
    else
    {
      v4 = (struct sockaddr_in *)&auth->client->ip;
      v4dns = (struct sockaddr_in *)&reply->addr;
      if(v4->sin_addr.s_addr != v4dns->sin_addr.s_addr)
      {
        sendheader(auth->client, REPORT_IP_MISMATCH);
        good = 0;
      }
    }
    if (good && strlen(reply->h_name) <= HOSTLEN)
    {
      strlcpy(auth->client->host, reply->h_name,
	      sizeof(auth->client->host));
      sendheader(auth->client, REPORT_FIN_DNS);
    }
    else if (strlen(reply->h_name) > HOSTLEN)
      sendheader(auth->client, REPORT_HOST_TOOLONG);
  }
  else
      sendheader(auth->client, REPORT_FAIL_DNS);

  MyFree(auth->client->localClient->dns_query);
  auth->client->localClient->dns_query = NULL;

  if (!IsDoingAuth(auth))
  {
    struct Client *client_p = auth->client;
    MyFree(auth);
    release_auth_client(client_p);
  }
}

/*
 * authsenderr - handle auth send errors
 */
static void
auth_error(struct AuthRequest *auth)
{
  ++ServerStats.is_abad;

  fd_close(&auth->fd);

  dlinkDelete(&auth->ident_node, &auth_doing_ident_list);
  ClearAuth(auth);

  sendheader(auth->client, REPORT_FAIL_ID);

  if (!IsDNSPending(auth) && !IsCrit(auth))
  {
    release_auth_client(auth->client);
    MyFree(auth);
  }
}

/*
 * start_auth_query - Flag the client to show that an attempt to 
 * contact the ident server on
 * the client's host.  The connect and subsequently the socket are all put
 * into 'non-blocking' mode.  Should the connect or any later phase of the
 * identifing process fail, it is aborted and the user is given a username
 * of "unknown".
 */
static int
start_auth_query(struct AuthRequest *auth)
{
  struct irc_ssaddr localaddr;
  socklen_t locallen = sizeof(struct irc_ssaddr);
  struct sockaddr_in6 *v6;

  /* open a socket of the same type as the client socket */
  if (comm_open(&auth->fd, auth->client->ip.ss.ss_family,
                SOCK_STREAM, 0, "ident") == -1)
  {
    report_error(L_ALL, "creating auth stream socket %s:%s", 
        get_client_name(auth->client, SHOW_IP), errno);
    ilog(L_ERROR, "Unable to create auth socket for %s",
        get_client_name(auth->client, SHOW_IP));
    ++ServerStats.is_abad;
    return 0;
  }

  sendheader(auth->client, REPORT_DO_ID);

  /* 
   * get the local address of the client and bind to that to
   * make the auth request.  This used to be done only for
   * ifdef VIRTUAL_HOST, but needs to be done for all clients
   * since the ident request must originate from that same address--
   * and machines with multiple IP addresses are common now
   */
  memset(&localaddr, 0, locallen);
  getsockname(auth->client->localClient->fd.fd, (struct sockaddr*)&localaddr,
      &locallen);

  remove_ipv6_mapping(&localaddr);
  v6 = (struct sockaddr_in6 *)&localaddr;
  v6->sin6_port = htons(0);
  localaddr.ss_port = htons(0);

  SetDoingAuth(auth);
  dlinkAdd(auth, &auth->ident_node, &auth_doing_ident_list);

  comm_connect_tcp(&auth->fd, auth->client->sockhost, 113, 
      (struct sockaddr *)&localaddr, localaddr.ss_len, auth_connect_callback, 
      auth, auth->client->ip.ss.ss_family, 
      GlobalSetOptions.ident_timeout);
  return 1; /* We suceed here for now */
}

/*
 * GetValidIdent - parse ident query reply from identd server
 * 
 * Inputs        - pointer to ident buf
 * Output        - NULL if no valid ident found, otherwise pointer to name
 * Side effects  -
 */
/*
 * A few questions have been asked about this mess, obviously
 * it should have been commented better the first time.
 * The original idea was to remove all references to libc from ircd-hybrid.
 * Instead of having to write a replacement for sscanf(), I did a
 * rather gruseome parser here so we could remove this function call.
 * Note, that I had also removed a few floating point printfs as well (though
 * now we are still stuck with a few...)
 * Remember, we have a replacement ircd sprintf, we have bleeps fputs lib
 * it would have been nice to remove some unneeded code.
 * Oh well. If we don't remove libc stuff totally, then it would be
 * far cleaner to use sscanf()
 *
 * - Dianora
 */
static char *
GetValidIdent(char *buf)
{
  int   remp = 0;
  int   locp = 0;
  char* colon1Ptr;
  char* colon2Ptr;
  char* colon3Ptr;
  char* commaPtr;
  char* remotePortString;

  /* All this to get rid of a sscanf() fun. */
  remotePortString = buf;
  
  if ((colon1Ptr = strchr(remotePortString,':')) == NULL)
    return 0;
  *colon1Ptr = '\0';
  colon1Ptr++;

  if ((colon2Ptr = strchr(colon1Ptr,':')) == NULL)
    return 0;
  *colon2Ptr = '\0';
  colon2Ptr++;
  
  if ((commaPtr = strchr(remotePortString, ',')) == NULL)
    return 0;
  *commaPtr = '\0';
  commaPtr++;

  if ((remp = atoi(remotePortString)) == 0)
    return 0;
              
  if ((locp = atoi(commaPtr)) == 0)
    return 0;

  /* look for USERID bordered by first pair of colons */
  if (strstr(colon1Ptr, "USERID") == NULL)
    return 0;

  if ((colon3Ptr = strchr(colon2Ptr,':')) == NULL)
    return 0;
  *colon3Ptr = '\0';
  colon3Ptr++;
  return (colon3Ptr);
}

/*
 * start_auth 
 *
 * inputs	- pointer to client to auth
 * output	- NONE
 * side effects	- starts auth (identd) and dns queries for a client
 */
static void *
start_auth(va_list args)
{
  struct Client *client = va_arg(args, struct Client *);
  struct AuthRequest *auth = NULL;

  assert(client != NULL);

  auth = make_auth_request(client);
  SetCrit(auth);

  client->localClient->dns_query = MyMalloc(sizeof(struct DNSQuery));
  client->localClient->dns_query->ptr = auth;
  client->localClient->dns_query->callback = auth_dns_callback;

  sendheader(client, REPORT_DO_DNS);

  if (ConfigFileEntry.disable_auth == 0)
    start_auth_query(auth);

  /* auth order changed, before gethost_byaddr can immediately call
   * dns callback under win32 when the lookup cannot be started.
   * And that would do MyFree(auth) etc -adx */
  SetDNSPending(auth);
  dlinkAdd(auth, &auth->dns_node, &auth_doing_dns_list);
  ClearCrit(auth);
  gethost_byaddr(&client->ip, client->localClient->dns_query);

  return NULL;
}

/*
 * timeout_auth_queries - timeout resolver and identd requests
 * allow clients through if requests failed
 */
static void
timeout_auth_queries_event(void *notused)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct AuthRequest* auth;

  DLINK_FOREACH_SAFE(ptr, next_ptr, auth_doing_ident_list.head)
  {
    auth = ptr->data;

    if (auth->timeout <= CurrentTime)
    {
      fd_close(&auth->fd);

      ++ServerStats.is_abad;
      sendheader(auth->client, REPORT_FAIL_ID);

      if (IsDNSPending(auth))
      {
        struct Client *client_p = auth->client;

        dlinkDelete(&auth->dns_node, &auth_doing_dns_list);
        if (client_p->localClient->dns_query != NULL)
          MyFree(client_p->localClient->dns_query);
        auth->client->localClient->dns_query = NULL;
        sendheader(client_p, REPORT_FAIL_DNS);
      }

      ilog(L_INFO, "DNS/AUTH timeout %s", get_client_name(auth->client, SHOW_IP));

      dlinkDelete(&auth->ident_node, &auth_doing_ident_list);
      release_auth_client(auth->client);
      MyFree(auth);
    }
  }
}

/*
 * auth_connect_callback() - deal with the result of comm_connect_tcp()
 *
 * If the connection failed, we simply close the auth fd and report
 * a failure. If the connection suceeded send the ident server a query
 * giving "theirport , ourport". The write is only attempted *once* so
 * it is deemed to be a fail if the entire write doesn't write all the
 * data given.  This shouldnt be a problem since the socket should have
 * a write buffer far greater than this message to store it in should
 * problems arise. -avalon
 */
static void
auth_connect_callback(fde_t *fd, int error, void *data)
{
  struct AuthRequest *auth = data;
  struct irc_ssaddr us;
  struct irc_ssaddr them;
  char authbuf[32];
  socklen_t ulen = sizeof(struct irc_ssaddr);
  socklen_t tlen = sizeof(struct irc_ssaddr);
  u_int16_t uport, tport;
  struct sockaddr_in6 *v6;

  if (error != COMM_OK)
  {
    auth_error(auth);
    return;
  }

  if (getsockname(auth->client->localClient->fd.fd, (struct sockaddr *) &us,
      (socklen_t *) &ulen) ||
      getpeername(auth->client->localClient->fd.fd, (struct sockaddr *) &them,
      (socklen_t *) &tlen))
  {
    ilog(L_INFO, "auth get{sock,peer}name error for %s",
        get_client_name(auth->client, SHOW_IP));
    auth_error(auth);
    return;
  }

  v6 = (struct sockaddr_in6 *)&us;
  uport = ntohs(v6->sin6_port);
  v6 = (struct sockaddr_in6 *)&them;
  tport = ntohs(v6->sin6_port);
  remove_ipv6_mapping(&us);
  remove_ipv6_mapping(&them);
  
  ircsprintf(authbuf, "%u , %u\r\n", tport, uport); 

  if (send(fd->fd, authbuf, strlen(authbuf), 0) == -1)
  {
    auth_error(auth);
    return;
  }

  read_auth_reply(&auth->fd, auth);
}

/*
 * read_auth_reply - read the reply (if any) from the ident server 
 * we connected to.
 * We only give it one shot, if the reply isn't good the first time
 * fail the authentication entirely. --Bleep
 */
#define AUTH_BUFSIZ 128

static void
read_auth_reply(fde_t *fd, void *data)
{
  struct AuthRequest *auth = data;
  char *s = NULL;
  char *t = NULL;
  int len;
  int count;
  char buf[AUTH_BUFSIZ + 1]; /* buffer to read auth reply into */

  /* Why?
   * Well, recv() on many POSIX systems is a per-packet operation,
   * and we do not necessarily want this, because on lowspec machines,
   * the ident response may come back fragmented, thus resulting in an
   * invalid ident response, even if the ident response was really OK.
   *
   * So PLEASE do not change this code to recv without being aware of the
   * consequences.
   *
   *    --nenolod
   */
#ifndef _WIN32
  len = read(fd->fd, buf, AUTH_BUFSIZ);
#else
  len = recv(fd->fd, buf, AUTH_BUFSIZ, 0);
#endif
  
  if (len < 0)
  {
#ifdef _WIN32
    errno = WSAGetLastError();
#endif
    if (ignoreErrno(errno))
      levent_add(fd, COMM_SELECT_READ, read_auth_reply, auth, 0);
    else
      auth_error(auth);
    return;
  }

  if (len > 0)
  {
    buf[len] = '\0';

    if ((s = GetValidIdent(buf)))
    {
      t = auth->client->username;

      while (*s == '~' || *s == '^')
        s++;

      for (count = USERLEN; *s && count; s++)
      {
        if (*s == '@')
          break;
        if (!IsSpace(*s) && *s != ':' && *s != '[')
        {
          *t++ = *s;
          count--;
        }
      }

      *t = '\0';
    }
  }

  fd_close(fd);

  dlinkDelete(&auth->ident_node, &auth_doing_ident_list);  
  ClearAuth(auth);

  if (s == NULL)
  {
    sendheader(auth->client, REPORT_FAIL_ID);
    ++ServerStats.is_abad;
  }
  else
  {
    sendheader(auth->client, REPORT_FIN_ID);
    ++ServerStats.is_asuc;
    SetGotId(auth->client);
  }

  if (!IsDNSPending(auth) && !IsCrit(auth))
  {
    release_auth_client(auth->client);
    MyFree(auth);
  }
}

/*
 * delete_auth()
 */
void 
delete_auth(struct Client *target_p)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct AuthRequest *auth;

  if (!IsUnknown(target_p))
    return;

  if (target_p->localClient->dns_query != NULL)
    DLINK_FOREACH_SAFE(ptr, next_ptr, auth_doing_dns_list.head)
    {
      auth = ptr->data;

      if (auth->client == target_p)
      {
        MyFree(target_p->localClient->dns_query);
        target_p->localClient->dns_query = NULL;

        dlinkDelete(&auth->dns_node, &auth_doing_dns_list);

        if (!IsDoingAuth(auth))
        {
          MyFree(auth);
          return;
        }
      }
    }

  DLINK_FOREACH_SAFE(ptr, next_ptr, auth_doing_ident_list.head)
  {
    auth = ptr->data;

    if (auth->client == target_p)
    {
      fd_close(&auth->fd);

      dlinkDelete(&auth->ident_node, &auth_doing_ident_list);
      MyFree(auth);
    }
  }
}
