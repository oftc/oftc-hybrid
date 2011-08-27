#include "stdinc.h"
#include "config.h"
#include "conf_channel.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__

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

static void
validate_channel_section()
{
}

void
channel_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  memset(&channel_config, 0, sizeof(channel_config));

  section_process(jobj, (char*)&channel_config, channel_section_entries);

  validate_channel_section();
}
