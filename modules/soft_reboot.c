/************************************************************************
 *   IRC - Internet Relay Chat, contrib/soft_reboot.c
 *   Copyright (C) 2006 Hybrid Development Team
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

#include "stdinc.h"
#include "s_conf.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "list.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "parse.h"
#include "restart.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "userhost.h"
#include "irc_string.h"
#include "s_log.h"
#include "s_bsd.h"

#ifdef HAVE_LIBCRYPTO
#define CanForward(x)   (!IsDefunct(x) && !(x)->localClient->fd.ssl)
#else
#define CanForward(x)   (!IsDefunct(x))
#endif

static dlink_node *h_shutdown, *h_verify;

struct SocketInfo
{
  int fd;
  int ctrlfd;
  int namelen;
  int pwdlen;
  int caplen;
  int recvqlen;
  int sendqlen;
  int slinkqofs;
  int slinkqlen;
  time_t first;
  time_t last;
};

/*
 * serverize()
 *
 * Turns a dummy client into a server.
 *
 * inputs: client pointer
 * output: none
 */
static void
serverize(struct Client *client_p)
{
  struct ConfItem *sconf = make_conf_item(SERVER_TYPE);
  //char *hub_mask;

  DupString(sconf->name, client_p->name);

  /*DupString(hub_mask, "*");
  dlinkAdd(hub_mask, make_dlink_node(), &sconf->hub_list);*/

  conf_add_class_to_conf(sconf, NULL);
  attach_conf(client_p, sconf);
  client_p->serv->sconf = find_conf_name(&client_p->localClient->confs,
                                         client_p->name, SERVER_TYPE);

  SetServer(client_p);
}

/*
 * make_dummy()
 *
 * Prepares a dummy server-alike local client.
 *
 * inputs: file descriptor to use
 * output: client pointer
 */
static struct Client *
make_dummy(int transfd)
{
  dlink_node *m;
  struct Client *client_p = make_client(NULL);

  fd_open(&client_p->localClient->fd, transfd, 1, "Softboot");
  client_p->localClient->caps = -1;

  strcpy(client_p->name, ".");
  strcpy(client_p->id, "...");
  hash_add_client(client_p);
  hash_add_id(client_p);
  dlinkAdd(client_p, &client_p->node, &global_client_list);

  m = dlinkFind(&unknown_list, client_p);
  dlinkDelete(m, &unknown_list);
  dlinkAdd(client_p, m, &serv_list);
  dlinkAdd(client_p, make_dlink_node(), &global_serv_list);

  make_server(client_p);
  serverize(client_p);

  return client_p;
}

/*
 * write_dbuf()
 *
 * Writes the contents of a dbuf to the given socket.
 *
 * inputs:
 *   transfd  -  where to write to
 *   dbuf     -  dbuf pointer
 * output: none
 */
static void
write_dbuf(int transfd, struct dbuf_queue *dbuf)
{
  while(dbuf_length(dbuf) > 0)
  {
    struct dbuf_block *first = dbuf->blocks.head->data;

    write(transfd, first->data, first->size);
    dbuf_delete(dbuf, first->size);
  }
}

/*
 * introduce_socket()
 *
 * Encodes and writes socket information about the given client.
 *
 * inputs:
 *   transfd   -  where to write to
 *   client_p  -  local client to inform about
 * output: none
 */
static void
introduce_socket(int transfd, struct Client *client_p)
{
  struct SocketInfo si;
  const char *capabs = "";

  if(!CanForward(client_p) || client_p->localClient->fd.fd == transfd)
    return;

  if(IsServer(client_p))
    capabs = show_capabilities(client_p);

  si.fd = client_p->localClient->fd.fd;
  si.ctrlfd = client_p->localClient->ctrlfd.flags.open ?
              client_p->localClient->ctrlfd.fd : -1;
  si.namelen = strlen(client_p->name);
  si.pwdlen = EmptyString(client_p->localClient->passwd) ? 0 :
              strlen(client_p->localClient->passwd);
  si.caplen = strlen(capabs);
  si.recvqlen = dbuf_length(&client_p->localClient->buf_recvq);
  si.sendqlen = dbuf_length(&client_p->localClient->buf_sendq);
  si.slinkqofs = client_p->localClient->slinkq_ofs;
  si.slinkqlen = client_p->localClient->slinkq_len;
  si.first = client_p->firsttime;
  si.last = client_p->localClient->last;

  write(transfd, &si, sizeof(si));
  write(transfd, client_p->name, si.namelen);

  if(si.pwdlen > 0)
    write(transfd, client_p->localClient->passwd, si.pwdlen);

  if(si.caplen > 0)
    write(transfd, capabs, si.caplen);

  write_dbuf(transfd, &client_p->localClient->buf_recvq);
  write_dbuf(transfd, &client_p->localClient->buf_sendq);

  if(si.slinkqlen > 0)
    write(transfd, client_p->localClient->slinkq, si.slinkqlen);
}

/*
 * do_shutdown()
 *
 * Implements the /RESTART part of the soft reboot code.
 *
 * inputs:
 *   msg    -  shutdown message
 *   rboot  -  1 if it's a restart, 0 if plain exit
 * output: none
 */
static void *
do_shutdown(va_list args)
{
  const char *msg = va_arg(args, const char *);
  int rboot = va_arg(args, int);
  struct Client *client_p;
  dlink_node *ptr;
  int transfd[2];
  char buf[24];

  if(!rboot || socketpair(AF_UNIX, SOCK_STREAM, 0, transfd) < 0)
    return pass_callback(h_shutdown, msg, rboot);

  if(EmptyString(msg))
  {
    ilog(L_CRIT, "Server Soft-Rebooting");
    sendto_realops_flags(UMODE_ALL, L_ALL, "Server Soft-Rebooting");
  }
  else
  {
    ilog(L_CRIT, "Server Soft-Rebooting: %s", msg);
    sendto_realops_flags(UMODE_ALL, L_ALL, "Server Soft-Rebooting: %s", msg);
  }

  //
  // Prevent all sockets which belong to registered users/servers from
  // being closed on exec().
  //
  fcntl(transfd[0], F_SETFD, 0);

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    client_p = ptr->data;

    if(CanForward(client_p))
    {
      fcntl(client_p->localClient->fd.fd, F_SETFD, 0);

      if(client_p->localClient->list_task != NULL)
        sendto_one(client_p, form_str(RPL_LISTEND), me.name, client_p->name);
    }
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    client_p = ptr->data;

    if(CanForward(client_p))
      fcntl(client_p->localClient->fd.fd, F_SETFD, 0);
  }

  close_listeners();
  unlink(pidFileName);

  //
  // Start the new ircd.
  //
  switch(fork())
  {
    case -1:
      ilog(L_CRIT, "Unable to fork(): %s", strerror(errno));
      exit(1);

    case 0:
    {
      int i;
      char **argv;

      close(transfd[1]);
      snprintf(buf, sizeof(buf), "softboot_%d", transfd[0]);

      for(i = 0; myargv[i] != NULL; i++);

      argv = MyMalloc((i + 2) * sizeof(char *));

      for(i = 0; myargv[i] != NULL; i++)
        argv[i] = myargv[i];

      argv[i++] = buf;
      argv[i] = NULL;

      execv(SPATH, argv);
      ilog(L_CRIT, "Unable to exec(): %s", strerror(errno));
      exit(1);
    }
  }

  //
  // Pass our data.
  //
  burst_all(make_dummy(transfd[1]));
  send_queued_all();

  snprintf(buf, sizeof(buf), "\001%ld\r\n", me.since);
  write(transfd[1], buf, strlen(buf));

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    introduce_socket(transfd[1], ptr->data);
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    introduce_socket(transfd[1], ptr->data);
  }

  exit(0);
}

/*
 * restore_socket()
 *
 * Restores socket related fields in struct LocalUser.
 *
 * inputs:
 *   client_p  -  client pointer
 *   fd        -  file descriptor
 *   ctrlfd    -  servlink control fd
 *   first     -  when the client was created
 *   last      -  since when the client is idle
 * output: none
 */
static void
restore_socket(struct Client *client_p, int fd, int ctrlfd,
               time_t first, time_t last)
{
  char buf[HOSTLEN + 16];
  struct irc_ssaddr addr;
  int family, port;

  snprintf(buf, sizeof(buf), IsClient(client_p) ? "Nick: %s" :
           (ctrlfd >= 0 ? "slink data: %s" : "Server: %s"),
           client_p->name);

  client_p->localClient = BlockHeapAlloc(lclient_heap);
  //  attach_conf(client_p, default_class);

  fd_open(&client_p->localClient->fd, fd, 1, buf);
  fcntl(fd, F_SETFD, FD_CLOEXEC);

  if(ctrlfd >= 0)
  {
    snprintf(buf, sizeof(buf), "slink ctrl: %s", client_p->name);
    fd_open(&client_p->localClient->ctrlfd, ctrlfd, 1, buf);
  }

  addr.ss_len = sizeof(addr);
  getsockname(fd, (struct sockaddr *) &addr, &addr.ss_len);
  family = addr.ss.sin_family;
  port = ntohs(addr.ss.sin_port);

  if(!(client_p->localClient->listener = find_listener(port, &addr)))
  {
    memset(&addr.ss, 0, sizeof(addr.ss));
    addr.ss.sin_family = family;
    addr.ss.sin_port = port;
    client_p->localClient->listener = find_listener(port, &addr);
  }

  client_p->localClient->ip.ss_len = sizeof(client_p->localClient->ip.ss);
  getpeername(fd, (struct sockaddr *) &client_p->localClient->ip,
              &client_p->localClient->ip.ss_len);
  client_p->localClient->aftype = client_p->localClient->ip.ss.sin_family;

  irc_getnameinfo((struct sockaddr *) &client_p->localClient->ip,
                  client_p->localClient->ip.ss_len, client_p->sockhost,
                  sizeof(client_p->sockhost), NULL, 0, NI_NUMERICHOST);

  client_p->servptr = &me;
  client_p->since = client_p->lasttime = CurrentTime;
  client_p->firsttime = first;
  client_p->localClient->last = last;

  client_p->localClient->allow_read = MAX_FLOOD;
  comm_setflush(&client_p->localClient->fd, 1000, flood_recalc, client_p);

  client_p->flags |= FLAGS_FINISHED_AUTH;
  comm_setselect(&client_p->localClient->fd, COMM_SELECT_READ, read_packet,
                 client_p, 0);
}

/*
 * restore_client()
 * restore_server()
 *
 * Restores a local user/server entity.
 *
 * inputs:
 *   client_p  -  client pointer
 *   capabs    -  user/server capab string
 * output: none
 */
static void
restore_client(struct Client *client_p, char *capabs)
{
  char userbuf[USERLEN + 1];
  struct Class *cptr;

  if(client_p->username[0] != '~')
    SetGotId(client_p);

  strlcpy(userbuf, client_p->username + !IsGotId(client_p),
          sizeof(userbuf));

  if((cptr = execute_callback(client_check_cb, client_p, userbuf)))
    attach_conf(client_p, cptr);

  Count.local++, Count.totalrestartcount++;

  if(Count.local > Count.max_loc)
    Count.max_loc = Count.local;

  delete_user_host(client_p->username, client_p->host, 1);
  add_user_host(client_p->username, client_p->host, 0);
  SetUserHost(client_p);

  dlinkAdd(client_p, &client_p->localClient->lclient_node, &local_client_list);
  dlinkAdd(client_p, &client_p->lnode, &me.serv->client_list);

  if(IsOper(client_p))
    dlinkAdd(client_p, make_dlink_node(), &oper_list);
}

static void
restore_server(struct Client *client_p, char *capabs)
{
  char *p = NULL, *s = NULL;
  int cap;

  SetGotId(client_p);

  for(s = strtoken(&p, capabs, " "); s; s = strtoken(&p, NULL, " "))
    if((cap = find_capability(s)) != 0)
      SetCapable(client_p, cap);

  if(check_server(client_p->name, client_p, NO) != 0)
    serverize(client_p);

  set_chcap_usage_counts(client_p);
  Count.myserver++;

  dlinkAdd(client_p, &client_p->localClient->lclient_node, &serv_list);
  dlinkAdd(client_p, &client_p->lnode, &me.serv->server_list);
}

/*
 * discover_from()
 *
 * Returns correct value of a client's from field.
 *
 * inputs: client pointer
 * output: from
 */
static struct Client *
discover_from(struct Client *client_p)
{
  return IsMe(client_p->servptr) ? client_p : discover_from(client_p->servptr);
}

/*
 * restore_dbuf()
 *
 * Loads a dbuf contents from a file stream.
 *
 * inputs:
 *   f     -  file stream
 *   dbuf  -  dbuf to fill or NULL
 *   cnt   -  number of bytes to read
 * output: none
 */
static void
restore_dbuf(FILE *f, struct dbuf_queue *dbuf, int cnt)
{
  while(cnt > 0)
  {
    int nread = fread(readBuf, 1, LIBIO_MIN(sizeof(readBuf), cnt), f);

    if(dbuf != NULL)
      dbuf_put(dbuf, readBuf, nread);

    cnt -= nread;
  }
}

/*
 * load_state()
 *
 * Loads ircd state from a socket stream.
 *
 * inputs: socket fd
 * output: none
 */
static void
load_state(int transfd)
{
  FILE *f = fdopen(transfd, "r");
  char buf[IRCD_BUFSIZE + 1], *p, *parv[4] = {NULL, NULL, "-o", NULL};
  struct Client *client_p;
  struct SocketInfo si;
  dlink_node *ptr, *ptr_next;

  //
  // Read server burst from &me
  //
  fd_open(&me.localClient->fd, transfd, 1, "Softboot");
  serverize(&me);

  while(fgets(buf, sizeof(buf), f))
  {
    if((p = strpbrk(buf, "\r\n")) != NULL)
      * p = 0;

    if(buf[0] == '\001')
    {
      me.since = atoi(buf + 1);
      break;
    }

    parse(&me, buf, buf + strlen(buf));
  }

  SetMe(&me);
  unref_link(me.serv->sconf);
  me.serv->sconf = NULL;

  //
  // Read local client information
  //
  while(fread(&si, sizeof(si), 1, f) == 1)
  {
    if(si.fd == -1)
      break;

    assert(si.namelen < IRCD_BUFSIZE);
    assert(si.caplen < IRCD_BUFSIZE);

    fread(buf, 1, si.namelen, f);
    buf[si.namelen] = 0;

    if((client_p = find_client(buf)) != NULL)
      restore_socket(client_p, si.fd, si.ctrlfd, si.first, si.last);
    else
      close(si.fd);

    fread(buf, 1, si.pwdlen, f);

    if(client_p != NULL && si.pwdlen > 0)
    {
      buf[si.pwdlen] = 0;
      DupString(client_p->localClient->passwd, buf);
    }

    fread(buf, 1, si.caplen, f);
    buf[si.caplen] = 0;

    if(client_p != NULL)
      (IsServer(client_p) ? restore_server : restore_client)(client_p, buf);

    restore_dbuf(f, client_p ? &client_p->localClient->buf_recvq : NULL,
                 si.recvqlen);
    restore_dbuf(f, client_p ? &client_p->localClient->buf_sendq : NULL,
                 si.sendqlen);

    if(si.slinkqlen > 0)
    {
      client_p->localClient->slinkq = MyMalloc(si.slinkqlen);
      fread(client_p->localClient->slinkq, 1, si.slinkqlen, f);
      client_p->localClient->slinkq_ofs = si.slinkqofs;
      client_p->localClient->slinkq_len = si.slinkqlen;
    }
  }

  //
  // Finalization
  //
  DLINK_FOREACH_SAFE(ptr, ptr_next, global_client_list.head)
  {
    client_p = ptr->data;
    client_p->from = discover_from(client_p);

    if(client_p->from == client_p && !client_p->localClient)
    {
      SetDead(client_p);
      client_p->localClient = BlockHeapAlloc(lclient_heap);
      exit_client(client_p, &me, "Soft reboot");
    }
  }

  while(oper_list.head != NULL)
  {
    client_p = oper_list.head->data;
    parv[0] = parv[1] = client_p->name;
    set_user_mode(client_p, client_p, 4, parv);
  }

  fd_close(&me.localClient->fd);
  fclose(f);
  send_queued_all();
}

/*
 * do_verify_conf()
 *
 * Handles the conf verification callback.
 *
 * inputs: none
 * output: none
 */
static void *
do_verify_conf(va_list args)
{
  pass_callback(h_verify);

  if(conf_cold)
  {
    int i;

    for(i = 0; myargv[i] != NULL; i++)
      if(!ircncmp(myargv[i], "softboot_", 9))
      {
        load_state(atoi(myargv[i] + 9));
        myargv[i] = NULL;
      }
  }

  return NULL;
}

INIT_MODULE(soft_reboot, "$Revision$")
{
  h_shutdown = install_hook(ircd_shutdown, do_shutdown);
  h_verify = install_hook(verify_conf, do_verify_conf);
}

CLEANUP_MODULE
{
  uninstall_hook(verify_conf, do_verify_conf);
  uninstall_hook(ircd_shutdown, do_shutdown);
}
