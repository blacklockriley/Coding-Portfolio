//****************************************************************************************************************************
//Program name: "Date and Time".  This program demonstrates multiple techniques of extracting the date and the time from an  *
//operating system and how to display those value in standard output. Copyright (C) 2019, 2021 Floyd Holliday                *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  *
//version 3 as published by the Free Software Foundation.                                                                    *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied         *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     *
//A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                           *
//****************************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
//
//Author information
//  Author name: Floyd Holliday
//  Author email: holliday@fullerton.edu
//
//Program information
//  Program name: Date and Time
//  Programming languages: One module in C and one module in X86
//  Date program began: 2019-Jan-05
//  Date of last update: 2019-Jan-05
//  Date of reorganization of comments: 2019-Nov-08.
//  Date of clarification of terms within comments: 2021-Dec-30.
//  Files in this program: current-time.c
//  Status: There are no user inputs.  The program performs correctly.
//
//References for this program
//  Kernighan and Ritchie, The C Programming Language, Second Edition, Appendix B10.
//
//Purpose
//  Show how to display the date and time in multiple formats.
//
//This file
//   File name: current-time.c
//   Language: C
//   Max page width: 132 columns
//   Compile: gcc -c -Wall -m64 -no-pie -o current-time.o current-time.c -std=gnu11
//   Link: gcc -m64 -no-pie -o current.out current-time.o date_and_time.o -std=gnu11
//   Optimal print specification: 132 columns width, 7 points, monospace, 8½x11 paper
//
//References for this file
//   zetcode.com/articles/cddatetime
//   stackoverflow.com/questions/7960318/math-to-convert-seconds-since-1970-into-date-and-vice-versa
//
//
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**
//
//
//
//
//===== Begin code area ================================================================================================

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>   //For malloc

//At the time of this writing C17 is the newest available standard for C language.  Most modern C compilers 
//conform to the C17 standard.  The GNU compiler, known as gcc, is C17 compliant.  If both languages, C and x86,
//are C17 compliant then object code files from the C compiler and from the NASM assembler may be linked together. 
//
int main(int argc, char* argv[])
{//There is one physical clock in the computer, which outputs tics at a given frequency often measured in 
 //units GHz.  However, there are multiple ways to view and interface with that physical clock.  Here are 
 //names of views of the same clock located inside the central microprocessor. 
 // CLOCK_REALTIME
 // CLOCK_MONOTONIC_COARSE
 // CLOCK_MONOTONIC
 // CLOCK_PROCESS_CPUTIME_ID
 // CLOCK_THREAD_CPUTIME_ID
 //The resolution of a clock is the reciprocal of its frequency, and is usually expressed in nanoseconds (ns).  
 //For example, if the frequency is 500 MHz, then the resolution is 1sec/5000000000tics = 2 ns/tic, and we say 
 //the resolution is 2 ns (2 nanoseconds).  Current day software does not support a time unit smaller than 1 ns, 
 //therefore, if a clock has a true resolution something less than 1 ns, then software like this program will 
 //report the resolution to be simply 1 (ns).

 //Obtain the resolution of the first two clocks in the list given above.
 struct timespec * resolution = malloc(sizeof(struct timespec));
 int success;
 success = clock_getres(CLOCK_REALTIME,resolution);
 if(success == -1)
     printf("An error occurred in the call to clock_getres.n");
 else if (success == 0)
     printf("CLOCK_REALTIME has resolution %lu ns.\n",(*resolution).tv_nsec);
 else
     printf("Unknown error in obtaining resolution");

 //Obtain the resolution of the second of four clocks
 success = clock_getres(CLOCK_MONOTONIC_COARSE,resolution);
 if(success == -1)
     printf("An error occurred in the call to clock_getres.n");
 else if (success == 0)
     printf("CLOCK_MONOTONIC_COARSE has resolution %lu ns.\n",(*resolution).tv_nsec);
 else
     printf("Unknown error in obtaining resolution");

 //Obtain and display the Linux time in the present machine.
 time_t current_linux_time;
 current_linux_time = time(NULL);
 printf("The number of seconds since the Great Epoch is %lu\n",current_linux_time);

 //Use the Linux time computed immediately above and convert it to broken time (human manageable 
 //time) in current time zone.
 struct tm * broken = localtime(&current_linux_time);
 if(broken == NULL)
     printf("A call to function localtime failed.\n");
 else
     printf("The date and time are now: %04d-%02d-%02d  %02d:%02d:%02d\n",
                                        broken->tm_year+1900,
                                        broken->tm_mon+1,
                                        broken->tm_mday,
                                        broken->tm_hour,
                                        broken->tm_min,
                                        broken->tm_sec);

 //Use the Linux time computed earlier in this program and convert it to broken UTC time.
 struct tm * utc = gmtime(&current_linux_time);
 if(utc == NULL)
     printf("A call to function gmtime failed.\n");
 else
     {printf("The UTC date and time are: %04d-%02d-%02d  %02d:%02d:%02d\n",
                                        utc->tm_year+1900,
                                        utc->tm_mon+1,
                                        utc->tm_mday,
                                        utc->tm_hour,
                                        utc->tm_min,
                                        utc->tm_sec);
      //Use an alternate format of displaying the information.
      printf("UTC time now is: %s",asctime(utc));
     }//End of if

 //Use an alternative function to obtain broken time.
 struct timeval * tv = malloc(sizeof(struct timeval));
 struct timezone * tz = malloc(sizeof(struct timezone));
 int c = gettimeofday(tv,tz);
 if(c == 0)
    {printf("The time elapsed since the epoch is %lu.%06lu seconds (accuracy to nearest micro sec)\n",
            (*tv).tv_sec, (*tv).tv_usec);
     printf("The current time zone is %d minutes west of Greenwich\n",(*tz).tz_minuteswest);
     printf("On the web it is widely reported that getttimeofday in the second parameter is disabled in "
            "modern computers.\n");
    }
 else
    printf("An error occurred in the call to function gettimeofday.\n");


 //Use the function clock_gettime which allows the programmer to specify which clock management software 
 //will be used.
 //First know the definition of the struct timespec:
 //         struct timespec 
 //             {time_t   tv_sec     //Seconds
 //              long     tv_nsec    //Nanoseconds
 //             };
 struct timespec * rightnow = malloc(sizeof(struct timespec));

 int zz = clock_gettime(CLOCK_REALTIME,rightnow);
 if(zz == 0)
    printf("Right now = %lu.%09lu seconds after the epoch (accuracy to nearest nano sec).\n",
           rightnow->tv_sec,rightnow->tv_nsec);
 else
    printf("An error occurred during the call to clock_gettime.\n"); 

 //The next two outputs are for the purpose of better understanding the universal constant CLOCK_REALTIME.
 printf("The size of CLOCK_REALTIME is %lu bytes\n",sizeof(CLOCK_REALTIME));
 printf("The value stored in CLOCK_REALTIME is %d\n",CLOCK_REALTIME);

 //Call a subprogram written in X86 assembly language for the purpose of calling the function gettimeofday 
 //used earlier in this program.

 // tzset(); //Set time zone from environmental variable TZ.  Not used in this program.

 printf("%s\n","Bye");
 return 0;
}
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**




