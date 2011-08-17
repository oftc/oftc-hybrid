/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  event.c: Event functions.
 *
 */

#include "stdinc.h"
#include "common.h"
#include "ircd.h"
#include "levent.h"
#include "s_bsd.h"
#include "s_log.h"
#include "restart.h"

#include <event2/event.h>

struct event_base *eventbase;

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

  ilog(L_DEBUG, "data on %d (%d)", fd, what);

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

  if(type & COMM_SELECT_READ)
  {
    what |= EV_READ;
    F->read_handler = handler;
    F->read_data = data;
  }

  if(type & COMM_SELECT_WRITE)
  {
    what |= EV_WRITE;
    F->write_handler = handler;
    F->write_data = data;
  }

  if(timeout != 0)
  {
    F->timeout = CurrentTime + (timeout / 1000);
    F->timeout_handler = handler;
    F->timeout_data = data;
  }
  
  ilog(L_DEBUG, "adding %d %d %p", F->fd, what, F->evptr);

  if(F->evptr == NULL)
    F->evptr = event_new(eventbase, F->fd, what, levent_event_callback, F);

  event_add(F->evptr, NULL);
}

void
levent_loop()
{
  int ret;

  ret = event_base_loop(eventbase, EVLOOP_NONBLOCK);

  if(ret == 1)
    usleep(10000);

  if(ret == -1)
    server_die("event loop problem", YES);
}

void
levent_init()
{
  event_set_log_callback(levent_log_cb);
  event_set_fatal_callback(levent_fatal_callback);
  event_set_mem_functions(MyMalloc, MyRealloc, MyFree);

  eventbase = event_base_new();

  if(eventbase == NULL)
    server_die("event init failed", YES);
}
