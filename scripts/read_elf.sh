#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
ELF=$SCRIPT_DIR/../build/kernel

riscv64-unknown-elf-readelf -h $ELF

exit 0