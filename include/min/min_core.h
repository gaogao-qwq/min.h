#ifndef MIN_CORE_H_
#define MIN_CORE_H_ 1
#include "min_def.h"

/**
 * @brief Allocate size bytes of memory.
 *
 * @param size - the size of byte to allocate
 * @return the pointer that pointed to the start of allocated bytes, if size is
 * 0 or program reach maximum heap capacity, it will return NULL.
 */
void *min_malloc(size_t size);

/**
 * @brief Allocate nmemb elements of size bytes each, all initialized to 0.
 *
 * @param nmemb - number of elements
 * @param size  - size of bytes
 */
void *min_calloc(size_t nmemb, size_t size);

/**
 * @brief Re-allocate the previously allocated block in ptr,
 *        making the new block size bytes long.
 *
 * @param ptr  - the pointer pointed to the allocated block
 * @param size - size of bytes
 */
void *min_realloc(void *ptr, size_t size);

/**
 * @brief Print allocated chunk list
 */
void bump_alloced_bucket();

/**
 * @brief Free the chunk allocated by min_malloc
 *
 * @param ptr - the pointer pointed to the chunk to be freed
 */
void min_free(void *ptr);

// TODO: Implement min_collect
void min_collect();

#endif	// MIN_CORE_H_
