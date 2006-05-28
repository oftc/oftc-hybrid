/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_signal.c: responsible for ircd's signal handling
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
#include "common.h"
#include "ircd_signal.h"
#include "ircd.h"         /* dorehash */
#include "restart.h"      /* server_reboot */

/*
 * signal_handler - general handler for ircd signals
 */
static void
signal_handler(int sig)
{
  switch (sig)
  {
    case SIG_DIE:
      server_die("received signal SIGTERM", NO);
    case SIG_RESTART:
      server_die("received signal SIGINT", !server_state.foreground);
    case SIG_REHASH:
      dorehash = 1;
      break;
    case SIG_REMOTD:
      doremotd = 1;
  }
}

#ifndef _WIN32
/*
 * 
 * inputs	- nothing
 * output	- nothing
 * side effects - Reaps zombies periodically
 * -AndroSyn
 */
static void
sigchld_handler(int sig)
{
  int status;
  waitpid(-1, &status, WNOHANG);
}
#endif

/*
 * setup_signals - initialize signal handlers for server
 */
void 
setup_signals(void)
{
#ifdef _WIN32
  dispatch_wm_signal = signal_handler;
#else
  struct sigaction act;

  act.sa_flags = 0;
  act.sa_handler = SIG_IGN;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGPIPE);
  sigaddset(&act.sa_mask, SIGALRM);
#ifdef SIGTRAP
  sigaddset(&act.sa_mask, SIGTRAP);
#endif

#ifdef SIGWINCH
  sigaddset(&act.sa_mask, SIGWINCH);
  sigaction(SIGWINCH, &act, 0);
#endif
  sigaction(SIGPIPE, &act, 0);
#ifdef SIGTRAP
  sigaction(SIGTRAP, &act, 0);
#endif

  act.sa_handler = signal_handler;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIG_REHASH);
  sigaction(SIG_REHASH, &act, 0);

  sigaddset(&act.sa_mask, SIG_RESTART);
  sigaction(SIG_RESTART, &act, 0);

  sigaddset(&act.sa_mask, SIG_DIE);
  sigaction(SIG_DIE, &act, 0);

  sigaddset(&act.sa_mask, SIG_REMOTD);
  sigaction(SIG_REMOTD, &act, 0);

  act.sa_handler = sigchld_handler;
  sigaddset(&act.sa_mask, SIGCHLD);
  sigaction(SIGCHLD, &act, 0);
#endif
}
