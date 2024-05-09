#ifndef MIN_TIME_H_
#define MIN_TIME_H_

typedef long int time_t;
typedef long int clock_t;

typedef struct {
	clock_t tms_utime;  /* user time */
	clock_t tms_stime;  /* system time */
	clock_t tms_cutime; /* user time of children */
	clock_t tms_cstime; /* system time of children */
} tms;

#endif
