extern void print_string(const char* ptr);
extern void context_switch(unsigned int* old_stack_pointer, unsigned int new_stack_pointer);

unsigned int task_a_stack_pointer;
unsigned int task_b_stack_pointer;

#define PROCESS_STACK_SIZE 1024

static void
task_a()
{
    print_string("Process A\n");
    context_switch(&task_a_stack_pointer, task_b_stack_pointer);
}

static void
task_b()
{
    print_string("Process B\n");
}

int main(void)
{
    task_a();

    return 0;
}