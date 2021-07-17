/**
 * Follow-along with the YouTube tutorial on creating a virtual machine
 * "Creating a VM / Compiler Episode 1: Bytecode VM" by jephthai
 * https://www.youtube.com/watch?v=DUNkdl0Jhgs
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define HALT_INSTR 'h'


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

STACK
stack_new(int size)
{
    STACK s;
    s.top = 0;
    s.size = size;
    s.stack = malloc(sizeof(OBJECT) * size);
    return s;
}

int
stack_push(STACK *s, OBJECT o)
{
    s->stack[s->top++] = o;
    return s->top;
}

OBJECT
stack_pop(STACK *s)
{
    return s->stack[--(s->top)];
}

OBJECT
stack_peek(STACK *s)
{
    return s->stack[s->top - 1];
}

void usage() {
    printf("usage: vm <file>\n");
    exit(1);
}

uint8_t
*load_file(char *filename)
{
    FILE *f;
    int size;
    uint8_t *code = NULL;
    struct stat st;

    if ((f = fopen(filename, "r"))) {
        fstat(fileno(f), &st);
        code = malloc(sizeof(uint8_t) * st.st_size);
        fread((void *)code, 1, st.st_size, f);
    } else {
        printf("ERROR: could not open file %s\n", filename);
        usage();
    }
    return code;
}


/******************************************************************************
 * op codes
 */

uint8_t
*op_nop(uint8_t *ip, STACK *s)
{
    return ip;
}

uint8_t
*op_push_char(uint8_t *ip, STACK *s)
{
    OBJECT o;
    o.type = 'c';
    o.u8 = *(ip +1);
    stack_push(s, o);
    return ip + 2;
}

uint8_t
*op_emit(uint8_t *ip, STACK *s)
{
    OBJECT o = stack_pop(s);
    putchar(o.u8);
    return ip + 1;
}

int
main(int argc, char **argv)
{
    uint8_t *code;
    uint8_t *ip;  // instruction pointer
    STACK data;
    instruction ops[256];

    if (argc != 2) {
        usage();
    }

    // initialize all op slots to nop
    for (int i = 0; i < 256; i++) {
        ops[i] = op_nop;
    }

    ops['c'] = op_push_char;
    ops['e'] = op_emit;

    code = load_file(argv[1]);
    data = stack_new(1024);
    ip = code;  // initialize instruction ponter to the start of the code

    while (*ip != HALT_INSTR) {
        ip = ops[*ip](ip, &data);
    }

    return 0;
}
