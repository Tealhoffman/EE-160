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
//    return -0.98*pow(input, 3) + 18.35*pow(input, 2) -0.087*input + 0.90004;
    return pow(input, 2) + 1;
}


/*
x24998    -1.749    4.058
 x24999    -14.363    207.289
 x25000    -1.497    3.240
In 25000 iterations, the secant method did not find a converging x-value
uhx02:/home/t/tealhoff%
    */
