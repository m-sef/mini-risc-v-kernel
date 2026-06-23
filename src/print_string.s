.include "../src/uart_def.s"

#==============================================================================
.macro m_print_string message
# Prints a null terminated string
# Expects: message - Raw string
# Returns: Nothing
#==============================================================================
.section .rodata 
1: .string "\message"
.section .text
    la a0, 1b
    call printString
.endm

.section .text.print_string
.global print_string
#==============================================================================
print_string:
# Prints a null terminated string
# Expects: a0 - Address of null terminated string
# Returns: Nothing
#==============================================================================
    li t0, UART_ADDR
    mv t1, a0

    j condition
jump:
    sb t2, (t0)
    addi t1, t1, 1
condition:
    lb t2, 0(t1)
    bnez t2, jump

    ret
