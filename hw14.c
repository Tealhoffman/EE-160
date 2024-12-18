/* hw14.c
 * Teal Hoffman
 * EE 160
 * 10/7/24
 * The purpose of this code is to add a function to the velocity/acceleration problem
 */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

// Add funtion to calculate the velocity and acceleration
//Function Prototype(declaration):

double velocity(double);
double acceleration(double);


int main() {
   // The variables: t is time, v is velocity, and a is acceleration
   double t;

   char choice;
   int done = FALSE;


   while (!done) {

       printf("Please enter a time, t, in seconds from 0 to 120:");
       scanf("%lf", &t);

       printf("You have entered the number: %lf\n", t);

       if (t>=0 && t<=120) {
           double endtime;
           printf("Please enter a number from 0 to 120 that you would like to end on:");
           scanf(" %lf", &endtime);

           if (endtime>=0 && endtime<=120) {

               printf("Time   Velocity   Acceleration\n");
               printf("====   ========   ============\n");

               t = 0;
               while (t <= endtime)  {
                    printf("%-3.0lf    %-3.1lf       %-3.3lf\n", t,velocity(t),acceleration(t));
                    t = t + 5;
               }
           }
           else {
               printf("ERROR...Please enter a valid number from 0 to 120\n");
           }

       }
       else {
           printf("ERROR...Please enter a valid number from 0 to 120\n");
       }



       printf("Are you done? Enter 'y' for yes and 'n' for no:");
       scanf(" %c", &choice);

       if (choice == 'y' || choice == 'Y') {
           done = TRUE;
       }
       else  {
           done = FALSE;
       }
   }

   return 0;
}

//This is where the functions for calculating velocity and acceleration are


//input is time
double velocity(double time) {
    return 0.000001*time*time*time - 0.00488*time*time + 0.75795*time + 181.3566;
}

//input is velocity
double acceleration(double time) {
    double v;
    v = 0.000001*time*time*time - 0.00488*time*time + 0.75795*time + 181.3566;
    return 3 - 0.000062*v*v;
}


/*
uhx02:/home/t/tealhoff% gcc -o hw14 hw14.c
uhx02:/home/t/tealhoff% ./hw14
Please enter a time, t, in seconds from 0 to 120:43.5
You have entered the number: 43.500000
Please enter a number from 0 to 120 that you would like to end on:43.5
Time   Velocity   Acceleration
====   ========   ============
0      181.4       0.961
5      185.0       0.877
10     188.4       0.798
15     191.6       0.723
20     194.6       0.653
25     197.3       0.587
30     199.7       0.527
35     201.9       0.471
40     203.9       0.422
Are you done? Enter 'y' for yes and 'n' for no:n
Please enter a time, t, in seconds from 0 to 120:36.5
You have entered the number: 36.500000
Please enter a number from 0 to 120 that you would like to end on:36.5
Time   Velocity   Acceleration
====   ========   ============
0      181.4       0.961
5      185.0       0.877
10     188.4       0.798
15     191.6       0.723
20     194.6       0.653
25     197.3       0.587
30     199.7       0.527
35     201.9       0.471
Are you done? Enter 'y' for yes and 'n' for no:y
uhx02:/home/t/tealhoff% ./hw14
Please enter a time, t, in seconds from 0 to 120:85.0
You have entered the number: 85.000000
Please enter a number from 0 to 120 that you would like to end on:10
Time   Velocity   Acceleration
====   ========   ============
0      181.4       0.961
5      185.0       0.877
10     188.4       0.798
Are you done? Enter 'y' for yes and 'n' for no:p
Please enter a time, t, in seconds from 0 to 120:11.2
You have entered the number: 11.200000
Please enter a number from 0 to 120 that you would like to end on:11.2
Time   Velocity   Acceleration
====   ========   ============
0      181.4       0.961
5      185.0       0.877
10     188.4       0.798
Are you done? Enter 'y' for yes and 'n' for no:y


uhx02:/home/t/tealhoff% ./hw14
Please enter a time, t, in seconds from 0 to 120:abc
You have entered the number: 0.000000
Please enter a number from 0 to 120 that you would like to end on:Time   Velocity   Acceleration
====   ========   ============
0      181.4       0.961
Are you done? Enter 'y' for yes and 'n' for no:Please enter a time, t, in seconds from 0 to 120:You have entered the number: 5.000000
Please enter a number from 0 to 120 that you would like to end on:Time   Velocity   Acceleration
====   ========   ============
0      181.4       0.961
Are you done? Enter 'y' for yes and 'n' for no:Please enter a time, t, in seconds from 0 to 120:You have entered the number: 5.000000
Please enter a number from 0 to 120 that you would like to end on:Time   Velocity   Acceleration
====   ========   ============
0      181.4       0.961
Are you done? Enter 'y' for yes and 'n' for no:Please enter a time, t, in seconds from 0 to 120:
   */
