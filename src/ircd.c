/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd.c: Starts up and runs the ircd.
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
#include "s_user.h"
#include "list.h"
#include "ircd.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "event.h"
#include "fdlist.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd_signal.h"
#include "motd.h"
#include "hostmask.h"
#include "numeric.h"
#include "packet.h"
#include "parse.h"
#include "irc_res.h"
#include "restart.h"
#include "s_auth.h"
#include "s_bsd.h"
#include "conf.h"
#include "log.h"
#include "s_misc.h"
#include "s_serv.h"      /* try_connections */
#include "send.h"
#include "whowas.h"
#include "modules.h"
#include "memory.h"
#include "hook.h"
#include "ircd_getopt.h"
#include "balloc.h"
#include "motd.h"
#include "supported.h"
#include "watch.h"

/* /quote set variables */
struct SetOptions GlobalSetOptions;

/* configuration set from ircd.conf */
struct config_file_entry ConfigFileEntry;
/* server info set from ircd.conf */
struct server_info ServerInfo;
/* admin info set from ircd.conf */
struct admin_info AdminInfo = { NULL, NULL, NULL };
struct Counter Count = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
struct ServerState_t server_state = { 0 };
struct logging_entry ConfigLoggingEntry = { 1 };
struct ServerStatistics ServerStats;
struct timeval SystemTime;
struct Client me;             /* That's me */
struct LocalUser meLocalUser; /* That's also part of me */

const char *logFileName = LPATH;
const char *pidFileName = PPATH;

char **myargv;

int dorehash = 0;
int doremotd = 0;

/* Set to zero because it should be initialized later using
 * initialize_server_capabs
 */
int default_server_capabs = 0;
unsigned int splitmode;
unsigned int splitchecking;
unsigned int split_users;
unsigned int split_servers;

/* Do klines the same way hybrid-6 did them, i.e. at the
 * top of the next io_loop instead of in the same loop as
 * the klines are being applied.
 *
 * This should fix strange CPU starvation as very indirectly reported.
 * (Why do you people not email bug reports? WHY? WHY?)
 *
 * - Dianora
 */

int rehashed_klines = 0;

/*
 * print_startup - print startup information
 */
static void
print_startup(int pid)
{
  printf("ircd: version %s\n", ircd_version);
  printf("ircd: pid %d\n", pid);
  printf("ircd: running in %s mode from %s\n",
         !server_state.foreground ? "background"
         : "foreground", ConfigFileEntry.dpath);
}

static void
make_daemon()
{
#ifndef _WIN32
  int pid;

  if ((pid = fork()) < 0)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0)
  {
    print_startup(pid);
    exit(EXIT_SUCCESS);
  }

  setsid();
#endif
}

static int printVersion = 0;

static struct lgetopt myopts[] =
{
  {
    "dlinefile",  &ConfigFileEntry.dlinefile,
    STRING, "File to use for dline.conf"
  },
  {
    "configfile", &ConfigFileEntry.configfile,
    STRING, "File to use for ircd.conf"
  },
  {
    "klinefile",  &ConfigFileEntry.klinefile,
    STRING, "File to use for kline.conf"
  },
  {
    "xlinefile",  &ConfigFileEntry.xlinefile,
    STRING, "File to use for xline.conf"
  },
  {
    "logfile",    &logFileName,
    STRING, "File to use for ircd.log"
  },
  {
    "pidfile",    &pidFileName,
    STRING, "File to use for process ID"
  },
  {
    "foreground", &server_state.foreground,
    YESNO, "Run in foreground (don't detach)"
  },
  {
    "version",    &printVersion,
    YESNO, "Print version and exit"
  },
  {"help", NULL, USAGE, "Print this text"},
  {NULL, NULL, STRING, NULL},
};

void
set_time()
{
  static char to_send[200];
  struct timeval newtime;
  newtime.tv_sec  = 0;
  newtime.tv_usec = 0;

  if (gettimeofday(&newtime, NULL) == -1)
  {
    ilog(LOG_TYPE_IRCD, "Clock Failure (%s), TS can be corrupted",
         strerror(errno));
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Clock Failure (%s), TS can be corrupted",
                         strerror(errno));
    restart("Clock Failure");
  }

  if (newtime.tv_sec < CurrentTime)
  {
    snprintf(to_send, sizeof(to_send),
             "System clock is running backwards - (%lu < %lu)",
             (unsigned long)newtime.tv_sec, (unsigned long)CurrentTime);

    sendto_realops_flags(UMODE_ALL, L_ALL, to_send);
  }

  SystemTime.tv_sec  = newtime.tv_sec;
  SystemTime.tv_usec = newtime.tv_usec;
}

static void
io_loop()
{
  while (1 == 1)
  {
    /*
     * Maybe we want a flags word?
     * ie. if (REHASHED_KLINES(global_flags))
     * SET_REHASHED_KLINES(global_flags)
     * CLEAR_REHASHED_KLINES(global_flags)
     *
     * - Dianora
     */
    if (rehashed_klines)
    {
      check_conf_klines();
      rehashed_klines = 0;
    }

    if (listing_client_list.head)
    {
      dlink_node *ptr = NULL, *ptr_next = NULL;
      DLINK_FOREACH_SAFE(ptr, ptr_next, listing_client_list.head)
      {
        struct Client *client_p = ptr->data;
        assert(client_p->localClient->list_task);
        safe_list_channels(client_p, client_p->localClient->list_task, 0);
      }
    }

    uv_run(server_state.event_loop, UV_RUN_ONCE);
    set_time();
    exit_aborted_clients();
    free_exited_clients();
    send_queued_all();

    /* Check to see whether we have to rehash the configuration .. */
    if (dorehash)
    {
      rehash(1);
      dorehash = 0;
    }

    if (doremotd)
    {
      read_message_file(&ConfigFileEntry.motd);
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "Got signal SIGUSR1, reloading ircd motd file");
      doremotd = 0;
    }
  }
}

/* initalialize_global_set_options()
 *
 * inputs       - none
 * output       - none
 * side effects - This sets all global set options needed
 */
static void
initialize_global_set_options()
{
  memset(&GlobalSetOptions, 0, sizeof(GlobalSetOptions));

  GlobalSetOptions.autoconn  = 1;
  GlobalSetOptions.spam_time = MIN_JOIN_LEAVE_TIME;
  GlobalSetOptions.spam_num  = MAX_JOIN_LEAVE_COUNT;

  if (ConfigFileEntry.default_floodcount)
    GlobalSetOptions.floodcount = ConfigFileEntry.default_floodcount;
  else
    GlobalSetOptions.floodcount = 10;

  /* XXX I have no idea what to try here - Dianora */
  GlobalSetOptions.joinfloodcount = 16;
  GlobalSetOptions.joinfloodtime = 8;

  split_servers = ConfigChannel.default_split_server_count;
  split_users   = ConfigChannel.default_split_user_count;

  if (split_users && split_servers && (ConfigChannel.no_create_on_split ||
                                       ConfigChannel.no_join_on_split))
  {
    splitmode     = 1;
    splitchecking = 1;
  }

  GlobalSetOptions.ident_timeout = IDENT_TIMEOUT;
  /* End of global set options */
}

/* initialize_message_files()
 *
 * inputs       - none
 * output       - none
 * side effects - Set up all message files needed, motd etc.
 */
static void
initialize_message_files()
{
  init_message_file(USER_MOTD, MPATH, &ConfigFileEntry.motd);
  init_message_file(USER_LINKS, LIPATH, &ConfigFileEntry.linksfile);

  read_message_file(&ConfigFileEntry.motd);
  read_message_file(&ConfigFileEntry.linksfile);

  init_isupport();
}

/* initialize_server_capabs()
 *
 * inputs       - none
 * output       - none
 */
static void
initialize_server_capabs()
{
  add_capability("QS", CAP_QS, 1);
  add_capability("EOB", CAP_EOB, 1);
  add_capability("TS6", CAP_TS6, 0);
  add_capability("CLUSTER", CAP_CLUSTER, 1);
  add_capability("SVS", CAP_SVS, 1);
#ifdef HALFOPS
  add_capability("HOPS", CAP_HOPS, 1);
#endif
}

/* write_pidfile()
 *
 * inputs       - filename+path of pid file
 * output       - NONE
 * side effects - write the pid of the ircd to filename
 */
static void
write_pidfile(const char *filename)
{
  FILE *fb;

  if ((fb = fopen(filename, "w")))
  {
    char buff[32];
    unsigned int pid = (unsigned int)getpid();

    snprintf(buff, sizeof(buff), "%u\n", pid);

    if ((fputs(buff, fb) == -1))
      ilog(LOG_TYPE_IRCD, "Error writing %u to pid file %s (%s)",
           pid, filename, strerror(errno));

    fclose(fb);
  }
  else
  {
    ilog(LOG_TYPE_IRCD, "Error opening pid file %s", filename);
  }
}

/* check_pidfile()
 *
 * inputs       - filename+path of pid file
 * output       - none
 * side effects - reads pid from pidfile and checks if ircd is in process
 *                list. if it is, gracefully exits
 * -kre
 */
static void
check_pidfile(const char *filename)
{
  FILE *fb;
  char buff[32];
  int pidfromfile;

  /* Don't do logging here, since we don't have log() initialised */
  if ((fb = fopen(filename, "r")))
  {
    if (fgets(buff, 20, fb) == NULL)
    {
      /* log(L_ERROR, "Error reading from pid file %s (%s)", filename,
       * strerror(errno));
       */
    }
    else
    {
      uv_err_t err;

      pidfromfile = atoi(buff);

      err = uv_kill(pidfromfile, 0);
      if (err.code == 0)
      {
        /* log(L_ERROR, "Server is already running"); */
        printf("ircd: daemon is already running\n");
        exit(-1);
      }
    }

    fclose(fb);
  }
  else if (errno != ENOENT)
  {
    /* log(L_ERROR, "Error opening pid file %s", filename); */
  }
}

/* setup_corefile()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups corefile to system limits.
 * -kre
 */
static void
setup_corefile()
{
#ifdef HAVE_SYS_RESOURCE_H
  struct rlimit rlim; /* resource limits */

  /* Set corefilesize to maximum */
  if (!getrlimit(RLIMIT_CORE, &rlim))
  {
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_CORE, &rlim);
  }

#endif
}

#ifdef HAVE_LIBCRYPTO
static int
always_accept_verify_cb(int preverify_ok, X509_STORE_CTX *x509_ctx)
{
  return 1;
}
#endif

/* init_ssl()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups SSL context.
 */
static void
init_ssl()
{
#ifdef HAVE_LIBCRYPTO
  const unsigned char session_id[] = "ircd-hybrid";

  SSL_load_error_strings();
  SSLeay_add_ssl_algorithms();

  if ((ServerInfo.server_ctx = SSL_CTX_new(SSLv23_server_method())) == NULL)
  {
    const char *s;

    fprintf(stderr, "ERROR: Could not initialize the SSL Server context -- %s\n",
            s = ERR_lib_error_string(ERR_get_error()));
    ilog(LOG_TYPE_IRCD,
         "ERROR: Could not initialize the SSL Server context -- %s\n", s);
  }

  SSL_CTX_set_options(ServerInfo.server_ctx,
                      SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1);
  SSL_CTX_set_options(ServerInfo.server_ctx,
                      SSL_OP_TLS_ROLLBACK_BUG | SSL_OP_ALL);
  SSL_CTX_set_verify(ServerInfo.server_ctx, SSL_VERIFY_PEER,
                     always_accept_verify_cb);
  SSL_CTX_set_session_id_context(ServerInfo.server_ctx, session_id, sizeof(session_id) - 1);

  if ((ServerInfo.client_ctx = SSL_CTX_new(SSLv23_client_method())) == NULL)
  {
    const char *s;

    fprintf(stderr, "ERROR: Could not initialize the SSL Client context -- %s\n",
            s = ERR_lib_error_string(ERR_get_error()));
    ilog(LOG_TYPE_IRCD,
         "ERROR: Could not initialize the SSL Client context -- %s\n", s);
  }

  SSL_CTX_set_options(ServerInfo.client_ctx,
                      SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1);
  SSL_CTX_set_options(ServerInfo.client_ctx,
                      SSL_OP_TLS_ROLLBACK_BUG | SSL_OP_ALL);
  SSL_CTX_set_verify(ServerInfo.client_ctx, SSL_VERIFY_NONE, NULL);
#endif /* HAVE_LIBCRYPTO */
}

/* init_callbacks()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups standard hook points
 */
static void
init_callbacks()
{
  iorecv_cb = register_callback("iorecv", iorecv_default);
  iosend_cb = register_callback("iosend", iosend_default);
}

int
main(int argc, char *argv[])
{
#ifndef _WIN32
  /* Check to see if the user is running
   * us as root, which is a nono
   */
  if (geteuid() == 0)
  {
    fprintf(stderr, "Don't run ircd as root!!!\n");
    return (-1);
  }
#endif

  /* Setup corefile size immediately after boot -kre */
  setup_corefile();

  /* It ain't random, but it ought to be a little harder to guess */
  srand(SystemTime.tv_sec ^ (SystemTime.tv_usec | (getpid() << 20)));

  me.localClient = &meLocalUser;
  dlinkAdd(&me, &me.node, &global_client_list);  /* Pointer to beginning
               of Client list */
  /* Initialise the channel capability usage counts... */
  init_chcap_usage_counts();

  ConfigFileEntry.dpath      = DPATH;
  ConfigFileEntry.configfile = CPATH;  /* Server configuration file */
  ConfigFileEntry.klinefile  = KPATH;  /* Server kline file         */
  ConfigFileEntry.xlinefile  = XPATH;  /* Server xline file         */
  ConfigFileEntry.dlinefile  = DLPATH; /* dline file                */
  ConfigFileEntry.cresvfile  = CRESVPATH; /* channel resv file      */
  ConfigFileEntry.nresvfile  = NRESVPATH; /* nick resv file         */
  myargv = argv;
  umask(077);                /* better safe than sorry --SRB */

  parseargs(&argc, &argv, myopts);

  if (printVersion)
  {
    printf("ircd: version %s\n", ircd_version);
    exit(EXIT_SUCCESS);
  }

  if (chdir(ConfigFileEntry.dpath))
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }

  init_ssl();

#ifndef _WIN32
  if (!server_state.foreground)
  {
    make_daemon();
    close_standard_fds(); /* this needs to be before init_netio()! */
  }
  else
#endif
    print_startup(getpid());

  setup_signals();
  server_state.event_loop = uv_default_loop();

  /* Init the event subsystem */
  eventInit();
  /* We need this to initialise the fd array before anything else */
  fdlist_init();
  log_set_file(LOG_TYPE_IRCD, 0, logFileName);
  check_can_use_v6();
  init_comm();         /* This needs to be setup early ! -- adrian */
  /* Check if there is pidfile and daemon already running */
  check_pidfile(pidFileName);

  initBlockHeap();
  init_dlink_nodes();
  init_callbacks();
  initialize_message_files();
  dbuf_init();
  init_hash();
  init_ip_hash_table();      /* client host ip hash table */
  init_host_hash();          /* Host-hashtable. */
  init_client();
  init_class();
  whowas_init();
  watch_init();
  init_auth();          /* Initialise the auth code */
  init_resolver();      /* Needs to be setup before the io loop */
  modules_init();
  read_conf_files(1);   /* cold start init conf files */
  init_uid();
  initialize_server_capabs();   /* Set up default_server_capabs */
  initialize_global_set_options();
  init_channels();

  if (EmptyString(ServerInfo.sid))
  {
    ilog(LOG_TYPE_IRCD, "ERROR: No server id specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.id, ServerInfo.sid, sizeof(me.id));

  if (EmptyString(ServerInfo.name))
  {
    ilog(LOG_TYPE_IRCD, "ERROR: No server name specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.name, ServerInfo.name, sizeof(me.name));

  /* serverinfo{} description must exist.  If not, error out.*/
  if (EmptyString(ServerInfo.description))
  {
    ilog(LOG_TYPE_IRCD,
         "ERROR: No server description specified in serverinfo block.");
    exit(EXIT_FAILURE);
  }

  strlcpy(me.info, ServerInfo.description, sizeof(me.info));

  me.from                   = &me;
  me.servptr                = &me;
  me.localClient->lasttime  = CurrentTime;
  me.localClient->since     = CurrentTime;
  me.localClient->firsttime = CurrentTime;

  SetMe(&me);
  make_server(&me);

  hash_add_id(&me);
  hash_add_client(&me);

  /* add ourselves to global_serv_list */
  dlinkAdd(&me, make_dlink_node(), &global_serv_list);

  if (chdir(MODPATH))
  {
    ilog(LOG_TYPE_IRCD, "Could not load core modules. Terminating!");
    exit(EXIT_FAILURE);
  }

  load_all_modules(1);
  load_conf_modules();
  load_core_modules(1);

  /* Go back to DPATH after checking to see if we can chdir to MODPATH */
  if (chdir(ConfigFileEntry.dpath))
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }

  /*
   * assemble_umode_buffer() has to be called after
   * reading conf/loading modules.
   */
  assemble_umode_buffer();

  write_pidfile(pidFileName);

  ilog(LOG_TYPE_IRCD, "Server Ready");

  eventAddIsh("cleanup_tklines", cleanup_tklines, NULL, CLEANUP_TKLINES_TIME);

  /* We want try_connections to be called as soon as possible now! -- adrian */
  /* No, 'cause after a restart it would cause all sorts of nick collides */
  eventAddIsh("try_connections", try_connections, NULL, STARTUP_CONNECTIONS_TIME);

  /* Setup the timeout check. I'll shift it later :)  -- adrian */
  eventAddIsh("comm_checktimeouts", comm_checktimeouts, NULL, 1);

  if (ConfigServerHide.links_delay > 0)
    eventAddIsh("write_links_file", write_links_file, NULL,
                ConfigServerHide.links_delay);
  else
    ConfigServerHide.links_disabled = 1;

  if (splitmode)
    eventAddIsh("check_splitmode", check_splitmode, NULL, 60);

  eventAddIsh("check_godmode", check_godmode, NULL, 60);

  io_loop();
  return 0;
}
