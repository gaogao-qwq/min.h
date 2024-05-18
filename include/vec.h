#ifndef VEC_CORE_H_
#define VEC_VORE_H_ 1
#include "min_def.h"

typedef struct Vec {
	void 	*data;
	u32  	len;
	u32  	capacity;
} Vec;
static Vec *makeVec(u32 size, u32 len);

#endif
