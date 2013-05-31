/* log.c - oftc specific server logging

 *   Copyright (C) 2002 Stuart Walsh
 *                      
 *   See file AUTHORS in IRC package for additional names of
 *   the programmers.
 *
 *   This program is free softwmare; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "stdinc.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "sprintf_irc.h"
#include "irc_string.h"

static void mo_log(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  FILE *logfile = NULL;

  if(parc < 2)
    return;

  if (IsClient(source_p) && ((logfile = fopen(OFTCLOG, "a+")) != NULL))
  {
    fprintf(logfile, "%s %s %s\n",
        myctime(time(NULL)), source_p->name, parv[1]);
    fclose(logfile);
  }
  return;
}

struct Message log_msgtab = {
  "LOG", 0, 0, 2, 0, MFLG_SLOW, 0,
  { m_ignore, m_ignore, mo_log, m_ignore, mo_log, m_ignore }
};

void 
module_init(void)
{
  mod_add_cmd(&log_msgtab);
}

void
module_exit(void)
{
  mod_del_cmd(&log_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
