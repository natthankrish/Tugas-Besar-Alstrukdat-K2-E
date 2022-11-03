#include <stdio.h>
#include "../dataStructure/CharMachine/charmachinefile.c"
#include "../dataStructure/WordMachine/wordmachinefile.c"
#include "../function/loadMakanan.c"
#include "../function/loadResep.c"
#include "../function/loadPeta.c"


void loadConfig (Matrix *peta, ListStatik *makanan, ListTree *resep) {
    *peta = loadPeta();
    *makanan = loadMakanan();
    *resep = loadResep(*makanan);
}
