/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hook.h: A header for the hooks into parts of ircd.
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

#ifndef __HOOK_H_INCLUDED
#define __HOOK_H_INCLUDED

#include "tools.h"


typedef struct
{
	char *name;
	dlink_list hooks;
} hook;

/* we don't define the arguments to hookfn, because they can
   vary between different hooks */
typedef int (*hookfn)(void *data);

/* this is used when a hook is called by an m_function
   stand data you'd need in that situation */
struct hook_mfunc_data 
{
	struct Client *client_p;
	struct Client *source_p;
	int parc;
	char **parv;
};

struct hook_stats_data 
{
	struct Client *source_p;
	char statchar;
	char *name;
};

struct hook_links_data
{
	struct Client *client_p;
	struct Client *source_p;
	int parc;
	char **parv;
	char statchar;
	char *mask;
};

struct hook_spy_data
{
	struct Client *source_p;
};

struct hook_io_data
{
        struct Client *connection;
        char *data;
        unsigned int len;
};

struct hook_burst_channel
{
	struct Client *client;
	struct Channel *chptr;
};


int hook_add_event(char *);
int hook_add_hook(char *, hookfn *);
int hook_call_event(char *, void *);
int hook_del_event(char *);
int hook_del_hook(char *event, hookfn *fn);
void init_hooks(void);

#endif
