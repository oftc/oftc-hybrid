/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ltrace.c: Traces a path to a client/server.
 *
 *  Copyright (C) 2002 Hybrid Development Team
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
#include "class.h"
#include "hook.h"
#include "client.h"
#include "hash.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void m_ltrace(struct Client *, struct Client *, int, char **);
static void mo_ltrace(struct Client*, struct Client*, int, char**);
static struct Client* next_client_double(struct Client *next, const char* ch);
static void ltrace_spy(struct Client *);

struct Message ltrace_msgtab = {
  "LTRACE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_ltrace, mo_ltrace, mo_ltrace}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  hook_add_event("doing_ltrace");
  mod_add_cmd(&ltrace_msgtab);
}

void
_moddeinit(void)
{
  hook_del_event("doing_ltrace");
  mod_del_cmd(&ltrace_msgtab);
}

const char *_version = "$Revision$";
#endif

static int report_this_status(struct Client *source_p, struct Client *target_p,int dow,
                              int link_u_p, int link_u_s);

/*
 * m_ltrace()
 *
 *	parv[0] = sender prefix
 *	parv[1] = target client/server to trace
 */
static void m_ltrace(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  char *tname;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;
  sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name, parv[0], tname);
}

/*
 * mo_ltrace
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void mo_ltrace(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  struct Client       *target_p = NULL;
  char  *tname;
  int   doall, link_s[MAXCONNECTIONS], link_u[MAXCONNECTIONS];
  int   wilds, dow;
  dlink_node *ptr;
  char *looking_for = parv[0];

  if(!IsClient(source_p))
    return;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  if(!IsOper(source_p))
  {
    sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name, parv[0], tname);
    return;
  }

  if (parc > 2)
    if (hunt_server(client_p, source_p, ":%s LTRACE %s :%s", 2, parc, parv))
      return;

  switch (hunt_server(client_p, source_p, ":%s LTRACE :%s", 1, parc, parv))
    {
    case HUNTED_PASS: /* note: gets here only if parv[1] exists */
      {
        struct Client *ac2ptr;
        
        ac2ptr = next_client_double(GlobalClientList, tname);
        if (ac2ptr)
          sendto_one(source_p, form_str(RPL_TRACELINK), me.name, looking_for,
                     ircd_version, debugmode, tname, ac2ptr->from->name);
        else
          sendto_one(source_p, form_str(RPL_TRACELINK), me.name, looking_for,
                     ircd_version, debugmode, tname, "ac2ptr_is_NULL!!");
        return;
      }
    case HUNTED_ISME:
      break;
    default:
      return;
    }

  ltrace_spy(source_p);

  doall = (parv[1] && (parc > 1)) ? match(tname, me.name): TRUE;
  wilds = !parv[1] || strchr(tname, '*') || strchr(tname, '?');
  dow = wilds || doall;
  
  set_time();

  /* lusers cant issue ltrace.. */
  if(!IsOper(source_p) || !dow)
    {
      const char* name;
      const char* class_name;
      char ipaddr[HOSTIPLEN];

      target_p = find_client(tname);
      
      if(target_p && IsPerson(target_p)) 
      {
        name = get_client_name(target_p, HIDE_IP);
        inetntop(target_p->localClient->aftype, &IN_ADDR(target_p->localClient->ip), ipaddr, HOSTIPLEN);

        class_name = get_client_class(target_p);

        if (IsOper(target_p))
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, parv[0], class_name, name, 
#ifndef HIDE_SPOOF_IPS
                     MyOper(source_p) ? ipaddr :
#endif
		     (IsIPSpoof(target_p) ? "255.255.255.255" : ipaddr),
                     CurrentTime - target_p->lasttime,
                     (target_p->user) ? (CurrentTime - target_p->user->last) : 0);
      }
      
      sendto_one(source_p, form_str(RPL_ENDOFTRACE),me.name,
                 parv[0], tname);
      return;
    }

  memset((void *)link_s,0,sizeof(link_s));
  memset((void *)link_u,0,sizeof(link_u));

  /*
   * Count up all the servers and clients in a downlink.
   */
  if (doall)
   {
    for (target_p = GlobalClientList; target_p; target_p = target_p->next)
     {
      if (IsPerson(target_p))
        {
          link_u[target_p->from->localClient->fd]++;
        }
      else if (IsServer(target_p))
	{
	  link_s[target_p->from->localClient->fd]++;
	}
     }
   }
   
  /* report all opers */
  for (ptr = lclient_list.head; ptr; ptr = ptr->next)
    {
      target_p = ptr->data;

      if(!IsOper(target_p))
	continue;

      if (!doall && wilds && !match(tname, target_p->name))
        continue;

      if (!dow && irccmp(tname, target_p->name))
        continue;

      report_this_status(source_p,target_p,dow,0,0);
    }

  /* report all servers */
  for (ptr = serv_list.head; ptr; ptr = ptr->next)
    {
      target_p = ptr->data;

      if (!doall && wilds && !match(tname, target_p->name))
        continue;
      if (!dow && irccmp(tname, target_p->name))
        continue;

      report_this_status(source_p, target_p, dow,
                               link_u[target_p->localClient->fd],
                               link_s[target_p->localClient->fd]);
    }

  sendto_one(source_p, form_str(RPL_ENDOFTRACE),me.name, parv[0],tname);
}




/*
 * report_this_status
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- counter of number of hits
 * side effects - NONE
 */
static int report_this_status(struct Client *source_p, struct Client *target_p,
                              int dow, int link_u_p, int link_s_p)
{
  const char* name;
  const char* class_name;
  char  ip[HOSTIPLEN];

  inetntop(target_p->localClient->aftype, &IN_ADDR(target_p->localClient->ip), ip, HOSTIPLEN);
  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(target_p);

  set_time();

  switch(target_p->status)
    {
    case STAT_CONNECTING:
      sendto_one(source_p, form_str(RPL_TRACECONNECTING), me.name,
                 source_p->name, class_name, 
		 IsOperAdmin(source_p) ? name : target_p->name);
		   
      break;

    case STAT_HANDSHAKE:
      sendto_one(source_p, form_str(RPL_TRACEHANDSHAKE), me.name,
                 source_p->name, class_name, 
                 IsOperAdmin(source_p) ? name : target_p->name);
		   
      break;
      
    case STAT_ME:
    case STAT_UNKNOWN:
      break;

    case STAT_CLIENT:
      if (IsAdmin(target_p))
	sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                   me.name, source_p->name, class_name, name,
#ifndef HIDE_SPOOF_IPS
                   IsOperAdmin(source_p) ? ip : 
#endif
                   (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                   CurrentTime - target_p->lasttime,
                   (target_p->user) ? (CurrentTime - target_p->user->last) : 0);
		       
      else if (IsOper(target_p))
	sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
		   me.name, source_p->name, class_name, name, 
#ifndef HIDE_SPOOF_IPS
		   MyOper(source_p) ? ip : 
#endif
		   (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
		   CurrentTime - target_p->lasttime,
		   (target_p->user)?(CurrentTime - target_p->user->last):0);

      break;
    case STAT_SERVER:
      if(!IsOperAdmin(source_p))
        name = get_client_name(target_p, MASK_IP);

      sendto_one(source_p, form_str(RPL_TRACESERVER),
		 me.name, source_p->name, class_name, link_s_p,
		 link_u_p, name, *(target_p->serv->by) ?
		 target_p->serv->by : "*", "*",
		 me.name, CurrentTime - target_p->lasttime);
      break;
      
    default: /* ...we actually shouldn't come here... --msa */
      sendto_one(source_p, form_str(RPL_TRACENEWTYPE), me.name,
		 source_p->name, name);
      break;
    }

  return 0;
}

/* ltrace_spy()
 *
 * input        - pointer to client
 * output       - none
 * side effects - hook event doing_trace is called
 */
static void ltrace_spy(struct Client *source_p)
{
  struct hook_spy_data data;

  data.source_p = source_p;

  hook_call_event("doing_ltrace", &data);
}

/* 
 * this slow version needs to be used for hostmasks *sigh
 *
 * next_client_double - find the next matching client. 
 * The search can be continued from the specified client entry. 
 * Normal usage loop is:
 *
 *      for (x = client; x = next_client_double(x,mask); x = x->next)
 *              HandleMatchingClient;
 *            
 */
static struct Client* 
next_client_double(struct Client *next, /* First client to check */
                   const char* ch)      /* search string (may include wilds) */
{
  struct Client *tmp = next;

  next = find_client(ch);

  if (next == NULL)
    next = tmp;

  if (tmp && tmp->prev == next)
    return NULL;
  if (next != tmp)
    return next;
  for ( ; next; next = next->next)
    {
      if (match(ch,next->name) || match(next->name,ch))
        break;
    }
  return next;
}
