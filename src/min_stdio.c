#include "../include/min/min_stdio.h"

#include "../include/min/min_conv.h"
#include "../include/min/min_core.h"
#include "../include/min/min_stdint.h"
#include "../include/min/min_string.h"
#include "../include/min/min_syscall.h"

i32 min_print(const char *str) {
	u32 len = min_strlen(str);
	i64 res = sys_write(STDOUT_FILENO, str, len);
	if (!res) return len;
	return -1;
}

i32 parse_format(const char *restrict format, u32 *cnt,
                 format_specifier *specs) {
	u32 i = 0, count = 0;
	for (i = 0; format[i]; ++i) {
		if (format[i] != '%') continue;
		if (!format[i + 1]) break;
		if (format[i + 1] == '%') {
			specs[count].conv_type = CONVTYPE_PERCENT_LITERAL;
			specs[count++].loc = i++;
			continue;
		} else if (format[i + 1] == 'd') {
			specs[count].conv_type = CONVTYPE_SIGNED_DECIMAL;
			specs[count++].loc = i++;
			continue;
		} else if (format[i + 1] == 's') {
			specs[count].conv_type = CONVTYPE_STRING;
			specs[count++].loc = i++;
			continue;
		} else if (format[i + 1] == 'p') {
			specs[count].conv_type = CONVTYPE_POINTER;
			specs[count++].loc = i++;
		}
	}
	*cnt = count;
	return 0;
}

i32 _min_sprintf(const char *restrict format, char *str,
                 format_specifier *specs, u32 cnt, __builtin_va_list argp) {
	if (str == nil) return -1;
	u32 i = 0, j = 0, k = 0;
	while (format[i]) {
		if (specs[j].loc == i) {
			if (specs[j].conv_type == CONVTYPE_PERCENT_LITERAL) {
				++i;
				str[k++] = '%';
			} else if (specs[j].conv_type == CONVTYPE_SIGNED_DECIMAL) {
				++i;
				char t[12], *pt = t;
				i32toa(__builtin_va_arg(argp, i32), t);
				while (*pt) {
					str[k] = *pt;
					++pt, ++k;
				}
			} else if (specs[j].conv_type == CONVTYPE_STRING) {
				++i;
				char *t = __builtin_va_arg(argp, char *);
				while (*t) {
					str[k] = *t;
					++t, ++k;
				}
			} else if (specs[j].conv_type == CONVTYPE_POINTER) {
				++i;
				char t[20], *pt = t;
				u64tohex(__builtin_va_arg(argp, u64), t);
				while (*pt) {
					str[k] = *pt;
					++k, ++pt;
				}
			}
			++j;
		} else {
			str[k++] = format[i];
		}
		++i;
	}
	str[k] = '\0';
	return 0;
}

i32 min_sprintf(char *buf, const char *restrict format, ...) {
	i32 res;
	u32 cnt = min_strlen(format);
	format_specifier specs[cnt];
	__builtin_va_list argp;

	parse_format(format, &cnt, specs);
	__builtin_va_start(argp, format);
	res = _min_sprintf(format, buf, specs, cnt, argp);
	__builtin_va_end(argp);
	return res;
}

i32 min_printf(const char *restrict format, ...) {
	i32 res;
	u32 cnt = min_strlen(format);
	char buf[U16_MAX];
	format_specifier specs[cnt];
	__builtin_va_list argp;

	parse_format(format, &cnt, specs);
	__builtin_va_start(argp, format);
	res = _min_sprintf(format, buf, specs, cnt, argp);
	__builtin_va_end(argp);
	sys_write(STDOUT_FILENO, buf, min_strlen(buf));
	return res;
}
