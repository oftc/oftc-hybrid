/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  parse.h: A header for the message parser.
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

#ifndef INCLUDED_parse_h_h
#define INCLUDED_parse_h_h

struct Message;
struct Client;

struct MessageHash
{
  char   *cmd;
  struct Message      *msg;
  struct MessageHash  *next;
}; 

#define MAX_MSG_HASH  387

extern  void    parse (struct Client *, char *, char *);
extern  void    clear_hash_parse (void);
extern  void    mod_add_cmd(struct Message *msg);
extern  void    mod_del_cmd(struct Message *msg);
extern  void    report_messages(struct Client *);
extern void list_commands(struct Client *);

#endif /* INCLUDED_parse_h_h */
