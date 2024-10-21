// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 10-14-2024, 11:59 PM
// Program Name: File Analysis
// Purpose: Print the contents of a file and sort the lines by length
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 10-12-2024
// Date of last upgrade: 10-14-2024

#include <stdio.h>  // Standard input/output library
#include <string.h> // String library

int sortbubble(char *arrayparameter[],
               int howmany_strings) { // Function to sort the lines by length
  for (int i = 0; i < howmany_strings - 1; i++) { // Loop through the lines
    for (int j = 0; j < howmany_strings - i - 1; j++) {
      if (strlen(arrayparameter[j]) >
          strlen(arrayparameter[j + 1])) { // Compare the lengths of the lines
        char *temp = arrayparameter[j]; // Put the line in a temporary variable
        arrayparameter[j] = arrayparameter[j + 1]; // Swap the lines
        arrayparameter[j + 1] =
            temp; // Take the line from the temporary variable
      }
    }
  }
  return 0; // End the function
}