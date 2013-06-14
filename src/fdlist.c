/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  fdlist.c: Maintains a list of file descriptors.
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
#include "list.h"
#include "fdlist.h"
#include "client.h"  /* struct Client */
#include "event.h"
#include "ircd.h"    /* GlobalSetOptions */
#include "irc_string.h"
#include "s_bsd.h"  
#include "conf.h"  /* ServerInfo */
#include "send.h"
#include "memory.h"
#include "numeric.h"
#include "s_misc.h"
#include "irc_res.h"
#include "log.h"

dlink_list fd_list = { 0 };
int number_fd = LEAKED_FDS;
int hard_fdlimit = 0;

static int
set_fdlimit()
{
  int fdmax;
  struct rlimit limit;

  if (!getrlimit(RLIMIT_NOFILE, &limit))
  {
    limit.rlim_cur = limit.rlim_max;
    setrlimit(RLIMIT_NOFILE, &limit);
  }

  fdmax = getdtablesize();

  /* allow MAXCLIENTS_MIN clients even at the cost of MAX_BUFFER and
   * some not really LEAKED_FDS */
  fdmax = IRCD_MAX(fdmax, LEAKED_FDS + MAX_BUFFER + MAXCLIENTS_MIN);

  /* under no condition shall this raise over 65536
   * for example user ip heap is sized 2*hard_fdlimit */
  hard_fdlimit = IRCD_MIN(fdmax, 65536);

  return -1;
}

void
fdlist_init()
{
  set_fdlimit();
}

/* Called to open a given filedescriptor */
void
fd_open(fde_t *F, uv_stream_t *handle, const char *desc)
{
  F->handle = handle;
  F->comm_index = -1;

  if (desc != NULL)
    strlcpy(F->desc, desc, sizeof(F->desc));

  /* Note: normally we'd have to clear the other flags,
   * but currently F is always cleared before calling us.. */
  F->flags.open = 1;

  dlinkAdd(F, &F->fnode, &fd_list);

  number_fd++;
}

/* Called to close a given filedescriptor */
void
fd_close(fde_t *F)
{
  delete_resolver_queries(F);

#ifdef HAVE_LIBCRYPTO

  if (F->ssl)
    SSL_free(F->ssl);

#endif

  dlinkDelete(&F->fnode, &fd_list);

  uv_close((uv_handle_t*)F->handle, NULL);
  number_fd--;

  MyFree(F->handle);

  memset(F, 0, sizeof(fde_t));
}

/*
 * fd_dump() - dump the list of active filedescriptors
 */
void
fd_dump(struct Client *source_p)
{
  fde_t *F;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, fd_list.head)
  {
    F = ptr->data;
    sendto_one(source_p, ":%s %d %s :fd %-5d desc '%s'",
               me.name, RPL_STATSDEBUG, source_p->name,
               F->handle->io_watcher.fd, F->desc);
  }
}

/*
 * fd_note() - set the fd note
 *
 * Note: must be careful not to overflow fd_table[fd].desc when
 *       calling.
 */
void
fd_note(fde_t *F, const char *format, ...)
{
  va_list args;

  if (format != NULL)
  {
    va_start(args, format);
    vsnprintf(F->desc, sizeof(F->desc), format, args);
    va_end(args);
  }
  else
    F->desc[0] = '\0';
}

/* Make sure stdio descriptors (0-2) and profiler descriptor (3)
 * always go somewhere harmless.  Use -foreground for profiling
 * or executing from gdb */
void
close_standard_fds()
{
  int i;

  for (i = 0; i < LOWEST_SAFE_FD; i++)
  {
    close(i);

    if (open("/dev/null", O_RDWR) < 0)
      exit(-1); /* we're hosed if we can't even open /dev/null */
  }
}

void
close_fds(fde_t *one)
{
  fde_t *F;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, fd_list.head)
  {
    F = ptr->data;
    if (F != one)
      uv_close((uv_handle_t *)&F->handle, NULL);
  }
}
