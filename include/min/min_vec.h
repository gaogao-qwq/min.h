#ifndef MIN_VEC_H
#define MIN_VEC_H_ 1
#include "min_def.h"
// clang-format off

#define MIN_CAPACITY 64

typedef struct Vec {
	void   *data;
	size_t  len;
	size_t  capacity;
} Vec;

Vec makeVec(size_t size, size_t len);
Vec makeEmptyVec(size_t size);

#endif // MIN_VEC_H_
