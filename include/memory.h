/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  memory.h: A header for the memory functions.
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
 *  $Id: memory.h 33 2005-10-02 20:50:00Z knight $
 */

#ifndef _I_MEMORY_H
#define _I_MEMORY_H

#include "ircd_defs.h"
#include "setup.h"
#include "balloc.h"

/* Needed to use uintptr_t for some pointer manipulation. */

#ifdef HAVE_INTTYPES_H
# include <inttypes.h>
#else /* No inttypes.h */
# ifndef HAVE_UINTPTR_T
typedef unsigned long uintptr_t;
# endif
#endif

extern void outofmemory(void);

extern void *MyMalloc(size_t size);
extern void *MyRealloc(void *x, size_t y);
extern void MyFree(void *x);
extern void _DupString(char **x, const char *y);

#define DupString(x,y) _DupString(&x, y)
#endif /* _I_MEMORY_H */
