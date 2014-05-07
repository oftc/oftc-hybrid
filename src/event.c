/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  event.c: Event functions.
 *
 *  Copyright (C) 1998-2000 Regents of the University of California
 *  Copyright (C) 2001-2002 Hybrid Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "event.h"
#include "client.h"
#include "send.h"
#include "memory.h"
#include "log.h"
#include "numeric.h"

static dlink_list events = { 0 };
static struct ev_entry *eventFind(uv_timer_cb, void *);

/*
 * void eventAdd(const char *name, uv_timer_cb func, void *arg, time_t when)
 *
 * Input: Name of event, function to call, arguments to pass, and frequency
 *    of the event.
 * Output: None
 * Side Effects: Adds the event to the event list.
 */
void
eventAdd(const char *name, uv_timer_cb func, void *arg, time_t when)
{
  struct ev_entry *event = MyMalloc(sizeof(struct ev_entry));

  uv_timer_init(server_state.event_loop, &event->handle);
  event->handle.data = arg;
  event->func = func;

  dlinkAdd(event, &event->node, &events);

  uv_timer_start(&event->handle, func, when * 1000, when * 1000);
}

/*
 * void eventDelete(uv_timer_cb func, void *arg)
 *
 * Input: Function handler, argument that was passed.
 * Output: None
 * Side Effects: Removes the event from the event list
 */
void
eventDelete(uv_timer_cb func, void *arg)
{
  struct ev_entry *event = eventFind(func, arg);

  if (event == NULL)
    return;

  uv_timer_stop(&event->handle);
  dlinkDelete(&event->node, &events);
  MyFree(event);
}

/*
 * void eventAddIsh(const char *name, uv_timer_cb func, void *arg, time_t delta_isa)
 *
 * Input: Name of event, function to call, arguments to pass, and frequency
 *    of the event.
 * Output: None
 * Side Effects: Adds the event to the event list within +- 1/3 of the
 *           specified frequency.
 */
void
eventAddIsh(const char *name, uv_timer_cb func, void *arg, time_t delta_ish)
{
  if (delta_ish >= 3.0)
  {
    const time_t two_third = (2 * delta_ish) / 3;
    delta_ish = two_third + ((rand() % 1000) * two_third) / 1000;
    /*
     * XXX I hate the above magic, I don't even know if its right.
     * Grr. -- adrian
     */
  }

  eventAdd(name, func, arg, delta_ish);
}

/*
 * void eventInit()
 *
 * Input: None
 * Output: None
 * Side Effects: Initializes the event system.
 */
void
eventInit()
{
}

/*
 * int eventFind(uv_timer_cb func, void *arg)
 *
 * Input: Event function and the argument passed to it
 * Output: Index to the slow in the event_table
 * Side Effects: None
 */
static struct ev_entry *
eventFind(uv_timer_cb func, void *arg)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, events.head)
  {
    struct ev_entry *event = ptr->data;

    if(event->func == func && event->handle.data == arg)
      return event;
  }

  return NULL;
}
