/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  class.c: Controls connection classes.
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

#include "stdinc.h"
#include "config.h"

#include "tools.h"
#include "class.h"
#include "client.h"
#include "common.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "s_conf.h"
#include "send.h"
#include "irc_string.h"
#include "s_debug.h"
#include "memory.h"


#define BAD_CONF_CLASS          -1
#define BAD_PING                -2
#define BAD_CLIENT_CLASS        -3

struct Class* ClassList;

static struct Class *make_class()
{
  struct Class        *tmp;

  tmp = (struct Class *)MyMalloc(sizeof(struct Class));
  tmp->className = NULL;
  tmp->servname = NULL;
  return tmp;
}

void free_class(struct Class *tmp)
{
  MyFree(tmp->className);
  MyFree((char *)tmp);
}

/*
 * get_conf_ping
 *
 * inputs	- pointer to struct ConfItem
 * output	- ping frequency
 * side effects - NONE
 */
static  int     get_conf_ping(struct ConfItem *aconf)
{
  if ((aconf) && ClassPtr(aconf))
    return (ConfPingFreq(aconf));

  Debug((DEBUG_DEBUG,"No Ping For %s",
         (aconf) ? aconf->name : "*No Conf*"));

  return (BAD_PING);
}

/*
 * get_client_class
 *
 * inputs	- pointer to client struct
 * output	- pointer to name of class
 * side effects - NONE
 */
const char*     get_client_class(struct Client *target_p)
{
  dlink_node *ptr;
  struct ConfItem *aconf;
  const char* retc = "unknown";

  if (target_p && !IsMe(target_p)  && (target_p->localClient->confs.head))
    for (ptr = target_p->localClient->confs.head; ptr; ptr = ptr->next)
      {
	aconf = ptr->data;
	if(aconf->className == NULL)
	  retc = "default";
	else
	  retc= aconf->className;
      }

  Debug((DEBUG_DEBUG,"Returning Class %s For %s",retc,target_p->name));

  return (retc);
}

/*
 * get_client_ping
 *
 * inputs	- pointer to client struct
 * output	- ping frequency
 * side effects - NONE
 */
int     get_client_ping(struct Client *target_p)
{
  int   ping = 0;
  int   ping2;
  struct ConfItem       *aconf;
  dlink_node		*nlink;


  if(target_p->localClient->confs.head != NULL)
    {
      for(nlink = target_p->localClient->confs.head; nlink; nlink = nlink->next)
	{
	  aconf = nlink->data;
	  if (aconf->status & (CONF_CLIENT|CONF_SERVER))
	    {
	      ping2 = get_conf_ping(aconf);
	      if ((ping2 != BAD_PING) && ((ping > ping2) || !ping))
		ping = ping2;
	    }
	}
    }
  else
    {
      ping = DEFAULT_PINGFREQUENCY;
      Debug((DEBUG_DEBUG,"No Attached Confs"));
    }

  if (ping <= 0)
    ping = DEFAULT_PINGFREQUENCY;
  Debug((DEBUG_DEBUG,"Client %s Ping %d", target_p->name, ping));
  return (ping);
}

/*
 * get_con_freq
 *
 * inputs	- pointer to class struct
 * output	- connection frequency
 * side effects - NONE
 */
int     get_con_freq(struct Class *clptr)
{
  if (clptr)
    return (ConFreq(clptr));
  return (DEFAULT_CONNECTFREQUENCY);
}

/*
 * add_class
 *
 * inputs	- classname to use
 * 		- ping frequency
 *		- connection frequency
 * 		- maximum links
 *		- max sendq
 * output	- NONE
 * side effects -
 * When adding a class, check to see if it is already present first.
 * if so, then update the information for that class, rather than create
 * a new entry for it and later delete the old entry.
 * if no present entry is found, then create a new one and add it in
 * immediately after the first one (class 0).
 */
void    add_class(char *classname,
                  int ping,
                  int confreq,
                  int maxli,
                  long sendq)
{
  struct Class *t, *p;

  if(!classname)
    return;

  t = find_class(classname);
  if (t == ClassList)
    {
      p = make_class();
      p->next = t->next;
      t->next = p;
    }
  else
    p = t;
  Debug((DEBUG_DEBUG,
         "Add Class %s: p %x t %x - cf: %d pf: %d ml: %d sq: %l",
         classname, p, t, confreq, ping, maxli, sendq));

  /* classname already known to be non NULL */
  MyFree(ClassName(p));
  DupString(ClassName(p),classname);
  ConFreq(p) = confreq;
  PingFreq(p) = ping;
  MaxLinks(p) = maxli;
  MaxSendq(p) = (sendq > 0) ? sendq : DEFAULT_SENDQ;
  if (p != t)
    Links(p) = 0;
}

/*
 * find_class
 *
 * inputs	- string name of class
 * output	- corresponding class pointer
 * side effects	- NONE
 */
struct Class  *find_class(char* classname)
{
  struct Class *cltmp;

  if(classname == NULL)
    {
      return(ClassList);	/* return class 0 */
    }

  for (cltmp = ClassList; cltmp; cltmp = cltmp->next)
    if (!strcmp(ClassName(cltmp),classname))
      return cltmp;
  return ClassList;
}

/*
 * check_class
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- 
 */
void    check_class()
{
  struct Class *cltmp, *cltmp2;

  Debug((DEBUG_DEBUG, "Class check:"));

  for (cltmp2 = cltmp = ClassList; cltmp; cltmp = cltmp2->next)
    {
      Debug((DEBUG_DEBUG,
             "ClassName %s Class %d : CF: %d PF: %d ML: %d LI: %d SQ: %ld",
             ClassName(cltmp),ClassType(cltmp), ConFreq(cltmp), PingFreq(cltmp),
             MaxLinks(cltmp), Links(cltmp), MaxSendq(cltmp)));
      if (MaxLinks(cltmp) < 0)
        {
          cltmp2->next = cltmp->next;
          if (Links(cltmp) <= 0)
            free_class(cltmp);
        }
      else
        cltmp2 = cltmp;
    }
}

/*
 * initclass
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- 
 */
void    initclass()
{
  ClassList = make_class();

  ClassType(ClassList) = 0;
  DupString(ClassName(ClassList),"default");
  ConFreq(ClassList) = DEFAULT_CONNECTFREQUENCY;
  PingFreq(ClassList) = DEFAULT_PINGFREQUENCY;
  MaxLinks(ClassList) = ConfigFileEntry.maximum_links;
  MaxSendq(ClassList) = DEFAULT_SENDQ;
  Links(ClassList) = 0;
  ClassList->next = NULL;
}

/*
 * report_classes
 *
 * inputs	- pointer to client to report to
 * output	- NONE
 * side effects	- class report is done to this client
 */
void    report_classes(struct Client *source_p)
{
  struct Class *cltmp;

  for (cltmp = ClassList; cltmp; cltmp = cltmp->next)
    sendto_one(source_p, form_str(RPL_STATSYLINE), me.name, source_p->name,
               'Y', ClassName(cltmp), PingFreq(cltmp), ConFreq(cltmp),
               MaxLinks(cltmp), MaxSendq(cltmp));
}

/*
 * get_sendq
 *
 * inputs	- pointer to client
 * output	- sendq for this client as found from its class
 * side effects	- NONE
 */
long    get_sendq(struct Client *client_p)
{
  int   sendq = DEFAULT_SENDQ, retc = BAD_CLIENT_CLASS;
  dlink_node      *ptr;
  struct Class    *cl;
  struct ConfItem *aconf;

  if (client_p && !IsMe(client_p)  && (client_p->localClient->confs.head))
    for (ptr = client_p->localClient->confs.head; ptr; ptr = ptr->next)
      {
	aconf = ptr->data;
	if(aconf == NULL)
	   continue;

        if ( !(cl = aconf->c_class))
          continue;

        if (ClassType(cl) > retc)
          sendq = MaxSendq(cl);
      }
  return sendq;
}


