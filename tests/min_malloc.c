#include "../include/min.h"

i32 main(void) {
	min_print("Testing min_malloc()...\n");
	i32 *i32arr = min_malloc(10 * sizeof(i32));
	u32 *u32arr = min_calloc(1000, sizeof(u32));
	i64 *i64arr = min_malloc(10 * sizeof(i64));
	char *str = min_malloc(16 * sizeof(char));

	bump_alloced_bucket();

	min_print("Testing min_realloc()...\n");
	min_realloc(i64arr, 1024 * sizeof(i64));
	min_print("Alloced chunks after min_realloc:\n");
	bump_alloced_bucket();

	min_print("Testing min_free()...\n");
	min_free(i32arr);
	min_print("Alloced chunks after min_free:\n");
	bump_alloced_bucket();
	return 0;
}
