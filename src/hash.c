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
#include "handlers.h"
#include "list.h"
#include "modules.h"
#include "hash.h"
#include "resv.h"
#include "userhost.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "memory.h"
#include "dbuf.h"

/* XXX ZZZ for "safe_list" *ugh* */
#include "channel.h"
#include "channel_mode.h"

extern BlockHeap *channel_heap;
static BlockHeap *userhost_heap;
static BlockHeap *namehost_heap;
static struct UserHost *find_or_add_userhost(const char *host);


/* Hash alghoritm based on ircu 2.10 implementation by Andrea Cocito "Nemesi" */

/* This hash function returns *exactly* N%HASHSIZE, where 'N'
 * is the string itself (included the trailing '\0') seen as 
 * a baseHASHSHIFT number whose "digits" are the bytes of the
 * number mapped through a "weight" transformation that gives
 * the same "weight" to caseless-equal chars, example:
 *
 * Hashing the string "Nick\0" the result will be:
 * N  i  c  k \0
 * |  |  |  |  `--->  ( (hash_weight('\0') * (HASHSHIFT**0) +
 * |  |  |  `------>    (hash_weight('k')  * (HASHSHIFT**1) +
 * |  |  `--------->    (hash_weight('c')  * (HASHSHIFT**2) +
 * |  `------------>    (hash_weight('i')  * (HASHSHIFT**3) +
 * `--------------->    (hash_weight('N')  * (HASHSHIFT**4)   ) % HASHSIZE
 *
 * It's actually a lot similar to a base transformation of the
 * text representation of an integer.
 * Looking at it this way seems slow and requiring unlimited integer
 * precision, but we actually do it with a *very* fast loop, using only 
 * short integer arithmetic and by means of two memory accesses and 
 * 3 additions per each byte processed.. and nothing else, as a side
 * note the distribution of real nicks over the hash table of this
 * function is about 3 times better than the previous one, and the
 * hash function itself is about 25% faster with a "normal" HASHSIZE
 * (it gets slower with larger ones and faster for smallest ones
 * because the hash table size affect the size of some maps and thus
 * the effectiveness of RAM caches while accesing them).
 */

/* The first prime bigger than the maximum character code (255) */
#define HASHSHIFT 257

#define HASHMAPSIZE (HASHSIZE + HASHSHIFT + 1)

/* Static memory structures */

/* We need a first function that, given an integer h between 0 and
 * HASHSIZE+HASHSHIFT, returns ( (h * HASHSHIFT) % HASHSIZE ) )
 * We'll map this function in this table
 */
static unsigned int hash_map[HASHMAPSIZE];

/* Then we need a second function that "maps" a char to its weitgh,
 * changed to a table this one too, with this macro we can use a char
 * as index and not care if it is signed or not, no.. this will not
 * cause an addition to take place at each access, trust me, the
 * optimizer takes it out of the actual code and passes "label+shift"
 * to the linker, and the linker does the addition :)
 */
static unsigned int hash_weight_table[CHAR_MAX - CHAR_MIN + 1];
#define hash_weight(ch) hash_weight_table[ch - CHAR_MIN]

/* The actual hash tables, both MUST be of the same HASHSIZE, variable
 * size tables could be supported but the rehash routine should also
 * rebuild the transformation maps, I kept the tables of equal size 
 * so that I can use one hash function and one transformation map
 */
static struct Client *idTable[HASHSIZE];
static struct Client *clientTable[HASHSIZE];
static struct Channel *channelTable[HASHSIZE];
static struct UserHost *userhostTable[HASHSIZE];
static struct ResvChannel *resvchannelTable[HASHSIZE];


/* init_hash()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - Initialize the maps used by hash
 *                functions and clear the tables
 */
void
init_hash(void)
{
  int i, weight_key;
  unsigned long l;
  unsigned long m;

  /* Default the userhost/namehost sizes to CLIENT_HEAP_SIZE for now,
   * should be a good close approximation anyway
   * - Dianora
   */
  userhost_heap = BlockHeapCreate(sizeof(struct UserHost), CLIENT_HEAP_SIZE);
  namehost_heap = BlockHeapCreate(sizeof(struct NameHost), CLIENT_HEAP_SIZE);

  weight_key = random() % 256;  /* better than nothing --adx */

  /* Here is to what we "map" a char before working on it */
  for (i = CHAR_MIN; i <= CHAR_MAX; i++)
    hash_weight(i) = ((unsigned int) ToLower(i)) ^ weight_key;

  /* Clear the hash tables first */
  for (l = 0; l < HASHSIZE; l++)
  {
    idTable[l]          = NULL;
    clientTable[l]      = NULL;
    channelTable[l]     = NULL;
    userhostTable[l]    = NULL;
    resvchannelTable[l] = NULL;
  }

  /* And this is our hash-loop "transformation" function, 
   * basically it will be hash_map[x] == ((x*HASHSHIFT)%HASHSIZE)
   * defined for 0<=x<=(HASHSIZE+HASHSHIFT)
   */
  for (m = 0; m < (unsigned long) HASHMAPSIZE; m++)
  {
    l = m;
    l *= (unsigned long) HASHSHIFT;
    l &= HASHSIZE - 1;
    hash_map[m] = (unsigned int) l;
  }
}

/* These are the actual hash functions, since they are static
 * and very short any decent compiler at a good optimization level
 * WILL inline these in the following functions
 */

static unsigned int
strhash(const char *n)
{
  unsigned int hash = 0;

  while (*n != '\0')
    hash = hash_map[hash + hash_weight(*n++)];

  return(hash);
}

/************************** Externally visible functions ********************/

/* Optimization note: in these functions I supposed that the CSE optimization
 * (Common Subexpression Elimination) does its work decently, this means that
 * I avoided introducing new variables to do the work myself and I did let
 * the optimizer play with more free registers, actual tests proved this
 * solution to be faster than doing things like tmp2=tmp->hnext... and then
 * use tmp2 myself which would have given less freedom to the optimizer.
 */

/* hash_add_client()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Adds a client's name in the proper hash linked
 *                list, can't fail, client_p must have a non-null
 *                name or expect a coredump, the name is infact
 *                taken from client_p->name
 */
void
hash_add_client(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->name);

  client_p->hnext = clientTable[hashv];
  clientTable[hashv] = client_p;
}

/* hash_add_channel()
 *
 * inputs       - pointer to channel
 * output       - NONE
 * side effects - Adds a channel's name in the proper hash linked
 *                list, can't fail. chptr must have a non-null name
 *                or expect a coredump. As before the name is taken
 *                from chptr->name, we do hash its entire lenght
 *                since this proved to be statistically faster
 */
void
hash_add_channel(struct Channel *chptr)
{
  unsigned int hashv = strhash(chptr->chname);

  chptr->hnextch = channelTable[hashv];
  channelTable[hashv] = chptr;
}

void
hash_add_resv(struct ResvChannel *chptr)
{
  unsigned int hashv = strhash(chptr->name);

  chptr->hnext = resvchannelTable[hashv];
  resvchannelTable[hashv] = chptr;
}

void
hash_add_userhost(struct UserHost *userhost)
{
  unsigned int hashv = strhash(userhost->host);

  userhost->next = userhostTable[hashv];
  userhostTable[hashv] = userhost;
}

void
hash_add_id(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->id);

  client_p->idhnext = idTable[hashv];
  idTable[hashv] = client_p;
}

/* hash_del_id()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes an ID from the hash linked list
 */
void
hash_del_id(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->id);
  struct Client *tmp = idTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == client_p)
    {
      idTable[hashv] = client_p->idhnext;
      client_p->idhnext = client_p;
    }
    else
    {
      while (tmp->idhnext != client_p)
      {
        if ((tmp = tmp->idhnext) == NULL)
          return;
      }

      tmp->idhnext = tmp->idhnext->idhnext;
      client_p->idhnext = client_p;
    }
  }
}

/* hash_del_client()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes a Client's name from the hash linked list
 */
void
hash_del_client(struct Client *client_p)
{
  unsigned int hashv = strhash(client_p->name);
  struct Client *tmp = clientTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == client_p)
    {
      clientTable[hashv] = client_p->hnext;
      client_p->hnext = client_p;
    }
    else
    {
      while (tmp->hnext != client_p)
      {
        if ((tmp = tmp->hnext) == NULL)
          return;
      }

      tmp->hnext = tmp->hnext->hnext;
      client_p->hnext = client_p;
    }
  }
}

/* hash_del_userhost()
 *
 * inputs       - pointer to userhost
 * output       - NONE
 * side effects - Removes a userhost from the hash linked list
 */
void
hash_del_userhost(struct UserHost *userhost)
{
  unsigned int hashv = strhash(userhost->host);
  struct UserHost *tmp = userhostTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == userhost)
    {
      userhostTable[hashv] = userhost->next;
      userhost->next = userhost;
    }
    else
    {
      while (tmp->next != userhost)
      {
        if ((tmp = tmp->next) == NULL)
          return;
      }

      tmp->next = tmp->next->next;
      userhost->next = userhost;
    }
  }
}

/* hash_del_channel()
 *
 * inputs       - pointer to client
 * output       - NONE
 * side effects - Removes the channel's name from the corresponding
 *                hash linked list
 */
void
hash_del_channel(struct Channel *chptr)
{
  unsigned int hashv = strhash(chptr->chname);
  struct Channel *tmp = channelTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == chptr)
    {
      channelTable[hashv] = chptr->hnextch;
      chptr->hnextch = chptr;
    }
    else
    {
      while (tmp->hnextch != chptr)
      {
        if ((tmp = tmp->hnextch) == NULL)
          return;
      }

      tmp->hnextch = tmp->hnextch->hnextch;
      chptr->hnextch = chptr;
    }
  }
}

void
hash_del_resv(struct ResvChannel *chptr)
{
  unsigned int hashv = strhash(chptr->name);
  struct ResvChannel *tmp = resvchannelTable[hashv];

  if (tmp != NULL)
  {
    if (tmp == chptr)
    {
      resvchannelTable[hashv] = chptr->hnext;
      chptr->hnext = chptr;
    }
    else
    {
      while (tmp->hnext != chptr)
      {
        if ((tmp = tmp->hnext) == NULL)
          return;
      }

      tmp->hnext = tmp->hnext->hnext;
      chptr->hnext = chptr;
    }
  }
}

/* find_client()
 *
 * inputs       - pointer to name
 * output       - NONE
 * side effects - New semantics: finds a client whose name is 'name'
 *                if can't find one returns NULL. If it finds one moves
 *                it to the top of the list and returns it.
 */
struct Client *
find_client(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Client *client_p;

  if ((client_p = clientTable[hashv]) != NULL)
  {
    if (irccmp(name, client_p->name))
    {
      struct Client *prev;

      while (prev = client_p, (client_p = client_p->hnext) != NULL)
      {
        if (!irccmp(name, client_p->name))
        {
          prev->hnext = client_p->hnext;
          client_p->hnext = clientTable[hashv];
          clientTable[hashv] = client_p;
          break;
        }
      }
    }
  }

  return(client_p);
}

struct Client *
hash_find_id(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Client *client_p;

  if ((client_p = idTable[hashv]) != NULL)
  {
    if (irccmp(name, client_p->id))
    {
      struct Client *prev;

      while (prev = client_p, (client_p = client_p->idhnext) != NULL)
      {
        if (!irccmp(name, client_p->id))
        {
          prev->idhnext = client_p->idhnext;
          client_p->idhnext = idTable[hashv];
          idTable[hashv] = client_p;
          break;
        }
      }
    }
  }

  return(client_p);
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
static struct Client *
hash_find_masked_server(const char *name)
{
  char buf[HOSTLEN + 1];
  char *p = buf;
  char *s;
  struct Client* server;

  if ('*' == *name || '.' == *name)
    return(NULL);

  /*
   * copy the damn thing and be done with it
   */
  strlcpy(buf, name, sizeof(buf));

  while ((s = strchr(p, '.')) != NULL)
  {
    *--s = '*';

    /* Dont need to check IsServer() here since nicknames cant
     * have *'s in them anyway.
     */
    if ((server = find_client(s)) != NULL)
      return(server);
    p = s + 2;
  }

  return(NULL);
}

struct Client *
find_server(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Client *client_p;

  if ((client_p = clientTable[hashv]) != NULL)
  {
    if ((!IsServer(client_p) && !IsMe(client_p)) ||
        irccmp(name, client_p->name))
    {
      struct Client *prev;

      while (prev = client_p, (client_p = client_p->hnext) != NULL)
      {
        if ((IsServer(client_p) || IsMe(client_p)) &&
            !irccmp(name, client_p->name))
        {
          prev->hnext = client_p->hnext;
          client_p->hnext = clientTable[hashv];
          clientTable[hashv] = client_p;
          break;
        }
      }
    }
  }

  return((client_p != NULL) ? client_p : hash_find_masked_server(name));
}

/* hash_find_channel()
 *
 * inputs       - pointer to name
 * output       - NONE
 * side effects - New semantics: finds a channel whose name is 'name', 
 *                if can't find one returns NULL, if can find it moves
 *                it to the top of the list and returns it.
 */
struct Channel *
hash_find_channel(const char *name)
{
  unsigned int hashv = strhash(name);
  struct Channel *chptr;

  if ((chptr = channelTable[hashv]) != NULL)
  {
    if (irccmp(name, chptr->chname))
    {
      struct Channel *prev;

      while (prev = chptr, (chptr = chptr->hnextch) != NULL)
      {
        if (!irccmp(name, chptr->chname))
        {
          prev->hnextch = chptr->hnextch;
          chptr->hnextch = channelTable[hashv];
          channelTable[hashv] = chptr;
          break;
        }
      }
    }
  }

  return(chptr);
}

/* hash_find_resv()
 *
 * inputs       - pointer to name
 * output       - NONE
 * side effects - New semantics: finds a reserved channel whose name is 'name',
 *                if can't find one returns NULL, if can find it moves
 *                it to the top of the list and returns it.
 */
struct ResvChannel *
hash_find_resv(const char *name)
{
  unsigned int hashv = strhash(name);
  struct ResvChannel *chptr;

  if ((chptr = resvchannelTable[hashv]) != NULL)
  {
    if (irccmp(name, chptr->name))
    {
      struct ResvChannel *prev;

      while (prev = chptr, (chptr = chptr->hnext) != NULL)
      {
        if (!irccmp(name, chptr->name))
        {
          prev->hnext = chptr->hnext;
          chptr->hnext = resvchannelTable[hashv];
          resvchannelTable[hashv] = chptr;
          break;
        }
      }
    }
  }

  return(chptr);
}

struct UserHost *
hash_find_userhost(const char *host)
{
  unsigned int hashv = strhash(host);
  struct UserHost *userhost;

  if ((userhost = userhostTable[hashv]))
  {
    if (irccmp(host, userhost->host))
    {
      struct UserHost *prev;

      while (prev = userhost, (userhost = userhost->next) != NULL)
      {
        if (!irccmp(host, userhost->host))
        {
          prev->next = userhost->next;
          userhost->next = userhostTable[hashv];
          userhostTable[hashv] = userhost;
          break;
        }
      }
    }
  }

  return(userhost);
}

/* get_or_create_channel()
 *
 * inputs       - client pointer
 *              - channel name
 *              - pointer to int flag whether channel was newly created or not
 * output       - returns channel block or NULL if illegal name
 *		- also modifies *isnew
 * side effects - Get Channel block for chname (and allocate a new channel
 *                block, if it didn't exist before).
 */
struct Channel *
get_or_create_channel(struct Client *client_p, char *chname, int *isnew)
{
  struct Channel *chptr;
  int len;

  if (EmptyString(chname))
    return(NULL);

  len = strlen(chname);

  if (len > CHANNELLEN)
  {
    if (IsServer(client_p))
    {
      sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL,
			   "*** Long channel name from %s (%d > %d): %s",
                           client_p->name, len, CHANNELLEN, chname);
    }

    len = CHANNELLEN;
    *(chname + CHANNELLEN) = '\0';
  }

  if ((chptr = hash_find_channel(chname)) != NULL)
  {
    if (isnew != NULL)
      *isnew = 0;

    return(chptr);
  }

  if (isnew != NULL)
    *isnew = 1;

  chptr = BlockHeapAlloc(channel_heap);
  memset(chptr, 0, sizeof(struct Channel));
  strlcpy(chptr->chname, chname, sizeof(chptr->chname));
  dlinkAdd(chptr, &chptr->node, &global_channel_list);
  chptr->channelts = CurrentTime; /* doesn't hurt to set it here */
  hash_add_channel(chptr);
  if(MyClient(client_p))
          sendto_gnotice_flags(UMODE_SPY, L_ALL, me.name, &me, NULL,
              "Channel %s created by %s!%s@%s", chname, client_p->name,
              client_p->username, client_p->host);

  return(chptr);
}

/* count_user_host()
 *
 * inputs	- user name
 *		- hostname
 *		- int flag 1 if global, 0 if local
 * 		- pointer to where global count should go
 *		- pointer to where local count should go
 *		- pointer to where identd count should go (local clients only)
 * output	- none
 * side effects	-
 */
void
count_user_host(const char *user, const char *host, int *global_p,
                int *local_p, int *icount_p)
{
  dlink_node *ptr;
  struct UserHost *found_userhost;
  struct NameHost *nameh;

  if ((found_userhost = hash_find_userhost(host)) == NULL)
    return;

  DLINK_FOREACH(ptr, found_userhost->list.head)
  {
    nameh = ptr->data;

    if (!irccmp(user, nameh->name))
    {
      if (global_p != NULL)
        *global_p = nameh->gcount;
      if (local_p != NULL)
        *local_p  = nameh->lcount;
      if (icount_p != NULL)
        *icount_p = nameh->icount;
      return;
    }
  }
}

/* add_user_host()
 *
 * inputs	- user name
 *		- hostname
 *		- int flag 1 if global, 0 if local
 * output	- none
 * side effects	- add given user@host to hash tables
 */
void
add_user_host(char *user, const char *host, int global)
{
  dlink_node *ptr;
  struct UserHost *found_userhost;
  struct NameHost *nameh;
  int hasident = 1;

  if (*user == '~')
  {
    hasident = 0;
    user++;
  }

  if ((found_userhost = find_or_add_userhost(host)) == NULL)
    return;

  DLINK_FOREACH(ptr, found_userhost->list.head)
  {
    nameh = ptr->data;

    if (!irccmp(user, nameh->name))
    {
      if (global)
	nameh->gcount++;
      else
      {
	if (hasident)
	  nameh->icount++;
	nameh->lcount++;
      }
      return;
    }
  }

  nameh = BlockHeapAlloc(namehost_heap);
  strlcpy(nameh->name, user, sizeof(nameh->name));

  if (global)
    nameh->gcount = 1;
  else
  {
    if (hasident)
      nameh->icount = 1;
    nameh->lcount = 1;
  }

  dlinkAdd(nameh, &nameh->node, &found_userhost->list);
}

/* delete_user_host()
 *
 * inputs	- user name
 *		- hostname
 *		- int flag 1 if global, 0 if local
 * output	- none
 * side effects	- delete given user@host to hash tables
 */
void
delete_user_host(char *user, const char *host, int global)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct UserHost *found_userhost;
  struct NameHost *nameh;
  int hasident = 1;

  if (*user == '~')
  {
    hasident = 0;
    user++;
  }

  if ((found_userhost = hash_find_userhost(host)) == NULL)
    return;

  DLINK_FOREACH_SAFE(ptr, next_ptr, found_userhost->list.head)
  {
    nameh = ptr->data;

    if (!irccmp(user, nameh->name))
    {
      if (global)
      {
	if (nameh->gcount > 0)
	  nameh->gcount--;
      }
      else
      {
	if (nameh->lcount > 0)
	  nameh->lcount--;
	if (hasident && (nameh->icount > 0))
	  nameh->icount--;
      }
      if ((nameh->gcount == 0) && (nameh->lcount == 0))
      {
	dlinkDelete(&nameh->node, &found_userhost->list);
	BlockHeapFree(namehost_heap, nameh);
      }
      if (dlink_list_length(&found_userhost->list) == 0)
      {
	hash_del_userhost(found_userhost);
	BlockHeapFree(userhost_heap, found_userhost);
      }
      return;
    }
  }
}

/* find_or_add_userhost()
 *
 * inputs	- host name
 * output	- none
 * side effects	- find UserHost * for given host name
 */
static struct UserHost *
find_or_add_userhost(const char *host)
{
  struct UserHost *userhost;

  if ((userhost = hash_find_userhost(host)) != NULL)
    return(userhost);

  userhost = BlockHeapAlloc(userhost_heap);
  memset(userhost, 0, sizeof(struct UserHost));
  strlcpy(userhost->host, host, sizeof(userhost->host));
  hash_add_userhost(userhost);

  return(userhost);
}

struct Message hash_msgtab = {
 "HASH", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, mo_hash, m_ignore }
};

/* I will add some useful(?) statistics here one of these days,
 * but not for DEBUGMODE: just to let the admins play with it,
 * coders are able to SIGCORE the server and look into what goes
 * on themselves :-)
 */
void
mo_hash(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  int i;
  int max_chain = 0;
  int buckets   = 0;
  int count     = 0;
  struct Client *cl;
  struct Client *icl;
  struct Channel *ch;
  struct UserHost *ush;
  struct ResvChannel *rch;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((cl = clientTable[i]) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; cl != NULL; cl = cl->hnext)
        ++len; 
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Client: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((ch = channelTable[i]) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; ch != NULL; ch = ch->hnextch)
        ++len; 
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Channel: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((rch = resvchannelTable[i]) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; rch != NULL; rch = rch->hnext)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Resv: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((icl = idTable[i]) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; icl != NULL; icl = icl->idhnext)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :Id: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);

  count     = 0;
  buckets   = 0;
  max_chain = 0;

  for (i = 0; i < HASHSIZE; ++i)
  {
    if ((ush = userhostTable[i]) != NULL)
    {
      int len = 0;

      ++buckets;
      for (; ush != NULL; ush = ush->next)
        ++len;
      if (len > max_chain)
        max_chain = len;
      count += len;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :UserHost: entries: %d buckets: %d "
             "max chain: %d", me.name, source_p->name, count, buckets,
             max_chain);
}

/*
 * Safe list code.
 *
 * The idea is really quite simple. As the link lists pointed to in
 * each "bucket" of the channel hash table are traversed atomically
 * there is no locking needed. Overall, yes, inconsistent reported
 * state can still happen, but normally this isn't a big deal.
 * I don't like sticking the code into hash.c but oh well. Moreover,
 * if a hash isn't used in future, oops.
 *
 * - Dianora
 */

/* exceeding_sendq()
 *
 * inputs       - pointer to client to check
 * ouput	- 1 if client is in danger of blowing its sendq
 *		  0 if it is not.
 * side effects -
 *
 * Sendq limit is fairly conservative at 1/2 (In original anyway)
 */
static int
exceeding_sendq(struct Client *to)
{
  if (dbuf_length(&to->localClient->buf_sendq) > (get_sendq(to) / 2))
    return(1);
  else
    return(0);
}

void
free_list_task(struct ListTask *lt, struct Client *source_p)
{
  dlink_node *dl, *dln;

  DLINK_FOREACH_SAFE(dl, dln, lt->show_mask.head)
  {
    MyFree(dl->data);
    free_dlink_node(dl);
  }

  DLINK_FOREACH_SAFE(dl, dln, lt->hide_mask.head)
  {
    MyFree(dl->data);
    free_dlink_node(dl);
  }

  MyFree(lt);

  if (MyConnect(source_p))
    source_p->localClient->list_task = NULL;
}

/* list_allow_channel()
 *
 * inputs       - channel name
 *              - pointer to a list task
 * output       - 1 if the channel is to be displayed
 *                0 otherwise
 * side effects -
 */
static int
list_allow_channel(const char *chname, struct ListTask *lt)
{
  dlink_node *dl;

  DLINK_FOREACH(dl, lt->show_mask.head)
    if (!match(dl->data, chname))
      return(0);

  DLINK_FOREACH(dl, lt->hide_mask.head)
    if (match(dl->data, chname))
      return(0);

  return(1);
}

/* list_one_channel()
 *
 * inputs       - client pointer to return result to
 *              - pointer to channel to list
 *              - pointer to ListTask structure
 * ouput	- none
 * side effects -
 */
static void
list_one_channel(struct Client *source_p, struct Channel *chptr,
                 struct ListTask *list_task, int remote_request)
{
  if ((remote_request && chptr->chname[0] == '&') ||
      (SecretChannel(chptr) && !IsMember(source_p, chptr)))
    return;
  if ((unsigned int)dlink_list_length(&chptr->members) < list_task->users_min ||
      (unsigned int)dlink_list_length(&chptr->members) > list_task->users_max ||
      (chptr->channelts != 0 &&
       ((unsigned int)chptr->channelts < list_task->created_min ||
        (unsigned int)chptr->channelts > list_task->created_max)) ||
      (unsigned int)chptr->topic_time < list_task->topicts_min ||
      (chptr->topic_time ? (unsigned int)chptr->topic_time : UINT_MAX) >
      list_task->topicts_max)
    return;

  if (!list_allow_channel(chptr->chname, list_task))
  {
    char *maskchan;
    if(!IsGod(source_p))
      return;
    
    maskchan = MyMalloc(strlen(chptr->chname)+2);
    snprintf(maskchan, (strlen(chptr->chname)+2), "%%%s", chptr->chname);
    
    sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
            maskchan, dlink_list_length(&chptr->members), chptr->topic == NULL ?
            "" : chptr->topic);
    MyFree(maskchan);
  }
  else
    sendto_one(source_p, form_str(RPL_LIST), me.name, source_p->name,
               chptr->chname, dlink_list_length(&chptr->members),
               chptr->topic == NULL ? "" : chptr->topic);
}

/* safe_list_channels()
 *
 * inputs	- pointer to client requesting list
 * output	- 0/1
 * side effects	- safely list all channels to source_p
 *
 * Walk the channel buckets, ensure all pointers in a bucket are
 * traversed before blocking on a sendq. This means, no locking is needed.
 *
 * N.B. This code is "remote" safe, but is not currently used for
 * remote clients.
 *
 * - Dianora
 */
void
safe_list_channels(struct Client *source_p, struct ListTask *list_task,
                   int only_unmasked_channels, int remote_request)
{
  struct Channel *chptr;

  if (!only_unmasked_channels)
  {
    int i;

    for (i = list_task->hash_index; i < HASHSIZE; i++)
    {
      if (MyConnect(source_p))
      {
        if (exceeding_sendq(source_p))
        {
          list_task->hash_index = i;
          return; /* still more to do */
        }
      }

      for (chptr = channelTable[i]; chptr; chptr = chptr->hnextch)
        list_one_channel(source_p, chptr, list_task, remote_request);
    }
  }
  else
  {
    dlink_node *dl;

    DLINK_FOREACH(dl, list_task->show_mask.head)
      if ((chptr = hash_find_channel(dl->data)) != NULL)
        list_one_channel(source_p, chptr, list_task, remote_request);
  }

  free_list_task(list_task, source_p);
  sendto_one(source_p, form_str(RPL_LISTEND),
             me.name, source_p->name);
}
