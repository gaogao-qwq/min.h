#ifndef ALGO_H_
#define ALGO_H_
#include "min_core.h"

#ifdef NOSTDLIB_BUILD
#define RNSEED_LEN 4
#endif

typedef i32 (*compar_t) (const void *, const void *);

/**
 *	@brief This function do what you expected it to do
 */
void min_swap(void *a, void *b, u32 size);

/**
 *	@brief The glibc bsearch implementation
 *	@param key		- pointer to the element to search for
 *	@param base		- pointer to the array to examine
 *	@param nmemb	- number of element in the array
 *	@param size		- size of each element in the array in bytes
 *	@param compar	- comparison function which returns a negative integer
 *					  value if the first argument is less than the second,
 *					  a positive integer value if the first argument is
 *					  greater than the second and zero if the arguments
 *					  are equivalent.
 *					  key is passed as the first argument, an element
 *					  from the array as the second.
 *	@return 		- Pointer to an element in the array that compares equal
 *					  to *key, or null pointer if such element has not been found.
 *
 *	The signature of the comparison function should be equivalent to the following:
 *	`int cmp(const void *a, const void *b);`
 */
void *min_bsearch(const void *key, const void *base,
            	  u32 nmemb, u32 size, compar_t compar);

/**
 *	@brief A simple 3-way-qsort implementation
 *	@param base		- pointer to the array to sort
 *	@param nmemb	- number of elements in the array
 *	@param size		- size of each element in the array in bytes
 *	@param compar	- comparison function which returns a negative
 *					  integer value if the first argument is less than the second,
 *					  a positive integer value if the first argument is greater
 *					  than the second and zero if the arguments are equivalent.
 *	TODO: Use heap sort as fallback
 */
void min_qsort(void *base, u32 nmemb, u32 size,
			   compar_t compar);

#endif
