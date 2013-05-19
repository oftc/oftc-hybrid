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
#include "stdinc.h"
#include "tools.h"
#include "irc_string.h"
#include "modules.h"
#include "s_log.h"
#include "client.h"
#include "send.h"
#include <libgen.h>

#ifndef RTLD_NOW
#define RTLD_NOW RTLD_LAZY /* openbsd deficiency */
#endif

#if defined(HAVE_DLINFO) && defined(HAVE_LINK_H)
# include <link.h>
#endif

#if USE_SHARED_MODULES

extern dlink_list mod_list;

static char unknown_ver[] = "<unknown>";

/* This file contains the core functions to use dynamic libraries.
 * -TimeMr14C
 */

/* unload_one_module()
 *
 * inputs	- name of module to unload
 *		- 1 to say modules unloaded, 0 to not
 * output	- 0 if successful, -1 if error
 * side effects	- module is unloaded
 */
int
unload_one_module(char *name, int warn)
{
  dlink_node *ptr = NULL;
  struct module *modp = NULL;

  if ((ptr = findmodule_byname(name)) == NULL) 
    return -1;

  modp = ptr->data;

  if (modp->modremove)
    (*modp->modremove)();

#ifdef HAVE_SHL_LOAD
    /* shl_* and friends have a slightly different format than dl*. But it does not
     * require creation of a totally new modules.c, instead proper usage of
     * defines solve this case. -TimeMr14C
     */
  shl_unload((shl_t) & (modp->handle));
#else
  /* We use FreeBSD's dlfunc(3) interface, or fake it as we
   * used to here if it isn't there.  The interface should
   * be standardised some day, and so it eventually will be
   * providing something guaranteed to do the right thing here.
   *          -jmallett
   */
  dlclose(modp->handle);
#endif
  assert(dlink_list_length(&mod_list) > 0);
  dlinkDelete(ptr, &mod_list);
  MyFree(modp->name);
  MyFree(modp);

  if (warn == 1)
  {
    ilog(L_INFO, "Module %s unloaded", name);
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s unloaded", name);
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
load_a_module(char *path, int warn, int core)
{
#ifdef HAVE_DLINFO
  struct link_map *map;
#endif
#ifdef HAVE_SHL_LOAD
  shl_t tmpptr;
#else
  void *tmpptr = NULL;
#endif
  void *addr = NULL;
  char *mod_basename;
  void (*initfunc)(void) = NULL;
  void (*mod_deinit)(void) = NULL;
  char **verp;
  char *ver;
  struct module *modp;

  mod_basename = basename(path);

  if (findmodule_byname(mod_basename) != NULL)
    return(1);

#ifdef HAVE_SHL_LOAD
  tmpptr = shl_load(path, BIND_IMMEDIATE, NULL);
#else
  tmpptr = dlopen(path, RTLD_NOW);
#endif

  if (tmpptr == NULL)
  {
#ifdef HAVE_SHL_LOAD
    const char *err = strerror(errno);
#else
    const char *err = dlerror();
#endif
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Error loading module %s: %s",
                         mod_basename, err);
    ilog(L_WARN, "Error loading module %s: %s", mod_basename, err);
    
    return(-1);
  }

#ifdef HAVE_SHL_LOAD
  if (shl_findsym(&tmpptr, "_modinit", TYPE_UNDEFINED, (void *)&initfunc) == -1)
  {
    if (shl_findsym(&tmpptr, "__modinit", TYPE_UNDEFINED, (void *)&initfunc) == -1)
    {
      ilog(L_WARN, "Module %s has no _modinit() function", mod_basename);
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s has no _modinit() function",
                           mod_basename);
      shl_unload(tmpptr);
      return(-1);
    }
  }

  if (shl_findsym(&tmpptr, "_moddeinit", TYPE_UNDEFINED, (void *)&mod_deinit) == -1)
  {
    if (shl_findsym(&tmpptr, "__moddeinit", TYPE_UNDEFINED, (void *)&mod_deinit) == -1)
    {
      ilog(L_WARN, "Module %s has no _moddeinit() function", mod_basename);
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s has no _moddeinit() function",
                           mod_basename);
      /* this is a soft error.  we're allowed not to have one, i guess.
       * (judging by the code in unload_one_module() */
      mod_deinit = NULL;
    }
  }

  if (shl_findsym(&tmpptr, "_version", TYPE_UNDEFINED, &verp) == -1)
  {
    if (shl_findsym(&tmpptr, "__version", TYPE_UNDEFINED, &verp) == -1)
      ver = unknown_ver;
    else
      ver = *verp;
  }
  else
    ver = *verp;
#else
  if ((initfunc = (void(*)(void))dlfunc(tmpptr, "_modinit")) == NULL &&
      /* Only for compatibility, because some systems have underscore
       * prepended symbol names */
      (initfunc = (void(*)(void))dlfunc(tmpptr, "__modinit")) == NULL)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s has no _modinit() function",
                         mod_basename);
    ilog(L_WARN, "Module %s has no _modinit() function", mod_basename);
    dlclose(tmpptr);
    return(-1);
  }

  mod_deinit = (void(*)(void))dlfunc(tmpptr, "_moddeinit");

  if (mod_deinit == NULL && (mod_deinit = (void(*)(void))dlfunc(tmpptr, "__moddeinit")) == NULL)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s has no _moddeinit() function",
                         mod_basename);
    ilog(L_WARN, "Module %s has no _moddeinit() function", mod_basename);
    /* blah blah soft error, see above. */
    mod_deinit = NULL;
  }

  verp = (char **)dlsym(tmpptr, "_version");

  if (verp == NULL && (verp = (char **)dlsym(tmpptr, "__version")) == NULL)
    ver = unknown_ver;
  else
    ver = *verp;
#endif

  modp            = MyMalloc(sizeof(struct module));
#ifdef HAVE_DLINFO
  dlinfo(tmpptr, RTLD_DI_LINKMAP, &map);
  if (map != NULL)
    addr = (void *)map->l_addr;
  else
#endif
    addr = tmpptr;

  modp->handle    = tmpptr;
  modp->address   = addr;
  modp->version   = ver;
  modp->core      = core;
  modp->modremove = mod_deinit;

  DupString(modp->name, mod_basename);
  dlinkAdd(modp, &modp->node, &mod_list);

  initfunc();

  if (warn == 1)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                         "Module %s [version: %s] loaded at %p",
                         mod_basename, ver, addr);
    ilog(L_WARN, "Module %s [version: %s] loaded at %p",
         mod_basename, ver, addr);
  }

  return(0);
}
#endif
