/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_stats.h: A header for the statistics functions.
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

#ifndef INCLUDED_s_stats_h
#define INCLUDED_s_stats_h

struct Client;

/*
 * statistics structures
 */
struct  ServerStatistics {

  /* These are trivially derived from dlink_list_length */
  unsigned int    is_cl;  /* number of client connections */
  unsigned int    is_sv;  /* number of server connections */
  unsigned int    is_ni;  /* connection but no idea who it was */

  unsigned short  is_cbs; /* bytes sent to clients */
  unsigned short  is_cbr; /* bytes received to clients */
  unsigned short  is_sbs; /* bytes sent to servers */
  unsigned short  is_sbr; /* bytes received to servers */
  unsigned long   is_cks; /* k-bytes sent to clients */
  unsigned long   is_ckr; /* k-bytes received to clients */
  unsigned long   is_sks; /* k-bytes sent to servers */
  unsigned long   is_skr; /* k-bytes received to servers */
  time_t          is_cti; /* time spent connected by clients */
  time_t          is_sti; /* time spent connected by servers */
  unsigned int    is_ac;  /* connections accepted */
  unsigned int    is_ref; /* accepts refused */
  unsigned int    is_unco; /* unknown commands */
  unsigned int    is_wrdi; /* command going in wrong direction */
  unsigned int    is_unpf; /* unknown prefix */
  unsigned int    is_empt; /* empty message */
  unsigned int    is_num; /* numeric message */
  unsigned int    is_kill; /* number of kills generated on collisions */
  unsigned int    is_asuc; /* successful auth requests */
  unsigned int    is_abad; /* bad auth requests */
};

extern struct ServerStatistics* ServerStats;

extern void init_stats(void);
extern void tstats(struct Client* client);

#endif /* INCLUDED_s_stats_h */
