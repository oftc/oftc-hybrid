/**********************************************************************
 *  IRC - Internet Relay Chat, iauth/auth.c
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 1, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  $Id$
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <assert.h>
#include <errno.h>

#include "auth.h"
#include "conf.h"
#include "iauth.h"
#include "log.h"
#include "misc.h"
#include "res.h"
#include "setup.h"

static struct AuthRequest *CreateAuthRequest();
static void FreeAuthRequest(struct AuthRequest *request);
static void LinkAuthRequest(struct AuthRequest *request,
                            struct AuthRequest **list);
static void UnlinkAuthRequest(struct AuthRequest *request,
                              struct AuthRequest **list);

static int BeginIdentQuery(struct AuthRequest *auth);
static char *GetValidIdent(char *buf);

static void BeginDNSQuery(struct AuthRequest *auth);
static void AuthDNSCallback(void* vptr, struct DNSReply* reply);

static void CompleteAuthRequest(struct AuthRequest *auth);

/*
 * List of pending authentication queries
 */
struct AuthRequest *AuthPollList = NULL;

/*
 * List of incomplete authentication queries
 */
struct AuthRequest *AuthIncompleteList = NULL;

/*
StartAuth()
 Begin the authentication process

 parv[0] = "DoAuth"
 parv[1] = client id
 parv[2] = client nickname
 parv[3] = client username
 parv[4] = client hostname
 parv[5] = Client IP Address in unsigned int format
 parv[6] = optional password
*/

void
StartAuth(struct Server *sptr, int parc, char **parv)

{
  struct AuthRequest *auth;

  if (parc < 6)
    return; /* paranoia */

  auth = CreateAuthRequest();

  auth->ip.s_addr = (unsigned int) atol(parv[2]);

  /*
   * If the DNS query fails, we will use the client's
   * ip address
   * bingo - the dns routine should do this when it fails
   */
  strcpy(auth->hostname, inet_ntoa(auth->ip));

  auth->server = sptr;

  if (strlen(parv[1]) > IDLEN)
  {
    /*
     * This should never happen, but just to be paranoid,
     * cancel the auth request
     */
    tosock(auth->server->sockfd,
      "DoneAuth %s ~ %s\n",
      parv[1],
      auth->hostname);

    FreeAuthRequest(auth);
    return;
  }

  strcpy(auth->clientid, parv[1]);

#if 0
  auth->remoteport = (unsigned int) atoi(parv[3]);
  auth->localport = (unsigned int) atoi(parv[4]);
#endif /* 0 */

#if 0
  /*
   * Begin dns query
   */
  BeginDNSQuery(auth);
#endif /* 0 */

#if 0
  /*
   * Begin ident query
   */
  if (BeginIdentQuery(auth))
    LinkAuthRequest(auth, &AuthPollList);
  else if (IsDNSPending(auth))
    LinkAuthRequest(auth, &AuthIncompleteList);
  else
  {
    CompleteAuthRequest(auth);
    FreeAuthRequest(auth);
  }
#endif /* 0 */

  strncpy_irc(auth->nickname, parv[2], NICKLEN);
  strncpy_irc(auth->username, parv[3], USERLEN);
  strncpy_irc(auth->hostname, parv[4], HOSTLEN);

  if (parc >= 7)
    strncpy_irc(auth->password, parv[6], PASSLEN);

  CompleteAuthRequest(auth);
} /* StartAuth() */

/*
CreateAuthRequest()
 Allocate a new AuthRequest structure and return a pointer
to it.
*/

static struct AuthRequest *
CreateAuthRequest()

{
  struct AuthRequest *request;

  request = (struct AuthRequest *) MyMalloc(sizeof(struct AuthRequest));

  memset(request, 0, sizeof(struct AuthRequest));

  request->identfd = NOSOCK;
  request->timeout = time(NULL) + CONNECTTIMEOUT;

  return (request);
} /* CreateAuthRequest() */

/*
FreeAuthRequest()
 Free the given auth request
*/

static void
FreeAuthRequest(struct AuthRequest *request)

{
  MyFree(request);
} /* FreeAuthRequest() */

/*
LinkAuthRequest()
 Link auth request to the specified list
*/

static void
LinkAuthRequest(struct AuthRequest *request, struct AuthRequest **list)

{
  request->prev = NULL;
  request->next = *list;

  if (*list)
    (*list)->prev = request;
  *list = request;
} /* LinkAuthRequest() */

/*
UnlinkAuthRequest()
 Remove auth request from the specified list
*/

static void
UnlinkAuthRequest(struct AuthRequest *request, struct AuthRequest **list)

{
  if (request->next)
    request->next->prev = request->prev;

  if (request->prev)
    request->prev->next = request->next;
  else
    *list = request->next;
} /* UnlinkAuthRequest() */

/*
BeginIdentQuery()
 Begin an ident query for the given auth structure
*/

static int
BeginIdentQuery(struct AuthRequest *auth)

{
  struct sockaddr_in remoteaddr,
                     localaddr;
  int length;
  int fd;

  assert(auth != NULL);

  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    log(L_ERROR,
      "BeginIdentQuery(): Unable to open stream socket: %s",
      strerror(errno));
    return 0;
  }

  if (!SetNonBlocking(fd))
  {
    log(L_ERROR,
      "BeginIdentQuery(): Unable to set socket [%d] non-blocking",
      fd);
    close(fd);
    return 0;
  }

  length = sizeof(struct sockaddr_in);
  memset((void *) &localaddr, 0, length);

  localaddr.sin_port = htons(0);

  if (bind(fd, (struct sockaddr *) &localaddr, sizeof(localaddr)) < 0)
  {
    log(L_ERROR,
      "BeginIdentQuery(): Unable to bind socket [%d]: %s",
      fd,
      strerror(errno));
    close(fd);
    return 0;
  }

  memcpy(&remoteaddr.sin_addr, &auth->ip, sizeof(struct in_addr));

  remoteaddr.sin_port = htons(113);
  remoteaddr.sin_family = AF_INET;

  /*
   * Now, attempt the connection
   */
  if ((connect(fd, (struct sockaddr *) &remoteaddr, sizeof(remoteaddr)) == (-1)) &&
      (errno != EINPROGRESS))
  {
    log(L_ERROR,
      "BeginIdentQuery(): Unable to connect to ident port of %s: %s",
      inet_ntoa(auth->ip),
      strerror(errno));
    close(fd);
    return 0;
  }

  auth->identfd = fd;

  SetIdentConnect(auth);

  return 1;
} /* BeginIdentQuery() */

/*
IdentError()
 An error has occured during the ident process - cleanup
*/

static void
IdentError(struct AuthRequest *auth)

{
  assert(auth != NULL);

  close(auth->identfd);
  auth->identfd = NOSOCK;

  ClearAuth(auth);

  UnlinkAuthRequest(auth, &AuthPollList);

  if (IsDNSPending(auth))
    LinkAuthRequest(auth, &AuthIncompleteList);
  else
  {
    CompleteAuthRequest(auth);
    FreeAuthRequest(auth);
  }
} /* IdentError() */

/*
SendIdentQuery()
 Send an ident query to the auth client
*/

void
SendIdentQuery(struct AuthRequest *auth)

{
  char authbuf[32];

  assert(auth != NULL);

  sprintf(authbuf, "%u , %u\r\n",
    auth->remoteport,
    auth->localport);

  if (send(auth->identfd, authbuf, strlen(authbuf), 0) == (-1))
  {
    log(L_ERROR,
      "SendIdentQuery(): Error sending ident request: %s",
      strerror(errno));
    IdentError(auth);
    return;
  }

  ClearIdentConnect(auth);
  SetIdentPending(auth);
} /* SendIdentQuery() */

/*
ReadIdentReply()
 Read a client's ident reply. We only give it one shot - if
the reply is not valid, fail the authentication.
*/

void
ReadIdentReply(struct AuthRequest *auth)

{
  char buf[ID_BUFSIZE + 1];
  int len;
  char *s = NULL,
       *t;
  int count;

  len = recv(auth->identfd, buf, ID_BUFSIZE, 0);

  if (len > 0)
  {
    buf[len] = '\0';

    if ((s = GetValidIdent(buf)))
    {
      t = auth->username;
      for (count = USERLEN; *s && count; s++)
      {
        if (*s == '@')
          break;

        if ( !isspace(*s) && *s != ':' )
        {
          *t++ = *s;
          --count;
        }
      }
      *t = '\0';
    }
  }

  close(auth->identfd);
  auth->identfd = NOSOCK;
  ClearAuth(auth);
  
  if (!s)
    strcpy(auth->username, "unknown");

  UnlinkAuthRequest(auth, &AuthPollList);

  if (IsDNSPending(auth))
    LinkAuthRequest(auth, &AuthIncompleteList);
  else
  {
    CompleteAuthRequest(auth);
    FreeAuthRequest(auth);
  }
} /* ReadIdentReply() */

/*
 * GetValidIdent - parse ident query reply from identd server
 * 
 * Inputs        - pointer to ident buf
 * Output        - NULL if no valid ident found, otherwise pointer to name
 * Side effects        -
 */

static char *
GetValidIdent(char *buf)

{
  int   remp = 0;
  int   locp = 0;
  char* colon1Ptr;
  char* colon2Ptr;
  char* colon3Ptr;
  char* commaPtr;
  char* remotePortString;

  /* All this to get rid of a sscanf() fun. */
  remotePortString = buf;
  
  colon1Ptr = strchr(remotePortString,':');
  if(!colon1Ptr)
    return 0;

  *colon1Ptr = '\0';
  colon1Ptr++;
  colon2Ptr = strchr(colon1Ptr,':');
  if(!colon2Ptr)
    return 0;

  *colon2Ptr = '\0';
  colon2Ptr++;
  commaPtr = strchr(remotePortString, ',');

  if(!commaPtr)
    return 0;

  *commaPtr = '\0';
  commaPtr++;

  remp = atoi(remotePortString);
  if(!remp)
    return 0;
              
  locp = atoi(commaPtr);
  if(!locp)
    return 0;

  /* look for USERID bordered by first pair of colons */
  if(!strstr(colon1Ptr, "USERID"))
    return 0;

  colon3Ptr = strchr(colon2Ptr,':');
  if(!colon3Ptr)
    return 0;
  
  *colon3Ptr = '\0';
  colon3Ptr++;
  return(colon3Ptr);
} /* GetValidIdent() */

#if 0
/*
BeginDNSQuery()
 Initiate a non-blocking dns query for auth->ip
*/

static void
BeginDNSQuery(struct AuthRequest *auth)

{
  struct DNSQuery query;

  assert(auth != NULL);

  query.vptr = auth;
  query.callback = AuthDNSCallback;

  auth->dns_reply = gethost_byaddr((char *) &auth->ip, &query);
  if (auth->dns_reply)
  {
    /*
     * The client's ip was cached
     */
    strncpy_irc(auth->hostname, auth->dns_reply->hp->h_name, HOSTLEN);
  }
  else
    SetDNSPending(auth);
} /* BeginDNSQuery() */

/*
 * AuthDNSCallback - called when resolver query finishes
 * if the query resulted in a successful search, hp will contain
 * a non-null pointer, otherwise hp will be null.
 * set the client on it's way to a connection completion, regardless
 * of success of failure
 */
static void
AuthDNSCallback(void* vptr, struct DNSReply* reply)

{
  struct AuthRequest* auth = (struct AuthRequest*) vptr;

  ClearDNSPending(auth);

  if (reply)
  {
    struct hostent* hp = reply->hp;
    int i;

    /*
     * Verify that the host to ip mapping is correct both ways and that
     * the ip#(s) for the socket is listed for the host.
     */
    for (i = 0; hp->h_addr_list[i]; ++i)
    {
      if (0 == memcmp(hp->h_addr_list[i], (char*) &auth->ip, sizeof(struct in_addr)))
         break;
    }

    if (hp->h_addr_list[i])
    {
      auth->dns_reply = reply;
      strncpy_irc(auth->hostname, hp->h_name, HOSTLEN);
    }
    /* else IP Mismatch */
  }
  else
  {
    /*
     * DNS query failed - use the ip address as their hostname
     */
    strcpy(auth->hostname, inet_ntoa(auth->ip));
  }

  auth->hostname[HOSTLEN] = '\0';

  if (!IsDoingAuth(auth))
  {
    UnlinkAuthRequest(auth, &AuthIncompleteList);
    FreeAuthRequest(auth);
  }
} /* AuthDNSCallback() */

#endif /* 0 */

/*
CompleteAuthRequest()
 We've completed ident and dns authentication for this client.
Now we must determine if the client passes the other checks, and
if so, tell the client's server the client is acceptable. This
is done as follows:

    DoneAuth <ID> <username> <hostname>

    <ID>           - unique ID for the client
    <username>     - Client's username (ident reply)
    <hostname>     - Client's hostname

 If, however, the client fails one of the checks, a reply
will be given to the client's server of the form:

    BadAuth <ID> :<Reason>

    <ID>           - unique ID for the client
    <Reason>       - Reason the client failed authentication
*/

static void
CompleteAuthRequest(struct AuthRequest *auth)

{
  int badauth = 0;
  int len;
  char buf[BUFSIZE],
       reason[BUFSIZE];
  struct ServerBan *kptr;
  struct Quarantine *qptr;
  struct Iline *iptr = NULL;

  *reason = '\0';

  switch (CheckIline(auth->username, auth->hostname, auth->password, &iptr))
  {
    /*
     * There was no I-line found for this client
     */
    case IL_ERR_NOTAUTHORIZED:
    {
      badauth = 1;
      sprintf(reason,
        "*** You are not authorized to use this server");

      break;
    } /* case IL_ERR_NOTAUTHORIZED */

    /*
     * The I-line is full - the number of users specified
     * in the corresponding Y: line has been reached.
     */
    case IL_ERR_FULL:
    {
      badauth = 1;
      sprintf(reason,
        "*** No more clients allowed in your connection class");

      break;
    } /* case IL_ERR_FULL */

    case IL_ERR_NEEDIDENT:
    {
      badauth = 1;
      sprintf(reason,
        "*** You need to install identd to use this server");

      break;
    } /* case IL_ERR_NOIDENT */

    case IL_ERR_BADPASS:
    {
      badauth = 1;
      sprintf(reason,
        "*** Bad Password");

      break;
    } /* case IL_ERR_BADPASS */

    /*
     * They have an acceptable I-line
     */
    default:
      break;
  }


  if (iptr)
  {
    if (!IsIlineExempt(iptr) &&
        (kptr = FindServerBan(auth->username, auth->hostname)))
    {
      /*
       * They are K-lined
       */
      badauth = 1;
      sprintf(reason,
        "*** Banned: %s",
        kptr->reason);
    }
    else if ((qptr = FindQuarantine(auth->nickname, auth->username, auth->hostname)))
    {
      badauth = 1;
      sprintf(reason,
        "*** Quarantined Nickname: %s",
        qptr->reason);
    }
  } /* if (iptr) */

  if (badauth)
  {
    len = sprintf(buf, "BadAuth %s :%s\n",
      auth->clientid,
      reason);
  }
  else
  {
    assert(iptr != NULL);

    /*
     * If the ident query failed, make their username "~",
     * which will tell the ircd server to use the given
     * ident in the USER statement.
     */
    if (!*auth->username)
      strcpy(auth->username, "~");

  #ifdef SPOOF_FREEFORM

    if (iptr->spoofhost && IsIlineSpoof(iptr))
    {
      strncpy_irc(auth->hostname, iptr->spoofhost, HOSTLEN);
      auth->hostname[HOSTLEN] = '\0';
    }

  #else

    if (auth->server->name)
    {
      /*
       * They have the spoof flag in their I: line, but
       * SPOOF_FREEFORM is not defined - make their
       * hostname: oper.server
       */
      strcpy(auth->hostname, "oper.");
      strncpy_irc(&auth->hostname[5], auth->server->name, HOSTLEN - 5);
    }

  #endif /* SPOOF_FREEFORM */

    len = sprintf(buf, "DoneAuth %s %s %s %d\n",
      auth->clientid,
      auth->username,
      auth->hostname,
      iptr ? iptr->classnum : 0);
  }

  send(auth->server->sockfd, buf, len, 0);
} /* CompleteAuthRequest() */
