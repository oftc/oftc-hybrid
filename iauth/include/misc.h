/************************************************************************
 *   IRC - Internet Relay Chat, iauth/misc.h
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

#ifndef INCLUDED_misc_h
#define INCLUDED_misc_h

/*
 * Prototypes
 */

char *strncpy_irc(char *s1, const char *s2, size_t n);
void *MyMalloc(size_t x);
char *MyStrdup(char *str);
void *MyRealloc(void *oldptr, size_t newsize);
void MyFree(void *ptr);

#endif /* INCLUDED_misc_h */
