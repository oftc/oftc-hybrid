/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_defs.h: A header for ircd global definitions.
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

/*
 * NOTE: NICKLEN and TOPICLEN do not live here anymore. Set it with configure
 * Otherwise there are no user servicable part here. 
 *
 */
 /* ircd_defs.h - Global size definitions for record entries used
 * througout ircd. Please think 3 times before adding anything to this
 * file.
 */
#ifndef INCLUDED_ircd_defs_h
#define INCLUDED_ircd_defs_h

#include "config.h"

#if !defined(CONFIG_H_LEVEL_7)
#  error Incorrect config.h for this revision of ircd.
#endif

#define HOSTLEN         63      /* Length of hostname.  Updated to         */
                                /* comply with RFC1123                     */

#define USERLEN         10
#define REALLEN         50
#define KILLLEN         90      
#define CHANNELLEN      200

/* 23+1 for \0 */
#define KEYLEN          24
#define BUFSIZE         512     /* WARNING: *DONT* CHANGE THIS!!!! */
#define MAXRECIPIENTS   20
#define MAXBANLENGTH    1024
#define OPERNICKLEN     NICKLEN*2 /* Length of OPERNICKs. */

#define USERHOST_REPLYLEN       (NICKLEN+HOSTLEN+USERLEN+5)
#define MAX_DATE_STRING 32      /* maximum string length for a date string */

#define HELPLEN         400

/* 
 * message return values 
 */
#define CLIENT_EXITED    -2
#define CLIENT_PARSE_ERROR -1
#define CLIENT_OK	1


struct irc_inaddr
{
	union {
		struct in_addr sin;
#ifdef IPV6
		struct in6_addr sin6;	
#endif
	} sins;
};

struct irc_sockaddr
{
	union {
		struct sockaddr_in sin;
#ifdef IPV6
		struct sockaddr_in6 sin6;
#endif			
	} sins;
};


#ifdef IPV6
#define copy_s_addr(a, b)  \
do { \
((uint32_t *)a)[0] = ((uint32_t *)b)[0]; \
((uint32_t *)a)[1] = ((uint32_t *)b)[1]; \
((uint32_t *)a)[2] = ((uint32_t *)b)[2]; \
((uint32_t *)a)[3] = ((uint32_t *)b)[3]; \
} while(0)


/* irc_sockaddr macros */
#define PS_ADDR(x) x->sins.sin6.sin6_addr.s6_addr  	/* s6_addr for pointer */
#define S_ADDR(x) x.sins.sin6.sin6_addr.s6_addr 	/* s6_addr for non pointer */
#define S_PORT(x) x.sins.sin6.sin6_port			/* s6_port */
#define S_FAM(x) x.sins.sin6.sin6_family		/* sin6_family */
#define SOCKADDR(x) x.sins.sin6				/* struct sockaddr_in6 for nonpointer */
#define PSOCKADDR(x) x->sins.sin6			/* struct sockaddr_in6 for pointer */


/* irc_inaddr macros */
#define IN_ADDR(x) x.sins.sin6.s6_addr
#define IPV4_MAPPED(x) ((uint32_t *)x.sins.sin6.s6_addr)[3]
#define PIN_ADDR(x) x->sins.sin6.s6_addr /* For Pointers */
#define IN_ADDR2(x) x.sins.sin6

#define DEF_FAM AF_INET6

#else
#define copy_s_addr(a, b) a = b


#define PS_ADDR(x)	x->sins.sin.sin_addr.s_addr	/* s_addr for pointer */
#define S_ADDR(x)	x.sins.sin.sin_addr.s_addr	/* s_addr for nonpointer */
#define S_PORT(x)	x.sins.sin.sin_port		/* sin_port   */
#define S_FAM(x)	x.sins.sin.sin_family		/* sin_family */
#define SOCKADDR(x)	x.sins.sin			/* struct sockaddr_in */
#define PSOCKADDR(x)	x->sins.sin			/* struct sockaddr_in */


#define PIN_ADDR(x) x->sins.sin.s_addr 
#define IN_ADDR(x) x.sins.sin.s_addr

#ifndef AF_INET6
#define AF_INET6 10 /* Dummy AF_INET6 declaration */
#endif 
#define DEF_FAM AF_INET

#endif


#endif /* INCLUDED_ircd_defs_h */
