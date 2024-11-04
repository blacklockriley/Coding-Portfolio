// Name: Riley Blacklock 885024539
// Email: blacklockriley@csu.fullerton.edu
// Course: CPSC223C Section 04
// Due Date: 11-4-2024, 12:00 AM
// Program Name: Binary Reader
// Purpose: Convert binary to text
// Operating System: Ubuntu 22.04 LTS, x86_64 architecture

// Date development begun: 11-3-2024
// Date of last upgrade: 11-3-2024

#ifndef STUDENT_H
#define STUDENT_H

typedef enum {
    Freshman,
    Sophomore,
    Junior,
    Senior
} ClassStanding;

typedef struct {
    char name[50];
    unsigned int cwid;
    char major[50];
    ClassStanding classStanding;
    unsigned long int phone;
    float parkingFee;
    unsigned int zipCode;
} Student;

#endif // STUDENT_H