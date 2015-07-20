/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_webirc.c: Makes CGI:IRC users appear as coming from their real host
 *
 *  Copyright (C) 1990 Jarkko Oikarinen and University of Oulu, Co Center
 *  Copyright (C) 2002-2006 ircd-ratbox development team
 *  Copyright (C) 1996-2012 Hybrid Development Team
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
/* #include "list.h" */
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"
#include "hash.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_conf.h"
#include "hostmask.h"
#include "s_user.h"

static void mr_webirc(struct Client *, struct Client *, int, char *[]);

struct Message webirc_msgtab = {
  "WEBIRC", 0, 0, 5, 0, MFLG_SLOW, 0,
  { mr_webirc, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore }
};

void
_modinit(void)
{
  mod_add_cmd(&webirc_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&webirc_msgtab);
}

const char *_version = "$Revision$";


/*
 * Usage:
 *
 * auth {
 *   user = "webirc@<cgiirc ip>"; # if identd used, put ident username instead
 *   password = "<password>"; # encryption possible
 *   spoof = "webirc."
 *   class = "users";
 *   encryption = yes; # [Using encryption is highly recommended]
 * };
 *
 * Possible flags:
 *   kline_exempt - k/g lines on the cgiirc ip are ignored
 *   gline_exempt - glines on the cgiirc ip are ignored
 *
 * dlines are checked on the cgiirc ip (of course).
 * k/d/g/x lines, auth blocks, user limits, etc are checked using the
 * real host/ip.
 *
 * The password should be specified unencrypted in webirc_password in
 * cgiirc.config
 */

/*
 * mr_webirc
 *      parv[0] = sender prefix
 *      parv[1] = password
 *      parv[2] = sockhost / ip
 *      parv[3] = realhost
 *      parv[4] = cloak
 */
static void
mr_webirc(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct AccessItem *aconf = NULL;
  struct ConfItem *conf = NULL;
  struct addrinfo hints, *res;
  char original_sockhost[HOSTIPLEN + 1];
  char *host;

  assert(source_p == client_p);

  aconf = find_address_conf(source_p->host,
                            IsGotId(source_p) ? source_p->username : "webirc",
                            &source_p->ip,
                            source_p->aftype, parv[1],
                            source_p->certfp);
  if (aconf == NULL || !IsConfClient(aconf))
    return;

  conf = unmap_conf_item(aconf);

  if (!IsConfDoSpoofIp(aconf) || irccmp(conf->name, "webirc."))
  {
    sendto_gnotice_flags(UMODE_UNAUTH, L_ALL, me.name, &me, NULL, 
                         "Not a CGI:IRC auth block: %s", source_p->sockhost);
    return;
  }

  if (EmptyString(aconf->passwd))
  {
    sendto_gnotice_flags(UMODE_UNAUTH, L_ALL, me.name, &me, NULL, 
                         "CGI:IRC auth blocks must have a password");
    return;
  }

  if (!match_conf_password(parv[1], aconf))
  {
    sendto_gnotice_flags(UMODE_UNAUTH, L_ALL, me.name, &me, NULL, 
                         "CGI:IRC password incorrect");
    return;
  }

  memset(&hints, 0, sizeof(hints));

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(parv[2], NULL, &hints, &res))
  {
    sendto_gnotice_flags(UMODE_UNAUTH, L_ALL, me.name, &me, NULL, 
                         "Inavlid CGI:IRC IP %s", parv[2]);
    return;
  }

  assert(res != NULL);

  memcpy(&source_p->ip, res->ai_addr, res->ai_addrlen);
  source_p->ip.ss_len = res->ai_addrlen;
  source_p->ip.ss.ss_family = res->ai_family;
  source_p->aftype = res->ai_family;
  freeaddrinfo(res);

  strlcpy(original_sockhost, source_p->sockhost, sizeof(original_sockhost));
  strlcpy(source_p->sockhost, parv[2], sizeof(source_p->sockhost));

  host = parv[3];

  if(parc == 5)
  {
    if(valid_hostname(parv[3]) == 0)
      strlcpy(source_p->realhost, source_p->sockhost, sizeof(source_p->realhost));
    else
      strlcpy(source_p->realhost, parv[3], sizeof(source_p->realhost));

    host = parv[4];
  }

  if(valid_hostname(host) == 0)
    strlcpy(source_p->host, source_p->sockhost, sizeof(source_p->host));

  /* Check dlines now, k/glines will be checked on registration */
  if ((aconf = find_dline_conf(&client_p->ip,
                                client_p->aftype)))
  {
    if (!(aconf->status & CONF_EXEMPTDLINE))
    {
      exit_client(client_p, &me, "D-lined");
      return;
    }
  }

  sendto_gnotice_flags(UMODE_CCONN, L_ALL, me.name, &me, NULL,
                       "CGI:IRC host/IP set %s to %s", 
                       original_sockhost, host);
}
