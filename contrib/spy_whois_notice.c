/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  spy_whois_notice.c: Sends a notice when someone uses WHOIS.
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
#include "modules.h"
#include "hook.h"
#include "client.h"
#include "ircd.h"
#include "send.h"

int
show_notice(struct hook_mfunc_data *);

void
_modinit(void)
{
  hook_add_hook("doing_whois", (hookfn *)show_notice);
}

void
_moddeinit(void)
{
  hook_del_hook("doing_whois", (hookfn *)show_notice);
}

const char *_version = "$Revision$";

/* show a whois notice
   source_p does a /whois on client_p */
int
show_notice(struct hook_mfunc_data *data)
{
  if (MyConnect(data->source_p) && MyConnect(data->client_p) &&
      IsOper(data->client_p) && (data->client_p != data->source_p) 
      && data->client_p->umodes & FLAGS_SPY) 
    {
      sendto_one(data->client_p, ":%s NOTICE %s :*** Notice -- %s (%s@%s) is doing a whois on you",
                 me.name, data->client_p->name, data->source_p->name, data->source_p->username,
                 data->source_p->host);
    }

  return 0;
}
