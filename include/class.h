/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  class.h: The ircd class management header.
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

#ifndef INCLUDED_class_h
#define INCLUDED_class_h

struct ConfItem;
struct Client;

struct Class {
  struct Class* next;     /* list node pointer */
  char*		className;
  int           type;
  int           conFreq;
  int           pingFreq;
  int           maxLinks;
  long          maxSendq;
  char*         servname;
  int           servport;
  int           links;
};


#define ClassName(x)	((x)->className)
#define ClassType(x)    ((x)->type)
#define ConFreq(x)      ((x)->conFreq)
#define PingFreq(x)     ((x)->pingFreq)
#define MaxLinks(x)     ((x)->maxLinks)
#define MaxSendq(x)     ((x)->maxSendq)
#define Links(x)        ((x)->links)

#define ClassPtr(x)      ((x)->c_class)
#define ConfLinks(x)     (ClassPtr(x)->links)
#define ConfMaxLinks(x)  (ClassPtr(x)->maxLinks)
#define ConfClassName(x) (ClassPtr(x)->class_name)
#define ConfClassType(x) (ClassPtr(x)->type)
#define ConfConFreq(x)   (ClassPtr(x)->conFreq)
#define ConfPingFreq(x)  (ClassPtr(x)->pingFreq)
#define ConfSendq(x)     (ClassPtr(x)->maxSendq)

extern struct Class* ClassList;  /* GLOBAL - class list */

extern  long    get_sendq(struct Client *);
extern  int     get_con_freq(struct Class* );
extern  struct Class  *find_class(char* );
extern  const   char* get_client_class (struct Client *);
extern  int     get_client_ping (struct Client *);
extern  void    check_class(void);
extern  void    initclass(void);
extern  void    free_class(struct Class* );
extern  void    add_class (char *, int, int, int, long);
extern  void    fix_class (struct ConfItem *, struct ConfItem *);
extern  void    report_classes (struct Client *);

#endif /* INCLUDED_class_h */
