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
#include "config.h"           /* config settings */
#include "ircd_defs.h"        /* buffer sizes */

/* Efnet wanted this... Maybe we should do this from configure? */
#define REQUIRE_OANDV

/* #define INTENSIVE_DEBUG */

struct Client;

/* mode structure for channels */

struct Mode
{
  unsigned int  mode;
  int   limit;
  char  key[KEYLEN];
};

/* channel structure */

struct Channel
{
  struct Channel* nextch;
  struct Channel* prevch;
  struct Channel* hnextch;
  struct Mode     mode;
  char            *topic;
  char            *topic_info;
  time_t          topic_time;
#ifdef VCHANS
  char            vchan_id[NICKLEN*2];   /* use this for empty vchans */
#endif
  int             users;      /* user count */
  int             locusers;   /* local user count */
  unsigned long   lazyLinkChannelExists;
  time_t          last_knock;           /* don't allow knock to flood */
#ifdef VCHANS
  struct Channel  *root_chptr;		/* pointer back to root if vchan */
  dlink_list	  vchan_list;	        /* vchan sublist */
#endif

  dlink_list      chanops;		/* lists of chanops etc. */
#ifdef REQUIRE_OANDV
  dlink_list	  chanops_voiced;	/* UGH I'm sorry */
#endif
#ifdef HALFOPS
  dlink_list      halfops;
#endif
  dlink_list      voiced;
  dlink_list      peons;                /* non ops, just members */
  dlink_list	  deopped;              /* users deopped on sjoin */

  dlink_list      locchanops;           /* local versions of the above */
#ifdef REQUIRE_OANDV
  dlink_list	  locchanops_voiced;	/* UGH I'm sorry */
#endif
#ifdef HALFOPS
  dlink_list      lochalfops;
#endif
  dlink_list      locvoiced;
  dlink_list      locpeons;             /* ... */
  
  dlink_list      invites;
  dlink_list      banlist;
  dlink_list      exceptlist;
  dlink_list      invexlist;

  time_t          first_received_message_time; /* channel flood control */
  int             received_number_of_privmsgs;
  int             flood_noticed;

  int             num_mask;              /* number of bans+exceptions+invite exceptions */
  time_t          channelts;
  char            chname[CHANNELLEN+1];
};

extern  struct  Channel *GlobalChannelList;

void init_channels(void);
void cleanup_channels(void *);


extern int     can_send (struct Channel *chptr, struct Client *who);
extern int     is_banned (struct Channel *chptr, struct Client *who);

extern int     can_join(struct Client *source_p, struct Channel *chptr,
                        char *key);
extern int     is_chan_op (struct Channel *chptr,struct Client *who);
extern int     is_any_op (struct Channel *chptr,struct Client *who);
#ifdef HALFOPS
extern int     is_half_op (struct Channel *chptr,struct Client *who);
#endif
extern int     is_voiced (struct Channel *chptr,struct Client *who);

#define find_user_link(list,who) who!=NULL?dlinkFind(list,who):NULL
#define FIND_AND_DELETE(list,who) who!=NULL?dlinkFindDelete(list,who)

extern void    add_user_to_channel(struct Channel *chptr,
				   struct Client *who, int flags);
extern int     remove_user_from_channel(struct Channel *chptr,
					struct Client *who);

extern int     check_channel_name(const char* name);

extern void    channel_member_names( struct Client *source_p,
				     struct Channel *chptr,
				     char *name_of_channel,
                                     int show_eon);
extern char    *channel_pub_or_secret(struct Channel *chptr);
extern char    *channel_chanop_or_voice(struct Channel *, struct Client *);

extern void    add_invite(struct Channel *chptr, struct Client *who);
extern void    del_invite(struct Channel *chptr, struct Client *who);

extern void    send_channel_modes (struct Client *, struct Channel *);
extern void    channel_modes(struct Channel *chptr, struct Client *who,
                             char *, char *);

extern void    check_spambot_warning(struct Client *source_p, const
                                     char *name);

extern void check_splitmode(void *);

/*
** Channel Related macros follow
*/

#define HoldChannel(x)          (!(x))
/* channel visible */
#define ShowChannel(v,c)        (PubChannel(c) || IsMember((v),(c)))

#define IsMember(who, chan) ((who && who->user && \
                dlinkFind(&who->user->channel, chan)) ? 1 : 0)

#define IsChannelName(name) ((name) && (*(name) == '#' || *(name) == '&'))

struct Ban          /* also used for exceptions -orabidoo */
{
  char *banstr;
  char *who;
  time_t when;
};

#define CLEANUP_CHANNELS_TIME (30*60)
#define MAX_VCHAN_TIME (60*60)
/* Number of chanops, peon, voiced, halfops sublists */
#ifdef REQUIRE_OANDV
#define NUMLISTS 5
#else
#define NUMLISTS 4
#endif

#ifdef INTENSIVE_DEBUG
void do_channel_integrity_check(void);
#endif

void set_channel_topic(struct Channel *chptr, const char *topic, const char *topic_info, time_t topicts); 
void free_topic(struct Channel *);
int allocate_topic(struct Channel *);
extern char * strip_color(char *);
extern int msg_has_colors(char*);

#endif  /* INCLUDED_channel_h */
