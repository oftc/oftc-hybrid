/************************************************************************
 *   IRC - Internet Relay Chat, iauth/class.h
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

#ifndef INCLUDED_class_h
#define INCLUDED_class_h

struct Class
{
  struct Class *next, *prev;

  int classnum; /* number that identifies this class */
  int maxLinks; /* maximum clients that may use this class */
  int links;    /* current clients using this class */
};

/*
 * Prototypes
 */

struct Class *AddClass(int classnum, int maxLinks);
void DeleteClass(struct Class *clptr);
struct Class *FindClass(int classnum);
void ClearClasses();

/*
 * External declarations
 */

extern struct Class          *ClassList;

#endif /* INCLUDED_class_h */
