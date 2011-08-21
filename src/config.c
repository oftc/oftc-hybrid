#include "stdinc.h"
#include "s_log.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "config.h"
#include "conf_general.h"

struct config_section config_sections[] = {
  { "general", general_section_process },
  { "", NULL }
};
  
struct config_section *
find_section(const char *name)
{
  struct config_section *section;

  section = config_sections;

  while(*section->name != '\0')
  {
    if(strncmp(section->name, name, sizeof(section->name)) == 0)
      return section;
    section++;
  }

  return NULL;
}

struct config_section_entry *
find_section_entry(struct config_section_entry *list, const char *name)
{
  struct config_section_entry *entry;

  entry = list;

  while(*entry->name != '\0')
  {
    if(strncmp(entry->name, name, sizeof(entry->name)) == 0)
      return entry;
    entry++;
  }

  return NULL;
}

void
init_config()
{
  json_object *config_object;
  json_type conftype;

  MC_SET_DEBUG(1);

  config_object = json_object_from_file(CCPATH);
  if(config_object == NULL)
  {
    ilog(L_CRIT, "Failed to parse json config file.  json-c sucks too much to tell us why");
    return;
  }

  conftype = json_object_get_type(config_object);
  if(conftype != json_type_object)
  {
    ilog(L_CRIT, "JSON Config did not start with an object, cannot parse");
    return;
  }

  json_object_object_foreach(config_object, key, value)
  {
    struct config_section *section;

    section = find_section(key);

    if(section == NULL)
    {
      ilog(L_CRIT, "Config section %s was unexpected", key);
      return;
    }

    (section->conf_section_process)(value);
  }
}
