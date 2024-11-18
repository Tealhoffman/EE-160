/* hw22.c
 * Teal Hoffman
 * EE 160
 * 11/15/24
 * The purpose of this code is to learn about reading from a file and writing to a file
 */

#include <stdio.h>
#include <stdlib.h>

/* MAIN FUNCTION */
int main(void) {
    /* Delcare Variables */
    FILE *fp;
    char fname[100];
    int c = 0;
    int A[20][2];

    /* Ask User to enter the file name they wish to read */
    printf("please enter the file you want to read: ");
    scanf("%s", fname);
    
    /* Attepmy to open file */
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Error reading file\n");
        return 1;
    }
    else printf("\nfile successfully opened...\n\n");

    /* Read the file */
    while (fscanf(fp, "%d,%d", &A[c][0], &A[c][1]) == 2) {
           c++;
           printf("reading line %i\n", c);
    }
    
    /* Print data temporarily stored in Array A[] */
    size_t i=0;
    printf("Data stored is:\n");
    for (i=0; i<c; i++) {
        printf("%d,%d   \n", A[i][0], A[i][1]);
    }
    
    /* Close file and exit */
    printf("\nClosing file...\n\n");
    fclose(fp);

    /* Separate array A into 1D arrarys: A1 and A2. Where A1 is the first column and A2 is the second column */
    int A1[c]; 
    int A2[c]; 
    for (i = 0; i < c; i++) { 
        A1[i] = A[i][0];
        A2[i] = A[i][1];
    }

    /* Show the user the data stored in A1 and A2 */
    printf("Data in A1 is:\n"); 
    for (i=0; i<c; i++) { 
        printf("%i ", A1[i]); 
    }
    printf("\n");

    printf("Data in A2 is:\n"); 
    for (i=0; i<c; i++) { 
        printf("%i ", A2[i]); 
    }
    printf("\n");

    

    return 0;
}



/*
uhx02:/home/t/tealhoff% nano hw22.c
uhx02:/home/t/tealhoff% gcc -o hw22 hw22.c
uhx02:/home/t/tealhoff% ./hw22
please enter the file you want to read: hw22.csv

file successfully opened...

reading line 1
reading line 2
reading line 3
reading line 4
reading line 5
reading line 6
reading line 7
reading line 8
reading line 9
reading line 10
reading line 11
reading line 12
reading line 13
reading line 14
reading line 15
reading line 16
reading line 17
reading line 18
reading line 19
reading line 20
Data stored is:
7,31
5,32
6,29
9,18
-2,26
-5,29
3,31
6,35
8,38
11,33
4,31
3,30
3,29
6,35
9,27
1,36
6,33
4,32
3,30
6,21

Closing file...

Data in A1 is:
7 5 6 9 -2 -5 3 6 8 11 4 3 3 6 9 1 6 4 3 6
Data in A2 is:
31 32 29 18 26 29 31 35 38 33 31 30 29 35 27 36 33 32 30 21
uhx02:/home/t/tealhoff%
*/