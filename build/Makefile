CC=riscv64-unknown-elf-gcc
CCFLAGS=-march=rv32im -mabi=ilp32 -nostdlib -ffreestanding -fno-stack-protector -msmall-data-limit=0 -Wall -Wextra -g -O3
RM=rm

all: main

main: ../src/boot.s
	$(CC) $(CCFLAGS) -T main.ld ../src/boot.s ../src/kernel.c -o kernel.elf

clean:
	$(RM) *.elf