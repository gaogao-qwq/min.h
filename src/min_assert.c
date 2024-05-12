#include "../include/min_assert.h"
#include "../include/min_syscall.h"
#include "../include/min_string.h"
#include "../include/min_conv.h"
#include "../include/min_stdlib.h"

void min_assert_fail(const char *assertion, const char *file,
					 u32 line, const char *function) {
	char linestr[9];
	u32toa(line, linestr);
	sys_write(STDERR_FILENO, file, min_strlen(file));
	sys_write(STDERR_FILENO, ":", 2);
	sys_write(STDERR_FILENO, linestr, min_strlen(linestr));
	sys_write(STDERR_FILENO, ": ", 3);
	sys_write(STDERR_FILENO, function, min_strlen(function));
	sys_write(STDERR_FILENO, ": ", 3);
	sys_write(STDERR_FILENO, "Assertion '", 12);
	sys_write(STDERR_FILENO, assertion, min_strlen(assertion));
	sys_write(STDERR_FILENO, "' failed.\n", 11);
	sys_exit(EXIT_SUCCESS);
}
