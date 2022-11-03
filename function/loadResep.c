#include "../dataStructure/boolean.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/Makanan/makanan.h"
#include "../dataStructure/WordMachine/wordmachinefile.h"

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
    CreateListTree(&listResep);

    STARTWORDFILE("config/resep.txt");

    int numberOfResep;
    copyIntegerFromWordMachine(&numberOfResep, currentWordFile);
    ADVWORDFILE();

    for (int i = 0; i < numberOfResep; i++) {
        node curTree;

        // menentukan parent dari curTree
        int IDcurParent;
        copyIntegerFromWordMachine(&IDcurParent, currentWordFile);
        MAKANAN curParentFood = getMakananByID(IDcurParent, listMakanan);
        node curParent;
        CreateNode(curParent, curParentFood);
        ADVWORDFILE();        

        // menentukan jumlah anak dari curTree
        int jumlahAnakCurTree;
        copyIntegerFromWordMachine(&jumlahAnakCurTree, currentWordFile);
        ADVWORDFILE();

        setParent(curTree, curParent);

        // Menentukan anak dari curTree
        for (int j = 0; j < jumlahAnakCurTree; j++) {
            int IDcurChild;
            copyIntegerFromWordMachine(&IDcurChild, currentWordFile);

            MAKANAN childFood = getMakananByID(IDcurChild, listMakanan);
            setChild(curTree, childFood);
            ADVWORDFILE();
        }

        // Masukkan curTree ke dalam listResep
        insertLastTree(&listResep, curTree);
        
    }

    return listResep;

}