/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hash.h: A header for the ircd hashtable code.
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

#ifndef INCLUDED_hash_h
#define INCLUDED_hash_h

/* 
 * Client hash table size
 *
 * used in hash.c, s_debug.c
 */
#define U_MAX 65536

/* 
 * Channel hash table size
 *
 * used in hash.c, s_debug.c
 */
#define CH_MAX 16384

/*
 * RESV hash table size
 *
 * used in hash.c
 */
#define R_MAX 1024

struct Client;
struct Channel;
struct ResvChannel;

struct HashEntry {
  int    hits;
  int    links;
  void*  list;
};

struct Client *find_id(const char *name);
extern int add_to_id_hash_table(char *, struct Client *);
extern struct HashEntry hash_get_channel_block(int i);

extern struct Channel
*get_or_create_channel(struct Client *client_p, char *chname, int *isnew);

extern size_t hash_get_client_table_size(void);
extern size_t hash_get_channel_table_size(void);
extern size_t hash_get_resv_table_size(void);

extern void   init_hash(void);
extern void   add_to_client_hash_table(const char* name, 
                                       struct Client* client);
extern void   del_from_client_hash_table(const char* name, 
                                         struct Client* client);
extern void   del_from_id_hash_table(const char *name, struct Client *client);
extern void   del_from_channel_hash_table(const char* name, 
                                          struct Channel* chan);
extern struct Channel* hash_find_channel(const char* name);
extern struct Client* find_client(const char* name);
extern struct Client* find_server(const char* name);
extern struct Client* hash_find_server(const char* name);

extern void add_to_resv_hash_table(const char *name,
                                   struct ResvChannel *resv_p);
extern void del_from_resv_hash_table(const char *name,
                                     struct ResvChannel *resv_p);
extern struct ResvChannel *hash_find_resv(const char *name);

#endif  /* INCLUDED_hash_h */



