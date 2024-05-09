#ifndef MIN_SYSCALL_H_
#define MIN_SYSCALL_H_ 1
#include "min_def.h"
#include "min_time.h"

#define NR_READ      		((u64)0)
#define NR_WRITE     		((u64)1)
#define NR_EXIT      		((u64)60)
#define NR_TIMES     		((u64)100)
#define NR_TIME      		((u64)201)
#define NR_GETRANDOM 		((u64)318)

#define STDIN_FILENO  		((u32)0x00)
#define STDOUT_FILENO 		((u32)0x01)
#define STDERR_FILENO 		((u32)0x02)

#define GRND_NONBLOCK 		((u32)0x01)
#define GRND_RANDOM   		((u32)0x02)
#define GRND_INSECURE 		((u32)0x04)

i64 sys_read(int fd, void *buf, u64 size);

i64 sys_write(int fd, const void *buf, u64 size);

void sys_exit(i32 status);

clock_t sys_times(tms *t);

time_t sys_time(time_t *tloc);

i64 sys_getrandom(char *buf, u64 count, u32 flags);

#endif
