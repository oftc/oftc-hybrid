/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_unkline.c: Unklines a user.
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
#include "handlers.h"
#include "channel.h"
#include "client.h"
#include "common.h"
#include "fileio.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "hostmask.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_misc.h"
#include "send.h"
#include "msg.h"
#include "s_gline.h"
#include "parse.h"
#include "modules.h"


static void mo_unkline(struct Client*, struct Client*, int, char**);
static void mo_undline(struct Client*, struct Client*, int, char**);
static void mo_ungline(struct Client*, struct Client*, int, char**);
static void ms_unkline(struct Client*, struct Client*, int, char**);
static void remove_permkline_match(struct Client *, char *, char *);

struct Message msgtabs[] = {
  {"UNKLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, ms_unkline, mo_unkline}},
  {"UNDLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, m_error, mo_undline}}, 
  {"UNGLINE", 0, 0, 2, 0, MFLG_SLOW, 0,
   {m_unregistered, m_not_oper, m_error, mo_ungline}}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&msgtabs[0]);
  mod_add_cmd(&msgtabs[1]);
  mod_add_cmd(&msgtabs[2]);
}

void
_moddeinit(void)
{
  mod_del_cmd(&msgtabs[0]);
  mod_del_cmd(&msgtabs[1]);
  mod_del_cmd(&msgtabs[2]);
}
const char *_version = "$Revision$";
#endif

static int flush_write(struct Client *, FBFILE *in, FBFILE *out,
		       char *, char *);
static int remove_tkline_match(char *,char *);


/*
** mo_unkline
** Added Aug 31, 1997 
** common (Keith Fralick) fralick@gate.net
**
**      parv[0] = sender
**      parv[1] = address to remove
*
*
*/
static void
mo_unkline (struct Client *client_p,struct Client *source_p,
	    int parc,char *parv[])
{
  FBFILE *in, *out;
  int pairme=0;
  char buf[BUFSIZE], buff[BUFSIZE], temppath[BUFSIZE], *user, *host, *p;
  const char  *filename;                /* filename to use for unkline */
  mode_t oldumask;

  ircsprintf(temppath, "%s.tmp", ConfigFileEntry.klinefile);
  
  if (!IsOperUnkline(source_p))
    {
      sendto_one(source_p,":%s NOTICE %s :You need unkline = yes;",me.name,parv[0]);
      return;
    }
  if (parc < 2)
    {
      sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
                 me.name, source_p->name, "UNKLINE");
      return;
    }

  if ((host = strchr(parv[1], '@')) || *parv[1] == '*')
    {
      /* Explicit user@host mask given */

      if(host)                  /* Found user@host */
        {
          user = parv[1];       /* here is user part */
          *(host++) = '\0';     /* and now here is host */
        }
      else
        {
          user = "*";           /* no @ found, assume its *@somehost */
          host = parv[1];
        }
    }
  else
    {
      sendto_one(source_p, ":%s NOTICE %s :Invalid parameters",
                 me.name, source_p->name);
      return;
    }

  /* possible remote kline.. */
  if(parc > 3)
  {
    if(irccmp(parv[2], "ON") == 0)
    {
      sendto_server(NULL, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
		    ":%s UNKLINE %s %s %s",
		    source_p->name, parv[3], user, host);
      
      if(match(parv[3], me.name) == 0)
        return;
    }
  }

  if(remove_tkline_match(host, user))
    {
      sendto_one(source_p,
		 ":%S NOTICE %s :Un-klined [%s@%s] from temporary k-lines",
		 me.name, parv[0],user, host);
      sendto_realops_flags(FLAGS_ALL, L_OPER, 
              "%s has removed the temporary K-Line for: [%s@%s]",
			   get_oper_name(source_p), user, host);
      ilog(L_NOTICE, "%s removed temporary K-Line for [%s@%s]", parv[0], user,
	   host);
      return;
    }

  remove_permkline_match(source_p, host, user);
}

/* ms_unkline()
 *
 * input	- pointer to servere
 * 		- pointer to client
 * 		- parm count
 * 		- params
 * output	- none
 * side effects - kline is removed if matching shared {} is found.
 */
static void ms_unkline(struct Client *client_p, struct Client *source_p,
		     int parc, char *parv[])
{
  char *kuser;
  char *khost;
  
  if(parc != 4)
    return;

  /* parv[0]  parv[1]        parv[2]  parv[3]
   * oper     target server  user     host    */
  sendto_server(client_p, source_p, NULL, NOCAPS, NOCAPS, LL_ICLIENT,
		":%s UNKLINE %s %s %s",
		parv[0], parv[1], parv[2], parv[3]);

  kuser = parv[2];
  khost = parv[3];

  if(!match(parv[1], me.name))
    return;

  if(!IsPerson(source_p))
    return;

  sendto_realops_flags(FLAGS_ALL, L_ALL,
      "*** Received Un-kline for [%s@%s], from %s",
      kuser, khost, get_oper_name(source_p));
  
  if(remove_tkline_match(khost, kuser))
  {
    sendto_one(source_p,
            ":%s NOTICE %s :Un-klined [%s@%s] from temporary k-lines",
            me.name, parv[0],kuser, khost);

    sendto_realops_flags(FLAGS_ALL, L_ALL,
            "%s has removed the temporary K-Line for: [%s@%s]",
            get_oper_name(source_p), kuser, khost);

    ilog(L_NOTICE, "%s removed temporary K-Line for [%s@%s]",
            source_p->name, kuser, khost);
    return;
  }

  remove_permkline_match(source_p, khost, kuser);    
}

/* remove_permkline_match()
 *
 * hunts for a permanent kline, and removes it.
 */
static void remove_permkline_match(struct Client *source_p,
	                           char *host, char *user)
{
  FBFILE *in, *out;
  int pairme = 0;
  int error_on_write = NO;
  char buf[BUFSIZE];
  char buff[BUFSIZE];
  char temppath[BUFSIZE];
  const char *filename;
  mode_t oldumask;
  char *p;
  
  ircsprintf(temppath, "%s.tmp", ConfigFileEntry.klinefile);
  
  filename = get_conf_name(KLINE_TYPE);

  if ((in = fbopen(filename, "r")) == 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :Cannot open %s", me.name, source_p->name,
		 filename);
      return;
    }

  oldumask = umask(0);
  if ((out = fbopen(temppath, "w")) == 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :Cannot open %s", me.name, 
              source_p->name, temppath);
      fbclose(in);
      umask(oldumask);
      return;
    }
  umask(oldumask);

  while (fbgets(buf, sizeof(buf), in)) 
    {
      char *found_host, *found_user;

      strlcpy(buff, buf, BUFSIZE);

      if ((p = strchr(buff,'\n')) != NULL)
	*p = '\0';

      if ((*buff == '\0') || (*buff == '#'))
	{
	  if(flush_write(source_p, in, out, buf, temppath) < 0)
	    return;
	}
      
      if ((found_user = getfield(buff)) == NULL)
	{
	  if(flush_write(source_p, in, out, buf, temppath) < 0)
	    return;
	  continue;
	}

      if ((found_host = getfield(NULL)) == NULL)
	{
	  if(flush_write(source_p, in, out, buf, temppath) < 0)
	    return;
	  continue;
	}

      if ((irccmp(host,found_host) == 0) && (irccmp(user,found_user) == 0))
	{
	  pairme++;
	}
      else
	{
	  if(flush_write(source_p, in, out, buf, temppath) < 0)
	    return;
	}
    }
  fbclose(in);
  fbclose(out);

/* The result of the rename should be checked too... oh well */
/* If there was an error on a write above, then its been reported
 * and I am not going to trash the original kline /conf file
 */

  (void)rename(temppath, filename);
  rehash(0);

  if(!pairme)
    {
      sendto_one(source_p, ":%s NOTICE %s :No K-Line for %s@%s",
                 me.name, source_p->name,user,host);
      return;
    }

  if(MyConnect(source_p))
    sendto_one(source_p, ":%s NOTICE %s :K-Line for [%s@%s] is removed", 
             me.name, source_p->name, user,host);
  sendto_realops_flags(FLAGS_ALL, L_ALL,
		       "%s has removed the K-Line for: [%s@%s]",
		       get_oper_name(source_p), user, host);

  ilog(L_NOTICE, "%s removed K-Line for [%s@%s]",
       source_p->name, user, host);
  return; 
}

/*
 * flush_write()
 *
 * inputs       - pointer to client structure of oper requesting unkline
 *		- in is the input file descriptor
 *              - out is the output file descriptor
 *              - buf is the buffer to write
 *              - ntowrite is the expected number of character to be written
 *              - temppath is the temporary file name to be written
 * output       - -1 for error on write
 *              - 0 for ok
 * side effects - if successful, the buf is written to output file
 *                if a write failure happesn, and the file pointed to
 *                by temppath, if its non NULL, is removed.
 *
 * The idea here is, to be as robust as possible when writing to the 
 * kline file.
 *
 * -Dianora
 */

static int
flush_write(struct Client *source_p, FBFILE *in, FBFILE* out, 
	    char *buf, char *temppath)
{
  int error_on_write = (fbputs(buf, out) < 0) ? (-1) : (0);

  if (error_on_write)
    {
      sendto_one(source_p,":%s NOTICE %s :Unable to write to %s aborting",
        me.name, source_p->name, temppath );
      fbclose(in);
      fbclose(out);
      if(temppath != (char *)NULL)
        (void)unlink(temppath);
    }
  return(error_on_write);
}

/* static int remove_tkline_match(char *host, char *user)
 * Input: A hostname, a username to unkline.
 * Output: returns YES on success, NO if no tkline removed.
 * Side effects: Any matching tklines are removed.
 */
static int
remove_tkline_match(char *host, char *user)
{
  struct ConfItem *tk_c;
  dlink_node *tk_n;
  struct irc_inaddr addr, caddr;
  int nm_t, cnm_t, bits, cbits;
  nm_t = parse_netmask(host, &addr, &bits);

  for (tk_n=temporary_klines.head; tk_n; tk_n=tk_n->next)
    {
      tk_c = (struct ConfItem*)tk_n->data;
      cnm_t = parse_netmask(tk_c->host, &caddr, &cbits);
      if (cnm_t != nm_t || irccmp(user, tk_c->user))
	continue;
      if ((nm_t==HM_HOST && !irccmp(tk_c->host, host)) ||
	  (nm_t==HM_IPV4 && bits==cbits && match_ipv4(&addr, &caddr, bits))
#ifdef IPV6
	  || (nm_t==HM_IPV6 && bits==cbits && match_ipv6(&addr, &caddr, bits))
#endif
	  )
	{
	  dlinkDelete(tk_n, &temporary_klines);
	  free_dlink_node(tk_n);
	  delete_one_address_conf(tk_c->host, tk_c);
	  return YES;
	}
    }
  return NO;
}

/*
** m_undline
** added May 28th 2000 by Toby Verrall <toot@melnet.co.uk>
** based totally on m_unkline
** added to hybrid-7 7/11/2000 --is
**
**      parv[0] = sender nick
**      parv[1] = dline to remove
*/
static void
mo_undline (struct Client *client_p, struct Client *source_p,
            int parc,char *parv[])
{
  FBFILE* in;
  FBFILE* out;
  char  buf[BUFSIZE], buff[BUFSIZE], temppath[BUFSIZE], *p;
  const char  *filename,*cidr, *found_cidr;
  int pairme = NO;
  mode_t oldumask;

  ircsprintf(temppath, "%s.tmp", ConfigFileEntry.dlinefile);

  if (!IsOperUnkline(source_p))
    {
      sendto_one(source_p,":%s NOTICE %s :You need unkline = yes;",me.name,
		 parv[0]);
      return;
    }

  cidr = parv[1];

#if 0
  if ((type=parse_netmask(cidr,&ip_host,&ip_mask)) == HM_HOST)
    {
      sendto_one(source_p, ":%s NOTICE %s :Invalid parameters",
		 me.name, parv[0]);
      return;
    }
#endif

  filename = get_conf_name(DLINE_TYPE);

  if ((in = fbopen(filename, "r")) == 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :Cannot open %s",
		 me.name,parv[0],filename);
      return;
    }

  oldumask = umask(0);                  /* ircd is normally too paranoid */
  if ((out = fbopen(temppath, "w")) == NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :Cannot open %s",
		 me.name,parv[0],temppath);
      fbclose(in);
      umask(oldumask);                  /* Restore the old umask */
      return;
    }
  umask(oldumask);                    /* Restore the old umask */

  while(fbgets(buf, sizeof(buf), in))
    {
      strlcpy(buff, buf, BUFSIZE);

      if ((p = strchr(buff,'\n')) != NULL)
	*p = '\0';

      if ((*buff == '\0') || (*buff == '#'))
	{
	  if(flush_write(source_p, in, out, buf, temppath) < 0)
	    return;
  	   continue;
	}

      if ((found_cidr = getfield(buff)) == NULL)
	{
	  if(flush_write(source_p, in, out, buf, temppath) < 0)
	    return;
	  continue;
	}
      
      if (irccmp(found_cidr,cidr) == 0)
	{
	  pairme++;
	}
      else
	{
	  if(flush_write(source_p, in, out, buf, temppath) < 0)
	    return;
	}
    }

  fbclose(in);
  fbclose(out);

  (void)rename(temppath, filename);
  rehash(0);

  if (!pairme)
    {
      sendto_one(source_p, ":%s NOTICE %s :No D-Line for %s", me.name,
		 parv[0],cidr);
      return;
    }

  sendto_one(source_p, ":%s NOTICE %s :D-Line for [%s] is removed",
	     me.name, parv[0], cidr);
  sendto_realops_flags(FLAGS_ALL, L_OPER, "%s has removed the D-Line for: "
          "[%s]", get_oper_name(source_p), cidr);
  ilog(L_NOTICE, "%s removed D-Line for [%s]", get_oper_name(source_p),
       cidr);
}

/*
** m_ungline
** added May 29th 2000 by Toby Verrall <toot@melnet.co.uk>
** added to hybrid-7 7/11/2000 --is
**
**      parv[0] = sender nick
**      parv[1] = gline to remove
*/

static void
mo_ungline(struct Client *client_p, struct Client *source_p,
	   int parc,char *parv[])
{
  char  *user,*host;

  if (!ConfigFileEntry.glines)
    {
      sendto_one(source_p,":%s NOTICE %s :UNGLINE disabled",me.name,parv[0]);
      return;
    }

  if (!IsOperUnkline(source_p) || !IsOperGline(source_p))
    {
      sendto_one(source_p,":%s NOTICE %s :You need unkline = yes;",
                 me.name,parv[0]);
      return;
    }

  if ((host = strchr(parv[1], '@')) || *parv[1] == '*')
    {
      /* Explicit user@host mask given */

      if(host != NULL)                  /* Found user@host */
        {
          user = parv[1];       /* here is user part */
          *(host++) = '\0';     /* and now here is host */
        }
      else
        {
          user = "*";           /* no @ found, assume its *@somehost */
          host = parv[1];
        }
    }
  else
    {
      sendto_one(source_p, ":%s NOTICE %s :Invalid parameters",
                 me.name, parv[0]);
      return;
    }

  if(remove_gline_match(user, host))
    {
      sendto_one(source_p, ":%s NOTICE %s :Un-glined [%s@%s]",
                 me.name, parv[0],user, host);
      sendto_realops_flags(FLAGS_ALL, L_OPER, "%s has removed the G-Line "
              "for: [%s@%s]", get_oper_name(source_p), user, host );
      ilog(L_NOTICE, "%s removed G-Line for [%s@%s]",
          get_oper_name(source_p), user, host);
      return;
    }
  else
    {
      sendto_one(source_p, ":%s NOTICE %s :No G-Line for %s@%s",
                 me.name, parv[0],user,host);
      return;
    }
}


