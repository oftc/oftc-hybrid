/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 1999 by the Bahamut Development Team.
 *  Copyright (C) 2011 by the Hybrid Development Team.
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
 */

/*! \file m_services.c
 * \brief Provides service aliases
 * \version $Id$
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "channel_mode.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "s_user.h"
#include "hash.h"


static void m_botserv(struct Client *, struct Client *, int, char *[]);
static void m_chanserv(struct Client *, struct Client *, int, char *[]);
static void m_memoserv(struct Client *, struct Client *, int, char *[]);
static void m_nickserv(struct Client *, struct Client *, int, char *[]);
static void m_operserv(struct Client *, struct Client *, int, char *[]);
static void m_identify(struct Client *, struct Client *, int, char *[]);

struct Message ms_msgtab = {
  "MS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore}
};

struct Message ns_msgtab = {
  "NS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore}
};

struct Message os_msgtab = {
  "OS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore}
};

struct Message bs_msgtab = {
  "BS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_botserv, m_ignore, m_ignore, m_botserv, m_ignore}
};

struct Message cs_msgtab = {
  "CS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore}
};

struct Message botserv_msgtab = {
  "BOTSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_botserv, m_ignore, m_ignore, m_botserv, m_ignore}
};

struct Message chanserv_msgtab = {
  "CHANSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore}
};

struct Message memoserv_msgtab = {
  "MEMOSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore}
};

struct Message nickserv_msgtab = {
  "NICKSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore}
};

struct Message operserv_msgtab = {
  "OPERSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore}
};

struct Message identify_msgtab = {
  "IDENTIFY", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_identify, m_ignore, m_ignore, m_identify, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&botserv_msgtab);
  mod_add_cmd(&chanserv_msgtab);
  mod_add_cmd(&memoserv_msgtab);
  mod_add_cmd(&nickserv_msgtab);
  mod_add_cmd(&operserv_msgtab);
  mod_add_cmd(&identify_msgtab);
  mod_add_cmd(&bs_msgtab);
  mod_add_cmd(&ns_msgtab);
  mod_add_cmd(&cs_msgtab);
  mod_add_cmd(&ms_msgtab);
  mod_add_cmd(&os_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&botserv_msgtab);
  mod_del_cmd(&chanserv_msgtab);
  mod_del_cmd(&memoserv_msgtab);
  mod_del_cmd(&nickserv_msgtab);
  mod_del_cmd(&operserv_msgtab);
  mod_del_cmd(&identify_msgtab);
  mod_del_cmd(&bs_msgtab);
  mod_del_cmd(&ns_msgtab);
  mod_del_cmd(&cs_msgtab);
  mod_del_cmd(&ms_msgtab);
  mod_del_cmd(&os_msgtab);
}

const char *_version = "$Revision$";

/*
 * XXX: Each services alias handler is currently ugly copy&paste.
 * Configureable aliases will get implemented.
 */

static void
m_nickserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG NickServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "NickServ");
}

static void
m_chanserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG ChanServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "ChanServ");
}

static void
m_memoserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG MemoServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "MemoServ");
}

static void
m_operserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG OperServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "OperServ");
}

static void
m_botserv(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG BotServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "BotServ");
}

static void
m_identify(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if (IsChanPrefix(*parv[1]))
  {
    if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
      sendto_one(target_p, ":%s PRIVMSG ChanServ@%s :IDENTIFY %s",
                 source_p->name, ConfigFileEntry.service_name, parv[1]);
    else
      sendto_one(source_p, form_str(ERR_SERVICESDOWN),
                 me.name, source_p->name, "ChanServ");
  }
  else
  {
    if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
      sendto_one(target_p, ":%s PRIVMSG NickServ@%s :IDENTIFY %s",
                 source_p->name, ConfigFileEntry.service_name, parv[1]);
    else
      sendto_one(source_p, form_str(ERR_SERVICESDOWN),
                 me.name, source_p->name, "NickServ");
  }
}
