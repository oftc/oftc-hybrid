/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_info.h: A header for the information sent by /info
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

#ifndef INCLUDED_m_info_h
#define INCLUDED_m_info_h

#include "config.h"

typedef struct Information
{
  char* name;        /* name of item */
  char* strvalue;    /* value of item if it's a boolean */
  int   intvalue;    /* value of item if it's an integer */
  char* desc;        /* short description of item */
} Info;

Info MyInformation[] = {

#ifdef CLIENT_FLOOD
  { "CLIENT_FLOOD", "", CLIENT_FLOOD, "Client Excess Flood Threshold" },
#else
  { "CLIENT_FLOOD", "OFF", 0, "Client Excess Flood Threshold" },
#endif /* CLIENT_FLOOD */

#ifdef CMDLINE_CONFIG
  { "CMDLINE_CONFIG", "ON", 0, "Allow Command Line Specification of Config File" },
#else
  { "CMDLINE_CONFIG", "OFF", 0, "Allow Command Line Specification of Config File" },
#endif /* CMDLINE_CONFIG */

#ifdef CPATH
  { "CPATH", CPATH, 0, "Path to Main Configuration File" },
#else
  { "CPATH", "NONE", 0, "Path to Main Configuration File" },
#endif /* CPATH */

#ifdef CRYPT_OPER_PASSWORD
  { "CRYPT_OPER_PASSWORD", "ON", 0, "Encrypt Operator Passwords" },
#else
  { "CRYPT_OPER_PASSWORD", "OFF", 0, "Encrypt Operator Passwords" },
#endif /* CRYPT_OPER_PASSWORD */

#ifdef DEBUGMODE
  { "DEBUGMODE", "ON", 0, "Support for debugging mode" },
#else
  { "DEBUGMODE", "OFF", 0, "Support for debugging mode" },
#endif /* DEBUGMODE */

#ifdef DPATH
  { "DPATH", DPATH, 0, "Directory Containing Configuration Files" },
#else
  { "DPATH", "NONE", 0, "Directory Containing Configuration Files" },
#endif /* DPATH */

#ifdef DLPATH
  { "DLPATH", DLPATH, 0, "Path to D-line File" },
#else
  { "DLPATH", "NONE", 0, "Path to D-line File" },
#endif /* DLPATH */

  { "HARD_FDLIMIT_", "", HARD_FDLIMIT_, "Maximum Number of File Descriptors Available" },

#ifdef HPATH
  { "HPATH", HPATH, 0, "Path to Operator Help Files" },
#else
  { "HPATH", "NONE", 0, "Path to Operator Help Files" },
#endif /* HPATH */

#ifdef UHPATH
  { "UHPATH", UHPATH, 0, "Path to User Help Files" },
#else
  { "UHPATH", "NONE", 0, "Path to User Help Files" },
#endif /* UH PATH */

#ifdef SOMAXCONN
  { "HYBRID_SOMAXCONN", "", SOMAXCONN, "Maximum Queue Length of Pending Connections" },
#else
  { "HYBRID_SOMAXCONN", "", HYBRID_SOMAXCONN, "Maximum Queue Length of Pending Connections" },
#endif /* SOMAXCONN */

#ifdef IPV6
  { "IPV6", "ON", 0, "IPv6 Support" },
#else
  { "IPV6", "OFF", 0, "IPv6 Support" },
#endif

  { "MAX_CLIENTS", "", MAX_CLIENTS, "Default maximum Clients" },

  { "JOIN_LEAVE_COUNT_EXPIRE_TIME", "", JOIN_LEAVE_COUNT_EXPIRE_TIME, "Anti SpamBot Parameter" },

  { "KILLCHASETIMELIMIT", "", KILLCHASETIMELIMIT, "Nick Change Tracker for KILL" },

#ifdef KPATH
  { "KPATH", KPATH, 0, "Path to K-line File" },
#else
  { "KPATH", "NONE", 0, "Path to K-line File" },
#endif /* KPATH */

#ifdef LPATH
  { "LPATH", LPATH, 0, "Path to Log File" },
#else
  { "LPATH", "NONE", 0, "Path to Log File" },
#endif /* LPATH */

  { "MAX_BUFFER", "", MAX_BUFFER, "Maximum Buffer Connections Allowed" },

  { "MAX_JOIN_LEAVE_COUNT", "", MAX_JOIN_LEAVE_COUNT, "Anti SpamBot Parameter" },

  { "MAXIMUM_LINKS_DEFAULT", "", MAXIMUM_LINKS_DEFAULT, "Default Maximum Links for Class 0" },

  { "MIN_JOIN_LEAVE_TIME", "", MIN_JOIN_LEAVE_TIME, "Anti SpamBot Parameter" },

#ifdef MPATH
  { "MPATH", MPATH, 0, "Path to MOTD File" },
#else
  { "MPATH", "NONE", 0, "Path to MOTD File" },
#endif /* MPATH */

  { "NICKNAMEHISTORYLENGTH", "", NICKNAMEHISTORYLENGTH, "Size of WHOWAS Array" },

#ifdef OPATH
  { "OPATH", OPATH, 0, "Path to Operator MOTD File" },
#else
  { "OPATH", "NONE", 0, "Path to Operator MOTD File" },
#endif /* OPATH */

  { "OPER_SPAM_COUNTDOWN", "", OPER_SPAM_COUNTDOWN, "Anti SpamBot Parameter" },

#ifdef PACE_CONNECT
  { "PACE_CONNECT", "ON", 0, "Pace connections to the ircd" },
#else
  { "PACE_CONNECT", "OFF", 0, "Pace connections to the ircd" },
#endif

#ifdef HAVE_LIBCRYPTO
  { "HAVE_LIBCRYPTO", "ON", 0, "Enable OpenSSL CHALLENGE Support" },
#else
  { "HAVE_LIBCRYPTO", "OFF", 0, "Enable OpenSSL CHALLENGE Support" },
#endif /* HAVE_LIBCRYPTO */

#ifdef HAVE_LIBZ
  { "HAVE_LIBZ", "YES", 0, "zlib (ziplinks) support" },
#else
  { "HAVE_LIBZ", "NO", 0, "zlib (ziplinks)  support" },
#endif /* HAVE_LIBZ */

#ifdef PPATH
  { "PPATH", PPATH, 0, "Path to Pid File" },
#else
  { "PPATH", "NONE", 0, "Path to Pid File" },
#endif /* PPATH */

  { "SELECT_TYPE", SELECT_TYPE, 0, "Method of Multiplexed I/O" },

#ifdef SPATH
  { "SPATH", SPATH, 0, "Path to Server Executable" },
#else
  { "SPATH", "NONE", 0, "Path to Server Executable" },
#endif /* SPATH */

  { "TS_MAX_DELTA_DEFAULT", "", TS_MAX_DELTA_DEFAULT, "Maximum Allowed TS Delta from another Server" },
  { "TS_WARN_DELTA_DEFAULT", "", TS_WARN_DELTA_DEFAULT, "Maximum TS Delta before Sending Warning" },

#ifdef USE_GETTEXT
  { "USE_GETTEXT", "ON", 0, "Use gettext() for message customisation" },
#else
  { "USE_GETTEXT", "OFF", 0, "Use gettext() for message customisation" },
#endif /* USE_GETTEXT */

#ifdef USE_SYSLOG
  { "USE_SYSLOG", "ON", 0, "Log Errors to syslog file" },
#else
  { "USE_SYSLOG", "OFF", 0, "Log Errors to syslog file" },
#endif /* USE_SYSLOG */

  /*
   * since we don't want to include the world here, NULL probably
   * isn't defined by the time we read this, just use plain 0 instead
   * 0 is guaranteed by the language to be assignable to ALL built
   * in types with the correct results.
   */
  { 0, 0, 0, 0 }
};


#endif /* INCLUDED_m_info_h */

