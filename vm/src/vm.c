/**
 * Follow-along with the YouTube tutorial on creating a virtual machine
 * "Creating a VM / Compiler Episode 1: Bytecode VM" by jephthai
 * https://www.youtube.com/watch?v=DUNkdl0Jhgs
 */

#include "vm.h"





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

    while (*ip != 'h') {
        ip = ops[*ip](ip, &data);
    }

    return 0;
}
