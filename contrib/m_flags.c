/*
 *  m_flags.c: Implements comstud-style mode flags.
 *
 *  Copyright 2002 by W. Campbell and the ircd-hybrid development team
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *  1.Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer. 
 *  2.Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution. 
 *  3.The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 *  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
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

#include "s_user.h"    /* send_umode_out() */


static void m_flags(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[]);
static void mo_flags(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[]);

static char *set_flags_to_string(struct Client *client_p);
static char *unset_flags_to_string(struct Client *client_p);

struct Message test_msgtab = {
  "FLAGS", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_flags, m_ignore, mo_flags}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&test_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&test_msgtab);
}

const char *_version = "$Revision$";
#endif

/* FLAGS requires it's own mini parser, since the last parameter in it can
** contain a number of FLAGS.  CS handles FLAGS mode1 mode2 OR
** FLAGS :mode1 mode2, but not both mixed.
**
** The best way to match a flag to a mode is with a simple table
*/

struct FlagTable
{
  char *name;
  int mode;
  int oper;
};

static struct FlagTable flag_table[] =
{
  /* name		mode it represents	oper only? */
  { "OWALLOPS",		FLAGS_OPERWALL,		1 },
  { "SWALLOPS",		FLAGS_WALLOP,		0 },
  { "STATSNOTICES",	FLAGS_SPY,		1 },
    /* We don't have a separate OKILL and SKILL modes */
  { "OKILLS",		FLAGS_SKILL,		0 },
  { "SKILLS",		FLAGS_SKILL,		0 },
  { "SNOTICES",		FLAGS_SERVNOTICE,	0 },
    /* We don't have separate client connect and disconnect modes */
  { "CLICONNECTS",	FLAGS_CCONN,		1 },
  { "CLIDISCONNECTS",	FLAGS_CCONN,		1 },
    /* I'm taking a wild guess here... */
  { "THROTTLES",	FLAGS_REJ,		1 },
#if 0
    /* This one is special...controlled via an oper block option */
  { "NICKCHANGES",	FLAGS_NCHANGE,		1 },
    /* NICKCHANGES must be checked for separately */
#endif
    /* I'm assuming this is correct... */
  { "IPMISMATCHES",	FLAGS_UNAUTH,		1 },
  { "LWALLOPS",		FLAGS_LOCOPS,		1 },
    /* These aren't separate on Hybrid */
  { "CONNECTS",		FLAGS_EXTERNAL,		1 },
  { "SQUITS",		FLAGS_EXTERNAL,		1 },
    /* Now we have our Hybrid specific flags */
  { "FULL",		FLAGS_FULL,		1 },
    /* Not in CS, but we might as well put it here */
  { "INVISIBLE",	FLAGS_INVISIBLE,	0 },
  { "BOTS",		FLAGS_BOTS,		1 },
  { "CALLERID",		FLAGS_CALLERID,		0 },
  { "UNAUTH",		FLAGS_UNAUTH,		1 },
  { "DEBUG",		FLAGS_DEBUG,		1 },
  { NULL,		0,			0 }
};

/* We won't control CALLERID or INVISIBLE in here */

#define FL_ALL_USER_FLAGS (FLAGS_WALLOP | FLAGS_SKILL | FLAGS_SERVNOTICE )

/* and we don't control NCHANGES here either */

#define FL_ALL_OPER_FLAGS (FL_ALL_USER_FLAGS | FLAGS_CCONN | FLAGS_REJ |\
                           FLAGS_FULL | FLAGS_SPY | FLAGS_DEBUG |\
                           FLAGS_OPERWALL | FLAGS_BOTS | FLAGS_EXTERNAL |\
                           FLAGS_UNAUTH | FLAGS_LOCOPS )

/*
** m_flags
**      parv[0] = sender prefix
**      parv[1] = parameter
*/
static void m_flags(struct Client *client_p, struct Client *source_p,
                   int parc, char *parv[])
{
  int i,j;
  int isadd;
  int setflags;
  int isgood;
  char *p;
  char *flag;

  if (parc < 2)
  {
    /* Generate a list of what flags you have and what you are missing,
    ** and send it to the user
    */
    sendto_one(source_p, ":%s NOTICE %s :Current flags:%s",
               me.name, parv[0], set_flags_to_string(source_p));
    sendto_one(source_p, ":%s NOTICE %s :Current missing flags:%s",
               me.name, parv[0], unset_flags_to_string(source_p));
    return;
  }

  /* Preserve the current flags */
  setflags = source_p->umodes;

/* XXX - change this to support a multiple last parameter like ISON */

  for (i = 1; i < parc; i++)
  {
    for (flag = strtoken(&p, parv[i], " "); flag;
         flag = strtoken(&p, NULL, " "))
    {
      /* We default to being in ADD mode */
      isadd = 1;

      /* We default to being in BAD mode */
      isgood = 0;

      if (!isalpha(flag[0]))
      {
        if (flag[0] == '-')
          isadd = 0;
        else if (flag[0] == '+')
          isadd = 1;
        flag++;
      }

      /* support ALL here */
      if (!irccmp(flag, "ALL"))
      {
        if (isadd)
          source_p->umodes |= FL_ALL_USER_FLAGS;
        else
          source_p->umodes &= ~FL_ALL_USER_FLAGS;
        sendto_one(source_p, ":%s NOTICE %s :Current flags:%s",
                   me.name, parv[0], set_flags_to_string(source_p));
        sendto_one(source_p, ":%s NOTICE %s :Current missing flags:%s",
                   me.name, parv[0], unset_flags_to_string(source_p));
        send_umode_out(client_p, source_p, setflags);
        return;
      }

      for (j = 0; flag_table[j].name; j++)
      {
        if (!flag_table[j].oper && !irccmp(flag, flag_table[j].name))
        {
          if (isadd)
            source_p->umodes |= flag_table[j].mode;
          else
            source_p->umodes &= ~ (flag_table[j].mode);
          isgood = 1;
          continue;
        }
      }
      /* This for ended without matching a valid FLAG, here is where
      ** I want to operate differently than ircd-comstud, and just ignore
      ** the invalid flag, send a warning and go on.
      */
      if (!isgood)
        sendto_one(source_p, ":%s NOTICE %s :Invalid FLAGS: %s (IGNORING)",
                   me.name, parv[0], flag);
    }
  }

  /* All done setting the flags, print the notices out to the user
  ** telling what flags they have and what flags they are missing
  */
  sendto_one(source_p, ":%s NOTICE %s :Current flags:%s",
             me.name, parv[0], set_flags_to_string(source_p));
  sendto_one(source_p, ":%s NOTICE %s :Current missing flags:%s",
             me.name, parv[0], unset_flags_to_string(source_p));

  send_umode_out(client_p, source_p, setflags);
}

/*
** mo_flags
**      parv[0] = sender prefix
**      parv[1] = parameter
*/
static void mo_flags(struct Client *client_p, struct Client *source_p,
                   int parc, char *parv[])
{		 
  int i,j;
  int isadd;
  int setflags;
  int isgood;
  char *p;
  char *flag;

  if (parc < 2)
  {
    /* Generate a list of what flags you have and what you are missing,
    ** and send it to the user
    */
    sendto_one(source_p, ":%s NOTICE %s :Current flags:%s",
               me.name, parv[0], set_flags_to_string(source_p));
    sendto_one(source_p, ":%s NOTICE %s :Current missing flags:%s",
               me.name, parv[0], unset_flags_to_string(source_p));
    return;
  }

  /* Preserve the current flags */
  setflags = source_p->umodes;

/* XXX - change this to support a multiple last parameter like ISON */

  for (i = 1; i < parc; i++)
  {
    for (flag = strtoken(&p, parv[i], " "); flag;
         flag = strtoken(&p, NULL, " "))
    {
      /* We default to being in ADD mode */
      isadd = 1;

      /* We default to being in BAD mode */
      isgood = 0;

      if (!isalpha(flag[0]))
      {
        if (flag[0] == '-')
          isadd = 0;
        else if (flag[0] == '+')
          isadd = 1;
        flag++;
      }

      /* support ALL here */
      if (!irccmp(flag, "ALL"))
      {
        if (isadd)
          source_p->umodes |= FL_ALL_OPER_FLAGS;
        else
          source_p->umodes &= ~FL_ALL_OPER_FLAGS;
        sendto_one(source_p, ":%s NOTICE %s :Current flags:%s",
                   me.name, parv[0], set_flags_to_string(source_p));
        sendto_one(source_p, ":%s NOTICE %s :Current missing flags:%s",
                   me.name, parv[0], unset_flags_to_string(source_p));
        send_umode_out(client_p, source_p, setflags);
        return;
      }

      if (!irccmp(flag, "NICKCHANGES"))
      {
        if (!IsOperN(source_p))
        {
          sendto_one(source_p,
                     ":%s NOTICE %s :*** You need oper and N flag for +n",
                     me.name,parv[0]);
          continue;
        }
        if (isadd)
          source_p->umodes |= FLAGS_NCHANGE;
        else
          source_p->umodes &= ~FLAGS_NCHANGE;
        isgood = 1;
        continue;
      }

      for (j = 0; flag_table[j].name; j++)
      {
        if (!irccmp(flag, flag_table[j].name))
        {
          if (isadd)
            source_p->umodes |= flag_table[j].mode;
          else
            source_p->umodes &= ~ (flag_table[j].mode);
          isgood = 1;
          continue;
        }
      }
      /* This for ended without matching a valid FLAG, here is where
      ** I want to operate differently than ircd-comstud, and just ignore
      ** the invalid flag, send a warning and go on.
      */
      if (!isgood)
        sendto_one(source_p, ":%s NOTICE %s :Invalid FLAGS: %s (IGNORING)",
                   me.name, parv[0], flag);
    }
  }

  /* All done setting the flags, print the notices out to the user
  ** telling what flags they have and what flags they are missing
  */
  sendto_one(source_p, ":%s NOTICE %s :Current flags:%s",
             me.name, parv[0], set_flags_to_string(source_p));
  sendto_one(source_p, ":%s NOTICE %s :Current missing flags:%s",
             me.name, parv[0], unset_flags_to_string(source_p));

  send_umode_out(client_p, source_p, setflags);
}

static char *set_flags_to_string(struct Client *client_p)
{
  /* XXX - list all flags that we have set on the client */
  static char setflags[BUFSIZE + 1];
  int i;

  /* Clear it to begin with, we'll be doing a lot of ircsprintf's */
  setflags[0] = '\0';

  /* Unlike unset_flags_to_string(), we don't have to care about oper
  ** flags and not showing them
  */

  for (i = 0; flag_table[i].name; i++)
  {
    if (client_p->umodes & flag_table[i].mode)
    {
      ircsprintf(setflags, "%s %s", setflags, flag_table[i].name);
    }
  }

#if 0
  if (IsOper(client_p) && IsOperN(client_p))
  {
#endif
    /* You can only be set +NICKCHANGES if you are an oper and
    ** IsOperN(client_p) is true
    */
    if (client_p->umodes & FLAGS_NCHANGE)
    {
      ircsprintf(setflags, "%s %s", setflags, "NICKCHANGES");
    }
#if 0
  }
#endif

  return setflags;
}

static char *unset_flags_to_string(struct Client *client_p)
{
  /* Inverse of above */
  /* XXX - list all flags that we do NOT have set on the client */
  static char setflags[BUFSIZE + 1];
  int i,isoper;

  /* Clear it to begin with, we'll be doing a lot of ircsprintf's */
  setflags[0] = '\0';

  if (IsOper(client_p))
    isoper = 1;
  else
    isoper = 0;

  for (i = 0; flag_table[i].name; i++)
  {
    if ( !(client_p->umodes & flag_table[i].mode))
    {
      if (!isoper && flag_table[i].oper)
        continue;
      ircsprintf(setflags, "%s %s", setflags, flag_table[i].name);
    }
  }

  if (IsOper(client_p) && IsOperN(client_p))
  {
    if ( !(client_p->umodes & FLAGS_NCHANGE))
    {
      ircsprintf(setflags, "%s %s", setflags, "NICKCHANGES");
    }
  }

  return setflags;
}
