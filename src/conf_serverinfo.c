#include "stdinc.h"
#include "config.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "ircd_defs.h"
#include "conf_serverinfo.h"

struct config_section_entry serverinfo_section_entries[] = {
  { SERVERINFO_SECTION_ENTRY(description, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(hub, json_type_boolean ) },
  { SERVERINFO_SECTION_ENTRY(max_clients, json_type_int ) },
  { SERVERINFO_SECTION_ENTRY(name, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(network_desc, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(network_name, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(rsa_private_key_file, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(sid, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(ssl_certificate_file, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(vhost, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(vhost6, json_type_string ) },
  { "", 0, 0, 0 }
};

struct conf_serverinfo serverinfo_config;

void
validate_serverinfo_section()
{
}

void
serverinfo_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  memset(&serverinfo_config, 0, sizeof(serverinfo_config));

  section_process(jobj, (char*)&serverinfo_config, serverinfo_section_entries);

  validate_serverinfo_section();
}
