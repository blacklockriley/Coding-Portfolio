// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 11-4-2024, 12:00 AM
// Program Name: Binary Reader
// Purpose: Convert binary to text
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 11-3-2024
// Date of last upgrade: 11-3-2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

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
    printf("Welcome to Read Academic Data\n");

    char inputFileName[50];
    printf("Please enter the name of the binary file: ");
    scanf("%s", inputFileName);
    printf("You entered %s\n\n", inputFileName);

    FILE *inputFile = fopen(inputFileName, "rb");

    if (!inputFile) {
        perror("Error opening file");
        return 1;
    }

    Student student;

    while (fread(&student, sizeof(Student), 1, inputFile)) {
        printf("name = %s\n", student.name);
        printf("cwid = %u\n", student.cwid);
        printf("major = %s\n", student.major);
        printf("Class level = %s\n", classStandingToString(student.classStanding));
        printf("phone = %lu\n", student.phone);
        printf("parking fee = %.2f\n", student.parkingFee);
        printf("zip = %u\n", student.zipCode);
        printf("\n");
    }

    fclose(inputFile);

    printf("The binary file was read successfully.\n");
    printf("Bye\n");

    return 0;
}
