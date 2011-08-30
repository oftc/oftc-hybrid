#include "stdinc.h"
#include "config.h"
#include "conf_modules.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "s_log.h"
#include "modules.h"

void
modules_section_clearout()
{
}

void
modules_section_set_defaults()
{
}

void
modules_section_validate()
{
}

void
modules_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;
  json_type root_type = json_object_get_type(jobj);
  int i;
  
  if(root_type != json_type_object)
  {
    ilog(L_ERROR, "modules config section has incorrect root type");
    return;
  }

  json_object_object_foreach(jobj, key, value)
  {
    json_type obj_type = json_object_get_type(value);
    int array_type = 0;

    if(obj_type != json_type_array)
    {
      ilog(L_WARN, "modules config, unexpected type %d, ignoring", obj_type);
      continue;
    }

    if(strcmp(key, "path") == 0)
      array_type = 1;
    else if(strcmp(key, "module") == 0)
      array_type = 2;
    else
    {
      ilog(L_ERROR, "modules config, unexpected key %s, ignoring", key);
      continue;
    }

    for(i = 0; i < json_object_array_length(value); i++)
    {
      json_object *curr = json_object_array_get_idx(value, i);

      if(json_object_get_type(curr) != json_type_string)
      {
        ilog(L_WARN, "modules config, %s list, unexpected type, ignoring", key);
        continue;
      }

      if(array_type == 1)
      {
        mod_add_path(json_object_get_string(curr));
      }
      else if(array_type == 2)
      {
        add_conf_module(json_object_get_string(curr));
      }
    }
  }
}
