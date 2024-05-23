#ifdef __loongarch__
#include "../../../include/min/arch/loongarch/loongarch64_syscall.h"
#include "../../../include/min/min_def.h"
// a7 a0 a1 a2 a3 a4 a5

ssize_t sys_read(i32 fd, void *buf, size_t size) {
	register u64     a7 __asm__("a7") = NR_READ;
	register i32     a0 __asm__("a0") = fd;
	register void   *a1 __asm__("a1") = buf;
	register size_t  a2 __asm__("a2") = size;
	i32 ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1), "r" (a2)
	);
	return ret;
}

ssize_t sys_write(i32 fd, const void *buf, size_t size) {
	register u64         a7 __asm__("a7") = NR_WRITE;
	register i32         a0 __asm__("a0") = fd;
	const register void *a1 __asm__("a1") = buf;
	register size_t      a2 __asm__("a2") = size;
	i32 ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1), "r" (a2)
	);
	return ret;
}

void *sys_mmap(void *addr, size_t length, i32 prot,
               i32 flags, i32 fd, i32 off) {
	register u64     a7 __asm__("a7") = NR_MMAP;
	register void   *a0 __asm__("a0") = addr;
	register size_t  a1 __asm__("a1") = length;
	register i32     a2 __asm__("a2") = prot;
	register i32     a3 __asm__("a3") = flags;
	register i32     a4 __asm__("a4") = fd;
	register i32     a5 __asm__("a5") = off;
	void *ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1), "r" (a2), "r" (a3), "r" (a4), "r" (a5)
	);
	return ret;
}

ssize_t sys_munmap(void *addr, size_t length) {
	register u64     a7 __asm__("a7") = NR_MUNMAP;
	register void   *a0 __asm__("a0") = addr;
	register size_t  a1 __asm__("a1") = length;
	i32 ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1)
	);
	return ret;
}

ssize_t sys_socket(i32 domain, i32 type, i32 protocol) {
	register u64 a7 __asm__("a7") = NR_SOCKET;
	register i32 a0 __asm__("a0") = domain;
	register i32 a1 __asm__("a1") = type;
	register i32 a2 __asm__("a2") = protocol;
	i32 ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1), "r" (a2)
	);
	return ret;
}

ssize_t sys_bind(i32 sockfd, sockaddr *my_addr, ssize_t addrlen) {
	register u64       a7 __asm__("a7") = NR_SOCKET;
	register i32       a0 __asm__("a0") = sockfd;
	register sockaddr *a1 __asm__("a1") = my_addr;
	register ssize_t   a2 __asm__("a2") = addrlen;
	ssize_t ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1), "r" (a2)
	);
	return ret;
}

void sys_exit(i32 status) {
	register u64 a7 __asm__("a7") = NR_EXIT;
	register i32 a0 __asm__("a0") = status;
	__asm__ __volatile__ ( "syscall 0a0"
		:
		: "r" (a7), "r" (a0)
	);
}

ssize_t sys_gettimeofday(timeval *restrict tv, timezone *restrict tz) {
	register u64       a7 __asm__("a7") = NR_GETTIMEOFDAY;
	register timeval  *a0 __asm__("a0") = tv;
	register timezone *a1 __asm__("a1") = tz;
	ssize_t ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1)
	);
}

clock_t sys_times(tms *t) {
	register u64  a7 __asm__("a7") = NR_TIMES;
	register tms *a0 __asm__("a0") = t;
	clock_t ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0)
	);
	return ret;
}

ssize_t sys_getrandom(char *buf, size_t count, u32 flags) {
	register u64     a7 __asm__("a7") = NR_GETRANDOM;
	register char   *a0 __asm__("a0") = buf;
	register size_t  a1 __asm__("a1") = count;
	register u32     a2 __asm__("a2") = flags;
	i32 ret;
	__asm__ __volatile__ ( "syscall 0a0"
		: "=r" (ret)
		: "r" (a7), "r" (a0), "r" (a1), "r" (a2)
	);
	return ret;
}

#endif // __loongarch__
