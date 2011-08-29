#include "stdinc.h"
#include "config.h"
#include "conf_logging.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "s_log.h"

struct config_section_entry logging_section_entries[] = {
  { LOGGING_SECTION_ENTRY(failed_operlog, json_type_string) }, 
  { LOGGING_SECTION_ENTRY(ioerrlog, json_type_string) }, 
  { LOGGING_SECTION_ENTRY(klinelog, json_type_string) }, 
  { LOGGING_SECTION_ENTRY(killlog, json_type_string) }, 
  { LOGGING_SECTION_ENTRY(log_level, json_type_int) }, 
  { LOGGING_SECTION_ENTRY(operlog, json_type_string) }, 
  { LOGGING_SECTION_ENTRY(operspylog, json_type_string) }, 
  { LOGGING_SECTION_ENTRY(userlog, json_type_string) }, 
  { LOGGING_SECTION_ENTRY(use_logging, json_type_boolean) }, 
  { "", 0, 0, 0 }
};

struct conf_logging logging_config = { 0 };

void
logging_section_clearout()
{
}

void
logging_section_set_defaults()
{
  set_log_level(L_NOTICE);
  logging_config.use_logging = 1;
}

void
logging_section_validate()
{
  set_log_level(logging_config.log_level);
  if(logging_config.operlog != NULL && strlen(logging_config.operlog) > PATH_MAX)
  {
    logging_config.operlog[PATH_MAX] = '\0';
    ilog(L_WARN, "operlog is too long, truncating");
  }

  if(logging_config.userlog != NULL && strlen(logging_config.userlog) > PATH_MAX)
  {
    logging_config.userlog[PATH_MAX] = '\0';
    ilog(L_WARN, "userlog is too long, truncating");
  }

  if(logging_config.ioerrlog != NULL && strlen(logging_config.ioerrlog) > PATH_MAX)
  {
    logging_config.ioerrlog[PATH_MAX] = '\0';
    ilog(L_WARN, "ioerrlog is too long, truncating");
  }

  if(logging_config.klinelog != NULL && strlen(logging_config.klinelog) > PATH_MAX)
  {
    logging_config.klinelog[PATH_MAX] = '\0';
    ilog(L_WARN, "klinelog is too long, truncating");
  }

  if(logging_config.killlog != NULL && strlen(logging_config.killlog) > PATH_MAX)
  {
    logging_config.killlog[PATH_MAX] = '\0';
    ilog(L_WARN, "killlog is too long, truncating");
  }

  if(logging_config.operspylog != NULL && strlen(logging_config.operspylog) > PATH_MAX)
  {
    logging_config.operspylog[PATH_MAX] = '\0';
    ilog(L_WARN, "operspylog is too long, truncating");
  }

  if(logging_config.failed_operlog != NULL && strlen(logging_config.failed_operlog) > PATH_MAX)
  {
    logging_config.failed_operlog[PATH_MAX] = '\0';
    ilog(L_WARN, "failed_operlog is too long, truncating");
  }
}

void
logging_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  section_process(jobj, (char*)&logging_config, logging_section_entries);
}
