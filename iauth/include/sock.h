/************************************************************************
 *   IRC - Internet Relay Chat, iauth/sock.h
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

#ifndef INCLUDED_sock_h
#define INCLUDED_sock_h

struct Port;
struct Server;

/*
 * Prototypes
 */

void tosock(int sockfd, char *format, ...);
void InitListenPorts();
int SetNonBlocking(int sockfd);
void CheckConnections();

/*
 * External variable declarations
 */

extern struct Port     *PortList;
extern struct Server   *ServerList;

#define  NOSOCK        (-1)

#define  NICKLEN        9   /* length of nickname */
#define  USERLEN       10   /* length of username */
#define  HOSTLEN       63   /* length of hostname */
#define  IDLEN         50   /* should be ample for a client id */

struct Port
{
  struct Port *next;

  int port;   /* port to listen on */
  int sockfd; /* socket file descriptor */
};

struct Server
{
  struct Server *next, *prev;

  int sockfd;    /* socket descriptor for their connection */
  char *name;    /* server name */
};

#endif /* INCLUDED_sock_h */
