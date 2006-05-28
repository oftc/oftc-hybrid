/*
 * include/irc_res.h for referencing functions in src/irc_res.c
 *
 * $Id$
 */

#ifndef INCLUDED_irc_res_h
#define INCLUDED_irc_res_h

#include "fdlist.h"

struct Client;

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

#endif
