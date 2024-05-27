#ifndef MIN_ARR_H_
#define MIN_ARR_H_
#include "min_algo.h"
#include "min_def.h"
// clang-format off

typedef struct Arr {
	void   *data;
	size_t  size;
	size_t  len;
} Arr;

Arr makeArr(size_t size, size_t len);
Arr makeEmptyArr(size_t size);
i32 arrSet(Arr arr, size_t index, const void *value);
void *arrGet(Arr arr, size_t index);
i32 arrReverse(Arr arr);
i32 arrSort(Arr arr, compar_t compar);

#endif // MIN_ARR_H_
