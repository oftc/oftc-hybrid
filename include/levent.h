/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
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
 *  $Id: event.h 33 2005-10-02 20:50:00Z knight $
 */

#ifndef INCLUDED_levent_h
#define INCLUDED_levent_h

#include "event.h"

struct DNSReply
{
  char *h_name;
  struct irc_ssaddr addr;
};

struct DNSQuery
{
  void *ptr; /* pointer used by callback to identify request */
  void (*callback)(void* vptr, struct DNSReply *reply); /* callback to call */
  void *dnsptr;
  int aftype;
};

extern void levent_init();
extern void levent_add(fde_t *, unsigned int, PF *, void *, time_t);
extern void levent_loop();
extern void levent_timer_add(struct ev_entry *);
extern void levent_timer_del(struct ev_entry *);
extern void *levent_timer_add_generic(const struct timeval *, void (*)(int, short, void*), void *);
extern void levent_timer_del_generic(void *);
extern void restart_resolver();
extern void gethost_byaddr(const struct irc_ssaddr *, struct DNSQuery *);
extern void gethost_byname(const char *, struct DNSQuery *);
extern void gethost_byname_type(const char *, struct DNSQuery *, int);

#endif /* INCLUDED_levent_h */
