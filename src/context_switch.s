.section .test.context_switch
.global context_switch
#==============================================================================
context_switch:
#
# Expects: a0 - Address of old stack pointer
#          a1 - New stack pointer
# Returns: Nothing
#==============================================================================
    sw sp, 0(a0)

    mv sp, a1
    
    ret
