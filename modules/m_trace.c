/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_trace.c: Traces a path to a client/server.
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
#include "tools.h"
#include "hook.h"
#include "client.h"
#include "hash.h"
#include "common.h"
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
#include "s_conf.h"
#include "irc_getnameinfo.h"

static void m_trace(struct Client *, struct Client *, int, char **);
static void ms_trace(struct Client*, struct Client*, int, char**);
static void mo_trace(struct Client*, struct Client*, int, char**);

#ifdef IPV6
static void mo_trace4(struct Client*, struct Client*, int, char**);
static void mo_trace6(struct Client*, struct Client*, int, char**);
#endif

static void trace_spy(struct Client *);
static void do_actual_trace(int ttype, const char *tname,
			    struct Client*, struct Client*, int, char**);

struct Message trace_msgtab = {
  "TRACE", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_trace, ms_trace, mo_trace, m_ignore}
};

#ifdef IPV6
struct Message trace_msgtab4 = {
  "TRACE4", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_trace, m_ignore, mo_trace4, m_ignore}
};

struct Message trace_msgtab6 = {
  "TRACE6", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_trace, m_ignore, mo_trace6, m_ignore}
};
#endif

#ifndef STATIC_MODULES
void
_modinit(void)
{
  hook_add_event("doing_trace");
  mod_add_cmd(&trace_msgtab);
#ifdef IPV6
  mod_add_cmd(&trace_msgtab4);
  mod_add_cmd(&trace_msgtab6);
#endif
}

void
_moddeinit(void)
{
  hook_del_event("doing_trace");
  mod_del_cmd(&trace_msgtab);
#ifdef IPV6
  mod_del_cmd(&trace_msgtab4);
  mod_del_cmd(&trace_msgtab6);
#endif
}
const char *_version = "$Revision$";
#endif

static int report_this_status(struct Client *source_p, struct Client *target_p,
			      int dow, int link_u_p, int link_u_s);

/*
 * m_trace()
 *
 *	parv[0] = sender prefix
 *	parv[1] = target client/server to trace
 */
static void
m_trace(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  const char *tname;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  sendto_one(source_p, form_str(RPL_ENDOFTRACE),
             me.name, source_p->name, tname);
}


/*
** mo_trace
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static void
mo_trace(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  dlink_node *ptr;
  const char *tname;

  if (!IsClient(source_p))
    return;
    
  if (parc > 2)
    if (hunt_server(client_p, source_p, ":%s TRACE %s :%s", 2, parc, parv))
      return;
  
  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  switch (hunt_server(client_p, source_p, ":%s TRACE :%s", 1, parc, parv))
    {
    case HUNTED_PASS: /* note: gets here only if parv[1] exists */
      {
        struct Client *ac2ptr = NULL;
        
        if ((ac2ptr = find_client(tname)) == NULL)
        {
          DLINK_FOREACH(ptr, global_client_list.head)
          {
            ac2ptr = ptr->data;

            if (match(tname, ac2ptr->name) || match(ac2ptr->name, tname))
              break;
            else
              ac2ptr = NULL;
          }
	}
 
	if (ac2ptr != NULL)
          sendto_one(source_p, form_str(RPL_TRACELINK), me.name, source_p->name,
                     ircd_version, tname, ac2ptr->from->name);
        else
          sendto_one(source_p, form_str(RPL_TRACELINK), me.name, source_p->name,
                     ircd_version, tname, "ac2ptr_is_NULL!!");
        return;
      }
    case HUNTED_ISME:
      do_actual_trace(AF_UNSPEC, tname, client_p, source_p, parc, parv);
      break;
    default:
      return;
    }
}

#ifdef IPV6
static void
mo_trace4(struct Client *client_p, struct Client *source_p,
	  int parc, char *parv[])
{
  const char *tname;

  if (!IsClient(source_p))
    return;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

    
  do_actual_trace(AF_INET, tname, client_p, source_p, parc, parv);
}

static void
mo_trace6(struct Client *client_p, struct Client *source_p,
	  int parc, char *parv[])
{
  const char *tname;

  if (!IsClient(source_p))
    return;

  if (parc > 1)
    tname = parv[1];
  else
    tname = me.name;

  do_actual_trace(AF_INET6, tname, client_p, source_p, parc, parv);
}
#endif

static void
do_actual_trace(int ttype, const char *tname,
		struct Client *client_p, struct Client *source_p,
		int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct ConfItem *conf;
  struct ClassItem *cltmp;
  int doall, link_s[HARD_FDLIMIT], link_u[HARD_FDLIMIT];
  int cnt = 0, wilds, dow;
  dlink_node *gcptr;	/* global_client_list ptr */
  dlink_node *ptr;

  trace_spy(source_p);

  doall = (parv[1] && (parc > 1)) ? match(tname, me.name): TRUE;
  wilds = !parv[1] || strchr(tname, '*') || strchr(tname, '?');
  dow = wilds || doall;
  
  set_time();
  if(!IsOper(source_p) || !dow) /* non-oper traces must be full nicks */
                              /* lets also do this for opers tracing nicks */
    {
      const char* name;
      const char* class_name;
      char ipaddr[HOSTIPLEN];

      target_p = find_client(tname);
      
      if(target_p && IsPerson(target_p)) 
      {
        name = get_client_name(target_p, HIDE_IP);
        /* should we not use sockhost here? - stu */
        irc_getnameinfo((struct sockaddr*)&target_p->localClient->ip,
            target_p->localClient->ip.ss_len, ipaddr, HOSTIPLEN, NULL, 0,
            NI_NUMERICHOST);

        class_name = get_client_class(target_p);

        if (IsOper(target_p))
        {
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                     me.name, parv[0], class_name, name, 
                     IsIPSpoof(target_p) ? "255.255.255.255" : ipaddr,
                     CurrentTime - target_p->lasttime,
                     (target_p->user) ? (CurrentTime - target_p->user->last) : 0);
        }
        else
        {
          sendto_one(source_p,form_str(RPL_TRACEUSER),
                     me.name, parv[0], class_name, name, 
                     MyOper(source_p) ? ipaddr : 
		     (IsIPSpoof(target_p) ? "255.255.255.255" : ipaddr),
                     CurrentTime - target_p->lasttime,
                     (target_p->user)?(CurrentTime - target_p->user->last):0);
        }
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
    DLINK_FOREACH(gcptr, global_client_list.head)
    {
      target_p = gcptr->data;

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
   
  /* report all direct connections */
  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    if (IsInvisible(target_p) && dow &&
	!(MyConnect(source_p) && IsOper(source_p)) &&
	!IsOper(target_p) && (target_p != source_p))
      continue;
    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

#ifdef IPV6
    if ((ttype == AF_UNSPEC) || 
	(target_p->localClient->ip.ss.ss_family == ttype))
      cnt = report_this_status(source_p, target_p, dow, 0, 0);
#else
    cnt = report_this_status(source_p, target_p, dow, 0, 0);
#endif
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

#ifdef IPV6
    if ((ttype == AF_UNSPEC) || 
	(target_p->localClient->ip.ss.ss_family == ttype))
      cnt = report_this_status(source_p, target_p, dow,
			       link_u[target_p->localClient->fd],
			       link_s[target_p->localClient->fd]);
#else
    cnt = report_this_status(source_p, target_p, dow,
			     link_u[target_p->localClient->fd],
			     link_s[target_p->localClient->fd]);
#endif
  }

  /* This section is to report the unknowns */
  DLINK_FOREACH(ptr, unknown_list.head)
  {
    target_p = ptr->data;

    if (!doall && wilds && !match(tname, target_p->name))
      continue;
    if (!dow && irccmp(tname, target_p->name))
      continue;

#ifdef IPV6
    if ((ttype == AF_UNSPEC) || 
	(target_p->localClient->ip.ss.ss_family == ttype))
      cnt = report_this_status(source_p, target_p, dow, 0, 0);
#else
    cnt = report_this_status(source_p, target_p, dow, 0, 0);
#endif
  }

  DLINK_FOREACH(ptr, class_items.head)
  {
    conf = ptr->data;
    cltmp = (struct ClassItem *)map_to_conf(conf);
    if (CurrUserCount(cltmp) > 0)
      sendto_one(source_p, form_str(RPL_TRACECLASS), me.name,
		 parv[0], conf->name, CurrUserCount(cltmp));
  }
  sendto_one(source_p, form_str(RPL_ENDOFTRACE),me.name, parv[0],tname);
}


/*
** ms_trace
**      parv[0] = sender prefix
**      parv[1] = servername
*/
static void
ms_trace(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s TRACE %s :%s", 2, parc, parv))
    return;

  if (IsOper(source_p))
    mo_trace(client_p, source_p, parc, parv);
}

/* report_this_status()
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- counter of number of hits
 * side effects - NONE
 */
static int
report_this_status(struct Client *source_p, struct Client *target_p,
                   int dow, int link_u_p, int link_s_p)
{
  const char* name;
  const char* class_name;
  char  ip[HOSTIPLEN];
  int cnt=0;

  /* Should this be sockhost? - stu */
  irc_getnameinfo((struct sockaddr*)&target_p->localClient->ip, 
        target_p->localClient->ip.ss_len, ip, HOSTIPLEN, NULL, 0, 
        NI_NUMERICHOST);
  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(target_p);

  set_time();

  switch(target_p->status)
    {
    case STAT_CONNECTING:
      sendto_one(source_p, form_str(RPL_TRACECONNECTING), me.name,
                 source_p->name, class_name, 
		 IsOperAdmin(source_p) ? name : target_p->name);
		   
      cnt++;
      break;
    case STAT_HANDSHAKE:
      sendto_one(source_p, form_str(RPL_TRACEHANDSHAKE), me.name,
                 source_p->name, class_name, 
                 IsOperAdmin(source_p) ? name : target_p->name);
		   
      cnt++;
      break;
    case STAT_ME:
      break;
    case STAT_UNKNOWN:
      /* added time -Taner */
      sendto_one(source_p, form_str(RPL_TRACEUNKNOWN),
		 me.name, source_p->name, class_name, name, ip,
		 target_p->firsttime ? CurrentTime - target_p->firsttime : -1);
      cnt++;
      break;
    case STAT_CLIENT:
      /* Only opers see users if there is a wildcard
       * but anyone can see all the opers.
       */
      if ((IsOper(source_p) &&
	   (MyClient(source_p) || !(dow && IsInvisible(target_p))))
	  || !dow || IsOper(target_p))
	{
          if (IsAdmin(target_p) && !ConfigFileEntry.hide_spoof_ips)
	    sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                       me.name, source_p->name, class_name, name,
                       IsOperAdmin(source_p) ? ip : "255.255.255.255",
                       CurrentTime - target_p->lasttime,
                       (target_p->user) ? (CurrentTime - target_p->user->last) : 0);
		       
	  else if (IsOper(target_p))
          {
	    if (ConfigFileEntry.hide_spoof_ips)
	      sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
		         me.name, source_p->name, class_name, name, 
		         IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		         CurrentTime - target_p->lasttime,
		         (target_p->user)?(CurrentTime - target_p->user->last):0);
	    else
              sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                         me.name, source_p->name, class_name, name,
                         MyOper(source_p) ? ip :
                         (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                         CurrentTime - target_p->lasttime,
                         (target_p->user)?(CurrentTime - target_p->user->last):0);
	  }		       
	  else
          {
            if (ConfigFileEntry.hide_spoof_ips)
	      sendto_one(source_p, form_str(RPL_TRACEUSER),
		         me.name, source_p->name, class_name, name,
                         IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		         CurrentTime - target_p->lasttime,
		         (target_p->user)?(CurrentTime - target_p->user->last):0);
	    else
              sendto_one(source_p, form_str(RPL_TRACEUSER),
                         me.name, source_p->name, class_name, name,
                         MyOper(source_p) ? ip :
                         (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                         CurrentTime - target_p->lasttime,
                         (target_p->user)?(CurrentTime - target_p->user->last):0);
	  }
	  cnt++;
	}
      break;
    case STAT_SERVER:
      if(!IsOperAdmin(source_p))
        name = get_client_name(target_p, MASK_IP);

      sendto_one(source_p, form_str(RPL_TRACESERVER),
		 me.name, source_p->name, class_name, link_s_p,
		 link_u_p, name, *(target_p->serv->by) ?
		 target_p->serv->by : "*", "*",
		 me.name, CurrentTime - target_p->lasttime);
      cnt++;
      break;
      
    default: /* ...we actually shouldn't come here... --msa */
      sendto_one(source_p, form_str(RPL_TRACENEWTYPE), me.name,
		 source_p->name, name);
      cnt++;
      break;
    }

  return(cnt);
}

/* trace_spy()
 *
 * input        - pointer to client
 * output       - none
 * side effects - hook event doing_trace is called
 */
static void
trace_spy(struct Client *source_p)
{
  struct hook_spy_data data;

  data.source_p = source_p;

  hook_call_event("doing_trace", &data);
}
