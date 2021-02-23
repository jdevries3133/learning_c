#include <stdio.h>

/* count lines in input */

int main(int argc, char *argv[])
{
    if (argc <= 1)
        printf("No character provided for counting");
        return 1;
    char count = argv[1][1];
    printf("Counting %c", count);

    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == count)
            ++nl;
    printf("%d\n", nl);
}

