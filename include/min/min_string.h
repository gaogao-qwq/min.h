#ifndef MIN_STRING_H_
#define MIN_STRING_H_ 1

#include "min_def.h"

i32 min_atoi(const char *str);

i64 min_atoll(const char *str);

bool min_isdigit(int ch);

char *min_strchr(char *str, i32 ch);

i32 min_strcmp(const char *lhs, const char *rhs);

i32 min_reverse(char *str);

u32 min_strlen(const char *s);

void min_memcpy(void *dst, const void *src, u32 size);

void *min_memset(void *dst, i32 ch, size_t cnt);

#endif // MIN_STRING_H_
