/************************************************************************
 *   IRC - Internet Relay Chat, iauth/class.c
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
#include <string.h>
#include <assert.h>

#include "auth.h"
#include "class.h"
#include "conf.h"
#include "iauth.h"
#include "log.h"
#include "match.h"
#include "misc.h"
#include "setup.h"

/*
 * Global - List of classes
 */
struct Class             *ClassList = NULL;

static void FreeClass(struct Class *clptr);

/*
AddClass()
 Add a class to ClassList
*/

struct Class *
AddClass(int classnum, int maxLinks)

{
  struct Class *ptr;

  ptr = (struct Class *) MyMalloc(sizeof(struct Class));
  memset(ptr, 0, sizeof(struct Class));

  ptr->classnum = classnum;
  ptr->maxLinks = maxLinks;

  ptr->prev = NULL;
  ptr->next = ClassList;
  ClassList = ptr;

  return (ptr);
} /* AddClass() */

/*
DeleteClass()
 Delete class 'clptr'
*/

void
DeleteClass(struct Class *clptr)

{
  if (clptr->next)
    clptr->next->prev = clptr->prev;

  if (clptr->prev)
    clptr->prev->next = clptr->next;
  else
    ClassList = clptr->next;

  FreeClass(clptr);
} /* DeleteClass() */

/*
FreeClass()
 Free the given class
*/

static void
FreeClass(struct Class *clptr)

{
  MyFree(clptr);
} /* FreeClass() */

/*
FindClass()
 Return pointer to class represented by 'classnum'
*/

struct Class *
FindClass(int classnum)

{
  struct Class *clptr;

  clptr = ClassList;
  while (clptr && !(clptr->classnum == classnum))
    clptr = clptr->next;

  return (clptr);
} /* FindClass() */

/*
ClearClasses()
 Delete all classes in ClassList
*/

void
ClearClasses()

{
  struct Class *next;

  while (ClassList)
  {
    next = ClassList->next;
    FreeClass(ClassList);
    ClassList = next;
  }
} /* ClearClasses() */
