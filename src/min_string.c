#include "../include/min/min_string.h"

#include "../include/min/algo.h"

i32 min_atoi(const char *str) {
	if (str == nil) return -1;
	const char *p = str;
	char numstr[12];
	i32 num = 0;
	u32 idx = 0;
	bool prefix = true, sign = false;

	while (*p && min_strchr("+-1234567890", *p)) {
		if (!min_strchr("+-0123456789", *p)) break;
		if (*p == '+' || *p == '-') {
			if (sign) return 0;
			else sign = true, numstr[idx++] = *p;
		} else if (*p == '0') {
			if (!prefix) numstr[idx++] = *p;
		} else {
			prefix = false, numstr[idx++] = *p;
		}
		++p;
	}
	numstr[idx] = '\0';
	u32 len = min_strlen(numstr);
	i32 place = 1;
	for (u32 i = 0; i < len; ++i, place *= 10) {
		char numc = numstr[len-i-1];
		if (numc == '+') break;
		if (numc == '-') {
			num = -num;
			break;
		}
		num += (numc - '0') * place;
	}
	return num;
}

i64 min_atoll(const char *str) {
	const char *p = str;
	if (str == nil) return -1;
	char numstr[24];
	i64 num = 0;
	u32 idx = 0;
	bool prefix = true, sign = false;

	while (*p && min_strchr("+-1234567890", *p)) {
		if (!min_strchr("+-0123456789", *p)) break;
		if (*p == '+' || *p == '-') {
			if (sign) return 0;
			else sign = true, numstr[idx++] = *p;
		} else if (*p == '0') {
			if (!prefix) numstr[idx++] = *p;
		} else {
			prefix = false, numstr[idx++] = *p;
		}
		++p;
	}
	numstr[idx] = '\0';
	u32 len = min_strlen(numstr);
	i64 place = 1;
	for (u32 i = 0; i < len; ++i, place *= 10) {
		char numc = numstr[len-i-1];
		if (numc == '+') break;
		if (numc == '-') {
			num = -num;
			break;
		}
		num += (numc - '0') * place;
	}
	return num;
}

char *min_strchr(char *str, i32 ch) {
	if (str == nil) return nil;
	char *p = str;
	while (true) {
		if (*p == ch) return p;
		if (*p == '\0') return nil;
		++p;
	}
}

bool min_isdigit(int ch) {
	return min_strchr("1234567890", ch) ? true : false;
}

i32 min_strcmp(const char *lhs, const char *rhs) {
	const char *l = lhs, *r = rhs;
	while (*l || *r) {
		if (*l < *r) return -1;
		if (*l > *r) return 1;
		++l, ++r;
	}
	if (*l && *r) return 0;
	if (*l) return -1;
	return 1;
}

i32 min_reverse(char *str) {
	if (str == nil) return -1;
	u32 len = min_strlen(str);
	for (u32 l = 0, r = len - 1; l < r; ++l, --r) {
		min_swap(str + l, str + r, sizeof(str[0]));
	}
	return 0;
}

u32 min_strlen(const char *str) {
	const char *p = str;
	while (*p) ++p;
	return p - str;
}

void min_memcpy(void *dst, const void *src, u32 size) {
	for (u32 i = 0; i < size; ++i) {
		*(char *)(dst + i) = *(char *)(src + i);
	}
}
