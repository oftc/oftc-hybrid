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
#include "ircd_defs.h"
#include "motd.h"               /* MessageFile */
#include "client.h"

struct Client;
struct DNSReply;
struct hostent;

/* used by new parser */
/* yacc/lex love globals!!! */
struct ip_value
{
  struct irc_ssaddr ip;
  int ip_mask;
  int type;
};

extern FBFILE *conf_fbfile_in;
extern char conf_line_in[256];
extern struct AccessItem* yy_aconf;

typedef enum
{  
  CONF_TYPE, 
  CLASS_TYPE,
  OPER_TYPE,
  CLIENT_TYPE,
  SERVER_TYPE,
  HUB_TYPE,
  LEAF_TYPE,
  KLINE_TYPE,
  DLINE_TYPE,
  EXEMPTDLINE_TYPE,
  CLUSTER_TYPE,
  XLINE_TYPE,    
  ULINE_TYPE,
  GLINE_TYPE,
  CRESV_TYPE,     
  NRESV_TYPE,
} ConfType;

struct ConfItem
{
  char *name;		/* Primary key */
  dlink_node node;	/* link into known ConfItems of this type */
  dlink_node conf_node;	/* When linked into a client */
  ConfType type;
};

/*
 * MatchItem - used for XLINE and ULINE types
 */
struct MatchItem
{
  char *user;		/* Used for ULINE only */
  char *host;		/* Used for ULINE only */
  char *reason;
  char *oper_reason;
  int  action;		/* used for xline and uline */
  int  ref_count;	/* How many times is this matchitem in use */
  int  illegal;		/* Should it be deleted when possible? */
};

struct AccessItem
{
  dlink_node node;
  unsigned int     status;   /* If CONF_ILLEGAL, delete when no clients */
  unsigned int     flags;
  unsigned int     modes;
  int              clients;  /* Number of *LOCAL* clients using this */
  struct irc_ssaddr my_ipnum; /* ip to bind to for outgoing connect */
  struct irc_ssaddr ipnum;	/* ip to connect to */
  char *           host;     /* host part of user@host */
  char *           passwd;
  char *           spasswd;  /* Password to send. */
  char *	   reason;
  char *	   oper_reason;
  char *           user;     /* user part of user@host */
  int              port;
  char *           fakename;   /* Mask name */
  time_t           hold;     /* Hold action until this time (calendar time) */
  struct ConfItem *class_ptr;  /* Class of connection */
  struct DNSQuery* dns_query;
  int              aftype;
#ifdef HAVE_LIBCRYPTO
  char *           rsa_public_key_file;
  RSA *            rsa_public_key;
  struct EncCapability *cipher_preference;
#endif
};

struct ClassItem
{
  int con_freq;
  int ping_freq;
  int max_total;
  int max_local;
  int max_global;
  int max_ident;
  int max_perip;
  long max_sendq;
  int curr_user_count;
};

#define ConFreq(x)	((x)->con_freq)
#define PingFreq(x)	((x)->ping_freq)
#define MaxTotal(x)	((x)->max_total)
#define MaxGlobal(x)	((x)->max_global)
#define MaxLocal(x)	((x)->max_local)
#define MaxIdent(x)	((x)->max_ident)
#define MaxPerIp(x)	((x)->max_perip)
#define MaxSendq(x)	((x)->max_sendq)
#define CurrUserCount(x) ((x)->curr_user_count)

#define ClassPtr(x)      ((x)->class_ptr)

extern unsigned long get_sendq(struct Client *);
extern int get_con_freq(struct ClassItem* );
extern const char *get_client_class(struct Client *);
extern int get_client_ping(struct Client *);
extern void check_class(void);
extern void init_class(void);
extern struct ConfItem *find_class(const char *);

#define CONF_ILLEGAL            0x80000000
#define CONF_RESERVED           0x00000001
#define CONF_CLIENT             0x00000002
#define CONF_SERVER             0x00000004
#define CONF_OPERATOR           0x00000008
#define CONF_KILL               0x00000010
#define CONF_KLINE              CONF_KILL
#define CONF_CLASS              0x00000020
#define CONF_LEAF               0x00000040
#define CONF_LISTEN_PORT        0x00000080
#define CONF_HUB                0x00000100
#define CONF_EXEMPTKLINE        0x00000200
#define CONF_NOLIMIT            0x00000400
#define CONF_DLINE              0x00000800
#define CONF_XLINE              0x00001000
#define CONF_ULINE              0x00002000
#define CONF_EXEMPTDLINE        0x00004000
#define CONF_CLUSTER            0x00008000
#define CONF_SERVICES           0x00010000

#define CONF_SERVER_MASK       CONF_SERVER
#define CONF_CLIENT_MASK       (CONF_CLIENT | CONF_OPERATOR | CONF_SERVER_MASK)

/* XXX temporary hack */
#define CONF_CRESV	        0x80000001
#define CONF_NRESV	        0x80000002

#define IsConfIllegal(x)	((x)->status & CONF_ILLEGAL)
#define SetConfIllegal(x)	((x)->status |= CONF_ILLEGAL)
#define IsConfServer(x)		((x)->status == CONF_SERVER)
#define SetConfServer(x)	((x)->status = CONF_SERVER)
#define IsConfOperator(x)	((x)->status & CONF_OPERATOR)
#define IsConfHub(x)		((x)->status == CONF_HUB)
#define SetConfHub(x)		((x)->status = CONF_HUB)
#define IsConfLeaf(x)		((x)->status == CONF_LEAF)
#define SetConfLeaf(x)		((x)->status = CONF_LEAF)
#define IsConfHubOrLeaf(x)	((x)->status & (CONF_HUB|CONF_LEAF))
#define IsConfKill(x)		((x)->status == CONF_KILL)
#define IsConfClient(x)		((x)->status & CONF_CLIENT)
#define IsConfTypeOfClient(x)	((x)->status & CONF_CLIENT_MASK)
#define IsConfUline(x)		((x)->status & CONF_ULINE)
#define IsConfXline(x)		((x)->status & CONF_XLINE)
#define IsConfCluster(x)	((x)->status & CONF_CLUSTER)

/* AccessItem->flags */

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
#define CONF_FLAGS_NEED_PASSWORD        0x00200000
/* server flags */
#define CONF_FLAGS_ALLOW_AUTO_CONN      0x00004000
#define CONF_FLAGS_LAZY_LINK            0x00008000
#define CONF_FLAGS_ENCRYPTED            0x00010000
#define CONF_FLAGS_COMPRESSED           0x00020000
#define CONF_FLAGS_TEMPORARY            0x00040000
#define CONF_FLAGS_CRYPTLINK            0x00080000

/* Macros for struct AccessItem */
#define IsLimitIp(x)            ((x)->flags & CONF_FLAGS_LIMIT_IP)
#define IsNoTilde(x)            ((x)->flags & CONF_FLAGS_NO_TILDE)
#define IsConfCanFlood(x)       ((x)->flags & CONF_FLAGS_CAN_FLOOD)
/* see below (default is 0 and need_password = yes) */
#define IsNeedPassword(x)       (!((x)->flags & CONF_FLAGS_NEED_PASSWORD))
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
#define IsConfLazyLink(x)       ((x)->flags & CONF_FLAGS_LAZY_LINK)
#define IsConfAllowAutoConn(x)  ((x)->flags & CONF_FLAGS_ALLOW_AUTO_CONN)
#define SetConfAllowAutoConn(x)	((x)->flags |= CONF_FLAGS_ALLOW_AUTO_CONN)
#define ClearConfAllowAutoConn(x) ((x)->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN)
#define IsConfTemporary(x)      ((x)->flags & CONF_FLAGS_TEMPORARY)
#define SetConfTemporary(x)     ((x)->flags |= CONF_FLAGS_TEMPORARY)
#define IsConfRedir(x)          ((x)->flags & CONF_FLAGS_REDIR)

/* shared server entry types */
#define SHARED_KLINE		0x0001
#define SHARED_UNKLINE		0x0002
#define SHARED_XLINE		0x0004
#define SHARED_UNXLINE		0x0008
#define SHARED_RESV		0x0010
#define SHARED_UNRESV		0x0020
#define SHARED_ALL		(SHARED_KLINE | SHARED_UNKLINE | SHARED_XLINE |\
				 SHARED_UNXLINE | SHARED_RESV | SHARED_UNRESV)

struct config_file_entry
{
  const char *dpath;          /* DPATH if set from command line */
  const char *configfile;
  const char *klinefile;
  const char *xlinefile;
  const char *dlinefile;
  const char *glinefile;
  const char *cresvfile;
  const char *nresvfile;

  char *logpath;
  char *operlog;

  char *servlink_path;
  char *egdpool_path;

  MessageFile motd;
  MessageFile opermotd;
  MessageFile linksfile;

  unsigned char compression_level;
  int dot_in_ip6_addr;
  int dots_in_ident;
  int failed_oper_notice;
  int anti_nick_flood;
  int anti_spam_exit_message_time;
  int max_accept;
  int max_nick_time;
  int max_nick_changes;
  int ts_max_delta;
  int ts_warn_delta;
  int kline_with_reason;
  int kline_with_connection_closed;
  int warn_no_nline;
  int stats_o_oper_only;
  int stats_k_oper_only;
  int stats_i_oper_only;
  int stats_P_oper_only;
  int pace_wait;
  int pace_wait_simple;
  int short_motd;
  int no_oper_flood;
  int true_no_oper_flood;
  int oper_pass_resv;
  int glines;
  int gline_time;
  int hide_spoof_ips;
  int idletime;
  int ignore_bogus_ts;
  int maximum_links;
  int oper_only_umodes;
  int oper_umodes;
  int crypt_oper_password;
  int max_targets;
  int caller_id_wait;
  int min_nonwildcard;
  int min_nonwildcard_simple;
  int default_floodcount;
  int client_flood;
  /* 0 == don't use throttle... */
  int throttle_time;
  int use_egd;
  int ping_cookie;
  int disable_auth;
  int disable_remote;
#ifdef HAVE_LIBCRYPTO
  struct EncCapability *default_cipher_preference;
#endif
};

struct config_channel_entry
{
  int disable_local_channels;
  int use_except;
  int use_invex;
  int use_knock;
  int knock_delay;
  int knock_delay_channel;
  unsigned int max_bans;
  unsigned int max_chans_per_user;
  int no_create_on_split;
  int no_join_on_split;
  int quiet_on_ban;
  int default_split_server_count;
  int default_split_user_count;
};

struct config_server_hide
{
  int flatten_links;
  int hide_servers;
  int links_delay;
  int links_disabled;
  int hidden;
  int disable_hidden;
  int hide_server_ips;
};

struct server_info
{
  char        *name;
  char        *description;
  char        *network_name;
  char        *network_desc;
#ifdef HAVE_LIBCRYPTO
  char        *rsa_private_key_file;
  RSA         *rsa_private_key;
  char        *ssl_certificate_file;
  SSL_CTX     *ctx;
  SSL_METHOD  *meth;
#endif
  char	      *sid;
  int         hub;
  struct      irc_ssaddr ip;
  struct      irc_ssaddr ip6;
  int         max_clients;
  int         specific_ipv4_vhost;
  int         specific_ipv6_vhost;
  struct      sockaddr_in dns_host;
  int         can_use_v6;
};

struct admin_info
{
  char *name;
  char *description;
  char *email;
};

extern int scount;
extern int ypass;
extern int specific_ipv4_vhost; /* used in s_bsd.c */
extern int specific_ipv6_vhost;
extern dlink_list class_items;
extern dlink_list server_items;
extern dlink_list services_items;
extern dlink_list cluster_items;
extern dlink_list hub_items;
extern dlink_list leaf_items;
extern dlink_list gline_items;
extern dlink_list temporary_klines;
extern dlink_list temporary_dlines;
extern dlink_list temporary_ip_klines;
extern struct config_file_entry ConfigFileEntry;/* defined in ircd.c*/
extern struct config_channel_entry ConfigChannel;/* defined in channel.c*/
extern struct config_server_hide ConfigServerHide; /* defined in s_conf.c */
extern struct server_info ServerInfo;       /* defined in ircd.c */
extern struct admin_info AdminInfo;        /* defined in ircd.c */
/* End GLOBAL section */

extern void init_ip_hash_table(void);
extern void count_ip_hash(int *, unsigned long *);
extern void remove_one_ip(struct irc_ssaddr *ip);
extern struct ConfItem *make_conf_item(ConfType type);

extern void free_access_item(struct AccessItem *);
extern void read_conf_files(int cold);
extern int attach_conf(struct Client *, struct ConfItem *);
extern int attach_connect_block(struct Client *client, const char *name,
				const char *host);
extern int check_client(struct Client *client_p, struct Client *source_p,
			const char *);

extern int detach_conf(struct Client *, ConfType );
extern void detach_all_confs(struct Client *);

extern struct ConfItem *find_conf_name(dlink_list *list, const char *name,
				       ConfType type);
extern struct ConfItem* 
find_conf_exact(ConfType type, const char* name, const char* user, 
		const char* host);

extern struct AccessItem *find_kill(struct Client *);
extern int conf_connect_allowed(struct irc_ssaddr *addr, int aftype);
extern char *oper_privs_as_string(const unsigned int);
extern void split_user_host(char *user_host, char **user_p, char **host_p);
extern struct ConfItem *find_matching_name_conf(ConfType type, const char *,
						const char *, const char *,
						int );
extern struct ConfItem *find_exact_name_conf(ConfType type, const char *,
					     const char *, const char *);
extern void delete_conf_item(struct ConfItem *);
extern void get_printable_conf(struct ConfItem *, char **, char **,
			       char **, int *,char **);

extern void report_confitem_types(struct Client *source_p, ConfType type);

extern void yyerror(const char *);
extern int conf_yy_fatal_error(const char *);
extern int conf_fbgets(char *, int, FBFILE *);

extern void write_conf_line(struct Client *, struct ConfItem *,
			    const char *, time_t);

extern int remove_conf_line(ConfType, struct Client *, const char *,
			    const char *);
extern void add_temp_kline(struct AccessItem *);
extern void add_temp_dline(struct AccessItem *);
extern void cleanup_tklines(void *notused);

extern const char *get_conf_name(ConfType);
extern int rehash(int);

extern int conf_add_server(struct ConfItem *, unsigned int, const char *);
extern void conf_add_class_to_conf(struct ConfItem *, const char *);
extern void conf_add_d_conf(struct AccessItem *);

/* XXX consider moving these into csvlib.h */
extern void parse_csv_file(FBFILE *file, ConfType);
extern char *getfield(char *newline);

extern char *get_oper_name(struct Client *client_p);
/* XXX consider inlining this */
extern void *map_to_conf(struct ConfItem *conf);
/* XXX consider inlining this */
struct ConfItem *unmap_conf_item(void *aconf);

extern int yylex(void);

#define NOT_AUTHORIZED  (-1)
#define IRCD_SOCKET_ERROR    (-2)
#define I_LINE_FULL     (-3)
#define TOO_MANY        (-4)
#define BANNED_CLIENT   (-5)
#define TOO_FAST        (-6)

#define CLEANUP_TKLINES_TIME 60
#endif /* INCLUDED_s_conf_h */
