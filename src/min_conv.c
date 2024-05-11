#include "../include/min_conv.h"
#include "../include/min_string.h"
#include "../include/min_math.h"

i32 u32toa(u32 num, char *dst) {
	if (dst == nil) return -1;
	u32 i = 0;
	while (num) {
		dst[i] = '0' + num % 10;
		num /= 10, ++i;
	}
	dst[i] = '\0';
	min_reverse(dst);
	return 0;
}

i32 u64toa(u64 num, char *dst) {
	if (dst == nil) return -1;
	u32 i = 0;
	while (num) {
		dst[i] = '0' + num % 10;
		num /= 10, ++i;
	}
	dst[i] = '\0';
	min_reverse(dst);
	return 0;
}

i32 i32toa(i32 num, char *dst) {
	if (dst == nil) return -1;
	u32 i = 0;
	bool neg = false;
	if (num < 0) {
		dst[i] = '-', ++i;
		neg = true;
	}
	while (num) {
		dst[i] = '0' + i32abs(num % 10);
		num /= 10, ++i;
	}
	dst[i] = '\0';
	if (neg) min_reverse(dst + 1);
	else min_reverse(dst);
	return 0;
}

i64 i64toa(i64 num, char *dst) {
	if (dst == nil) return -1;
	u32 i = 0;
	bool neg = false;
	if (num < 0) {
		dst[i] = '-', ++i;
		neg = true;
	}
	while (num) {
		dst[i] = '0' + i64abs(num % 10);
		num /= 10, ++i;
	}
	dst[i] = '\0';
	if (neg) min_reverse(dst + 1);
	else min_reverse(dst);
	return 0;
}
