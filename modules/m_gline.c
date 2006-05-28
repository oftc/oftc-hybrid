/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_gline.c: Votes towards globally banning a mask.
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
#include "tools.h"
#include "handlers.h"
#include "s_gline.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "hostmask.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "parse_aline.h"
#include "send.h"
#include "msg.h"
#include "fileio.h"
#include "s_serv.h"
#include "hash.h"
#include "parse.h"
#include "modules.h"
#include "list.h"
#include "s_log.h"

#define GLINE_NOT_PLACED     0
#define GLINE_ALREADY_VOTED -1
#define GLINE_PLACED         1

/* internal functions */
static void set_local_gline(
			    struct Client *source_p,
                            const char *user, const char *host,
                            const char *reason);


static int check_majority_gline(struct Client *source_p,
				const char *oper_nick, const char *oper_user,
				const char *oper_host, const char *oper_server,
				const char *user, const char *host,
				const char *reason);

static void add_new_majority_gline(const char *, const char *, const char *,
                                   const char *, const char *, const char *,
                                   const char *);

static int check_wild_gline(char *, char *);
static int invalid_gline(struct Client *, const char *);
		       
static void ms_gline(struct Client *, struct Client *, int, char **);
static void mo_gline(struct Client *, struct Client *, int, char **);
static void mo_ungline(struct Client *, struct Client *, int, char **);

struct Message gline_msgtab = {
  "GLINE", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, ms_gline, mo_gline, m_ignore}
};

struct Message ungline_msgtab = {
  "UNGLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_error, mo_ungline, m_ignore}
};
		
#ifndef STATIC_MODULES
void
_modinit(void)
{
    mod_add_cmd(&gline_msgtab);
    mod_add_cmd(&ungline_msgtab);
    add_capability("GLN", CAP_GLN, 1);
}

void
_moddeinit(void)
{
  mod_del_cmd(&gline_msgtab);
  mod_del_cmd(&ungline_msgtab);
  delete_capability("GLN");
}

const char *_version = "$Revision$";
#endif

/* mo_gline()
 *
 * inputs       - The usual for a m_ function
 * output       -
 * side effects -
 *
 * Place a G line if 3 opers agree on the identical user@host
 * 
 */
/* Allow this server to pass along GLINE if received and
 * GLINES is not defined.
 *
 */

static void
mo_gline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  char *user = NULL;
  char *host = NULL;	     /* user and host of GLINE "victim" */
  const char *reason = NULL; /* reason for "victims" demise     */
  char star[] = "*";
  char tempuser[USERLEN * 2 + 2];
  char temphost[HOSTLEN * 2 + 2];

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :GLINE disabled",
               me.name, source_p->name);
    return;
  }

  if (!IsOperGline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if ((host = strchr(parv[1], '@')) || *parv[1] == '*')
  {
    /* Explicit user@host mask given */
    if (host != NULL)	/* Found user@host */
    {
      user = parv[1];   /* here is user part */
      *(host++) = '\0'; /* and now here is host */

      /* gline for "@host", use *@host */
      if (*user == '\0')
	user = star;
    }
    else
    {
      user = star; /* no @ found, assume its *@somehost */
      host = parv[1];
    }
	      
    if (*host == '\0') /* duh. no host found, assume its '*' host */
      host = star;

    strlcpy(tempuser, collapse(user), sizeof(tempuser)); /* allow for '*' */
    strlcpy(temphost, collapse(host), sizeof(temphost));
    user = tempuser;
    host = temphost;
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :Can't G-Line a nick use user@host",
	       me.name, source_p->name);
    return;
  }

  if (invalid_gline(source_p, user))
    return;
			
  /* Not enough non-wild characters were found,
   * assume they are trying to gline *@*.
   */

  if (check_wild_gline(user, host))
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Please include at least %d non-wildcard characters with the user@host",
               me.name, parv[0], ConfigFileEntry.min_nonwildcard);
    return;
  }

  reason = parv[2];

  /* If at least 3 opers agree this user should be G lined then do it */
  if (check_majority_gline(source_p, source_p->name, source_p->username,
                           source_p->host, me.name, user, host, reason) ==
      GLINE_ALREADY_VOTED)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :This server or oper has already voted",
               me.name, source_p->name);
    return;
  }

  /* call these two functions first so the 'requesting' notice always comes
   * before the 'has triggered' notice.  -bill
   */
  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "%s!%s@%s on %s is requesting gline for [%s@%s] [%s]",
                       source_p->name, source_p->username, source_p->host,
                       me.name, user, host, reason);
  ilog(L_TRACE, "#gline for %s@%s [%s] requested by %s!%s@%s",
       user, host, reason, source_p->name, source_p->username,
       source_p->host);

  /* 4 param version for hyb-7 servers */
  sendto_server(NULL, source_p, NULL, CAP_GLN|CAP_SID, NOCAPS,
		LL_ICLIENT, ":%s GLINE %s %s :%s",
		ID(source_p), user, host, reason);
  sendto_server(NULL, source_p, NULL, CAP_GLN, CAP_SID,
		LL_ICLIENT, ":%s GLINE %s %s :%s",
		source_p->name, user, host, reason);

  /* 8 param for hyb-6 */
  sendto_server(NULL, NULL, NULL, CAP_SID, CAP_GLN, NOFLAGS,
		":%s GLINE %s %s %s %s %s %s :%s",
		me.name, ID(source_p), source_p->username,
		source_p->host, source_p->user->server->name, user, host,
		reason);
  sendto_server(NULL, NULL, NULL, NOCAPS, CAP_GLN|CAP_SID, NOFLAGS,
		":%s GLINE %s %s %s %s %s %s :%s",
		me.name, source_p->name, source_p->username,
		source_p->host, source_p->user->server->name, user, host,
		reason);
}

/* ms_gline()
 *
 * inputs       - The usual for a m_ function
 * output       -
 * side effects -
 *
 * Place a G line if 3 opers agree on the identical user@host
 * 
 */
/* Allow this server to pass along GLINE if received and
 * GLINES is not defined.
 */

static void
ms_gline(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  /* These are needed for hyb6 compatibility.. if its ever removed we can
   * just use source_p->username etc.. 
   */
  const char *oper_nick = NULL;   /* nick of oper requesting GLINE     */
  const char *oper_user = NULL;   /* username of oper requesting GLINE */
  const char *oper_host = NULL;   /* hostname of oper requesting GLINE */
  const char *oper_server = NULL; /* server of oper requesting GLINE   */
  const char *reason = NULL;      /* reason for "victims" demise       */
  char *user = NULL;
  char *host = NULL;              /* user and host of GLINE "victim"   */
  struct Client *target_p;

  assert(source_p->user != NULL);
  assert(source_p->user->server != NULL);

  /* hyb-7 style gline (post beta3) */
  if (parc == 4 && IsPerson(source_p))
  {
    oper_nick   = source_p->name;
    oper_user   = source_p->username;
    oper_host   = source_p->host;
    oper_server = source_p->user->server->name;
    user        = parv[1];
    host        = parv[2];
    reason      = parv[3];
  }
  /* or it's a hyb-6 style */
  else if (parc == 8 && IsServer(source_p))
  {
    oper_nick   = parv[1];
    oper_user   = parv[2];
    oper_host   = parv[3];
    oper_server = parv[4];
    user        = parv[5];
    host        = parv[6];
    reason      = parv[7];
  }
  /* none of the above */
  else
    return;

  /* Its plausible that the server and/or client dont actually exist,
   * and its faked, as the oper isnt sending the gline..
   * check they're real --fl_ */
  /* we need acptr for LL introduction anyway -davidt */
  if ((target_p = find_server(oper_server)))
  {
    if ((target_p = find_client(oper_nick)) == NULL)
      return;
  }
  else
    return;

  if (invalid_gline(target_p, user))
     return;
    
  /* send in hyb-7 to compatible servers */
  sendto_server(client_p, target_p, NULL, CAP_GLN, NOCAPS, LL_ICLIENT,
                ":%s GLINE %s %s :%s",
                oper_nick, user, host, reason);
  /* hyb-6 version to the rest */
  sendto_server(client_p, NULL, NULL, NOCAPS, CAP_GLN, NOFLAGS,
                ":%s GLINE %s %s %s %s %s %s :%s",
                oper_server, oper_nick, oper_user, oper_host,
                oper_server, user, host, reason);

  if (ConfigFileEntry.glines)
  {
     /* I dont like the idea of checking for x non-wildcard chars in a
      * gline.. it could lead to a desync... but we have to stop people
      * glining *@*..   -- fl
      */
     if (check_wild_gline(user, host))
     {
       sendto_realops_flags(UMODE_ALL, L_ALL, 
                    "%s!%s@%s on %s is requesting a gline without %d non-wildcard characters for [%s@%s] [%s]",
                     oper_nick, oper_user, oper_host, oper_server, ConfigFileEntry.min_nonwildcard,
                     user, host, reason);
       return;
     }

     /* If at least 3 opers agree this user should be G lined then do it */
     if (check_majority_gline(source_p, oper_nick, oper_user, oper_host,
                              oper_server, user, host, reason) ==
         GLINE_ALREADY_VOTED)
     {
       sendto_realops_flags(UMODE_ALL, L_ALL, "oper or server has already voted");
       return;
     }

     ilog(L_TRACE, "#gline for %s@%s [%s] requested by %s!%s@%s on %s",
          user, host, reason, source_p->name, source_p->username,
          source_p->host, oper_server);

      sendto_realops_flags(UMODE_ALL, L_ALL,
			   "%s!%s@%s on %s is requesting gline for [%s@%s] [%s]",
			   oper_nick, oper_user, oper_host, oper_server,
			   user, host, reason);
  }
}

/* check_wild_gline()
 *
 * inputs       - user, host of gline
 * output       - 1 if not enough non-wildchar char's, 0 if ok
 * side effects - NONE
 */
static int
check_wild_gline(char *user, char *host)
{
  char *p;
  char tmpch;
  unsigned int nonwild = 0;
  const unsigned int min_nonwildcard = ConfigFileEntry.min_nonwildcard;

  p = user;

  while ((tmpch = *p++))
  {
    if (!IsKWildChar(tmpch))
    {
      /* If we find enough non-wild characters, we can
       * break - no point in searching further.
       */
      if (++nonwild >= min_nonwildcard)
        break;
    }
  }

  if (nonwild < min_nonwildcard)
  {
    /* The user portion did not contain enough non-wild
     * characters, try the host.
     */
    p = host;

    while ((tmpch = *p++))
    {
      if (!IsKWildChar(tmpch))
        if (++nonwild >= min_nonwildcard)
          break;
    }
  }

  if (nonwild < min_nonwildcard)
    return(1);
  else
    return(0);
}

/* invalid_gline()
 *
 * inputs       - pointer to source client
 *              - pointer to ident
 * output       - 1 if invalid, 0 if valid
 */
static int
invalid_gline(struct Client *source_p, const char *luser)
{
  if (strchr(luser, '!') != NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid character '!' in gline",
               me.name, source_p->name);
    return(1);
  }

  return(0);
}

/* set_local_gline()
 *
 * inputs	- pointer to client struct of oper
 *		- pointer to victim user
 *		- pointer to victim host
 *		- pointer reason
 * output	- NONE
 * side effects	-
 */
static void
set_local_gline(struct Client *source_p, const char *user,
                const char *host, const char *reason)
{
  char buffer[IRCD_BUFSIZE];
  struct ConfItem *conf;
  struct AccessItem *aconf;
  const char *current_date;
  time_t cur_time;

  set_time();
  cur_time = CurrentTime;
  current_date = smalldate(cur_time);
  conf = make_conf_item(GLINE_TYPE);
  aconf = (struct AccessItem *)map_to_conf(conf);
  ircsprintf(buffer, "%s (%s)", reason, current_date);
  DupString(aconf->reason, buffer);
  DupString(aconf->user, user);
  DupString(aconf->host, host);
  aconf->hold = CurrentTime + ConfigFileEntry.gline_time;
  write_conf_line(source_p, conf, current_date, cur_time);
  /* Now, activate gline against current online clients */
  rehashed_klines = 1;
}

/* add_new_majority_gline()
 * 
 * inputs       - name of operator requesting gline
 * 		- username of operator requesting gline
 * 		- hostname of operator requesting gline
 * 		- servername of operator requesting gline
 * 		- username covered by the gline
 * 		- hostname covered by the gline
 * 		- reason for the gline
 * output       - NONE
 * side effects -
 * This function is called once a majority of opers
 * have agreed on a gline, and it can be placed. The
 * information about an operator being passed to us
 * happens to be the operator who pushed us over the
 * "majority" level needed. See check_majority_gline()
 * for more information.
 */
static void
add_new_majority_gline(const char *oper_nick, const char *oper_user,
                       const char *oper_host, const char *oper_server,
                       const char *user, const char *host,
                       const char *reason)
{
  struct gline_pending *pending = (struct gline_pending *)
    MyMalloc(sizeof(struct gline_pending));

  strlcpy(pending->oper_nick1, oper_nick, sizeof(pending->oper_nick1));
  strlcpy(pending->oper_user1, oper_user, sizeof(pending->oper_user1));
  strlcpy(pending->oper_host1, oper_host, sizeof(pending->oper_host1));

  strlcpy(pending->oper_server1, oper_server, sizeof(pending->oper_server1));

  strlcpy(pending->user, user, sizeof(pending->user));
  strlcpy(pending->host, host, sizeof(pending->host));
  strlcpy(pending->reason1, reason, sizeof(pending->reason1));

  pending->last_gline_time = CurrentTime;
  pending->time_request1   = CurrentTime;

  dlinkAdd(pending, &pending->node, &pending_glines);
}

/* check_majority_gline()
 *
 * inputs       - oper_nick, oper_user, oper_host, oper_server
 *                user,host reason
 *
 * output       - one of three results
 *                
 * GLINE_ALREADY_VOTED	- returned if oper/server has already voted
 * GLINE_PLACED		- returned if this triggers a gline
 * GLINE_NOT_PLACED	- returned if not triggered
 *
 * Side effects -
 *      See if there is a majority agreement on a GLINE on the given user
 *      There must be at least 3 different opers agreeing on this GLINE
 *
 */
static int
check_majority_gline(struct Client *source_p, const char *oper_nick,
                     const char *oper_user, const char *oper_host,
                     const char* oper_server, const char *user,
                     const char *host, const char *reason)
{
  dlink_node *pending_node;
  struct gline_pending *gline_pending_ptr;

  /* if its already glined, why bother? :) -- fl_ */
  if(find_is_glined(host, user))
    return(GLINE_NOT_PLACED);

  /* special case condition where there are no pending glines */
  if (dlink_list_length(&pending_glines) == 0) /* first gline request placed */
  {
    add_new_majority_gline(oper_nick, oper_user, oper_host, oper_server,
                           user, host, reason);
    return(GLINE_NOT_PLACED);
  }

  DLINK_FOREACH(pending_node, pending_glines.head)
  {
    gline_pending_ptr = pending_node->data;

    if ((irccmp(gline_pending_ptr->user,user) == 0) &&
	(irccmp(gline_pending_ptr->host,host) == 0))
    {
      if (((irccmp(gline_pending_ptr->oper_user1,oper_user) == 0) ||
          (irccmp(gline_pending_ptr->oper_host1,oper_host) == 0)) ||
          (irccmp(gline_pending_ptr->oper_server1,oper_server) == 0))
      {
	return(GLINE_ALREADY_VOTED);
      }

      if (gline_pending_ptr->oper_user2[0] != '\0')
      {
	/* if two other opers on two different servers have voted yes */

	if(((irccmp(gline_pending_ptr->oper_user2,oper_user)==0) ||
	    (irccmp(gline_pending_ptr->oper_host2,oper_host)==0)) ||
	   (irccmp(gline_pending_ptr->oper_server2,oper_server)==0))
	{
	  return(GLINE_ALREADY_VOTED);
	}

	/* trigger the gline using the original reason --fl */
	set_local_gline(source_p, user, host, gline_pending_ptr->reason1);
	cleanup_glines(NULL);
	return(GLINE_PLACED);
      }
      else
      {
	strlcpy(gline_pending_ptr->oper_nick2, oper_nick,
	        sizeof(gline_pending_ptr->oper_nick2));
	strlcpy(gline_pending_ptr->oper_user2, oper_user,
	        sizeof(gline_pending_ptr->oper_user2));
	strlcpy(gline_pending_ptr->oper_host2, oper_host,
	        sizeof(gline_pending_ptr->oper_host2));
        strlcpy(gline_pending_ptr->reason2, reason,
                sizeof(gline_pending_ptr->reason2));
        strlcpy(gline_pending_ptr->oper_server2, oper_server,
                sizeof(gline_pending_ptr->oper_server2));
	gline_pending_ptr->last_gline_time = CurrentTime;
	gline_pending_ptr->time_request2 = CurrentTime;
	return(GLINE_NOT_PLACED);
      }
    }
  }

  /* Didn't find this user@host gline in pending gline list
   * so add it.
   */
  add_new_majority_gline(oper_nick, oper_user, oper_host, oper_server,
                         user, host, reason);
  return(GLINE_NOT_PLACED);
}

/*
** m_ungline
** added May 29th 2000 by Toby Verrall <toot@melnet.co.uk>
** added to hybrid-7 7/11/2000 --is
**
**      parv[0] = sender nick
**      parv[1] = gline to remove
*/
static void
mo_ungline(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char star[] = "*";
  char *user, *host;

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :UNGLINE disabled",
               me.name, source_p->name);
    return;
  }

  if (!IsOperUnkline(source_p) || !IsOperGline(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if ((host = strchr(parv[1], '@')) || *parv[1] == '*')
  {
    /* Explicit user@host mask given */
    if (host != NULL)   /* Found user@host */
    {
      user = parv[1];   /* here is user part */
      *(host++) = '\0'; /* and now here is host */
    }
    else
    {
      user = star;      /* no @ found, assume its *@somehost */
      host = parv[1];
    }
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :Invalid parameters",
               me.name, source_p->name);
    return;
  }

  if (remove_gline_match(user, host))
  {
    sendto_one(source_p, ":%s NOTICE %s :G-Line for [%s@%s] is removed",
               me.name, source_p->name, user, host);
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "%s has removed the G-Line for: [%s@%s]",
                         get_oper_name(source_p), user, host);
    ilog(L_NOTICE, "%s removed G-Line for [%s@%s]",
         get_oper_name(source_p), user, host);
    return;
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :No G-Line for %s@%s",
               me.name, source_p->name, user, host);
    return;
  }
}
