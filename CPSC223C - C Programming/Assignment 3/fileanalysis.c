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

#include "copy.c" // Include the copy function from the copy.c file
#include "show.c" // Include the show function from the show.c file
#include "sort.c" // Include the sort function from the sort.c file

int main(int argc, char *argv[]) {

  // Introduce the user to the program and prompt the user for the file name.
  printf(
      "Welcome to File Analysis brought to you by Riley Blacklock.\n"); // Introduction
  printf("Please enter the name of a file residing in the same directory where "
         "this program is running: "); // Prompt the user to enter a file name

  // Read the file name from the user
  char filename[100];    // Declare a character array to store the file name
  scanf("%s", filename); // Read the file name from the user

  // Open the file in read mode
  FILE *file = fopen(filename, "r"); // Open the file in read mode
  if (file == NULL) {                // Check if the file does not exist
    printf("The file does not exist. Please run the program again and enter "
           "the title carefully.\n"); // Print an error message
    return 1;                         // Exit the program
  }

  // Copy the contents of the file into a string array
  printf(
      "Thank you. This will be copied to an internal array of strings.\n"); // Inform the user that the contents of the file will be copied
  char *lines[MAX_LINE_LENGTH]; // Declare a string array to store the lines
  int lineCount = copy(
      file, lines,
      MAX_LINE_LENGTH); // Copy the contents of the file into the string array
  if (lineCount <= 0) { // Check if the file is empty
    fclose(file);       // Close the file
    printf("The file is empty. Please run the program again and enter a file "
           "with content.\n"); // Print an error message
    return 1;                  // Exit the program
  }
  printf("The copy operation has finished.\n"); // Inform the user that the copy operation has finished

    // Print the contents of the file
    printf("Here are the data stored in the array.\n\n"); // Print a message
    show(lines, lineCount); // Print the contents of the file

    // Sort the lines by length
    printf("\nThe data in the array will sorted next according to length of lines\n"); // Print a message
    sortbubble(lines, lineCount); // Sort the lines by length

    // Print the sorted contents of the file
    printf("The sorting has finished.  Here are the contents of the main array.\n\n"); // Print a message
    show(lines, lineCount); // Print the sorted contents of the file

    // Free up space in the array
    printf("\nThis program will conclude by freeing the space occupied by each row of the main array.\n"); // Print a message
    for (int i = 0; i < lineCount; i++) { // Loop through the lines
        free(lines[i]); // Free up space in the array
        lines[i] = NULL; // Set the line to NULL
    }
    
    // Print the contents of the file after freeing up space
    printf("The space has now been recovered.   The following show the contents of the array after recovery of space.\n\n"); // Print a message
    show(lines, lineCount); // Print the contents of the file

    // Terminate the program
    printf("\nThis program will now terminate by sending a zero to the operating system.\nBye.");
    return 0;
}