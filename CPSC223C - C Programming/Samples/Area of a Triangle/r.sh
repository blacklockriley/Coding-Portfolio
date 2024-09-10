#/bin/bash          #<== That is the first line of every bash file.

#Author: F. Holliday
#Author email: holliday@fullerton.edu

#Program name: Basic triangular geometry


echo "Remove old un-needed files, if any exist."
rm *.o
rm *.out

echo "Compile the C main function area-of-triangle.c according to C standard 2017"
gcc -c -Wall -std=c17 -o triangle.o -no-pie -fno-pie area-of-triangle.c

echo "Compile the called function area.cpp according to C++ standard 2017."
#The standard for compilation has been omitted intentionally.  This needs more research.
g++ -c -Wall -std=c++17 -no-pie -fno-pie -o surface.o area.cpp

echo "Link object files"
g++ -fno-pie -no-pie -o area.out triangle.o surface.o                         #-std=c++17

echo "Run the program \"Basic triangular geometry\""
./area.out

echo "The bash file has terminated."
