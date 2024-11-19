/* hw23.c
 * Teal Hoffman 
 * EE 160 
 * 11/18/24
 * NOTE TO USER: The 51st and 52nd data points are not real data points and are used to test the code 
 **********************************************************************************************************
 * TOPIC: STRUCTS 
 * The PURPOSE of this code is to take real data of minor earthquakes in a 10 day period 
 *    in the local area on Hawaii island. The data includes the date and time that the earthquakes
 *    occured. These are events that are recorded in universal coordinated time for Earth (UTC).
 *    The goal is to convert this time into Hawaii standard time (HST) which is 10 hours behind UTC.
 *    Also to convert the depth from kilometers to feet. (3280 ft for 1km) 
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
 *    Create a new file pointer and name it fw 
 *    Decalre a user defined struct including all the 8 data types: 'earthquake'
 *    Open hw23.csv file and read only ("r")
 *    Display error message if file not found 
 *    Save the data to the struct (user defined) 'earthquake' 
 *    Tell user the data has been read and provide error message if the data cannot be read
 *    Show the data in UTC and kilometers 
 *    Close the file and exit 
 *    Use if statements to change the date and time from UTC to HST 
 *    Change the depth from kilometers to feet 
 *    Show the new changed data in HST and feet 
 *    Open the file as a read and write file ("w")
 *    Attempt to open the file and name it 'hw23_output.csv' 
 *    Display an error message if the file is not found
 *    Print to file 
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
    struct earthquake E[52]; 

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
    printf("   AGNCY| MNT/DAY/YR|HR:MIN| MAG| DEPTH|\n");
    printf("   =====| ==========|======| ===| =====|\n");
    for (i=0; i<c; i++) {
        printf( "%02i) %4s| %02d/%02d/%4d| %02d:%02d| %.1f| %5.2f| \n", 
        i+1, E[i].agency, E[i].month, E[i].day, E[i].year, E[i].hour, E[i].min, E[i].mag, E[i].depth);
    }

    /* Close file and exit */
    printf("Closing file...\n\n");
    fclose(fp);

    /* Use if statements to change UTC to HST */
    for (i=0; i<c; i++) {
        E[i].hour = E[i].hour - 10;   // To convert to HST subtract 10 from the hours 

        if (E[i].hour <= 0) {            // If the hour becomes negative then subtract 1 from the day and add 24 to hours 
            E[i].day = E[i].day - 1;
            E[i].hour = E[i].hour + 24;

            if (E[i].day == 0) {         // If the day becomes 0 then subtract 1 from the month 
                E[i].month = E[i].month - 1;
                
                if (E[i].month == 0) {       // If the month becomes 0 then subtract 1 from the year and add 12 (12 months in a year)
                    E[i].year = E[i].year -1;
                    E[i].month = E[i].month + 12; 
                }

                int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};   // Create an array for days in each month
                E[i].day = days_in_month[E[i].month - 1];    // Set the day to the corresponding month 

                // If statement for leap years
                // If it is Feburary and the year is divisible by 4 as well as that year NOT being divisible by 100 or if it is 
                //    divisible by 400 then it is a leap year and month 2 has 29 days instead of 28
                if (E[i].month == 2 && (E[i].year % 4 == 0 && (E[i].year % 100 != 0 || E[i].year % 400 == 0))) {
                    E[i].day = 29;  // February has 29 days in a leap year
                }

            }
        }

    }

    /* Change kilometers to feet */
    for (i=0; i<c; i++) {
        E[i].depth = E[i].depth * 3280;
    }

    /* Print converted data */
    printf("Data converted to HST is:\n");
    printf("   AGNCY| MNT/DAY/YR|HR:MIN| MAG|   DEPTH  |\n");
    printf("   =====| ==========|======| ===| =========|\n");
    for (i=0; i<c; i++) {
        printf( "%02i) %4s| %02d/%02d/%4d| %02d:%02d| %.1f| %9.2f| \n", 
        i+1, E[i].agency, E[i].month, E[i].day, E[i].year, E[i].hour, E[i].min, E[i].mag, E[i].depth);
    }

    /* Attempt to open file */
    fw = fopen("hw23_output.csv", "w");
    if (fw == NULL) {
        printf("Unable to open file\n");
        return 1;
    }
    else printf("\nfile successfully opened...\n");

    /* Print to file and print on screen */
    for (i=0; i<c; i++) {
        fprintf(fw, "%4s, %d, %d, %d, %d, %d, %.1f, %.2f\n", 
            E[i].agency, E[i].month, E[i].day, E[i].year, E[i].hour, E[i].min, E[i].mag, E[i].depth);
    }

    /* Close file and exit */
    printf("\nClosing file...\n\n");
    fclose(fp);
    
    return 0;
}



/*
uhx02:/home/t/tealhoff% gcc -o hw23 hw23.c
uhx02:/home/t/tealhoff% ./hw23

file successfully opened...

Data stored in UTC and Kilometers:

   AGNCY| MNT/DAY/YR|HR:MIN| MAG| DEPTH|
   =====| ==========|======| ===| =====|
01) USGS| 10/08/2019| 23:02| 2.5| -1.07|
02) USGS| 10/08/2019| 17:27| 2.5|  3.53|
03) USGS| 10/08/2019| 13:05| 4.0| 16.32|
04) EMSC| 10/08/2019| 13:05| 3.6| 15.01|
05) USGS| 10/08/2019| 00:33| 2.8| 33.60|
06) USGS| 10/06/2019| 15:57| 2.5|  0.32|
07) USGS| 10/04/2019| 01:52| 2.5|  1.44|
08) EMSC| 10/04/2019| 01:52| 2.9|  1.13|
09) USGS| 10/03/2019| 06:10| 2.6|  6.52|
10) USGS| 10/01/2019| 05:12| 2.5|  0.05|
11) USGS| 09/30/2019| 13:38| 2.5| 32.20|
12) USGS| 09/30/2019| 06:23| 2.5| 28.60|
13) USGS| 09/30/2019| 02:32| 2.5|  8.60|
14) USGS| 09/29/2019| 10:06| 2.8| 24.92|
15) USGS| 09/29/2019| 09:45| 2.6| 28.30|
16) USGS| 09/29/2019| 08:17| 2.9|  0.22|
17) EMSC| 09/29/2019| 08:17| 2.9|  1.20|
18) USGS| 09/28/2019| 06:13| 2.5| 13.60|
19) USGS| 09/27/2019| 01:12| 2.8|  8.62|
20) USGS| 09/26/2019| 17:14| 2.6| 40.30|
21) USGS| 09/25/2019| 00:43| 2.5| 34.10|
22) USGS| 09/24/2019| 11:02| 2.7|  7.03|
23) USGS| 09/21/2019| 09:31| 2.7|  1.90|
24) USGS| 09/21/2019| 09:31| 2.8|  0.90|
25) USGS| 09/21/2019| 09:23| 2.6|  1.38|
26) USGS| 09/20/2019| 22:32| 2.6| 12.20|
27) USGS| 09/20/2019| 03:04| 2.6|  2.20|
28) USGS| 09/18/2019| 03:34| 2.5|  1.09|
29) USGS| 09/16/2019| 19:00| 2.8|  6.33|
30) USGS| 09/16/2019| 12:06| 3.0| 33.40|
31) USGS| 09/15/2019| 12:55| 2.5| 34.70|
32) USGS| 09/14/2019| 08:58| 2.5| 32.62|
33) USGS| 09/14/2019| 01:48| 2.5|  9.41|
34) USGS| 09/13/2019| 00:52| 2.5| 33.02|
35) USGS| 09/12/2019| 11:49| 2.9| 32.20|
36) EMSC| 09/12/2019| 11:49| 2.9| 33.75|
37) USGS| 09/12/2019| 08:00| 2.5|  0.32|
38) USGS| 09/11/2019| 14:22| 2.9|  0.56|
39) EMSC| 09/11/2019| 14:22| 2.9|  0.43|
40) USGS| 09/11/2019| 13:36| 2.8| -0.16|
41) USGS| 09/10/2019| 08:24| 3.5| 32.20|
42) EMSC| 09/10/2019| 08:24| 3.2| 33.60|
43) USGS| 09/09/2019| 14:29| 2.6| 32.77|
44) USGS| 09/08/2019| 18:40| 2.5| 34.61|
45) USGS| 09/08/2019| 09:55| 2.5| 35.31|
46) USGS| 09/07/2019| 19:11| 2.5|  6.60|
47) EMSC| 09/07/2019| 05:58| 3.2|  2.10|
48) USGS| 09/07/2019| 05:58| 3.2|  2.70|
49) USGS| 09/07/2019| 05:58| 3.2|  0.32|
50) USGS| 09/06/2019| 23:12| 2.6| -1.38|
Closing file...

Data converted to HST is:
   AGNCY| MNT/DAY/YR|HR:MIN| MAG|   DEPTH  |
   =====| ==========|======| ===| =========|
01) USGS| 10/08/2019| 13:02| 2.5|  -3509.60|
02) USGS| 10/08/2019| 07:27| 2.5|  11578.40|
03) USGS| 10/08/2019| 03:05| 4.0|  53529.60|
04) EMSC| 10/08/2019| 03:05| 3.6|  49232.80|
05) USGS| 10/07/2019| 14:33| 2.8| 110207.99|
06) USGS| 10/06/2019| 05:57| 2.5|   1049.60|
07) USGS| 10/03/2019| 15:52| 2.5|   4723.20|
08) EMSC| 10/03/2019| 15:52| 2.9|   3706.40|
09) USGS| 10/02/2019| 20:10| 2.6|  21385.60|
10) USGS| 09/30/2019| 19:12| 2.5|    164.00|
11) USGS| 09/30/2019| 03:38| 2.5| 105616.00|
12) USGS| 09/29/2019| 20:23| 2.5|  93808.00|
13) USGS| 09/29/2019| 16:32| 2.5|  28208.00|
14) USGS| 09/28/2019| 24:06| 2.8|  81737.60|
15) USGS| 09/28/2019| 23:45| 2.6|  92824.00|
16) USGS| 09/28/2019| 22:17| 2.9|    721.60|
17) EMSC| 09/28/2019| 22:17| 2.9|   3936.00|
18) USGS| 09/27/2019| 20:13| 2.5|  44608.00|
19) USGS| 09/26/2019| 15:12| 2.8|  28267.04|
20) USGS| 09/26/2019| 07:14| 2.6| 132184.00|
21) USGS| 09/24/2019| 14:43| 2.5| 111847.99|
22) USGS| 09/24/2019| 01:02| 2.7|  23058.40|
23) USGS| 09/20/2019| 23:31| 2.7|   6232.00|
24) USGS| 09/20/2019| 23:31| 2.8|   2952.00|
25) USGS| 09/20/2019| 23:23| 2.6|   4526.40|
26) USGS| 09/20/2019| 12:32| 2.6|  40016.00|
27) USGS| 09/19/2019| 17:04| 2.6|   7219.28|
28) USGS| 09/17/2019| 17:34| 2.5|   3581.76|
29) USGS| 09/16/2019| 09:00| 2.8|  20762.40|
30) USGS| 09/16/2019| 02:06| 3.0| 109552.01|
31) USGS| 09/15/2019| 02:55| 2.5| 113822.56|
32) USGS| 09/13/2019| 22:58| 2.5| 106993.59|
33) USGS| 09/13/2019| 15:48| 2.5|  30864.80|
34) USGS| 09/12/2019| 14:52| 2.5| 108305.60|
35) USGS| 09/12/2019| 01:49| 2.9| 105616.00|
36) EMSC| 09/12/2019| 01:49| 2.9| 110696.72|
37) USGS| 09/11/2019| 22:00| 2.5|   1049.60|
38) USGS| 09/11/2019| 04:22| 2.9|   1840.08|
39) EMSC| 09/11/2019| 04:22| 2.9|   1413.68|
40) USGS| 09/11/2019| 03:36| 2.8|   -518.24|
41) USGS| 09/09/2019| 22:24| 3.5| 105616.00|
42) EMSC| 09/09/2019| 22:24| 3.2| 110207.99|
43) USGS| 09/09/2019| 04:29| 2.6| 107485.60|
44) USGS| 09/08/2019| 08:40| 2.5| 113520.80|
45) USGS| 09/07/2019| 23:55| 2.5| 115816.80|
46) USGS| 09/07/2019| 09:11| 2.5|  21648.00|
47) EMSC| 09/06/2019| 19:58| 3.2|   6888.00|
48) USGS| 09/06/2019| 19:58| 3.2|   8856.00|
49) USGS| 09/06/2019| 19:58| 3.2|   1049.60|
50) USGS| 09/06/2019| 13:12| 2.6|  -4513.28|

file successfully opened...

Closing file...

uhx02:/home/t/tealhoff%
*/