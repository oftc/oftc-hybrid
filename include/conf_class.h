#ifndef CONF_CLASS_H
#define CONF_CLASS_H

extern struct Callback *client_check_cb;

void class_section_process(void *);
void class_section_clearout();
void class_section_validate();
void class_section_set_defaults();

void init_class();
dlink_list *class_get_list();
int class_get_count();
struct conf_class *class_find_by_name(const char *);
void class_report_items(struct Client *);

struct conf_class
{
  int cidr_bitlen_ipv4;
  int cidr_bitlen_ipv6;
  int connect_freq;
  int max_number;
  int max_local;
  int max_global;
  int max_ident;
  int number_per_ip;
  char *name;
  int number_per_cidr;
  int ping_time;
  int ping_warning;
  char *reject_message;
  int sendq;

  int active;
  int curr_user_count;
  dlink_list list_ipv4;         /* base of per cidr ipv4 client link list */
  dlink_list list_ipv6;         /* base of per cidr ipv6 client link list */
  dlink_node node;
};

#define CLASS_SECTION_ENTRY(name, type) #name, type, offsetof(struct conf_class, name), ssizeof(struct conf_class, name)

#define DEFAULT_CLASS_REJECT_MESSAGE "No more connections permitted from your host"

#endif
