#define MAX_CONF_SECTION_NAME 64
#define MAX_CONF_SECTION_ENTRY_NAME 128

#define ssizeof(t, m) sizeof(((t *)0)->m)

#define CONF_SECTION(name) #name, name##_section_process, name##_section_clearout, name##_section_validate, name##_section_set_defaults
#define CONF_SECTION_END "", NULL, NULL, NULL, NULL
#define CONF_ENTRY_END "", 0, 0, 0

typedef void CSP(void *);
typedef void CCB(void);

struct config_section
{
  char name[MAX_CONF_SECTION_NAME];
  CSP *conf_section_process;
  CCB *conf_section_clearout;
  CCB *conf_section_validate;
  CCB *conf_section_set_defaults;
};

struct config_section_entry
{
  char name[MAX_CONF_SECTION_ENTRY_NAME];
  int type;
  int offset;
  int length;
};

void init_config(int);
struct config_section_entry *find_section_entry(struct config_section_entry *, const char *);
void section_process(void *, char *, struct config_section_entry *);
