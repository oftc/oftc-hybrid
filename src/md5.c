/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  md5.c: An MD5 implementation.
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

#include "memory.h"
#include "s_log.h"
#include "client.h"
#include "md5.h"
#include "setup.h"

/*
** how unique ID generation works:
**
** . to get an ID, we do an MD5 step, and encode
**      66 bits of the result into something printable
**
** . to mix the seed with new random information, we MD5-hash the info
**      into the seed
**
** . on startup, mix some rather week data (current time, pid,
**	server name) to initialize the seed
**
*/

static	u_int32_t seed[MD5_BLOCK_SIZE] = {
	0x67452301 , 0xefcdab89 , 0x98badcfe , 0x10325476 ,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

static	unsigned char *seed_char = (unsigned char *)seed;
static void	id_reseed(char *in, int len);
static void	md5_block(u_int32_t *in, u_int32_t *out, u_int32_t *x);


static	u_int32_t databuf_int[MD5_HASH_SIZE];
static	char *databuf = (char *)databuf_int;

static int ork[64] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
	1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 
 	5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2, 
 	0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9
};

static int ors[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static	u_int32_t t[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,

	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,

	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,

	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

/*
** Should not include any 'flag' characters like @ and %, or special chars
** like : * and #, but 8bit accented stuff is quite ok  -orabidoo
*/
static	char printable7[] =
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789[\\]{|}^ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõöøùúûüý";
 
static  char base64_chars[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

static  char base64_values[] =
            {
/* 00-15   */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 16-31   */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 32-47   */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
/* 48-63   */ 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1,  0, -1, -1,
/* 64-79   */ -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
/* 80-95   */ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
/* 96-111  */ -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
/* 112-127 */ 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
/* 128-143 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 144-159 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 160-175 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 186-191 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 192-207 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 208-223 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 224-239 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
/* 240-255 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
            };

void	id_init()
{
  int fd;

  struct tmpcrap 
  {
    struct timeval tv;
    int pid;
    int ppid;
  } st;

  gettimeofday(&st.tv, NULL);
  st.pid = rand();
  st.ppid = rand();
  id_reseed((char *)&st, sizeof(st));

#ifdef RPATH
  fd = open(RPATH, O_RDONLY);
  if (fd > 0)
    {
      read(fd, databuf, 16);
      close(fd);
      md5_block(databuf_int, seed, seed);    	
    }
#endif
}

void	save_random()
{
  int fd;

#ifdef	RPATH
  fd = open(RPATH, O_WRONLY|O_CREAT|O_TRUNC);
  if (fd > 0)
    {
      write(fd, seed_char, 16);
/* by default on VMS, files can only be read by their owner */
#ifndef VMS
      fchmod(fd, 0600);
#endif
      close(fd);
    }
#endif
}

static void	md5_block(u_int32_t *in, u_int32_t *out, u_int32_t *x) 
{
  u_int32_t a, b, c, d;
  int i, j;

  a = in[0];
  b = in[1];
  c = in[2];
  d = in[3];
  for (i=0; i<4; i++)
    {
      j = 4*i;
      a = b + rotl(a + F(b, c, d) + x[ork[j]] + t[j], ors[j]);
      d = a + rotl(d + F(a, b, c) + x[ork[j+1]] + t[j+1], ors[j+1]);
      c = d + rotl(c + F(d, a, b) + x[ork[j+2]] + t[j+2], ors[j+2]);
      b = c + rotl(b + F(c, d, a) + x[ork[j+3]] + t[j+3], ors[j+3]);
    }
  for (i=0; i<4; i++)
    {
      j = 4*i + 16;
      a = b + rotl(a + G(b, c, d) + x[ork[j]] + t[j], ors[j]);
      d = a + rotl(d + G(a, b, c) + x[ork[j+1]] + t[j+1], ors[j+1]);
      c = d + rotl(c + G(d, a, b) + x[ork[j+2]] + t[j+2], ors[j+2]);
      b = c + rotl(b + G(c, d, a) + x[ork[j+3]] + t[j+3], ors[j+3]);
    }
  for (i=0; i<4; i++)
    {
      j = 4*i + 32;
      a = b + rotl(a + H(b, c, d) + x[ork[j]] + t[j], ors[j]);
      d = a + rotl(d + H(a, b, c) + x[ork[j+1]] + t[j+1], ors[j+1]);
      c = d + rotl(c + H(d, a, b) + x[ork[j+2]] + t[j+2], ors[j+2]);
      b = c + rotl(b + H(c, d, a) + x[ork[j+3]] + t[j+3], ors[j+3]);
    }
  for (i=0; i<4; i++)
    {
      j = 4*i + 48;
      a = b + rotl(a + I(b, c, d) + x[ork[j]] + t[j], ors[j]);
      d = a + rotl(d + I(a, b, c) + x[ork[j+1]] + t[j+1], ors[j+1]);
      c = d + rotl(c + I(d, a, b) + x[ork[j+2]] + t[j+2], ors[j+2]);
      b = c + rotl(b + I(c, d, a) + x[ork[j+3]] + t[j+3], ors[j+3]);
    }

  a += in[0];
  b += in[1];
  c += in[2];
  d += in[3];
  out[0] = a;
  out[1] = b;
  out[2] = c;
  out[3] = d;
}

/*
 * base64_block will allocate and return a new block of memory
 * using MyMalloc().  It should be freed after use.
 */
int base64_block(char **output, char *data, int len)
{
  unsigned char *out;
  unsigned char *in = (unsigned char*)data;
  unsigned long int q_in;
  int i;
  int count = 0;

  out = MyMalloc(((((len + 2) - ((len + 2) % 3)) / 3) * 4) + 1);

  /* process 24 bits at a time */
  for( i = 0; i < len; i += 3)
  {
    q_in = 0;

    if ( i + 2 < len )
    {
      q_in  = (in[i+2] & 0xc0) << 2;
      q_in |=  in[i+2];
    }

    if ( i + 1 < len )
    {
      q_in |= (in[i+1] & 0x0f) << 10;
      q_in |= (in[i+1] & 0xf0) << 12;
    }

    q_in |= (in[i]   & 0x03) << 20;
    q_in |=  in[i]           << 22;

    q_in &= 0x3f3f3f3f;

    out[count++] = base64_chars[((q_in >> 24)       )];
    out[count++] = base64_chars[((q_in >> 16) & 0xff)];
    out[count++] = base64_chars[((q_in >>  8) & 0xff)];
    out[count++] = base64_chars[((q_in      ) & 0xff)];
  }
  if ( (i - len) > 0 )
  {
    out[count-1] = '=';
    if ( (i - len) > 1 )
      out[count-2] = '=';
  }

  out[count] = '\0';
  *output = (char *)out;
  return count;
}

/*
 * unbase64_block will allocate and return a new block of memory
 * using MyMalloc().  It should be freed after use.
 */
int unbase64_block(char **output, char *data, int len)
{
  unsigned char *out;
  unsigned char *in = (unsigned char*)data;
  unsigned long int q_in;
  int i;
  int count = 0;

  if ( ( len % 4 ) != 0 )
    return 0;

  out = MyMalloc(((len / 4) * 3) + 1);

  /* process 32 bits at a time */
  for( i = 0; (i + 3) < len; i+=4)
  {
    /* compress input (chars a, b, c and d) as follows:
     * (after converting ascii -> base64 value)
     *
     * |00000000aaaaaabbbbbbccccccdddddd|
     * |  765432  107654  321076  543210|
     */

    q_in = 0;

    if (base64_values[in[i+3]] > -1)
      q_in |= base64_values[in[i+3]]      ;
    if (base64_values[in[i+2]] > -1)
      q_in |= base64_values[in[i+2]] <<  6;
    if (base64_values[in[i+1]] > -1)
      q_in |= base64_values[in[i+1]] << 12;
    if (base64_values[in[i  ]] > -1)
      q_in |= base64_values[in[i  ]] << 18;

    out[count++] = (q_in >> 16) & 0xff;
    out[count++] = (q_in >>  8) & 0xff;
    out[count++] = (q_in      ) & 0xff;
  }

  if (in[i-1] == '=') count--;
  if (in[i-2] == '=') count--;

  out[count] = '\0';
  *output = (char *)out;
  return count;
}

static void	id_reseed(char *in, int len)
{
  int i;

  for (i=0; i<len; i++)
    databuf[i%(4*MD5_HASH_SIZE)] += in[i];
  md5_block(databuf_int, seed, seed);    	
}

char	*id_get()
{
  static char id[ID_GEN_LEN+1];
  int i;

  md5_block(databuf_int, seed, seed);

  id[0] = '.';
  for (i=1; i<ID_GEN_LEN; i++)
    id[i] = printable7[seed_char[i] & 127];

  id[ID_GEN_LEN] = '\0';
  return id;
}

