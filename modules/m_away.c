/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_away.c: Sets/removes away status on a user.
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
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"
#include "s_serv.h"
#include "packet.h"


static void m_away(struct Client*, struct Client*, int, char**);

struct Message away_msgtab = {
  "AWAY", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_away, m_away, m_away}
};
#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&away_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&away_msgtab);
}
const char *_version = "$Revision$";
#endif
/***********************************************************************
 * m_away() - Added 14 Dec 1988 by jto. 
 *            Not currently really working, I don't like this
 *            call at all...
 *
 *            ...trying to make it work. I don't like it either,
 *            but perhaps it's worth the load it causes to net.
 *            This requires flooding of the whole net like NICK,
 *            USER, MODE, etc messages...  --msa
 ***********************************************************************/

/*
** m_away
**      parv[0] = sender prefix
**      parv[1] = away message
*/
static void m_away(struct Client *client_p,
                  struct Client *source_p,
                  int parc,
                  char *parv[])
{
  char  *away, *awy2 = parv[1];

  if(MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  if(!IsClient(source_p))
    return;

  away = source_p->user->away;

  if (parc < 2 || !*awy2)
    {
      /* Marking as not away */

      if (away)
        {
          /* we now send this only if they were away before --is */
          sendto_server(client_p, source_p, NULL, CAP_UID, NOCAPS,
                        NOFLAGS, ":%s AWAY", ID(source_p));
          sendto_server(client_p, source_p, NULL, NOCAPS, CAP_UID,
                        NOFLAGS, ":%s AWAY", source_p->name);
          MyFree(away);
          source_p->user->away = NULL;
        }
      if (MyConnect(source_p))
        sendto_one(source_p, form_str(RPL_UNAWAY),
                   me.name, parv[0]);
      return;
    }

  /* Marking as away */
  
  if (MyConnect(source_p) && !IsOper(source_p) &&
     (CurrentTime-source_p->user->last_away)<ConfigFileEntry.pace_wait)
    {
      sendto_one(source_p, form_str(RPL_LOAD2HI), me.name, parv[0]);
      return;
    }

  source_p->user->last_away = CurrentTime;

  if (strlen(awy2) > (size_t) TOPICLEN)
    awy2[TOPICLEN] = '\0';

  /* we now send this only if they weren't away already --is */
  if (!away)
  {
    sendto_server(client_p, source_p, NULL, CAP_UID, NOCAPS,
                  NOFLAGS, ":%s AWAY :%s", ID(source_p), awy2);
    sendto_server(client_p, source_p, NULL, NOCAPS, CAP_UID,
                  NOFLAGS, ":%s AWAY :%s", source_p->name, awy2);
  }
  else
    MyFree(away);

  away = (char *)MyMalloc(strlen(awy2)+1);
  strcpy(away,awy2);

  source_p->user->away = away;

  if (MyConnect(source_p))
    sendto_one(source_p, form_str(RPL_NOWAWAY), me.name, parv[0]);
}

