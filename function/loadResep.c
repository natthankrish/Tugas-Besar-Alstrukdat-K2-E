#include "../boolean.h"
#include "../Tree/tree.h"
#include "../Makanan/makanan.h"
#include "../WordMachine/wordmachinefile.h"

MAKANAN getMakananFromID(int ID, ListStatik listMakanan) {
    MAKANAN Food;
    for (int j = 0; j < Lengthlist(listMakanan); j++) {
        MAKANAN curFood = ELMTlistMakanan(listMakanan, j);
        if (ID = ID(curFood)) {
            Food = curFood;
            break;
        }
    }
    return Food;
}

ListStatik loadResep(ListStatik listMakanan) {
    // deklarasi listResep
    ListStatik listResep;
    CreateListStatik(&listResep);

    STARTWORDFILE("config/resep.txt");

    int numberOfResep;
    copyIntegerFromWordMachine(&numberOfResep, currentWordFile);
    ADVWORDFILE();

    for (int i = 0; i < numberOfResep; i++) {
        TREE curTree;

        // menentukan parent dari curTree
        int IDcurParent;
        copyIntegerFromWordMachine(&IDcurParent, currentWordFile);
        MAKANAN curParent = getMakananFromID(IDcurParent, listMakanan);
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

            MAKANAN child = getMakananFromID(IDcurChild, listMakanan);
            setChild(&curTree, child);
            ADVWORDFILE();
        }

        // Masukkan curTree ke dalam listResep
        ElType val;
        Tree(val) = curTree;
        insertLast(&listResep, val);
        
    }

    return listResep;

}