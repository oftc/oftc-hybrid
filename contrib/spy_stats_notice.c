/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  spy_stats_notice.c: Sends a notice when someone uses STATS.
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
show_stats(struct hook_stats_data *);

void
_modinit(void)
{
	hook_add_hook("doing_stats", (hookfn *)show_stats);
}

void
_moddeinit(void)
{
	hook_del_hook("doing_stats", (hookfn *)show_stats);
}

const char *_version = "$Revision$";

/* show a stats request */
int
show_stats(struct hook_stats_data *data)
{
  if((data->statchar == 'L') || (data->statchar == 'l'))
    {
      if(data->name != NULL)
	sendto_realops_flags(FLAGS_SPY, L_ALL,
			     "STATS %c requested by %s (%s@%s) [%s] on %s",
			     data->statchar,
			     data->source_p->name,
			     data->source_p->username,
			     data->source_p->host,
			     data->source_p->user->server,
			     data->name);
      else
	sendto_realops_flags(FLAGS_SPY, L_ALL,
			     "STATS %c requested by %s (%s@%s) [%s]",
			     data->statchar,
			     data->source_p->name,
			     data->source_p->username,
			     data->source_p->host,
			     data->source_p->user->server);
    }
  else
    {
      sendto_realops_flags(FLAGS_SPY, L_ALL,
                           "STATS %c requested by %s (%s@%s) [%s]",
			   data->statchar, data->source_p->name, data->source_p->username,
			   data->source_p->host, data->source_p->user->server);
    }

  return 0;
}
