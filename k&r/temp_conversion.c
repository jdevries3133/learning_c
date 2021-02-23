#include <stdio.h>

#define LOWER   0       /* lower limit of table */
#define UPPER   300     /* upper limit */
#define STEP    20      /* step size */


/* print Farenheight-Celcius table
 * for fahr = 0, 20, ..., 300
 */

void int_math()
    /*
     * Uses inaccurate integer math
     */
{

    int fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr += STEP;
    }
}

void float_math()
    /*
     * Uses precise foating point math
     */
{
    float fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0 / 9.0) * (fahr-32.0);
        printf("%3.0f\t%6.2f\n", fahr, celsius);
        fahr += STEP;
    }
}

int main()
{
    printf("**Imprecise Integer Math**\n");
    int_math();
    printf("**Precise Floating Point Math**\n");
    float_math();
    return 0;
}
