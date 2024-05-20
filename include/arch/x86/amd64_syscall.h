#ifndef AMD_SYSCALL_H_
#define AMD_SYSCALL_H_ 1
#include "../../min_def.h"
#include "../../min_socket.h"
#include "../../min_time.h"

#define NR_READ          		((u64)0)
#define NR_WRITE         		((u64)1)
#define NR_MMAP          		((u64)9)
#define NR_MUNMAP        		((u64)11)
#define NR_SOCKET        		((u64)41)
#define NR_BIND          		((u64)41)
#define NR_EXIT          		((u64)60)
#define NR_TIMES         		((u64)100)
#define NR_TIME          		((u64)201)
#define NR_GETRANDOM     		((u64)318)

#define EXIT_FAILURE 		((u32)1)
#define EXIT_SUCCESS 		((u32)0)

#define STDIN_FILENO  		((u32)0)
#define STDOUT_FILENO 		((u32)1)
#define STDERR_FILENO 		((u32)2)

#define PROT_READ  		((u32)1)
#define PROT_WRITE 		((u32)2)
#define PROT_EXEC  		((u32)4)
#define PROT_NONE  		((u32)0)

#define MAP_SHARED          		((u32)1)
#define MAP_PRIVATE         		((u32)2)
#define MAP_SHARED_VALIDATE 		((u32)3)
#define MAP_ANONYMOUS       		((u32)32)

#define GRND_NONBLOCK 		((u32)1)
#define GRND_RANDOM   		((u32)2)
#define GRND_INSECURE 		((u32)4)

i64 sys_read(i32 fd, void *buf, u64 size);

i64 sys_write(i32 fd, const void *buf, u64 size);

void *sys_mmap(void *addr, u32 length, i32 prot,
               i32 flags, i32 fd, i32 off);

i32 sys_munmap(void *addr, u32 length);

i32 sys_socket(i32 domain, i32 type, i32 protocol);

i32 sys_bind(i32 sockfd, sockaddr *my_addr, i32 addrlen);

void sys_exit(i32 status);

clock_t sys_times(tms *t);

time_t sys_time(time_t *tloc);

i64 sys_getrandom(char *buf, u64 count, u32 flags);

#endif // AMD_SYSCALL_H_
