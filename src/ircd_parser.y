/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_parser.y: Parses the ircd configuration file.
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

%{


/* XXX */
#define  WE_ARE_MEMORY_C

#define YY_NO_UNPUT
#include "stdinc.h"
#include "config.h"
#include "ircd.h"
#include "tools.h"
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
#include "client.h"	/* for FLAGS_ALL only */
#include "irc_string.h"
#include "ircdauth.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h" /* for CAP_LL / IsCapable */
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#endif

extern char *ip_string;

int yyparse();

static struct ConfItem *yy_achead = NULL;
static struct ConfItem *yy_aconf = NULL;
static struct ConfItem *yy_aprev = NULL;
static int              yy_acount = 0;
static struct ConfItem *yy_hconf;
static struct ConfItem *yy_lconf;

static struct ConfItem *hub_confs;
static struct ConfItem *leaf_confs;
static struct ConfItem *yy_aconf_next;

static dlink_node *node;

char  *class_name_var;
int   class_ping_time_var;
int   class_number_per_ip_var;
int   class_max_number_var;
int   class_sendq_var;

static char  *listener_address;

char *resv_reason;

char  *class_redirserv_var;
int   class_redirport_var;

%}

%union {
        int  number;
        char *string;
        struct ip_value ip_entry;
}

%token  ACCEPT_PASSWORD
%token  ACTION
%token  ADMIN
%token  AFTYPE
%token  ANTI_NICK_FLOOD
%token  ANTI_SPAM_EXIT_MESSAGE_TIME
%token  AUTH
%token  AUTOCONN
%token  BYTES KBYTES MBYTES GBYTES TBYTES
%token  CALLER_ID_WAIT
%token  CAN_FLOOD
%token  CHANNEL
%token  CIPHER_PREFERENCE
%token  CLASS
%token  CLIENT_EXIT
%token  COMPRESSED
%token  COMPRESSION_LEVEL
%token  CONNECT
%token  CONNECTFREQ
%token  CRYPTLINK
%token  DEFAULT_CIPHER_PREFERENCE
%token  DEFAULT_FLOODCOUNT
%token  DEFAULT_SPLIT_SERVER_COUNT
%token  DEFAULT_SPLIT_USER_COUNT
%token  DENY
%token  DESCRIPTION
%token  DIE
%token  DISABLE_HIDDEN
%token  DISABLE_LOCAL_CHANNELS
%token  DISABLE_REMOTE_COMMANDS
%token  DOT_IN_IP6_ADDR
%token  DOTS_IN_IDENT
%token  EGDPOOL_PATH
%token  EMAIL
%token  ENCRYPTED
%token  EXCEED_LIMIT
%token  EXEMPT
%token  FAILED_OPER_NOTICE
%token  FAKENAME
%token  FALLBACK_IP6_INT
%token  FLATTEN_LINKS
%token  FNAME_FOPERLOG
%token  FNAME_OPERLOG
%token  FNAME_USERLOG
%token  GECOS
%token  GENERAL
%token  GLINE
%token  GLINES
%token  GLINE_EXEMPT
%token  GLINE_LOG
%token  GLINE_TIME
%token  GLOBAL_KILL
%token  HAVE_IDENT
%token	HAVENT_READ_CONF
%token  HIDDEN
%token  HIDE_SERVERS
%token  HOST
%token  HUB
%token  HUB_MASK
%token  IAUTH_PORT
%token  IAUTH_SERVER
%token  IDLETIME
%token  IP
%token  KILL
%token  KLINE
%token  KLINE_EXEMPT
%token  KLINE_WITH_CONNECTION_CLOSED
%token  KLINE_WITH_REASON
%token  KNOCK_DELAY
%token  KNOCK_DELAY_CHANNEL
%token  LAZYLINK
%token  LEAF_MASK
%token  LINKS_DELAY
%token  LISTEN
%token  LOGGING
%token  LOG_LEVEL
%token  MAXIMUM_LINKS
%token  MAX_ACCEPT
%token  MAX_BANS
%token  MAX_CHANS_PER_USER
%token  MAX_NICK_CHANGES
%token  MAX_NICK_TIME
%token  MAX_NUMBER
%token  MAX_TARGETS
%token  MESSAGE_LOCALE
%token  MIN_NONWILDCARD
%token  MODULE
%token  MODULES
%token  NAME
%token  NETWORK_DESC
%token  NETWORK_NAME
%token	NICK
%token  NICK_CHANGES
%token  NON_REDUNDANT_KLINES
%token  NO_CREATE_ON_SPLIT
%token  NO_JOIN_ON_SPLIT
%token  NO_OPER_FLOOD
%token  NO_TILDE
%token  NUMBER
%token  NUMBER_PER_IP
%token  OPERATOR
%token  OPER_LOG
%token  OPER_ONLY_UMODES
%token	OPER_PASS_RESV
%token  OPER_UMODES
%token  PACE_WAIT
%token	PACE_WAIT_SIMPLE
%token  PASSWORD
%token  PATH
%token  PING_COOKIE
%token  PING_TIME
%token  PORT
%token  QSTRING
%token  QUIET_ON_BAN
%token  REASON
%token  REDIRPORT
%token  REDIRSERV
%token  REHASH
%token  REMOTE
%token  RESTRICTED
%token  RSA_PRIVATE_KEY_FILE
%token  RSA_PUBLIC_KEY_FILE
%token	RESV
%token  SECONDS MINUTES HOURS DAYS WEEKS MONTHS YEARS DECADES CENTURIES MILLENNIA
%token  SENDQ
%token  SEND_PASSWORD
%token  SERVERHIDE
%token  SERVERINFO
%token  SERVICE
%token  SERVICES
%token  SERVLINK_PATH
%token  T_SHARED
%token  SHORT_MOTD
%token  SILENT
%token  SPOOF
%token  SPOOF_NOTICE
%token  STATS_I_OPER_ONLY
%token  STATS_K_OPER_ONLY
%token  STATS_O_OPER_ONLY
%token  STATS_P_OPER_ONLY
%token  TMASKED
%token  TNO
%token  TREJECT
%token  TS_MAX_DELTA
%token  TS_WARN_DELTA
%token  TWODOTS
%token  TYES
%token  T_BOTS
%token  T_CALLERID
%token  T_CCONN
%token  T_CLIENT_FLOOD
%token  T_DEBUG
%token  T_DRONE
%token  T_EXTERNAL
%token  T_FULL
%token  T_INVISIBLE
%token  T_IPV4
%token  T_IPV6
%token  T_LOCOPS
%token  T_LOGPATH
%token  T_L_CRIT
%token  T_L_DEBUG
%token  T_L_ERROR
%token  T_L_INFO
%token  T_L_NOTICE
%token  T_L_TRACE
%token  T_L_WARN
%token  T_MAX_BUFFER
%token  T_MAX_CLIENTS
%token  T_NCHANGE
%token  T_OPERWALL
%token  T_REJ
%token  T_SERVNOTICE
%token  T_SKILL
%token  T_SPY
%token  T_UNAUTH
%token  T_WALLOP
%token  T_GOD
%token  T_NICKSERVREG
%token  THROTTLE_TIME
%token  TRUE_NO_OPER_FLOOD
%token  UNKLINE
%token  USER
%token	USE_ANONOPS
%token  USE_EGD
%token  USE_EXCEPT
%token  USE_HALFOPS
%token  USE_HELP
%token  USE_INVEX
%token  USE_KNOCK
%token  USE_VCHANS
%token  VCHANS_OPER_ONLY
%token  VHOST
%token  VHOST6
%token  WARN
%token  WARN_NO_NLINE

%type   <string>   QSTRING
%type   <number>   NUMBER
%type   <number>   timespec
%type	<number>   timespec_
%type   <number>   sizespec
%type   <number>   sizespec_

%%
conf:   
        | conf conf_item
        ;

conf_item:        admin_entry
                | logging_entry
                | oper_entry
		| channel_entry
                | class_entry 
                | listen_entry
                | auth_entry
                | serverinfo_entry
		| serverhide_entry
                | resv_entry
                | shared_entry
                | connect_entry
                | kill_entry
                | deny_entry
		| exempt_entry
		| general_entry
                | gecos_entry
                | modules_entry
                | services_entry
                | error ';'
                | error '}'
        ;


timespec_: { $$ = 0; } | timespec;
timespec:	NUMBER timespec_
		{
			$$ = $1 + $2;
		}
		| NUMBER SECONDS timespec_
		{
			$$ = $1 + $3;
		}
		| NUMBER MINUTES timespec_
		{
			$$ = $1 * 60 + $3;
		}
		| NUMBER HOURS timespec_
		{
			$$ = $1 * 60 * 60 + $3;
		}
		| NUMBER DAYS timespec_
		{
			$$ = $1 * 60 * 60 * 24 + $3;
		}
		| NUMBER WEEKS timespec_
		{
			$$ = $1 * 60 * 60 * 24 * 7 + $3;
		}
		;

sizespec_:	{ $$ = 0; } | sizespec;
sizespec:	NUMBER sizespec_ { $$ = $1 + $2; }
		| NUMBER BYTES sizespec_ { $$ = $1 + $3; }
		| NUMBER KBYTES sizespec_ { $$ = $1 * 1024 + $3; }
		| NUMBER MBYTES sizespec_ { $$ = $1 * 1024 * 1024 + $3; }
		;


/***************************************************************************
 *  section modules
 ***************************************************************************/

modules_entry:          MODULES
  '{' modules_items '}' ';';

modules_items:   modules_items modules_item |
                    modules_item;

modules_item:    modules_module | modules_path |
                 error;

modules_module:  MODULE '=' QSTRING ';'
{
#ifndef STATIC_MODULES /* NOOP in the static case */
  char *m_bn;

  m_bn = irc_basename(yylval.string);

  /* I suppose we should just ignore it if it is already loaded(since
   * otherwise we would flood the opers on rehash) -A1kmm. */
  if (findmodule_byname(m_bn) != -1)
    break;

  /* XXX - should we unload this module on /rehash, if it isn't listed? */
  load_one_module (yylval.string, 0);

  MyFree(m_bn);
#endif
};

modules_path: PATH '=' QSTRING ';'
{
#ifndef STATIC_MODULES
  mod_add_path(yylval.string);
#endif
};


/***************************************************************************
 *  section serverinfo
 ***************************************************************************/

serverinfo_entry:       SERVERINFO
  '{' serverinfo_items '}' ';';

serverinfo_items:       serverinfo_items serverinfo_item |
                        serverinfo_item ;

serverinfo_item:        serverinfo_name | serverinfo_vhost |
                        serverinfo_hub | serverinfo_description |
                        serverinfo_network_name | serverinfo_network_desc |
                        serverinfo_max_clients | 
                        serverinfo_rsa_private_key_file | serverinfo_vhost6 |
                        serverinfo_max_buffer | 
			error;

serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'
  {
#ifdef HAVE_LIBCRYPTO
  BIO *file;

  if (ServerInfo.rsa_private_key)
  {
    RSA_free(ServerInfo.rsa_private_key);
    ServerInfo.rsa_private_key = NULL;
  }

  if (ServerInfo.rsa_private_key_file)
  {
    MyFree(ServerInfo.rsa_private_key_file);
    ServerInfo.rsa_private_key_file = NULL;
  }

  DupString(ServerInfo.rsa_private_key_file, yylval.string);

  file = BIO_new_file( yylval.string, "r" );

  if (file == NULL)
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
      "Ignoring config file entry rsa_private_key -- file open failed"
      " (%s)", yylval.string);
    break;
  }

  ServerInfo.rsa_private_key = (RSA *) PEM_read_bio_RSAPrivateKey(file,
                                                            NULL, 0, NULL);
  if (ServerInfo.rsa_private_key == NULL)
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
      "Ignoring config file entry rsa_private_key -- couldn't extract key");
    break;
  }

  if (!RSA_check_key( ServerInfo.rsa_private_key ))
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
      "Ignoring config file entry rsa_private_key -- invalid key");
    break;
  }

  /* require 2048 bit (256 byte) key */
  if ( RSA_size(ServerInfo.rsa_private_key) != 256 )
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
      "Ignoring config file entry rsa_private_key -- not 2048 bit");
    break;
  }

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);
#endif
  };

serverinfo_name:        NAME '=' QSTRING ';' 
  {
    /* this isn't rehashable */
    if(ServerInfo.name == NULL)
    {
      /* the ircd will exit() in main() if we dont set one */
      if(strlen(yylval.string) <= HOSTLEN)
        DupString(ServerInfo.name,yylval.string);
    }
  };

serverinfo_description: DESCRIPTION '=' QSTRING ';'
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  };

serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'
  {
    char *p;

    if((p = strchr(yylval.string, ' ')))
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name,yylval.string);
  };

serverinfo_network_desc: NETWORK_DESC '=' QSTRING ';'
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc,yylval.string);
  };

serverinfo_vhost:  VHOST '=' QSTRING ';'
  {
    if(inetpton(DEF_FAM, yylval.string, &IN_ADDR(ServerInfo.ip)) <= 0)
    {
     ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    }
    ServerInfo.specific_ipv4_vhost = 1;
  };

serverinfo_vhost6:	VHOST6 '=' QSTRING ';'
  {
#ifdef IPV6
    if(inetpton(DEF_FAM,yylval.string, &IN_ADDR(ServerInfo.ip6)) <= 0)
      {
        ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
      }
    ServerInfo.specific_ipv6_vhost = 1;
#endif
  };
   
serverinfo_max_clients: T_MAX_CLIENTS '=' NUMBER ';'
  {
    if (MAX_CLIENTS >= $3)
    {
      ServerInfo.max_clients = $3;
    }
    else
    {
      ilog(L_ERROR, "Setting serverinfo_max_clients to MAX_CLIENTS");
      ServerInfo.max_clients = MAX_CLIENTS;
    }
  };

serverinfo_max_buffer: T_MAX_BUFFER '=' NUMBER ';'
  {
    ServerInfo.max_buffer = $3;
  };

serverinfo_hub:         HUB '=' TYES ';' 
  {
    /* Don't become a hub if we have a lazylink active. */
    if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "Ignoring config file line hub = yes; due to active LazyLink (%s)",
        uplink->name);
    }
    else
    {
      ServerInfo.hub = 1;
      uplink = NULL;
    }
  }
                        |
                        HUB '=' TNO ';'
  {
    /* Don't become a leaf if we have a lazylink active. */
    if (ServerInfo.hub)
    {
      ServerInfo.hub = 0;
      for(node = serv_list.head; node; node = node->next)
      {
        if(MyConnect((struct Client *)node->data) &&
           IsCapable((struct Client *)node->data,CAP_LL))
        {
          sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
            "Ignoring config file line hub = no; due to active LazyLink (%s)",
            ((struct Client *)node->data)->name);
          ServerInfo.hub = 1;
        }
      }
    }
    else
      ServerInfo.hub = 0;
  } ;


/***************************************************************************
 * admin section
 ***************************************************************************/

admin_entry: ADMIN  '{' admin_items '}' ';' ;

admin_items:    admin_items admin_item |
                admin_item;

admin_item:     admin_name | admin_description |
                admin_email | error;

admin_name:     NAME '=' QSTRING ';' 
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  };

admin_email:    EMAIL '=' QSTRING ';'
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  };

admin_description:      DESCRIPTION '=' QSTRING ';'
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  };

/***************************************************************************
 *  section logging
 ***************************************************************************/

logging_entry:          LOGGING  '{' logging_items '}' ';' ;

logging_items:          logging_items logging_item |
                        logging_item ;

logging_item:           logging_path | logging_oper_log |
                        logging_gline_log | logging_log_level |
			error;

logging_path:           T_LOGPATH '=' QSTRING ';' 
                        {
                        };

logging_oper_log:	OPER_LOG '=' QSTRING ';'
                        {
                        };

logging_gline_log:	GLINE_LOG '=' QSTRING ';'
                        {
                        };

logging_log_level:     LOG_LEVEL '=' T_L_CRIT ';'
  { set_log_level(L_CRIT); }
                       |
                       LOG_LEVEL '=' T_L_ERROR ';'
  { set_log_level(L_ERROR); }
                       |
                       LOG_LEVEL '=' T_L_WARN ';'
  { set_log_level(L_WARN); }
                       |
                       LOG_LEVEL '=' T_L_NOTICE ';'
  { set_log_level(L_NOTICE); }
                       |
                       LOG_LEVEL '=' T_L_TRACE ';'
  { set_log_level(L_TRACE); }
                       |
                       LOG_LEVEL '=' T_L_INFO ';'
  { set_log_level(L_INFO); }
                       |
                       LOG_LEVEL '=' T_L_DEBUG ';'
  { set_log_level(L_DEBUG); };

/***************************************************************************
 * oper section
  ***************************************************************************/

oper_entry:     OPERATOR 
  {
    struct ConfItem *yy_tmp;

    yy_tmp = yy_achead;
    while(yy_tmp)
      {
        yy_aconf = yy_tmp;
        yy_tmp = yy_tmp->next;
        yy_aconf->next = NULL;
        free_conf(yy_aconf);
      }
    yy_acount = 0;

    yy_achead = yy_aconf = make_conf();
    yy_aconf->status = CONF_OPERATOR;
  }
 '{' oper_items '}' ';'
  {
    struct ConfItem *yy_tmp;
    struct ConfItem *yy_next;

    /* copy over settings from first struct */
    for( yy_tmp = yy_achead->next; yy_tmp; yy_tmp = yy_tmp->next )
    {
      if (yy_achead->className)
        DupString(yy_tmp->className, yy_achead->className);
      if (yy_achead->name)
       DupString(yy_tmp->name, yy_achead->name);
      if (yy_achead->passwd)
        DupString(yy_tmp->passwd, yy_achead->passwd);
      yy_tmp->port = yy_achead->port;

#ifdef HAVE_LIBCRYPTO
      if(yy_achead->rsa_public_key_file)
        DupString(yy_tmp->rsa_public_key_file, yy_achead->rsa_public_key_file);

      if(yy_achead->rsa_public_key)
      {
        BIO *file;

	file = BIO_new_file(yy_achead->rsa_public_key_file, "r");
	yy_tmp->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file,
	                                           NULL, 0, NULL);
        BIO_set_close(file, BIO_CLOSE);
	BIO_free(file);
      }
#endif
    }

    for( yy_tmp = yy_achead; yy_tmp; yy_tmp = yy_next )
      {
        yy_next = yy_tmp->next;
        yy_tmp->next = NULL;

#ifdef HAVE_LIBCRYPTO
        if(yy_tmp->name && (yy_tmp->passwd || yy_aconf->rsa_public_key) && yy_tmp->host)
#else
        if(yy_tmp->name && yy_tmp->passwd && yy_tmp->host)
#endif
          {
            conf_add_class_to_conf(yy_tmp);
            conf_add_conf(yy_tmp);
          }
        else
          {
            free_conf(yy_tmp);
          }
      }
    yy_achead = NULL;
    yy_aconf = NULL;
    yy_aprev = NULL;
    yy_acount = 0;
  }; 

oper_items:     oper_items oper_item |
                oper_item;

oper_item:      oper_name  | oper_user | oper_password |
                oper_class | oper_global_kill | oper_remote |
                oper_kline | oper_unkline | oper_gline | oper_nick_changes |
                oper_die | oper_rehash | oper_admin | oper_rsa_public_key_file | error;

oper_name:      NAME '=' QSTRING ';'
  {
   int oname_len;
   MyFree(yy_achead->name);
   if ((oname_len = strlen(yylval.string)) > OPERNICKLEN)
    yylval.string[OPERNICKLEN] = 0;
   DupString(yy_achead->name, yylval.string);
  };

oper_user:      USER '='  QSTRING ';'
  {
    char *p;
    char *new_user;
    char *new_host;

    /* The first user= line doesn't allocate a new conf */
    if ( yy_acount++ )
    {
      yy_aconf = (yy_aconf->next = make_conf());
      yy_aconf->status = CONF_OPERATOR;
    }

    if((p = strchr(yylval.string,'@')))
      {
	*p = '\0';
	DupString(new_user,yylval.string);
	MyFree(yy_aconf->user);
	yy_aconf->user = new_user;
	p++;
	DupString(new_host,p);
	MyFree(yy_aconf->host);
	yy_aconf->host = new_host;
      }
    else
      {
	MyFree(yy_aconf->host);
   	DupString(yy_aconf->host, yylval.string);
   	DupString(yy_aconf->user,"*");
      }
  };

oper_password:  PASSWORD '=' QSTRING ';'
  {
    if (yy_achead->passwd)
      memset(yy_achead->passwd, 0, strlen(yy_achead->passwd));
    MyFree(yy_achead->passwd);
    DupString(yy_achead->passwd, yylval.string);
  };

oper_rsa_public_key_file: RSA_PUBLIC_KEY_FILE '=' QSTRING ';'
  {
#ifdef HAVE_LIBCRYPTO
    BIO *file;

    if (yy_achead->rsa_public_key)
    {
      RSA_free(yy_achead->rsa_public_key);
      yy_achead->rsa_public_key = NULL;
    }

    if (yy_achead->rsa_public_key_file)
    {
      MyFree(yy_achead->rsa_public_key_file);
      yy_achead->rsa_public_key_file = NULL;
    }

    DupString(yy_achead->rsa_public_key_file, yylval.string);

    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "Ignoring rsa_public_key_file -- does %s exist?", yylval.string);
      break;
    }

    yy_achead->rsa_public_key = (RSA *) PEM_read_bio_RSA_PUBKEY(file,
                                                    NULL, 0, NULL );

    if (yy_achead->rsa_public_key == NULL)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

#endif /* HAVE_LIBCRYPTO */
  };

oper_class:     CLASS '=' QSTRING ';'
  {
    MyFree(yy_achead->className);
    DupString(yy_achead->className, yylval.string);
  };

oper_global_kill: GLOBAL_KILL '=' TYES ';'
  {
    yy_achead->port |= CONF_OPER_GLOBAL_KILL;
  }
                  |
                  GLOBAL_KILL '=' TNO ';'
  {
    yy_achead->port &= ~CONF_OPER_GLOBAL_KILL;
  };

oper_remote: REMOTE '=' TYES ';' { yy_achead->port |= CONF_OPER_REMOTE;}
             |
             REMOTE '=' TNO ';' { yy_achead->port &= ~CONF_OPER_REMOTE; } ;

oper_kline: KLINE '=' TYES ';' { yy_achead->port |= CONF_OPER_K;}
            |
            KLINE '=' TNO ';' { yy_achead->port &= ~CONF_OPER_K; } ;

oper_unkline: UNKLINE '=' TYES ';' { yy_achead->port |= CONF_OPER_UNKLINE;}
              |
              UNKLINE '=' TNO ';' { yy_achead->port &= ~CONF_OPER_UNKLINE; } ;

oper_gline: GLINE '=' TYES ';' { yy_achead->port |= CONF_OPER_GLINE;}
            |
            GLINE '=' TNO ';' { yy_achead->port &= ~CONF_OPER_GLINE; };

oper_nick_changes: NICK_CHANGES '=' TYES ';' { yy_achead->port |= CONF_OPER_N;}
                   |
                   NICK_CHANGES '=' TNO ';' { yy_achead->port &= ~CONF_OPER_N;};

oper_die: DIE '=' TYES ';' { yy_achead->port |= CONF_OPER_DIE; }
          |
          DIE '=' TNO ';' { yy_achead->port &= ~CONF_OPER_DIE; } ;

oper_rehash: REHASH '=' TYES ';' { yy_achead->port |= CONF_OPER_REHASH;}
             |
             REHASH '=' TNO ';' { yy_achead->port &= ~CONF_OPER_REHASH; } ;

oper_admin: ADMIN '=' TYES ';' { yy_achead->port |= CONF_OPER_ADMIN;}
            |
            ADMIN '=' TNO ';' { yy_achead->port &= ~CONF_OPER_ADMIN;} ;

/***************************************************************************
 *  section class
 ***************************************************************************/

class_entry:    CLASS 
  {
    MyFree(class_name_var);
    class_name_var = NULL;
    class_ping_time_var = 0;
    class_number_per_ip_var = 0;
    class_max_number_var = 0;
    class_sendq_var = 0;
  }
  '{' class_items '}' ';'
  {

    add_class(class_name_var,class_ping_time_var,
              class_number_per_ip_var, class_max_number_var,
              class_sendq_var );

    MyFree(class_name_var);
    class_name_var = NULL;
  };

class_items:    class_items class_item |
                class_item;

class_item:     class_name |
                class_ping_time |
                class_number_per_ip |
                class_connectfreq |
                class_max_number |
                class_sendq |
		error;

class_name:     NAME '=' QSTRING ';' 
  {
    MyFree(class_name_var);
    DupString(class_name_var, yylval.string);
  };

class_ping_time:        PING_TIME '=' timespec ';'
  {
    class_ping_time_var = $3;
  };

class_number_per_ip:    NUMBER_PER_IP '=' NUMBER ';'
  {
    class_number_per_ip_var = $3;
  };

class_connectfreq:     CONNECTFREQ '=' timespec ';'
  {
    class_number_per_ip_var = $3;
  };

class_max_number:       MAX_NUMBER '=' NUMBER ';'
  {
    class_max_number_var = $3;
  };

class_sendq:    SENDQ '=' sizespec ';'
  {
    class_sendq_var = $3;
  };


/***************************************************************************
 *  section listen
 ***************************************************************************/

listen_entry:   LISTEN
  {
    listener_address = NULL;
  }
  '{' listen_items '}' ';'
  {
    MyFree(listener_address);
    listener_address = NULL;
  };

listen_items:   listen_items listen_item |
                listen_item;

listen_item:    listen_port | listen_address | listen_host | error;

listen_port: PORT '=' port_items ';' ;

port_items: port_items ',' port_item | port_item;

port_item: NUMBER
{
  add_listener($1, listener_address);
} | NUMBER TWODOTS NUMBER
{
  int i;
  for (i = $1; i <= $3; i++)
	{
	  add_listener(i, listener_address);
	}
};

listen_address: IP '=' QSTRING ';'
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  };

listen_host:	HOST '=' QSTRING ';'
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  };

/***************************************************************************
 *  section auth
 ***************************************************************************/

auth_entry:   AUTH
  {
    struct ConfItem *yy_tmp;

    yy_tmp = yy_achead;
    while(yy_tmp)
      {
        yy_aconf = yy_tmp;
        yy_tmp = yy_tmp->next;
        yy_aconf->next = NULL;
        free_conf(yy_aconf);
      }
    yy_achead = NULL;
    yy_aconf = NULL;
    yy_aprev = NULL;

    yy_achead = yy_aprev = yy_aconf = make_conf();
    yy_aconf->status = CONF_CLIENT;
  }
 '{' auth_items '}' ';' 
  {
    struct ConfItem *yy_tmp;
    struct ConfItem *yy_next;

    /* copy over settings from first struct */
    for( yy_tmp = yy_achead->next; yy_tmp; yy_tmp = yy_tmp->next )
    {
      if(yy_achead->passwd)
        DupString(yy_tmp->passwd, yy_achead->passwd);
      if(yy_achead->name)
        DupString(yy_tmp->name, yy_achead->name);
      if(yy_achead->className)
        DupString(yy_tmp->className, yy_achead->className);

      yy_tmp->flags = yy_achead->flags;
      yy_tmp->port  = yy_achead->port;
    }

    for( yy_tmp = yy_achead; yy_tmp; yy_tmp = yy_next )
    {
      yy_next = yy_tmp->next; /* yy_tmp->next is used by conf_add_conf */
      yy_tmp->next = NULL;

      if (yy_tmp->name == NULL)
       DupString(yy_tmp->name,"NOMATCH");

      conf_add_class_to_conf(yy_tmp);

      if (yy_tmp->user == NULL)
       DupString(yy_tmp->user,"*");
      else
       (void)collapse(yy_tmp->user);

      if (yy_tmp->host == NULL)
       continue;
      else
        (void)collapse(yy_tmp->host);

      add_conf_by_address(yy_tmp->host, CONF_CLIENT, yy_tmp->user, yy_tmp);
    }
    yy_achead = NULL;
    yy_aconf = NULL;
    yy_aprev = NULL;
    yy_acount = 0;
  }; 

auth_items:     auth_items auth_item |
                auth_item;

auth_item:      auth_user | auth_passwd | auth_class |
                auth_kline_exempt | auth_have_ident | auth_is_restricted |
                auth_exceed_limit | auth_no_tilde | auth_gline_exempt |
                auth_spoof | auth_spoof_notice |
                auth_redir_serv | auth_redir_port | auth_can_flood |
                error;

auth_user:   USER '=' QSTRING ';'
  {
    char *p;
    char *new_user;
    char *new_host;

    /* The first user= line doesn't allocate a new conf */
    if ( yy_acount++ )
    {
      yy_aprev = yy_aconf;
      yy_aconf = (yy_aconf->next = make_conf());
      yy_aconf->status = CONF_CLIENT;
    }

    if((p = strchr(yylval.string,'@')))
      {
	*p = '\0';
	DupString(new_user, yylval.string);
	MyFree(yy_aconf->user);
	yy_aconf->user = new_user;
	p++;
	MyFree(yy_aconf->host);
	DupString(new_host,p);
	yy_aconf->host = new_host;
      }
    else
      {
	MyFree(yy_aconf->host);
	DupString(yy_aconf->host, yylval.string);
	DupString(yy_aconf->user,"*");
      }
  };
/* XXX - IP/IPV6 tags don't exist anymore - put IP/IPV6 into user. */

auth_passwd:  PASSWORD '=' QSTRING ';' 
  {
    /* be paranoid */
    if (yy_achead->passwd)
      memset(yy_achead->passwd, 0, strlen(yy_achead->passwd));
    MyFree(yy_achead->passwd);
    DupString(yy_achead->passwd,yylval.string);
  };

/* TYES/TNO are flipped to change the default value to YES */
auth_spoof_notice:   SPOOF_NOTICE '=' TNO ';'
  {
    yy_achead->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }
    |
    SPOOF_NOTICE '=' TYES ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
  };

auth_spoof:   SPOOF '=' QSTRING ';' 
  {
    MyFree(yy_achead->name);
    if(strlen(yylval.string) < HOSTLEN)
    {    
	DupString(yy_achead->name, yylval.string);
    	yy_achead->flags |= CONF_FLAGS_SPOOF_IP;
    } else
	ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
  };

auth_exceed_limit:    EXCEED_LIMIT '=' TYES ';'
  {
    yy_achead->flags |= CONF_FLAGS_NOLIMIT;
  }
                      |
                      EXCEED_LIMIT '=' TNO ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_NOLIMIT;
  };

auth_is_restricted:    RESTRICTED '=' TYES ';'
  {
    yy_achead->flags |= CONF_FLAGS_RESTRICTED;
  }
                      |
                      RESTRICTED '=' TNO ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_RESTRICTED;
  };

auth_kline_exempt:    KLINE_EXEMPT '=' TYES ';'
  {
    yy_achead->flags |= CONF_FLAGS_EXEMPTKLINE;
  }
                      |
                      KLINE_EXEMPT '=' TNO ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_EXEMPTKLINE;
  };

auth_have_ident:      HAVE_IDENT '=' TYES ';'
  {
    yy_achead->flags |= CONF_FLAGS_NEED_IDENTD;
  }
                      |
                      HAVE_IDENT '=' TNO ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_NEED_IDENTD;
  };

auth_can_flood:      CAN_FLOOD '=' TYES ';'
  {
    yy_achead->flags |= CONF_FLAGS_CAN_FLOOD;
  }
                      |
                      CAN_FLOOD '=' TNO ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_CAN_FLOOD;
  };

auth_no_tilde:        NO_TILDE '=' TYES ';' 
  {
    yy_achead->flags |= CONF_FLAGS_NO_TILDE;
  }
                      |
                      NO_TILDE '=' TNO ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_NO_TILDE;
  };

auth_gline_exempt:  GLINE_EXEMPT '=' TYES ';' 
  {
    yy_achead->flags |= CONF_FLAGS_EXEMPTGLINE;
  }
                    |
                    GLINE_EXEMPT '=' TNO ';'
  {
    yy_achead->flags &= ~CONF_FLAGS_EXEMPTGLINE;
  };


auth_redir_serv:    REDIRSERV '=' QSTRING ';'
  {
    yy_achead->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_achead->name);
    DupString(yy_achead->name, yylval.string);
  };

auth_redir_port:    REDIRPORT '=' NUMBER ';'
  {
    yy_achead->flags |= CONF_FLAGS_REDIR;
    yy_achead->port = $3;
  };

auth_class:   CLASS '=' QSTRING ';'
  {
    MyFree(yy_achead->className);
    DupString(yy_achead->className, yylval.string);
  };


/***************************************************************************
 *  section resv
 ***************************************************************************/

resv_entry:	RESV
  {
    resv_reason = NULL;
  }
  '{' resv_items '}' ';'
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  };

resv_items:	resv_items resv_item |
                resv_item;

resv_item:	resv_creason | resv_channel | resv_nick | error;

resv_creason:	REASON '=' QSTRING ';'
{
  MyFree(resv_reason);
  DupString(resv_reason, yylval.string);
};

resv_channel:	CHANNEL '=' QSTRING ';'
{
  if(IsChannelName(yylval.string))
  {
    if(resv_reason)
      create_channel_resv(yylval.string, resv_reason, 1);
    else
      create_channel_resv(yylval.string, "No Reason", 1);
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
};

resv_nick:	NICK '=' QSTRING ';'
{
  if(clean_resv_nick(yylval.string))
  {
    if(resv_reason)
      create_nick_resv(yylval.string, resv_reason, 1);
    else
      create_nick_resv(yylval.string, "No Reason", 1);
  }

  /* otherwise its erroneous, but ignore it for now */
};

/***************************************************************************
 *  services, which servers are allowed to perform network services
 ***************************************************************************/
services_entry:           SERVICES
  {
    if(yy_aconf != NULL)
      {
        free_conf(yy_aconf);
        yy_aconf = NULL;
      }
    yy_aconf=make_conf();
    yy_aconf->status = CONF_SERVICES;
    yy_aconf->name = NULL;
    yy_aconf->user = NULL;
    yy_aconf->host = NULL;
  }
  '{' services_items '}' ';'
  {
    conf_add_services_conf(yy_aconf);
    yy_aconf = (struct ConfItem *)NULL;
  };

services_items:         services_items services_item |
                        services_item;

services_item:          services_service | error;

services_service:            SERVICE '=' QSTRING ';'
  {
    MyFree(yy_aconf->name);
    DupString(yy_aconf->name, yylval.string);
  };

/***************************************************************************
 *  section shared, for sharing remote klines etc.
 ***************************************************************************/

shared_entry:		T_SHARED
  {
    if(yy_aconf != NULL)
      {
        free_conf(yy_aconf);
        yy_aconf = NULL;
      }
    yy_aconf=make_conf();
    yy_aconf->status = CONF_ULINE;
    yy_aconf->name = NULL;
    yy_aconf->user = NULL;
    yy_aconf->host = NULL;
  }
  '{' shared_items '}' ';'
  {
    conf_add_u_conf(yy_aconf);
    yy_aconf = (struct ConfItem *)NULL;
  };

shared_items:		shared_items shared_item |
			shared_item;

shared_item:		shared_name | shared_user | error;

shared_name:		NAME '=' QSTRING ';'
  {
    MyFree(yy_aconf->name);
    DupString(yy_aconf->name, yylval.string);
  };

shared_user:		USER '=' QSTRING ';'
  {
    char *p;
    char *new_user;
    char *new_host;

    if((p = strchr(yylval.string,'@')))
    {
      *p = '\0';
      DupString(new_user, yylval.string);
      MyFree(yy_aconf->user);
      yy_aconf->user = new_user;

      p++;
      DupString(new_host, p);
      MyFree(yy_aconf->host);
      yy_aconf->host = new_host;
    }
  };

/***************************************************************************
 *  section connect
 ***************************************************************************/

connect_entry:  CONNECT   
  {
    hub_confs = (struct ConfItem *)NULL;

    if(yy_aconf)
      {
        free_conf(yy_aconf);
        yy_aconf = (struct ConfItem *)NULL;
      }

    if(yy_hconf)
      {
        free_conf(yy_hconf);
        yy_hconf = (struct ConfItem *)NULL;
      }

    if(yy_lconf)
      {
	free_conf(yy_lconf);
	yy_lconf = (struct ConfItem *)NULL;
      }

    yy_aconf=make_conf();
    yy_aconf->passwd = NULL;
    /* Finally we can do this -A1kmm. */
    yy_aconf->status = CONF_SERVER;

    /* defaults */
    yy_aconf->port = PORTNUM;
  }
  '{' connect_items '}' ';'
  {
#ifdef HAVE_LIBCRYPTO
    if(yy_aconf->host &&
       ((yy_aconf->passwd && yy_aconf->spasswd) ||
        (yy_aconf->rsa_public_key && IsConfCryptLink(yy_aconf))))
#else /* !HAVE_LIBCRYPTO */
    if(yy_aconf->host && !IsConfCryptLink(yy_aconf) && 
       yy_aconf->passwd && yy_aconf->spasswd)
#endif /* !HAVE_LIBCRYPTO */
      {
        if( conf_add_server(yy_aconf, scount) >= 0 )
	  {
	    conf_add_conf(yy_aconf);
	    ++scount;
	  }
	else
	  {
	    free_conf(yy_aconf);
	    yy_aconf = NULL;
	  }
      }
    else
      {
        if(yy_aconf->name)
	{
#ifndef HAVE_LIBCRYPTO
          if (IsConfCryptLink(yy_aconf))
            sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                       "Ignoring connect block for %s -- no OpenSSL support",
                       yy_aconf->name);
#else
          if(IsConfCryptLink(yy_aconf) && !yy_aconf->rsa_public_key)
	    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
	                     "Ignoring connect block for %s -- missing key",
			     yy_aconf->name);
#endif
          if(!yy_aconf->host)
	    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
	                     "Ignoring connect block for %s -- missing host",
	                     yy_aconf->name);
          else if(!IsConfCryptLink(yy_aconf) && 
	         (!yy_aconf->passwd || !yy_aconf->spasswd))
            sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
	                   "Ignoring connect block for %s -- missing password",
			   yy_aconf->name);
        }

        free_conf(yy_aconf);
        yy_aconf = NULL;
      }

    /*
     * yy_aconf is still pointing at the server that is having
     * a connect block built for it. This means, y_aconf->name 
     * points to the actual irc name this server will be known as.
     * Now this new server has a set or even just one hub_mask (or leaf_mask)
     * given in the link list at yy_hconf. Fill in the HUB confs
     * from this link list now.
     */        
    for (yy_hconf = hub_confs; yy_hconf; yy_hconf = yy_aconf_next)
      {
	yy_aconf_next = yy_hconf->next;
	MyFree(yy_hconf->name);
	yy_hconf->name = NULL;

	/* yy_aconf == NULL is a fatal error for this connect block! */
	if (yy_aconf != NULL)
	  {
	    DupString(yy_hconf->name, yy_aconf->name);
	    conf_add_conf(yy_hconf);
	  }
	else
	  free_conf(yy_hconf);
      }

    /* Ditto for the LEAF confs */

    for (yy_lconf = leaf_confs; yy_lconf; yy_lconf = yy_aconf_next)
      {
	yy_aconf_next = yy_lconf->next;
	if (yy_aconf != NULL)
	  {
	    DupString(yy_lconf->name, yy_aconf->name);
	    conf_add_conf(yy_lconf);
	  }
	else
	  free_conf(yy_lconf);
      }

    hub_confs = NULL;
    leaf_confs = NULL;

    yy_aconf = NULL;
    yy_hconf = NULL;
    yy_lconf = NULL;
  };

connect_items:  connect_items connect_item |
                connect_item;

connect_item:   connect_name | connect_host | connect_send_password |
                connect_accept_password | connect_port | connect_aftype | 
 		connect_fakename | connect_lazylink | connect_hub_mask | 
		connect_leaf_mask | connect_class | connect_auto | 
		connect_encrypted | connect_compressed | connect_cryptlink |
		connect_rsa_public_key_file | connect_cipher_preference |
                error;

connect_name:   NAME '=' QSTRING ';'
  {
    if(yy_aconf->name != NULL)
      {
	sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,"*** Multiple connect name entry");
	ilog(L_WARN, "Multiple connect name entry %s", yy_aconf->name);
      }

    MyFree(yy_aconf->name);
    DupString(yy_aconf->name, yylval.string);
  };

connect_host:   HOST '=' QSTRING ';' 
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  };
 
connect_send_password:  SEND_PASSWORD '=' QSTRING ';'
  {
    if (yy_aconf->spasswd)
      memset(yy_aconf->spasswd, 0, strlen(yy_aconf->spasswd));
    MyFree(yy_aconf->spasswd);
    DupString(yy_aconf->spasswd, yylval.string);
  };

connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'
  {
    if (yy_aconf->passwd)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));
    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  };

connect_port:   PORT '=' NUMBER ';' { yy_aconf->port = $3; };


connect_aftype: 	AFTYPE '=' T_IPV4 ';'
  {
    yy_aconf->aftype = AF_INET;
  }
			|
			AFTYPE '=' T_IPV6 ';'
  {
#ifdef IPV6
    yy_aconf->aftype = AF_INET6;
#endif
  };

connect_fakename: FAKENAME '=' QSTRING ';'
 {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
 };

connect_lazylink:       LAZYLINK '=' TYES ';'
  {
    yy_aconf->flags |= CONF_FLAGS_LAZY_LINK;
  }
                        |
                        LAZYLINK '=' TNO ';'
  {
    yy_aconf->flags &= ~CONF_FLAGS_LAZY_LINK;
  };

connect_encrypted:       ENCRYPTED '=' TYES ';'
  {
    yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
  }
                        |
                        ENCRYPTED '=' TNO ';'
  {
    yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  };

connect_rsa_public_key_file: RSA_PUBLIC_KEY_FILE '=' QSTRING ';'
  {
#ifdef HAVE_LIBCRYPTO
    BIO *file;

    if (yy_aconf->rsa_public_key)
    {
      RSA_free(yy_aconf->rsa_public_key);
      yy_aconf->rsa_public_key = NULL;
    }

    if (yy_aconf->rsa_public_key_file)
    {
      MyFree(yy_aconf->rsa_public_key_file);
      yy_aconf->rsa_public_key_file = NULL;
    }

    DupString(yy_aconf->rsa_public_key_file, yylval.string);

    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "Ignoring rsa_public_key_file -- does %s exist?", yylval.string);
      break;
    }

    yy_aconf->rsa_public_key = (RSA *) PEM_read_bio_RSA_PUBKEY(file,
                                                    NULL, 0, NULL );

    if (yy_aconf->rsa_public_key == NULL)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
#endif /* HAVE_LIBCRYPTO */
  };

connect_cryptlink:	CRYPTLINK '=' TYES ';'
  {
    yy_aconf->flags |= CONF_FLAGS_CRYPTLINK;
  }
			|
			CRYPTLINK '=' TNO ';'
  {
    yy_aconf->flags &= ~CONF_FLAGS_CRYPTLINK;
  };

connect_compressed:       COMPRESSED '=' TYES ';'
  {
#ifndef HAVE_LIBZ
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL, 
      "Ignoring compressed = yes; -- no zlib support");
#else
    yy_aconf->flags |= CONF_FLAGS_COMPRESSED;
#endif
  }
                        |
                        COMPRESSED '=' TNO ';'
  {
    yy_aconf->flags &= ~CONF_FLAGS_COMPRESSED;
  };

connect_auto:           AUTOCONN '=' TYES ';'
  {
    yy_aconf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
  }
                        |
                        AUTOCONN '=' TNO ';'
  {
    yy_aconf->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN;
  };

connect_hub_mask:       HUB_MASK '=' QSTRING ';' 
  {
    if(hub_confs == NULL)
      {
	hub_confs = make_conf();
	hub_confs->status = CONF_HUB;
	DupString(hub_confs->host, yylval.string);
	DupString(hub_confs->user, "*");
      }
    else
      {
	yy_hconf = make_conf();
	yy_hconf->status = CONF_HUB;
	DupString(yy_hconf->host, yylval.string);
	DupString(yy_hconf->user, "*");
	yy_hconf->next = hub_confs;
	hub_confs = yy_hconf;
      }
  };

connect_leaf_mask:       LEAF_MASK '=' QSTRING ';' 
  {
    if(leaf_confs == NULL)
      {
	leaf_confs = make_conf();
	leaf_confs->status = CONF_LEAF;
	DupString(leaf_confs->host, yylval.string);
	DupString(leaf_confs->user, "*");
      }
    else
      {
	yy_lconf = make_conf();
	yy_lconf->status = CONF_LEAF;
	DupString(yy_lconf->host, yylval.string);
	DupString(yy_lconf->user, "*");
	yy_lconf->next = leaf_confs;
	leaf_confs = yy_lconf;
      }
  };

connect_class:  CLASS '=' QSTRING ';'
  {
    MyFree(yy_aconf->className);
    DupString(yy_aconf->className, yylval.string);
  };

connect_cipher_preference: CIPHER_PREFERENCE '=' QSTRING ';'
  {
#ifdef HAVE_LIBCRYPTO
    struct EncCapability *ecap;
    char *cipher_name;
    int found = 0;

    yy_aconf->cipher_preference = NULL;

    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ( (!irccmp(ecap->name, cipher_name)) &&
           (ecap->cap & CAP_ENC_MASK))
      {
        yy_aconf->cipher_preference = ecap;
        found = 1;
      }
    }

    if (!found)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL, "Invalid cipher '%s' for %s",
                           cipher_name, yy_aconf->name);
      ilog(L_ERROR, "Invalid cipher '%s' for %s",
                    cipher_name, yy_aconf->name);
    }
#else
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "Ignoring 'cipher_preference' line for %s -- no OpenSSL support",
         yy_aconf->name);
      ilog(L_ERROR, "Ignoring 'cipher_preference' line for %s -- "
                    "no OpenSSL support", yy_aconf->name);
#endif
  };

/***************************************************************************
 *  section kill
 ***************************************************************************/

kill_entry:     KILL
  {
    if(yy_aconf)
      {
        free_conf(yy_aconf);
        yy_aconf = NULL;
      }
    yy_aconf=make_conf();
    yy_aconf->status = CONF_KILL;
  }
 '{' kill_items '}' ';'
  {
    if(yy_aconf->user && yy_aconf->passwd && yy_aconf->host)
      {
        if (yy_aconf->host != NULL)
	  add_conf_by_address(yy_aconf->host, CONF_KILL,
			      yy_aconf->user, yy_aconf);
      }
    else
      {
        free_conf(yy_aconf);
      }
    yy_aconf = NULL;
  }; 

kill_items:     kill_items kill_item |
                kill_item;

kill_item:      kill_user | kill_reason | error;


kill_user:      USER '=' QSTRING ';'
  {
    char *p;
    char *new_user;
    char *new_host;

    if((p = strchr(yylval.string,'@')))
      {
	*p = '\0';
	DupString(new_user,yylval.string);
	yy_aconf->user = new_user;
	p++;
	DupString(new_host,p);
	MyFree(yy_aconf->host);
	yy_aconf->host = new_host;
      }
    else
      {
	MyFree(yy_aconf->host);
	DupString(yy_aconf->host, yylval.string);
	MyFree(yy_aconf->user);
	DupString(yy_aconf->user,"*");
      }
  };

kill_reason:    REASON '=' QSTRING ';' 
  {
    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  };

/***************************************************************************
 *  section deny
 ***************************************************************************/

deny_entry:     DENY 
  {
    if(yy_aconf)
      {
        free_conf(yy_aconf);
        yy_aconf = (struct ConfItem *)NULL;
      }
    yy_aconf=make_conf();
    yy_aconf->status = CONF_DLINE;
    /* default reason */
    DupString(yy_aconf->passwd,"NO REASON");
  }
'{' deny_items '}' ';'
  {
    if (yy_aconf->host &&
        parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
    {
      add_conf_by_address(yy_aconf->host, CONF_DLINE, NULL, yy_aconf);
    }
    else
    {
      free_conf(yy_aconf);
    }
    yy_aconf = (struct ConfItem *)NULL;
  }; 

deny_items:     deny_items deny_item |
                deny_item;

deny_item:      deny_ip | deny_reason | error;


deny_ip:        IP '=' QSTRING ';'
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  };

deny_reason:    REASON '=' QSTRING ';' 
  {
    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  };

/***************************************************************************
 *  section exempt
 ***************************************************************************/

exempt_entry:     EXEMPT
  {
    if(yy_aconf)
      {
        free_conf(yy_aconf);
        yy_aconf = (struct ConfItem *)NULL;
      }
    yy_aconf=make_conf();
    DupString(yy_aconf->passwd, "*");
    yy_aconf->status = CONF_EXEMPTDLINE;
  }
'{' exempt_items '}' ';'
  {
   if (yy_aconf->host &&
      parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
   {
    add_conf_by_address(yy_aconf->host, CONF_EXEMPTDLINE, NULL, yy_aconf);
   } else
   {
    free_conf(yy_aconf);
   }
   yy_aconf = (struct ConfItem *)NULL;
  };

exempt_items:     exempt_items exempt_item |
                exempt_item;

exempt_item:      exempt_ip | error;

exempt_ip:        IP '=' QSTRING ';'
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  };


/***************************************************************************
 *  section gecos
 ***************************************************************************/

gecos_entry:     GECOS
  {
    if(yy_aconf != NULL)
      {
        free_conf(yy_aconf);
        yy_aconf = NULL;
      }
    yy_aconf=make_conf();
    yy_aconf->status = CONF_XLINE;
    /* default reason */
    DupString(yy_aconf->passwd,"Something about your name");
  }
 '{' gecos_items '}' ';'
  {
    if(yy_aconf->name != NULL)
      conf_add_x_conf(yy_aconf);
    else
      free_conf(yy_aconf);
    yy_aconf = NULL;
  }; 

gecos_items:     gecos_items gecos_item |
                 gecos_item;

gecos_item:      gecos_name | gecos_reason | gecos_action | error;


gecos_name:    NAME '=' QSTRING ';' 
  {
    DupString(yy_aconf->name, yylval.string);
    collapse(yy_aconf->name);
  };

gecos_reason:    REASON '=' QSTRING ';' 
  {
    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  };

gecos_action:    ACTION '=' WARN ';'
  {
    yy_aconf->port = 0;
  }
                 |
                 ACTION '=' TREJECT ';'
  {
    yy_aconf->port = 1;
  }
                 |
                 ACTION '=' SILENT ';'
  {
    yy_aconf->port = 2;
  };


/***************************************************************************
 *  section general
 ***************************************************************************/

general_entry:      GENERAL
  '{' general_items '}' ';';

general_items:      general_items general_item |
                    general_item;

general_item:       general_failed_oper_notice |
                    general_anti_nick_flood | general_max_nick_time |
                    general_max_nick_changes | general_max_accept |
                    general_anti_spam_exit_message_time |
                    general_ts_warn_delta | general_ts_max_delta |
                    general_kline_with_reason |
                    general_kline_with_connection_closed |
                    general_warn_no_nline |
                    general_non_redundant_klines | general_dots_in_ident |
                    general_stats_o_oper_only | general_stats_k_oper_only |
                    general_pace_wait | general_stats_i_oper_only |
                    general_pace_wait_simple | general_stats_P_oper_only |
                    general_short_motd | general_no_oper_flood |
                    general_true_no_oper_flood |
                    general_iauth_server |
                    general_iauth_port |
                    general_glines | general_gline_time |
                    general_idletime |
                    general_maximum_links |
                    general_message_locale | general_client_exit |
                    general_fname_userlog | general_fname_operlog |
                    general_fname_foperlog | general_oper_only_umodes |
                    general_max_targets |
                    general_use_egd | general_egdpool_path |
                    general_oper_umodes |
                    general_caller_id_wait | general_default_floodcount |
                    general_min_nonwildcard |
                    general_servlink_path | general_use_help |
                    general_default_cipher_preference |
                    general_compression_level | general_client_flood |
                    general_throttle_time | general_havent_read_conf |
                    general_dot_in_ip6_addr | general_ping_cookie |
                    general_fallback_to_ip6_int | 
                    error;

general_failed_oper_notice:   FAILED_OPER_NOTICE '=' TYES ';'
  {
    ConfigFileEntry.failed_oper_notice = 1;
  }
                        |
                        FAILED_OPER_NOTICE '=' TNO ';'
  {
    ConfigFileEntry.failed_oper_notice = 0;
  } ;

general_anti_nick_flood:   ANTI_NICK_FLOOD '=' TYES ';'
  {
    ConfigFileEntry.anti_nick_flood = 1;
  }
                        |
                        ANTI_NICK_FLOOD '=' TNO ';'
  {
    ConfigFileEntry.anti_nick_flood = 0;
  } ;

general_max_nick_time:    MAX_NICK_TIME '=' timespec ';'
  {
    ConfigFileEntry.max_nick_time = $3; 
  } ;

general_max_nick_changes:  MAX_NICK_CHANGES '=' NUMBER ';'
  {
    ConfigFileEntry.max_nick_changes = $3;
  } ;

general_max_accept:  MAX_ACCEPT '=' NUMBER ';'
  {
    ConfigFileEntry.max_accept = $3;
  } ;

general_anti_spam_exit_message_time:  ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'
  {
    ConfigFileEntry.anti_spam_exit_message_time = $3;
  } ;

general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'
  {
    ConfigFileEntry.ts_warn_delta = $3;
  } ;

general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'
  {
    ConfigFileEntry.ts_max_delta = $3;
  } ;

general_havent_read_conf:  HAVENT_READ_CONF '=' NUMBER ';'
{
  if($3 > 0)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
};
general_kline_with_reason: KLINE_WITH_REASON '=' TYES ';'
  {
    ConfigFileEntry.kline_with_reason = 1;
  }
    |
    KLINE_WITH_REASON '=' TNO ';'
  {
    ConfigFileEntry.kline_with_reason = 0;
  } ;

general_client_exit: CLIENT_EXIT '=' TYES ';'
  {
    ConfigFileEntry.client_exit = 1;
  }
    |
    CLIENT_EXIT '=' TNO ';'
  {
    ConfigFileEntry.client_exit = 0;
  };

general_kline_with_connection_closed: KLINE_WITH_CONNECTION_CLOSED '=' TYES ';'
  {
    ConfigFileEntry.kline_with_connection_closed = 1;
  }
    |
    KLINE_WITH_CONNECTION_CLOSED '=' TNO ';'
  {
    ConfigFileEntry.kline_with_connection_closed = 0;
  } ;

general_warn_no_nline: WARN_NO_NLINE '=' TYES ';'
  {
    ConfigFileEntry.warn_no_nline = 1;
  }
    |
    WARN_NO_NLINE '=' TNO ';'
  {
    ConfigFileEntry.warn_no_nline = 0;
  } ;

general_non_redundant_klines: NON_REDUNDANT_KLINES '=' TYES ';'
  {
    ConfigFileEntry.non_redundant_klines = 1;
  }
    |
    NON_REDUNDANT_KLINES '=' TNO ';'
  {
    ConfigFileEntry.non_redundant_klines = 0;
  } ;

general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TYES ';'
  {
    ConfigFileEntry.stats_o_oper_only = 1;
  }
    |
    STATS_O_OPER_ONLY '=' TNO ';'
  {
    ConfigFileEntry.stats_o_oper_only = 0;
  } ;

general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TYES ';'
  {
    ConfigFileEntry.stats_P_oper_only = 1;
  }
    |
    STATS_P_OPER_ONLY '=' TNO ';'
  {
    ConfigFileEntry.stats_P_oper_only = 0;
  } ;
  
general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TYES ';'
  {
    ConfigFileEntry.stats_k_oper_only = 2;
  }
    |
    STATS_K_OPER_ONLY '=' TMASKED ';'
  {
    ConfigFileEntry.stats_k_oper_only = 1;
  }
    |
    STATS_K_OPER_ONLY '=' TNO ';'
  {
    ConfigFileEntry.stats_k_oper_only = 0;
  } ;

general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TYES ';'
  {
    ConfigFileEntry.stats_i_oper_only = 2;
  }
    |
    STATS_I_OPER_ONLY '=' TMASKED ';'
  {
    ConfigFileEntry.stats_i_oper_only = 1;
  }
    |
    STATS_I_OPER_ONLY '=' TNO ';'
  {
    ConfigFileEntry.stats_i_oper_only = 0;
  } ;

general_pace_wait: PACE_WAIT '=' timespec ';'
  {
    ConfigFileEntry.pace_wait = $3;
  } ;

general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'
  {
    ConfigFileEntry.caller_id_wait = $3;
  } ;

general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'
  {
    ConfigFileEntry.pace_wait_simple = $3;
  } ;

general_short_motd: SHORT_MOTD '=' TYES ';'
  {
    ConfigFileEntry.short_motd = 1;
  }
    |
    SHORT_MOTD '=' TNO ';'
  {
    ConfigFileEntry.short_motd = 0;
  } ;
  
general_no_oper_flood: NO_OPER_FLOOD '=' TYES ';'
  {
    ConfigFileEntry.no_oper_flood = 1;
  }
    | 
    NO_OPER_FLOOD '=' TNO ';'
  {
    ConfigFileEntry.no_oper_flood = 0;
  };

general_true_no_oper_flood: TRUE_NO_OPER_FLOOD '=' TYES ';'
  {
    ConfigFileEntry.true_no_oper_flood = 1;
  }
    |
    TRUE_NO_OPER_FLOOD '=' TNO ';'
  {
    ConfigFileEntry.true_no_oper_flood = 0;
  };

general_iauth_server: IAUTH_SERVER '=' QSTRING ';'
{
#if 0
    strncpy(iAuth.hostname, yylval.string, HOSTLEN)[HOSTLEN] = 0;
#endif
} ;

general_iauth_port: IAUTH_PORT '=' NUMBER ';'
{
#if 0
    iAuth.port = $3;
#endif
} ;

general_fname_userlog: FNAME_USERLOG '=' QSTRING ';'
{
  strlcpy(ConfigFileEntry.fname_userlog, yylval.string,
	      MAXPATHLEN);
} ;

general_fname_foperlog: FNAME_FOPERLOG '=' QSTRING ';'
{
  strlcpy(ConfigFileEntry.fname_foperlog, yylval.string,
	      MAXPATHLEN);
};

general_fname_operlog: FNAME_OPERLOG '=' QSTRING ';'
{
  strlcpy(ConfigFileEntry.fname_operlog, yylval.string,
	      MAXPATHLEN);
};

general_glines: GLINES '=' TYES ';'
  {
    ConfigFileEntry.glines = 1;
  } 
    |
    GLINES '=' TNO ';'
  {
    ConfigFileEntry.glines = 0;
  } ;

general_message_locale: MESSAGE_LOCALE '=' QSTRING ';'
  {
    char langenv[BUFSIZE];
    if (strlen(yylval.string) > BUFSIZE-10)
      yylval.string[BUFSIZE-9] = 0;
    ircsprintf(langenv, "LANGUAGE=%s", yylval.string);
    putenv(langenv);
  } ;

general_gline_time: GLINE_TIME '=' timespec ';'
  {
    ConfigFileEntry.gline_time = $3;
  } ;

general_idletime: IDLETIME '=' timespec ';'
  {
    ConfigFileEntry.idletime = $3;
  } ;

general_dots_in_ident: DOTS_IN_IDENT '=' NUMBER ';'
  {
    ConfigFileEntry.dots_in_ident = $3;
  } ;

general_maximum_links: MAXIMUM_LINKS '=' NUMBER ';'
  {
    ConfigFileEntry.maximum_links = $3;
  } ;

general_max_targets: MAX_TARGETS '=' NUMBER ';'
  {
    ConfigFileEntry.max_targets = $3;
  } ;

general_servlink_path: SERVLINK_PATH '=' QSTRING ';'
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  } ;

general_default_cipher_preference: DEFAULT_CIPHER_PREFERENCE '=' QSTRING ';'
  {
#ifdef HAVE_LIBCRYPTO
    struct EncCapability *ecap;
    char *cipher_name;
    int found = 0;

    ConfigFileEntry.default_cipher_preference = NULL;

    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ( (!irccmp(ecap->name, cipher_name)) &&
           (ecap->cap & CAP_ENC_MASK))
      {
        ConfigFileEntry.default_cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL, "Invalid cipher '%s'", cipher_name);
      ilog(L_ERROR, "Invalid cipher '%s'", cipher_name);
    }
#else
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL, "Ignoring 'default_cipher_preference' "
                                    "-- no OpenSSL support");
    ilog(L_ERROR, "Ignoring 'default_cipher_preference' "
                  "-- no OpenSSL support");
#endif
  } ;

general_compression_level: COMPRESSION_LEVEL '=' NUMBER ';'
  {
    ConfigFileEntry.compression_level = $3;
#ifndef HAVE_LIBZ
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
      "Ignoring compression_level = %d; -- no zlib support",
       ConfigFileEntry.compression_level);
#else
    if ((ConfigFileEntry.compression_level < 1) ||
        (ConfigFileEntry.compression_level > 9))
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
        "Ignoring invalid compression level '%d', using default",
        ConfigFileEntry.compression_level);
      ConfigFileEntry.compression_level = 0;
    }
#endif
  };

general_use_egd: USE_EGD '=' TYES ';'
  {
    ConfigFileEntry.use_egd = 1;
  }
    |
    USE_EGD '=' TNO ';'
  {
    ConfigFileEntry.use_egd = 0;
  } ;

general_egdpool_path: EGDPOOL_PATH '=' QSTRING ';'
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  } ;

general_ping_cookie: PING_COOKIE '=' TYES ';'
  {
    ConfigFileEntry.ping_cookie = 1;
  } |
    PING_COOKIE '=' TNO ';'
  {
    ConfigFileEntry.ping_cookie = 0;
  } ;

general_use_help: USE_HELP '=' TYES ';'
  {
    ConfigFileEntry.use_help = 1;
  }
    |
    USE_HELP '=' TNO ';'
  {
    ConfigFileEntry.use_help = 0;
  } ;

general_throttle_time: THROTTLE_TIME '=' timespec ';'
{
 ConfigFileEntry.throttle_time = yylval.number;
} ;

general_fallback_to_ip6_int: FALLBACK_IP6_INT '=' TYES ';'
{
#ifdef IPV6
 ConfigFileEntry.fallback_to_ip6_int = 1;
#endif
} |
  FALLBACK_IP6_INT '=' TNO ';'
{
#ifdef IPV6
 ConfigFileEntry.fallback_to_ip6_int = 0;
#endif
} ;

general_oper_umodes: OPER_UMODES
  {
    ConfigFileEntry.oper_umodes = 0;
  }
  '='  umode_oitems ';' ;

umode_oitems:    umode_oitems ',' umode_oitem |
  umode_oitem;

umode_oitem:     T_BOTS
  {
    ConfigFileEntry.oper_umodes |= FLAGS_BOTS;
  }
              | T_CCONN
  {
    ConfigFileEntry.oper_umodes |= FLAGS_CCONN;
  }
              | T_DEBUG
  {
    ConfigFileEntry.oper_umodes |= FLAGS_DEBUG;
  }
              | T_FULL
  {
    ConfigFileEntry.oper_umodes |= FLAGS_FULL;
  }
              | T_SKILL
  {
    ConfigFileEntry.oper_umodes |= FLAGS_SKILL;
  }
              | T_NCHANGE
  {
    ConfigFileEntry.oper_umodes |= FLAGS_NCHANGE;
  }
              | T_REJ
  {
    ConfigFileEntry.oper_umodes |= FLAGS_REJ;
  }
              | T_UNAUTH
  {
    ConfigFileEntry.oper_umodes |= FLAGS_UNAUTH;
  }
              | T_SPY
  {
    ConfigFileEntry.oper_umodes |= FLAGS_SPY;
  }
              | T_EXTERNAL
  {
    ConfigFileEntry.oper_umodes |= FLAGS_EXTERNAL;
  }
              | T_OPERWALL
  {
    ConfigFileEntry.oper_umodes |= FLAGS_OPERWALL;
  }
              | T_SERVNOTICE
  {
    ConfigFileEntry.oper_umodes |= FLAGS_SERVNOTICE;
  }
              | T_INVISIBLE
  {
    ConfigFileEntry.oper_umodes |= FLAGS_INVISIBLE;
  }
              | T_WALLOP
  {
    ConfigFileEntry.oper_umodes |= FLAGS_WALLOP;
  }
              | T_CALLERID
  {
    ConfigFileEntry.oper_umodes |= FLAGS_CALLERID;
  }
              | T_LOCOPS
  {
    ConfigFileEntry.oper_umodes |= FLAGS_LOCOPS;
  }
              | T_GOD
  {
    ConfigFileEntry.oper_umodes |= FLAGS_GOD;
  }
              | T_NICKSERVREG
  {
    ConfigFileEntry.oper_umodes |= FLAGS_NICKSERVREG;
  };

general_oper_only_umodes: OPER_ONLY_UMODES 
  {
    ConfigFileEntry.oper_only_umodes = 0;
  }
  '='  umode_items ';' ;

umode_items:	umode_items ',' umode_item |
  umode_item ;

umode_item:	T_BOTS 
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_BOTS;
  } 
              | T_CCONN
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_CCONN;
  }
              | T_DEBUG
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_DEBUG;
  }
              | T_FULL
  { 
    ConfigFileEntry.oper_only_umodes |= FLAGS_FULL;
  }
              | T_SKILL
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_SKILL;
  }
              | T_NCHANGE
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_NCHANGE;
  }
              | T_REJ
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_REJ;
  }
              | T_UNAUTH
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_UNAUTH;
  }
              | T_SPY
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_SPY;
  }
              | T_EXTERNAL
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_EXTERNAL;
  }
              | T_OPERWALL
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_OPERWALL;
  } 
              | T_SERVNOTICE
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_SERVNOTICE;
  }
              | T_INVISIBLE
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_INVISIBLE;
  }
              | T_WALLOP
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_WALLOP;
  }
              | T_CALLERID
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_CALLERID;
  }
              | T_LOCOPS
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_LOCOPS;
  }
              | T_GOD
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_GOD;
  }
              | T_NICKSERVREG
  {
    ConfigFileEntry.oper_only_umodes |= FLAGS_NICKSERVREG;
  };


general_min_nonwildcard:    MIN_NONWILDCARD '=' NUMBER ';'
  {
    ConfigFileEntry.min_nonwildcard = $3;
  };
general_default_floodcount:    DEFAULT_FLOODCOUNT '=' NUMBER ';'
  {
    ConfigFileEntry.default_floodcount = $3;
  };

general_client_flood: T_CLIENT_FLOOD '=' NUMBER ';'
  {
    ConfigFileEntry.client_flood = $3;
  };

general_dot_in_ip6_addr: DOT_IN_IP6_ADDR '=' TYES ';'
  {
    ConfigFileEntry.dot_in_ip6_addr = 1;
  } |
    DOT_IN_IP6_ADDR '=' TNO ';'
  {
    ConfigFileEntry.dot_in_ip6_addr = 0;
  } ;

/***************************************************************************
 *  section channel
 ***************************************************************************/

channel_entry:      CHANNEL
  '{' channel_items '}' ';';

channel_items:      channel_items channel_item |
                    channel_item;

channel_item:       channel_use_except |
                    channel_use_halfops |
                    channel_use_invex |
                    channel_use_knock |
                    channel_use_vchans |
		    channel_use_anonops |
		    channel_vchans_oper_only |
                    channel_max_bans |
                    channel_knock_delay |
		    channel_knock_delay_channel |
                    channel_max_chans_per_user |
                    channel_quiet_on_ban |
		    channel_default_split_user_count | 
		    channel_default_split_server_count |
		    channel_no_create_on_split | 
		    channel_no_join_on_split |
		    channel_oper_pass_resv |
                    error;

channel_use_except:   USE_EXCEPT '=' TYES ';'
  {
    ConfigChannel.use_except = 1;
  }
                        |
                      USE_EXCEPT '=' TNO ';'
  {
    ConfigChannel.use_except = 0;
  } ;


channel_use_halfops:   USE_HALFOPS '=' TYES ';'
  {
#ifdef HALFOPS
    /* Set to -1 on boot */
    if (ConfigChannel.use_halfops == 0)
    {
      ilog(L_ERROR, "Ignoring config file entry 'use_halfops = yes' "
                    "-- can only be changed on boot");
      break;
    }
    else
      ConfigChannel.use_halfops = 1;
#endif
  }
  |
    USE_HALFOPS '=' TNO ';'
  {
    /* Set to -1 on boot */
    if (ConfigChannel.use_halfops == 1)
    {
      ilog(L_ERROR, "Ignoring config file entry 'use_halfops = no' "
                    "-- can only be changed on boot");
      break;
    }
    else
      ConfigChannel.use_halfops = 0;
  };


channel_use_anonops: USE_ANONOPS '=' TYES ';'
  {
#ifdef ANONOPS
    if(ConfigChannel.use_anonops == 0)
    {
      ilog(L_ERROR, "Ignoring config file entry 'use_anonops = yes' "
                    "-- can only be changed on boot");
      break;
    }
    else
      ConfigChannel.use_anonops = 1;
#endif
  }
    |
    USE_ANONOPS '=' TNO ';'
  {
    if(ConfigChannel.use_anonops == 1)
    {
      ilog(L_ERROR, "Ignoring config file entry 'use_anonops = no' "
                    "-- can only be changed on boot");
      break;
    }
    else
      ConfigChannel.use_anonops = 0;
  } ;


channel_use_invex:   USE_INVEX '=' TYES ';'
  {
    ConfigChannel.use_invex = 1;
  }
                        |
                     USE_INVEX '=' TNO ';'
  {
    ConfigChannel.use_invex = 0;
  } ;


channel_use_knock:   USE_KNOCK '=' TYES ';'
  {
    ConfigChannel.use_knock = 1;
  }
                     |
                     USE_KNOCK '=' TNO ';'
  {
    ConfigChannel.use_knock = 0;
  } ;


channel_use_vchans: USE_VCHANS '=' TYES ';'
  { 
#ifdef VCHANS
    ConfigChannel.use_vchans = 1;
#endif
  }
    |
    USE_VCHANS '=' TNO ';'
  { ConfigChannel.use_vchans = 0; };


channel_vchans_oper_only: VCHANS_OPER_ONLY '=' TYES ';'
  { ConfigChannel.vchans_oper_only = 1; }
    |
    VCHANS_OPER_ONLY '=' TNO ';'
  { ConfigChannel.vchans_oper_only = 0; };


channel_knock_delay: KNOCK_DELAY '=' timespec ';'
   {
     ConfigChannel.knock_delay = $3;
   } ;

channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'
   {
     ConfigChannel.knock_delay_channel = $3;
   } ;

channel_max_chans_per_user:  MAX_CHANS_PER_USER '=' NUMBER ';'
   {
     ConfigChannel.max_chans_per_user = $3;
   } ;

channel_quiet_on_ban : QUIET_ON_BAN '=' TYES ';'
   {
     ConfigChannel.quiet_on_ban = 1;
   }
     |
     QUIET_ON_BAN '=' TNO ';'
   {
     ConfigChannel.quiet_on_ban = 0;
   } ;

channel_max_bans: MAX_BANS '=' NUMBER ';'
   {
      ConfigChannel.max_bans = $3;
   } ;

channel_persist_time: PERSIST_TIME '=' timespec ';'
  {
    ConfigChannel.persist_time = $3;
  } ;

channel_default_split_user_count: DEFAULT_SPLIT_USER_COUNT '=' NUMBER ';'
  {
    ConfigChannel.default_split_user_count = $3;
  } ;

channel_default_split_server_count: DEFAULT_SPLIT_SERVER_COUNT '=' NUMBER ';'
  {
    ConfigChannel.default_split_server_count = $3;
  } ;

channel_no_create_on_split: NO_CREATE_ON_SPLIT '=' TYES ';'
  {
    ConfigChannel.no_create_on_split = 1;
  }
    |
    NO_CREATE_ON_SPLIT '=' TNO ';'
  {
    ConfigChannel.no_create_on_split = 0;
  } ;

channel_no_join_on_split: NO_JOIN_ON_SPLIT '=' TYES ';'
  {
    ConfigChannel.no_join_on_split = 1;
  }
    |
    NO_JOIN_ON_SPLIT '=' TNO ';'
  {
    ConfigChannel.no_join_on_split = 0;
  } ;
  
channel_oper_pass_resv: OPER_PASS_RESV '=' TYES ';'
  {
    ConfigChannel.oper_pass_resv = 1;
  }
    |
    OPER_PASS_RESV '=' TNO ';'
  {
    ConfigChannel.oper_pass_resv = 0;
  } ;

/***************************************************************************
 *  section serverhide
 ***************************************************************************/

serverhide_entry:      SERVERHIDE
  '{' serverhide_items '}' ';';

serverhide_items:   serverhide_items serverhide_item |
                    serverhide_item;

serverhide_item:    serverhide_flatten_links |
		    serverhide_hide_servers |
		    serverhide_disable_remote_commands |
		    serverhide_links_delay |
		    serverhide_disable_hidden |
		    serverhide_hidden |
		    serverhide_disable_local_channels |
                    error;

serverhide_flatten_links: FLATTEN_LINKS '=' TYES ';'
  {
    ConfigServerHide.flatten_links = 1;
  }
    |
    FLATTEN_LINKS '=' TNO ';'
  {
    ConfigServerHide.flatten_links = 0;
  } ;

serverhide_hide_servers: HIDE_SERVERS '=' TYES ';'
  {
    ConfigServerHide.hide_servers = 1;
  }
    |
    HIDE_SERVERS '=' TNO ';'
  {
    ConfigServerHide.hide_servers = 0;
  } ;

serverhide_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TYES ';'
  {
    ConfigServerHide.disable_remote = 1;
  }
    |
    DISABLE_REMOTE_COMMANDS '=' TNO ';'
  {
    ConfigServerHide.disable_remote = 0;
  } ;

serverhide_disable_local_channels: DISABLE_LOCAL_CHANNELS '=' TYES ';'
  {
    ConfigServerHide.disable_local_channels = 1;
  }
    |
    DISABLE_LOCAL_CHANNELS '=' TNO ';'
  {
    ConfigServerHide.disable_local_channels = 0;
  } ;

serverhide_links_delay: LINKS_DELAY '=' timespec ';'
  {
    if(($3 > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, $3);
      ConfigServerHide.links_disabled = 0;
    }
	
    ConfigServerHide.links_delay = $3;

  };

serverhide_hidden: HIDDEN '=' TYES ';'
  {
    ConfigServerHide.hidden = 1;
  }
    |
    HIDDEN '=' TNO ';'
  {
    ConfigServerHide.hidden = 0;
  };

serverhide_disable_hidden: DISABLE_HIDDEN '=' TYES ';'
  {
    ConfigServerHide.disable_hidden = 1;
  }
    |
    DISABLE_HIDDEN '=' TNO ';'
  {
    ConfigServerHide.disable_hidden = 0;
  };
  
  
  
