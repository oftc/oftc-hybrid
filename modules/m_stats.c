/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_stats.c: Sends the user statistics or config information.
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
#include "tools.h"	 /* dlink_node/dlink_list */
#include "handlers.h"    /* m_pass prototype */
#include "client.h"      /* Client */
#include "common.h"      /* TRUE/FALSE */
#include "irc_string.h"  
#include "ircd.h"        /* me */
#include "listener.h"    /* show_ports */
#include "s_gline.h"
#include "ircd_handler.h"
#include "msg.h"         /* Message */
#include "hostmask.h"
#include "numeric.h"     /* ERR_xxx */
#include "send.h"        /* sendto_one */
#include "fdlist.h"      /* PF and friends */
#include "s_bsd.h"       /* highest_fd */
#include "s_conf.h"      /* AccessItem, report_configured_links */
#include "s_misc.h"      /* serv_info */
#include "s_serv.h"      /* hunt_server */
#include "s_stats.h"     /* tstats */
#include "s_user.h"      /* show_opers */
#include "event.h"	 /* events */
#include "dbuf.h"
#include "parse.h"
#include "modules.h"
#include "hook.h"
#include "resv.h"  /* report_resv */
#include "whowas.h"
#include "list.h"
#include "rlimits.h"     /* getrlimit() */
#include "s_log.h"       /* ilog */
#include "hash.h"
#include "irc_getnameinfo.h"

static void do_stats(struct Client *, int, char **);
static void m_stats(struct Client *, struct Client *, int, char *[]);
static void mo_stats(struct Client *, struct Client *, int, char *[]);
static void ms_stats(struct Client *, struct Client *, int, char *[]);

struct Message stats_msgtab = {
  "STATS", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_unregistered, m_stats, ms_stats, m_ignore, mo_stats, m_ignore }
};

#ifndef STATIC_MODULES
const char *_version = "$Revision$";
static struct Callback *stats_cb;

static void *
va_stats(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  int parc = va_arg(args, int);
  char **parv = va_arg(args, char **);

  do_stats(source_p, parc, parv);
  return NULL;
}

void
_modinit(void)
{
  stats_cb = register_callback("doing_stats", va_stats);
  mod_add_cmd(&stats_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&stats_msgtab);
  uninstall_hook(stats_cb, va_stats);
}
#endif

static char *parse_stats_args(int, char **, int *, int *);
static void stats_L(struct Client *, char *, int, int, char);
static void stats_L_list(struct Client *s, char *, int, int, dlink_list *, char);

static void stats_dns_servers(struct Client *);
static void stats_connect(struct Client *);
static void stats_deny(struct Client *);
static void stats_tdeny(struct Client *);
static void stats_exempt(struct Client *);
static void stats_events(struct Client *);
static void stats_pending_glines(struct Client *);
static void stats_glines(struct Client *);
static void stats_gdeny(struct Client *);
static void stats_hubleaf(struct Client *);
static void stats_auth(struct Client *);
static void stats_tklines(struct Client *);
static void stats_klines(struct Client *);
static void stats_messages(struct Client *);
static void stats_oper(struct Client *);
static void stats_operedup(struct Client *);
static void stats_ports(struct Client *);
static void stats_resv(struct Client *);
static void stats_usage(struct Client *);
static void stats_tstats(struct Client *);
static void stats_uptime(struct Client *);
static void stats_shared(struct Client *);
static void stats_servers(struct Client *);
static void stats_gecos(struct Client *);
static void stats_class(struct Client *);
static void stats_memory(struct Client *);
static void stats_numbers(struct Client *);
static void stats_servlinks(struct Client *);
static void stats_ltrace(struct Client *, int, char **);
static void stats_ziplinks(struct Client *);

/* This table contains the possible stats items, in order:
 * /stats name,  function to call, operonly? adminonly? /stats letter
 * case only matters in the stats letter column.. -- fl_ */
static const struct StatsStruct
{
  const unsigned char letter;
  void (*handler)();
  const unsigned int need_oper;
  const unsigned int need_admin;
} stats_cmd_table[] = {
  /* letter     function            need_oper need_admin */
  { 'a',	stats_dns_servers,	1,	1,	},
  { 'A',	stats_dns_servers,	1,	1,	},
  { 'c',	stats_connect,		1,	0,	},
  { 'C',	stats_connect,		1,	0,	},
  { 'd',	stats_tdeny,		1,	0,	},
  { 'D',	stats_deny,		1,	0,	},
  { 'e', 	stats_exempt,		1,	0,	},
  { 'E',	stats_events,		1,	0,	},
  { 'f',	fd_dump,		1,	1,	},
  { 'F',	fd_dump,		1,	1,	},
  { 'g',	stats_pending_glines,	1,	0,	},
  { 'G',	stats_glines,		1,	0,	},
  { 'h',	stats_hooks,		1,	1,	},
  { 'H',	stats_hubleaf,		1,	0,	},
  { 'i',	stats_auth,		0,	0,	},
  { 'I',	stats_auth,		0,	0,	},
  { 'k',	stats_tklines,		0,	0,	},
  { 'K',	stats_klines,		0,	0,	},
  { 'l',	stats_ltrace,		1,	0,	},
  { 'L',	stats_ltrace,		1,	0,	},
  { 'm',	stats_messages,		1,	0,	},
  { 'M',	stats_messages,		1,	0,	},
  { 'n',	stats_numbers,		1,	0,	},
  { 'o',	stats_oper,		0,	0,	},
  { 'O',	stats_oper,		0,	0,	},
  { 'p',	stats_operedup,		0,	0,	},
  { 'P',	stats_ports,		0,	0,	},
  { 'q',	stats_resv,		1,	0,	},
  { 'Q',	stats_resv,		1,	0,	},
  { 'r',	stats_usage,		1,	0,	},
  { 'R',	stats_usage,		1,	0,	},
  { 't',	stats_tstats,		1,	0,	},
  { 'T',	stats_tstats,		1,	0,	},
  { 'u',	stats_uptime,		0,	0,	},
  { 'U',	stats_shared,		1,	0,	},
  { 'v',	stats_servers,		1,	0,	},
  { 'V',	stats_gdeny,		1,	0,	},
  { 'x',	stats_gecos,		1,	0,	},
  { 'X',	stats_gecos,		1,	0,	},
  { 'y',	stats_class,		1,	0,	},
  { 'Y',	stats_class,		1,	0,	},
  { 'z',	stats_memory,		1,	0,	},
  { 'Z',	stats_ziplinks,		1,	0,	},
  { '?',	stats_servlinks,	0,	0,	},
  { '\0',       (void(*)())0,           0,	0,	}
};

const char *from, *to;

static void
do_stats(struct Client *source_p, int parc, char **parv)
{
  char statchar = *parv[1];
  int i;

  if (statchar == '\0')
  {
    sendto_one(source_p, form_str(RPL_ENDOFSTATS),
               from, to, '*');
    return;
  }

  for (i = 0; stats_cmd_table[i].handler; i++)
  {
    if (stats_cmd_table[i].letter == statchar)
    {
      /* The stats table says what privs are needed, so check --fl_ */
      if ((stats_cmd_table[i].need_admin && !IsAdmin(source_p)) ||
          (stats_cmd_table[i].need_oper && !IsOper(source_p)))
      {
        sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
                   from, to);
        break;
      }

      /* Blah, stats L needs the parameters, none of the others do.. */
      if (statchar == 'L' || statchar == 'l')
        stats_cmd_table[i].handler(source_p, parc, parv);
      else
        stats_cmd_table[i].handler(source_p);

      break;
    }
  }

  sendto_one(source_p, form_str(RPL_ENDOFSTATS),
             from, to, statchar);
}

/*
 * m_stats()
 *      parv[0] = sender prefix
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L
 * 
 * This will search the tables for the appropriate stats letter/command,
 * if found execute it.  
 */
static void
m_stats(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  static time_t last_used = 0;

  /* Is the stats meant for us? */
  if (!ConfigFileEntry.disable_remote)
    if (hunt_server(client_p,source_p,":%s STATS %s :%s",2,parc,parv) != HUNTED_ISME)
      return;

  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  /* Check the user is actually allowed to do /stats, and isnt flooding */
  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one(source_p,form_str(RPL_LOAD2HI),
               from, to, "STATS");
    return;
  }
  else
    last_used = CurrentTime;

#ifdef STATIC_MODULES
  do_stats(source_p, parc, parv);
#else
  execute_callback(stats_cb, source_p, parc, parv);
#endif
}

/*
 * mo_stats()
 *      parv[0] = sender prefix
 *      parv[1] = stat letter/command
 *      parv[2] = (if present) server/mask in stats L, or target
 *
 * This will search the tables for the appropriate stats letter,
 * if found execute it.  
 */
static void
mo_stats(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s STATS %s :%s", 2,
                  parc, parv) != HUNTED_ISME)
     return;

  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

#ifdef STATIC_MODULES
  do_stats(source_p, parc, parv);
#else
  execute_callback(stats_cb, source_p, parc, parv);
#endif
}

/*
 * This is part of the STATS replies. There is no offical numeric for this
 * since this isnt an official command, in much the same way as HASH isnt.
 * It is also possible that some systems wont support this call or have
 * different field names for "struct rusage".
 * -avalon
 */
static void
send_usage(struct Client *source_p)
{
#ifndef _WIN32
  struct rusage rus;
  time_t secs;
  time_t rup;
#ifdef  hz
# define hzz hz
#else
# ifdef HZ
#  define hzz HZ
# else
  int hzz = 1;
# endif
#endif

  if (getrusage(RUSAGE_SELF, &rus) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Getruseage error: %s",
               me.name, source_p->name, strerror(errno));
    return;
  }

  secs = rus.ru_utime.tv_sec + rus.ru_stime.tv_sec;

  if (secs == 0)
    secs = 1;

  rup = (CurrentTime - me.since) * hzz;

  if (rup == 0)
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
#endif
}

static void
count_memory(struct Client *source_p)
{
  const dlink_node *gptr = NULL;
  const dlink_node *dlink = NULL;

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
  size_t channel_ban_memory = 0;
  size_t channel_except_memory = 0;
  size_t channel_invex_memory = 0;

  unsigned int safelist_count = 0;
  size_t safelist_memory = 0;

  unsigned long away_memory = 0;       /* memory used by aways           */
  unsigned long wwm = 0;               /* whowas array memory used       */
  unsigned long conf_memory = 0;       /* memory used by conf lines      */
  unsigned long mem_ips_stored;        /* memory used by ip address hash */

  unsigned long client_hash_table_size = 0;
  unsigned long channel_hash_table_size = 0;
  unsigned long resv_hash_table_size = 0;
  unsigned long id_hash_table_size = 0;
  unsigned long total_channel_memory = 0;
  unsigned long totww = 0;

  unsigned int local_client_count  = 0;
  unsigned int remote_client_count = 0;

  unsigned int local_client_memory_used  = 0;
  unsigned int remote_client_memory_used = 0;

  unsigned long total_memory = 0;
  unsigned int topic_count = 0;

  struct rlimit rlim;

  count_whowas_memory(&wwu, &wwm);

  DLINK_FOREACH(gptr, global_client_list.head)
  {
    struct Client *target_p = gptr->data;

    if (MyConnect(target_p))
    {
      ++local_client_count;
      local_client_conf_count += dlink_list_length(&target_p->localClient->confs);
      users_invited_count += dlink_list_length(&target_p->localClient->invited);
    }
    else
      ++remote_client_count;

    if (IsClient(target_p))
    {
      ++users_counted;

      if (target_p->away != NULL)
      {
        ++aways_counted;
        away_memory += strlen(target_p->away) + 1;
      }
    }
  }

  /* Count up all channels, ban lists, except lists, Invex lists */
  channel_memory = dlink_list_length(&global_channel_list) *
                   sizeof(struct Channel);
  DLINK_FOREACH(gptr, global_channel_list.head)
  {
    struct Ban *actualBan;
    struct Channel *chptr = gptr->data;

    channel_users   += dlink_list_length(&chptr->members);
    channel_invites += dlink_list_length(&chptr->invites);

    if (chptr->topic != NULL)
      ++topic_count;

    if ((channel_bans = dlink_list_length(&chptr->banlist)))
    {
      channel_ban_memory = channel_bans * sizeof(struct Ban);

      DLINK_FOREACH(dlink, chptr->banlist.head)
      {
        actualBan = dlink->data;
        assert(actualBan->who);

        channel_ban_memory += actualBan->len + 3;
        channel_ban_memory += strlen(actualBan->who) + 1;
      }
    }

    if ((channel_except = dlink_list_length(&chptr->exceptlist)))
    {
      channel_except_memory = channel_except * sizeof(struct Ban);

      DLINK_FOREACH(dlink, chptr->exceptlist.head)
      {
        actualBan = dlink->data;
        assert(actualBan->who);

        channel_except_memory += actualBan->len + 3;
        channel_except_memory += strlen(actualBan->who) + 1;
      }
    }

    if ((channel_invex = dlink_list_length(&chptr->invexlist)))
    {
      channel_invex_memory = channel_invex * sizeof(struct Ban);

      DLINK_FOREACH(dlink, chptr->invexlist.head)
      {
        actualBan = dlink->data;
        assert(actualBan->who);

        channel_invex_memory += actualBan->len + 3;
        channel_invex_memory += strlen(actualBan->who) + 1;
      }
    }
  }

  if ((safelist_count = dlink_list_length(&listing_client_list)))
  {
    safelist_memory = safelist_count * sizeof(struct ListTask);
    DLINK_FOREACH(gptr, listing_client_list.head)
    {
      struct Client *acptr = gptr->data;

      DLINK_FOREACH(dlink, acptr->localClient->list_task->show_mask.head)
        safelist_memory += strlen(dlink->data);

      DLINK_FOREACH(dlink, acptr->localClient->list_task->hide_mask.head)
        safelist_memory += strlen(dlink->data);
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

  sendto_one(source_p, ":%s %d %s z :Clients %u(%lu) Invites %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name, users_counted,
             (unsigned long)(users_counted * sizeof(struct Client)),
             users_invited_count, (unsigned long)(users_invited_count * sizeof(dlink_node)));

  sendto_one(source_p, ":%s %d %s z :User aways %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
             aways_counted, (int)away_memory);

  sendto_one(source_p, ":%s %d %s z :Attached confs %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             local_client_conf_count,
             (unsigned long)(local_client_conf_count * sizeof(dlink_node)));

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
             class_count, (unsigned long)(class_count * sizeof(struct ClassItem)));

  sendto_one(source_p, ":%s %d %s z :Channels %lu(%lu) Topics %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
             dlink_list_length(&global_channel_list),
             channel_memory, topic_count, topic_count *
             (TOPICLEN + 1 + USERHOST_REPLYLEN));

  sendto_one(source_p, ":%s %d %s z :Bans %u(%zu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             channel_bans, channel_ban_memory);

  sendto_one(source_p, ":%s %d %s z :Exceptions %u(%zu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             channel_except, channel_except_memory);

  sendto_one(source_p, ":%s %d %s z :Invex %u(%zu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             channel_invex, channel_invex_memory);

  sendto_one(source_p, ":%s %d %s z :Channel members %u(%lu) invite %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name, channel_users,
             (unsigned long)(channel_users * sizeof(struct Membership)),
             channel_invites, (unsigned long)channel_invites *
             sizeof(dlink_node));

  total_channel_memory = channel_memory + channel_ban_memory +
                         channel_users * sizeof(struct Membership) +
                         channel_invites * sizeof(dlink_node);

  sendto_one(source_p, ":%s %d %s z :Safelist %u(%zu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             safelist_count, safelist_memory);

  sendto_one(source_p, ":%s %d %s z :Whowas users %u(%lu)",
             me.name, RPL_STATSDEBUG, source_p->name,
             wwu, (unsigned long)(wwu * sizeof(struct Client)));

  sendto_one(source_p, ":%s %d %s z :Whowas array %u(%d)",
             me.name, RPL_STATSDEBUG, source_p->name,
             NICKNAMEHISTORYLENGTH, (int)wwm);

  totww = wwu * sizeof(struct Client) + wwm;
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
             number_ips_stored, (int)mem_ips_stored);

  total_memory = totww + total_channel_memory + conf_memory + class_count *
                 sizeof(struct ClassItem);
  total_memory += client_hash_table_size;
  total_memory += channel_hash_table_size;
  total_memory += resv_hash_table_size;
  total_memory += id_hash_table_size;

  sendto_one(source_p, ":%s %d %s z :Total: whowas %d channel %d conf %d",
             me.name, RPL_STATSDEBUG, source_p->name, (int)totww,
            (int)total_channel_memory, (int)conf_memory);

  local_client_memory_used = local_client_count*(sizeof(struct Client) + sizeof(struct LocalUser));
  total_memory += local_client_memory_used;
  sendto_one(source_p, ":%s %d %s z :Local client Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name, local_client_count,
             local_client_memory_used);

  remote_client_memory_used = remote_client_count * sizeof(struct Client);
  total_memory += remote_client_memory_used;
  sendto_one(source_p, ":%s %d %s z :Remote client Memory in use: %d(%d)",
             me.name, RPL_STATSDEBUG, source_p->name, remote_client_count,
             remote_client_memory_used);

  block_heap_report_stats(source_p);

  sendto_one(source_p,
             ":%s %d %s z :TOTAL: %d Available:  Current max RSS: %lu",
             me.name, RPL_STATSDEBUG, source_p->name,
             (int)total_memory, get_maxrss());

  if (getrlimit(RLIMIT_FD_MAX, &rlim) == 0) {
    sendto_one(source_p,
               ":%s %d %s z :rlimit_nofile: soft: %d; hard: %d",
               me.name, RPL_STATSDEBUG, source_p->name,
               (int)rlim.rlim_cur, (int)rlim.rlim_max);
  } else {
    ilog(L_NOTICE, "Unable to getrlimit(): %s", strerror(errno));
    sendto_one(source_p,
               ":%s %d %s z :rlimit_nofile: getrlimit() failed.  See log.",
               me.name, RPL_STATSDEBUG, source_p->name);
  }

}

static void
dump_counters(struct Client *source_p)
{
  struct ClassItem *classitem;
  struct ConfItem *conf;
  struct CidrItem *cidr;
  dlink_node *ptr, *ptr2;
  char ipaddr[HOSTIPLEN];
  int ret;

  dump_userhosttable(source_p);
  dump_ip_hash_table(source_p);
  DLINK_FOREACH(ptr, class_items.head)
  {
    conf = ptr->data;
    classitem = &conf->aclass;
    DLINK_FOREACH(ptr2, classitem->list_ipv4.head)
    {
      cidr = ptr2->data;

      ret = irc_getnameinfo((struct sockaddr*)&cidr->mask, cidr->mask.ss_len,
          ipaddr, HOSTIPLEN, NULL, 0, NI_NUMERICHOST);
      if (ret != 0)
        continue;

      sendto_one(source_p, ":%s %d %s n :cidr_table: %s: %s/%d %d", me.name,
          RPL_STATSCCOUNT, source_p->name, conf->name, ipaddr,
          CidrBitlenIPV4(classitem), cidr->number_on_this_cidr);
    }
    DLINK_FOREACH(ptr2, classitem->list_ipv6.head)
    {
      cidr = ptr2->data;

      ret = irc_getnameinfo((struct sockaddr*)&cidr->mask, cidr->mask.ss_len,
          ipaddr, HOSTIPLEN, NULL, 0, NI_NUMERICHOST);
      if (ret != 0)
        continue;

      sendto_one(source_p, ":%s %d %s n :cidr_table: %s: %s/%d %d", me.name,
          RPL_STATSCCOUNT, source_p->name, conf->name, ipaddr,
          CidrBitlenIPV6(classitem), cidr->number_on_this_cidr);
    }
  }
}

static void
stats_dns_servers(struct Client *source_p)
{
  report_dns_servers(source_p);
}

static void
stats_connect(struct Client *source_p)
{
  report_confitem_types(source_p, SERVER_TYPE, 0);
}

/* stats_deny()
 *
 * input	- client to report to
 * output	- none
 * side effects - client is given dline list.
 */
static void
stats_deny(struct Client *source_p)
{
  struct AddressRec *arec;
  struct AccessItem *aconf;
  int i;

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec=arec->next)
    {
      if (arec->type == CONF_DLINE)
      {
        aconf = arec->aconf;

        /* dont report a tdline as a dline */
        if (aconf->flags & CONF_FLAGS_TEMPORARY)
          continue;

        sendto_one(source_p, form_str(RPL_STATSDLINE),
            from, to, 'D', aconf->host, aconf->reason,
            aconf->oper_reason);
      }
    }
  }
}

/* stats_tdeny()
 *
 * input        - client to report to
 * output       - none
 * side effects - client is given dline list.
 */
static void
stats_tdeny(struct Client *source_p)
{
  struct AddressRec *arec;
  struct AccessItem *aconf;
  int i;

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec=arec->next)
    {
      if (arec->type == CONF_DLINE)
      {
        aconf = arec->aconf;

        /* dont report a permanent dline as a tdline */
        if (!(aconf->flags & CONF_FLAGS_TEMPORARY))
          continue;


        sendto_one(source_p, form_str(RPL_STATSDLINE),
            from, to, 'd', aconf->host, aconf->reason,
            aconf->oper_reason);
      }
    }
  }
}

/* stats_exempt()
 *
 * input        - client to report to
 * output       - none
 * side effects - client is given list of exempt blocks
 */
static void
stats_exempt(struct Client *source_p)
{
  struct AddressRec *arec;
  struct AccessItem *aconf;
  int i;

  if (ConfigFileEntry.stats_e_disabled)
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               from, to);
    return;
  }

  for (i = 0; i < ATABLE_SIZE; i++)
  {
    for (arec = atable[i]; arec; arec=arec->next)
    {
      if (arec->type == CONF_EXEMPTDLINE)
      {
        aconf = arec->aconf;

        sendto_one(source_p, form_str(RPL_STATSDLINE),
            from, to, 'e', aconf->host, 
            aconf->reason, aconf->oper_reason);
      }
    }
  }
}

static void
stats_events(struct Client *source_p)
{
  show_events(source_p);
}

/* stats_pending_glines()
 *
 * input        - client pointer
 * output       - none
 * side effects - client is shown list of pending glines
 */
static void
stats_pending_glines(struct Client *source_p)
{
#ifdef GLINE_VOTING
  dlink_node *pending_node;
  struct gline_pending *glp_ptr;
  char timebuffer[MAX_DATE_STRING];
  struct tm *tmptr;

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :This server does not support G-Lines",
               from, to); 
    return;
  }

  if (dlink_list_length(&pending_glines) > 0)
    sendto_one(source_p, ":%s NOTICE %s :Pending G-lines",
               from, to);

  DLINK_FOREACH(pending_node, pending_glines.head)
  {
    glp_ptr = pending_node->data;
    tmptr   = localtime(&glp_ptr->time_request1);
    strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);

    sendto_one(source_p,
               ":%s NOTICE %s :1) %s!%s@%s on %s requested gline at %s for %s@%s [%s]",
               from, to, glp_ptr->oper_nick1,
               glp_ptr->oper_user1, glp_ptr->oper_host1,
               glp_ptr->oper_server1, timebuffer,
               glp_ptr->user, glp_ptr->host, glp_ptr->reason1);

    if (glp_ptr->oper_nick2[0] != '\0')
    {
      tmptr = localtime(&glp_ptr->time_request2);
      strftime(timebuffer, MAX_DATE_STRING, "%Y/%m/%d %H:%M:%S", tmptr);
      sendto_one(source_p,
      ":%s NOTICE %s :2) %s!%s@%s on %s requested gline at %s for %s@%s [%s]",
                 from, to, glp_ptr->oper_nick2,
                 glp_ptr->oper_user2, glp_ptr->oper_host2,
                 glp_ptr->oper_server2, timebuffer,
                 glp_ptr->user, glp_ptr->host, glp_ptr->reason2);
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :End of Pending G-lines",
             from, to);
#else
  sendto_one(source_p, ":%s NOTICE %s :This server does not support G-Line voting",
             from, to);
#endif /* GLINE VOTING */
}

/* stats_glines()
 *
 * input        - client pointer
 * output       - none
 * side effects - client is shown list of glines
 */
static void
stats_glines(struct Client *source_p)
{
  struct AddressRec *arec = NULL;
  int i = 0;

  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :This server does not support G-Lines",
               from, to);
    return;
  }

  for (; i < ATABLE_SIZE; ++i)
  {
    for (arec = atable[i]; arec; arec=arec->next)
    {
      if (arec->type == CONF_GLINE)
      {
        const struct AccessItem *aconf = arec->aconf;

        sendto_one(source_p, form_str(RPL_STATSKLINE),
                   from, to, "G",
                   aconf->host ? aconf->host : "*",
                   aconf->user ? aconf->user : "*",
                   aconf->reason ? aconf->reason : "No reason", "" );
      }
    }
  }
}

/* stats_gdeny()
 *
 * input        - client pointer
 * outputs      - none
 * side effects - client is shown gline ACL
 */
static void
stats_gdeny(struct Client *source_p)
{
  if (!ConfigFileEntry.glines)
  {
    sendto_one(source_p, ":%s NOTICE %s :This server does not support G-Lines",
               from, to);
    return;
  }

  report_confitem_types(source_p, GDENY_TYPE, 0);
}

static void
stats_hubleaf(struct Client *source_p)
{
  report_confitem_types(source_p, HUB_TYPE, 0);
  report_confitem_types(source_p, LEAF_TYPE, 0);
}

static void
stats_auth(struct Client *source_p)
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if ((ConfigFileEntry.stats_i_oper_only == 2) && !IsOper(source_p))
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               from, to);

  /* If unopered, Only return matching auth blocks */
  else if ((ConfigFileEntry.stats_i_oper_only == 1) && !IsOper(source_p))
  {
    struct AccessItem *aconf;

    if (MyConnect(source_p))
      aconf = find_conf_by_address(source_p->host, &source_p->ip,
          CONF_CLIENT, source_p->aftype, source_p->username,
          source_p->localClient->passwd, source_p->certfp);
    else
      aconf = find_conf_by_address(source_p->host, NULL, CONF_CLIENT,
          0, source_p->username, NULL, source_p->certfp);

    if (aconf == NULL)
      return;

    sendto_one(source_p, form_str(RPL_STATSILINE), from,
               to, 'I',
	       "*", show_iline_prefix(source_p, aconf, aconf->user), 
	       aconf->host, aconf->port,
	       aconf->class_ptr ? aconf->class_ptr->name : "<default>");
  }
  /* They are opered, or allowed to see all auth blocks */
  else
    report_auth(source_p);
}

static void
stats_tklines(struct Client *source_p)
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if ((ConfigFileEntry.stats_k_oper_only == 2) && !IsOper(source_p))
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               from, to);

  /* If unopered, Only return matching klines */
  else if ((ConfigFileEntry.stats_k_oper_only == 1) && !IsOper(source_p))
  {
    struct AccessItem *aconf;

    if (MyConnect(source_p))
      aconf = find_conf_by_address(source_p->host, &source_p->ip,
          CONF_KILL, source_p->aftype, source_p->username, NULL, NULL);
    else
      aconf = find_conf_by_address(source_p->host, NULL, CONF_KILL,
          0, source_p->username, NULL, NULL);

    if (aconf == NULL)
      return;

    /* dont report a permanent kline as a tkline */
    if (!(aconf->flags & CONF_FLAGS_TEMPORARY))
      return;

    sendto_one(source_p, form_str(RPL_STATSKLINE), from,
               to, "k", aconf->host, aconf->user, aconf->reason, "");
  }
  /* Theyre opered, or allowed to see all klines */
  else {
    report_Klines(source_p, 1);
    report_confitem_types(source_p, RKLINE_TYPE, 1);
  }
}

static void
stats_klines(struct Client *source_p)
{
  /* Oper only, if unopered, return ERR_NOPRIVILEGES */
  if ((ConfigFileEntry.stats_k_oper_only == 2) && !IsOper(source_p))
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               from, to);

  /* If unopered, Only return matching klines */
  else if ((ConfigFileEntry.stats_k_oper_only == 1) && !IsOper(source_p))
  {
    struct AccessItem *aconf;

    /* search for a kline */
    if (MyConnect(source_p))
      aconf = find_conf_by_address(source_p->host, &source_p->ip,
          CONF_KILL, source_p->aftype, source_p->username, NULL, NULL);
    else
      aconf = find_conf_by_address(source_p->host, NULL, CONF_KILL,
          0, source_p->username, NULL, NULL);

    if (aconf == NULL)
      return;

    /* dont report a tkline as a kline */
    if (aconf->flags & CONF_FLAGS_TEMPORARY)
      return;
      
    sendto_one(source_p, form_str(RPL_STATSKLINE), from,
               to, "K", aconf->host, aconf->user, aconf->reason,
	       aconf->oper_reason);
  }
  /* Theyre opered, or allowed to see all klines */
  else {
    report_Klines(source_p, 0);
    report_confitem_types(source_p, RKLINE_TYPE, 0);
  }
}

static void
stats_messages(struct Client *source_p)
{
  report_messages(source_p);
}

static void
stats_oper(struct Client *source_p)
{
  if (!IsOper(source_p) && ConfigFileEntry.stats_o_oper_only)
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               from, to);
  else
    report_confitem_types(source_p, OPER_TYPE, 0);
}

/* stats_operedup()
 *
 * input	- client pointer
 * output	- none
 * side effects - client is shown a list of active opers
 */
static void
stats_operedup(struct Client *source_p)
{
  dlink_node *ptr;
  int oper_count = 0;

  DLINK_FOREACH(ptr, global_client_list.head)
  {
    const struct Client *target_p = ptr->data;

    if (IsOperHidden(target_p) && !IsOper(source_p))
      continue;

    if(!IsOper(target_p))
      continue;

    if(IsService(target_p))
      continue;

    oper_count++;
    if(MyClient(target_p))
    {
      if (MyClient(source_p) && IsOper(source_p))
        sendto_one(source_p, ":%s %d %s p :[%c][%s] %s (%s@%s) Idle: %d",
            from, RPL_STATSDEBUG, to,
            IsAdmin(target_p) ?
            (IsOperHiddenAdmin(target_p) ? 'O' : 'A') : 'O',
            oper_privs_as_string(target_p->localClient->operflags),
            target_p->name, target_p->username, target_p->host,
            (int)(CurrentTime - target_p->localClient->last));
      else
        sendto_one(source_p, ":%s %d %s p :[%c] %s (%s@%s) Idle: %d",
            from, RPL_STATSDEBUG, to,
            IsAdmin(target_p) ?
            (IsOperHiddenAdmin(target_p) ? 'O' : 'A') : 'O',
            target_p->name, target_p->username, target_p->host,
            (int)(CurrentTime - target_p->localClient->last));
    }
    /* The logic here is that we only show remote admins so we can hide remote
     * opers.  Local opers can be hidden with config flags 
     */
    else if(IsAdmin(target_p))
    {
      sendto_one(source_p, ":%s %d %s p :[%c] %s (%s@%s) Server: %s",
          from, RPL_STATSDEBUG, to,
          IsAdmin(target_p) ?
          (IsOperHiddenAdmin(target_p) ? 'O' : 'A') : 'O',
          target_p->name, target_p->username, target_p->host,
          target_p->servptr->name);
    }
  }

  sendto_one(source_p, ":%s %d %s p :%d OPER(s)",
             from, RPL_STATSDEBUG, to, oper_count);
}

static void
stats_ports(struct Client *source_p)
{
  if (!IsOper(source_p) && ConfigFileEntry.stats_P_oper_only)
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               from, to);
  else
    show_ports(source_p);
}

static void
stats_resv(struct Client *source_p)
{
  report_resv(source_p);
}

static void
stats_usage(struct Client *source_p)
{
  send_usage(source_p);
}

static void
stats_tstats(struct Client *source_p)
{
  tstats(source_p);
}

static void
stats_uptime(struct Client *source_p)
{
  time_t now = CurrentTime - me.since;
  sendto_one(source_p, form_str(RPL_STATSUPTIME), from, to,
             now/86400, (now/3600)%24, (now/60)%60, now%60);
  if (!ConfigFileEntry.disable_remote || IsOper(source_p))
     sendto_one(source_p, form_str(RPL_STATSCONN), from, to,
                MaxConnectionCount, MaxClientCount, Count.totalrestartcount);
}

static void
stats_shared(struct Client *source_p)
{
  report_confitem_types(source_p, ULINE_TYPE, 0);
}

/* stats_servers()
 *
 * input	- client pointer
 * output	- none
 * side effects - client is shown lists of who connected servers
 */
static void
stats_servers(struct Client *source_p)
{
  struct Client *target_p;
  dlink_node *ptr;
  int j = 0;

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    j++;

    sendto_one(source_p, ":%s %d %s v :%s (%s!%s@%s) Idle: %d",
               from, RPL_STATSDEBUG, to,
	       target_p->name,
	       (target_p->serv->by[0] ? target_p->serv->by : "Remote."),
	       "*", "*", (int)(CurrentTime - target_p->lasttime));
  }

  sendto_one(source_p, ":%s %d %s v :%d Server(s)",
             from, RPL_STATSDEBUG, to, j);
}

static void
stats_gecos(struct Client *source_p)
{
  report_confitem_types(source_p, XLINE_TYPE, 0);
  report_confitem_types(source_p, RXLINE_TYPE, 0);
}

static void
stats_class(struct Client *source_p)
{
  report_confitem_types(source_p, CLASS_TYPE, 0);
}

static void
stats_memory(struct Client *source_p)
{
  count_memory(source_p);
}

static void
stats_numbers(struct Client *source_p)
{
  dump_counters(source_p);
}

static void
stats_ziplinks(struct Client *source_p)
{
  dlink_node *ptr;
  struct Client *target_p;
  unsigned int sent_data = 0;

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (IsCapable(target_p, CAP_ZIP))
    {
      /* we use memcpy(3) and a local copy of the structure to
       * work around a register use bug on GCC on the SPARC.
       * -jmallett, 04/27/2002
       */
      struct ZipStats zipstats;
      memcpy(&zipstats, &target_p->localClient->zipstats, sizeof (struct ZipStats));

      sendto_one(source_p, ":%s %d %s Z :ZipLinks stats for %s send[%.2f%% "
                 "compression (%lu bytes data/%lu bytes wire)] recv[%.2f%% "
                 "compression (%lu bytes data/%lu bytes wire)]",
                 from, RPL_STATSDEBUG, to, target_p->name,
                 zipstats.out_ratio, zipstats.out, zipstats.out_wire,
                 zipstats.in_ratio,  zipstats.in,  zipstats.in_wire);
      ++sent_data;
    }
  }

  sendto_one(source_p, ":%s %d %s Z :%u ziplink(s)",
             from, RPL_STATSDEBUG, to, sent_data);
}

static void
stats_servlinks(struct Client *source_p)
{
  uint64_t sendB = 0, recvB = 0;
  time_t uptime = 0;
  dlink_node *ptr = NULL;

  if (ConfigServerHide.flatten_links && !IsOper(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               from, to);
    return;
  }

  DLINK_FOREACH(ptr, serv_list.head)
  {
    struct Client *target_p = ptr->data;

    sendB += target_p->localClient->send.bytes;
    recvB += target_p->localClient->recv.bytes;

    /* ":%s 211 %s %s %u %u %llu %u %llu :%u %u %s" */
    sendto_one(source_p, form_str(RPL_STATSLINKINFO),
               from, to,
               get_client_name(target_p, IsAdmin(source_p) ? SHOW_IP : MASK_IP),
               dbuf_length(&target_p->localClient->buf_sendq),
               target_p->localClient->send.messages,
               target_p->localClient->send.bytes >> 10,
               target_p->localClient->recv.messages,
               target_p->localClient->recv.bytes >> 10,
               (unsigned)(CurrentTime - target_p->firsttime),
               (CurrentTime > target_p->since) ? (unsigned)(CurrentTime - target_p->since): 0,
               IsOper(source_p) ? show_capabilities(target_p) : "TS");
  }

  sendB >>= 10;
  recvB >>= 10;

  sendto_one(source_p, ":%s %d %s ? :%lu total server(s)",
             from, RPL_STATSDEBUG, to, dlink_list_length(&serv_list));
  sendto_one(source_p, ":%s %d %s ? :Sent total : %7.2f %s",
             from, RPL_STATSDEBUG, to,
             _GMKv(sendB), _GMKs(sendB));
  sendto_one(source_p, ":%s %d %s ? :Recv total : %7.2f %s",
             from, RPL_STATSDEBUG, to,
             _GMKv(recvB), _GMKs(recvB));

  uptime = (CurrentTime - me.since);

  sendto_one(source_p, ":%s %d %s ? :Server send: %7.2f %s (%4.1f K/s)",
             from, RPL_STATSDEBUG, to,
             _GMKv((me.localClient->send.bytes>>10)),
             _GMKs((me.localClient->send.bytes>>10)),
             (float)((float)((me.localClient->send.bytes) >> 10) /
             (float)uptime));
  sendto_one(source_p, ":%s %d %s ? :Server recv: %7.2f %s (%4.1f K/s)",
             from, RPL_STATSDEBUG, to,
             _GMKv((me.localClient->recv.bytes>>10)),
             _GMKs((me.localClient->recv.bytes>>10)),
             (float)((float)((me.localClient->recv.bytes) >> 10) /
             (float)uptime));
}

static void
stats_ltrace(struct Client *source_p, int parc, char *parv[])
{
  int doall = 0;
  int wilds = 0;
  char *name = NULL;
  char statchar;

  if ((name = parse_stats_args(parc, parv, &doall, &wilds)) != NULL)
  {
    statchar = parv[1][0];

    stats_L(source_p, name, doall, wilds, statchar);
  }
  else
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               from, to, "STATS");
}

/*
 * ms_stats - STATS message handler
 *      parv[0] = sender prefix
 *      parv[1] = statistics selector (defaults to Message frequency)
 *      parv[2] = server name (current server defaulted, if omitted)
 */
static void
ms_stats(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p,source_p,":%s STATS %s :%s",2,parc,parv)!=HUNTED_ISME)
    return;

  if (IsClient(source_p))
    mo_stats(client_p, source_p, parc, parv);
}

/*
 * stats_L
 *
 * inputs	- pointer to client to report to
 *		- doall flag
 *		- wild card or not
 * output	- NONE
 * side effects	-
 */
static void
stats_L(struct Client *source_p,char *name,int doall,
        int wilds,char statchar)
{
  stats_L_list(source_p, name, doall, wilds, &unknown_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &local_client_list, statchar);
  stats_L_list(source_p, name, doall, wilds, &serv_list, statchar);
}

static void
stats_L_list(struct Client *source_p,char *name, int doall, int wilds,
             dlink_list *list,char statchar)
{
  dlink_node *ptr;
  struct Client *target_p;

  /*
   * send info about connections which match, or all if the
   * mask matches from.  Only restrictions are on those who
   * are invisible not being visible to 'foreigners' who use
   * a wild card based search to list it.
   */
  DLINK_FOREACH(ptr, list->head)
  {
    target_p = ptr->data;

    if (IsInvisible(target_p) && (doall || wilds) &&
	!(MyConnect(source_p) && IsOper(source_p)) &&
	!IsOper(target_p) && (target_p != source_p))
      continue;
    if (!doall && wilds && !match(name, target_p->name))
      continue;
    if (!(doall || wilds) && irccmp(name, target_p->name))
      continue;

    /* This basically shows ips for our opers if its not a server/admin, or
     * its one of our admins.  */
    if(MyClient(source_p) && IsOper(source_p) && 
       (IsAdmin(source_p) || 
       (!IsServer(target_p) && !IsAdmin(target_p) && 
       !IsHandshake(target_p) && !IsConnecting(target_p))))
    {
      sendto_one(source_p, form_str(RPL_STATSLINKINFO),
		 from, to, 
                 (IsUpper(statchar)) ?
                 get_client_name(target_p, SHOW_IP) :
                 get_client_name(target_p, HIDE_IP),
                 dbuf_length(&target_p->localClient->buf_sendq),
                 target_p->localClient->send.messages,
                 target_p->localClient->send.bytes>>10,
                 target_p->localClient->recv.messages,
                 target_p->localClient->recv.bytes>>10,
                 (unsigned)(CurrentTime - target_p->firsttime),
                 (CurrentTime > target_p->since) ? (unsigned)(CurrentTime - target_p->since):0,
                 IsServer(target_p) ? show_capabilities(target_p) : "-");
    }
    else
    {
      /* If its a hidden ip, an admin, or a server, mask the real IP */
      if(IsIPSpoof(target_p) || IsServer(target_p) || IsAdmin(target_p)
         || IsHandshake(target_p) || IsConnecting(target_p))
        sendto_one(source_p, form_str(RPL_STATSLINKINFO),
                   from, to,
		   get_client_name(target_p, MASK_IP),
		   dbuf_length(&target_p->localClient->buf_sendq),
		   target_p->localClient->send.messages,
		   target_p->localClient->send.bytes>>10,
		   target_p->localClient->recv.messages,
		   target_p->localClient->recv.bytes>>10,
		   (unsigned)(CurrentTime - target_p->firsttime),
		   (CurrentTime > target_p->since) ? (unsigned)(CurrentTime - target_p->since):0,
		   IsServer(target_p) ? show_capabilities(target_p) : "-");
      else /* show the real IP */
        sendto_one(source_p, form_str(RPL_STATSLINKINFO),
                   from, to,
	           (IsUpper(statchar)) ?
		   get_client_name(target_p, SHOW_IP) :
		   get_client_name(target_p, HIDE_IP),
		   dbuf_length(&target_p->localClient->buf_sendq),
		   target_p->localClient->send.messages,
		   target_p->localClient->send.bytes>>10,
		   target_p->localClient->recv.messages,
		   target_p->localClient->recv.bytes>>10,
		   (unsigned)(CurrentTime - target_p->firsttime),
		   (CurrentTime > target_p->since) ? (unsigned)(CurrentTime - target_p->since):0,
		   IsServer(target_p) ? show_capabilities(target_p) : "-");
    }
  }
}

/* parse_stats_args()
 *
 * inputs	- arg count
 *		- args
 *		- doall flag
 *		- wild card or not
 * output	- pointer to name to use
 * side effects	-
 * common parse routine for m_stats args
 * 
 */
static char *
parse_stats_args(int parc, char *parv[], int *doall, int *wilds)
{
  char *name;

  if (parc > 2)
  {
    name = parv[2];

    if (!irccmp(name, from))
      *doall = 2;
    else if (match(name, from))
      *doall = 1;

    if (strchr(name, '*') ||
        strchr(name, '?'))
      *wilds = 1;

    return(name);
  }
  else
    return(NULL);
}
