#ifndef MIN_CORE_H_
#define MIN_CORE_H_ 1
#include "min_def.h"

#define CHUNK_LIST_CAP 		((u32)1024)
typedef struct {
	void 		*start;
	u32  		size;
} Chunk;

typedef struct {
	u32   		length;
	Chunk 		chunks[CHUNK_LIST_CAP];
} ChunkList;

// TODO: Implement chunk_list_find
int chunk_list_find(void *ptr);

void chunk_list_insert(ChunkList *list, void *start, u32 size);

// TODO: Implement chunk_list_remove
void chunk_list_remove(ChunkList *list, u32 index);

/**
 *	@brief Malloc memory
 *	@param size - the size of byte to allocate
 *	@return the pointer that pointed to the start of allocated bytes, if size is 0 or
 *	program reach maximum heap capacity, it will return nil.
 */
void *min_malloc(u32 size);

/**
 *	@brief Free block allocated by min_malloc
 */
void min_free(void *ptr);

ChunkList *bump_alloced_chunks();

// TODO: Implement min_free
void min_free(void *ptr);

// TODO: Implement min_collect
void min_collect();

#endif
