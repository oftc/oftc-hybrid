/************************************************************************
 *   IRC - Internet Relay Chat, iauth/conf.c
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
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "auth.h"
#include "class.h"
#include "conf.h"
#include "iauth.h"
#include "log.h"
#include "match.h"
#include "misc.h"
#include "mtree.h"
#include "setup.h"

/*
 * Configuration file
 */
char                    *ConfigFile = CONFFILE;

/*
 * List of banned users (K-lines)
 */
struct ServerBan        *ServerBanList = NULL;

/*
 * List of allowed users
 */
struct Iline            *IlineList = NULL;

/*
 * List of listen ports
 */
struct Port             *PortList = NULL;

/*
 * List of nickname quarantines
 */
struct Quarantine       *QuarantineList = NULL;

static int ParseConfig(char *filename);
static char *getfield (char *newline);
static void GetUserAndHost(char **user, char **host);

static struct ServerBan *AddServerBan(char *user, char *host,
                                      char *reason, time_t expires);
static void DeleteServerBan(struct ServerBan *kptr);

static char *ParseIlineFlags(struct Iline *iptr, char *user);
static struct Iline *AddIline(char *spoofhost, char *password,
                              char *user, char *host, int class);

static void AddPort(int portnum);

static void AddQuarantine(char *nick, char *reason, char *user, char *host);

/*
ParseConfig()
  Parse configuration file 'filename'

Return: 1 if successful
        0 if unsuccessful
*/

static int
ParseConfig(char *filename)

{
  FILE *fp;
  char buffer[BUFSIZE];
  char *key;
  int linenum;

  if (!(fp = fopen(filename, "r")))
  {
    log(L_ERROR,
      "ParseConfig(): Unable to open configuration file: %s",
      filename);
    return 0;
  }

  linenum = 0;
  while (fgets(buffer, sizeof(buffer) - 1, fp) && ++linenum)
  {
    if (*buffer == '#')
      continue; /* comment */

    if (!(key = getfield(buffer)))
      continue;

    switch (*key)
    {
      /*
       * K-lines (bans)
       */
      case 'k':
      case 'K':
      {
        char *user,
             *host,
             *reason;

        user = getfield(NULL);
        reason = getfield(NULL);

        if (!user || !reason)
        {
          log(L_ERROR,
            "%s:%d Invalid configuration line",
            filename,
            linenum);
          continue;
        }

        GetUserAndHost(&user, &host);

        AddServerBan(user, host, reason, 0);

        break;
      } /* case 'K' */

      /*
       * I-lines (authorization)
       */
      case 'i':
      case 'I':
      {
        char *spoofhost,
             *password,
             *user,
             *host,
             *class;

        spoofhost = getfield(NULL);
        password = getfield(NULL);
        user = getfield(NULL);
        (void) getfield(NULL); /* unused field */
        class = getfield(NULL);

        if (!user || !class)
        {
          log(L_ERROR,
            "%s:%d Invalid configuration line",
            filename,
            linenum);
          continue;
        }

        GetUserAndHost(&user, &host);

        AddIline(spoofhost, password, user, host, atoi(class));

        break;
      } /* case 'I' */

      /*
       * Y-lines (class lines)
       */
      case 'y':
      case 'Y':
      {
        break;
      } /* case 'Y' */

      /*
       * P-lines (listen ports)
       */
      case 'p':
      case 'P':
      {
        char *port;

        port = getfield(NULL);
        if (!port)
        {
          log(L_ERROR,
            "%s:%d Invalid configuration line",
            filename,
            linenum);
          continue;
        }

        AddPort(atoi(port));

        break;
      } /* case 'P' */

      /*
       * Nickname quarantine lines
       */
      case 'q':
      case 'Q':
      {
        char *nick,
             *reason,
             *user,
             *host;

        nick = getfield(NULL);
        reason = getfield(NULL);
        user = getfield(NULL);

        if (!nick)
        {
          log(L_ERROR,
            "%s:%d Invalid configuration line",
            filename,
            linenum);
          continue;
        }

        if (user)
          GetUserAndHost(&user, &host);

        AddQuarantine(nick, reason, user, host);
      } /* case 'Q' */
    } /* switch (*key) */
  }

  fclose(fp);

  return 1;
} /* ParseConfig() */

/*
LoadConfig()
  Call ParseConfig() to load configuration file
*/

void
LoadConfig()

{
  if (!ParseConfig(ConfigFile))
  {
    fprintf(stderr,
      "Unable to parse configuration file: %s\n",
      ConfigFile);
    exit (-1);
  }
} /* LoadConfig() */

/*
getfield()
 Get next field separated by a : in the line
*/

static char *
getfield (char *newline)

{
  static char *line = NULL;
  char *end, *field;
  
  if (newline)
    line = newline;

  if (!line)
    return (NULL);

  field = line;
  if ((end = strchr(line, ':')) == NULL)
  {
    line = NULL;
    if ((end = strchr(field, '\n')) == NULL)
      end = field + strlen(field);
  }
  else
    line = end + 1;

  *end = '\0';
  if (strlen(field))
    return (field);
  else
    return (NULL);
} /* getfield() */

/*
GetUserAndHost()
 Called from ParseConfig() when a possible string fitting
"user@host" is read. Set the 'user' variable to "user" and
the 'host' variable to "host".
 Assume 'user' initially points to the entire string "user@host".
*/

static void
GetUserAndHost(char **user, char **host)

{
  char *ch;

  if ((ch = strchr(*user, '@')))
  {
    *ch++ = '\0';
    *host = ch;
  }
  else
  {
    *host = *user;
    *user = NULL;
  }
} /* GetUserAndHost() */

/*
AddServerBan()
 Add a kline to the list with the given information. Return
pointer to new kline.
*/

static struct ServerBan *
AddServerBan(char *user, char *host, char *reason, time_t expires)

{
  struct ServerBan *ptr;

  ptr = (struct ServerBan *) MyMalloc(sizeof(struct ServerBan));
  memset(ptr, 0, sizeof(struct ServerBan));

  if (user)
    ptr->username = MyStrdup(user);
  else
    ptr->username = MyStrdup("*");

  ptr->hostname = MyStrdup(host);

  if (reason)
    ptr->reason = MyStrdup(reason);
  else
    ptr->reason = MyStrdup("No reason");

  ptr->expires = expires;

  ptr->prev = NULL;
  ptr->next = ServerBanList;
  if (ptr->next)
    ptr->next->prev = ptr;
  ServerBanList = ptr;

  TreeAddKline(ptr);

  return (ptr);
} /* AddServerBan() */

/*
DeleteServerBan()
 Remove kptr from the kline list
*/

static void
DeleteServerBan(struct ServerBan *kptr)

{
} /* DeleteServerBan() */

/*
FindServerBan()
 Determine if 'user' and 'host' match a kline, if so,
return a pointer to it.
*/

struct ServerBan *
FindServerBan(char *user, char *host)

{
  struct ServerBan *tmp;

  tmp = (struct ServerBan *) SearchKlineTree(user, host);
  if (tmp)
    fprintf(stderr, "FOUND KLINE: [%s@%s]\n", tmp->username, tmp->hostname);
  return (tmp);

#if 0
  for (tmp = ServerBanList; tmp; tmp = tmp->next)
  {
    if (match(tmp->username, user) && match(tmp->hostname, host))
      return (tmp);
  }

  return (NULL);
#endif /* 0 */
} /* FindServerBan() */

/*
ParseIlineFlags()
 Determine if iptr has any special flags in it's user field.
If so, update iptr->flags accordingly.

Valid flags:
 =  : spoof their ip
 !  : limit to 1 client per ip
 -  : don't give them a ~ even if they have no identd
 +  : don't let them connect unless they have an ident
 $  :
 %  :
 ^  : user is exempt from K/G lines
 >  : user is also exempt from connection limits
*/

static char *
ParseIlineFlags(struct Iline *iptr, char *user)

{
  while (*user)
  {
    switch (*user)
    {
      case '=':
        SetIlineSpoof(iptr);
        break;

      case '!':
        SetIlineLimit(iptr);
        break;

      case '-':
        SetIlineNoTilde(iptr);
        break;

      case '+':
        SetIlineForceId(iptr);
        break;

#ifdef bingo
      case '$':
        SetIlinePassIdent(iptr);
        break;

      case '%':
        SetIlineNoMatch(iptr);
        break;
#endif /* bingo */

      case '^':
        SetIlineExempt(iptr);
        break;

      case '>':
        SetIlineExempt(iptr);
        SetIlineSuperExempt(iptr);
        break;

      default:
        return (user);
    }

    ++user;
  }

  return (user);
} /* ParseIlineFlags() */

/*
AddIline()
 Allocate a new Iline structure with the given information.
Return a pointer to it.

 Assume everything is NON-NULL, except for user and password. user
may be null in case there was no @ in the userhost field.
*/

static struct Iline *
AddIline(char *spoofhost, char *password, char *user, char *host,
         int class)

{
  struct Iline *ptr;
  char *tmpuser;

  ptr = (struct Iline *) MyMalloc(sizeof(struct Iline));
  memset(ptr, 0, sizeof(struct Iline));

  if (password)
    ptr->password = MyStrdup(password);

  if (user)
  {
    /*
     * If this Iline has any special flags, they would
     * be in the user field - parse them
     */
    tmpuser = ParseIlineFlags(ptr, user);

    ptr->username = MyStrdup(tmpuser);
  }
  else
    ptr->username = MyStrdup("*");

  if (spoofhost && IsIlineSpoof(ptr))
    ptr->spoofhost = MyStrdup(spoofhost);

  ptr->hostname = MyStrdup(host);

  ptr->class = FindClass(class);
  ptr->classnum = class;

  ptr->prev = NULL;
  ptr->next = IlineList;
  if (ptr->next)
    ptr->next->prev = ptr;
  IlineList = ptr;

  /*
   * Add ptr to the Iline tree
   */
  TreeAddIline(ptr);

  return (ptr);
} /* AddIline() */

/*
FindIline()
 Determine if user and host match an I line, if so return
a pointer to it.
*/

struct Iline *
FindIline(char *user, char *host)

{
  struct Iline *iptr;

  for (iptr = IlineList; iptr; iptr = iptr->next)
  {
    if (match(iptr->username, user) && match(iptr->hostname, host))
      return (iptr);
  }

  return (NULL);
} /* FindIline() */

/*
CheckIline()
 Called when a client connects to an ircd server to determine
if they have a valid I: line.

Return values:

IL_ERR_NOTAUTHORIZED - An I-line could not be found matching
                       the given user.

IL_ERR_FULL          - The given Iline is full - no more clients
                       may use it.

IL_ERR_NEEDIDENT     - The given Iline requires identd, and the
                       client did not have an ident reply.

IL_ERR_BADPASS       - The given Iline requires a password, which
                       was not correctly supplied by the client.

IL_ERR_GOODMATCH     - Not actually an error - the client is an
                       acceptable match for the given Iline.

  If the client matches an Iline, the Iline structure is stored
in 'imatch'
*/

int
CheckIline(char *user, char *host, char *pass, struct Iline **imatch)

{
  struct Iline *iptr;

  iptr = (struct Iline *) SearchIlineTree(user, host);
  if (iptr)
    fprintf(stderr, "FOUND IN TREE: [%s@%s]\n", iptr->username, iptr->hostname);

  if (!iptr)
    return (IL_ERR_NOTAUTHORIZED);

  if (iptr->class)
  {
    if ((iptr->class->links >= iptr->class->maxLinks) &&
        !IsIlineSuperExempt(iptr))
      return (IL_ERR_FULL);

    ++iptr->class->links;
  }

  if (IsIlineForceId(iptr) && (*user == '~'))
    return (IL_ERR_NEEDIDENT);

  if (iptr->password && (strcmp(iptr->password, pass) != 0))
    return (IL_ERR_BADPASS);

  *imatch = iptr;

  return (IL_ERR_GOODMATCH);
} /* CheckIline() */

/*
AddPort()
 Add a port number to the list of listen ports
*/

static void
AddPort(int portnum)

{
  struct Port *ptr;

  ptr = (struct Port *) MyMalloc(sizeof(struct Port));
  memset(ptr, 0, sizeof(struct Port));

  ptr->port = portnum;
  ptr->sockfd = NOSOCK;

  ptr->next = PortList;
  PortList = ptr;
} /* AddPort() */

/*
AddQuarantine()
 Add a nickname quarantine with the given information
*/

static void
AddQuarantine(char *nick, char *reason, char *user, char *host)

{
  struct Quarantine *ptr;

  ptr = (struct Quarantine *) MyMalloc(sizeof(struct Quarantine));
  memset(ptr, 0, sizeof(struct Quarantine));

  ptr->nickname = MyStrdup(nick);
  if (reason)
    ptr->reason = MyStrdup(reason);
  else
    ptr->reason = MyStrdup("No reason");

  if (host)
  {
    ptr->hostname = MyStrdup(host);
    if (user)
      ptr->username = MyStrdup(user);
    else
      ptr->username = MyStrdup("*");
  }

  ptr->next = QuarantineList;
  QuarantineList = ptr;
} /* AddQuarantine() */

/*
FindQuarantine()
 Attempt to locate the given nickname in the quarantine list -
return a pointer to it if found
*/

struct Quarantine *
FindQuarantine(char *nick, char *user, char *host)

{
  struct Quarantine *qptr;

  for (qptr = QuarantineList; qptr; qptr = qptr->next)
  {
    if (match(qptr->nickname, nick))
    {
      /*
       * The user may be exempt from this quarantine if
       * their username and hostname match qptr's
       */
      if (qptr->username && qptr->hostname)
      {
        if (match(qptr->username, user) && match(qptr->hostname, host))
          continue;
      }

      return (qptr);
    }
  }

  return (NULL);
} /* FindQuarantine() */
