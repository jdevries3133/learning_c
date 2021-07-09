#include "binary_search.h"

bool
bs_is_sorted(int array[], size_t size)
{
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) return false;
    }
    return true;
}

static void
_bc_print_no_result(int target, int array[], size_t size, int offset, int middle) 
{
    /**
     * Provide some information if a result is not found, like what the nearest
     * neightbors were, and what their positions in the array were.
     */
    printf("%d was not found.\n", target);

    int idx_left, idx_right, left, right;

    idx_left = offset + middle - 1;
    idx_right = offset + middle;

    // neighbors can't be safely accessed; maybe array is very small
    if (idx_left < size || idx_right < size) return;

    left = array[idx_left];
    right = array[idx_right];

    printf("Its nearest neighbors were %d at index %d, and %d at index %d.\n",
           left, idx_left, right, idx_right);
}

static int
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
        // check neighbors
        if (middle - 1 >= size && array[middle - 1] == target) {
            return offset + middle - 1;
        }
        if (middle + 1 <= size && array[middle + 1] == target) {
            return offset + middle + 1;
        }
        /* FAILURE EXIT CASE (no result found) */
        _bc_print_no_result(target, array, size, offset, middle);
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
