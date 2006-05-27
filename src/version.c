/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
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
#include "patchlevel.h"
#include "serno.h"
#include "ircd.h"
#ifndef _WIN32
#include <sys/utsname.h>
#else
#endif

const char *ircd_version = PATCHLEVEL;
const char *serno = SERIALNUM;

#ifdef _WIN32
/* Copyright (C) 2001 Free Software Foundation, Inc.
 *
 * Get name and information about current kernel.
 */
int
uname(struct utsname *uts)
{
  enum { WinNT, Win95, Win98, WinUnknown };
  OSVERSIONINFO osver;
  SYSTEM_INFO sysinfo;
  DWORD sLength;
  DWORD os = WinUnknown;

  memset(uts, 0, sizeof(*uts));

  osver.dwOSVersionInfoSize = sizeof (osver);
  GetVersionEx (&osver);
  GetSystemInfo (&sysinfo);

  switch (osver.dwPlatformId)
    {
    case VER_PLATFORM_WIN32_NT: /* NT, Windows 2000 or Windows XP */
      if (osver.dwMajorVersion == 4)
        strcpy (uts->sysname, "Windows NT4x"); /* NT4x */
      else if (osver.dwMajorVersion <= 3)
        strcpy (uts->sysname, "Windows NT3x"); /* NT3x */
      else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion  < 1)
        strcpy (uts->sysname, "Windows 2000"); /* 2k */
      else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 2)
        strcpy (uts->sysname, "Windows 2003"); /* 2003 */
      else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)
        strcpy (uts->sysname, "Windows XP");   /* XP */
      os = WinNT;
      break;

    case VER_PLATFORM_WIN32_WINDOWS: /* Win95, Win98 or WinME */
      if ((osver.dwMajorVersion > 4) || 
          ((osver.dwMajorVersion == 4) && (osver.dwMinorVersion > 0)))
        {
	  if (osver.dwMinorVersion >= 90)
	    strcpy (uts->sysname, "Windows ME"); /* ME */
	  else
	    strcpy (uts->sysname, "Windows 98"); /* 98 */
          os = Win98;
        }
      else
        {
          strcpy (uts->sysname, "Windows 95"); /* 95 */
          os = Win95;
        }
      break;

    case VER_PLATFORM_WIN32s: /* Windows 3.x */
      strcpy (uts->sysname, "Windows");
      break;
    }

  sprintf (uts->version, "%ld.%02ld", 
           osver.dwMajorVersion, osver.dwMinorVersion);

  if (osver.szCSDVersion[0] != '\0' &&
      (strlen (osver.szCSDVersion) + strlen (uts->version) + 1) < 
      sizeof (uts->version))
    {
      strcat (uts->version, " ");
      strcat (uts->version, osver.szCSDVersion);
    }

  sprintf (uts->release, "build %ld", osver.dwBuildNumber & 0xFFFF);

  switch (sysinfo.wProcessorArchitecture)
    {
    case PROCESSOR_ARCHITECTURE_PPC:
      strcpy (uts->machine, "ppc");
      break;
    case PROCESSOR_ARCHITECTURE_ALPHA:
      strcpy (uts->machine, "alpha");
      break;
    case PROCESSOR_ARCHITECTURE_MIPS:
      strcpy (uts->machine, "mips");
      break;
    case PROCESSOR_ARCHITECTURE_INTEL:
      /* 
       * dwProcessorType is only valid in Win95 and Win98 and WinME
       * wProcessorLevel is only valid in WinNT 
       */
      switch (os)
        {
        case Win95:
        case Win98:
          switch (sysinfo.dwProcessorType)
            {
            case PROCESSOR_INTEL_386:
            case PROCESSOR_INTEL_486:
            case PROCESSOR_INTEL_PENTIUM:
              sprintf (uts->machine, "i%ld", sysinfo.dwProcessorType);
              break;
            default:
              strcpy (uts->machine, "i386");
              break;
          }
          break;
        case WinNT:
          switch(sysinfo.wProcessorArchitecture)
            {
            case PROCESSOR_ARCHITECTURE_INTEL:
              sprintf (uts->machine, "x86(%d)", sysinfo.wProcessorLevel);
              break;
            case PROCESSOR_ARCHITECTURE_IA64:
              sprintf (uts->machine, "ia64(%d)", sysinfo.wProcessorLevel);
              break;
#ifdef PROCESSOR_ARCHITECTURE_AMD64
            case PROCESSOR_ARCHITECTURE_AMD64:
              sprintf (uts->machine, "x86_64(%d)", sysinfo.wProcessorLevel);
              break;
#endif
            default:
              sprintf (uts->machine, "unknown(%d)", sysinfo.wProcessorLevel);
              break;
            }
          break;
        default:
          strcpy (uts->machine, "unknown");
          break;
      }
      break;
    default:
      strcpy (uts->machine, "unknown");
      break;
  }
  
  sLength = sizeof (uts->nodename) - 1;
  GetComputerName (uts->nodename, &sLength);
  return 0;
}
#endif

char *
get_ircd_platform(char *str)
{
  struct utsname uts;

  uname(&uts);
  snprintf(str, PLATFORMLEN, "%s %s %s %s %s", uts.sysname, uts.nodename,
           uts.release, uts.version, uts.machine);
  return str;
}

const char *infotext[] =
{
  "IRC --",
  "Based on the original code written by Jarkko Oikarinen",
  "Copyright 1988, 1989, 1990, 1991 University of Oulu, Computing Center",
  "Copyright (c) 1996-2005 Hybrid Development Team", 
  "",
  "This program is free software; you can redistribute it and/or",
  "modify it under the terms of the GNU General Public License as",
  "published by the Free Software Foundation; either version 2, or",
  "(at your option) any later version.",
  "",
  "",
  "The hybrid team is a group of ircd coders who were frustrated",
  "with the instability and all-out dirtiness of the EFnet ircd's",
  "available. hybrid is the name for the collective efforts of a group",
  "of people, all of us.",
  "",
  "Anyone is welcome to contribute to this effort. You are encouraged",
  "to participate in the Hybrid mailing list. To subscribe to the",
  "Hybrid List, use this link:",
  "  https://lists.ircd-hybrid.org/mailman/listinfo/hybrid",
  "",
  "The core team as, of this major release:",
  "",
  "adx, Piotr Nizynski <adx@irc7.pl>",
  "billy-jon, William Bierman III <bill@mu.org>",
  "cryogen, Stuart Walsh <stu@ipng.org.uk>",
  "Dianora, Diane Bruce <db@db.net>",
  "joshk, Joshua Kwan <joshk@triplehelix.org>",
  "knight, Alan LeVee <alan.levee@prometheus-designs.net>",
  "metalrock, Jack Low <jclow@csupomona.edu>",
  "Michael, Michael Wobst <michael.wobst@gmail.com>",
  "Rodder, Jon Lusky <lusky@blown.net>",
  "Wohali, Joan Touzet <joant@ieee.org>",
  "",
  "The following people have contributed blood, sweat, and/or code to",
  "recent releases of Hybrid, in nick alphabetical order:",
  "",
  "A1kmm, Andrew Miller <a1kmm@mware.virtualave.net>",
  "AndroSyn, Aaron Sethman <androsyn@ratbox.org>",
  "bane, Dragan Dosen <bane@idolnet.org>",
  "bysin, Ben Kittridge <bkittridge@cfl.rr.com>",
  "cosine, Patrick Alken <wnder@uwns.underworld.net>",
  "David-T, David Taylor <davidt@yadt.co.uk>",
  "fl, Lee Hardy <lee@leeh.co.uk>",
  "Garion, Joost Vunderink <garion@efnet.nl>",
  "Habeeb, David Supuran <habeeb@cfl.rr.com>",
  "Hwy101, W. Campbell <wcampbel@botbay.net>",
  "jmallett, Juli Mallett <jmallett@FreeBSD.org>",
  "jv, Jakub Vlasek <jv@pilsedu.cz>",
  "k9, Jeremy Chadwick <ircd@jdc.parodius.com>",
  "kire, Erik Small <smalle@hawaii.edu>",
  "kre, Dinko Korunic <kreator@fly.srk.fer.hr>",
  "madmax, Paul Lomax <madmax@efnet.org>",
  "nenolod, William Pitcock <nenolod@nenolod.net>",
  "Riedel, Dennis Vink, <riedel@chaotic.nl>",
  "scuzzy, David Todd <scuzzy@aniverse.net>",
  "spookey, David Colburn <spookey@spookey.org>",
  "TimeMr14C, Yusuf Iskenderoglu <uhc0@stud.uni-karlsruhe.de>",
  "toot, Toby Verrall <to7@antipope.fsnet.co.uk>",
  "vx0, Mark Miller <mark@oc768.net>",
  "wiz, Jason Dambrosio <jason@wiz.cx>",
  "Xride, Søren Straarup <xride@x12.dk>",
  "zb^3, Alfred Perlstein <alfred@freebsd.org>",
  "",
  "Others are welcome. Always. And if we left anyone off the above list,",
  "be sure to let us know that too. Many others have contributed to",
  "previous versions of this ircd and its ancestors, too many to list",
  "here.",
  "",
  "Send bug fixes/complaints/rotten tomatoes to bugs@ircd-hybrid.org.",
  "", 0
};
