/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  modules.h: A header for the modules functions.
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

#ifndef INCLUDED_modules_h
#define INCLUDED_modules_h
#include "config.h"
#include "setup.h"
#include "parse.h"


#if defined(HAVE_SHL_LOAD)
#include <dl.h>
#endif
#if !defined(STATIC_MODULES) && defined(HAVE_DLFCN_H)
#include <dlfcn.h>
#endif

#include "ircd_handler.h"
#include "msg.h"
#include "memory.h"

#ifndef STATIC_MODULES
struct module {
  char *name;
  char *version;
  void *address;
  int core;
};

struct module_path
{
	char path[MAXPATHLEN];
};

/* add a path */
void mod_add_path(char *path);
void mod_clear_paths(void);

/* load a module */
extern void load_module(char *path);

/* load all modules */
extern void load_all_modules(int warn);

/* load core modules */
extern void load_core_modules(int);

extern void _modinit(void);
extern void _moddeinit(void);

extern int unload_one_module (char *, int);
extern int load_one_module (char *);
extern int load_a_module (char *, int, int);
extern int findmodule_byname (char *);
extern char* irc_basename(char *);
extern void modules_init(void);

#else /* STATIC_MODULES */

extern struct Message accept_msgtab;
extern struct Message admin_msgtab;
extern struct Message away_msgtab;
extern struct Message capab_msgtab;
extern struct Message cburst_msgtab;
#ifdef HAVE_LIBCRYPTO
extern struct Message challenge_msgtab;
extern struct Message cryptlink_msgtab;
#endif
extern struct Message cjoin_msgtab;
extern struct Message client_msgtab;
extern struct Message close_msgtab;
extern struct Message connect_msgtab;
extern struct Message die_msgtab;
extern struct Message dmem_msgtab;
extern struct Message drop_msgtab;
extern struct Message eob_msgtab;
extern struct Message error_msgtab;
extern struct Message gline_msgtab;
extern struct Message help_msgtab;
extern struct Message info_msgtab;
extern struct Message invite_msgtab;
extern struct Message ison_msgtab;
extern struct Message join_msgtab;
extern struct Message kick_msgtab;
extern struct Message kill_msgtab;
extern struct Message kline_msgtab;
extern struct Message dline_msgtab;
extern struct Message knock_msgtab;
extern struct Message knockll_msgtab;
extern struct Message links_msgtab;
extern struct Message list_msgtab;
extern struct Message lljoin_msgtab;
extern struct Message llnick_msgtab;
extern struct Message locops_msgtab;
extern struct Message lusers_msgtab;
extern struct Message privmsg_msgtab;
extern struct Message notice_msgtab;
extern struct Message mode_msgtab;
extern struct Message motd_msgtab;
extern struct Message names_msgtab;
extern struct Message nburst_msgtab;
extern struct Message nick_msgtab;
extern struct Message oper_msgtab;
extern struct Message operwall_msgtab;
extern struct Message part_msgtab;
extern struct Message pass_msgtab;
extern struct Message ping_msgtab;
extern struct Message pong_msgtab;
extern struct Message post_msgtab;
extern struct Message quit_msgtab;
extern struct Message rehash_msgtab;
extern struct Message restart_msgtab;
extern struct Message resv_msgtab;
extern struct Message server_msgtab;
extern struct Message set_msgtab;
extern struct Message sjoin_msgtab;
extern struct Message squit_msgtab;
extern struct Message stats_msgtab;
extern struct Message svinfo_msgtab;
extern struct Message testline_msgtab;
extern struct Message time_msgtab;
extern struct Message topic_msgtab;
extern struct Message trace_msgtab;
extern struct Message msgtabs[];
extern struct Message unresv_msgtab;
extern struct Message user_msgtab;
extern struct Message userhost_msgtab;
extern struct Message users_msgtab;
extern struct Message version_msgtab;
extern struct Message wallops_msgtab;
extern struct Message who_msgtab;
extern struct Message whois_msgtab;
extern struct Message whowas_msgtab;
extern struct Message get_msgtab;
extern struct Message put_msgtab;
extern void load_all_modules(int check);

#endif /* STATIC_MODULES */
#endif /* INCLUDED_modules_h */
