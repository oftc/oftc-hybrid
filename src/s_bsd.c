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
#include <netinet/tcp.h>
#include "fdlist.h"
#include "s_bsd.h"
#include "client.h"
#include "common.h"
#include "event.h"
#include "irc_string.h"
#include "irc_getnameinfo.h"
#include "irc_getaddrinfo.h"
#include "ircdauth.h"
#include "ircd.h"
#include "list.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "irc_res.h"
#include "restart.h"
#include "s_auth.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "s_stats.h"
#include "send.h"
#include "memory.h"


#ifndef IN_LOOPBACKNET
#define IN_LOOPBACKNET        0x7f
#endif

#ifndef INADDR_NONE
#define INADDR_NONE ((unsigned int) 0xffffffff)
#endif

const char* const NONB_ERROR_MSG   = "set_non_blocking failed for %s:%s"; 
const char* const OPT_ERROR_MSG    = "disable_sock_options failed for %s:%s";
const char* const SETBUF_ERROR_MSG = "set_sock_buffers failed for server %s:%s";

static const char *comm_err_str[] = { "Comm OK", "Error during bind()",
  "Error during DNS lookup", "connect timeout", "Error during connect()",
  "Comm Error" };

static void comm_connect_callback(int fd, int status);
static PF comm_connect_timeout;
static void comm_connect_dns_callback(void *vptr, struct DNSReply *reply);
static PF comm_connect_tryconnect;

/* close_all_connections() can be used *before* the system come up! */

void
close_all_connections(void)
{
  int i;
  int fd;

  for (i = 0; i < HARD_FDLIMIT; ++i)
  {
    if (fd_table[i].flags.open)
      fd_close(i);
    else
      close(i);
  }

  /* Make sure stdio descriptors (0-2) and profiler descriptor (3)
     always go somewhere harmless.  Use -foreground for profiling
     or executing from gdb */
  for (i = 0; i < LOWEST_SAFE_FD; i++)
  {
    if ((fd = open(PATH_DEVNULL, O_RDWR)) < 0)
      exit(-1); /* we're hosed if we can't even open /dev/null */
  }

  /* While we're here, let's check if the system can open AF_INET6 sockets */
  check_can_use_v6();
}

/*
 * check_can_use_v6()
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
    close(v6);
  }
#else
  ServerInfo.can_use_v6 = 0;
#endif
}

/*
 * get_sockerr - get the error value from the socket or the current errno
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
report_error(int level, const char* text, const char* who, int error) 
{
  who = (who) ? who : "";

  sendto_gnotice_flags(FLAGS_DEBUG, L_OPER, me.name, &me, NULL, text, who, strerror(error));

  ilog(L_ERROR, text, who, strerror(error));
}

/*
 * set_sock_buffers - set send and receive buffers for socket
 * 
 * inputs	- fd file descriptor
 * 		- size to set
 * output       - returns true (1) if successful, false (0) otherwise
 * side effects -
 */
int
set_sock_buffers(int fd, int size)
{
  if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char*) &size, sizeof(size)) ||
      setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char*) &size, sizeof(size)))
    return 0;
  return 1;
}

/*
 * disable_sock_options
 * 
 * inputs	- fd
 * output	- returns true (1) if successful, false (0) otherwise
 * side effects - disable_sock_options - if remote has any socket options set,
 *                disable them 
 */
int
disable_sock_options(int fd)
{
#if 0 
defined(IP_OPTIONS) && defined(IPPROTO_IP) && !defined(IPV6)
  if (setsockopt(fd, IPPROTO_IP, IP_OPTIONS, NULL, 0))
    return 0;
#endif
  return 1;
}

/*
 * set_non_blocking - Set the client connection into non-blocking mode. 
 *
 * inputs	- fd to set into non blocking mode
 * output	- 1 if successful 0 if not
 * side effects - use POSIX compliant non blocking and
 *                be done with it.
 */
int
set_non_blocking(int fd)
{
#ifndef VMS
  int nonb = 0;
  int res;

#ifdef USE_SIGIO
  setup_sigio_fd(fd);
#endif

  nonb |= O_NONBLOCK;
  res = fcntl(fd, F_GETFL, 0);
  if (-1 == res || fcntl(fd, F_SETFL, res | nonb) == -1)
    return 0;

  fd_table[fd].flags.nonblocking = 1;
  return 1;
#endif
}

/*
 * set_no_delay()
 *
 * inputs       - fd
 * output       - NONE
 * side effects - disable Nagle algorithm if possible
 */
void
set_no_delay(int fd)
{
  int opt = 1;

  setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (char *) &opt, sizeof(opt));
}

/*
 * close_connection
 *        Close the physical connection. This function must make
 *        MyConnect(client_p) == FALSE, and set client_p->from == NULL.
 */
void
close_connection(struct Client *client_p)
{
  struct ConfItem *aconf;
  assert(NULL != client_p);
  if(client_p == NULL)
    return;
  if (IsServer(client_p))
    {
      ServerStats->is_sv++;
      ServerStats->is_sbs += client_p->localClient->sendB;
      ServerStats->is_sbr += client_p->localClient->receiveB;
      ServerStats->is_sks += client_p->localClient->sendK;
      ServerStats->is_skr += client_p->localClient->receiveK;
      ServerStats->is_sti += CurrentTime - client_p->firsttime;
      if (ServerStats->is_sbs > 2047)
        {
          ServerStats->is_sks += (ServerStats->is_sbs >> 10);
          ServerStats->is_sbs &= 0x3ff;
        }
      if (ServerStats->is_sbr > 2047)
        {
          ServerStats->is_skr += (ServerStats->is_sbr >> 10);
          ServerStats->is_sbr &= 0x3ff;
        }
      /*
       * If the connection has been up for a long amount of time, schedule
       * a 'quick' reconnect, else reset the next-connect cycle.
       */
      if ((aconf = find_conf_exact(client_p->name, client_p->username,
                                   client_p->host, CONF_SERVER)))
        {
          /*
           * Reschedule a faster reconnect, if this was a automatically
           * connected configuration entry. (Note that if we have had
           * a rehash in between, the status has been changed to
           * CONF_ILLEGAL). But only do this if it was a "good" link.
           */
          aconf->hold = time(NULL);
          aconf->hold += (aconf->hold - client_p->since > HANGONGOODLINK) ?
            HANGONRETRYDELAY : ConfConFreq(aconf);
          if (nextconnect > aconf->hold)
            nextconnect = aconf->hold;
        }

    }
  else if (IsClient(client_p))
    {
      ServerStats->is_cl++;
      ServerStats->is_cbs += client_p->localClient->sendB;
      ServerStats->is_cbr += client_p->localClient->receiveB;
      ServerStats->is_cks += client_p->localClient->sendK;
      ServerStats->is_ckr += client_p->localClient->receiveK;
      ServerStats->is_cti += CurrentTime - client_p->firsttime;
      if (ServerStats->is_cbs > 2047)
        {
          ServerStats->is_cks += (ServerStats->is_cbs >> 10);
          ServerStats->is_cbs &= 0x3ff;
        }
      if (ServerStats->is_cbr > 2047)
        {
          ServerStats->is_ckr += (ServerStats->is_cbr >> 10);
          ServerStats->is_cbr &= 0x3ff;
        }
    }
  else
    ServerStats->is_ni++;
  
  if (!IsDead(client_p))
    {
      /* attempt to flush any pending dbufs. Evil, but .. -- adrian */
      send_queued_write(client_p->localClient->fd, client_p);
      fd_close(client_p->localClient->fd);
      client_p->localClient->fd = -1;
    }

  if(HasServlink(client_p))
    {
      if(client_p->localClient->ctrlfd > -1)
      {
        fd_close(client_p->localClient->ctrlfd);
#ifndef HAVE_SOCKETPAIR
        fd_close(client_p->localClient->ctrlfd_r);
        fd_close(client_p->localClient->fd_r);
        client_p->localClient->ctrlfd_r = -1;
        client_p->localClient->fd_r = -1;
#endif
        client_p->localClient->ctrlfd = -1;
      }
    }
  
  linebuf_donebuf(&client_p->localClient->buf_sendq);
  linebuf_donebuf(&client_p->localClient->buf_recvq);
  memset(client_p->localClient->passwd, 0, sizeof(client_p->localClient->passwd));
  det_confs_butmask(client_p, 0);
  client_p->from = NULL; /* ...this should catch them! >:) --msa */
}

/*
 * add_connection - creates a client which has just connected to us on 
 * the given fd. The sockhost field is initialized with the ip# of the host.
 * The client is sent to the auth module for verification, and not put in
 * any client list yet.
 */
void
add_connection(struct Listener* listener, int fd)
{
  struct Client*     new_client;
  socklen_t len = sizeof(struct irc_ssaddr);
  struct irc_ssaddr   irn;
  assert(NULL != listener);

#ifdef USE_IAUTH
  if (iAuth.socket == NOSOCK)
  {
    send(fd,
      "NOTICE AUTH :*** Ircd Authentication Server is temporarily down, please connect later\r\n",
      87,
      0);
    fd_close(fd);
    return;
  }
#endif

  /* 
   * get the client socket name from the socket
   * the client has already been checked out in accept_connection
   */

  memset(&irn, 0, sizeof(irn));
  if (getpeername(fd, (struct sockaddr *)&irn, (socklen_t *)&len))
  {
    report_error(L_ALL, "Failed in adding new connection %s :%s", 
            get_listener_name(listener), errno);
    ServerStats->is_ref++;
    fd_close(fd);
    return;
  }

#ifdef IPV6
  remove_ipv6_mapping(&irn);
#else
  irn.ss_len = len;
#endif
  new_client = make_client(NULL);
  memset(&new_client->localClient->ip, 0, sizeof(struct irc_ssaddr));

  /* 
   * copy address to 'sockhost' as a string, copy it to host too
   * so we have something valid to put into error messages...
   */
  new_client->localClient->port = ntohs(irn.ss_port);
  memcpy(&new_client->localClient->ip, &irn, sizeof(struct irc_ssaddr));
  
  irc_getnameinfo((struct sockaddr*)&new_client->localClient->ip,
        new_client->localClient->ip.ss_len,  new_client->localClient->sockhost, 
        HOSTIPLEN, NULL, 0, NI_NUMERICHOST);
  new_client->localClient->aftype = new_client->localClient->ip.ss.ss_family;
  
  *new_client->host = '\0';
#ifdef IPV6
  if(*new_client->localClient->sockhost == ':')
    strlcat(new_client->host, "0",HOSTLEN+1);

  if(new_client->localClient->aftype == AF_INET6 && 
        ConfigFileEntry.dot_in_ip6_addr == 1)
  {
    strlcat(new_client->host, new_client->localClient->sockhost,HOSTLEN+1);
    strlcat(new_client->host, ".",HOSTLEN+1);
  } else
#endif
    strlcat(new_client->host, new_client->localClient->sockhost,HOSTLEN+1);

  new_client->localClient->fd        = fd;
  
  new_client->localClient->listener  = listener;
  ++listener->ref_count;

  if (!set_non_blocking(new_client->localClient->fd))
    report_error(L_ALL, NONB_ERROR_MSG, get_client_name(new_client, SHOW_IP), errno);
  if (!disable_sock_options(new_client->localClient->fd))
    report_error(L_ALL, OPT_ERROR_MSG, get_client_name(new_client, SHOW_IP), errno);
  start_auth(new_client);
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
comm_settimeout(int fd, time_t timeout, PF *callback, void *cbdata)
{
    assert(fd > -1);
    assert(fd_table[fd].flags.open);

    fd_table[fd].timeout = CurrentTime + (timeout / 1000);
    fd_table[fd].timeout_handler = callback;
    fd_table[fd].timeout_data = cbdata;
}


/*
 * comm_setflush() - set a flush function
 *
 * A flush function is simply a function called if found during
 * comm_timeouts(). Its basically a second timeout, except in this case
 * I'm too lazy to implement multiple timeout functions! :-)
 * its kinda nice to have it seperate, since this is designed for
 * flush functions, and when comm_close() is implemented correctly
 * with close functions, we _actually_ don't call comm_close() here ..
 */
void
comm_setflush(int fd, time_t timeout, PF *callback, void *cbdata)
{
    assert(fd > -1);
    assert(fd_table[fd].flags.open);

    fd_table[fd].flush_timeout = CurrentTime + (timeout / 1000);
    fd_table[fd].flush_handler = callback;
    fd_table[fd].flush_data = cbdata;
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
    int fd;
    PF *hdl;
    void *data;

    for (fd = 0; fd <= highest_fd; fd++)
      {
        if (!fd_table[fd].flags.open)
            continue;
        if (fd_table[fd].flags.closing)
            continue;

        /* check flush functions */
        if (fd_table[fd].flush_handler &&
            fd_table[fd].flush_timeout > 0 && fd_table[fd].flush_timeout 
            < CurrentTime)
	  {
            hdl = fd_table[fd].flush_handler;
            data = fd_table[fd].flush_data;
            comm_setflush(fd, 0, NULL, NULL);
            hdl(fd, data);
	  }

        /* check timeouts */
        if (fd_table[fd].timeout_handler &&
            fd_table[fd].timeout > 0 && fd_table[fd].timeout < CurrentTime)
	  {
            /* Call timeout handler */
            hdl = fd_table[fd].timeout_handler;
            data = fd_table[fd].timeout_data;
            comm_settimeout(fd, 0, NULL, NULL);
            hdl(fd, fd_table[fd].timeout_data);           
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
comm_connect_tcp(int fd, const char *host, unsigned short port,
                 struct sockaddr *clocal, int socklen, CNCB *callback,
                 void *data, int aftype, int timeout)
{
 struct addrinfo hints, *res;
 char portname[PORTNAMELEN+1];
 
 fd_table[fd].flags.called_connect = 1;
 assert(callback);
 fd_table[fd].connect.callback = callback;
 fd_table[fd].connect.data = data;

 fd_table[fd].connect.hostaddr.ss.ss_family = aftype;
 fd_table[fd].connect.hostaddr.ss_port = htons(port);
 /* Note that we're using a passed sockaddr here. This is because
  * generally you'll be bind()ing to a sockaddr grabbed from
  * getsockname(), so this makes things easier.
  * XXX If NULL is passed as local, we should later on bind() to the
  * virtual host IP, for completeness.
  *   -- adrian
  */
 if ((clocal != NULL) && (bind(fd, clocal, socklen) < 0))
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
  fd_table[fd].dns_query = MyMalloc(sizeof(struct DNSQuery));
  fd_table[fd].dns_query->ptr = &fd_table[fd];
  fd_table[fd].dns_query->callback = comm_connect_dns_callback;
  gethost_byname(host, fd_table[fd].dns_query);
 }
 else
 {
  /* We have a valid IP, so we just call tryconnect */
  /* Make sure we actually set the timeout here .. */
  assert(res != NULL);
  memcpy(&fd_table[fd].connect.hostaddr, res->ai_addr, res->ai_addrlen);
  fd_table[fd].connect.hostaddr.ss_len = res->ai_addrlen;
  fd_table[fd].connect.hostaddr.ss.ss_family = res->ai_family;
  irc_freeaddrinfo(res);
  comm_settimeout(fd, timeout*1000, comm_connect_timeout, NULL);
  comm_connect_tryconnect(fd, NULL);
 }
}

/*
 * comm_connect_callback() - call the callback, and continue with life
 */
static void
comm_connect_callback(int fd, int status)
{
 CNCB *hdl;
 /* This check is gross..but probably necessary */
 if(fd_table[fd].connect.callback == NULL)
 	return;
 /* Clear the connect flag + handler */
 hdl = fd_table[fd].connect.callback;
 fd_table[fd].connect.callback = NULL;
 fd_table[fd].flags.called_connect = 0;
  
 /* Clear the timeout handler */
 comm_settimeout(fd, 0, NULL, NULL);
  
 /* Call the handler */
 hdl(fd, status, fd_table[fd].connect.data);
}


/*
 * comm_connect_timeout() - this gets called when the socket connection
 * times out. This *only* can be called once connect() is initially
 * called ..
 */
static void
comm_connect_timeout(int fd, void *notused)
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

    if(reply == NULL)
    {
      comm_connect_callback(F->fd, COMM_ERR_DNS);
      return;
    }
    
    /* No error, set a 10 second timeout */
    comm_settimeout(F->fd, 30*1000, comm_connect_timeout, NULL);

    /* Copy over the DNS reply info so we can use it in the connect() */
    /*
     * Note we don't fudge the refcount here, because we aren't keeping
     * the DNS record around, and the DNS cache is gone anyway.. 
     *     -- adrian
     */
#ifdef IPV6
    if(reply->h_addrtype == AF_INET6)
    {
      memcpy(&F->connect.hostaddr, &reply->addr, 
            sizeof(struct irc_ssaddr));
    }
    else
#endif
    {
      memcpy(&F->connect.hostaddr, &reply->addr,
            sizeof(struct irc_ssaddr));
    }
    /* Now, call the tryconnect() routine to try a connect() */
    MyFree(reply); 
    comm_connect_tryconnect(F->fd, NULL);
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
comm_connect_tryconnect(int fd, void *notused)
{
 int retval;
 /* This check is needed or re-entrant s_bsd_* like sigio break it. */
 if (fd_table[fd].connect.callback == NULL)
   return;
 /* Try the connect() */
 retval = connect(fd, (struct sockaddr *) &fd_table[fd].connect.hostaddr, 
        fd_table[fd].connect.hostaddr.ss_len);
 /* Error? */
 if (retval < 0)
 {
  /*
   * If we get EISCONN, then we've already connect()ed the socket,
   * which is a good thing.
   *   -- adrian
   */
  if (errno == EISCONN)
   comm_connect_callback(fd, COMM_OK);
  else if (ignoreErrno(errno))
   /* Ignore error? Reschedule */
   comm_setselect(fd, FDLIST_SERVER, COMM_SELECT_WRITE,
                  comm_connect_tryconnect, NULL, 0);
  else
   /* Error? Fail with COMM_ERR_CONNECT */
   comm_connect_callback(fd, COMM_ERR_CONNECT);
  return;
 }
 /* If we get here, we've suceeded, so call with COMM_OK */
 comm_connect_callback(fd, COMM_OK);
}

/*
 * comm_error_str() - return an error string for the given error condition
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
comm_open(int family, int sock_type, int proto, const char *note)
{
  int fd;
  /* First, make sure we aren't going to run out of file descriptors */
  if (number_fd >= MASTER_MAX)
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
    return -1; /* errno will be passed through, yay.. */

  /* Set the socket non-blocking, and other wonderful bits */
  if (!set_non_blocking(fd))
    {
      ilog(L_CRIT, "comm_open: Couldn't set FD %d non blocking: %s", fd, strerror(errno));
    /* if VMS, we might be opening a file (ircd.conf, resolv.conf).
       VMS doesn't let us set non-blocking on a file, so it might fail. */
#ifndef VMS
      close(fd);
      return -1;
#endif
    }

  /* Next, update things in our fd tracking */
  fd_open(fd, FD_SOCKET, note);
  return fd;
}


/*
 * comm_accept() - accept an incoming connection
 *
 * This is a simple wrapper for accept() which enforces FD limits like
 * comm_open() does.
 */
int
comm_accept(int fd, struct irc_ssaddr *pn)
{
  int newfd;
  socklen_t addrlen = sizeof(struct irc_ssaddr);
  if (number_fd >= MASTER_MAX)
    {
      errno = ENFILE;
      return -1;
    }

  /*
   * Next, do the accept(). if we get an error, we should drop the
   * reserved fd limit, but we can deal with that when comm_open()
   * also does it. XXX -- adrian
   */
  newfd = accept(fd, (struct sockaddr *)pn, (socklen_t *)&addrlen);
  if (newfd < 0)
    return -1;

#ifdef IPV6
  remove_ipv6_mapping(pn);
#else
  pn->ss_len = addrlen;
#endif
 
  /* Set the socket non-blocking, and other wonderful bits */
  if (!set_non_blocking(newfd))
    {
      ilog(L_CRIT, "comm_accept: Couldn't set FD %d non blocking!", newfd);
      close(newfd);
      return -1;
    }

  /* Next, tag the FD as an incoming connection */
  fd_open(newfd, FD_SOCKET, "Incoming connection");

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
  if(addr->ss.ss_family == AF_INET6)
  {
    struct sockaddr_in6 *v6;

    v6 = (struct sockaddr_in6*)addr;
    if(IN6_IS_ADDR_V4MAPPED(&v6->sin6_addr))
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
