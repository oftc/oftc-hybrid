/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_info.c: Sends information about the server.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
#include "list.h"
#include "channel.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"


static void send_conf_options(struct Client *);
static void send_birthdate_online_time(struct Client *);
static void send_info_text(struct Client *);

/*
 * jdc -- Structure for our configuration value table
 */
struct InfoStruct
{
  const char *name;         /* Displayed variable name           */
  unsigned int output_type; /* See below #defines                */
  void *option;             /* Pointer reference to the value    */
  const char *desc;         /* ASCII description of the variable */
};

/* Types for output_type in InfoStruct */
#define OUTPUT_STRING     0x0001 /* Output option as %s w/ dereference  */
#define OUTPUT_STRING_PTR 0x0002 /* Output option as %s w/out deference */
#define OUTPUT_DECIMAL    0x0004 /* Output option as decimal (%d)       */
#define OUTPUT_BOOLEAN    0x0008 /* Output option as "ON" or "OFF"      */
#define OUTPUT_BOOLEAN_YN 0x0010 /* Output option as "YES" or "NO"      */
#define OUTPUT_BOOLEAN2   0x0020 /* Output option as "YES/NO/MASKED"    */

static struct InfoStruct info_table[] =
{
  /* --[  START OF TABLE  ]-------------------------------------------- */

  {
    "CPATH",
    OUTPUT_STRING,
    NULL,
    "Path to Main Configuration File"
  },
  {
    "DPATH",
    OUTPUT_STRING,
    NULL,
    "Directory Containing Configuration Files"
  },
  {
    "DLPATH",
    OUTPUT_STRING,
    NULL,
    "Path to D-line File"
  },
  {
    "KPATH",
    OUTPUT_STRING,
    NULL,
    "Path to K-line File"
  },
  {
    "network_name",
    OUTPUT_STRING,
    NULL,
    "Network name"
  },
  {
    "network_desc",
    OUTPUT_STRING,
    NULL,
    "Network description"
  },
  {
    "hub",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Server is a hub"
  },
  {
    "max_clients",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum number of clients permitted simultaneously on this server"
  },
  {
    "max_nick_length",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum nickname length"
  },
  {
    "max_topic_length",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum topic length"
  },
  {
    "use_logging",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Enable logging"
  },
  {
    "disable_fake_channels",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Forbids channels with special ASCII characters in their name"
  },
  {
    "restrict_channels",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Only reserved channels are allowed"
  },
  {
    "knock_delay",
    OUTPUT_DECIMAL,
    NULL,
    "Delay between a users KNOCK attempts"
  },
  {
    "knock_delay_channel",
    OUTPUT_DECIMAL,
    NULL,
    "Delay between KNOCK attempts to a channel"
  },
  {
    "max_chans_per_user",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum number of channels a user can join"
  },
  {
    "max_chans_per_oper",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum number of channels an oper can join"
  },
  {
    "quiet_on_ban",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Banned users may not send text to a channel"
  },
  {
    "max_bans",
    OUTPUT_DECIMAL,
    NULL,
    "Total +b/e/I modes allowed in a channel"
  },
  {
    "default_split_user_count",
    OUTPUT_DECIMAL,
    NULL,
    "Startup value of SPLITUSERS"
  },
  {
    "default_split_server_count",
    OUTPUT_DECIMAL,
    NULL,
    "Startup value of SPLITNUM"
  },
  {
    "no_create_on_split",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Disallow creation of channels when split"
  },
  {
    "no_join_on_split",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Disallow joining channels when split"
  },
  {
    "flatten_links",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Flatten /links list"
  },
  {
    "links_delay",
    OUTPUT_DECIMAL,
    NULL,
    "Links rehash delay"
  },
  {
    "hidden",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Hide this server from a flattened /links on remote servers"
  },
  {
    "hide_servers",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Hide servernames from users"
  },
  {
    "hidden_name",
    OUTPUT_STRING,
    NULL,
    "Server name users see if hide_servers = yes"
  },
  {
    "hide_server_ips",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Prevent people from seeing server IPs"
  },
  {
    "invisible_on_connect",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Automatically set mode +i on connecting users"
  },
  {
    "kill_chase_time_limit",
    OUTPUT_DECIMAL,
    NULL,
    "Nick Change Tracker for KILL"
  },
  {
    "hide_spoof_ips",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Hide spoofed IP's"
  },
  {
    "ignore_bogus_ts",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Ignore bogus timestamps from other servers"
  },
  {
    "disable_auth",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Completely disable ident lookups"
  },
  {
    "disable_remote_commands",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Prevent users issuing commands on remote servers"
  },
  {
    "tkline_expire_notices",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Show temporary kline/xline expire notices"
  },
  {
    "default_floodcount",
    OUTPUT_DECIMAL,
    NULL,
    "Startup value of FLOODCOUNT"
  },
  {
    "failed_oper_notice",
    OUTPUT_BOOLEAN,
    NULL,
    "Inform opers if someone /oper's with the wrong password"
  },
  {
    "dots_in_ident",
    OUTPUT_DECIMAL,
    NULL,
    "Number of permissable dots in an ident"
  },
  {
    "min_nonwildcard",
    OUTPUT_DECIMAL,
    NULL,
    "Minimum non-wildcard chars in K/G lines"
  },
  {
    "min_nonwildcard_simple",
    OUTPUT_DECIMAL,
    NULL,
    "Minimum non-wildcards in gecos bans"
  },
  {
    "max_accept",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum nicknames on accept list"
  },
  {
    "anti_nick_flood",
    OUTPUT_BOOLEAN,
    NULL,
    "NICK flood protection"
  },
  {
    "max_nick_time",
    OUTPUT_DECIMAL,
    NULL,
    "NICK flood protection time interval"
  },
  {
    "max_nick_changes",
    OUTPUT_DECIMAL,
    NULL,
    "NICK change threshhold setting"
  },
  {
    "anti_spam_exit_message_time",
    OUTPUT_DECIMAL,
    NULL,
    "Duration a client must be connected for to have an exit message"
  },
  {
    "ts_warn_delta",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum permitted TS delta before displaying a warning"
  },
  {
    "ts_max_delta",
    OUTPUT_DECIMAL,
    NULL,
    "Maximum permitted TS delta from another server"
  },
  {
    "warn_no_nline",
    OUTPUT_BOOLEAN,
    NULL,
    "Display warning if connecting server lacks N-line"
  },
  {
    "stats_e_disabled",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Whether or not STATS e is disabled"
  },
  {
    "stats_o_oper_only",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "STATS O output is only shown to operators"
  },
  {
    "stats_P_oper_only",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "STATS P is only shown to operators"
  },
  {
    "stats_i_oper_only",
    OUTPUT_BOOLEAN2,
    NULL,
    "STATS I output is only shown to operators"
  },
  {
    "stats_k_oper_only",
    OUTPUT_BOOLEAN2,
    NULL,
    "STATS K output is only shown to operators"
  },
  {
    "caller_id_wait",
    OUTPUT_DECIMAL,
    NULL,
    "Minimum delay between notifying UMODE +g users of messages"
  },
  {
    "opers_bypass_callerid",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Allows IRC operators to message users who are +g (callerid)"
  },
  {
    "pace_wait_simple",
    OUTPUT_DECIMAL,
    NULL,
    "Minimum delay between less intensive commands"
  },
  {
    "pace_wait",
    OUTPUT_DECIMAL,
    NULL,
    "Minimum delay between uses of certain commands"
  },
  {
    "short_motd",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Do not show MOTD; only tell clients they should read it"
  },
  {
    "ping_cookie",
    OUTPUT_BOOLEAN,
    NULL,
    "Require ping cookies to connect"
  },
  {
    "no_oper_flood",
    OUTPUT_BOOLEAN,
    NULL,
    "Reduce flood control for operators"
  },
  {
    "true_no_oper_flood",
    OUTPUT_BOOLEAN,
    NULL,
    "Completely disable flood control for operators"
  },
  {
    "oper_pass_resv",
    OUTPUT_BOOLEAN_YN,
    NULL,
    "Opers can over-ride RESVs"
  },
  {
    "max_targets",
    OUTPUT_DECIMAL,
    NULL,
    "The maximum number of PRIVMSG/NOTICE targets"
  },
  {
    "throttle_time",
    OUTPUT_DECIMAL,
    NULL,
    "Minimum time between client reconnects"
  },

  /* --[  END OF TABLE  ]---------------------------------------------- */
  {
    NULL,
    0,
    NULL,
    0
  }
};

/*
** m_info()
**  parv[0] = sender prefix
**  parv[1] = servername
*/
static void
m_info(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }
  else
    last_used = CurrentTime;

  if (!ConfigFileEntry.disable_remote)
    if (hunt_server(client_p, source_p, ":%s INFO :%s", 1,
                    parc, parv) != HUNTED_ISME)
      return;

  send_info_text(source_p);
}

/*
** mo_info()
**  parv[0] = sender prefix
**  parv[1] = servername
*/
static void
mo_info(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s INFO :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return;

  send_info_text(source_p);
}

/*
** ms_info()
**  parv[0] = sender prefix
**  parv[1] = servername
*/
static void
ms_info(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  if (!IsClient(source_p))
    return;

  if (hunt_server(client_p, source_p, ":%s INFO :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return;

  send_info_text(source_p);
}

/* send_info_text()
 *
 * inputs  - client pointer to send info text to
 * output  - NONE
 * side effects  - info text is sent to client
 */
static void
send_info_text(struct Client *source_p)
{
  const char **text = infotext;
  char *source, *target;

  sendto_realops_flags(UMODE_SPY, L_ALL,
                       "INFO requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) &&
      HasID(source_p))
    source = me.id, target = source_p->id;
  else
    source = me.name, target = source_p->name;

  while (*text)
  {
    const char *line = *text++;

    if (*line == '\0')
      line = " ";

    sendto_one(source_p, form_str(RPL_INFO),
               source, target, line);
  }

  if (HasUMode(source_p, UMODE_OPER))
    send_conf_options(source_p);

  send_birthdate_online_time(source_p);

  sendto_one(source_p, form_str(RPL_ENDOFINFO),
             me.name, source_p->name);
}

/* send_birthdate_online_time()
 *
 * inputs  - client pointer to send to
 * output  - NONE
 * side effects  - birthdate and online time are sent
 */
static void
send_birthdate_online_time(struct Client *source_p)
{
  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6)
      && HasID(source_p))
  {
    sendto_one(source_p, ":%s %d %s :On-line since %s",
               me.id, RPL_INFO, source_p->id,
               myctime(me.localClient->firsttime));
  }
  else
  {
    sendto_one(source_p, ":%s %d %s :On-line since %s",
               me.name, RPL_INFO, source_p->name,
               myctime(me.localClient->firsttime));
  }
}

/* send_conf_options()
 *
 * inputs  - client pointer to send to
 * output  - NONE
 * side effects  - send config options to client
 */
static void
send_conf_options(struct Client *source_p)
{
  const char *from, *to;
  const struct InfoStruct *iptr = NULL;

  /* Now send them a list of all our configuration options
   * (mostly from defaults.h and setup.h)
   */
  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6)
      && HasID(source_p))
  {
    from = me.id;
    to = source_p->id;
  }
  else
  {
    from = me.name;
    to = source_p->name;
  }

  /*
   * Parse the info_table[] and do the magic.
   */
  for (iptr = info_table; iptr->name; ++iptr)
  {
    switch (iptr->output_type)
    {
        /* For "char *" references */
      case OUTPUT_STRING:
      {
        const char *option = *((char **)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? option : "NONE",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* For "char foo[]" references */
      case OUTPUT_STRING_PTR:
      {
        const char *option = iptr->option;

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? option : "NONE",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as a decimal value. */
      case OUTPUT_DECIMAL:
      {
        const int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5d [%-30s]",
                   from, RPL_INFO, to, iptr->name,
                   option, iptr->desc ? iptr->desc : "<none>");
        break;
      }

      /* Output info_table[i].option as "ON" or "OFF" */
      case OUTPUT_BOOLEAN:
      {
        const int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? "ON" : "OFF",
                   iptr->desc ? iptr->desc : "<none>");

        break;
      }

      /* Output info_table[i].option as "YES" or "NO" */
      case OUTPUT_BOOLEAN_YN:
      {
        int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? "YES" : "NO",
                   iptr->desc ? iptr->desc : "<none>");
        break;
      }

      case OUTPUT_BOOLEAN2:
      {
        int option = *((int *)iptr->option);

        sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                   from, RPL_INFO, to,
                   iptr->name, option ? ((option == 1) ? "MASK" : "YES") : "NO",
                     iptr->desc ? iptr->desc : "<none>");
        break;
      }
    }
  }

  sendto_one(source_p, form_str(RPL_INFO),
             from, to, "");
}

static struct Message info_msgtab =
{
  "INFO", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_info, ms_info, m_ignore, mo_info, m_ignore }
};

static void
module_init()
{
  mod_add_cmd(&info_msgtab);
  info_table[0].option = &ConfigFileEntry.configfile;
  info_table[1].option = &ConfigFileEntry.dpath;
  info_table[2].option = &ConfigFileEntry.dlinefile;
  info_table[3].option = &ConfigFileEntry.klinefile;
  info_table[4].option = &ServerInfo.network_name;
  info_table[5].option = &ServerInfo.network_desc;
  info_table[6].option = &ServerInfo.hub;
  info_table[7].option = &ServerInfo.max_clients;
  info_table[8].option = &ServerInfo.max_nick_length;
  info_table[9].option = &ServerInfo.max_topic_length;
  info_table[10].option = &ConfigLoggingEntry.use_logging;
  info_table[11].option = &ConfigChannel.disable_fake_channels;
  info_table[12].option = &ConfigChannel.restrict_channels;
  info_table[13].option = &ConfigChannel.knock_delay;
  info_table[14].option = &ConfigChannel.knock_delay_channel;
  info_table[15].option = &ConfigChannel.max_chans_per_user;
  info_table[16].option = &ConfigChannel.max_chans_per_oper;
  info_table[17].option = &ConfigChannel.quiet_on_ban;
  info_table[18].option = &ConfigChannel.max_bans;
  info_table[19].option = &ConfigChannel.default_split_user_count;
  info_table[20].option = &ConfigChannel.default_split_server_count;
  info_table[21].option = &ConfigChannel.no_create_on_split;
  info_table[22].option = &ConfigChannel.no_join_on_split;
  info_table[23].option = &ConfigServerHide.flatten_links;
  info_table[24].option = &ConfigServerHide.links_delay;
  info_table[25].option = &ConfigServerHide.hidden;
  info_table[26].option = &ConfigServerHide.hide_servers;
  info_table[27].option = &ConfigServerHide.hidden_name;
  info_table[28].option = &ConfigServerHide.hide_server_ips;
  info_table[29].option = &ConfigFileEntry.invisible_on_connect;
  info_table[30].option = &ConfigFileEntry.kill_chase_time_limit;
  info_table[31].option = &ConfigFileEntry.hide_spoof_ips;
  info_table[32].option = &ConfigFileEntry.ignore_bogus_ts;
  info_table[33].option = &ConfigFileEntry.disable_auth;
  info_table[34].option = &ConfigFileEntry.disable_remote;
  info_table[35].option = &ConfigFileEntry.tkline_expire_notices;
  info_table[36].option = &ConfigFileEntry.default_floodcount;
  info_table[37].option = &ConfigFileEntry.failed_oper_notice;
  info_table[38].option = &ConfigFileEntry.dots_in_ident;
  info_table[39].option = &ConfigFileEntry.min_nonwildcard;
  info_table[40].option = &ConfigFileEntry.min_nonwildcard_simple;
  info_table[41].option = &ConfigFileEntry.max_accept;
  info_table[42].option = &ConfigFileEntry.anti_nick_flood;
  info_table[43].option = &ConfigFileEntry.max_nick_time;
  info_table[44].option = &ConfigFileEntry.max_nick_changes;
  info_table[45].option = &ConfigFileEntry.anti_spam_exit_message_time;
  info_table[46].option = &ConfigFileEntry.ts_warn_delta;
  info_table[47].option = &ConfigFileEntry.ts_max_delta;
  info_table[48].option = &ConfigFileEntry.warn_no_nline;
  info_table[49].option = &ConfigFileEntry.stats_e_disabled;
  info_table[50].option = &ConfigFileEntry.stats_o_oper_only;
  info_table[51].option = &ConfigFileEntry.stats_P_oper_only;
  info_table[52].option = &ConfigFileEntry.stats_i_oper_only;
  info_table[53].option = &ConfigFileEntry.stats_k_oper_only;
  info_table[54].option = &ConfigFileEntry.caller_id_wait;
  info_table[55].option = &ConfigFileEntry.opers_bypass_callerid;
  info_table[56].option = &ConfigFileEntry.pace_wait_simple;
  info_table[57].option = &ConfigFileEntry.pace_wait;
  info_table[58].option = &ConfigFileEntry.short_motd;
  info_table[59].option = &ConfigFileEntry.ping_cookie;
  info_table[60].option = &ConfigFileEntry.no_oper_flood;
  info_table[61].option = &ConfigFileEntry.true_no_oper_flood;
  info_table[62].option = &ConfigFileEntry.oper_pass_resv;
  info_table[63].option = &ConfigFileEntry.max_targets;
  info_table[64].option = &ConfigFileEntry.throttle_time;
}

static void
module_exit()
{
  mod_del_cmd(&info_msgtab);
}

IRCD_EXPORT struct module module_entry =
{
  { NULL, NULL, NULL },
  NULL,
  "$Revision$",
  NULL,
  module_init,
  module_exit,
  0
};
