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

//Compile: g++ -c -Wall -std=c++17 -m64 -no-pie -fno-pie -o surface.o area.cpp
//Link: g++ -m64 -fno-pie -no-pie -o area.out triangle.o surface.o


//Terminology used in the source code of function compute_area
//"ar" means activation record, a segment of memory assigned to a function for its use.
//"current ar" means the ar belonging to the currently executing function
//"previous ar" means the ar of function that called the currently executing function.
//"backend" of an ar is the quadword of an ar with the highest address among all quadwords of that ar.
//"frontend" of an ar is the quadword of an ar with the lowest address among all quadwords of that ar.


//======== Begin source code ==========

#include "stdio.h"     //Provides access to printf and scanf
#include "math.h"

extern "C" double compute_area(double s1,double s2,double phi);

//The next variables are declared in global scope.  The practice of declaring data in global scope should
//always be avoided except in rare cases where there is no alternative technique available.  Here the global
//variable are used solely a vehicles from transferring data from data in the registers to variables in the program.
long unsigned int current_ar_frontend_global;
long unsigned int current_ar_backend_global;
long unsigned int previous_ar_backend_global;

double compute_area(double s1,double s2,double phi)
{const double pi = 3.14159;
 double area;
 long unsigned int c; //loop counting variable

 area = 0.5 * s1 * s2 * sin(phi * pi / 180.0);
// printf("area = %lf\n",area);  //<==Debug statement.

 //Obtain the addresses of current ar frontend, current ar backend, previous ar frontend, and previous ar backend.
 //Declare local variables to hold the front and back addresses of
 long unsigned int curr_ar_frontend;
 long unsigned int curr_ar_backend;
 long unsigned int prev_ar_frontend;
 long unsigned int prev_ar_backend;

 //Block of assembly statement to retrieve 3 numbers from the cpu.
 // asm(".intel_syntax noprefix");
 // asm("mov current_ar_frontend_global,rsp");
 // asm("mov current_ar_backend_global,rbp");
 // asm("mov rax,[rbp]");
 // asm("mov previous_ar_backend_global,rax");
 // asm(".att_syntax noprefix");                //Set the mode back to ATT which is the original default.

 //Block of statements to copy values from global variables to local variables.
 curr_ar_frontend = current_ar_frontend_global;
 curr_ar_backend = current_ar_backend_global;
 prev_ar_frontend = curr_ar_backend+8;
 prev_ar_backend = previous_ar_backend_global;

//Debug block.  This block can be deleted.
// printf("curr_ar_frontend = 0x%016lx\n",curr_ar_frontend);
// printf("curr_ar_backend  = 0x%016lx\n",curr_ar_backend);
// printf("prev_ar_frontend = 0x%016lx\n",prev_ar_frontend);
// printf("prev_ar_backend  = 0x%016lx\n",prev_ar_backend);

 //Compute the number of quadwords in each of the two activation records.
 long unsigned int number_qwords_current_ar = (curr_ar_backend - curr_ar_frontend)/8+1;
 long unsigned int number_qwords_previous_ar = (prev_ar_backend - prev_ar_frontend)/8+1;

 //Show all the quadwords in the activation record of function main.
 long unsigned int * r = (long unsigned int *)prev_ar_backend;
 printf("Dump of activation record of function main\n       Address             Data\n");
 for(c=number_qwords_previous_ar;c>0;c--)
      {printf("%2ld  0x%016lx   0x%016lx\n",c-1,(long unsigned int)r,*r);
       r--;
      }
 printf("\n");

 //Show all the quadwords in the activation record of function compute_area.
 r = (long unsigned int *)curr_ar_backend;
 printf("Dump of activation record of function compute_area\n       Address             Data\n");
 for(c=number_qwords_current_ar;c>0;c--)
      {printf("%2ld  0x%016lx   0x%016lx\n",c-1,(long unsigned int)r,*r);
       r--;
      }
 printf("\n");

 return area;
}//End of compute_area
