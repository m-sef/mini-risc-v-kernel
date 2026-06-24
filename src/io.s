#==============================================================================
# Author(s): m-sef (https://github.com/m-sef)
# Collection of macros and functions for printing via UART
#==============================================================================
.include "../src/uart_def.s"

#==============================================================================
.macro m_print_char char
# Prints a single character
# Expects: char - Character (word)
# Returns: Nothing
#==============================================================================
.section .text
    la a0, \char
    call print_char
.endm

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
    call print_string
.endm

.section .text.print_char
.global print_char
#==============================================================================
print_char:
# Prints a single character
# Expects: a0 - Character
# Returns: Nothing
#==============================================================================
    li t0, UART_ADDR
    sb a0, (t0)
    ret

.section .text.read_char
.global read_char
#==============================================================================
read_char:
# Reads a single character (blocking)
# Expects: Nothing
# Returns: a0 - Character received
#==============================================================================
    li t0, UART_ADDR
wait:
    lb t1, 5(t0)
    andi t1, t1, 0x01 
    beqz t1, wait
    lb a0, 0(t0)
    ret

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
    lb t2, (t1)
    bnez t2, jump

    ret
