/************************************************************************
 *   IRC - Internet Relay Chat, iauth/log.c
 *
 *   This program is free software; you can redistribute it and/or modify
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
 *
 *   $Id$
 */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "iauth.h"
#include "log.h"

/*
 * File descriptor for LOGFILE
 */
int                   LogFileDescriptor = (-1);

static void WriteLog(char *str);

/*
log()
 Make a log entry
*/

void
log(int level, char *format, ...)

{
  char buf[BUFSIZE];
  va_list args;

  assert(LogFileDescriptor >= 0);

  va_start(args, format);
  vsprintf(buf, format, args);
  va_end(args);

  WriteLog(buf);
} /* log() */

static void
WriteLog(char *str)

{
  char buf[BUFSIZE];
  int len;

  assert(LogFileDescriptor >= 0);

  len = sprintf(buf, "%s\n", str);

  write(LogFileDescriptor, buf, len);
} /* WriteLog() */

/*
InitLog()
 Initialize the log file
*/

void
InitLog(char *filename)

{
  LogFileDescriptor = open(filename,
                           O_WRONLY | O_APPEND | O_CREAT | O_NONBLOCK,
                           0644);

  if (LogFileDescriptor < 0)
  {
    fprintf(stderr,
      "Unable to open log file [%s]: %s\n",
      filename,
      strerror(errno));
    exit(-1);
  }
} /* InitLog() */
