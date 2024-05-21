#ifdef __aarch64__
#include "../../../include/arch/arm/aarch64_syscall.h"
#include "../../../include/min_def.h"
// x8 x0 x1 x2 x3 x4 x5

ssize_t sys_read(i32 fd, void *buf, u64 size) {
	register u64   x8 __asm__("x8") = NR_READ;
	register i32   x0 __asm__("x0") = fd;
	register void *x1 __asm__("x1") = buf;
	register u32   x2 __asm__("x2") = size;
	i32 ret;
	__asm__ __volatile__ ("svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1), "r" (x2)
	);
	return ret;
}

ssize_t sys_write(i32 fd, const void *buf, u64 size) {
	register u64         x8 __asm__("x8") = NR_WRITE;
	register i32         x0 __asm__("x0") = fd;
	const register void *x1 __asm__("x1") = buf;
	register u32         x2 __asm__("x2") = size;
	i32 ret;
	__asm__ __volatile__ ("svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1), "r" (x2)
	);
	return ret;
}

void *sys_mmap(void *addr, u32 length, i32 prot,
               i32 flags, i32 fd, i32 off) {
	register u64   x8 __asm__("x8") = NR_MMAP;
	register void *x0 __asm__("x0") = addr;
	register u32   x1 __asm__("x1") = length;
	register i32   x2 __asm__("x2") = prot;
	register i32   x3 __asm__("x3") = flags;
	register i32   x4 __asm__("x4") = fd;
	register i32   x5 __asm__("x5") = off;
	void *ret;
	__asm__ __volatile__ ("svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1), "r" (x2), "r" (x3), "r" (x4), "r" (x5)
	);
	return ret;
}

ssize_t sys_munmap(void *addr, u32 length) {
	register u64   x8 __asm__("x8") = NR_MUNMAP;
	register void *x0 __asm__("x0") = addr;
	register u32   x1 __asm__("x1") = length;
	i32 ret;
	__asm__ __volatile__ ("svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1)
	);
	return ret;
}

ssize_t sys_socket(i32 domain, i32 type, i32 protocol) {
	register u64 x8 __asm__("x8") = NR_SOCKET;
	register i32 x0 __asm__("x0") = domain;
	register i32 x1 __asm__("x1") = type;
	register i32 x2 __asm__("x2") = protocol;
	i32 ret;
	__asm__ __volatile__ ( "svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1), "r" (x2)
	);
	return ret;
}

ssize_t sys_bind(i32 sockfd, sockaddr *my_addr, i32 addrlen) {
	register u64       x8 __asm__("x8") = NR_SOCKET;
	register i32       x0 __asm__("x0") = sockfd;
	register sockaddr *x1 __asm__("x1") = my_addr;
	register i32       x2 __asm__("x2") = addrlen;
	ssize_t ret;
	__asm__ __volatile__ ( "svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1), "r" (x2)
	);
	return ret;
}

void sys_exit(i32 status) {
	register u64 x8 __asm__("x8") = NR_EXIT;
	register i32 x0 __asm__("x0") = status;
	__asm__ __volatile__ ( "svc #0"
		:
		: "r" (x8), "r" (x0)
	);
}

ssize_t sys_gettimeofday(timeval *restrict tv, timezone *restrict tz) {
	register u64       x8 __asm__("x8") = NR_GETTIMEOFDAY;
	register timeval  *x0 __asm__("x0") = tv;
	register timezone *x1 __asm__("x1") = tz;
	ssize_t ret;
	__asm__ __volatile__ ( "svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1)
	);
}

clock_t sys_times(tms *t) {
	register u64  x8 __asm__("x8") = NR_TIMES;
	register tms *x0 __asm__("x0") = t;
	clock_t ret;
	__asm__ __volatile__ ( "svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0)
	);
	return ret;
}

ssize_t sys_getrandom(char *buf, u64 count, u32 flags) {
	register u64   x8 __asm__("x8") = NR_GETRANDOM;
	register char *x0 __asm__("x0") = buf;
	register u64   x1 __asm__("x1") = count;
	register u32   x2 __asm__("x2") = flags;
	i32 ret;
	__asm__ __volatile__ ( "svc #0"
		: "=r" (ret)
		: "r" (x8), "r" (x0), "r" (x1), "r" (x2)
	);
	return ret;
}

#endif // __aarch64__
