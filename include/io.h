#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <stddef.h>

void print_char(char ch);
char read_char();

void print_byte(uint8_t byte);
void print_word(uint32_t word);
void print_uint(uint32_t word);

void print_string(const char* buffer);

void dump_buffer(const uint8_t* buffer, size_t size);

#

#endif