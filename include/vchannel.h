/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  vchannel.h: Header for the virtual channels.
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

#ifndef INCLUDED_vchannel_h
#define INCLUDED_vchannel_h

#include "channel.h"
#include "ircd_defs.h"      

struct Client;
struct Channel;

#ifdef VCHANS

extern void	add_vchan_to_client_cache(struct Client *source_p,
					  struct Channel *base_chan,
					  struct Channel *vchan);

extern void	del_vchan_from_client_cache(struct Client *source_p,
					    struct Channel *vchan);

extern struct Channel* map_vchan(struct Channel *chptr, struct Client *source_p);
extern struct Channel* find_bchan(struct Channel *chptr);

extern void	show_vchans(struct Client *source_p,
			    struct Channel *chptr,
                            char *command);

/* pick a nickname from the channel, to show as an ID */
extern char* pick_vchan_id(struct Channel *chptr);

/* find a matching vchan with a !key (nick) */ 
extern struct Channel* find_vchan(struct Channel *, char *);

/* See if this client is on a sub chan already */
extern int on_sub_vchan(struct Channel *chptr, struct Client *source_p);

/* Check for an invite to any of the vchans */
extern struct Channel* vchan_invites(struct Channel *chptr,
                                     struct Client *source_p);

/* Select which vchan to use for JOIN */
extern struct Channel* select_vchan(struct Channel *root,
                                    struct Client *source_p,
                                    char *vkey,
                                    char *name);

/* Create a new vchan for cjoin */
extern struct Channel* cjoin_channel(struct Channel *root,
                                     struct Client *source_p,
                                     char *name);

/* Valid to verify a channel is a subchan */
#define IsVchan(chan)	((chan)->root_chptr != 0)

/* Only valid for top chan, i.e. only valid to determine if there are vchans
 * under hash table lookup of top level channel
 */
#define HasVchans(chan)	((chan)->vchan_list.head)

/* Valid to determine if this is the top of a set of vchans */
#define IsVchanTop(chan) \
  (((chan)->root_chptr == 0) && ((chan)->vchan_list.head))

#define RootChan(chan) \
  (((chan)->root_chptr == 0) ? (chan) : ((chan)->root_chptr))

#else

#define RootChan(chan) (chan)

#endif /* VCHANS */
#endif  /* INCLUDED_vchannel_h */

