/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_conf.h: A header for the configuration functions.
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

#ifndef INCLUDED_s_conf_h
#define INCLUDED_s_conf_h
#include "setup.h"



#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#endif

#include "config.h"             /* defines */
#include "fileio.h"             /* FBFILE */
#include "ircd_defs.h"
#include "motd.h"               /* MessageFile */
#include "class.h"
#include "client.h"
struct Client;
struct DNSReply;
struct hostent;

/* used by new parser */
/* yacc/lex love globals!!! */

struct ip_value {
  struct irc_inaddr ip;
  int ip_mask;
  int type;
};

extern FBFILE* conf_fbfile_in;
extern char conf_line_in[256];
extern struct ConfItem* yy_aconf;

struct ConfItem
{
  struct ConfItem* next;     /* list node pointer */
  unsigned int     status;   /* If CONF_ILLEGAL, delete when no clients */
  unsigned int     flags;
  int              clients;  /* Number of *LOCAL* clients using this */
  struct irc_inaddr my_ipnum; /* ip to bind to for outgoing connect */
  struct irc_inaddr ipnum;	/* ip to connect to */
  char *           name;     /* IRC name, nick, server name, or original u@h */
  char *           host;     /* host part of user@host */
  char *           passwd;   /* doubles as kline reason *ugh* */
  char *           spasswd;  /* Password to send. */
  char *           user;     /* user part of user@host */
  int              port;
  char *           fakename;   /* Mask name */
  time_t           hold;     /* Hold action until this time (calendar time) */
  char *           className;   /* Name of class */
  struct Class *   c_class;     /* Class of connection */
  struct DNSQuery* dns_query;
  int              aftype;
#ifdef HAVE_LIBCRYPTO
  char *           rsa_public_key_file;
  RSA *            rsa_public_key;
  struct EncCapability *cipher_preference;
#endif
};

#define CONF_ILLEGAL            0x80000000
#define CONF_QUARANTINED_NICK   0x0001
#define CONF_CLIENT             0x0002
#define CONF_SERVER             0x0004
#define CONF_OPERATOR           0x0010
#define CONF_KILL               0x0040
#define CONF_SERVICES           0x0080

#define CONF_CLASS              0x0400
#define CONF_LEAF               0x0800
#define CONF_LISTEN_PORT        0x1000
#define CONF_HUB                0x2000
#define CONF_EXEMPTKLINE        0x4000
#define CONF_NOLIMIT            0x8000
#define CONF_DLINE             0x20000
#define CONF_XLINE             0x40000
#define CONF_ULINE             0x80000
#define CONF_EXEMPTDLINE      0x100000

#define CONF_SERVER_MASK       CONF_SERVER
#define CONF_CLIENT_MASK       (CONF_CLIENT | CONF_OPERATOR | CONF_SERVER_MASK)

#define IsIllegal(x)    ((x)->status & CONF_ILLEGAL)

/* aConfItem->flags */

/* Generic flags... */
/* access flags... */
#define CONF_FLAGS_DO_IDENTD            0x00000001
#define CONF_FLAGS_LIMIT_IP             0x00000002
#define CONF_FLAGS_NO_TILDE             0x00000004
#define CONF_FLAGS_NEED_IDENTD          0x00000008
#define CONF_FLAGS_PASS_IDENTD          0x00000010
#define CONF_FLAGS_NOMATCH_IP           0x00000020
#define CONF_FLAGS_EXEMPTKLINE          0x00000040
#define CONF_FLAGS_NOLIMIT              0x00000080
#define CONF_FLAGS_IDLE_LINED           0x00000100
#define CONF_FLAGS_SPOOF_IP             0x00000200
#define CONF_FLAGS_SPOOF_NOTICE         0x00000400
#define CONF_FLAGS_REDIR                0x00000800
#define CONF_FLAGS_EXEMPTGLINE          0x00001000
#define CONF_FLAGS_RESTRICTED           0x00002000
#define CONF_FLAGS_CAN_FLOOD            0x00100000
/* server flags */
#define CONF_FLAGS_ALLOW_AUTO_CONN      0x00004000
#define CONF_FLAGS_LAZY_LINK            0x00008000
#define CONF_FLAGS_ENCRYPTED            0x00010000
#define CONF_FLAGS_COMPRESSED           0x00020000
#define CONF_FLAGS_TEMPORARY            0x00040000
#define CONF_FLAGS_CRYPTLINK            0x00080000
/* Macros for struct ConfItem */

#define IsLimitIp(x)            ((x)->flags & CONF_FLAGS_LIMIT_IP)
#define IsNoTilde(x)            ((x)->flags & CONF_FLAGS_NO_TILDE)
#define IsConfCanFlood(x)       ((x)->flags & CONF_FLAGS_CAN_FLOOD)
#define IsNeedIdentd(x)         ((x)->flags & CONF_FLAGS_NEED_IDENTD)
#define IsPassIdentd(x)         ((x)->flags & CONF_FLAGS_PASS_IDENTD)
#define IsNoMatchIp(x)          ((x)->flags & CONF_FLAGS_NOMATCH_IP)
#define IsConfExemptKline(x)    ((x)->flags & CONF_FLAGS_EXEMPTKLINE)
#define IsConfExemptLimits(x)   ((x)->flags & CONF_FLAGS_NOLIMIT)
#define IsConfExemptGline(x)    ((x)->flags & CONF_FLAGS_EXEMPTGLINE)
#define IsConfIdlelined(x)      ((x)->flags & CONF_FLAGS_IDLE_LINED)
#define IsConfDoIdentd(x)       ((x)->flags & CONF_FLAGS_DO_IDENTD)
#define IsConfDoSpoofIp(x)      ((x)->flags & CONF_FLAGS_SPOOF_IP)
/* jdc -- flip logic since YES/NO are reversed in the conf code */
#define IsConfSpoofNotice(x)    (!((x)->flags & CONF_FLAGS_SPOOF_NOTICE))
#define IsConfRestricted(x)     ((x)->flags & CONF_FLAGS_RESTRICTED)
#define IsConfEncrypted(x)      ((x)->flags & CONF_FLAGS_ENCRYPTED)
#define IsConfCompressed(x)     ((x)->flags & CONF_FLAGS_COMPRESSED)
#define IsConfCryptLink(x)      ((x)->flags & CONF_FLAGS_CRYPTLINK)

/* port definitions for Opers */

#define CONF_OPER_GLOBAL_KILL   0x0001
#define CONF_OPER_REMOTE        0x0002
#define CONF_OPER_UNKLINE       0x0004
#define CONF_OPER_GLINE         0x0008
#define CONF_OPER_N             0x0010
#define CONF_OPER_K             0x0020
#define CONF_OPER_REHASH        0x0040
#define CONF_OPER_DIE           0x0080
#define CONF_OPER_ADMIN         0x0100

struct config_file_entry
{
  char *dpath;          /* DPATH if set from command line */
  char *configfile;
  char *klinefile;
  char *dlinefile;

  char *glinefile;

  char *logpath;
  char *operlog;
  char *glinelog;

  char *servlink_path;
  char *egdpool_path;

  char* network_name;
  char* network_desc;

  char fname_operlog[MAXPATHLEN];
  char fname_userlog[MAXPATHLEN];
  char fname_foperlog[MAXPATHLEN];

  MessageFile motd;
  MessageFile opermotd;
  MessageFile linksfile;

  int           hub;
  unsigned char compression_level;
  int		dot_in_ip6_addr;
  int           dots_in_ident;
  int           failed_oper_notice;
  int           anti_nick_flood;
  int           anti_spam_exit_message_time;
  int           max_accept;
  int           max_nick_time;
  int           max_nick_changes;
  int           ts_max_delta;
  int           ts_warn_delta;
  int           kline_with_reason;
  int           kline_with_connection_closed;
  int           warn_no_nline;
  int           non_redundant_klines;
  int           stats_o_oper_only;
  int		stats_k_oper_only;
  int		stats_i_oper_only;
  int		stats_P_oper_only;
  int           pace_wait;
  int           pace_wait_simple;
  int           short_motd;
  int           no_oper_flood;
  int           true_no_oper_flood;
  int           glines;
  int           gline_time;
  int           idletime;
  int           hide_server;
  int           client_exit;
  int           maximum_links;
  int           oper_only_umodes;
  int           oper_umodes;
  int           max_targets;
  int           caller_id_wait;
  int           min_nonwildcard;
  int           default_floodcount;
  int           client_flood;
  /* 0 == don't use throttle... */
  int           throttle_time;
  int           use_egd;
  int		ping_cookie;
  int           use_help;
#ifdef IPV6  
  int		fallback_to_ip6_int;
#endif
#ifdef HAVE_LIBCRYPTO
  struct EncCapability *default_cipher_preference;
#endif
};

struct config_channel_entry
{
  int	use_anonops;
  int   use_except;
  int   use_halfops;
  int   use_invex;
  int   use_knock;
  int   use_vchans;
  int   knock_delay;
  int	knock_delay_channel;
  int   vchans_oper_only;
  int   max_bans;
  int   max_chans_per_user;
  int   no_create_on_split;
  int   no_join_on_split;
  int	oper_pass_resv;
  int   quiet_on_ban;
  int   default_split_server_count;
  int   default_split_user_count;
};

struct config_server_hide
{
  int	flatten_links;
  int	hide_servers;
  int	disable_remote;
  int   disable_local_channels;
  int	links_delay;
  int   links_disabled;
  int	hidden;
  int	disable_hidden;
};

struct server_info
{
  char        *name;
  char        *description;
  char        *network_name;
  char        *network_desc;
#ifdef HAVE_LIBCRYPTO
  char *      rsa_private_key_file;
  RSA *       rsa_private_key;
#endif
  int         hub;
  struct      irc_inaddr ip;
  struct      irc_inaddr ip6;
  int         max_clients;
  int         max_buffer;
  int         no_hack_ops;
  int         specific_ipv4_vhost;
  int         specific_ipv6_vhost;
  struct      sockaddr_in dns_host;
};

struct admin_info
{
  char        *name;
  char        *description;
  char        *email;
};

/* bleh. have to become global. */
extern int scount;

/* struct ConfItems */
/* conf uline link list root */
extern struct ConfItem *u_conf;
/* conf xline link list root */
extern struct ConfItem *x_conf;

/* All variables are GLOBAL */
extern struct ConfItem* ConfigItemList;      /* conf list head */
extern int              specific_ipv4_vhost; /* used in s_bsd.c */
extern int              specific_ipv6_vhost;
extern struct config_file_entry ConfigFileEntry;/* defined in ircd.c*/
extern struct config_channel_entry ConfigChannel;/* defined in channel.c*/
extern struct config_server_hide ConfigServerHide; /* defined in s_conf.c */
extern struct server_info ServerInfo;       /* defined in ircd.c */
extern struct admin_info  AdminInfo;        /* defined in ircd.c */
/* End GLOBAL section */

dlink_list temporary_klines;
dlink_list temporary_ip_klines;

extern void clear_ip_hash_table(void);
extern void iphash_stats(struct Client *,struct Client *,int,char **,FBFILE*);
extern void count_ip_hash(int *, u_long *);

void remove_one_ip(struct irc_inaddr *ip);

extern struct ConfItem* make_conf(void);
extern void             free_conf(struct ConfItem*);

extern void             read_conf_files(int cold);

extern int              attach_conf(struct Client*, struct ConfItem *);
extern int              attach_confs(struct Client* client, 
                                     const char* name, int statmask);
extern int              attach_connect_block(struct Client* client, 
					     const char* name,
					     const char* host);
extern int              check_client(struct Client* client_p, struct Client *source_p, char *);
extern void             det_confs_butmask (struct Client *, int);
extern int              detach_conf (struct Client *, struct ConfItem *);
extern struct ConfItem* det_confs_butone (struct Client *, struct ConfItem *);
extern struct ConfItem* find_conf_exact(const char* name, const char* user, const char* host, int statmask);
extern struct ConfItem* find_conf_name(dlink_list *list, const char* name, int statmask);
extern struct ConfItem* find_conf_host(dlink_list *list, const char* host, int statmask);
extern struct ConfItem* find_conf_ip(dlink_list *list, char* ip, char* name, int);
extern struct ConfItem* find_conf_by_name(const char* name, int status);
extern struct ConfItem* find_conf_by_host(const char* host, int status);
extern struct ConfItem* find_kill (struct Client *);
extern int conf_connect_allowed(struct irc_inaddr *addr, int aftype);
extern char *oper_flags_as_string(int);
extern char *oper_privs_as_string(struct Client *, int);

extern int find_u_conf(char*, char*, char *);
extern int find_services_conf(char*);
extern struct ConfItem *find_x_conf(char*);

extern struct ConfItem* find_tkline(const char*, const char*, struct irc_inaddr *);
extern char* show_iline_prefix(struct Client *,struct ConfItem *,char *);
extern void get_printable_conf(struct ConfItem *,
                                    char **, char **, char **,
                                    char **, int *,char **);
extern void report_configured_links(struct Client* client_p, int mask);
extern void report_specials(struct Client* source_p, int flags, int numeric);

extern void yyerror(char *);
extern int conf_yy_fatal_error(char *);
extern int conf_fbgets(char *, int, FBFILE *);

typedef enum {
  CONF_TYPE,
  KLINE_TYPE,
  DLINE_TYPE
} KlineType;

extern void WriteKlineOrDline( KlineType, struct Client *,
			       char *user, char *host, const char *reason,
			       const char *oper_reason,
			       const char *current_date, time_t cur_time );
extern  void    add_temp_kline(struct ConfItem *);
extern  void    report_temp_klines(struct Client *);
extern  void    show_temp_klines(struct Client *, dlink_list *);
extern  void    cleanup_tklines(void *notused);

extern  const   char *get_conf_name(KlineType);
extern  int     rehash (int);

extern int  conf_add_server(struct ConfItem *,int);
extern void conf_add_class_to_conf(struct ConfItem *);
extern void conf_add_me(struct ConfItem *);
extern void conf_add_class(struct ConfItem *,int );
extern void conf_add_d_conf(struct ConfItem *);
extern void conf_add_x_conf(struct ConfItem *);
extern void conf_add_u_conf(struct ConfItem *);
extern void conf_add_services_conf(struct ConfItem *);
extern void conf_add_fields(struct ConfItem*, char*, char *, char*, char *,char *);
extern void conf_add_conf(struct ConfItem *);
extern void flush_expired_ips(void *);

/* XXX consider moving these into kdparse.h */
extern void parse_k_file(FBFILE *fb);
extern void parse_d_file(FBFILE *fb);
extern char *getfield(char *newline);

extern char *get_oper_name(struct Client *client_p);

extern int yylex(void);

extern unsigned long cidr_to_bitmask[];

#define NOT_AUTHORIZED  (-1)
#define SOCKET_ERROR    (-2)
#define I_LINE_FULL     (-3)
#define TOO_MANY        (-4)
#define BANNED_CLIENT   (-5)
#define TOO_FAST        (-6)

#define CLEANUP_TKLINES_TIME 60

#endif /* INCLUDED_s_conf_h */

