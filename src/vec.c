#include "../include/vec.h"

static Vec *makeVec(u32 size, u32 len) {
	Vec *v = min_malloc(sizeof(Vec));
	v->len = len;
	v->capacity = 2 * len;
	v->data = min_malloc(v->capacity * size);
	return v;
}
