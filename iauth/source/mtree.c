/************************************************************************
 *   IRC - Internet Relay Chat, iauth/mtree.c
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

/*
 *  This file contains routines to add and locate items
 * in a "modified" tree. These routines were specifically
 * designed for I: and K: line handling. In short, a
 * rather complicated solution is needed to solve a seemingly
 * trivial problem.
 *
 * The problem is this: Suppose you have 2 I: lines:
 *
 * I:NOMATCH::*@*::1
 * I:NOMATCH::*@*.varner.com::1
 *
 *  Now, if you place the *@* in front of the *@*.varner.com
 * I: line, it could be put in from of *@*.varner.com in
 * the I: line linked list. Now suppose a client connects
 * from koruna.varner.com. If you do a simple linear search
 * of the linked list, you will come across the *@* I: line
 * first, and it happens to be a good match - but it is not
 * the BEST match.
 *  A widely used feature of I: lines is so you can group
 * all the generic users under a common I: line, such as *@*
 * or *@*.com, but make separate I: lines for server operators
 * or administrators (that may conflict with the generic I: lines).
 *
 *  This is where the modified tree comes in. As I: and K: lines
 * are read in, they are added to a regular linked list, and also
 * a type of tree. In this special tree, each node contains
 * part of a hostname - specifically the part between dots.
 *
 *  So, if you make an I: line for *.koruna.varner.com, it would
 * be entered into the tree in the following manner:
 *
 *                       com
 *                        |
 *                      varner
 *                        |
 *                      koruna
 *                        |
 *                        *
 *
 *  This is convenient because when a client connects from
 * *.koruna.varner.com, you can take apart their hostname in
 * the same manner and compare each segment to it's corresponding
 * node in the tree.
 *
 *  Now suppose you wanted to add another I: line for
 * hyland.magenet.com.
 *
 *  The new tree would then look like this:
 *
 *                       com
 *                       /
 *                     /
 *                   /
 *                varner --> magenet
 *                  |           |
 *                koruna      hyland
 *                  |
 *                  *
 *
 *  Notice the TLD is always kept on top. If you wanted to add
 * a new TLD, for example: *.underworld.n?t, the tree
 * would look like this:
 *
 *                       com ---> n?t
 *                      /            \
 *                    /                \
 *                  /                    \
 *               varner -> magenet   underworld
 *                 |          |           |
 *               koruna     hyland        *
 *                 |
 *                 *
 *
 * and so on..
 *  The easy part is setting up the tree. The hard part is
 * making a search algorithm to handle every possibility.
 * I've designed the following search algorithm (SearchSubTree()).
 * When an ircd server requests an authorization, iauth takes
 * the client's hostname (uwns.underworld.net) and breaks it up
 * into segments, keeping pointers to each segment. In this
 * case, the array would look like this:
 *
 *   array[0] = "uwns"
 *   array[1] = "underworld"
 *   array[2] = "net"
 *
 *  Then it begins with the last segment (net) and searches the
 * very top level of the tree. First it searches for an exact
 * match, and if it finds none, it searches for a wildcard
 * match. The reason it takes exact matches over wildcard
 * matches, is because each level is searched only once. If it
 * took the first wildcard match it came to, there might be
 * a better (exact) match later down the line. And again, that
 * is the entire reason a tree is needed - because more exact
 * matches are better than generic matches.
 *  In this case, there is no exact match for the TLD, so it
 * takes the next best thing (n?t). It then hops down a level,
 * and searches for the next lower index of our array (underworld).
 * It will find an exact match right away and jump down to the next
 * (and final) level. It will again find an acceptable wildcard
 * match on the final level, and since there are no more pieces
 * to our hostname, declare that the client has an acceptable I:
 * line.
 *
 *  One more note about wildcard matches. The tree search starts
 * with the last segment of the hostname. In other words, if
 * you have two I: lines:
 *   1) *@*.net
 *   2) *@uwns.*
 * A client from uwns.underworld.net will be given the first I:
 * line. This is not a bug ;-). It is the way the routine was
 * designed. If you were to do something like this:
 *   1) *@*.net
 *   2) *@uwns.*.net
 * then the client would be sure to get the second I: line.
 *
 * Patrick Alken <wnder@underworld.net>
 * 09/13/1999
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "conf.h"
#include "log.h"
#include "match.h"
#include "misc.h"
#include "mtree.h"
#include "sock.h"

/*
 * Beginning of our Iline tree
 */
static struct Level           *IlineTree = NULL;

/*
 * Beginning of our Kline tree
 */
static struct Level           *KlineTree = NULL;

/*
 * List of unsortable Ilines
 */
static struct UnsortableIline *UnsortableIlines = NULL;

/*
 * List of unsortable Klines
 */
static struct UnsortableKline *UnsortableKlines = NULL;

/*
 * This is a nifty trick suggested by Dianora - instead of
 * flagging each node with a bitmask after it has been searched,
 * set it to the current serial number and increment. That way,
 * we won't need to "reset" the tree after every search - only
 * when our serial number gets larger than 32 bits.
 */
static long                   SerialNumber = 0;

/*
 * Local functions
 */

static void CreateSubTree(struct Level **level, struct Level *parent,
                          void *typeptr, int hostc, char **hostv);
static struct Level *SearchSubTree(struct Level **level, int hostc,
                                   char **hostv);

static void ResetTree(struct Level **tree);
static void MarkNodeSearched(struct Level *node);
static void LinkStructPointer(void *ptr, struct Level **list);
static struct Level *IsOnLevel(struct Level *level, char *piece);
static int CountNonWilds(char *str);

static int BreakupHost(char *hostname, char ***array);
static int IsSortable(int hostc, char **hostv);
static void AddUnsortableIline(struct Iline *iptr);
static struct Iline *FindUnsortableIline(char *username,
                                         char *hostname);
static void AddUnsortableKline(struct ServerBan *kptr);
static struct ServerBan *FindUnsortableKline(char *username,
                                             char *hostname);

/*
TreeAddIline()
 Add an Iline entry to our tree
*/

void
TreeAddIline(struct Iline *iptr)

{
  char **hostv;
  char hostname[HOSTLEN + 1];
  int hostpieces;

  assert(iptr != NULL);

  /*
   * So we don't destroy iptr->hostname, use another buffer
   */
  memset(hostname, 0, sizeof(hostname));
  strncpy_irc(hostname, iptr->hostname, HOSTLEN);

  hostpieces = BreakupHost(hostname, &hostv);

  if (IsSortable(hostpieces, hostv))
    CreateSubTree(&IlineTree, NULL, iptr, hostpieces, hostv);
  else
  {
    fprintf(stderr, "HOSTNAME [%s] IS NOT SORTABLE\n",
      iptr->hostname);
    AddUnsortableIline(iptr);
  }

  MyFree(hostv);
} /* TreeAddIline() */

/*
TreeAddKline()
 Add a Kline entry to our tree
*/

void
TreeAddKline(struct ServerBan *kptr)

{
  char **hostv;
  char hostname[HOSTLEN + 1];
  int hostpieces;

  assert(kptr != NULL);

  /*
   * So we don't destroy kptr->hostname, use another buffer
   */
  memset(hostname, 0, sizeof(hostname));
  strncpy_irc(hostname, kptr->hostname, HOSTLEN);

  hostpieces = BreakupHost(hostname, &hostv);

  if (IsSortable(hostpieces, hostv))
    CreateSubTree(&KlineTree, NULL, kptr, hostpieces, hostv);
  else
  {
    fprintf(stderr, "HOSTNAME [%s] IS NOT SORTABLE\n",
      kptr->hostname);
    AddUnsortableKline(kptr);
  }

  MyFree(hostv);
} /* TreeAddKline() */

/*
CreateSubTree()
 Create a sub-tree within 'level' containing the given information.

Inputs: level   - where to start building our tree
        parent  - pointer to this level's parent node
        typeptr - Iline or Kline structure that we're adding to
                  the tree
        hostc   - number of hostname pieces we're adding
        hostv   - array of pointers to each host piece
*/

static void
CreateSubTree(struct Level **level, struct Level *parent,
              void *typeptr, int hostc, char **hostv)

{
  struct Level *tmpnode;
  char *ch;

  if (hostc == 0)
    return;

  /*
   * First search the current level for an exact match
   * of hostv[hostc - 1]. - if found proceed to the next
   * level down from there.
   * We can't use IsOnLevel() here because we need an
   * exact match (strcasecmp) - we don't want stuff like
   * "c?m" and "com" being put in the same node.
   */
  for (tmpnode = *level; tmpnode; tmpnode = tmpnode->nextpiece)
  {
    if (!strcasecmp(tmpnode->name, hostv[hostc - 1]))
    {
      /*
       * We have found a matching host piece on this
       * level - no need to allocate a new level
       * structure. Now we will recursively call
       * CreateSubTree() again using tmpnode->nextlevel
       * as the level pointer, indicating that we want
       * to see if the next lower index of hostv
       * (hostv[hostc - 2]) is in the next level. If so,
       * again recursively call CreateSubTree(). Eventually
       * we might reach a level that does not contain
       * the corresponding index of hostv[]. When that
       * happens, the loop will fail and we will
       * drop below to allocate a new level structure.
       * If that does not happen, we have an exact duplicate
       * of a previous I/K line, in which case hostc will
       * be 1, and we add typeptr to the node's list of
       * pointers (the username may differ).
       */

      if (hostc == 1)
        LinkStructPointer(typeptr, &tmpnode);

      CreateSubTree(&tmpnode->nextlevel, tmpnode, typeptr, hostc - 1, hostv);

      return;
    }
  }

  /*
   * If we reach this point, one of two conditions must
   * be true.
   *  1) *level is NULL, which means we must initialize it
   *     and then add our hostv[] index to it.
   *  2) The host piece hostv[hostc - 1] was not found
   *     on this level - allocate a new structure for it.
   */

  tmpnode = (struct Level *) MyMalloc(sizeof(struct Level));
  memset(tmpnode, 0, sizeof(struct Level));

  tmpnode->name = MyStrdup(hostv[hostc - 1]);
  if (parent)
  {
    tmpnode->prevlevel = parent;
    ++parent->SubNodes;
    ++parent->UnsearchedSubNodes;
  }

  for (ch = tmpnode->name; *ch; ++ch)
  {
    if (IsWild(*ch))
    {
      tmpnode->flags |= LV_WILDCARD;
      break;
    }
  }

  if (hostc == 1)
  {
    /*
     * Since hostc is 1, this is the very last hostname piece
     * we need to add to the sub tree. This is the piece that
     * will contain a pointer to the corresponding Iline or
     * Kline structure, so SearchSubTree() will know when to
     * stop.
     * Now, it is quite possible that later on we will need to
     * add more host pieces past this current piece. For example,
     * suppose our tree looks like this after this call:
     *
     *     com
     *      |
     *    varner -> [struct Iline *iptr (for @varner.com)]
     *
     * Then, suppose later we wish to add an Iline for
     * @koruna.varner.com. Our tree should then look like this:
     *
     *     com
     *      |
     *    varner -> [struct Iline (for @varner.com)]
     *      |
     *    koruna -> [struct Iline (for @koruna.varner.com)]
     *
     * SearchSubTree() will then know that both levels are a
     * complete I/K line, and depending on how big the hostname
     * it is looking for, will know how deep to go.
     */

    LinkStructPointer(typeptr, &tmpnode);
  }

  if (*level == NULL)
  {
    /*
     * Set the level to our newly allocated structure
     */
    *level = tmpnode;
  }
  else
  {
    /*
     * The level already exists, and possibly has some
     * host pieces on it - add our new piece after
     * *level. For example, if the level originally looked
     * like:
     *
     *  ...
     *   |
     * "com" --> "net" --> "org" --> NULL
     *
     * It will now look like:
     *
     *  ...
     *   |
     * "com" --> tmpnode->name --> "net" --> "org" --> NULL
     */
    tmpnode->nextpiece = (*level)->nextpiece;
    (*level)->nextpiece = tmpnode;
  }

  /*
   * We've just added hostv[hostc - 1] to the correct level,
   * but as long as hostc != 0, there are more host pieces
   * to add. Recursively call CreateSubTree() until there
   * are no more pieces to add.
   */
  CreateSubTree(&tmpnode->nextlevel, tmpnode, typeptr, hostc - 1, hostv);
} /* CreateSubTree() */

/*
SearchIlineTree()
 Search the Iline tree for the given hostname and username.
Return a pointer to the Iline structure if found.
*/

struct Iline *
SearchIlineTree(char *username, char *hostname)

{
  char host[HOSTLEN + 1];
  char **hostv;
  int hostc,
      ii;
  struct Level *ret;
  struct Iline *tmp;

  memset(host, 0, sizeof(host));
  strncpy_irc(host, hostname, HOSTLEN);

  hostc = BreakupHost(host, &hostv);

  /*
   * A loop is needed to continually search the IlineTree
   * because of the username problem. Suppose we have 2
   * Ilines:
   *    (a) foo@*.net
   *    (b)   *@*.underworld.net
   * and suppose the client comes from wnder@uwns.underworld.net.
   * SearchSubTree() may return (a) since the hostname part
   * actually does match, but this routine will return NULL
   * because it cannot find a username match, even though
   * there is another I: line that matches. Therefore, this
   * loop will continue searching the tree until absolutely
   * no more hostname matches are found.
   *
   * We can be sure it will not return the same I: line twice
   * because the variable SerialNumber gets continually
   * incremented. When a node has been searched, it's
   * serial is set to the current SerialNumber variable, so
   * we know it has been searched if it's serial matches
   * SerialNumber.
   */

  if (!(++SerialNumber))
  {
    /*
     * SerialNumber will eventually roll over to 0 when it
     * reaches it's 32 bit limit - reset both trees and
     * increment SerialNumber to 1.
     */
    ++SerialNumber;
    ResetTree(&IlineTree);
    ResetTree(&KlineTree);
  }

  while ((ret = SearchSubTree(&IlineTree, hostc, hostv)))
  {
    if (!ret->numptrs)
    {
      log(L_ERROR,
        "SearchIlineTree(): search result has 0 Iline pointers");
      MyFree(hostv);
      /*ResetTree(&IlineTree);*/
      return (NULL);
    }

    /*
     * Now for the username check
     */
    for (ii = 0; ii < ret->numptrs; ++ii)
    {
      tmp = (struct Iline *) ret->typeptrs[ii];
      if (match(tmp->username, username))
      {
        MyFree(hostv);
        /*ResetTree(&IlineTree);*/
        return (tmp);
      }
    }
  }

  /*ResetTree(&IlineTree);*/

  /*
   * We failed to locate the Iline in our tree - search
   * the unsortable list
   */
  tmp = FindUnsortableIline(username, hostname);
  MyFree(hostv);
  return (tmp);
} /* SearchIlineTree() */

/*
SearchKlineTree()
 Search the Kline tree for the given hostname.
Return a pointer to the Kline structure if found.
*/

struct ServerBan *
SearchKlineTree(char *username, char *hostname)

{
  char host[HOSTLEN + 1];
  char **hostv;
  int hostc,
      ii;
  struct Level *ret;
  struct ServerBan *tmp;

  memset(host, 0, sizeof(host));
  strncpy_irc(host, hostname, HOSTLEN);

  hostc = BreakupHost(host, &hostv);

  if (!(++SerialNumber))
  {
    ++SerialNumber;
    ResetTree(&IlineTree);
    ResetTree(&KlineTree);
  }

  while ((ret = SearchSubTree(&KlineTree, hostc, hostv)))
  {
    if (!ret->numptrs)
    {
      log(L_ERROR,
        "SearchKlineTree(): search result has 0 Kline pointers");
      MyFree(hostv);
      /*ResetTree(&KlineTree);*/
      return (NULL);
    }

    /*
     * Check the username
     */
    for (ii = 0; ii < ret->numptrs; ++ii)
    {
      tmp = (struct ServerBan *) ret->typeptrs[ii];
      if (match(tmp->username, username))
      {
        MyFree(hostv);
        /*ResetTree(&KlineTree);*/
        return (tmp);
      }
    }
  }

  /*ResetTree(&KlineTree);*/

  /*
   * We failed to locate the Kline in our tree - search
   * the unsortable list
   */
  tmp = FindUnsortableKline(username, hostname);
  MyFree(hostv);
  return (tmp);
} /* SearchKlineTree() */

/*
SearchSubTree()
 Backend for Search*lineTree() - Recurse through the levels of
'level' looking for the best match with the given hostname
pieces.
 Return a pointer to the level containing the I/K line structure
if found.
*/

static struct Level *
SearchSubTree(struct Level **level, int hostc, char **hostv)

{
  struct Level *tmpnode,
               *tmpnode2,
               *ret;
  int tmphostc;
  int ContinueLevel;

  if (hostc == 0)
    return (NULL);

  /*
   * Search the current level for our host piece
   */
  ContinueLevel = 0;
  while ((tmpnode = IsOnLevel(*level, hostv[hostc - 1])))
  {
    if (tmpnode->UnsearchedSubNodes == 0)
      MarkNodeSearched(tmpnode);

    if (hostc == 1)
    {
      /*
       * Since hostc is 1, there are no more pieces to
       * search for - we have found a match
       */
      return (tmpnode);
    }

    /*
     * We found a match on a particular host piece, but
     * there are still more pieces to check - continue
     * searching
     */

    if (tmpnode->flags & LV_WILDCARD)
    {
      /*
       * We want to try to take this wildcard piece as
       * far as we can before moving on to the next level.
       * In other words, move to the next level only when:
       *  a) we find a match on the next level for the
       *     corresponding host piece
       *  b) the wildcard on this level fails to match
       *     the next host piece
       */

      tmphostc = hostc;

      if ((tmpnode2 = IsOnLevel(tmpnode->nextlevel, hostv[tmphostc - 2])))
      {
        /*
         * Since the next index of hostv[] was found
         * on the level below tmpnode, give up on the
         * current wildcard (tmpnode->name), and go
         * down to the next level to continue the search.
         */
        tmpnode = tmpnode2;
        --tmphostc;

        if (tmpnode->UnsearchedSubNodes == 0)
          MarkNodeSearched(tmpnode);
      }

      while (tmphostc)
      {
        if (!match(tmpnode->name, hostv[tmphostc - 2]))
          break;

        if (--tmphostc == 1)
        {
          /*
           * There is a case in which the tmpnode we are about
           * to return is not valid, meaning it does not contain
           * any pointers to I/K line structures.
           * Consider the following Iline:
           *
           * *@uwns.underworld.*
           *
           * Now suppose we have a client connecting from:
           * *@koruna.varner.com. This loop will match the
           * "com", "varner", and "koruna" against the "*"
           * in the Iline and determine we have made a match.
           * However, the piece containing the "*" is not
           * the final piece of the Iline, and so it will not
           * contain a pointer to an Iline. Therefore we must
           * ensure that tmpnode contains at least 1 typeptr.
           */
          if (!tmpnode->numptrs)
          {
            /*
             * Continue searching the same level for another
             * match.
             */
            ContinueLevel = 1;

            /*
             * Make sure we don't search the same dead-end
             * node again.
             */
            MarkNodeSearched(tmpnode);

            break;
          }
          else
            return (tmpnode);
        }

        /*
         * Since we just decremented tmphostc, we need to check
         * if the corresponding index of hostv[] is on the
         * next level - if so, drop to the next level to
         * continue checking.
         * For example, suppose the tree looked like this:
         *
         *   *
         *   |
         *  irc
         *
         * And we're checking the host: irc.wnder.com.
         * "com" and "wnder" should both be matched against
         * the "*", but once we see that "irc" matches
         * something on the next level, drop down and continue
         * searching - we wouldn't want to match "irc" against
         * "*" (even though its a good match) because although
         * we're at the end of our hostv[] array, the "*"
         * structure will NOT contain a pointer to the
         * corresponding I/K line structure - only the very
         * last branch of the tree does that.
         */
        if (IsOnLevel(tmpnode->nextlevel, hostv[tmphostc - 2]))
          break;
      } /* while (tmphostc) */
    } /* if (tmpnode->flags & LV_WILDCARD) */

    if (ContinueLevel)
      continue;

    /*
     * Continue our search on the next level
     */
    ret = SearchSubTree(&tmpnode->nextlevel, hostc - 1, hostv);
    if (ret)
      return (ret);

    /*
     * We didn't find a match in the current branch of the tree -
     * continue the loop to search other branches
     */

  } /* while ((tmpnode = IsOnLevel(*level, hostv[hostc - 1]))) */

  /*
   * If we get here, we've hit a level that does not contain
   * the corresponding host piece in our list - the hostname
   * is not in this branch of the tree - continue searching
   * other branches.
   */
  if (*level && (*level)->prevlevel)
    MarkNodeSearched((*level)->prevlevel);

  return (NULL);
} /* SearchSubTree() */

/*
ResetTree()
 The SearchSubTree() routine marks various nodes as "searched"
so after the search is complete, we need to unmark those nodes.
*/

static void
ResetTree(struct Level **tree)

{
  struct Level *tmplev,
               *tmpnode;

  for (tmplev = *tree; tmplev; tmplev = tmplev->nextlevel)
  {
    for (tmpnode = tmplev; tmpnode; tmpnode = tmpnode->nextpiece)
    {
      /*ClearChecked(tmpnode);*/
      tmpnode->serial = 0;
      tmpnode->UnsearchedSubNodes = tmpnode->SubNodes;
    }
  }
} /* ResetTree() */

/*
MarkNodeSearched()
 Called when a node has been, or is about to be searched. The
idea is to determine if we can mark this node as "searched".
A node is considered searched/checked when:
 a) It is the very last node in a branch
 b) Or, all nodes below this node have been checked
*/

static void
MarkNodeSearched(struct Level *node)

{
  node->serial = SerialNumber;
  /*SetChecked(node);*/
  if (node->prevlevel)
  {
    if (--node->prevlevel->UnsearchedSubNodes == 0)
      MarkNodeSearched(node->prevlevel);
  }
} /* MarkNodeSearched() */

/*
LinkStructPointer()
 Link I:/K: line structure to list->typeptrs
*/

static void
LinkStructPointer(void *ptr, struct Level **list)

{
  ++(*list)->numptrs;

  if (!(*list)->typeptrs)
    (*list)->typeptrs = (void **) MyMalloc(sizeof(void *));
  else
    (*list)->typeptrs = (void **) MyRealloc((*list)->typeptrs, sizeof(void *) * (*list)->numptrs);

  (*list)->typeptrs[(*list)->numptrs - 1] = ptr;
} /* LinkStructPointer() */

/*
IsOnLevel()
 Determine if 'piece' is on the sub-level 'level'.
Return a pointer to the level struct containing 'piece'

NOTE: We always try to find the MOST exact match - for example:
      Nodes which contain no wildcards are always taken over
      nodes which do contain wildcards. If an exact match
      cannot be found, the best wildcard match is taken. The
      best wildcard match is calculated by counting the number
      of non-wildcard characters in the node. A node with a
      greater number of non-wildcard characters is considered
      a better match. For example, suppose the following are true:

           piece = "net"

           nodeA = "n*t"
           nodeB = "???"
           nodeC = "*t"

      nodeA will be considered the best match available, since it
      is the most specific.
*/

static struct Level *
IsOnLevel(struct Level *level, char *piece)

{
  struct Level *tmpnode,
               *prevmatch;
  int currnw, /* non wild characters in current level */
      prevnw; /* non wild characters in previous match */

#if 0
  /*
   * First try to do strcasecmp's because exact matches
   * should be taken over wildcard matches
   */
  for (tmpnode = level; tmpnode; tmpnode = tmpnode->nextpiece)
  {
    if (!strcasecmp(tmpnode->name, piece))
      return (tmpnode);
  }
#endif

  prevnw = 0;
  prevmatch = NULL;
  for (tmpnode = level; tmpnode; tmpnode = tmpnode->nextpiece)
  {
    /*
     * Don't check the same node twice
     */
    if (tmpnode->serial == SerialNumber)
      continue;

  #if 0
    if (WasChecked(tmpnode))
      continue;
  #endif

    if (match(tmpnode->name, piece))
    {
      if (!(tmpnode->flags & LV_WILDCARD))
      {
        /*
         * If there are no wildcards in tmpnode, it must
         * be an exact match - return it.
         */
        return (tmpnode);
      }

      currnw = CountNonWilds(tmpnode->name);

      /*
       * If the number of non-wildcard characters in tmpnode->name
       * is greater than that of our previous match, drop
       * prevmatch and record tmpnode because it is a more exact
       * match. If hostA has more non-wildcard characters than
       * hostB it is considered to be a more exact match.
       */
      if (!prevmatch || (currnw > prevnw))
      {
        /*
         * We've found an acceptable match, but keep going
         * in case we find a more exact match
         */
        prevmatch = tmpnode;
        prevnw = currnw;
      }
    } /* if (match(tmpnode->name, piece)) */
  }

  return (prevmatch);
} /* IsOnLevel() */

/*
CountNonWilds()
 Return the number of non-wildcard characters in 'str'.
'*' and '?' are considered wilds
*/

static int
CountNonWilds(char *str)

{
  char *ch;
  int nonwildcnt = 0;

  for (ch = str; *ch; ++ch)
    if (!IsWild(*ch))
      ++nonwildcnt;

  return (nonwildcnt);
} /* CountNonWilds() */

/*
BreakupHost()
 Break up host pieces (separated by dots ".") and store pointers
to each piece in 'array'.

Return: number of host pieces in 'hostname'

NOTE: Memory is allocated for array - so free it when done.
*/

static int
BreakupHost(char *hostname, char ***array)

{
  int argnum = 4; /* initial number of slots in our array */
  int pieces;     /* number of "pieces" in hostname */
  char *tmp,
       *founddot;

  *array = (char **) MyMalloc(sizeof(char *) * argnum);
  pieces = 0;

  tmp = hostname;
  while (*tmp)
  {
    if (pieces == argnum)
    {
      /*
       * We've filled up all the slots allocated so far,
       * allocate some more
       */
      argnum += 4;
      *array = (char **) MyRealloc(*array, sizeof(char *) * argnum);
    }

    founddot = strstr(tmp, ".");
    if (founddot)
      *founddot++ = '\0';
    else
      founddot = tmp + strlen(tmp);

    (*array)[pieces++] = tmp;
    tmp = founddot;
  }

  return (pieces);
} /* BreakupHost() */

/*
IsSortable()
 Determine if hostname is sortable in our modified tree.

Inputs: hostc - host piece count
        hostv - host piece array

Return: 1 if sortable
        0 if not
*/

static int
IsSortable(int hostc, char **hostv)

{
  char *tmp;
  int ii;
  int precedingchars, /* characters preceding a '*' */
      postchars,      /* characters after a '*' */
      wildfound;      /* a '*' was found */

  for (ii = 0; ii < hostc; ++ii)
  {
    /*
     * There are basically two rules for determining a hostname
     * is unsortable.
     *
     *  - If one of the hostname pieces contains a *, preceded by
     *    characters. (ie: foo* or foo*bar)
     *
     *  - If a hostname piece begins with a *, followed by characters.
     *    (ie: *bar)
     */

    precedingchars = 0;
    postchars = 0;
    wildfound = 0;

    /*
     * This loop will tell us if there are any characters
     * preceding a '*', if there are any '*' characters, and if
     * there are any characters trailing a '*' character in the
     * hostpiece.
     */
    for (tmp = hostv[ii]; *tmp; ++tmp)
    {
      if (*tmp != '*')
      {
        if (!precedingchars && !wildfound)
        {
          precedingchars = 1;
          continue;
        }

        if (!postchars && wildfound)
        {
          postchars = 1;
          continue;
        }
      }
      else if (!wildfound)
      {
        wildfound = 1;
        continue;
      }
    }

    /*
     * Case 1a: <chars>*
     * Case 1b: <chars>*<chars>
     * Case 2 : *<chars>
     */
    if (wildfound)
    {
      if (precedingchars || postchars)
        return (0);
    }
  }

  return (1);
} /* IsSortable() */

/*
AddUnsortableIline()
 Add Iline structure 'iptr' to list of unsortable Ilines
*/

static void
AddUnsortableIline(struct Iline *iptr)

{
  struct UnsortableIline *tmp;

  tmp = (struct UnsortableIline *) MyMalloc(sizeof(struct UnsortableIline));
  tmp->iptr = iptr;

  tmp->prev = NULL;
  tmp->next = UnsortableIlines;
  if (tmp->next)
    tmp->next->prev = tmp;
  UnsortableIlines = tmp;
} /* AddUnsortableIline() */

/*
FindUnsortableIline()
 Attempt to locate 'username' and 'hostname' in the unsortable
Iline list
*/

static struct Iline *
FindUnsortableIline(char *username, char *hostname)

{
  struct UnsortableIline *tmp;

  for (tmp = UnsortableIlines; tmp; tmp = tmp->next)
  {
    if (match(tmp->iptr->username, username) &&
        match(tmp->iptr->hostname, hostname))
      return (tmp->iptr);
  }

  return (NULL);
} /* FindUnsortableIline() */

/*
AddUnsortableKline()
 Add ServerBan structure 'kptr' to list of unsortable Klines
*/

static void
AddUnsortableKline(struct ServerBan *kptr)

{
  struct UnsortableKline *tmp;

  tmp = (struct UnsortableKline *) MyMalloc(sizeof(struct UnsortableKline));
  tmp->kptr = kptr;

  tmp->prev = NULL;
  tmp->next = UnsortableKlines;
  if (tmp->next)
    tmp->next->prev = tmp;
  UnsortableKlines = tmp;
} /* AddUnsortableKline() */

/*
FindUnsortableKline()
 Attempt to locate 'username' and 'hostname' in the unsortable
Kline list
*/

static struct ServerBan *
FindUnsortableKline(char *username, char *hostname)

{
  struct UnsortableKline *tmp;

  for (tmp = UnsortableKlines; tmp; tmp = tmp->next)
  {
    if (match(tmp->kptr->username, username) &&
        match(tmp->kptr->hostname, hostname))
      return (tmp->kptr);
  }

  return (NULL);
} /* FindUnsortableKline() */
