#include "../boolean.h"
#include "../Tree/tree.h"
#include "../Makanan/makanan.h"
#include "../WordMachine/wordmachinefile.h"

MAKANAN getMakananByID(int ID, ListStatik listMakanan) {
    MAKANAN Food;
    for (int j = 0; j < Lengthlist(listMakanan); j++) {
        MAKANAN curFood = ELMTlist(listMakanan, j);
        if (ID = ID(curFood)) {
            Food = curFood;
            break;
        }
    }
    return Food;
}

ListTree loadResep(ListStatik listMakanan) {
    // deklarasi listResep
    ListTree listResep;

    STARTWORDFILE("config/resep.txt");

    int numberOfResep;
    copyIntegerFromWordMachine(&numberOfResep, currentWordFile);
    ADVWORDFILE();

    for (int i = 0; i < numberOfResep; i++) {
        TREE curTree;

        // menentukan parent dari curTree
        int IDcurParent;
        copyIntegerFromWordMachine(&IDcurParent, currentWordFile);
        MAKANAN curParent = getMakananByID(IDcurParent, listMakanan);
        ADVWORDFILE();        

        // menentukan jumlah anak dari curTree
        int jumlahAnakCurTree;
        copyIntegerFromWordMachine(&jumlahAnakCurFood, currentWordFile);
        ADVWORDFILE();

        CreateTree(&curTree, curParent, jumlahAnakCurTree);

        // Menentukan anak dari curTree
        for (int j = 0; j < jumlahAnakCurTree; j++) {
            int IDcurChild;
            copyIntegerFromWordMachine(&IDcurChild, currentWordFile);

            MAKANAN child = getMakananByID(IDcurChild, listMakanan);
            setChild(&curTree, child);
            ADVWORDFILE();
        }

        // Masukkan curTree ke dalam listResep
        insertLastTree(&listResep, curTree);
        
    }

    return listResep;

}