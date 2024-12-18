/* hw16.c
 * Teal Hoffman
 * EE 160
 * 10/13/2024
 * The purpose of this code is to implement the secant method
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

// Designating boolean variables
#define TRUE 1
#define FALSE 0

// Function prototype (declaration)
// output-name Name(input-type);
double y(double);

int main() {

    double x0, x1, x_old, x_current, x_new, epsilon;
    int n, max_value;
    int done = FALSE;

    printf("This program is to implement the secant method to find ONE root of the polynomial function \n");
    printf("Please guess two initial x values separated by a space: ");
    scanf("%lf %lf",&x0,&x1);
    printf("You entered %.3lf and %.3lf as your initial values\n",x0,x1);
    printf("  n    x-value   y-value \n");
    printf(" ===   =======   =======\n");
    n = 0;
    printf(" x%i    %.3lf    %.3lf\n",n, x0, y(x0));
    n = 1;
    printf(" x%i    %.3lf    %.3lf\n",n, x1, y(x1));

    // (to test function:)  printf("%lf %lf\n", y(x0), y(x1));

    // Initialize n as 2
    n = 2;
    x_old = x0;
    x_current = x1;
    epsilon = 0.001;
    max_value = 25000;

    // Loop to calculate the next value of x
    while (!done) {

        x_new = x_current - y(x_current)*((x_current - x_old)/(y(x_current) - y(x_old)));

        // You can comment this printf out if you only want to show the x-value that converged
        printf(" x%i    %-.3lf    %-.3lf\n", n, x_new, y(x_new));

        if (fabs(y(x_new)) < epsilon) {

            printf("Final (converged) value of x: %.3lf\n", x_new);

            done = TRUE;
        }
        else if (n == max_value) {
            printf("In %i iterations, the secant method did not find a converging x-value\n", max_value);
            done = TRUE;
        }
        else {
            x_old = x_current;
            x_current = x_new;
            n = n + 1;
        }
    }


    return 0;
}


// User made functions are located here

// Function to take the input value of x and calculate f(x)
double y(double input) {
//    return input*input - 10*input + 21;
    return -0.98*pow(input, 3) + 18.35*pow(input, 2) -0.087*input + 0.90004;
//    return pow(input, 2) + 1;
}


/*
uhx02:/home/t/tealhoff% gcc -o hw16 hw16.c -lm
uhx02:/home/t/tealhoff% ./hw16
This program is to implement the secant method to find ONE root of the polynomial function
Please guess two initial x values separated by a space: 0 9
You entered 0.000 and 9.000 as your initial values
  n    x-value   y-value
 ===   =======   =======
 x0    0.000    0.900
 x1    9.000    772.047
 x2    -0.011    0.903
 x3    -0.021    0.910
 x4    1.344    31.530
 x5    -0.062    0.975

.....

 x1777    -3.953    348.500
 x1778    10.581    893.479
 x1779    -13.247    5500.337
 x1780    15.203    797.285
 x1781    20.025    -512.103
 x1782    18.139    188.057
 x1783    18.646    26.088
 x1784    18.727    -1.731
 x1785    18.722    0.014
 x1786    18.722    0.000
Final (converged) value of x: 18.722
uhx02:/home/t/tealhoff%
    */
