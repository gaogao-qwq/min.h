#ifndef MIN_SYSCALL_H_
#define MIN_SYSCALL_H_ 1

#if defined (__amd64__)
	#include "arch/x86/syscall.h"
#elif defined (__aarch64__)
	#include "arch/arm/syscall.h"
#elif defined (__loongarch__)
	#include "arch/loongarch/syscall.h"
#endif

#endif // MIN_SYSCALL_H_
