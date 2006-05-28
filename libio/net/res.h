/*
 * res.h for referencing functions in libio/net/res.c
 *
 * $Id$
 */

/* Maximum number of nameservers in /etc/resolv.conf we care about */
#define IRCD_MAXNS 2

struct DNSReply
{
  char *h_name;
  struct irc_ssaddr addr;
};

struct DNSQuery
{
#ifdef _WIN32
  dlink_node node;
  HANDLE handle;
  char reply[MAXGETHOSTSTRUCT];
#endif
  void *ptr; /* pointer used by callback to identify request */
  void (*callback)(void* vptr, struct DNSReply *reply); /* callback to call */
};

extern struct irc_ssaddr irc_nsaddr_list[];
extern int irc_nscount;

extern void init_resolver(void);
extern void restart_resolver(void);
extern void delete_resolver_queries(const struct DNSQuery *);
extern void gethost_byname_type(const char *, struct DNSQuery *, int);
extern void gethost_byname(const char *, struct DNSQuery *);
extern void gethost_byaddr(const struct irc_ssaddr *, struct DNSQuery *);
extern void add_local_domain(char *, size_t);
