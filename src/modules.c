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
#include "s_log.h"
#include "ircd.h"
#include "client.h"
#include "send.h"
#include "s_conf.h"
#include "handlers.h"
#include "numeric.h"
#include "parse.h"
#include "ircd_defs.h"
#include "irc_string.h"
#include "memory.h"
#include "tools.h"
#include "list.h"

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

static char *core_module_table[] =
{
  "m_die.s",
  "m_kick.s",
  "m_kill.s",
  "m_message.s",
  "m_mode.s",
  "m_nick.s",
  "m_part.s",
  "m_quit.s",
  "m_server.s",
  "m_sjoin.s",
  "m_squit.s",
  NULL
};

#define MODS_INCREMENT 10
int num_mods = 0;
int max_mods = MODS_INCREMENT;

static dlink_list mod_paths;

static void mo_modload(struct Client*, struct Client*, int, char**);
static void mo_modlist(struct Client*, struct Client*, int, char**);
static void mo_modreload(struct Client*, struct Client*, int, char**);
static void mo_modunload(struct Client*, struct Client*, int, char**);
static void mo_modrestart(struct Client*, struct Client*, int, char**);

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
}

/* mod_find_path()
 *
 * input	- path
 * output	- none
 * side effects - returns a module path from path
 */
static struct module_path *
mod_find_path(char *path)
{
  dlink_node *pathst = mod_paths.head;
  struct module_path *mpath;
  
  if (!pathst)
    return NULL;

  for (; pathst; pathst = pathst->next)
  {
    mpath = (struct module_path *)pathst->data;

    if (!strcmp(path, mpath->path))
      return mpath;
  }
  
  return NULL;
}

/* mod_add_path
 *
 * input	- path
 * ouput	- 
 * side effects - adds path to list
 */
void
mod_add_path(char *path)
{
  struct module_path *pathst;
  dlink_node *node;
  
  if (mod_find_path(path))
    return;

  pathst = MyMalloc (sizeof (struct module_path));
  node = make_dlink_node();
  
  strcpy(pathst->path, path);
  dlinkAdd(pathst, node, &mod_paths);
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
  dlink_node *node, *next;

  for(node = mod_paths.head; node; node = next)
    {
      next = node->next;
      pathst = (struct module_path *)node->data;
      dlinkDelete(node, &mod_paths);
      free_dlink_node(node);
      MyFree(pathst);
    }
}

/* irc_basename
 *
 * input	-
 * output	-
 * side effects -
 */
char *
irc_basename(char *path)
{
  char *mod_basename = MyMalloc (strlen (path) + 1);
  char *s;

  if (!(s = strrchr (path, '/')))
    s = path;
  else
    s++;

  (void)strcpy (mod_basename, s);
  return mod_basename;
}

/* findmodule_byname
 *
 * input        -
 * output       -
 * side effects -
 */

int 
findmodule_byname (char *name)
{
  int i;

  for (i = 0; i < num_mods; i++) 
    {
      if (!irccmp (modlist[i]->name, name))
	return i;
    }
  return -1;
}

/* load_all_modules()
 *
 * input        -
 * output       -
 * side effects -
 */
void
load_all_modules (int warn)
{
  DIR            *system_module_dir = NULL;
  struct dirent  *ldirent = NULL;
  char            module_fq_name[PATH_MAX + 1];
  int             len;

  modules_init();
  
  modlist = (struct module **)MyMalloc ( sizeof (struct module) *
                                         (MODS_INCREMENT));

  max_mods = MODS_INCREMENT;

  system_module_dir = opendir (AUTOMODPATH);

  if (system_module_dir == NULL)
    {
      ilog (L_WARN, "Could not load modules from %s: %s",
	   AUTOMODPATH, strerror (errno));
      return;
    }

  while ((ldirent = readdir (system_module_dir)) != NULL)
    {
      len = strlen(ldirent->d_name);

      /* On HPUX, we have *.sl as shared library extension
       * -TimeMr14C */
      
      if ((len > 3) && 
          (ldirent->d_name[len-3] == '.') &&
          (ldirent->d_name[len-2] == 's') &&
          ((ldirent->d_name[len-1] == 'o') || (ldirent->d_name[len-1] == 'l')))
	{
	  (void)sprintf (module_fq_name, "%s/%s",  AUTOMODPATH,
			 ldirent->d_name);
	  (void)load_a_module (module_fq_name, warn, 0);
	}
    }

  (void)closedir (system_module_dir);
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
  char module_name[MAXPATHLEN];
  int i, hpux = 0;

#ifdef HAVE_SHL_LOAD
  hpux = 1;
#endif

  for(i = 0; core_module_table[i]; i++)
  {
    sprintf(module_name, "%s/%s%c",
            MODPATH, core_module_table[i], hpux ? 'l' : 'o');
	    
    if(load_a_module(module_name, warn, 1) == -1)
    {
      ilog(L_CRIT, "Error loading core module %s%c: terminating ircd", 
           core_module_table[i], hpux ? 'l' : 'o');
      exit(0);
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
load_one_module (char *path)
{
  char modpath[MAXPATHLEN];
  dlink_node *pathst;
  struct module_path *mpath;
	
  struct stat statbuf;
  
  for (pathst = mod_paths.head; pathst; pathst = pathst->next)
    {
      mpath = (struct module_path *)pathst->data;
      
      sprintf(modpath, "%s/%s", mpath->path, path);
      if((strstr(modpath, "../") == NULL) && (strstr(modpath, "/..") == NULL)) 
	 {
	    if (stat(modpath, &statbuf) == 0)
	      {
		 if(S_ISREG(statbuf.st_mode))
		    {
		       /* Regular files only please */
		       return load_a_module(modpath, 1, 0);
		    }
	      }
	    
	 }
    }
   
  sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                       "Cannot locate module %s", path);
  ilog(L_WARN, "Cannot locate module %s", path);
  return -1;
}
		

/* load a module .. */
static void
mo_modload (struct Client *client_p, struct Client *source_p, int parc, char **parv)
{
  char *m_bn;

  if (!IsOperAdmin(source_p))
  {
    sendto_one(source_p, ":%s NOTICE %s :You have no A flag", me.name, parv[0]);
    return;
  }

  m_bn = irc_basename (parv[1]);

  if (findmodule_byname (m_bn) != -1)
  {
    sendto_one (source_p, ":%s NOTICE %s :Module %s is already loaded",
                me.name, source_p->name, m_bn);
    return;
  }

  load_one_module (parv[1]);

  MyFree(m_bn);
}


/* unload a module .. */
static void
mo_modunload (struct Client *client_p, struct Client *source_p, int parc, char **parv)
{
  char *m_bn;
  int modindex;

  if (!IsOperAdmin (source_p))
  {
    sendto_one (source_p, ":%s NOTICE %s :You have no A flag",
                me.name, parv[0]);
    return;
  }

  m_bn = irc_basename (parv[1]);

  if((modindex = findmodule_byname (m_bn)) == -1)
  {
    sendto_one (source_p, ":%s NOTICE %s :Module %s is not loaded",
                me.name, source_p->name, m_bn);
    MyFree (m_bn);
    return;
  }

  if(modlist[modindex]->core == 1)
  {
    sendto_one(source_p, 
               ":%s NOTICE %s :Module %s is a core module and may not be unloaded",
	       me.name, source_p->name, m_bn);
    MyFree(m_bn);
    return;
  }

  if( unload_one_module (m_bn, 1) == -1 )
  {
    sendto_one (source_p, ":%s NOTICE %s :Module %s is not loaded",
                me.name, source_p->name, m_bn);
  }
  MyFree (m_bn);
}

/* unload and load in one! */
static void
mo_modreload (struct Client *client_p, struct Client *source_p, int parc, char **parv)
{
  char *m_bn;
  int modindex;
  int check_core;

  if (!IsOperAdmin (source_p))
    {
      sendto_one (source_p, ":%s NOTICE %s :You have no A flag",
                  me.name, parv[0]);
      return;
    }

  m_bn = irc_basename (parv[1]);

  if((modindex = findmodule_byname(m_bn)) == -1)
    {
      sendto_one (source_p, ":%s NOTICE %s :Module %s is not loaded",
                  me.name, source_p->name, m_bn);
      MyFree (m_bn);
      return;
    }

  check_core = modlist[modindex]->core;

  if( unload_one_module (m_bn, 1) == -1 )
    {
      sendto_one (source_p, ":%s NOTICE %s :Module %s is not loaded",
                  me.name, source_p->name, m_bn);
      MyFree (m_bn);
      return;
    }

  if((load_one_module(parv[1]) == -1) && check_core)
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                         "Error reloading core module: %s: terminating ircd",
			 parv[1]);
    ilog(L_CRIT, "Error loading core module %s: terminating ircd", parv[1]);
    exit(0);
  }

  MyFree(m_bn);
}

/* list modules .. */
static void
mo_modlist (struct Client *client_p, struct Client *source_p, int parc, char **parv)
{
  int i;

  if (!IsOperAdmin (source_p))
  {
    sendto_one (source_p, ":%s NOTICE %s :You have no A flag",
                me.name, parv[0]);
    return;
  }

  for(i = 0; i < num_mods; i++ )
  {
    if(parc>1)
    {
      if(match(parv[1],modlist[i]->name))
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
  
  sendto_one(source_p, form_str(RPL_ENDOFMODLIST), me.name, parv[0]);
}

/* unload and reload all modules */
static void
mo_modrestart (struct Client *client_p, struct Client *source_p, int parc, char **parv)

{
  int modnum;

  if (!IsOperAdmin (source_p))
  {
    sendto_one (source_p, ":%s NOTICE %s :You have no A flag",
                me.name, parv[0]);
    return;
  }

  sendto_one(source_p, ":%s NOTICE %s :Reloading all modules",
             me.name, parv[0]);

  modnum = num_mods;
  while (num_mods)
     unload_one_module(modlist[0]->name, 0);

  load_all_modules(0);
  load_core_modules(0);
  rehash(0);
  
  sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
              "Module Restart: %d modules unloaded, %d modules loaded",
			modnum, num_mods);
  ilog(L_WARN, "Module Restart: %d modules unloaded, %d modules loaded",
      modnum, num_mods);
}

#else /* STATIC_MODULES */

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
#ifdef VCHANS
	mod_add_cmd(&cjoin_msgtab);
#endif
	mod_add_cmd(&client_msgtab);
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
	mod_add_cmd(&help_msgtab);
	mod_add_cmd(&info_msgtab);
	mod_add_cmd(&invite_msgtab);
	mod_add_cmd(&ison_msgtab);
	mod_add_cmd(&join_msgtab);
	mod_add_cmd(&kick_msgtab);
	mod_add_cmd(&kill_msgtab);
	mod_add_cmd(&kline_msgtab);
	mod_add_cmd(&dline_msgtab);
	mod_add_cmd(&knock_msgtab);
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
	mod_add_cmd(&msgtabs[0]);
	mod_add_cmd(&msgtabs[1]);
	mod_add_cmd(&msgtabs[2]);
	mod_add_cmd(&unresv_msgtab);
	mod_add_cmd(&user_msgtab);
	mod_add_cmd(&userhost_msgtab);
	mod_add_cmd(&users_msgtab);
	mod_add_cmd(&version_msgtab);
	mod_add_cmd(&wallops_msgtab);
	mod_add_cmd(&who_msgtab);
	mod_add_cmd(&whois_msgtab);
	mod_add_cmd(&whowas_msgtab);
}

#endif /* STATIC_MODULES */
