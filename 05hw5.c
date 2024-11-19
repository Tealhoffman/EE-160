/* hw5.c
 * Teal Hoffman
 * EE 160
 * 9/13/24
 * The point of this code is to get familiar with fgets and sscanf
 */

#include <stdio.h>

int main() {
   int x;
   char buff[100];
   char ch;
   double y;

   printf("Enter an integer with 5 or less digits: ");
   fgets(buff, 100, stdin);
   sscanf(buff, "%5i", &x);

   printf("Enter a character: ");
   scanf(" %c", &ch);

   printf("Enter a double: ");
   scanf("%lf", &y);

   printf("The integer is %i \n", x);
   printf("The character is %c \n", ch);
   printf("The double is %8.3lf \n", y);

   return 0;
 }


/*
The Program:

uhx02:/home/t/tealhoff% gcc -o hw5 hw5.c
uhx02:/home/t/tealhoff% ./hw5
Enter an integer with 5 or less digits: 12345678
Enter a character: b
Enter a double: 12.2
The integer is 12345
The character is b
The double is   12.200
uhx02:/home/t/tealhoff%
   */
