#include "stdinc.h"
#include "config.h"
#include "conf_listen.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "s_log.h"
#include "listener.h"
#include "conf_serverinfo.h"

void
listen_section_clearout()
{
  close_listeners();
}

void
listen_section_set_defaults()
{
}

void
listen_section_validate()
{
}

void
listen_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;
  json_type root_type = json_object_get_type(jobj);
  int i;
  
  if(root_type != json_type_array)
  {
    ilog(L_ERROR, "listen config section has incorrect root type");
    return;
  }
  
  for(i = 0; i < json_object_array_length(jobj); i++)
  {
    const char *host = NULL;
    int port = -1;
    int flags = 0;

    json_object *curr = json_object_array_get_idx(jobj, i);

    json_object_object_foreach(curr, key, value)
    {
      json_type obj_type = json_object_get_type(value);

      if(strcmp(key, "host") == 0)
      {
        if(obj_type != json_type_string)
          continue;
        host = json_object_get_string(value);
      }
      else if(strcmp(key, "port") == 0)
      {
        if(obj_type != json_type_int)
          continue;
        port = json_object_get_int(value);
      }
      else if(strcmp(key, "ssl") == 0)
      {
        if(obj_type != json_type_boolean)
          continue;

        flags |= LISTENER_SSL;
      }
      else if(strcmp(key, "hidden") == 0)
      {
        if(obj_type != json_type_boolean)
          continue;

        flags |= LISTENER_HIDDEN;
      }
      else if(strcmp(key, "server") == 0)
      {
        if(obj_type != json_type_boolean)
          continue;

        flags |= LISTENER_SERVER;
      }
      else if(strcmp(key, "websocket") == 0)
      {
        if(obj_type != json_type_boolean)
          continue;

        flags |= LISTENER_WEBSOCKET;
      }
    }
    if(flags & LISTENER_SSL && serverinfo_config.ctx == NULL)
      ilog(L_WARN, "SSL listener specified but SSL not enabled, ignoring");
    else if(port == -1)
      ilog(L_WARN, "No port or invalid port specified for listener, ignoring");
    else
      add_listener(port, host, flags);
  }
}
