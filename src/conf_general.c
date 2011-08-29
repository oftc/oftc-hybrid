#include "stdinc.h"
#include "config.h"
#include "conf_general.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "s_log.h"
#include "memory.h"
#include "s_user.h"
#include "numeric.h"
#include "common.h"

struct config_section_entry general_section_entries[] = {
  { GENERAL_SECTION_ENTRY(anti_nick_flood, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(anti_spam_exit_message_time, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(burst_away, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(caller_id_wait, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(client_flood, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(compression_level, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(default_cipher_preference, json_type_string) }, 
  { GENERAL_SECTION_ENTRY(default_floodcount, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(disable_auth, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(disable_remote_commands, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(dot_in_ip6_addr, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(dots_in_ident, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(egdpool_path, json_type_string) }, 
  { GENERAL_SECTION_ENTRY(failed_oper_notice, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(godmode_timeout, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(havent_read_conf, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(hide_spoof_ips, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(idletime, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(ignore_bogus_ts, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(invisible_on_connect, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(kline_min_cidr, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(kline_min_cidr6, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(kill_chase_time_limit, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(kline_reason, json_type_string) }, 
  { GENERAL_SECTION_ENTRY(kline_with_reason, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(max_accept, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(max_nick_changes, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(max_nick_time, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(max_targets, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(max_watch, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(message_locale, json_type_string) }, 
  { GENERAL_SECTION_ENTRY(min_nonwildcard, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(min_nonwildcard_simple, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(no_oper_flood, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(oper_only_umodes, json_type_string) }, 
  { GENERAL_SECTION_ENTRY(oper_pass_resv, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(oper_umodes, json_type_string) }, 
  { GENERAL_SECTION_ENTRY(opers_bypass_callerid, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(pace_wait, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(pace_wait_simple, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(ping_cookie, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(reject_hold_time, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(servlink_path, json_type_string) }, 
  { GENERAL_SECTION_ENTRY(short_motd, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(stats_e_disabled, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(stats_i_oper_only, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(stats_k_oper_only, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(stats_o_oper_only, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(stats_P_oper_only, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(tkline_expire_notices, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(throttle_time, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(true_no_oper_flood, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(ts_max_delta, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(ts_warn_delta, json_type_int) }, 
  { GENERAL_SECTION_ENTRY(use_egd, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(use_whois_actually, json_type_boolean) }, 
  { GENERAL_SECTION_ENTRY(warn_no_nline, json_type_boolean) }, 
  { "", 0, 0, 0 }
};

struct conf_general general_config;

void
general_section_clearout()
{
  MyFree(general_config.egdpool_path);
  general_config.egdpool_path = NULL;
  MyFree(general_config.servlink_path);
  general_config.servlink_path = NULL;
#ifdef HAVE_LIBCRYPTO
  general_config.default_cipher_preference = NULL;
#endif /* HAVE_LIBCRYPTO */
}

void
general_section_set_defaults()
{
  general_config.max_watch = WATCHSIZE_DEFAULT;
  general_config.kline_min_cidr = 16;
  general_config.kline_min_cidr6 = 48;
  general_config.invisible_on_connect = YES;
  general_config.burst_away = NO;
  general_config.use_whois_actually = YES;
  general_config.tkline_expire_notices = YES;
  general_config.hide_spoof_ips = YES;
  general_config.ignore_bogus_ts = NO;
  general_config.disable_auth = NO;
  general_config.disable_remote_commands = NO;
  general_config.kill_chase_time_limit = 90;
  general_config.default_floodcount = 8; /* XXX */
  general_config.failed_oper_notice = YES;
  general_config.dots_in_ident = 0;      /* XXX */
  general_config.dot_in_ip6_addr = YES;
  general_config.min_nonwildcard = 4;
  general_config.min_nonwildcard_simple = 3;
  general_config.max_accept = 20;
  general_config.anti_nick_flood = NO;   /* XXX */
  general_config.max_nick_time = 20;
  general_config.max_nick_changes = 5;
  general_config.anti_spam_exit_message_time = 0;  /* XXX */
  general_config.ts_warn_delta = TS_WARN_DELTA_DEFAULT;
  general_config.ts_max_delta = TS_MAX_DELTA_DEFAULT;  /* XXX */
  general_config.kline_with_reason = YES;
  general_config.kline_reason = NULL;
  general_config.warn_no_nline = YES;
  general_config.stats_o_oper_only = NO; /* XXX */
  general_config.stats_k_oper_only = 1;  /* masked */
  general_config.stats_i_oper_only = 1;  /* masked */
  general_config.stats_P_oper_only = NO;
  general_config.caller_id_wait = 60;
  general_config.opers_bypass_callerid = NO;
  general_config.pace_wait = 10;
  general_config.pace_wait_simple = 1;
  general_config.short_motd = NO;
  general_config.ping_cookie = NO;
  general_config.no_oper_flood = NO;     /* XXX */
  general_config.true_no_oper_flood = NO;  /* XXX */
  general_config.oper_pass_resv = YES;
  general_config.idletime = 0;
  general_config.max_targets = MAX_TARGETS_DEFAULT;
  general_config.client_flood = CLIENT_FLOOD_DEFAULT;
  general_config.oper_only_umodes = "SD";
  general_config.oper_umodes = "blswz";
  DupString(general_config.servlink_path, SLPATH);
//  general_config.default_cipher_preference = &CipherTable[1];
  general_config.use_egd = NO;
  general_config.egdpool_path = NULL;
#ifdef HAVE_LIBZ
  general_config.compression_level = 0;
#endif
  general_config.throttle_time = 10;
}

void
general_section_validate()
{
  if(general_config.havent_read_conf)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }

  general_config.oper_only_umodes_int = mode_string_to_flags(general_config.oper_only_umodes);
  general_config.oper_umodes_int = mode_string_to_flags(general_config.oper_umodes);

  if(strlen(general_config.message_locale) > LOCALE_LENGTH - 2)
    general_config.message_locale[LOCALE_LENGTH-1] = '\0';

  set_locale(general_config.message_locale);

  if(general_config.compression_level < 1 || general_config.compression_level > 9)
    general_config.compression_level = 0;

  add_isupport("MAXTARGETS", NULL, general_config.max_targets);

  if (general_config.ts_warn_delta < TS_WARN_DELTA_MIN)
    general_config.ts_warn_delta = TS_WARN_DELTA_DEFAULT;

  if (general_config.ts_max_delta < TS_MAX_DELTA_MIN)
    general_config.ts_max_delta = TS_MAX_DELTA_DEFAULT;

  if (general_config.servlink_path == NULL)
    DupString(general_config.servlink_path, SLPATH);

  if ((general_config.client_flood < CLIENT_FLOOD_MIN) ||
      (general_config.client_flood > CLIENT_FLOOD_MAX))
    general_config.client_flood = CLIENT_FLOOD_MAX;

  general_config.max_watch = IRCD_MAX(general_config.max_watch, WATCHSIZE_MIN);
}

void
general_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  memset(&general_config, 0, sizeof(general_config));

  section_process(jobj, (char*)&general_config, general_section_entries);
}
