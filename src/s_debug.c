/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_debug.c: Some assorted debug functions.
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
#include "s_debug.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "fdlist.h"
#include "fileio.h"
#include "hash.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "irc_res.h"
#include "resv.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_user.h"
#include "send.h"
#include "whowas.h"
#include "memory.h"


/* Option string.
 */
const char serveropts[] =
{
  ' ',
  'T',
  'S',
#ifdef TS_CURRENT
  '0' + TS_CURRENT,
#endif
/* ONLY do TS */
/* ALWAYS do TS_WARNINGS */
  'o',
  'w',
  '\0'
};

/*
 * This is part of the STATS replies. There is no offical numeric for this
 * since this isnt an official command, in much the same way as HASH isnt.
 * It is also possible that some systems wont support this call or have
 * different field names for "struct rusage".
 * -avalon
 */
void
send_usage(struct Client *source_p)
{
  struct rusage  rus;
  time_t         secs;
  time_t         rup;
#ifdef  hz
# define hzz hz
#else
# ifdef HZ
#  define hzz HZ
# else
  int   hzz = 1;
# endif
#endif

  if (getrusage(RUSAGE_SELF, &rus) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Getruseage error: %s.",
               me.name, source_p->name, strerror(errno));
    return;
  }

  secs = rus.ru_utime.tv_sec + rus.ru_stime.tv_sec;

  if (0 == secs)
    secs = 1;

  rup = (CurrentTime - me.since) * hzz;

  if (0 == rup)
    rup = 1;

  sendto_one(source_p,
             ":%s %d %s R :CPU Secs %d:%d User %d:%d System %d:%d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)(secs/60), (int)(secs%60),
             (int)(rus.ru_utime.tv_sec/60), (int)(rus.ru_utime.tv_sec%60),
             (int)(rus.ru_stime.tv_sec/60), (int)(rus.ru_stime.tv_sec%60));
  sendto_one(source_p, ":%s %d %s R :RSS %ld ShMem %ld Data %ld Stack %ld",
             me.name, RPL_STATSDEBUG, source_p->name, rus.ru_maxrss,
             (rus.ru_ixrss / rup), (rus.ru_idrss / rup),
             (rus.ru_isrss / rup));
  sendto_one(source_p, ":%s %d %s R :Swaps %d Reclaims %d Faults %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_nswap,
             (int)rus.ru_minflt, (int)rus.ru_majflt);
  sendto_one(source_p, ":%s %d %s R :Block in %d out %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_inblock,
             (int)rus.ru_oublock);
  sendto_one(source_p, ":%s %d %s R :Msg Rcv %d Send %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_msgrcv,
             (int)rus.ru_msgsnd);
  sendto_one(source_p, ":%s %d %s R :Signals %d Context Vol. %d Invol %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_nsignals,
             (int)rus.ru_nvcsw, (int)rus.ru_nivcsw);
}

void
count_memory(struct Client *source_p)
{
  dlink_node *gptr;
  struct Client *target_p;
  struct Channel *chptr;
  struct Ban *actualBan;
  dlink_node *dlink;

  int local_client_conf_count = 0;      /* local client conf links */
  int users_counted = 0;                /* user structs */

  int channel_users = 0; /* XXX */
  int channel_invites = 0;
  int channel_bans = 0;      
  int channel_except = 0;
  int channel_invex = 0;

  int wwu = 0;                  /* whowas users */
  int class_count = 0;          /* classes */
  int users_invited_count = 0;  /* users invited */
  int aways_counted = 0;   
  int number_ips_stored;        /* number of ip addresses hashed */

  unsigned long channel_memory = 0;
  unsigned long channel_ban_memory = 0;
  unsigned long channel_except_memory = 0;
  unsigned long channel_invex_memory = 0;

  unsigned long away_memory = 0;       /* memory used by aways */
  unsigned long wwm = 0;               /* whowas array memory used */
  unsigned long conf_memory = 0;       /* memory used by conf lines */
  unsigned long mem_ips_stored;        /* memory used by ip address hash */

  unsigned long client_hash_table_size = 0;
  unsigned long channel_hash_table_size = 0;
  unsigned long resv_hash_table_size = 0;
  unsigned long id_hash_table_size = 0;
  unsigned long total_channel_memory = 0;
  unsigned long totww = 0;

  int local_client_count = 0;
  unsigned long local_client_memory_used = 0;

  int remote_client_count = 0;
  unsigned long remote_client_memory_used = 0;

  int user_count = 0;
  unsigned long user_memory_used = 0;

  int links_count = 0;
  unsigned long links_memory_used = 0;

  unsigned long total_memory = 0;
  unsigned int topic_count = 0;

  count_whowas_memory(&wwu, &wwm);

  DLINK_FOREACH(gptr, global_client_list.head)
  {
    target_p = gptr->data;

    if (MyConnect(target_p))
    {
      local_client_conf_count += dlink_list_length(&target_p->localClient->confs);
    }

    if (target_p->user != NULL)
    {
      users_counted++;
      users_invited_count += dlink_list_length(&target_p->user->invited);

      if (target_p->user->away != NULL)
      {
        aways_counted++;
        away_memory += (strlen(target_p->user->away)+1);
      }
    }
  }

  /* Count up all channels, ban lists, except lists, Invex lists */
  channel_memory = dlink_list_length(&global_channel_list) *
                   sizeof(struct Channel);
  DLINK_FOREACH(gptr, global_channel_list.head)
  {
    chptr = gptr->data;

    channel_users   += dlink_list_length(&chptr->members);
    channel_invites += dlink_list_length(&chptr->invites);

    if (chptr->topic != NULL)
      topic_count++;

    if (dlink_list_length(&chptr->banlist))
    {
      channel_bans += dlink_list_length(&chptr->banlist);

      DLINK_FOREACH(dlink, chptr->banlist.head)
      {
        actualBan = dlink->data;

        channel_ban_memory += sizeof(struct Ban);

        if (actualBan->banstr)
          channel_ban_memory += strlen(actualBan->banstr) + 1;
        if (actualBan->who)
          channel_ban_memory += strlen(actualBan->who) + 1;
      }
    }

    if (dlink_list_length(&chptr->exceptlist))
    {
      channel_except += dlink_list_length(&chptr->exceptlist);

      DLINK_FOREACH(dlink, chptr->exceptlist.head)
      {
        actualBan = dlink->data;

        channel_except_memory += sizeof(struct Ban);

        if (actualBan->banstr)
          channel_except_memory += strlen(actualBan->banstr) + 1;
        if (actualBan->who)
          channel_except_memory += strlen(actualBan->who) + 1;
      }
    }

    if (dlink_list_length(&chptr->invexlist))
    {
      channel_invex += dlink_list_length(&chptr->invexlist);

      DLINK_FOREACH(dlink, chptr->invexlist.head)
      {
        actualBan = dlink->data;

        channel_invex_memory += sizeof(struct Ban);

        if (actualBan->banstr)
          channel_invex_memory += strlen(actualBan->banstr) + 1;
        if (actualBan->who)
          channel_invex_memory += strlen(actualBan->who) + 1;
      }
    }
  }

#if 0
  /* XXX THIS has to be fixed !!!! -db */
  /* count up all config items */
  DLINK_FOREACH(dlink, ConfigItemList.head)
  {
      aconf = dlink->data;
      conf_memory += aconf->host ? strlen(aconf->host)+1 : 0;
      conf_memory += aconf->passwd ? strlen(aconf->passwd)+1 : 0;
      conf_memory += aconf->name ? strlen(aconf->name)+1 : 0;
      conf_memory += sizeof(struct AccessItem);
  }
#endif
  /* count up all classes */
  class_count = dlink_list_length(&class_items);

  sendto_one(source_p, ":%s %d %s z :Users %u(%lu) Invites %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     users_counted, (unsigned long)users_counted * sizeof(struct User),
	     users_invited_count, (unsigned long)users_invited_count * sizeof(dlink_node));

  sendto_one(source_p, ":%s %d %s z :User aways %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
             aways_counted, (int)away_memory);

  sendto_one(source_p, ":%s %d %s z :Attached confs %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     local_client_conf_count,
	     (unsigned long)local_client_conf_count * sizeof(dlink_node));

  /* XXX  ConfigItemList fix */
#if 0
  sendto_one(source_p, ":%s %d %s z :Conflines %lu(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     dlink_list_length(&ConfigItemList), (int) conf_memory);
#endif

  sendto_one(source_p, ":%s %d %s z :Resv channels %lu(%lu) nicks %lu(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             dlink_list_length(&resv_channel_list),
             dlink_list_length(&resv_channel_list) * sizeof(struct ResvChannel),
             dlink_list_length(&nresv_items),
             dlink_list_length(&nresv_items) * sizeof(struct MatchItem));

  sendto_one(source_p, ":%s %d %s z :Classes %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     class_count, (unsigned long) class_count * sizeof(struct ClassItem));

  sendto_one(source_p, ":%s %d %s z :Channels %lu(%d) Topics %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     dlink_list_length(&global_channel_list),
             (int)channel_memory, topic_count, topic_count *
	     (TOPICLEN + 1 + USERHOST_REPLYLEN));

  sendto_one(source_p, ":%s %d %s z :Bans %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     channel_bans, (int)channel_ban_memory);

  sendto_one(source_p, ":%s %d %s z :Exceptions %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     channel_except, (int)channel_except_memory);

  sendto_one(source_p, ":%s %d %s z :Invex %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     channel_invex, (int)channel_invex_memory);

  sendto_one(source_p, ":%s %d %s z :Channel members %u(%lu) invite %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name, channel_users,
	     (unsigned long)channel_users * sizeof(struct Membership),
             channel_invites, (unsigned long)channel_invites *
	     sizeof(dlink_node));
 
  total_channel_memory = channel_memory +
    channel_ban_memory +
    channel_users * sizeof(struct Membership) + 
    channel_invites * sizeof(dlink_node);

  sendto_one(source_p, ":%s %d %s z :Whowas users %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     wwu, (unsigned long) wwu * sizeof(struct User));

  sendto_one(source_p, ":%s %d %s z :Whowas array %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name, NICKNAMEHISTORYLENGTH,
             (int) wwm);

  totww = wwu * sizeof(struct User) + wwm;
/****
  client_hash_table_size  = hash_get_client_table_size();
  channel_hash_table_size = hash_get_channel_table_size();
  resv_hash_table_size    = hash_get_resv_table_size();
  id_hash_table_size      = hash_get_id_table_size();

  sendto_one(source_p, ":%s %d %s z :Hash: client %u(%lu) chan %u(%lu) resv "
             "%u(%lu) id %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             U_MAX, client_hash_table_size,
             CH_MAX, channel_hash_table_size , R_MAX,
             resv_hash_table_size, U_MAX, id_hash_table_size);
****/
  count_ip_hash(&number_ips_stored,&mem_ips_stored);
  sendto_one(source_p, ":%s %d %s z :iphash %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
             number_ips_stored,
             (int) mem_ips_stored);

  total_memory = totww + total_channel_memory + conf_memory + class_count *
    sizeof(struct ClassItem);
  total_memory += client_hash_table_size;
  total_memory += channel_hash_table_size;
  total_memory += resv_hash_table_size;
  total_memory += id_hash_table_size;

  sendto_one(source_p, ":%s %d %s z :Total: whowas %d channel %d conf %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)totww,
	     (int) total_channel_memory, (int)conf_memory);

  count_local_client_memory(&local_client_count,
			    &local_client_memory_used);
  total_memory += local_client_memory_used;
  sendto_one(source_p, ":%s %d %s z :Local client Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     local_client_count,
             (int) local_client_memory_used);

  count_remote_client_memory(&remote_client_count,
			      &remote_client_memory_used);
  total_memory += remote_client_memory_used;
  sendto_one(source_p, ":%s %d %s z :Remote client Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     remote_client_count,
             (int) remote_client_memory_used);

  count_user_memory(&user_count, &user_memory_used);
  total_memory += user_memory_used;
  sendto_one(source_p, ":%s %d %s z :User Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     user_count, (int) user_memory_used);

  count_links_memory(&links_count, &links_memory_used);
  total_memory += links_memory_used;
  sendto_one(source_p, ":%s %d %s z :Links Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     (int) links_count,
             (int) links_memory_used);

  sendto_one(source_p, 
             ":%s %d %s z :TOTAL: %d Available:  Current max RSS: %lu",
             me.name, RPL_STATSDEBUG, source_p->name,
	     (int) total_memory, get_maxrss());
}
