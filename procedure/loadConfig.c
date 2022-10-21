#include <stdio.h>
#include "../function/loadMakanan.c"
#include "../function/loadResep.c"
#include "../function/loadPeta.c"

void loadConfig (Matrix *peta) {
    *peta = loadPeta();
}
