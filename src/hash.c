/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hash.c: Maintains hashtables.
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
#include "s_conf.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "resv.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_debug.h"
#include "fdlist.h"
#include "fileio.h"
#include "memory.h"

/* New hash code */
/*
 * Contributed by James L. Davis
 */

static unsigned int hash_channel_name(const char* name);

#ifdef DEBUGMODE
static struct HashEntry* clientTable = NULL;
static struct HashEntry* channelTable = NULL;
static struct HashEntry* idTable = NULL;
static struct HashEntry* resvTable = NULL;
static int clhits;
static int clmiss;
static int chhits;
static int chmiss;
static int rhits;
static int rmiss;
#else

static struct HashEntry clientTable[U_MAX];
static struct HashEntry channelTable[CH_MAX];
static struct HashEntry idTable[U_MAX];
static struct HashEntry resvTable[R_MAX];

#endif

/* XXX move channel hash into channel.c or hash channel stuff in channel.c
 * into here eventually -db
 */
extern BlockHeap *channel_heap;

struct HashEntry hash_get_channel_block(int i)
{
  return channelTable[i];
}

size_t hash_get_channel_table_size(void)
{
  return sizeof(struct HashEntry) * CH_MAX;
}

size_t hash_get_client_table_size(void)
{
  return sizeof(struct HashEntry) * U_MAX;
}

size_t hash_get_resv_table_size(void)
{
  return sizeof(struct HashEntry) * R_MAX;
}

/*
 *
 * look in whowas.c for the missing ...[WW_MAX]; entry
 */

/*
 * Hashing.
 *
 *   The server uses a chained hash table to provide quick and efficient
 * hash table maintenance (providing the hash function works evenly over
 * the input range).  The hash table is thus not susceptible to problems
 * of filling all the buckets or the need to rehash.
 *    It is expected that the hash table would look something like this
 * during use:
 *                   +-----+    +-----+    +-----+   +-----+
 *                ---| 224 |----| 225 |----| 226 |---| 227 |---
 *                   +-----+    +-----+    +-----+   +-----+
 *                      |          |          |
 *                   +-----+    +-----+    +-----+
 *                   |  A  |    |  C  |    |  D  |
 *                   +-----+    +-----+    +-----+
 *                      |
 *                   +-----+
 *                   |  B  |
 *                   +-----+
 *
 * A - GOPbot, B - chang, C - hanuaway, D - *.mu.OZ.AU
 *
 * The order shown above is just one instant of the server. 
 */

static unsigned
int hash_nick_name(const char* name)
{
  unsigned int h = 0;

  while (*name)
    {
      h = (h << 4) - (h + (unsigned char)ToLower(*name++));
    }

  return(h & (U_MAX - 1));
}

/*
 * hash_id
 *
 * IDs are a easy to hash -- they're already evenly distributed,
 * and they are always case sensitive.   -orabidoo
 */
static  unsigned int 
hash_id(const char *nname)
{
	unsigned int h = 0;
	
	while (*nname) {
		h = (h << 4) - (h + (unsigned char)*nname++);
	}

	return (h & (U_MAX - 1));
}
/*
 * hash_channel_name
 *
 * calculate a hash value on at most the first 30 characters of the channel
 * name. Most names are short than this or dissimilar in this range. There
 * is little or no point hashing on a full channel name which maybe 255 chars
 * long.
 */
static unsigned
int hash_channel_name(const char* name)
{
  int i = 30;
  unsigned int h = 0;

  while (*name && --i)
    {
      h = (h << 4) - (h + (unsigned char)ToLower(*name++));
    }

  return (h & (CH_MAX - 1));
}


/*
 * hash_resv_channel()
 *
 * calculate a hash value on at most the first 30 characters and add
 * it to the resv hash
 */
static unsigned
int hash_resv_channel(const char *name)
{
  int i = 30;
  unsigned int h = 0;

  while (*name && --i)
  {
    h = (h << 4) - (h + (unsigned char)ToLower(*name++));
  }

  return (h & (R_MAX -1));
}

/*
 * clear_client_hash_table
 *
 * Nullify the hashtable and its contents so it is completely empty.
 */
static void clear_client_hash_table()
{
#ifdef DEBUGMODE
  clhits = 0;
  clmiss = 0;
  if(!clientTable)
    clientTable = (struct HashEntry*) MyMalloc(U_MAX * sizeof(struct HashEntry));
#endif
  memset(clientTable, 0, sizeof(struct HashEntry) * U_MAX);
}

/*
 * clear_id_hash_table
 *
 * Nullify the hashtable and its contents so it is completely empty.
 */
static void clear_id_hash_table()
{
#ifdef DEBUGMODE
  /* XXX -
   * idhits = 0;
   * idmiss = 0;
   * -cosine
   */
  if(!idTable)
    idTable = (struct HashEntry*) MyMalloc(U_MAX * sizeof(struct HashEntry));
#endif
  memset(idTable, 0, sizeof(struct HashEntry) * U_MAX);
}

static void
clear_channel_hash_table()
{
#ifdef DEBUGMODE
  chmiss = 0;
  chhits = 0;
  if (!channelTable)
    channelTable = (struct HashEntry*) MyMalloc(CH_MAX *
                                                sizeof(struct HashEntry));
#endif
  memset(channelTable, 0, sizeof(struct HashEntry) * CH_MAX);
}

static void
clear_resv_hash_table()
{
#ifdef DEBUGMODE
  rmiss = 0;
  rhits = 0;
  if(!resvTable)
    resvTable = (struct HashEntry*) MyMalloc(R_MAX *
                                             sizeof(struct HashEntry));
#endif
  memset(resvTable, 0, sizeof(struct HashEntry) * R_MAX);
}

void 
init_hash(void)
{
  clear_client_hash_table();
  clear_channel_hash_table();
  clear_id_hash_table();
  clear_resv_hash_table();
}

/*
 * add_to_id_hash_table
 */
int
add_to_id_hash_table(char *name, struct Client *client_p)
{
  unsigned int     hashv;

  hashv = hash_id(name);
  client_p->idhnext = (struct Client *)idTable[hashv].list;
  idTable[hashv].list = (void *)client_p;
  idTable[hashv].links++;
  idTable[hashv].hits++;
  return 0;
}

/*
 * add_to_client_hash_table
 */
void 
add_to_client_hash_table(const char* name, struct Client* client_p)
{
  unsigned int hashv;
  assert(name != NULL);
  assert(client_p != NULL);
  if(name == NULL || client_p == NULL)
    return;
  
  hashv = hash_nick_name(name);
  client_p->hnext = (struct Client*) clientTable[hashv].list;
  clientTable[hashv].list = (void*) client_p;
  ++clientTable[hashv].links;
  ++clientTable[hashv].hits;
}

/*
 * add_to_resv_hash_table
 */
void
add_to_resv_hash_table(const char *name, struct ResvChannel *resv_p)
{
  unsigned int hashv;
  assert(name != NULL);
  assert(resv_p != NULL);
  
  if(name == NULL || resv_p == NULL)
    return;

  hashv = hash_resv_channel(name);

  resv_p->hnext = (struct ResvChannel *) resvTable[hashv].list;
  resvTable[hashv].list = (void*)resv_p;
  ++resvTable[hashv].links;
  ++resvTable[hashv].hits;
}


/*
 * del_from_id_hash_table - remove a client/server from the id
 * hash table
 */
void
del_from_id_hash_table(const char* id, struct Client* client_p)
{
  struct Client* found_client;
  struct Client* prev = NULL;
  unsigned int   hashv;

  assert(id != NULL);
  assert(client_p != NULL);
  
  if(id == NULL || client_p == NULL)
    return;

  hashv = hash_id(id);
  found_client = (struct Client*) idTable[hashv].list;

  for ( ; found_client; found_client = found_client->idhnext)
    {
      if (found_client == client_p)
        {
          if (prev)
            prev->idhnext = found_client->idhnext;
          else
            idTable[hashv].list = (void*) found_client->idhnext;
          found_client->idhnext = NULL;

          assert(idTable[hashv].links > 0);
          if (idTable[hashv].links > 0)
            --idTable[hashv].links;
          return;
        }
      prev = found_client;
    }
  Debug((DEBUG_ERROR, "%#x !in tab %s[%s] %#x %#x %#x %d %d %#x",
         client_p, client_p->name, client_p->from ? client_p->from->host : "??host",
         client_p->from, client_p->next, client_p->prev, client_p->localClient->fd, 
         client_p->status, client_p->user));
}

/*
 * del_from_client_hash_table - remove a client/server from the client
 * hash table
 */
void
del_from_client_hash_table(const char* name, struct Client* client_p)
{
  struct Client* found_client;
  struct Client* prev = NULL;
  unsigned int   hashv;
  assert(name != NULL);
  assert(client_p != NULL);
  
  if(name == NULL || client_p == NULL)
    return;

  hashv = hash_nick_name(name);
  found_client = (struct Client*) clientTable[hashv].list;

  for ( ; found_client; found_client = found_client->hnext)
    {
      if (found_client == client_p)
        {
          if (prev)
            prev->hnext = found_client->hnext;
          else
            clientTable[hashv].list = (void*) found_client->hnext;
          found_client->hnext = NULL;

          assert(clientTable[hashv].links > 0);
          if (clientTable[hashv].links > 0)
            --clientTable[hashv].links;
          return;
        }
      prev = found_client;
    }
  Debug((DEBUG_ERROR, "%#x !in tab %s[%s] %#x %#x %#x %d %d %#x",
         client_p, client_p->name, client_p->from ? client_p->from->host : "??host",
         client_p->from, client_p->next, client_p->prev, client_p->localClient->fd, 
         client_p->status, client_p->user));
}

/*
 * del_from_channel_hash_table
 */
void 
del_from_channel_hash_table(const char* name, struct Channel* chptr)
{
  struct Channel* found_chptr;
  struct Channel* prev = NULL;
  unsigned int    hashv;

#ifdef INVARIANTS
  assert(name != NULL);
  assert(chptr != NULL);
#else
  if(name == NULL || chptr == NULL)
    return;
#endif
    
  hashv = hash_channel_name(name);
  found_chptr = (struct Channel*) channelTable[hashv].list;

  for ( ; found_chptr; found_chptr = found_chptr->hnextch)
    {
      if (found_chptr == chptr)
        {
          if (prev)
            prev->hnextch = found_chptr->hnextch;
          else
            channelTable[hashv].list = (void*) found_chptr->hnextch;
          found_chptr->hnextch = NULL;

          assert(channelTable[hashv].links > 0);
          if (channelTable[hashv].links > 0)
            --channelTable[hashv].links;
          return;
        }
      prev = found_chptr;
    }
}

/*
 * del_from_resv_hash_table()
 */
void 
del_from_resv_hash_table(const char *name, struct ResvChannel *rptr)
{
  struct ResvChannel *found_chptr;
  struct ResvChannel *prev=NULL;
  unsigned int hashv;

  assert(name != NULL);
  assert(rptr != NULL);

  if(name == NULL || rptr == NULL)
    return;
    
  hashv = hash_resv_channel(name);

  found_chptr = (struct ResvChannel *) resvTable[hashv].list;

  for( ; found_chptr; found_chptr = found_chptr->hnext)
  {
    if(found_chptr == rptr)
    {
      if(prev)
        prev->hnext = found_chptr->hnext;
      else
        resvTable[hashv].list = (void*)found_chptr->hnext;

      found_chptr->hnext=NULL;

      assert(resvTable[hashv].links > 0);
      --resvTable[hashv].links;

      return;
    }
  }
}  
 
/*
 * find_id
 */
struct Client *
find_id(const char *name)
{
  struct Client *found_client;
  unsigned int hashv;
	
  if (name == NULL)
    return NULL;

  hashv = hash_id(name);
  found_client = (struct Client *)idTable[hashv].list;

  /*
   * Got the bucket, now search the chain.
   */
  for (; found_client; found_client = found_client->idhnext)
  {
    if (found_client->user && strcmp(name, found_client->user->id) == 0)
    {
      return(found_client);
    }
  }
	
  return (NULL);
}


/*
 * find_client
 *
 * inputs	- name of either server or client
 * output	- pointer to client pointer
 * side effects	- none
 */
struct Client* 
find_client(const char* name)
{
  struct Client* found_client;
  unsigned int   hashv;

  assert(name != NULL);
  if(name == NULL)
    return NULL;

  if (*name == '.') /* it's an ID .. */
    return (find_id(name));

  hashv = hash_nick_name(name);
  found_client = (struct Client*) clientTable[hashv].list;

  for ( ; found_client; found_client = found_client->hnext)
    if (irccmp(name, found_client->name) == 0)
      {
#ifdef DEBUGMODE
        ++clhits;
#endif
        return (found_client);
      }
#ifdef DEBUGMODE
  ++clmiss;
#endif
  
  return (NULL);
}


/*
 * Whats happening in this next loop ? Well, it takes a name like
 * foo.bar.edu and proceeds to earch for *.edu and then *.bar.edu.
 * This is for checking full server names against masks although
 * it isnt often done this way in lieu of using matches().
 *
 * Rewrote to do *.bar.edu first, which is the most likely case,
 * also made const correct
 * --Bleep
 */
static struct Client* 
hash_find_masked_server(const char* name)
{
  char           buf[HOSTLEN + 1];
  char*          p = buf;
  char*          s;
  struct Client* server;

  if ('*' == *name || '.' == *name)
    return 0;

  /*
   * copy the damn thing and be done with it
   */
  strlcpy(buf, name, sizeof(buf));

  while ((s = strchr(p, '.')) != 0)
    {
       *--s = '*';
      /*
       * Dont need to check IsServer() here since nicknames cant
       * have *'s in them anyway.
       */
       if ((server = find_client(s)))
	 return server;
       p = s + 2;
    }
  return 0;
}

/*
 * find_server
 *
 * inputs	- pointer to server name
 * output	- NULL if given name is NULL or
 *		  given server not found
 * side effects	-
 */
struct Client* 
find_server(const char* name)
{
  struct Client* found_server;
  unsigned int   hashv;

  if (name == NULL)
    return(NULL);

  hashv = hash_nick_name(name);
  found_server = (struct Client*) clientTable[hashv].list;

  for ( ; found_server; found_server = found_server->hnext)
    {
      if (!IsServer(found_server) && !IsMe(found_server))
        continue;
      if (irccmp(name, found_server->name) == 0)
        {
#ifdef DEBUGMODE
          ++clhits;
#endif
          return (found_server);
        }
    }
  
#ifndef DEBUGMODE
  return hash_find_masked_server(name);

#else /* DEBUGMODE */
  if (!(found_server = hash_find_masked_server(name)))
    ++clmiss;
  return (found_server);
#endif
}

/*
 * hash_find_channel
 * inputs	- pointer to name
 * output	- 
 * side effects	-
 */
struct Channel* 
hash_find_channel(const char* name)
{
  struct Channel* found_chptr;
  unsigned int hashv;
  
  assert(name != NULL);
  if(name == NULL)
    return NULL;
  hashv = hash_channel_name(name);

  found_chptr = (struct Channel*) channelTable[hashv].list;

  for ( ; found_chptr; found_chptr = found_chptr->hnextch)
  
    if (irccmp(name, found_chptr->chname) == 0)
      {
#ifdef DEBUGMODE
        ++chhits;
#endif
        return(found_chptr);
      }
#ifdef DEBUGMODE
  ++chmiss;
#endif
  return(NULL);
}

/*
 * get_or_create_channel
 * inputs       - client pointer
 *              - channel name
 *              - pointer to int flag whether channel was newly created or not
 * output       - returns channel block or NULL if illegal name
 *		- also modifies *isnew
 *
 *  Get Channel block for chname (and allocate a new channel
 *  block, if it didn't exist before).
 */
struct Channel *
get_or_create_channel(struct Client *client_p, char *chname, int *isnew)
{
  struct Channel *chptr;
  struct Channel *found_chptr;
  unsigned int hashv;
  int len;

  if (BadPtr(chname))
    return NULL;

  len = strlen(chname);
  if (len > CHANNELLEN)
    {
      if (IsServer(client_p))
	{
	  sendto_gnotice_flags(FLAGS_DEBUG, L_OPER, me.name, &me, NULL,
			       "*** Long channel name from %s (%d > %d): %s",
			       client_p->name,
			       len,
			       CHANNELLEN,
			       chname);
	}
      len = CHANNELLEN;
      *(chname + CHANNELLEN) = '\0';
    }

  hashv = hash_channel_name(chname);

  for ( found_chptr = (struct Channel*) channelTable[hashv].list;
	found_chptr; found_chptr = found_chptr->hnextch)
    {
      if (irccmp(chname, found_chptr->chname) == 0)
	{
#ifdef DEBUGMODE
	  ++chhits;
#endif
	  if(isnew != NULL)
	    *isnew = 0;
	  return(found_chptr);
	}
#ifdef DEBUGMODE
      ++chmiss;
#endif
    }

  if(isnew != NULL)
    *isnew = 1;

  chptr = BlockHeapAlloc(channel_heap);
  memset(chptr, 0, sizeof(struct Channel));
  strlcpy(chptr->chname, chname, sizeof(chptr->chname));

  if (GlobalChannelList)
    GlobalChannelList->prevch = chptr;

  chptr->prevch = NULL;
  chptr->nextch = GlobalChannelList;
  GlobalChannelList = chptr;
  chptr->channelts = CurrentTime;     /* doesn't hurt to set it here */

  chptr->hnextch = (struct Channel*) channelTable[hashv].list;
  channelTable[hashv].list = (void*) chptr;
  ++channelTable[hashv].links;
  ++channelTable[hashv].hits;

  Count.chan++;
  return chptr;
}

/*
 * hash_find_resv()
 */
struct ResvChannel *
hash_find_resv(const char *name)
{
  struct ResvChannel *found_chptr;
  unsigned int hashv;

  assert(name != NULL);
  if(name == NULL)
    return NULL;
  hashv = hash_resv_channel(name);

  found_chptr = (struct ResvChannel *) resvTable[hashv].list;

  for( ; found_chptr; found_chptr = found_chptr->hnext)
  {
    if(!irccmp(name, found_chptr->name))
    {
#ifdef DEBUGMODE
      ++rhits;
#endif      
      return(found_chptr);
    }
  }
#ifdef DEBUGMODE
  ++rmiss;
#endif
  
  return(NULL);
}  






