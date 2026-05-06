S3K - Simple Secure Separation Kernel
=====================================

S3K is a capability-based separation kernel targetting RISC-V embedded systems.\
This repository contains a re-implementation of S3K-v1 in the Barocq programming language.

Configuration
-------------

Compiler toolchain is defined in `cross/*.ini`.

Requirements
------------

- The Barocq compiler
- [RISC-V GNU Toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain) 
  - We recommend that you clone the repository and build the toolchains as follows:
    ```
    ./configure --prefix=/opt/riscv --enable-multilib
    sudo make
    ```
    This puts `riscv64-unknown-elf-*` tools in `/opt/riscv/bin`.
  - You should then add `/opt/riscv/bin` to the `PATH` variable, e.g., `PATH=/opt/riscv/bin:$PATH`.
  - You can make the toolchain user only by setting `--prefix=$HOME/.opt/riscv` and `PATH=$HOME/.opt/riscv/bin:$PATH`.
    Then you do not need to build the toolchain with `sudo`.
- QEMU System RISC-V - Build or install QEMU with RISC-V.
  - You should have `qemu-system-riscv64` installed to execute the projects using QEMU.

Build and Run
-------------

For building and running the `hello` project with `meson` and `ninja`:
```bash
# Setup the project in builddir
meson setup builddir examples/hello --cross-file cross/gcc-rv64imac.ini
# Compile the project
ninja -C builddir
# Run the project using QEMU
ninja -C builddir qemu
```
