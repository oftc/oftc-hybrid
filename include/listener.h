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

#include "ircd_defs.h"  

struct Client;

struct Listener {
  struct Listener* next;               /* list node pointer */
  const char*      name;               /* listener name */
  int              fd;                 /* file descriptor */
  int              port;               /* listener IP port */
  int              ref_count;          /* number of connection references */
  int              active;             /* current state of listener */
  int              index;              /* index into poll array */
  time_t           last_accept;        /* last time listener accepted */
/* jdc -- this seems to be incorrect in comparison to src/listener.c */
/*
  struct in_addr    addr;
*/
  struct irc_inaddr addr;              /* virtual address or INADDR_ANY */
  struct DNSQuery   *dns_query;
  char             vhost[HOSTLEN + 1]; /* virtual name of listener */
};

extern void        add_listener(int port, const char* vaddr_ip);
extern void        close_listener(struct Listener* listener);
extern void        close_listeners(void);
extern const char* get_listener_name(const struct Listener* listener);
extern void        show_ports(struct Client* client);
extern void free_listener(struct Listener * );

#endif /* INCLUDED_listener_h */
