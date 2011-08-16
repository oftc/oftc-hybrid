/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  event.c: Event functions.
 *
 */

#include "stdinc.h"

#include "ircd.h"
#include "levent.h"
#include "s_log.h"
#include <event2/event.h>

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

void
levent_init()
{
  event_set_log_callback(levent_log_cb);
}
