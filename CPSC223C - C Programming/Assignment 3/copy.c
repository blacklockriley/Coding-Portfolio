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
#include <stdlib.h> // Standard library
#include <string.h> // String library

#define MAX_LINE_LENGTH 1024 // Define the maximum line length

int copy(FILE *myfile, char *arrayparameter[], int maxsize) {
  char buffer[MAX_LINE_LENGTH]; // Declare a buffer to store the line
  int lineCount = 0; // Declare an integer to store the number of lines

  while (
      fgets(buffer, MAX_LINE_LENGTH, myfile) &&
      lineCount <
          maxsize) { // Allocate memory for the line and copy the buffer content
    arrayparameter[lineCount] =
        (char *)malloc(strlen(buffer) + 1); // Allocate memory for the line
    if (arrayparameter[lineCount] ==
        NULL) { // Check if the memory allocation failed
      perror("Error allocating memory"); // Print an error message
      return -1;                          // Indicate an error
    }
    strcpy(arrayparameter[lineCount],
           buffer); // Copy the buffer content to the line
    lineCount++;    // Increment the line count
  }

  return lineCount; // Return the number of lines
}
