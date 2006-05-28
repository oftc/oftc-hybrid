/*
 * include/irc_res.h for referencing functions in src/irc_res.c
 *
 * $Id$
 */

#ifndef INCLUDED_irc_res_h
#define INCLUDED_irc_res_h

#include "ircd_defs.h"

struct Client;

struct DNSReply
{
  char *h_name;
  int h_addrtype;
  struct irc_ssaddr addr;
};

struct DNSQuery
{
  void *ptr; /* pointer used by callback to identify request */
  void (*callback)(void* vptr, struct DNSReply *reply); /* callback to call */
};

extern int init_resolver(void);
extern void restart_resolver(void);
extern void add_local_domain(char *hname, size_t size);
extern void timeout_resolver(void *notused);
extern void delete_resolver_queries(const struct DNSQuery *query);
extern void report_dns_servers(struct Client *source_p);
extern void gethost_byname_type(const char *name, const struct DNSQuery *query, int type);
extern void gethost_byname(const char *name, const struct DNSQuery *query);
extern void gethost_byaddr(const struct irc_ssaddr *addr, const struct DNSQuery *query);
#endif
