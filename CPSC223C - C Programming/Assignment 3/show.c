// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 10-14-2024, 11:59 PM
// Program Name: File Analysis
// Purpose: Print the contents of a file and sort the lines by length
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 10-12-2024
// Date of last upgrade: 10-14-2024

#include <stdio.h> // Standard input/output library

int show(char *arrayparameter[],
         int howmany_strings) { // Function to print the contents of the file
  for (int i = 0; i < howmany_strings; i++) { // Loop through the lines
    if (arrayparameter[i] != NULL) {   // Check if the pointer is not NULL
      printf("%s", arrayparameter[i]); // Print the line
    } else {                           // If the pointer is NULL
      printf("\n");                    // Print a blank line
    }
  }
  return 0; // End the function
}