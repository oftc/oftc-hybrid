/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  list.h: A header for the code in list.c.
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

#ifndef INCLUDED_list_h
#define INCLUDED_list_h
#include "memory.h"

struct dlink_node;
struct Client;
struct Class;
struct User;
struct Channel;
struct ConfItem;
struct Ban;

extern void initUser(void);
extern void count_user_memory(int *count,int *user_memory_used);
extern void count_links_memory(int *count,int *links_memory_used);
extern void outofmemory(void);
extern void free_user (struct User *, struct Client *);
extern dlink_node *make_dlink_node (void);
extern void free_dlink_node(dlink_node *lp);
extern void init_dlink_nodes();

extern struct User     *make_user (struct Client *);
extern struct Server   *make_server (struct Client *);

#endif
