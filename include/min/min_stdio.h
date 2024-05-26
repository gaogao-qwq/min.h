#ifndef MIN_STDIO_H_
#define MIN_STDIO_H_ 1
#include "min_def.h"

typedef enum conversion_type {
	CONVTYPE_PERCENT_LITERAL,
	CONVTYPE_CHARACTER,
	CONVTYPE_STRING,
	CONVTYPE_SIGNED_DECIMAL,
	CONVTYPE_DECIMAL_OCTAL,
	CONVTYPE_DECIMAL_HEXADECIMAL,
	CONVTYPE_UNSIGNED_DECIMAL,
	CONVTTYPE_FLOATING,
	CONVTYPE_FLOATING_EXPONENT,
	CONVTYPE_FLOATING_HEXADECIMAL_EXPONENT,
	CONVTYPE_POINTER,
} conversion_type;

typedef struct format_specifier {
	conversion_type conv_type;
	u32 loc;
} format_specifier;

i32 min_print(const char *s);

i32 parse_format(const char *restrict format, u32 *cnt,
                 format_specifier *specs);

i32 min_sprintf(char *buf, const char *fmt, ...);

i32 min_printf(const char *fmt, ...);

i32 min_errorf(const char *fmt, ...);

#endif // MIN_STDIO_H_
