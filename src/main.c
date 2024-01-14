#include "lib/inst.h"
#include "lib/machine.h"

int main(void) {
    void* machine = init_machine();

    DMP(machine);

    SET(machine, 15);
    STO(machine, 'a');

    SET(machine, 10);
    STO(machine, 'b');

    SET(machine, 5);
    STO(machine, 'c');

    SET(machine, 20);
    STO(machine, 'd');

    SET(machine, 25);
    STO(machine, 'e');

    DMP(machine);

    ADD(machine, 'a', 'c');
    STO(machine, 'f');

    DMP(machine);

    SUB(machine, 'b', 'd');
    STO(machine, 'g');

    DMP(machine);

    halt_machine(machine);
    return 0;
}
