/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_restart.c: Exits and re-runs ircd.
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
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "parse.h"
#include "restart.h"
#include "s_serv.h"
#include "s_user.h"
#include "conf.h"
#include "send.h"
#include "userhost.h"
#include "irc_string.h"
#include "log.h"
#include "sprintf_irc.h"
#include "modules.h"

#ifdef HAVE_LIBCRYPTO
#define CanForward(x)   (!IsDefunct(x) && !(x)->localClient->fd.ssl)
#else
#define CanForward(x)   (!IsDefunct(x))
#endif

struct SocketInfo
{
  int fd;
  int namelen;
  int pwdlen;
  int caplen;
  int recvqlen;
  int sendqlen;
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

  DupString(sconf->name, client_p->name);

  /*  DupString(hub_mask, "*");
    dlinkAdd(hub_mask, make_dlink_node(), &sconf->hub_list);*/

  conf_add_class_to_conf(sconf, NULL);
  attach_conf(client_p, sconf);

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
  while (dbuf_length(dbuf) > 0)
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

  if (!CanForward(client_p) || client_p->localClient->fd.fd == transfd)
    return;

  if (IsServer(client_p))
    capabs = show_capabilities(client_p);

  si.fd = client_p->localClient->fd.fd;
  si.namelen = strlen(client_p->name);
  si.pwdlen = EmptyString(client_p->localClient->passwd) ? 0 :
              strlen(client_p->localClient->passwd);
  si.caplen = strlen(capabs);
  si.recvqlen = dbuf_length(&client_p->localClient->buf_recvq);
  si.sendqlen = dbuf_length(&client_p->localClient->buf_sendq);
  si.first = client_p->localClient->firsttime;
  si.last = client_p->localClient->lasttime;

  write(transfd, &si, sizeof(si));
  write(transfd, client_p->name, si.namelen);

  if (si.pwdlen > 0)
    write(transfd, client_p->localClient->passwd, si.pwdlen);

  if (si.caplen > 0)
    write(transfd, capabs, si.caplen);

  write_dbuf(transfd, &client_p->localClient->buf_recvq);
  write_dbuf(transfd, &client_p->localClient->buf_sendq);
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
static void
do_shutdown(const char *msg, int rboot)
{
  struct Client *client_p;
  dlink_node *ptr;
  int transfd[2];
  char buf[24];

  if (!rboot || socketpair(AF_UNIX, SOCK_STREAM, 0, transfd) < 0)
  {
    server_die(buf, true);
    return;
  }

  if (EmptyString(msg))
  {
    ilog(LOG_TYPE_IRCD, "Server Soft-Rebooting");
    sendto_realops_flags(UMODE_ALL, L_ALL, "Server Soft-Rebooting");
  }
  else
  {
    ilog(LOG_TYPE_IRCD, "Server Soft-Rebooting: %s", msg);
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

    if (CanForward(client_p))
    {
      fcntl(client_p->localClient->fd.fd, F_SETFD, 0);

      if (client_p->localClient->list_task != NULL)
        sendto_one(client_p, form_str(RPL_LISTEND), me.name, client_p->name);
    }
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    client_p = ptr->data;

    if (CanForward(client_p))
      fcntl(client_p->localClient->fd.fd, F_SETFD, 0);
  }

  close_listeners();
  unlink(pidFileName);

  //
  // Start the new ircd.
  //
  switch (fork())
  {
    case -1:
      ilog(LOG_TYPE_IRCD, "Unable to fork(): %s", strerror(errno));
      exit(1);

    case 0:
    {
      int i;
      char **argv;

      close(transfd[1]);
      snprintf(buf, sizeof(buf), "softboot_%d", transfd[0]);

      for (i = 0; myargv[i] != NULL; i++);

      argv = MyMalloc((i + 2) * sizeof(char *));

      for (i = 0; myargv[i] != NULL; i++)
        argv[i] = myargv[i];

      argv[i++] = buf;
      argv[i] = NULL;

      printf("execing: %s %s %s\n", SPATH, argv[0], argv[1]);
      execv(SPATH, argv);
      ilog(LOG_TYPE_IRCD, "Unable to exec(): %s", strerror(errno));
      printf("hi\n");
      exit(1);
    }
  }

  //
  // Pass our data.
  //
  burst_all(make_dummy(transfd[1]));
  send_queued_all();

  snprintf(buf, sizeof(buf), "\001%jd\r\n", (intmax_t)me.localClient->since);
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
 * mo_restart
 *
 */
static void
mo_restart(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];

  if (!HasOFlag(source_p, OPER_FLAG_RESTART))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "restart");
    return;
  }

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, ":%s NOTICE %s :Need server name /restart %s",
               me.name, source_p->name, me.name);
    return;
  }

  if (irccmp(parv[1], me.name))
  {
    sendto_one(source_p, ":%s NOTICE %s :Mismatch on /restart %s",
               me.name, source_p->name, me.name);
    return;
  }

  snprintf(buf, sizeof(buf), "received RESTART command from %s",
           get_oper_name(source_p));
  do_shutdown(buf, true);
}

static struct Message restart_msgtab =
{
  "RESTART", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_restart, m_ignore }
};

static void
module_init()
{
  mod_add_cmd(&restart_msgtab);
}

static void
module_exit()
{
  mod_del_cmd(&restart_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
