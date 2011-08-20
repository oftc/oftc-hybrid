/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  irc_string.c: IRC string functions.
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
 *  $Id: irc_string.c 593 2006-05-12 05:47:32Z michael $
 */

#include "stdinc.h"
#include "tools.h"
#include "pcre.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "client.h"
#include "list.h"
#include "memory.h"

#ifndef INADDRSZ 
#define INADDRSZ 4
#endif

#ifndef IN6ADDRSZ
#define IN6ADDRSZ 16
#endif

#ifndef INT16SZ
#define INT16SZ 2
#endif


/*
 * myctime - This is like standard ctime()-function, but it zaps away
 *   the newline from the end of that string. Also, it takes
 *   the time value as parameter, instead of pointer to it.
 *   Note that it is necessary to copy the string to alternate
 *   buffer (who knows how ctime() implements it, maybe it statically
 *   has newline there and never 'refreshes' it -- zapping that
 *   might break things in other places...)
 *
 *
 * Thu Nov 24 18:22:48 1986 
 */
const char *
myctime(time_t value)
{
  static char buf[32];
  char *p;

  strcpy(buf, ctime(&value));

  if ((p = strchr(buf, '\n')) != NULL)
    *p = '\0';
  return buf;
}

/*
 * clean_string - clean up a string possibly containing garbage
 *
 * *sigh* Before the kiddies find this new and exciting way of 
 * annoying opers, lets clean up what is sent to local opers
 * -Dianora
 */
char *
clean_string(char* dest, const unsigned char* src, ssize_t len)
{
  char* d    = dest; 
  assert(0 != dest);
  assert(0 != src);

  if(dest == NULL || src == NULL)
    return NULL;
    
  len -= 3;  /* allow for worst case, '^A\0' */

  while (*src && (len > 0))
  {
    if (*src & 0x80)             /* if high bit is set */
      *d++ = '.';
    else if (!IsPrint(*src))       /* if NOT printable */
    {
      *d++ = '^';
      --len;
      *d++ = 0x40 + *src;   /* turn it into a printable */
    }
    else
      *d++ = *src;

    ++src, --len;
  }
  *d = '\0';
  return dest;
}

/*
 * strip_tabs(dst, src, length)
 *
 *   Copies src to dst, while converting all \t (tabs) into spaces.
 */
void
strip_tabs(char *dest, const char *src, size_t len)
{
  char *d = dest;

  /* Sanity check; we don't want anything nasty... */
  assert(dest != NULL);
  assert(src  != NULL);
  assert(len > 0);

  for (; --len && *src; ++src)
    *d++ = *src == '\t' ? ' ' : *src;

  *d = '\0'; /* NUL terminate, thanks and goodbye */
}

/* 
 * From: Thomas Helvey <tomh@inxpress.net>
 */
static const char *IpQuadTab[] =
{
    "0",   "1",   "2",   "3",   "4",   "5",   "6",   "7",   "8",   "9",
   "10",  "11",  "12",  "13",  "14",  "15",  "16",  "17",  "18",  "19",
   "20",  "21",  "22",  "23",  "24",  "25",  "26",  "27",  "28",  "29",
   "30",  "31",  "32",  "33",  "34",  "35",  "36",  "37",  "38",  "39",
   "40",  "41",  "42",  "43",  "44",  "45",  "46",  "47",  "48",  "49",
   "50",  "51",  "52",  "53",  "54",  "55",  "56",  "57",  "58",  "59",
   "60",  "61",  "62",  "63",  "64",  "65",  "66",  "67",  "68",  "69",
   "70",  "71",  "72",  "73",  "74",  "75",  "76",  "77",  "78",  "79",
   "80",  "81",  "82",  "83",  "84",  "85",  "86",  "87",  "88",  "89",
   "90",  "91",  "92",  "93",  "94",  "95",  "96",  "97",  "98",  "99",
  "100", "101", "102", "103", "104", "105", "106", "107", "108", "109",
  "110", "111", "112", "113", "114", "115", "116", "117", "118", "119",
  "120", "121", "122", "123", "124", "125", "126", "127", "128", "129",
  "130", "131", "132", "133", "134", "135", "136", "137", "138", "139",
  "140", "141", "142", "143", "144", "145", "146", "147", "148", "149",
  "150", "151", "152", "153", "154", "155", "156", "157", "158", "159",
  "160", "161", "162", "163", "164", "165", "166", "167", "168", "169",
  "170", "171", "172", "173", "174", "175", "176", "177", "178", "179",
  "180", "181", "182", "183", "184", "185", "186", "187", "188", "189",
  "190", "191", "192", "193", "194", "195", "196", "197", "198", "199",
  "200", "201", "202", "203", "204", "205", "206", "207", "208", "209",
  "210", "211", "212", "213", "214", "215", "216", "217", "218", "219",
  "220", "221", "222", "223", "224", "225", "226", "227", "228", "229",
  "230", "231", "232", "233", "234", "235", "236", "237", "238", "239",
  "240", "241", "242", "243", "244", "245", "246", "247", "248", "249",
  "250", "251", "252", "253", "254", "255"
};

#define SPRINTF(x) ((size_t)ircsprintf x)

/*
 * strlcat and strlcpy were ripped from openssh 2.5.1p2
 * They had the following Copyright info: 
 *
 *
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright    
 *    notice, this list of conditions and the following disclaimer in the  
 *    documentation and/or other materials provided with the distribution. 
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED `AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
#ifndef HAVE_STRLCAT
size_t
strlcat(char *dst, const char *src, size_t siz)
{
  char *d = dst;
  const char *s = src;
  size_t n = siz, dlen;

  while (n-- != 0 && *d != '\0')
    d++;

  dlen = d - dst;
  n    = siz - dlen;

  if (n == 0)
    return(dlen + strlen(s));

  while (*s != '\0')
  {
    if (n != 1)
    {
      *d++ = *s;
      n--;
    }

    s++;
  }

  *d = '\0';
  return dlen + (s - src); /* count does not include NUL */
}
#endif

#ifndef HAVE_STRLCPY
size_t
strlcpy(char *dst, const char *src, size_t siz)
{
  char *d = dst;
  const char *s = src;
  size_t n = siz;

  /* Copy as many bytes as will fit */
  if (n != 0 && --n != 0)
  {
    do
    {
      if ((*d++ = *s++) == 0)
        break;
    } while (--n != 0);
  }

  /* Not enough room in dst, add NUL and traverse rest of src */
  if (n == 0)
  {
    if (siz != 0)
      *d = '\0'; /* NUL-terminate dst */
    while (*s++)
      ;
  }

  return s - src - 1; /* count does not include NUL */
}
#endif

pcre *
ircd_pcre_compile(const char *pattern, const char **errptr)
{
  int erroroffset = 0;
  int options = PCRE_EXTRA;

  assert(pattern);

  return pcre_compile(pattern, options, errptr, &erroroffset, NULL);
}

int
ircd_pcre_exec(const pcre *code, const char *subject)
{
  assert(code && subject);

  return pcre_exec(code, NULL, subject, strlen(subject), 0, 0, NULL, 0) < 0;
}
