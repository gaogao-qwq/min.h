#include "../include/min/min_conv.h"

#include "../include/min/min_string.h"
#include "../include/min/min_math.h"

i32 u32toa(u32 num, char *dst) {
	if (dst == nil) return -1;
	if (!num) {
		dst[0] = '0', dst[1] = '\0';
		return 0;
	}
	u32 i = 0;
	while (num) {
		dst[i] = '0' + num % 10;
		num /= 10, ++i;
	}
	dst[i] = '\0';
	min_reverse(dst);
	return 0;
}

i32 u32tohex(u32 num, char *dst) {
	if (dst == nil) return -1;
	u32 i = 0;
	dst[i++] = '0', dst[i++] = 'x';
	if (!num) {
		dst[i++] = '0', dst[i++] = '\0';
		return 0;
	}
	while (num) {
		u32 n = num % 16;
		if (n < 10) {
			dst[i] = '0' + n;
		} else {
			switch (n) {
				case 10:
					dst[i] = 'a';
					break;
				case 11:
					dst[i] = 'b';
					break;
				case 12:
					dst[i] = 'c';
					break;
				case 13:
					dst[i] = 'd';
					break;
				case 14:
					dst[i] = 'e';
					break;
				case 15:
					dst[i] = 'f';
					break;
			}
		}
		num /= 16, ++i;
	}
	dst[i] = '\0';
	min_reverse(dst + 2);
	return 0;
}

i32 u64toa(u64 num, char *dst) {
	if (dst == nil) return -1;
	if (!num) {
		dst[0] = '0', dst[1] = '\0';
		return 0;
	}
	u32 i = 0;
	while (num) {
		dst[i] = '0' + num % 10;
		num /= 10, ++i;
	}
	dst[i] = '\0';
	min_reverse(dst);
	return 0;
}

i32 u64tohex(u64 num, char *dst) {
	if (dst == nil) return -1;
	u32 i = 0;
	dst[i++] = '0', dst[i++] = 'x';
	if (!num) {
		dst[i++] = '0', dst[i++] = '\0';
		return 0;
	}
	while (num) {
		u32 n = num % 16;
		if (n < 10) {
			dst[i] = '0' + n;
		} else {
			switch (n) {
				case 10:
					dst[i] = 'a';
					break;
				case 11:
					dst[i] = 'b';
					break;
				case 12:
					dst[i] = 'c';
					break;
				case 13:
					dst[i] = 'd';
					break;
				case 14:
					dst[i] = 'e';
					break;
				case 15:
					dst[i] = 'f';
					break;
			}
		}
		num /= 16, ++i;
	}
	dst[i] = '\0';
	min_reverse(dst + 2);
	return 0;
}

i32 i32toa(i32 num, char *dst) {
	if (dst == nil) return -1;
	if (!num) {
		dst[0] = '0', dst[1] = '\0';
		return 0;
	}
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
	if (!num) {
		dst[0] = '0', dst[1] = '\0';
		return 0;
	}
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
