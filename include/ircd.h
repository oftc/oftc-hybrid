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

#include "config.h"
#include "tools.h"
#include "memory.h"

struct Client;
struct dlink_list;

struct SetOptions
{
  int maxclients;       /* max clients allowed */
  int autoconn;         /* autoconn enabled for all servers? */

  int idletime;

  int floodcount;	/* Number of messages in 1 second */
  int ident_timeout;     /* timeout for identd lookups */

  int spam_num;
  int spam_time;
};

struct Counter {
  int     server;         /* servers */
  int     myserver;       /* my servers */
  int     oper;           /* Opers */
  int     chan;           /* Channels */
  int     local;          /* Local Clients */
  int     total;          /* total clients */
  int     invisi;         /* invisible clients */
  int     unknown;        /* unknown connections */
  int     max_loc;        /* MAX local clients */
  int     max_tot;        /* MAX global clients */
  unsigned long totalrestartcount; /* Total client count ever */
};

extern struct SetOptions GlobalSetOptions;  /* defined in ircd.c */

struct ServerState_t {
  int     foreground;
};

extern struct ServerState_t server_state;

extern char*          debugmode;
extern int            debuglevel;
extern int            debugtty;
extern char*          creation;
extern char*          generation;
extern char*          platform;
extern char*          infotext[];
extern char*          serno;
extern char*          ircd_version;
extern const char*    logFileName;
extern const char     serveropts[];
extern int            cold_start;
extern int            dorehash;
extern struct Client  me;
extern struct Client* GlobalClientList;
extern struct Client* local[];
extern struct Counter Count;
#if 0
extern time_t         CurrentTime;
#endif
extern struct timeval SystemTime;
#define CurrentTime SystemTime.tv_sec
extern time_t         nextconnect;
extern int            default_server_capabs;

extern int splitmode;
extern int splitchecking;
extern int split_users;
extern int split_servers;

extern dlink_list unknown_list;
extern dlink_list lclient_list;
extern dlink_list serv_list;
extern dlink_list global_serv_list;
extern dlink_list oper_list;
extern dlink_list dead_list;
extern dlink_list abort_list;
extern dlink_list lazylink_channels;
extern int callbacks_called;

extern unsigned long get_maxrss(void);
extern void set_time(void);

#endif
