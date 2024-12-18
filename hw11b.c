/* hw11b.c
 * Teal Hoffman
 * EE 160
 * 9/21/24
 * The purpose of this code is to practice more incremental development by doing a tough problem, starting off small and
 *   then working my way to create more complex code
 */

#include <stdio.h>
#include <math.h>

int main() {
   // The variables: t is time, v is velocity, and a is acceleration
   double t;
   double v;
   double a;
   printf("Please enter a time, t, in seconds from 0 to 120:\n");
   scanf("%lf", &t);

   if (t>=0 && t<=120) {
       v = 0.000001*t*t*t - 0.00488*t*t + 0.75795*t + 181.3566;
       a = 3 - 0.000062*v*v;
       printf("Velocity = %lf, Acceleration = %lf\n", v,a);
     }
   else {
       printf("ERROR...Please enter a valid number from 0 to 120\n");
     }

   return 0;
  }

/*
The Program:
    
uhx02:/home/t/tealhoff% gcc -o hw11b hw11b.c
uhx02:/home/t/tealhoff% ./hw11b
Please enter a time, t, in seconds from 0 to 120:
123
ERROR...Please enter a valid number from 0 to 120
uhx02:/home/t/tealhoff% ./hw11b
Please enter a time, t, in seconds from 0 to 120:
0
Velocity = 181.356600, Acceleration = 0.960807
*/                                                                                                                                                                                                                                                            
