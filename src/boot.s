#.include "../src/io.s"
#.include "../src/context_switch.s"

.section .text.init
.global _start
#==============================================================================
_start:
# Kernel entry point
#==============================================================================
    la sp, _stack_top
    call main
loop:
    j loop
