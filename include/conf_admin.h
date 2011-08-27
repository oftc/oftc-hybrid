#ifndef CONF_ADMIN_H
#define CONF_ADMIN_H

struct conf_admin
{
  char *description;
  char *email;
  char *name;
};

extern struct conf_admin admin_config;

void admin_section_process(void *);

#define ADMIN_SECTION_ENTRY(name, type) #name, type, offsetof(struct conf_admin, name), ssizeof(struct conf_admin, name)

#endif
