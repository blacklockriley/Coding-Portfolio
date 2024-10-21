// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Date: October 14th, 2024
// Product: Midterm 1
// Program Name: Frequency Table
// Purpose: This program reads a text file and creates a frequency table of the
// characters in the file. Operating System: Ubuntu 22.04 LTS, x86_64
// architecture

// Date development begun: 10 - 14 - 2024
// Date of last upgrade: 10 - 14 - 2024

#include <stdio.h>  // For printf, fopen, fseek, ftell, fread, fclose, fgets
#include <stdlib.h> // For malloc, realloc

int main(int argc, char *argv[]) {
  char filename[100]; // Declare a buffer to hold the filename
  FILE *file;         // Declare a file pointer
  char *buffer;       // Declare a buffer to hold the file contents
  long file_size;     // Declare a variable to hold the file size
  int frequency[256] = {
      0}; // Declare an array to hold the frequency of each character

  // The program asks the user to input the name of a local text file.
  printf("Enter the name of a text file: "); // Prompt the user to enter the
                                             // filename
  scanf("%s", filename);                     // Read the filename from the user

  // The program opens the file and reads its contents into a buffer.
  file = fopen(filename, "r");     // Open the file for reading
  if (file == NULL) {              // Check if the file failed to open
    perror("Failed to open file"); // Print an error message
    return 1;                      // Exit the program
  }

  // Obtain the number of bytes in the file
  fseek(file, 0, SEEK_END); // Move the file pointer to the end of the file
  file_size = ftell(file);  // Get the position of the file pointer
  fseek(file, 0,
        SEEK_SET); // Move the file pointer back to the beginning of the file

  // Allocate memory for the buffer
  buffer = (char *)malloc(file_size + 1); // Allocate memory for the buffer
  if (buffer == NULL) { // Check if the memory allocation failed
    perror("Failed to allocate memory"); // Print an error message
    fclose(file);                        // Close the file
    return 1;                            // Exit the program
  }

  // Read the contents of the file into the buffer
  fread(buffer, 1, file_size,
        file);              // Read the contents of the file into the buffer
  buffer[file_size] = '\0'; // Null-terminate the buffer

  // Close the file
  fclose(file); // Close the file

  // The program creates a frequency table of the characters in the file.
  for (long i = 0; i < file_size;
       i++) {                    // Loop through each character in the buffer
    unsigned char c = buffer[i]; // Get the character at index i
    frequency[c]++;              // Increment the frequency of the character
  }

  // Free the memory allocated for the buffer
  free(buffer); // Free the memory allocated for the buffer

  // The program displays the frequency table.
  printf("ASCII Frequency Table:\n"); // Print the header of the frequency table
  for (int i = 0; i < 256; i++) {     // Loop through each ASCII character
    if (frequency[i] > 0) {
      if (i == '\n') {
        printf("%d \\n %d\n", i,
               frequency[i]); // Print the newline character and its frequency
      } else if (i == '\t') {
        printf("%d \\t %d\n", i,
               frequency[i]); // Print the tab character and its frequency
      } else {
        printf("%d %c %d\n", i, i,
               frequency[i]); // Print the character and its frequency
      }
    }
  }

  // Sort the frequency table in reverse order
  struct Frequency {
    int ascii;       // The ASCII value of the character
    int frequency;   // The frequency of the character
  } freq_table[256]; // Declare an array to hold the frequency table

  int freq_count = 0; // Declare a variable to hold the number of characters
                      // with non-zero frequency
  for (int i = 0; i < 256; i++) { // Loop through each ASCII character
    if (frequency[i] > 0) { // Check if the character has a non-zero frequency
      freq_table[freq_count].ascii =
          i; // Store the ASCII value of the character
      freq_table[freq_count].frequency =
          frequency[i]; // Store the frequency of the character
      freq_count++;     // Increment the number of characters with non-zero
                        // frequency
    }
  }

  // Sort the frequency table in descending order of frequency
  for (int i = 0; i < freq_count - 1;
       i++) { // Loop through each character in the frequency table
    for (int j = i + 1; j < freq_count;
         j++) { // Loop through each character after the current character
      if (freq_table[i].frequency <
          freq_table[j]
              .frequency) { // Check if the frequency of the current character
                            // is less than the frequency of the next character
        struct Frequency temp =
            freq_table[i]; // Swap the current character with the next character
        freq_table[i] = freq_table[j];
        freq_table[j] = temp;
      }
    }
  }

  // Display the sorted frequency table
  printf("\nSorted ASCII Frequency Table:\n");
  for (int i = 0; i < freq_count;
       i++) { // Loop through each character in the frequency table
    if (freq_table[i].ascii == '\n') {
      printf("%d \\n %d\n", freq_table[i].ascii,
             freq_table[i]
                 .frequency); // Print the newline character and its frequency
    } else if (freq_table[i].ascii == '\t') {
      printf(
          "%d \\t %d\n", freq_table[i].ascii,
          freq_table[i].frequency); // Print the tab character and its frequency
    } else {
      printf("%d %c %d\n", freq_table[i].ascii, freq_table[i].ascii,
             freq_table[i].frequency); // Print the character and its frequency
    }
  }

  // Farewell message
  printf("\nThank you for using the Frequency Table program!\n");

  return 0; // Exit the program
}