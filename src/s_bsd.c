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
 *  $Id: s_bsd.c 549 2006-04-20 12:46:18Z michael $
 */

#include "stdinc.h"
#ifndef _WIN32
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#endif
#include "fdlist.h"
#include "s_bsd.h"
#include "client.h"
#include "common.h"
#include "dbuf.h"
#include "event.h"
#include "irc_string.h"
#include "irc_getnameinfo.h"
#include "irc_getaddrinfo.h"
#include "ircd.h"
#include "list.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "irc_res.h"
#include "inet_misc.h"
#include "restart.h"
#include "s_auth.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "s_stats.h"
#include "send.h"
#include "memory.h"
#include "s_user.h"
#include "hook.h"
#include "s_misc.h"

static const char *comm_err_str[] = { "Comm OK", "Error during bind()",
  "Error during DNS lookup", "connect timeout", "Error during connect()",
  "Comm Error" };

struct Callback *setup_socket_cb = NULL;

static void comm_connect_callback(fde_t *fd, int status);
static PF comm_connect_timeout;
static void comm_connect_dns_callback(void *vptr, struct DNSReply *reply);
static PF comm_connect_tryconnect;

extern void init_netio(void);

/* check_can_use_v6()
 *  Check if the system can open AF_INET6 sockets
 */
void
check_can_use_v6(void)
{
#ifdef IPV6
  int v6;

  if ((v6 = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
    ServerInfo.can_use_v6 = 0;
  else
  {
    ServerInfo.can_use_v6 = 1;
#ifdef _WIN32
    closesocket(v6);
#else
    close(v6);
#endif
  }
#else
  ServerInfo.can_use_v6 = 0;
#endif
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
#ifndef _WIN32
  int errtmp = errno;
#else
  int errtmp = WSAGetLastError();
#endif
#ifdef SO_ERROR
  int err = 0;
  socklen_t len = sizeof(err);

  if (-1 < fd && !getsockopt(fd, SOL_SOCKET, SO_ERROR, (char*) &err, (socklen_t *)&len))
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
 * Cannot use perror() within daemon. stderr is closed in
 * ircd and cannot be used. And, worse yet, it might have
 * been reassigned to a normal connection...
 * 
 * Actually stderr is still there IFF ircd was run with -s --Rodder
 */

void
report_error(int level, const char* format, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];

  va_start(args, format);
  vsnprintf(buffer, IRCD_BUFSIZE, format, args);
  va_end(args);

  sendto_realops_flags(UMODE_DEBUG, level, "%s", buffer);
  log_oper_action(LOG_IOERR_TYPE, NULL, "%s\n", buffer);
  ilog(L_ERROR, "%s", buffer);
}

/*
 * setup_socket()
 *
 * Set the socket non-blocking, and other wonderful bits.
 */
static void *
setup_socket(va_list args)
{
  int fd = va_arg(args, int);
  int opt = 1;

  setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (char *) &opt, sizeof(opt));

#ifdef IPTOS_LOWDELAY
  opt = IPTOS_LOWDELAY;
  setsockopt(fd, IPPROTO_IP, IP_TOS, (char *) &opt, sizeof(opt));
#endif

#ifndef _WIN32
  fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
#endif

  return NULL;
}

/*
 * init_comm()
 *
 * Initializes comm subsystem.
 */
void
init_comm(void)
{
  setup_socket_cb = register_callback("setup_socket", setup_socket);
  init_netio();
}

/*
 * close_connection
 *        Close the physical connection. This function must make
 *        MyConnect(client_p) == FALSE, and set client_p->from == NULL.
 */
void
close_connection(struct Client *client_p)
{
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct ClassItem *aclass;

  assert(NULL != client_p);

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

  if (IsServer(client_p))
  {
    ServerStats->is_sv++;
    ServerStats->is_sbs += client_p->localClient->send.bytes;
    ServerStats->is_sbr += client_p->localClient->recv.bytes;
    ServerStats->is_sti += CurrentTime - client_p->firsttime;

    /* XXX Does this even make any sense at all anymore?
     * scheduling a 'quick' reconnect could cause a pile of
     * nick collides under TSora protocol... -db
     */
    /*
     * If the connection has been up for a long amount of time, schedule
     * a 'quick' reconnect, else reset the next-connect cycle.
     */
    if ((conf = find_conf_exact(SERVER_TYPE,
				  client_p->name, client_p->username,
				  client_p->host)))
    {
      /*
       * Reschedule a faster reconnect, if this was a automatically
       * connected configuration entry. (Note that if we have had
       * a rehash in between, the status has been changed to
       * CONF_ILLEGAL). But only do this if it was a "good" link.
       */
      aconf = &conf->aconf;
      aclass = &aconf->class_ptr->aclass;
      aconf->hold = time(NULL);
      aconf->hold += (aconf->hold - client_p->since > HANGONGOODLINK) ?
        HANGONRETRYDELAY : ConFreq(aclass);
      if (nextconnect > aconf->hold)
        nextconnect = aconf->hold;
    }
  }
  else if (IsClient(client_p))
  {
    ServerStats->is_cl++;
    ServerStats->is_cbs += client_p->localClient->send.bytes;
    ServerStats->is_cbr += client_p->localClient->recv.bytes;
    ServerStats->is_cti += CurrentTime - client_p->firsttime;
  }
  else
    ServerStats->is_ni++;

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

  if (HasServlink(client_p))
  {
    if (client_p->localClient->ctrlfd.flags.open)
      fd_close(&client_p->localClient->ctrlfd);
  }

  dbuf_clear(&client_p->localClient->buf_sendq);
  dbuf_clear(&client_p->localClient->buf_recvq);
  
  MyFree(client_p->localClient->passwd);
  detach_conf(client_p, CONF_TYPE);
  client_p->from = NULL; /* ...this should catch them! >:) --msa */
}

#ifdef HAVE_LIBCRYPTO
/*
 * ssl_handshake - let OpenSSL initialize the protocol. Register for
 * read/write events if necessary.
 */
static void
ssl_handshake(fde_t *fd, struct Client *client_p)
{
  int ret = SSL_accept(client_p->localClient->fd.ssl);
  X509 *cert;

  if ((cert = SSL_get_peer_certificate(client_p->localClient->fd.ssl)) != NULL)
  {
    int res = SSL_get_verify_result(client_p->localClient->fd.ssl);
    if (res == X509_V_OK || res == X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN ||
        res == X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE ||
        res == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT)
    {
      unsigned char md[EVP_MAX_MD_SIZE];
      unsigned int n = sizeof(md);

      if (X509_digest(cert, EVP_sha1(), md, &n))
      {
        /* The client sent a certificate which verified OK */
        base16_encode(client_p->certfp, sizeof(client_p->certfp),
          (char *) md, n);
      }
    }
    else
    {
      ilog(L_WARN, "Client %s!%s@%s gave bad SSL client certificate: %d",
          client_p->name, client_p->username, client_p->host, res);
    }

    X509_free(cert);
  }

  if (ret <= 0)
  {
    if((CurrentTime - client_p->firsttime) > 30)
    {
      exit_client(client_p, client_p, "Timeout during SSL handshake");
      return;
    }
    switch (SSL_get_error(client_p->localClient->fd.ssl, ret))
    {
      case SSL_ERROR_WANT_WRITE:
        comm_setselect(&client_p->localClient->fd, COMM_SELECT_WRITE,
	               (PF *) ssl_handshake, client_p, 30);
        return;

      case SSL_ERROR_WANT_READ:
        comm_setselect(&client_p->localClient->fd, COMM_SELECT_READ,
	               (PF *) ssl_handshake, client_p, 30);
        return;

      default:
        exit_client(client_p, client_p, "Error during SSL handshake");
        return;
    }
  }

  comm_setselect(&client_p->localClient->fd, COMM_SELECT_READ | COMM_SELECT_WRITE, NULL, NULL, 0);
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
add_connection(struct Listener *listener, struct irc_ssaddr *irn, int fd)
{
  struct Client *new_client;

  assert(NULL != listener);

  new_client = make_client(NULL);

  fd_open(&new_client->localClient->fd, fd, 1,
          (listener->flags & LISTENER_SSL) ?
	  "Incoming SSL connection" : "Incoming connection");

  /* 
   * copy address to 'sockhost' as a string, copy it to host too
   * so we have something valid to put into error messages...
   */
  memcpy(&new_client->ip, irn, sizeof(struct irc_ssaddr));

  irc_getnameinfo((struct sockaddr*)&new_client->ip,
        new_client->ip.ss_len,  new_client->sockhost, 
        HOSTIPLEN, NULL, 0, NI_NUMERICHOST);
  new_client->aftype = new_client->ip.ss.ss_family;
#ifdef IPV6
  if (new_client->sockhost[0] == ':')
    strlcat(new_client->host, "0", HOSTLEN+1);

  if (new_client->aftype == AF_INET6 && 
      ConfigFileEntry.dot_in_ip6_addr == 1)
  {
    strlcat(new_client->host, new_client->sockhost,HOSTLEN+1);
    strlcat(new_client->host, ".", HOSTLEN+1);
  }
  else
#endif
    strlcat(new_client->host, new_client->sockhost,HOSTLEN+1);

  new_client->connect_id = ++connect_id;
  new_client->localClient->listener = listener;
  ++listener->ref_count;

#ifdef HAVE_LIBCRYPTO
  if (listener->flags & LISTENER_SSL)
  {
    if ((new_client->localClient->fd.ssl = SSL_new(ServerInfo.ctx)) == NULL)
    {
      ilog(L_CRIT, "SSL_new() ERROR! -- %s",
           ERR_error_string(ERR_get_error(), NULL));

      SetDead(new_client);
      exit_client(new_client, new_client, "SSL_new failed");
      return;
    }

    SSL_set_fd(new_client->localClient->fd.ssl, fd);
    ssl_handshake(0, new_client);
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
 * Set the timeout IN SECONDS for the fd
 */
void
comm_settimeout(fde_t *fd, time_t timeout, PF *callback, void *cbdata)
{
  assert(fd->flags.open);

  fd->timeout = CurrentTime + timeout;
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
  int i;
  fde_t *F;
  PF *hdl;
  void *data;

  for (i = 0; i < FD_HASH_SIZE; i++)
    for (F = fd_hash[i]; F != NULL; F = fd_next_in_loop)
    {
      assert(F->flags.open);
      fd_next_in_loop = F->hnext;

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
  struct addrinfo hints, *res;
  char portname[PORTNAMELEN+1];

  assert(callback);
  fd->connect.callback = callback;
  fd->connect.data = data;

  fd->connect.hostaddr.ss.ss_family = aftype;
  fd->connect.hostaddr.ss_port = htons(port);

  /* Note that we're using a passed sockaddr here. This is because
   * generally you'll be bind()ing to a sockaddr grabbed from
   * getsockname(), so this makes things easier.
   * XXX If NULL is passed as local, we should later on bind() to the
   * virtual host IP, for completeness.
   *   -- adrian
   */
  if ((clocal != NULL) && (bind(fd->fd, clocal, socklen) < 0))
  { 
    /* Failure, call the callback with COMM_ERR_BIND */
    comm_connect_callback(fd, COMM_ERR_BIND);
    /* ... and quit */
    return;
  }

  /* Next, if we have been given an IP, get the addr and skip the
   * DNS check (and head direct to comm_connect_tryconnect().
   */
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  snprintf(portname, PORTNAMELEN, "%d", port);

  if (irc_getaddrinfo(host, portname, &hints, &res))
  {
    /* Send the DNS request, for the next level */
    fd->dns_query = MyMalloc(sizeof(struct DNSQuery));
    fd->dns_query->ptr = fd;
    fd->dns_query->callback = comm_connect_dns_callback;
    gethost_byname(host, fd->dns_query);
  }
  else
  {
    /* We have a valid IP, so we just call tryconnect */
    /* Make sure we actually set the timeout here .. */
    assert(res != NULL);
    memcpy(&fd->connect.hostaddr, res->ai_addr, res->ai_addrlen);
    fd->connect.hostaddr.ss_len = res->ai_addrlen;
    fd->connect.hostaddr.ss.ss_family = res->ai_family;
    irc_freeaddrinfo(res);
    comm_settimeout(fd, timeout, comm_connect_timeout, NULL);
    comm_connect_tryconnect(fd, NULL);
  }
}

/*
 * comm_connect_callback() - call the callback, and continue with life
 */
static void
comm_connect_callback(fde_t *fd, int status)
{
  CNCB *hdl;

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
  comm_connect_callback(fd, COMM_ERR_TIMEOUT);
}

/*
 * comm_connect_dns_callback() - called at the completion of the DNS request
 *
 * The DNS request has completed, so if we've got an error, return it,
 * otherwise we initiate the connect()
 */
static void
comm_connect_dns_callback(void *vptr, struct DNSReply *reply)
{
  fde_t *F = vptr;

  if (reply == NULL)
  {
    MyFree(F->dns_query);
    F->dns_query = NULL;
    comm_connect_callback(F, COMM_ERR_DNS);
    return;
  }

  /* No error, set a 30 second timeout */
  comm_settimeout(F, 30, comm_connect_timeout, NULL);

  /* Copy over the DNS reply info so we can use it in the connect() */
  /*
   * Note we don't fudge the refcount here, because we aren't keeping
   * the DNS record around, and the DNS cache is gone anyway.. 
   *     -- adrian
   */
  memcpy(&F->connect.hostaddr, &reply->addr, reply->addr.ss_len);
  /* The cast is hacky, but safe - port offset is same on v4 and v6 */
  ((struct sockaddr_in *) &F->connect.hostaddr)->sin_port =
    F->connect.hostaddr.ss_port;
  F->connect.hostaddr.ss_len = reply->addr.ss_len;

  /* Now, call the tryconnect() routine to try a connect() */
  MyFree(F->dns_query);
  F->dns_query = NULL;
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

  /* Try the connect() */
  retval = connect(fd->fd, (struct sockaddr *) &fd->connect.hostaddr, 
    fd->connect.hostaddr.ss_len);

  /* Error? */
  if (retval < 0)
  {
#ifdef _WIN32
    errno = WSAGetLastError();
#endif
    /*
     * If we get EISCONN, then we've already connect()ed the socket,
     * which is a good thing.
     *   -- adrian
     */
    if (errno == EISCONN)
      comm_connect_callback(fd, COMM_OK);
    else if (ignoreErrno(errno))
      /* Ignore error? Reschedule */
      comm_setselect(fd, COMM_SELECT_WRITE, comm_connect_tryconnect,
                     NULL, 0);
    else
      /* Error? Fail with COMM_ERR_CONNECT */
      comm_connect_callback(fd, COMM_ERR_CONNECT);
    return;
  }

  /* If we get here, we've suceeded, so call with COMM_OK */
  comm_connect_callback(fd, COMM_OK);
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
comm_open(fde_t *F, int family, int sock_type, int proto, const char *note)
{
  int fd;

  /* First, make sure we aren't going to run out of file descriptors */
  if (number_fd >= hard_fdlimit)
  {
    errno = ENFILE;
    return -1;
  }

  /*
   * Next, we try to open the socket. We *should* drop the reserved FD
   * limit if/when we get an error, but we can deal with that later.
   * XXX !!! -- adrian
   */
  fd = socket(family, sock_type, proto);
  if (fd < 0)
  {
#ifdef _WIN32
    errno = WSAGetLastError();
#endif
    return -1; /* errno will be passed through, yay.. */
  }

  execute_callback(setup_socket_cb, fd);

  /* update things in our fd tracking */
  fd_open(F, fd, 1, note);
  return 0;
}

/*
 * comm_accept() - accept an incoming connection
 *
 * This is a simple wrapper for accept() which enforces FD limits like
 * comm_open() does. Returned fd must be either closed or tagged with
 * fd_open (this function no longer does it).
 */
int
comm_accept(struct Listener *lptr, struct irc_ssaddr *pn)
{
  int newfd;
  socklen_t addrlen = sizeof(struct irc_ssaddr);

  if (number_fd >= hard_fdlimit)
  {
    errno = ENFILE;
    return -1;
  }

  /*
   * Next, do the accept(). if we get an error, we should drop the
   * reserved fd limit, but we can deal with that when comm_open()
   * also does it. XXX -- adrian
   */
  newfd = accept(lptr->fd.fd, (struct sockaddr *)pn, (socklen_t *)&addrlen);
  if (newfd < 0)
  {
#ifdef _WIN32
    errno = WSAGetLastError();
#endif
    return -1;
  }

#ifdef IPV6
  remove_ipv6_mapping(pn);
#else
  pn->ss_len = addrlen;
#endif

  execute_callback(setup_socket_cb, newfd);

  /* .. and return */
  return newfd;
}

/* 
 * remove_ipv6_mapping() - Removes IPv4-In-IPv6 mapping from an address
 * This function should really inspect the struct itself rather than relying
 * on inet_pton and inet_ntop.  OSes with IPv6 mapping listening on both
 * AF_INET and AF_INET6 map AF_INET connections inside AF_INET6 structures
 * 
 */
#ifdef IPV6
void
remove_ipv6_mapping(struct irc_ssaddr *addr)
{
  if (addr->ss.ss_family == AF_INET6)
  {
    struct sockaddr_in6 *v6;

    v6 = (struct sockaddr_in6*)addr;
    if (IN6_IS_ADDR_V4MAPPED(&v6->sin6_addr))
    {
      char v4ip[HOSTIPLEN];
      struct sockaddr_in *v4 = (struct sockaddr_in*)addr;
      inetntop(AF_INET6, &v6->sin6_addr, v4ip, HOSTIPLEN);
      inet_pton(AF_INET, v4ip, &v4->sin_addr);
      addr->ss.ss_family = AF_INET;
      addr->ss_len = sizeof(struct sockaddr_in);
    }
    else 
      addr->ss_len = sizeof(struct sockaddr_in6);
  }
  else
    addr->ss_len = sizeof(struct sockaddr_in);
} 
#endif
