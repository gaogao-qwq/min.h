#ifndef LOONGARCH64_SYSCALL_H_
#define LOONGARCH64_SYSCALL_H_ 1
#include "../../min_def.h"
#include "../../min_socket.h"
#include "../../min_time.h"
// clang-format off

#define NR_READ         		((u64)63)
#define NR_WRITE        		((u64)64)
#define NR_EXIT         		((u64)93)
#define NR_TIMES        		((u64)153)
#define NR_GETTIMEOFDAY 		((u64)169)
#define NR_SOCKET       		((u64)198)
#define NR_BIND         		((u64)200)
#define NR_BRK          		((u64)214)
#define NR_MUNMAP       		((u64)215)
#define NR_MREMAP       		((u64)216)
#define NR_MMAP         		((u64)222)
#define NR_GETRANDOM    		((u64)278)

#ifndef _STDLIB_H
	#define EXIT_FAILURE 		((u32)1)
	#define EXIT_SUCCESS 		((u32)0)
#endif

#ifndef _UNISTD_H
	#define STDIN_FILENO  		((u32)0)
	#define STDOUT_FILENO 		((u32)1)
	#define STDERR_FILENO 		((u32)2)
#endif

#ifndef _SYS_MMAN_H
	#define PROT_READ  		((u32)1)
	#define PROT_WRITE 		((u32)2)
	#define PROT_EXEC  		((u32)4)
	#define PROT_NONE  		((u32)0)

	#define MAP_SHARED          		((u32)1)
	#define MAP_PRIVATE         		((u32)2)
	#define MAP_SHARED_VALIDATE 		((u32)3)
	#define MAP_ANONYMOUS       		((u32)32)

	#define MREMAP_MAYMOVE   		1
	#define MREMAP_FIXED     		2
	#define MREMAP_DONTUNMAP 		4

	#define MAP_FAILED 		((void *) -1)
#endif

#ifndef _SYS_RANDOM_H
	#define GRND_NONBLOCK 		((u32)1)
	#define GRND_RANDOM   		((u32)2)
	#define GRND_INSECURE 		((u32)4)
#endif

ssize_t sys_read(i32 fd, void *buf, size_t size);

ssize_t sys_write(i32 fd, const void *buf, size_t size);

void *sys_mmap(void *addr, size_t length, i32 prot,
               i32 flags, i32 fd, i32 off);

ssize_t sys_munmap(void *addr, size_t length);

ssize_t sys_brk(void *addr);

void *sys_mremap(void *old_addr, size_t old_size,
             size_t new_size, i32 flags, void *new_address);

ssize_t sys_socket(i32 domain, i32 type, i32 protocol);

ssize_t sys_bind(i32 sockfd, sockaddr *my_addr, ssize_t addrlen);

void sys_exit(i32 status);

ssize_t sys_gettimeofday(timeval *restrict tv, timezone *restrict tz);

clock_t sys_times(tms *t);

ssize_t sys_getrandom(char *buf, size_t count, u32 flags);

#endif // LOONGARCH64_SYSCALL_H_
