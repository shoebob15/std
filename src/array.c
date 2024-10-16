#include "array.h"

#include <string.h>

void* _array_init(size_t item_size, size_t capacity) {
    void* ptr = 0;

    size_t size = item_size * capacity; // size of the array in bytes
    array_header_t* header = malloc(size); // allocate memory for the array

    if (header) {
        header->length = 0;
        header->capacity = capacity;
        ptr = header + 1; // set the pointer to the first element of the array
    }

    return ptr;
}

void* _array_ensure_capacity(void *a, size_t item_count, size_t item_size) {
    array_header_t* h = array_header(a);
    size_t required_capacity = h->length + item_count;

    // if the array is not large enough, reallocate memory
    if (h->capacity < required_capacity) {
        size_t new_capacity = h->capacity * 2;

        while (new_capacity < required_capacity) {
            new_capacity *= 2;
        }

        size_t new_size = sizeof(&h) + new_capacity * item_size;
        array_header_t* new_h = malloc(new_size);

        if (new_h) {
            size_t old_size = sizeof(&h) + h->capacity * item_size;

            memcpy(new_h, h, old_size);

            free(h);

            new_h->capacity = new_capacity;
            h = new_h + 1;
        } else {
            h = 0; // blow up
        }
    } else {
        h = h + 1;
    }

    return h;
}
