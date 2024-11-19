/* hw23.c
 * Teal Hoffman 
 * EE 160 
 * 11/18/24
 **********************************************************************************************************
 * TOPIC: STRUCTS 
 * The PURPOSE of this code is to take real data of minor earthquakes in a 10 day period 
 *    in the local area on Hawaii island. The data includes the date and time that the earthquakes
 *    occured. These are events that are recorded in universal coordinated time for Earth (UTC).
 *    The goal is to convert this time into Hawaii standard time (HST) which is 10 hours behind UTC.
 *    Also to convert the depth from kilometers to feet. (3280 fr for 1km) 
 **********************************************************************************************************
 * DATA IN CSV FILE 
 *    Reporting Agency (string)
 *    Month (integer)
 *    Day (integer)
 *    Year (integer)
 *    Hour (integer) - 24 hr clock
 *    Minute (integer) - Range is 0-60
 *    Magnitude (float) - Richter Scale 
 *    Depth (float) - In Kilometers 
 **********************************************************************************************************
 * PSEUDOCODE (High Level)
 *    Declare all variables
 *    Create a file pointer and name it fp 
 *    Decalre a user defined struct including all the 8 data types: 'earthquake'
 *    Open hw23.csv file and read only ("r")
 *    Display error message if file not found 
 *    Save the data to the struct (user defined) 'earthquake' 
 *    Tell user the data has been read and provide error message if the data cannot be read
 *    Close the file and exit 
 *    Show the data in UTC and kilometers 
 *    Use if statements to change the date and time from UTC to HST 
 *    Change the depth from kilometers to feet 
 *    Show the new changed data in HST and feet 
 *    Create a new file pointer and name it fw 
 *    Open the file as a read and write file ("w")
 *    Attempt to open the file and name it 'hw23_output.csv' 
 *    Display an error message if the file is not found
 *    Print to file and print on screen
 *    Close the file and exit
 ********************************************************************************************************** 
 */

#include <stdio.h>
#include <stdlib.h>

/* MAIN FUNCTION */
int main(void) {
    /* Declare variables */
    int c = 0; 
    int i = 0;

    /* Create file pointers */
    FILE *fp;
    FILE *fw;

    /* Create a struct with type 'earthquake' */
    struct earthquake {
        char agency[10];      // Reporting agency
        int month;           // Month 
        int day;             // Day
        int year;            // Year
        int hour;            // Hour (24 hour clock)
        int min;             // Minute (0 - 60 Range)
        float mag;           // Magnitude of earthquake (Richter scale)
        float depth;         // Depth in kilometers 
    };

    /* Name the struct */
    struct earthquake E[50]; 

    /* Attempt to open file */
    fp = fopen("hw23.csv", "r");   // "r" is read only
    if (fp == NULL) {
        printf("Error Reading file\n");
        return 1;
    }
    else printf("\nfile successfully opened...\n");

    /* Read the file */
    while (fscanf(fp, "%4s, %d, %d, %d, %d, %d, %f, %f", 
        E[c].agency, &E[c].month, &E[c].day, &E[c].year, &E[c].hour, &E[c].min, &E[c].mag, &E[c].depth) == 8) {
            c++;
            // printf("reading line %i\n", c);
        }
    printf("\n");

    /* Print data temporarily stored in arrray of struct */
    printf("Data stored in UTC and Kilometers:\n\n");
    printf("    AGNCY MON DAY YEAR HOUR MIN MAG  DEPTH\n");
    printf("    ===== === === ==== ==== === ===  =====\n");
    for (i=0; i<c; i++) {
        printf( "%02i) %4s, %02d, %02d, %4d, %02d, %02d, %.1f, %.2f \n", 
        i+1, E[i].agency, E[i].month, E[i].day, E[i].year, E[i].hour, E[i].min, E[i].mag, E[i].depth);
    }

    /* Close file and exit */
    printf("Closing file...\n\n");
    fclose(fp);

    /* Use if statements to change  */
    // er[].agency = E[c][0]   (the first column will be the reporting agency column)


    return 0;
}


/*
uhx02:/home/t/tealhoff% ./hw23_v1

file successfully opened...

Data stored in UTC and Kilometers:

    AGNCY MON DAY YEAR HOUR MIN MAG  DEPTH
    ===== === === ==== ==== === ===  =====
01) USGS, 10, 08, 2019, 23, 02, 2.5, -1.07
02) USGS, 10, 08, 2019, 17, 27, 2.5, 3.53
03) USGS, 10, 08, 2019, 13, 05, 4.0, 16.32
04) EMSC, 10, 08, 2019, 13, 05, 3.6, 15.01
05) USGS, 10, 08, 2019, 00, 33, 2.8, 33.60
06) USGS, 10, 06, 2019, 15, 57, 2.5, 0.32
07) USGS, 10, 04, 2019, 01, 52, 2.5, 1.44
08) EMSC, 10, 04, 2019, 01, 52, 2.9, 1.13
09) USGS, 10, 03, 2019, 06, 10, 2.6, 6.52
10) USGS, 10, 01, 2019, 05, 12, 2.5, 0.05
11) USGS, 09, 30, 2019, 13, 38, 2.5, 32.20
12) USGS, 09, 30, 2019, 06, 23, 2.5, 28.60
13) USGS, 09, 30, 2019, 02, 32, 2.5, 8.60
14) USGS, 09, 29, 2019, 10, 06, 2.8, 24.92
15) USGS, 09, 29, 2019, 09, 45, 2.6, 28.30
16) USGS, 09, 29, 2019, 08, 17, 2.9, 0.22
17) EMSC, 09, 29, 2019, 08, 17, 2.9, 1.20
18) USGS, 09, 28, 2019, 06, 13, 2.5, 13.60
19) USGS, 09, 27, 2019, 01, 12, 2.8, 8.62
20) USGS, 09, 26, 2019, 17, 14, 2.6, 40.30
21) USGS, 09, 25, 2019, 00, 43, 2.5, 34.10
22) USGS, 09, 24, 2019, 11, 02, 2.7, 7.03
23) USGS, 09, 21, 2019, 09, 31, 2.7, 1.90
24) USGS, 09, 21, 2019, 09, 31, 2.8, 0.90
25) USGS, 09, 21, 2019, 09, 23, 2.6, 1.38
26) USGS, 09, 20, 2019, 22, 32, 2.6, 12.20
27) USGS, 09, 20, 2019, 03, 04, 2.6, 2.20
28) USGS, 09, 18, 2019, 03, 34, 2.5, 1.09
29) USGS, 09, 16, 2019, 19, 00, 2.8, 6.33
30) USGS, 09, 16, 2019, 12, 06, 3.0, 33.40
31) USGS, 09, 15, 2019, 12, 55, 2.5, 34.70
32) USGS, 09, 14, 2019, 08, 58, 2.5, 32.62
33) USGS, 09, 14, 2019, 01, 48, 2.5, 9.41
34) USGS, 09, 13, 2019, 00, 52, 2.5, 33.02
35) USGS, 09, 12, 2019, 11, 49, 2.9, 32.20
36) EMSC, 09, 12, 2019, 11, 49, 2.9, 33.75
37) USGS, 09, 12, 2019, 08, 00, 2.5, 0.32
38) USGS, 09, 11, 2019, 14, 22, 2.9, 0.56
39) EMSC, 09, 11, 2019, 14, 22, 2.9, 0.43
40) USGS, 09, 11, 2019, 13, 36, 2.8, -0.16
41) USGS, 09, 10, 2019, 08, 24, 3.5, 32.20
42) EMSC, 09, 10, 2019, 08, 24, 3.2, 33.60
43) USGS, 09, 09, 2019, 14, 29, 2.6, 32.77
44) USGS, 09, 08, 2019, 18, 40, 2.5, 34.61
45) USGS, 09, 08, 2019, 09, 55, 2.5, 35.31
46) USGS, 09, 07, 2019, 19, 11, 2.5, 6.60
47) EMSC, 09, 07, 2019, 05, 58, 3.2, 2.10
48) USGS, 09, 07, 2019, 05, 58, 3.2, 2.70
49) USGS, 09, 07, 2019, 05, 58, 3.2, 0.32
50) USGS, 09, 06, 2019, 23, 12, 2.6, -1.38
Closing file...

uhx02:/home/t/tealhoff%
*/