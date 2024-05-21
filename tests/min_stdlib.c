#include <stdio.h>

#include "../include/min.h"

int main(void) {
	timeval tv = {0};
	i32 res = sys_gettimeofday(&tv, nil);
	printf("%d\n", tv.tv_sec);
	char buf[4];
	res = sys_getrandom(buf, 4u, GRND_NONBLOCK);
	i32 *rn = (i32 *)buf;
	if (res != -1) {
		printf("%d\n", *rn);
	}
	const char str[] = "Hello, World";
	sys_write(STDOUT_FILENO, str, 13);
	return 0;
}
