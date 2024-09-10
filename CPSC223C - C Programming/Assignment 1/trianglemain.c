// Name : Riley Blacklock 885024539
// Email : blacklockriley @csu.fullerton.edu
// Course : CPSC223C Section 04
// Due Date : 9 - 8 - 2024, 11 : 59 PM
// Program Name : Euclidean Triangles
// Purpose : To calculate the area of a triangle using the Euclidean formula
// Operating System : Ubuntu 22.04 LTS, aarch64 architecture

// Date development begun: 8 - 28 - 2024
// Date of last upgrade: 8 - 28 - 2024

#include <ctype.h>    // For tolower
#include <math.h>     // For sin, cos, and sqrt
#include <stdio.h>    // For printf and scanf
#include <stdlib.h>   // For malloc
#include <sys/time.h> // For struct tm
#include <time.h>     // For time

int main(int argc, char *argv[]) {
  double side1;
  double side2;
  double side3;
  double angle;
  double area;

  printf("Welcome to Euclidean Triangles\n");
  printf("This software was built by and maintained by Computer Science "
         "Student Riley Blacklock.\n");

  time_t current_time;
  current_time = time(NULL); // Get the current time.

  char buffer[80];
  struct tm *broken = localtime(&current_time);
  if (broken == NULL)
    printf("A call to function localtime failed.\n");
  else {
    strftime(buffer, sizeof(buffer), "Today is %B %d, %Y at %I:%M%p.",
             broken); // Convert the time into a string
    for (char *p = buffer + 20; *p; ++p)
      *p = tolower(*p);     // Convert the string to lowercase
    printf("%s\n", buffer); // Print the time
  }

  printf("The number of seconds since the Great Epoch is %lu\n", current_time);
  printf("This program will manage all your triangles.\n");
  printf("Enter a float number for each quantity first side, second side, and "
         "angle in degrees between those two sides.   Separate each quantity "
         "by ws.  After the third quantity press enter.\n");

  scanf("%lf%lf%lf", &side1, &side2, &angle); // Get the user input.

  if (side1 <= 0 || side2 <= 0 || angle <= 0 ||
      angle >= 180) { // Check if the input is valid.
    printf("You entered %5.5lf, %5.5lf, and %5.5lf.\n", side1, side2, angle);
    printf("There are invalid data among the inputs.  Please run this program "
           "again\n");
  } else {
    printf(
        "You entered %5.5lf and %5.5lf for sides and %5.5lf for the angle.\n",
        side1, side2, angle);
    area = 0.5 * side1 * side2 *
           sin(angle * 3.1459 / 180.0); // Calculate the area of the triangle.
    printf("The area of this triangle is %5.5lf square units.\n",
           area); // Print the area of the triangle.
    side3 = sqrt(pow(side1, 2) + pow(side2, 2) -
                 2 * side1 * side2 *
                     cos(angle * 3.1459 /
                         180.0)); // Calculate the third side of the triangle.
    printf("The length of the third side of the triangle is %5.5lf linear "
           "units.\n",
           side3);             // Print the third side of the triangle.
    current_time = time(NULL); // Get the current time, again.
    printf(
        "The elapsed time since the Great Epoch is %lu seconds.\n",
        current_time); // Print the elapsed time since the Great Epoch, again.
  }
  printf("Have a nice day.\n");
  printf("An integer 0 will be sent to the operating system as a signal of "
         "successful execution.  Bye.\n");

  return 0;
}
