#ifndef MIN_SYSCALL_H_
#define MIN_SYSCALL_H_ 1

#if defined (__amd64__)
	#include "arch/x86/amd64_syscall.h"
#elif defined (__aarch64__)
	#include "arch/arm/aarch64_syscall.h"
#elif defined (__loongarch__)
	#include "arch/loongarch/loongarch64_syscall.h"
#endif

#endif
