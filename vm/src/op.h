#include <stdint.h>
#include <stdio.h>

#include "stack.h"

uint8_t *op_nop(uint8_t *ip, STACK *s);
uint8_t *op_push_char(uint8_t *ip, STACK *s);
uint8_t *op_emit(uint8_t *ip, STACK *s);
