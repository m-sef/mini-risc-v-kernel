#ifndef PHYSICAL_MEMORY_H
#define PHYSICAL_MEMORY_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct memory_block {
    bool in_use;
    bool end_of_memory;
    size_t size;
    struct memory_block* previous_block __attribute__((aligned(8)));
    struct memory_block* next_block;
} __attribute__((packed));

extern struct memory_block* last_memory_block;

#endif