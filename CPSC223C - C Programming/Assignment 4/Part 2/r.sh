#/bin.bash

#Name: Riley Blacklock 885024539
#Email: blacklockriley@csu.fullerton.edu
#Course: CPSC223C Section 04
#Due Date: 11-4-2024, 12:00 AM
#Program Name: Binary Reader
#Purpose: Convert binary to text
#Operating System: Ubuntu 22.04 LTS, x86_64 architecture

echo "Do a compiler check on scholar.c"

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile scholar.c"
gcc -c -Wall -std=c17 -o scholar.o -no-pie -fno-pie scholar.c -std=gnu11

echo "Link object files"
g++ -fno-pie -no-pie -o scholar.out scholar.o -std=c++17

chmod u+x scholar.out

echo "Execute the program"
./scholar.out
