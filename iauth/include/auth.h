/************************************************************************
 *   IRC - Internet Relay Chat, iauth/auth.h
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

#ifndef INCLUDED_auth_h
#define INCLUDED_auth_h

#ifndef INCLUDED_sys_types_h
#include <sys/types.h>          /* time_t */
#define INCLUDED_sys_types_h
#endif

#ifndef INCLUDED_netinet_in_h
#include <netinet/in.h>         /* struct in_addr */
#define INCLUDED_netinet_in_h
#endif

#ifndef INCLUDED_sock_h
#include "sock.h"        /* USERLEN/HOSTLEN */
#define INCLUDED_sock_h
#endif

#ifndef INCLUDED_conf_h
#include "conf.h"        /* PASSLEN */
#define INCLUDED_conf_h
#endif

struct Server;

struct AuthRequest
{
  struct AuthRequest *next, *prev;

  unsigned int flags;                /* current state of request */
  time_t       timeout;              /* time when query expires */
  int          identfd;              /* ident query socket descriptor */
  char         clientid[IDLEN + 1];  /* unique client ID */

  struct Server *server;      /* server where request came from */

  struct in_addr ip;          /* ip address of client */

  struct DNSReply *dns_reply; /* result from resolver query */

  unsigned int remoteport;    /* client's remote port */
  unsigned int localport;     /* server's local port */

  char         nickname[NICKLEN + 1]; /* user's nickname */
  char         username[USERLEN + 1]; /* user's ident */
  char         hostname[HOSTLEN + 1]; /* user's hostname */
  char         password[PASSLEN + 1]; /* user's password */
};

/* auth.c prototypes */

void StartAuth(struct Server *sptr, int parc, char **parv);
void SendIdentQuery(struct AuthRequest *auth);
void ReadIdentReply(struct AuthRequest *auth);

/*
 * External declarations
 */

extern struct AuthRequest *AuthPollList;
extern struct AuthRequest *AuthIncompleteList;

/* Maximum parameters an ircd server will send us */
#define MAXPARAMS       15

/* Buffer size for ident reply */
#define ID_BUFSIZE      128

/*
 * AM_* - Authentication Module Flags
 */

#define AM_IDENT_CONNECTING  (1 << 0) /* connecting to their ident port */
#define AM_IDENT_PENDING     (1 << 1) /* ident reply is pending */
#define AM_DNS_PENDING       (1 << 2) /* dns reply is pending */

/*
 * Authentication Module Macros
 */

#define SetDNSPending(x)     ((x)->flags |= AM_DNS_PENDING)
#define ClearDNSPending(x)   ((x)->flags &= ~AM_DNS_PENDING)
#define IsDNSPending(x)      ((x)->flags &  AM_DNS_PENDING)

#define SetIdentConnect(x)   ((x)->flags |= AM_IDENT_CONNECTING)
#define ClearIdentConnect(x) ((x)->flags &= ~AM_IDENT_CONNECTING)
#define IsIdentConnect(x)    ((x)->flags &  AM_IDENT_CONNECTING)

#define SetIdentPending(x)   ((x)->flags |= AM_IDENT_PENDING)
#define ClearIdentPending(x) ((x)->flags &= AM_IDENT_PENDING)
#define IsIdentPending(x)    ((x)->flags &  AM_IDENT_PENDING)

#define ClearAuth(x)         ((x)->flags &= ~(AM_IDENT_PENDING | AM_IDENT_CONNECTING))
#define IsDoingAuth(x)       ((x)->flags &  (AM_IDENT_PENDING | AM_IDENT_CONNECTING))

#endif /* INCLUDED_auth_h */
