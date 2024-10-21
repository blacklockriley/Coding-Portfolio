#/bin/bash

#Name: Riley Blacklock 885024539
#Email: blacklockriley@csu.fullerton.edu
#Course: CPSC223C Section 04
#Date: October 14th, 2024
#Product: Midterm 1
#Program Name: Frequency Table
#Purpose: This program reads a text file and creates a frequency table of the characters in the file.
#Operating System: Ubuntu 22.04 LTS, x86_64 architecture

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile frequencytable.c"
gcc -c -Wall -std=c17 -o frequencytable.o -no-pie -fno-pie frequencytable.c -std=gnu11

echo "Link the object files"
g++ -fno-pie -no-pie -o frequencytable.out frequencytable.o -std=c++17

chmod u+x frequencytable.out

echo "Run the program Frequency Table:"
./frequencytable.out

echo "The script file will terminate"
