cmake_minimum_required(VERSION 3.28.3)
project(kernel LANGUAGES C ASM)

add_executable(kernel
    src/context_switch.s
    src/boot.s
    src/kernel.c
    src/io.c
)

target_link_options(kernel PRIVATE "-T${CMAKE_SOURCE_DIR}/linker.ld")
target_include_directories(kernel PUBLIC ${CMAKE_SOURCE_DIR}/include)