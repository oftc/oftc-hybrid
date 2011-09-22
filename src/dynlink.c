/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  dynlink.c: A module loader.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 * $Id$
 *
 */

#include "ltdl.h"

#include "stdinc.h"
#include "list.h"
#include "irc_string.h"
#include "modules.h"
#include "s_log.h"
#include "client.h"
#include "send.h"


static const char *unknown_ver = "<unknown>";

/* This file contains the core functions to use dynamic libraries.
 * -TimeMr14C
 */

void
dynlink_init(void)
{
  if (lt_dlinit())
  {
    ilog(L_ERROR, "Couldn't initialize the libltdl run time dynamic"
         " link library. Exiting.");
    exit(0);
  }
}

int
modules_valid_suffix(const char *name)
{
  return ((name = strrchr(name, '.'))) && !strcmp(name, ".la");
}

/* unload_one_module()
 *
 * inputs	- name of module to unload
 *		- 1 to say modules unloaded, 0 to not
 * output	- 0 if successful, -1 if error
 * side effects	- module is unloaded
 */
int
unload_one_module(const char *name, int warn)
{
  struct module *modp = NULL;

  if ((modp = findmodule_byname(name)) == NULL) 
    return -1;

  if (modp->modexit)
   modp->modexit();

  assert(dlink_list_length(&mod_list) > 0);
  dlinkDelete(&modp->node, &mod_list);
  MyFree(modp->name);

  lt_dlclose(modp->handle);

  if (warn == 1)
  {
    ilog(L_INFO, "Module %s unloaded", name);
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s unloaded", name);
  }

  return 0;
}

/* load_a_module()
 *
 * inputs	- path name of module, int to notice, int of core
 * output	- -1 if error 0 if success
 * side effects - loads a module if successful
 */
int
load_a_module(const char *path, int warn, int core)
{
  lt_dlhandle tmpptr = NULL;
  const char *mod_basename = NULL;
  struct module *modp = NULL;

  if (findmodule_byname((mod_basename = libio_basename(path))))
    return 1;

  if (!(tmpptr = lt_dlopen(path))) {
    const char *err = ((err = lt_dlerror())) ? err : "<unknown>";

    sendto_realops_flags(UMODE_ALL, L_ALL, "Error loading module %s: %s",
                         mod_basename, err);
    ilog(L_WARN, "Error loading module %s: %s", mod_basename, err);
    return -1;
  }

  if ((modp = lt_dlsym(tmpptr, "module_entry")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s has no module_entry export",
                         mod_basename);
    ilog(L_WARN, "Module %s has no module_entry export", mod_basename);
    lt_dlclose(tmpptr);
    return -1;
  }

  modp->handle = tmpptr;

  if (EmptyString(modp->version))
    modp->version = unknown_ver;

  if (core)
    modp->flags |= MODULE_FLAG_CORE;

  DupString(modp->name, mod_basename);
  dlinkAdd(modp, &modp->node, &mod_list);

  if (modp->modinit)
    modp->modinit();

  if (warn == 1)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Module %s [version: %s handle: %p] loaded.",
                         modp->name, modp->version, tmpptr);
    ilog(L_WARN, "Module %s [version: %s handle: %p] loaded.",
         modp->name, modp->version, tmpptr);
  }

  return 0;
}
