/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  modules.c: A module loader.
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
 *  $Id$
 */

#include "ltdl.h"

#include "stdinc.h"
#include "list.h"
#include "modules.h"
#include "log.h"
#include "ircd.h"
#include "client.h"
#include "send.h"
#include "conf.h"
#include "numeric.h"
#include "parse.h"
#include "ircd_defs.h"
#include "irc_string.h"
#include "memory.h"
#include "list.h"
#include <libgen.h>

#define SHARED_SUFFIX ".so"


#ifndef STATIC_MODULES

static dlink_list modules_list = { NULL, NULL, 0 };

static const char *unknown_ver = "<unknown>";

static const char *core_module_table[] =
{
  "m_die",
  "m_error",
  "m_join",
  "m_kick",
  "m_kill",
  "m_message",
  "m_mode",
  "m_nick",
  "m_part",
  "m_quit",
  "m_server",
  "m_sjoin",
  "m_squit",
  NULL
};

static dlink_list mod_paths = { NULL, NULL, 0 };
static dlink_list conf_modules = { NULL, NULL, 0 };

static void mo_module(struct Client *, struct Client *, int, char *[]);

struct Message module_msgtab = {
 "MODULE", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_module, m_ignore}
};

int
modules_valid_suffix(const char *name)
{
  return ((name = strrchr(name, '.'))) && !strcmp(name, ".la");
}

/* unload_one_module()
 *
 * inputs       - name of module to unload
 *              - 1 to say modules unloaded, 0 to not
 * output       - 0 if successful, -1 if error
 * side effects - module is unloaded
 */
int
unload_one_module(const char *name, int warn)
{
  struct module *modp = NULL;

  if ((modp = findmodule_byname(name)) == NULL)
    return -1;

  if (modp->modexit)
   modp->modexit();

  assert(dlink_list_length(&modules_list) > 0);
  dlinkDelete(&modp->node, &modules_list);
  MyFree(modp->name);

  lt_dlclose(modp->handle);

  if (warn == 1)
  {
    ilog(LOG_TYPE_IRCD, "Module %s unloaded", name);
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s unloaded", name);
  }

  return 0;
}

/* load_a_module()
 *
 * inputs       - path name of module, int to notice, int of core
 * output       - -1 if error 0 if success
 * side effects - loads a module if successful
 */
int
load_a_module(const char *path, int warn)
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
    ilog(LOG_TYPE_IRCD, "Error loading module %s: %s", mod_basename, err);
    return -1;
  }

  if ((modp = lt_dlsym(tmpptr, "module_entry")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s has no module_entry export",
                         mod_basename);
    ilog(LOG_TYPE_IRCD, "Module %s has no module_entry export", mod_basename);
    lt_dlclose(tmpptr);
    return -1;
  }

  modp->handle = tmpptr;

  if (EmptyString(modp->version))
    modp->version = unknown_ver;

  DupString(modp->name, mod_basename);
  dlinkAdd(modp, &modp->node, &modules_list);

  if (modp->modinit)
    modp->modinit();

  if (warn == 1)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Module %s [version: %s handle: %p] loaded.",
                         modp->name, modp->version, tmpptr);
    ilog(LOG_TYPE_IRCD, "Module %s [version: %s handle: %p] loaded.",
         modp->name, modp->version, tmpptr);
  }

  return 0;
}

/*
 * modules_init
 *
 * input	- NONE
 * output	- NONE
 * side effects	- The basic module manipulation modules are loaded
 */
void
modules_init(void)
{
  if (lt_dlinit())
  {
    ilog(LOG_TYPE_IRCD, "Couldn't initialize the libltdl run time dynamic"
         " link library. Exiting.");
    exit(0);
  }

  mod_add_cmd(&module_msgtab);
}

/* mod_find_path()
 *
 * input	- path
 * output	- none
 * side effects - returns a module path from path
 */
static struct module_path *
mod_find_path(const char *path)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, mod_paths.head)
  {
    struct module_path *mpath = ptr->data;

    if (!strcmp(path, mpath->path))
      return mpath;
  }

  return NULL;
}

/* mod_add_path()
 *
 * input	- path
 * output	- NONE
 * side effects - adds path to list
 */
void
mod_add_path(const char *path)
{
  struct module_path *pathst;

  if (mod_find_path(path))
    return;

  pathst = MyMalloc(sizeof(struct module_path));

  strlcpy(pathst->path, path, sizeof(pathst->path));
  dlinkAdd(pathst, &pathst->node, &mod_paths);
}

/* add_conf_module
 *
 * input	- module name
 * output	- NONE
 * side effects - adds module to conf_mod
 */
void
add_conf_module(const char *name)
{
  struct module_path *pathst;

  pathst = MyMalloc(sizeof(struct module_path));

  strlcpy(pathst->path, name, sizeof(pathst->path));
  dlinkAdd(pathst, &pathst->node, &conf_modules);
}

/* mod_clear_paths()
 *
 * input	- NONE
 * output	- NONE
 * side effects - clear the lists of paths and conf modules
 */
void
mod_clear_paths(void)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, mod_paths.head)
  {
    dlinkDelete(ptr, &mod_paths);
    MyFree(ptr->data);
  }

  DLINK_FOREACH_SAFE(ptr, next_ptr, conf_modules.head)
  {
    dlinkDelete(ptr, &conf_modules);
    MyFree(ptr->data);
  }
}

/* findmodule_byname
 *
 * input        - name of module
 * output       - NULL if not found or pointer to module
 * side effects - NONE
 */
struct module *
findmodule_byname(const char *name)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, modules_list.head)
  {
    struct module *modp = ptr->data;

    if (strcmp(modp->name, name) == 0)
      return modp;
  }

  return NULL;
}

/* load_all_modules()
 *
 * input        - int flag warn
 * output       - NONE
 * side effects - load all modules found in autoload directory
 */
void
load_all_modules(int warn)
{
  DIR *system_module_dir = NULL;
  struct dirent *ldirent = NULL;
  char module_fq_name[PATH_MAX + 1];

  if ((system_module_dir = opendir(AUTOMODPATH)) == NULL)
  {
    ilog(LOG_TYPE_IRCD, "Could not load modules from %s: %s",
         AUTOMODPATH, strerror(errno));
    return;
  }

  while ((ldirent = readdir(system_module_dir)) != NULL)
  {
    const char *offset = strrchr(ldirent->d_name, '.');

    if (offset && !strcmp(offset, SHARED_SUFFIX))
    {
       snprintf(module_fq_name, sizeof(module_fq_name), "%s/%s",
                AUTOMODPATH, ldirent->d_name);
       load_a_module(module_fq_name, warn);
    }
  }

  closedir(system_module_dir);
}

/* load_conf_modules()
 *
 * input        - NONE
 * output       - NONE
 * side effects - load modules given in ircd.conf
 */
void
load_conf_modules(void)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, conf_modules.head)
  {
    struct module_path *mpath = ptr->data;

    if (findmodule_byname(mpath->path) == NULL)
      load_one_module(mpath->path);
  }
}

/* load_core_modules()
 *
 * input        - int flag warn
 * output       - NONE
 * side effects - core modules are loaded, if any fail, kill ircd
 */
void
load_core_modules(int warn)
{
  char module_name[PATH_MAX + 1];
  int i = 0;

  for (; core_module_table[i]; ++i)
  {
    snprintf(module_name, sizeof(module_name), "%s%s%s", MODPATH,
             core_module_table[i], SHARED_SUFFIX);

    if (load_a_module(module_name, warn) == -1)
    {
      ilog(LOG_TYPE_IRCD, "Error loading core module %s%s: terminating ircd",
           core_module_table[i], SHARED_SUFFIX);
      exit(EXIT_FAILURE);
    }
  }
}

/* load_one_module()
 *
 * input        - pointer to path
 *		- flagged as core module or not
 * output       - -1 if error 
 * side effects - module is loaded if found.
 */
int
load_one_module(const char *path)
{
  dlink_node *ptr = NULL;
  char modpath[PATH_MAX + 1];
  struct stat statbuf;

  DLINK_FOREACH(ptr, mod_paths.head)
  {
    const struct module_path *mpath = ptr->data;

    snprintf(modpath, sizeof(modpath), "%s/%s", mpath->path, path);

    if (strstr(modpath, "../") == NULL &&
        strstr(modpath, "/..") == NULL) 
      if (!stat(modpath, &statbuf))
        if (S_ISREG(statbuf.st_mode))  /* Regular files only please */
          return load_a_module(modpath, 1);
  }

  sendto_realops_flags(UMODE_ALL, L_ALL, 
                       "Cannot locate module %s", path);
  ilog(LOG_TYPE_IRCD, "Cannot locate module %s", path);
  return -1;
}

/*! \brief MODULE command handler (called by operators)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = action [LOAD, UNLOAD, RELOAD, LIST]
 *      - parv[2] = module name
 */
static void
mo_module(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  const char *m_bn = NULL;
  struct module *modp = NULL;
  int check_core;

  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "MODULE");
    return;
  }

  if (!irccmp(parv[1], "LOAD"))
  {
    if (findmodule_byname((m_bn = basename(parv[2]))) != NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :Module %s is already loaded",
                 me.name, source_p->name, m_bn);
      return;
    }

    load_one_module(parv[2]);
    return;
  }

  if (!irccmp(parv[1], "UNLOAD"))
  {
    if ((modp = findmodule_byname((m_bn = basename(parv[2])))) == NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
                 me.name, source_p->name, m_bn);
      return;
    }

    if (modp->flags & MODULE_FLAG_CORE)
    {
      sendto_one(source_p,
                 ":%s NOTICE %s :Module %s is a core module and may not be unloaded",
                 me.name, source_p->name, m_bn);
      return;
    }

    if (unload_one_module(m_bn, 1) == -1)
      sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
                 me.name, source_p->name, m_bn);
    return;
  }

  if (!irccmp(parv[1], "RELOAD"))
  {
    if (!strcmp(parv[2], "*"))
    {
      unsigned int modnum = 0;
      dlink_node *ptr = NULL, *ptr_next = NULL;

      sendto_one(source_p, ":%s NOTICE %s :Reloading all modules",
                 me.name, source_p->name);

      modnum = dlink_list_length(&modules_list);

      DLINK_FOREACH_SAFE(ptr, ptr_next, modules_list.head)
      {
        modp = ptr->data;
        unload_one_module(modp->name, 0);
      }

      load_all_modules(0);
      load_conf_modules();
      load_core_modules(0);

      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "Module Restart: %u modules unloaded, %u modules loaded",
                           modnum, dlink_list_length(&modules_list));
      ilog(LOG_TYPE_IRCD, "Module Restart: %u modules unloaded, %u modules loaded",
           modnum, dlink_list_length(&modules_list));
      return;
    }

    if ((modp = findmodule_byname((m_bn = libio_basename(parv[2])))) == NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
      return;
    }

    check_core = (modp->flags & MODULE_FLAG_CORE) != 0;

    if (unload_one_module(m_bn, 1) == -1)
    {
      sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
                 me.name, source_p->name, m_bn);
      return;
    }

    if ((load_one_module(parv[2]) == -1) && check_core)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, "Error reloading core "
                           "module: %s: terminating ircd", parv[2]);
      ilog(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd", parv[2]);
      exit(0);
    }

    return;
  }

  if (!irccmp(parv[1], "LIST"))
  {
    const dlink_node *ptr = NULL;

    DLINK_FOREACH(ptr, modules_list.head)
    {
      if (parc > 2 && !match(parv[2], modp->name))
        continue;

      sendto_one(source_p, form_str(RPL_MODLIST), me.name, source_p->name,
                 modp->name, modp->handle,
                 modp->version, (modp->flags & MODULE_FLAG_CORE) ?"(core)":"");
    }

    sendto_one(source_p, form_str(RPL_ENDOFMODLIST),
               me.name, source_p->name);
    return;
  }
}
