/************************************************************************
 *   IRC - Internet Relay Chat, iauth/commands.c
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
#include "commands.h"
#include "conf.h"
#include "iauth.h"
#include "log.h"
#include "match.h"
#include "misc.h"
#include "setup.h"

static struct CommandTable *GetCommand(struct CommandTable *cmdlist,
                                       char *name);

static void c_server(struct Server *sptr, int ac, char **av);
static void c_doauth(struct Server *sptr, int ac, char **av);
static void c_class(struct Server *sptr, int ac, char **av);
static void c_class_add(struct Server *sptr, int ac, char **av);
static void c_class_clear(struct Server *sptr, int ac, char **av);

struct CommandTable Commands[] = {
  { "Server", c_server },
  { "DoAuth", c_doauth },
  { "Class", c_class },

  { 0, 0 }
};

/*
 * sub-commands for c_class()
 */
struct CommandTable classcmds[] = {
  { "Add", c_class_add },
  { "Clear", c_class_clear },
};

/*
GetCommand()
 Attempt to find the command "name" in the list "cmdlist".
Return a pointer to the index containing "name" if found,
otherwise NULL.  If the command is found, but there is
more than 1 match (ambiguous), return (struct CommandTable *) -1.
*/

static struct CommandTable *
GetCommand(struct CommandTable *cmdlist, char *name)

{
  struct CommandTable *cmdptr, *tmp;
  int matches, /* number of matches we've had so far */
      clength;

  if (!cmdlist || !name)
    return (NULL);

  tmp = NULL;
  matches = 0;
  clength = strlen(name);
  for (cmdptr = cmdlist; cmdptr->name; cmdptr++)
  {
    if (!strncasecmp(name, cmdptr->name, clength))
    {
      if (clength == strlen(cmdptr->name))
      {
        /*
         * name and cmdptr->name are the same length, so it
         * must be an exact match, don't search any further
         */
        matches = 0;
        break;
      }
      tmp = cmdptr;
      ++matches;
    }
  }

  /*
   * If matches > 1, name is an ambiguous command, so the
   * user needs to be more specific
   */
  if ((matches == 1) && (tmp))
    cmdptr = tmp;

  if (cmdptr->name)
    return (cmdptr);

  if (matches == 0)
    return (NULL); /* no matches found */
  else
    return ((struct CommandTable *) -1); /* multiple matches found */
} /* GetCommand() */

/*
c_server()
 When an ircd server connects, it should send a "Server" string
to identify itself

av[0] = "Server"
av[1] = server name
*/

static void
c_server(struct Server *sptr, int ac, char **av)

{
  if (ac < 2)
    return;

  sptr->name = MyStrdup(av[1]);
} /* c_server() */

/*
c_doauth()
 Begin an authorization for a client
*/

static void
c_doauth(struct Server *sptr, int ac, char **av)

{
  StartAuth(sptr, ac, av);
} /* c_doauth() */

/*
c_class()
 Add/Delete classes

av[0] = "Class"
av[1] = "Add" or "Clear"
av[2] = optional class number
av[3] = optional maximum links
*/

static void
c_class(struct Server *sptr, int ac, char **av)

{
  struct CommandTable *cmdptr;

  if (ac < 2)
    return;

  cmdptr = GetCommand(classcmds, av[1]);
  if (cmdptr && (cmdptr != (struct CommandTable *) -1))
    (*cmdptr->func)(sptr, ac, av);
} /* c_class() */

/*
c_class_add()
 Add a class to ClassList

av[0] = "Class"
av[1] = "Add"
av[2] = class number
av[3] = maximum links
*/

static void
c_class_add(struct Server *sptr, int ac, char **av)

{
  struct Class *clptr;
  struct Iline *iptr;
  int classnum;

  if (ac < 4)
    return;

  fprintf(stderr, "IN CLASS ADD\n");

  classnum = atoi(av[2]);
  clptr = AddClass(classnum, atoi(av[3]));

  /*
   * Now go through the Iline list and set all Ilines
   * with the given class number to the new class
   */
  for (iptr = IlineList; iptr; iptr = iptr->next)
  {
    if (iptr->classnum == classnum)
      iptr->class = clptr;
  }
} /* c_class_add() */

/*
c_class_clear()
 Called when a server rehashes - clear the old class lines
to make room for the new ones.

av[0] = "Class"
av[1] = "Clear"
av[2] = optional class number (if not given, all classes are cleared)
*/

static void
c_class_clear(struct Server *sptr, int ac, char **av)

{
  struct Class *clptr;

  if (ac >= 3)
  {
    if ((clptr = FindClass(atoi(av[2]))))
      DeleteClass(clptr);
  }
  else
    ClearClasses();
} /* c_class_clear() */
