#/bin.bash

#Name: Riley Blacklock 885024539
#Email: blacklockriley@csu.fullerton.edu
#Course: CPSC223C Section 04
#Due Date: 10-14-2024, 11:59 PM
#Program Name: File Analysis
#Purpose: Print the contents of a file and sort the lines by length
#Operating System: Ubuntu 22.04 LTS, x86_64 architecture

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile fileanalysis.c"
gcc -c -Wall -std=c17 -o fileanalysis.o -no-pie -fno-pie fileanalysis.c -std=gnu11

echo "Link the object files"
g++ -fno-pie -no-pie -o fileanalysis.out fileanalysis.o -std=c++17

chmod u+x fileanalysis.out

echo "Run the program File Analysis:"
echo "" # Add a newline for better readability
./fileanalysis.out

echo "" # Add a newline for better readability
echo "The script file will terminate"
