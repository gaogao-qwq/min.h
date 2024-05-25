#ifndef MIN_STDINT_H_
#define MIN_STDINT_H_ 1

#include "min_def.h"

#define I8_MIN  		(-128)
#define I16_MIN 		(-32768)
#define I32_MIN 		(-2147483647-1)
#define I64_MIN 		(-((i64)9223372036854775807)-1)

#define I8_MAX  		(127)
#define I16_MAX 		(32767)
#define I32_MAX 		(2147483647)
#define I64_MAX 		((i64)(9223372036854775807))

#define U8_MAX  		(255)
#define U16_MAX 		(65535)
#define U32_MAX 		(4294967295U)
#define U64_MAX 		((u64)(18446744073709551615U))

#endif // MIN_STDINT_H_
