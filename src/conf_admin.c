#include "stdinc.h"
#include "config.h"
#include "conf_admin.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__

struct config_section_entry admin_section_entries[] = {
  { ADMIN_SECTION_ENTRY(description, json_type_string) }, 
  { ADMIN_SECTION_ENTRY(email, json_type_string) }, 
  { ADMIN_SECTION_ENTRY(name, json_type_string) }, 
  { "", 0, 0, 0 }
};

struct conf_admin admin_config;

void
admin_section_clearout()
{
  MyFree(admin_config.name);
  admin_config.name = NULL;
  MyFree(admin_config.email);
  admin_config.email = NULL;
  MyFree(admin_config.description);
  admin_config.description = NULL;
}

void
admin_section_set_defaults()
{
}

void
admin_section_validate()
{
}

void
admin_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  memset(&admin_config, 0, sizeof(admin_config));

  section_process(jobj, (char*)&admin_config, admin_section_entries);
}
