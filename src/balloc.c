/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  balloc.c: A block allocator.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
 *  Original credit lines follow:
 *
 *  File:   blalloc.c
 *  Owner:  Wohali (Joan Touzet)
 *  
 *  Modified 2001/11/29 for mmap() support by Aaron Sethman <androsyn@ratbox.org>
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
 * About the block allocator
 *
 * Basically we have three ways of getting memory off of the operating
 * system. Below are this list of methods and the order of preference.
 *
 * 1. mmap() anonymous pages with the MMAP_ANON flag.
 * 2. mmap() via the /dev/zero trick.
 * 3. malloc() 
 *
 * The advantages of 1 and 2 are this.  We can munmap() the pages which will
 * return the pages back to the operating system, thus reducing the size 
 * of the process as the memory is unused.  malloc() on many systems just keeps
 * a heap of memory to itself, which never gets given back to the OS, except on
 * exit.  This of course is bad, if say we have an event that causes us to allocate
 * say, 200MB of memory, while our normal memory consumption would be 15MB.  In the
 * malloc() case, the amount of memory allocated to our process never goes down, as
 * malloc() has it locked up in its heap.  With the mmap() method, we can munmap()
 * the block and return it back to the OS, thus causing our memory consumption to go
 * down after we no longer need it.
 * 
 * Of course it is up to the caller to make sure BlockHeapGarbageCollect() gets
 * called periodically to do this cleanup, otherwise you'll keep the memory in the
 * process.
 *
 *
 */

#include "stdinc.h"

#define WE_ARE_MEMORY_C
#include "setup.h"
#ifndef NOBALLOC

#include "ircd_defs.h"          /* DEBUG_BLOCK_ALLOCATOR */
#include "ircd.h"
#include "memory.h"
#include "balloc.h"
#include "irc_string.h"
#include "tools.h"
#include "s_log.h"
#include "client.h"
#include "fdlist.h"

#ifdef HAVE_MMAP /* We've got mmap() that is good */
#include <sys/mman.h>

/* HP-UX sucks */
#ifdef MAP_ANONYMOUS
#ifndef MAP_ANON
#define MAP_ANON MAP_ANONYMOUS
#endif
#endif



static int newblock(BlockHeap * bh);


/*
 * static inline void free_block(void *ptr, size_t size)
 *
 * Inputs: The block and its size
 * Output: None
 * Side Effects: Returns memory for the block back to the OS
 */
static inline void free_block(void *ptr, size_t size)
{
  munmap(ptr, size);
}

#ifndef MAP_ANON /* But we cannot mmap() anonymous pages */
		 /* So we mmap() /dev/zero, which is just as good */
static int zero_fd = -1;

/*
 * void initBlockHeap(void)
 * Note: This is the /dev/zero version of getting pages 
 * 
 * Inputs: None
 * Outputs: None
 * Side Effects: Opens /dev/zero and saves the file handle for
 *		 future allocations.
 */
 
void
initBlockHeap(void)
{
  zero_fd = open("/dev/zero", O_RDWR);

  if (zero_fd < 0)
    outofmemory();
  fd_open(zero_fd, FD_FILE, "Anonymous mmap()");
}

/*
 * static inline void *get_block(size_t size)
 * 
 * Note: This is the /dev/zero version
 * Input: Size of block to allocate
 * Output: Pointer to new block
 * Side Effects: None
 */
static inline void *
get_block(size_t size)
{
  void *ptr;
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, zero_fd, 0);
  if(ptr == MAP_FAILED)
    {
      ptr = NULL;
    }
  return(ptr);
}
#else /* MAP_ANON */ 

/* 
 * void initBlockHeap(void)
 *
 * Note: This is the anonymous pages version: This is a placeholder
 * Input: None
 * Output: None
 */ 
void
initBlockHeap(void)
{
  return;
}

/*
 * static inline void *get_block(size_t size)
 * 
 * Note: This is the /dev/zero version
 * Input: Size of block to allocate
 * Output: Pointer to new block
 * Side Effects: None
 */

static inline void *
get_block(size_t size)
{
  void *ptr;
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
  if(ptr == MAP_FAILED)
    {
      ptr = NULL;
    }
  return(ptr);
}

#endif /* MAP_ANON */

#else  /* HAVE_MMAP */
/* Poor bastards don't even have mmap() */

/* 
 * static inline void *get_block(size_t size)
 *
 * Note: This is the non-mmap() version
 * Input: Size of block
 * Output: Pointer to the memory
 */
static inline void *
get_block(size_t size)
{
  return(malloc(size));
}

/*
 * static inline void free_block(void *ptr, size_t size)
 *
 * Inputs: The block and its size
 * Output: None
 * Side Effects: Returns memory for the block back to the malloc heap
 */

static inline void 
free_block(void *ptr, size_t unused)
{
  free(ptr);
}

/* 
 * void initBlockHeap(void)
 *
 * Note: This is the malloc() version: This is a placeholder
 * Input: None
 * Output: None
 */ 

void
initBlockHeap()
{
  return;

}
#endif /* HAVE_MMAP */



/* ************************************************************************ */
/* FUNCTION DOCUMENTATION:                                                  */
/*    newblock                                                              */
/* Description:                                                             */
/*    Allocates a new block for addition to a blockheap                     */
/* Parameters:                                                              */
/*    bh (IN): Pointer to parent blockheap.                                 */
/* Returns:                                                                 */
/*    0 if successful, 1 if not                                             */
/* ************************************************************************ */

static int
newblock(BlockHeap * bh)
{
    MemBlock *newblk;
    Block *b;
    int i;
    void *offset;

    /* Setup the initial data structure. */
    b = (Block *) calloc(1, sizeof(Block));
    if (b == NULL)
      {
        return(1);
      }
    b->freeElems = bh->elemsPerBlock;
    b->free_list.head = b->free_list.tail = NULL;
    b->used_list.head = b->used_list.tail = NULL;
    b->next = bh->base;

    b->alloc_size = (bh->elemsPerBlock + 1) * (bh->elemSize + sizeof(MemBlock));

    b->elems = get_block(b->alloc_size);
    if (b->elems == NULL)
      {
        return(1);
      }
    offset = b->elems;
    /* Setup our blocks now */
    for (i = 0; i < bh->elemsPerBlock; i++)
      {
        void *data;
        newblk = (void *)offset;
        newblk->block = b;
        data = (void *)((size_t)offset + sizeof(MemBlock));
        newblk->block = b;
        dlinkAdd(data, &newblk->self, &b->free_list);
        offset = (unsigned char *)((unsigned char *)offset + bh->elemSize + sizeof(MemBlock));
      }

    ++bh->blocksAllocated;
    bh->freeElems += bh->elemsPerBlock;
    bh->base = b;

    return(0);
}


/* ************************************************************************ */
/* FUNCTION DOCUMENTATION:                                                  */
/*    BlockHeapCreate                                                       */
/* Description:                                                             */
/*   Creates a new blockheap from which smaller blocks can be allocated.    */
/*   Intended to be used instead of multiple calls to malloc() when         */
/*   performance is an issue.                                               */
/* Parameters:                                                              */
/*   elemsize (IN):  Size of the basic element to be stored                 */
/*   elemsperblock (IN):  Number of elements to be stored in a single block */
/*         of memory.  When the blockheap runs out of free memory, it will  */
/*         allocate elemsize * elemsperblock more.                          */
/* Returns:                                                                 */
/*   Pointer to new BlockHeap, or NULL if unsuccessful                      */
/* ************************************************************************ */
BlockHeap *
BlockHeapCreate(size_t elemsize, int elemsperblock)
{
    BlockHeap *bh;
    assert(elemsize > 0 && elemsperblock > 0);

    /* Catch idiotic requests up front */
    if ((elemsize <= 0) || (elemsperblock <= 0))
      {
        outofmemory();          /* die.. out of memory */
      }

    /* Allocate our new BlockHeap */
    bh = (BlockHeap *) calloc(1, sizeof(BlockHeap));
    if (bh == NULL)
      {
        outofmemory();          /* die.. out of memory */
      }

    if((elemsize % sizeof(void *)) != 0)
      {
	/* Pad to even pointer boundary */
	elemsize += sizeof(void *);
	elemsize &= ~(sizeof(void *) - 1);
      }

    bh->elemSize = elemsize;
    bh->elemsPerBlock = elemsperblock;
    bh->blocksAllocated = 0;
    bh->freeElems = 0;
    bh->base = NULL;

    /* Be sure our malloc was successful */
    if (newblock(bh))
      {
        if(bh != NULL)
          free(bh);
        outofmemory();          /* die.. out of memory */
      }

    if (bh == NULL)
      {
        outofmemory();          /* die.. out of memory */
      }

    return(bh);
}

/* ************************************************************************ */
/* FUNCTION DOCUMENTATION:                                                  */
/*    BlockHeapAlloc                                                        */
/* Description:                                                             */
/*    Returns a pointer to a struct within our BlockHeap that's free for    */
/*    the taking.                                                           */
/* Parameters:                                                              */
/*    bh (IN):  Pointer to the Blockheap.                                   */
/* Returns:                                                                 */
/*    Pointer to a structure (void *), or NULL if unsuccessful.             */
/* ************************************************************************ */

void *
BlockHeapAlloc(BlockHeap * bh)
{
    Block *walker;
    dlink_node *new_node;

    assert(bh != NULL);
    if (bh == NULL)
      {
	outofmemory();
      }

    if (bh->freeElems == 0)
      {   
        /* Allocate new block and assign */
        /* newblock returns 1 if unsuccessful, 0 if not */

        if (newblock(bh))
	  {
            /* That didn't work..try to garbage collect */
            BlockHeapGarbageCollect(bh);  
            if(bh->freeElems == 0)
              {
                 outofmemory(); /* Well that didn't work either...bail */
              }
	  }
       }
      
    for (walker = bh->base; walker != NULL; walker = walker->next)
      {
        if (walker->freeElems > 0)
	  {
            bh->freeElems--;
            walker->freeElems--;
            new_node = walker->free_list.head;
            dlinkDelete(new_node, &walker->free_list);
            dlinkAdd(new_node->data, new_node, &walker->used_list);
            assert(new_node->data != NULL);
            if(new_node->data == NULL)
              outofmemory();
            return (new_node->data);
	  }
      }
    assert(0 == 1);
    outofmemory();
}


/* ************************************************************************ */
/* FUNCTION DOCUMENTATION:                                                  */
/*    BlockHeapFree                                                         */
/* Description:                                                             */
/*    Returns an element to the free pool, does not free()                  */
/* Parameters:                                                              */
/*    bh (IN): Pointer to BlockHeap containing element                      */
/*    ptr (in):  Pointer to element to be "freed"                           */
/* Returns:                                                                 */
/*    0 if successful, 1 if element not contained within BlockHeap.         */
/* ************************************************************************ */
int
BlockHeapFree(BlockHeap * bh, void *ptr)
{
    Block *block;
    struct MemBlock *memblock;
    
    assert(bh != NULL);
    assert(ptr != NULL);

    if (bh == NULL)
      {

        ilog(L_NOTICE, "balloc.c:BlockHeapFree() bh == NULL");
        return(1);
      }

    if (ptr == NULL)
      {
        ilog(L_NOTICE, "balloc.BlockHeapFree() ptr == NULL");
        return(1);
      }

    memblock = (void *)((size_t)ptr - sizeof(MemBlock));
    assert(memblock->block != NULL);
    if(memblock->block == NULL)
    {
      outofmemory();
    }
    /* Is this block really on the used list? */
    assert(dlinkFind(&memblock->block->used_list, memblock) == NULL); 

    block = memblock->block;
    bh->freeElems++;
    block->freeElems++;
    mem_frob(ptr, bh->elemSize);
    dlinkDelete(&memblock->self, &block->used_list);
    dlinkAdd(ptr, &memblock->self, &block->free_list);
    return(0);
}

/* ************************************************************************ */
/* FUNCTION DOCUMENTATION:                                                  */
/*    BlockHeapGarbageCollect                                               */
/* Description:                                                             */
/*    Performs garbage collection on the block heap.  Any blocks that are   */
/*    completely unallocated are removed from the heap.  Garbage collection */
/*    will never remove the root node of the heap.                          */
/* Parameters:                                                              */
/*    bh (IN):  Pointer to the BlockHeap to be cleaned up                   */
/* Returns:                                                                 */
/*   0 if successful, 1 if bh == NULL                                       */
/* ************************************************************************ */
int
BlockHeapGarbageCollect(BlockHeap * bh)
{
    Block *walker, *last;

    if (bh == NULL)
      {
        return(1);
      }

    if (bh->freeElems < bh->elemsPerBlock || bh->blocksAllocated == 1)
      {
        /* There couldn't possibly be an entire free block.  Return. */
        return(0);
      }

    last = NULL;
    walker = bh->base;

    while (walker != NULL)
      {
        if ((walker->freeElems == bh->elemsPerBlock) != 0)
	  {
            free_block(walker->elems, walker->alloc_size);
            if (last != NULL)
	      {
                last->next = walker->next;
                if(walker != NULL)
                 free(walker);
                walker = last->next;
	      }
	    else
	      {
                bh->base = walker->next;
                if(walker != NULL)
                 free(walker);
                walker = bh->base;
	      }
            bh->blocksAllocated--;
            bh->freeElems -= bh->elemsPerBlock;
	  }
	else
	  {
            last = walker;
            walker = walker->next;
	  }
      }
    return(0);
}

/* ************************************************************************ */
/* FUNCTION DOCUMENTATION:                                                  */
/*    BlockHeapDestroy                                                      */
/* Description:                                                             */
/*    Completely free()s a BlockHeap.  Use for cleanup.                     */
/* Parameters:                                                              */
/*    bh (IN):  Pointer to the BlockHeap to be destroyed.                   */
/* Returns:                                                                 */
/*   0 if successful, 1 if bh == NULL                                       */
/* ************************************************************************ */
int
BlockHeapDestroy(BlockHeap * bh)
{
    Block *walker, *next;

    if (bh == NULL)
      {
        return(1);
      }

    for (walker = bh->base; walker != NULL; walker = next)
      {
        next = walker->next;
        free_block(walker->elems, walker->alloc_size);
        if(walker != NULL)
          free(walker);
      }

    if(walker != NULL)
      {
	free(bh);
      }
    return(0);
}
#endif
