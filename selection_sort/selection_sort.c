#include "selection_sort.h"

void
sel_sort(RandArray *rar)
{
}

bool sel_is_sorted(RandArray *rar)
{
    for (int i = 1; i < rar->size; i++) {
        if (rar->array[i] < rar->array[i - 1]) {
            return false;
        }
    }
    return true;
}
