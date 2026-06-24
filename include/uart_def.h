#ifndef UART_DEF_H
#define UART_DEF_H

#define UART_ADDR 0x10000000 /* Universal Asynchronous Receiver-Transmitter (UART) Address */

#define UART_WRITE(ch) *(volatile char*)UART_ADDR = ch
#define UART_READ *(volatile char*)UART_ADDR

#endif