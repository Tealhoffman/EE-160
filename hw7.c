/* hw7.c
 * Teal Hoffman
 * EE 160
 * 9/14/24
 * The point of this code is to practice given code from hw7
 */

#include <stdio.h>
#include <math.h>

int main() {
   int points;
   points = 2+12+16;
   int credits;
   credits = 1+4+4;
   float GPA;
   GPA = (float)points/credits;
   printf("%-8.3f\n", GPA);


   long int honRailCost;
   honRailCost = 12450000000000;
   printf("%li\n", honRailCost);


// King Kamehameha Statue
   double GPS_N, GPS_W;
   GPS_N = 21.305736;
   GPS_W = -157.859661;
   printf("%lf\n", GPS_N);
   printf("%lf\n", GPS_W);

   return 0;
 }

/*
The program:

uhx02:/home/t/tealhoff% gcc -o hw7 hw7.c
uhx02:/home/t/tealhoff% ./hw7
3.333
12450000000000
21.305736
-157.859661
uhx02:/home/t/tealhoff%
   */
