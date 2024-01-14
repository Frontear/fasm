#ifndef FRONTEAR_FASM_INST
#define FRONTEAR_FASM_INST

#include <stdint.h>

void LOD(void*, char);
void SET(void*, int8_t);
void STO(void*, char);

void ADD(void*, char, char);
void SUB(void*, char, char);
void MUL(void*, char, char);
void DIV(void*, char, char);

void DMP(void*);

#endif
