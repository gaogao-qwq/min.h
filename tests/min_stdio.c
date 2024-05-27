#include "../include/min.h"

static char buf[U16_MAX];
int main(void) {
	i32 *arr = min_malloc(10 *  sizeof(i32));
	min_printf("%%: %%\n");
	min_printf("signed decimal: %d\nsigned long decimal: %ld\n", I32_MIN, I64_MIN);
	min_printf("unsigned decimal: %u\nunsigned long decimal: %lu\n", U32_MAX, U64_MAX);
	min_printf("string: %s\n", "Hello, world!");
	min_printf("pointer: %p\n", arr);
	return EXIT_SUCCESS;
}
