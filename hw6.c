/* hw6.c
 * Teal Hoffman
 * EE 160
 * 9/13/24
 * The meaning of this code is to practice debugging 
 */

#include <stdio.h>

int main() {
   double x;
   double y;
   char buff[100];
   printf("Enter two numbers separated by a space: ");
   fgets(buff,100,stdin);
   sscanf(buff,"%lf %lf",&x,&y);
   printf("The sum of those two numbers is %lf\n",x+y);
   return 0;
 }



/*
uhx02:/home/t/tealhoff% gcc -o hw6 hw6.c
uhx02:/home/t/tealhoff% ./hw6
Enter two numbers separated by a space: 3 3
The sum of those two numbers is 6.000000
*/
