#include "stdinc.h"
#include "config.h"
#include "conf_channel.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "s_user.h"
#include "sprintf_irc.h"
#include "ircd_defs.h"
#include "common.h"

struct config_section_entry channel_section_entries[] = {
  { CHANNEL_SECTION_ENTRY(burst_topicwho, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(disable_fake_channels, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(disable_local_channels, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(default_split_server_count, json_type_int) }, 
  { CHANNEL_SECTION_ENTRY(default_split_user_count, json_type_int) }, 
  { CHANNEL_SECTION_ENTRY(knock_delay, json_type_int) }, 
  { CHANNEL_SECTION_ENTRY(knock_delay_channel, json_type_int) }, 
  { CHANNEL_SECTION_ENTRY(max_bans, json_type_int) }, 
  { CHANNEL_SECTION_ENTRY(max_chans_per_user, json_type_int) }, 
  { CHANNEL_SECTION_ENTRY(no_create_on_split, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(no_join_on_split, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(quiet_on_ban, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(restrict_channels, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(use_except, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(use_invex, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(use_knock, json_type_boolean) }, 
  { CHANNEL_SECTION_ENTRY(use_quiet, json_type_boolean) }, 
  { "", 0, 0, 0 }
};

struct conf_channel channel_config;

void
channel_section_clearout()
{
  delete_isupport("INVEX");
  delete_isupport("EXCEPTS");
}

void
channel_section_set_defaults()
{
  channel_config.disable_fake_channels = NO;
  channel_config.restrict_channels = NO;
  channel_config.disable_local_channels = NO;
  channel_config.use_invex = YES;
  channel_config.use_except = YES;
  channel_config.use_knock = YES;
  channel_config.knock_delay = 300;
  channel_config.knock_delay_channel = 60;
  channel_config.max_chans_per_user = 15;
  channel_config.quiet_on_ban = YES;
  channel_config.max_bans = 25;
  channel_config.default_split_user_count = 0;
  channel_config.default_split_server_count = 0;
  channel_config.no_join_on_split = NO;
  channel_config.no_create_on_split = NO;
  channel_config.burst_topicwho = YES;
}

void
channel_section_validate()
{
  char chanmodes[32];
  char chanlimit[32];

  ircsprintf(chanmodes, "b%s%s:%d", channel_config.use_except ? "e" : "",
             channel_config.use_invex ? "I" : "", channel_config.max_bans);
  add_isupport("MAXLIST", chanmodes, -1);
  if (channel_config.disable_local_channels)
    add_isupport("CHANTYPES", "#", -1);
  else
    add_isupport("CHANTYPES", "#&", -1);
  ircsprintf(chanlimit, "%s:%d", channel_config.disable_local_channels ? "#" : "#&",
       channel_config.max_chans_per_user);
  add_isupport("CHANLIMIT", chanlimit, -1);
  ircsprintf(chanmodes, "%s%s%s%s", channel_config.use_except ? "e" : "",
       channel_config.use_invex ? "I" : "", channel_config.use_quiet ? "q" : "",
       "b,k,l,imnpstMRS");
  add_isupport("CHANNELLEN", NULL, LOCAL_CHANNELLEN);
  if (channel_config.use_except)
    add_isupport("EXCEPTS", "e", -1);
  if (channel_config.use_invex)
    add_isupport("INVEX", "I", -1);
  add_isupport("CHANMODES", chanmodes, -1);
}

void
channel_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  memset(&channel_config, 0, sizeof(channel_config));

  section_process(jobj, (char*)&channel_config, channel_section_entries);
}
