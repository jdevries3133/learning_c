#include <stdio.h>
#include <stdlib.h>

/* The cat we all know and love!
*/

int main( int argc, char *argv[] )
{
    FILE* fp;
    char str[80];
    const size_t line_size = 80;
    fp = fopen(argv[1], "r");
    int length = 0;
    while (fgets(str, line_size, fp) != NULL) {
        length ++;
        printf("%s", str);
    }
}
