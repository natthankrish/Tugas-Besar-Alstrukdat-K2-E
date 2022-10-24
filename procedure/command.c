#include <stdio.h>
#include "../dataStructure/CharMachine/charmachine.c"
#include "../dataStructure/WordMachine/wordmachine.c"
#include "../function/compareString.c"
#include "loadConfig.c"


void inputCommand (boolean *isStarted, boolean *isExit, Matrix *peta, ListStatik *makanan) {
    printf("Enter Command: ");
    STARTWORD();

    if (compareString(currentWord.TabWord, currentWord.Length, "START", 5)) {
        if (*isStarted) {
            printf("Program sudah berjalan, silahkan lakukan command yang lain\n");
            inputCommand(isStarted, isExit, peta, makanan);
        } else {
            *isStarted = true;
            printf("LOADING...\n");
            loadConfig(peta, makanan);
        }
    } else if (compareString(currentWord.TabWord, currentWord.Length, "EXIT", 4)) {
        *isExit = true;
        printf("TERIMA KASIH TELAH MENGGUNAKAN BNMO, SAMPAI JUMPA KEMBALI!\n");
    }
    
}