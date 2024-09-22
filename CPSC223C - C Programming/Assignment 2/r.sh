#/bin/bash

#Name: Riley Blacklock 885024539
#Email: blacklockriley@csu.fullerton.edu
#Course: CPSC223C Section 04
#Due Date: 9-22-2024, 11:59 PM
#Program Name: Tokenizer
#Purpose: Separates a string into tokens based on a delimiter
#Operating System: Ubuntu 22.04 LTS, x86_64 architecture

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile tokenize.c"
gcc -c -Wall -std=c17 -o tokenize.o -no-pie -fno-pie tokenize.c -std=gnu11

echo "Link the object files"
g++ -fno-pie -no-pie -o tokenizer.out tokenize.o -std=c++17

chmod u+x tokenizer.out

echo "Run the program Tokenizer:"
./tokenizer.out

echo "The script file will terminate"
