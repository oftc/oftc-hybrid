/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  balloc.h: The ircd block allocator header.
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

#ifndef INCLUDED_blalloc_h
#define INCLUDED_blalloc_h

#include "setup.h"

#ifndef NOBALLOC

#include "tools.h"
#include "memory.h"
#include "ircd_defs.h"


/* 
 * Block contains status information for an allocated block in our
 * heap.
 */


struct Block {
	int		freeElems;		/* Number of available elems */
	size_t		alloc_size;
	struct Block*	next;			/* Next in our chain of blocks */
	void*		elems;			/* Points to allocated memory */
	dlink_list	free_list;
	dlink_list	used_list;					
};

typedef struct Block Block;

struct MemBlock {
	dlink_node self;		
	Block *block;				/* Which block we belong to */
};
typedef struct MemBlock MemBlock;

/* 
 * BlockHeap contains the information for the root node of the
 * memory heap.
 */
struct BlockHeap {
   size_t  elemSize;                    /* Size of each element to be stored */
   int     elemsPerBlock;               /* Number of elements per block */
   int     blocksAllocated;             /* Number of blocks allocated */
   int     freeElems;                   /* Number of free elements */
   Block*  base;                        /* Pointer to first block */
};

typedef struct BlockHeap BlockHeap;


extern int         BlockHeapFree(BlockHeap *bh, void *ptr);
extern void *     BlockHeapAlloc(BlockHeap *bh);

extern BlockHeap* BlockHeapCreate(size_t elemsize, int elemsperblock);
extern int        BlockHeapDestroy(BlockHeap *bh);


extern int        BlockHeapGarbageCollect(BlockHeap *);
extern void	  initBlockHeap(void);
#else /* NOBALLOC */

typedef struct BlockHeap BlockHeap;
#define initBlockHeap()
#define BlockHeapGarbageCollect(x)
/* This is really kludgy, passing ints as pointers is always bad. */
#define BlockHeapCreate(es, epb) ((BlockHeap*)(es))
#define BlockHeapDestroy(x)
#define BlockHeapAlloc(x) MyMalloc((int)x)
#define BlockHeapFree(x,y) MyFree(y)


#endif /* NOBALLOC */

#endif /* INCLUDED_blalloc_h */
