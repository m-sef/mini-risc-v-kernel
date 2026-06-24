#include <stdint.h>

#include "io.h"

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
    print_string("god@device:~> Mini Kernel v0.0.0\n");
    print_string("usr@device:~> ");

    char ch = 0x00;
    while (ch != 0x03)
    {
        ch = read_char();

        if (ch == 0x0D)
        {
            print_string("\nusr@device:~> ");
            continue;
        }

        print_char(ch);
    }

    //context_switch(&kernel_stack_pointer, worker_stack_pointer);
    //print_string("main: ...back from task. done\n");

    return 0;
}