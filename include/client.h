/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  client.h: The ircd client header.
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

#ifndef INCLUDED_client_h
#define INCLUDED_client_h

#include "config.h"

#if !defined(CONFIG_H_LEVEL_7)
#error Incorrect config.h for this revision of ircd.
#endif

#include "ircd_defs.h"
#include "ircd_handler.h"
#include "linebuf.h"
#include "channel.h"
#include "res.h"
#ifdef IPV6
#define HOSTIPLEN	53 /* sizeof("ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255.ipv6") */
#else
#define HOSTIPLEN       16      /* Length of dotted quad form of IP        */
#endif
#define PASSWDLEN       20
#define CIPHERKEYLEN    64      /* 512bit */

#define IDLEN           12      /* this is the maximum length, not the actual
                                   generated length; DO NOT CHANGE! */
#define COOKIELEN       IDLEN

#define CLIENT_BUFSIZE 512      /* must be at least 512 bytes */


/*
 * pre declare structs
 */
struct ConfItem;
struct Whowas;
struct DNSReply;
struct Listener;
struct Client;
struct LocalUser;

/*
 * Client structures
 */
struct User
{
  dlink_list     channel;       /* chain of channel pointer blocks */
  dlink_list     invited;       /* chain of invite pointer blocks */
  char*          away;          /* pointer to away message */
  time_t         last_away;     /* Away since... */
  time_t         last;
  int            refcnt;        /* Number of times this block is referenced */
  int            joined;        /* number of channels joined */
  const char*    server;        /* pointer to scached server name */
  char*          response;  /* expected response from client */
  char*          auth_oper; /* Operator to become if they supply the response.*/
	/* client ID, unique ID per client */
  char id[IDLEN + 1];
  char id_key[IDLEN + 1];
  /* When did we detach from them, if they are detached... */
  time_t            last_detach_time;
};

struct Server
{
  struct User*     user;        /* who activated this connection */
  const char*      up;          /* Pointer to scache name */
  char             by[NICKLEN];
  struct ConfItem* sconf;       /* connect{} pointer for this server */
  struct Client*   servers;     /* Servers on this server */
  struct Client*   users;       /* Users on this server */
};

struct SlinkRpl
{
  int command;
  int datalen;
  int gotdatalen;
  int readdata;
  unsigned char *data;
};

struct ZipStats
{
  unsigned long in;
  unsigned long in_wire;
  unsigned long out;
  unsigned long out_wire;
  double in_ratio;
  double out_ratio;
};

/* entry for base_chan pointer and the corresponding vchan
 * client is actually on
 */
struct Vchan_map
{
  struct Channel *base_chan;
  struct Channel *vchan;
};

struct Client
{
  struct Client*    next;
  struct Client*    prev;
  struct Client*    hnext;
  struct Client*    idhnext;
	
  struct Client*    lnext;      /* Used for Server->servers/users */
  struct Client*    lprev;      /* Used for Server->servers/users */

  struct User*      user;       /* ...defined, if this is a User */
  struct Server*    serv;       /* ...defined, if this is a server */
  struct Client*    servptr;    /* Points to server this Client is on */
  struct Client*    from;       /* == self, if Local Client, *NEVER* NULL! */

  struct Whowas*    whowas;     /* Pointers to whowas structs */
  time_t            lasttime;   /* ...should be only LOCAL clients? --msa */
  time_t            firsttime;  /* time client was created */
  time_t            since;      /* last time we parsed something */
  time_t            tsinfo;     /* TS on the nick, SVINFO on server */
  unsigned int      umodes;     /* opers, normal users subset */
  unsigned int      flags;      /* client flags */
  unsigned int      flags2;     /* ugh. overflow */

  int               slink_pid;  /* pid of servlink process if any */
  int               hopcount;   /* number of servers to this 0 = local */
  int		    hidden_server;
  unsigned short    status;     /* Client type */
  unsigned char     handler;    /* Handler index */
  char              eob;	/* server eob has been received */
  unsigned long     serial;	/* used to enforce 1 send per nick */
  unsigned long     lazyLinkClientExists; /* This client exists on the
					   * bit mapped lazylink servers 
					   * mapped here
					   */
  /*
   * client->name is the unique name for a client nick or host
   */
  char              name[HOSTLEN + 1]; 
  /*
   * client->llname is used to store the clients requested nick
   * temporarily for new connections.
   */
  char              llname[NICKLEN];
  /* 
   * client->username is the username from ident or the USER message, 
   * If the client is idented the USER message is ignored, otherwise 
   * the username part of the USER message is put here prefixed with a 
   * tilde depending on the I:line, Once a client has registered, this
   * field should be considered read-only.
   */ 
  char              username[USERLEN + 1]; /* client's username */
  /*
   * client->host contains the resolved name or ip address
   * as a string for the user, it may be fiddled with for oper spoofing etc.
   * once it's changed the *real* address goes away. This should be
   * considered a read-only field after the client has registered.
   */
  char              host[HOSTLEN + 1];     /* client's hostname */
  /*
   * client->info for unix clients will normally contain the info from the 
   * gcos field in /etc/passwd but anything can go here.
   */
  char              info[REALLEN + 1]; /* Free form additional client info */

/* cache table of mappings between top level chan and sub vchan client
 * is on.
 */

  dlink_list      vchan_map;

  /* caller ID allow list */
  /* This has to be here, since a client on an on_allow_list could
   * be a remote client. simpler to keep both here.
   */
  dlink_list	allow_list;	/* clients I'll allow to talk to me */
  dlink_list	on_allow_list;	/* clients that have =me= on their allow list*/
  
  
  struct LocalUser *localClient;
  struct timeval ping_time, ping_send_time;
  char              realhost[HOSTLEN + 1];

};

struct LocalUser
{
  /*
   * The following fields are allocated only for local clients
   * (directly connected to *this* server with a socket.
   */
  /* Anti flooding part, all because of lamers... */
  time_t            last_join_time;   /* when this client last 
                                         joined a channel */
  time_t            last_leave_time;  /* when this client last 
                                       * left a channel */
  int               join_leave_count; /* count of JOIN/LEAVE in less than 
                                         MIN_JOIN_LEAVE_TIME seconds */
  int               oper_warn_count_down; /* warn opers of this possible 
                                          spambot every time this gets to 0 */
  time_t            last_caller_id_time;
  time_t            first_received_message_time;
  int               received_number_of_privmsgs;
  int               flood_noticed;

  /* Send and receive linebuf queues .. */
  buf_head_t        buf_sendq;
  buf_head_t        buf_recvq;
  /*
   * we want to use unsigned int here so the sizes have a better chance of
   * staying the same on 64 bit machines. The current trend is to use
   * I32LP64, (32 bit ints, 64 bit longs and pointers) and since ircd
   * will NEVER run on an operating system where ints are less than 32 bits, 
   * it's a relatively safe bet to use ints. Since right shift operations are
   * performed on these, it's not safe to allow them to become negative, 
   * which is possible for long running server connections. Unsigned values 
   * generally overflow gracefully. --Bleep
   */
  unsigned int      sendM;      /* Statistics: protocol messages send */
  unsigned int      sendK;      /* Statistics: total k-bytes send */
  unsigned int      receiveM;   /* Statistics: protocol messages received */
  unsigned int      receiveK;   /* Statistics: total k-bytes received */
  unsigned short    sendB;      /* counters to count upto 1-k lots of bytes */
  unsigned short    receiveB;   /* sent and received. */
  unsigned int      lastrecvM;  /* to check for activity --Mika */
  int               priority;
  struct Listener*  listener;   /* listener accepted from */
  dlink_list        confs;      /* Configuration record associated */

  struct irc_inaddr ip;
  unsigned short    port;       /* and the remote port# too :-) */
  int 		    aftype;	/* Makes life easier for DNS res in IPV6 */
  struct DNSQuery   *dns_query;  /* result returned from resolver query */
  unsigned long     serverMask; /* Only used for Lazy Links */
  time_t            last_nick_change;
  int               number_of_nick_changes;
  /*
   * client->sockhost contains the ip address gotten from the socket as a
   * string, this field should be considered read-only once the connection
   * has been made. (set in s_bsd.c only)
   */
  char              sockhost[HOSTIPLEN + 1]; /* This is the host name from the 
                                              socket ip address as string */
  /*
   * XXX - there is no reason to save this, it should be checked when it's
   * received and not stored, this is not used after registration
   */
  char              passwd[PASSWDLEN + 1];
  int               caps;       /* capabilities bit-field */
  int               enc_caps;   /* cipher capabilities bit-field */

#ifdef HAVE_LIBCRYPTO
  struct EncCapability *in_cipher;
  struct EncCapability *out_cipher;

  char              in_key[CIPHERKEYLEN];
  char              out_key[CIPHERKEYLEN];
#endif

  int               fd;         /* >= 0, for local clients */
#ifndef HAVE_SOCKETPAIR
  int               fd_r;       /* fd for reading */
#endif

  int               ctrlfd;     /* For servers:
                                   control fd used for sending commands
                                   to servlink */
#ifndef HAVE_SOCKETPAIR
  int              ctrlfd_r;    /* control fd for reading */
#endif

  struct SlinkRpl  slinkrpl;    /* slink reply being parsed */
  unsigned char    *slinkq;     /* sendq for control data */
  int              slinkq_ofs;  /* ofset into slinkq */
  int              slinkq_len;  /* length remaining after slinkq_ofs */

  struct ZipStats  zipstats;

  /*
   * Anti-flood stuff. We track how many messages were parsed and how
   * many we were allowed in the current second, and apply a simple decay
   * to avoid flooding.
   *   -- adrian
   */
  int allow_read;	/* how many we're allowed to read in this second */
  int actually_read;    /* how many we've actually read in this second */
  int sent_parsed;      /* how many messages we've parsed in this second */
  time_t last_knock;    /* time of last knock */
  unsigned long random_ping;

};

/*
 * status macros.
 */
#define STAT_CONNECTING         0x01
#define STAT_HANDSHAKE          0x02
#define STAT_ME                 0x04
#define STAT_UNKNOWN            0x08
#define STAT_SERVER             0x10
#define STAT_CLIENT             0x20

#define HasID(x) (!IsServer(x) && (x)->user && (x)->user->id[0] != '\0')
#define ID(source_p) (HasID(source_p) ? source_p->user->id : source_p->name)

#define ID_or_name(x,client_p) (IsCapable(client_p,CAP_UID)?(x)->user->id:(x)->name)

#define IsRegisteredUser(x)     ((x)->status == STAT_CLIENT)
#define IsRegistered(x)         ((x)->status  > STAT_UNKNOWN)
#define IsConnecting(x)         ((x)->status == STAT_CONNECTING)
#define IsHandshake(x)          ((x)->status == STAT_HANDSHAKE)
#define IsMe(x)                 ((x)->status == STAT_ME)
#define IsUnknown(x)            ((x)->status == STAT_UNKNOWN)
#define IsServer(x)             ((x)->status == STAT_SERVER)
#define IsClient(x)             ((x)->status == STAT_CLIENT)

#define IsOper(x)		((x)->umodes & FLAGS_OPER)
#define IsAdmin(x)		((x)->umodes & FLAGS_ADMIN)

#define SetConnecting(x)        {(x)->status = STAT_CONNECTING; \
				 (x)->handler = UNREGISTERED_HANDLER; }

#define SetHandshake(x)         {(x)->status = STAT_HANDSHAKE; \
				 (x)->handler = UNREGISTERED_HANDLER; }

#define SetMe(x)                {(x)->status = STAT_ME; \
				 (x)->handler = UNREGISTERED_HANDLER; }

#define SetUnknown(x)           {(x)->status = STAT_UNKNOWN; \
				 (x)->handler = UNREGISTERED_HANDLER; }

#define SetServer(x)            {(x)->status = STAT_SERVER; \
				 (x)->handler = SERVER_HANDLER; }

#define SetClient(x)            {(x)->status = STAT_CLIENT; \
				 (x)->handler = IsOper((x)) ? \
					OPER_HANDLER : CLIENT_HANDLER; }

#define STAT_CLIENT_PARSE (STAT_UNKNOWN | STAT_CLIENT)
#define STAT_SERVER_PARSE (STAT_CONNECTING | STAT_HANDSHAKE | STAT_SERVER)

#define PARSE_AS_CLIENT(x)      ((x)->status & STAT_CLIENT_PARSE)
#define PARSE_AS_SERVER(x)      ((x)->status & STAT_SERVER_PARSE)

#define SetEob(x)		((x)->eob = 1)
#define HasSentEob(x)		((x)->eob)

/*
 * ts stuff
 */
#define TS_CURRENT      5       /* current TS protocol version */
#ifdef TS5_ONLY
#define TS_MIN          5
#else
#define TS_MIN          3       /* minimum supported TS protocol version */
#endif
#define TS_DOESTS       0x20000000
#define DoesTS(x)       ((x)->tsinfo == TS_DOESTS)


/* housekeeping flags */

#define FLAGS_PINGSENT     0x0001 /* Unreplied ping sent */
#define FLAGS_DEADSOCKET   0x0002 /* Local socket is dead--Exiting soon */
#define FLAGS_KILLED       0x0004 /* Prevents "QUIT" from being sent for this*/
#define FLAGS_CLOSING      0x0020 /* set when closing to suppress errors */
#define FLAGS_CHKACCESS    0x0040 /* ok to check clients access if set */
#define FLAGS_GOTID        0x0080 /* successful ident lookup achieved */
#define FLAGS_NEEDID       0x0100 /* I-lines say must use ident return */
#define FLAGS_NORMALEX     0x0400 /* Client exited normally */
#define FLAGS_SENDQEX      0x0800 /* Sendq exceeded */
#define FLAGS_IPHASH       0x1000 /* iphashed this client */
#define FLAGS_CRYPTIN      0x2000 /* incoming data must be decrypted */
#define FLAGS_CRYPTOUT     0x4000 /* outgoing data must be encrypted */
#define FLAGS_WAITAUTH     0x8000 /* waiting for CRYPTLINK AUTH command */
#define FLAGS_SERVLINK     0x10000 /* servlink has servlink process */
#define FLAGS_MARK	   0x20000 /* marked client */
#define FLAGS_SERVICE      0x40000 /* services server/client */
#define FLAGS_CANFLOOD     0x80000 /* client has the ability to flood */
/* umodes, settable flags */

#define FLAGS_SERVNOTICE   0x0001 /* server notices such as kill */
#define FLAGS_CCONN        0x0002 /* Client Connections */
#define FLAGS_REJ          0x0004 /* Bot Rejections */
#define FLAGS_SKILL        0x0008 /* Server Killed */
#define FLAGS_FULL         0x0010 /* Full messages */
#define FLAGS_SPY          0x0020 /* see STATS / LINKS */
#define FLAGS_DEBUG        0x0040 /* 'debugging' info */
#define FLAGS_NCHANGE      0x0080 /* Nick change notice */
#define FLAGS_WALLOP       0x0100 /* send wallops to them */
#define FLAGS_OPERWALL     0x0200 /* Operwalls */
#define FLAGS_INVISIBLE    0x0400 /* makes user invisible */
#define FLAGS_BOTS         0x0800 /* shows bots */
#define FLAGS_EXTERNAL     0x1000 /* show servers introduced and splitting */
#define FLAGS_CALLERID     0x4000 /* block unless caller id's */
#define FLAGS_UNAUTH       0x8000 /* show unauth connects here */
#define FLAGS_LOCOPS       0x10000 /* show locops */

/* user information flags, only settable by remote mode or local oper */
#define FLAGS_OPER         0x20000 /* Operator */
#define FLAGS_ADMIN        0x40000 /* Admin on server */
#define FLAGS_GOD          0x80000 /* Operator is God - oftc */
#define FLAGS_NICKSERVREG  0x100000 /* User is registered with nickserv and has identified */

#define FLAGS_ALL	   FLAGS_SERVNOTICE


/* overflow flags */
#define FLAGS2_EXEMPTGLINE  0x0001	/* client can't be G-lined */
#define FLAGS2_EXEMPTKLINE  0x0002      /* client is exempt from kline */
#define FLAGS2_NOLIMIT      0x0004      /* client is exempt from limits */
#define FLAGS2_RESTRICTED   0x0008      /* client cannot op others */

/* oper priv flags */
#define FLAGS2_OPER_GLOBAL_KILL 0x0020  /* oper can global kill */
#define FLAGS2_OPER_REMOTE      0x0040  /* oper can do squits/connects */
#define FLAGS2_OPER_UNKLINE     0x0080  /* oper can use unkline */
#define FLAGS2_OPER_GLINE       0x0100  /* oper can use gline */
#define FLAGS2_OPER_N           0x0200  /* oper can umode n */
#define FLAGS2_OPER_K           0x0400  /* oper can kill/kline */
#define FLAGS2_OPER_DIE         0x0800  /* oper can die */
#define FLAGS2_OPER_REHASH      0x1000  /* oper can rehash */
#define FLAGS2_OPER_ADMIN       0x2000  /* oper can set umode +a */
#define FLAGS2_OPER_FLAGS       (FLAGS2_OPER_GLOBAL_KILL | \
                                 FLAGS2_OPER_REMOTE | \
                                 FLAGS2_OPER_UNKLINE | \
                                 FLAGS2_OPER_GLINE | \
                                 FLAGS2_OPER_N | \
                                 FLAGS2_OPER_K | \
                                 FLAGS2_OPER_DIE | \
                                 FLAGS2_OPER_REHASH| \
                                 FLAGS2_OPER_ADMIN)

#define FLAGS2_CBURST		0x10000  /* connection burst being sent */
#define FLAGS2_PING_COOKIE	0x20000		/* PING Cookie */
#define FLAGS2_IDLE_LINED       0x40000
#define FLAGS2_IP_SPOOFING      0x80000        /* client IP is spoofed */
#define FLAGS2_FLOODDONE        0x200000      /* Flood grace period has
                                               * been ended. */

#define SEND_UMODES  (FLAGS_INVISIBLE | FLAGS_OPER | FLAGS_WALLOP | \
                      FLAGS_ADMIN | FLAGS_GOD | FLAGS_NICKSERVREG)
#define ALL_UMODES   (SEND_UMODES | FLAGS_SERVNOTICE | FLAGS_CCONN | \
                      FLAGS_REJ | FLAGS_SKILL | FLAGS_FULL | FLAGS_SPY | \
                      FLAGS_NCHANGE | FLAGS_OPERWALL | FLAGS_DEBUG | \
                      FLAGS_BOTS | FLAGS_EXTERNAL | FLAGS_LOCOPS | \
 		      FLAGS_ADMIN | FLAGS_UNAUTH | FLAGS_CALLERID | FLAGS_GOD | \
		      FLAGS_NICKSERVREG )

#define FLAGS_ID     (FLAGS_NEEDID | FLAGS_GOTID)

/*
 * flags macros.
 */
#define IsPerson(x)             (IsClient(x) && (x)->user)
#define DoAccess(x)             ((x)->flags & FLAGS_CHKACCESS)
#define IsDead(x)               ((x)->flags & FLAGS_DEADSOCKET)
#define SetDead(x)              ((x)->flags |= FLAGS_DEADSOCKET)
#define SetAccess(x)            ((x)->flags |= FLAGS_CHKACCESS)
#define IsClosing(x)		((x)->flags & FLAGS_CLOSING)
#define SetClosing(x)		((x)->flags |= FLAGS_CLOSING)
#define ClearAccess(x)          ((x)->flags &= ~FLAGS_CHKACCESS)
#define IsCryptIn(x)            ((x)->flags &  FLAGS_CRYPTIN)
#define SetCryptIn(x)           ((x)->flags |= FLAGS_CRYPTIN)
#define IsCryptOut(x)           ((x)->flags &  FLAGS_CRYPTOUT)
#define SetCryptOut(x)          ((x)->flags |= FLAGS_CRYPTOUT)
#define IsWaitAuth(x)           ((x)->flags &  FLAGS_WAITAUTH)
#define SetWaitAuth(x)          ((x)->flags |= FLAGS_WAITAUTH)
#define ClearWaitAuth(x)        ((x)->flags &= ~FLAGS_WAITAUTH)
#define HasServlink(x)          ((x)->flags &  FLAGS_SERVLINK)
#define SetServlink(x)          ((x)->flags |= FLAGS_SERVLINK)
#define MyConnect(x)            ((x)->localClient != NULL)
#define MyClient(x)             (MyConnect(x) && IsClient(x))
#define SetMark(x)		((x)->flags |= FLAGS_MARK)
#define ClearMark(x)		((x)->flags &= ~FLAGS_MARK)
#define IsMarked(x)		((x)->flags & FLAGS_MARK)

#define IsService(x)            ((x)->flags & FLAGS_SERVICE)
#define SetService(x)           ((x)->flags |= FLAGS_SERVICE)
#define SetCanFlood(x)          ((x)->flags |= FLAGS_CANFLOOD)
#define ClearCanFlood(x)        ((x)->flags &= FLAGS_CANFLOOD)
#define IsCanFlood(x)           ((x)->flags & FLAGS_CANFLOOD)
#define IsDefunct(x)            ((x)->flags & (FLAGS_DEADSOCKET|FLAGS_CLOSING))


/* oper flags */
#define MyOper(x)               (MyConnect(x) && IsOper(x))

#define SetOper(x)              {(x)->umodes |= FLAGS_OPER; \
				 if (!IsServer((x))) (x)->handler = OPER_HANDLER;}

#define ClearOper(x)            {(x)->umodes &= ~(FLAGS_OPER|FLAGS_ADMIN); \
				 if (!IsOper((x)) && !IsServer((x))) \
				  (x)->handler = CLIENT_HANDLER; }

#define IsPrivileged(x)         (IsOper(x) || IsServer(x))
#define IsGod(x)                ((x)->umodes & FLAGS_GOD)
#define IsNickServReg(x)        ((x)->umodes & FLAGS_NICKSERVREG)
/* umode flags */
#define IsInvisible(x)          ((x)->umodes & FLAGS_INVISIBLE)
#define SetInvisible(x)         ((x)->umodes |= FLAGS_INVISIBLE)
#define ClearInvisible(x)       ((x)->umodes &= ~FLAGS_INVISIBLE)
#define SendWallops(x)          ((x)->umodes & FLAGS_WALLOP)
#define ClearWallops(x)         ((x)->umodes &= ~FLAGS_WALLOP)
#define SendLocops(x)           ((x)->umodes & FLAGS_LOCOPS)
#define SendServNotice(x)       ((x)->umodes & FLAGS_SERVNOTICE)
#define SendOperwall(x)         ((x)->umodes & FLAGS_OPERWALL)
#define SendCConnNotice(x)      ((x)->umodes & FLAGS_CCONN)
#define SendRejNotice(x)        ((x)->umodes & FLAGS_REJ)
#define SendSkillNotice(x)      ((x)->umodes & FLAGS_SKILL)
#define SendFullNotice(x)       ((x)->umodes & FLAGS_FULL)
#define SendSpyNotice(x)        ((x)->umodes & FLAGS_SPY)
#define SendDebugNotice(x)      ((x)->umodes & FLAGS_DEBUG)
#define SendNickChange(x)       ((x)->umodes & FLAGS_NCHANGE)
#define SetWallops(x)           ((x)->umodes |= FLAGS_WALLOP)
#define SetCallerId(x)		((x)->umodes |= FLAGS_CALLERID)
#define SetNickServReg(x)   ((x)->umodes |= FLAGS_NICKSERVREG)
#define ClearNickServReg(x) ((x)->umodes &= ~FLAGS_NICKSERVREG)
#define IsSetCallerId(x)	((x)->umodes & FLAGS_CALLERID)

#define SetIpHash(x)            ((x)->flags |= FLAGS_IPHASH)
#define ClearIpHash(x)          ((x)->flags &= ~FLAGS_IPHASH)
#define IsIpHash(x)             ((x)->flags & FLAGS_IPHASH)

#define SetNeedId(x)            ((x)->flags |= FLAGS_NEEDID)
#define IsNeedId(x)             (((x)->flags & FLAGS_NEEDID) != 0)

#define SetGotId(x)             ((x)->flags |= FLAGS_GOTID)
#define IsGotId(x)              (((x)->flags & FLAGS_GOTID) != 0)

/*
 * flags2 macros.
 */
#define IsExemptKline(x)        ((x)->flags2 & FLAGS2_EXEMPTKLINE)
#define SetExemptKline(x)       ((x)->flags2 |= FLAGS2_EXEMPTKLINE)
#define IsExemptLimits(x)       ((x)->flags2 & FLAGS2_NOLIMIT)
#define SetExemptLimits(x)      ((x)->flags2 |= FLAGS2_NOLIMIT)
#define IsExemptGline(x)        ((x)->flags2 & FLAGS2_EXEMPTGLINE)
#define SetExemptGline(x)       ((x)->flags2 |= FLAGS2_EXEMPTGLINE)
#define SetIPSpoof(x)           ((x)->flags2 |= FLAGS2_IP_SPOOFING)
#define IsIPSpoof(x)            ((x)->flags2 & FLAGS2_IP_SPOOFING)

#define SetIdlelined(x)         ((x)->flags2 |= FLAGS2_IDLE_LINED)
#define IsIdlelined(x)          ((x)->flags2 & FLAGS2_IDLE_LINED)

#define IsRestricted(x)         ((x)->flags2 &  FLAGS2_RESTRICTED)
#define SetRestricted(x)        ((x)->flags2 |= FLAGS2_RESTRICTED)

#define IsOperGlobalKill(x)     ((x)->flags2 & FLAGS2_OPER_GLOBAL_KILL)
#define SetOperGlobalKill(x)    ((x)->flags2 |= FLAGS2_OPER_GLOBAL_KILL)
#define IsOperRemote(x)         ((x)->flags2 & FLAGS2_OPER_REMOTE)
#define SetOperRemote(x)        ((x)->flags2 |= FLAGS2_OPER_REMOTE)
#define IsOperUnkline(x)        ((x)->flags2 & FLAGS2_OPER_UNKLINE)
#define SetOperUnkline(x)       ((x)->flags2 |= FLAGS2_OPER_UNKLINE)
#define IsOperGline(x)          ((x)->flags2 & FLAGS2_OPER_GLINE)
#define SetOperGline(x)         ((x)->flags2 |= FLAGS2_OPER_GLINE)
#define IsOperN(x)              ((x)->flags2 & FLAGS2_OPER_N)
#define SetOperN(x)             ((x)->flags2 |= FLAGS2_OPER_N)
#define IsOperK(x)              ((x)->flags2 & FLAGS2_OPER_K)
#define SetOperK(x)             ((x)->flags2 |= FLAGS2_OPER_K)
#define IsOperDie(x)            ((x)->flags2 & FLAGS2_OPER_DIE)
#define SetOperDie(x)           ((x)->flags2 |= FLAGS2_OPER_DIE)
#define IsOperRehash(x)         ((x)->flags2 & FLAGS2_OPER_REHASH)
#define SetOperRehash(x)        ((x)->flags2 |= FLAGS2_OPER_REHASH)
#define IsOperAdmin(x)          ((x)->flags2 & FLAGS2_OPER_ADMIN)
#define SetOperAdmin(x)         ((x)->flags2 |= FLAGS2_OPER_ADMIN)

#define IsFloodDone(x)          ((x)->flags2 & FLAGS2_FLOODDONE)
#define SetFloodDone(x)         ((x)->flags2 |= FLAGS2_FLOODDONE)
#define CBurst(x)               ((x)->flags2 & FLAGS2_CBURST)

/*
 * definitions for get_client_name
 */
#define HIDE_IP 0
#define SHOW_IP 1
#define MASK_IP 2

extern void           check_klines(void);
extern const char*    get_client_name(struct Client* client, int show_ip);
extern void           init_client(void);
extern struct Client* make_client(struct Client* from);
extern void           free_client(struct Client* client);
extern void           add_client_to_list(struct Client* client);
extern void           remove_client_from_list(struct Client *);
extern void           add_client_to_llist(struct Client** list, 
                                          struct Client* client);
extern void           del_client_from_llist(struct Client** list, 
                                            struct Client* client);
extern int            exit_client(struct Client*, struct Client*, 
                                  struct Client*, const char*);


extern void     count_local_client_memory(int *count, int *memory);
extern void     count_remote_client_memory(int *count, int *memory);

extern struct Client* find_chasing (struct Client *, char *, int *);
extern struct Client* find_person (char *);
extern struct Client* next_client (struct Client *, const char *);
extern int accept_message(struct Client *source, struct Client *target);
extern void del_from_accept(struct Client *source, struct Client *target);
extern void del_all_accepts(struct Client *client_p);

extern int set_initial_nick(struct Client *client_p, struct Client *source_p,
                            char *nick);
extern int change_local_nick(struct Client *client_p, struct Client *source_p,
                             char *nick);
extern void dead_link(struct Client *client_p);
extern void exit_aborted_clients(void);
#endif /* INCLUDED_client_h */

