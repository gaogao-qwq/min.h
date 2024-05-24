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

/**
 * @brief Binary search allocated chunk by pointer
 * @param ptr - the pointer to find
 * @return the index of the chunk in chunk list, if the pointer is NULL or is not
 * allocated by min_malloc, it will return -1;
 */
i32 chunk_list_find(void *ptr);

/**
 * @brief Insert a new chunk into chunk list
 * @param list  - the list where the chunk will be inserted to
 * @param start - the pointer pointed to the insert chunk
 * @param size  - the size of the insert chunk
 */
void chunk_list_insert(ChunkList *list, void *start, size_t size);

/**
 * @brief Remove a chunk from chunk list by index
 * @param list  - the list where the chunk will be removed from
 * @param index - the index of the chunk to remove
 * @return 0 when successfully remove chunk, -1 when failed to remove
 */
ssize_t chunk_list_remove(ChunkList *list, u32 index);

/**
 * @brief Malloc memory
 * @param size - the size of byte to allocate
 * @return the pointer that pointed to the start of allocated bytes, if size is 0 or
 *         program reach maximum heap capacity, it will return nil.
 */
void *min_malloc(size_t size);

/**
 * @brief Get allocated chunk list
 * @return the allocated chunk list
 */
ChunkList *bump_alloced_chunks();

/**
 * @brief Free the chunk allocated by min_malloc
 * @param ptr - the pointer pointed to the chunk to be freed
 */
void min_free(void *ptr);

// TODO: Implement min_collect
void min_collect();

#endif // MIN_CORE_H_
