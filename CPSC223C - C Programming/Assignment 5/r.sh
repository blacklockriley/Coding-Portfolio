#/bin.bash

#Name: Riley Blacklock 885024539
#Email: blacklockriley@csu.fullerton.edu
#Course: CPSC223C Section 04
#Due Date: 11-25-2024, 12:00 AM
#Program Name: Academic File Management System
#Purpose: Access student information from a random access file
#Operating System: Ubuntu 22.04 LTS, x86_64 architecture

echo "Do a compiler check on main.c"

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile main.c"
gcc -c -Wall -std=c17 -o main.o -no-pie -fno-pie main.c -std=gnu11

echo "Link object files"
g++ -fno-pie -no-pie -o main.out main.o -std=c++17

chmod u+x main.out

echo "Execute the program"
./main.out

# End of script
