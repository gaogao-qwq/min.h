#include "../include/min.h"

i32 main(void) {
	i32 a = 1, b = 2;
	min_assert(a == b);
	min_printf("This line won't be excuted");
	return 0;
}
