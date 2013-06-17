/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  resv.h: A header for the RESV functions.
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

struct ResvChannel
{
  dlink_node          node;
  struct ResvChannel  *hnext;
  time_t              hold;          /* Hold action until this time (calendar time) */
  /* +1 for \0 */
  char                name[CHANNELLEN + 1];
  char                *reason;
  int                 conf;    /* 1 if set from ircd.conf, 0 if from elsewhere */
  int                 count; /* How many times this item has been matched */
};

IRCD_EXTERN dlink_list nresv_items;
IRCD_EXTERN dlink_list resv_channel_list;

IRCD_EXTERN struct ConfItem *create_channel_resv(char *, char *, int);
IRCD_EXTERN struct ConfItem *create_nick_resv(char *, char *, int);

IRCD_EXTERN int delete_channel_resv(struct ResvChannel *);

IRCD_EXTERN void clear_conf_resv();
IRCD_EXTERN void report_resv(struct Client *);

IRCD_EXTERN int valid_wild_card_simple(const char *);
IRCD_EXTERN struct ResvChannel *match_find_resv(const char *);
#endif  /* INCLUDED_resv_h */
