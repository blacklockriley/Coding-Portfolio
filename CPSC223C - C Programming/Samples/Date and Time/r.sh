#/bin/bash

#Program: Date and Time
#Author: F. Holliday

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile current-time.c"
gcc -c -Wall -no-pie -o current-time.o current-time.c -std=gnu11
#Note the uncommon standard "GNU of 2011"

echo "Link the object files"
gcc -no-pie -o current.out current-time.o -std=gnu11

#Make sure the executable has permission to execute
chmod u+x current.out

echo "Run the program Date and Time:"
./current.out

echo "The script file will terminate"
