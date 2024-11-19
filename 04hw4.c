/* hw4.c
 * Name: Teal Hoffman
 * Class: EE 160
 * 9/9/2024
 * Objective: This code is homework 4 to learn about scanf
 */

#include <stdio.h>

int main() {
   double x;
   char choice;

   printf("Please enter a number:");
   scanf("%lf", &x);
   printf("Enter 'a' to double or 'b' to triple:");
   scanf(" %c", &choice);

   /* There needs to be a space after the " in scanf(" %c") because
     the second scanf is taking the ENTER as its input and since
     scanf terminates after getting an ENTER, it is not taking
     anything else
    */

   if (choice == 'a' || choice == 'A') {
      printf("You chose 'a'\n");
      printf("The result is%lf\n", 2*x);
    }
   else if (choice == 'b' || choice == 'B') {
      printf("You chose 'b'\n");
      printf("The result is %lf\n", 3*x);
    }

   return 0;
}



/*
uhx02:/home/t/tealhoff% gcc -o hw4 hw4.c
uhx02:/home/t/tealhoff% ./hw4
Please enter a number:100
Enter 'a' to double or 'b' to triple:a
You chose 'a'
The result is200.000000

uhx02:/home/t/tealhoff% ./hw4
Please enter a number:5
Enter 'a' to double or 'b' to triple:b
You chose 'b'
The result is 15.000000
*/
