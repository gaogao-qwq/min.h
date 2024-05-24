#include "../include/min.h"

i32 main(void) {
	char s1[12], s2[11], s3[21], s4[20];
	i32toa(I32_MIN, s1);
	u32toa(U32_MAX, s2);
	i64toa(I64_MAX, s3);
	u64toa(U64_MAX, s4);
	min_printf("s1 = %s, s2 = %s, s3 = %s, s4 = %s\n", s1, s2, s3, s4);
	char h1[12], h2[12];
	u32tohex(U32_MAX, h1);
	u64tohex(1145141919810, h2);
	min_printf("h1 = %s, h2 = %s", h1, h2);
	return 0;
}
