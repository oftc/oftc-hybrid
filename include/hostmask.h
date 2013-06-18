/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  hostmask.h: A header for the hostmask code.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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

#ifndef INCLUDE_hostmask_h
#define INCLUDE_hostmask_h 1

#define ATABLE_SIZE 0x1000


enum hostmask_type
{
  HM_HOST,
  HM_IPV4,
  HM_IPV6
};

struct AddressRec
{
  /* masktype: HM_HOST, HM_IPV4, HM_IPV6 -A1kmm */
  enum hostmask_type masktype;

  union
  {
    struct
    {
      /* Pointer into AccessItem... -A1kmm */
      struct sockaddr_storage addr;
      int bits;
    } ipa;

    /* Pointer into AccessItem... -A1kmm */
    const char *hostname;
  } Mask;

  /* type: CONF_CLIENT, CONF_DLINE, CONF_KLINE etc... -A1kmm */
  unsigned int type;

  /* Higher precedences overrule lower ones... */
  unsigned int precedence;

  /* Only checked if !(type & 1)... */
  const char *username;
  struct AccessItem *aconf;

  dlink_node node;
};

IRCD_EXTERN dlink_list atable[ATABLE_SIZE];
IRCD_EXTERN int parse_netmask(const char *, struct sockaddr_storage *, int *);
IRCD_EXTERN int match_ipv6(const struct sockaddr_storage *, 
                      const struct sockaddr_storage *, int);
IRCD_EXTERN int match_ipv4(const struct sockaddr_storage *, 
                      const struct sockaddr_storage *, int);

IRCD_EXTERN void mask_addr(struct sockaddr_storage *, int);
IRCD_EXTERN void init_host_hash();
IRCD_EXTERN void add_conf_by_address(const unsigned int, struct AccessItem *);
IRCD_EXTERN void delete_one_address_conf(const char *, struct AccessItem *);
IRCD_EXTERN void clear_out_address_conf();
IRCD_EXTERN void hostmask_expire_temporary();

IRCD_EXTERN struct AccessItem *find_address_conf(const char *, const char *,
                                            struct sockaddr_storage *, int, char *, 
                                            char *);
IRCD_EXTERN struct AccessItem *find_dline_conf(struct sockaddr_storage *, int);
IRCD_EXTERN struct AccessItem *find_conf_by_address(const char *,
                                               struct sockaddr_storage *,
                                               unsigned int, int, 
                                               const char *, const char *, 
                                               int, const char *);
#endif /* INCLUDE_hostmask_h */
