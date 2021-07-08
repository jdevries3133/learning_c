#include <stdio.h>
#include <assert.h>

#include "binary_search.h"
#include "rar.h"


int
main()
{
    int num_elements = 100;
    RandArray *rar = rar_create(num_elements);
    for (int i = 0; i < rar->size; i++) {
        printf("%d\n", rar->array[i]);
        if (i > 0) {
            assert(rar->array[i] > rar->array[i - 1]);
        }
    }
    return 0;
}
