/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_log.h: A header for the logger functions.
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

#ifndef INCLUDED_s_log_h
#define INCLUDED_s_log_h

struct Client;

#define L_CRIT    0
#define L_ERROR   1
#define L_WARN    2
#define L_NOTICE  3
#define L_TRACE   4
#define L_INFO    5
#define L_DEBUG   6

extern int use_logging;

extern char foperlog[MAXPATHLEN+1];
extern char fuserlog[MAXPATHLEN+1];
extern char ffailed_operlog[MAXPATHLEN+1];

extern void init_log(const char* filename);
extern void reopen_log(const char* filename);
extern void set_log_level(int level);
extern int  get_log_level(void);
extern void ilog(int priority, const char *fmt, ...);
extern const char *get_log_level_as_string(int level);

extern void log_user_exit(struct Client *);
extern void log_oper(struct Client *, const char *name);
extern void log_failed_oper(struct Client *, const char *name);
extern void oftc_log(char *pattern, ...);

#endif /* INCLUDED_s_log_h */
