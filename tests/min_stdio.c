#include "../include/min.h"

static char buf[U16_MAX];
int main(void) {
	i32 *arr = min_malloc(10 *  sizeof(i32));
	min_printf("%%: %%\n");
	min_printf("signed decimal: %d\n", I64_MIN);
	min_printf("unsigned decimal: %u\n", U64_MAX);
	min_printf("string: %s\n", "Hello, world!");
	min_printf("pointer: %p\n", arr);
	return EXIT_SUCCESS;
}
