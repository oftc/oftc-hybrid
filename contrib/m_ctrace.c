/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ctrace.c: Traces a given class
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
 *  $Id: m_ctrace.c 606 2006-06-08 22:35:55Z stu $
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
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "irc_getnameinfo.h"

static void do_ctrace(struct Client *, int, char **);
static void mo_ctrace(struct Client *, struct Client *, int, char *[]);

struct Message ctrace_msgtab = {
  "CTRACE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_ctrace, m_ignore}
};

#ifndef STATIC_MODULES
const char *_version = "$Revision: 606 $";
static struct Callback *ctrace_cb;

static void *
va_ctrace(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  do_ctrace(source_p, parc, parv);
  return NULL;
}

void
_modinit(void)
{
  ctrace_cb = register_callback("doing_ctrace", va_ctrace);
  mod_add_cmd(&ctrace_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&ctrace_msgtab);
  uninstall_hook(ctrace_cb, va_ctrace);
}
#endif

static int report_this_status(struct Client *, struct Client *);

/*
** mo_ctrace
**      parv[0] = sender prefix
**      parv[1] = classname
*/
static void
mo_ctrace(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, parv[0], "CTRACE");
    return;
  }

#ifdef STATIC_MODULES
  do_ctrace(source_p, parc, parv);
#else
  execute_callback(ctrace_cb, source_p, parc, parv);
#endif
}

/*
 * do_ctrace
 */
static void
do_ctrace(struct Client *source_p, int parc, char **parv)
{
  struct Client *target_p = NULL;
  char *class_looking_for;
  const char *class_name;
  dlink_node *ptr;

  class_looking_for = parv[1];

  /* report all direct connections */

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    class_name = get_client_class(target_p);
    if ((class_name != NULL) && match(class_looking_for, class_name))
      report_this_status(source_p, target_p);
  }

  sendto_one(source_p, form_str(RPL_ENDOFTRACE), me.name,
             parv[0], class_looking_for);
}

/*
 * report_this_status
 *
 * inputs	- pointer to client to report to
 * 		- pointer to client to report about
 * output	- counter of number of hits
 * side effects - NONE
 */
static int
report_this_status(struct Client *source_p, struct Client *target_p)
{
  const char *name = NULL;
  const char *class_name = NULL;
  char ip[HOSTIPLEN];
  int cnt = 0;

  /* Should this be sockhost? - stu */
  irc_getnameinfo((struct sockaddr*)&target_p->localClient->ip, 
        target_p->localClient->ip.ss_len, ip, HOSTIPLEN, NULL, 0, 
        NI_NUMERICHOST);
  name = get_client_name(target_p, HIDE_IP);
  class_name = get_client_class(target_p);

  switch(target_p->status)
  {
    case STAT_CLIENT:

      if ((IsOper(source_p) &&
          (MyClient(source_p) || !IsInvisible(target_p)))
          || IsOper(target_p))
      {
        if (IsAdmin(target_p) && !ConfigFileEntry.hide_spoof_ips)
          sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                       me.name, source_p->name, class_name, name,
                       IsAdmin(source_p) ? ip : "255.255.255.255",
                       CurrentTime - target_p->lasttime,
                       CurrentTime - target_p->localClient->last);
          else if (IsOper(target_p))
          {
            if (ConfigFileEntry.hide_spoof_ips)
	      sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
		         me.name, source_p->name, class_name, name, 
		         IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		         CurrentTime - target_p->lasttime,
		         CurrentTime - target_p->localClient->last);
	    else   
              sendto_one(source_p, form_str(RPL_TRACEOPERATOR),
                         me.name, source_p->name, class_name, name,
                         (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                         CurrentTime - target_p->lasttime,
                         CurrentTime - target_p->localClient->last);
          }
	  else
          {
            if (ConfigFileEntry.hide_spoof_ips)
	      sendto_one(source_p, form_str(RPL_TRACEUSER),
		         me.name, source_p->name, class_name, name,
                         IsIPSpoof(target_p) ? "255.255.255.255" : ip,
		         CurrentTime - target_p->lasttime,
		         CurrentTime - target_p->localClient->last);
            else
              sendto_one(source_p, form_str(RPL_TRACEUSER),
                         me.name, source_p->name, class_name, name,
                         (IsIPSpoof(target_p) ? "255.255.255.255" : ip),
                         CurrentTime - target_p->lasttime,
                         CurrentTime - target_p->localClient->last);
          }
	  cnt++;
        }
      break;
    case STAT_SERVER:
      if(!IsAdmin(source_p))
        name = get_client_name(target_p, MASK_IP);

      sendto_one(source_p, form_str(RPL_TRACESERVER),
		 me.name, source_p->name, class_name, 0,
		 0, name, *(target_p->serv->by) ?
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

  return cnt;
}
