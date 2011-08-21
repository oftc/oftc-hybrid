#include "stdinc.h"
#include "config.h"
#include "conf_general.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "s_log.h"
#include "memory.h"

struct config_section_entry general_section_entries[] = {
  { SECTION_ENTRY(anti_nick_flood, json_type_boolean) }, 
  { SECTION_ENTRY(anti_spam_exit_message_time, json_type_int) }, 
  { SECTION_ENTRY(burst_away, json_type_boolean) }, 
  { SECTION_ENTRY(caller_id_wait, json_type_int) }, 
  { SECTION_ENTRY(client_flood, json_type_int) }, 
  { SECTION_ENTRY(compression_level, json_type_int) }, 
  { SECTION_ENTRY(default_cipher_preference, json_type_string) }, 
  { SECTION_ENTRY(default_floodcount, json_type_int) }, 
  { SECTION_ENTRY(disable_auth, json_type_boolean) }, 
  { SECTION_ENTRY(disable_remote_commands, json_type_boolean) }, 
  { SECTION_ENTRY(dot_in_ip6_addr, json_type_boolean) }, 
  { SECTION_ENTRY(dots_in_ident, json_type_int) }, 
  { SECTION_ENTRY(egdpool_path, json_type_string) }, 
  { SECTION_ENTRY(failed_oper_notice, json_type_boolean) }, 
  { SECTION_ENTRY(godmode_timeout, json_type_int) }, 
  { SECTION_ENTRY(havent_read_conf, json_type_boolean) }, 
  { SECTION_ENTRY(hide_spoof_ips, json_type_boolean) }, 
  { SECTION_ENTRY(idletime, json_type_int) }, 
  { SECTION_ENTRY(ignore_bogus_ts, json_type_boolean) }, 
  { SECTION_ENTRY(invisible_on_connect, json_type_boolean) }, 
  { SECTION_ENTRY(kline_min_cidr, json_type_int) }, 
  { SECTION_ENTRY(kline_min_cidr6, json_type_int) }, 
  { SECTION_ENTRY(kill_chase_time_limit, json_type_int) }, 
  { SECTION_ENTRY(kline_reason, json_type_string) }, 
  { SECTION_ENTRY(kline_with_reason, json_type_boolean) }, 
  { SECTION_ENTRY(max_accept, json_type_int) }, 
  { SECTION_ENTRY(max_nick_changes, json_type_int) }, 
  { SECTION_ENTRY(max_nick_time, json_type_int) }, 
  { SECTION_ENTRY(max_targets, json_type_int) }, 
  { SECTION_ENTRY(max_watch, json_type_int) }, 
  { SECTION_ENTRY(message_locale, json_type_string) }, 
  { SECTION_ENTRY(min_nonwildcard, json_type_int) }, 
  { SECTION_ENTRY(min_nonwildcard_simple, json_type_int) }, 
  { SECTION_ENTRY(no_oper_flood, json_type_boolean) }, 
  { SECTION_ENTRY(oper_only_umodes, json_type_string) }, 
  { SECTION_ENTRY(oper_pass_resv, json_type_boolean) }, 
  { SECTION_ENTRY(oper_umodes, json_type_string) }, 
  { SECTION_ENTRY(opers_bypass_callerid, json_type_boolean) }, 
  { SECTION_ENTRY(pace_wait, json_type_int) }, 
  { SECTION_ENTRY(pace_wait_simple, json_type_int) }, 
  { SECTION_ENTRY(ping_cookie, json_type_boolean) }, 
  { SECTION_ENTRY(reject_hold_time, json_type_int) }, 
  { SECTION_ENTRY(servlink_path, json_type_string) }, 
  { SECTION_ENTRY(short_motd, json_type_boolean) }, 
  { SECTION_ENTRY(stats_e_disabled, json_type_boolean) }, 
  { SECTION_ENTRY(stats_i_oper_only, json_type_boolean) }, 
  { SECTION_ENTRY(stats_k_oper_only, json_type_boolean) }, 
  { SECTION_ENTRY(stats_o_oper_only, json_type_boolean) }, 
  { SECTION_ENTRY(stats_P_oper_only, json_type_boolean) }, 
  { SECTION_ENTRY(tkline_expire_notices, json_type_boolean) }, 
  { SECTION_ENTRY(throttle_time, json_type_int) }, 
  { SECTION_ENTRY(true_no_oper_flood, json_type_boolean) }, 
  { SECTION_ENTRY(ts_max_delta, json_type_int) }, 
  { SECTION_ENTRY(ts_warn_delta, json_type_int) }, 
  { SECTION_ENTRY(use_egd, json_type_boolean) }, 
  { SECTION_ENTRY(use_whois_actually, json_type_boolean) }, 
  { SECTION_ENTRY(warn_no_nline, json_type_boolean) }, 
  { "", 0, 0, 0 }
};

struct conf_general general_config;

void
general_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;
  char *genptr = (char*)&general_config;

  memset(&general_config, 0, sizeof(general_config));

  json_object_object_foreach(jobj, key, value)
  {
    struct config_section_entry *entry;
    json_type obj_type = json_object_get_type(value);

    entry = find_section_entry(general_section_entries, key);

    if(entry == NULL)
    {
      ilog(L_WARN, "Unexpected entry %s in general section", key);
      continue;
    }

    if(obj_type != entry->type)
    {
      ilog(L_WARN, "type mismatch element %s expected %d got %d", key,
          obj_type, entry->type);
      continue;
    }

    switch(obj_type)
    {
      case json_type_int:
      {
        int intval = json_object_get_int(value);

        memcpy(genptr + entry->offset, &intval, entry->length);
        break;
      }
      case json_type_boolean:
      {
        int boolval = json_object_get_boolean(value);

        memcpy(genptr + entry->offset, &boolval, entry->length);
        break;
      }
      case json_type_string:
      {
        char *strval;
        
        DupString(strval, json_object_get_string(value));

        memcpy(genptr + entry->offset, &strval, entry->length);
        break;
      }
      default:
        ilog(L_DEBUG, "type %d as yet not handled field name is %s", obj_type,
            key);
        break;
    }
  }
}
