/*   contrib/m_opme.c
 *   Copyright (C) 2002 Hybrid Development Team
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */
#include "stdinc.h"
#include "tools.h"
#include "handlers.h"
#include "channel.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "irc_string.h"
#include "hash.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "vchannel.h"


static void mo_opme(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[]);
static int chan_is_opless(struct Channel *chptr);

struct Message opme_msgtab = {
  "OPME", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_opme}
};

void
_modinit(void)
{
  mod_add_cmd(&opme_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&opme_msgtab);
}

char *_version = "$Revision$";

static int chan_is_opless(struct Channel *chptr)
{
  if (chptr->chanops.head)
	  return 0;
  else
	  return 1;
}

/*
** mo_opme
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void mo_opme(struct Client *client_p, struct Client *source_p,
                    int parc, char *parv[])
{
  struct Channel *chptr, *root_chptr;
  int on_vchan = 0;
  dlink_node *ptr;
  dlink_node *locptr;
  
  /* admins only */
  if (!IsAdmin(source_p))
    {
      sendto_one(source_p, ":%s NOTICE %s :You have no A flag", me.name,
                 parv[0]);
      return;
    }

  /* XXX - we might not have CBURSTed this channel if we are a lazylink
   * yet. */
  chptr= hash_find_channel(parv[1]);
  root_chptr = chptr;

#ifdef VCHANS
  if (chptr && parc > 2 && parv[2][0] == '!')
    {
      chptr = find_vchan(chptr, parv[2]);
      if (root_chptr != chptr)
		  on_vchan++;
    }
#endif
  
  if( chptr == NULL )
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
		 me.name, parv[0], parv[1]);
      return;
    }

  if (!chan_is_opless(chptr))
  {
    sendto_one(source_p, ":%s NOTICE %s :%s Channel is not opless",
               me.name, parv[0], parv[1]);
    return;
  }

  if ((ptr = find_user_link(&chptr->peons, source_p)))
	  dlinkDelete(ptr, &chptr->peons);
  else if ((ptr = find_user_link(&chptr->voiced, source_p)))
	  dlinkDelete(ptr, &chptr->voiced);
#ifdef HALFOPS
  else if ((ptr = find_user_link(&chptr->halfops, source_p)))
	  dlinkDelete(ptr, &chptr->halfops);
#endif
  else if ((ptr = find_user_link(&chptr->chanops, source_p)))
	  dlinkDelete(ptr, &chptr->chanops);
#ifdef REQUIRE_OANDV
  else if((ptr = find_user_link(&chptr->chanops_voiced, source_p)))
    dlinkDelete(ptr, &chptr->chanops_voiced);
#endif
  else
    {
       /* Theyre not even on the channel, bail. */
       return;      
    }

  if((locptr = find_user_link(&chptr->locpeons, source_p)))
    dlinkDelete(locptr, &chptr->locpeons);
  else if((locptr = find_user_link(&chptr->locvoiced, source_p)))
    dlinkDelete(locptr, &chptr->locvoiced);
#ifdef HALFOPS
  else if((locptr = find_user_link(&chptr->lochalfops, source_p)))
    dlinkDelete(locptr, &chptr->lochalfops);
#endif
  else if((locptr = find_user_link(&chptr->locchanops, source_p)))
    dlinkDelete(locptr, &chptr->locchanops);
  
#ifdef REQUIRE_OANDV
  else if((locptr = find_user_link(&chptr->locchanops_voiced, source_p)))
    dlinkDelete(locptr, &chptr->locchanops_voiced);
#endif

  else
    return;

  dlinkAdd(source_p, ptr, &chptr->chanops);
  dlinkAdd(source_p, locptr, &chptr->locchanops);

  if (!on_vchan)
    {
     sendto_wallops_flags(FLAGS_WALLOP, &me,
                          "OPME called for [%s] by %s!%s@%s",
                          parv[1], source_p->name, source_p->username,
                          source_p->host);
     sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                   ":%s WALLOPS :OPME called for [%s] by %s!%s@%s",
                   me.name, parv[1], source_p->name, source_p->username,
                   source_p->host);
     ilog(L_NOTICE, "OPME called for [%s] by %s!%s@%s",
                   parv[1], source_p->name, source_p->username,
                   source_p->host);
    }
  else
    {
     sendto_wallops_flags(FLAGS_WALLOP, &me,
                          "OPME called for [%s %s] by %s!%s@%s",
                          parv[1], parv[2], source_p->name,
                          source_p->username, source_p->host);
     sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                   ":%s WALLOPS :OPME called for [%s %s] by %s!%s@%s",
                   me.name, parv[1], parv[2], source_p->name,
                   source_p->username, source_p->host);
     ilog(L_NOTICE, "OPME called for [%s %s] by %s!%s@%s",
                   parv[1], parv[2], source_p->name, source_p->username,
                   source_p->host);
    }

  sendto_server(NULL, source_p, chptr, CAP_UID, NOCAPS, NOFLAGS,
                 ":%s PART %s", ID(source_p), parv[1]);
  sendto_server(NULL, source_p, chptr, NOCAPS, CAP_UID, NOFLAGS,
                ":%s PART %s", source_p->name, parv[1]);
  sendto_server(NULL, source_p, chptr, CAP_UID, NOCAPS, NOFLAGS,
                ":%s SJOIN %ld %s + :@%s",
                me.name, (signed long) chptr->channelts,
                parv[1],
                source_p->name /* XXX ID(source_p) */ );
  sendto_server(NULL, source_p, chptr, NOCAPS, CAP_UID, NOFLAGS,
                ":%s SJOIN %ld %s + :@%s",
                me.name, (signed long) chptr->channelts,
                parv[1], source_p->name);
  sendto_channel_local(ALL_MEMBERS, chptr,
                       ":%s MODE %s +o %s",
                       me.name, parv[1], source_p->name);
}
