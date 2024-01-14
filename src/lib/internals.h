#ifndef FRONTEAR_FASM_INTERNALS
#define FRONTEAR_FASM_INTERNALS

#include <stdint.h>

typedef struct {
    int8_t r0;          // the 0th register, holds a value from the most recent operation
    int8_t r[7];        // the 7 other registers, free to be modified as needed. will NOT change unless explicitly called for with STO
} machine;

#endif
