#include "../include/min/min_arr.h"

#include "../include/min/min_core.h"

Arr *makeArr(u32 size, u32 len) {
	Arr *a = min_malloc(sizeof(Arr));
	a->data = min_malloc(len * size);
	a->len = len;
	return a;
}

Arr *makeEmptyArr() {
	Arr *a = nil;
	return a;
}
