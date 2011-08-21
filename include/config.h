#define MAX_CONF_SECTION_NAME 64
#define MAX_CONF_SECTION_ENTRY_NAME 128

#define ssizeof(t, m) sizeof(((t *)0)->m)

#define SECTION_ENTRY(name, type) #name, type, offsetof(struct conf_general, name), ssizeof(struct conf_general, name)

typedef void CSP(void *);

struct config_section
{
  char name[MAX_CONF_SECTION_NAME];
  CSP *conf_section_process;
};

struct config_section_entry
{
  char name[MAX_CONF_SECTION_ENTRY_NAME];
  int type;
  int offset;
  int length;
};

void init_config();
struct config_section_entry *find_section_entry(struct config_section_entry *, const char *);
