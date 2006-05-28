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
#include "modules.h"
#include "client.h"
#include "send.h"

#ifndef RTLD_NOW
#define RTLD_NOW RTLD_LAZY /* openbsd deficiency */
#endif

extern struct module **modlist;
extern int num_mods;
extern int max_mods;

static void increase_modlist(void);

#define MODS_INCREMENT 10

static char unknown_ver[] = "<unknown>";

/* This file contains the core functions to use dynamic libraries.
 * -TimeMr14C
 */

#if !defined(HAVE_SHL_LOAD) && !defined(HAVE_DLFUNC)
/*
 * Fake dlfunc(3) if we don't have it, cause it's happy.
 */
typedef void (*__function_p)(void);

static __function_p
dlfunc(void *myHandle, const char *functionName)
{
  /* XXX This is not guaranteed to work, but with
   * traditional dl*(3), it is the best we can do.
   * -jmallett
   */
  void *symbolp;

  symbolp = dlsym(myHandle, functionName);
  return((__function_p)(uintptr_t)symbolp);
}
#endif

#ifdef HAVE_MACH_O_DYLD_H
/*
** jmallett's dl*(3) shims for NSModule(3) systems.
*/
#include <mach-o/dyld.h>

#ifndef HAVE_DLOPEN
#ifndef	RTLD_LAZY
#define RTLD_LAZY 2185 /* built-in dl*(3) don't care */
#endif

void undefinedErrorHandler(const char *);
NSModule multipleErrorHandler(NSSymbol, NSModule, NSModule);
void linkEditErrorHandler(NSLinkEditErrors, int, const char *, const char *);
char *dlerror(void);
void *dlopen(char *, int);
int dlclose(void *);
void *dlsym(void *, char *);

static int firstLoad = TRUE;
static int myDlError;
static const char *myErrorTable[] =
{
  "Loading file as object failed\n",
  "Loading file as object succeeded\n",
  "Not a valid shared object\n",
  "Architecture of object invalid on this architecture\n",
  "Invalid or corrupt image\n",
  "Could not access object\n",
  "NSCreateObjectFileImageFromFile failed\n",
  NULL
};

void undefinedErrorHandler(const char *symbolName)
{
  sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Undefined symbol: %s", symbolName);
  ilog(L_WARN, "Undefined symbol: %s", symbolName);
  return;
}

NSModule multipleErrorHandler(NSSymbol s, NSModule old, NSModule new)
{
  /* XXX
  ** This results in substantial leaking of memory... Should free one
  ** module, maybe?
  */
  sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,"Symbol `%s' found in `%s' and `%s'",
                       NSNameOfSymbol(s), NSNameOfModule(old), NSNameOfModule(new));
  ilog(L_WARN, "Symbol `%s' found in `%s' and `%s'", NSNameOfSymbol(s),
       NSNameOfModule(old), NSNameOfModule(new));
  /* We return which module should be considered valid, I believe */
  return(new);
}

void linkEditErrorHandler(NSLinkEditErrors errorClass, int errnum,
                          const char *fileName, const char *errorString)
{
  sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Link editor error: %s for %s",
                       errorString, fileName);
  ilog(L_WARN, "Link editor error: %s for %s", errorString, fileName);
  return;
}

char *dlerror(void)
{
  return(myDlError == NSObjectFileImageSuccess ? NULL : myErrorTable[myDlError % 7]);
}

void *dlopen(char *filename, int unused)
{
  NSObjectFileImage myImage;
  NSModule myModule;

  if (firstLoad)
  {
    /* If we are loading our first symbol (huzzah!) we should go ahead
     * and install link editor error handling!
     */
    NSLinkEditErrorHandlers linkEditorErrorHandlers;

    linkEditorErrorHandlers.undefined = undefinedErrorHandler;
    linkEditorErrorHandlers.multiple  = multipleErrorHandler;
    linkEditorErrorHandlers.linkEdit  = linkEditErrorHandler;
    NSInstallLinkEditErrorHandlers(&linkEditorErrorHandlers);
    firstLoad = FALSE;
  }

  myDlError = NSCreateObjectFileImageFromFile(filename, &myImage);

  if (myDlError != NSObjectFileImageSuccess)
    return(NULL);

  myModule = NSLinkModule(myImage, filename, NSLINKMODULE_OPTION_PRIVATE);
  return((void *)myModule);
}

int dlclose(void *myModule)
{
  NSUnLinkModule(myModule, FALSE);
  return(0);
}

void *dlsym(void *myModule, char *mySymbolName)
{
  NSSymbol mySymbol;

  mySymbol = NSLookupSymbolInModule((NSModule)myModule, mySymbolName);
  return NSAddressOfSymbol(mySymbol);
}
#endif
#endif

/* unload_one_module()
 *
 * inputs	- name of module to unload
 *		- 1 to say modules unloaded, 0 to not
 * output	- 0 if successful, -1 if error
 * side effects	- module is unloaded
 */
int unload_one_module(char *name, int warn)
{
  int modindex;

  if ((modindex = findmodule_byname(name)) == -1) 
    return(-1);

  if (modlist[modindex]->modremove) (*(modlist[modindex]->modremove))();

#ifdef HAVE_SHL_LOAD
    /* shl_* and friends have a slightly different format than dl*. But it does not
     * require creation of a totally new modules.c, instead proper usage of
     * defines solve this case. -TimeMr14C
     */
  shl_unload((shl_t) & (modlist[modindex]->address));
#else
  /* We use FreeBSD's dlfunc(3) interface, or fake it as we
   * used to here if it isn't there.  The interface should
   * be standardised some day, and so it eventually will be
   * providing something guaranteed to do the right thing here.
   *          -jmallett
   */
  dlclose(modlist[modindex]->address);
#endif
  MyFree(modlist[modindex]->name);
  memcpy(&modlist[modindex], &modlist[modindex+1],
         sizeof(struct module) * ((num_mods-1) - modindex));

  if (num_mods != 0)
    num_mods--;

  if (warn == 1)
  {
    ilog(L_INFO, "Module %s unloaded", name);
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s unloaded", name);
  }

  return(0);
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
#ifdef HAVE_SHL_LOAD
  shl_t tmpptr;
#else
  void *tmpptr = NULL;
#endif
  char *mod_basename;
  void (*initfunc)(void) = NULL;
  void (*mod_deinit)(void) = NULL;
  char **verp;
  char *ver;

  mod_basename = basename(path);

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
    ilog (L_WARN, "Error loading module %s: %s", mod_basename, err);
    
    return(-1);
  }

#ifdef HAVE_SHL_LOAD
  if (shl_findsym(&tmpptr, "_modinit", TYPE_UNDEFINED, (void *)&initfunc) == -1)
  {
    if (shl_findsym(&tmpptr, "__modinit", TYPE_UNDEFINED, (void *)&initfunc) == -1)
    {
      ilog (L_WARN, "Module %s has no _modinit() function", mod_basename);
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
      ilog (L_WARN, "Module %s has no _moddeinit() function", mod_basename);
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
  initfunc = (void(*)(void))dlfunc(tmpptr, "_modinit");

  if (initfunc == NULL && (initfunc = (void(*)(void))dlfunc(tmpptr, "__modinit")) == NULL)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s has no _modinit() function",
                         mod_basename);
    ilog (L_WARN, "Module %s has no _modinit() function", mod_basename);
    (void)dlclose (tmpptr);
    return(-1);
  }

  mod_deinit = (void(*)(void))dlfunc(tmpptr, "_moddeinit");

  if (mod_deinit == NULL && (mod_deinit = (void(*)(void))dlfunc(tmpptr, "__moddeinit")) == NULL)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Module %s has no _moddeinit() function",
                         mod_basename);
    ilog (L_WARN, "Module %s has no _moddeinit() function", mod_basename);
    /* blah blah soft error, see above. */
    mod_deinit = NULL;
  }

  verp = (char **)dlsym(tmpptr, "_version");

  if (verp == NULL && (verp = (char **)dlsym(tmpptr, "__version")) == NULL)
    ver = unknown_ver;
  else
    ver = *verp;
#endif

  increase_modlist();

  modlist[num_mods] = MyMalloc(sizeof(struct module));
  modlist[num_mods]->address = tmpptr;
  modlist[num_mods]->version = ver;
  modlist[num_mods]->core    = core;
  modlist[num_mods]->modremove = mod_deinit;
  DupString(modlist[num_mods]->name, mod_basename);
  num_mods++;

  initfunc();

  if (warn == 1)
  {
    sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                         "Module %s [version: %s] loaded at 0x%lx",
                         mod_basename, ver, (unsigned long)tmpptr);
    ilog(L_WARN, "Module %s [version: %s] loaded at 0x%x",
         mod_basename, ver, tmpptr);
  }

  return(0);
}

/* increase_modlist()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- expand the size of modlist if necessary
 */
static void increase_modlist(void)
{
  struct module **new_modlist = NULL;

  if ((num_mods + 1) < max_mods)
    return;

  new_modlist = (struct module **)MyMalloc(sizeof(struct module) *
                                           (max_mods + MODS_INCREMENT));
  memcpy((void *)new_modlist,
         (void *)modlist, sizeof(struct module) * num_mods);

  MyFree(modlist);
  modlist = new_modlist;
  max_mods += MODS_INCREMENT;
}

