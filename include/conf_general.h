#ifndef CONF_GENERAL_H
#define CONF_GENERAL_H

struct conf_general
{
  int anti_nick_flood;
  int anti_spam_exit_message_time;
  int burst_away;
  int caller_id_wait;
  int client_flood;
  int compression_level;
  char *default_cipher_preference;
  int default_floodcount;
  int disable_auth;
  int disable_remote_commands;
  int dot_in_ip6_addr;
  int dots_in_ident;
  char *egdpool_path;
  int failed_oper_notice;
  int godmode_timeout; 
  int havent_read_conf;
  int hide_spoof_ips;
  int idletime;
  int ignore_bogus_ts;
  int invisible_on_connect;
  int kline_min_cidr;
  int kline_min_cidr6;
  int kill_chase_time_limit;
  char *kline_reason;
  int kline_with_reason;
  int max_accept;
  int max_nick_changes;
  int max_nick_time;
  int max_targets;
  int max_watch;
  char *message_locale;
  int min_nonwildcard;
  int min_nonwildcard_simple;
  int no_oper_flood;
  char *oper_only_umodes;
  int oper_pass_resv;
  char *oper_umodes;
  int opers_bypass_callerid;
  int pace_wait;
  int pace_wait_simple;
  int ping_cookie;
  int reject_hold_time;
  char *servlink_path;
  int short_motd;
  int stats_e_disabled;
  int stats_i_oper_only;
  int stats_k_oper_only;
  int stats_o_oper_only;
  int stats_P_oper_only;
  int tkline_expire_notices;
  int throttle_time;
  int true_no_oper_flood;
  int ts_max_delta;
  int ts_warn_delta;
  int use_egd;
  int use_whois_actually;
  int warn_no_nline;
};

void general_section_process(void *);

#endif
