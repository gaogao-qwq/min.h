#ifdef __amd64__
#include "../../../include/arch/x86/amd64_syscall.h"
#include "../../../include/min_def.h"
// rax rdi rsi rdx r10 r8 r9

i64 sys_read(i32 fd, void *buf, u64 size) {
	register u64         rax __asm__("rax") = NR_READ;
	register i32         rdi __asm__("rdi") = fd;
	register const void *rsi __asm__("rsi") = buf;
	register u64         rdx __asm__("rdx") = size;
	i64 ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

i64 sys_write(i32 fd, const void *buf, u64 size) {
	register u64         rax __asm__("rax") = NR_WRITE;
	register i32         rdi __asm__("rdi") = fd;
	register const void *rsi __asm__("rsi") = buf;
	register u64         rdx __asm__("rdx") = size;
	i64 ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

void *sys_mmap(void *addr, u32 length, i32 prot,
               i32 flags, i32 fd, i32 off) {
	register u64   rax __asm__("rax") = NR_MMAP;
	register void *rdi __asm__("rdi") = addr;
	register u32   rsi __asm__("rsi") = length;
	register i32   rdx __asm__("rdx") = prot;
	register i32   r10 __asm__("r10") = flags;
	register i32   r8  __asm__("r8") = fd;
	register i32   r9  __asm__("r9") = off;
	void *ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx), "r" (r10), "r" (r8), "r" (r9)
		: "rcx", "r11", "memory"
	);
	return ret;
}

i32 sys_munmap(void *addr, u32 length) {
	register u64   rax __asm__("rax") = NR_MUNMAP;
	register void *rdi __asm__("rdi") = addr;
	register u32   rsi __asm__("rsi") = length;
	i32 ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi)
		: "rcx", "r11", "memory"
	);
	return ret;
}

i32 sys_socket(i32 domain, i32 type, i32 protocol) {
	register u64 rax __asm__("rax") = NR_SOCKET;
	register i32 rdi __asm__("rdi") = domain;
	register i32 rsi __asm__("rsi") = type;
	register i32 rdx __asm__("rdx") = protocol;
	i32 ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

i32 sys_bind(i32 sockfd, sockaddr *my_addr, i32 addrlen) {
	register u64       rax __asm__("rax") = NR_SOCKET;
	register i32       rdi __asm__("rdi") = sockfd;
	register sockaddr *rsi __asm__("rsi") = my_addr;
	register i32       rdx __asm__("rdx") = addrlen;
	i32 ret;
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

time_t sys_time(time_t *tloc) {
	register u64     rax __asm__("rax") = NR_TIME;
	register time_t *rdi __asm__("rdi") = tloc;
	time_t ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi)
		: "rcx", "r11", "memory"
	);
	return ret;
}

i64 sys_getrandom(char *buf, u64 count, u32 flags) {
	register u64   rax __asm__("rax") = NR_GETRANDOM;
	register char *rdi __asm__("rdi") = buf;
	register u64   rsi __asm__("rsi") = count;
	register u32   rdx __asm__("rdx") = flags;
	i64 ret;
	__asm__ volatile ( "syscall"
		: "=a" (ret)
		: "r" (rax), "r" (rdi), "r" (rsi), "r" (rdx)
		: "rcx", "r11", "memory"
	);
	return ret;
}

#endif // __amd64__
