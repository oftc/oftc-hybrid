/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_oper.c: Makes a user an IRC Operator.
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
#include "client.h"
#include "common.h"
#include "fdlist.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_user.h"
#include "send.h"
#include "list.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"


static struct ConfItem *find_password_aconf(char *name, struct Client *source_p);
static int match_oper_password(char *password, struct ConfItem *aconf);
static void failed_oper_notice(struct Client *source_p, char *name, char *reason);
int oper_up( struct Client *source_p, struct ConfItem *aconf );
#ifdef CRYPT_OPER_PASSWORD
extern        char *crypt();
#endif /* CRYPT_OPER_PASSWORD */

static void m_oper(struct Client*, struct Client*, int, char**);
static void ms_oper(struct Client*, struct Client*, int, char**);
static void mo_oper(struct Client*, struct Client*, int, char**);


struct Message oper_msgtab = {
  "OPER", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_unregistered, m_oper, ms_oper, mo_oper} 
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&oper_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&oper_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
** m_oper
**      parv[0] = sender prefix
**      parv[1] = oper name
**      parv[2] = oper password
*/
static void
m_oper(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct ConfItem *aconf;
  struct ConfItem *oconf = NULL;
  char  *name;
  char  *password;
  dlink_node *ptr;

  name = parv[1];
  password = parv[2];

  if (EmptyString(password))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
	       me.name, source_p->name, "OPER");
    return;
  }

  /* end the grace period */
  if(!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if((aconf = find_password_aconf(name,source_p)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOOPERHOST), me.name, source_p->name);
    failed_oper_notice(source_p, name, find_conf_by_name(name, CONF_OPERATOR) ?
                       "host mismatch" : "no oper {} block");
    log_failed_oper(source_p, name);
    return;
  }

  if (match_oper_password(password,aconf))
  {
    /*
     *  20001216:
     *  detach old iline
     *  -einride
     */
    if ((ptr = source_p->localClient->confs.head) != NULL)
    {
      oconf = ptr->data;
      detach_conf(source_p,oconf);
    }

    if(attach_conf(source_p, aconf) != 0)
    {
      sendto_one(source_p,":%s NOTICE %s :Can't attach conf!",
		 me.name, source_p->name);
      failed_oper_notice(source_p, name, "can't attach conf!");
      /* 
       * 20001216:
       * Reattach old iline
       *     -einride
       */
      attach_conf(source_p, oconf);
      log_failed_oper(source_p, name);
      return;
    }

    oper_up(source_p, aconf);
      
    ilog(L_TRACE, "OPER %s by %s!%s@%s",
	 name, source_p->name, source_p->username, source_p->host);
    log_oper(source_p, name);
  }
  else
  {
    sendto_one(source_p,form_str(ERR_PASSWDMISMATCH),me.name, parv[0]);
    failed_oper_notice(source_p, name, "password mismatch");
  }
  log_failed_oper(source_p, name);
}

/*
** mo_oper
**      parv[0] = sender prefix
**      parv[1] = oper name
**      parv[2] = oper password
*/
static void
mo_oper(struct Client *client_p, struct Client *source_p,
	int parc, char *parv[])
{
  sendto_one(source_p, form_str(RPL_YOUREOPER), me.name, parv[0]);
  SendMessageFile(source_p, &ConfigFileEntry.opermotd);
  return;
}

/*
** ms_oper
**      parv[0] = sender prefix
**      parv[1] = oper name
**      parv[2] = oper password
*/
static void
ms_oper(struct Client *client_p, struct Client *source_p, 
	int parc, char *parv[])
{
  /* if message arrived from server, trust it, and set to oper */
  
  if (!IsOper(source_p) && IsClient(source_p))
  {
    SetOper(source_p);
    Count.oper++;
    sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, NOFLAGS,
		  ":%s MODE %s :+o", parv[0], parv[0]);
  }
}

/*
 * find_password_aconf
 *
 * inputs       -
 * output       -
 */

static struct ConfItem *
find_password_aconf(char *name, struct Client *source_p)
{
  struct ConfItem *aconf;

  if ((aconf = find_conf_exact(name, source_p->username, source_p->host,
			       CONF_OPERATOR)) != NULL)
    return (aconf);
  else if ((aconf = find_conf_exact(name, source_p->username,
                                    source_p->localClient->sockhost,
                                    CONF_OPERATOR)) != NULL)
    return (aconf);
  return (NULL);
}

/*
 * match_oper_password
 *
 * inputs       - pointer to given password
 *              - pointer to Conf 
 * output       - YES or NO if match
 * side effects - none
 */

static int
match_oper_password(char *password, struct ConfItem *aconf)
{
  char *encr;

  if (!aconf->status & CONF_OPERATOR)
    return (NO);

  /* XXX another #ifdef that should go */
#ifdef CRYPT_OPER_PASSWORD
  /* use first two chars of the password they send in as salt */
  /* If the password in the conf is MD5, and ircd is linked   
  ** to scrypt on FreeBSD, or the standard crypt library on
  ** glibc Linux, then this code will work fine on generating
  ** the proper encrypted hash for comparison.
  */

  /* passwd may be NULL pointer. Head it off at the pass... */
  if (aconf->passwd == NULL)
    return (NO);

  if (password && *aconf->passwd)
    encr = crypt(password, aconf->passwd);
  else
    encr = "";
#else
  encr = password;
#endif  /* CRYPT_OPER_PASSWORD */

  if (strcmp(encr, aconf->passwd) == 0)
    return (YES);
  else
    return (NO);
}


/*
 * failed_oper_notice
 *
 * inputs       - pointer to client doing /oper ...
 *              - pointer to nick they tried to oper as
 *              - pointer to reason they have failed
 * output       - nothing
 * side effects - notices all opers of the failed oper attempt if enabled
 */

static void
failed_oper_notice(struct Client *source_p, char *name, char *reason)
{
    if (ConfigFileEntry.failed_oper_notice)
      sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
              "Failed OPER attempt as %s "
                           "by %s (%s@%s) - %s", name, source_p->name,
                           source_p->username, source_p->host, reason);
}
