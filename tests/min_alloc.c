#include <stdio.h>
#include "../include/min.h"

// TEST: min_alloc
int main() {
	printf("Testing min_alloc...\n");
	for (u32 i = 1; i <= 100; ++i) {
		int *p = min_malloc(i);
	}
	Chunk_List *alloced = bump_alloced_chunks();
	u32 chunks_count = alloced->count;
	printf("Allocated chunks (%zu):\n", (size_t)(chunks_count));
	for (u32 i = 0; i < chunks_count; ++i) {
		printf("\tstart: %p, size: %zu\n",
				alloced->chunks[i].start,
				(size_t)alloced->chunks[i].size);
	}
	printf("\n");
	return 0;
}
