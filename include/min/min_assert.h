#include "min_syscall.h"
#ifndef MIN_ASSERT_H_
#define MIN_ASSERT_H_ 1

void min_assert_fail(const char* assertion, const char *file,
                     u32 line, const char *function);

#define min_assert(expr) ((void) sizeof ((expr) ? 1 : 0), ({\
	if (expr) ;\
	else min_assert_fail(#expr, __FILE__, __LINE__, __func__);\
}))

#endif // MIN_ASSERT_H_
