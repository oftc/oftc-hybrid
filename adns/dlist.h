/*
 * dlist.h
 * - macros for handling doubly linked lists
 */
/*
 *  This file is
 *    Copyright (C) 1997-1999 Ian Jackson <ian@davenant.greenend.org.uk>
 *
 *  It is part of adns, which is
 *    Copyright (C) 1997-2000 Ian Jackson <ian@davenant.greenend.org.uk>
 *    Copyright (C) 1999 Tony Finch <dot@dotat.at>
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software Foundation,
 *  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. 
 *
 * $Id$
 */

#ifndef ADNS_DLIST_H_INCLUDED
#define ADNS_DLIST_H_INCLUDED

/* More strange shit for OS X and its b0rked C compiler */

#define unused_arg /**/

#define ADNS_LIST_INIT(flist) ((flist).head= (flist).tail= 0)
#define LINK_INIT(flink) ((flink).next= (flink).back= 0)



#define LIST_UNLINK_PART(flist,node,part) \
  do { \
    if ((node)->part back) (node)->part back->part next= (node)->part next; \
      else                                  (flist).head= (node)->part next; \
    if ((node)->part next) (node)->part next->part back= (node)->part back; \
      else                                  (flist).tail= (node)->part back; \
  } while(0)

#define LIST_LINK_TAIL_PART(flist,node,part) \
  do { \
    (node)->part next= 0; \
    (node)->part back= (flist).tail; \
    if ((flist).tail) (flist).tail->part next= (node); else (flist).head= (node); \
    (flist).tail= (node); \
  } while(0)

#define LIST_UNLINK(flist,node) LIST_UNLINK_PART(flist,node,unused_arg)
#define LIST_LINK_TAIL(flist,node) LIST_LINK_TAIL_PART(flist,node, unused_arg)
#endif
