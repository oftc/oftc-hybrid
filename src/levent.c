/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  event.c: Event functions.
 *
 */

#include "stdinc.h"
#include "common.h"
#include "ircd.h"
#include "client.h"
#include "levent.h"
#include "s_bsd.h"
#include "s_log.h"
#include "restart.h"

#include <event2/event.h>
#include <event2/dns.h>

#undef EVENT_DEBUGGING 

struct event_base *eventbase;
struct evdns_base *dnsbase;

static void 
levent_log_cb(int severity, const char *msg)
{
  int log_level;

  switch(severity)
  {
    case _EVENT_LOG_DEBUG:
      log_level = L_DEBUG;
      break;
    case _EVENT_LOG_MSG:
      log_level = L_INFO;
      break;
    case _EVENT_LOG_WARN:
      log_level = L_WARN;
      break;
    case _EVENT_LOG_ERR:
      log_level = L_ERROR;
      break;
    default:
      log_level = L_INFO;
      break;
  }

  ilog(log_level, "%s", msg);
}

static void
levent_fatal_callback(int err)
{
  server_die("Fatal error from libevent", YES);
}

static void
levent_event_callback(int fd, short what, void *data)
{
  fde_t *F = (fde_t *)data;
  PF *handler;
  struct event *ev = F->evptr;

#ifdef EVENT_DEBUGGING
  ilog(L_DEBUG, "data on %d (%d)", fd, what);
#endif

  if(F == NULL || !F->flags.open || ev == NULL)
    return;

  if(what & EV_READ)
  {
    if((handler = F->read_handler) != NULL)
    {
      F->read_handler = NULL;
      handler(F, F->read_data);
      if(!F->flags.open)
        return;
    }
  }

  if(what & EV_WRITE)
  {
    if((handler = F->write_handler) != NULL)
    {
      F->write_handler = NULL;
      handler(F, F->write_data);
      if(!F->flags.open)
        return;
    }
  }
}

void
levent_add(fde_t *F, unsigned int type, PF *handler, void *data, time_t timeout)
{
  short what = 0;
  int op;

#ifdef EVENT_DEBUGGING
  ilog(L_DEBUG, "fd %d type %d handler %p data %p timeout %d", F->fd,
      type, handler, data, timeout);
#endif

  if(type & COMM_SELECT_READ)
  {
    F->read_handler = handler;
    F->read_data = data;
  }

  if(type & COMM_SELECT_WRITE)
  {
    F->write_handler = handler;
    F->write_data = data;
  }

  if(timeout != 0)
  {
    F->timeout = CurrentTime + (timeout / 1000);
    F->timeout_handler = handler;
    F->timeout_data = data;
  }

  if(F->read_handler != NULL)
  {
#ifdef EVENT_DEBUGGING
    ilog(L_DEBUG, "Marking for read");
#endif
    what |= EV_READ;
  }
  if(F->write_handler != NULL)
  {
#ifdef EVENT_DEBUGGING
    ilog(L_DEBUG, "Marking for write");
#endif
    what |= EV_WRITE;
  }

  if(what != F->evcache)
  {
    if(what == 0)
    {
#ifdef EVENT_DEBUGGING
      ilog(L_DEBUG, "Deleteing");
#endif
      op = 0; // del
    }
    else if(F->evcache == 0)
    {
#ifdef EVENT_DEBUGGING
      ilog(L_DEBUG, "Adding");
#endif
      op = 1; // add
    }
    else
    {
#ifdef EVENT_DEBUGGING
      ilog(L_DEBUG, "Modifying");
#endif
      op = 2; // modify
    }

    F->evcache = what;

    switch(op)
    {
      case 0:
        if(F->evptr == NULL)
          return;
        event_del(F->evptr);
        F->evptr = NULL;
        break;
      case 1:
      case 2:
        if(F->evptr != NULL)
          event_del(F->evptr);

        F->evptr = event_new(eventbase, F->fd, what, levent_event_callback, F);
        event_add(F->evptr, NULL);
        break;
    }
  }
  else
  {
#ifdef EVENT_DEBUGGING
    ilog(L_DEBUG, "evcache == what, no change %d", F->evcache);
#endif
    if(F->evptr != NULL)
      event_add(F->evptr, NULL);
  }
}

static void
levent_timer_callback(int fd, short what, void *data)
{
  struct ev_entry *entry = (struct ev_entry *)data;
  if(entry != NULL)
  {
    last_event_ran = entry->name;
    entry->func(entry->arg);
    entry->when = CurrentTime + entry->frequency;
  }
}

void
levent_timer_add(struct ev_entry *entry)
{
  if(entry->evptr != NULL)
    levent_timer_del(entry);

  struct timeval tv = { entry->frequency, 0 };
  entry->evptr = levent_timer_add_generic(&tv, levent_timer_callback, entry);
}

void
levent_timer_del(struct ev_entry *entry)
{
  if (entry->evptr != NULL)
  {
    event_del(entry->evptr);
    entry->evptr = NULL;
  }
}

void *
levent_timer_add_generic(const struct timeval *tv, void (*cb)(int, short, void*), void *arg)
{
  struct event *evptr = event_new(eventbase, -1, EV_PERSIST, cb, arg);
  event_add(evptr, tv);
  return evptr;
}

void
levent_timer_del_generic(void *evptr)
{
  if(evptr != NULL)
    event_del(evptr);
}

static void
levent_dns_callback(int result, char type, int count, int ttl, void *addresses, void *arg)
{
  struct DNSQuery *query = (struct DNSQuery *)arg;
  struct DNSReply *reply = (struct DNSReply *)query->dnsptr;
  char tmp[256];

  if(result != DNS_ERR_NONE)
  {
    if(result == DNS_ERR_NOTEXIST && query->aftype == AF_INET6 && reply->h_name != NULL)
    {
      ilog(L_DEBUG, "%s not found ipv6, trying v4", reply->h_name);
      gethost_byname_type(reply->h_name, query, AF_INET);
      return;
    }
    ilog(L_DEBUG, "DNS Error %d", result);
    (*query->callback)(query->ptr, NULL);
    MyFree(reply);
    return;
  }

  if(type == DNS_PTR)
  {
    if(reply->h_name != NULL)
      MyFree(reply->h_name);
    DupString(reply->h_name, ((char **)addresses)[0]);

    ilog(L_DEBUG, "PTR answer %s", reply->h_name);

    gethost_byname(reply->h_name, query);

    return;
  }
  else if(type == DNS_IPv4_A)
  {
    struct in_addr *v4 = addresses;
    struct sockaddr_in *v4addr = (struct sockaddr_in *)&reply->addr;

    reply->addr.ss_len = sizeof(struct sockaddr_in);
    v4addr->sin_family = AF_INET;

    memcpy(&v4addr->sin_addr, &v4[0], sizeof(struct in_addr));

    evutil_inet_ntop(AF_INET, &v4addr->sin_addr, tmp, 256);

    ilog(L_DEBUG, "A Answer %s", tmp);

    (*query->callback)(query->ptr, reply);
    MyFree(reply);
  }
  else if(type == DNS_IPv6_AAAA)
  {
    struct in6_addr *v6 = addresses;
    struct sockaddr_in6 *v6addr = (struct sockaddr_in6 *)&reply->addr;

    reply->addr.ss_len = sizeof(struct sockaddr_in6);
    v6addr->sin6_family = AF_INET6;

    memcpy(&v6addr->sin6_addr, &v6[0], sizeof(struct in6_addr));

    evutil_inet_ntop(AF_INET6, &v6addr->sin6_addr, tmp, 256);

    ilog(L_DEBUG, "AAAA Answer %s", tmp);

    (*query->callback)(query->ptr, reply);
    MyFree(reply);
  }
}

void 
gethost_byaddr(const struct irc_ssaddr *addr, struct DNSQuery *query)
{
  char tmp[256];

  if(query->dnsptr == NULL)
  {
    struct DNSReply *reply = MyMalloc(sizeof(struct DNSReply)); 
    query->dnsptr = reply;

    memcpy(&reply->addr, addr, sizeof(reply->addr));
  }

  if(addr->ss.ss_family == AF_INET)
  {
    struct sockaddr_in *v4 = (struct sockaddr_in *)addr;

    query->aftype = AF_INET;

    evutil_inet_ntop(AF_INET, &v4->sin_addr, tmp, 256);

    evdns_base_resolve_reverse(dnsbase, &v4->sin_addr, 0,
        levent_dns_callback, query);
  }
  else if(addr->ss.ss_family == AF_INET6)
  {
    struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)addr;

    query->aftype = AF_INET6;

    evutil_inet_ntop(AF_INET6, v6, tmp, 256);

    evdns_base_resolve_reverse_ipv6(dnsbase, &v6->sin6_addr, 0,
        levent_dns_callback, query);
  }

  ilog(L_DEBUG, "Looking up IP to host %s", tmp);
}

void 
gethost_byname(const char *name, struct DNSQuery *query)
{
  gethost_byname_type(name, query, AF_INET6);
}

void 
gethost_byname_type(const char *name, struct DNSQuery *query, int aftype)
{
  ilog(L_DEBUG, "Looking up host to ip aftype %d %s", aftype, name);
  if(query->dnsptr == NULL)
  {
    struct DNSReply *reply = MyMalloc(sizeof(struct DNSReply)); 
    query->dnsptr = reply;

    DupString(reply->h_name, name);
  }

  query->aftype = aftype;

  if(aftype == AF_INET)
  {
    evdns_base_resolve_ipv4(dnsbase, name, 0, levent_dns_callback, query);
  }
  else if(aftype == AF_INET6)
  {
    evdns_base_resolve_ipv6(dnsbase, name, 0, levent_dns_callback, query);
  }
}

void
levent_loop()
{
  event_base_dispatch(eventbase);
  server_die("event loop problem", YES);
}

void restart_resolver()
{
  evdns_base_free(dnsbase, YES);
  dnsbase = evdns_base_new(eventbase, YES);
}

void
levent_init()
{
  event_set_log_callback(levent_log_cb);
  event_set_fatal_callback(levent_fatal_callback);
  event_set_mem_functions(MyMalloc, MyRealloc, MyFree);

  event_enable_debug_mode();

  eventbase = event_base_new();
  dnsbase = evdns_base_new(eventbase, YES);

  if(eventbase == NULL)
    server_die("event init failed", YES);
}
