#include <stdio.h>
#include "../dataStructure/CharMachine/charmachinefile.c"
#include "../dataStructure/WordMachine/wordmachinefile.c"
#include "../function/loadMakanan.c"
#include "../function/loadResep.c"
#include "../function/loadPeta.c"


void loadConfig (Matrix *peta, ListStatik *makanan) {
    *peta = loadPeta();
    *makanan = loadMakanan();
}
