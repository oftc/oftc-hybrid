/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  restart.h: A header for the restart functions.
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

#ifndef INCLUDED_resv_h
#define INCLUDED_resv_h

/* allows resv *nicknick* etc */
#define RESVNICKLEN NICKLEN*2

struct ResvChannel
{
  struct ResvChannel *next;
  struct ResvChannel *prev;
  struct ResvChannel *hnext;

  /* +1 for \0 */
  char	name[CHANNELLEN + 1];
  char	*reason;
  int	conf;
};

struct ResvNick
{
  struct ResvNick *next;
  struct ResvNick *prev;

  char	name[RESVNICKLEN];
  char	*reason;
  int	conf;
};

extern struct ResvChannel *ResvChannelList;
extern struct ResvNick *ResvNickList;

extern struct ResvChannel *create_channel_resv(char *, char *, int);
extern struct ResvNick *create_nick_resv(char *, char *, int);

extern int delete_channel_resv(struct ResvChannel *);
extern int delete_nick_resv(struct ResvNick *);

extern int clear_conf_resv();

extern int find_channel_resv(char *);
extern int find_nick_resv(char *);

extern void report_resv(struct Client *);
extern struct ResvNick *return_nick_resv(char *);

extern int clean_resv_nick(char *);

#endif  /* INCLUDED_hash_h */



