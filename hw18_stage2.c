/* hw18_stage2.c
 * Teal Hoffman 
 * EE 160
 * 11/3/2024
 * The purpose of this program is to hard-code two 3x3 matrices and then multiply them together using matrix multiplication
 * ***************************************************************************************************************************
 * NOTES 
 * -----
 * D could be less hard-coded if you defined it as an MxN matrix and E as an NxP matrix. The resulting matrix would be 
 *    a MxP matrix. you would make the rows i < M and the columns j < P. The inner n value would include k < N.
 * 
 * D = [ -1  0  -3 ]
 *     [ -4  -5  -6]
 *     [ -7  -8  -9 ]
 *
 * E = [-2  2  1 ]
 *     [ 1  6  3 ]
 *     [ 5  5  4 ]
 *
 * D * E = F = [ -13  -17  -13 ]
 *             [ -27  -68  -43 ]
 *             [ -39 -107  -67 ]
 *
 * Conceptual Example: finding the top left corner of a rectangle in the F  matrix: 
 * F[0][0] = (D[0][0] * E[0][0]) + (D[0][1] * E[1][0]) + (D[0][2] * E[2][0])  
 * 
 */

#include <stdio.h>

int main(void) {
  int D[3][3] = {{-1,  0, -3}, 
                 {-4, -5, -6}, 
                 {-7, -8, -9}};   // hard-code two 3x3 matrices
  int E[3][3] = {{-2, 2, 1}, 
                 { 1, 6, 3}, 
                 { 5, 5, 4}};
  int F[3][3];                    // declare a 3x3 matrix to store the result 
  int i, j;                       // declare loop variables (i as row, j as column)

  // Show the user what the matrix D looks like 
  printf("The matrix D:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf(" %4i ", D[i][j]);
    }
    printf("\n");
  }
  // Show the user what the matrix E looks like 
  printf("The matrix E:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf(" %4i ", E[i][j]);
    }
    printf("\n");
  }
  // 1st row:
  //F[0][0] = (D[0][0] * E[0][0]) + (D[0][1] * E[1][0]) + (D[0][2] * E[2][0]); 
  //F[0][1] = (D[0][0] * E[0][1]) + (D[0][1] * E[1][1]) + (D[0][2] * E[2][1]); 
  //F[0][2] = (D[0][0] * E[0][2]) + (D[0][1] * E[1][2]) + (D[0][2] * E[2][2]); 
  // 2nd row:
  //F[1][0] = (D[1][0] * E[0][0]) + (D[1][1] * E[1][0]) + (D[1][2] * E[2][0]); 
  //F[1][1] = (D[1][0] * E[0][1]) + (D[1][1] * E[1][1]) + (D[1][2] * E[2][1]); 
  //F[1][2] = (D[1][0] * E[0][2]) + (D[1][1] * E[1][2]) + (D[1][2] * E[2][2]); 
  // 3rd row:
  //F[2][0] = (D[2][0] * E[0][0]) + (D[2][1] * E[1][0]) + (D[2][2] * E[2][0]); 
  //F[2][1] = (D[2][0] * E[0][1]) + (D[2][1] * E[1][1]) + (D[2][2] * E[2][1]); 
  //F[2][2] = (D[2][0] * E[0][2]) + (D[2][1] * E[1][2]) + (D[2][2] * E[2][2]); 

  // Calculating the result matrix F using i and j "for" loops 
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      F[i][j] = (D[i][0] * E[0][j]) + (D[i][1] * E[1][j]) + (D[i][2] * E[2][j]);
    }
  }

  printf("The resulting matrix F = D*E is:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf(" %4i ", F[i][j]);
    }
    printf("\n");
  }
}

/*
Output: 

uhx02:/home/t/tealhoff% nano hw18_part1.c
uhx02:/home/t/tealhoff% gcc -o hw18_part1 hw18_part1.c
uhx02:/home/t/tealhoff% ./hw18_part1
The matrix D:
   -1     0    -3
   -4    -5    -6
   -7    -8    -9
The matrix E:
   -2     2     1
    1     6     3
    5     5     4
The resulting matrix F = D*E is:
  -13   -17   -13
  -27   -68   -43
  -39  -107   -67
uhx02:/home/t/tealhoff%
*/
