/* hw3.c
 * Teal Hoffman
 * EE 160
 * 9/6/2024
 * This code is to practice variables (part 2) and we will purposefully
 *     write an incorect line of code
 */

#include <stdio.h>

int main(void) {

   /*Correct! assign a variable of a character and have the computer write a message for it*/
   char letter = 'A';
   printf("The first letter of the alphabet is %c\n", letter);


   /*purposefully making a bug for the wrong variable type*/
   printf("The first letter of the alphabet is %i\n", letter);


   return 0;
}


/*
uhx02:/home/t/tealhoff% gcc -o hw3 hw3.c
uhx02:/home/t/tealhoff% ./hw3
The first letter of the alphabet is A
The first letter of the alphabet is 65
uhx02:/home/t/tealhoff% lol wat
*/