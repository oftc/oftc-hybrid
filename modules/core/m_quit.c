/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_quit.c: Makes a user quit from IRC.
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
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"

static void m_quit(struct Client*, struct Client*, int, char**);
static void ms_quit(struct Client*, struct Client*, int, char**);

struct Message quit_msgtab = {
  "QUIT", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {m_quit, m_quit, ms_quit, m_quit}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&quit_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&quit_msgtab);
}

const char *_version = "$Revision$";
#endif
/*
** m_quit
**      parv[0] = sender prefix
**      parv[1] = comment
*/
static void m_quit(struct Client *client_p,
                  struct Client *source_p,
                  int parc,
                  char *parv[])
{
  char *comment = (parc > 1 && parv[1]) ? parv[1] : client_p->name;
  char reason [TOPICLEN + 1];

  source_p->flags |= FLAGS_NORMALEX;
  if (strlen(comment) > (size_t) TOPICLEN)
    comment[TOPICLEN] = '\0';

  if (ConfigFileEntry.client_exit && comment[0])
    {
#ifndef VMS
      snprintf(reason, TOPICLEN, "Quit: %s", comment);
#else
      sprintf(reason, "Quit: %s", comment);
#endif
      comment = reason;
    }
  
  if(!IsOper(source_p) && 
     (source_p->firsttime + ConfigFileEntry.anti_spam_exit_message_time)
     > CurrentTime)
    {
      comment = "Client Quit";
    }

  exit_client(client_p, source_p, source_p, comment);
}

/*
** ms_quit
**      parv[0] = sender prefix
**      parv[1] = comment
*/
static void ms_quit(struct Client *client_p,
                   struct Client *source_p,
                   int parc,
                   char *parv[])
{
  char *comment = (parc > 1 && parv[1]) ? parv[1] : client_p->name;

  source_p->flags |= FLAGS_NORMALEX;
  if (strlen(comment) > (size_t) TOPICLEN)
    comment[TOPICLEN] = '\0';

  exit_client(client_p, source_p, source_p, comment);
}

