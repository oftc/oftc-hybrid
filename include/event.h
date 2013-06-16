/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  event.h: The ircd event header.
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

#ifndef INCLUDED_event_h
#define INCLUDED_event_h

/* The list of event processes */
struct ev_entry
{
  uv_timer_cb func;
  uv_timer_t  handle;
  dlink_node  node;
};

extern void eventAdd(const char *, uv_timer_cb, void *, time_t);
extern void eventAddIsh(const char *, uv_timer_cb, void *, time_t);
extern void eventInit();
extern void eventDelete(uv_timer_cb, void *);

#endif /* INCLUDED_event_h */
