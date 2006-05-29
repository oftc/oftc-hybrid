/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  manager.h: A header for the configuration manager.
 *
 *  Copyright (C) 2003 by Piotr Nizynski, Advanced IRC Services Project
 *  Copyright (C) 2005 by the Hybrid Development Team.
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
 *  $Id: conf.h 69 2005-10-04 16:09:51Z adx $
 */

#define CONF_BUFSIZE 512

#define CT_NUMBER 0
#define CT_BOOL   1
#define CT_TIME   2
#define CT_SIZE   3
#define CT_STRING 4
#define CT_LIST   5

typedef void CONFS_HANDLER(void);
typedef void CONFF_HANDLER(void *);

struct ConfParserContext {
  FBFILE *f;
  char *filename;
  int lineno;
};

struct ConfSection {
  const char *name;
  CONFS_HANDLER *before;
  CONFS_HANDLER *after;
  int pass;
  dlink_list fields;
  dlink_node node;
};

struct ConfField {
  const char *name;
  int type;
  CONFF_HANDLER *handler;
  dlink_node node;
};

extern int conf_pass;
extern struct ConfParserContext conf_curctx;
extern char conf_linebuf[];
extern int conf_include_sptr;

extern struct Callback *reset_conf;
extern struct Callback *verify_conf;

extern void init_conf(void);
extern void parse_error(const char *, ...);
extern void yyerror(const char *);
extern int conf_yy_input(char *, int);
extern int yylex(void);
extern void conf_clear_ident_list(void);
extern struct ConfSection *find_conf_section(const char *);
extern struct ConfSection *add_conf_section(const char *, int);
extern void delete_conf_section(struct ConfSection *);
extern struct ConfField *find_conf_field(struct ConfSection *, char *);
extern void conf_assign(int, struct ConfField *, void *);
extern void add_conf_field(struct ConfSection *, const char *, int,
                           CONFF_HANDLER *);
