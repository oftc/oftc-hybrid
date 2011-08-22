#include "stdinc.h"
#include "s_log.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "config.h"
#include "ircd_defs.h"
#include "conf_general.h"
#include "conf_serverinfo.h"
#include "memory.h"

struct config_section config_sections[] = {
  { "serverinfo", serverinfo_section_process },
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
section_process(void *obj, char *ptr, struct config_section_entry *entry_list)
{
  json_object_object_foreach(obj, key, value)
  {
    struct config_section_entry *entry;
    json_type obj_type = json_object_get_type(value);

    entry = find_section_entry(entry_list, key);

    if(entry == NULL)
    {
      ilog(L_WARN, "Unexpected entry %s", key);
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

        memcpy(ptr + entry->offset, &intval, entry->length);
        break;
      }
      case json_type_boolean:
      {
        int boolval = json_object_get_boolean(value);

        memcpy(ptr + entry->offset, &boolval, entry->length);
        break;
      }
      case json_type_string:
      {
        char *strval;
        char *addr;

        strval = ptr + entry->offset;
        addr = (char*)(*(int*)strval);
        
        MyFree(addr);
      
        DupString(strval, json_object_get_string(value));
        memcpy(ptr + entry->offset, &strval, entry->length);
        break;
      }
      default:
        ilog(L_DEBUG, "type %d as yet not handled field name is %s", obj_type,
            key);
        break;
    }
  }
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
