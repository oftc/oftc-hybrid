/************************************************************************
 *   IRC - Internet Relay Chat, iauth/commands.h
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

#ifndef INCLUDED_commands_h
#define INCLUDED_commands_h

struct CommandTable
{
  char *name;      /* name of command */
  void (* func)(); /* function to call */
};

/*
 * External declarations
 */

extern struct CommandTable          Commands[];

#endif /* INCLUDED_commands_h */
