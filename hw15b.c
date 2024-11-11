//For the function f(x)=2x^3-28.4x^2-1.38x+59.22
/* hw15b.c
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

    printf("For the function f(x)=2x^3-28.4x^2-1.38x+59.22:\n");
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
    return 2*input*input*input - 28.4*input*input - 1.38*input + 59.22;
}



/*
uhx02:/home/t/tealhoff% gcc -o hw15b hw15b.c
uhx02:/home/t/tealhoff% ./hw15b
Please enter a minimum number and a maximum number separated by a space:-100 100
You entered -100.0 as the xmin and 100.0 as xmax
Please enter an amount of steps you would like to take to get from -100.0 to 100.0:17
For the function f(x)=2x^3-28.4x^2-1.38x+59.22:
x-value     y-value    sign-change
=======     =======    ===========
 -100.000    -2283802.780
 -88.235    -1594832.245
 -76.471    -1060273.272
 -64.706    -660585.864
 -52.941    -376230.025
 -41.176    -187665.760
 -29.412    -75353.072
 -17.647    -19751.965
 -5.882    -1322.445
 5.882    -524.513
 17.647    2181.824     YES!
 29.412    26336.564
 41.176    91479.702
 52.941    217151.233
 64.706    422891.155
 76.471    728239.463
 88.235    1152736.153
uhx02:/home/t/tealhoff% ./hw15b
Please enter a minimum number and a maximum number separated by a space:-2 15
You entered -2.0 as the xmin and 15.0 as xmax
Please enter an amount of steps you would like to take to get from -2.0 to 15.0:31
For the function f(x)=2x^3-28.4x^2-1.38x+59.22:
x-value     y-value    sign-change
=======     =======    ===========
 -2.000    -67.620
 -1.452    -4.738
 -0.903    35.824     YES!
 -0.355    56.044
 0.194    57.904
 0.742    43.380
 1.290    14.452
 1.839    -26.901     YES!
 2.387    -78.699
 2.935    -138.965
 3.484    -205.719
 4.032    -276.981
 4.581    -350.774
 5.129    -425.117
 5.677    -498.033
 6.226    -567.542
 6.774    -631.664
 7.323    -688.422
 7.871    -735.836
 8.419    -771.927
 8.968    -794.716
 9.516    -802.224
 10.065    -792.472
 10.613    -763.482
 11.161    -713.273
 11.710    -639.868
 12.258    -541.287
 12.806    -415.551
 13.355    -260.682
 13.903    -74.699
 14.452    144.375     YES!
uhx02:/home/t/tealhoff%
*/
