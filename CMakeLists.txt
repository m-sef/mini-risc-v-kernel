cmake_minimum_required(VERSION 3.28.3)
project(kernel LANGUAGES C ASM)

add_executable(kernel
    src/boot.s
    src/kernel.c
)

target_link_options(kernel PRIVATE "-T${CMAKE_SOURCE_DIR}/linker.ld")