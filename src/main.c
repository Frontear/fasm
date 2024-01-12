#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    uint8_t* registers = malloc(sizeof(uint8_t) * 3); // 0th immediate, 1st 2nd are a b
    if (!registers) {
        fprintf(stderr, "Failed to allocate for registers\n");
        return -1;
    }

    // set instruction
    uint8_t value = 10;
    int register_to_set = 1; // register a

    registers[0] = value;
    registers[register_to_set] = registers[0];

    // load instruction
    int register_to_load = 1; // register b

    registers[0] = registers[register_to_load];

    // store instruction
    int register_to_store_into = 2; // register b

    registers[register_to_store_into] = registers[0];

    // another set instruction
    value = 15;
    register_to_set = 1;

    registers[0] = value;
    registers[register_to_set] = registers[0];

    // halt instruction
    printf("Register contents:\n");
    printf("---------\n");
    printf("|a  |b  |\n");
    printf("---------\n");
    printf("|%d |%d |\n", registers[1], registers[2]);
    printf("---------\n");

    return 0;
}
