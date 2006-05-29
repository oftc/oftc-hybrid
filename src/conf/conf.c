/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  conf.c: Configuration manager.
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
 *  $Id: conf.c 69 2005-10-04 16:09:51Z adx $
 */

#include "stdinc.h"
#include "conf/conf.h"
#include "client.h"
#include "send.h"

struct Callback *reset_conf = NULL;
struct Callback *verify_conf = NULL;

static dlink_list conf_section_list = {NULL, NULL, 0};

extern int yyparse(void);

/*
 * init_conf()
 *
 * Initializes the configuration manager.
 *
 * inputs: none
 * output: none
 */
void
init_conf(void)
{
  reset_conf = register_callback("reset_conf", NULL);
  verify_conf = register_callback("verify_conf", NULL);
}

/*
 * parse_error()
 *
 * Log a parse error message.
 *
 * inputs:
 *   fmt  -  error message format
 * output: none
 */
void
parse_error(const char *fmt, ...)
{
  char *newbuf = stripws(conf_linebuf);
  char msg[CONF_BUFSIZE];
  va_list args;

  va_start(args, fmt);
  vsnprintf(msg, CONF_BUFSIZE, fmt, args);
  va_end(args);

  sendto_realops_flags(UMODE_ALL, L_ALL, "\"%s\", line %u: %s: %s",
    conf_curctx.filename, conf_curctx.lineno, msg, newbuf);
  ilog(L_WARN, "\"%s\", line %u: %s: %s",
    conf_curctx.filename, conf_curctx.lineno, msg, newbuf);
}

/*
 * yyerror()
 *
 * Log a parse error message if the current pass is 2.
 *
 * inputs:
 *   msg  -  error message
 * output: none
 */
void
_yyerror(const char *msg)
{
  if (conf_pass == 2)
    parse_error("%s", msg);
}

/*
 * conf_yy_input()
 *
 * Loads a block of data from the conf file.
 *
 * inputs:
 *   buf  -  address of destination buffer
 *   siz  -  size of the buffer
 * output: number of bytes actually read
 */
int
conf_yy_input(char *buf, int siz)
{
  return (fbgets(buf, siz, conf_curctx.f) == NULL ? 0 : strlen(buf));
}

/*
 * find_conf_section()
 *
 * Finds a conf block (section) structure.
 *
 * inputs:
 *   name  -  name of the block
 * output: pointer to struct ConfSection or NULL if not found
 */
struct ConfSection *
find_conf_section(const char *name)
{
  dlink_node *ptr;
  struct ConfSection *section;

  DLINK_FOREACH(ptr, conf_section_list.head)
  {
    section = ptr->data;
    if (!strcasecmp(section->name, name))
      return section;
  }

  return NULL;
}

/*
 * add_conf_section()
 *
 * Adds a conf block (section) structure.
 *
 * inputs:
 *   name  -  name of the block
 *   pass  -  pass when the section should be parsed (1 or 2)
 * output: pointer to struct ConfSection or NULL if already exists
 */
struct ConfSection *
add_conf_section(const char *name, int pass)
{
  struct ConfSection *section;

  if (find_conf_section(name) != NULL)
    return NULL;

  section = MyMalloc(sizeof(struct ConfSection));
  section->name = name;
  section->pass = pass;
  dlinkAdd(section, &section->node, &conf_section_list);
  return section;
}

/*
 * delete_conf_section()
 *
 * Deletes a conf block (section) structure.
 *
 * inputs:
 *   section  -  pointer to ConfSection structure
 * output: none
 */
void
delete_conf_section(struct ConfSection *section)
{
  dlink_node *ptr, *ptr_next;

  DLINK_FOREACH_SAFE(ptr, ptr_next, section->fields.head)
  {
    dlinkDelete(ptr, &section->fields);
    MyFree(ptr->data);
  }

  dlinkDelete(&section->node, &conf_section_list);
}

struct ConfField *
find_conf_field(struct ConfSection *section, char *name)
{
  dlink_node *ptr;
  struct ConfField *field;

  if (section == NULL)
    return NULL;
  if (section->pass != conf_pass)
    return NULL;

  DLINK_FOREACH(ptr, section->fields.head)
  {
    field = ptr->data;
    if (!strcasecmp(field->name, name))
      return field;
  }

  parse_error("unknown field");
  return NULL;
}

/*
 * conf_assign()
 *
 * Called when a conf item (xxx = 'yyy'; form) is parsed.
 *
 * inputs:
 *   type     -  type of supplied value
 *   field    -  pointer to struct ConfField
 *   value    -  address of value data
 * output: none
 */
void
conf_assign(int type, struct ConfField *field, void *value)
{
  static char *field_types[] =
  {"NUMBER", "BOOLEAN", "TIME", "SIZE", "STRING", "LIST"};

  if (field == NULL)
    return;
  if ((type == CT_NUMBER && (field->type == CT_TIME || field->type == CT_SIZE))
      || type == field->type)
    field->handler(value);
  else
    parse_error("type mismatch, expected %s", field_types[type]);
}

/*
 * add_conf_field()
 *
 * Adds a field of type number to the given section.
 *
 * inputs:
 *   section  -  pointer to ConfSection structure
 *   name     -  name of the field
 *   type     -  type of the field as defined in conf.h
 *   handler  -  function to be called when an assignment
 *               is encountered (one argument: info)
 * output: none
 */
void
add_conf_field(struct ConfSection *section, const char *name, int type,
               CONFF_HANDLER *handler)
{
  struct ConfField *field = MyMalloc(sizeof(struct ConfField));

  field->name = name;
  field->type = type;
  field->handler = handler;
  dlinkAdd(field, &field->node, &section->fields);
}
