#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "inst.h"

int main(void) {
    REGISTER_TYPE* a;
    REGISTER_TYPE* b;
    REGISTER_TYPE* c;

    REGISTER_TYPE* buffer = malloc(sizeof(REGISTER_TYPE) * 3);

    if (!buffer) {
        return -1;
    }

    a = &(buffer[0]);
    b = &(buffer[1]);
    c = &(buffer[2]);

    SET(10);
    STO(a);

    SET(50);
    STO(b);

    printf("a   b   c\n");
    printf("%d  %d  %d\n", *a, *b, *c);

    free(buffer);

    return 0;
}
