/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_accept.c: Allows a user to talk to a +g user.
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
#include "handlers.h"
#include "client.h"
#include "hash.h"       /* for find_client() */
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static void m_accept(struct Client*, struct Client*, int, char**);
static void build_nicklist(struct Client *, char *, char *, char *);

static void add_accept(struct Client *, struct Client *);
static void list_accepts(struct Client *);

struct Message accept_msgtab = {
  "ACCEPT", 0, 0, 2, 0, MFLG_SLOW | MFLG_UNREG, 0, 
  {m_unregistered, m_accept, m_ignore, m_accept}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&accept_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&accept_msgtab);
}

const char *_version = "$Revision$";
#endif
/*
 * m_accept - ACCEPT command handler
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void m_accept(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  char *nick;
  char *p = NULL;
  static char addbuf[BUFSIZE];
  static char delbuf[BUFSIZE];
  struct Client *target_p;
  int accept_num;
  
  if(*parv[1] == '*')
  {
    list_accepts(source_p);
    return;
  }

  build_nicklist(source_p, addbuf, delbuf, parv[1]);

  /* parse the delete list */
  for(nick = strtoken(&p, delbuf, ","); nick != NULL;
      nick = strtoken(&p, NULL, ","))
  {
    /* shouldnt happen, but lets be paranoid */
    if(((target_p = find_client(nick)) == NULL) || !IsPerson(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, nick);
      continue;
    }

    /* user isnt on clients accept list */
    if(!accept_message(target_p, source_p))
    {
      sendto_one(source_p, form_str(ERR_ACCEPTNOT),
                 me.name, source_p->name, target_p->name);
      continue;
    }

    del_from_accept(target_p, source_p);
  }

  /* get the number of accepts they have */ 
  accept_num = dlink_list_length(&source_p->allow_list);
  
  /* parse the add list */
  for(nick = strtoken(&p, addbuf, ","); nick;
      nick = strtoken(&p, NULL, ","), accept_num++)
  {
    /* shouldnt happen, but lets be paranoid */
    if(((target_p = find_client(nick)) == NULL) || !IsPerson(target_p)) 
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, nick);
      continue;
    }

    /* user is already on clients accept list */
    if(accept_message(target_p, source_p))
    {
      sendto_one(source_p, form_str(ERR_ACCEPTEXIST),
                 me.name, source_p->name, target_p->name);
      continue;
    }

    if(accept_num >= ConfigFileEntry.max_accept)
    {
      sendto_one(source_p, form_str(ERR_ACCEPTFULL),
                 me.name, source_p->name);
      return;
    }
      
    /* why is this here? */
    /* del_from accept(target_p, source_p); */
    add_accept(source_p, target_p);

  }


}
/*
 * build_nicklist()
 *
 * input	- pointer to client
 *		- pointer to addbuffer
 *		- pointer to remove buffer
 *		- pointer to list of nicks
 * output	- 
 * side effects - addbuf/delbuf are modified to give valid nicks
 */
static void build_nicklist(struct Client *source_p, char *addbuf,
                           char *delbuf, char *nicks)
{
  char *name;
  char *p;
  int lenadd;
  int lendel;
  int del;
  struct Client *target_p;

  *addbuf = *delbuf = '\0';
  del = lenadd = lendel = 0;

  /* build list of clients to add into addbuf, clients to remove in delbuf */
  for(name = strtoken(&p, nicks, ","); name; 
      name = strtoken(&p, (char *)NULL, ","), del = 0)
  {
    if(*name == '-')
    {
      del = 1;
      name++;
    }

    if(((target_p = find_client(name)) == NULL) || !IsPerson(target_p))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, name);
      continue;
    }

    /* we're deleting a client */
    if(del)
    {
      if(*delbuf)
        (void)strcat(delbuf, ",");
	
      (void)strncat(delbuf, name, BUFSIZE - lendel - 1);
      lendel += strlen(name) + 1;
    }
    /* adding a client */
    else
    {
      if(*addbuf)
        (void)strcat(addbuf, ",");

      (void)strncat(addbuf, name, BUFSIZE - lenadd - 1);
      lenadd += strlen(name) + 1;
    }
  }
}

/*
 * add_accept()
 *
 * input	- pointer to clients accept list to add to
 * 		- pointer to client to add
 * output	- none
 * side effects - target is added to clients list
 */
static void add_accept(struct Client *source_p, 
                       struct Client *target_p)
{
  dlink_node *m;

  m = make_dlink_node();
  dlinkAdd(target_p, m, &source_p->allow_list);

  m = make_dlink_node();
  dlinkAdd(source_p, m, &target_p->on_allow_list);
}
  

/*
 * list_accepts()
 *
 * input 	- pointer to client
 * output	- none
 * side effects	- print accept list to client
 */
static void list_accepts(struct Client *source_p)
{
  dlink_node *ptr;
  struct Client *target_p;
  char nicks[BUFSIZE];
  int len=0;
  int len2=0;
  int count=0;
  
  *nicks = '\0';
  len2= strlen(source_p->name) + 10;

  DLINK_FOREACH(ptr, source_p->allow_list.head)
  {
    target_p = ptr->data;

    if(target_p)
    {

      if((len + strlen(target_p->name) + len2 > BUFSIZE) || count > 14)
      {
        sendto_one(source_p, form_str(RPL_ACCEPTLIST),
	           me.name, source_p->name, nicks);
		   
	len = count = 0;
	*nicks = '\0';
      }

      ircsprintf(nicks+len, "%s ", target_p->name);
      
      count++;
      len += strlen(target_p->name) + 1;
    }
  }

  if(*nicks)
    sendto_one(source_p, form_str(RPL_ACCEPTLIST),
               me.name, source_p->name, nicks);

  sendto_one(source_p, form_str(RPL_ENDOFACCEPT),
             me.name, source_p->name);

}
