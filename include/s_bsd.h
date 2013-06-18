/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_bsd.h: A header for the network subsystem.
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

#ifndef INCLUDED_s_bsd_h
#define INCLUDED_s_bsd_h

#include "fdlist.h"
#include "hook.h"
#include "balloc.h"

/* Type of IO */
#define  COMM_SELECT_READ    1
#define  COMM_SELECT_WRITE   2

/* How long can comm_select() wait for network events [milliseconds] */
#define SELECT_DELAY        500

#define READBUF_SIZE 16384

struct Client;
struct AccessItem;
struct Listener;

IRCD_EXTERN struct Callback *setup_socket_cb;

IRCD_EXTERN BlockHeap *write_req_heap;
IRCD_EXTERN BlockHeap *tcp_handle_heap;
IRCD_EXTERN BlockHeap *udp_handle_heap;
IRCD_EXTERN BlockHeap *udp_send_handle_heap;
IRCD_EXTERN BlockHeap *buffer_heap;

IRCD_EXTERN void add_connection(struct Listener *, struct sockaddr_storage *, 
                           uv_tcp_t *);
IRCD_EXTERN void close_connection(struct Client *);
IRCD_EXTERN void report_error(int, const char *, const char *, uv_err_t);

IRCD_EXTERN int ignoreErrno(int);

IRCD_EXTERN void comm_settimeout(fde_t *, time_t, PF *, void *);
IRCD_EXTERN void comm_setflush(fde_t *, time_t, PF *, void *);
IRCD_EXTERN void comm_checktimeouts(uv_timer_t *, int);
IRCD_EXTERN void comm_connect_tcp(fde_t *, const char *, u_short,
                             struct sockaddr *, int, CNCB *, void *, int, int);
IRCD_EXTERN const char *comm_errstr(int);
IRCD_EXTERN int comm_open(fde_t *, int, int, const char *);
IRCD_EXTERN bool comm_accept(struct Listener *, uv_tcp_t *, 
                        struct sockaddr_storage *);

/* These must be defined in the network IO loop code of your choice */
IRCD_EXTERN void init_netio();
IRCD_EXTERN void comm_setselect(fde_t *, unsigned int, PF *, void *, time_t);
IRCD_EXTERN void init_comm();
IRCD_EXTERN int read_message(time_t, unsigned char);
IRCD_EXTERN void comm_select();
IRCD_EXTERN void check_can_use_v6();
IRCD_EXTERN void remove_ipv6_mapping(struct sockaddr_storage *);

IRCD_EXTERN void string_to_ip(const char *, unsigned int, struct sockaddr_storage *);
IRCD_EXTERN bool ip_to_string(const struct sockaddr_storage *, char *, size_t);

IRCD_EXTERN void ssl_handshake(struct Client *, bool);
IRCD_EXTERN void ssl_flush_write(struct Client *);
IRCD_EXTERN uv_buf_t allocate_uv_buffer(uv_handle_t *, size_t);
IRCD_EXTERN void write_callback(uv_write_t *, int);
IRCD_EXTERN void close_callback(uv_handle_t *);

#endif /* INCLUDED_s_bsd_h */
