#include <stdint.h>

extern void print_string(const char* ptr);
extern void context_switch(uint32_t* old_stack_pointer, uint32_t new_stack_pointer);

uint32_t kernel_stack_pointer;
uint32_t worker_stack_pointer;

#define STACK_SIZE 1024
uint8_t worker_stack[STACK_SIZE] __attribute__((aligned(16)));

static void
worker_task()
{
    print_string("Vile Machinations!\n");
    context_switch(&worker_stack_pointer, kernel_stack_pointer);
}

int main(void)
{
    __asm__(
        "addi sp, sp, -52\n"
        "sw x0, 48(sp)\n"
        "sw x0, 44(sp)\n"
        "sw x0, 40(sp)\n"
        "sw x0, 36(sp)\n"
        "sw x0, 32(sp)\n"
        "sw x0, 28(sp)\n"
        "sw x0, 24(sp)\n"
        "sw x0, 20(sp)\n"
        "sw x0, 16(sp)\n"
        "sw x0, 12(sp)\n"
        "sw x0, 8(sp)\n"
        "sw x0, 4(sp)\n"
        "sw ra, 0(s0)\n"
    );

    print_string("main: switching INTO worker task...\n");
    context_switch(&kernel_stack_pointer, worker_stack_pointer);
    print_string("main: ...back from task. done\n");

    return 0;
}