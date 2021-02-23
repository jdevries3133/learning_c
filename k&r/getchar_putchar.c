/*
 * flow of the program:
 * read a character
 * while (character is not end-of-file indicator)
 *      output the character just read
 *      read a character
 */

#include <stdio.h>

int main()
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
