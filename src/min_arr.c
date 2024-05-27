#include "../include/min/min_arr.h"

#include "../include/min/min_algo.h"
#include "../include/min/min_assert.h"
#include "../include/min/min_core.h"
#include "../include/min/min_string.h"
// clang-format off

Arr makeArr(size_t size, size_t len) {
	Arr arr = {
		.data = min_malloc(len * size),
		.size = size,
		.len = len
	};
	return arr;
}

Arr makeEmptyArr(size_t size) {
	Arr arr = {
		.data = nil,
		.len = 0
	};
	return arr;
}

i32 arrSet(Arr arr, size_t index, const void *value) {
	if (arr.data == nil || index > arr.len) return -1;
	min_memcpy(arr.data + index * arr.size, value, arr.size);
	return 0;
}

void *arrGet(Arr arr, size_t index) {
	if (arr.data == nil || index > arr.len) return nil;
	return arr.data + index * arr.size;
}

i32 arrReverse(Arr arr) {
	if (arr.data == nil) return -1;
	size_t mid = arr.len / 2;
	for (size_t i = 0; i < mid; ++i) {
		min_swap(arr.data + i * arr.size,
		         arr.data + (arr.len - i) * arr.size,
		         arr.size);
	}
	return 0;
}

i32 arrSort(Arr arr, compar_t compar) {
	if (arr.data == nil || compar == nil) return -1;
	min_qsort(arr.data, arr.len, arr.size, compar);
	return 0;
}

