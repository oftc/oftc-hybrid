/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_bsd.c: Network functions.
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
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include "list.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "client.h"
#include "dbuf.h"
#include "event.h"
#include "irc_string.h"
#include "ircd.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "irc_res.h"
#include "restart.h"
#include "s_auth.h"
#include "conf.h"
#include "log.h"
#include "s_serv.h"
#include "send.h"
#include "memory.h"
#include "s_user.h"
#include "hook.h"
#include "s_misc.h"

static const char *comm_err_str[] = { "Comm OK", "Error during bind()",
                                      "Error during DNS lookup", "connect timeout", "Error during connect()",
                                      "Comm Error"
                                    };

struct Callback *setup_socket_cb = NULL;

static void comm_connect_callback(uv_connect_t *, int);
static PF comm_connect_timeout;
static void comm_connect_dns_callback(void *, const struct sockaddr_storage*,
                                      const char *);
static PF comm_connect_tryconnect;

void
string_to_ip(const char *ipstr, unsigned int port, 
             struct sockaddr_storage *addr)
{
  struct sockaddr_in v4;
  struct sockaddr_in6 v6;

  memset(addr, 0, sizeof(struct sockaddr_storage));

  if(EmptyString(ipstr))
    ipstr = "::";

  if(strchr(ipstr, ':') == NULL)
  {
    v4 = uv_ip4_addr(ipstr, port);
    memcpy(addr, &v4, sizeof(v4));
  }
  else
  {
    v6 = uv_ip6_addr(ipstr, port);
    memcpy(addr, &v6, sizeof(v6));
  }
}

/* check_can_use_v6()
 *  Check if the system can open AF_INET6 sockets
 */
void
check_can_use_v6()
{
  int v6;

  if ((v6 = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
    ServerInfo.can_use_v6 = 0;
  else
  {
    ServerInfo.can_use_v6 = 1;
    close(v6);
  }
}

/* get_sockerr - get the error value from the socket or the current errno
 *
 * Get the *real* error from the socket (well try to anyway..).
 * This may only work when SO_DEBUG is enabled but its worth the
 * gamble anyway.
 */
int
get_sockerr(int fd)
{
  int errtmp = errno;
#ifdef SO_ERROR
  int err = 0;
  socklen_t len = sizeof(err);

  if (-1 < fd && !getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &len))
  {
    if (err)
      errtmp = err;
  }

  errno = errtmp;
#endif
  return errtmp;
}

/*
 * report_error - report an error from an errno.
 * Record error to log and also send a copy to all *LOCAL* opers online.
 *
 *        text        is a *format* string for outputing error. It must
 *                contain only two '%s', the first will be replaced
 *                by the sockhost from the client_p, and the latter will
 *                be taken from sys_errlist[errno].
 *
 *        client_p        if not NULL, is the *LOCAL* client associated with
 *                the error.
 *
 * Cannot use perror() within daemon. stderr is closed in
 * ircd and cannot be used. And, worse yet, it might have
 * been reassigned to a normal connection...
 *
 * Actually stderr is still there IFF ircd was run with -s --Rodder
 */

void
report_error(int level, const char *text, const char *who, int error)
{
  who = (who) ? who : "";

  sendto_realops_flags(UMODE_DEBUG, level, text, who, strerror(error));
  ilog(LOG_TYPE_IRCD, text, who, strerror(error));
}

/*
 * setup_socket()
 *
 * Set the socket non-blocking, and other wonderful bits.
 */
static void *
setup_socket(va_list args)
{
  uv_tcp_t *fd = va_arg(args, uv_tcp_t *);
  int opt;

  uv_tcp_nodelay(fd, 1);

#ifdef IPTOS_LOWDELAY
  opt = IPTOS_LOWDELAY;
  setsockopt(fd->io_watcher.fd, IPPROTO_IP, IP_TOS, &opt, sizeof(opt));
#endif

  return NULL;
}

/*
 * init_comm()
 *
 * Initializes comm subsystem.
 */
void
init_comm()
{
  setup_socket_cb = register_callback("setup_socket", setup_socket);
  //init_netio();
}

/*
 * close_connection
 *        Close the physical connection. This function must make
 *        MyConnect(client_p) == FALSE, and set client_p->from == NULL.
 */
void
close_connection(struct Client *client_p)
{
  struct AccessItem *aconf;
  struct ClassItem *aclass;
  dlink_node *ptr = NULL;

  assert(client_p);

  if (!IsDead(client_p))
  {
    /* attempt to flush any pending dbufs. Evil, but .. -- adrian */
    /* there is still a chance that we might send data to this socket
     * even if it is marked as blocked (COMM_SELECT_READ handler is called
     * before COMM_SELECT_WRITE). Let's try, nothing to lose.. -adx
     */
    ClearSendqBlocked(client_p);
    send_queued_write(client_p);
  }

  if (IsClient(client_p))
  {
    ++ServerStats.is_cl;
    ServerStats.is_cbs += client_p->localClient->send.bytes;
    ServerStats.is_cbr += client_p->localClient->recv.bytes;
    ServerStats.is_cti += CurrentTime - client_p->localClient->firsttime;
  }
  else if (IsServer(client_p))
  {
    ++ServerStats.is_sv;
    ServerStats.is_sbs += client_p->localClient->send.bytes;
    ServerStats.is_sbr += client_p->localClient->recv.bytes;
    ServerStats.is_sti += CurrentTime - client_p->localClient->firsttime;

    DLINK_FOREACH(ptr, server_items.head)
    {
      struct ConfItem *conf = ptr->data;

      if (irccmp(conf->name, client_p->name))
        continue;

      /*
       * Reset next-connect cycle of all connect{} blocks that match
       * this servername.
       */
      aconf  = map_to_conf(conf);
      aclass = map_to_conf(aconf->class_ptr);
      aconf->hold = CurrentTime + aclass->con_freq;
    }
  }
  else
    ++ServerStats.is_ni;

#ifdef HAVE_LIBCRYPTO

  if (client_p->localClient->fd.ssl)
  {
    SSL_set_shutdown(client_p->localClient->fd.ssl, SSL_RECEIVED_SHUTDOWN);

    if (!SSL_shutdown(client_p->localClient->fd.ssl))
      SSL_shutdown(client_p->localClient->fd.ssl);
  }

#endif

  if (client_p->localClient->fd.flags.open)
    fd_close(&client_p->localClient->fd);

  dbuf_clear(&client_p->localClient->buf_sendq);
  dbuf_clear(&client_p->localClient->buf_recvq);

  MyFree(client_p->localClient->passwd);
  detach_conf(client_p, CONF_TYPE);
  client_p->from = NULL; /* ...this should catch them! >:) --msa */
}

static void ssl_handshake(struct Client *);

uv_buf_t 
ssl_alloc_buffer(uv_handle_t *handle, size_t suggested_size)
{
  return uv_buf_init(MyMalloc(suggested_size), suggested_size);
}

void 
ssl_write_callback(uv_write_t *req, int status)
{
  MyFree(req);
}

void
ssl_flush_write(struct Client *client_p)
{
  int pending;

  while((pending = BIO_pending(client_p->localClient->fd.write_bio)) > 0)
  {
    char *buffer = MyMalloc(pending);
    uv_write_t *req = MyMalloc(sizeof(uv_write_t));
    uv_buf_t buf;

    int len = BIO_read(client_p->localClient->fd.write_bio, buffer, pending);

    buf.base = buffer;
    buf.len = len;

    uv_write(req, client_p->localClient->fd.handle, &buf, 1, 
             ssl_write_callback);
  }
}

void
ssl_read_callback(uv_stream_t *stream, ssize_t nread, uv_buf_t buf)
{
  struct Client *client_p = stream->data;

  if(nread <= 0)
    ; // XXX DO SOMETHING

  BIO_write(client_p->localClient->fd.read_bio, buf.base, nread);

  uv_read_stop(stream);

  ssl_handshake(client_p);

  ssl_flush_write(client_p);
}

#ifdef HAVE_LIBCRYPTO
/*
 * ssl_handshake - let OpenSSL initialize the protocol. Register for
 * read/write events if necessary.
 */
static void
ssl_handshake(struct Client *client_p)
{
  int ret = SSL_accept(client_p->localClient->fd.ssl);
  X509 *cert;

  int err = SSL_get_error(client_p->localClient->fd.ssl, ret);
  ilog(LOG_TYPE_IRCD, "SSL Error %d %s", err, ERR_error_string(err, NULL));

  if ((cert = SSL_get_peer_certificate(client_p->localClient->fd.ssl)) != NULL)
  {
    int res = SSL_get_verify_result(client_p->localClient->fd.ssl);

    if (res == X509_V_OK || res == X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN ||
        res == X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE ||
        res == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT)
    {
      /* The client sent a certificate which verified OK */
      base16_encode(client_p->certfp, sizeof(client_p->certfp),
                    (const char *)cert->sha1_hash, sizeof(cert->sha1_hash));
    }
    else
    {
      ilog(LOG_TYPE_IRCD, "Client %s!%s@%s gave bad SSL client certificate: %d",
           client_p->name, client_p->username, client_p->host, res);
    }

    X509_free(cert);
  }

  if (ret <= 0)
  {
    if ((CurrentTime - client_p->localClient->firsttime) > 30)
    {
      exit_client(client_p, client_p, "Timeout during SSL handshake");
      return;
    }

    switch (SSL_get_error(client_p->localClient->fd.ssl, ret))
    {
      case SSL_ERROR_WANT_WRITE:
        {
        int i = 0;
        i++;
        }
//        comm_setselect(&client_p->localClient->fd, COMM_SELECT_WRITE,
  //                     (PF *) ssl_handshake, client_p, 30);
        return;

      case SSL_ERROR_WANT_READ:
        uv_read_start(client_p->localClient->fd.handle, ssl_alloc_buffer,
                      ssl_read_callback);
    //    comm_setselect(&client_p->localClient->fd, COMM_SELECT_READ,
      //                 (PF *) ssl_handshake, client_p, 30);
        return;

      default:
        exit_client(client_p, client_p, "Error during SSL handshake");
        return;
    }
  }

  comm_settimeout(&client_p->localClient->fd, 0, NULL, NULL);
  execute_callback(auth_cb, client_p);
}
#endif
/*
 * add_connection - creates a client which has just connected to us on
 * the given fd. The sockhost field is initialized with the ip# of the host.
 * An unique id is calculated now, in case it is needed for auth.
 * The client is sent to the auth module for verification, and not put in
 * any client list yet.
 */
void
add_connection(struct Listener *listener, struct sockaddr_storage *irn, 
               uv_tcp_t *handle)
{
  struct Client *new_client = make_client(NULL);
  uv_err_t ret;

  fd_open(&new_client->localClient->fd, (uv_stream_t *)handle, 
          (listener->flags & LISTENER_SSL) ?
          "Incoming SSL connection" : "Incoming connection");

  new_client->localClient->fd.handle->data = new_client;

  /*
   * copy address to 'sockhost' as a string, copy it to host too
   * so we have something valid to put into error messages...
   */
  memcpy(&new_client->ip, irn, sizeof(new_client->ip));

  ret = uv_inet_ntop(new_client->ip.ss_family, &new_client->ip, 
                     new_client->sockhost, sizeof(new_client->sockhost));

  if(ret.code != UV_OK)
  {
    ilog(LOG_TYPE_IRCD, "uv_ip*_name failed!");
    SetDead(new_client);
    exit_client(new_client, new_client, "uv_ip*_name failed!");
    return;
  }

  if (new_client->sockhost[0] == ':' && new_client->sockhost[1] == ':')
  {
    strlcpy(new_client->host, "0", sizeof(new_client->host));
    strlcpy(new_client->host + 1, new_client->sockhost,
            sizeof(new_client->host) - 1);
    memmove(new_client->sockhost + 1, new_client->sockhost,
            sizeof(new_client->sockhost) - 1);
    new_client->sockhost[0] = '0';
  }
  else
    strlcpy(new_client->host, new_client->sockhost, sizeof(new_client->host));

  new_client->localClient->listener = listener;
  ++listener->ref_count;

#ifdef HAVE_LIBCRYPTO

  if (listener->flags & LISTENER_SSL)
  {
    if ((new_client->localClient->fd.ssl = SSL_new(ServerInfo.server_ctx)) == NULL)
    {
      ilog(LOG_TYPE_IRCD, "SSL_new() ERROR! -- %s",
           ERR_error_string(ERR_get_error(), NULL));

      SetDead(new_client);
      exit_client(new_client, new_client, "SSL_new failed");
      return;
    }

    new_client->localClient->fd.read_bio = BIO_new(BIO_s_mem());
    new_client->localClient->fd.write_bio = BIO_new(BIO_s_mem());

    SSL_set_bio(new_client->localClient->fd.ssl, 
                new_client->localClient->fd.read_bio, 
                new_client->localClient->fd.write_bio);

    SSL_set_accept_state(new_client->localClient->fd.ssl);

    ssl_handshake(new_client);
  }
  else
#endif
    execute_callback(auth_cb, new_client);
}

/*
 * stolen from squid - its a neat (but overused! :) routine which we
 * can use to see whether we can ignore this errno or not. It is
 * generally useful for non-blocking network IO related errnos.
 *     -- adrian
 */
int
ignoreErrno(int ierrno)
{
  switch (ierrno)
  {
    case EINPROGRESS:
    case EWOULDBLOCK:
#if EAGAIN != EWOULDBLOCK
    case EAGAIN:
#endif
    case EALREADY:
    case EINTR:
#ifdef ERESTART
    case ERESTART:
#endif
      return 1;

    default:
      return 0;
  }
}

/*
 * comm_settimeout() - set the socket timeout
 *
 * Set the timeout for the fd
 */
void
comm_settimeout(fde_t *fd, time_t timeout, PF *callback, void *cbdata)
{
  assert(fd->flags.open);

  fd->timeout = CurrentTime + (timeout / 1000);
  fd->timeout_handler = callback;
  fd->timeout_data = cbdata;
}

/*
 * comm_setflush() - set a flush function
 *
 * A flush function is simply a function called if found during
 * comm_timeouts(). Its basically a second timeout, except in this case
 * I'm too lazy to implement multiple timeout functions! :-)
 * its kinda nice to have it separate, since this is designed for
 * flush functions, and when comm_close() is implemented correctly
 * with close functions, we _actually_ don't call comm_close() here ..
 * -- originally Adrian's notes
 * comm_close() is replaced with fd_close() in fdlist.c
 */
void
comm_setflush(fde_t *fd, time_t timeout, PF *callback, void *cbdata)
{
  assert(fd->flags.open);

  fd->flush_timeout = CurrentTime + (timeout / 1000);
  fd->flush_handler = callback;
  fd->flush_data = cbdata;
}

/*
 * comm_checktimeouts() - check the socket timeouts
 *
 * All this routine does is call the given callback/cbdata, without closing
 * down the file descriptor. When close handlers have been implemented,
 * this will happen.
 */
void
comm_checktimeouts(void *notused)
{
  fde_t *F;
  PF *hdl;
  void *data;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, fd_list.head)
  {
    F = ptr->data;
    assert(F->flags.open);

    /* check flush functions */
    if (F->flush_handler && F->flush_timeout > 0 &&
        F->flush_timeout < CurrentTime)
    {
      hdl = F->flush_handler;
      data = F->flush_data;
      comm_setflush(F, 0, NULL, NULL);
      hdl(F, data);
    }

    /* check timeouts */
    if (F->timeout_handler && F->timeout > 0 &&
        F->timeout < CurrentTime)
    {
      /* Call timeout handler */
      hdl = F->timeout_handler;
      data = F->timeout_data;
      comm_settimeout(F, 0, NULL, NULL);
      hdl(F, data);
    }
  }
}

/*
 * void comm_connect_tcp(int fd, const char *host, unsigned short port,
 *                       struct sockaddr *clocal, int socklen,
 *                       CNCB *callback, void *data, int aftype, int timeout)
 * Input: An fd to connect with, a host and port to connect to,
 *        a local sockaddr to connect from + length(or NULL to use the
 *        default), a callback, the data to pass into the callback, the
 *        address family.
 * Output: None.
 * Side-effects: A non-blocking connection to the host is started, and
 *               if necessary, set up for selection. The callback given
 *               may be called now, or it may be called later.
 */
void
comm_connect_tcp(fde_t *fd, const char *host, unsigned short port,
                 struct sockaddr *clocal, int socklen, CNCB *callback,
                 void *data, int aftype, int timeout)
{
  assert(callback);
  fd->connect.callback = callback;
  fd->connect.handle.data = fd;
  fd->connect.data = data;

  fd->connect.hostaddr.ss_family = aftype;

  /* Note that we're using a passed sockaddr here. This is because
   * generally you'll be bind()ing to a sockaddr grabbed from
   * getsockname(), so this makes things easier.
   * XXX If NULL is passed as local, we should later on bind() to the
   * virtual host IP, for completeness.
   *   -- adrian
   */
  if ((clocal != NULL))
  {
    int ret;

    switch(aftype)
    {
      case AF_INET:
        ret = uv_tcp_bind((uv_tcp_t *)fd->handle, 
                          *(struct sockaddr_in *)clocal);
        break;
      case AF_INET6:
        ret = uv_tcp_bind6((uv_tcp_t *)fd->handle, 
                           *(struct sockaddr_in6 *)clocal);
        break;
      default:
        assert(0);
        ret = -1;
    }

    if(ret != 0)
    {
      /* Failure, call the callback with COMM_ERR_BIND */
      comm_connect_callback(&fd->connect.handle, COMM_ERR_BIND);
      /* ... and quit */
      return;
    }
  }

  /* Next, if we have been given an IP, get the addr and skip the
   * DNS check (and head direct to comm_connect_tryconnect().
   */

  struct in6_addr tmp;
  uv_err_t err = uv_inet_pton(aftype, host, &tmp);
  if(err.code != UV_OK)
  {
    /* Send the DNS request, for the next level */
    if (aftype == AF_INET6)
      gethost_byname_type(comm_connect_dns_callback, fd, host, T_AAAA);
    else
      gethost_byname_type(comm_connect_dns_callback, fd, host, T_A);
  }
  else
  {
    /* We have a valid IP, so we just call tryconnect */
    /* Make sure we actually set the timeout here .. */

    string_to_ip(host, 0, &fd->connect.hostaddr);
    comm_settimeout(fd, timeout * 1000, comm_connect_timeout, NULL);
    comm_connect_tryconnect(fd, NULL);
  }
}

/*
 * comm_connect_callback() - call the callback, and continue with life
 */
static void
comm_connect_callback(uv_connect_t *request, int status)
{
  CNCB *hdl;
  fde_t *fd = request->data;

  /* This check is gross..but probably necessary */
  if (fd->connect.callback == NULL)
    return;

  /* Clear the connect flag + handler */
  hdl = fd->connect.callback;
  fd->connect.callback = NULL;

  /* Clear the timeout handler */
  comm_settimeout(fd, 0, NULL, NULL);

  /* Call the handler */
  hdl(fd, status, fd->connect.data);
}

/*
 * comm_connect_timeout() - this gets called when the socket connection
 * times out. This *only* can be called once connect() is initially
 * called ..
 */
static void
comm_connect_timeout(fde_t *fd, void *notused)
{
  /* error! */
  comm_connect_callback(&fd->connect.handle, COMM_ERR_TIMEOUT);
}

/*
 * comm_connect_dns_callback() - called at the completion of the DNS request
 *
 * The DNS request has completed, so if we've got an error, return it,
 * otherwise we initiate the connect()
 */
static void
comm_connect_dns_callback(void *vptr, const struct sockaddr_storage *addr,
                          const char *name)
{
  fde_t *F = vptr;

  if (name == NULL)
  {
    comm_connect_callback(&F->connect.handle, COMM_ERR_DNS);
    return;
  }

  /* No error, set a 10 second timeout */
  comm_settimeout(F, 30 * 1000, comm_connect_timeout, NULL);

  /* Copy over the DNS reply info so we can use it in the connect() */
  /*
   * Note we don't fudge the refcount here, because we aren't keeping
   * the DNS record around, and the DNS cache is gone anyway..
   *     -- adrian
   */
  memcpy(&F->connect.hostaddr, addr, sizeof(F->connect.hostaddr));

  /* Now, call the tryconnect() routine to try a connect() */
  comm_connect_tryconnect(F, NULL);
}
/* static void comm_connect_tryconnect(int fd, void *notused)
 * Input: The fd, the handler data(unused).
 * Output: None.
 * Side-effects: Try and connect with pending connect data for the FD. If
 *               we succeed or get a fatal error, call the callback.
 *               Otherwise, it is still blocking or something, so register
 *               to select for a write event on this FD.
 */
static void
comm_connect_tryconnect(fde_t *fd, void *notused)
{
  int retval;

  /* This check is needed or re-entrant s_bsd_* like sigio break it. */
  if (fd->connect.callback == NULL)
    return;

  switch(fd->connect.hostaddr.ss_family)
  {
    case AF_INET:
      retval = uv_tcp_connect(&fd->connect.handle, (uv_tcp_t *)fd->handle, 
                              *(struct sockaddr_in *)&fd->connect.hostaddr,
                              comm_connect_callback);
      break;
    case AF_INET6:
      retval = uv_tcp_connect6(&fd->connect.handle, (uv_tcp_t *)fd->handle,
                               *(struct sockaddr_in6 *)&fd->connect.hostaddr,
                               comm_connect_callback);
    default:
      assert(0);
      retval = -1;
  }

  /* Error? */
  if (retval != 0)
  {
    /* Error? Fail with COMM_ERR_CONNECT */
    comm_connect_callback(&fd->connect.handle, COMM_ERR_CONNECT);

    return;
  }
}

/*
 * comm_errorstr() - return an error string for the given error condition
 */
const char *
comm_errstr(int error)
{
  if (error < 0 || error >= COMM_ERR_MAX)
    return "Invalid error number!";

  return comm_err_str[error];
}

/*
 * comm_open() - open a socket
 *
 * This is a highly highly cut down version of squid's comm_open() which
 * for the most part emulates socket(), *EXCEPT* it fails if we're about
 * to run out of file descriptors.
 */
int
comm_open(fde_t *F, int family, int sock_type, const char *note)
{
  uv_stream_t *handle;
  int ret;

  /* First, make sure we aren't going to run out of file descriptors */
  if (number_fd >= hard_fdlimit)
  {
    errno = ENFILE;
    return -1;
  }

  switch(sock_type)
  {
    case SOCK_STREAM:
      handle = MyMalloc(sizeof(uv_tcp_t));
      ret = uv_tcp_init(server_state.event_loop, (uv_tcp_t *)handle);
      break;
    case SOCK_DGRAM:
      handle = MyMalloc(sizeof(uv_udp_t));
      ret = uv_udp_init(server_state.event_loop, (uv_udp_t *)handle);
      break;
  }

  if (ret != 0)
    return -1; /* errno will be passed through, yay.. */

  execute_callback(setup_socket_cb, handle);

  /* update things in our fd tracking */
  fd_open(F, handle, note);
  return 0;
}

/*
 * comm_accept() - accept an incoming connection
 *
 * This is a simple wrapper for accept() which enforces FD limits like
 * comm_open() does. Returned fd must be either closed or tagged with
 * fd_open (this function no longer does it).
 */
bool
comm_accept(struct Listener *lptr, uv_tcp_t *handle, 
            struct sockaddr_storage *addr)
{
  int len = sizeof(struct sockaddr_storage);

  if (number_fd >= hard_fdlimit)
  {
    errno = ENFILE;
    return false;
  }

  if(uv_accept(lptr->fd.handle, (uv_stream_t *)handle) != 0)
    return false;

  if(uv_tcp_getpeername(handle, (struct sockaddr *)addr, &len) != 0)
    return false;

  remove_ipv6_mapping(addr);

  execute_callback(setup_socket_cb, handle);

  return true;
}

/*
 * remove_ipv6_mapping() - Removes IPv4-In-IPv6 mapping from an address
 * OSes with IPv6 mapping listening on both
 * AF_INET and AF_INET6 map AF_INET connections inside AF_INET6 structures
 *
 */
void
remove_ipv6_mapping(struct sockaddr_storage *addr)
{
  if (addr->ss_family == AF_INET6)
  {
    if (IN6_IS_ADDR_V4MAPPED(&((struct sockaddr_in6 *)addr)->sin6_addr))
    {
      struct sockaddr_in6 v6;
      struct sockaddr_in *v4 = (struct sockaddr_in *)addr;

      memcpy(&v6, addr, sizeof(v6));
      memset(v4, 0, sizeof(struct sockaddr_in));
      memcpy(&v4->sin_addr, &v6.sin6_addr.s6_addr[12], sizeof(v4->sin_addr));

      addr->ss_family = AF_INET;
    }
  }
}
