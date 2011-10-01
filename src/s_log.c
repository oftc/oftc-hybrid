/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_log.c: Logger functions.
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

#include "s_log.h"
#include "fileio.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "s_misc.h"
#include "s_conf.h"
#include "memory.h"

/* some older syslogs would overflow at 2024 */
#define LOG_BUFSIZE 2000

static struct {
  char path[PATH_MAX + 1];
  size_t size;
  FBFILE *file;
} log_type_table[LOG_TYPE_LAST];


int
log_add_file(unsigned int type, size_t size, const char *path)
{
  if (log_type_table[type].file)
    fbclose(log_type_table[type].file);
  else
    log_type_table[type].file = MyMalloc(sizeof(FBFILE));

  strlcpy(log_type_table[type].path, path, sizeof(log_type_table[type].path));

  return (log_type_table[type].file = fbopen(path, "a")) != NULL;
}

void
log_close_all(void)
{
  unsigned int type = 0;

  while (++type < LOG_TYPE_LAST)
  {
    if (log_type_table[type].file == NULL)
      continue;

    fbclose(log_type_table[type].file);
    MyFree(log_type_table[type].file);
  }
}

static void 
write_log(unsigned int type, const char *message)
{
  char buf[LOG_BUFSIZE];
  size_t nbytes = 0;

  if (log_type_table[type].file == NULL)
    return;

  if (ConfigLoggingEntry.timestamp)
    nbytes = snprintf(buf, sizeof(buf), "[%s] %s\n",
                      smalldate(CurrentTime), message);
  else
    nbytes = snprintf(buf, sizeof(buf), "%s\n", message);

  fbputs(buf, log_type_table[type].file, nbytes);
}
   
void
ilog(unsigned int type, const char *fmt, ...)
{
  char buf[LOG_BUFSIZE];
  va_list args;

  assert(fmt);
  assert(type >= 0 && type < LOG_TYPE_LAST);

  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);

  if (ConfigLoggingEntry.use_logging)
    write_log(type, buf);
} 
