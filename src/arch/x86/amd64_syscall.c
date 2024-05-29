#ifdef __amd64__
#include "../../../include/min/arch/x86/amd64_syscall.h"

#include "../../../include/min/min_def.h"
// rax rdi rsi rdx r10 r8 r9
// clang-format off

ssize_t sys_read(i32 fd, void *buf, size_t size) {
	register u64         rax __asm__("rax") = NR_READ;
	register i32         rdi __asm__("rdi") = fd;
	register const void *rsi __asm__("rsi") = buf;
	register size_t      rdx __asm__("rdx") = size;
	ssize_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

ssize_t sys_write(i32 fd, const void *buf, size_t size) {
	register u64         rax __asm__("rax") = NR_WRITE;
	register i32         rdi __asm__("rdi") = fd;
	register const void *rsi __asm__("rsi") = buf;
	register size_t      rdx __asm__("rdx") = size;
	ssize_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

void *sys_mmap(void *addr, size_t length, i32 prot,
               i32 flags, i32 fd, i32 off) {
	register u64     rax __asm__("rax") = NR_MMAP;
	register void   *rdi __asm__("rdi") = addr;
	register size_t  rsi __asm__("rsi") = length;
	register i32     rdx __asm__("rdx") = prot;
	register i32     r10 __asm__("r10") = flags;
	register i32     r8  __asm__("r8") = fd;
	register i32     r9  __asm__("r9") = off;
	void *ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx), "r" (r10), "r" (r8), "r" (r9)
		: "rcx", "r11", "memory"
	);
	return ret;
}

ssize_t sys_munmap(void *addr, size_t length) {
	register u64     rax __asm__("rax") = NR_MUNMAP;
	register void   *rdi __asm__("rdi") = addr;
	register size_t  rsi __asm__("rsi") = length;
	ssize_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi)
		: "rcx", "r11", "memory"
	);
	return ret;
}

void *sys_mremap(void *old_addr, size_t old_size,
             size_t new_size, i32 flags, void *new_address) {
	register u64     rax __asm__("rax") = NR_MREMAP;
	register void   *rdi __asm__("rdi") = old_addr;
	register size_t  rsi __asm__("rsi") = old_size;
	register size_t  rdx __asm__("rdx") = new_size;
	register i32     r10 __asm__("r10") = flags;
	register void   *r8  __asm__("r8")  = new_address;
	void *ret;
	if (r8 == nil) {
		__asm__ volatile ( "syscall"
			: "=a" (ret)
			: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx), "r" (r10), "r" (r8)
			: "rcx", "r11", "memory"
		);
	} else {
		__asm__ volatile ( "syscall"
			: "=a" (ret)
			: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx), "r" (r10)
			: "rcx", "r11", "memory"
		);
	}
	return ret;
}

ssize_t sys_socket(i32 domain, i32 type, i32 protocol) {
	register u64 rax __asm__("rax") = NR_SOCKET;
	register i32 rdi __asm__("rdi") = domain;
	register i32 rsi __asm__("rsi") = type;
	register i32 rdx __asm__("rdx") = protocol;
	ssize_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

ssize_t sys_bind(i32 sockfd, sockaddr *my_addr, ssize_t addrlen) {
	register u64       rax __asm__("rax") = NR_SOCKET;
	register i32       rdi __asm__("rdi") = sockfd;
	register sockaddr *rsi __asm__("rsi") = my_addr;
	register ssize_t   rdx __asm__("rdx") = addrlen;
	ssize_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

void sys_exit(i32 status) {
	register u64 rax __asm__("rax") = NR_EXIT;
	register i32 rdi __asm__("rdi") = status;
	__asm__ volatile ( "syscall"
		:
		: "r" (rax), "r" (rdi)
		: "rcx", "r11", "memory"
	);
}

ssize_t sys_gettimeofday(timeval *restrict tv, timezone *restrict tz) {
	register u64       rax __asm__("rax") = NR_GETTIMEOFDAY;
	register timeval  *rdi __asm__("rdi") = tv;
	register timezone *rsi __asm__("rsi") = tz;
	ssize_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi)
		: "rcx", "r11", "memory"
	);
	return 0;
}

clock_t sys_times(tms *t) {
	register u64  rax __asm__("rax") = NR_TIMES;
	register tms *rdi __asm__("rdi") = t;
	clock_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi)
		: "rcx", "r11", "memory"
	);
	return ret;
}

ssize_t sys_getrandom(char *buf, size_t count, u32 flags) {
	register u64     rax __asm__("rax") = NR_GETRANDOM;
	register char   *rdi __asm__("rdi") = buf;
	register size_t  rsi __asm__("rsi") = count;
	register u32     rdx __asm__("rdx") = flags;
	ssize_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

#endif // __amd64__
