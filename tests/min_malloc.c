#include "../include/min.h"

i32 main(void) {
	min_printf("Testing min_malloc()...\n");
	int *i32arr = min_malloc(10 * sizeof(i32));
	i64 *i64arr = min_malloc(10 * sizeof(i64));
	char *str = min_malloc(16 * sizeof(char));

	ChunkList *alloced = bump_alloced_chunks();
	u32 chunks_count = alloced->length;
	min_printf("Allocated chunks:\n");
	for (u32 i = 0; i < chunks_count; ++i) {
		min_printf("\tstart: %p, size: %u\n", alloced->chunks[i].start,
			 alloced->chunks[i].size);
	}
	min_printf("\n");

	min_printf("Testing min_free()...\n");
	min_free(i32arr);
	alloced = bump_alloced_chunks();
	chunks_count = alloced->length;
	min_printf("Allocated chunks after min_free:\n");
	for (u32 i = 0; i < chunks_count; ++i) {
		min_printf("\tstart: %p, size: %u\n", alloced->chunks[i].start,
			 alloced->chunks[i].size);
	}
	min_printf("\n");
	return 0;
}
