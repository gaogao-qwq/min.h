#include <stdio.h>
#include <time.h>
#include "../include/min.h"

#define TESTARR_LEN (u32)1e4

i32 sorted[TESTARR_LEN];

static i32 compar (const void *a, const void *b) {
	return *((int *)a) - *(int *)b;
}

// TEST: min_bsearch
int main() {
	printf("Testing min_bsearch...\n");
	srandom(time(nil));
	for (u32 i = 0, n = 2; i < 10000; ++i, n+=2)
		sorted[i] = n;
	printf("\n");
	i32 key = 1024;
	i32 *res = min_bsearch(&key, sorted, 10000, sizeof(i32), compar);
	if (res == nil) printf("Not found by min_bsearch\n");
	else printf("Found: %d\n", *res);
	return 0;
}
