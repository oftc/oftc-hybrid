/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_resv.c: Reserves(jupes) a nickname or channel.
 *
 *  Copyright (C) 2001-2002 Hybrid Development Team
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
#include "channel.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"
#include "resv.h"
#include "hash.h"

static void mo_resv(struct Client *, struct Client *, int, char **);
static void ms_resv(struct Client *, struct Client *, int, char **);
static void mo_unresv(struct Client *, struct Client *, int, char **);

struct Message resv_msgtab = {
  "RESV", 0, 0, 3, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {m_ignore, m_not_oper, ms_resv, mo_resv}
};

struct Message unresv_msgtab = {
  "UNRESV", 0, 0, 2, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {m_ignore, m_not_oper, m_ignore, mo_unresv}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&resv_msgtab);
  mod_add_cmd(&unresv_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&resv_msgtab);
  mod_del_cmd(&unresv_msgtab);
}

const char *_version = "$Revision$";
#endif

/* ms_resv()
 *      parv[0] = sender prefix
 *      parv[1] = channel/nick to resv
 *
 */

static void ms_resv(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  if(EmptyString(parv[1]))
    return;

  if(IsChannelName(parv[1]))
  {
    struct ResvChannel *resv_p;

    resv_p = create_channel_resv(parv[1], parv[2], 0);

    if(!(resv_p))
      return;                                                  

    sendto_realops_flags(FLAGS_ALL, L_OPER, NULL,
                         "%s has placed a global RESV on channel: %s [%s]",
                         get_oper_name(source_p),
                         resv_p->name, resv_p->reason);
  }
  else if(clean_resv_nick(parv[1]))
  {
    struct ResvNick *resv_p;

    if((strchr(parv[1], '*') || strchr(parv[1], '?')) && !IsAdmin(source_p))
      return;

    resv_p = create_nick_resv(parv[1], parv[2], 0);

    if(!(resv_p))
      return;

    sendto_realops_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                         "%s has placed a global RESV on nick: %s [%s]",
             get_oper_name(source_p),
             resv_p->name, resv_p->reason);
  }
  sendto_server(client_p, NULL, NULL, NOCAPS, NOCAPS, NOFLAGS, 
             ":%s RESV :%s", me.name, parv[1]);
}



/*
 * mo_resv()
 *      parv[0] = sender prefix
 *      parv[1] = channel/nick to forbid
 */

static void mo_resv(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  if(BadPtr(parv[1]))
    return;

  if(IsChannelName(parv[1]))
  {
    struct ResvChannel *resv_p;
    
    resv_p = create_channel_resv(parv[1], parv[2], 0);
  
    if(!(resv_p))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A RESV has already been placed on channel: %s",
                 me.name, source_p->name, parv[1]);
      return;
    }
    
    sendto_one(source_p,
               ":%s NOTICE %s :A local RESV has been placed on channel: %s [%s]",
               me.name, source_p->name, resv_p->name, resv_p->reason);
	       
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                         "%s has placed a local RESV on channel: %s [%s]",
             	         get_oper_name(source_p),
		         resv_p->name, resv_p->reason);
  }
  else if(clean_resv_nick(parv[1]))
  {
    struct ResvNick *resv_p;

    if((strchr(parv[1], '*') || strchr(parv[1], '?')) && !IsAdmin(source_p))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :You must be an admin to perform a wildcard RESV",
		 me.name, source_p->name);
      return;
    }

    resv_p = create_nick_resv(parv[1], parv[2], 0);

    if(!(resv_p))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A RESV has already been placed on nick: %s",
		 me.name, source_p->name, parv[1]);
      return;
    }

    sendto_one(source_p,
               ":%s NOTICE %s :A local RESV has been placed on nick: %s [%s]",
	       me.name, source_p->name,
	       resv_p->name, resv_p->reason);

    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                         "%s has placed a local RESV on nick: %s [%s]",
			 get_oper_name(source_p),
			 resv_p->name, resv_p->reason);
  }			 
  else
    sendto_one(source_p, 
              ":%s NOTICE %s :You have specified an invalid resv: [%s]",
	      me.name, source_p->name, parv[1]);
    sendto_server(NULL, NULL, NULL, NOCAPS, NOCAPS, NOFLAGS,
                         ":%s RESV :%s", me.name, parv[1]);
}

/*
 * mo_unresv()
 *     parv[0] = sender prefix
 *     parv[1] = channel/nick to unforbid
 */

static void mo_unresv(struct Client *client_p, struct Client *source_p,
                      int parc, char *parv[])
{
  if(IsChannelName(parv[1]))
  {
    struct ResvChannel *resv_p;
    
    if(!ResvChannelList || 
       !(resv_p = (struct ResvChannel *)hash_find_resv(parv[1])))
    {
      sendto_one(source_p, 
                 ":%s NOTICE %s :A RESV does not exist for channel: %s",
	         me.name, source_p->name, parv[1]);
      return;
    }
  
    else if(resv_p->conf)
    {
      sendto_one(source_p,
         ":%s NOTICE %s :The RESV for channel: %s is in the config file and must be removed by hand.",
                 me.name, source_p->name, parv[1]);
      return;	       
    }
    /* otherwise, delete it */
    else
    {
      delete_channel_resv(resv_p);

      sendto_one(source_p,
                 ":%s NOTICE %s :The local RESV has been removed on channel: %s",
  	         me.name, source_p->name, parv[1]);
		 
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                           "%s has removed the local RESV for channel: %s",
	  		   get_oper_name(source_p), parv[1]);
	      
    }
  }
  else if(clean_resv_nick(parv[1]))
  {
    struct ResvNick *resv_p;

    if(!ResvNickList || !(resv_p = return_nick_resv(parv[1])))
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :A RESV does not exist for nick: %s",
		 me.name, source_p->name, parv[1]);
      return;
    }

    else if(resv_p->conf)
    {
      sendto_one(source_p,
         ":%s NOTICE %s :The RESV for nick: %s is in the config file and must be removed by hand.",
	         me.name, source_p->name, parv[1]);
      return;
    }

    else
    {
      delete_nick_resv(resv_p);

      sendto_one(source_p,
                 ":%s NOTICE %s :The local RESV has been removed on nick: %s",
		 me.name, source_p->name, parv[1]);

      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                           "%s has removed the local RESV for nick: %s",
			   get_oper_name(source_p), parv[1]);
    }
  }
}
