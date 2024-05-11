#define NOSTDLIB_BUILD
#include <stdio.h>
#include "../include/min.h"

i32 main(void) {
	char s1[12], s2[11], s3 [21], s4[20];
	i32toa(I32_MIN, s1);
	u32toa(U32_MAX, s2);
	i64toa(I64_MAX, s3);
	u64toa(U64_MAX, s4);
	printf("s1=%s, s2=%s, s3=%s, s4=%s", s1, s2, s3, s4);
	return 0;
}

