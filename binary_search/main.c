#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "binary_search.h"
#include "rar.h"

typedef struct Args {
    int array_size;
    int search_target;
} Args;

static void
print_help()
{
    printf("Usage:\nbinary_search [array_size] [target]\n");
}

static struct Args *
parse_args(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Error: invalid usage\n");
        print_help();
        exit(1);
    }

    struct Args * arg = malloc(sizeof(Args));

    arg->array_size = atoi(argv[1]);
    arg->search_target = atoi(argv[2]);
    return arg;
}

int
main(int argc, char *argv[])
{
    struct Args *args = parse_args(argc, argv);
    RandArray *rar = rar_create(args->array_size);

    if (!(bs_is_sorted(rar->array, rar->size))) {
        printf("Fatal error: array is not sorted]n");
        exit(1);
    }

    int index = bs_search(args->search_target, rar->array, rar->size);

    if (index == BINARY_SEARCH_NO_RESULT) {
        printf("Search target not found.\n");
    }
    else {
        printf("Search target %d is at position %d\n",
                args->search_target, index);
        printf("Its neighbors are %d and %d.\n",
                rar->array[index-1], rar->array[index+1]);
    }

    free(rar);
    free(args);
    return 0;
}
