// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 9-22-2024, 11:59 PM
// Program Name: Tokenizer
// Purpose: Separates a string into tokens based on a delimiter
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 9 - 19 - 2024
// Date of last upgrade: 9 - 22 - 2024

#include <stdio.h>  // For printf, fopen, fseek, ftell, fread, fclose, fgets
#include <stdlib.h> // For malloc, realloc

char* file2string(char* filename) {
    // 1. Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    // 2. Obtain the number of bytes in the file
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // 3. Declare a string of sufficient size to hold all the chars in the file
    char* buffer = (char*)malloc(length + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    // 4. Copy the bytes from the file into the string array character by character
    size_t total_length = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        size_t line_length = strlen(line);
        if (total_length + line_length >= length) {
            length *= 2;
            char* new_buffer = (char*)realloc(buffer, length + 1);
            if (new_buffer == NULL) {
                perror("Failed to reallocate memory");
                free(buffer);
                fclose(file);
                return NULL;
            }
            buffer = new_buffer;
        }
        strcpy(buffer + total_length, line);
        total_length += line_length;
    }

    // 5. Ensure the string array terminates with a null character
    buffer[total_length] = '\0';

    // 6. Close the file
    fclose(file);

    // Return the string
    return buffer;
}
