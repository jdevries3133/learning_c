#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdlib.h>

typedef struct OBJECT_t
{
    uint8_t type;

    union {
        uint8_t     u8;
        int8_t      i8;
        uint32_t    u32;
        int32_t     i32;
        void        *ptr;
    };
} OBJECT;

typedef struct STACK_t
{
    int top;
    int size;
    OBJECT *stack;
} STACK;

/** Defines "instruction" as a pointer to a function that takes an op code and
 * a stack, and returns a uint_8 (the new instruction pointer)
 */
typedef uint8_t* (*instruction)(uint8_t *ip, STACK *);


STACK stack_new(int size);
int stack_push(STACK *s, OBJECT o);
OBJECT stack_pop(STACK *s);
OBJECT stack_peek(STACK *s);

#endif  // STACK_H
