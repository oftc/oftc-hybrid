/*
 *   IRC - Internet Relay Chat, contrib/m_clearchan.c
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
#include "channel_mode.h"
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
#include "list.h"


#define MSG_CLEARCHAN "CLEARCHAN"

extern BlockHeap *ban_heap;

static void mo_clearchan(struct Client *client_p, struct Client *source_p,
                         int parc, char *parv[]);

static void kick_list(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
                      dlink_list *list,char *chname);

static void remove_our_modes(int type,
                      struct Channel *chptr, struct Channel *top_chptr,
                      struct Client *source_p);
static void remove_a_mode(int hide_or_not,
                          struct Channel *chptr, struct Channel *top_chptr,
                          struct Client *source_p, dlink_list *list, char flag);
static void free_channel_list(dlink_list *list);

static char    *mbuf;


struct Message clearchan_msgtab = {
  MSG_CLEARCHAN, 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_clearchan}
};

void
_modinit(void)
{
  mod_add_cmd(&clearchan_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&clearchan_msgtab);
}

char *_version = "$Revision$";

/*
** mo_clearchan
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void mo_clearchan(struct Client *client_p, struct Client *source_p,
                        int parc, char *parv[])
{
  struct Channel *chptr, *root_chptr;
  int on_vchan = 0;

  /* admins only */
  if (!IsOperAdmin(source_p))
    {
      sendto_one(source_p, ":%s NOTICE %s :You have no A flag", me.name, parv[0]);
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

  if(IsMember(source_p, chptr))
    {
      sendto_one(source_p, ":%s NOTICE %s :*** Please part %s before using CLEARCHAN",
                 me.name, source_p->name, parv[1]);
      return;
    }

  if (!on_vchan)
    {
     sendto_wallops_flags(FLAGS_WALLOP, &me, 
              "CLEARCHAN called for [%s] by %s!%s@%s",
              parv[1], source_p->name, source_p->username, source_p->host);
     sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                   ":%s WALLOPS :CLEARCHAN called for [%s] by %s!%s@%s",
                   me.name, parv[1], source_p->name, source_p->username,
                   source_p->host);
     ilog(L_NOTICE, "CLEARCHAN called for [%s] by %s!%s@%s",
         parv[1], source_p->name, source_p->username, source_p->host);
    }
  else
    {
     sendto_wallops_flags(FLAGS_WALLOP, &me,
              "CLEARCHAN called for [%s %s] by %s!%s@%s",
              parv[1], parv[2], source_p->name, source_p->username,
              source_p->host);
     sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
                   ":%s WALLOPS :CLEARCHAN called for [%s %s] by %s!%s@%s",
                   me.name, parv[1], parv[2], source_p->name,
                   source_p->username, source_p->host);
     ilog(L_NOTICE, "CLEARCHAN called for [%s %s] by %s!%s@%s",
         parv[1], parv[2], source_p->name, source_p->username, source_p->host);
    }

  /* Kill all the modes we have about the channel.. making everyone a peon */  
  remove_our_modes(0, chptr, root_chptr, source_p);
  
  /* SJOIN the user to give them ops, and lock the channel */

  sendto_server(client_p, source_p, chptr, NOCAPS, NOCAPS,
                LL_ICLIENT, ":%s SJOIN %lu %s +ntsi :@%s",
                me.name, (unsigned long) (chptr->channelts - 1),
                chptr->chname, source_p->name);
  sendto_channel_local(ALL_MEMBERS, chptr, ":%s!%s@%s JOIN %s",
                       source_p->name,
                       source_p->username,
                       source_p->host,
                       root_chptr->chname);
  sendto_channel_local(ALL_MEMBERS, chptr, ":%s MODE %s +o %s",
                       me.name, chptr->chname, source_p->name);

  add_user_to_channel(chptr, source_p, CHFL_CHANOP);

  /* Take the TS down by 1, so we don't see the channel taken over
   * again. */
  if (chptr->channelts)
    chptr->channelts--;
  
#ifdef VCHANS
  if (on_vchan)
    add_vchan_to_client_cache(source_p,root_chptr,chptr);
#endif

  chptr->mode.mode =
    MODE_SECRET | MODE_TOPICLIMIT | MODE_INVITEONLY | MODE_NOPRIVMSGS;
  free_topic(chptr);
  chptr->mode.key[0] = 0;

  /* Kick the users out and join the oper */
  kick_list(client_p, source_p, chptr, &chptr->peons, chptr->chname);

}

void kick_list(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
	       dlink_list *list,char *chname)
{
  struct Client *who;
  dlink_node *m;
  dlink_node *next_m;

  for (m = list->head; m; m = next_m)
    {
      next_m = m->next;
      who = m->data;
      sendto_channel_local(ALL_MEMBERS, chptr,
			   ":%s KICK %s %s :CLEARCHAN",
			   source_p->name, chname, who->name);
      sendto_server(NULL, source_p, chptr, NOCAPS, NOCAPS, LL_ICLIENT,
                    ":%s KICK %s %s :CLEARCHAN", source_p->name,
                    chname, who->name);
      remove_user_from_channel(chptr, who);
    }

  /* Join the user themselves to the channel down here, so they dont see a nicklist 
   * or people being kicked */
  sendto_one(source_p, ":%s!%s@%s JOIN %s",
	     source_p->name,
	     source_p->username,
	     source_p->host,
	     chname);

  channel_member_names(source_p, chptr, chname, 1);

}


/*
 * remove_our_modes
 *
 * inputs       - hide from ops or not int flag
 *              - pointer to channel to remove modes from
 *              - if vchan basechannel pointer
 *              - client pointer
 * output       - NONE
 * side effects - Go through the local members, remove all their
 *                chanop modes etc., this side lost the TS.
 */
static void remove_our_modes( int hide_or_not,
                              struct Channel *chptr, struct Channel *top_chptr,
                              struct Client *source_p)
{
  remove_a_mode(hide_or_not, chptr, top_chptr, source_p, &chptr->chanops, 'o');
#ifdef REQUIRE_OANDV
  remove_a_mode(hide_or_not, chptr, top_chptr, source_p, &chptr->chanops_voiced, 'o');
#endif
#ifdef HALFOPS
  remove_a_mode(hide_or_not, chptr, top_chptr, source_p, &chptr->halfops, 'h');
#endif
  remove_a_mode(hide_or_not, chptr, top_chptr, source_p, &chptr->voiced, 'v');
#ifdef REQUIRE_OANDV
  remove_a_mode(hide_or_not, chptr, top_chptr, source_p, &chptr->chanops_voiced, 'v');
#endif

  /* Move all voice/ops etc. to non opped list */
  dlinkMoveList(&chptr->chanops, &chptr->peons);
#ifdef HALFOPS
  dlinkMoveList(&chptr->halfops, &chptr->peons);
#endif
  dlinkMoveList(&chptr->voiced, &chptr->peons);
#ifdef REQUIRE_OANDV
  dlinkMoveList(&chptr->chanops_voiced, &chptr->peons);
#endif
  dlinkMoveList(&chptr->locchanops, &chptr->locpeons);
#ifdef HALFOPS
  dlinkMoveList(&chptr->lochalfops, &chptr->locpeons);
#endif
  dlinkMoveList(&chptr->locvoiced, &chptr->locpeons);
#ifdef REQUIRE_OANDV
  dlinkMoveList(&chptr->locchanops_voiced, &chptr->locpeons);
#endif

  /* Clear all +beI modes */
  free_channel_list(&chptr->banlist);
  free_channel_list(&chptr->exceptlist);
  free_channel_list(&chptr->invexlist);
  chptr->banlist.head = chptr->exceptlist.head = chptr->invexlist.head = NULL;
  chptr->banlist.tail = chptr->exceptlist.tail = chptr->invexlist.tail = NULL;
}


/*
 * remove_a_mode
 *
 * inputs       -
 * output       - NONE
 * side effects - remove ONE mode from a channel
 */
static void remove_a_mode( int hide_or_not,
                           struct Channel *chptr, struct Channel *top_chptr,
                           struct Client *source_p, dlink_list *list, char flag)
{
  dlink_node *ptr;
  struct Client *target_p;
  char buf[BUFSIZE];
  char lmodebuf[MODEBUFLEN];
  char *lpara[MAXMODEPARAMS];
  char *chname;
  int count = 0;

  mbuf = lmodebuf;
  *mbuf++ = '-';

  lpara[0] = lpara[1] = lpara[2] = lpara[3] = "";

  chname = chptr->chname;

  ircsprintf(buf,":%s MODE %s ", me.name, chname);

  for (ptr = list->head; ptr && ptr->data; ptr = ptr->next)
    {
      target_p = ptr->data;
      lpara[count++] = target_p->name;

      *mbuf++ = flag;
      if (count >= MAXMODEPARAMS)
        {
          *mbuf   = '\0';
          sendto_channel_local(hide_or_not, chptr,
                               ":%s MODE %s %s %s %s %s %s",
                               me.name,
                               chname,
                               lmodebuf,
                               lpara[0], lpara[1], lpara[2], lpara[3] );

          mbuf = lmodebuf;
          *mbuf++ = '-';
          count = 0;
          lpara[0] = lpara[1] = lpara[2] = lpara[3] = "";
        }
    }

  if(count != 0)
    {
      *mbuf   = '\0';
      sendto_channel_local(hide_or_not, chptr,
                           ":%s MODE %s %s %s %s %s %s",
                           me.name,
                           chname,
                           lmodebuf,
                           lpara[0], lpara[1], lpara[2], lpara[3] );

    }
}


/*
 * free_channel_list
 *
 * inputs       - pointer to dlink_list
 * output       - NONE
 * side effects -
 */
static void free_channel_list(dlink_list *list)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct Ban *actualBan;

  for (ptr = list->head; ptr; ptr = next_ptr)
    {
      next_ptr = ptr->next;

      actualBan = ptr->data;
      MyFree(actualBan->banstr);
      MyFree(actualBan->who);
      BlockHeapFree(ban_heap, actualBan);

      free_dlink_node(ptr);
    }
}

