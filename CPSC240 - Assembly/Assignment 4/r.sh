#!/bin/bash

# Remove old object files and executables
rm -f multipletest.o multipletest

# Compile the C file
gcc -o multipletest multipletest.c

# Run the executable
./multipletest