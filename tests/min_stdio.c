#include "../include/min.h"

static char buf[U16_MAX];
int main(void) {
	min_printf("int: %d\nstring: %s", 12345, "hello, world");
	return EXIT_SUCCESS;
}
