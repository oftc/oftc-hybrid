/************************************************************************
 *   IRC - Internet Relay Chat, iauth/mtree.h
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

#ifndef INCLUDED_mtree_h
#define INCLUDED_mtree_h

struct Iline;

/*
 * The format for our modified tree is something like this:
 *
 * struct Level -----> IlineTree
 *                         |
 *                         |
 *       -------------------
 *       |
 *     "net" --> "com" --> "org" --> "edu"
 *                /
 *               /
 *              /
 *             /
 *          "varner" ---> "blackened" ---> ...
 *              |              |
 *          "koruna"       "scorched"
 *              |              |
 *             "*"            "*"
 *
 * As can be seen from the diagram, each level may only have 1
 * parent node.
 */

struct Level
{
  struct Level *nextpiece; /* pointer to next piece (in this level) */
  struct Level *nextlevel, /* pointer to next level (below this one) */
               *prevlevel; /* pointer to parent level (above this one) */

  char *name;              /* name of piece on this level */

  int SubNodes;            /* # of nodes immediately below this one */

  /*
   * This is the number of unsearched nodes immediately below
   * this node. This number can never exceed SubNodes.
   */
  int UnsearchedSubNodes;

  /*
   * This is an array of pointers to the corresponding
   * I/K line structure(s). The reason there may be more than
   * one, is if the hostnames are the same, but the usernames
   * differ.
   * It is only set for the very last piece of the I/K line -
   * (ie: the very bottom of the tree). Every piece up until
   * the last piece has a NULL typeptrs.
   */
  void **typeptrs;
  int numptrs;             /* number of pointers in typeptrs */

  unsigned int flags;
  long serial;
};

struct UnsortableIline
{
  struct UnsortableIline *prev, *next;
  struct Iline *iptr;
};

struct UnsortableKline
{
  struct UnsortableKline *prev, *next;
  struct ServerBan *kptr;
};

/*
 * LV_xxx flags indicate the status of a particular level node
 */

#define LV_WILDCARD   (1 << 0) /* node contains a wild host piece */
#define LV_CHECKED    (1 << 1) /* node has been checked during a search */

#if 0
#define SetChecked(x)   ((x)->flags |= LV_CHECKED)
#define WasChecked(x)   ((x)->flags &  LV_CHECKED)
#define ClearChecked(x) ((x)->flags &= ~LV_CHECKED)
#endif

/*
 * Prototypes
 */

void TreeAddIline(struct Iline *iptr);
void TreeAddKline(struct ServerBan *kptr);
struct Iline *SearchIlineTree(char *username, char *hostname);
struct ServerBan *SearchKlineTree(char *username, char *hostname);

#endif /* INCLUDED_mtree_h */
