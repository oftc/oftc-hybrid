/************************************************************************
 *   IRC - Internet Relay Chat, tools/convertconf.c
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
 * $Id$
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/config.h"
#include "../include/setup.h"

#define CONFPATH ETCPATH "/.convertconf-example.conf"
#define BUFSIZE 512

#define IS_LEAF 0
#define IS_HUB 1

struct ConnectPair
{
  struct ConnectPair* next;     /* list node pointer */
  char*            name;     /* server name */
  char*            host;     /* host part of user@host */
  char*            c_passwd;
  char*            n_passwd;
  char*		   hub_mask;
  char*		   leaf_mask;
  int		   compressed;
  int		   lazylink;
  int              port;
  char             *class;     /* Class of connection */
};

static struct ConnectPair* base_ptr=NULL;

static void ConvertConf(FILE* file,FILE *out);
static void usage(void);
static char *getfield(char *);
static void ReplaceQuotes(char *out, char *in);
static void oldParseOneLine(FILE *out, char *in);
static void PrintOutServers(FILE *out);
static void PairUpServers(struct ConnectPair* );
static void AddHubOrLeaf(int type,char* name,char* host);
static void OperPrivsFromString(FILE* , char* );
static int basic = 0;

int main(int argc,char *argv[])
{
  FILE *in;
  FILE *out;
  char line[BUFSIZE];
  char *filein, *fileout;

  if(argc < 3)
    usage();

  if(argc > 3)
  {
    if((argv[1][0] == '-') && argv[1][1] && (argv[1][1] == 'b'))
      basic = 1;

    filein = argv[2];
    fileout = argv[3];
  }
  else
  {
    filein = argv[1];
    fileout = argv[2];
  }

#ifdef EFNET
  basic = 1;
#endif

  if ((in = fopen(filein, "r")) == NULL)
    {
      fprintf(stderr,"Can't open %s for reading\n", filein);
      usage();
    }

  if ((out = fopen(fileout, "w")) == NULL)
    {
      fprintf(stderr,"Can't open %s for writing\n", fileout);
      usage();
    }
  
  ConvertConf(in,out);

  if(!basic && ((in = fopen(CONFPATH, "r")) == NULL))
  {
    fprintf(stderr, "Can't open %s for reading\n", CONFPATH);
    puts("You must use the example.conf in the ircd-hybrid-7 source to get the\n"
	 "general {}; logging {}; channel {}; serverhide {}; modules {}; blocks.\n");
  }
  else if(!basic)
  {
    while (fgets(line, sizeof(line), in))
      fprintf(out, line);

    puts("Adding the remaining missing blocks to your config..\n");
  }

  puts("The config file has been converted however you MUST rearrange and check the config:\n"
       "   o class blocks (Y:) must be before anything that uses then\n"
       "   o auth blocks (I:) have NOT been converted, please use convertilines\n"
       "     to convert them\n");
  if(!basic)
    puts("   o the general/channel/serverhide parts will need to be edited\n");

  return 0;
}

static void usage()
{
  fprintf(stderr,"convertconf [-b] ircd.conf.old ircd.conf.new\n");
  fprintf(stderr, "   -b - this will run in 'basic' mode and not add extra blocks\n");
  fprintf(stderr, "        such as general{}, channel{} etc. (Used for EFNet)\n");
  exit(-1);
}

/*
** ConvertConf() 
**    Read configuration file.
**
*
* Inputs        - FILE* to config file to convert
*		- FILE* to output for new style conf
*
**    returns -1, if file cannot be opened
**             0, if file opened
*/

#define MAXCONFLINKS 150

static void ConvertConf(FILE* file,FILE *out)
{
  char             line[BUFSIZE];
  char             quotedLine[BUFSIZE];
  char*            p;

  while (fgets(line, sizeof(line), file))
    {
      if ((p = strchr(line, '\n')))
        *p = '\0';

      ReplaceQuotes(quotedLine,line);

      if (!*quotedLine || quotedLine[0] == '#' || quotedLine[0] == '\n' ||
          quotedLine[0] == ' ' || quotedLine[0] == '\t')
        continue;

      if(quotedLine[0] == '.')
        {
          char *filename;
          char *back;

          if(!strncmp(quotedLine+1,"include ",8))
            {
              if( (filename = strchr(quotedLine+8,'"')) )
                filename++;
              else
                {
                  fprintf(stderr, "Bad config line: %s", quotedLine);
                  continue;
                }

              if( (back = strchr(filename,'"')) )
                *back = '\0';
              else
                {
                  fprintf(stderr, "Bad config line: %s", quotedLine);
                  continue;
                }

	    }
	}

      /* Could we test if it's conf line at all?        -Vesa */
      if (quotedLine[1] == ':')
        oldParseOneLine(out,quotedLine);

    }

  PrintOutServers(out);
  fclose(file);
}

/*
 * ReplaceQuotes
 * Inputs       - input line to quote
 * Output       - quoted line
 * Side Effects - All quoted chars in input are replaced
 *                with quoted values in output, # chars replaced with '\0'
 *                otherwise input is copied to output.
 */
static void ReplaceQuotes(char* quotedLine,char *inputLine)
{
  char *in;
  char *out;
  static char  quotes[] = {
    0,    /*  */
    0,    /* a */
    '\b', /* b */
    0,    /* c */
    0,    /* d */
    0,    /* e */
    '\f', /* f */
    0,    /* g */
    0,    /* h */
    0,    /* i */
    0,    /* j */
    0,    /* k */
    0,    /* l */
    0,    /* m */
    '\n', /* n */
    0,    /* o */
    0,    /* p */
    0,    /* q */
    '\r', /* r */
    0,    /* s */
    '\t', /* t */
    0,    /* u */
    '\v', /* v */
    0,    /* w */
    0,    /* x */
    0,    /* y */
    0,    /* z */
    0,0,0,0,0,0 
    };

  /*
   * Do quoting of characters and # detection.
   */
  for (out = quotedLine,in = inputLine; *in; out++, in++)
    {
      if (*in == '\\')
	{
          in++;
          if(*in == '\\')
            *out = '\\';
          else if(*in == '#')
            *out = '#';
	  else
	    *out = quotes[ (unsigned int) (*in & 0x1F) ];
	}
      else if (*in == '#')
        {
	  *out = '\0';
          return;
	}
      else
        *out = *in;
    }
  *out = '\0';
}

/*
 * oldParseOneLine
 * Inputs       - pointer to line to parse
 *		- pointer to output to write
 * Output       - 
 * Side Effects - Parse one old style conf line.
 */

static void oldParseOneLine(FILE *out,char* line)
{
  char conf_letter;
  char* tmp;
  char* user_field=(char *)NULL;
  char* passwd_field=(char *)NULL;
  char* host_field=(char *)NULL;
  char* port_field=(char *)NULL;
  char* class_field=(char *)NULL;
  struct ConnectPair* pair;
  int sendq = 0;
  int restricted;

  tmp = getfield(line);

  conf_letter = *tmp;

  restricted = 0;
  for (;;) /* Fake loop, that I can use break here --msa */
    {
      /* host field */
      if ((host_field = getfield(NULL)) == NULL)
	return;
      
      /* pass field */
      if ((passwd_field = getfield(NULL)) == NULL)
	break;

      /* user field */
      if ((user_field = getfield(NULL)) == NULL)
	break;

      /* port field */
      if ((port_field = getfield(NULL)) == NULL)
	break;

      /* class field */
      if ((class_field = getfield(NULL)) == NULL)
	break;

      break;
    }
  if (!passwd_field)
    passwd_field = "";
  if (!user_field)
    user_field = "";
  if (!port_field)    
    port_field = "";
  if (!class_field)
    class_field = "";
  switch( conf_letter )
    {
    case 'A':case 'a': /* Name, e-mail address of administrator */
      fprintf(out,"administrator {\n");
      if(host_field)
	fprintf(out,"\tname=\"%s\";\n", passwd_field);
      if(user_field)
	fprintf(out,"\tdescription=\"%s\";\n", user_field);
      if(passwd_field)
	fprintf(out,"\temail=\"%s\";\n", host_field);
      fprintf(out,"};\n\n");
      break;

    case 'c':
    case 'C':
      pair = (struct ConnectPair *)malloc(sizeof(struct ConnectPair));
      memset(pair,0,sizeof(struct ConnectPair));
      if(user_field)
	pair->name = strdup(user_field);
      if(host_field)
	pair->host = strdup(host_field);
      if(passwd_field)
	pair->c_passwd = strdup(passwd_field);
      if(port_field)
	pair->port = atoi(port_field);
      if(class_field)
	pair->class = strdup(class_field);
      PairUpServers(pair);
      break;

    case 'd':
      fprintf(out,"exempt {\n");
      if(user_field)
	fprintf(out,"\tip=\"%s\";\n", user_field);
      fprintf(out,"};\n\n");
      break;

    case 'D': /* Deny lines (immediate refusal) */
      fprintf(out,"deny {\n");
      if(host_field)
	fprintf(out,"\tip=\"%s\";\n", host_field);
      if(passwd_field)
	fprintf(out,"\treason=\"%s\";\n", passwd_field);
      fprintf(out,"};\n\n");
      break;

    case 'H': /* Hub server line */
    case 'h':
      AddHubOrLeaf(IS_HUB,user_field,host_field);
      break;

    /* We no longer have restricted connection in Hybrid 7 */
    case 'i': 
    case 'I': 
      break;
      
    case 'K': /* Kill user line on irc.conf           */
    case 'k':
      fprintf(out,"kill {\n");
      if(host_field)
	fprintf(out,"\tuser=\"%s@%s\";\n", user_field,host_field);
      if(passwd_field)
	fprintf(out,"\treason=\"%s\";\n", passwd_field);
      fprintf(out,"};\n\n");
      break;

    case 'L': /* guaranteed leaf server */
    case 'l':
      AddHubOrLeaf(IS_LEAF,user_field,host_field);
      break;

/* Me. Host field is name used for this host */
      /* and port number is the number of the port */
    case 'M':
    case 'm':
      fprintf(out,"serverinfo {\n");
      if(host_field)
	fprintf(out,"\tname=\"%s\";\n", host_field);
      if(passwd_field)
	fprintf(out,"\tvhost=\"%s\";\n", passwd_field);
      if(user_field)
	fprintf(out,"\tdescription=\"%s\";\n", user_field);
      if(port_field)
	fprintf(out,"\thub=yes;\n");
      else
     	fprintf(out,"\thub=no;\n");
      /* Also print a default servername/netname */
      fprintf(out, "\tnetwork_name=\"EFNet\";\n");
      fprintf(out, "\tnetwork_desc=\"Eris Free Network\";\n");
      fprintf(out, "\tmax_clients=1024;\n");
      fprintf(out,"};\n\n");
      break;

    case 'n': 
      pair = (struct ConnectPair *)malloc(sizeof(struct ConnectPair));
      memset(pair,0,sizeof(struct ConnectPair));
      if(user_field)
	pair->name = strdup(user_field);
      if(host_field)
	pair->host = strdup(host_field);
      if(passwd_field)
	pair->n_passwd = strdup(passwd_field);
      pair->lazylink = 1;
      if(port_field)
	pair->port = atoi(port_field);
      if(class_field)
	pair->class = strdup(class_field);
      PairUpServers(pair);
      break;

    case 'N': 
      pair = (struct ConnectPair *)malloc(sizeof(struct ConnectPair));
      memset(pair,0,sizeof(struct ConnectPair));
      if(user_field)
	pair->name = strdup(user_field);
      if(host_field)
	pair->host = strdup(host_field);
      if(passwd_field)
	pair->n_passwd = strdup(passwd_field);
      if(port_field)
	pair->port = atoi(port_field);
      if(class_field)
	pair->class = strdup(class_field);
      PairUpServers(pair);
      break;

      /* Operator. Line should contain at least */
      /* password and host where connection is  */
      /* Local operators no longer exist        */
      /* For now, I don't force locals to have  */
      /* certain default flags.  I probably     */
      /* should if there is no port field       */
    case 'o':
    case 'O':
      /* defaults */
      fprintf(out,"operator {\n");
      if(user_field)
	fprintf(out,"\tname=\"%s\";\n", user_field);
      if(host_field)
	{
	  fprintf(out,"\tuser=\"%s\";\n", host_field);
	}
      if(passwd_field)
	fprintf(out,"\tpassword=\"%s\";\n", passwd_field);
      if(port_field)
	OperPrivsFromString(out,port_field);
      if(class_field)
	fprintf(out,"\tclass=\"%s\";\n", class_field);	
      fprintf(out,"};\n\n");
      break;

    case 'P': /* listen port line */
    case 'p':
      fprintf(out,"listen {\n");
      /* What is the purpose of this field? */
      if(host_field && *host_field)
	fprintf(out,"\tname=\"%s\";\n", host_field);
      if(port_field)
	fprintf(out,"\tport=%d;\n", atoi(port_field));
      fprintf(out,"};\n\n");
      break;

    case 'Q': /* reserved nicks */
    case 'q': 
      if(host_field && (*host_field != '#'))
        {
          fprintf(out,"resv {\n");
          fprintf(out,"\tnick=\"%s\";\n", host_field);
        }
      else
        {
          fprintf(out,"resv {\n");
          fprintf(out,"\tchannel=\"%s\";\n", host_field);
          break;
        } 
     if(passwd_field)
	fprintf(out,"\treason=\"%s\";\n", passwd_field);
      fprintf(out,"};\n\n");
      break;

    case 'U': 
    case 'u': 
      fprintf(out,"shared {\n");
      if(host_field)
	fprintf(out,"\tname=\"%s\";\n", host_field);
#if 0
      if(passwd_field)
	fprintf(out,"\treason=\"%s\";\n", passwd_field);
#endif
      fprintf(out,"};\n\n");
      break;

    case 'X': /* rejected gecos */
    case 'x': 
      fprintf(out,"gecos {\n");
      if(host_field)
	fprintf(out,"\tname=\"%s\";\n", host_field);
      if(passwd_field)
	fprintf(out,"\treason=\"%s\";\n", passwd_field);
      if(port_field)
        {
          if (*user_field == '0')
            fprintf(out,"\taction=reject;\n");
          else if (*user_field == '1')
            fprintf(out,"\taction=warn;\n");
          else
            fprintf(out, "\taction=silent;\n");
        }
      fprintf(out,"};\n\n");
      break;

    case 'Y':
    case 'y':
      fprintf(out,"class {\n");
      if(host_field)
	fprintf(out,"\tname=\"%s\";\n", host_field);
      if(passwd_field)
	{
	  int ping_time;
	  ping_time = atoi(passwd_field);
	  fprintf(out,"\tping_time=%d;\n", ping_time );
	}
      if(user_field)
	{
          /* Note that connectfreq and number_per_ip set the same variable
          ** when read by the ircd.  They *ARE* interchangable, just both
          ** exist for the user's benefit
          */
	  int number_per_ip;
	  number_per_ip = atoi(user_field);
	  fprintf(out,"\tnumber_per_ip=%d;\n", number_per_ip );
	}
      if(port_field)
	{
	  int max_number;
	  max_number = atoi(port_field);
	  fprintf(out,"\tmax_number=%d;\n", max_number );
	}
      if(class_field)
	sendq = atoi(class_field);
      fprintf(out,"\tsendq=%d;\n", sendq);
      fprintf(out,"};\n\n");
      break;
      
    default:
      fprintf(stderr, "Error in config file: %s", line);
      break;
    }
}

/*
 * PrintOutServers
 *
 * In		- FILE pointer
 * Out		- NONE
 * Side Effects	- Print out connect configurations
 */
static void PrintOutServers(FILE* out)
{
  struct ConnectPair* p;

  for(p = base_ptr; p; p = p->next)
    {
      if(p->name && p->c_passwd && p->n_passwd && p->host)
	{
	  fprintf(out,"connect {\n");
	  fprintf(out,"\thost=\"%s\";\n", p->host);
	  fprintf(out,"\tname=\"%s\";\n", p->name);
	  fprintf(out,"\tsend_password=\"%s\";\n", p->c_passwd);
	  fprintf(out,"\taccept_password=\"%s\";\n", p->n_passwd);
	  fprintf(out,"\tport=%d;\n", p->port );

#if 0
          /* ZIP links are gone */
	  if(p->compressed)
	    fprintf(out,"\tcompressed=yes;\n");
#endif
#if 0
	  if(p->lazylink)
	    fprintf(out,"\tlazylink=yes;\n");
#endif
	  if(p->hub_mask)
	    {
	      fprintf(out,"\thub_mask=\"%s\";\n",p->hub_mask);
	    }
	  else
	    {
	      if(p->leaf_mask)
		fprintf(out,"\tleaf_mask=\"%s\";\n",p->leaf_mask);
	    }

	  if(p->class)
	    fprintf(out,"\tclass=\"%s\";\n", p->class );

	  fprintf(out,"};\n\n");
	}
    }
}

/*
 * PairUpServers
 *
 * In		- pointer to ConnectPair
 * Out		- none
 * Side Effects	- Pair up C/N lines on servers into one output
 */
static void PairUpServers(struct ConnectPair* pair)
{
  struct ConnectPair *p;

  for(p = base_ptr; p; p = p->next )
    {
      if(p->name && pair->name )
	{
	  if( !strcasecmp(p->name,pair->name) )
	    {
	      if(!p->n_passwd && pair->n_passwd)
		p->n_passwd = strdup(pair->n_passwd);

	      if(!p->c_passwd && pair->c_passwd)
		p->c_passwd = strdup(pair->c_passwd);

	      p->compressed |= pair->compressed;
	      p->lazylink |= pair->lazylink;

	      if(pair->port)
		p->port = pair->port;

	      return;
	    }
	}
    }

  if(base_ptr)
    {
      pair->next = base_ptr;
      base_ptr = pair;
    }
  else
    base_ptr = pair;
}

/*
 * AddHubOrLeaf
 *
 * In		- type either IS_HUB or IS_LEAF
 *		- name of leaf or hub
 *		- mask 
 * Out		- none
 * Side Effects	- Pair up hub or leaf with connect configuration
 */
static void AddHubOrLeaf(int type,char* name,char* host)
{
  struct ConnectPair* p;
  struct ConnectPair* pair;

  for(p = base_ptr; p; p = p->next )
    {
      if(p->name && name )
	{
	  if( !strcasecmp(p->name,name) )
	    {
	      if(type == IS_HUB)
		p->hub_mask = strdup(host);

	      if(type == IS_LEAF)
		p->leaf_mask = strdup(host);
	      return;
	    }
	}
    }

  pair = (struct ConnectPair *)malloc(sizeof(struct ConnectPair));
  memset(pair,0,sizeof(struct ConnectPair));

  pair->name = strdup(name);

  if(type == IS_HUB)
    {
      pair->hub_mask = strdup(host);
    }
  else if(type == IS_LEAF)
    {
      pair->leaf_mask = strdup(host);
    }

  if(base_ptr)
    {
      pair->next = base_ptr;
      base_ptr = pair;
    }
  else
    base_ptr = pair;
}

/*
 * field breakup for ircd.conf file.
 */
static char *getfield(char *newline)
{
  static char *line = (char *)NULL;
  char  *end, *field;
        
  if (newline)
    line = newline;

  if (line == (char *)NULL)
    return((char *)NULL);

  field = line;
  if ((end = strchr(line,':')) == NULL)
    {
      line = (char *)NULL;
      if ((end = strchr(field,'\n')) == (char *)NULL)
        end = field + strlen(field);
    }
  else
    line = end + 1;
  *end = '\0';
  return(field);
}

/* OperPrivsFromString
 *
 * inputs        - privs as string
 * output        - none
 * side effects -
 */

static void OperPrivsFromString(FILE* out, char *privs)
{
  while(*privs)
    {
      /* If the priv is lower case, it defaults to whatever=no; anyway, so we dont need this? --fl */
      if(*privs == 'O')                     /* allow global kill */
	{
	  fprintf(out,"\tglobal_kill=yes;\n");
	}
      else if(*privs == 'o')                /* disallow global kill */
	{
	  fprintf(out,"\tglobal_kill=no;\n");
	}
      else if(*privs == 'U')                /* allow unkline */
	{
	  fprintf(out,"\tunkline=yes;\n");
	}
      else if(*privs == 'u')                /* disallow unkline */
	{
	  fprintf(out,"\tunkline=no;\n");
	}
      else if(*privs == 'R')               /* allow remote squit/connect etc.*/
	{
	  fprintf(out,"\tremote=yes;\n");
	}
      else if(*privs == 'r')                /* disallow remote squit/connect etc.*/
	{
	  fprintf(out,"\tremote=no;\n");
	}
      else if(*privs == 'N')                /* allow +n see nick changes */
	{
	  fprintf(out,"\tnick_changes=yes;\n");
	}
      else if(*privs == 'K')                /* allow kill and kline privs */
	{
	  fprintf(out,"\tkline=yes;\n");
	}
      else if(*privs == 'k')                /* disallow kill and kline privs */
	{
	  fprintf(out,"\tkline=no;\n");
	}
      else if(*privs == 'G')                /* allow gline */
	{
	  fprintf(out,"\tgline=yes;\n");
	}
      else if(*privs == 'g')                /* disallow gline */
	{
	  fprintf(out,"\tgline=no;\n");
	}
      else if(*privs == 'H')                /* allow rehash */
	{
	  fprintf(out,"\trehash=yes;\n");
	}
      else if(*privs == 'h')                /* disallow rehash */
	{
	  fprintf(out,"\trehash=no;\n");
	}
      else if(*privs == 'D')
	{
	  fprintf(out,"\tdie=yes;\n");
	}
      else if(*privs == 'd')
	{
	  fprintf(out,"\tdie=no;\n");
 	}
      privs++;
    }
}

