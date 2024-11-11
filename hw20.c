/* hw20.c 
 * Teal Hoffman 
 * EE 160 
 * 11/8/2024
 * The purpose of this program is to create a function to calculate the mean of an array and then 
 *     another function to caculate the variance which will be used to calculate the standard deviation.
 * See Textbook pg. 232 Section 5.4 (Engineering Problem Solving in C) for more information on the mean, variance, and standard deviation.
 */

#include <stdio.h>
#include <math.h>

/* FUNCTION PROTOTYPE
 * CalcMean returns the mean value of an array with 8 elements and 
 * CalcVar returns the variance of an array with 8 elements. */
double CalcMean(double array[], int elements);
double CalcVar(double array[], int elements);

/* Main Function */
int main (void) {
   /* Declare variables and arrays */
   double array[8];    // Declaring the array 
   int elements = 8;   // Amount of elements in the array 
   int i;              // Loop counter 
   /* Ask user to enter 8 integers*/
   printf("Please enter the 8 integers separated by a space: \n");
   for (i = 0; i < elements; i++) {
      scanf("%lf", &array[i]);
   }
   /* Show the user what they entered */
   printf("You entered the input values:\n");
   for (i = 0; i < elements; i++) {
      printf("%.1lf ", array[i]);
   }
   printf("\n\n");
   /* Call the mean function */
   printf("The mean value is: %.3lf\n", CalcMean(array, elements));
   printf("The variance is: %.3lf\n", CalcVar(array, elements));
   printf("The std dev is: %.3lf\n", sqrt(CalcVar(array, elements)));  // The sqr root of variance is the std dev.
  return 0;
}
/* FUNCTION DEFINITION
 * This function returns the mean value of an array with 8 elements*/
double CalcMean(double arr[], int ele) {
   int k;             // Loop counter
   double sum = 0;    // Sum of the array elements initialized to 0 
   for (k = 0; k < ele; k++) {
      sum += arr[k];
   }
   return sum / ele;  // returning the sum of the elements diveded by the amount of elements
}
/* This funtion returns the variance of an array with 8 elements */
double CalcVar(double arra[], int elem) {
   int j;                              // Loop counter
   double sums = 0;                    // Sum of the array elements initialized to 0
   double mu;                          // Mean of the array elements
   mu = CalcMean(arra, elem);          // Calling the mean function to get the mean of the array
   for (j = 0; j < elem; j++) {
      sums += pow(arra[j] - mu, 2);    // Sum of the squared differences from the mean
   }
   return sums / elem;                 // Returning the sum of the squared differences divided by the amount of elements
}



/*
uhx02:/home/t/tealhoff% gcc -o hw20 hw20.c -lm
uhx02:/home/t/tealhoff% ./hw20
Please enter the 8 integers separated by a space:
1 2 3 4 5 6 7 8
You entered the input values:
1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0

The mean value is: 4.500
The variance is: 5.250
The std dev is: 2.291
uhx02:/home/t/tealhoff%
   */
