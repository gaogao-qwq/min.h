#ifndef MIN_STDIO_H_
#define MIN_STDIO_H_ 1
#include "min_def.h"

typedef enum conversion_type {
	PERCENT_LITERAL,
	CHARACTER,
	STRING,
	SIGNED_DECIMAL,
	DECIMAL_OCTAL,
	DECIMAL_HEXADECIMAL,
	UNSIGNED_DECIMAL,
	FLOATING,
	FLOATING_EXPONENT,
	FLOATING_HEXADECIMAL_EXPONENT,
	POINTER,
} conversion_type;

typedef struct format_specifier {
	conversion_type conv_type;
	u32 loc;
} format_specifier;

i32 min_print(const char *s);

i32 parse_format(const char *restrict format, u32 *cnt,
                 format_specifier *specs);

i32 _min_sprintf(const char *restrict format, char *str,
                 format_specifier *specs, u32 cnt, __builtin_va_list argp);

i32 min_sprintf(char *buf, const char *fmt, ...);

i32 min_printf(const char *fmt, ...);

#endif
