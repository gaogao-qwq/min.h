#include "../include/min/min_core.h"

#include "../include/min/min_assert.h"
#include "../include/min/min_stdio.h"
#include "../include/min/min_syscall.h"
// clang-format off

#define BUCKET_CAP ((u32)101)

typedef struct bucket_node {
	void *base;
	size_t size;
	struct bucket_node *next;
	struct bucket_node *prev;
} bucket_node;

typedef struct bucket {
	bucket_node *nodes;
	size_t length;
} bucket;

static bucket buckets[BUCKET_CAP];

u32 _hash(void *base) {
	u32 h = sizeof(void *);
	const char *ptr_str = (const char *)&base;
	size_t i;

	for (i = 0; i < sizeof base; ++i) {
		h = ((h << 5) ^ (h >> 27) ^ ptr_str[i]);
	}
	return h % BUCKET_CAP;
}

bucket_node *_bucket_find(void *ptr) {
	u32 idx = _hash(ptr);
	bucket bucket = buckets[idx];
	bucket_node *p = bucket.nodes;

	if (!bucket.length) {
		return nil;
	}

	while (p) {
		if (p->base == ptr) return p;
		p = p->next;
	}

	return nil;
}

void _bucket_insert(void *start, size_t size) {
	u32 idx = _hash(start);
	bucket *bucket = &buckets[idx];
	bucket_node *p = bucket->nodes;
	bucket_node *new_node = sys_mmap(nil, sizeof(bucket_node),
                                     PROT_READ | PROT_WRITE,
                                     MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	
	new_node->base = start;
	new_node->size = size;
	new_node->next = nil;
	new_node->prev = nil;

	if (!bucket->length) {
		bucket->nodes = new_node;
		++bucket->length;
		return;
	}

	while (p && p->next) {
		p = p->next;
	}

	p->next = new_node;
	p->next->prev = p;
	++bucket->length;
}

ssize_t _bucket_remove(bucket_node *node) {
	if (node == nil) return -1;
	ssize_t res;
	if (node->prev != nil) node->prev->next = node->next;
	if (node->next != nil) node->next->prev = node->prev;
	res = sys_munmap(node, sizeof(bucket_node));
	return res;
}

void bump_alloced_bucket() {
	bucket_node *p;

	min_print("Bumping alloced memories...\n");
	for(size_t i = 0; i < BUCKET_CAP; ++i) {
		if (!buckets[i].length) {
			continue;
		}
		p = buckets[i].nodes;
		while (p) {
			min_printf("[%p] size: %u\n", p->base, p->size);
			p = p->next;
		}
	}
}

void *min_malloc(size_t size) {
	void *p = sys_mmap(nil, size, PROT_READ | PROT_WRITE,
                       MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	if (p == MAP_FAILED) return nil;
	_bucket_insert(p, size);
	return p;
}

void *min_calloc(size_t nmemb, size_t size) {
	size *= nmemb;
	void *p = sys_mmap(nil, size, PROT_READ | PROT_WRITE,
	                   MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
	if (p == MAP_FAILED) return nil;
	for (size_t i = 0; i < size; ++i) {
		(*(char *)p) ^= (*(char *)p);
	}
	_bucket_insert(p, size);
	return p;
}

void *min_realloc(void *ptr, size_t size) {
	u32 idx = _hash(ptr);
	bucket *bucket = &buckets[idx];
	bucket_node *node = _bucket_find(ptr);

	if (node == nil) return nil;
	void *new_address = sys_mremap(ptr, node->size,
                                   size, MREMAP_MAYMOVE, nil);

	if (new_address != ptr) {
		_bucket_remove(node);
		_bucket_insert(new_address, size);
		if (--bucket->length) bucket->nodes = nil;
		ptr = new_address;
	} else {
		node->size = size;
	}

	return new_address;
}

void min_free(void *ptr) {
	if (ptr == nil) return;

	ssize_t res;
	u32 idx = _hash(ptr);
	bucket *bucket = &buckets[idx];
	bucket_node *node = _bucket_find(ptr);
	min_assert(node != nil);

	res = sys_munmap(node->base, node->size);
	min_assert(res == 0);
	res = _bucket_remove(node);
	min_assert(res == 0);

	if (!--bucket->length) buckets[idx].nodes = nil;
}

void min_collect() {}

