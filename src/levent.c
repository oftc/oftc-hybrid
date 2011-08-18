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

  //ilog(L_DEBUG, "data on %d (%d)", fd, what);

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

  //ilog(L_DEBUG, "fd %d type %d handler %p data %p timeout %d", F->fd,
    //  type, handler, data, timeout);

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
//    ilog(L_DEBUG, "Marking for read");
    what |= EV_READ;
  }
  if(F->write_handler != NULL)
  {
//    ilog(L_DEBUG, "Marking for write");
    what |= EV_WRITE;
  }

  if(what != F->evcache)
  {
    if(what == 0)
    {
//      ilog(L_DEBUG, "Deleteing");
      op = 0; // del
    }
    else if(F->evcache == 0)
    {
//      ilog(L_DEBUG, "Adding");
      op = 1; // add
    }
    else
    {
//      ilog(L_DEBUG, "Modifying");
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
//    ilog(L_DEBUG, "evcache == what, no change %d", F->evcache);
    if(F->evptr != NULL)
      event_add(F->evptr, NULL);
  }
}

void
levent_loop()
{
  int ret;

  ret = event_base_loop(eventbase, EVLOOP_NONBLOCK);

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

  event_enable_debug_mode();

  eventbase = event_base_new();

  if(eventbase == NULL)
    server_die("event init failed", YES);
}
