#include "../include/min/min_vec.h"

#include "../include/min/min_core.h"
// clang-format off

Vec makeVec(size_t size, size_t len) {
	size_t capacity = len < MIN_CAPACITY ? MIN_CAPACITY : len * 2;
	Vec vec = {
		.len = len,
		.capacity = capacity,
		.data = min_malloc(capacity * size)
	};
	return vec;
}

Vec makeEmptyVec(size_t size) {
	Vec vec = {
		.len = 0,
		.capacity = MIN_CAPACITY,
		.data = min_malloc(MIN_CAPACITY * size)
	};
	return vec;
}
