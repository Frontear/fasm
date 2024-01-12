#ifndef FRONTEAR_FASM_INST
#define FRONTEAR_FASM_INST

#include <stdint.h>

#define REGISTER_TYPE uint8_t

void LOD(void*);
void STO(void*);
void SET(REGISTER_TYPE);

#endif
