#ifndef ARR_H_
#define ARR_H_
#include "min_def.h"

typedef struct Arr {
	void	*data;
	u32		len;
} Arr;
static Arr *makeArr(u32 size, u32 len);
static Arr *makeEmptyArr();

#endif
