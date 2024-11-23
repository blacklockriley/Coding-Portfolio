// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 11-25-2024, 12:00 AM
// Program Name: Academic File Management System
// Purpose: Access student information from a random access file
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 11-23-2024
// Date of last upgrade: 11-24-2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void greetUser() {
    printf("Hello! Welcome to the Academic File Management System.\n");
}

void displayDeveloperInfo() {
    printf("This program was developed by Riley Blacklock.\n");
}

void displayWelcomeMessage() {
    printf("We hope you enjoy using this file management system.\n");
}

void displayMenu() {
    printf("\nMenu of Choices:\n");
    printf("A = Add a new student\n");
    printf("D = Delete an existing student\n");
    printf("S = Show all students in the file\n");
    printf("F = Find a student\n");
    printf("X = Exit from this program\n");
}

void addStudent(FILE *file) {
    Student student;
    char confirm;

    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter CWID: ");
    scanf("%u", &student.cwid);
    printf("Enter major: ");
    scanf("%s", student.major);
    printf("Enter class standing (0=Freshman, 1=Sophomore, 2=Junior, 3=Senior): ");
    scanf("%u", (unsigned int*)&student.classStanding);
    printf("Enter phone number: ");
    scanf("%lu", &student.phone);
    printf("Enter parking fee: ");
    scanf("%f", &student.parkingFee);
    printf("Enter zip code: ");
    scanf("%u", &student.zipCode);

    printf("Enter 'C' to confirm and submit the student information: ");
    scanf(" %c", &confirm);

    if (confirm == 'C' || confirm == 'c') {
        fseek(file, 0, SEEK_END);
        fwrite(&student, sizeof(Student), 1, file);
        printf("Student added successfully.\n");
    } else {
        printf("Student information not submitted.\n");
    }
}

void displayAllStudents(FILE *file) {
    Student student;
    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.cwid != 0) {
            printf("Name: %s, CWID: %u, Major: %s, Class Standing: %d, Phone: %lu, Parking Fee: %.2f, Zip Code: %u\n",
                   student.name, student.cwid, student.major, student.classStanding, student.phone, student.parkingFee, student.zipCode);
        }
    }
}

void findStudent(FILE *file) {
    unsigned int cwid;
    printf("Enter CWID of the student to find: ");
    scanf("%u", &cwid);

    Student student;
    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.cwid == cwid) {
            printf("Name: %s, CWID: %u, Major: %s, Class Standing: %d, Phone: %lu, Parking Fee: %.2f, Zip Code: %u\n",
                   student.name, student.cwid, student.major, student.classStanding, student.phone, student.parkingFee, student.zipCode);
            return;
        }
    }
    printf("Student with CWID %u not found.\n", cwid);
}

void deleteStudent(FILE *file) {
    int position;
    printf("Enter the position of the student to delete: ");
    while (scanf("%d", &position) != 1 || position < 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '\n'); // clear the input buffer
    }

    fseek(file, position * sizeof(Student), SEEK_SET);
    Student student;
    if (fread(&student, sizeof(Student), 1, file) == 1 && student.cwid != 0) {
        student.cwid = 0;
        fseek(file, position * sizeof(Student), SEEK_SET);
        fwrite(&student, sizeof(Student), 1, file);
        printf("Student at position %d deleted successfully.\n", position);
    } else {
        printf("No valid student found at position %d. Please try again.\n", position);
    }
}

int main() {
    greetUser();
    displayDeveloperInfo();
    displayWelcomeMessage();

    FILE *file = fopen("academic.bin", "wb+");
    if (!file) {
        perror("Failed to create file");
        return EXIT_FAILURE;
    }

    char choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                addStudent(file);
                break;
            case 'D':
                deleteStudent(file);
                break;
            case 'S':
                displayAllStudents(file);
                break;
            case 'F':
                findStudent(file);
                break;
            case 'X':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'X');

    fclose(file);
    return EXIT_SUCCESS;
}