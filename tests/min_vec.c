#include "../include/min.h"
// clang-format off

i32 main(void) {
	Vec vec = makeEmptyVec(sizeof(i32));
	i32 t = 114514;

	bump_alloced_bucket();
	for (size_t i = 0; i < 10000; ++i) {
		vecAppend(&vec, &i);
	}
	min_assert(*(int *)vecGet(vec, 9999) == 9999);
	bump_alloced_bucket();

	vecSet(vec, 9999, &t);
	min_assert(*(int *)vecGet(vec, 9999) == t);
}
