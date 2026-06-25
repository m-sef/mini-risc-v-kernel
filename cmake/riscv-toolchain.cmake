set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR riscv)

set(TOOLCHAIN_PREFIX "riscv64-unknown-elf-")

set(CMAKE_C_COMPILER   "${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PREFIX}gcc")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(RISCV_FLAGS "-march=rv32imac -mabi=ilp32 -nostdlib -ffreestanding -fno-stack-protector -msmall-data-limit=0 -Wall -Wextra -g -O0")

set(CMAKE_C_FLAGS   "${RISCV_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_ASM_FLAGS "${RISCV_FLAGS}" CACHE STRING "" FORCE)