/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  adns.c: Interfaces to the adns DNS library.
 *
 *  Copyright (C) 2001-2002 Aaron Sethman <androsyn@ratbox.org> 
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
#include "setup.h"

#include "fileio.h"
#include "res.h"
#include "send.h"
#include "s_conf.h"
#include "s_bsd.h"
#include "s_log.h"
#include "event.h"
#include "client.h"
#include "ircd_defs.h"
#include "numeric.h"
#include "../adns/internal.h"
#define ADNS_MAXFD 2

adns_state dns_state;

/* void report_adns_servers(struct Client *source_p)
 * Input: A client to send a list of DNS servers to.
 * Output: None
 * Side effects: Sends a list of DNS servers to source_p
 */
void report_adns_servers(struct Client *source_p)
{
  int x;
  char buf[16]; /* XXX: adns only deals with ipv4 dns servers so this is okay */
  for(x = 0; x < dns_state->nservers; x++)    
  {
    inetntop(AF_INET, &dns_state->servers[x].addr.s_addr, buf, 16);
    sendto_one(source_p, form_str(RPL_STATSALINE), me.name, source_p->name, buf); 
  }
}

/* void delete_adns_queries(struct DNSQuery *q)
 * Input: A pointer to the applicable DNSQuery structure.
 * Output: None
 * Side effects: Cancels a DNS query.
 */
void delete_adns_queries(struct DNSQuery *q)
{
  if (q != NULL && q->query != NULL)
    adns_cancel(q->query);
}                       

/* void restart_resolver(void)
 * Input: None
 * Output: None
 * Side effects: Tears down any old ADNS sockets..reloads the conf
 */
void restart_resolver(void)
{
  adns__rereadconfig(dns_state);
}

/* void init_resolver(void)
 * Input: None
 * Output: None
 * Side effects: Reads the ADNS configuration and sets up the ADNS server
 *               polling and query timeouts.
 */
void init_resolver(void)
{
  int r;

  r = adns_init(&dns_state, adns_if_noautosys, 0);    
 
  if(dns_state == NULL) 
  {
    ilog(L_CRIT, "Error opening /etc/resolv.conf: %s; r = %d", strerror(errno), r);
    exit(76);
  }
  
  eventAddIsh("timeout_adns", timeout_adns, NULL, 2);
  dns_select();
}

/* void timeout_adns(void *ptr);
 * Input: None used.
 * Output: None
 * Side effects: Cancel any old(expired) DNS queries.
 * Note: Called by the event code.
 */
void timeout_adns(void *ptr)
{
  adns_processtimeouts(dns_state, &SystemTime); 
}

/* void dns_writeable(int fd, void *ptr)
 * Input: An fd which has become writeable, ptr not used.
 * Output: None.
 * Side effects: Write any queued buffers out.
 * Note: Called by the fd system.
 */
void dns_writeable(int fd, void *ptr)
{
  adns_processwriteable(dns_state, fd, &SystemTime); 
  dns_select();
  dns_do_callbacks();
}


/* void dns_do_callbacks(void)
 * Input: None.
 * Output: None.
 * Side effects: Call all the callbacks(into the ircd core) for the
 *               results of a DNS resolution.
 */
void dns_do_callbacks(void)
{
  adns_query q, r;
  adns_answer *answer;
  struct DNSQuery *query;
  
  adns_forallqueries_begin(dns_state);
  
  while((q = adns_forallqueries_next(dns_state, (void **)&r)) != NULL)
  {
    switch(adns_check(dns_state, &q, &answer, (void **)&query))  
    {
      case 0:
        /* Looks like we got a winner */            
        assert(query->callback != NULL);
        if(query->callback != NULL)
        {
          query->query = NULL;
          query->callback(query->ptr, answer);
        }
        break;
	
      case EAGAIN:
        /* Go into the queue again */
        break;
	
      default:
        assert(query->callback != NULL);
        if(query->callback != NULL)
        {
          /* Awww we failed, what a shame */
          query->query = NULL;
          query->callback(query->ptr, NULL);      
        }
        break;
    } 
  }
}

/* void dns_readable(int fd, void *ptr)
 * Input: An fd which has become readable, ptr not used.
 * Output: None.
 * Side effects: Read DNS responses from DNS servers.
 * Note: Called by the fd system.
 */
void dns_readable(int fd, void *ptr)
{
  adns_processreadable(dns_state, fd, &SystemTime);  
  dns_select();
  dns_do_callbacks();
}

/* void dns_select(void)
 * Input: None.
 * Output: None
 * Side effects: Re-register ADNS fds with the fd system. Also calls the
 *               callbacks into core ircd.
 */
void dns_select(void)
{
  struct adns_pollfd pollfds[MAXFD_POLL];
  int npollfds, i, fd;
  
  adns__consistency(dns_state,0,cc_entex);
  npollfds = adns__pollfds(dns_state, pollfds);
  for(i = 0; i < npollfds; i++)
  {
    fd = pollfds[i].fd;
    if (pollfds[i].events & ADNS_POLLIN) 
      comm_setselect(fd, FDLIST_SERVER, COMM_SELECT_READ, dns_readable, NULL, 0);
    if (pollfds[i].events & ADNS_POLLOUT)
      comm_setselect(fd, FDLIST_SERVICE, COMM_SELECT_WRITE, dns_writeable, NULL, 0);
  }
 /* Call our callbacks, now that they may have some relevant data...
  */
/*
 *dns_do_callbacks();
 */
}

/* void adns_gethost(const char *name, int aftype, struct DNSQuery *req);
 * Input: A name, an address family, a DNSQuery structure.
 * Output: None
 * Side effects: Sets up a query structure and sends off a DNS query to
 *               the DNS server to resolve an "A"(address) entry by name.
 */
void adns_gethost(const char *name, int aftype, struct DNSQuery *req)
{
  assert(dns_state->nservers > 0);
#ifdef IPV6 
  if (aftype == AF_INET6)
    adns_submit(dns_state, name, adns_r_addr6, adns_qf_owner, req,
                &req->query);
  else
#endif
    adns_submit(dns_state, name, adns_r_addr, adns_qf_owner, req,
                &req->query);
}

/* void adns_getaddr(struct irc_inaddr *addr, int aftype,
 *                   struct DNSQuery *req);
 * Input: An address, an address family, a DNSQuery structure.
 * Output: None
 * Side effects: Sets up a query entry and sends it to the DNS server to
 *               resolve an IP address to a domain name.
 */
void adns_getaddr(struct irc_inaddr *addr, int aftype,
                  struct DNSQuery *req)
{
  struct irc_sockaddr ipn;
  memset(&ipn, 0, sizeof(struct irc_sockaddr));
  assert(dns_state->nservers > 0);
  
#ifdef IPV6
  if (aftype == AF_INET6)
  {
    ipn.sins.sin6.sin6_family = AF_INET6;
    ipn.sins.sin6.sin6_port = 0;
    memcpy(&ipn.sins.sin6.sin6_addr.s6_addr, &addr->sins.sin6.s6_addr,
           sizeof(struct in6_addr));
    adns_submit_reverse(dns_state, (struct sockaddr *)&ipn.sins.sin6,
                       adns_r_ptr_ip6, 
		       adns_qf_owner|adns_qf_cname_loose|adns_qf_quoteok_anshost, 
		       req, &req->query);
  } 
  else
  {
    ipn.sins.sin.sin_family = AF_INET;
    ipn.sins.sin.sin_port = 0;
    ipn.sins.sin.sin_addr.s_addr = addr->sins.sin.s_addr;
    adns_submit_reverse(dns_state, (struct sockaddr *)&ipn.sins.sin, adns_r_ptr, 
                        adns_qf_owner|adns_qf_cname_loose|adns_qf_quoteok_anshost, 
			req, &req->query);
  }
#else
  ipn.sins.sin.sin_family = AF_INET;
  ipn.sins.sin.sin_port = 0;
  ipn.sins.sin.sin_addr.s_addr = addr->sins.sin.s_addr;
  adns_submit_reverse(dns_state, (struct sockaddr *)&ipn.sins.sin, adns_r_ptr, 
                      adns_qf_owner|adns_qf_cname_loose|adns_qf_quoteok_anshost, 
                      req, &req->query);
#endif
}
