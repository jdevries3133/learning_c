#include "binary_search.h"

bool
bs_is_sorted(int array[], size_t size)
{
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) return false;
    }
    return true;
}

int
_bc_recurse_search(int target, int array[], size_t size, int offset)
{
    /**
     * Where offset + size is the index in the full array. Otherwise, the
     * recursive calls are unaware of the larger array and cannot return an
     * accurate result, because their result is in the context of the slice
     * of the array that they search.
     */

    int middle = size / 2;

    if (middle == 0) {
        /* FAILURE EXIT CASE (no result found) */
        return BINARY_SEARCH_NO_RESULT;
    }

    int result = array[middle];
    if (result > target) {
        return _bc_recurse_search(target, array, middle, offset);
    } else if (result < target) {
        return _bc_recurse_search(target, &array[middle],
                                  middle, middle + offset);
    } 

    /* SUCCESS EXIT CASE (result == target) */
    return middle + offset;
}

int bs_search(int target, int array[], size_t size)
{
    return _bc_recurse_search(target, array, size, 0);
}
