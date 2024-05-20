#ifdef __aarch64__
#include "../../../include/arch/arm/aarch64_syscall.h"
#include "../../../include/min_def.h"
// x8 x0 x1 x2 x3 x4 x5

i64 sys_read(i32 fd, void *buf, u64 size) {
	register u64   r7 __asm__("r7") = NR_READ;
	register i32   r0 __asm__("r0") = fd;
	register void *r1 __asm__("r1") = buf;
	register u32   r2 __asm__("r2") = size;
	i64 ret;
	__asm__ __volatile__ ("syscall 0x0"
		: "=a" (ret)
		: "r" (r7), "r" (r0), "r" (r1), "r" (r2)
	);
	return ret
}

i64 sys_write(i32 fd, const void *buf, u64 size) {
	register u64         r7 __asm__("r7") = NR_WRITE;
	register i32         r0 __asm__("r0") = fd;
	const register void *r1 __asm__("r1") = buf;
	register u32         r2 __asm__("r2") = size;
	__asm__ __volatile__ ("syscall 0x0"
		: "=a" (ret)
		: "r" (r7), "r" (r0), "r" (r1), "r" (r2)
	);
	return ret
}

void *sys_mmap(void *addr, u32 length, i32 prot,
               i32 flags, i32 fd, i32 off) {
	register u64   r7 __asm__("r7") = NR_MMAP;
	register void *r0 __asm__("r0") = addr;
	register u32   r1 __asm__("r1") = length;
	register i32   r2 __asm__("r2") = prot;
	register i32   r3 __asm__("r3") = flags;
	register i32   r4 __asm__("r4") = fd;
	register i32   r5 __asm__("r5") = off;
	void *ret;
	__asm__ __volatile__ ("syscall 0x0"
		: "=a" (ret)
		: "r" (r7), "r" (r0), "r" (r1), "r" (r2), "r" (r3), "r" (r4), "r" (r5)
	);
	return ret;
}

i32 sys_munmap(void *addr, u32 length) {
	register u64   r7 __asm__("r7") = NR_MUNMAP;
	register void *r0 __asm__("r0") = addr;
	register u32   r1 __asm__("r1") = length;
	i32 ret;
	__asm__ __volatile__ ("syscall 0x0"
		: "=a" (ret)
		: "r" (r7), "r" (r0), "r" (r1)
	);
	return ret;
}

i32 sys_socket(i32 domain, i32 type, i32 protocol) {
	register u64 r7 __asm__("r7") = NR_SOCKET;
	register i32 r0 __asm__("r0") = domain;
	register i32 r1 __asm__("r1") = type;
	register i32 r2 __asm__("r2") = protocol;
	i32 ret;
	__asm__ __volatile__ ( "syscall 0x0"
		: "=a" (ret)
		: "r" (r7), "r" (r0), "r" (r1), "r" (r2)
	);
	return ret;
}

i32 sys_bind(i32 sockfd, sockaddr *my_addr, i32 addrlen) {
	register u64       r7 __asm__("r7") = NR_SOCKET;
	register i32       r0 __asm__("r0") = sockfd;
	register sockaddr *r1 __asm__("r1") = my_addr;
	register i32       r2 __asm__("r2") = addrlen;
	i32 ret;
	__asm__ __volatile__ ( "syscall 0x0"
		: "=a" (ret)
		: "r" (r7), "r" (r0), "r" (r1), "r" (r2)
	);
	return ret;
}

void sys_exit(i32 status) {
	register u64 r7 __asm__("r7") = NR_EXIT;
	register i32 r0 __asm__("r0") = status;
	__asm__ __volatile__ ( "syscall 0x0"
		:
		: "r" (r7), "r" (r0)
	);
}

clock_t sys_times(tms *t) {
	register u64  r7 __asm__("r7") = NR_TIMES;
	register tms *r0 __asm__("r0") = t;
	clock_t ret;
	__asm__ __volatile__ ( "syscall 0x0 "
		: "=a" (ret)
		: "r" (r7), "r" (r0)
	);
	return ret;
}

i64 sys_getrandom(char *buf, u64 count, u32 flags) {
	register u64   r7 __asm__("r7") = NR_GETRANDOM;
	register char *r0 __asm__("r0") = buf;
	register u64   r1 __asm__("r1") = count;
	register u32   r2 __asm__("r2") = flags;
	i64 ret;
	__asm__ __volatile__ ( "syscall 0x0"
		: "=a" (ret)
		: "r" (r7), "r" (r0), "r" (r1), "r" (r2)
	);
	return ret;
}

#endif // __aarch64__
