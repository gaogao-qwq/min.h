#define NOSTDLIB_BUILD 1
#include "../include/min.h"
#include <stdio.h>

int main(void) {
	// clock_t curr_time = sys_time(nil);
	// printf("%ld\n", curr_time);
	char buf[4];
	i64 res = sys_getrandom(buf, 4u, GRND_NONBLOCK);
	i32 *rn = (i32 *)buf;
	if (res != -1) {
		printf("%d\n", *rn);
	}
	const char str[] = "Hello, World";
	sys_write(STDOUT_FILENO, str, 13);
	return 0;
}
