/************************************************************************
 *   IRC - Internet Relay Chat, iauth/misc.c
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

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "iauth.h"
#include "log.h"
#include "misc.h"

static void outofmemory();

/*
 * strncpy_irc - optimized strncpy
 * This may not look like it would be the fastest possible way to do it,
 * but it generally outperforms everything else on many platforms, 
 * including asm library versions and memcpy, if compiled with the 
 * optimizer on. (-O2 for gcc) --Bleep
 */
char *
strncpy_irc(char* s1, const char* s2, size_t n)

{
  char* endp = s1 + n;
  char* s = s1;
  while (s < endp && (*s++ = *s2++))
    ;
  return s1;
}

/*
 * MyMalloc - allocate memory, call outofmemory on failure
 */
void *
MyMalloc(size_t x)

{
  void* ret = malloc(x);

  if (!ret)
    outofmemory();
  return ret;
} /* MyMalloc() */

char *
MyStrdup(char *str)

{
  char *final;

  final = (char *) MyMalloc(strlen(str) + 1);
  strcpy(final, str);

  return (final);
} /* MyStrdup() */

/*
MyRealloc()
  calls realloc() with 'oldptr' and 'newsize'; returns pointer to
allocated memory if successful, otherwise calls outofmemory()
*/

void *
MyRealloc(void *oldptr, size_t newsize)

{
  void  *ptr;

  ptr = (void *) realloc(oldptr, newsize);
  if (!ptr)
    outofmemory();

  return (ptr);
} /* MyRealloc() */

/*
MyFree()
 Free a pointer
*/

void
MyFree(void *ptr)

{
  if (ptr)
  {
    free(ptr);
    ptr = NULL;
  }
} /* MyFree() */

static void
outofmemory()

{
  log(L_INFO, "Out of memory, exiting");
  exit (-1);
} /* outofmemory() */
