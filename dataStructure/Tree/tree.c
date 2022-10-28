#include "tree.h"

void insertLastTree(ListTree * L, TREE T) {
    if (ListTreeLength(*L) < 100) {
        int i = LengthTreeLength(*L);
        ELMTListTree(*L, i) = T;
        ListTreeLength(*L)++;
    }
}

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk TREE *** */
void CreateTree (TREE * T, MAKANAN parent, int jumlahAnak) {
/* I.S. Sembarang */
/* F.S. Terbentuk TREE dengan jumlah anak yang terdefinisi dan listChild */
    NumOfChild(*T) = jumlahAnak;
    Parent(T) = parent;
    ListStatik Childlist;
    CreateListStatik(&Childlist);
    Childlist(*T) = Childlist;
}

void setChild (TREE * T, MAKANAN child) { 
/* I.S. TREE P terdefinisi*/
/* F.S. child menjadi element di listChild pada P*/ 
    insertLast(&Childlist(*T), child);
}

MAKANAN getChild(TREE T, int idx) {
/* Mengembalikan anak ke-idx dari P */
    MAKANAN child;
    child = ELMTlist(Childlist(T), idx);
    return child;
}

/* *** Fungsi yang berguna *** */
ListStatik ableTo(int action, ListStatik listMakanan, ListStatik listResep ) {
/* Mengembalikan list yang berisi bahan makanan yang
   diolah dengna cara action*/
    ListStatik listAbleTo;
    CreateListStatik(&listAbleTo);
    for (int i = 0; i < Lengthlist(listMakanan); i++) {
        MAKANAN curMakanan = ELMTlist(listMakanan, i);
        // Jika makanan dibuat dengan cara action
        if (Action(curMakanan) == action ) { 
            for (int j = 0; j < Lengthlist(listResep); j++) {
                TREE curTree = ELMTlist(listResep, j);
                if (Parent(curTree) == curMakanan) {
                    // Setiap anak dari parent curMakanan
                    for (int k = 0; k < NumOfChild(curTree); k++) {
                        insertLast(&listAbleTo,getChild(curTree, k));
                    }
                }
            }
        }
    }
    return listAbleTo;
}
