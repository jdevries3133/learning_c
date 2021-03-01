#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main ()
{
    printf("Hello from main\n");

    Birthday bd;

    int birth_year = 2019;
    int birth_month = 4;
    int birth_date = 25;

    insert_birthday(&birth_year, &birth_month, &birth_date, &bd);

    printf("Created Birthday:\n");

    int *p = NULL;
    print_birthday(&bd, p);

    printf("\n\n");

    char name[] = "Timmy Timson";
    Person * timmy = alloc_person(name, &bd);

    print_person(timmy);

    free(timmy);

    return 0;
}
