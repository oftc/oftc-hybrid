/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_squit.c: Makes a server quit.
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
#include "common.h"      /* FALSE bleah */
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void ms_squit(struct Client*, struct Client*, int, char**);
static void mo_squit(struct Client*, struct Client*, int, char**);

struct Message squit_msgtab = {
  "SQUIT", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_squit, mo_squit}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&squit_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&squit_msgtab);
}
const char *_version = "$Revision$";
#endif
struct squit_parms 
{
  char *server_name;
  struct Client *target_p;
};

static struct squit_parms *find_squit(struct Client *client_p,
                                      struct Client *source_p,
                                      char *server);


/*
 * mo_squit - SQUIT message handler
 *      parv[0] = sender prefix
 *      parv[1] = server name
 *      parv[2] = comment
 */
static void mo_squit(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  struct squit_parms *found_squit;
  char  *comment = (parc > 2 && parv[2]) ? parv[2] : client_p->name;

  if (!IsOperRemote(source_p))
    {
      sendto_one(source_p,":%s NOTICE %s :You need remote = yes;",me.name,parv[0]);
      return;
    }

  if(parc < 2)
    {
      sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), 
              me.name, parv[0], "SQUIT");
      return;
    }

  if( (found_squit = find_squit(client_p,source_p,parv[1])) )
    {
      if(MyConnect(found_squit->target_p))
	    {
	      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                "Received SQUIT %s from %s (%s)",
                found_squit->target_p->name,
                get_client_name(source_p, HIDE_IP), comment);
          ilog(L_NOTICE, "Received SQUIT %s from %s (%s)",
                found_squit->target_p->name, get_client_name(source_p, HIDE_IP),
                comment);
	    }
      exit_client(client_p, found_squit->target_p, source_p, comment);
      return;
    }
  else
    {
      sendto_one(source_p, form_str(ERR_NOSUCHSERVER), me.name, parv[0], parv[1]);
    }
}

/*
 * ms_squit - SQUIT message handler
 *      parv[0] = sender prefix
 *      parv[1] = server name
 *      parv[2] = comment
 */
static void ms_squit(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  struct squit_parms *found_squit;
  char  *comment = (parc > 2 && parv[2]) ? parv[2] : client_p->name;

  if(parc < 2)
  {
    exit_client(client_p, client_p, source_p, comment);
    return;
  }

  if((found_squit = find_squit(client_p, source_p, parv[1])))
  {
    /*
    **  Notify all opers, if my local link is remotely squitted
    */
    if (MyConnect(found_squit->target_p))
    {
      sendto_gnotice_flags(FLAGS_CCONN, L_OPER, me.name, &me, NULL,
          "Remote SQUIT %s from %s (%s)", found_squit->server_name,
          source_p->name, comment);
        
      ilog(L_TRACE, "SQUIT From %s : %s (%s)", parv[0],
	   found_squit->server_name, comment);

    }
    exit_client(client_p, found_squit->target_p, source_p, comment);
    return;
  }
}


/*
 * find_squit
 * inputs	- local server connection
 *		-
 *		-
 * output	- pointer to struct containing found squit or none if not found
 * side effects	-
 */
static struct squit_parms *
find_squit(struct Client *client_p, struct Client *source_p, char *server)
{
  static struct squit_parms found_squit;
  static struct Client *target_p;
  struct ConfItem *aconf;

  found_squit.target_p = NULL;
  found_squit.server_name = NULL;

  /*
  ** To accomodate host masking, a squit for a masked server
  ** name is expanded if the incoming mask is the same as
  ** the server name for that link to the name of link.
  */
  if ((*server == '*') && IsServer(client_p))
    {
      aconf = client_p->serv->sconf;
      if (aconf)
        {
	  if (!irccmp(server, my_name_for_link(me.name, aconf)))
	    {
	       found_squit.server_name = client_p->name;
	       found_squit.target_p = client_p;
	    }
	}
    }

  /*
  ** The following allows wild cards in SQUIT. Only useful
  ** when the command is issued by an oper.
  */
  for (target_p = GlobalClientList; (target_p = next_client(target_p, server));
       target_p = target_p->next)
    {
      if (IsServer(target_p) || IsMe(target_p))
	break;
    }

  found_squit.target_p = target_p;
  found_squit.server_name = server;

  if (target_p && IsMe(target_p))
    {
       if (IsClient(client_p))
         {
		 sendto_one(source_p,":%s NOTICE %s :You are trying to squit me.",me.name,client_p->name);
	         found_squit.target_p = NULL;
         }
       else
         {
           found_squit.target_p = client_p;
           found_squit.server_name = client_p->name;
         }
       
    }

  if(found_squit.target_p != NULL)
    return &found_squit;
  else
    return(NULL);
}
