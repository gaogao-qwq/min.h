#include "../../include/min.h"
#define N 10

int main(void) {
	i32 *arr = min_malloc(N * sizeof(i32));
	arr[0] = 1, arr[1] = 2;
	for (size_t i = 2; i < N; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for (size_t i = 0; i < N; ++i) {
		if (i < N-1) min_printf("[%d]: %d, ", i, arr[i]);
		else min_printf("[%d]: %d.", i, arr[i]);
	}
	return 0;
}
