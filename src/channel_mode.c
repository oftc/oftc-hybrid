/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  channel_mode.c: Controls modes on channels.
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
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "s_serv.h"             /* captab */
#include "s_user.h"
#include "send.h"
#include "whowas.h"
#include "s_conf.h"             /* ConfigFileEntry, ConfigChannel */
#include "event.h"
#include "memory.h"
#include "balloc.h"
#include "s_log.h"

static int add_id(struct Client *, struct Channel *, char *, int);
static int del_id(struct Channel *, const char *, int);

/* some small utility functions */
static char *check_string(char *s);
static char *pretty_mask(char *);
static char *fix_key(char *);
static char *fix_key_old(char *);


static void chm_nosuch(struct Client *, struct Client *,
                       struct Channel *, int, int *, char **, int *, int,
                       int, char, void *, const char *chname);

static void chm_simple(struct Client *, struct Client *, struct Channel *,
                       int, int *, char **, int *, int, int, char, void *,
                       const char *chname);

static void chm_limit(struct Client *, struct Client *, struct Channel *,
                      int, int *, char **, int *, int, int, char, void *,
                      const char *chname);

static void chm_key(struct Client *, struct Client *, struct Channel *,
                    int, int *, char **, int *, int, int, char, void *,
                    const char *chname);

static void chm_op(struct Client *, struct Client *, struct Channel *, int,
                   int *, char **, int *, int, int, char, void *,
                   const char *chname);
#ifdef USE_HALFOPS
static void chm_hop(struct Client *, struct Client *, struct Channel *, int,
                   int *, char **, int *, int, int, char, void *,
                   const char *chname);
#endif

static void chm_voice(struct Client *, struct Client *, struct Channel *,
                      int, int *, char **, int *, int, int, char, void *,
                      const char *chname);

static void chm_ban(struct Client *, struct Client *, struct Channel *, int,
                    int *, char **, int *, int, int, char, void *,
                    const char *chname);

static void chm_except(struct Client *, struct Client *, struct Channel *,
                       int, int *, char **, int *, int, int, char, void *,
                       const char *chname);

static void chm_invex(struct Client *, struct Client *, struct Channel *,
                      int, int *, char **, int *, int, int, char, void *,
                      const char *chname);

static void send_cap_mode_changes(struct Client *, struct Client *,
                                  struct Channel *, int, int);

static void send_mode_changes(struct Client *, struct Client *,
                              struct Channel *, char *chname);


/*
 * some buffers for rebuilding channel/nick lists with ,'s
 */

static char modebuf[BUFSIZE];
static char parabuf[MODEBUFLEN];
static char mask_buf[BUFSIZE];
static int mask_pos;

/* 10 is a magic number in hybrid 6 NFI where it comes from -db */
#define BAN_FUDGE	10

static struct ChModeChange mode_changes[BUFSIZE];
static int mode_count;

static int mode_limit;		/* number of modes set other than simple */
static int simple_modes_mask;	/* bit mask of simple modes already set */

static int channel_capabs[] = { CAP_EX, CAP_IE, CAP_SID };

#define NCHCAPS         (sizeof(channel_capabs)/sizeof(int))
#define NCHCAP_COMBOS   (1 << NCHCAPS)

static struct ChCapCombo chcap_combos[NCHCAP_COMBOS];

extern BlockHeap *ban_heap;

/* check_string()
 *
 * inputs       - string to check
 * output       - pointer to modified string
 * side effects - Fixes a string so that the first white space found
 *                becomes an end of string marker (`\0`).
 *                returns the 'fixed' string or "*" if the string
 *                was NULL length or a NULL pointer.
 */
static char *
check_string(char *s)
{
  char *str = s;
  static char star[] = "*";

  if (EmptyString(s))
    return(star);

  for (; *s; ++s)
  {
    if (IsSpace(*s))
    {
      *s = '\0';
      break;
    }
  }

  return(str);
}

/*
 * Ban functions to work with mode +b/e/d/I
 */
/* add the specified ID to the channel.. 
 *   -is 8/9/00 
 */

static int
add_id(struct Client *client_p, struct Channel *chptr, char *banid, int type)
{
  dlink_list *list;
  dlink_node *ban;
  struct Ban *actualBan;
  unsigned int num_mask = 0;

  /* dont let local clients overflow the b/e/I lists */
  if (MyClient(client_p))
  {
    num_mask = dlink_list_length(&chptr->banlist) +
               dlink_list_length(&chptr->exceptlist) +
               dlink_list_length(&chptr->invexlist);

    if (num_mask >= ConfigChannel.max_bans)
    {
      sendto_one(client_p, form_str(ERR_BANLISTFULL),
                 me.name, client_p->name, chptr->chname, banid);
      return(0);
    }

    collapse(banid);
  }

  switch (type)
  {
    case CHFL_BAN:
      list = &chptr->banlist;
      break;
    case CHFL_EXCEPTION:
      list = &chptr->exceptlist;
      break;
    case CHFL_INVEX:
      list = &chptr->invexlist;
      break;
    default:
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                           "add_id() called with unknown ban type %d!", type);
      return(0);
  }

  DLINK_FOREACH(ban, list->head)
  {
    actualBan = ban->data;

    if (match(actualBan->banstr, banid))
      return(0);
  }

  actualBan = (struct Ban *)BlockHeapAlloc(ban_heap);
  DupString(actualBan->banstr, banid);

  if (IsPerson(client_p))
  {
    actualBan->who =
      (char *)MyMalloc(strlen(client_p->name) +
                       strlen(client_p->username) +
                       strlen(client_p->host) + 3);
    ircsprintf(actualBan->who, "%s!%s@%s",
               client_p->name, client_p->username, client_p->host);
  }
  else
  {
    DupString(actualBan->who, client_p->name);
  }

  actualBan->when = CurrentTime;

  dlinkAdd(actualBan, &actualBan->node, list);

  return(1);
}

/*
 *
 * "del_id - delete an id belonging to client_p
 * if banid is null, deleteall banids belonging to client_p."
 *
 * from orabidoo
 * modified 8/9/00 by is: now we handle add ban types here
 * (invex/excemp/etc)
 *
 * inputs	- pointer to channel
 *		- pointer to ban id
 *		- type of ban, i.e. ban, exception, invex
 * output	- 0 for failure, 1 for success
 * side effects	-
 */
static int
del_id(struct Channel *chptr, const char *banid, int type)
{
  dlink_list *list;
  dlink_node *ban;
  struct Ban *banptr;

  if (banid == NULL)
    return(0);

  switch (type)
  {
    case CHFL_BAN:
      list = &chptr->banlist;
      break;
    case CHFL_EXCEPTION:
      list = &chptr->exceptlist;
      break;
    case CHFL_INVEX:
      list = &chptr->invexlist;
      break;
    default:
      sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                           "del_id() called with unknown ban type %d!", type);
      return(0);
  }

  DLINK_FOREACH(ban, list->head)
  {
    banptr = ban->data;

    if (irccmp(banid, banptr->banstr) == 0)
    {
      MyFree(banptr->banstr);
      MyFree(banptr->who);
      dlinkDelete(&banptr->node, list);
      BlockHeapFree(ban_heap, banptr);
      return(1);
    }
  }

  return(0);
}

static const struct mode_letter
{
  const unsigned int mode;
  const unsigned char letter;
} flags[] = {
  { MODE_INVITEONLY, 'i' },
  { MODE_MODERATED,  'm' },
  { MODE_NOPRIVMSGS, 'n' },
  { MODE_PRIVATE,    'p' },
  { MODE_SECRET,     's' },
  { MODE_TOPICLIMIT, 't' }, YYY { MODE_NOCOLOR, 'c' },
  { 0, '\0' }
};

/* channel_modes()
 *
 * inputs       - pointer to channel
 *              - pointer to client
 *              - pointer to mode buf
 *              - pointer to parameter buf
 * output       - NONE
 * side effects - write the "simple" list of channel modes for channel
 * chptr onto buffer mbuf with the parameters in pbuf.
 */
void
channel_modes(struct Channel *chptr, struct Client *client_p,
              char *mbuf, char *pbuf)
{
  int i;
  int len = 0;

  *mbuf++ = '+';
  *pbuf = '\0';

  for (i = 0; flags[i].mode; i++)
  {
    if (chptr->mode.mode & flags[i].mode)
      *mbuf++ = flags[i].letter;
  }

  /* XXX - two find_channel_link()  calls are obviously
   *       too much if we have both +l and +k. -Michael
   */
  if (chptr->mode.limit)
  {
    *mbuf++ = 'l';

    if (IsMember(client_p, chptr) || IsServer(client_p))
    {
      len = ircsprintf(pbuf, "%d ", chptr->mode.limit);
      pbuf += len;
    }
  }

  if (*chptr->mode.key)
  {
    *mbuf++ = 'k';

    if (len || IsMember(client_p, chptr) || IsServer(client_p))
      ircsprintf(pbuf, "%s ", chptr->mode.key);
  }

  *mbuf++ = '\0';
}

/* static char *
 * pretty_mask(char *mask);
 *
 * Input: A mask.
 * Output: A "user-friendly" version of the mask, in mask_buf.
 * Side-effects: mask_buf is appended to. mask_pos is incremented.
 * Notes: The following transitions are made:
 *  x!y@z =>  x!y@z
 *  y@z   =>  *!y@z
 *  x!y   =>  x!y@*
 *  x     =>  x!*@*
 *  z.d   =>  *!*@z.d
 *
 * If either nick/user/host are > than their respective limits, they are
 * chopped
 */
static char *
pretty_mask(char *mask)
{
  int old_mask_pos;
  char star[]= "*";
  char *nick = star, *user = star, *host = star;

  char *t, *at, *ex;
  char ne = 0, ue = 0, he = 0; /* save values at nick[NICKLEN], et all */
  mask = check_string(mask);

  if ((size_t)(BUFSIZE - mask_pos) < strlen(mask) + 5)
    return(NULL);

  old_mask_pos = mask_pos;

  at = ex = NULL;
  if ((t = strchr(mask, '@')) != NULL)
  {
    at = t;
    *t++ = '\0';
    if (*t != '\0')
      host = t;

    if ((t = strchr(mask, '!')) != NULL)
    {
      ex = t;
      *t++ = '\0';
      if (*t != '\0')
	user = t;
      if (*mask != '\0')
	nick = mask;
    }
    else
    {
      if (*mask != '\0')
	user = mask;
    }
  }
  else if ((t = strchr(mask, '!')) != NULL)
  {
    ex = t;
    *t++ = '\0';
    if (*mask != '\0')
      nick = mask;
    if (*t != '\0')
      user = t;
  }
  else if (strchr(mask, '.') != NULL && strchr(mask, ':') != NULL)
  {
    if (*mask != '\0')
      host = mask;
  }
  else
  {
    if (*mask != '\0')
      nick = mask;
  }

  /* truncate values to max lengths */
  if (strlen(nick) > NICKLEN - 1)
  {
    ne = nick[NICKLEN - 1];
    nick[NICKLEN - 1] = '\0';
  }
  if (strlen(user) > USERLEN)
  {
    ue = user[USERLEN];
    user[USERLEN] = '\0';
  }
  if (strlen(host) > HOSTLEN)
  {
    he = host[HOSTLEN];
    host[HOSTLEN] = '\0';
  }
    
  mask_pos += ircsprintf(mask_buf + mask_pos, "%s!%s@%s", nick, user, host) + 1;

  /* restore mask, since we may need to use it again later */
  if (at)
    *at = '@';
  if (ex)
    *ex = '!';
  if (ne)
    nick[NICKLEN - 1] = ne;
  if (ue)
    user[USERLEN] = ue;
  if (he)
    host[HOSTLEN] = he;

  return(mask_buf + old_mask_pos);
}

/* fix_key()
 * 
 * inputs       - pointer to key to clean up
 * output       - pointer to cleaned up key
 * side effects - input string is modified
 *
 * stolen from Undernet's ircd  -orabidoo
 */
static char *
fix_key(char *arg)
{
  unsigned char *s, *t, c;

  for (s = t = (unsigned char *)arg; (c = *s); s++)
  {
    c &= 0x7f;
    if (c != ':' && c > ' ' && c != ',')
      *t++ = c;
  }

  *t = '\0';
  return(arg);
}

/* fix_key_old()
 * 
 * inputs       - pointer to key to clean up
 * output       - pointer to cleaned up key
 * side effects - input string is modifed 
 *
 * Here we attempt to be compatible with older non-hybrid servers.
 * We can't back down from the ':' issue however.  --Rodder
 */
static char *
fix_key_old(char *arg)
{
  unsigned char *s, *t, c;

  for (s = t = (unsigned char *)arg; (c = *s); s++)
  {
    c &= 0x7f;
    if ((c != 0x0a) && (c != ':') && (c != 0x0d) && (c != ','))
      *t++ = c;
  }

  *t = '\0';
  return(arg);
}

/* bitmasks for various error returns that set_channel_mode should only return
 * once per call  -orabidoo
 */

#define SM_ERR_NOTS         0x00000001 /* No TS on channel  */
#define SM_ERR_NOOPS        0x00000002 /* No chan ops       */
#define SM_ERR_UNKNOWN      0x00000004
#define SM_ERR_RPL_B        0x00000008
#define SM_ERR_RPL_E        0x00000010
#define SM_ERR_NOTONCHANNEL 0x00000020 /* Not on channel    */
#define SM_ERR_RESTRICTED   0x00000040 /* Restricted chanop */
#define SM_ERR_RPL_I        0x00000080

/* Now lets do some stuff to keep track of what combinations of
 * servers exist...
 * Note that the number of combinations doubles each time you add
 * something to this list. Each one is only quick if no servers use that
 * combination, but if the numbers get too high here MODE will get too
 * slow. I suggest if you get more than 7 here, you consider getting rid
 * of some and merging or something. If it wasn't for irc+cs we would
 * probably not even need to bother about most of these, but unfortunately
 * we do. -A1kmm
 */

/* void init_chcap_usage_counts(void)
 *
 * Inputs	- none
 * Output	- none
 * Side-effects	- Initialises the usage counts to zero. Fills in the
 *                chcap_yes and chcap_no combination tables.
 */
void
init_chcap_usage_counts(void)
{
  unsigned long m, c, y, n;

  memset(chcap_combos, 0, sizeof(chcap_combos));

  /* For every possible combination */
  for (m = 0; m < NCHCAP_COMBOS; m++)
  {
    /* Check each capab */
    for (c = y = n = 0; c < NCHCAPS; c++)
    {
      if ((m & (1 << c)) == 0)
        n |= channel_capabs[c];
      else
        y |= channel_capabs[c];
    }
    chcap_combos[m].cap_yes = y;
    chcap_combos[m].cap_no  = n;
  }
}

/* void set_chcap_usage_counts(struct Client *serv_p)
 * Input: serv_p; The client whose capabs to register.
 * Output: none
 * Side-effects: Increments the usage counts for the correct capab
 *               combination.
 */
void
set_chcap_usage_counts(struct Client *serv_p)
{
  int n;

  for (n = 0; n < NCHCAP_COMBOS; n++)
  {
    if (((serv_p->localClient->caps & chcap_combos[n].cap_yes) ==
         chcap_combos[n].cap_yes) &&
        ((serv_p->localClient->caps & chcap_combos[n].cap_no) == 0))
    {
      chcap_combos[n].count++;
      return;
    }
  }

  /* This should be impossible -A1kmm. */
  assert(0);
}

/* void set_chcap_usage_counts(struct Client *serv_p)
 *
 * Inputs	- serv_p; The client whose capabs to register.
 * Output	- none
 * Side-effects	- Decrements the usage counts for the correct capab
 *                combination.
 */
void
unset_chcap_usage_counts(struct Client *serv_p)
{
  int n;

  for (n = 0; n < NCHCAP_COMBOS; n++)
  {
    if ((serv_p->localClient->caps & chcap_combos[n].cap_yes) ==
        chcap_combos[n].cap_yes &&
        (serv_p->localClient->caps & chcap_combos[n].cap_no) == 0)
    {
      /* Hopefully capabs can't change dynamically or anything... */
      assert(chcap_combos[n].count > 0);
      chcap_combos[n].count--;
      return;
    }
  }

  /* This should be impossible -A1kmm. */
  assert(0);
}

/* Mode functions handle mode changes for a particular mode... */
static void
chm_nosuch(struct Client *client_p, struct Client *source_p,
           struct Channel *chptr, int parc, int *parn,
           char **parv, int *errors, int alev, int dir, char c, void *d,
           const char *chname)
{
  if (*errors & SM_ERR_UNKNOWN)
    return;
  *errors |= SM_ERR_UNKNOWN;
  sendto_one(source_p, form_str(ERR_UNKNOWNMODE), me.name, source_p->name, c);
}

static void
chm_simple(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
           int parc, int *parn, char **parv, int *errors, int alev, int dir,
           char c, void *d, const char *chname)
{
  long mode_type;

  mode_type = (long)d;

  /* dont allow halfops to set +-p, as this controls whether they can set
   * +-h or not.. all other simple modes are ok   
   */ 
  if ((alev < CHACCESS_HALFOP) ||
      ((mode_type == MODE_PRIVATE) && (alev < CHACCESS_CHANOP)))
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  /* If have already dealt with this simple mode, ignore it */
  if (simple_modes_mask & mode_type)
    return;
  simple_modes_mask |= mode_type;

  /* setting + */
  /* Apparently, (though no one has ever told the hybrid group directly) 
   * admins don't like redundant mode checking. ok. It would have been nice 
   * if you had have told us directly. I've left the original code snippets 
   * in place. 
   * 
   * -Dianora 
   */ 
  if ((dir == MODE_ADD))  && !(chptr->mode.mode & mode_type)) 
  {
    chptr->mode.mode |= mode_type;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count++].arg = NULL;
  }
  else if ((dir == MODE_DEL)) && (chptr->mode.mode & mode_type)) YYY del anonop stuff
  {
    /* setting - */

    chptr->mode.mode &= ~mode_type;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = NULL;
    gnote = 1;
  }
  if(alev == (CHACCESS_CHANOP + 1) && MyClient(source_p) && gnote)
  {     
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0],
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  } 

}

#ifdef ANONOPS
static void
chm_hideops(struct Client *client_p, struct Client *source_p,
            struct Channel *chptr, int parc, int *parn,
            char **parv, int *errors, int alev, int dir, char c, void *d,
            const char *chname)
{
  /* if we dont support it, dont send it anywhere.  well only
   * have the capab if we support it, so we should never get
   * here for a remote server if we dont support it..
   */
  if(!ConfigChannel.use_anonops)
    return;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED), me.name,
                 source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  if (simple_modes_mask & MODE_HIDEOPS)
    return;
  simple_modes_mask |= MODE_HIDEOPS;

  if (dir == MODE_ADD && !(chptr->mode.mode & MODE_HIDEOPS))
  {
    chptr->mode.mode |= MODE_HIDEOPS;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = CAP_AOPS;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count++].arg = NULL;
  }
  else if (dir == MODE_DEL && (chptr->mode.mode & MODE_HIDEOPS))
  {
    chptr->mode.mode &= ~MODE_HIDEOPS;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = CAP_AOPS;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count++].arg = NULL;
  }
}
#endif

static void
chm_ban(struct Client *client_p, struct Client *source_p,
        struct Channel *chptr, int parc, int *parn,
        char **parv, int *errors, int alev, int dir, char c, void *d,
        const char *chname)
{
  char *mask;
  char *raw_mask;
  dlink_node *ptr;
  struct Ban *banptr;

  if (dir == 0 || parc <= *parn)
  {
    if ((*errors & SM_ERR_RPL_B) != 0)
      return;
    *errors |= SM_ERR_RPL_B;

      DLINK_FOREACH(ptr, chptr->banlist.head)
      {
        banptr = ptr->data;
        sendto_one(client_p, form_str(RPL_BANLIST),
                   me.name, client_p->name, chname,
                   banptr->banstr, banptr->who, banptr->when);
      }
    sendto_one(source_p, form_str(RPL_ENDOFBANLIST), me.name,
               source_p->name, chname);
    return;
  }

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  raw_mask = parv[(*parn)++];
  
  if (IsServer(client_p))
    mask = raw_mask;
  else
    mask = pretty_mask(raw_mask);
    
  /* if we're adding a NEW id */
  if (dir == MODE_ADD) 
  {
    if((add_id(source_p, chptr, mask, CHFL_BAN) == 0))
      return;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = mask;
  }
  else if (dir == MODE_DEL)
  {
/* XXX grrrrrrr */
#ifdef NO_BAN_COOKIE

    if (del_id(chptr, mask, CHFL_BAN) == 0)
    {
      /* mask isn't a valid ban, check raw_mask */
      if((del_id(chptr, raw_mask, CHFL_BAN) == 0) && MyClient(source_p))
      {
        /* nope */
        return;
      }
      mask = raw_mask;
    }

#else
/* XXX this hack allows /mode * +o-b nick ban.cookie
 * I'd like to see this hack go away in the future.
 */
    if (del_id(chptr, raw_mask, CHFL_BAN))
      mask = raw_mask;
    else
      del_id(chptr, mask, CHFL_BAN);
#endif

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = mask;
  }
  if(alev == CHACCESS_CHANOP + 1 && MyClient(source_p))
  {
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0],       
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  }
}

static void
chm_except(struct Client *client_p, struct Client *source_p,
           struct Channel *chptr, int parc, int *parn,
           char **parv, int *errors, int alev, int dir, char c, void *d,
           const char *chname)
{
  dlink_node *ptr;
  struct Ban *banptr;
  char *mask, *raw_mask;

  /* if we have +e disabled, allow local clients to do anything but
   * set the mode.  This prevents the abuse of +e when just a few
   * servers support it. --fl
   */
  if(!ConfigChannel.use_except && MyClient(source_p) && 
    ((dir == MODE_ADD) && (parc > *parn)))
  {
    if ((*errors & SM_ERR_RPL_E) != 0)
      return;

    *errors |= SM_ERR_RPL_E;
    return;
  }

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if ((dir == MODE_QUERY) || parc <= *parn)
  {
    if ((*errors & SM_ERR_RPL_E) != 0)
      return;
    *errors |= SM_ERR_RPL_E;

    DLINK_FOREACH(ptr, chptr->exceptlist.head)
    {
      banptr = ptr->data;
      sendto_one(client_p, form_str(RPL_EXCEPTLIST),
                 me.name, client_p->name, chname,
                 banptr->banstr, banptr->who, banptr->when);
    }
    sendto_one(source_p, form_str(RPL_ENDOFEXCEPTLIST), me.name,
               source_p->name, chname);
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  raw_mask = parv[(*parn)++];
  if (IsServer(client_p))
    mask = raw_mask;
  else
    mask = pretty_mask(raw_mask);

  /* If we're adding a NEW id */
  if (dir == MODE_ADD)
  {
    if((add_id(source_p, chptr, mask, CHFL_EXCEPTION) == 0))
      return;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = CAP_EX;
    mode_changes[mode_count].nocaps = 0;

    if(ConfigChannel.use_except)
      mode_changes[mode_count].mems = ONLY_CHANOPS; YYY do firther down
    else
      mode_changes[mode_count].mems = ONLY_SERVERS;

    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = mask;
  }
  else if (dir == MODE_DEL)
  {
    if (del_id(chptr, mask, CHFL_EXCEPTION) == 0)
    {
      /* mask isn't a valid ban, check raw_mask */
      if((del_id(chptr, raw_mask, CHFL_EXCEPTION) == 0) && MyClient(source_p))
      {
        /* nope */
        return;
      }
      mask = raw_mask;
    }

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = CAP_EX;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = mask;
  }
  if(alev == CHACCESS_CHANOP + 1 && MyClient(source_p))
  {
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0],       
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  }

}

static void
chm_invex(struct Client *client_p, struct Client *source_p,
          struct Channel *chptr, int parc, int *parn,
          char **parv, int *errors, int alev, int dir, char c, void *d,
          const char *chname)
{
  char *mask, *raw_mask;
  dlink_node *ptr;
  struct Ban *banptr;

  /* if we have +I disabled, allow local clients to do anything but
   * set the mode.  This prevents the abuse of +I when just a few
   * servers support it --fl
   */
  if(!ConfigChannel.use_invex && MyClient(source_p) && 
    (dir == MODE_ADD) && (parc > *parn))
  {
    if((*errors & SM_ERR_RPL_I) != 0)
      return;
    
    *errors |= SM_ERR_RPL_I;
    return;
  }

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED), me.name,
                 source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }
  if(alev == CHACCESS_CHANOP + 1 && MyClient(source_p))
  {
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0], 
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  }

  if ((dir == MODE_QUERY) || parc <= *parn)
  {
    if ((*errors & SM_ERR_RPL_I) != 0)
      return;
    *errors |= SM_ERR_RPL_I;

    DLINK_FOREACH(ptr, chptr->invexlist.head)
    {
      banptr = ptr->data;
      sendto_one(client_p, form_str(RPL_INVITELIST), me.name,
                 client_p->name, chname, banptr->banstr,
                 banptr->who, banptr->when);
    }
    sendto_one(source_p, form_str(RPL_ENDOFINVITELIST), me.name,
               source_p->name, chname);
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  raw_mask = parv[(*parn)++];
  if (IsServer(client_p))
    mask = raw_mask;
  else
    mask = pretty_mask(raw_mask);

  if (dir == MODE_ADD)
  {
    if ((add_id(source_p, chptr, mask, CHFL_INVEX) == 0))
      return;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = CAP_IE;
    mode_changes[mode_count].nocaps = 0;
    
    if(ConfigChannel.use_invex)
      mode_changes[mode_count].mems = ONLY_CHANOPS;
    else
      mode_changes[mode_count].mems = ONLY_SERVERS;

    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = mask;
  }
  else if (dir == MODE_DEL)
  {
    if (del_id(chptr, mask, CHFL_INVEX) == 0)
    {
      /* mask isn't a valid ban, check raw_mask */
      if ((del_id(chptr, raw_mask, CHFL_INVEX) == 0) && MyClient(source_p))
      {
        /* nope */
        return;
      }
      mask = raw_mask;
    }

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = CAP_IE;
    mode_changes[mode_count].nocaps = 0;

    if (ConfigChannel.use_invex)
      mode_changes[mode_count].mems = ONLY_CHANOPS;
    else
      mode_changes[mode_count].mems = ONLY_SERVERS;

    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = mask;
  }
}

static void
chm_op(struct Client *client_p, struct Client *source_p,
       struct Channel *chptr, int parc, int *parn,
       char **parv, int *errors, int alev, int dir, char c, void *d,
       const char *chname)
{
  int i, was_hopped;
  char *opnick;
  struct Client *targ_p;
  struct Membership *member;

  if (alev < CHACCESS_CHANOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if ((dir == MODE_QUERY) || (parc <= *parn))
    return;

  if (IsRestricted(source_p) && (dir == MODE_ADD))
  {
    if (!(*errors & SM_ERR_RESTRICTED))
      sendto_one(source_p, 
                 ":%s NOTICE %s :*** Notice -- You are restricted and cannot "
		 "chanop others", me.name, source_p->name);
    
    *errors |= SM_ERR_RESTRICTED;
    return;
  }

  opnick = parv[(*parn)++];

  if ((targ_p = find_chasing(source_p, opnick, NULL)) == NULL)
  {
    return;
  }

  if (!IsMember(targ_p, chptr))
  {
    if (!(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one(source_p, form_str(ERR_USERNOTINCHANNEL), me.name,
                 source_p->name, chname, opnick);
    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  mode_get_status(chptr, targ_p, &t_op, &t_hop, &t_voice, 1);

  if (((dir == MODE_ADD) && t_op) ||
      ((dir == MODE_DEL) && !t_op
#ifdef HALFOPS
       && !t_hop
#endif
    ))
    return;

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  /* Cancel mode changes... */

  for (i = 0; i < mode_count; i++)
    if (mode_changes[i].dir == MODE_ADD && 
        (mode_changes[i].letter == 'o'
#ifdef HALFOPS
         || mode_changes[i].letter == 'h'
#endif
#ifndef REQUIRE_OANDV
         || mode_changes[i].letter == 'v'
#endif
       )
        && mode_changes[i].client == targ_p)
    {
      if (mode_changes[i].letter == 'o')
      {
        mode_changes[i].letter = 0;
        return;
      }
#ifdef HALFOPS
      else if (mode_changes[i].letter == 'h')
        wasnt_hopped = 1;
#endif
      else if (mode_changes[i].letter == 'v')
        wasnt_voiced = 1;
      mode_changes[i].letter = 0;
    }

  if (dir == MODE_ADD)
  {

#ifndef REQUIRE_OANDV
    if (!wasnt_voiced && t_voice)
    {
      mode_changes[mode_count].letter = 'v';
      mode_changes[mode_count].dir = MODE_DEL;
      mode_changes[mode_count].caps = 0;
      mode_changes[mode_count].nocaps = 0;
      mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
      mode_changes[mode_count].id = targ_p->user->id;
      mode_changes[mode_count].arg = targ_p->name;
      mode_changes[mode_count++].client = targ_p;
    }
#endif
#ifdef HALFOPS
    if (!wasnt_hopped && t_hop)
    {
      mode_changes[mode_count].letter = 'h';
      mode_changes[mode_count].dir = MODE_DEL;
      mode_changes[mode_count].caps = CAP_HOPS;
      mode_changes[mode_count].nocaps = 0;
      mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
      mode_changes[mode_count].id = targ_p->user->id;
      mode_changes[mode_count].arg = targ_p->name;
      mode_changes[mode_count++].client = targ_p;
    }
#endif

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
    mode_changes[mode_count].id = targ_p->user->id;
    mode_changes[mode_count].arg = targ_p->name;
    mode_changes[mode_count++].client = targ_p;
  }
  else
  {
#ifdef HALFOPS
    /* Converting -o to -h... */
    if (t_hop)
    {
      c = 'h';

      /* This code previously only allowed us to convert if it was a local
       * client, however, we may convert halfops to ops when sending to
       * old servers (assuming the target isn't on the older server),
       * so we should accept this from other servers too.
       *
       * -David-T
       */

      /* check if this just canceled out an earlier mode we cleared */
      if (!wasnt_hopped)
      {
        mode_changes[mode_count].letter = 'h';
        mode_changes[mode_count].dir = MODE_DEL;
        mode_changes[mode_count].caps = CAP_HOPS;
        mode_changes[mode_count].nocaps = 0;
        mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
        mode_changes[mode_count].id = targ_p->user->id;
        mode_changes[mode_count].arg = targ_p->name;
	mode_changes[mode_count++].client = targ_p;

#ifdef BOUNCE_BAD_HOPS
        mode_changes[mode_count].letter = 'o';
        mode_changes[mode_count].dir = MODE_DEL;
        mode_changes[mode_count].caps = 0;
        mode_changes[mode_count].nocaps = CAP_HOPS;
        mode_changes[mode_count].mems = ONLY_SERVERS;
        mode_changes[mode_count].id = targ_p->user->id;
        mode_changes[mode_count].arg = targ_p->name;
	mode_changes[mode_count++].client = targ_p;
#endif
      }
    }
    else
#endif
    {
      mode_changes[mode_count].letter = c;
      mode_changes[mode_count].dir = MODE_DEL;
      mode_changes[mode_count].caps = 0;
      mode_changes[mode_count].nocaps = 0;
      mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
      mode_changes[mode_count].id = targ_p->user->id;
      mode_changes[mode_count].arg = targ_p->name;
      mode_changes[mode_count++].client = targ_p;
    }
  }
  if(alev == CHACCESS_CHANOP + 1 && MyClient(source_p))
  {
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0], 
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  }
}

#ifdef HALFOPS
static void
chm_halfop(struct Client *client_p, struct Client *source_p,
           struct Channel *chptr, int parc, int *parn,
           char **parv, int *errors, int alev, int dir, char c, void *d,
           const char *chname)
{
  int i, wasnt_voiced = 0, t_voice, t_op, t_hop;
  char *opnick;
  struct Client *targ_p;

  /* halfops have been disabled.. disallow local users to set,
   * remote is taken care of via BOUNCE_BAD_HOPS, and we shouldnt
   * get halfops because we unset CAP_HOPS anyway..
   */
  if(!ConfigChannel.use_halfops && MyClient(source_p))
    return;

/* *sigh* - dont allow halfops to set +/-h, they could fully control a
 * channel if there were no ops - it doesnt solve anything.. MODE_PRIVATE
 * when used with MODE_SECRET is paranoid - cant use +p
 *
 * it needs to be optional per channel - but not via +p, that or remove
 * paranoid.. -- fl_
 *
 * +p means paranoid, it is useless for anything else on modern IRC, as
 * list isn't really usable. If you want to have a private channel these
 * days, you set it +s. Halfops can no longer remove simple modes when
 * +p is set(although they can set +p) so it is safe to use this to
 * control whether they can (de)halfop...
 */
  if (alev <
      ((chptr->mode.mode & MODE_PRIVATE) ?
        CHACCESS_CHANOP : CHACCESS_HALFOP))
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED), me.name,
                 source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if ((dir == MODE_QUERY) || parc <= *parn)
    return;

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  opnick = parv[(*parn)++];

  if ((targ_p = find_chasing(source_p, opnick, NULL)) == NULL)
  {
    return;
  }

  mode_get_status(chptr, targ_p, &t_op, &t_hop, &t_voice, 1);

  if (!IsMember(targ_p, chptr))
  {
    if (!(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one(source_p, form_str(ERR_USERNOTINCHANNEL), me.name,
                 source_p->name, chname, opnick);
    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (((dir == MODE_ADD) && (t_hop || t_op)) ||
      ((dir == MODE_DEL) && !t_hop))
    return;

#ifdef BOUNCE_BAD_HOPS
  if (!MyClient(targ_p) && !IsCapable(targ_p->from, CAP_HOPS))
  {
    if (IsServer(client_p))
    {
      mode_bounces[bounce_count].letter = 'h';
      mode_bounces[bounce_count].dir = MODE_DEL;
      mode_bounces[bounce_count].id = targ_p->user->id;
      mode_bounces[bounce_count++].arg = targ_p->name;
    }

    if (IsClient(source_p))
      sendto_one(source_p,
                 ":%s NOTICE %s :Unable to halfop %s"
                 " - server does not support halfops.",
                 me.name, source_p->name, targ_p->name);
    return;
  }
#endif

  /* Cancel out all other mode changes... */
  for (i = 0; i < mode_count; i++)
    if (mode_changes[i].dir == MODE_ADD &&
        (mode_changes[i].letter == 'v' ||
         mode_changes[i].letter == 'h')
        && mode_changes[i].client == targ_p)
    {
      if (mode_changes[i].letter == 'h')
      {
        mode_changes[i].letter = 0;
        return;
      }
      mode_changes[i].letter = 0;
      wasnt_voiced = 1;
    }

  if (dir == MODE_ADD)
  {
    if (!wasnt_voiced && t_voice)
    {
      mode_changes[mode_count].letter = 'v';
      mode_changes[mode_count].dir = MODE_DEL;
      mode_changes[mode_count].caps = 0;
      mode_changes[mode_count].nocaps = 0;
      mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
      mode_changes[mode_count].id = targ_p->user->id;
      mode_changes[mode_count].arg = targ_p->name;
      mode_changes[mode_count++].client = targ_p;
    }

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = CAP_HOPS;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
    mode_changes[mode_count].id = targ_p->user->id;
    mode_changes[mode_count].arg = targ_p->name;
    mode_changes[mode_count++].client = targ_p;

  #ifdef BOUNCE_BAD_HOPS
    mode_changes[mode_count].letter = 'o';
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = CAP_HOPS;
    mode_changes[mode_count].mems = ONLY_SERVERS;
    mode_changes[mode_count].id = targ_p->user->id;
    mode_changes[mode_count].arg = targ_p->name;
    mode_changes[mode_count++].client = targ_p;
  #endif
  }
  else 
  { /* MODE_DEL */
    mode_changes[mode_count].letter = 'h';
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = CAP_HOPS;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ONLY_CHANOPS_HALFOPS;
    mode_changes[mode_count].id = targ_p->user->id;
    mode_changes[mode_count].arg = targ_p->name;
    mode_changes[mode_count++].client = targ_p;

#ifdef BOUNCE_BAD_HOPS
    mode_changes[mode_count].letter = 'o';
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = CAP_HOPS;
    mode_changes[mode_count].mems = ONLY_SERVERS;
    mode_changes[mode_count].id = targ_p->user->id;
    mode_changes[mode_count].arg = targ_p->name;
    mode_changes[mode_count++].client = targ_p;
#endif
  }
  if(alev == CHACCESS_CHANOP + 1 && MyClient(source_p))
  {
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0], 
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  }
}
#endif

static void
chm_voice(struct Client *client_p, struct Client *source_p,
          struct Channel *chptr, int parc, int *parn,
          char **parv, int *errors, int alev, int dir, char c, void *d,
          const char *chname)
{
  char *opnick;
  struct Client *targ_p;
  struct Membership *member;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if ((dir == MODE_QUERY) || parc <= *parn)
    return;

  opnick = parv[(*parn)++];

  if ((targ_p = find_chasing(source_p, opnick, NULL)) == NULL)
    return;
  if (!IsClient(targ_p))
    return;

  if ((member = find_channel_link(targ_p, chptr)) == NULL)
  {
    if (!(*errors & SM_ERR_NOTONCHANNEL))
      sendto_one(source_p, form_str(ERR_USERNOTINCHANNEL),
                 me.name, source_p->name, opnick, chname);
    *errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (MyClient(source_p) && (++mode_limit > MAXMODEPARAMS))
    return;

  /* no redundant mode changes */
  if (dir == MODE_ADD &&  has_member_flags(member, CHFL_VOICE))
    return;
  if (dir == MODE_DEL && !has_member_flags(member, CHFL_VOICE))
    return;

  mode_changes[mode_count].letter = 'v';
  mode_changes[mode_count].dir = dir;
  mode_changes[mode_count].caps = 0;
  mode_changes[mode_count].nocaps = 0;
  mode_changes[mode_count].mems = ALL_MEMBERS;
  mode_changes[mode_count].id = targ_p->id;
  mode_changes[mode_count].arg = targ_p->name;
  mode_changes[mode_count++].client = targ_p;

  if (dir == MODE_ADD)
    AddMemberFlag(member, CHFL_VOICE);
  else
    DelMemberFlag(member, CHFL_VOICE);
}

static void
chm_limit(struct Client *client_p, struct Client *source_p,
          struct Channel *chptr, int parc, int *parn,
          char **parv, int *errors, int alev, int dir, char c, void *d,
          const char *chname)
{
  int i, limit;
  char *lstr;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (dir == MODE_QUERY)
    return;

  if ((dir == MODE_ADD) && parc > *parn)
  {
    lstr = parv[(*parn)++];

    if ((limit = atoi(lstr)) <= 0)
      return;

    ircsprintf(lstr, "%d", limit);

    /* if somebody sets MODE #channel +ll 1 2, accept latter --fl */
    for (i = 0; i < mode_count; i++)
    {
      if (mode_changes[i].letter == c && mode_changes[i].dir == MODE_ADD)
        mode_changes[i].letter = 0;
    }

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = lstr;

    chptr->mode.limit = limit;
  }
  else if (dir == MODE_DEL)
  {
    if (!chptr->mode.limit)
      return;

    chptr->mode.limit = 0;

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = NULL;
  }
  if(alev == CHACCESS_CHANOP + 1 && MyClient(source_p))
  {
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0],       
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  }
}

static void
chm_key(struct Client *client_p, struct Client *source_p,
        struct Channel *chptr, int parc, int *parn,
        char **parv, int *errors, int alev, int dir, char c, void *d,
        const char *chname)
{
  int i;
  char *key;

  if (alev < CHACCESS_HALFOP)
  {
    if (!(*errors & SM_ERR_NOOPS))
      sendto_one(source_p, form_str(alev == CHACCESS_NOTONCHAN ?
                                    ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chname);
    *errors |= SM_ERR_NOOPS;
    return;
  }

  if (dir == MODE_QUERY)
    return;

  if ((dir == MODE_ADD) && parc > *parn)
  {
    key = parv[(*parn)++];

    if (MyClient(source_p))
      fix_key(key);
    else
      fix_key_old(key);

    if (*key == '\0')
      return;

    assert(key[0] != ' ');
    strlcpy(chptr->mode.key, key, sizeof(chptr->mode.key));

    /* if somebody does MODE #channel +kk a b, accept latter --fl */
    for (i = 0; i < mode_count; i++)
    {
      if (mode_changes[i].letter == c && mode_changes[i].dir == MODE_ADD)
        mode_changes[i].letter = 0;
    }

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_ADD;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = chptr->mode.key;
  }
  else if (dir == MODE_DEL)
  {
    if (parc > *parn)
      (*parn)++;

    if ((*chptr->mode.key) == '\0')
      return;

    *chptr->mode.key = '\0';

    mode_changes[mode_count].letter = c;
    mode_changes[mode_count].dir = MODE_DEL;
    mode_changes[mode_count].caps = 0;
    mode_changes[mode_count].nocaps = 0;
    mode_changes[mode_count].mems = ALL_MEMBERS;
    mode_changes[mode_count].id = NULL;
    mode_changes[mode_count++].arg = "*";
  }
  if(alev == CHACCESS_CHANOP + 1 && MyClient(source_p))
  {
    char tmp[IRCD_BUFSIZE];
    ircsprintf(tmp, "%s is using God mode: MODE %s %s %s",
        source_p->name, chname, parv[0],       
        EmptyString(parv[1]) ? "" : parv[1]);
    sendto_gnotice_flags(FLAGS_SERVNOTICE, L_OPER, me.name, &me, NULL, tmp);
    oftc_log(tmp);
  }
}

struct ChannelMode
{
  void (*func) (struct Client *client_p, struct Client *source_p,
                struct Channel *chptr, int parc, int *parn, char **parv,
                int *errors, int alev, int dir, char c, void *d,
                const char *chname);
  void *d;
};

/* *INDENT-OFF* */
static struct ChannelMode ModeTable[255] =
{
  {chm_nosuch, NULL},
  {chm_nosuch, NULL},                             /* A */
  {chm_nosuch, NULL},                             /* B */
  {chm_nosuch, NULL},                             /* C */
  {chm_nosuch, NULL},                             /* D */
  {chm_nosuch, NULL},                             /* E */
  {chm_nosuch, NULL},                             /* F */
  {chm_nosuch, NULL},                             /* G */
  {chm_nosuch, NULL},                             /* H */
  {chm_invex, NULL},                              /* I */
  {chm_nosuch, NULL},                             /* J */
  {chm_nosuch, NULL},                             /* K */
  {chm_nosuch, NULL},                             /* L */
  {chm_nosuch, NULL},                             /* M */
  {chm_nosuch, NULL},                             /* N */
  {chm_nosuch, NULL},                             /* O */
  {chm_nosuch, NULL},                             /* P */
  {chm_nosuch, NULL},                             /* Q */
  {chm_nosuch, NULL},                             /* R */
  {chm_nosuch, NULL},                             /* S */
  {chm_nosuch, NULL},                             /* T */
  {chm_nosuch, NULL},                             /* U */
  {chm_nosuch, NULL},                             /* V */
  {chm_nosuch, NULL},                             /* W */
  {chm_nosuch, NULL},                             /* X */
  {chm_nosuch, NULL},                             /* Y */
  {chm_nosuch, NULL},                             /* Z */
  {chm_nosuch, NULL},
  {chm_nosuch, NULL},
  {chm_nosuch, NULL},
  {chm_nosuch, NULL},
  {chm_nosuch, NULL},
  {chm_nosuch, NULL},
  {chm_nosuch, NULL},				  /* a */
  {chm_ban, NULL},                                /* b */
  {chm_simple, (void *) MODE_NOCOLOR},            /* c */
  {chm_nosuch, NULL},                             /* d */
  {chm_except, NULL},                             /* e */
  {chm_nosuch, NULL},                             /* f */
  {chm_nosuch, NULL},                             /* g */
#ifdef USE_HALFOPS
  {chm_hop, NULL},                                /* h */
#else
  {chm_nosuch, NULL},				  /* h */
#endif
  {chm_simple, (void *) MODE_INVITEONLY},         /* i */
  {chm_nosuch, NULL},                             /* j */
  {chm_key, NULL},                                /* k */
  {chm_limit, NULL},                              /* l */
  {chm_simple, (void *) MODE_MODERATED},          /* m */
  {chm_simple, (void *) MODE_NOPRIVMSGS},         /* n */
  {chm_op, NULL},                                 /* o */
  {chm_simple, (void *) MODE_PRIVATE},            /* p */
  {chm_nosuch, NULL},                             /* q */
  {chm_nosuch, NULL},                             /* r */
  {chm_simple, (void *) MODE_SECRET},             /* s */
  {chm_simple, (void *) MODE_TOPICLIMIT},         /* t */
  {chm_nosuch, NULL},                             /* u */
  {chm_voice, NULL},                              /* v */
  {chm_nosuch, NULL},                             /* w */
  {chm_nosuch, NULL},                             /* x */
  {chm_nosuch, NULL},                             /* y */
  {chm_nosuch, NULL},                             /* z */
};
/* *INDENT-ON* */

/* int get_channel_access(struct Client *source_p, struct Channel *chptr)
 * Input: The client, the channel
 * Output: MODE_CHANOP if we should let them have chanop level access,
 *         MODE_HALFOP for halfop level access,
 *         MODE_PEON for peon level access.
 * Side-effects: None.
 */
static int
get_channel_access(struct Client *source_p, struct Channel *chptr)
{
  /* Let hacked servers in for now... */

  if (!MyClient(source_p))
    return CHACCESS_CHANOP;

  /* Services always have access */
  if(IsService(source_p))
    return CHACCESS_CHANOP;   

  if (is_chan_op(chptr, source_p))
    return CHACCESS_CHANOP;
  if(IsGod(source_p))
    return CHACCESS_CHANOP+1;

#ifdef HALFOPS
  if (is_half_op(chptr, source_p))
    return CHACCESS_HALFOP;
#endif

  return CHACCESS_PEON;
}

/* void send_cap_mode_changes(struct Client *client_p,
 *                        struct Client *source_p,
 *                        struct Channel *chptr, int cap, int nocap)
 * Input: The client sending(client_p), the source client(source_p),
 *        the channel to send mode changes for(chptr)
 * Output: None.
 * Side-effects: Sends the appropriate mode changes to capable servers.
 *
 * send_cap_mode_changes() will loop the server list itself, because
 * at this point in time we have 4 capabs for channels, CAP_IE, CAP_EX,
 * and a server could support any number of these..
 * so we make the modebufs per server, tailoring them to each servers
 * specific demand.  Its not very pretty, but its one of the few realistic
 * ways to handle having this many capabs for channel modes.. --fl_
 *
 * Reverted back to my original design, except that we now keep a count
 * of the number of servers which each combination as an optimisation, so
 * the capabs combinations which are not needed are not worked out. -A1kmm
 */
/* rewritten to ensure parabuf < MODEBUFLEN -db */

static void
send_cap_mode_changes(struct Client *client_p, struct Client *source_p,
                      struct Channel *chptr, int cap, int nocap)
{
  int i, mbl, pbl, arglen, nc, mc;
  int len;
  char *arg;
  char *parptr;
  int dir = MODE_QUERY;

  mc = 0;
  nc = 0;
  pbl = 0;

  parabuf[0] = '\0';
  parptr = parabuf;

  if ((cap & CAP_SID) && source_p->user &&
      (source_p->id[0] != '\0'))
    mbl = ircsprintf(modebuf, ":%s MODE %s ", source_p->id,
                     chptr->chname);
  else
    mbl = ircsprintf(modebuf, ":%s MODE %s ", source_p->name,
                     chptr->chname);

  /* loop the list of - modes we have */
  for (i = 0; i < mode_count; i++)
  {
    /* if they dont support the cap we need, or they do support a cap they
     * cant have, then dont add it to the modebuf.. that way they wont see
     * the mode
     */
    if ((mode_changes[i].letter == 0) ||
        ((cap & mode_changes[i].caps) != mode_changes[i].caps)
        || ((nocap & mode_changes[i].nocaps) != mode_changes[i].nocaps))
      continue;

    arg = "";

    if ((cap & CAP_SID) && mode_changes[i].id)
      arg = mode_changes[i].id;
    if (*arg == '\0')
      arg = mode_changes[i].arg;

    /* if we're creeping past the buf size, we need to send it and make
     * another line for the other modes
     * XXX - this could give away server topology with uids being
     * different lengths, but not much we can do, except possibly break
     * them as if they were the longest of the nick or uid at all times,
     * which even then won't work as we don't always know the uid -A1kmm.
     */
    if (arg != NULL)
      arglen = strlen(arg);
    else
      arglen = 0;

    if((mc == MAXMODEPARAMS) ||
       ((arglen + mbl + pbl + 2) > BUFSIZE) ||
       (pbl + arglen + BAN_FUDGE) >= MODEBUFLEN)
    {
      if (nc != 0)
        sendto_server(client_p, source_p, chptr, cap, nocap,
                      LL_ICHAN | LL_ICLIENT, "%s %s",
		      modebuf, parabuf);
      nc = 0;
      mc = 0;

      if ((cap & CAP_SID) && source_p->user &&
          (source_p->id[0] != '\0'))
        mbl = ircsprintf(modebuf, ":%s MODE %s ", source_p->id,
                         chptr->chname);
      else
        mbl = ircsprintf(modebuf, ":%s MODE %s ", source_p->name,
                         chptr->chname);

      pbl = 0;
      parabuf[0] = '\0';
      parptr = parabuf;
      dir = MODE_QUERY;
    }

    if(dir != mode_changes[i].dir)
    {
      modebuf[mbl++] = (mode_changes[i].dir == MODE_ADD) ? '+' : '-';
      dir = mode_changes[i].dir;
    }

    modebuf[mbl++] = mode_changes[i].letter;
    modebuf[mbl] = '\0';
    nc++;

    if (arg != NULL)
    {
      len = ircsprintf(parptr, "%s ", arg);
      pbl += len;
      parptr += len;
      mc++;
    }
  }

  if (pbl && parabuf[pbl - 1] == ' ')
    parabuf[pbl - 1] = 0;

  if (nc != 0)
    sendto_server(client_p, source_p, chptr, cap, nocap,
                  LL_ICLIENT, "%s %s", modebuf, parabuf);
}

/* void send_mode_changes(struct Client *client_p,
 *                        struct Client *source_p,
 *                        struct Channel *chptr)
 * Input: The client sending(client_p), the source client(source_p),
 *        the channel to send mode changes for(chptr),
 *        mode change globals.
 * Output: None.
 * Side-effects: Sends the appropriate mode changes to other clients
 *               and propagates to servers.
 */
/* ensure parabuf < MODEBUFLEN -db */
static void
send_mode_changes(struct Client *client_p, struct Client *source_p,
                  struct Channel *chptr, char *chname)
{
  int i, mbl, pbl, arglen, nc, mc;
  int len;
  char *arg;
  char *parptr;
  int dir = MODE_QUERY;

  /* bail out if we have nothing to do... */
  if (!(mode_count))
    return;

  if (IsServer(source_p))
    mbl = ircsprintf(modebuf, ":%s MODE %s ", (IsHidden(source_p) ||
		     ConfigServerHide.hide_servers) ?
		     me.name : source_p->name, chname);
  else
    mbl = ircsprintf(modebuf, ":%s!%s@%s MODE %s ", source_p->name,
                     source_p->username, source_p->host, chname);

  mc = 0;
  nc = 0;
  pbl = 0;

  parabuf[0] = '\0';
  parptr = parabuf;

  for (i = 0; i < mode_count; i++)
  {
    if (mode_changes[i].letter == 0 ||
        mode_changes[i].mems == NON_CHANOPS ||
        mode_changes[i].mems == ONLY_SERVERS)
      continue;

    arg = mode_changes[i].arg;
    if (arg != NULL)
      arglen = strlen(arg);
    else
      arglen = 0;

    if ((mc == MAXMODEPARAMS)  || 
        ((arglen + mbl + pbl + 2) > BUFSIZE) ||
	((arglen + pbl + BAN_FUDGE) >= MODEBUFLEN))
    {
      if (mbl && modebuf[mbl - 1] == '-')
        modebuf[mbl - 1] = '\0';

      if (nc != 0)
        sendto_channel_local(ALL_MEMBERS, chptr, "%s %s", modebuf, parabuf);

      nc = 0;
      mc = 0;

      if (IsServer(source_p))
        mbl = ircsprintf(modebuf, ":%s MODE %s ", me.name, chname);
      else
        mbl = ircsprintf(modebuf, ":%s!%s@%s MODE %s ", source_p->name,
                   source_p->username, source_p->host, chname);

      pbl = 0;
      parabuf[0] = '\0';
      parptr = parabuf;
      dir = MODE_QUERY;
    }

    if(dir != mode_changes[i].dir)
    {
      modebuf[mbl++] = (mode_changes[i].dir == MODE_ADD) ? '+' : '-';
      dir = mode_changes[i].dir;
    }

    modebuf[mbl++] = mode_changes[i].letter;
    modebuf[mbl] = '\0';
    nc++;

    if (arg != NULL)
    {
      len = ircsprintf(parptr, "%s ", arg);
      pbl += len;
      parptr += len;
      mc++;
    }
  }

  if (pbl && parabuf[pbl - 1] == ' ')
    parabuf[pbl - 1] = 0;

  if (nc != 0)
    sendto_channel_local(ALL_MEMBERS, chptr, "%s %s", modebuf, parabuf);

  nc = 0;
  mc = 0;

  /* Now send to servers... */
  for (i = 0; i < NCHCAP_COMBOS; i++)
    if (chcap_combos[i].count != 0)
      send_cap_mode_changes(client_p, source_p, chptr,
                            chcap_combos[i].cap_yes,
                            chcap_combos[i].cap_no);
}

/* void set_channel_mode(struct Client *client_p, struct Client *source_p,
 *               struct Channel *chptr, int parc, char **parv,
 *               char *chname)
 * Input: The client we received this from, the client this originated
 *        from, the channel, the parameter count starting at the modes,
 *        the parameters, the channel name.
 * Output: None.
 * Side-effects: Changes the channel membership and modes appropriately,
 *               sends the appropriate MODE messages to the appropriate
 *               clients.
 */
void
set_channel_mode(struct Client *client_p, struct Client *source_p, struct Channel *chptr,
                 struct Membership *member, int parc, char *parv[], char *chname)
{
  int dir = MODE_ADD;
  int parn = 1;
  int alevel, errors = 0;
  char *ml = parv[0], c;
  int table_position;

  mask_pos = 0;
  mode_count = 0;
  mode_limit = 0;
  simple_modes_mask = 0;

  alevel = get_channel_access(source_p, member);

  for (; (c = *ml) != '\0'; ml++) 
  {
#ifdef notyet
    if(mode_count > 20)
      break;
#endif
    switch (c)
    {
      case '+':
        dir = MODE_ADD;
        break;
      case '-':
        dir = MODE_DEL;
        break;
      case '=':
        dir = MODE_QUERY;
        break;
      default:
        if (c < 'A' || c > 'z')
          table_position = 0;
        else
          table_position = c - 'A' + 1;
        ModeTable[table_position].func(client_p, source_p, chptr,
                                       parc, &parn,
                                       parv, &errors, alevel, dir, c,
                                       ModeTable[table_position].d,
                                       chname);
        break;
    }
  }
  send_mode_changes(client_p, source_p, chptr, chname);
}
