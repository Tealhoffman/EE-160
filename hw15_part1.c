
/* hw15.c
 * Teal Hoffman
 * EE 160
 * 10/7/24
 * The purpose of this code is to create a function that calculates the y value (output) for any given x value (input)
 * Then the program will prompt the user to for an additional integer input which will be the amount of steps
 * Then you will use booleans to determine where the sign changes are
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

double y(double);

int main() {

    double xmin, xmax, x, interval, old_y, current_y;
    int steps;

    printf("Please enter a minimum number and a maximum number separated by a space:");
    scanf("%lf %lf", &xmin, &xmax);
    printf("You entered %3.1lf as the xmin and %3.1lf as xmax\n",xmin,xmax);

    printf("Please enter an amount of steps you would like to take to get from %3.1lf to %3.1lf:", xmin, xmax);
    scanf(" %i", &steps);

    //Calculation for the interval, given the amount of steps
    interval = (xmax - xmin)/steps;

    printf("For the function f(x)=x^2-10x+21:\n");
    printf("x-value  y-value  sign-change\n");
    printf("=======  =======  ===========\n");

    x = xmin; //initialize x to whatever the user input as the minimum
    old_y = y(x);  //initialize the first y-value for the first x value

    while (x <= xmax) {

        current_y = y(x);  //set the current y-value calculation within the loop

        if (old_y*current_y < 0) {  // A negative*negative is positive and a postive*positive is a positive (the product of two opposite signs are negative)
            printf(" %6.3lf  %6.3lf     YES!\n", x, current_y);
        }
        else {
            printf(" %6.3lf  %6.3lf     \n", x, current_y);
        }

        old_y = current_y;  // the current y-value will become the old y value

        x = x + interval;
    }

    return 0;
}


//Funtions are located here:

double y(double input) {
    return input*input - 10*input + 21;
}



/*
uhx02:/home/t/tealhoff% gcc -o hw15 hw15.c
uhx02:/home/t/tealhoff% ./hw15
Please enter a minimum number and a maximum number separated by a space:0 11
You entered 0.0 as the xmin and 11.0 as xmax
Please enter an amount of steps you would like to take to get from 0.0 to 11.0:15
For the function f(x)=x^2-10x+21:
x-value  y-value  sign-change
=======  =======  ===========
  0.000  21.000
  0.733  14.204
  1.467   8.484
  2.200   3.840
  2.933   0.271
  3.667  -2.222     YES!
  4.400  -3.640
  5.133  -3.982
  5.867  -3.249
  6.600  -1.440
  7.333   1.444     YES!
  8.067   5.404
  8.800  10.440
  9.533  16.551
 10.267  23.738
 11.000  32.000
uhx02:/home/t/tealhoff% ./hw15
Please enter a minimum number and a maximum number separated by a space:-2 11
You entered -2.0 as the xmin and 11.0 as xmax
Please enter an amount of steps you would like to take to get from -2.0 to 11.0:10
For the function f(x)=x^2-10x+21:
x-value  y-value  sign-change
=======  =======  ===========
 -2.000  45.000
 -0.700  28.490
  0.600  15.360
  1.900   5.610
  3.200  -0.760     YES!
  4.500  -3.750
  5.800  -3.360
  7.100   0.410     YES!
  8.400   7.560
  9.700  18.090
uhx02:/home/t/tealhoff%
*/
