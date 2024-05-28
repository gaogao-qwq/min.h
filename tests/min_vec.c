#include "../include/min.h"

i32 main(void) {
	Vec vec = makeEmptyVec(sizeof (i32));
	for (size_t i = 0; i <= 10000; ++i) {
		vecAppend(&vec, &i);
	}
	for (size_t i = 0; i < 10; ++i) {
		min_printf("%d ", *(int *)vecGet(vec, i));
	}
	min_printf("%d", *(int*)vecGet(vec, 10000));
}
