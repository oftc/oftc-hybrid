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
 *  $Id$
 */

#ifndef _I_MEMORY_H
#define _I_MEMORY_H

#include "ircd_defs.h"
#include "setup.h"
#include "balloc.h"

/* Needed to use uintptr_t for some pointer manipulation. */
#ifdef __VMS
#include inttypes
#else /* Not VMS */
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#else /* No inttypes.h */
#ifndef HAVE_UINTPTR_T
typedef unsigned long uintptr_t;
#endif
#endif
#endif

extern void outofmemory(void);


extern void *MyMalloc(size_t size);
extern void *MyRealloc(void *x, size_t y);
extern void MyFree(void *x);
extern void _DupString(char **x, const char *y);

/* forte (and maybe others) dont like double declarations, 
 * so we dont declare the inlines unless GNUC
 */
#ifdef __GNUC__
extern inline void * MyMalloc(size_t size)
{
  void *ret = calloc(1, size);
  if(ret == NULL)
    outofmemory();
  return(ret);
}

extern inline void* MyRealloc(void* x, size_t y)
{
  void *ret = realloc(x, y);
  
  if(ret == NULL)
    outofmemory();
  return(ret);    
}

extern inline void MyFree(void *x)
{
  if(x != NULL)
    free(x);
}

extern inline void _DupString(char **x, const char *y)
{
  (*x) = malloc(strlen(y) + 1);
  if(x == NULL)
    outofmemory();
  strcpy((*x), y); 
}
#endif /* __GNUC__ */

#define DupString(x,y) _DupString(&x, y)


#ifndef WE_ARE_MEMORY_C
#undef strdup
#undef malloc
#undef realloc
#undef calloc
#undef free
#define malloc do_not_call_old_memory_functions!call_My*functions
#define calloc do_not_call_old_memory_functions!call_My*functions
#define realloc do_not_call_old_memory_functions!call_My*functions
#define strdup do_not_call_old_memory_functions!call_My*functions
#define free do_not_call_old_memory_functions!call_My*functions
#endif


#endif /* _I_MEMORY_H */

