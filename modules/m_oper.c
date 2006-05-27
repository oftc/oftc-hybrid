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

static struct ConfItem *find_password_conf(const char *name,
					      struct Client *source_p);
static int match_oper_password(const char *password, struct AccessItem *aconf);
static void failed_oper_notice(struct Client *source_p, const char *name,
			       const char *reason);
static void m_oper(struct Client*, struct Client*, int, char**);
static void mo_oper(struct Client*, struct Client*, int, char**);


struct Message oper_msgtab = {
  "OPER", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_unregistered, m_oper, m_ignore, mo_oper, m_ignore} 
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

const char *_version = "$Revision: 475 $";
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
  struct ConfItem *conf;
  struct AccessItem *aconf=NULL;
  const char *name = parv[1];
  const char *password = parv[2];

  if (EmptyString(password))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
	       me.name, source_p->name, "OPER");
    return;
  }

  /* end the grace period */
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((conf = find_password_conf(name,source_p)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOOPERHOST), me.name, source_p->name);
    conf = find_exact_name_conf(OPER_TYPE, name, NULL, NULL);
    failed_oper_notice(source_p, name, (conf != NULL) ?
                       "host mismatch" : "no oper {} block");
    log_failed_oper(source_p, name);
    return;
  }

  aconf = (struct AccessItem *)map_to_conf(conf);

  if (match_oper_password(password, aconf))
  {
    if (attach_conf(source_p, conf) != 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :Can't attach conf!",
                 me.name, source_p->name);
      failed_oper_notice(source_p, name, "can't attach conf!");
      log_failed_oper(source_p, name);
      return;
    }

    oper_up(source_p, name);
      
    ilog(L_TRACE, "OPER %s by %s!%s@%s",
	 name, source_p->name, source_p->username, source_p->host);
    log_oper(source_p, name);
  }
  else
  {
    sendto_one(source_p, form_str(ERR_PASSWDMISMATCH), me.name, parv[0]);
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
  send_message_file(source_p, &ConfigFileEntry.opermotd);
}

/* find_password_conf()
 *
 * inputs       - name
 *		- pointer to source_p
 * output       - pointer to oper conf or NULL
 * side effects	- NONE
 */
static struct ConfItem *
find_password_conf(const char *name, struct Client *source_p)
{
  struct ConfItem *conf;

  if ((conf = find_exact_name_conf(OPER_TYPE,
				   name, source_p->username, source_p->host
				   )) != NULL)
  {
    return(conf);
  }
  else
  if ((conf = find_exact_name_conf(OPER_TYPE,
				   name, source_p->username,
				   source_p->localClient->sockhost)) != NULL)
  {
    return(conf);
  }

  return(NULL);
}

/* match_oper_password()
 *
 * inputs       - pointer to given password
 *              - pointer to Conf 
 * output       - YES or NO if match
 * side effects - none
 */
static int
match_oper_password(const char *password, struct AccessItem *aconf)
{
  const char *encr = NULL;

  if (!IsConfOperator(aconf))
    return(NO);

  if (ConfigFileEntry.crypt_oper_password)
  {
    /* use first two chars of the password they send in as salt */
    /* If the password in the conf is MD5, and ircd is linked   
     * to scrypt on FreeBSD, or the standard crypt library on
     * glibc Linux, then this code will work fine on generating
     * the proper encrypted hash for comparison.
     */
    /* passwd may be NULL pointer. Head it off at the pass... */
    if (aconf->passwd == NULL)
      return(NO);

    if (password && *aconf->passwd)
      encr = crypt(password, aconf->passwd);
    else
      encr = "";
  }
  else
    encr = password;

  if (strcmp(encr, aconf->passwd) == 0)
    return(YES);
  else
    return(NO);
}

/* failed_oper_notice()
 *
 * inputs       - pointer to client doing /oper ...
 *              - pointer to nick they tried to oper as
 *              - pointer to reason they have failed
 * output       - nothing
 * side effects - notices all opers of the failed oper attempt if enabled
 */
static void
failed_oper_notice(struct Client *source_p, const char *name,
                   const char *reason)
{
  if (ConfigFileEntry.failed_oper_notice)
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Failed OPER attempt as %s "
                         "by %s (%s@%s) - %s", name, source_p->name,
                         source_p->username, source_p->host, reason);
}
