S3K - Simple Secure Separation Kernel
=====================================

S3K is a capability-based separation kernel targetting RISC-V embedded systems.\
This repository contains a re-implementation of [S3Kv1](https://github.com/HAKarlsson/s3k-c) in the [Barocq programming language](https://gitlab.inria.fr/cchavano/barocq).

Requirements
------------

- The build system is [Meson](https://mesonbuild.com/) + [Ninja](https://ninja-build.org/)
- [The Barocq compiler](https://gitlab.inria.fr/cchavano/barocq/-/tree/riscv64?ref_type=heads#riscv64) compiled with CompCert-rv64-linux
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

First, setup the project:

```sh
./setup
```
To compile S3K, run the following `ninja` command:

```sh
ninja -C build/kernel
```

This command places the kernel elf file at `build/kernel/s3k.elf`.

To run the Hello world example, you can use the `hello-world` script:

```sh
./hello-world
```
