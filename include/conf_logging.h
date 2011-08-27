#ifndef CONF_LOGGING_H
#define CONF_LOGGING_H

struct conf_logging
{
  char *failed_operlog;
  char *ioerrlog;
  char *killlog;
  char *klinelog;
  int log_level;
  char *operlog;
  char *operspylog;
  int use_logging;
  char *userlog;
};

extern struct conf_logging logging_config;

void logging_section_process(void *);

#define LOGGING_SECTION_ENTRY(name, type) #name, type, offsetof(struct conf_logging, name), ssizeof(struct conf_logging, name)

#endif
