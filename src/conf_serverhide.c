#include "stdinc.h"
#include "config.h"
#include "conf_serverhide.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "client.h"
#include "event.h"
#include "s_serv.h"
#include "common.h"
#include "memory.h"

struct config_section_entry serverhide_section_entries[] = {
  { SERVERHIDE_SECTION_ENTRY(disable_hidden, json_type_boolean) }, 
  { SERVERHIDE_SECTION_ENTRY(flatten_links, json_type_boolean) }, 
  { SERVERHIDE_SECTION_ENTRY(hidden, json_type_boolean) }, 
  { SERVERHIDE_SECTION_ENTRY(hidden_name, json_type_string) }, 
  { SERVERHIDE_SECTION_ENTRY(hide_server_ips, json_type_boolean) }, 
  { SERVERHIDE_SECTION_ENTRY(hide_servers, json_type_boolean) }, 
  { SERVERHIDE_SECTION_ENTRY(links_delay, json_type_int) }, 
  { SERVERHIDE_SECTION_ENTRY(links_disabled, json_type_boolean) }, 
  { "", 0, 0, 0 }
};

struct conf_serverhide serverhide_config;

void
serverhide_section_clearout()
{
  MyFree(serverhide_config.hidden_name);
  serverhide_config.hidden_name = NULL;
}

void
serverhide_section_set_defaults()
{
  serverhide_config.flatten_links = NO;
  serverhide_config.links_delay = 300;
  serverhide_config.hidden = NO;
  serverhide_config.disable_hidden = NO;
  serverhide_config.hide_servers = NO;
  DupString(serverhide_config.hidden_name, NETWORK_NAME_DEFAULT);
  serverhide_config.hide_server_ips = NO;
}

void
serverhide_section_validate()
{
  if(serverhide_config.links_delay > 0)
  {
    eventAddIsh("write_links_file", write_links_file, NULL, serverhide_config.links_delay);
    serverhide_config.links_disabled = 0;
  }
}

void
serverhide_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  memset(&serverhide_config, 0, sizeof(serverhide_config));

  section_process(jobj, (char*)&serverhide_config, serverhide_section_entries);
}
