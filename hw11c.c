
/* hw11b.c
 * Teal Hoffman
 * EE 160
 * 9/21/24
 * The purpose of this code is to practice more incremental development by doing a tough problem, starting off small and
 *   then working my way to create more complex code
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
   // The variables: t is time, v is velocity, and a is acceleration
   double t, v, a;
   char buff[100];
   char x;
   printf("Please enter a time, t, in seconds from 0 to 120:\n");
   fgets(buff,100,stdin);
   sscanf(buff,"%lf",&t);

   x = buff[0];

   if (isdigit(x) == 0) {
       printf("Error...Please enter number digits\n");
     }
   else {
      if (t>=0 && t<=120) {
       v = 0.000001*t*t*t - 0.00488*t*t + 0.75795*t + 181.3566;
       a = 3 - 0.000062*v*v;
       printf("Velocity = %lf, Acceleration = %lf\n", v,a);
     }
   else {
       printf("ERROR...Please enter a valid number from 0 to 120\n");
     }
   }
   return 0;
  }



/*
uhx02:/home/t/tealhoff% gcc -o hw11c hw11c.c -lm
uhx02:/home/t/tealhoff% ./hw11c
Please enter a time, t, in seconds from 0 to 120:
23
Velocity = 196.220097, Acceleration = 0.612856
uhx02:/home/t/tealhoff% ./hw11c
Please enter a time, t, in seconds from 0 to 120:
a34
Error...Please enter number digits
uhx02:/home/t/tealhoff% ./hw11c
Please enter a time, t, in seconds from 0 to 120:
34
Velocity = 201.524924, Acceleration = 0.482038
uhx02:/home/t/tealhoff% ./hw11c
Please enter a time, t, in seconds from 0 to 120:
234
ERROR...Please enter a valid number from 0 to 120
uhx02:/home/t/tealhoff%


Help: 
uhx02:/home/t/tealhoff% ./hw11c
Please enter a time, t, in seconds from 0 to 120:
-3
Error...Please enter number digits
uhx02:/home/t/tealhoff%
*/
