#include "../include/min.h"

i32 compar(const void *p1, const void *p2) {
	i32 a = *((i32 *)p1), b = *((i32 *)p2);
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}

i32 main(void) {
	Arr arr = makeArr(sizeof(i32), 10);
	i32 a0 = 0, a1 = 1;
	arrSet(arr, 0, &a0);
	arrSet(arr, 1, &a1);
	for (size_t i = 2; i < arr.len; ++i) {
		i32 t = *((i32 *)arrGet(arr, i - 1)) + *((i32 *)arrGet(arr, i - 2));
		arrSet(arr, i, &t);
	}
	for (size_t i = 0; i < arr.len; ++i) {
		if (i != arr.len - 1) {
			min_printf("%d, ", *((i32 *)arrGet(arr, i)));
		} else {
			min_printf("%d\n", *((i32 *)arrGet(arr, i)));
		}
	}

	min_print("After reverse:\n");
	arrReverse(arr);
	for (size_t i = 0; i < arr.len; ++i) {
		if (i != arr.len - 1) {
			min_printf("%d, ", *((i32 *)arrGet(arr, i)));
		} else {
			min_printf("%d\n", *((i32 *)arrGet(arr, i)));
		}
	}

	arrSort(arr, compar);
	min_print("After sort:\n");
	for (size_t i = 0; i < arr.len; ++i) {
		if (i != arr.len - 1) {
			min_printf("%d, ", *((i32 *)arrGet(arr, i)));
		} else {
			min_printf("%d\n", *((i32 *)arrGet(arr, i)));
		}
	}
	arrFree(&arr);
	return 0;
}
