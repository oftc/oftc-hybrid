/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hook.c: Provides a generic event hooking interface.
 *
 *  Copyright (C) 2000-2002 Edward Brocklesby, Hybrid Development Team
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

/* hooks are used by modules to hook into events called by other parts of
 * the code.  modules can also register their own events, and call them
 * as appropriate.
 */

#include "stdinc.h"
#include "tools.h"
#include "list.h"
#include "hook.h"
#include "memory.h"

static dlink_list hooks = { NULL, NULL, 0 };
static hook *find_hook(const char *name);

void
init_hooks(void)
{
#ifndef NDEBUG
  hook_add_event("iosend");
  hook_add_event("iorecv");
  hook_add_event("iorecvctrl");
#endif
  hook_add_event("burst_channel");
}

static hook *
new_hook(const char *name)
{
  hook *h;

  h = MyMalloc(sizeof(hook));
  DupString(h->name, name);
  return(h);
}

int
hook_add_event(const char *name)
{
  hook *newhook;

  if (find_hook(name) != NULL)
    return(-1);

  newhook = new_hook(name);
	
  dlinkAdd(newhook, make_dlink_node(), &hooks);
  return(0);
}

int
hook_del_event(const char *name)
{
  dlink_node *node;
  hook *h;

  DLINK_FOREACH(node, hooks.head)
  {
    h = node->data;

    if (!strcmp(h->name, name))
    {
      dlinkDelete(node, &hooks);
      MyFree(h);
      return(0);
    }
  }

  return(0);
}

static hook *
find_hook(const char *name)
{
  dlink_node *node;
  hook *h;

  DLINK_FOREACH(node, hooks.head)
  {
    h = node->data;

    if (!strcmp(h->name, name))
      return(h);
  }

  return(NULL);
}

int 
hook_del_hook(const char *event, hookfn *fn)
{
  hook *h;
  dlink_node *node, *nnode;

  if ((h = find_hook(event)) == NULL)
    return(-1);

  DLINK_FOREACH_SAFE(node, nnode, h->hooks.head)
  {
    if (fn == node->data)
    {
      dlinkDelete(node, &h->hooks);
      free_dlink_node(node);
    } 
  }

  return(0);
}

int
hook_add_hook(const char *event, hookfn *fn)
{
  hook *h;

  if ((h = find_hook(event)) == NULL)
    return(-1);

  dlinkAdd(fn, make_dlink_node(), &h->hooks);
  return(0);
}

int
hook_call_event(const char *event, void *data)
{
  hook *h;
  dlink_node *node;
  hookfn fn;

  if ((h = find_hook(event)) == NULL)
    return(-1);

  DLINK_FOREACH(node, h->hooks.head)
  {
    fn = (hookfn)(uintptr_t)node->data;

    if (fn(data) != 0)
      return(0);
  }

  return(0);
}

