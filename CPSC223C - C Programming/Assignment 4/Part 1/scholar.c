// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 11-4-2024, 12:00 AM
// Program Name: Text to Binary Conversion
// Purpose: Convert text to binary
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 11-3-2024
// Date of last upgrade: 11-3-2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

ClassStanding stringToClassStanding(const char* str) {
    if (strcmp(str, "Freshman") == 0) return Freshman;
    if (strcmp(str, "Sophomore") == 0) return Sophomore;
    if (strcmp(str, "Junior") == 0) return Junior;
    if (strcmp(str, "Senior") == 0) return Senior;
    fprintf(stderr, "Invalid class standing: %s\n", str);
    exit(1);
}

const char* classStandingToString(ClassStanding classStanding) {
    switch (classStanding) {
        case Freshman: return "freshman";
        case Sophomore: return "sophomore";
        case Junior: return "junior";
        case Senior: return "senior";
        default: return "unknown";
    }
}

int main() {
    printf("Welcome to Manage Academic Data\n");

    char inputFileName[50];
    printf("Please enter the name of the text file: ");
    scanf("%s", inputFileName);
    printf("You entered %s\n", inputFileName);

    char outputFileName[50];
    strncpy(outputFileName, inputFileName, strlen(inputFileName) - 4);
    outputFileName[strlen(inputFileName) - 4] = '\0';
    strcat(outputFileName, ".bin");
    printf("The output file name is %s\n\n", outputFileName);

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (!inputFile || !outputFile) {
        perror("Error opening file");
        return 1;
    }

    Student student;
    char line[100];

    while (fgets(student.name, sizeof(student.name), inputFile)) {
        student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline character
        fscanf(inputFile, "%u\n", &student.cwid);
        fgets(student.major, sizeof(student.major), inputFile);
        student.major[strcspn(student.major, "\n")] = '\0'; // Remove newline character
        fgets(line, sizeof(line), inputFile);
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        student.classStanding = stringToClassStanding(line);
        fscanf(inputFile, "%lu\n", &student.phone);
        fscanf(inputFile, "%f\n", &student.parkingFee);
        fscanf(inputFile, "%u\n", &student.zipCode);

        printf("name = %s\n", student.name);
        printf("cwid = %u\n", student.cwid);
        printf("major = %s\n", student.major);
        printf("Class level = %s\n", classStandingToString(student.classStanding));
        printf("zip = %u\n", student.zipCode);
        printf("\n");

        fwrite(&student, sizeof(Student), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("The binary file was created.\n");
    printf("Bye\n");

    return 0;
}
