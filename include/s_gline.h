/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_gline.h: A header for the gline functions.
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
 *  $Id: s_gline.h 588 2006-05-29 18:45:22Z stu $
 */

#ifndef INCLUDED_s_gline_h
#define INCLUDED_s_gline_h

#include "ircd_defs.h"

struct AccessItem;

extern void cleanup_glines(void *);
extern struct AccessItem *find_is_glined(const char *, const char *);

struct gline_pending
{
  dlink_node node;

  char oper_nick1[NICKLEN + 1];
  char oper_user1[USERLEN + 1];
  char oper_host1[HOSTLEN + 1];
  char oper_server1[HOSTLEN + 1];
  char reason1[REASONLEN + 1];
  time_t time_request1;

  char oper_nick2[NICKLEN + 1];
  char oper_user2[USERLEN + 1];
  char oper_host2[HOSTLEN + 1];
  char oper_server2[HOSTLEN + 1];
  char reason2[REASONLEN + 1];
  time_t time_request2;

  time_t last_gline_time;       /* for expiring entry */
  char user[USERLEN * 2 + 2];
  char host[HOSTLEN * 2 + 2];
};

/*
 * how long a pending G line can be around
 * 10 minutes should be plenty
 */
#define GLINE_PENDING_EXPIRE 600
#define CLEANUP_GLINES_TIME  300

extern dlink_list pending_glines;
#endif /* INCLUDED_s_gline_h */
