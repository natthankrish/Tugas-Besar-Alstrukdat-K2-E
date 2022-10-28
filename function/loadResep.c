#include "../boolean.h"
#include "../Tree/tree.h"
#include "../Makanan/makanan.h"

ListStatik loadResep() {
    // deklarasi listResep
    ListStatik listResep;
    CreateListStatik(&listResep);

    STARTWORDFILE("config/resep.txt");

    int numberOfResep;
    copyIntegerFromWordMachine(&numberOfResep, currentWordFile);
    ADVWORDFILE();

    for (int i = 0; i < numberOfResep; i++) {

    }


}