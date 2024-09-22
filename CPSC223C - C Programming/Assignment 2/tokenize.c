// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 9-22-2024, 11:59 PM
// Program Name: Tokenizer
// Purpose: Separates a string into tokens based on a delimiter
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 9 - 19 - 2024
// Date of last upgrade: 9 - 22 - 2024

#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc
#include <string.h> // For strtok

#include "file2string.c" // For file2string

int main(int argc, char *argv[]) {

  printf("Welcome to Epic Software Systems, Inc. Head of Systems Lab: Henry "
         "Gonzalez\n"); // Print a welcome message
  printf("Enter the name of a file to be tokanized: "); // Prompt the user to
                                                        // enter the filename
  char filename[80];     // Declare a buffer to hold the filename
  scanf("%s", filename); // Read the filename from the user
  getchar();             // Consume the newline character

  char *file2string(char *filename); // Declare the function prototype
  char *string =
      file2string(filename); // Call the function to read the file into a string
  if (string == NULL) {      // Check if the function failed
    printf("Failed to read file\n"); // Print an error message
    return 1;                        // Exit the program
  }

  printf("%s\n", string); // Print the contents of the file
  printf(
      "%ld characters were read from the file into an array of the program.\n",
      strlen(string)); // Print the number of characters read

  printf("Enter the separator characters which may include white space and "
         "press enter:"); // Prompt the user to enter the delimiter(s)
  char delimiters[80];    // Declare a buffer to hold the delimiter
  fgets(delimiters, sizeof(delimiters),
        stdin); // Read the delimiter(s) from the user
  delimiters[strcspn(delimiters, "\n")] =
      '\0'; // Remove the newline character at the end
  printf("\nConfirmation: These are the separators => %s\n",
         delimiters); // Print the delimiter(s)

  printf("Here is the complete list of tokens:\n");
  char *token = strtok(string, delimiters); // Tokenize the string
  int token_number = 0;   // Declare a variable to hold the token number
  while (token != NULL) { // Loop through each token
    printf("Token %d: %s\n", token_number, token); // Print the token
    token = strtok(NULL, delimiters);               // Get the next token
    token_number++;                                // Increment the token number
  }

  printf("\nThe total number of tokens is %d\n",
         token_number);             // Print the total number of tokens
  printf("Have a nice evening.\n"); // Print a closing message
  free(string);                     // Free the memory allocated for the string

  return 0;
}
