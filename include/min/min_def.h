#ifndef MIN_DEF_H_
#define MIN_DEF_H_ 1

#define nil   		((void *)0)
#define true  		((_Bool)1)
#define false 		((_Bool)0)

typedef _Bool                  		bool;
typedef signed char            		i8;
typedef unsigned char          		u8;
typedef signed short int       		i16;
typedef unsigned short int     		u16;
typedef signed int             		i32;
typedef unsigned int           		u32;
typedef float                  		f32;
typedef signed long long int   		i64;
typedef unsigned long long int 		u64;
typedef double                 		f64;

#ifndef __need_size_t
	typedef signed int   ssize_t;
	typedef unsigned int size_t;
	#define SSIZE_MAX    ((ssize_t)2147483647)
	#define SIZE_MAX     ((size_t)4294967295U)
#endif // __need_size_t

#endif // MIN_DEF_H_
