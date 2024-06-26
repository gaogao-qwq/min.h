#include "../include/min/min_core.h"

#include "../include/min/min_algo.h"
#include "../include/min/min_assert.h"
#include "../include/min/min_syscall.h"
// clang-format off

static ChunkList alloced_chunks = {0};

// INFO: O(logN)
i32 chunk_list_find(void *ptr) {
	u32 l = 0, r = alloced_chunks.length;
	while (l < r) {
		size_t idx = (l + r) / 2;
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
void chunk_list_insert(ChunkList *list, void *start, size_t size) {
	if (list->length >= CHUNK_LIST_CAP) return;
	list->chunks[list->length] = (Chunk){.start = start, .size = size};
	for (size_t i = list->length;
			i > 0 && list->chunks[i].start < list->chunks[i-1].start;
			--i) {
		min_swap(&list->chunks[i], &list->chunks[i-1], sizeof list->chunks[i]);
	}
	++list->length;
}

ssize_t chunk_list_remove(ChunkList *list, u32 index) {
	ssize_t res = sys_munmap(list->chunks[index].start, list->chunks[index].size);
	if (res != 0) return res;
	size_t length = list->length;
	for (size_t i = index + 1; i < length; ++i) {
		list->chunks[i - 1] = list->chunks[i];
	}
	list->chunks[length - 1] = (Chunk){.start = nil, .size = 0};
	--list->length;
	return res;
}

void *min_malloc(size_t size) {
	if (!size || alloced_chunks.length >= CHUNK_LIST_CAP) return nil;
	void *ptr = sys_mmap(nil, size, PROT_READ | PROT_WRITE,
                         MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	if (ptr == ((void *) -1)) return nil;
	chunk_list_insert(&alloced_chunks, ptr, size);
	return ptr;
}

void *min_calloc(size_t nmemb, size_t size) {
	size *= nmemb;
	if (!size || alloced_chunks.length >= CHUNK_LIST_CAP) return nil;
	void * ptr = sys_mmap(nil, size, PROT_READ | PROT_WRITE,
	                      MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	if (ptr == ((void *) -1)) return nil;
	for (size_t i = 0; i < size; ++i) {
		(*(char *)ptr) ^= (*(char *)ptr);
	}
	chunk_list_insert(&alloced_chunks, ptr, size);
	return ptr;
}

void *min_realloc(void *ptr, size_t size) {
	i32 idx = chunk_list_find(ptr);
	if (idx == -1) return nil;
	void *new_address = sys_mremap(ptr, alloced_chunks.chunks[idx].size,
                                   size, MREMAP_MAYMOVE, nil);
	if (new_address != ptr) {
		chunk_list_remove(&alloced_chunks, idx);
		chunk_list_insert(&alloced_chunks, new_address, size);
		ptr = new_address;
	}
	return new_address;
}

ChunkList *bump_alloced_chunks() {
	return &alloced_chunks;
}

void min_free(void *ptr) {
	if (ptr == nil) return;
	i32 index = chunk_list_find(ptr);
	min_assert(index >= 0);
	ssize_t res = chunk_list_remove(&alloced_chunks, index);
	min_assert(res == 0);
}

void min_collect() {}

