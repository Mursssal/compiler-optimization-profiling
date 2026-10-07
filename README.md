# Compiler Optimization & Profiling

A C/Linux project exploring compiler optimization, program profiling, linking, executable layout, and x86-64 assembly.

## Topics

- C header files and modular compilation
- GCC compilation and linking
- `-O0` vs. `-O2` compiler optimization
- Performance profiling with `gprof`
- Executable analysis with `objdump`
- x86-64 assembly
- Dynamic memory management
- Bubble sort and quicksort

## Technologies

- C
- GCC
- Linux
- gprof
- objdump

## Overview

This project compares the performance of sorting algorithms under different compiler optimization levels and examines how compiler optimizations affect the generated machine code.

The project includes:

- `bubbleSort.c` — bubble sort implementation
- `quickSort.c` — quicksort implementation
- `main.c` — program entry point, input handling, array generation, and memory management
- `header.h` — shared function declarations
- `answers.txt` — profiling and executable-analysis results
