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
#include "class.h"
#include "client.h"
#include "common.h"
#include "fdlist.h"
#include "fileio.h"
#include "hash.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "res.h"
#include "s_conf.h"
#include "s_log.h"
#include "scache.h"
#include "send.h"
#include "whowas.h"
#include "linebuf.h"
#include "memory.h"


/*
 * Option string.  Must be before #ifdef DEBUGMODE.
 */
const char serveropts[] = {
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

void debug(int level, char *format, ...)
{
  static char debugbuf[1024];
  va_list args;
  int err = errno;

  if ((debuglevel >= 0) && (level <= debuglevel)) {
    va_start(args, format);

    vsprintf(debugbuf, format, args);
    va_end(args);

    ilog(L_DEBUG, "%s", debugbuf);
  }
  errno = err;
} /* debug() */

/*
 * This is part of the STATS replies. There is no offical numeric for this
 * since this isnt an official command, in much the same way as HASH isnt.
 * It is also possible that some systems wont support this call or have
 * different field names for "struct rusage".
 * -avalon
 */
void send_usage(struct Client *source_p)
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

#ifdef VMS
  sendto_one(source_p, ":%s NOTICE %s :getrusage not supported on this system");
  return;
#else
  if (getrusage(RUSAGE_SELF, &rus) == -1)
    {
      sendto_one(source_p,":%s NOTICE %s :Getruseage error: %s.",
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
             ":%s %d %s :CPU Secs %d:%d User %d:%d System %d:%d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)(secs/60), (int)(secs%60),
             (int)(rus.ru_utime.tv_sec/60), (int)(rus.ru_utime.tv_sec%60),
             (int)(rus.ru_stime.tv_sec/60), (int)(rus.ru_stime.tv_sec%60));
  sendto_one(source_p, ":%s %d %s :RSS %ld ShMem %ld Data %ld Stack %ld",
             me.name, RPL_STATSDEBUG, source_p->name, rus.ru_maxrss,
             (rus.ru_ixrss / rup), (rus.ru_idrss / rup),
             (rus.ru_isrss / rup));
  sendto_one(source_p, ":%s %d %s :Swaps %d Reclaims %d Faults %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_nswap,
             (int)rus.ru_minflt, (int)rus.ru_majflt);
  sendto_one(source_p, ":%s %d %s :Block in %d out %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_inblock,
             (int)rus.ru_oublock);
  sendto_one(source_p, ":%s %d %s :Msg Rcv %d Send %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_msgrcv,
             (int)rus.ru_msgsnd);
  sendto_one(source_p, ":%s %d %s :Signals %d Context Vol. %d Invol %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)rus.ru_nsignals,
             (int)rus.ru_nvcsw, (int)rus.ru_nivcsw);
#endif /* VMS */
}

void count_memory(struct Client *source_p)
{
  struct Client *target_p;
  struct Channel *chptr;
  struct ConfItem *aconf;
  struct Ban *actualBan;
  struct Class *cltmp;
  dlink_node *dlink;

  int channel_count = 0; 
  int local_client_conf_count = 0;      /* local client conf links */
  int users_counted = 0;                /* user structs */

  int channel_users = 0;
  int channel_invites = 0;
  int channel_bans = 0;      
  int channel_except = 0;
  int channel_invex = 0;

  int wwu = 0;                  /* whowas users */
  int class_count = 0;          /* classes */
  int conf_count = 0;           /* conf lines */
  int users_invited_count = 0;  /* users invited */
  int user_channels = 0;        /* users in channels */
  int aways_counted = 0;   
  int number_ips_stored;        /* number of ip addresses hashed */
  int number_servers_cached;    /* number of servers cached by scache */

  u_long channel_memory = 0;
  u_long channel_ban_memory = 0;
  u_long channel_except_memory = 0;
  u_long channel_invex_memory = 0;

  u_long away_memory = 0;       /* memory used by aways */
  u_long wwm = 0;               /* whowas array memory used */
  u_long conf_memory = 0;       /* memory used by conf lines */
  u_long mem_servers_cached;    /* memory used by scache */
  u_long mem_ips_stored;        /* memory used by ip address hash */

  int linebuf_count =0;
  u_long linebuf_memory_used = 0;

  u_long client_hash_table_size = 0;
  u_long channel_hash_table_size = 0;
  u_long total_channel_memory = 0;
  u_long totww = 0;

  int local_client_count = 0;
  u_long local_client_memory_used = 0;

  int remote_client_count = 0;
  u_long remote_client_memory_used = 0;

  int    user_count = 0;
  u_long user_memory_used = 0;

  int    links_count = 0;
  u_long links_memory_used = 0;

  u_long total_memory = 0;

  count_whowas_memory(&wwu, &wwm);

  for (target_p = GlobalClientList; target_p; target_p = target_p->next)
    {
      if (MyConnect(target_p))
        {
          for (dlink = target_p->localClient->confs.head;
	       dlink; dlink = dlink->next)
            local_client_conf_count++;
        }

      if (target_p->user)
        {
          users_counted++;
          for (dlink = target_p->user->invited.head; dlink;
               dlink = dlink->next)
            users_invited_count++;
          for (dlink = target_p->user->channel.head; dlink;
               dlink = dlink->next)
            user_channels++;
          if (target_p->user->away)
            {
              aways_counted++;
              away_memory += (strlen(target_p->user->away)+1);
            }
        }
    }

  /* Count up all channels, ban lists, except lists, Invex lists */

  for (chptr = GlobalChannelList; chptr; chptr = chptr->nextch)
    {
      channel_count++;
      channel_memory += (strlen(chptr->chname) + sizeof(struct Channel));

      for (dlink = chptr->peons.head; dlink; dlink = dlink->next)
        channel_users++;
      for (dlink = chptr->chanops.head; dlink; dlink = dlink->next)
        channel_users++;
#ifdef REQUIRE_OANDV
      for (dlink = chptr->chanops_voiced.head; dlink; dlink = dlink->next)
        channel_users++;
#endif
      for (dlink = chptr->voiced.head; dlink; dlink = dlink->next)
        channel_users++;
#ifdef HALFOPS
      for (dlink = chptr->halfops.head; dlink; dlink = dlink->next)
        channel_users++;
#endif

      for (dlink = chptr->invites.head; dlink; dlink = dlink->next)
        channel_invites++;

      for (dlink = chptr->banlist.head; dlink; dlink = dlink->next)
        {
	  actualBan = dlink->data;
          channel_bans++;

          channel_ban_memory += sizeof(dlink_node) +
	    sizeof(struct Ban);
          if (actualBan->banstr)
            channel_ban_memory += strlen(actualBan->banstr);
          if (actualBan->who)
            channel_ban_memory += strlen(actualBan->who);
        }

      for (dlink = chptr->exceptlist.head; dlink; dlink = dlink->next)
        {
	  actualBan = dlink->data;
          channel_except++;

          channel_except_memory += (sizeof(dlink_node) +
				     sizeof(struct Ban));
          if (actualBan->banstr)
            channel_except_memory += strlen(actualBan->banstr);
          if (actualBan->who)
            channel_except_memory += strlen(actualBan->who);
        }

      for (dlink = chptr->invexlist.head; dlink; dlink = dlink->next)
        {
	  actualBan = dlink->data;
          channel_invex++;

          channel_invex_memory += (sizeof(dlink_node) + 
				   sizeof(struct Ban));
          if (actualBan->banstr)
            channel_invex_memory += strlen(actualBan->banstr);
          if (actualBan->who)
            channel_invex_memory += strlen(actualBan->who);
        }
    }

  /* count up all config items */

  for (aconf = ConfigItemList; aconf; aconf = aconf->next)
    {
      conf_count++;
      conf_memory += aconf->host ? strlen(aconf->host)+1 : 0;
      conf_memory += aconf->passwd ? strlen(aconf->passwd)+1 : 0;
      conf_memory += aconf->name ? strlen(aconf->name)+1 : 0;
      conf_memory += sizeof(struct ConfItem);
    }

  /* count up all classes */

  for (cltmp = ClassList; cltmp; cltmp = cltmp->next)
    class_count++;

  count_linebuf_memory(&linebuf_count, &linebuf_memory_used);

  sendto_one(source_p, ":%s %d %s :Users %u(%lu) Invites %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     users_counted, (unsigned long)users_counted * sizeof(struct User),
	     users_invited_count, (unsigned long)users_invited_count * sizeof(dlink_node));

  sendto_one(source_p, ":%s %d %s :User channels %u(%lu) Aways %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     user_channels, (unsigned long)user_channels*sizeof(dlink_node),
             aways_counted, (int)away_memory);

  sendto_one(source_p, ":%s %d %s :Attached confs %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     local_client_conf_count,
	     (unsigned long)local_client_conf_count * sizeof(dlink_node));

  sendto_one(source_p, ":%s %d %s :Conflines %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     conf_count, (int)conf_memory);

  sendto_one(source_p, ":%s %d %s :Classes %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     class_count, (unsigned long)class_count*sizeof(struct Class));

  sendto_one(source_p, ":%s %d %s :Channels %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     channel_count, (int)channel_memory);

  sendto_one(source_p, ":%s %d %s :Bans %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     channel_bans, (int)channel_ban_memory);

  sendto_one(source_p, ":%s %d %s :Exceptions %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     channel_except, (int)channel_except_memory);

  sendto_one(source_p, ":%s %d %s :Invex %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     channel_invex, (int)channel_invex_memory);

  sendto_one(source_p, ":%s %d %s :Channel members %u(%lu) invite %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name, channel_users,
	     (unsigned long)channel_users*sizeof(dlink_node),
             channel_invites, (unsigned long)channel_invites*sizeof(dlink_node));
 
  total_channel_memory = channel_memory +
    channel_ban_memory +
    channel_users*sizeof(dlink_node) + 
    channel_invites*sizeof(dlink_node);

  sendto_one(source_p, ":%s %d %s :Whowas users %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     wwu, (unsigned long)wwu*sizeof(struct User));

  sendto_one(source_p, ":%s %d %s :Whowas array %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name, NICKNAMEHISTORYLENGTH, (int)wwm);

  totww = wwu * sizeof(struct User) + wwm;

  client_hash_table_size  = hash_get_client_table_size();
  channel_hash_table_size = hash_get_channel_table_size();

  sendto_one(source_p, ":%s %d %s :Hash: client %u(%lu) chan %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             U_MAX, client_hash_table_size,
             CH_MAX, channel_hash_table_size);

  sendto_one(source_p, ":%s %d %s :linebuf %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     linebuf_count, (int)linebuf_memory_used);

  count_scache(&number_servers_cached,&mem_servers_cached);

  sendto_one(source_p, ":%s %d %s :scache %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
             number_servers_cached,
             (int)mem_servers_cached);

  count_ip_hash(&number_ips_stored,&mem_ips_stored);
  sendto_one(source_p, ":%s %d %s :iphash %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
             number_ips_stored,
             (int)mem_ips_stored);

  total_memory = totww + total_channel_memory + conf_memory +
    class_count * sizeof(struct Class);
  total_memory += client_hash_table_size;
  total_memory += channel_hash_table_size;

  total_memory += mem_servers_cached;
  sendto_one(source_p, ":%s %d %s :Total: whowas %d channel %d conf %d",
             me.name, RPL_STATSDEBUG, source_p->name,
	     (int)totww,
	     (int)total_channel_memory,
             (int)conf_memory);

  count_local_client_memory( &local_client_count,
			     (int *)&local_client_memory_used );
  total_memory += local_client_memory_used;
  sendto_one(source_p, ":%s %d %s :Local client Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     local_client_count,
             (int)local_client_memory_used);


  count_remote_client_memory( &remote_client_count,
			      (int *)&remote_client_memory_used);
  total_memory += remote_client_memory_used;
  sendto_one(source_p, ":%s %d %s :Remote client Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     remote_client_count,
             (int)remote_client_memory_used);

  count_user_memory( &user_count, (int *)&user_memory_used );
  total_memory += user_memory_used;
  sendto_one(source_p, ":%s %d %s :User Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     user_count, (int)user_memory_used);

  count_links_memory( &links_count, (int *)&links_memory_used );
  total_memory += links_memory_used;
  sendto_one(source_p, ":%s %d %s :Links Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
	     (int)links_count,
             (int)links_memory_used);

  sendto_one(source_p, 
             ":%s %d %s :TOTAL: %d Available:  Current max RSS: %lu",
             me.name, RPL_STATSDEBUG, source_p->name,
	     (int)total_memory, get_maxrss());
}

