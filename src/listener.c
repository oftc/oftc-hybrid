/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  listener.c: Listens on a port.
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
#include "list.h"
#include "listener.h"
#include "client.h"
#include "fdlist.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "s_bsd.h"
#include "numeric.h"
#include "conf.h"
#include "send.h"
#include "memory.h"

static void accept_connection(uv_stream_t *, int);

static dlink_list ListenerPollList = { NULL, NULL, 0 };
static void close_listener(struct Listener *listener);

static void
listener_close_callback(uv_handle_t *handle)
{
  MyFree(handle);
}

static void
listener_send_callback(uv_write_t *req, int status)
{
  MyFree(req);
}

static struct Listener *
make_listener(int port, struct sockaddr_storage *addr)
{
  struct Listener *listener = MyMalloc(sizeof(struct Listener));

  listener->port = port;
  memcpy(&listener->addr, addr, sizeof(struct sockaddr_storage));

  return listener;
}

void
free_listener(struct Listener *listener)
{
  assert(listener != NULL);

  dlinkDelete(&listener->listener_node, &ListenerPollList);
  MyFree(listener);
}

/*
 * get_listener_name - return displayable listener name and port
 * returns "host.foo.org/6667" for a given listener
 */
const char *
get_listener_name(const struct Listener *const listener)
{
  static char buf[HOSTLEN + HOSTLEN + PORTNAMELEN + 4];

  snprintf(buf, sizeof(buf), "%s[%s/%u]", me.name,
           listener->name, listener->port);
  return buf;
}

/* show_ports()
 *
 * inputs       - pointer to client to show ports to
 * output       - none
 * side effects - send port listing to a client
 */
void
show_ports(struct Client *source_p)
{
  char buf[6];
  char *p = NULL;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, ListenerPollList.head)
  {
    const struct Listener *listener = ptr->data;
    p = buf;

    if (listener->flags & LISTENER_HIDDEN)
    {
      if (!HasUMode(source_p, UMODE_ADMIN))
        continue;

      *p++ = 'H';
    }

    if (listener->flags & LISTENER_SERVER)
      *p++ = 'S';

    if (listener->flags & LISTENER_SSL)
      *p++ = 's';

    *p = '\0';
    sendto_one(source_p, form_str(RPL_STATSPLINE),
               me.name, source_p->name, 'P', listener->port,
               HasUMode(source_p, UMODE_ADMIN) ? listener->name : me.name,
               listener->ref_count, buf,
               listener->active ? "active" : "disabled");
  }
}

/*
 * inetport - create a listener socket in the AF_INET or AF_INET6 domain,
 * bind it to the port given in 'port' and listen to it
 * returns true (1) if successful false (0) on error.
 *
 * If the operating system has a define for SOMAXCONN, use it, otherwise
 * use HYBRID_SOMAXCONN
 */
#ifdef SOMAXCONN
#undef HYBRID_SOMAXCONN
#define HYBRID_SOMAXCONN SOMAXCONN
#endif

static int
inetport(struct Listener *listener)
{
  int ret;

  /*
   * At first, open a new socket
   */
  if (comm_open(&listener->fd, listener->addr.ss_family, SOCK_STREAM, 
                "Listener socket") == -1)
  {
    report_error(L_ALL, "opening listener socket %s:%s",
                 get_listener_name(listener), 
                 uv_last_error(server_state.event_loop));
    return 0;
  }

  /*
   * Bind a port to listen for new connections if port is non-null,
   * else assume it is already open and try get something from it.
   */
  switch(listener->addr.ss_family)
  {
    case AF_INET:
      ret = uv_tcp_bind((uv_tcp_t *)listener->fd.handle, 
                        *(struct sockaddr_in *)&listener->addr);
      break;
    case AF_INET6:
      ret = uv_tcp_bind6((uv_tcp_t *)listener->fd.handle,
                         *(struct sockaddr_in6 *)&listener->addr);
      break;
    default:
      assert(0);
      ret = -1;
  }

  if (ret != 0)
  {
    report_error(L_ALL, "binding listener socket %s:%s",
                 get_listener_name(listener),
                 uv_last_error(server_state.event_loop));
    fd_close(&listener->fd);
    return 0;
  }

  if (uv_listen(listener->fd.handle, HYBRID_SOMAXCONN, accept_connection) != 0)
  {
    report_error(L_ALL, "listen failed for %s:%s",
                 get_listener_name(listener), 
                 uv_last_error(server_state.event_loop));
    fd_close(&listener->fd);
    return 0;
  }

  listener->fd.handle->data = listener;

  return 1;
}

struct Listener *
find_listener(int port, struct sockaddr_storage *addr)
{
  dlink_node *ptr;
  struct Listener *listener    = NULL;
  struct Listener *last_closed = NULL;

  DLINK_FOREACH(ptr, ListenerPollList.head)
  {
    listener = ptr->data;

    if ((port == listener->port) &&
        (!memcmp(addr, &listener->addr, sizeof(struct sockaddr_storage))))
    {
      /* Try to return an open listener, otherwise reuse a closed one */
      if (!listener->fd.flags.open)
        last_closed = listener;
      else
        return (listener);
    }
  }

  return (last_closed);
}

/*
 * add_listener- create a new listener
 * port - the port number to listen on
 * vhost_ip - if non-null must contain a valid IP address string in
 * the format "255.255.255.255"
 */
void
add_listener(int port, const char *vhost_ip, unsigned int flags)
{
  struct Listener *listener;
  struct sockaddr_storage vaddr;
  static short int pass = 0; /* if ipv6 and no address specified we need to
                                have two listeners; one for each protocol. */

  /*
   * if no or invalid port in conf line, don't bother
   */
  if (!(port > 0 && port <= 0xFFFF))
    return;

  memset(&vaddr, 0, sizeof(vaddr));

  if (EmptyString(vhost_ip) && pass == 0)
  {
    pass = 1;
    add_listener(port, "0.0.0.0", flags);
    pass = 0;
    vhost_ip = "::";
  }

  string_to_ip(vhost_ip, port, &vaddr);

  if ((listener = find_listener(port, &vaddr)))
  {
    listener->flags = flags;

    if (listener->fd.flags.open)
      return;
  }
  else
  {
    listener = make_listener(port, &vaddr);
    dlinkAdd(listener, &listener->listener_node, &ListenerPollList);
    listener->flags = flags;
  }

  if (inetport(listener))
    listener->active = 1;
  else
    close_listener(listener);
}

/*
 * close_listener - close a single listener
 */
static void
close_listener(struct Listener *listener)
{
  assert(listener != NULL);

  if (listener == NULL)
    return;

  if (listener->fd.flags.open)
    fd_close(&listener->fd);

  listener->active = 0;

  if (listener->ref_count)
    return;

  free_listener(listener);
}

/*
 * close_listeners - close and free all listeners that are not being used
 */
void
close_listeners()
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  /* close all 'extra' listening ports we have */
  DLINK_FOREACH_SAFE(ptr, next_ptr, ListenerPollList.head)
  {
    close_listener(ptr->data);
  }
}

static void 
listener_send(struct Listener *listener, uv_tcp_t *handle,
                          const char *buffer, size_t len)
{
  if ((listener->flags & LISTENER_SSL) == LISTENER_SSL)
    return;

  uv_buf_t buf = uv_buf_init((char *)buffer, len);
  uv_write_t *req = MyMalloc(sizeof(uv_write_t));

  uv_write(req, (uv_stream_t *)handle, &buf, 1, listener_send_callback);
}

#define TOOFAST_WARNING "ERROR :Trying to reconnect too fast.\r\n"
#define DLINE_WARNING "ERROR :You have been D-lined.\r\n"
#define ALLINUSE_WARNING "ERROR :All connections in use\r\n"

static void
accept_connection(uv_stream_t *server, int status)
{
  static time_t last_oper_notice = 0;
  struct sockaddr_storage addr;
  int pe;
  struct Listener *listener = server->data;
  uv_tcp_t *handle;

  memset(&addr, 0, sizeof(addr));

  assert(listener != NULL);

  if(status != 0)
    return;

  /* There may be many reasons for error return, but
   * in otherwise correctly working environment the
   * probable cause is running out of file descriptors
   * (EMFILE, ENFILE or others?). The man pages for
   * accept don't seem to list these as possible,
   * although it's obvious that it may happen here.
   * Thus no specific errors are tested at this
   * point, just assume that connections cannot
   * be accepted until some old is closed first.
   */

  handle = MyMalloc(sizeof(uv_tcp_t));

  if(uv_tcp_init(server_state.event_loop, handle) != 0)
  {
    MyFree(handle);
    return;
  }

  if(!comm_accept(listener, handle, &addr))
  {
    MyFree(handle);
    return;
  }

  /*
   * check for connection limit
   */
  if (number_fd > hard_fdlimit - 10)
  {
    ++ServerStats.is_ref;

    /*
     * slow down the whining to opers bit
     */
    if ((last_oper_notice + 20) <= CurrentTime)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, "All connections in use. (%s)",
                           get_listener_name(listener));
      last_oper_notice = CurrentTime;
    }

    listener_send(listener, handle, ALLINUSE_WARNING, 
                  sizeof(ALLINUSE_WARNING) - 1);

    uv_close((uv_handle_t *)handle, listener_close_callback);
    return;
  }

  /*
   * Do an initial check we aren't connecting too fast or with too many
   * from this IP...
   */
  if ((pe = conf_connect_allowed(&addr, addr.ss_family)) != 0)
  {
    ++ServerStats.is_ref;

    switch (pe)
    {
      case BANNED_CLIENT:
        listener_send(listener, handle, DLINE_WARNING, 
                      sizeof(DLINE_WARNING) - 1);
        break;

      case TOO_FAST:
        listener_send(listener, handle, TOOFAST_WARNING, 
                      sizeof(TOOFAST_WARNING) - 1);
        break;
    }

    uv_close((uv_handle_t *)handle, listener_close_callback);
    return;
  }

  ++ServerStats.is_ac;
  add_connection(listener, &addr, handle);
}
