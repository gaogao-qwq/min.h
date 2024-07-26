#include "../include/min.h"
#define N 10

int main(void) {
	i32 *arr = min_malloc(sizeof(i32) * N);
	min_memset(arr, 1, sizeof(i32) * N);
	for (size_t i = 0; i < N; ++i) {
		min_assert(arr[i] == 0x1010101);
	}
	return 0;
}
