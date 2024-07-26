#include "../include/min.h"
// clang-format off

i32 main(void) {
	Vec vec = makeEmptyVec(sizeof(i32));
	ChunkList *chunks = bump_alloced_chunks();
	min_printf("chunks length: %u\n", chunks->length);
	for (size_t i = 0; i < chunks->length; ++i) {
		min_printf("start: %p\nsize: %u\n",
		           chunks->chunks[i].start,
		           chunks->chunks[i].size);
	}
	for (size_t i = 0; i < 10000; ++i) {
		vecAppend(&vec, &i);
	}
	chunks = bump_alloced_chunks();
	min_printf("chunks length: %u\n", chunks->length);
	for (size_t i = 0; i < chunks->length; ++i) {
		min_printf("start: %p\nsize: %u\n",
		           chunks->chunks[i].start,
		           chunks->chunks[i].size);
	}
	min_assert(*(int *)vecGet(vec, 9999) == 9999);
	i32 t = 114514;
	vecSet(vec, 9999, &t);
	min_assert(*(int *)vecGet(vec, 9999) == t);
}
