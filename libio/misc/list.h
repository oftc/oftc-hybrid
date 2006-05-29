/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  list.h: A header for the code in list.c.
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

/*
 * double-linked-list and single-linked-list stuff
 */
typedef struct _dlink_node dlink_node;
typedef struct _dlink_list dlink_list;

#ifdef IN_MISC_C
extern void init_dlink_nodes(void);
#endif
LIBIO_EXTERN void free_dlink_node(dlink_node *);
LIBIO_EXTERN dlink_node *make_dlink_node(void);

struct _dlink_node
{
  void *data;
  dlink_node *prev;
  dlink_node *next;
};
  
struct _dlink_list
{
  dlink_node *head;
  dlink_node *tail;
  unsigned long length;
};

LIBIO_EXTERN void dlinkAdd(void *data, dlink_node * m, dlink_list * list);
LIBIO_EXTERN void dlinkAddBefore(dlink_node *b, void *data, dlink_node *m, dlink_list *list);
LIBIO_EXTERN void dlinkAddTail(void *data, dlink_node *m, dlink_list *list);
LIBIO_EXTERN void dlinkDelete(dlink_node *m, dlink_list *list);
LIBIO_EXTERN void dlinkMoveList(dlink_list *from, dlink_list *to);
LIBIO_EXTERN dlink_node *dlinkFind(dlink_list *m, void *data);
LIBIO_EXTERN dlink_node *dlinkFindDelete(dlink_list *m, void *data);

/* These macros are basically swiped from the linux kernel
 * they are simple yet effective
 */

/*
 * Walks forward of a list.  
 * pos is your node
 * head is your list head
 */
#define DLINK_FOREACH(pos, head) for (pos = (head); pos != NULL; pos = pos->next)
   		
/*
 * Walks forward of a list safely while removing nodes 
 * pos is your node
 * n is another list head for temporary storage
 * head is your list head
 */
#define DLINK_FOREACH_SAFE(pos, n, head) for (pos = (head), n = pos ? pos->next : NULL; pos != NULL; pos = n, n = pos ? pos->next : NULL)
#define DLINK_FOREACH_PREV(pos, head) for (pos = (head); pos != NULL; pos = pos->prev)
              		       
/* Returns the list length */
#define dlink_list_length(list) (list)->length

/*
 * The functions below are included for the sake of inlining
 * hopefully this will speed up things just a bit
 * 
 */
/* forte (and maybe others) dont like these being declared twice,
 * so we dont declare the inlines unless GNUC.
 */
#ifdef __GNUC__

/* 
 * dlink_ routines are stolen from squid, except for dlinkAddBefore,
 * which is mine.
 *   -- adrian
 */
LIBIO_EXTERN inline void
dlinkAdd(void *data, dlink_node * m, dlink_list * list)
{
  m->data = data;
  m->prev = NULL;
  m->next = list->head;
  /* Assumption: If list->tail != NULL, list->head != NULL */
  if (list->head != NULL)
    list->head->prev = m;
  else if (list->tail == NULL)
    list->tail = m;
  list->head = m;
  list->length++;
}

LIBIO_EXTERN inline void
dlinkAddBefore(dlink_node *b, void *data, dlink_node *m, dlink_list *list)
{
  /* Shortcut - if its the first one, call dlinkAdd only */
  if (b == list->head)
    dlinkAdd(data, m, list);
  else {
    m->data = data;
    b->prev->next = m;
    m->prev = b->prev;
    b->prev = m; 
    m->next = b;
    list->length++;
  }
}

LIBIO_EXTERN inline void
dlinkAddTail(void *data, dlink_node *m, dlink_list *list)
{
 m->data = data;
 m->next = NULL;
 m->prev = list->tail;
 /* Assumption: If list->tail != NULL, list->head != NULL */
 if (list->tail != NULL)
   list->tail->next = m;
 else if (list->head == NULL)
   list->head = m;
 list->tail = m;
 list->length++;
}

/* Execution profiles show that this function is called the most
 * often of all non-spontaneous functions. So it had better be
 * efficient. */
LIBIO_EXTERN inline void
dlinkDelete(dlink_node *m, dlink_list *list)
{
 /* Assumption: If m->next == NULL, then list->tail == m
  *      and:   If m->prev == NULL, then list->head == m
  */
 if (m->next)
   m->next->prev = m->prev;
 else {
   assert(list->tail == m);
   list->tail = m->prev;
 }
 if (m->prev)
   m->prev->next = m->next;
 else {
   assert(list->head == m);
   list->head = m->next;
 }
 /* Set this to NULL does matter */
 m->next = m->prev = NULL;
  list->length--;
}

/*
 * dlinkFind
 * inputs	- list to search 
 *		- data
 * output	- pointer to link or NULL if not found
 * side effects	- Look for ptr in the linked listed pointed to by link.
 */
LIBIO_EXTERN inline dlink_node *
dlinkFind(dlink_list *list, void *data)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, list->head)
    if (ptr->data == data)
      return ptr;

  return NULL;
}

LIBIO_EXTERN inline void
dlinkMoveList(dlink_list *from, dlink_list *to)
{
  /* There are three cases */
  /* case one, nothing in from list */

  if (from->head == NULL)
    return;

  /* case two, nothing in to list */
  /* actually if to->head is NULL and to->tail isn't, thats a bug */

  if (to->head == NULL)
  {
    to->head = from->head;
    to->tail = from->tail;
    from->head = from->tail = NULL;
    to->length = from->length;
    from->length = 0;
    return;
  }

  /* third case play with the links */

  from->tail->next = to->head;
  from->head->prev = to->head->prev;
  to->head->prev = from->tail;
  to->head = from->head;
  from->head = from->tail = NULL;
  to->length += from->length;
  from->length = 0;

  /* I think I got that right */
}

LIBIO_EXTERN inline dlink_node *
dlinkFindDelete(dlink_list *list, void *data)
{
  dlink_node *m;

  DLINK_FOREACH(m, list->head)
  {
    if (m->data == data)
    {
      if (m->next)
        m->next->prev = m->prev;
      else
      {
        assert(list->tail == m);
        list->tail = m->prev;
      }
      if (m->prev)
        m->prev->next = m->next;
      else
      {
        assert(list->head == m);
        list->head = m->next;
      }
      /* Set this to NULL does matter */
      m->next = m->prev = NULL;
      list->length--;

      return m;
    }
  }

  return NULL;
}

#endif /* __GNUC__ */
