#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ELF=$SCRIPT_DIR/../build/kernel.elf

riscv64-unknown-elf-readelf -s $ELF

exit 0