#include "../include/min.h"

#define TESTARR_LEN (u32)1e4
i32 unsorted[TESTARR_LEN];
i32 arr[10] = {-100, 4, -100, 6, 9, 3, 2, 1, 10, 7};

static i32 compar(const void *p1, const void *p2) {
	int a = *(int *)p1, b = *(int *)p2;
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

// TEST: min_qsort
int main(void) {
	bool flag1 = true, flag2 = true;
	min_print("Testing min_qsort...\n");
	//---------------
	// Test 1
	//---------------
	min_print("Testing(1/2)...\n");
	min_qsort(arr, 10, sizeof(arr[0]), compar);
	for (u32 i = 1; i < 10; ++i) {
		if (arr[i] < arr[i - 1]) {
			min_printf("1st test failed at idx %d", i);
			flag1 = false;
			break;
		}
	}
	if (flag1) min_print("\nTest 1 passed.\n");

	//---------------
	// Test 2
	//---------------
	min_print("\nTesting(2/2)...\n");
	char buf[4];
	sys_getrandom(buf, 4, GRND_NONBLOCK);
	for (u32 i = 0; i < TESTARR_LEN; ++i) unsorted[i] = *(i32 *)buf;
	min_qsort(unsorted, TESTARR_LEN, sizeof(unsorted[0]), compar);
	for (u32 i = 1; i < TESTARR_LEN; ++i) {
		if (unsorted[i] < unsorted[i - 1]) {
			min_printf("2nd test failed at idx %d", i);
			flag2 = false;
			break;
		}
	}
	if (flag2) min_print("\nTest 2 passed.\n");
	return 0;
}
