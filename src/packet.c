/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  packet.c: Packet handlers.
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
#include "tools.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_serv.h"
#include "client.h"
#include "common.h"
#include "ircd.h"
#include "list.h"
#include "parse.h"
#include "fdlist.h"
#include "packet.h"
#include "irc_string.h"
#include "memory.h"
#include "hook.h"
#include "send.h"

static char               readBuf[READBUF_SIZE];
static void client_dopacket(struct Client *client_p, char *buffer, size_t length);


/*
 * parse_client_queued - parse client queued messages
 */
static void
parse_client_queued(struct Client *client_p)
{ 
  int dolen = 0;
  int checkflood = 1;
  struct LocalUser *lclient_p = client_p->localClient;

  if(IsUnknown(client_p))
  {
    int i = 0;

    for(;;)
    {
      /* rate unknown clients at MAX_FLOOD per loop */
      if(i >= MAX_FLOOD)
        break;

      dolen = linebuf_get(&client_p->localClient->buf_recvq, readBuf,
                          READBUF_SIZE, LINEBUF_COMPLETE, LINEBUF_PARSED);

      if(dolen <= 0)
        break;
                          
      if(!IsDead(client_p))
      {
        client_dopacket(client_p, readBuf, dolen);
        i++;

        /* if theyve dropped out of the unknown state, break and move
         * to the parsing for their appropriate status.  --fl
         */
        if(!IsUnknown(client_p))
          break;

      }
      else if(MyConnect(client_p))
      {
        linebuf_donebuf(&client_p->localClient->buf_recvq);
        linebuf_donebuf(&client_p->localClient->buf_sendq);
        return;
      }
    }
  }

  if (IsServer(client_p) || IsConnecting(client_p) || IsHandshake(client_p))
  {
    while ((dolen = linebuf_get(&client_p->localClient->buf_recvq,
                              readBuf, READBUF_SIZE, LINEBUF_COMPLETE,
                              LINEBUF_PARSED)) > 0)
    {
      if (!IsDead(client_p))
        client_dopacket(client_p, readBuf, dolen);
      else if(MyConnect(client_p))
      {
        linebuf_donebuf(&client_p->localClient->buf_recvq);
        linebuf_donebuf(&client_p->localClient->buf_sendq);
        return;
      }
    }
  } 
  else if(IsClient(client_p)) 
  {

    if (ConfigFileEntry.no_oper_flood && IsOper(client_p))
      checkflood = 0;
    /*
     * Handle flood protection here - if we exceed our flood limit on
     * messages in this loop, we simply drop out of the loop prematurely.
     *   -- adrian
     */
    for (;;)
    {
      /* This flood protection works as follows:
       *
       * A client is given allow_read lines to send to the server.  Every
       * time a line is parsed, sent_parsed is increased.  sent_parsed
       * is decreased by 1 every time flood_recalc is called.
       *
       * Thus a client can 'burst' allow_read lines to the server, any
       * excess lines will be parsed one per flood_recalc() call.
       *
       * Therefore a client will be penalised more if they keep flooding,
       * as sent_parsed will always hover around the allow_read limit
       * and no 'bursts' will be permitted.
       */
      if(checkflood)
      {
        if(lclient_p->sent_parsed >= lclient_p->allow_read)
          break;
      }
      
      /* allow opers 4 times the amount of messages as users. why 4?
       * why not. :) --fl_
       */
      else if(lclient_p->sent_parsed >= (4 * lclient_p->allow_read))
        break;
       
      dolen = linebuf_get(&client_p->localClient->buf_recvq, readBuf,
                          READBUF_SIZE, LINEBUF_COMPLETE, LINEBUF_PARSED);
			 
      if (!dolen)
        break;
       
      client_dopacket(client_p, readBuf, dolen);
      lclient_p->sent_parsed++;
    }
  }
}

/* flood_endgrace()
 *
 * marks the end of the clients grace period
 */
void
flood_endgrace(struct Client *client_p)
{
  SetFloodDone(client_p);

  /* Drop their flood limit back down */
  client_p->localClient->allow_read = MAX_FLOOD;

  /* sent_parsed could be way over MAX_FLOOD but under MAX_FLOOD_BURST,
   * so reset it.
   */
  client_p->localClient->sent_parsed = 0;
}
	    
/*
 * flood_recalc
 *
 * recalculate the number of allowed flood lines. this should be called
 * once a second on any given client. We then attempt to flush some data.
 */
void
flood_recalc(int fd, void *data)
{
  struct Client *client_p = data;
  struct LocalUser *lclient_p = client_p->localClient;
 
  /* This can happen in the event that the client detached. */
  if (!lclient_p)
    return;

  /* allow a bursting client their allocation per second, allow
   * a client whos flooding an extra 2 per second
   */
  if(IsFloodDone(client_p))
    lclient_p->sent_parsed -= 2;
  else
    lclient_p->sent_parsed = 0;
  
  if(lclient_p->sent_parsed < 0)
    lclient_p->sent_parsed = 0;
  
  if(--lclient_p->actually_read < 0)
    lclient_p->actually_read = 0;

  parse_client_queued(client_p);
  
  /* And now, try flushing .. */
  if (!IsDead(client_p))
  {
    /* and finally, reset the flood check */
    comm_setflush(fd, 1000, flood_recalc, client_p);
  }
}

/*
 * read_ctrl_packet - Read a 'packet' of data from a servlink control
 *                    link and process it.
 */
void
read_ctrl_packet(int fd, void *data)
{
  struct Client *server = data;
  struct LocalUser *lserver = server->localClient;
  struct SlinkRpl *reply;
  int length = 0;
  unsigned char tmp[2];
  unsigned char *len = tmp;
  struct SlinkRplDef *replydef;
#ifndef NDEBUG
  struct hook_io_data hdata;
#endif
 
 
  assert(lserver != NULL);
    
  reply = &lserver->slinkrpl;

  if(IsDead(server))
  {
    return;
  }

  if (!reply->command)
  {
    reply->gotdatalen = 0;
    reply->readdata = 0;
    reply->data = NULL;

    length = recv(fd, tmp, 1, 0);

    if (length <= 0)
    {
      if((length == -1) && ignoreErrno(errno))
        goto nodata;
      error_exit_client(server, length);
      return;
    }

    reply->command = tmp[0];
  }

  for (replydef = slinkrpltab; replydef->handler; replydef++)
  {
    if (replydef->replyid == reply->command)
      break;
  }

  /* we should be able to trust a local slink process...
   * and if it sends an invalid command, that's a bug.. */
  assert(replydef->handler);

  if ((replydef->flags & SLINKRPL_FLAG_DATA) && (reply->gotdatalen < 2))
  {
    /* we need a datalen u16 which we don't have yet... */
    length = recv(fd, len, (2 - reply->gotdatalen), 0);
    if (length <= 0)
    {
      if((length == -1) && ignoreErrno(errno))
        goto nodata;
      error_exit_client(server, length);
      return;
    }

    if (reply->gotdatalen == 0)
    {
      reply->datalen = *len << 8;
      reply->gotdatalen++;
      length--;
      len++;
    }
    if (length && (reply->gotdatalen == 1))
    {
      reply->datalen |= *len;
      reply->gotdatalen++;
      if (reply->datalen > 0)
        reply->data = MyMalloc(reply->datalen);
    }

    if (reply->gotdatalen < 2)
      return; /* wait for more data */
  }

  if (reply->readdata < reply->datalen) /* try to get any remaining data */
  {
    length = recv(fd, (reply->data + reply->readdata),
                  (reply->datalen - reply->readdata), 0);
    if (length <= 0)
    {
      if((length == -1) && ignoreErrno(errno))
        goto nodata;
      error_exit_client(server, length);
      return;
    }

    reply->readdata += length;
    if (reply->readdata < reply->datalen)
      return; /* wait for more data */
  }

#ifndef NDEBUG
  hdata.connection = server;
  hdata.len = reply->command;
  hdata.data = NULL;
  hook_call_event("iorecvctrl", &hdata);
#endif
  
  /* we now have the command and any data, pass it off to the handler */
  (*replydef->handler)(reply->command, reply->datalen, reply->data, server);

  /* reset SlinkRpl */                      
  if (reply->datalen > 0)
    MyFree(reply->data);
  reply->command = 0;

  if (IsDead(server))
    return;

nodata:
  /* If we get here, we need to register for another COMM_SELECT_READ */
  comm_setselect(fd, FDLIST_SERVER, COMM_SELECT_READ,
                 read_ctrl_packet, server, 0);
}
  
/*
 * read_packet - Read a 'packet' of data from a connection and process it.
 */
void
read_packet(int fd, void *data)
{
  struct Client *client_p = data;
  struct LocalUser *lclient_p = client_p->localClient;
  int length = 0;
  int lbuf_len;
  int fd_r; 
  int binary = 0;
#ifndef NDEBUG
  struct hook_io_data hdata;
#endif
  if(IsDead(client_p))
    return;
  
  assert(lclient_p != NULL);
  fd_r = client_p->localClient->fd;

#ifndef HAVE_SOCKETPAIR
  if (HasServlink(client_p))
  {
    assert(client_p->localClient->fd_r > -1);
    fd_r = client_p->localClient->fd_r;
  }
#endif

  /*
   * Read some data. We *used to* do anti-flood protection here, but
   * I personally think it makes the code too hairy to make sane.
   *     -- adrian
   */
  length = recv(fd_r, readBuf, READBUF_SIZE, 0);

  if (length <= 0)
  {
    if((length == -1) && ignoreErrno(errno))
    {
      comm_setselect(fd_r, FDLIST_IDLECLIENT, COMM_SELECT_READ,
      		read_packet, client_p, 0);
      return;
    }  	
    error_exit_client(client_p, length);
    return;
  }

#ifndef NDEBUG
  hdata.connection = client_p;
  hdata.data = readBuf;
  hdata.len = length;
  hook_call_event("iorecv", &hdata);
#endif
  
  if (client_p->lasttime < CurrentTime)
    client_p->lasttime = CurrentTime;
  if (client_p->lasttime > client_p->since)
    client_p->since = CurrentTime;
  client_p->flags &= ~FLAGS_PINGSENT;

  /*
   * Before we even think of parsing what we just read, stick
   * it on the end of the receive queue and do it when its
   * turn comes around.
   */
  if (IsHandshake(client_p) || IsUnknown(client_p))
    binary = 1;

  lbuf_len = linebuf_parse(&client_p->localClient->buf_recvq,
                           readBuf, length, binary);

  if (lbuf_len < 0)
  {
    if (IsClient(client_p))
      sendto_one(client_p, ":%s NOTICE %s :*** - You sent a NULL character in "
                 "your message. Ignored.",
                 me.name, client_p->name);
    else
      exit_client(client_p, client_p, client_p, "NULL character found in message");
    return;
  }

  lclient_p->actually_read += lbuf_len;
  
  /* Attempt to parse what we have */
  parse_client_queued(client_p);
  
  /* Check to make sure we're not flooding */
  if (IsPerson(client_p) &&
     (linebuf_alloclen(&client_p->localClient->buf_recvq) >
      ConfigFileEntry.client_flood))
  {
      if (!(ConfigFileEntry.no_oper_flood && IsOper(client_p)))
      {
       exit_client(client_p, client_p, client_p, "Excess Flood");
       return;
      }
  }

  /* server fd may have changed */
  fd_r = client_p->localClient->fd;
#ifndef HAVE_SOCKETPAIR
  if (HasServlink(client_p))
  {
    assert(client_p->localClient->fd_r > -1);
    fd_r = client_p->localClient->fd_r;
  }
#endif

  
  if (!IsDead(client_p))
  {
    /* If we get here, we need to register for another COMM_SELECT_READ */
    if (PARSE_AS_SERVER(client_p)) {
      comm_setselect(fd_r, FDLIST_SERVER, COMM_SELECT_READ,
        read_packet, client_p, 0);
    } else {
      comm_setselect(fd_r, FDLIST_IDLECLIENT, COMM_SELECT_READ,
        read_packet, client_p, 0);
    }
  }
  /* This is about the only place useful to put it */
  exit_aborted_clients();

}




/*
 * client_dopacket - copy packet to client buf and parse it
 *      client_p - pointer to client structure for which the buffer data
 *             applies.
 *      buffer - pointr to the buffer containing the newly read data
 *      length - number of valid bytes of data in the buffer
 *
 * Note:
 *      It is implicitly assumed that dopacket is called only
 *      with client_p of "local" variation, which contains all the
 *      necessary fields (buffer etc..)
 */
void
client_dopacket(struct Client *client_p, char *buffer, size_t length)
{
  assert(client_p != NULL);
  assert(buffer != NULL);

  if(client_p == NULL || buffer == NULL)
    return;
  /* 
   * Update messages received
   */
  ++me.localClient->receiveM;
  ++client_p->localClient->receiveM;

  /* 
   * Update bytes received
   */
  client_p->localClient->receiveB += length;

  if (client_p->localClient->receiveB > 1023)
  {
    client_p->localClient->receiveK += (client_p->localClient->receiveB >> 10);
    client_p->localClient->receiveB &= 0x03ff; /* 2^10 = 1024, 3ff = 1023 */
  }

  me.localClient->receiveB += length;

  if (me.localClient->receiveB > 1023)
    {
      me.localClient->receiveK += (me.localClient->receiveB >> 10);
      me.localClient->receiveB &= 0x03ff;
    }

  parse(client_p, buffer, buffer + length);
}


