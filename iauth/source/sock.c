/************************************************************************
 *   IRC - Internet Relay Chat, iauth/sock.c
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
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BSD_COMP /* needed on Solaris for FIONBIO */
#include <sys/ioctl.h>

#include "auth.h"
#include "commands.h"
#include "log.h"
#include "iauth.h"
#include "match.h"
#include "misc.h"
#include "res.h"
#include "sock.h"

/*
 * List of all connected ircd servers
 */
struct Server *ServerList = NULL;

static char               buffer[BUFSIZE + 1];

static char               *paramv[MAXPARAMS + 1];
static int                paramc = 0;
static char               *nextparam = NULL;

static char               spill[BUFSIZE + 1];
static int                offset = 0;

static void DoListen(struct Port *portptr);
static void SetSocketOptions(int sockfd);

static int ReadData(struct Server *sptr);
static void ProcessData(struct Server *sptr, int paramc, char **paramv);
static int EstablishConnection(struct Port *portptr);
static void AddServer(struct Server *sptr);
static void DelServer(struct Server *sptr);
static void DoDNSAsync();

/*
tosock()
 Send the given string to sockfd
*/

void
tosock(int sockfd, char *format, ...)

{
  va_list args;
  int len;
  char buf[BUFSIZE];

  va_start(args, format);

  len = vsprintf(buf, format, args);

  va_end(args);

  send(sockfd, buf, len, 0);
} /* tosock() */

/*
DoListen()
 Begin listening on port 'portinfo->port'
*/

static void
DoListen(struct Port *portptr)

{
  struct sockaddr_in sockname;

  assert(portptr != NULL);

  memset((void *) &sockname, 0, sizeof(struct sockaddr));
  sockname.sin_family = AF_INET;
  sockname.sin_addr.s_addr = INADDR_ANY;
  sockname.sin_port = htons(portptr->port);

  if ((portptr->sockfd = socket(PF_INET, SOCK_STREAM, 6)) < 0)
  {
    log(L_ERROR, "Unable to create stream socket: %s",
      strerror(errno));
    portptr->sockfd = NOSOCK;
    return;
  }

  /* set various socket options */
  SetSocketOptions(portptr->sockfd);

  if (bind(portptr->sockfd, (struct sockaddr *)&sockname, sizeof(sockname)) < 0)
  {
    log(L_ERROR, "Unable to bind port %d: %s",
      portptr->port,
      strerror(errno));
    close(portptr->sockfd);
    portptr->sockfd = NOSOCK;
    return;
  }

  if (listen(portptr->sockfd, 4) < 0)
  {
    log(L_ERROR, "Unable to listen on port %d: %s",
      portptr->port,
      strerror(errno));
    close(portptr->sockfd);
    portptr->sockfd = NOSOCK;
    return;
  }

  if (!SetNonBlocking(portptr->sockfd))
  {
    log(L_ERROR, "Unable to set socket [%d] non-blocking",
      portptr->sockfd);
    close(portptr->sockfd);
    portptr->sockfd = NOSOCK;
    return;
  }
} /* DoListen() */

/*
InitListenPorts()
 Initialize listening ports to allow server connections
*/

void
InitListenPorts()

{
  struct Port *portptr;

  for (portptr = PortList; portptr; portptr = portptr->next)
    DoListen(portptr);
} /* InitListenPorts() */

/*
SetSocketOptions()
 Set various socket options on 'sockfd'
*/

static void
SetSocketOptions(int sockfd)

{
  int option;

  option = 1;

  /*
   * SO_REUSEADDR will enable immediate local address reuse of
   * the port this socket is bound to
   */
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) &option, sizeof(option)) < 0)
  {
    log(L_ERROR, "SetSocketOptions(): setsockopt(SO_REUSEADDR) failed: %s",
      strerror(errno));
    return;
  }
} /* SetSocketOptions() */

/*
SetNonBlocking()
 Mark socket as non-blocking

Return: 1 if successful
        0 if unsuccessful
*/

int
SetNonBlocking(int socket)

{
  int flags = 0;

  if ((flags = fcntl(socket, F_GETFL, 0)) == -1)
  {
    log(L_ERROR,
      "SetNonBlocking: fcntl(%d, F_GETFL, 0) failed: %s",
      socket,
      strerror(errno));
    return 0;
  }
  else
  {
    if (fcntl(socket, F_SETFL, flags | O_NONBLOCK) == -1)
    {
      log(L_ERROR,
        "SetNonBlocking: fcntl(%d, F_SETFL, %d) failed: %s",
        socket,
        flags | O_NONBLOCK,
        strerror(errno));
      return 0;
    }
  }

  return 1;
} /* SetNonBlocking() */

/*
CheckConnections()
 Enter a select() loop waiting for socket activity from one
of our ircd connections. Once we receive a request, process
it.
*/

void
CheckConnections()

{
  int activefds; /* result obtained from select() */
  fd_set readfds,
         writefds;
  struct timeval TimeOut;
  struct Port *portptr;
  struct Server *sptr,
                *tmp;
  struct AuthRequest *auth,
                     *auth_next;

  for (;;)
  {
    TimeOut.tv_sec = 1;
    TimeOut.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_ZERO(&writefds);

    /*
     * Check all of our listen ports
     */
    for (portptr = PortList; portptr; portptr = portptr->next)
      if (portptr->sockfd != NOSOCK)
        FD_SET(portptr->sockfd, &readfds);

    /*
     * Check all of our server connections
     */
    for (sptr = ServerList; sptr; sptr = sptr->next)
      FD_SET(sptr->sockfd, &readfds);

    /*
     * Check all of our authentication queries
     */
    for (auth = AuthPollList; auth; auth = auth->next)
    {
      assert (NOSOCK != auth->identfd);

      if (IsIdentConnect(auth))
        FD_SET(auth->identfd, &writefds);
      else /* if (IsIdentPending(auth)) */
        FD_SET(auth->identfd, &readfds);
    }

#if 0
    /*
     * Check dns resolver
     */
    if (ResolverFileDescriptor >= 0)
      FD_SET(ResolverFileDescriptor, &readfds);
#endif

    activefds = select(FD_SETSIZE, &readfds, &writefds, 0, &TimeOut);

    if (activefds > 0)
    {
      /* we got something */

      for (sptr = ServerList; sptr; sptr = sptr->next)
      {
        if (FD_ISSET(sptr->sockfd, &readfds))
        {
          fprintf(stderr, "READING DATA\n");
          if (!ReadData(sptr))
          {
            /*
             * Connection has been closed
             */
            fprintf(stderr, "CONNECTION CLOSED\n");

            close(sptr->sockfd);

            tmp = sptr->prev;

            DelServer(sptr);

            if (tmp)
              sptr = tmp;
            else
              break;

            continue;
          }
        }
      }

      for (portptr = PortList; portptr; portptr = portptr->next)
      {
        if (portptr->sockfd == NOSOCK)
          continue;

        if (FD_ISSET(portptr->sockfd, &readfds))
        {
          fprintf(stderr, "GOT CONNECTION\n");
          /*
           * We have received a new connection, possibly
           * from an ircd - accept it
           */
          if (!EstablishConnection(portptr))
            continue;
        }
      }

      for (auth = AuthPollList; auth; auth = auth_next)
      {
        auth_next = auth->next;

        assert(NOSOCK != auth->identfd);

        if (IsIdentConnect(auth) && FD_ISSET(auth->identfd, &writefds))
          SendIdentQuery(auth);
        else if (FD_ISSET(auth->identfd, &readfds))
          ReadIdentReply(auth);
      }

#if 0
      if ((-1 < ResolverFileDescriptor) &&
          FD_ISSET(ResolverFileDescriptor, &readfds))
        DoDNSAsync();
#endif
    }
    else if ((activefds == (-1)) && (errno != EINTR))
    {
      /*
       * Not good - the connection was closed
       */
    }
  } /* for (;;) */
} /* CheckConnections() */

static int
ReadData(struct Server *sptr)

{
  int length; /* number of bytes we read */
  char *ch;
  char *linech;

  /* read in a line */
  length = recv(sptr->sockfd, buffer, BUFSIZE, 0);

  if ((length == (-1)) && ((errno == EWOULDBLOCK) || (errno == EAGAIN)))
    return 2; /* no error - there's just nothing to read */

  if (length <= 0)
  {
    log(L_ERROR, "Read error from server: %s",
      strerror(errno));
    return 0; /* the connection was closed */
  }

  /*
   * buffer may not be big enough to read the whole last line
   * so it may contain only part of it
   */
  buffer[length] = '\0';

  fprintf(stderr, "%s", buffer);

  /*
   * buffer could possibly contain several lines of info,
   * especially if this is the inital connect burst, so go
   * through, and record each line (until we hit a \n) and
   * process it separately
   */

  ch = buffer;
  linech = spill + offset;

  /*
   * The following routine works something like this:
   * buffer may contain several full lines, and then
   * a partial line. If this is the case, loop through
   * buffer, storing each character in 'spill' until
   * we hit a \n or \r.  When we do, process the line.
   * When we hit the end of buffer, spill will contain
   * the partial line that buffer had, and offset will
   * contain the index of spill where we left off, so the
   * next time we recv() from the hub, the beginning
   * characters of buffer will be appended to the end of
   * spill, thus forming a complete line.
   * If buffer does not contain a partial line, then
   * linech will simply point to the first index of 'spill'
   * (offset will be zero) after we process all of buffer's
   * lines, and we can continue normally from there.
   */

  while (*ch)
  {
    char tmp;

    tmp = *ch;
    if (IsEol(tmp))
    {
      *linech = '\0';

      if (nextparam)
      {
        /*
         * It is possible nextparam will not be NULL here
         * if there is a line like:
         * BadAuth id :Blah
         * where the text after the colon does not have
         * any spaces, so we reach the \n and do not
         * execute the code below which sets the next
         * index of param[] to nextparam. Do it here.
         */
        paramv[paramc++] = nextparam;
      }

      /*
       * Make sure paramc is non-zero, because if the line
       * starts with a \n, we will immediately come here,
       * without initializing paramv[0]
       */
      if (paramc)
      {
        /* process the line */
        ProcessData(sptr, paramc, paramv);
      }

      linech = spill;
      offset = 0;
      paramc = 0;
      nextparam = NULL;

      /*
       * If the line ends in \r\n, then this algorithm would
       * have only picked up the \r. We don't want an entire
       * other loop to do the \n, so advance ch here.
       */
      if (IsEol(*(ch + 1)))
        ch++;
    }
    else
    {
      /* make sure we don't overflow spill[] */
      if (linech >= (spill + (sizeof(spill) - 1)))
      {
        ch++;
        continue;
      }

      *linech++ = tmp;
      if (tmp == ' ')
      {
        /*
         * Only set the space character to \0 if this is
         * the very first parameter, or if nextparam is
         * not NULL. If nextparam is NULL, then we've hit
         * a parameter that starts with a colon (:), so
         * leave it as a whole parameter.
         */
        if (nextparam || (paramc == 0))
          *(linech - 1) = '\0';

        if (paramc == 0)
        {
          /*
           * Its the first parameter - set it to the beginning
           * of spill
           */
          paramv[paramc++] = spill;
          nextparam = linech;
        }
        else if (nextparam)
        {
          paramv[paramc++] = nextparam;
          if (*nextparam == ':')
          {
            /*
             * We've hit a colon, set nextparam to NULL,
             * so we know not to set any more spaces to \0
             */
            nextparam = NULL;

            /*
             * Unfortunately, the first space has already
             * been set to \0 above, so reset to to a
             * space character
             */
            *(linech - 1) = ' ';
          }
          else
            nextparam = linech;

          if (paramc >= MAXPARAMS)
            nextparam = NULL;
        }
      }
      ++offset;
    }

    /*
     * Advance ch to go to the next letter in the buffer
     */
    ++ch;
  } /* while (*ch) */

  return 1;
} /* ReadData() */

#if 0
/*
ReadData()
 Read and parse any incoming data from sptr->sockfd

Return: 0 if unsuccessful
        1 if successful
        2 if the socket is ok, but there's no data to be read
*/

static int
ReadData(struct Server *sptr)

{
  int length; /* number of bytes we read */
  char *ch;

  length = recv(sptr->sockfd, buffer, sizeof(buffer) - 1, 0);

  if ((length == (-1)) &&
      ((errno == EWOULDBLOCK) || (errno == EAGAIN)))
    return 2; /* no data to read */

  if (length <= 0)
  {
    /*
     * Connection closed
     */
    log(L_ERROR, "IAuth: Read error from server: %s",
      strerror(errno));
    return 0;
  }

  buffer[length] = '\0';

  fprintf(stderr, "%s", buffer);

  ch = buffer;

  /*
   * The following routine works something like this:
   * We receive a line from the ircd process, but we
   * wish to break it up by inserting NULLs where
   * there are spaces, and keeping pointers to the
   * beginning of each "word". paramv[] will be
   * our array of pointers and paramc will be the
   * number of parameters we have in paramv[].
   */

  paramc = 0;
  paramv[paramc++] = buffer;

  while (*ch)
  {
    char tmp;

    tmp = *ch;

    if (IsEol(tmp))
    {
      /*
       * We've reached the end of our line - process it
       */

      *ch = '\0';

      if (paramc)
        ProcessData(sptr, paramc, paramv);

      break;
    }
    else
    {
      if (tmp == ' ')
      {
        *ch++ = '\0';
        while (IsSpace(*ch) && !IsEol(*ch))
          ++ch;

        if (IsEol(*ch))
          continue;
        paramv[paramc++] = ch;
      }
    }

    /*
     * Advance ch to the next letter in buffer[]
     */
    ++ch;
  } /* while (*ch) */

  return 1;
} /* ReadData() */
#endif

/*
ProcessData()
 Inputs: sptr - ircd server we read data from
         paramc - number of parameters in paramv[]
         paramv - array of pointers to individual parameters
                  sent by the parent ircd process

 Purpose: Process the data contained in paramv[] and call
          the corresponding function to handle it

 Return: none
*/

static void
ProcessData(struct Server *sptr, int paramc, char **paramv)

{
  struct CommandTable *cmdptr;

  for (cmdptr = Commands; cmdptr->name; cmdptr++)
  {
    if (!strcasecmp(paramv[0], cmdptr->name))
    {
      /*
       * Call the corresponding function
       */
      (*cmdptr->func)(sptr, paramc, paramv);
      break;
    }
  }
} /* ProcessData() */

/*
EstablishConnection()
 Accept the new connection which has occured on portptr->port -
most likely from an ircd connection
*/

static int
EstablishConnection(struct Port *portptr)

{
  struct sockaddr_in ClientAddr;
  int clientlen;
  struct Server *newconn;

  assert(portptr != NULL);

  newconn = (struct Server *) MyMalloc(sizeof(struct Server));
  memset(newconn, 0, sizeof(struct Server));

  clientlen = sizeof(ClientAddr);
  newconn->sockfd = accept(portptr->sockfd, (struct sockaddr *) &ClientAddr, &clientlen);

  if (newconn->sockfd < 0)
  {
    log(L_ERROR, "EstablishConnection(): Error accepting connection: %s",
      strerror(errno));
    MyFree(newconn);
    return 0;
  }

  if (!SetNonBlocking(newconn->sockfd))
  {
    log(L_ERROR, "EstablishConnection(): Unable to set socket [%d] non-blocking",
      newconn->sockfd);
    MyFree(newconn);
    return 0;
  }

  /*
   * All of newconn's fields have been filled in, just add it
   * to the list
   */
  AddServer(newconn);

  return 1;
} /* EstablishConnection() */

/*
AddServer()
 Insert 'sptr' into the beginning of ServerList;
*/

static void
AddServer(struct Server *sptr)

{
  assert(sptr != NULL);

  sptr->prev = NULL;
  sptr->next = ServerList;
  if (sptr->next)
    sptr->next->prev = sptr;
  ServerList = sptr;
} /* AddServer() */

/*
DelServer()
 Delete 'sptr' from ServerList
*/

static void
DelServer(struct Server *sptr)

{
  assert(sptr != NULL);

  if (sptr->next)
    sptr->next->prev = sptr->prev;
  if (sptr->prev)
    sptr->prev->next = sptr->next;
  else
    ServerList = sptr->next;

  MyFree(sptr);
} /* DelServer() */

/*
 * DoDNSAsync - called when the fd returned from init_resolver() has 
 * been selected for reading.
 */
static void
DoDNSAsync()

{
  int bytes = 0;
  int packets = 0;

#if 0
  do
  {
    get_res();
    if (ioctl(ResolverFileDescriptor, FIONREAD, &bytes) == -1)
      bytes = 0;
    packets++;
  }  while ((bytes > 0) && (packets < 10)); 
#endif
} /* DoDNSAsync() */
