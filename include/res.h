/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  res.h: A header with the DNS functions.
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

#ifndef _RES_H_INCLUDED
#define _RES_H_INCLUDED 1

#include "config.h"
#include "ircd_defs.h"
#include "fileio.h"
#include "adns.h"

#define DNS_BLOCK_SIZE 64

struct DNSQuery {
	void *ptr;
	adns_query query;
	adns_answer answer;
	void (*callback)(void* vptr, adns_answer *reply);
};

void init_resolver(void);
void restart_resolver(void);
void timeout_adns (void * );
void dns_writeable (int fd , void *ptr );
void dns_readable (int fd , void *ptr );
void dns_do_callbacks(void);
void dns_select (void);
void adns_gethost (const char *name , int aftype , struct DNSQuery *req );
void adns_getaddr (struct irc_inaddr *addr , int aftype , struct DNSQuery *req );
void delete_adns_queries(struct DNSQuery *q);
void report_adns_servers(struct Client *);
#endif
