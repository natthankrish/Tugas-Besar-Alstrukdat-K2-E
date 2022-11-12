#include "tree.h"
#include <stdlib.h>

node newNode(){
    node T = (node) malloc(sizeof(TREE));
}

/* I.S. Sembarang */
/* F.S. Terbentuk node tree dengan jumlah anak 0 dan listChild kosong berukuran MAXCHILD
   dan parent menunjuk NULL (node adalah root) */
void CreateNode(node* T, MAKANAN food){
    *T = newNode();
    (*T)->info = food;
    (*T)->numChild = 0;
    (*T)->parent = NULL;
}

/* I.S. T terdefinisi, parent terdefinisi */
/* F.S. T menjadi child dari P*/
void setParent(node* T, node P){
    (*T)->parent = P;
}

/* I.S. T terdefinisi*/
/* F.S. membuat child baru dengan makanan food dan menjadi element terakhir di listChild pada T */
void setChild (node* T, MAKANAN food) {
    if(NumOfChild(*T) < MAXCHILD){
        node Child;
        CreateNode(&Child, food);
        setParent(&Child, *T); 
        Childlist(*T)[NumOfChild(*T)] = Child;
        NumOfChild(*T)++;
    }
}

/* Mengembalikan anak ke-idx dari T */
MAKANAN getChild(node T, int idx) {
    MAKANAN child = T->listChild[idx]->info;
    return child;
}

/* Mengembalikan list yang berisi bahan makanan yang
   diolah dengan cara action*/
ListStatik ableTo(int action, ListStatik listMakanan, ListTree listResep ) {
    ListStatik listAbleTo;
    CreateListStatik(&listAbleTo);
    for (int i = 0; i < Lengthlist(listMakanan); i++) {
        MAKANAN curMakanan = ELMTlist(listMakanan, i);
        // Jika makanan dibuat dengan cara action
        if (Action(curMakanan) == action ) { 
            for (int j = 0; j < Lengthlist(listResep); j++) {
                node curTree = ELMTListTree(listResep, j);
                if (ID(InfoTree(curTree)) == ID(curMakanan)) {
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




/* Mengembalikan list yang berisi bahan makanan yang
   dibuat dengan cara action*/
ListStatik madeBy(int action, ListStatik listMakanan, ListTree listResep) {
    ListStatik madeByAction;
    CreateListStatik(&madeByAction);
    for (int i = 0; i < Lengthlist(listMakanan); i++) {
        MAKANAN curMakanan = ELMTlist(listMakanan, i);
        // Jika makanan dibuat dengan cara action
        if (Action(curMakanan) == action ) { 
            insertLast(&madeByAction, curMakanan);
        }
    }
    return madeByAction;
}

/* I.S. l sembarang */
/* F.S. Terbentuk ListTree L kosong dengan kapasitas 100 */
/* dengan panjang 0*/
void CreateListTree(ListTree * L) {
    ListTreeLength(*L) = 0;
}

/* I.S. L terdefinisi */
/* F.S. T menjadi elemen listchild terakhir */
void insertLastTree(ListTree * L, node T) {
    if (ListTreeLength(*L) < MAXTREE) {
        int i = ListTreeLength(*L);
        ELMTListTree(*L, i) = T;
        ListTreeLength(*L)++;
    }
}

/* Mengembalikan list of all child of food*/
ListStatik getListChildByFood(MAKANAN food, ListTree listResep) {
    ListStatik listChildren;
    CreateListStatik(&listChildren);

    for (int i = 0; i < ListTreeLength(listResep); i++){
        node curTree = ELMTListTree(listResep, i);
        if ( ID(InfoTree(curTree)) == ID(food)) {
            for (int j = 0; j < NumOfChild(curTree); j++) {
                insertLast(&listChildren, InfoTree(Childlist(curTree)[j]));
            }
            break;
        }
    }
}