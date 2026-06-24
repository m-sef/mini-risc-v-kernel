#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ELF=$SCRIPT_DIR/../build/kernel

gdb() {
    qemu-system-riscv32 -machine virt -nographic -bios none -serial mon:stdio -kernel $ELF -s -S

    exit 0
}

qemu-system-riscv32 -machine virt -nographic -bios none -serial mon:stdio -kernel $ELF

exit 0
