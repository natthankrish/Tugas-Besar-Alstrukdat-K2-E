#include "tree.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk TREE *** */
void CreateTree (TREE * T, MAKANAN parent, int jumlahAnak) {
/* I.S. Sembarang */
/* F.S. Terbentuk TREE dengan jumlah anak yang terdefinisi dan listChild kosong berukuran 10 */
    NumOfChild(*T) = jumlahAnak;
    MAKANAN
    ListStatik Childlist;
    CreateListStatik(&Childlist);
}

void setChild (TREE * T, MAKANAN child) { 
/* I.S. TREE P terdefinisi*/
/* F.S. child menjadi element di listChild pada P*/
    ElType val;
    Makanan(val) = child; 
    insertLast(&Childlist(*T), val);
}

MAKANAN getChild(TREE T, int idx) {
/* Mengembalikan anak ke-idx dari P */
    MAKANAN child;
    child = ELMTlistMakanan(Childlist(T), idx);
    return child;
}

/* *** Fungsi yang berguna *** */
ListStatik ableTo(int action, ListStatik listMakanan, ListStatik listResep ) {
/* Mengembalikan list yang berisi bahan makanan yang
   diolah dengna cara action*/
    ListStatik listAbleTo;
    CreateListStatik(&listAbleTo);
    for (int i = 0; i < Lengthlist(listMakanan); i++) {
        MAKANAN curMakanan = ELMTlistMakanan(listMakanan, i);
        // Jika makanan dibuat dengan cara action
        if (Action(curMakanan) == action ) { 
            ElType val;
            for (int j = 0; j < Lengthlist(listResep); j++) {
                TREE curTree = ELMTlistTree(listResep, j);
                if (Parent(curTree) == curMakanan) {
                    // Setiap anak dari parent curMakanan
                    for (int k = 0; k < NumOfChild(curTree); k++) {
                        Makanan(val) = getChild(curTree, k);
                        insertLast(&listAbleTo,val);
                    }
                }
            }
        }
    }
    return listAbleTo;
}

