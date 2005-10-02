/* $Id$ */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFLEN 1024

static void checkbug(const char *fmt, ...);

int main(int argc, char *argv[])
{
  checkbug("Constant Format String");
  checkbug("1=%d, foo=%s", 1, "foo"); 

  exit(0); /*NOTREACHED*/
}

static void checkbug(const char *fmt, ...)
{
  char buf_a[BUFLEN];
  char buf_b[BUFLEN];
  char buf_c[BUFLEN];
  int n;
  va_list ap, ap2;

  printf("checkbug(%s)\n", fmt);

  va_start(ap, fmt);
  va_copy(ap2, ap);
 
  n = vsnprintf(buf_a, BUFLEN, fmt, ap);
  printf("  buf_a (len=%4d): %s\n", n, buf_a);
  vsnprintf(buf_b, BUFLEN, fmt, ap);
  printf("  buf_b (len=%4d): %s\n", n, buf_b);
  vsnprintf(buf_c, BUFLEN, fmt, ap2);
  printf("  buf_c (len=%4d): %s\n", n, buf_c);

  va_end(ap);
  va_end(ap2);
}

