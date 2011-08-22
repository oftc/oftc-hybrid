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
#include "tools.h"
#include "m_info.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircd.h"
#include "hook.h"
#include "numeric.h"
#include "s_log.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "s_conf.h"
#include "handlers.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "conf_general.h"
#include "conf_serverinfo.h"
#include "conf_logging.h"

static void send_conf_options(struct Client *);
static void send_birthdate_online_time(struct Client *);
static void send_info_text(struct Client *);

static void m_info(struct Client *, struct Client *, int, char *[]);
static void ms_info(struct Client *, struct Client *, int, char *[]);
static void mo_info(struct Client *, struct Client *, int, char *[]);

struct Message info_msgtab = {
  "INFO", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_info, ms_info, m_ignore, mo_info, m_ignore }
};

#ifndef STATIC_MODULES
const char *_version = "$Revision$";
static struct Callback *info_cb;

static void *
va_send_info_text(va_list args)
{
  send_info_text(va_arg(args, struct Client *));
  return NULL;
}

void
_modinit(void)
{
  info_cb = register_callback("doing_info", va_send_info_text);
  mod_add_cmd(&info_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&info_msgtab);
  uninstall_hook(info_cb, va_send_info_text);
}
#endif

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

static const struct InfoStruct info_table[] =
{
  /* --[  START OF TABLE  ]-------------------------------------------- */
  {
    "network_name",
    OUTPUT_STRING,
    &serverinfo_config.network_name,
    "Network name"
  },
  {
    "network_desc",
    OUTPUT_STRING,
    &serverinfo_config.network_desc,
    "Network description"
  },
  {
    "hub",
    OUTPUT_BOOLEAN_YN,
    &serverinfo_config.hub,
    "Server is a hub"
  },
  {
    "use_logging",
    OUTPUT_BOOLEAN_YN,
    &logging_config.use_logging,
    "Enable logging"
  },
  {
    "fuserlog",
    OUTPUT_STRING_PTR,
    &logging_config.userlog,
    "User log file"
  },
  {
    "foperlog",
    OUTPUT_STRING_PTR,
    &logging_config.operlog,
    "Operator log file"
  },
  {
    "fkilllog",
    OUTPUT_STRING_PTR,
    &logging_config.killlog,
    "Kill log file"
  },
  {
    "fklinelog",
    OUTPUT_STRING_PTR,
    &logging_config.klinelog,
    "K-Line log file"
  },
  {
    "restrict_channels",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.restrict_channels,
    "Only reserved channels are allowed"
  },
  {
    "disable_local_channels",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.disable_local_channels,
    "Prevent users from joining &channels"
  },
 {
    "use_invex",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.use_invex,
    "Enable chanmode +I (invite exceptions)"
  },
 {
   "use_quiet",
   OUTPUT_BOOLEAN_YN,
   &ConfigChannel.use_quiet,
   "Enable chanmode +q (Quiet users)"
 },
  {
    "use_except",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.use_except,
    "Enable chanmode +e (ban exceptions)"
  },
  {
    "use_knock",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.use_knock,
    "Enable /KNOCK"
  },
  {
    "knock_delay",
    OUTPUT_DECIMAL,
    &ConfigChannel.knock_delay,
    "Delay between a users KNOCK attempts"
  },
  {
    "knock_delay_channel",
    OUTPUT_DECIMAL,
    &ConfigChannel.knock_delay_channel,
    "Delay between KNOCK attempts to a channel"
  },
  {
    "max_chans_per_user",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_chans_per_user,
    "Maximum number of channels a user can join"
  },
  {
    "quiet_on_ban",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.quiet_on_ban,
    "Banned users may not send text to a channel"
  },
  {
    "max_bans",
    OUTPUT_DECIMAL,
    &ConfigChannel.max_bans,
    "Total +b/e/I modes allowed in a channel"
  },
  {
    "default_split_user_count",
    OUTPUT_DECIMAL,
    &ConfigChannel.default_split_user_count,
    "Startup value of SPLITUSERS"
  },
  {
    "default_split_server_count",
    OUTPUT_DECIMAL,
    &ConfigChannel.default_split_server_count,
    "Startup value of SPLITNUM"
  },
  {
    "no_create_on_split",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.no_create_on_split,
    "Disallow creation of channels when split"
  },
  {
    "no_join_on_split",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.no_join_on_split,
    "Disallow joining channels when split"
  },
  {
    "burst_topicwho",
    OUTPUT_BOOLEAN_YN,
    &ConfigChannel.burst_topicwho,
    "Enable sending of who set topic on topicburst"
  },
  {
    "flatten_links",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.flatten_links,
    "Flatten /links list"
  },
  {
    "links_delay",
    OUTPUT_DECIMAL,
    &ConfigServerHide.links_delay,
    "Links rehash delay"
  },
  {
    "hidden",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.hidden,
    "Hide this server from a flattened /links on remote servers"
  },
  {
    "disable_hidden",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.disable_hidden,
    "Prevent servers from hiding themselves from a flattened /links"
  },
  {
    "hide_servers",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.hide_servers,
    "Hide servernames from users"
  },
  {
    "hidden_name",
    OUTPUT_STRING,
    &ConfigServerHide.hidden_name,
    "Server name users see if hide_servers = yes"
  },
  {
    "hide_server_ips",
    OUTPUT_BOOLEAN_YN,
    &ConfigServerHide.hide_server_ips,
    "Prevent people from seeing server IPs"
  },
  {
    "invisible_on_connect",
    OUTPUT_BOOLEAN_YN,
    &general_config.invisible_on_connect,
    "Automatically set mode +i on connecting users"
  },
  {
    "burst_away",
    OUTPUT_BOOLEAN_YN,
    &general_config.burst_away,
    "Send /away string that users have set on the server burst"
  },
  {
    "use_whois_actually",
    OUTPUT_BOOLEAN_YN,
    &general_config.use_whois_actually,
    "Show IP address on /WHOIS when possible"
  },
  {
    "kill_chase_time_limit",
    OUTPUT_DECIMAL,
    &general_config.kill_chase_time_limit,
    "Nick Change Tracker for KILL"
  },
  {
    "hide_spoof_ips",
    OUTPUT_BOOLEAN_YN,
    &general_config.hide_spoof_ips,
    "Hide spoofed IP's"
  },
  {
    "ignore_bogus_ts",
    OUTPUT_BOOLEAN_YN,
    &general_config.ignore_bogus_ts,
    "Ignore bogus timestamps from other servers"
  },
  {
    "disable_auth",
    OUTPUT_BOOLEAN_YN,
    &general_config.disable_auth,
    "Completely disable ident lookups"
  },
  {
    "disable_remote_commands",
    OUTPUT_BOOLEAN_YN,
    &general_config.disable_remote_commands,
    "Prevent users issuing commands on remote servers"
  },
  {
    "tkline_expire_notices",
    OUTPUT_BOOLEAN_YN,
    &general_config.tkline_expire_notices,
    "Show temporary kline/xline expire notices"
  },
  {
    "default_floodcount",
    OUTPUT_DECIMAL,
    &general_config.default_floodcount,
    "Startup value of FLOODCOUNT"
  },
  {
    "failed_oper_notice",
    OUTPUT_BOOLEAN,
    &general_config.failed_oper_notice,
    "Inform opers if someone /oper's with the wrong password"
  },
  {
    "dots_in_ident",
    OUTPUT_DECIMAL,
    &general_config.dots_in_ident,
    "Number of permissable dots in an ident"
  },
  {
    "dot_in_ip6_addr",
    OUTPUT_BOOLEAN,
    &general_config.dot_in_ip6_addr,
    "Suffix a . to ip6 addresses (for linked servers still running hybrid-6)"
  },
  {
    "min_nonwildcard",
    OUTPUT_DECIMAL,
    &general_config.min_nonwildcard,
    "Minimum non-wildcard chars in K/G lines"
  },
  {
    "min_nonwildcard_simple",
    OUTPUT_DECIMAL,
    &general_config.min_nonwildcard_simple,
    "Minimum non-wildcards in gecos bans"
  },
  {
    "max_accept",
    OUTPUT_DECIMAL,
    &general_config.max_accept,
    "Maximum nicknames on accept list"
  },
  {
    "anti_nick_flood",
    OUTPUT_BOOLEAN,
    &general_config.anti_nick_flood,
    "NICK flood protection"
  },
  {
    "max_nick_time",
    OUTPUT_DECIMAL,
    &general_config.max_nick_time,
    "NICK flood protection time interval"
  },
  {
    "max_nick_changes",
    OUTPUT_DECIMAL,
    &general_config.max_nick_changes,
    "NICK change threshhold setting"
  },
  {
    "anti_spam_exit_message_time",
    OUTPUT_DECIMAL,
    &general_config.anti_spam_exit_message_time,
    "Duration a client must be connected for to have an exit message"
  },
  {
    "ts_warn_delta",
    OUTPUT_DECIMAL,
    &general_config.ts_warn_delta,
    "Maximum permitted TS delta before displaying a warning"
  },
  {
    "ts_max_delta",
    OUTPUT_DECIMAL,
    &general_config.ts_max_delta,
    "Maximum permitted TS delta from another server"
  },
  {
    "kline_with_reason",
    OUTPUT_BOOLEAN_YN,
    &general_config.kline_with_reason,
    "Display K-line reason to client on disconnect"
  },
  {
    "kline_reason",
    OUTPUT_STRING,
    &general_config.kline_reason,
    "Reason given to K-lined clients on sign off"
  },
  {
    "warn_no_nline",
    OUTPUT_BOOLEAN,
    &general_config.warn_no_nline,
    "Display warning if connecting server lacks N-line"
  },
  {
    "stats_o_oper_only",
    OUTPUT_BOOLEAN_YN,
    &general_config.stats_o_oper_only,
    "STATS O output is only shown to operators"
  },
  {
    "stats_P_oper_only",
    OUTPUT_BOOLEAN_YN,
    &general_config.stats_P_oper_only,
    "STATS P is only shown to operators"
  },
  {
    "stats_i_oper_only",
    OUTPUT_BOOLEAN2,
    &general_config.stats_i_oper_only,
    "STATS I output is only shown to operators"
  },
  {
    "stats_k_oper_only",
    OUTPUT_BOOLEAN2,
    &general_config.stats_k_oper_only,
    "STATS K output is only shown to operators"
  },
  {
    "caller_id_wait",
    OUTPUT_DECIMAL,
    &general_config.caller_id_wait,
    "Minimum delay between notifying UMODE +g users of messages"
  },
  {
    "opers_bypass_callerid",
    OUTPUT_BOOLEAN_YN,
    &general_config.opers_bypass_callerid,
    "Allows IRC operators to message users who are +g (callerid)"
  },
  {
    "pace_wait_simple",
    OUTPUT_DECIMAL,
    &general_config.pace_wait_simple,
    "Minimum delay between less intensive commands"
  },
  {
    "pace_wait",
    OUTPUT_DECIMAL,
    &general_config.pace_wait,
    "Minimum delay between uses of certain commands"
  },
  {
    "short_motd",
    OUTPUT_BOOLEAN_YN,
    &general_config.short_motd,
    "Do not show MOTD; only tell clients they should read it"
  },
  {
    "ping_cookie",
    OUTPUT_BOOLEAN,
    &general_config.ping_cookie,
    "Require ping cookies to connect"
  },
  {
    "no_oper_flood",
    OUTPUT_BOOLEAN,
    &general_config.no_oper_flood,
    "Reduce flood control for operators"
  },
  {
    "true_no_oper_flood",
    OUTPUT_BOOLEAN,
    &general_config.true_no_oper_flood,
    "Completely disable flood control for operators"
  },
  {
    "oper_pass_resv",
    OUTPUT_BOOLEAN_YN,
    &general_config.oper_pass_resv,
    "Opers can over-ride RESVs"
  },
  {
    "idletime",
    OUTPUT_DECIMAL,
    &general_config.idletime,
    "Number of seconds before a client is considered idle"
  },
  {
    "max_targets",
    OUTPUT_DECIMAL,
    &general_config.max_targets,
    "The maximum number of PRIVMSG/NOTICE targets"
  },
  {
    "client_flood",
    OUTPUT_DECIMAL,
    &general_config.client_flood,
    "Maximum amount of data in a client's queue before they are disconnected"
  },
  {
    "throttle_time",
    OUTPUT_DECIMAL,
    &general_config.throttle_time,
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

  if ((last_used + general_config.pace_wait) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }
  else
    last_used = CurrentTime;

  if (!general_config.disable_remote_commands)
  {
    if (hunt_server(client_p,source_p, ":%s INFO :%s",
                    1, parc, parv) != HUNTED_ISME)
    {
      return;
    }
  }

#ifdef STATIC_MODULES
  send_info_text(source_p);
#else
  execute_callback(info_cb, source_p, parc, parv);
#endif
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

#ifdef STATIC_MODULES
  send_info_text(source_p);
#else
  execute_callback(info_cb, source_p, parc, parv);
#endif
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

  if (hunt_server(client_p, source_p, ":%s INFO :%s",
                  1, parc, parv) != HUNTED_ISME)
    return;

#ifdef STATIC_MODULES
  send_info_text(source_p);
#else
  execute_callback(info_cb, source_p, parc, parv);
#endif
}

/* send_info_text()
 *
 * inputs	- client pointer to send info text to
 * output	- NONE
 * side effects	- info text is sent to client
 */
static void
send_info_text(struct Client *source_p)
{
  const char **text = infotext;
  char *source, *target;
  
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

  if (IsOper(source_p))
    send_conf_options(source_p);

  send_birthdate_online_time(source_p);

  sendto_one(source_p, form_str(RPL_ENDOFINFO),
             me.name, source_p->name);
}

/* send_birthdate_online_time()
 *
 * inputs	- client pointer to send to
 * output	- NONE
 * side effects	- birthdate and online time are sent
 */
static void
send_birthdate_online_time(struct Client *source_p)
{
  if (!MyClient(source_p) && IsCapable(source_p->from, CAP_TS6) && HasID(source_p))
  {
    sendto_one(source_p, ":%s %d %s :On-line since %s",
               me.id, RPL_INFO, source_p->id,
               myctime(me.firsttime));
  }
  else
  {
    sendto_one(source_p, ":%s %d %s :On-line since %s",
               me.name, RPL_INFO, source_p->name,
               myctime(me.firsttime));
  }
}

/* send_conf_options()
 *
 * inputs	- client pointer to send to
 * output	- NONE
 * side effects	- send config options to client
 */
static void
send_conf_options(struct Client *source_p)
{
  Info *infoptr;
  const char *from, *to;
  const struct InfoStruct *iptr = NULL;

  /* Now send them a list of all our configuration options
   * (mostly from defaults.h and setup.h)
   */
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

  for (infoptr = MyInformation; infoptr->name; infoptr++)
  {
    if (infoptr->intvalue)
    {
      sendto_one(source_p, ":%s %d %s :%-30s %-5d [%-30s]",
                 from, RPL_INFO, to, infoptr->name,
                 infoptr->intvalue, infoptr->desc);
    }
    else
    {
      sendto_one(source_p, ":%s %d %s :%-30s %-5s [%-30s]",
                 from, RPL_INFO, to, infoptr->name,
                 infoptr->strvalue, infoptr->desc);
    }
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

#ifndef EFNET
  /* jdc -- Only send compile information to admins. */
  if (IsAdmin(source_p))
    sendto_one(source_p, ":%s %d %s :Running on [%s]",
               from, RPL_INFO, to, ircd_platform); 
#endif
  sendto_one(source_p, form_str(RPL_INFO),
             from, to, "");
}
