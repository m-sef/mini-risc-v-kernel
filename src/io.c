#include "io.h"

#include "uart_def.h"

static const char hex_ascii_lookup[16] = "0123456789ABCDEF";
static const char dec_ascii_lookup[10] = "0123456789";

void
print_char(
        char ch)
{
    *(volatile char*)UART_ADDR = ch;
}

char
read_char()
{
    uint8_t temp = *(volatile char*)(UART_ADDR + 5);

    while ((temp & 0x01) == 0) { temp = *(volatile char*)(UART_ADDR + 5); };

    return UART_READ;
}

void
print_byte(
        uint8_t byte)
{
    UART_WRITE(hex_ascii_lookup[(byte & 0xF0) >> 4]);
    UART_WRITE(hex_ascii_lookup[ byte & 0x0F]);
}

void
print_word(
        uint32_t word)
{
    UART_WRITE(hex_ascii_lookup[(word & 0xF0000000) >> 28]);
    UART_WRITE(hex_ascii_lookup[(word & 0x0F000000) >> 24]);
    UART_WRITE(hex_ascii_lookup[(word & 0x00F00000) >> 20]);
    UART_WRITE(hex_ascii_lookup[(word & 0x000F0000) >> 16]);
    UART_WRITE(hex_ascii_lookup[(word & 0x0000F000) >> 12]);
    UART_WRITE(hex_ascii_lookup[(word & 0x00000F00) >> 8]);
    UART_WRITE(hex_ascii_lookup[(word & 0x000000F0) >> 4]);
    UART_WRITE(hex_ascii_lookup[ word & 0x0000000F]);
}

void
print_uint(
        uint32_t word)
{

}

void
print_string(
        const char* buffer)
{
    char* ptr = buffer;

    while (*ptr != 0x00)
    {
        *(volatile char*)UART_ADDR = *ptr;

        ptr++;
    }
}