#include "../include/min_core.h"
#include <string.h>

static char heap[HEAP_CAP] = {0};
static u32 heap_size = 0;

static Chunk_List alloced_chunks = {0};
static Chunk_List freed_chunks = {0};

// INFO: O(logN)
int chunk_list_find(void *ptr) {
	return -1;
}

// INFO: O(N)
void chunk_list_insert(Chunk_List *list, void *start, u32 size) {
	if (list->count >= CHUNK_LIST_CAP) return;
	list->chunks[list->count].start	= start;
	list->chunks[list->count].size	= size;
	for (u32 i = list->count;
			i > 0 && list->chunks[i].start < list->chunks[i-1].start;
			--i) {
		const Chunk t = list->chunks[i];
		list->chunks[i]		= list->chunks[i-1];
		list->chunks[i-1]	= list->chunks[i];
	}
	++list->count;
}

void chunk_list_remove(Chunk_List *list, u32 index) {}

void *min_malloc(u32 size) {
	if (!size) return nil;
	if (heap_size + size > HEAP_CAP) return nil;

	void *ptr = heap + heap_size;
	heap_size += size;
	chunk_list_insert(&alloced_chunks, ptr, size);
	return ptr;
}

Chunk_List *bump_alloced_chunks() {
	return &alloced_chunks;
}

void min_free(void *ptr) {
	i32 index = chunk_list_find(ptr);
	if (index < 0) return;
	chunk_list_insert(&freed_chunks,
					  alloced_chunks.chunks[index].start,
					  alloced_chunks.chunks[index].size);
	chunk_list_remove(&alloced_chunks, (u32)index);
}

void min_collect() {}

