
/* hw13.c
 * Teal Hoffman
 * EE 160
 * 10/3/24
 * The purpose of this code is to ask the user if they want to make another calcualation for t
 */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main() {
   // The variables: t is time, v is velocity, and a is acceleration
   double t, v, a;

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
                    v = 0.000001*t*t*t - 0.00488*t*t + 0.75795*t + 181.3566;
                    a = 3 - 0.000062*v*v;
                    printf("%-3.0lf    %-3.1lf        %-3.3lf\n", t,v,a);
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



/*
uhx02:/home/t/tealhoff% ./hw13
Please enter a time, t, in seconds from 0 to 120:2
You have entered the number: 2.000000
Please enter a number from 0 to 120 that you would like to end on:43.5
Time   Velocity   Acceleration
====   ========   ============
0      181.4        0.961
5      185.0        0.877
10     188.4        0.798
15     191.6        0.723
20     194.6        0.653
25     197.3        0.587
30     199.7        0.527
35     201.9        0.471
40     203.9        0.422
Are you done? Enter 'y' for yes and 'n' for no:n
Please enter a time, t, in seconds from 0 to 120:-3
You have entered the number: -3.000000
ERROR...Please enter a valid number from 0 to 120
Are you done? Enter 'y' for yes and 'n' for no:n
Please enter a time, t, in seconds from 0 to 120:2
You have entered the number: 2.000000
Please enter a number from 0 to 120 that you would like to end on:abc
Time   Velocity   Acceleration
====   ========   ============
0      181.4        0.961
5      185.0        0.877
10     188.4        0.798
15     191.6        0.723
20     194.6        0.653
25     197.3        0.587
30     199.7        0.527
35     201.9        0.471
40     203.9        0.422
Are you done? Enter 'y' for yes and 'n' for no:Please enter a time, t, in seconds from 0 to 120:You have entered the number: 45.000000
Please enter a number from 0 to 120 that you would like to end on:Time   Velocity   Acceleration
====   ========   ============
0      181.4        0.961
5      185.0        0.877
10     188.4        0.798
15     191.6        0.723
20     194.6        0.653
25     197.3        0.587
30     199.7        0.527
35     201.9        0.471
40     203.9        0.422
Are you done? Enter 'y' for yes and 'n' for no:Please enter a time, t, in seconds from 0 to 120:You have entered the number: 45.000000
Please enter a number from 0 to 120 that you would like to end on:Time   Velocity   Acceleration
====   ========   ============
0      181.4        0.961
5      185.0        0.877
10     188.4        0.798
15     191.6        0.723
20     194.6        0.653
25     197.3        0.587
30     199.7        0.527
35     201.9        0.471
40     203.9        0.422
Are you done? Enter 'y' for yes and 'n' for no:Please enter a time, t, in seconds from 0 to 120:2
You have entered the number: 2.000000
Please enter a number from 0 to 120 that you would like to end on:23
Time   Velocity   Acceleration
====   ========   ============
0      181.4        0.961
5      185.0        0.877
10     188.4        0.798
15     191.6        0.723
20     194.6        0.653
Are you done? Enter 'y' for yes and 'n' for no:y
uhx02:/home/t/tealhoff%
*/
