#include "../include/min.h"

i32 main(void) {
	min_print("Testing min_malloc()...\n");
	int *i32arr = min_malloc(10 * sizeof(i32));
	i64 *i64arr = min_malloc(10 * sizeof(i64));
	char *str = min_malloc(16 * sizeof(char));

	ChunkList *alloced = bump_alloced_chunks();
	u32 chunks_count = alloced->length;
	min_print("Allocated chunks:\n");
	for (u32 i = 0; i < chunks_count; ++i) {
		min_printf("\tstart: %p, size: %u\n", alloced->chunks[i].start,
			 alloced->chunks[i].size);
	}
	min_print("\n");

	min_print("Testing min_realloc()...\n");
	min_realloc(i64arr, 1024 * sizeof(i64));
	alloced = bump_alloced_chunks();
	for (u32 i = 0; i < chunks_count; ++i) {
		min_printf("\tstart: %p, size: %u\n", alloced->chunks[i].start,
			 alloced->chunks[i].size);
	}
	min_print("\n");

	min_print("Testing min_free()...\n");
	min_free(i32arr);
	alloced = bump_alloced_chunks();
	chunks_count = alloced->length;
	min_print("Allocated chunks after min_free:\n");
	for (u32 i = 0; i < chunks_count; ++i) {
		min_printf("\tstart: %p, size: %u\n", alloced->chunks[i].start,
			 alloced->chunks[i].size);
	}
	min_print("\n");
	return 0;
}
