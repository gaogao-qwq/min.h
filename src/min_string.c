#include "../include/min_string.h"

u32 min_strlen(const char *s) {
	const char *p = s;
	while (*p) ++p;
	return p - s;
}

void min_memcpy(void *dst, const void *src, u32 size) {
	char *p = dst;
	for (u32 i = 0; i < size; ++i) {
		*(p + i) = *(char *)(src + i);
	}
}
