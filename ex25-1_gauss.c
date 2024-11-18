/* ex25-1_gauss.c 
 * Teal Hoffman 
 * EE 160 
 * 11/18/24
 * This class exercise is to solve a system of 2 linear equations using Gaussian elimination.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Declare variables and arrays 
  int i, j, k;
  float A[2][3] = {{3, 1, 12}, 
                   {1, 1,  8}};
  
  /* Divide ONLY row 1 by 3 */
  for (j = 0; j < 3; j++) {
       A[0][j] = A[0][j] / 3;
  }
  
  /* Print this intermediate step 1 */
  printf("step 1: \n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf(" %4.1f ", A[i][j]);
    }
    printf("\n");
  } 
  
  /* Now row 2 minus row 1 */
  for (j = 0; j < 3; j++) {
    A[1][j] = A[1][j] - A[0][j];  // A good note is that whatever row you are changing is the one that will be hard coded (row 2 - A[1][j]) 
  }
  
  /* Print this intermediate step 2 */
  printf("step 2: \n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf(" %4.1f ", A[i][j]);
    }
    printf("\n");
  }
  
  /* Now divide row2 by 0.67 */
  for (j = 0; j < 3; j++) {
    A[1][j] = A[1][j] / 0.67;
  }
  
  /* Print this intermediate step 3 */
  printf("step 3: \n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf(" %4.1f ", A[i][j]);
    }
    printf("\n");
  }

  /* Now subtract row 1 from row 2 times 0.33 */
  for (j = 0; j < 3; j++) {
    A[0][j] = A[0][j] - (A[1][j] * 0.33);
  }

  /* Print this intermediate step 4 */
  printf("step 4: \n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf(" %4.1f ", A[i][j]);
    }
    printf("\n");
  }

  /* Tell the user the solution of the two linear equations */
  printf("The solution is x = %.1f and y = %.1f\n", A[0][2], A[1][2]);

  return 0;
}



/*
uhx02:/home/t/tealhoff% nano ex25-1_gauss.c
uhx02:/home/t/tealhoff% gcc -o ex25-1_gauss ex25-1_gauss.c
uhx02:/home/t/tealhoff% ./ex25-1_gauss
step 1:
  1.0   0.3   4.0
  1.0   1.0   8.0
step 2:
  1.0   0.3   4.0
  0.0   0.7   4.0
step 3:
  1.0   0.3   4.0
  0.0   1.0   6.0
step 4:
  1.0   0.0   2.0
  0.0   1.0   6.0
The solution is x = 2.0 and y = 6.0
uhx02:/home/t/tealhoff%
*/