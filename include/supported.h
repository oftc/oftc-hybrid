/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  supported.h: Header for 005 numeric etc...
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

#ifndef INCLUDED_supported_h
#define INCLUDED_supported_h

#include "config.h"
#include "channel.h"
#include "ircd_defs.h"

#ifndef USE_ASCII_CASEMAP
#define CASEMAP "rfc1459"
#else
#define CASEMAP "ascii"
#endif

#define FEATURES "WALLCHOPS"\
                "%s%s%s%s" \
                " MODES=%i" \
                " MAXCHANNELS=%i" \
                " MAXBANS=%i" \
                " MAXTARGETS=%i" \
                " NICKLEN=%i" \
                " TOPICLEN=%i" \
                " KICKLEN=%i"

#define FEATURESVALUES ConfigChannel.use_knock ? " KNOCK" : "", \
        ConfigChannel.use_vchans ? " VCHANS" : "", \
        ConfigChannel.use_except ? " EXCEPTS" : "", \
        ConfigChannel.use_invex ? " INVEX" : "", \
        MAXMODEPARAMS,ConfigChannel.max_chans_per_user, \
        ConfigChannel.max_bans, \
        ConfigFileEntry.max_targets,NICKLEN-1,TOPICLEN,TOPICLEN

#define FEATURES2 "CHANTYPES=%s" \
                  " PREFIX=%s" \
		  " CHANMODES=%s%s%s%s" \
		  " NETWORK=%s" \
		  " CASEMAPPING=%s" \
		  " CALLERID"

#define FEATURES2VALUES ConfigServerHide.disable_local_channels ? "#" : "#&", \
                        ConfigChannel.use_halfops ? "(ohv)@%+" : "(ov)@+", \
                        ConfigChannel.use_except ? "e" : "", \
                        ConfigChannel.use_invex ? "I" : "", \
                        "b,k,l,imnpst", \
                        ConfigChannel.use_anonops ? "a" : "", \
                        ServerInfo.network_name, CASEMAP

/*
 * - from mirc's versions.txt
 *
 *  mIRC now supports the numeric 005 tokens: CHANTYPES=# and
 *  PREFIX=(ohv)@%+ and can handle a dynamic set of channel and
 *  nick prefixes.
 *
 *  mIRC assumes that @ is supported on all networks, any mode
 *  left of @ is assumed to have at least equal power to @, and
 *  any mode right of @ has less power.
 *
 *  mIRC has internal support for @%+ modes.
 *
 *  $nick() can now handle all mode letters listed in PREFIX.
 *
 *  Also added support for CHANMODES=A,B,C,D token (not currently
 *  supported by any servers), which lists all modes supported
 *  by a channel, where:
 *
 *    A = modes that take a parameter, and add or remove nicks
 *        or addresses to a list, such as +bIe for the ban,
 *        invite, and exception lists.
 *
 *    B = modes that change channel settings, but which take
 *        a parameter when they are set and unset, such as
 *        +k key, and -k key.
 *
 *    C = modes that change channel settings, but which take
 *        a parameter only when they are set, such as +l N,
 *        and -l.
 *
 *    D = modes that change channel settings, such as +imnpst
 *        and take no parameters.
 *
 *  All unknown/unlisted modes are treated as type D.
 */

#endif /* INCLUDED_supported_h */
