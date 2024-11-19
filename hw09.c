/* hw9.c
 * Teal Hoffman
 * EE 160
 * 9/18/24
 * The purpose of this code is use hw8 pseudocode and flowchart to convert it into real code in c
 */

#include <stdio.h>

int main() {
   int num;
   printf("Enter a value: \n");
   scanf(" %i", &num);
   if (num < 7) {
      printf("Number is small \n");
   }
   else if (num < 10) {
      printf("That's a good number!\n");
   }
   else if (num >= 10) {
      printf("Number is large \n");
   }

   return 0;
}



/*
The program: 

uhx02:/home/t/tealhoff% gcc -o hw9 hw9.c
uhx02:/home/t/tealhoff% ./hw9
Enter a value:
3
Number is small

uhx02:/home/t/tealhoff% ./hw9
Enter a value:
7
That's a good number!

uhx02:/home/t/tealhoff% ./hw9
Enter a value:
10
Number is large
*/
