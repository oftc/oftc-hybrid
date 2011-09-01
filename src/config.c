#include "stdinc.h"
#include "s_log.h"
#include "memory.h"
#include "s_user.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "config.h"
#include "ircd_defs.h"
#include "conf_general.h"
#include "conf_serverinfo.h"
#include "conf_admin.h"
#include "conf_logging.h"
#include "conf_channel.h"
#include "conf_serverhide.h"
#include "conf_modules.h"
#include "conf_listen.h"
#include "conf_class.h"

struct config_section config_sections[] = {
  { CONF_SECTION(serverinfo) },
  { CONF_SECTION(general) },
  { CONF_SECTION(admin) },
  { CONF_SECTION(logging) },
  { CONF_SECTION(channel) },
  { CONF_SECTION(serverhide) },
  { CONF_SECTION(modules) },
  { CONF_SECTION(listen) },
  { CONF_SECTION(class) },
  { CONF_SECTION_END }
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
do_post_config_setup()
{
  /*
   * message_locale may have changed.  rebuild isupport since it relies
   * on strlen(form_str(RPL_ISUPPORT))
   */
  rebuild_isupport_message_line();
}

void
init_config(int cold_start)
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

    if(!cold_start)
      (section->conf_section_clearout)();

    (section->conf_section_set_defaults)();
    (section->conf_section_process)(value);
    (section->conf_section_validate)();
  }

  do_post_config_setup();
}
