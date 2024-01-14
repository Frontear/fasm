#include <stdio.h>

#include "internals.h"
#include "inst.h"

// Basic register manipulation

void LOD(void* m, char r) {
    ((machine*) m)->r0 = ((machine*) m)->r[r - 'a'];
}

void SET(void* m, int8_t v) {
    ((machine*) m)->r0 = v;
}

void STO(void* m, char r) {
    ((machine*) m)->r[r - 'a'] = ((machine*) m)->r0;
}

// Arithmetic

void ADD(void* m, char r1, char r2) {
    ((machine*) m)->r0 = ((machine*) m)->r[r1 - 'a'] + ((machine*) m)->r[r2 - 'a'];
}

void SUB(void* m, char r1, char r2) {
    ((machine*) m)->r0 = ((machine*) m)->r[r1 - 'a'] - ((machine*) m)->r[r2 - 'a'];
}

void MUL(void* m, char r1, char r2) {
    ((machine*) m)->r0 = ((machine*) m)->r[r1 - 'a'] * ((machine*) m)->r[r2 - 'a'];
}

void DIV(void* m, char r1, char r2) {
    ((machine*) m)->r0 = ((machine*) m)->r[r1 - 'a'] / ((machine*) m)->r[r2 - 'a'];
}

// Debugging

void DMP(void* m) {
    for (int i = 0; i < 7; ++i) {
        printf("%c", 'a' + i);
        if (i + 1 != 7) {
            printf("\t");
        }
    }
    printf("\n");

    for (int i = 0; i < 7; ++i) {
        printf("%d", ((machine*) m)->r[i]);
        if (i + 1 != 7) {
            printf("\t");
        }
    }
    printf("\n\n"); // intentional extra spacing
}
