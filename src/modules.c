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

#include "stdinc.h"
#include "modules.h"
#include "ircd.h"
#include "client.h"
#include "send.h"
#include "s_conf.h"
#include "handlers.h"
#include "numeric.h"
#include "parse.h"
#include "ircd_defs.h"

/* -TimeMr14C:
 * I have moved the dl* function definitions and
 * the two functions (load_a_module / unload_a_module) to the
 * file dynlink.c 
 * And also made the necessary changes to those functions
 * to comply with shl_load and friends.
 * In this file, to keep consistency with the makefile, 
 * I added the ability to load *.sl files, too.
 * 27/02/2002
 */

#ifndef STATIC_MODULES

struct module **modlist = NULL;

static char base_valid = 0;
static char modlist_valid = 0;

static char* base_path = NULL;
static char* base_autoload = NULL;

static const char *core_module_table[] =
{
  "m_die",
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

#define MODS_INCREMENT 10
int num_mods = 0;
int max_mods = MODS_INCREMENT;

static dlink_list mod_paths = { NULL, NULL, 0 };

static void mo_modload(struct Client *, struct Client *, int, char **);
static void mo_modlist(struct Client *, struct Client *, int, char **);
static void mo_modreload(struct Client *, struct Client *, int, char **);
static void mo_modunload(struct Client *, struct Client *, int, char **);
static void mo_modrestart(struct Client *, struct Client *, int, char **);

struct Message modload_msgtab = {
 "MODLOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_modload}
};

struct Message modunload_msgtab = {
 "MODUNLOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_modunload}
};

struct Message modreload_msgtab = {
  "MODRELOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_modreload}
};

struct Message modlist_msgtab = {
 "MODLIST", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, mo_modlist}
};

struct Message modrestart_msgtab = {
 "MODRESTART", 0, 0, 0, 0, MFLG_SLOW, 0,
 {m_unregistered, m_not_oper, m_ignore, mo_modrestart}
};


extern struct Message hash_msgtab; /* XXX */
extern struct Message error_msgtab;

void
modules_init(void)
{
  mod_add_cmd(&modload_msgtab);
  mod_add_cmd(&modunload_msgtab);
  mod_add_cmd(&modreload_msgtab);
  mod_add_cmd(&modlist_msgtab);
  mod_add_cmd(&modrestart_msgtab);
  mod_add_cmd(&error_msgtab);
  mod_add_cmd(&hash_msgtab);
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
  struct module_path *mpath;

  DLINK_FOREACH(ptr, mod_paths.head)
  {
    mpath = ptr->data;

    if (!strcmp(path, mpath->path))
      return(mpath);
  }

  return(NULL);
}

/* init_modlist()
 * Convenience function to malloc the modlist when necessary.
 *
 * input - nothing
 * output - nothing
 * side effect - modlist may have been malloc'd and modlist_valid set to 1.
 */

static void
init_modlist (void)
{
  if (!modlist_valid)
  {
    modlist = (struct module **)MyMalloc(sizeof(struct module) *
                                        (MODS_INCREMENT));
    modlist_valid = 1;
  }
}

/* mod_set_base()
 * Defines the base path to find the official hybrid modules.
 * I.E., all core/ modules MUST be in this directory. Specified in ircd.conf.
 * 
 * input - path
 * output - none
 * side effects - sets the base path to path
 */

void
mod_set_base (char* path)
{
  unsigned int len;
  base_valid = 1;

  MyFree (base_path);
  MyFree (base_autoload);

  DupString (base_path, path);
  
  len = strlen(path) + 10;
  /* whatever path + "/autoload/" */
  
  base_autoload = MyMalloc (len + 1);
  snprintf (base_autoload, len, "%s/autoload/", base_path);
}

/* mod_add_path()
 *
 * input	- path
 * ouput	- 
 * side effects - adds path to list
 */
void
mod_add_path(const char *path)
{
  unsigned int len = strlen (path);
  struct module_path *pathst;

  if (mod_find_path(path))
    return;

  pathst = MyMalloc(sizeof(struct module_path));
  pathst->path = MyMalloc (len + 1);
  
  strlcpy(pathst->path, path, len + 1);
  dlinkAdd(pathst, &pathst->node, &mod_paths);
}

/* mod_clear_paths()
 *
 * input	-
 * output	-
 * side effects - clear the lists of paths
 */
void
mod_clear_paths(void)
{
  struct module_path *pathst;
  dlink_node *ptr;
  dlink_node *next_ptr;

  DLINK_FOREACH_SAFE(ptr, next_ptr, mod_paths.head)
  {
    pathst = ptr->data;

    dlinkDelete(&pathst->node, &mod_paths);
    MyFree(pathst->path);
    MyFree(pathst);
  }
}

/* findmodule_byname
 *
 * input        -
 * output       -
 * side effects -
 */
int 
findmodule_byname(const char *name)
{
  int i;

  for (i = 0; i < num_mods; i++) 
  {
    if (irccmp(modlist[i]->name, name) == 0)
      return(i);
  }

  return(-1);
}

/* load_all_modules()
 *
 * input        -
 * output       -
 * side effects -
 */
void
load_all_modules(int warn)
{
  DIR *system_module_dir = NULL;
  struct dirent *ldirent = NULL;
  char* module_fq_name;
  int len;
  unsigned int mq_len;
  
  /* At this point, base_path MUST be specified */
  if (base_valid == 0)
  {
    ilog (L_CRIT, "You must specify a base_path in ircd.conf. See the examples. Terminating!");
    exit (EXIT_FAILURE);
  }

  modules_init();

  init_modlist();
  
  max_mods = MODS_INCREMENT;
  system_module_dir = opendir(base_autoload);

  if (system_module_dir == NULL)
  {
    ilog(L_WARN, "Could not load modules from %s: %s",
         base_autoload, strerror (errno));
    return;
  }

  while ((ldirent = readdir(system_module_dir)) != NULL)
  {
    len = strlen(ldirent->d_name);

    /* On HPUX, we have *.sl as shared library extension
     * -TimeMr14C
     */
    if ((len > 3) && (ldirent->d_name[len-3] == '.') &&
        (ldirent->d_name[len-2] == 's') &&
        ((ldirent->d_name[len-1] == 'o') ||
        (ldirent->d_name[len-1] == 'l')))
    {
       if ((mq_len = strlen(base_autoload) + len + 1) > PATH_MAX)
       {
          ilog (L_ERROR, "Module path for %s truncated, module not loaded!",
                  ldirent->d_name);
       }
       else /* Guaranteed the path fits into a string of PATH_MAX now */
       {
         module_fq_name = MyMalloc(mq_len + 1);
         snprintf (module_fq_name, mq_len + 1, "%s/%s", base_autoload, ldirent->d_name);
         load_a_module(module_fq_name, warn, 0);
         MyFree (module_fq_name);
       }
    }
  }

  closedir(system_module_dir);
}

/* load_core_modules()
 *
 * input        -
 * output       -
 * side effects - core modules are loaded, if any fail, kill ircd
 */
void
load_core_modules(int warn)
{
  char* module_name;
  int i;
  unsigned int m_len;

  for (i = 0; core_module_table[i]; i++)
  {
    if ((m_len = (strlen(base_path) + strlen(core_module_table[i]) + strlen(SHARED_SUFFIX) + 2)) > PATH_MAX)
    {
       ilog (L_ERROR, "Path for %s%s was truncated, the module was not loaded.",
               core_module_table[i], SHARED_SUFFIX);
    }
    else
    {
      module_name = MyMalloc (m_len + 1);
      snprintf (module_name, m_len + 1, "%s/%s%s", base_path, core_module_table[i], SHARED_SUFFIX);
      if (load_a_module(module_name, warn, 1) == -1)
      {
        ilog(L_CRIT, "Error loading core module %s%s: terminating ircd",
             core_module_table[i], SHARED_SUFFIX);
        exit (EXIT_FAILURE);
      }
      MyFree (module_name);
    }
  }
}

/* load_one_module()
 *
 * input        -
 * output       -
 * side effects -
 */
int
load_one_module(char *path, int coremodule)
{
  char* modpath;
  dlink_node *ptr;
  struct module_path *mpath;
  struct stat statbuf;
  unsigned int m_len;

  init_modlist();
  
  DLINK_FOREACH(ptr, mod_paths.head)
  {
    mpath = ptr->data;

    if ((m_len = strlen(mpath->path) + strlen(path) + 1) > PATH_MAX)
    {
      ilog(L_ERROR, "Path for %s/%s was truncated, not loading module from there",
           mpath->path, path);
      continue;
    }
    else
    {
      modpath = MyMalloc(m_len + 1);
      snprintf(modpath, m_len + 1, "%s/%s", mpath->path, path);

      if ((strstr(modpath, "../") == NULL) &&
          (strstr(modpath, "/..") == NULL)) 
      {
        if (stat(modpath, &statbuf) == 0)
        {
          if (S_ISREG(statbuf.st_mode))
          {
            /* Regular files only please */
            return(load_a_module(modpath, 1, coremodule));
          }
        }
      }
    }
  }

  sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                       "Cannot locate module %s", path);
  ilog(L_WARN, "Cannot locate module %s", path);
  return(-1);
}

/* load a module .. */
static void
mo_modload(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char *m_bn;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if (findmodule_byname(m_bn) != -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is already loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  load_one_module(parv[1], 0);
}

/* unload a module .. */
static void
mo_modunload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  char *m_bn;
  int modindex;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((modindex = findmodule_byname(m_bn)) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  if (modlist[modindex]->core == 1)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Module %s is a core module and may not be unloaded",
	       me.name, source_p->name, m_bn);
    return;
  }

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
  }
}

/* unload and load in one! */
static void
mo_modreload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  char *m_bn;
  int modindex;
  int check_core;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((modindex = findmodule_byname(m_bn)) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  check_core = modlist[modindex]->core;

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  if ((load_one_module(parv[1], check_core) == -1) && check_core)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Error reloading core "
                         "module: %s: terminating ircd", parv[1]);
    ilog(L_CRIT, "Error loading core module %s: terminating ircd", parv[1]);
    exit(0);
  }
}

/* list modules .. */
static void
mo_modlist(struct Client *client_p, struct Client *source_p,
	   int parc, char *parv[])
{
  int i;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  for (i = 0; i < num_mods; i++)
  {
    if (parc > 1)
    {
      if (match(parv[1], modlist[i]->name))
      {
        sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                   modlist[i]->name, modlist[i]->address,
                   modlist[i]->version, modlist[i]->core?"(core)":"");
      }
    }
    else
    {
      sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                 modlist[i]->name, modlist[i]->address,
                 modlist[i]->version, modlist[i]->core?"(core)":"");
    }
  }

  sendto_one(source_p, form_str(RPL_ENDOFMODLIST),
             me.name, source_p->name);
}

/* unload and reload all modules */
static void
mo_modrestart(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  int modnum;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  sendto_one(source_p, ":%s NOTICE %s :Reloading all modules",
             me.name, source_p->name);

  modnum = num_mods;

  while (num_mods)
     unload_one_module(modlist[0]->name, 0);

  load_all_modules(0);
  load_core_modules(0);
  rehash(0);

  sendto_realops_flags(UMODE_ALL, L_ALL,
              "Module Restart: %d modules unloaded, %d modules loaded",
			modnum, num_mods);
  ilog(L_WARN, "Module Restart: %d modules unloaded, %d modules loaded",
       modnum, num_mods);
}

#else /* STATIC_MODULES */
#include "s_serv.h"

/* load_all_modules()
 *
 * input        -
 * output       -
 * side effects - all the msgtabs are added for static modules
 */
void
load_all_modules(int warn)
{
  mod_add_cmd(&error_msgtab);
  mod_add_cmd(&accept_msgtab);
  mod_add_cmd(&admin_msgtab);
  mod_add_cmd(&away_msgtab);
  mod_add_cmd(&capab_msgtab);
  mod_add_cmd(&cburst_msgtab);
  mod_add_cmd(&close_msgtab);
  mod_add_cmd(&connect_msgtab);
#ifdef HAVE_LIBCRYPTO
  mod_add_cmd(&challenge_msgtab);
  mod_add_cmd(&cryptlink_msgtab);
#endif
  mod_add_cmd(&die_msgtab);
  mod_add_cmd(&dmem_msgtab);
  mod_add_cmd(&drop_msgtab);
  mod_add_cmd(&eob_msgtab);
  mod_add_cmd(&gline_msgtab);
  add_capability("GLN", CAP_GLN, 1);
  mod_add_cmd(&ungline_msgtab);
  mod_add_cmd(&info_msgtab);
  mod_add_cmd(&invite_msgtab);
  mod_add_cmd(&ison_msgtab);
  mod_add_cmd(&join_msgtab);
  mod_add_cmd(&kick_msgtab);
  mod_add_cmd(&kill_msgtab);
  mod_add_cmd(&kline_msgtab);
  add_capability("KLN", CAP_KLN, 1);
  mod_add_cmd(&dline_msgtab);
  mod_add_cmd(&unkline_msgtab);
  mod_add_cmd(&undline_msgtab);
  mod_add_cmd(&knock_msgtab);
  add_capability("KNOCK", CAP_KNOCK, 1);
  mod_add_cmd(&knockll_msgtab);
  mod_add_cmd(&links_msgtab);
  mod_add_cmd(&list_msgtab);
  mod_add_cmd(&lljoin_msgtab);
  mod_add_cmd(&llnick_msgtab);
  mod_add_cmd(&locops_msgtab);
  mod_add_cmd(&lusers_msgtab);
  mod_add_cmd(&privmsg_msgtab);
  mod_add_cmd(&notice_msgtab);
  mod_add_cmd(&mode_msgtab);
  mod_add_cmd(&motd_msgtab);
  mod_add_cmd(&names_msgtab);
  mod_add_cmd(&nburst_msgtab);
  mod_add_cmd(&nick_msgtab);
  mod_add_cmd(&oper_msgtab);
  mod_add_cmd(&operwall_msgtab);
  mod_add_cmd(&part_msgtab);
  mod_add_cmd(&pass_msgtab);
  mod_add_cmd(&ping_msgtab);
  mod_add_cmd(&pong_msgtab);
  mod_add_cmd(&post_msgtab);
  mod_add_cmd(&get_msgtab);
  mod_add_cmd(&put_msgtab);
  mod_add_cmd(&quit_msgtab);
  mod_add_cmd(&rehash_msgtab);
  mod_add_cmd(&restart_msgtab);
  mod_add_cmd(&resv_msgtab);  
  mod_add_cmd(&server_msgtab);
  mod_add_cmd(&set_msgtab);
  mod_add_cmd(&sjoin_msgtab);
  mod_add_cmd(&squit_msgtab);
  mod_add_cmd(&stats_msgtab);
  mod_add_cmd(&svinfo_msgtab);
  mod_add_cmd(&testline_msgtab);
  mod_add_cmd(&time_msgtab);
  mod_add_cmd(&topic_msgtab);
  mod_add_cmd(&trace_msgtab);
  add_capability("UNKLN", CAP_UNKLN, 1);
  mod_add_cmd(&unresv_msgtab);
  mod_add_cmd(&unxline_msgtab);
  mod_add_cmd(&user_msgtab);
  mod_add_cmd(&userhost_msgtab);
  mod_add_cmd(&users_msgtab);
  mod_add_cmd(&version_msgtab);
  mod_add_cmd(&wallops_msgtab);
  mod_add_cmd(&who_msgtab);
  mod_add_cmd(&whois_msgtab);
  mod_add_cmd(&whowas_msgtab);
  mod_add_cmd(&xline_msgtab);
#ifdef BUILD_CONTRIB
  mod_add_cmd(&test_msgtab);
  mod_add_cmd(&classlist_msgtab);
  mod_add_cmd(&clearchan_msgtab);
  mod_add_cmd(&forcejoin_msgtab);
  mod_add_cmd(&forcepart_msgtab);
  mod_add_cmd(&help_msgtab);
  mod_add_cmd(&uhelp_msgtab);
  mod_add_cmd(&jupe_msgtab);
  mod_add_cmd(&killhost_msgtab);
  mod_add_cmd(&map_msgtab);
  mod_add_cmd(&test_msgtab);
  mod_add_cmd(&ojoin_msgtab);
  mod_add_cmd(&omotd_msgtab);
  mod_add_cmd(&operspy_msgtab);
  mod_add_cmd(&opme_msgtab);
#endif
}
#endif /* STATIC_MODULES */
