#include <stdint.h>
#include <stdlib.h>

#include "internals.h"
#include "machine.h"

void* init_machine() {
    machine* m = calloc(1, sizeof(machine)); // its very important registers are empty

    return m;
}

void halt_machine(void* m) {
    free(m);
}
