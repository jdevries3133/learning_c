/**
 * Utilities for generating random arrays of sorted integers
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


/* If defined, a consecutive array will be generated instead ([0, 1, 2...]) */ 
#define RAR_DEBUG

typedef struct rar_RandArray {
    size_t size;
    int array[];
} RandArray;


/**
 * Create a random array of sorted random numbers between zero and RAND_MAX
 */
RandArray *rar_create(int num_elements);
