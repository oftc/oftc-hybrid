/*
 * iauth/res.h (C)opyright 1992 Darren Reed.
 *
 * $Id$
 */

#ifndef INCLUDED_res_h
#define INCLUDED_res_h

#ifndef INCLUDED_sys_types_h
#include <sys/types.h>       /* time_t */
#define INCLUDED_sys_types_h
#endif

struct Client;
struct hostent;

struct DNSReply {
  struct hostent* hp;        /* hostent struct  */
  int             ref_count; /* reference count */
};

struct DNSQuery {
  void* vptr;               /* pointer used by callback to identify request */
  void (*callback)(void* vptr, struct DNSReply* reply); /* callback to call */
};

extern int ResolverFileDescriptor;  /* GLOBAL - file descriptor (s_bsd.c) */

extern void get_res(void);
extern struct DNSReply* gethost_byname(const char* name, 
                                       const struct DNSQuery* req);
extern struct DNSReply* gethost_byaddr(const char* name, 
                                       const struct DNSQuery* req);
extern int             init_resolver(void);
extern void            restart_resolver(void);
extern time_t          timeout_resolver(time_t now);
extern void            delete_resolver_queries(const void* vptr);
extern unsigned long   cres_mem(struct Client* cptr);

/*
 * add_local_domain - append local domain suffix to hostnames that 
 * don't contain a dot '.'
 * name - string to append to
 * len  - total length of the buffer
 * name is modified only if there is enough space in the buffer to hold
 * the suffix
 */
extern void add_local_domain(char* name, int len);

#endif /* INCLUDED_res_h */

