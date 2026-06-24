#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ELF=$SCRIPT_DIR/../build/kernel

riscv64-unknown-elf-objdump -d $ELF

exit 0