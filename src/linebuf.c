/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  linebuf.c: Maintains linebuffers.
 *
 *  Copyright (C) 2001-2002 Adrian Chadd <adrian@creative.net.au>
 *  Copyright (C) 2002 Hybrid Development Team
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
#include "client.h"
#include "linebuf.h"
#include "memory.h"
#include "event.h"
#include "list.h"
#include "balloc.h"
#include "hook.h"

#ifdef STRING_WITH_STRINGS
# include <string.h>
# include <strings.h>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  ifdef HAVE_STRINGS_H
#   include <strings.h>
#  endif
# endif
#endif

static BlockHeap *linebuf_heap;

static int bufline_count = 0;


/*
 * linebuf_init
 *
 * Initialise the linebuf mechanism
 */

static void linebuf_garbage_collect(void *unused)
{
  BlockHeapGarbageCollect(linebuf_heap);
}
      

void
linebuf_init(void)
{
  linebuf_heap  = BlockHeapCreate(sizeof(buf_line_t), LINEBUF_HEAP_SIZE);
  eventAddIsh("linebuf_garbage_collect", linebuf_garbage_collect, NULL, 30);
}

static buf_line_t *
linebuf_allocate(void)
{
  buf_line_t *t;
  t = BlockHeapAlloc(linebuf_heap);
  assert(t != NULL);
  if(t == NULL)
    return NULL;
  t->refcount = 0;
  return(t);
 
}

static void
linebuf_free(buf_line_t *p)
{
   BlockHeapFree(linebuf_heap, p);
}

/*
 * linebuf_new_line
 *
 * Create a new line, and link it to the given linebuf.
 * It will be initially empty.
 */
static buf_line_t *
linebuf_new_line(buf_head_t *bufhead)
{
  buf_line_t *bufline;
  dlink_node *node;

  bufline = linebuf_allocate();
  if(bufline == NULL)
    return NULL;
  ++bufline_count;
  
  
  node = make_dlink_node();
  
  bufline->len = 0;
  bufline->terminated = 0;
  bufline->flushing = 0;
  bufline->raw = 0;

  /* Stick it at the end of the buf list */
  dlinkAddTail(bufline, node, &bufhead->list);
  bufline->refcount++;

  /* And finally, update the allocated size */
  bufhead->alloclen++;
  bufhead->numlines++;

  return bufline;
}


/*
 * linebuf_done_line
 *
 * We've finished with the given line, so deallocate it
 */
static void
linebuf_done_line(buf_head_t *bufhead, buf_line_t *bufline,
                  dlink_node *node)
{
  /* Remove it from the linked list */
  dlinkDelete(node, &bufhead->list);
  free_dlink_node(node);

  /* Update the allocated size */
  bufhead->alloclen--;
  bufhead->len -= bufline->len;
  assert(bufhead->len >= 0);
  bufhead->numlines--;

  bufline->refcount--;
  assert(bufline->refcount >= 0);

  if (bufline->refcount == 0)
  {
    /* and finally, deallocate the buf */
    --bufline_count;
    assert(bufline_count >= 0);
    linebuf_free(bufline);
  }
}


/*
 * skip to end of line or the crlfs, return the number of bytes ..
 */
static inline int
linebuf_skip_crlf(char *ch, int len)
{
  int orig_len = len;
  
  /* First, skip until the first non-CRLF */
  for(; len; len--, ch++)
    {
      if (*ch == '\r')
	break;
      else if(*ch == '\n')
        break;
      else if (*ch == 0)
        return -1;
    }

  /* Then, skip until the last CRLF */
  for(; len; len--, ch++)
    {
      if ((*ch != '\r') && (*ch != '\n'))
        break;
    }
  assert(orig_len > len);
  return(orig_len - len);
}



/*
 * linebuf_newbuf
 *
 * Initialise the new buffer
 */
void
linebuf_newbuf(buf_head_t *bufhead)
{
  /* not much to do right now :) */
  memset(bufhead, 0, sizeof(buf_head_t));
}

/*
 * client_flush_input
 *
 * inputs	- pointer to client
 * output	- none
 * side effects - all input line bufs are flushed 
 */
void
client_flush_input(struct Client *client_p)
{
  /* This way, it can be called for remote client as well */

  if(client_p->localClient == NULL)
    return;

  linebuf_donebuf(&client_p->localClient->buf_recvq);
}


/*
 * linebuf_donebuf
 *
 * Flush all the lines associated with this buffer
 */
void
linebuf_donebuf(buf_head_t *bufhead)
{
    while (bufhead->list.head != NULL)
      {
       linebuf_done_line(bufhead, (buf_line_t *)bufhead->list.head->data,
                         bufhead->list.head);
      }
}

/*
 * linebuf_copy_line
 *
 * Okay..this functions comments made absolutely no sense.
 * 
 * Basically what we do is this.  Find the first chunk of text
 * and then scan for a CRLF.  If we didn't find it, but we didn't
 * overflow our buffer..we wait for some more data.
 * If we found a CRLF, we replace them with a \0 character.
 * If we overflowed, we copy the most our buffer can handle, terminate
 * it with a \0 and return.
 *
 * The return value is the amount of data we consumed.  This could
 * be different than the size of the linebuffer, as when we discard
 * the overflow, we don't want to process it again.
 *
 * This still sucks in my opinion, but it seems to work.
 *
 * -Aaron
 */
static int
linebuf_copy_line(buf_head_t *bufhead, buf_line_t *bufline,
                  char *data, int len)
{
  int cpylen = 0;	/* how many bytes we've copied */
  char *ch = data;	/* Pointer to where we are in the read data */
  char *bufch = bufline->buf + bufline->len;
  int clen = 0;                 /* how many bytes we've processed,
                                   and don't ever want to see again.. */

  /* If its full or terminated, ignore it */

  bufline->raw = 0;
  assert(bufline->len < BUF_DATA_SIZE);
  if (bufline->terminated == 1)
    return 0;

  clen = cpylen = linebuf_skip_crlf(ch, len);
  if (clen == -1)
    return -1;

  /* This is the ~overflow case..This doesn't happen often.. */
  if(cpylen > (BUF_DATA_SIZE - bufline->len - 1))
    {
      memcpy(bufch, ch, (BUF_DATA_SIZE - bufline->len - 1));
      bufline->buf[BUF_DATA_SIZE-1] = '\0';
      bufch = bufline->buf + BUF_DATA_SIZE - 2;
      while(cpylen && (*bufch == '\r' || *bufch == '\n'))
        {
          *bufch = '\0';
          cpylen--;
          bufch--;
        }
      bufline->terminated = 1;
      bufline->len = BUF_DATA_SIZE - 1;
      bufhead->len += BUF_DATA_SIZE - 1;
      return clen;
    }

  memcpy(bufch, ch, cpylen);
  bufch += cpylen;
  *bufch = '\0';
  bufch--;

  if(*bufch != '\r' && *bufch != '\n')
    { 
      /* No linefeed, bail for the next time */
      bufhead->len += cpylen;
      bufline->len += cpylen;
      bufline->terminated = 0;
      return clen;
    }

  /* Yank the CRLF off this, replace with a \0 */
  while(cpylen && (*bufch == '\r' || *bufch == '\n'))
    {
      *bufch = '\0';
      cpylen--;
      bufch--;
    }
  
  bufline->terminated = 1;
  bufhead->len += cpylen;
  bufline->len += cpylen;
  return clen;
}

/*
 * linebuf_copy_raw
 *
 * Copy as much data as possible directly into a linebuf,
 * splitting at \r\n, but without altering any data.
 *
 */
static int
linebuf_copy_raw(buf_head_t *bufhead, buf_line_t *bufline,
                  char *data, int len)
{
  int cpylen = 0;	/* how many bytes we've copied */
  char *ch = data;	/* Pointer to where we are in the read data */
  char *bufch = bufline->buf + bufline->len;
  int clen = 0;                 /* how many bytes we've processed,
                                   and don't ever want to see again.. */

  /* If its full or terminated, ignore it */

  bufline->raw = 1;
  assert(bufline->len < BUF_DATA_SIZE);
  if (bufline->terminated == 1)
    return 0;

  clen = cpylen = linebuf_skip_crlf(ch, len);
  if (clen == -1)
    return -1;

  /* This is the overflow case..This doesn't happen often.. */
  if(cpylen > (BUF_DATA_SIZE - bufline->len - 1))
    {
      memcpy(bufch, ch, (BUF_DATA_SIZE - bufline->len - 1));
      bufline->buf[BUF_DATA_SIZE-1] = '\0';
      bufch = bufline->buf + BUF_DATA_SIZE - 2;
      bufline->terminated = 1;
      bufline->len = BUF_DATA_SIZE - 1;
      bufhead->len += BUF_DATA_SIZE - 1;
      return clen;
    }

  memcpy(bufch, ch, cpylen);
  bufch += cpylen;
  *bufch = '\0';
  bufch--;

  if(*bufch != '\r' && *bufch != '\n')
    { 
      /* No linefeed, bail for the next time */
      bufhead->len += cpylen;
      bufline->len += cpylen;
      bufline->terminated = 0;
      return clen;
    }

  bufline->terminated = 1;
  bufhead->len += cpylen;
  bufline->len += cpylen;
  return clen;
}


/*
 * linebuf_parse
 *
 * Take a given buffer and break out as many buffers as we can.
 * If we find a CRLF, we terminate that buffer and create a new one.
 * If we don't find a CRLF whilst parsing a buffer, we don't mark it
 * 'finished', so the next loop through we can continue appending ..
 *
 * A few notes here, which you'll need to understand before continuing.
 *
 * - right now I'm only dealing with single sized buffers. Later on,
 *   I might consider chaining buffers together to get longer "lines"
 *   but seriously, I don't see the advantage right now.
 *
 * - This *is* designed to turn into a reference-counter-protected setup
 *   to dodge copious copies.
 */
int
linebuf_parse(buf_head_t *bufhead, char *data, int len, int raw)
{
  buf_line_t *bufline;
  int cpylen;
  int linecnt = 0;

  /* First, if we have a partial buffer, try to squeze data into it */
  if (bufhead->list.tail != NULL)
  {
    /* Check we're doing the partial buffer thing */
    bufline = bufhead->list.tail->data;
    assert(!bufline->flushing);
    /* just try, the worst it could do is *reject* us .. */
    if (raw) /* if we could be dealing with 8-bit data */
      cpylen = linebuf_copy_raw(bufhead, bufline, data, len);
    else
      cpylen = linebuf_copy_line(bufhead, bufline, data, len);
    if (cpylen == -1)
      return -1;
    
    linecnt++;
    /* If we've copied the same as what we've got, quit now */
    if (cpylen == len)
      return linecnt; /* all the data done so soon? */
    
    /* Skip the data and update len .. */
    len -= cpylen;
    assert(len >= 0);
    data += cpylen;
  }
  
  /* Next, the loop */
  while (len > 0)
  {
    /* We obviously need a new buffer, so .. */
    bufline = linebuf_new_line(bufhead);
    
    /* And parse */
    if (raw) /* if we could be dealing with 8-bit data */
      cpylen = linebuf_copy_raw(bufhead, bufline, data, len);
    else
      cpylen = linebuf_copy_line(bufhead, bufline, data, len);
    if (cpylen == -1)
      return -1;

    len -= cpylen;
    assert(len >= 0);
    data += cpylen;
    linecnt++;
  }
  return linecnt;
}


/*
 * linebuf_get
 *
 * get the next buffer from our line. For the time being it will copy
 * data into the given buffer and free the underlying linebuf.
 */
int
linebuf_get(buf_head_t *bufhead, char *buf, int buflen, int partial,
            int raw)
{
  buf_line_t *bufline;
  int cpylen;
  char *start, *ch;

  /* make sure we have a line */
  if (bufhead->list.head == NULL)
    return 0; /* Obviously not.. hrm. */

  bufline = bufhead->list.head->data; 

  /* make sure that the buffer was actually *terminated */
  if (!(partial || bufline->terminated))
    return 0;  /* Wait for more data! */

  /* make sure we've got the space, including the NULL */
  cpylen = bufline->len;
  assert(cpylen + 1 <= buflen);

  /* Copy it */
  start = bufline->buf;

  /* if we left extraneous '\r\n' characters in the string,
   * and we don't want to read the raw data, clean up the string.
   */
  if (bufline->raw && !raw)
  {
    /* skip leading EOL characters */
    while(cpylen && (*start == '\r' || *start == '\n'))
    {
      start++;
      cpylen--;
    }
    /* skip trailing EOL characters */
    ch = &start[cpylen-1];
    while(cpylen && (*ch == '\r' || *ch == '\n'))
    {
      ch--;
      cpylen--;
    }
  }
  memcpy(buf, start, cpylen+1);

  /* convert CR/LF to NUL */
  buf[cpylen] = '\0';

  assert(cpylen >= 0);

  /* Deallocate the line */
  linebuf_done_line(bufhead, bufline, bufhead->list.head);

  /* return how much we copied */
  return cpylen;
}

/*
 * linebuf_attach
 *
 * attach the lines in a buf_head_t to another buf_head_t
 * without copying the data (using refcounts).
 */
void
linebuf_attach(buf_head_t *bufhead, buf_head_t *new)
{
  dlink_node *new_node;
  dlink_node *node;
  buf_line_t *line;
  
  for (node = new->list.head; node; node = node->next)
  {
    line = (buf_line_t *)node->data;
    new_node = make_dlink_node();
    dlinkAddTail(line, new_node, &bufhead->list);

    /* Update the allocated size */
    bufhead->alloclen++;
    bufhead->len += line->len;
    bufhead->numlines++;

    line->refcount++;
  }
}

/*
 * linebuf_putmsg
 *
 * Similar to linebuf_put, but designed for use by send.c.
 *
 * prefixfmt is used as a format for the varargs, and is inserted first.
 * Then format/va_args is appended to the buffer.
 */
void
linebuf_putmsg(buf_head_t *bufhead, const char *format, va_list *va_args,
               const char *prefixfmt, ...)
{
  buf_line_t *bufline;
  int len = 0;
  va_list prefix_args;
  
  /* make sure the previous line is terminated */
#ifndef NDEBUG
  if (bufhead->list.tail)
    {
      bufline = bufhead->list.tail->data;
      assert(bufline->terminated);
    }
#endif
  /* Create a new line */
  bufline = linebuf_new_line(bufhead);

  if (prefixfmt != NULL)
  {
    va_start(prefix_args, prefixfmt);
    len = vsnprintf(bufline->buf, BUF_DATA_SIZE, prefixfmt, prefix_args);
    va_end(prefix_args);
  }

  if (va_args != NULL)
  {
    len += vsnprintf((bufline->buf + len), (BUF_DATA_SIZE - len), format,
                    *va_args);
  }
  
  bufline->terminated = 1;

  /* Truncate the data if required */
  if (len > 510)
    {
      len = 510;
      bufline->buf[len++] = '\r';
      bufline->buf[len++] = '\n';
    }
  else if(len == 0)
    {
      bufline->buf[len++] = '\r';
      bufline->buf[len++] = '\n';
      bufline->buf[len] = '\0';
    }
  else
    {
      /* Chop trailing CRLF's .. */
      while((bufline->buf[len] == '\r') || (bufline->buf[len] == '\n') ||
	    (bufline->buf[len] == '\0'))
	{
	  len--;
	}

      bufline->buf[++len] = '\r';
      bufline->buf[++len] = '\n';
      bufline->buf[++len] = '\0';
    }

  bufline->len  = len;
  bufhead->len += len;
}

/*
 * linebuf_flush
 *
 * Flush data to the buffer. It tries to write as much data as possible
 * to the given socket. Any return values are passed straight through.
 * If there is no data in the socket, EWOULDBLOCK is set as an errno
 * rather than returning 0 (which would map to an EOF..)
 *
 * Notes: XXX We *should* have a clue here when a non-full buffer is arrived.
 *        and tag it so that we don't re-schedule another write until
 *        we have a CRLF.
 */
int
linebuf_flush(int fd, buf_head_t *bufhead)
{
  buf_line_t *bufline;
  int retval;
  
  /* Check we actually have a first buffer */
  if (bufhead->list.head == NULL)
    {
      /* nope, so we return none .. */
      errno = EWOULDBLOCK;
      return -1;    
    }

  bufline = bufhead->list.head->data;

  /* And that its actually full .. */
  if (!bufline->terminated)
    {
      errno = EWOULDBLOCK;
      return -1;
    }
    
  /* Check we're flushing the first buffer */
  if (!bufline->flushing)
    {
      bufline->flushing = 1;
      bufhead->writeofs = 0;
    }

  /* Now, try writing data */
  retval = send(fd, bufline->buf + bufhead->writeofs, bufline->len
		 - bufhead->writeofs, 0);
   
  /* Deal with return code */
  if (retval < 0)
    return retval;
  if (retval == 0)
    return 0;

  /* we've got data, so update the write offset */
  bufhead->writeofs += retval;

  /* if we've written everything *and* the CRLF, deallocate and update
     bufhead */
  if (bufhead->writeofs == bufline->len)
    {
      bufhead->writeofs = 0;
      assert(bufhead->len >=0);
      linebuf_done_line(bufhead, bufline, bufhead->list.head);
    }

  /* Return line length */
  return retval;
}

/*
 * count linebufs for s_debug
 */

void count_linebuf_memory(int *count, u_long *linebuf_memory_used)
{
  *count = bufline_count;
  *linebuf_memory_used = bufline_count * sizeof(buf_line_t);
}
