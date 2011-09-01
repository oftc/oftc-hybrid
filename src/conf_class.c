#include "stdinc.h"
#include "config.h"
#include "tools.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "s_log.h"
#include "irc_string.h"
#include "memory.h"
#include "hook.h"
#include "client.h"
#include "send.h"
#include "numeric.h"
#include "conf_class.h"

struct config_section_entry class_section_entries[] = {
  { CLASS_SECTION_ENTRY(cidr_bitlen_ipv4, json_type_int) }, 
  { CLASS_SECTION_ENTRY(cidr_bitlen_ipv6, json_type_int) }, 
  { CLASS_SECTION_ENTRY(connect_freq, json_type_int) }, 
  { CLASS_SECTION_ENTRY(max_number, json_type_int) }, 
  { CLASS_SECTION_ENTRY(max_local, json_type_int) }, 
  { CLASS_SECTION_ENTRY(max_global, json_type_int) }, 
  { CLASS_SECTION_ENTRY(max_ident, json_type_int) }, 
  { CLASS_SECTION_ENTRY(number_per_ip, json_type_int) }, 
  { CLASS_SECTION_ENTRY(name, json_type_string) },
  { CLASS_SECTION_ENTRY(number_per_cidr, json_type_int) }, 
  { CLASS_SECTION_ENTRY(ping_time, json_type_int) }, 
  { CLASS_SECTION_ENTRY(ping_warning, json_type_int) }, 
  { CLASS_SECTION_ENTRY(reject_message, json_type_string) }, 
  { CLASS_SECTION_ENTRY(sendq, json_type_int) }, 
  { CONF_ENTRY_END },
};

dlink_list class_list = { 0 };
struct conf_class *class_default;
struct Callback *client_check_cb = NULL;

static void *
check_client(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  const char *username = va_arg(args, const char *);

  return source_p;
}

struct conf_class *
class_new()
{
  struct conf_class *new_class;

  new_class = MyMalloc(sizeof(struct conf_class));

  dlinkAdd(new_class, &new_class->node, &class_list);

  new_class->active = 1;
  new_class->connect_freq  = DEFAULT_CONNECTFREQUENCY;
  new_class->ping_time = DEFAULT_PINGFREQUENCY;
  new_class->max_number = MAXIMUM_LINKS_DEFAULT;
  new_class->sendq = DEFAULT_SENDQ;

  return new_class;
}

void
init_class()
{
  class_default = class_new();

  DupString(class_default->name, "default");
  client_check_cb = register_callback("check_client", check_client);
}

void
class_section_clearout()
{
  dlink_node *ptr;
  struct conf_class *cltmp;

  DLINK_FOREACH(ptr, class_list.head)
  {
    cltmp = (struct conf_class *)ptr->data;

    if (ptr != class_list.tail)  /* never mark the "default" class */
      cltmp->active = 0;
  }
}

void
class_section_set_defaults()
{
}

void
class_section_validate()
{
}

static void
process_class(struct conf_class *cptr)
{
  struct conf_class *class_ptr;

  class_ptr = class_find_by_name(cptr->name);
  if(class_ptr == NULL)
  {
    class_ptr = cptr;
  }
  else
  {
    class_ptr->active = 1;
    if(class_ptr->reject_message == NULL)
      DupString(class_ptr->reject_message, DEFAULT_CLASS_REJECT_MESSAGE);
  }
}

void
class_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;
  json_type root_type = json_object_get_type(jobj);
  int i;
  
  if(root_type != json_type_array)
  {
    ilog(L_ERROR, "class config section has incorrect root type");
    return;
  }
  
  for(i = 0; i < json_object_array_length(jobj); i++)
  {
    struct conf_class *new_class; 

    json_object *curr = json_object_array_get_idx(jobj, i);

    new_class = class_new();

    section_process(curr, (char*)new_class, class_section_entries);

    process_class(new_class);
  }
}

static void
destroy_cidr_list(dlink_list *list)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
  {
    dlinkDelete(ptr, list);
    MyFree(ptr->data);
  }
}

static void
destroy_cidr_class(struct conf_class *aclass)
{
  destroy_cidr_list(&aclass->list_ipv4);
  destroy_cidr_list(&aclass->list_ipv6);
}

void
check_class(void)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, class_list.head)
  {
    struct conf_class *aclass = (struct conf_class *)ptr->data;

    if (!aclass->active && !aclass->curr_user_count)
    {
      destroy_cidr_class(aclass);
      delete_conf_item(ptr->data);
    }
  }
}

struct conf_class *
class_find_by_name(const char *name)
{
  struct conf_class *cptr;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, class_list.head)
  {
    cptr = ptr->data;
    if (EmptyString(cptr->name))
      continue;

    if (strcmp(cptr->name, name) == 0)
      return (cptr);
  }

  return class_default; 
}

void
class_delete(struct conf_class *cptr)
{

}

void
class_report_items(struct Client *source_p)
{
  dlink_node *ptr;
  struct conf_class *class_item;

  DLINK_FOREACH(ptr, class_list.head)
  {
    class_item = (struct conf_class *)ptr->data;
    sendto_one(source_p, form_str(RPL_STATSYLINE), me.name, source_p->name, 
        'Y', class_item->name, class_item->ping_time, class_item->connect_freq,
        class_item->max_number, class_item->sendq, class_item->curr_user_count,
        class_item->active ? "active" : "disabled");
  }
}
