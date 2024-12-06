/* hw24_v02.c
 * Teal Hoffman
 * EE 160
 * 11/25/24
 * The purpose of this code is to create a program to calculate the solution for a system 
 *       of 3 linear equations and 3 unknowns by using the Gauss Jordan Elimination process
 * 
 * VERSIONS
 * --------
 * v1: Shows the augmented matrix the user created 
 * v2: This version will implement the Gauss Jordan process 
 * 
 * PSEUDOCODE
 * ----------
 *    Declare variables and initialize arrays 
 *    Explain the way this program will work
 *    Ask user to enter the coefficients of the system 
 *    Show the user what they inputed 
 *    Ask the user to enter the constants 
 *    Show the user what they inputed 
 *    Make the augmented matrix
 *    Show the user the augmented matrix
 *    Calculate step 1 
 *    Show step 1 
 *    Calculate step 2
 *    Show step 2
 *    Calculate step 3 
 *    Show step 3
 *    Calculate step 4
 *    Show step 4
 *    Calculate step 5
 *    Show step 5
 *    Calculate step 6
 *    Show step 6
 *    Calculate step 7
 *    Show step 7
 *    Calculate step 8
 *    Show step 8
 *    Calculate step 9
 *    Show step 9
 *    Show the user the solution 
 */

#include <stdio.h> 
#include <stdlib.h>

/* MAIN FUNCTION */
int main() {
    /* Declare varibles and initialize arrays */
    int i, j, k;
    float A[3][3];    // The 3x3 matrix of the coefficients of the equations 
    float B[3][1];    // The constants on the opposite side of the equal sign 
    float C[3][4];    // The augmented matrix 

    printf("EXPLAINATION OF PROGRAM: This program will solve a system of 3 linear equations with 3 unknowns\n");

    /* Have the user enter matrix A */
    printf("Please enter the coefficients of the equation one equation at a time (one row at a time) separated by a space\n");
    for (i=0; i<3; i++) {
        printf("Please enter row %i: ", i+1);
        for (j=0; j<3; j++) {
            scanf("%f", &A[i][j]);
        }
    }
    /* Show the user Matrix A (coefficient matrix)*/
    printf("Matrix of coefficients:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf(" %6.2f ", A[i][j]);
        }
        printf("\n");
    }
    /* Have user enter matrix B (constants) */
    printf("Now enter the constants of the equation separated by a space\n");
    for (i=0; i<3; i++) {
        printf("Enter constant %i: ", i+1);
        for (j=0; j<1; j++) {
            scanf("%f", &B[i][j]);
        }
    }
    /* Show the user matrix B (constants) */
    printf("Matrix of constants:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<1; j++) {
            printf(" %6.2f ", B[i][j]);
        }
        printf("\n");
    }
    /* Make the augmented matrix C */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j];   // The 3x3 of augmented matrix C is just A
        }
        C[i][3] = B[i][0];       // For every row of C, the last column of C will belong to that specific row of B
    }
    /* Show augmented matrix */
    printf("Augmented Matrix:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
        printf("\n");
    }
    /* Do the Gauss Jordan Calculations on the matrix */
    /* Step 1 is to divide row 1 with c11 */
    float c11 = C[0][0];         // c11 is the top left position of the matrix 
    for (j = 0; j < 4; j++) {
        C[0][j] = C[0][j] / c11;
    }
    /* Print this intermediate step 1 */
    printf("step 1: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 2 is row 2 = row 2 minus c21*row1 */
    float c21 = C[1][0];
    for (j=0; j<4; j++) {
        C[1][j] = C[1][j] - (c21 * C[0][j]);
    }
    /* Print this intermediate step 2 */
    printf("step 2: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 3 is row 3 = row 3 - c31*row1 */
    float c31 = C[2][0];
    for (j=0; j<4; j++) {
        C[2][j] = C[2][j] - (c31 * C[0][j]);
    }
    /* Print this intermediate step 3 */
    printf("step 3: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 4 is row 2 = row 2 / c22 */
    float c22 = C[1][1];
    for (j=0; j<4; j++) {
        C[1][j] = C[1][j] / c22;
    }
    /* Print this intermediate step 4 */
    printf("step 4: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 5 is row 3 = row 3 - c32*row2 */
    float c32 = C[2][1];
    for (j=0; j<4; j++) {
        C[2][j] = C[2][j] - (c32 * C[1][j]);
    }
    /* Print this intermediate step 5 */
    printf("step 5: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 6 is row 1 = row 1 - c12*row2 */
    float c12 = C[0][1];
    for (j=0; j<4; j++) {
        C[0][j] = C[0][j] - (c12 * C[1][j]);
    }
    /* Print this intermediate step 6 */
    printf("step 6: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 7 is row 3 = row 3 / c33 */
    float c33 = C[2][2];
    for (j=0; j<4; j++) {
        C[2][j] = C[2][j] / c33;
    }
    /* Print this intermediate step 7 */
    printf("step 7: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 8 is row 2 = row 2 - c23*row3 */
    float c23 = C[1][2];
    for (j=0; j<4; j++) {
        C[1][j] = C[1][j] - (c23 * C[2][j]);
    }
    /* Print this intermediate step 8 */
    printf("step 8: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    } 
    /* Step 9 is row 1 = row 1 - c13*row3 */
    float c13 = C[0][2];
    for (j=0; j<4; j++) {
        C[0][j] = C[0][j] - (c13 * C[2][j]);
    }
    /* Print this intermediate step 9 */
    printf("step 9: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %6.2f ", C[i][j]);
        }
    printf("\n");
    }
    /* Show the user the solution */
    float x1 = C[0][3];
    float x2 = C[1][3];
    float x3 = C[2][3];
    printf("The solution is x1 = %.2f and x2 = %.2f x3 = %.2f\n", x1, x2, x3);
    return 0;
}



/*

uhx02:/home/t/tealhoff% gcc -o hw24_v02 hw24_v02.c
uhx02:/home/t/tealhoff% ./hw24_v02
EXPLAINATION OF PROGRAM: This program will solve a system of 3 linear equations with 3 unknowns
Please enter the coefficients of the equation one equation at a time (one row at a time) separated by a space
Please enter row 1: 2 0 0
Please enter row 2: 0 3 0
Please enter row 3: 0 0 1
Matrix of coefficients:
   2.00    0.00    0.00
   0.00    3.00    0.00
   0.00    0.00    1.00
Now enter the constants of the equation separated by a space
Enter constant 1: 3
Enter constant 2: 6
Enter constant 3: 0.68
Matrix of constants:
   3.00
   6.00
   0.68
Augmented Matrix:
   2.00    0.00    0.00    3.00
   0.00    3.00    0.00    6.00
   0.00    0.00    1.00    0.68
step 1:
   1.00    0.00    0.00    1.50
   0.00    3.00    0.00    6.00
   0.00    0.00    1.00    0.68
step 2:
   1.00    0.00    0.00    1.50
   0.00    3.00    0.00    6.00
   0.00    0.00    1.00    0.68
step 3:
   1.00    0.00    0.00    1.50
   0.00    3.00    0.00    6.00
   0.00    0.00    1.00    0.68
step 4:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00    2.00
   0.00    0.00    1.00    0.68
step 5:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00    2.00
   0.00    0.00    1.00    0.68
step 6:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00    2.00
   0.00    0.00    1.00    0.68
step 7:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00    2.00
   0.00    0.00    1.00    0.68
step 8:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00    2.00
   0.00    0.00    1.00    0.68
step 9:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00    2.00
   0.00    0.00    1.00    0.68
The solution is x1 = 1.50 and x2 = 2.00 x3 = 0.68
uhx02:/home/t/tealhoff%

uhx02:/home/t/tealhoff% ./hw24_v02
EXPLAINATION OF PROGRAM: This program will solve a system of 3 linear equations with 3 unknowns
Please enter the coefficients of the equation one equation at a time (one row at a time) separated by a space
Please enter row 1: 1 2 3
Please enter row 2: 6 5 4
Please enter row 3: 9 8 8
Matrix of coefficients:
   1.00    2.00    3.00
   6.00    5.00    4.00
   9.00    8.00    8.00
Now enter the constants of the equation separated by a space
Enter constant 1: 3
Enter constant 2: 10
Enter constant 3: 100
Matrix of constants:
   3.00
  10.00
 100.00
Augmented Matrix:
   1.00    2.00    3.00    3.00
   6.00    5.00    4.00   10.00
   9.00    8.00    8.00  100.00
step 1:
   1.00    2.00    3.00    3.00
   6.00    5.00    4.00   10.00
   9.00    8.00    8.00  100.00
step 2:
   1.00    2.00    3.00    3.00
   0.00   -7.00  -14.00   -8.00
   9.00    8.00    8.00  100.00
step 3:
   1.00    2.00    3.00    3.00
   0.00   -7.00  -14.00   -8.00
   0.00  -10.00  -19.00   73.00
step 4:
   1.00    2.00    3.00    3.00
  -0.00    1.00    2.00    1.14
   0.00  -10.00  -19.00   73.00
step 5:
   1.00    2.00    3.00    3.00
  -0.00    1.00    2.00    1.14
   0.00    0.00    1.00   84.43
step 6:
   1.00    0.00   -1.00    0.71
  -0.00    1.00    2.00    1.14
   0.00    0.00    1.00   84.43
step 7:
   1.00    0.00   -1.00    0.71
  -0.00    1.00    2.00    1.14
   0.00    0.00    1.00   84.43
step 8:
   1.00    0.00   -1.00    0.71
  -0.00    1.00    0.00  -167.71
   0.00    0.00    1.00   84.43
step 9:
   1.00    0.00    0.00   85.14
  -0.00    1.00    0.00  -167.71
   0.00    0.00    1.00   84.43
The solution is x1 = 85.14 and x2 = -167.71 x3 = 84.43
uhx02:/home/t/tealhoff%

uhx02:/home/t/tealhoff% ./hw24_v02
EXPLAINATION OF PROGRAM: This program will solve a system of 3 linear equations with 3 unknowns
Please enter the coefficients of the equation one equation at a time (one row at a time) separated by a space
Please enter row 1: 2 0 0
Please enter row 2: 0 -3 0
Please enter row 3: 0 0 8
Matrix of coefficients:
   2.00    0.00    0.00
   0.00   -3.00    0.00
   0.00    0.00    8.00
Now enter the constants of the equation separated by a space
Enter constant 1: 3
Enter constant 2: 6
Enter constant 3: -4
Matrix of constants:
   3.00
   6.00
  -4.00
Augmented Matrix:
   2.00    0.00    0.00    3.00
   0.00   -3.00    0.00    6.00
   0.00    0.00    8.00   -4.00
step 1:
   1.00    0.00    0.00    1.50
   0.00   -3.00    0.00    6.00
   0.00    0.00    8.00   -4.00
step 2:
   1.00    0.00    0.00    1.50
   0.00   -3.00    0.00    6.00
   0.00    0.00    8.00   -4.00
step 3:
   1.00    0.00    0.00    1.50
   0.00   -3.00    0.00    6.00
   0.00    0.00    8.00   -4.00
step 4:
   1.00    0.00    0.00    1.50
  -0.00    1.00   -0.00   -2.00
   0.00    0.00    8.00   -4.00
step 5:
   1.00    0.00    0.00    1.50
  -0.00    1.00   -0.00   -2.00
   0.00    0.00    8.00   -4.00
step 6:
   1.00    0.00    0.00    1.50
  -0.00    1.00   -0.00   -2.00
   0.00    0.00    8.00   -4.00
step 7:
   1.00    0.00    0.00    1.50
  -0.00    1.00   -0.00   -2.00
   0.00    0.00    1.00   -0.50
step 8:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00   -2.00
   0.00    0.00    1.00   -0.50
step 9:
   1.00    0.00    0.00    1.50
   0.00    1.00    0.00   -2.00
   0.00    0.00    1.00   -0.50
The solution is x1 = 1.50 and x2 = -2.00 x3 = -0.50
uhx02:/home/t/tealhoff%

*/

