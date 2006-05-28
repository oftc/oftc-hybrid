/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_misc.c: Yet another miscellaneous functions file.
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

#define IN_MISC_C
#include "stdinc.h"
#include "s_misc.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "irc_res.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "memory.h"
#include "s_log.h"
#include "event.h"


static const char *months[] =
{
  "January",   "February", "March",   "April",
  "May",       "June",     "July",    "August",
  "September", "October",  "November","December"
};

static const char *weekdays[] =
{
  "Sunday",   "Monday", "Tuesday", "Wednesday",
  "Thursday", "Friday", "Saturday"
};

char *
date(time_t lclock) 
{
  static        char        buf[80], plus;
  struct        tm *lt, *gm;
  struct        tm        gmbuf;
  int        minswest;

  if (!lclock) 
    lclock = CurrentTime;
  gm = gmtime(&lclock);
  memcpy((void *)&gmbuf, (void *)gm, sizeof(gmbuf));
  gm = &gmbuf;
  lt = localtime(&lclock);

  if (lt->tm_yday == gm->tm_yday)
    minswest = (gm->tm_hour - lt->tm_hour) * 60 +
      (gm->tm_min - lt->tm_min);
  else if (lt->tm_yday > gm->tm_yday)
    minswest = (gm->tm_hour - (lt->tm_hour + 24)) * 60;
  else
    minswest = ((gm->tm_hour + 24) - lt->tm_hour) * 60;

  plus = (minswest > 0) ? '-' : '+';
  if (minswest < 0)
    minswest = -minswest;

  ircsprintf(buf, "%s %s %d %d -- %02u:%02u:%02u %c%02u:%02u",
          weekdays[lt->tm_wday], months[lt->tm_mon],lt->tm_mday,
          lt->tm_year + 1900, lt->tm_hour, lt->tm_min, lt->tm_sec,
          plus, minswest/60, minswest%60);

  return(buf);
}

const char *
smalldate(time_t lclock)
{
  static char buf[MAX_DATE_STRING];
  struct tm *lt, *gm;
  struct tm gmbuf;

  if (!lclock)
    lclock = CurrentTime;
  gm = gmtime(&lclock);
  memcpy((void *)&gmbuf, (void *)gm, sizeof(gmbuf));
  gm = &gmbuf; 
  lt = localtime(&lclock);
  
  ircsprintf(buf, "%d/%d/%d %02d.%02d",
             lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday,
             lt->tm_hour, lt->tm_min);

  return(buf);
}

/* small_file_date()
 * Make a small YYYYMMDD formatted string suitable for a
 * dated file stamp. 
 */
char *
small_file_date(time_t lclock)
{
  static char timebuffer[MAX_DATE_STRING];
  struct tm *tmptr;

  if (!lclock)
    time(&lclock);
  tmptr = localtime(&lclock);
  strftime(timebuffer, MAX_DATE_STRING, "%Y%m%d", tmptr);

  return(timebuffer);
}

#define PLUGPARAMS 16


#ifdef HAVE_LIBCRYPTO
static struct {
    int err;
    char *str;
} errtab[] = {
    {SSL_ERROR_NONE, "SSL_ERROR_NONE"},
    {SSL_ERROR_ZERO_RETURN, "SSL_ERROR_ZERO_RETURN"},
    {SSL_ERROR_WANT_READ, "SSL_ERROR_WANT_READ"},
    {SSL_ERROR_WANT_WRITE, "SSL_ERROR_WANT_WRITE"},
    {SSL_ERROR_WANT_CONNECT, "SSL_ERROR_WANT_CONNECT"},
    /*{SSL_ERROR_WANT_ACCEPT, "SSL_ERROR_WANT_ACCEPT"},*/
    {SSL_ERROR_WANT_X509_LOOKUP, "SSL_ERROR_WANT_X509_LOOKUP"},
    {SSL_ERROR_SYSCALL, "SSL_ERROR_SYSCALL"},
    {SSL_ERROR_SSL, "SSL_ERROR_SSL"},
    {-1, NULL}
};

char *get_ssl_error(int sslerr) 
{
    int i;
    
    for (i=0; errtab[i].err != -1; i++)
        if (errtab[i].err == sslerr)
            return errtab[i].str;
    
    return "<NULL>";
}
#endif

void
set_time(void)
{
  struct timeval newtime;
#ifdef _WIN32
  FILETIME ft;

  GetSystemTimeAsFileTime(&ft);
  if (ft.dwLowDateTime < 0xd53e8000)
    ft.dwHighDateTime--;
  ft.dwLowDateTime -= 0xd53e8000;
  ft.dwHighDateTime -= 0x19db1de;

  newtime.tv_sec  = (*(uint64_t *) &ft) / 10000000;
  newtime.tv_usec = (*(uint64_t *) &ft) / 10 % 1000000;
#else
  newtime.tv_sec  = 0;
  newtime.tv_usec = 0;
  gettimeofday(&newtime, NULL);
#endif

  if (newtime.tv_sec < CurrentTime)
  {
    ilog(L_CRIT, "System clock is running backwards - (%lu < %lu)",
         (unsigned long)newtime.tv_sec, (unsigned long)CurrentTime);
    set_back_events(CurrentTime - newtime.tv_sec);
  }

  SystemTime.tv_sec  = newtime.tv_sec;
  SystemTime.tv_usec = newtime.tv_usec;
}

void
libio_init(void)
{
  /* It ain't random, but it ought to be a little harder to guess */
  srand(SystemTime.tv_sec ^ (SystemTime.tv_usec | (getpid() << 20)));

  set_time();
  eventInit();
  fdlist_init();
  init_comm();
#ifndef NOBALLOC
  initBlockHeap();
#endif
  init_dlink_nodes();
  dbuf_init();
#ifndef _WIN32
  init_resolver();
#endif
}
