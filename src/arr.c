#include "../include/arr.h"
#include "../include/min_core.h"

static Arr *makeArr(u32 size, u32 len) {
	Arr *a = min_malloc(sizeof(Arr));
	a->data = min_malloc(len * size);
	a->len = len;
	return a;
}

static Arr *makeEmptyArr() {
	Arr *a = nil;
	return a;
}
