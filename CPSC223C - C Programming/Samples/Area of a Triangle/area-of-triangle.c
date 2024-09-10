//****************************************************************************************************************************
//Program name: "Basic Triangular Geometry Dual Language Version".  This program demonstrates how to compute the area of a   *
//planar triangle given the length of two sides and the size of the angle between them.  Copyright (C) 2021 Floyd Holliday   *
//                                                                                                                           *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  *
//version 3 as published by the Free Software Foundation.                                                                    *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied         *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     *
//A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                           *
//****************************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2

//Author: Floyd Holliday
//Contact: holliday@fullerton.edu

//Program name: Basic Triangular Geometry Dual Language Version

//Date development begun: December 22, 2021
//Date of last upgrade:   December 27, 2021
//Development platform:  Linux Xubuntu platform

//Application purpose: Given the lengths of two sides of a triangle and the measure of the include angle compute the 
//area of the triangle.

//Educational purpose 1: Learn how to view the activation record of the currently executing function and the activation 
//record of the caller function.

//Educational purpose 2: Learn how to create a program containing function written in both C and C++ languages.

//Compile: gcc -c -Wall -std=c17 -o triangle.o -m64 -no-pie -fno-pie area-of-triangle.c
//Link: g++ -m64 -fno-pie -no-pie -o area.out triangle.o surface.o


//======== Begin source code ==========

#include "stdio.h"     //Provides access to printf and scanf
#include <math.h>

extern double compute_area(double,double,double);   //<== Prototype of function to be called by function main

int main(int argc, char* argv[])    //<== Function header for main.
{double side1;
 double side2;
 double angle_degrees;
 double area_triangle;

 printf("Welcome to Basic Triangular Geometry\n");
 printf("This program will compute any area\n\n");

 printf("Please enter three float numbers: side 1, side 2, and included angle in degrees with ws separating each number\n");
 printf("After the last number is entered press <enter>\n");
 printf("Reminder: Enter the numbers carefully because there is no error checking.  The sum of angles in a planar\n");
 printf("triangle is 180 degrees; therefore, an input of 190 for one angle is not part of a valid triangle.\n");

 scanf("%lf%lf%lf",&side1,&side2,&angle_degrees);

 printf("You entered side 1: %5.5lf, side 2: %5.5lf, angle: %5.5lf\n",side1,side2,angle_degrees);

 area_triangle = compute_area(side1,side2,angle_degrees);

 printf("The area of a triangle with sides %6.5lf and %6.5lf and included angle %6.5lf is %10.8lf square units.\n",side1,side2,angle_degrees,area_triangle);

 printf("We hope you liked your geometry.  Please come back again.\n");
 printf("Now an integer zero will be returned to the operating system.  Bye.\n");

 return 0;
}//End of main
