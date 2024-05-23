#include "../include/min/min_math.h"

#include "../include/min/min_stdint.h"

i32 i32abs(i32 num) {
	if (num == I32_MIN) return I32_MAX;
	return num < 0 ? -num : num;
}

i64 i64abs(i64 num) {
	if (num == I64_MIN) return I64_MAX;
	return num < 0 ? -num : num;
}
