/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  restart.c: Functions to allow the ircd to restart.
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
#include "tools.h"
#include "restart.h"
#include "common.h"
#include "fdlist.h"
#include "ircd.h"
#include "send.h"
#include "s_log.h"
#include "client.h" /* for UMODE_ALL */
#include "memory.h"


void
restart(const char *mesg)
{
  static int was_here = 0; /* redundant due to restarting flag below */

  if (was_here)
    abort();
  was_here = 1;

  ilog(L_NOTICE, "Restarting Server because: %s, memory data limit: %ld",
       mesg, get_maxrss());

  server_reboot();
}

void
server_reboot(void)
{
  int i;

  sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                       "Restarting server...");

  ilog(L_NOTICE, "Restarting server... (%s)", SPATH);
  send_queued_all();

  for (i = 3; i < HARD_FDLIMIT; ++i)
    close(i);

  unlink(pidFileName);
  execv(SPATH, myargv);
  fprintf(stderr, "ircd: execv() failed: %s\n",
          strerror(errno));
  exit(-1);
}

