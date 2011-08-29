#ifndef CONF_SERVERHIDE_H
#define CONF_SERVERHIDE_H

struct conf_serverhide
{
  int disable_hidden;
  int flatten_links;
  int hidden;
  char *hidden_name;
  int hide_server_ips;
  int hide_servers;
  int links_delay;
  int links_disabled;
};

extern struct conf_serverhide serverhide_config;

void serverhide_section_process(void *);
void serverhide_section_clearout();
void serverhide_section_set_defaults();
void serverhide_section_validate();

#define SERVERHIDE_SECTION_ENTRY(name, type) #name, type, offsetof(struct conf_serverhide, name), ssizeof(struct conf_serverhide, name)

#endif
