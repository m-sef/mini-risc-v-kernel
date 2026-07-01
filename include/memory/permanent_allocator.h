#ifndef PERMANENT_ALLOCATOR_H
#define PERMANENT_ALLOCATOR_H

#include <stddef.h>

void init_permanent_allocator(void* start_address, size_t size);
void* allocate_permanent_buffer(size_t size);

#endif