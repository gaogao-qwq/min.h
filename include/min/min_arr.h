#ifndef MIN_ARR_H_
#define MIN_ARR_H_
#include "min_def.h"

typedef struct Arr {
	void 	*data;
	u32  	len;
} Arr;
Arr *makeArr(u32 size, u32 len);
Arr *makeEmptyArr();

#endif // MIN_ARR_H_
