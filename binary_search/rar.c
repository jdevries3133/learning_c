#include "rar.h"


#ifdef RAR_DEBUG  // generate a simple consecutive array

RandArray *
rar_create(int num_elements)
{
    RandArray * rar = malloc(sizeof(RandArray) + sizeof(int) * num_elements);
    rar->size = num_elements;

    // in debug mode, fill a simple consequtive array
    for (int i = 0; i < rar->size; i++) {
        rar->array[i] = i;
    }

    return rar;
}

#else // generate a random array, as normal

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

#endif // RAR_DEBUG
