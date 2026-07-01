#include <stdint.h>

#include "io.h"
#include "memory/permanent_allocator.h"

extern void context_switch(uint32_t* old_stack_ptr, uint32_t new_stack_ptr);

uint32_t kernel_stack_ptr;
uint32_t worker_stack_ptr;

#define STACK_SIZE 1024
uint8_t kernel_stack[STACK_SIZE] __attribute__((aligned(16))) = {0x00};
uint8_t worker_stack[STACK_SIZE] __attribute__((aligned(16))) = {0x00};

static void
worker_task()
{
    print_string("Vile Machinations!\n");
    context_switch(&worker_stack_ptr, kernel_stack_ptr);
}

static inline void
init_stack_pointers()
{
    uint32_t* stack_ptr = (uint32_t*)(kernel_stack + STACK_SIZE);
    kernel_stack_ptr = (uint32_t)stack_ptr;

    stack_ptr = (uint32_t*)(worker_stack + STACK_SIZE);
    worker_stack_ptr = (uint32_t)stack_ptr;

    *((uint32_t*)worker_stack) = (uint32_t)&worker_task;
}

int main(void)
{
    init_permanent_allocator(kernel_stack, STACK_SIZE);
    char* buffer = allocate_permanent_buffer(STACK_SIZE);
    copy_buffer("Vile Machinations!\n", 20, buffer, 64);

    dump_buffer(kernel_stack, STACK_SIZE);

    return 0;
}