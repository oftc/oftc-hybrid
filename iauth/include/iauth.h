/************************************************************************
 *   IRC - Internet Relay Chat, iauth/iauth.h
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

#ifndef INCLUDED_iauth_h
#define INCLUDED_iauth_h

#ifndef INCLUDED_sys_types_h
#include <sys/types.h>         /* time_t */
#define INCLUDED_sys_types_h
#endif

#define ICONF              "./iauth.conf"

#define BUFSIZE            512

#define IRCD_MIN(a, b)  ((a) < (b) ? (a) : (b))

/*
 * The IA_xxx defines are for the communication between the ircd
 * server and the iauth server.
 */
#define IA_DOAUTH        0x01  /* perform an auth query */
#define IA_GOODAUTH      0x02  /* client passed auth checks */
#define IA_BADAUTH       0x03  /* client failed auth checks */

/*
 * External declarations
 */

extern time_t              CurrentTime;
extern FILE                *LogPtr;

#endif /* INCLUDED_iauth_h */
