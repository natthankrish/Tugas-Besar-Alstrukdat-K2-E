#include "tree.h"



/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk TREE *** */
void CreateTree (TREE * T, MAKANAN parent, int jumlahAnak) {
/* I.S. Sembarang */
/* F.S. Terbentuk TREE dengan jumlah anak yang terdefinisi dan listChild */
    NumOfChild(*T) = jumlahAnak;
    Parent(*T) = parent;
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
ListStatik ableTo(int action, ListStatik listMakanan, ListTree listResep ) {
/* Mengembalikan list yang berisi bahan makanan yang
   diolah dengna cara action*/
    ListStatik listAbleTo;
    CreateListStatik(&listAbleTo);
    for (int i = 0; i < Lengthlist(listMakanan); i++) {
        MAKANAN curMakanan = ELMTlist(listMakanan, i);
        // Jika makanan dibuat dengan cara action
        if (Action(curMakanan) == action ) { 
            for (int j = 0; j < Lengthlist(listResep); j++) {
                TREE curTree = ELMTListTree(listResep, j);
                if (ID(Parent(curTree)) == ID(curMakanan)) {
                    // Setiap anak dari parent curMakanan
                    for (int k = 0; k < NumOfChild(curTree); k++) {
                        insertLast(&listAbleTo,getChild(curTree, k));
                    }
                    break;
                }
            }
        }
    }
    return listAbleTo;
}

/* *** PRIMITIF LIST TREE *** */
void CreateListTree(ListTree * L) {
/* I.S. l sembarang */
/* F.S. Terbentuk ListTree L kosong dengan kapasitas 100 */
/* dengan panjang 0*/
    ListTreeLength(*L) = 0;
}

void insertLastTree(ListTree * L, TREE T) {
/* I.S. L terdefinisi */
/* F.S. T menjadi elemen listchild terakhir */
    if (ListTreeLength(*L) < 100) {
        int i = ListTreeLength(*L);
        ELMTListTree(*L, i) = T;
        ListTreeLength(*L)++;
    }
}