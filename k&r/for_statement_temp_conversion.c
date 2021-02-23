#include <stdio.h>

#define LOWER   0       // lower limit of table
#define UPPER   300     // upper limit of table
#define STEP    20      // degrees of step between table rows

/* print Farenheight-Celcius table in reverse */
int main()
{
    int fahr;
    for (fahr = LOWER; fahr >= UPPER; fahr -= STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
    return 0;
}
