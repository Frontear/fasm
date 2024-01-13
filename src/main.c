#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// supports 8 registers, holding an 8-bit value
// The 1st register is not allowed to be used, so
// technically it only allows 7 registers.
typedef struct {
    int8_t reg0;                // initial register
    char regn[7];               // register names
    int8_t regv[7];             // register values
} cpu;

// 4 kib of ram, divided up into a stack and buffer
typedef struct {
    int8_t stack[256];          // stack structure
    int8_t buffer[4096 - 256];  // rest of memory
} ram;

void init_cpu(cpu*);
void init_ram(ram*);

void DMP(cpu*);

void LOD(cpu*, char);
void SET(cpu*, int8_t);
void STO(cpu*, char);

void ADD(cpu*, char, char);
void SUB(cpu*, char, char);

int main(void) {
    cpu c;
    ram r;

    init_cpu(&c);
    init_ram(&r);

    DMP(&c);

    SET(&c, 15);
    STO(&c, 'a');

    SET(&c, 10);
    STO(&c, 'b');

    SET(&c, 5);
    STO(&c, 'c');

    SET(&c, 20);
    STO(&c, 'd');

    SET(&c, 25);
    STO(&c, 'e');

    DMP(&c);

    ADD(&c, 'a', 'c');
    STO(&c, 'f');

    DMP(&c);

    SUB(&c, 'b', 'd');
    STO(&c, 'g');

    DMP(&c);

    return 0;
}

void init_cpu(cpu* c) {
    for (int i = 0; i < 7; ++i) {
        c->regn[i] = 'a' + i;
        c->regv[i] = 0;
    }
}

void init_ram(ram* r) {
    memset(r->stack, 0, 256);
    memset(r->buffer, 0, 4096 - 256);
}

void DMP(cpu* c) {
    printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\n", c->regn[0], c->regn[1], c->regn[2], c->regn[3], c->regn[4], c->regn[5], c->regn[6]);
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", c->regv[0], c->regv[1], c->regv[2], c->regv[3], c->regv[4], c->regv[5], c->regv[6]);

    printf("\n");
}

void LOD(cpu* c, char n) {
    c->reg0 = c->regv[n - 'a'];
}

void SET(cpu* c, int8_t v) {
    c->reg0 = v;
}

void STO(cpu* c, char n) {
    c->regv[n - 'a'] = c->reg0;
}

void ADD(cpu* c, char n1, char n2) {
    int8_t v1 = c->regv[n1 - 'a'];
    int8_t v2 = c->regv[n2 - 'a'];

    int8_t res = v1 + v2;

    c->reg0 = res;
}

void SUB(cpu* c, char n1, char n2) {
    int8_t v1 = c->regv[n1 - 'a'];
    int8_t v2 = c->regv[n2 - 'a'];

    int8_t res = v1 - v2;

    c->reg0 = res;
}
