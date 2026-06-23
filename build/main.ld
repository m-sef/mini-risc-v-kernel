ENTRY(_start)
SECTIONS
{
    . = 0x80000000;
    .text : ALIGN(4)
    {
        *(.text.init)
        *(.text .text.*)
    }

    .data : ALIGN(4)
    {
        *(.data .data.*)
    }
    . = ALIGN(16);  /* ABI states sp has to be 16-byte aligned */

    . += 0x1000;    /* 4 KB memory region for stack */
    _stack_top = .; /* Creates _stack_top symbol */
}