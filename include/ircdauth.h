/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircdauth.h: A header for the iAuth interface.
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

#ifndef INCLUDED_ircdauth_h
#define INCLUDED_ircdauth_h

struct Client;

#define NOSOCK        (-1)
#define MAXPARAMS     15

#define IA_CONNECT    (1 >> 0)

#define IsIAuthConnect(x)    ((x).flags &  IA_CONNECT)
#define SetIAuthConnect(x)   ((x).flags |= IA_CONNECT)
#define ClearIAuthConnect(x) ((x).flags &= ~IA_CONNECT)

struct IrcdAuthentication
{
	char hostname[HOSTLEN + 1]; /* hostname of IAuth server */
	int port;                   /* port for connection */
	int socket;                 /* socket fd for IAuth connection */
	unsigned int flags;         /* IA_* */
};

/*
 * Prototypes
 */

int ConnectToIAuth();
void IAuthQuery(struct Client *client);
extern void BeginAuthorization(struct Client *);
extern void SendIAuth(char *, ...);


/*
 * External declarations
 */

extern struct IrcdAuthentication iAuth;

#endif /* INCLUDED_ircdauth_h */
