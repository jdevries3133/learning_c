#include "selection_sort.h"
#include <stdio.h>

static void
ui(RandArray *rar)
{
    /**
     * As the user whether they want to print the array
     */
    char response = '\0';
    while (response != 'y' && response != 'n') {
        printf("response: %c\n", response);
        printf("Do you want to print the contents of the array? (y/n)\n");
        response = getchar();
    }
    if (response == 'y') {
        rar_print(rar);
    } else {
        printf("Ok, exiting...\n");
    }
}

int
main()
{
    RandArray *rar = rar_create(100);
    rar_shuffle(rar);

    sel_sort(rar);
    if (sel_is_sorted(rar)) {
        printf("Array successfully sorted!\n");
    } else {
        printf("ERROR: array was not sorted.\n");
    }
        ui(rar);
}
