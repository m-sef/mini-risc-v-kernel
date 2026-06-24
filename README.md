# mini-risc-v-kernel

```bash
sudo apt-get install -y gcc-riscv64-unknown-elf
```

```bash
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/riscv-toolchain.cmake
```