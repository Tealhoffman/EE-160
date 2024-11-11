
/* hw2.c
 * Teal Hoffman
 * EE 160
 * 9/6/2024
 * This code is to practice variables (declaring, initializing, and compile)
 */

#include <stdio.h>

int main(void) {
   int num;
   double x = 3.5;
   float y = 1.5;
   num = 7;
   char myletter = 'a';

   printf("The value of the integer 'num' is %i\n", num);
   printf("The value of the double 'x' is %lf\n", x);
   printf("The value of the float 'y' is %f\n", y);
   printf("The value of the character 'myletter' is %c\n", myletter);

   return 0;
}

/*
uhx02:/home/t/tealhoff% nano hw2.c
uhx02:/home/t/tealhoff% gcc -o hw2 hw2.c
uhx02:/home/t/tealhoff% ./hw2
The value of the integer 'num' is 7
The value of the double 'x' is 3.500000
The value of the float 'y' is 1.500000
The value of the character 'myletter' is a
uhx02:/home/t/tealhoff%
   */
