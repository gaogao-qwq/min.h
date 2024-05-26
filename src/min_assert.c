#include "../include/min/min_assert.h"

#include "../include/min/min_stdio.h"
#include "../include/min/min_syscall.h"

void min_assert_fail(const char *assertion, const char *file,
                     u32 line, const char *function) {
	min_errorf("%s:%u: %s: Assertion '%s' failed.\n",
               file, line, function, assertion);
	sys_exit(EXIT_SUCCESS);
}
