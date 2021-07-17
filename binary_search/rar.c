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
rar_shuffle(RandArray *rar)
{
    srand(time(NULL));
    int temp;
    int swap1;
    int swap2;

    for (int i = 0; i < rar->size * 2; i++) {
        swap1 = rand() % rar->size;
        swap2 = rand() % rar->size;
        temp = rar->array[swap1];
        rar->array[swap1] = rar->array[swap2];
        rar->array[swap2] = temp;
    }
}

void
rar_print(RandArray *rar)
{
    printf("Index\tValue\n");
    for (int i = 0; i < rar->size; i++) {
        printf("%d\t%d\n", i, rar->array[i]);
    }
}
