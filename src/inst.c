#include "inst.h"

REGISTER_TYPE i; // immediate register

void LOD(void* reg) {
    i = *((REGISTER_TYPE*) reg);
}

void STO(void* reg) {
    *((REGISTER_TYPE*) reg) = i;
}

void SET(REGISTER_TYPE value) {
    i = value;
}
