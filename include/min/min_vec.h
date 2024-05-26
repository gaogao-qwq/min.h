#ifndef MIN_VEC_H
#define MIN_VEC_H_ 1
#include "min_def.h"

typedef struct Vec {
	void 	*data;
	u32  	len;
	u32  	capacity;
} Vec;
Vec *makeVec(u32 size, u32 len);

#endif // MIN_VEC_H_
