//
//  ctime.c
//  
// REf: https://www.gnu.org/software/libc/manual/html_node/Simple-Calendar-Time.html
//  Created by Simpy on 2019-03-14.
//

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    time_t current_time; //Data Type: time_t. This is the data type used to represent simple time. When interpreted as a calendar time value, it represents the number of seconds elapsed since 00:00:00 on January 1, 1970, Coordinated Universal Time. (This calendar time is sometimes referred to as the epoch.) time_t as 64 bit signed.
    char* c_time_string;
    
    /* Obtain current time. */
    current_time = time(NULL);
    
    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }
    
    /* Convert to local time format. */
    c_time_string = ctime(&current_time);
    
    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }
    
    /* Print to stdout. ctime() has already added a terminating newline character. */
    (void) printf("Current time is %s", c_time_string);
    exit(EXIT_SUCCESS);
}
