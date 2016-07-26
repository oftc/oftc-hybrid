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

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"
#include "handlers.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "modules.h"
#include "msg.h"
#include "numeric.h"
#include "parse.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "sprintf_irc.h"
#include "stdinc.h"

/* $Id$ */

static void mo_log(struct Client *client_p, struct Client *source_p, int parc,
                   char **parv);

const char *_version = "$Revision: 301 $";

struct Message log_msgtab = {
    "LOG", 0,
    0,     2,
    0,     MFLG_SLOW,
    0,     {m_unregistered, m_not_oper, mo_log, m_ignore, mo_log, m_ignore}};

void
_modinit(void)
{
    mod_add_cmd(&log_msgtab);
}

void
_moddeinit(void)
{
    mod_del_cmd(&log_msgtab);
}

static void
mo_log(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
    FBFILE *logfile = NULL;
    char buf[IRCD_BUFSIZE + NICKLEN];

    if(parc < 2)
        return;

    if(IsClient(source_p) && (logfile = fbopen(OFTCLOG, "a+")) != NULL)
    {
        ircsprintf(buf, "%s %s %s\n", myctime(time(NULL)), source_p->name,
                   parv[1]);
        fbputs(buf, logfile, sizeof(buf));
        fbclose(logfile);
    }
    return;
}
