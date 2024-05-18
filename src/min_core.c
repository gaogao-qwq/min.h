#include "../include/min_core.h"
#include "../include/min_syscall.h"
#include "../include/algo.h"

static ChunkList alloced_chunks = {0};

static int compar(const void *a, const void *b) {
	return (Chunk *)a - (Chunk *)b;
}

// INFO: O(logN)
int chunk_list_find(void *ptr) {
	u32 l = 0, r = alloced_chunks.length;
	while (l < r) {
		u32 idx = (l + r) / 2;
		if (ptr < alloced_chunks.chunks[idx].start)
			r = idx;
		else if (ptr > alloced_chunks.chunks[idx].start)
			l = idx + 1;
		else
			return idx;
	}
	return -1;
}

// INFO: O(N)
void chunk_list_insert(ChunkList *list, void *start, u32 size) {
	if (list->length >= CHUNK_LIST_CAP) return;
	list->chunks[list->length] = (Chunk){.start = start, .size = size};
	for (u32 i = list->length;
			i > 0 && list->chunks[i].start < list->chunks[i-1].start;
			--i) {
		min_swap(&list->chunks[i], &list->chunks[i-1], sizeof list->chunks[i]);
	}
	++list->length;
}

void chunk_list_remove(ChunkList *list, u32 index) {
	u32 length = list->length;
	for (u32 i = index + 1; i < length; ++i) {
		list->chunks[i-1] = list->chunks[i];
	}
	sys_munmap(&list->chunks[length - 1], list->chunks[length - 1].size);
	list->chunks[length - 1] = (Chunk){.start = nil, .size = 0};
	--list->length;
}

void *min_malloc(u32 size) {
	if (!size || alloced_chunks.length >= CHUNK_LIST_CAP) return nil;
	void *ptr = sys_mmap(nil, size, PROT_READ | PROT_WRITE,
					     MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	if (*(i32 *)ptr == -1) return nil;
	chunk_list_insert(&alloced_chunks, ptr, size);
	return ptr;
}

ChunkList *bump_alloced_chunks() {
	return &alloced_chunks;
}

void min_free(void *ptr) {
	i32 index = chunk_list_find(ptr);
	if (index < 0) return;
	chunk_list_remove(&alloced_chunks, index);
}

void min_collect() {}

