/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_bsd_sigio.c: Linux Realtime SIGIO compatible network routines.
 *
 *  Originally by Aaron Sethman <androsyn@ratbox.org>
 *    based upon: s_bsd_poll.c by Adrian Chadd <adrian@creative.net.au>
 *  Copyright (C) 2001-2002 Hybrid Development Team
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

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1           /* Needed for F_SETSIG */
#endif

#include "config.h"
#ifdef USE_SIGIO
#include "stdinc.h"
#include <sys/poll.h>

#include "fdlist.h"
#include "s_bsd.h"
#include "class.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircdauth.h"
#include "ircd.h"
#include "list.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "res.h"
#include "restart.h"
#include "s_auth.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_serv.h"
#include "s_stats.h"
#include "send.h"
#include "s_debug.h"
#include "s_bsd.h"
#include "memory.h"



static int sigio_signal;
static int sigio_is_screwed = 0;        /* We overflowed our sigio queue */
static sigset_t our_sigset;
struct _pollfd_list {
    struct pollfd pollfds[MAXCONNECTIONS];
    int maxindex;               /* highest FD number */
};

typedef struct _pollfd_list pollfd_list_t;

pollfd_list_t pollfd_list;
static void poll_update_pollfds(int, short, PF *);

/* 
 * static void mask_our_signal(int s)
 *
 * Input: Signal to block
 * Output: None
 * Side Effects:  Block the said signal
 */
static void mask_our_signal(int s)
{
    sigemptyset(&our_sigset);
    sigaddset(&our_sigset, s);
    sigaddset(&our_sigset, SIGIO);
    sigprocmask(SIG_BLOCK, &our_sigset, NULL);
}

/*
 * find a spare slot in the fd list. We can optimise this out later!
 *   -- adrian
 */
static inline int poll_findslot(void)
{
    int i;
    for (i = 0; i < MAXCONNECTIONS; i++)
    {
        if (pollfd_list.pollfds[i].fd == -1)
        {
            /* MATCH!!#$*&$ */
            return i;
        }
    }
    assert(1 == 0);
    /* NOTREACHED */
    return -1;
}

/*
 * set and clear entries in the pollfds[] array.
 */
static void poll_update_pollfds(int fd, short event, PF * handler)
{
    fde_t *F = &fd_table[fd];
    int comm_index;

    if (F->comm_index < 0)
    {
        F->comm_index = poll_findslot();
    }
    comm_index = F->comm_index;

    /* Update the events */
    if (handler)
    {
        F->list = FDLIST_IDLECLIENT;
        pollfd_list.pollfds[comm_index].events |= event;
        pollfd_list.pollfds[comm_index].fd = fd;
        /* update maxindex here */
        if (comm_index > pollfd_list.maxindex)
            pollfd_list.maxindex = comm_index;
    } else
    {
        if (comm_index >= 0)
        {
            pollfd_list.pollfds[comm_index].events &= ~event;
            if (pollfd_list.pollfds[comm_index].events == 0)
            {
                pollfd_list.pollfds[comm_index].fd = -1;
                pollfd_list.pollfds[comm_index].revents = 0;
                F->comm_index = -1;
                F->list = FDLIST_NONE;

                /* update pollfd_list.maxindex here */
                if (comm_index == pollfd_list.maxindex)
                { 
                    while (pollfd_list.maxindex >= 0 &&
                           pollfd_list.pollfds[pollfd_list.maxindex].fd == -1)
                        pollfd_list.maxindex--;
                }
            }
        }
    }
}


/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
/* Public functions */


/*
 * void setup_sigio_fd(int fd)
 * 
 * Input: File descriptor
 * Output: None
 * Side Effect: Sets the FD up for SIGIO
 */
void setup_sigio_fd(int fd)
{
    int flags;
    flags = fcntl(fd, F_GETFL, 0);
    flags |= O_ASYNC | O_NONBLOCK;
    fcntl(fd, F_SETFL, flags);
    fcntl(fd, F_SETSIG, sigio_signal);
    fcntl(fd, F_SETOWN, getpid());
}

/*
 * void init_netio(void)
 *
 * Input: None
 * Output: None
 * Side Effects: This is a needed exported function which will 
 *		 be called to initialise the network loop code.
 */
void init_netio(void)
{
    int fd;
    sigio_signal = SIGRTMIN;
    for (fd = 0; fd < MAXCONNECTIONS; fd++)
    {
        pollfd_list.pollfds[fd].fd = -1;
    }
    pollfd_list.maxindex = 0;
    mask_our_signal(sigio_signal);
}

/*
 * comm_setselect
 *
 * This is a needed exported function which will be called to register
 * and deregister interest in a pending IO state for a given FD.
 */
void
comm_setselect(int fd, fdlist_t list, unsigned int type, PF * handler,
               void *client_data, time_t timeout)
{
    fde_t *F = &fd_table[fd];
    assert(fd >= 0);
    assert(F->flags.open);
    if (type & COMM_SELECT_READ)
    {
        F->read_handler = handler;
        F->read_data = client_data;
        poll_update_pollfds(fd, POLLIN, handler);
    }
    if (type & COMM_SELECT_WRITE)
    {
        F->write_handler = handler;
        F->write_data = client_data;
        poll_update_pollfds(fd, POLLOUT, handler);
    }
    if (timeout)
        F->timeout = CurrentTime + (timeout / 1000);
}

/* int comm_select(unsigned long delay)
 * Input: The maximum time to delay.
 * Output: Returns -1 on error, 0 on success.
 * Side-effects: Deregisters future interest in IO and calls the handlers
 *               if an event occurs for an FD.
 * Comments: Check all connections for new connections and input data
 * that is to be processed. Also check for connections with data queued
 * and whether we can write it out.
 * Called to do the new-style IO, courtesy of of squid (like most of this
 * new IO code). This routine handles the stuff we've hidden in
 * comm_setselect and fd_table[] and calls callbacks for IO ready
 * events.
 */
int comm_select(unsigned long delay)
{
    int num = 0;
    int revents = 0;
    int sig;
    int fd;
    int ci;
    PF *hdl;
    fde_t *F;
    struct siginfo si;
    struct timespec timeout;
    timeout.tv_sec = 0;
    timeout.tv_nsec = 1000000 * delay;
    for (;;)
    {
        if (!sigio_is_screwed)
        {
            if ((sig = sigtimedwait(&our_sigset, &si, &timeout)) > 0)
            {
                if (sig == SIGIO)
                {
                    ilog(L_WARN, "Kernel RT Signal queue overflowed.  Is /proc/sys/kernel/rtsig-max too small?");
                    sigio_is_screwed = 1;
                    break;
                }
                fd = si.si_fd;
                pollfd_list.pollfds[fd].revents |= si.si_band;
                revents = pollfd_list.pollfds[fd].revents;
                num++;
                F = &fd_table[fd];
                set_time();
                if (revents & (POLLRDNORM | POLLIN | POLLHUP | POLLERR))
                {
                    callbacks_called++;
                    hdl = F->read_handler;
                    F->read_handler = NULL;
                    poll_update_pollfds(fd, POLLIN, NULL);
                    if (hdl)
                        hdl(fd, F->read_data);
                }
                if (revents & (POLLWRNORM | POLLOUT | POLLHUP | POLLERR))
                {
                    callbacks_called++;
                    hdl = F->write_handler;
                    F->write_handler = NULL;
                    poll_update_pollfds(fd, POLLOUT, NULL);
                    if (hdl)
                        hdl(fd, F->write_data);
                }
            } else
                break;

        } else
            break;
    }
    
    if (!sigio_is_screwed)      /* We don't need to proceed */
    {
        set_time();
        return 0;
    }
    for (;;)
    {
        if (sigio_is_screwed)
        {
            signal(sigio_signal, SIG_IGN);
            signal(sigio_signal, SIG_DFL);
            sigio_is_screwed = 0;
        }
        num = poll(pollfd_list.pollfds, pollfd_list.maxindex + 1, 0);
        if (num >= 0)
            break;
        if (ignoreErrno(errno))
            continue;
        /* error! */
        set_time();
        return -1;
        /* NOTREACHED */
    }

    /* update current time again, eww.. */
    set_time();

    if (num == 0)
        return 0;
    /* XXX we *could* optimise by falling out after doing num fds ... */
    for (ci = 0; ci < pollfd_list.maxindex + 1; ci++)
    {
        if (((revents = pollfd_list.pollfds[ci].revents) == 0) ||
            (pollfd_list.pollfds[ci].fd) == -1)
            continue;
        fd = pollfd_list.pollfds[ci].fd;
        F = &fd_table[fd];
        if (revents & (POLLRDNORM | POLLIN | POLLHUP | POLLERR))
        {
            callbacks_called++;
            hdl = F->read_handler;
            F->read_handler = NULL;
            poll_update_pollfds(fd, POLLIN, NULL);
            if (hdl)
                hdl(fd, F->read_data);
        }
        if (revents & (POLLWRNORM | POLLOUT | POLLHUP | POLLERR))
        {
            callbacks_called++;
            hdl = F->write_handler;
            F->write_handler = NULL;
            poll_update_pollfds(fd, POLLOUT, NULL);
            if (hdl)
                hdl(fd, F->write_data);
        }
    }
    mask_our_signal(sigio_signal);
    return 0;
}

#endif
