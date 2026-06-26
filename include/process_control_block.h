#ifndef PROCESS_CONTROL_BLOCK_H
#define PROCESS_CONTROL_BLOCK_H

#include <stdint.h>

struct process_control_block {
    uint32_t s11, s10, s9, s8, s7, s6, s5, s4, s3, s2, s1, s0, ra;
};

#endif