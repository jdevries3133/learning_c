#include "util.h"

void
usage()
{
    printf("usage: vm <file>\n");
    exit(1);
}

uint8_t
*load_file(char *filename)
{
    FILE *f;
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
