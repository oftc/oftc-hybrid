/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  client.c: Controls clients.
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
#include "config.h"

#include "tools.h"
#include "client.h"
#include "class.h"
#include "channel_mode.h"
#include "common.h"
#include "event.h"
#include "fdlist.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "s_gline.h"
#include "numeric.h"
#include "packet.h"
#include "s_auth.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_misc.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "s_debug.h"
#include "s_user.h"
#include "linebuf.h"
#include "hash.h"
#include "memory.h"
#include "hostmask.h"
#include "balloc.h"
#include "listener.h"

static void check_pings_list(dlink_list *list);
static void check_unknowns_list(dlink_list *list);

static EVH check_pings;

static int remote_client_count=0;
static int local_client_count=0;

static BlockHeap *client_heap = NULL;
static BlockHeap *lclient_heap = NULL;

dlink_list dead_list;
dlink_list abort_list;

/*
 * client_heap_gc
 *
 * inputs	- NONE
 * output	- NONE
 * side effect  - Does garbage collection of client heaps
 */
 
static void client_heap_gc(void *unused)
{
  BlockHeapGarbageCollect(client_heap);
  BlockHeapGarbageCollect(lclient_heap);
}

/*
 * init_client
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- initialize client free memory
 */
void
init_client(void)
{
  remote_client_count = 0;
  local_client_count = 0;
  /*
   * start off the check ping event ..  -- adrian
   * Every 30 seconds is plenty -- db
   */
  client_heap = BlockHeapCreate(sizeof(struct Client), CLIENT_HEAP_SIZE);
  lclient_heap = BlockHeapCreate(sizeof(struct LocalUser), LCLIENT_HEAP_SIZE);
  eventAddIsh("check_pings", check_pings, NULL, 30);
  eventAddIsh("client_heap_gc", client_heap_gc, NULL, 30);
}

/*
 * make_client - create a new Client struct and set it to initial state.
 *
 *      from == NULL,   create local client (a client connected
 *                      to a socket).
 *
 *      from,   create remote client (behind a socket
 *                      associated with the client defined by
 *                      'from'). ('from' is a local client!!).
 */
struct Client*
make_client(struct Client* from)
{
  struct Client* client_p = NULL;
  struct LocalUser *localClient;
  dlink_node *m;

  client_p = BlockHeapAlloc(client_heap);
  memset(client_p, 0, sizeof(struct Client)); 
  if (from == NULL)
    {
      client_p->from  = client_p; /* 'from' of local client is self! */
      client_p->since = client_p->lasttime = client_p->firsttime = CurrentTime;

      localClient = (struct LocalUser *)BlockHeapAlloc(lclient_heap);
      memset(localClient, 0, sizeof(struct LocalUser));

      client_p->localClient = localClient;
       
      client_p->localClient->fd = -1;
      client_p->localClient->ctrlfd = -1;
#ifndef HAVE_SOCKETPAIR
      client_p->localClient->fd_r = -1;
      client_p->localClient->ctrlfd_r = -1;
#endif      
      /* as good a place as any... */
      m = make_dlink_node();
      dlinkAdd(client_p, m, &unknown_list);
      ++local_client_count;
    }
  else
    { /* from is not NULL */
      client_p->localClient = NULL;
      client_p->from = from; /* 'from' of local client is self! */
      ++remote_client_count;
    }

  client_p->status = STAT_UNKNOWN;
  strcpy(client_p->username, "unknown");
#if 0
  client_p->name[0] = '\0';
  client_p->flags   = 0;
  client_p->next    = NULL;
  client_p->prev    = NULL;
  client_p->hnext   = NULL;
  client_p->lnext   = NULL;
  client_p->lprev   = NULL;
  client_p->user    = NULL;
  client_p->serv    = NULL;
  client_p->servptr = NULL;
  client_p->whowas  = NULL;
  client_p->allow_list.head = NULL;
  client_p->allow_list.tail = NULL;
  client_p->on_allow_list.head = NULL;
  client_p->on_allow_list.tail = NULL;
#endif
  return client_p;
}

void
free_client(struct Client* client_p)
{
  assert(NULL != client_p);
  assert(&me != client_p);
  assert(NULL == client_p->prev);
  assert(NULL == client_p->next);

  if (MyConnect(client_p))
  {
    assert(IsClosing(client_p) && IsDead(client_p));
      
    /*
     * clean up extra sockets from P-lines which have been discarded.
     */
    if (client_p->localClient->listener)
    {
      assert(0 < client_p->localClient->listener->ref_count);
      if (0 == --client_p->localClient->listener->ref_count &&
          !client_p->localClient->listener->active) 
        free_listener(client_p->localClient->listener);
      client_p->localClient->listener = 0;
    }

      if (client_p->localClient->fd >= 0)
	fd_close(client_p->localClient->fd);

      linebuf_donebuf(&client_p->localClient->buf_recvq);
      linebuf_donebuf(&client_p->localClient->buf_sendq);

      BlockHeapFree(lclient_heap, client_p->localClient);
      --local_client_count;
      assert(local_client_count >= 0);
  }
  else
  {
    --remote_client_count;
  }

  BlockHeapFree(client_heap, client_p);
}

/*
 * check_pings - go through the local client list and check activity
 * kill off stuff that should die
 *
 * inputs       - NOT USED (from event)
 * output       - next time_t when check_pings() should be called again
 * side effects - 
 *
 *
 * A PING can be sent to clients as necessary.
 *
 * Client/Server ping outs are handled.
 */

/*
 * Addon from adrian. We used to call this after nextping seconds,
 * however I've changed it to run once a second. This is only for
 * PING timeouts, not K/etc-line checks (thanks dianora!). Having it
 * run once a second makes life a lot easier - when a new client connects
 * and they need a ping in 4 seconds, if nextping was set to 20 seconds
 * we end up waiting 20 seconds. This is stupid. :-)
 * I will optimise (hah!) check_pings() once I've finished working on
 * tidying up other network IO evilnesses.
 *     -- adrian
 */

static void
check_pings(void *notused)
{               
  check_pings_list(&lclient_list);
  check_pings_list(&serv_list);
  check_unknowns_list(&unknown_list);
}

/*
 * Check_pings_list()
 *
 * inputs	- pointer to list to check
 * output	- NONE
 * side effects	- 
 */
static void
check_pings_list(dlink_list *list)
{
  char         scratch[32];     /* way too generous but... */
  struct Client *client_p;      /* current local client_p being examined */
  int           ping = 0;       /* ping time value from client */
  dlink_node    *ptr, *next_ptr;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
  {
    client_p = ptr->data;

    /*
    ** Note: No need to notify opers here. It's
    ** already done when "FLAGS_DEADSOCKET" is set.
    */
    if (IsDead(client_p))
    {
      /* Ignore it, its been exited already */
      continue; 
    }

    if (IsPerson(client_p))
    {
      if(!IsExemptKline(client_p) &&
	 GlobalSetOptions.idletime && 
	 !IsOper(client_p) &&
	 !IsIdlelined(client_p) && 
	 ((CurrentTime - client_p->user->last) > GlobalSetOptions.idletime))
	{
	  struct ConfItem *aconf;

	  aconf = make_conf();
	  aconf->status = CONF_KILL;

	  DupString(aconf->host, client_p->host);
	  DupString(aconf->passwd, "idle exceeder");
	  DupString(aconf->user, client_p->username);
	  aconf->port = 0;
	  aconf->hold = CurrentTime + 60;
	  add_temp_kline(aconf);
	  sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
		       "Idle time limit exceeded for %s - temp k-lining",
			       get_client_name(client_p, HIDE_IP));


	  (void)exit_client(client_p, client_p, &me, aconf->passwd);
	  continue;
	}
    }

    if (!IsRegistered(client_p))
      ping = CONNECTTIMEOUT;
    else
      ping = get_client_ping(client_p);

    if (ping < (CurrentTime - client_p->lasttime))
    {
      /*
       * If the client/server hasnt talked to us in 2*ping seconds
       * and it has a ping time, then close its connection.
       */
      if (((CurrentTime - client_p->lasttime) >= (2 * ping) &&
	   IsPingSent(client_p)))
      {
	if (IsServer(client_p) || IsConnecting(client_p) ||
	    IsHandshake(client_p))
	  {
	    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
				 "No response from %s, closing link",
				 get_client_name(client_p, MASK_IP));
	    ilog(L_NOTICE, "No response from %s, closing link",
		 get_client_name(client_p, HIDE_IP));
	  }
	(void)ircsprintf(scratch,
			 "Ping timeout: %d seconds",
			 (int)(CurrentTime - client_p->lasttime));
	      
	(void)exit_client(client_p, client_p, &me, scratch);
	continue;
      }
      else if (!IsPingSent(client_p))
      {
	/*
	 * if we havent PINGed the connection and we havent
	 * heard from it in a while, PING it to make sure
	 * it is still alive.
	 */
	SetPingSent(client_p);
	client_p->lasttime = CurrentTime - ping;
    gettimeofday(&client_p->ping_send_time, NULL);
	sendto_one(client_p, "PING :%s", me.name);
      }
    }
    /* ping_timeout: */

  }
}

/*
 * check_unknowns_list
 *
 * inputs	- pointer to list of unknown clients
 * output	- NONE
 * side effects	- unknown clients get marked for termination after n seconds
 */
static void
check_unknowns_list(dlink_list *list)
{
  dlink_node *ptr, *next_ptr;
  struct Client *client_p;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
  {
    client_p = ptr->data;

    /*
     * Check UNKNOWN connections - if they have been in this state
     * for > 30s, close them.
     */

    if (client_p->firsttime ? ((CurrentTime - client_p->firsttime) > 30) : 0)
    {
      (void)exit_client(client_p, client_p, &me, "Connection timed out");
    }
  }
}

/*
 * check_klines
 * inputs	- NONE
 * output	- NONE
 * side effects - Check all connections for a pending kline against the
 * 		  client, exit the client if a kline matches.
 */
void 
check_klines(void)
{               
  struct Client *client_p;          /* current local client_p being examined */
  struct ConfItem *aconf = NULL;
  char *reason;                /* pointer to reason string */
  dlink_node *ptr, *next_ptr;
 
  DLINK_FOREACH_SAFE(ptr, next_ptr, lclient_list.head)
  {
    client_p = ptr->data;
      
    if (IsMe(client_p))
      continue;

    /* If a client is already being exited
     */
    if (IsDead(client_p))
      continue;
	
    /* if there is a returned struct ConfItem then kill it */
    if ((aconf = find_dline_conf(&client_p->localClient->ip,
				 client_p->localClient->aftype)) != NULL)
    {
      if (aconf->status & CONF_EXEMPTDLINE)
	continue;
	    
      sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
              "DLINE active for %s",
			   get_client_name(client_p, HIDE_IP));
      
      if (ConfigFileEntry.kline_with_connection_closed &&
	  ConfigFileEntry.kline_with_reason)
      {
	reason = "Connection closed";

	if(IsPerson(client_p))
	  sendto_one(client_p, form_str(ERR_YOUREBANNEDCREEP),
		     me.name, client_p->name,
		     aconf->passwd ? aconf->passwd : "D-lined");
	else
	  sendto_one(client_p, "NOTICE DLINE :*** You have been D-lined");
      }
      else
      {
	if(ConfigFileEntry.kline_with_connection_closed)
	  reason = "Connection closed";
	else if(ConfigFileEntry.kline_with_reason && aconf->passwd)
	  reason = aconf->passwd;
	else
	  reason = "D-lined";

	if(IsPerson(client_p))
	  sendto_one(client_p, form_str(ERR_YOUREBANNEDCREEP),
		     me.name, client_p->name, reason);
	else
	  sendto_one(client_p, "NOTICE DLINE :*** You have been D-lined");
      }
	    
      (void)exit_client(client_p, client_p, &me, reason);
      continue; /* and go examine next fd/client_p */
    }

    if (IsPerson(client_p))
    {
      if (ConfigFileEntry.glines &&
	  (aconf = find_gkill(client_p, client_p->username)))
      {
	if (IsExemptKline(client_p))
	{
	  sendto_realops_flags(FLAGS_ALL, L_ALL,
		       "GLINE over-ruled for %s, client is kline_exempt",
			       get_client_name(client_p, HIDE_IP));
	  continue;
	}
	
	if (IsExemptGline(client_p))
	{
	  sendto_realops_flags(FLAGS_ALL, L_ALL,
			"GLINE over-ruled for %s, client is gline_exempt",
			       get_client_name(client_p, HIDE_IP));
	  continue;
	}
       
	sendto_realops_flags(FLAGS_ALL, L_ALL, "GLINE active for %s",
			     get_client_name(client_p, HIDE_IP));
			    
	if(ConfigFileEntry.kline_with_connection_closed &&
	   ConfigFileEntry.kline_with_reason)
	{
	  reason = "Connection closed";

	  sendto_one(client_p, form_str(ERR_YOUREBANNEDCREEP),
		     me.name, client_p->name,
		     aconf->passwd ? aconf->passwd : "G-lined");
	} 
	else 
	{
	  if(ConfigFileEntry.kline_with_connection_closed)
	    reason = "Connection closed";
	  else if(ConfigFileEntry.kline_with_reason && aconf->passwd)
	    reason = aconf->passwd;
	  else
	    reason = "G-lined";

	  sendto_one(client_p, form_str(ERR_YOUREBANNEDCREEP),
		     me.name, client_p->name, reason);
	}
	
	(void)exit_client(client_p, client_p, &me, reason);
	/* and go examine next fd/client_p */    
	continue;
      } 
      else if((aconf = find_kill(client_p)) != NULL) 
      {
	/* if there is a returned struct ConfItem.. then kill it */
	if (IsExemptKline(client_p))
	{
	  sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
			     "KLINE over-ruled for %s, client is kline_exempt",
			     get_client_name(client_p, HIDE_IP));
	  continue;
	}

	sendto_gnotice_flags(FLAGS_ALL, L_ALL, me.name, &me, NULL,
            "KLINE active for %s",
			     get_client_name(client_p, HIDE_IP));
	
	if(ConfigFileEntry.kline_with_connection_closed &&
	   ConfigFileEntry.kline_with_reason)
	{
	  reason = "Connection closed";

	  sendto_one(client_p, form_str(ERR_YOUREBANNEDCREEP),
		     me.name, client_p->name, 
		     aconf->passwd ? aconf->passwd : "K-lined");
	}
	else
	{
	  if(ConfigFileEntry.kline_with_connection_closed)
	    reason = "Connection closed";
	  else if(ConfigFileEntry.kline_with_reason && aconf->passwd)
	    reason = aconf->passwd;
	  else
	    reason = "K-lined";

	  sendto_one(client_p, form_str(ERR_YOUREBANNEDCREEP),
		     me.name, client_p->name, reason);
	}
	      
	(void)exit_client(client_p, client_p, &me, reason);
	continue; 
      }
    }
  }
 
  /* also check the unknowns list for new dlines */
  DLINK_FOREACH_SAFE(ptr, next_ptr, unknown_list.head)
  {
    client_p = ptr->data;

    if((aconf = find_dline_conf(&client_p->localClient->ip,
				client_p->localClient->aftype)))
    {
      if(aconf->status & CONF_EXEMPTDLINE)
        continue;

      sendto_one(client_p, "NOTICE DLINE :*** You have been D-lined");
      exit_client(client_p, client_p, &me, "D-lined");
    }
  }

}

/*
 * update_client_exit_stats
 *
 * input	- pointer to client
 * output	- NONE
 * side effects	- 
 */
static void
update_client_exit_stats(struct Client* client_p)
{
  if (IsServer(client_p))
  {
    --Count.server;
  }
  else if (IsClient(client_p))
  {
    --Count.total;
    if (IsOper(client_p))
      --Count.oper;
    if (IsInvisible(client_p)) 
      --Count.invisi;
  }

  if(splitchecking && !splitmode)
    check_splitmode(NULL);
}

/*
 * release_client_state
 *
 * input	- pointer to client to release
 * output	- NONE
 * side effects	- 
 */
static void
release_client_state(struct Client* client_p)
{
  if (client_p->user != NULL)
  {
    free_user(client_p->user, client_p); /* try this here */
  }

  if (client_p->serv != NULL)
  {
    if (client_p->serv->user != NULL)
      free_user(client_p->serv->user, client_p);
    MyFree((char*) client_p->serv);
  }
}

/*
 * remove_client_from_list
 * inputs	- point to client to remove
 * output	- NONE
 * side effects - taken the code from ExitOneClient() for this
 *		  and placed it here. - avalon
 */
void
remove_client_from_list(struct Client* client_p)
{
  assert(client_p != NULL);

  if(client_p == NULL)
    return;

/* XXX try without this as well */
#if 1
  /* A client made with make_client()
   * is on the unknown_list until removed.
   * If it =does= happen to exit before its removed from that list
   * and its =not= on the GlobalClientList, it will core here.
   * short circuit that case now -db
   */
  if (!client_p->prev && !client_p->next)
    {
      return;
    }
#endif

  if (client_p->prev)
    client_p->prev->next = client_p->next;
  else
    {
      GlobalClientList = client_p->next;
      GlobalClientList->prev = NULL;
    }

  if (client_p->next)
    client_p->next->prev = client_p->prev;
  client_p->next = client_p->prev = NULL;

  update_client_exit_stats(client_p);
}

/*
 * add_client_to_list
 * input	- pointer to client
 * output	- NONE
 * side effects	- although only a small routine,
 *		  it appears in a number of places
 * 		  as a collection of a few lines...functions like this
 *		  should be in this file, shouldnt they ?  after all,
 *		  this is list.c, isnt it ? (no
 *		  -avalon
 */
void
add_client_to_list(struct Client *client_p)
{
  /*
   * since we always insert new clients to the top of the list,
   * this should mean the "me" is the bottom most item in the list.
   */
  client_p->next = GlobalClientList;
  GlobalClientList = client_p;
  if (client_p->next)
    client_p->next->prev = client_p;
  return;
}

/* Functions taken from +CSr31, paranoified to check that the client
** isn't on a llist already when adding, and is there when removing -orabidoo
*/
void
add_client_to_llist(struct Client **bucket, struct Client *client)
{
  if (!client->lprev && !client->lnext)
    {
      client->lprev = NULL;
      if ((client->lnext = *bucket) != NULL)
        client->lnext->lprev = client;
      *bucket = client;
    }
}

void
del_client_from_llist(struct Client **bucket, struct Client *client)
{
  if (client->lprev)
    {
      client->lprev->lnext = client->lnext;
    }
  else if (*bucket == client)
    {
      *bucket = client->lnext;
    }
  if (client->lnext)
    {
      client->lnext->lprev = client->lprev;
    }
  client->lnext = client->lprev = NULL;
}

/*
 * next_client - find the next matching client. 
 * The search can be continued from the specified client entry. 
 * Normal usage loop is:
 *
 *      for (x = client; x = next_client(x,mask); x = x->next)
 *              HandleMatchingClient;
 *            
 */
struct Client*
next_client(struct Client *next,     /* First client to check */
            const char* ch)          /* search string (may include wilds) */
{
  struct Client *tmp = next;

  next = find_client(ch);

  if (next == NULL)
    next = tmp;

  if (tmp && tmp->prev == next)
    return (NULL);

  if (next != tmp)
    return next;

  for ( ; next; next = next->next)
    {
      if (match(ch,next->name)) break;
    }
  return next;
}

/*
 * find_person	- find person by (nick)name.
 * inputs	- pointer to name
 * output	- return client pointer
 * side effects -
 */
struct Client *
find_person(char *name)
{
  struct Client       *c2ptr;

  c2ptr = find_client(name);

  if (c2ptr && IsPerson(c2ptr))
    return (c2ptr);
  return (NULL);
}

/*
 * find_chasing - find the client structure for a nick name (user) 
 *      using history mechanism if necessary. If the client is not found, 
 *      an error message (NO SUCH NICK) is generated. If the client was found
 *      through the history, chasing will be 1 and otherwise 0.
 */
struct Client *
find_chasing(struct Client *source_p, char *user, int *chasing)
{
  struct Client *who = find_client(user);
  
  if (chasing)
    *chasing = 0;
  if (who)
    return who;
  if (!(who = get_history(user, (long)KILLCHASETIMELIMIT)))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHNICK),
                 me.name, source_p->name, user);
      return (NULL);
    }
  if (chasing)
    *chasing = 1;
  return who;
}

/*
 * get_client_name -  Return the name of the client
 *    for various tracking and
 *      admin purposes. The main purpose of this function is to
 *      return the "socket host" name of the client, if that
 *        differs from the advertised name (other than case).
 *        But, this can be used to any client structure.
 *
 * NOTE 1:
 *        Watch out the allocation of "nbuf", if either source_p->name
 *        or source_p->sockhost gets changed into pointers instead of
 *        directly allocated within the structure...
 *
 * NOTE 2:
 *        Function return either a pointer to the structure (source_p) or
 *        to internal buffer (nbuf). *NEVER* use the returned pointer
 *        to modify what it points!!!
 */

const char* 
get_client_name(struct Client* client, int showip)
{
  static char nbuf[HOSTLEN * 2 + USERLEN + 5];

  assert(NULL != client);
  if(client == NULL)
    return NULL;
    
  if (MyConnect(client))
    {
      if (!irccmp(client->name, client->host))
        return client->name;

#ifdef HIDE_SERVERS_IPS
      if(IsServer(client) || IsConnecting(client) || IsHandshake(client))
        showip = MASK_IP;
#endif
#ifdef HIDE_SPOOF_IPS
      if(showip == SHOW_IP && IsIPSpoof(client))
        showip = MASK_IP;
#endif

      /* And finally, let's get the host information, ip or name */
      switch (showip)
        {
          case SHOW_IP:
            ircsprintf(nbuf, "%s[%s@%s]", client->name, client->username,
              client->localClient->sockhost);
            break;
          case MASK_IP:
            ircsprintf(nbuf, "%s[%s@255.255.255.255]", client->name,
              client->username);
            break;
          default:
            ircsprintf(nbuf, "%s[%s@%s]", client->name, client->username,
              client->host);
        }
      return nbuf;
    }

  /* As pointed out by Adel Mezibra 
   * Neph|l|m@EFnet. Was missing a return here.
   */
  return client->name;
}

void
free_exited_clients(void)
{
  dlink_node *ptr, *next;
  struct Client *target_p;
  
  DLINK_FOREACH_SAFE(ptr, next, dead_list.head)
    {
      target_p = ptr->data;

      if (ptr->data == NULL)
        {
          sendto_realops_flags(FLAGS_ALL, L_ALL,
                        "Warning: null client on dead_list!");
          dlinkDelete(ptr, &dead_list);
          free_dlink_node(ptr);
          continue;
        }
      release_client_state(target_p);
      free_client(target_p);
      dlinkDelete(ptr, &dead_list);
      free_dlink_node(ptr);
    }
}

/*
** Exit one client, local or remote. Assuming all dependents have
** been already removed, and socket closed for local client.
*/
static void
exit_one_client(struct Client *client_p, struct Client *source_p,
		struct Client *from, const char *comment)
{
  struct Client* target_p;
  dlink_node *lp;
  dlink_node *next_lp;
  dlink_node *m;

  if (IsServer(source_p))
    {
      if (source_p->servptr && source_p->servptr->serv)
        del_client_from_llist(&(source_p->servptr->serv->servers),
                                    source_p);
      else
        ts_warn("server %s without servptr!", source_p->name);

      if(!IsMe(source_p))
      {
        if ((m = dlinkFindDelete(&global_serv_list, source_p)) != NULL)
	  free_dlink_node(m);
      }
    }
  else if (source_p->servptr && source_p->servptr->serv)
    {
      del_client_from_llist(&(source_p->servptr->serv->users), source_p);
    }
  /* there are clients w/o a servptr: unregistered ones */

  /*
  **  For a server or user quitting, propogate the information to
  **  other servers (except to the one where is came from (client_p))
  */
  if (IsMe(source_p))
    {
      sendto_realops_flags(FLAGS_ALL, L_ALL,
			   "ERROR: tried to exit me! : %s", comment);
      return;        /* ...must *never* exit self!! */
    }
  else if (IsServer(source_p))
    {
      /*
      ** Old sendto_serv_but_one() call removed because we now
      ** need to send different names to different servers
      ** (domain name matching)
      */
      /*
      ** The bulk of this is done in remove_dependents now, all
      ** we have left to do is send the SQUIT upstream.  -orabidoo
      */
      if (MyConnect(source_p))
      {
	if(source_p->localClient->ctrlfd > -1)
	{
          fd_close(source_p->localClient->ctrlfd);
	  source_p->localClient->ctrlfd = -1;

#ifndef HAVE_SOCKETPAIR
          fd_close(source_p->localClient->ctrlfd_r);
	  fd_close(source_p->localClient->fd_r);
	  
	  source_p->localClient->ctrlfd_r = -1;
	  source_p->localClient->fd_r = -1;
#endif
	}
      }

      target_p = source_p->from;
      if (target_p && IsServer(target_p) && target_p != client_p &&
          !IsMe(target_p) && !IsKilled(source_p))
        sendto_one(target_p, ":%s SQUIT %s :%s", from->name, source_p->name,
                   comment);
    }
  else if (IsPerson(source_p)) /* ...just clean all others with QUIT... */
    {
      /*
      ** If this exit is generated from "m_kill", then there
      ** is no sense in sending the QUIT--KILL's have been
      ** sent instead.
      */
      if (!IsKilled(source_p))
        {
          sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS,
                        NOFLAGS, ":%s QUIT :%s", source_p->name, comment);
        }
      /*
      ** If a person is on a channel, send a QUIT notice
      ** to every client (person) on the same channel (so
      ** that the client can show the "**signoff" message).
      ** (Note: The notice is to the local clients *only*)
      */
      sendto_common_channels_local(source_p, 0,
                                   ":%s!%s@%s QUIT :%s",
				   source_p->name, source_p->username,
				   source_p->host, comment);

      DLINK_FOREACH_SAFE(lp, next_lp, source_p->user->channel.head)
      {
	remove_user_from_channel(lp->data, source_p);
      }
        
      /* Should not be in any channels now */
      assert(source_p->user->channel.head == NULL);
          
      /* Clean up invitefield */
      DLINK_FOREACH_SAFE(lp, next_lp, source_p->user->invited.head)
	{
	  del_invite(lp->data, source_p);
	}

      /* Clean up allow lists */
      del_all_accepts(source_p);

      add_history(source_p, 0);
      off_history(source_p);

      if (HasID(source_p))
	del_from_id_hash_table(source_p->user->id, source_p);
  
      /* again, this is all that is needed */
    }
  
  /* 
   * Remove source_p from the client lists
   */
  del_from_client_hash_table(source_p->name, source_p);

  /* remove from global client list */
  remove_client_from_list(source_p);

  /* Check to see if the client isn't already on the dead list */
  assert(dlinkFind(&dead_list, source_p) == NULL);
  /* add to dead client dlist */
  lp = make_dlink_node();
  SetDead(source_p);
  dlinkAdd(source_p, lp, &dead_list);
}

/*
** Recursively send QUITs and SQUITs for source_p and all its dependent clients
** and servers to those servers that need them.  A server needs the client
** QUITs if it can't figure them out from the SQUIT (ie pre-TS4) or if it
** isn't getting the SQUIT because of @#(*&@)# hostmasking.  With TS4, once
** a link gets a SQUIT, it doesn't need any QUIT/SQUITs for clients depending
** on that one -orabidoo
*/
static void recurse_send_quits(struct Client *client_p, struct Client *source_p, struct Client *to,
                                const char* comment,  /* for servers */
                                const char* myname)
{
  struct Client *target_p;

  /* If this server can handle quit storm (QS) removal
   * of dependents, just send the SQUIT
   */

  if (IsCapable(to,CAP_QS))
    {
      if (match(myname, source_p->name))
        {
          for (target_p = source_p->serv->users; target_p; target_p = target_p->lnext)
            sendto_one(to, ":%s QUIT :%s", target_p->name, comment);
          for (target_p = source_p->serv->servers; target_p; target_p = target_p->lnext)
            recurse_send_quits(client_p, target_p, to, comment, myname);
        }
      else
        sendto_one(to, "SQUIT %s :%s", source_p->name, me.name);
    }
  else
    {
      for (target_p = source_p->serv->users; target_p; target_p = target_p->lnext)
        sendto_one(to, ":%s QUIT :%s", target_p->name, comment);
      for (target_p = source_p->serv->servers; target_p; target_p = target_p->lnext)
        recurse_send_quits(client_p, target_p, to, comment, myname);
      if (!match(myname, source_p->name))
        sendto_one(to, "SQUIT %s :%s", source_p->name, me.name);
    }
}

/* 
** Remove all clients that depend on source_p; assumes all (S)QUITs have
** already been sent.  we make sure to exit a server's dependent clients 
** and servers before the server itself; exit_one_client takes care of 
** actually removing things off llists.   tweaked from +CSr31  -orabidoo
*/
/*
 * added sanity test code.... source_p->serv might be NULL...
 */
static void
recurse_remove_clients(struct Client* source_p, const char* comment)
{
  struct Client *target_p;

  if (IsMe(source_p))
    return;

  if (source_p->serv == NULL)     /* oooops. uh this is actually a major bug */
    return;

  while ((target_p = source_p->serv->users))
    {
      SetKilled(target_p);
      exit_one_client(NULL, target_p, &me, comment);
    }

  while ((target_p = source_p->serv->servers))
    {
      recurse_remove_clients(target_p, comment);
      /*
      ** a server marked as "KILLED" won't send a SQUIT 
      ** in exit_one_client()   -orabidoo
      */
      SetKilled(target_p);
      exit_one_client(NULL, target_p, &me, me.name);
    }
}

/*
** Remove *everything* that depends on source_p, from all lists, and sending
** all necessary QUITs and SQUITs.  source_p itself is still on the lists,
** and its SQUITs have been sent except for the upstream one  -orabidoo
*/
static void
remove_dependents(struct Client* client_p, 
		  struct Client* source_p,
		  struct Client* from,
		  const char* comment,
		  const char* comment1)
{
  struct Client *to;
  struct ConfItem *aconf;
  static char myname[HOSTLEN+1];
  dlink_node *ptr;

  DLINK_FOREACH(ptr, serv_list.head)
    {
      to = ptr->data;

      if (IsMe(to) ||to == source_p->from || (to == client_p && IsCapable(to,CAP_QS)))
        continue;

      /* MyConnect(source_p) is rotten at this point: if source_p
       * was mine, ->from is NULL. 
       */
      /* The WALLOPS isn't needed here as pointed out by
       * comstud, since m_squit already does the notification.
       */

      if ((aconf = to->serv->sconf) != NULL)
        strlcpy(myname, my_name_for_link(me.name, aconf), sizeof(myname));
      else
        strlcpy(myname, me.name, sizeof(myname));
      recurse_send_quits(client_p, source_p, to, comment1, myname);
    }

  recurse_remove_clients(source_p, comment1);
}

/*
 * dead_link_on_write - report a write error if not already dead,
 *			mark it as dead then exit it
 *
 */
void
dead_link_on_write(struct Client *client_p, int ierrno)
{
  dlink_node *m;
  const char *notice;

  if(IsDefunct(client_p))
    return;

  linebuf_donebuf(&client_p->localClient->buf_recvq);
  linebuf_donebuf(&client_p->localClient->buf_sendq);

  if (IsSendQExceeded(client_p))
    notice = "Max SendQ exceeded";
  else
    notice = "Write error: connection closed";
    	
  Debug((DEBUG_ERROR, "Closing link to %s: %s", get_client_name(to, HIDE_IP), 
              notice));
  assert(dlinkFind(&abort_list, client_p) == NULL);
  m = make_dlink_node();
  dlinkAdd(client_p, m, &abort_list);
  SetDead(client_p); /* You are dead my friend */
  if (!IsPerson(client_p) && !IsUnknown(client_p) && !IsClosing(client_p))
  {
    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
		         "Closing link to %s: %s",
                         get_client_name(client_p, MASK_IP), notice);
  }
}

/*
 * dead_link_on_read -  report a read error if not already dead,
 *			mark it as dead then exit it
 *
 */
void
dead_link_on_read(struct Client* client_p, int error)
{
  char errmsg[255];
  int  current_error = get_sockerr(client_p->localClient->fd);

  if(IsDefunct(client_p))
    return;

  linebuf_donebuf(&client_p->localClient->buf_recvq);
  linebuf_donebuf(&client_p->localClient->buf_sendq);

  Debug((DEBUG_ERROR, "READ ERROR: fd = %d %d %d",
         client_p->localClient->fd, current_error, error));

  if (IsServer(client_p) || IsHandshake(client_p))
  {
    int connected = CurrentTime - client_p->firsttime;
      
    if (error == 0)
    {
      sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
            get_client_name(client_p, MASK_IP));

      ilog(L_NOTICE, "Server %s closed the connection",
	   get_client_name(client_p, SHOW_IP));
    }
    else
    {
      report_error(L_OPER, "Lost connection to %s: %d",
		   get_client_name(client_p, MASK_IP), current_error);
    }

    sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
			 "%s had been connected for %d day%s, %2d:%02d:%02d",
			 client_p->name, connected/86400,
			 (connected/86400 == 1) ? "" : "s",
			 (connected % 86400) / 3600, (connected % 3600) / 60,
			 connected % 60);
  }

  if (error == 0)
  {
    strcpy(errmsg, "Remote host closed the connection");
  }
  else
  {
    ircsprintf(errmsg, "Read error: %s", strerror(current_error));
  }
  exit_client(client_p, client_p, &me, errmsg);
}

void
exit_aborted_clients(void)
{
  dlink_node *ptr, *next;
  struct Client *target_p;
  char *notice;
  
  DLINK_FOREACH_SAFE(ptr, next, abort_list.head)
  {
      target_p = ptr->data;
      if (ptr->data == NULL)
        {
          sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                        "Warning: null client on abort_list!");
          dlinkDelete(ptr, &abort_list);
          free_dlink_node(ptr);
          continue;
        }
      dlinkDelete(ptr, &abort_list);
      if(IsSendQExceeded(target_p))
        notice = "Max SendQ exceeded";
      else
        notice = "Write error: connection closed";
      
      exit_client(target_p, target_p, &me, notice);  
      free_dlink_node(ptr);
    }
}

/*
** exit_client - This is old "m_bye". Name  changed, because this is not a
**        protocol function, but a general server utility function.
**
**        This function exits a client of *any* type (user, server, etc)
**        from this server. Also, this generates all necessary prototol
**        messages that this exit may cause.
**
**   1) If the client is a local client, then this implicitly
**        exits all other clients depending on this connection (e.g.
**        remote clients having 'from'-field that points to this.
**
**   2) If the client is a remote client, then only this is exited.
**
** For convenience, this function returns a suitable value for
** m_function return value:
**
**        CLIENT_EXITED        if (client_p == source_p)
**        0                if (client_p != source_p)
*/

int
exit_client(
	    struct Client* client_p, /* The local client originating the
				      * exit or NULL, if this exit is
				      * generated by this server for
				      * internal reasons.
				      * This will not get any of the
				      * generated messages. */
	    struct Client* source_p, /* Client exiting */
	    struct Client* from,     /* Client firing off this Exit,
				      * never NULL! */
	    const char* comment      /* Reason for the exit */
	    )
{
  char comment1[HOSTLEN + HOSTLEN + 2];
  dlink_node *m;

  if (MyConnect(source_p))
  {
    /* DO NOT REMOVE. exit_client can be called twice after a failed
     * read/write.
     */
    if(IsClosing(source_p))
      return 0;

    SetClosing(source_p);

    if (IsIpHash(source_p))
      remove_one_ip(&source_p->localClient->ip);
    
    delete_adns_queries(source_p->localClient->dns_query);
    delete_identd_queries(source_p);
    client_flush_input(source_p);
    
    /* This source_p could have status of one of STAT_UNKNOWN, STAT_CONNECTING
     * STAT_HANDSHAKE or STAT_UNKNOWN
     * all of which are lumped together into unknown_list
     *
     * In all above cases IsRegistered() will not be true.
     */
    if (!IsRegistered(source_p))
    {
      if ((m = dlinkFindDelete(&unknown_list, source_p)) != NULL)
        free_dlink_node(m);
    }
    else if (IsOper(source_p))
    {
      if ((m = dlinkFindDelete(&oper_list, source_p)) != NULL)
        free_dlink_node(m);
    }
    if (IsClient(source_p))
    {
      Count.local--;
      
      /* a little extra paranoia */
      if (IsPerson(source_p))
        dlinkDelete(&source_p->localClient->lclient_node, &lclient_list);
    }

    /* As soon as a client is known to be a server of some sort
     * it has to be put on the serv_list, or SJOIN's to this new server
     * from the connect burst will not be seen.
     */
    if (IsServer(source_p) || IsConnecting(source_p) ||
        IsHandshake(source_p))
    {
      if ((m = dlinkFindDelete(&serv_list, source_p)) != NULL)
      {
        free_dlink_node(m);
        unset_chcap_usage_counts(source_p);
      }
    }

    if (IsServer(source_p))
    {
      Count.myserver--;
      if(ServerInfo.hub)
        remove_lazylink_flags(source_p->localClient->serverMask);
      else
        uplink = NULL;
    }
    
    if (IsPerson(source_p))
        sendto_gnotice_flags(FLAGS_CCONN, L_ALL, me.name, &me, NULL,
                           "Client exiting: %s (%s@%s) [%s] [%s]",
                           source_p->name, source_p->username, source_p->host,
                           comment, 
#ifdef HIDE_SPOOF_IPS
                           IsIPSpoof(source_p) ? "255.255.255.255" :
#endif
                           source_p->localClient->sockhost);
    
    log_user_exit(source_p);
  
    if (!IsDead(source_p))
    {
      if (client_p != NULL && source_p != client_p)
        sendto_one(source_p, "ERROR :Closing Link: %s %s (%s)",
                   source_p->host, source_p->name, comment);
      else
        sendto_one(source_p, "ERROR :Closing Link: %s (%s)",
                   source_p->host, comment);
    }

    /*
    ** Currently only server connections can have
    ** depending remote clients here, but it does no
    ** harm to check for all local clients. In
    ** future some other clients than servers might
    ** have remotes too...
    **
    ** Close the Client connection first and mark it
    ** so that no messages are attempted to send to it.
    ** (The following *must* make MyConnect(source_p) == FALSE!).
    ** It also makes source_p->from == NULL, thus it's unnecessary
    ** to test whether "source_p != target_p" in the following loops.
    */
    close_connection(source_p);
  }

  if (IsServer(source_p))
  {
    if(ConfigServerHide.hide_servers)
    {
      /* set netsplit message to "me.name *.split" to still show 
       * that its a split, but hide the servers splitting
       */
      ircsprintf(comment1,"%s *.split", me.name);
    }
    else
    {
      if((source_p->serv) && (source_p->serv->up))
        strcpy(comment1, source_p->serv->up);
      else
        strcpy(comment1, "<Unknown>");
      
      strcat(comment1," ");
      strcat(comment1, source_p->name);
    }

    /* XXX Why does this happen */
    if (source_p->serv != NULL)
      remove_dependents(client_p, source_p, from, comment, comment1);
    
    if (source_p->servptr == &me)
    {
        sendto_gnotice_flags(FLAGS_ALL, L_OPER, me.name, &me, NULL,
                           "%s was connected for %d seconds.  %d/%d sendK/recvK.",
                           source_p->name, (int)(CurrentTime - source_p->firsttime),
                           source_p->localClient->sendK,
                           source_p->localClient->receiveK);
      ilog(L_NOTICE, "%s was connected for %d seconds.  %d/%d sendK/recvK.",
           source_p->name, CurrentTime - source_p->firsttime, 
           source_p->localClient->sendK, source_p->localClient->receiveK);
    }
  }
  
  /* The client *better* be off all of the lists */
  assert(dlinkFind(&unknown_list, source_p) == NULL);
  assert(dlinkFind(&lclient_list, source_p) == NULL);
  assert(dlinkFind(&serv_list, source_p) == NULL);
  assert(dlinkFind(&oper_list, source_p) == NULL);

  exit_one_client(client_p, source_p, from, comment);
  return client_p == source_p ? CLIENT_EXITED : 0;
}

/*
 * Count up local client memory
 */

/* XXX one common Client list now */
void
count_local_client_memory(int *count, int *local_client_memory_used)
{
  *count = local_client_count;
  *local_client_memory_used = local_client_count *
    (sizeof(struct Client) + sizeof(struct LocalUser));
}

/*
 * Count up remote client memory
 */
void
count_remote_client_memory(int *count, int *remote_client_memory_used)
{
  *count = remote_client_count;
  *remote_client_memory_used = remote_client_count * sizeof(struct Client);
}


/*
 * accept processing, this adds a form of "caller ID" to ircd
 * 
 * If a client puts themselves into "caller ID only" mode,
 * only clients that match a client pointer they have put on 
 * the accept list will be allowed to message them.
 *
 * [ source.on_allow_list ] -> [ target1 ] -> [ target2 ]
 *
 * [target.allow_list] -> [ source1 ] -> [source2 ]
 *
 * i.e. a target will have a link list of source pointers it will allow
 * each source client then has a back pointer pointing back
 * to the client that has it on its accept list.
 * This allows for exit_one_client to remove these now bogus entries
 * from any client having an accept on them. 
 */

/*
 * accept_message
 *
 * inputs	- pointer to source client
 * 		- pointer to target client
 * output	- 1 if accept this message 0 if not
 * side effects - See if source is on target's allow list
 */
int
accept_message(struct Client *source, struct Client *target)
{
  dlink_node *ptr;
  struct Client *target_p;

  DLINK_FOREACH(ptr, target->allow_list.head)
  {
    target_p = ptr->data;
    if(source == target_p)
    return 1;
  }
  return 0;
}


/*
 * del_from_accept
 *
 * inputs	- pointer to source client
 * 		- pointer to target client
 * output	- NONE
 * side effects - Delete's source pointer to targets allow list
 *
 * Walk through the target's accept list, remove if source is found,
 * Then walk through the source's on_accept_list remove target if found.
 */
void
del_from_accept(struct Client *source, struct Client *target)
{
  dlink_node *ptr;
  dlink_node *ptr2;
  dlink_node *next_ptr;
  dlink_node *next_ptr2;
  struct Client *target_p;

  DLINK_FOREACH_SAFE(ptr, next_ptr, target->allow_list.head)
    {
      target_p = ptr->data;
      if(source == target_p)
	{
	  dlinkDelete(ptr, &target->allow_list);
	  free_dlink_node(ptr);

	  DLINK_FOREACH_SAFE(ptr2, next_ptr2, source->on_allow_list.head)
	    {
	      target_p = ptr2->data;
	      if (target == target_p)
		{
		  dlinkDelete(ptr2, &source->on_allow_list);
		  free_dlink_node(ptr2);
		}
	    }
	}
    }
}

/*
 * del_all_accepts
 *
 * inputs	- pointer to exiting client
 * output	- NONE
 * side effects - Walk through given clients allow_list and on_allow_list
 *                remove all references to this client
 */
void
del_all_accepts(struct Client *client_p)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct Client *target_p;

  DLINK_FOREACH_SAFE(ptr, next_ptr, client_p->allow_list.head)
    {
      target_p = ptr->data;
      if(target_p != NULL)
        del_from_accept(target_p,client_p);
    }

  DLINK_FOREACH_SAFE(ptr, next_ptr, client_p->on_allow_list.head)
    {
      target_p = ptr->data;
      if(target_p != NULL)
	del_from_accept(client_p, target_p);
    }
}

/*
 * set_initial_nick
 * inputs
 * output
 * side effects	-
 *
 * This function is only called to set up an initially registering
 * client. 
 */
int
set_initial_nick(struct Client *client_p, struct Client *source_p,
                 char *nick)
{
 char buf[USERLEN + 1];
 /* Client setting NICK the first time */
  
 /* This had to be copied here to avoid problems.. */
 source_p->tsinfo = CurrentTime;
 if (source_p->name[0])
  del_from_client_hash_table(source_p->name, source_p);
 strcpy(source_p->name, nick);
 add_to_client_hash_table(nick, source_p);
 /* fd_desc is long enough */
 fd_note(client_p->localClient->fd, "Nick: %s", nick);
  
 /* They have the nick they want now.. */
 *client_p->llname = '\0';

 if (source_p->user != NULL)
 {
  strlcpy(buf, source_p->username, sizeof(buf));
  /*
   * USER already received, now we have NICK.
   * *NOTE* For servers "NICK" *must* precede the
   * user message (giving USER before NICK is possible
   * only for local client connection!). register_user
   * may reject the client and call exit_client for it
   * --must test this and exit m_nick too!!!
   */
#ifdef USE_IAUTH
  /*
   * Send the client to the iauth module for verification
   */
  BeginAuthorization(source_p);
#else
  if (register_local_user(client_p, source_p, nick, buf) == CLIENT_EXITED)
   return CLIENT_EXITED;
#endif
 }
 return 0;
}

/*
 * change_local_nick
 * inputs	- pointer to server
 *		- pointer to client
 * output	- 
 * side effects	- changes nick of a LOCAL user
 *
 */
int
change_local_nick(struct Client *client_p, struct Client *source_p, char *nick)
{
  /*
  ** Client just changing his/her nick. If he/she is
  ** on a channel, send note of change to all clients
  ** on that channel. Propagate notice to other servers.
  */

  source_p->tsinfo = CurrentTime;

  if((source_p->localClient->last_nick_change +
       ConfigFileEntry.max_nick_time) < CurrentTime)
    source_p->localClient->number_of_nick_changes = 0;
  source_p->localClient->last_nick_change = CurrentTime;
  source_p->localClient->number_of_nick_changes++;

  if((ConfigFileEntry.anti_nick_flood && 
      (source_p->localClient->number_of_nick_changes
       <= ConfigFileEntry.max_nick_changes)) ||
     !ConfigFileEntry.anti_nick_flood || 
     (IsOper(source_p) && ConfigFileEntry.no_oper_flood))
    {
      /* XXX - the format of this notice should eventually be changed
       * to either %s[%s@%s], or even better would be get_client_name() -bill
       */
        sendto_gnotice_flags(FLAGS_NCHANGE, L_OPER, me.name, &me, NULL,
			   "Nick change: From %s to %s [%s@%s]",
			   source_p->name, nick, source_p->username,
			   source_p->host);

      sendto_common_channels_local(source_p, 1,
                                   ":%s!%s@%s NICK :%s",
				   source_p->name, source_p->username,
				   source_p->host, nick);
      /* Don't clear +R if changing case */
      if(IsNickServReg(source_p) && irccmp(source_p->name, nick) != 0)
      {
        ClearNickServReg(source_p);
        sendto_one(source_p, ":%s MODE %s :-R", source_p->name,
            source_p->name);
      }

      if (source_p->user)
	{
	  add_history(source_p, 1);
	  
	  /* Only hubs care about lazy link nicks not being sent on yet
	   * lazylink leafs/leafs always send their nicks up to hub,
	   * hence must always propogate nick changes.
	   * hubs might not propogate a nick change, if the leaf
	   * does not know about that client yet.
	   */
          sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS,
                        NOFLAGS, ":%s NICK %s :%lu", source_p->name,
                        nick, (unsigned long) source_p->tsinfo);
	}
    }
  else
    {
      sendto_one(source_p,
                 form_str(ERR_NICKTOOFAST),me.name, source_p->name,
                 source_p->name, nick, ConfigFileEntry.max_nick_time);
      return 0;
    }

  /* Finally, add to hash */
  del_from_client_hash_table(source_p->name, source_p);
  strcpy(source_p->name, nick);
  add_to_client_hash_table(nick, source_p);

  /* Make sure everyone that has this client on its accept list
   * loses that reference. 
   */

  del_all_accepts(source_p);

  /* fd_desc is long enough */
  fd_note(client_p->localClient->fd, "Nick: %s", nick);

  return 1;
}


