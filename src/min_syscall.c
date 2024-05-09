#include "../include/min_syscall.h"

i64 sys_read(int fd, void *buf, u64 size) {
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

