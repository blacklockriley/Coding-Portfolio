#/bin/bash

#Name: Riley Blacklock 885024539
#Email: blacklockriley@csu.fullerton.edu
#Course: CPSC223C Section 04
#Due Date: 9-8-2024, 11:59 PM
#Program Name: Euclidean Triangles
#Purpose: To calculate the area of a triangle using the Euclidean formula
#Operating System: Ubuntu 22.04 LTS, aarch64 architecture

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile trianglemain.c"
gcc -c -Wall -std=c17 -o trianglemain.o -no-pie -fno-pie trianglemain.c -std=gnu11

echo "Link the object files"
g++ -fno-pie -no-pie -o triangle.out trianglemain.o -std=c++17

chmod u+x triangle.out

echo "Run the program Euclidean Triangles:"
./triangle.out

echo "The script file will terminate"
