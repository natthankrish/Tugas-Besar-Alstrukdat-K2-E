#include "../dataStructure/boolean.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/Makanan/makanan.h"
#include "../dataStructure/WordMachine/wordmachinefile.h"

MAKANAN getMakananByID(int ID, ListStatik listMakanan) {
    MAKANAN Food;
    for (int j = 0; j < Lengthlist(listMakanan); j++) {
        MAKANAN curFood = ELMTlist(listMakanan, j);
        if (ID == ID(curFood)) {
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
    int j;
    for (int i = 0; i < numberOfResep; i++) {
        int IDroot;
        copyIntegerFromWordMachine(&IDroot, currentWordFile);
        MAKANAN rootFood = getMakananByID(IDroot, listMakanan);
        node root;
        CreateNode(&root, rootFood);
        ADVWORDFILE();        

        // menentukan jumlah anak dari root
        int jumlahAnakRoot;
        copyIntegerFromWordMachine(&jumlahAnakRoot, currentWordFile);
        ADVWORDFILE();

        // Menentukan anak dari curTree
        for (int j = 0; j < jumlahAnakRoot; j++) {
            int IDcurChild;
            copyIntegerFromWordMachine(&IDcurChild, currentWordFile);

            MAKANAN childFood = getMakananByID(IDcurChild, listMakanan);
            setChild(&root, childFood);
            ADVWORDFILE();
        }

        // Masukkan curTree ke dalam listResep
        insertLastTree(&listResep, root);
    }

    return listResep;

}
