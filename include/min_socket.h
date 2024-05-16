#ifndef MIN_SOCKET_H_
#define MIN_SOCKET_H_ 1

#include "../include/min_def.h"

#define IPPROTO_TCP ((u32)6)
#define UPROOTO_UDP ((u32)17)

typedef i16 sa_family_t;

// The only purpose of this structure is to cast the structure
// pointer passed in addr in order to avoid compiler warnings.
typedef struct sockaddr {
	sa_family_t 		sa_family;
	char        		sa_data[14];
} sockaddr;

#endif
