#include "../include/min/min_vec.h"

#include "../include/min/min_core.h"
#include "../include/min/min_string.h"
#include "../include/min/min_syscall.h"
// clang-format off

Vec makeVec(size_t size, size_t len) {
	size_t capacity = len < MIN_CAPACITY ? MIN_CAPACITY : len * 2;
	Vec vec = {
		.size = size,
		.len = len,
		.capacity = capacity,
		.data = min_malloc(capacity * size)
	};
	return vec;
}

Vec makeEmptyVec(size_t size) {
	Vec vec = {
		.size = size,
		.len = 0,
		.capacity = MIN_CAPACITY,
		.data = min_malloc(MIN_CAPACITY * size)
	};
	return vec;
}

i32 vecSet(Vec vec, size_t index, const void *value) {
	if (vec.data == nil || index >= vec.len) return -1;
	min_memcpy(vec.data + index * vec.size, value, vec.size);
	return 0;
}

void *vecGet(Vec vec, size_t index) {
	if (vec.data == nil || index >= vec.len) return nil;
	return vec.data + index * vec.size;
}

void vecAppend(Vec *vec, void *value) {
	if (vec->len + 1 > vec->capacity) {
		vec->capacity *= 2;
		vec->data = min_realloc(vec->data, vec->capacity * vec->size);
		if (vec->data == nil) return;
	}
	min_memcpy(vec->data + vec->len * vec->size, value, vec->size);
	++vec->len;
}
