/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  md5.h: A header for the MD5 hash algorithms.
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

#ifndef __INCLUDE_MD5_H_INCLUDED
#define __INCLUDE_MD5_H_INCLUDED

#include "setup.h"

#define MD5_HASH_SIZE   4
#define	MD5_BLOCK_SIZE	16

#define rotl(x,n) ((((x)<<(n))&(-(1<<(n))))|(((x)>>(32-(n)))&((1<<(n))-1)))
#define F(x,y,z) (((x)&(y))|((~x)&(z)))
#define G(x,y,z) (((x)&(z))|((y)&(~z)))
#define H(x,y,z) ((x)^(y)^(z))
#define I(x,y,z) ((y)^((x)|(~z)))

/* Length of IDs to generate; at most IDLEN (12) */
#define ID_GEN_LEN 9

void id_init(void);
void save_random(void);
int base64_block(char **out, char *in, int len);
int unbase64_block(char **out, char *data, int len);
char *id_get(void);

#endif
