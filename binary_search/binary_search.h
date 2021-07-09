#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define BINARY_SEARCH_NO_RESULT -1


/**
 * Checks if the array is sorted in linear time
 */
bool bs_is_sorted(int array[], size_t size);


/**
 * Return integer index of the item in the array.
 * O(log n) time complexity via binary search.
 *
 * Returns BINARY_SEARCH_NO_RESULT (-1) if no match is found.
 */
int bs_search(int target, int array[], size_t size);


#endif  // BINARY_SEARCH_H
