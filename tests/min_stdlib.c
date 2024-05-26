#include "../include/min.h"

int main(void) {
	timeval tv = {0};
	i32 res = sys_gettimeofday(&tv, nil);
	min_printf("%d\n", tv.tv_sec);
	char buf[4];
	res = sys_getrandom(buf, 4u, GRND_NONBLOCK);
	i32 *rn = (i32 *)buf;
	if (res != -1) {
		min_printf("%d\n", *rn);
	}
	return 0;
}
