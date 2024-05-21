#ifndef MIN_TIME_H_
#define MIN_TIME_H_
#include "min_def.h"

#ifndef _STDLIB_H
	typedef i32 time_t;
	typedef i32 suseconds_t;
	typedef u32 useconds_t;
	typedef i32 clock_t;

	typedef struct timeval {
		time_t      tv_sec;   /* Seconds */
		suseconds_t tv_usec;  /* Microseconds */
	} timeval;

	typedef struct timezone {
		i32 tz_minuteswest;
		i32 tz_dsttime;
	} timezone;

	typedef struct {
		clock_t tms_utime;  /* user time */
		clock_t tms_stime;  /* system time */
		clock_t tms_cutime; /* user time of children */
		clock_t tms_cstime; /* system time of children */
	} tms;
#endif // _STDLIB_H

#endif // MIN_TIME_H_
