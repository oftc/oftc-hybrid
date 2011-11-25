/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  listener.h: A header for the listener code.
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

#ifndef INCLUDED_listener_h
#define INCLUDED_listener_h

#define LISTENER_SSL    0x1
#define LISTENER_HIDDEN 0x2
#define LISTENER_SERVER 0x4
#define LISTENER_WEBSOCKET 0x8

#include "ircd_defs.h"  
#include "tools.h"
#include "fdlist.h"

struct Client;

struct libwebsocket_context;
#define IsWebsocket(x) ((x)->flags & LISTENER_WEBSOCKET)

struct Listener
{
  dlink_node	   listener_node;      /* list node pointer */
  const char*      name;               /* listener name */
  fde_t            fd;                 /* file descriptor */
  int              port;               /* listener IP port */
  int              ref_count;          /* number of connection references */
  int              active;             /* current state of listener */
  struct irc_ssaddr addr;              /* virtual address or INADDR_ANY */
  char              vhost[HOSTLEN + 1]; /* virtual name of listener */
  unsigned int      flags;
  struct libwebsocket_context *wsc;   /* Websocket Context */
};

extern void add_listener(int, const char *, unsigned int);
extern void close_listeners(void);
extern const char *get_listener_name(const struct Listener *);
extern void show_ports(struct Client *);
extern void free_listener(struct Listener *);
struct Listener *find_listener(int port, struct irc_ssaddr *addr);
extern dlink_list ListenerPollList;
#endif /* INCLUDED_listener_h */
