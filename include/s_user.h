/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_user.h: A header for the user functions.
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

#ifndef INCLUDED_s_user_h
#define INCLUDED_s_user_h

#include "config.h"

struct Client;
extern time_t LastUsedWallops;


extern int   user_mode(struct Client* , struct Client* , int, char** );
extern void  send_umode (struct Client* , struct Client* ,
                         int, int, char* );
extern void  send_umode_out(struct Client* , struct Client* , int);
extern int   show_lusers(struct Client* source_p);
extern int   register_local_user(struct Client* ,struct Client* ,
				 char* ,char* );
extern int   register_remote_user(struct Client* ,struct Client* ,
				  char* ,char* );
extern int   do_local_user(char* ,struct Client* ,struct Client*,
			   char* ,char *,char *,char *);

extern int   do_remote_user(char* ,struct Client* ,struct Client*,
			    char* ,char *,char *,char *,char *);

extern int   user_modes_from_c_to_bitmask[];
extern void  show_isupport(struct Client *);


#endif
