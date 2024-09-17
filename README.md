This project implements an interpreter for Monty bytecode files. It includes:

monty.h: Header file with struct definitions and function prototypes.
main.c: Main program that reads and executes Monty bytecode files.
opcodehandlers.c: Implements opcode functions (push, pall, pint, pop, swap, add, nop).
helperfunctions.c: Contains utility functions like is_number and free_stack.
bytecodes/: Directory containing sample Monty bytecode files for testing.

Compile with: gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
Usage: ./monty bytecode_file
