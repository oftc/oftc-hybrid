/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd.h: A header for the ircd startup routines.
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

#ifndef INCLUDED_ircd_h
#define INCLUDED_ircd_h

#include "ircd_defs.h"
#include "memory.h"
#include "list.h"

struct Client;

struct SetOptions
{
  int autoconn;      /* autoconn enabled for all servers? */
  int floodcount;    /* Number of messages in 1 second    */
  int joinfloodtime;
  int joinfloodcount;
  int ident_timeout; /* timeout for identd lookups        */
  int spam_num;
  int spam_time;
};

/*
 * statistics structures
 */
struct ServerStatistics
{
  uint64_t        is_cbs;  /* bytes sent to clients */
  uint64_t        is_cbr;  /* bytes received from clients */
  uint64_t        is_sbs;  /* bytes sent to servers */
  uint64_t        is_sbr;  /* bytes received from servers */

  time_t          is_cti;  /* time spent connected by clients */
  time_t          is_sti;  /* time spent connected by servers */

  unsigned int    is_cl;   /* number of client connections */
  unsigned int    is_sv;   /* number of server connections */
  unsigned int    is_ni;   /* connection but no idea who it was */
  unsigned int    is_ac;   /* connections accepted */
  unsigned int    is_ref;  /* accepts refused */
  unsigned int    is_unco; /* unknown commands */
  unsigned int    is_wrdi; /* command going in wrong direction */
  unsigned int    is_unpf; /* unknown prefix */
  unsigned int    is_empt; /* empty message */
  unsigned int    is_num;  /* numeric message */
  unsigned int    is_kill; /* number of kills generated on collisions */
  unsigned int    is_asuc; /* successful auth requests */
  unsigned int    is_abad; /* bad auth requests */
};

IRCD_EXTERN struct ServerStatistics ServerStats;


struct Counter
{
  uint64_t      totalrestartcount;  /* Total client count ever */
  unsigned int  myserver;           /* my servers          */
  unsigned int  oper;               /* Opers               */
  unsigned int  local;              /* Local Clients       */
  unsigned int  total;              /* total clients       */
  unsigned int  invisi;             /* invisible clients   */
  unsigned int  max_loc;            /* MAX local clients   */
  unsigned int  max_tot;            /* MAX global clients  */
  unsigned int  max_loc_con;        /* MAX local connection count (clients + server) */
  unsigned int  max_loc_cli;        /* XXX This is redundant - Max local client count */
};

IRCD_EXTERN struct SetOptions GlobalSetOptions; /* defined in ircd.c */

struct ServerState_t
{
  int       foreground;
  uv_loop_t *event_loop;
};

IRCD_EXTERN struct ServerState_t server_state;

IRCD_EXTERN char **myargv;
IRCD_EXTERN const char *infotext[];
IRCD_EXTERN const char *serno;
IRCD_EXTERN const char *ircd_version;
IRCD_EXTERN const char *logFileName;
IRCD_EXTERN const char *pidFileName;
IRCD_EXTERN int dorehash;
IRCD_EXTERN int doremotd;
IRCD_EXTERN struct Counter Count;
IRCD_EXTERN struct timeval SystemTime;
#define CurrentTime SystemTime.tv_sec
IRCD_EXTERN int default_server_capabs;
IRCD_EXTERN unsigned int splitmode;
IRCD_EXTERN unsigned int splitchecking;
IRCD_EXTERN unsigned int split_users;
IRCD_EXTERN unsigned int split_servers;

IRCD_EXTERN dlink_list
unknown_list;       /* unknown clients ON this server only        */
IRCD_EXTERN dlink_list
local_client_list;  /* local clients only ON this server          */
IRCD_EXTERN dlink_list
serv_list;          /* local servers to this server ONLY          */
IRCD_EXTERN dlink_list
global_serv_list;   /* global servers on the network              */
IRCD_EXTERN dlink_list
oper_list;          /* our opers, duplicated in local_client_list */
IRCD_EXTERN int rehashed_klines;
#endif
