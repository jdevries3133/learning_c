#include "rar.h"

RandArray *
rar_create(int num_elements)
{
    RandArray * rar = malloc(sizeof(RandArray) + sizeof(int) * num_elements);
    rar->size = num_elements;

    rar->array[0] = rand();
    for (int i = 1; i < rar->size; i++) {
        // add a random number between 1 and 9 to the previous number
        int prev = rar->array[i - 1];
        int next = prev + rand() % 10 + 1;
        rar->array[i] = next;
    }
    return rar;
}
