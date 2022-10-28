#include <stdio.h>
#include "wordmachinefile.h"


int main() {
    STARTWORDFILE("config/makanan.txt");
    int countmakanan;
    copyIntegerFromWordMachine(&countmakanan, currentWordFile);
    ADVWORDFILE();
//     printf("%d", countmakanan);
//     copyIntegerFromWordMachine(&countmakanan, currentWordFile);
//     printf("%d", countmakanan);
}