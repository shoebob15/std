#pragma once

#include <stdlib.h>


// convenience macros
#define array_header(a) (((array_header_t*)(a) - 1))
#define array_length(a) (array_header(a)->length)
#define array_capacity(a) (array_header(a)->capacity)

// macros
#define array(T) _array_init(sizeof(T), 16) // T = type of array (int, float, etc.)

#define append(a, i) ( \
    (a) = _array_ensure_capacity((a), 1, sizeof(i)), \
    (a)[array_header(a)->length] = (*i), \
    &(a)[array_header(a)->length++] \
)

#define array_remove(a, i) do { \
    array_header_t *h = array_header(a); \
    if (i == h->length - 1) { \
        h->length--; \
    } else { \
        h->length -= 1; \
        void* elem = &a[i]; \
        void* last = &a[h->length - 1]; \
        memcpy(elem, last, sizeof(*elem)); \
    } \
} while (0);

typedef struct {
    size_t length;
    size_t capacity;
} array_header_t;

// initializes an empty array and returns a pointer to the memory
void* _array_init(size_t item_size, size_t capacity);

// grow array if not big enough
void* _array_ensure_capacity(void *a, size_t item_count, size_t item_size);
