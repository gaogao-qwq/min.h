#include "../include/min.h"

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
	min_printf("After reverse:\n");
	arrReverse(arr);
	for (size_t i = 0; i < arr.len; ++i) {
		if (i != arr.len - 1) {
			min_printf("%d, ", *((i32 *)arrGet(arr, i)));
		} else {
			min_printf("%d\n", *((i32 *)arrGet(arr, i)));
		}
	}
	return 0;
}
