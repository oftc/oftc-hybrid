/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  channel.h: The ircd channel header.
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

#ifndef INCLUDED_channel_h
#define INCLUDED_channel_h

#include "ircd_defs.h"        /* buffer sizes */
#include "tools.h"

struct Client;

/* mode structure for channels */

struct Mode
{
  unsigned int mode;
  int limit;
  char key[KEYLEN];
};

/* channel structure */
struct Channel
{
  dlink_node node;

  struct Channel *hnextch;

  struct Mode mode;
  char *topic;
  char *topic_info;
  time_t topic_time;
  unsigned long lazyLinkChannelExists;
  time_t last_knock; /* don't allow knock to flood */

  dlink_list members;
  dlink_list locmembers;  /* local members are here too */
  dlink_list invites;
  dlink_list banlist;
  dlink_list exceptlist;
  dlink_list invexlist;

  time_t first_received_message_time; /* channel flood control */
  int received_number_of_privmsgs;
  char flood_noticed;

  time_t channelts;
  char chname[CHANNELLEN + 1];
};

struct Membership
{
  dlink_node channode;    /* link to chptr->members          */
  dlink_node locchannode; /* link to chptr->locmembers       */
  dlink_node usernode;    /* link to source_p->user->channel */
  struct Channel *chptr;
  struct Client *client_p;
  unsigned int flags;
};

extern dlink_list global_channel_list;

extern void init_channels(void);
extern int can_send (struct Channel *chptr, struct Client *who);
extern int can_send_part(struct Membership *, struct Channel *, struct Client *);
extern int is_banned (struct Channel *chptr, struct Client *who);
extern int can_join(struct Client *source_p, struct Channel *chptr,
                    const char *key);
extern int has_member_flags(struct Membership *ms, unsigned int flags);
extern void add_user_to_channel(struct Channel *chptr, struct Client *who,
                                unsigned int flags);
extern void remove_user_from_channel(struct Membership *);
extern int check_channel_name(const char *name);
extern void channel_member_names(struct Client *source_p, struct Channel *chptr,
                                 int show_eon);
extern const char *get_member_status(struct Membership *, int);
extern void add_invite(struct Channel *chptr, struct Client *who);
extern void del_invite(struct Channel *chptr, struct Client *who);
extern void send_channel_modes (struct Client *, struct Channel *);
extern void channel_modes(struct Channel *, struct Client *, char *, char *);

extern void check_spambot_warning(struct Client *source_p, const char *name);
extern void check_splitmode(void *);
extern void free_channel_list(dlink_list *);

/*
** Channel Related macros follow
*/

/* channel visible */
#define ShowChannel(v,c)        (PubChannel(c) || IsMember((v),(c)))

#define IsMember(who, chan) ((who && who->user && \
                 find_channel_link(who, chan)) ? 1 : 0)
#define AddMemberFlag(x, y) ((x)->flags |=  (y))
#define DelMemberFlag(x, y) ((x)->flags &= ~(y))

#define IsChannelName(name) ((name) && (*(name) == '#' || *(name) == '&'))

struct Ban          /* also used for exceptions -orabidoo */
{
  dlink_node node;
  char *banstr;
  char *who;
  time_t when;
};

extern struct Membership *find_channel_link(struct Client *client_p,
                                            struct Channel *chptr);
extern void set_channel_topic(struct Channel *chptr, const char *topic,
                              const char *topic_info, time_t topicts); 
extern void free_topic(struct Channel *);
extern int msg_has_colors(char*);
extern char *strip_color(char *);
#endif  /* INCLUDED_channel_h */
