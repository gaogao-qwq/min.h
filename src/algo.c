#include "../include/algo.h"

#ifdef NOSTDLIB_BUILD
static char buf[RNSEED_LEN];
#endif

void min_swap(void *a, void *b, u32 size) {
	if (a == b) return;
	char *p = a, *q = b;
	for (u32 i = 0; i < size; ++i) {
		if (p[i] == q[i]) continue;
		p[i] ^= q[i];
		q[i] ^= p[i];
		p[i] ^= q[i];
	}
}

void *min_bsearch(const void *key, const void *base,
				  u32 nmemb, u32 size,
				  compar_t compar) {
	u32 l, u, idx;
	const void *p;
	i32 comparison;

	l = 0;
	u = nmemb;
	while (l < u) {
		idx = (l + u) / 2;
		p = (const void *) (((const char *) base) + (idx * size));
		comparison = (*compar) (key, p);
		if (comparison < 0)
			u = idx;
		else if (comparison > 0)
			l = idx + 1;
		else
			return (void *) p;
	}

	return nil;
}

void min_qsort(void *base, u32 nmemb, u32 size,
			   compar_t compar) {
	// End point of recursion
	if (nmemb <= 1) return;
	u32 rn;
	char pivot[size];

#ifdef NOSTDLIB_BUILD
	// Get random bytes and cast first 4bytes of it to u32
	i32 res = sys_getrandom(buf, RNSEED_LEN, GRND_NONBLOCK);
	if (res == -1) return;
	rn = *((u32 *)buf) % nmemb;
	// Copy pivot from base
	min_memcpy(pivot, base + rn * size, size);
#else
	/* Use stdlib rand() */
	srand(time(nil));
	rn = (u32)rand() % nmemb;
	// Use memcpy
	memcpy(pivot, base + rn * size, size);
#endif

	// idx: index of current operating element
	// base[0:j): elements less than pivot
	// base[k:nmemb): elements greater than pivot
	i32 i = 0, j = 0, k = nmemb;
	while (i < k) {
		if (compar(base + i * size, pivot) < 0) {
			// If base[i] is less than pivot, swap base[i], base[j] and increment i, j
			min_swap(base + i * size, base + j * size, size);
			++i, ++j;
		} else if (compar(base + i * size, pivot) > 0) {
			// If base[i] is greater than pivot, swap base[i], base[k-1] and decrement k
			min_swap(base + i * size, base + (k - 1) * size, size);
			--k;
		} else {
			// If base[i] is equal to pivot, ++i
			++i;
		}
	}
	// recursive sort arr[0:j) and arr[k:nmemb-k)
	min_qsort(base, j, size, compar);
	min_qsort(base + k * size, nmemb - k, size, compar);
}
