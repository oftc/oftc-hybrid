/*
 *  m_mkpasswd.c: Encrypts a password online, DES or MD5.
 *
 *  Copyright 2002 W. Campbell and the ircd-hybrid development team
 *  Based on mkpasswd.c, originally by Nelson Minar (minar@reed.edu)
 *
 *  You can use this code in any way as long as these names remain.
 *
 *  $Id$
 */

/* List of ircd includes from ../include/ */
#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "common.h"     /* FALSE bleah */
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

#include <string.h>

extern char *crypt();

static void m_mkpasswd(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[]);
static void mo_mkpasswd(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[]);
static char *make_salt(void);
static char *make_md5_salt(void);

static char saltChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

struct Message test_msgtab = {
  "MKPASSWD", 0, 0, 1, 2, MFLG_SLOW, 0,
  {m_unregistered, m_mkpasswd, m_ignore, mo_mkpasswd}
};

#ifndef STATIC_MODULES
void _modinit(void)
{
  mod_add_cmd(&test_msgtab);
}

void _moddeinit(void)
{
  mod_del_cmd(&test_msgtab);
}

const char *_version = "$Revision$";
#endif

static void m_mkpasswd(struct Client *client_p, struct Client *source_p,
                   int parc, char *parv[])
{
  static time_t last_used = 0;
  int is_md5 = 0;

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
    {
      /* safe enough to give this on a local connect only */
      sendto_one(source_p,form_str(RPL_LOAD2HI),me.name,parv[0]);
      return;
    }
  else
    {
      last_used = CurrentTime;
    }

  if (parc == 3)
  {
    if (!irccmp(parv[2], "MD5"))
    {
      is_md5 = 1;
    }
    else if (!irccmp(parv[2], "DES"))
    {
      /* Not really needed, but we may want to have a default encryption
       * setting somewhere down the road
       */
      is_md5 = 0;
    }
    else
    {
      sendto_one(source_p, ":%s NOTICE %s :MKPASSWD syntax error:  MKPASSWD pass [DES|MD5]", me.name, parv[0]);
      return;
    }
  }

  if(parc == 1)
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, parv[0], "MKPASSWD");
  else
    sendto_one(source_p, ":%s NOTICE %s :Encryption for [%s]:  %s",
               me.name, parv[0], parv[1], crypt(parv[1],
               is_md5 ? make_md5_salt() : make_salt()));
}

/*
** mo_test
**      parv[0] = sender prefix
**      parv[1] = parameter
*/
static void mo_mkpasswd(struct Client *client_p, struct Client *source_p,
                   int parc, char *parv[])
{		 
  int is_md5 = 0;

  if (parc == 3)
  {
    if (!irccmp(parv[2], "MD5"))
    {
      is_md5 = 1;
    }
    else if (!irccmp(parv[2], "DES"))
    {
      /* Not really needed, but we may want to have a default encryption
       * setting somewhere down the road
       */
      is_md5 = 0;
    }
    else
    {
      sendto_one(source_p, ":%s NOTICE %s :MKPASSWD syntax error:  MKPASSWD pass [DES|MD5]", me.name, parv[0]);
      return;
    }
  }

  if (parc == 1)
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, parv[0], "MKPASSWD");
  else
    sendto_one(source_p, ":%s NOTICE %s :Encryption for [%s]:  %s",
               me.name, parv[0], parv[1], crypt(parv[1],
               is_md5 ? make_md5_salt() : make_salt()));
}

static char *make_salt(void)
{
  static char salt[3];
  salt[0] = saltChars[random() % 64];
  salt[1] = saltChars[random() % 64];
  salt[2] = '\0';
  return salt;
}

static char *make_md5_salt(void)
{
  static char salt[13];
  int i;
  salt[0] = '$';
  salt[1] = '1';
  salt[2] = '$';
  for (i=3; i<11; i++)
    salt[i] = saltChars[random() % 64];
  salt[11] = '$';
  salt[12] = '\0';
  return salt;
}
