#include "memory/permanent_allocator.h"

#include "stdbool.h"

#include "io.h"

static void* available_address;
static void* last_address;

void
init_permanent_allocator(
        void* start_address, 
        size_t size)
{
    available_address = start_address;
    last_address      = start_address + size;
}

void*
allocate_permanent_buffer(
        size_t size)
{
    if (available_address + size > last_address)
        while (true)
            print_string("[FATAL ERROR] PERMANENT ALLOCATOR: OUT OF MEMORY\n");
    
    void* new_buffer   = available_address;
    available_address += size;
    return new_buffer;
}