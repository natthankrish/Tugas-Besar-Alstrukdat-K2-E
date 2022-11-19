#include "stdio.h"
#include "../dataStructure/CharMachine/charmachine.h"

int main() {
    /*Run Driver: gcc ./driver/driver_charmachine.c  ./datastructure/CharMachine/charmachine.c -o main */
    /*Testing START*/
    START();

    /*Testing ADV*/
    while (!EOP) {
        printf("read: %c\n", currentChar);
        ADV();
        if (currentChar == '\n') {
            break;
        }
    }
    return 0;
}