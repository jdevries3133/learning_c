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
    srand(time(NULL));
    RandArray * rar = malloc(sizeof(RandArray) + sizeof(int) * num_elements);
    rar->size = num_elements;

    rar->array[0] = 0;
    for (int i = 1; i < rar->size; i++) {
        // add a random number between 1 and 9 to the previous number
        int prev = rar->array[i - 1];
        int next = prev + random() % RAR_MAX_GAP + 1;
        rar->array[i] = next;
    }
    return rar;
}

#endif // RAR_DEBUG


void
rar_print(RandArray * rar)
{
    /* allocate 5 characters for each integer in the array */
    size_t outbuf_size = 0;
    size_t outbuf_limit = rar->size * 5;
    char outbuf[sizeof(char) * outbuf_limit];

    size_t line_length = 0;
    for (int i = 0; i < rar->size; i++) {
    }
}
