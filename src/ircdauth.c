/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircdauth.c: Provides an interface to the iAuth process.
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
#include "client.h"
#include "common.h"
#include "fdlist.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "ircd.h"
#include "ircdauth.h"
#include "list.h"
#include "listener.h"
#include "numeric.h"
#include "s_auth.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_user.h"
#include "send.h"
#include "memory.h"
#include "s_serv.h"

static PF CompleteIAuthConnection;
static PF ParseIAuth;

extern dlink_list auth_client_list;

/*
 * This structure will contain the information for the IAuth
 * server.
 */
struct IrcdAuthentication iAuth;

/*
 * Contains data read from IAuth server
 */
static char buffer[BUFSIZE + 1];

/*
 * Array of pointers to each parameter IAuth sends
 */
static char               *param[MAXPARAMS + 1];
static int                paramc;               /* param count */
static char               *nextparam = NULL;    /* pointer to next parameter */

/*
 * If the data read into buffer[] contains several lines,
 * and the last one was cut off in the middle, store it into
 * spill[]. offset is the index of spill[] where we left
 * off.
 */
static char spill[BUFSIZE + 1];
int offset;

static void ProcessIAuthData(int parc, char **parv);
static void GoodAuth(int parc, char **parv);
static void GreetUser(struct Client *client);
static void BadAuth(int parc, char **parv);

/*
ConnectToIAuth()
 Attempt to connect to the Ircd Authentication server.
*/

int
ConnectToIAuth()

{
	struct sockaddr_in ServAddr;
	struct hostent *hostptr;
	struct in_addr *ptr;

	iAuth.socket = comm_open(AF_INET, SOCK_STREAM, 0, "iAuth socket");
	if (iAuth.socket < 0)
	{
    report_error(L_ALL, "ConnectToIAuth(): Unable to open stream socket to %s: %s",
      iAuth.hostname,
      errno);
		iAuth.socket = NOSOCK;
		return(NOSOCK);
	}

  /*
   * bingo - this is blocking :(
   */
  ilog(L_ERROR, "looking up: %s\n", iAuth.hostname);
	if ((hostptr = gethostbyname(iAuth.hostname)) == NULL)
	{
    ilog(L_ERROR, "unsuccessful lookup\n");
		ilog(L_ERROR,
			"Unable to connect to IAuth server: Unknown host");

		fd_close(iAuth.socket);
		iAuth.socket = NOSOCK;
		return(NOSOCK);
	}

	memset((void *) &ServAddr, 0, sizeof(ServAddr));

	ptr = (struct in_addr *) *hostptr->h_addr_list;
	ServAddr.sin_addr.s_addr = ptr->s_addr;

	ServAddr.sin_family = AF_INET;
	ServAddr.sin_port = htons(iAuth.port);

	if (!set_non_blocking(iAuth.socket))
	{
		ilog(L_ERROR,
			"ConnectToIAuth(): set_non_blocking() failed");
		fd_close(iAuth.socket);
		iAuth.socket = NOSOCK;
		return (NOSOCK);
	}

	if (connect(iAuth.socket, (struct sockaddr *) &ServAddr, sizeof(ServAddr)) < 0)
	{
		if (errno != EINPROGRESS)
		{
			ilog(L_ERROR,
				"Unable to connect to IAuth server: %s",
				strerror(errno));
			fd_close(iAuth.socket);
			iAuth.socket = NOSOCK;
			return(NOSOCK);
		}
	}

	SetIAuthConnect(iAuth);

  comm_setselect(iAuth.socket, FDLIST_SERVER, COMM_SELECT_WRITE,
                 CompleteIAuthConnection, NULL, 0);

	return(iAuth.socket);
} /* ConnectToIAuth() */

/*
CompleteIAuthConnection()
 Second portion of non-blocking connect sequence to IAuth.
Return: 1 if successful
        0 if unsuccessful
*/

static void
CompleteIAuthConnection(int fd, void *notused)

{
	int errval;
	unsigned int errlen;

	ClearIAuthConnect(iAuth);

	errval = 0;
	errlen = sizeof(errval);
	if (getsockopt(fd, SOL_SOCKET, SO_ERROR, (void *)&errval, &errlen) < 0)
	{
		ilog(L_ERROR,
			"CompleteIAuthConnection(): getsockopt(SO_ERROR) failed: %s",
			strerror(errno));
/*		return 0; */
    return;
	}

	if (errval > 0)
	{
		ilog(L_ERROR,
			"Connect to IAuth server (%s:%d) failed: %s",
			iAuth.hostname,
			iAuth.port,
			strerror(errval));
		/*return 0;*/
    return;
	}

  comm_setselect(fd, FDLIST_SERVER, COMM_SELECT_READ,
                 ParseIAuth, NULL, 0);

	/*return (1);*/
} /* CompleteIAuthConnection() */

/*
BeginAuthorization()
 Called when a client connects and gives the USER/NICK combo -
send the client's information to the IAuth server to begin
an authorization. The syntax for an auth query is as follows:

    DoAuth <id> <nickname> <username> <hostname> <ip address> [password]

  <id>            - A unique ID for the client so when the
                    authentication completes, we can re-find
                    the client.

  <nickname>      - client's nickname

  <username>      - client's ident reply, or the username
                    given in the USER statement if ident
                    not available.

  <hostname>      - client's resolved hostname.

  <ip address>    - IP Address of the client. This is represented
                    in unsigned int form.

  [password]      - I-line password (if specified)
*/

void
BeginAuthorization(struct Client *client)

{
	char buf[BUFSIZE];
	int len;

	assert(iAuth.socket != NOSOCK);

	/*
	 * The client ID will be the memory address of the
	 * client. This is acceptable, because as long
	 * as the client exists, no other client will have
	 * the same address, thus ensuring a unique ID for
	 * each client.
	 */

        /* XXX - the IPv6 code is very broken */
	len = sprintf(buf,
#ifdef IPV6
		"DoAuth %p %s %s %s %lu %s\n",
#else
		"DoAuth %p %s %s %s %u %s\n",
#endif
		client,
		client->name,
		client->username,
		client->host,
#ifdef IPV6
		(long unsigned int)0,
/*                (unsigned int) client->localClient->ip6.s6_addr, */
#else
		(unsigned int) client->localClient->ip.sins.sin.s_addr,
#endif
		client->localClient->passwd != NULL ?
                client->localClient->passwd : "");

  send(iAuth.socket, buf, len, 0);
} /* BeginAuthorization() */

/*
SendIAuth()
 Send a string to the iauth server
*/

void
SendIAuth(char *format, ...)

{
	va_list args;
	char buf[BUFSIZE];
	int len;

	assert(iAuth.socket != NOSOCK);

	va_start(args, format);

	len = vsprintf(buf, format, args);

	va_end(args);

	send(iAuth.socket, buf, len, 0);
} /* SendIAuth() */

/*
ParseIAuth()
 Read and parse any data from the IAuth server

Return: 0 if connection closed
        1 if successful
        2 if socket is ok, but there's nothing to read
*/

static void
ParseIAuth(int fd, void *notused)

{
	int length; /* number of bytes we read */
	char *ch;
	char *linech;

	/* read in a line */
	length = recv(fd, buffer, BUFSIZE, 0);

	if ((length == (-1)) && ((errno == EWOULDBLOCK) || (errno == EAGAIN)))
    return; /* no error - there's just nothing to read */

	if (length <= 0)
	{
		ilog(L_ERROR, "Read error from server: %s",
			strerror(errno));
    return;
  #if 0
		return 0; /* the connection was closed */
  #endif
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
				param[paramc++] = nextparam;
			}

			/*
			 * Make sure paramc is non-zero, because if the line
			 * starts with a \n, we will immediately come here,
			 * without initializing param[0]
			 */
			if (paramc)
			{
				/* process the line */
				ProcessIAuthData(paramc, param);
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
					param[paramc++] = spill;
					nextparam = linech;
				}
				else if (nextparam)
				{
					param[paramc++] = nextparam;
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

  /*
   * We need to register for another read
   */
  comm_setselect(fd, FDLIST_SERVER, COMM_SELECT_READ,
                 ParseIAuth, NULL, 0);
} /* ParseIAuth() */

/*
ProcessIAuthData()
 Process the data sent by the IAuth server
*/

static void
ProcessIAuthData(int parc, char **parv)

{
	int len;

	len = strlen(parv[0]);

	if (!strncasecmp(parv[0], "DoneAuth", len))
		GoodAuth(parc, parv);
	else if (!strncasecmp(parv[0], "BadAuth", len))
		BadAuth(parc, parv);
} /* ProcessIAuthData() */

/*
GoodAuth()
 Called when an authorization request succeeds - grant the
client access to the server

parv[0] = "DoneAuth"
parv[1] = client id
parv[2] = username
parv[3] = hostname
parv[4] = class
*/

static void
GoodAuth(int parc, char **parv)

{
  struct AuthRequest *auth;
  long id;
  dlink_node *aptr;

/*	assert(parc == 3); */

  id = strtol(parv[1], 0, 0);

  for (aptr = auth_client_list.head; aptr; aptr = aptr->next)
  {
    auth = (struct AuthRequest *) aptr->data;

    /*
     * Remember: the client id is the memory address
     * of auth->client, so if it matches id, we
     * found our client.
     */
    if ((void *) auth->client == (void *) id)
    {
      /*
       * Use IAuth's username, because it may be different
       * if ident failed, but the client's I: line specified
       * no tilde character
       */
      strlcpy(auth->client->username, parv[2], sizeof(auth->client->username));

      /*
       * Also use IAuth's hostname in case of SPOOF_FREEFORM
       */
      strlcpy(auth->client->host, parv[3], sizeof(auth->client->host));

      /*
       * Register them
       */
      GreetUser(auth->client);

      remove_auth_request(auth);
	  
      break;
    }
  }
} /* GoodAuth() */

/*
 * GreetUser()
 * inputs	- pointer to client connecting
 * output	- NONE
 * side effects - Called after a user passes authorization
 *                register them and send them the motd
 */

static void
GreetUser(struct Client *client)

{
  static char ubuf[12];
  dlink_node *m;

  assert(client != NULL);

  client->user->last = CurrentTime;

  sendto_gnotice_flags(UMODE_CCONN, L_ALL, me.name, &me, NULL,
		       "Client connecting: %s (%s@%s) [%s] {%s}",
		       client->name,
		       client->username,
		       client->host,
                       /* XXX - the IPv6 code is very broken */
#ifdef IPV6
		       "",
                       /*inetntoa((char *)&client->localClient->ip6),*/
#else
		       inetntoa((char *)&client->localClient->ip),
#endif
		       get_client_class(client));

  if ((++Count.local) > Count.max_loc)
    {
      Count.max_loc = Count.local;
      if (!(Count.max_loc % 10))
        sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "New Max Local Clients: %d",
                             Count.max_loc);
    }

  SetClient(client);

  client->servptr = find_server(client->user->server->name);
  if (!client->servptr)
    {
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL, "Ghost killed: %s on invalid server %s",
			   client->name,
			   client->user->server->name);

      sendto_one(client, ":%s KILL %s: %s (Ghosted, %s doesn't exist)",
		 me.name,
		 client->name,
		 me.name,
		 client->user->server->name);

      SetKilled(client);

      exit_client(NULL, client, &me, "Ghost");
      return;
    }

  dlinkAdd(client, &client->lnode, &client->servptr->serv->users);

  /* Increment our total user count here */
  if (++Count.total > Count.max_tot)
    Count.max_tot = Count.total;
  
  sendto_one(client, form_str(RPL_WELCOME),
	     me.name,
	     client->name,
	     client->name);

  /* This is a duplicate of the NOTICE but see below...*/
  sendto_one(client, form_str(RPL_YOURHOST),
	     me.name,
	     client->name,
	     get_listener_name(client->localClient->listener), version);
      
  /*
  ** Don't mess with this one - IRCII needs it! -Avalon
  */
  sendto_one(client,
	     "NOTICE %s :*** Your host is %s, running version %s",
	     client->name,
	     get_listener_name(client->localClient->listener),
	     version);

  sendto_one(client, form_str(RPL_CREATED),
	     me.name,
	     client->name,
	     creation);

  sendto_one(client, form_str(RPL_MYINFO),
	     me.name,
	     client->name,
	     me.name,
	     version);

  show_lusers(client);

  if(ConfigFileEntry.short_motd) {
    sendto_one(client,"NOTICE %s :*** Notice -- motd was last changed at %s",
	       client->name,
	       ConfigFileEntry.motd.lastChangedDate);
    
    sendto_one(client,
	       "NOTICE %s :*** Notice -- Please read the motd if you haven't read it",
	       client->name);

    sendto_one(client, form_str(RPL_MOTDSTART),
	       me.name,
	       client->name,
	       me.name);

    sendto_one(client,
	       form_str(RPL_MOTD),
	       me.name,
	       client->name,
	       "*** This is the short motd ***");
    
    sendto_one(client, form_str(RPL_ENDOFMOTD),
	       me.name,
	       client->name);

  }
  else
    send_message_file(client, &ConfigFileEntry.motd);

  send_umode(NULL, client, 0, SEND_UMODES, ubuf);
  if (!*ubuf)
    {
      ubuf[0] = '+';
      ubuf[1] = '\0';
    }
  
  if ((m = dlinkFindDelete(&unknown_list, client)) != NULL)
    free_dlink_node(m);

  dlinkAdd(client, &client->localClient->lclient_node, &local_client_list);

#if 0
  sendto_serv_butone(client,
		     "NICK %s %d %lu %s %s %s %s :%s",
		     client->name,
		     client->hopcount + 1,
		     client->tsinfo,
		     ubuf,
		     client->username,
		     client->host,
		     client->user->server->name,
		     client->info);
#endif

  if (!ServerInfo.hub && uplink && IsCapable(uplink,CAP_LL))
  {
    sendto_one(uplink, "NICK %s %d %lu %s %s %s %s :%s",
		client->name,
		client->hopcount+1,
		(unsigned long) client->tsinfo,
		ubuf,
		client->username, client->host,
		client->user->server->name, client->info);
  }
  else
  {
    /* send to all servers, except LL servers */
    sendto_server(NULL, NULL, NULL, NOCAPS, CAP_LL,
                  NOFLAGS, "NICK %s %d %lu %s %s %s %s :%s",
                  client->name,
                  client->hopcount+1,
                  (unsigned long) client->tsinfo,
                  ubuf,
                  client->username, client->host,
                  client->user->server->name, client->info);
  }
  if (ubuf[1])
  {
    send_umode_out(client, client, 0);
  }
} /* GreetUser() */

/*
BadAuth()
 Called when a client fails authorization - exit them

parv[0] = "BadAuth"
parv[1] = client id
parv[2] = :reason
*/

static void
BadAuth(int parc, char **parv)

{
  struct AuthRequest *auth;
  long id;

  id = strtol(parv[1], 0, 0);
  if ((auth = FindAuthClient(id)))
    {
      exit_client(auth->client, auth->client, &me, parv[2] + 1);
    }
} /* BadAuth() */
