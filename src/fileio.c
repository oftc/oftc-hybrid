/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  fileio.c: Provides a file input-output interface to ircd.
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
#include "config.h"
#include "fileio.h"
#include "irc_string.h"
#include "client.h"	/* for FLAGS_ALL */
#include "send.h"	/* sendto_realops_flags */
#include "memory.h"

/* The following are to get the fd manipulation routines. eww. */
#include "fdlist.h"


/*
 * Wrappers around open() / close() for fileio, since a whole bunch of
 * code that should be using the fbopen() / fbclose() code isn't.
 * Grr. -- adrian
 */

int
file_open(const char *filename, int mode, int fmode)
{
    int fd;
    fd = open(filename, mode, fmode);
    if (fd == MASTER_MAX) {
        fd_close(fd); /* Too many FDs! */
        errno = ENFILE;
        fd = -1;
    } else if (fd >= 0)
        fd_open(fd, FD_FILE, filename);
    
    return fd;
}

void
file_close(int fd)
{
    /*
     * Debug - we set type to FD_FILECLOSE so we can get trapped
     * in fd_close() with type == FD_FILE. This will allow us to
     * convert all abusers of fd_close() of a FD_FILE fd over
     * to file_close() .. mwahaha!
     */
    assert(fd_table[fd].type == FD_FILE);
    fd_table[fd].type = FD_FILECLOSE;
    fd_close(fd);
}

FBFILE* fbopen(const char* filename, const char* mode)
{
  int openmode = 0;
  int pmode = 0;
  FBFILE* fb = NULL;
  int fd;
  assert(filename);
  assert(mode);
  
  if(filename == NULL || mode == NULL)
  {
     errno = EINVAL;
     return NULL;
  }
  while (*mode)
  {
    switch (*mode)
    {
    case 'r':
      openmode = O_RDONLY;
      break;
    case 'w':
      openmode = O_WRONLY | O_CREAT | O_TRUNC;
      pmode = 0644;
      break;
    case 'a':
      openmode = O_WRONLY | O_CREAT | O_APPEND;
      pmode = 0644;
      break;
    case '+':
      openmode &= ~(O_RDONLY | O_WRONLY);
      openmode |= O_RDWR;
      break;
    default:
      break;
    }
    ++mode;
  }

  if ((fd = file_open(filename, openmode, pmode)) == -1) {
    return fb;
  }

  if (NULL == (fb = fdbopen(fd, NULL)))
    file_close(fd);
  return fb;
}

FBFILE* fdbopen(int fd, const char* mode)
{
  /*
   * ignore mode, if file descriptor hasn't been opened with the
   * correct mode, the first use will fail
   */
  FBFILE* fb = (FBFILE*) MyMalloc(sizeof(FBFILE));
  if (NULL != fb) {
    fb->ptr = fb->endp = fb->buf;
    fb->fd = fd;
    fb->flags = 0;
    fb->pbptr = (char *)NULL;
  }
  return fb;
}

void fbclose(FBFILE* fb)
{
  assert(fb);
  if(fb != NULL)
  {
    file_close(fb->fd);
    MyFree(fb);
  } else
    errno = EINVAL;
   
}

static int fbfill(FBFILE* fb)
{
  int n;
  assert(fb);
  if(fb == NULL)
  {
    errno = EINVAL;
    return -1;
  }  
  if (fb->flags)
    return -1;
  n = read(fb->fd, fb->buf, BUFSIZ);
  if (0 < n)
  {
    fb->ptr  = fb->buf;
    fb->endp = fb->buf + n;
  }
  else if (n < 0)
    fb->flags |= FB_FAIL;
  else
    fb->flags |= FB_EOF;
  return n;
}

int fbgetc(FBFILE* fb)
{
  assert(fb);
  if(fb == NULL)
  {
    errno = EINVAL;
    return -1;
  }
  if(fb->pbptr)
  {
    if( (fb->pbptr == (fb->pbuf+BUFSIZ)) ||
	(!*fb->pbptr) )
      fb->pbptr = NULL;
  }

  if (fb->ptr < fb->endp || fbfill(fb) > 0)
    return *fb->ptr++;
  return EOF;
}

void fbungetc(char c, FBFILE* fb)
{
  assert(fb);
  if(fb == NULL)
  {
    errno = EINVAL;
    return;
  }
  if(!fb->pbptr)
  {
    fb->pbptr = fb->pbuf+BUFSIZ;
  }

  if(fb->pbptr != fb->pbuf)
  {
    fb->pbptr--;
    *fb->pbptr = c;
  }
}

char* fbgets(char* buf, size_t len, FBFILE* fb)
{
  char* p = buf;
  assert(buf);
  assert(fb);
  assert(0 < len);
  
  if(fb == NULL || buf == NULL)
  {
    errno = EINVAL;
    return NULL;
  }
  if(fb->pbptr)
  {
    strlcpy(buf,fb->pbptr,len);
    fb->pbptr = NULL;
    return(buf);
  }

  if (fb->ptr == fb->endp && fbfill(fb) < 1)
    return 0;
  --len; 
  while (len--)
  {
    *p = *fb->ptr++;
    if ('\n' == *p)
    {
      ++p;
      break;
    }
    /*
     * deal with CR's
     */
    else if ('\r' == *p)
    {
      if (fb->ptr < fb->endp || fbfill(fb) > 0)
      {
        if ('\n' == *fb->ptr)
          ++fb->ptr;
      }
      *p++ = '\n';
      break;
    }
    ++p;
    if (fb->ptr == fb->endp && fbfill(fb) < 1)
      break;
  }
  *p = '\0';
  return buf;
}
 
int fbputs(const char* str, FBFILE* fb)
{
  int n = -1;
  assert(str);
  assert(fb);
  
  if(str == NULL || fb == NULL)
  {
    errno = EINVAL;
    return -1;
  } 
  if (0 == fb->flags)
  {
    n = write(fb->fd, str, strlen(str));
    if (-1 == n)
      fb->flags |= FB_FAIL;
  }
  return n;
}

int fbstat(struct stat* sb, FBFILE* fb)
{
  assert(sb);
  assert(fb);
  if(sb == NULL || fb == NULL)
  {
    errno = EINVAL;
    return -1;
  }
  return fstat(fb->fd, sb);
}


