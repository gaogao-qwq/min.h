#include "../include/min.h"

int main(void) {
	timeval tv = {0};
	i32 res = sys_gettimeofday(&tv, nil);
	min_assert(res != -1);
	min_printf("%d\n", tv.tv_sec);

	char buf[4];
	res = sys_getrandom(buf, 4u, GRND_NONBLOCK);
	min_assert(res != -1);
	min_printf("%d\n", *(i32 *)buf);
}
