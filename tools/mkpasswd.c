/* simple password generator by Nelson Minar (minar@reed.edu)
** copyright 1991, all rights reserved.
** You can use this code as long as my name stays with it.
**
** md5 patch by W. Campbell <wcampbel@botbay.net>
** Modernization, getopt, etc for the Hybrid IRCD team
** by W. Campbell
**
** VMS support by Edward Brocklesby, crypt.c implementation
** phk@login.dknet.dk
**
** $Id$
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifdef VMS
# include descrip
# include psldef
# include iodef
# include ssdef
# include starlet
#endif

#define FLAG_MD5     0x00000001
#define FLAG_DES     0x00000002
#define FLAG_SALT    0x00000004
#define FLAG_PASS    0x00000008
#define FLAG_LENGTH  0x00000010

#ifdef VMS
static char *getpass();
#else
extern char *getpass();
#endif

extern char *crypt();

char *make_des_salt();
char *make_md5_salt(int);
char *make_md5_salt_para(char *);
void usage();
static char saltChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

int main(int argc, char *argv[])
{
  char *plaintext = NULL;
  extern char *optarg;
  int c;
  char *saltpara = NULL;
  char *salt;
  int flag = 0;
  int length = 8;

  /* Not the best salt, but... */
  srandom(time(NULL));

#ifdef VMS
  /* always use MD5 on VMS */
  flag |= FLAG_MD5;
#endif

  while( (c=getopt(argc, argv, "mdh?l:s:p:")) != -1)
  {
    switch(c)
    {
      case 'm':
        flag |= FLAG_MD5;
        break;
      case 'd':
#ifdef VMS
        printf("DES is not supported on VMS.  Sorry\n");
#else
        flag |= FLAG_DES;
#endif
        break;
      case 'l':
        flag |= FLAG_LENGTH;
        length = atoi(optarg);
        break;
      case 's':
        flag |= FLAG_SALT;
        saltpara = optarg;
        break;
      case 'p':
        flag |= FLAG_PASS;
        plaintext = optarg;
        break;
      case 'h':
      case '?':
        usage();
        break;
      default:
        printf("Invalid Option: -%c\n", c);
        break;
    }
  }

  if (flag & FLAG_MD5)
  {
    if (flag & FLAG_SALT)
      salt = make_md5_salt_para(saltpara);
    else
      salt = make_md5_salt(length);
  }
  else
  {
    if (flag & FLAG_SALT)
    {
      if ((strlen(saltpara) == 2))
      {
        salt = saltpara;
      }
      else
      {
        printf("Invalid salt, please enter 2 alphanumeric characters\n");
        exit(1);
      }
    }
    else
    {
      salt = make_des_salt();
    }
  }

  if (flag & FLAG_PASS)
  {
    if (!plaintext)
      printf("Please enter a valid password\n");
  }
  else
  {
    plaintext = getpass("plaintext: ");
  }

  printf("%s\n", crypt(plaintext, salt));
  return 0;
}

char *make_des_salt()
{
  static char salt[3];
  salt[0] = saltChars[random() % 64];
  salt[1] = saltChars[random() % 64];
  salt[2] = '\0';
  return salt;
}

char *make_md5_salt_para(char *saltpara)
{
  static char salt[21];
  if (saltpara && (strlen(saltpara) <= 16))
  {
    /* sprintf used because of portability requirements, the length
    ** is checked above, so it should not be too much of a concern
    */
    sprintf(salt, "$1$%s$", saltpara);
    return salt;
  }
  printf("Invalid Salt, please use up to 16 random alphanumeric characters\n");
  exit(1);

  /* NOT REACHED */
  return NULL;
}
  
char *make_md5_salt(int length)
{
  static char salt[21];
  int i;
  if (length > 16)
  {
    printf("MD5 salt length too long\n");
    exit(0);
  }
  salt[0] = '$';
  salt[1] = '1';
  salt[2] = '$';
  for (i=3; i<(length+3); i++)
    salt[i] = saltChars[random() % 64];
  salt[length+3] = '$';
  salt[length+4] = '\0';
  return salt;
}

void usage()
{
  printf("mkpasswd [-m|-d] [-l saltlength] [-s salt] [-p plaintext]\n");
  printf("-m Generate an MD5 password\n");
  printf("-d Generate a DES password\n");
  printf("-l Specify a length for a random MD5 salt\n");
  printf("-s Specify a salt, 2 alphanumeric characters for DES, up to 16 for MD5\n");
  printf("-p Specify a plaintext password to use\n");
  printf("Example: mkpasswd -m -s 3dr -p test\n");
  exit(0);
}

/* getpass replacement for VMS */
#ifdef VMS

static char *
getpass (prompt)
        char *prompt;
{
  static char password[64];
  int result;
  int chan;
  int promptlen;

  $DESCRIPTOR(devnam,"SYS$INPUT");

  struct {
     short result;
     short count;
     int   info;
  } iosb;

  promptlen = strlen(prompt);

  SYS$ASSIGN(&devnam, &chan, PSL$C_USER, 0, 0);
  SYS$QIOW(0, chan, IO$_READPROMPT | IO$M_PURGE | IO$M_NOECHO, &iosb, 0, 0,
                    password, 255, 0, 0, prompt, promptlen);
  password[iosb.count] = '\0';
  SYS$DASSGN(chan);

  printf("\r");
  return password;
}
#endif
