/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  parse.c: The message parser.
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
#include "parse.h"
#include "client.h"
#include "channel.h"
#include "handlers.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "numeric.h"
#include "s_log.h"
#include "s_stats.h"
#include "send.h"
#include "ircd_handler.h"
#include "msg.h"
#include "s_conf.h"
#include "memory.h"
#include "s_serv.h"

/*
 * (based on orabidoo's parser code)
 *
 * This has always just been a trie. Look at volume III of Knuth ACP
 *
 *
 * ok, you start out with an array of pointers, each one corresponds
 * to a letter at the current position in the command being examined.
 *
 * so roughly you have this for matching 'trie' or 'tie'
 *
 * 't' points -> [MessageTree *] 'r' -> [MessageTree *] -> 'i'
 *   -> [MessageTree *] -> [MessageTree *] -> 'e' and matches
 *
 *				 'i' -> [MessageTree *] -> 'e' and matches
 *
 * BUGS (Limitations!)
 * 
 * I designed this trie to parse ircd commands. Hence it currently
 * casefolds. This is trivial to fix by increasing MAXPTRLEN.
 * This trie also "folds" '{' etc. down. This means, the input to this
 * trie must be alpha tokens only. This again, is a limitation that
 * can be overcome by increasing MAXPTRLEN to include upper/lower case
 * at the expense of more memory. At the extreme end, you could make
 * MAXPTRLEN 128.
 *
 * This is also not a patricia trie. On short ircd tokens, this is
 * not likely going to matter. 
 *
 * Diane Bruce (Dianora), June 6 2003
 */

#define MAXPTRLEN	32
                                /* Must be a power of 2, and
				 * larger than 26 [a-z]|[A-Z]
				 * its used to allocate the set
				 * of pointers at each node of the tree
				 * There are MAXPTRLEN pointers at each node.
				 * Obviously, there have to be more pointers
				 * Than ASCII letters. 32 is a nice number
				 * since there is then no need to shift
				 * 'A'/'a' to base 0 index, at the expense
				 * of a few never used pointers. For a small
				 * parser like this, this is a good compromise
				 * and does make it somewhat faster.
				 *
				 * - Dianora
				 */

struct MessageTree
{
  int links; /* Count of nodes =under= this node */
  struct Message *msg;
  struct MessageTree *pointers[MAXPTRLEN];
};

static struct MessageTree msg_tree;

/*
 * NOTE: parse() should not be called recursively by other functions!
 */
static char *sender;
static char *para[MAXPARA + 1];
static char buffer[1024];

static int cancel_clients(struct Client *, struct Client *, char *);
static void remove_unknown(struct Client *, char *, char *);
static void do_numeric(char[], struct Client *, struct Client *, int, char **);
static void handle_command(struct Message *, struct Client *, struct Client *, unsigned int, char **);
static void recurse_report_messages(struct Client *source_p, struct MessageTree *mtree);
static void add_msg_element(struct MessageTree *mtree_p, struct Message *msg_p, const char *cmd);
static void del_msg_element(struct MessageTree *mtree_p, const char *cmd);

/* turn a string into a parc/parv pair */
static inline int
string_to_array(char *string, char *parv[MAXPARA])
{
  char *p;
  char *buf = string;
  int x = 1;

  parv[x] = NULL;

  while (*buf == ' ') /* skip leading spaces */
    buf++;

  if (*buf == '\0') /* ignore all-space args */
    return(x);

  do
  {
    if (*buf == ':') /* Last parameter */
    {
      buf++;
      parv[x++] = buf;
      parv[x]   = NULL;
      return(x);
    }
    else
    {
      parv[x++] = buf;
      parv[x]   = NULL;

      if ((p = strchr(buf, ' ')) != NULL)
      {
        *p++ = '\0';
        buf  = p;
      }
      else
        return(x);
    }       

    while (*buf == ' ')
      buf++;

    if (*buf == '\0')
      return(x);
  } while (x < MAXPARA - 1);

  if (*p == ':')
    p++;

  parv[x++] = p;
  parv[x]   = NULL;
  return(x);
}

/*
 * parse a buffer.
 *
 * NOTE: parse() should not be called recusively by any other functions!
 */
void
parse(struct Client *client_p, char *pbuffer, char *bufend)
{
  struct Client *from = client_p;
  char *ch;
  char *s;
  char *numeric = 0;
  unsigned int i = 0;
  int paramcount;
  int mpara = 0;
  struct Message *mptr;

  if (IsDefunct(client_p))
    return;

  assert(client_p->localClient->fd >= 0);
  assert((bufend - pbuffer) < 512);

  for (ch = pbuffer; *ch == ' '; ch++) /* skip spaces */
    /* null statement */ ;

  para[0] = from->name;

  if (*ch == ':')
  {
    ch++;

    /* Copy the prefix to 'sender' assuming it terminates
     * with SPACE (or NULL, which is an error, though).
     */
    sender = ch;

    if ((s = strchr(ch, ' ')) != NULL)
    {
      *s = '\0';
      s++;
      ch = s;
    }

    if (*sender && IsServer(client_p))
    {
      from = find_client(sender);

      if (from == NULL)
      {
        from = find_server(sender);

        if (from == NULL)
          from = hash_find_id(sender);
      }

      /* Hmm! If the client corresponding to the
       * prefix is not found--what is the correct
       * action??? Now, I will ignore the message
       * (old IRC just let it through as if the
       * prefix just wasn't there...) --msa
       */
      if (from == NULL)
      {
        ServerStats->is_unpf++;
        remove_unknown(client_p, sender, pbuffer);
        return;
      }

      para[0] = from->name;

      if (from->from != client_p)
      {
        ServerStats->is_wrdi++;
        cancel_clients(client_p, from, pbuffer);
        return;
      }
    }

    while (*ch == ' ')
      ch++;
  }

  if (*ch == '\0')
  {
    ServerStats->is_empt++;
    return;
  }

  /* Extract the command code from the packet.  Point s to the end
   * of the command code and calculate the length using pointer
   * arithmetic.  Note: only need length for numerics and *all*
   * numerics must have parameters and thus a space after the command
   * code. -avalon
   */

  /* EOB is 3 chars long but is not a numeric */
  if (*(ch + 3) == ' ' && /* ok, lets see if its a possible numeric.. */
      IsDigit(*ch) && IsDigit(*(ch + 1)) && IsDigit(*(ch + 2)))
  {
    mptr = NULL;
    numeric = ch;
    paramcount = MAXPARA;
    ServerStats->is_num++;
    s = ch + 3;  /* I know this is ' ' from above if            */
    *s++ = '\0'; /* blow away the ' ', and point s to next part */
  }
  else
  { 
    int ii = 0;

    if ((s = strchr(ch, ' ')) != NULL)
      *s++ = '\0';

    mptr = find_command(ch);

    if ((mptr == NULL) || (mptr->cmd == NULL))
    {
      /* Note: Give error message *only* to recognized
       * persons. It's a nightmare situation to have
       * two programs sending "Unknown command"'s or
       * equivalent to each other at full blast....
       * If it has got to person state, it at least
       * seems to be well behaving. Perhaps this message
       * should never be generated, though...  --msa
       * Hm, when is the buffer empty -- if a command
       * code has been found ?? -Armin
       */
      if (pbuffer[0] != '\0')
      {
        if (IsPerson(from))
          sendto_one(from, form_str(ERR_UNKNOWNCOMMAND),
                     me.name, from->name, ch);
      }

      ServerStats->is_unco++;
      return;
    }

    paramcount = mptr->parameters;
    mpara      = mptr->maxpara;

    ii = bufend - ((s) ? s : ch);
    mptr->bytes += ii;

    /*
     * hidden commands set para[0] to the command (case intact)
     * used to call their function
     */
    if (mptr->flags & MFLG_HIDDEN)
      para[0] = ch;
  }

  if (s != NULL)
    i = string_to_array(s, para);
  else
  {
    i = 0;
    para[1] = NULL;
  }

  if (mptr == NULL)
    do_numeric(numeric, client_p, from, i, para);
  else
    handle_command(mptr, client_p, from, i, para);
}

/* handle_command()
 *
 * inputs	- pointer to message block
 *		- pointer to client
 *		- pointer to client message is from
 *		- count of number of args
 *		- pointer to argv[] array
 * output	- -1 if error from server
 * side effects	-
 */
static void
handle_command(struct Message *mptr, struct Client *client_p,
               struct Client *from, unsigned int i, char *hpara[MAXPARA])
{
  MessageHandler handler = 0;

  if (IsServer(client_p))
    mptr->rcount++;

  mptr->count++;

  /* New patch to avoid server flooding from unregistered connects
   * - Pie-Man 07/27/2000 */
  if (!IsRegistered(client_p))
  {
    /* if its from a possible server connection
     * ignore it.. more than likely its a header thats sneaked through
     */
    if ((IsHandshake(client_p) || IsConnecting(client_p) ||
        IsServer(client_p)) && !(mptr->flags & MFLG_UNREG))
      return;
  }

  handler = mptr->handlers[client_p->handler];

  /* check right amount of params is passed... --is */
  if (i < mptr->parameters)
  {
    if (!IsServer(client_p))
    {
      sendto_one(client_p, form_str(ERR_NEEDMOREPARAMS),
                   me.name, EmptyString(hpara[0]) ? "*" : hpara[0], mptr->cmd);
    }
    else
    {
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                           "Dropping server %s due to (invalid) command '%s'"
                           "with only %d arguments (expecting %d).",
                           client_p->name, mptr->cmd, i, mptr->parameters);
      ilog(L_CRIT, "Insufficient parameters (%d) for command '%s' from %s.",
           i, mptr->cmd, client_p->name);
      exit_client(client_p, client_p, client_p,
                  "Not enough arguments to server command.");
    }
  }
  else
    (*handler)(client_p, from, i, hpara);
}

/* clear_hash_parse()
 *
 * inputs       -
 * output       - NONE
 * side effects - MUST MUST be called at startup ONCE before
 *                any other keyword routine is used.
 */
void
clear_hash_parse(void)
{
  memset(&msg_tree, 0, sizeof(msg_tree));
}

/* add_msg_element()
 *
 * inputs	- pointer to MessageTree
 *		- pointer to Message to add for given command
 *		- pointer to current portion of command being added
 * output	- NONE
 * side effects	- recursively build the Message Tree ;-)
 */
static void
add_msg_element(struct MessageTree *mtree_p, struct Message *msg_p, const char *cmd)
{
  struct MessageTree *ntree_p;

  if (*cmd == '\0')
  {
    mtree_p->msg = msg_p;
    return;
  }

  if ((ntree_p = mtree_p->pointers[*cmd & (MAXPTRLEN-1)]) != NULL)
  {
    mtree_p->links++;
    add_msg_element(ntree_p, msg_p, cmd+1);
  }
  else
  {
    ntree_p = (struct MessageTree *)MyMalloc(sizeof(struct MessageTree));
    mtree_p->pointers[*cmd & (MAXPTRLEN-1)] = ntree_p;
    mtree_p->links++;
    add_msg_element(ntree_p, msg_p, cmd+1);
  }
}

/* del_msg_element()
 *
 * inputs	- Pointer to MessageTree to delete from
 *		- pointer to command name to delete
 * output	- NONE
 * side effects	- recursively deletes a token from the Message Tree ;-)
 */
static void
del_msg_element(struct MessageTree *mtree_p, const char *cmd)
{
  struct MessageTree *ntree_p;

  if (*cmd == '\0')
    return;

  if ((ntree_p = mtree_p->pointers[*cmd & (MAXPTRLEN-1)]) != NULL)
  {
    del_msg_element(ntree_p, cmd+1);
    ntree_p->links--;

    /* this would be bad if it happened */
    if (ntree_p != &msg_tree)
    {
      if (ntree_p->links == 0)
      {
	MyFree(ntree_p);
	mtree_p->pointers[*cmd & (MAXPTRLEN-1)] = NULL;
      }
    }
  }
}

/* msg_tree_parse()
 *
 * inputs	- Pointer to command to find
 *		- Pointer to MessageTree root
 * output	- Find given command returning Message * if found NULL if not
 * side effects	- none
 */
static struct Message *
msg_tree_parse(const char *cmd, struct MessageTree *root)
{
  struct MessageTree *mtree;
  for (mtree = root->pointers[(*cmd++) & (MAXPTRLEN-1)]; mtree != NULL;
       mtree = mtree->pointers[(*cmd++) & (MAXPTRLEN-1)])
  {
    if ((mtree->msg != NULL) && (*cmd == '\0'))
      return(mtree->msg);
  }

  return(NULL);
}

/* mod_add_cmd()
 *
 * inputs	- command name
 *		- pointer to struct Message
 * output	- none
 * side effects - load this one command name
 *		  msg->count msg->bytes is modified in place, in
 *		  modules address space. Might not want to do that...
 */
void
mod_add_cmd(struct Message *msg)
{
  struct Message *found_msg;

  if (msg == NULL)
    return;

  /* command already added? */
  if ((found_msg = msg_tree_parse(msg->cmd, &msg_tree)) != NULL)
    return;

  add_msg_element(&msg_tree, msg, msg->cmd);
  msg->count = msg->rcount = msg->bytes = 0;
}

/* mod_del_cmd()
 *
 * inputs	- command name
 * output	- none
 * side effects - unload this one command name
 */
void
mod_del_cmd(struct Message *msg)
{
  assert(msg != NULL);

  if (msg == NULL)
    return;

  del_msg_element(&msg_tree, msg->cmd);
}

/* find_command()
 *
 * inputs	- command name
 * output	- pointer to struct Message
 * side effects - none
 */
struct Message *
find_command(const char *cmd)
{
  return(msg_tree_parse(cmd, &msg_tree));
}

/* report_messages()
 *
 * inputs	- pointer to client to report to
 * output	- NONE
 * side effects	- client is shown list of commands
 */
void
report_messages(struct Client *source_p)
{
  struct MessageTree *mtree;
  int i;

  mtree = &msg_tree;

  for (i = 0; i < MAXPTRLEN; i++)
  {
    if (mtree->pointers[i] != NULL)
      recurse_report_messages(source_p, mtree->pointers[i]);
  }
}

static void
recurse_report_messages(struct Client *source_p, struct MessageTree *mtree)
{
  int i;

  if (mtree->msg != NULL)
  {
    if (!((mtree->msg->flags & MFLG_HIDDEN) && !IsAdmin(source_p)))
      sendto_one(source_p, form_str(RPL_STATSCOMMANDS),
		 me.name, source_p->name, mtree->msg->cmd,
		 mtree->msg->count, mtree->msg->bytes,
		 mtree->msg->rcount);
  }

  for (i = 0; i < MAXPTRLEN; i++)
  {
    if (mtree->pointers[i] != NULL)
      recurse_report_messages(source_p, mtree->pointers[i]);
  }
}

/* cancel_clients()
 *
 * inputs	- 
 * output	- 
 * side effects	- 
 */
static int
cancel_clients(struct Client *client_p, struct Client *source_p, char *cmd)
{
  /* kill all possible points that are causing confusion here,
   * I'm not sure I've got this all right...
   * - avalon
   *
   * knowing avalon, probably not.
   */

  /* with TS, fake prefixes are a common thing, during the
   * connect burst when there's a nick collision, and they
   * must be ignored rather than killed because one of the
   * two is surviving.. so we don't bother sending them to
   * all ops everytime, as this could send 'private' stuff
   * from lagged clients. we do send the ones that cause
   * servers to be dropped though, as well as the ones from
   * non-TS servers -orabidoo
   */
  /* Incorrect prefix for a server from some connection.  If it is a
   * client trying to be annoying, just QUIT them, if it is a server
   * then the same deal.
   */
  if (IsServer(source_p) || IsMe(source_p))
  {
    sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL, "Message for %s[%s] from %s",
                         source_p->name, source_p->from->name,
                         get_client_name(client_p, SHOW_IP));

    if (IsServer(client_p))
    {
      sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL,
                           "Not dropping server %s (%s) for Fake Direction",
                           client_p->name, source_p->name);
      return(-1);
    }

    if (IsClient(client_p))
      sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL,
                           "Would have dropped client %s (%s@%s) [%s from %s]",
                           client_p->name, client_p->username, client_p->host,
                           client_p->user->server->name, client_p->from->name);
    return(-1);

    /* return exit_client(client_p, client_p, &me, "Fake Direction");*/
  }

  /* Ok, someone is trying to impose as a client and things are
   * confused.  If we got the wrong prefix from a server, send out a
   * kill, else just exit the lame client.
   */
  if (IsServer(client_p))
  {
    /* If the fake prefix is coming from a TS server, discard it
     * silently -orabidoo
     *
     * all servers must be TS these days --is
     */
    if (source_p->user != NULL)
    {
      sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL,
                           "Message for %s[%s@%s!%s] from %s (TS, ignored)",
                           source_p->name, source_p->username, source_p->host,
                           source_p->from->name, get_client_name(client_p, SHOW_IP));
    }

    return(0);
 }

  return(exit_client(client_p, client_p, &me, "Fake prefix"));
}

/* remove_unknown()
 *
 * inputs	- 
 * output	- 
 * side effects	- 
 */
static void
remove_unknown(struct Client *client_p, char *lsender, char *lbuffer)
{
  if (!IsRegistered(client_p))
    return;

  if (IsClient(client_p))
  {
    sendto_gnotice_flags(UMODE_DEBUG, L_ALL, me.name, &me, NULL,
                         "Weirdness: Unknown client prefix (%s) from %s, Ignoring %s",
                         lbuffer, get_client_name(client_p, SHOW_IP), lsender);
    return;
  }

  /* Not from a server so don't need to worry about it.
   */
  if (!IsServer(client_p))
    return;

  /* Do kill if it came from a server because it means there is a ghost
   * user on the other server which needs to be removed. -avalon
   * Tell opers about this. -Taner
   */
  /* '.something'      is an ID      (KILL)
   * 'nodots'          is a nickname (KILL)
   * 'no.dot.at.start' is a server   (SQUIT)
   */
  if ((lsender[0] == '.') || !strchr(lsender, '.'))
    sendto_one(client_p, ":%s KILL %s :%s (Unknown Client)",
               me.name, lsender, me.name);
  else
  {
    sendto_gnotice_flags(UMODE_DEBUG, L_ADMIN, me.name, &me, NULL,
                         "Unknown prefix (%s) from %s, Squitting %s",
                         lbuffer, get_client_name(client_p, SHOW_IP), lsender);
    sendto_gnotice_flags(UMODE_DEBUG, L_OPER, me.name, &me, NULL,
                         "Unknown prefix (%s) from %s, Squitting %s",
                         lbuffer, client_p->name, lsender);
    sendto_one(client_p, ":%s SQUIT %s :(Unknown prefix (%s) from %s)",
               me.name, lsender, lbuffer, client_p->name);
  }
}

/*
 *
 *      parc    number of arguments ('sender' counted as one!)
 *      parv[0] pointer to 'sender' (may point to empty string) (not used)
 *      parv[1]..parv[parc-1]
 *              pointers to additional parameters, this is a NULL
 *              terminated list (parv[parc] == NULL).
 *
 * *WARNING*
 *      Numerics are mostly error reports. If there is something
 *      wrong with the message, just *DROP* it! Don't even think of
 *      sending back a neat error message -- big danger of creating
 *      a ping pong error message...
 */
static void
do_numeric(char numeric[], struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p;
  struct Channel *chptr;

  if (parc < 2 || !IsServer(source_p))
    return;

  /* Remap low number numerics. */
  if (numeric[0] == '0')
    numeric[0] = '1';

  /* Prepare the parameter portion of the message into 'buffer'.
   * (Because the buffer is twice as large as the message buffer
   * for the socket, no overflow can occur here... ...on current
   * assumptions--bets are off, if these are changed --msa)
   * Note: if buffer is non-empty, it will begin with SPACE.
   */
  if (parc > 1)
  {
    char *t = buffer; /* Current position within the buffer */
    int i;
    int tl; /* current length of presently being built string in t */

    for (i = 2; i < (parc - 1); i++)
    {
      tl = ircsprintf(t, " %s", parv[i]);
      t += tl;
    }

    ircsprintf(t," :%s", parv[parc-1]);
  }

  if ((target_p = find_client(parv[1])) != NULL)
  {
    if (IsMe(target_p)) 
    {
      /*
       * We shouldn't get numerics sent to us,
       * any numerics we do get indicate a bug somewhere..
       */
      /* ugh.  this is here because of nick collisions.  when two servers
       * relink, they burst each other their nicks, then perform collides.
       * if there is a nick collision, BOTH servers will kill their own
       * nicks, and BOTH will kill the other servers nick, which wont exist,
       * because it will have been already killed by the local server.
       *
       * unfortunately, as we cant guarantee other servers will do the
       * "right thing" on a nick collision, we have to keep both kills.  
       * ergo we need to ignore ERR_NOSUCHNICK. --fl_
       */
      /* quick comment. This _was_ tried. i.e. assume the other servers
       * will do the "right thing" and kill a nick that is colliding.
       * unfortunately, it did not work. --Dianora
       */
      if (atoi(numeric) != ERR_NOSUCHNICK)
        sendto_gnotice_flags(UMODE_ALL, L_ADMIN, me.name, &me, NULL,
			     "*** %s(via %s) sent a %s numeric to me: %s",
			     source_p->name, client_p->name, numeric, buffer);
      return;
    }
    else if (target_p->from == client_p) 
    {
      /* This message changed direction (nick collision?)
       * ignore it.
       */
      return;
    }

    /* csircd will send out unknown umode flag for +a (admin), drop it here. */
    if ((atoi(numeric) == ERR_UMODEUNKNOWNFLAG) && MyClient(target_p))
      return;
    
    /* Fake it for server hiding, if its our client */
    if (ConfigServerHide.hide_servers &&
        MyClient(target_p) && !IsOper(target_p))
      sendto_one(target_p, ":%s %s %s%s", me.name, numeric, parv[1], buffer);
    else
      sendto_one(target_p, ":%s %s %s%s", source_p->name, numeric, parv[1], buffer);
    return;
  }
  else if ((chptr = hash_find_channel(parv[1])) != NULL)
    sendto_channel_local(ALL_MEMBERS, chptr,
			 ":%s %s %s %s",
			 source_p->name,
			 numeric, chptr->chname, buffer);
}

/* m_not_oper()
 * inputs	- 
 * output	-
 * side effects	- just returns a nastyogram to given user
 */
void
m_not_oper(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
             me.name, parv[0]);
}

void
m_unregistered(struct Client *client_p, struct Client *source_p,
               int parc, char *parv[])
{
  /* bit of a hack.
   * I don't =really= want to waste a bit in a flag
   * number_of_nick_changes is only really valid after the client
   * is fully registered..
   */
  if (client_p->localClient->number_of_nick_changes == 0)
  {
    sendto_one(client_p, ":%s %d * %s :Register first.",
               me.name, ERR_NOTREGISTERED, parv[0]);
    client_p->localClient->number_of_nick_changes++;
  }
}

void
m_registered(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  sendto_one(client_p, form_str(ERR_ALREADYREGISTRED),   
             me.name, parv[0]); 
}

void
m_ignore(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  return;
}

