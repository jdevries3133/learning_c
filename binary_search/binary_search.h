#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdbool.h>
#include <stddef.h>


/**
 * Checks if the array is sorted in linear time
 */
bool is_sorted(int array[], size_t size);


/**
 * Return integer index of the item in the array.
 * O(log n) time complexity via binary search.
 */
int search(int item, int array[], size_t size);


#endif  // BINARY_SEARCH_H
