#include "stdio.h"
#include "../dataStructure/CharMachine/charmachine.h"
#include "../dataStructure/WordMachine/wordmachine.h"

int main() {
    /*Run Driver: gcc ./driver/driver_wordmachine.c  ./datastructure/CharMachine/charmachine.c ./datastructure/WordMachine/wordmachine.c -o main */
    /*Testing START*/
    STARTWORD();

    /*Testing ADV*/
    while (!endWord) {
        printf("read: ");
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();
        printf("\n");
    }
    return 0;
}