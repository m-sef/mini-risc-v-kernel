#include <stdint.h>

#include "io.h"

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
    init_stack_pointers();

    print_string("Dumping kernel stack\n");
    dump_buffer(kernel_stack, STACK_SIZE);

    print_string("Dumping worker stack\n");
    dump_buffer(worker_stack, STACK_SIZE);

    __asm__ volatile ( 
        "lw a0, 0(%[input])\n"
        "call print_word"
        : 
        : [input] "r" (worker_stack)
        : "a0"
    );

    print_string("Switching into worker task...\n");
    context_switch(&kernel_stack_ptr, (uint32_t)worker_stack);
    print_string("... returning from worker task\n");

    print_string("Is everything in working condition?\n");

    return 0;
}