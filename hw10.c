/* hw10.c
 * Teal Hoffman
 * EE 160
 * 9/21/2024
 * The purpose of this code is to practice loops
 */

#include <stdio.h>
#include <math.h>

int main()  {
   int x = 0;
   for (x=0;x<=10;x++) {
       int y = x*x - 3*x + 17;
       printf("x=%i, y=%i\n", x,y);
      }

   return 0;
 }


/*
The Program:

uhx02:/home/t/tealhoff% gcc -o hw10 hw10.c
uhx02:/home/t/tealhoff% ./hw10
x=0, y=17
x=1, y=15
x=2, y=15
x=3, y=17
x=4, y=21
x=5, y=27
x=6, y=35
x=7, y=45
x=8, y=57
x=9, y=71
x=10, y=87
   */
