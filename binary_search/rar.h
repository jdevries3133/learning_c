/**
 * Utilities for generating random arrays of sorted integers
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


/* If defined, a consecutive array will be generated instead ([0, 1, 2...]) */ 
/* #define RAR_DEBUG */

#ifndef RAR_DEBUG
    /* max gap between random integer array members.
     * Likelihood of finding the search target is 1 / RAR_GAP
     */
    #define RAR_MAX_GAP 3
#endif

typedef struct rar_RandArray {
    size_t size;
    int array[];
} RandArray;


/**
 * Create a random array of sorted random numbers between zero and RAND_MAX
 */
RandArray *rar_create(int num_elements);
