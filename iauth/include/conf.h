/************************************************************************
 *   IRC - Internet Relay Chat, iauth/conf.h
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

#ifndef INCLUDED_conf_h
#define INCLUDED_conf_h

#ifndef INCLUDED_sys_types_h
#include <sys/types.h>        /* time_t */
#define INCLUDED_sys_types_h
#endif

struct Class;

#define PASSLEN      20 /* max length of I: line passwords */

/*
 * Server bans (K-lines) disallow specific users from connecting
 * to the ircd server.
 */
struct ServerBan
{
  struct ServerBan *next, *prev;

  char *username; /* banned username */
  char *hostname; /* banned hostname */
  char *reason;   /* reason for ban */
  time_t expires; /* ts of when kline expires (0 if permanent) */
};

/*
 * Ilines specify clients who have permission to
 * connect to the ircd server. Clients who do not
 * match an Iline will be denied access.
 *
 * The IL_* defines represent ILine flags.
 */

#define IL_IPLIMIT     (1 << 0) /* allow only 1 connection per ip */
#define IL_EXEMPT      (1 << 1) /* exempt from K/G lines */
#define IL_SUPEREXEMPT (1 << 2) /* exempt from iplimit as well */
#define IL_IPSPOOF     (1 << 3) /* spoof their ip */
#define IL_FORCEID     (1 << 4) /* force client to have an ident */
#define IL_NOTILDE     (1 << 5) /* don't use ~ for non-identd clients */

/*
 * Macros utilizing the IL_* defines
 */

#define SetIlineLimit(x)           ((x)->flags |= IL_IPLIMIT)
#define IsIlineLimit(x)            ((x)->flags &  IL_IPLIMIT)

#define SetIlineExempt(x)          ((x)->flags |= IL_EXEMPT)
#define IsIlineExempt(x)           ((x)->flags &  IL_EXEMPT)

#define SetIlineSuperExempt(x)     ((x)->flags |= IL_SUPEREXEMPT)
#define IsIlineSuperExempt(x)      ((x)->flags &  IL_SUPEREXEMPT)

#define SetIlineSpoof(x)           ((x)->flags |= IL_IPSPOOF)
#define IsIlineSpoof(x)            ((x)->flags &  IL_IPSPOOF)

#define SetIlineForceId(x)         ((x)->flags |= IL_FORCEID)
#define IsIlineForceId(x)          ((x)->flags &  IL_FORCEID)

#define SetIlineNoTilde(x)         ((x)->flags |= IL_NOTILDE)
#define IsIlineNoTilde(x)          ((x)->flags &  IL_NOTILDE)

/*
 * The IL_ERR_* defines represent Iline errors
 */
#define IL_ERR_NOTAUTHORIZED  0 /* client does not match an I-line */
#define IL_ERR_FULL           1 /* I-line is full */
#define IL_ERR_NEEDIDENT      2 /* user requires identd */
#define IL_ERR_BADPASS        3 /* user did not supply correct password */
#define IL_ERR_GOODMATCH      4 /* user is a good match for the Iline */

struct Iline
{
  struct Iline *next, *prev;

  char *username;       /* username of client */
  char *hostname;       /* hostname of client */
  char *spoofhost;      /* hostname to use if IL_IPSPOOF */
  char *password;       /* password client needs (NULL if none) */

  struct Class *class;  /* pointer to class */
  int classnum;         /* class number */
  unsigned int flags;   /* flags for client (IL_*) */
};

/*
 * Nickname quarantines disallow clients from using certain
 * nicknames
 */
struct Quarantine
{
  struct Quarantine *next;

  char *nickname;  /* quarantined nickname */
  char *reason;    /* reason it is quarantined */

  /*
   * Allow users matching username and hostname to use
   * the nickname
   */
  char *username;
  char *hostname;
};

/*
 * Prototypes
 */

void LoadConfig();

struct ServerBan  *FindServerBan(char *user, char *host);
struct Iline      *FindIline(char *user, char *host);
int               CheckIline(char *user, char *host, char *pass,
                             struct Iline **imatch);
struct Class      *FindClass(int classnum);
struct Quarantine *FindQuarantine(char *nick, char *user, char *host);

/*
 * External declarations
 */

extern struct ServerBan       *ServerBanList;
extern struct Iline           *IlineList;

#endif /* INCLUDED_conf_h */
