S3K - Simple Secure Separation Kernel
=====================================

S3K is a capability-based separation kernel targetting embedded RISC-V systems.

Documentation
-------------

| Page | Description |
| --- | --- |
| [Home](https://github.com/kth-step/s3k/wiki)                  | Documentation Index |
| [S3K Design](https://github.com/kth-step/s3k/wiki/S3K-Design) | High-level design of S3K |
| [S3K Implementation](https://github.com/kth-step/s3k/wiki/S3K-Implementation) | Description of S3K implementation |
| [S3K API](https://github.com/kth-step/s3k/wiki/S3K-API)       | User-level Kernel API |

More documenation will be added.

Configuration
-------------

Compiler toolchain is defined in `cross/*.mk`.

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

Requirements
------------

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

Repository structure
--------------------

- kernel - The kernel source code.
  - src - C and assembly files
  - inc - Header files
  - linker.ld - Linker script
  - Makefile - Kernel's makefile
  - s3k_conf.h - Default kernel configuration
- lib - Kernel API
- examples - Example projects using the kernel
  - hello - Hello, world example with two processes
- LICENSE - MIT License file
- tools.mk - Set the compiler tools here
