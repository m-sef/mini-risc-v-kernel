#include <stdint.h>

#include "io.h"
#include "process_control_block.h"
#include "physical_memory.h"

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
    struct memory_block* ptr = (struct memory_block*)kernel_stack;
    ptr->in_use = true;
    ptr->end_of_memory = true;
    ptr->size = 0xFF00;
    ptr->next_block = (struct memory_block*)kernel_stack + ptr->size;
    
    dump_buffer(kernel_stack, STACK_SIZE);

    return 0;
}