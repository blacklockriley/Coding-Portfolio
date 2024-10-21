#!/bin/bash

# Remove old object files and executables
rm -f paritysimulation.o paritysimulation

# Compile the C file
gcc -o paritysimulation paritysimulation.c

# Run the executable
./paritysimulation