#include "tree.h"
#include <stdlib.h>

node newNode(){
    node T = (node) malloc(sizeof(TREE));
}

void CreateNode(node* T, MAKANAN food){
    *T = newNode();
    (*T)->info = food;
    (*T)->numChild = 0;
    (*T)->parent = NULL;
}

void setParent(node* T, node P){
    (*T)->parent = P;
}

void setChild (node* T, MAKANAN food) {
    if((*T)->numChild < MAXCHILD){
        node Child;
        CreateNode(&Child, food);
        setParent(&Child, *T); 
        (*T)->listChild[(*T)->numChild] = Child;
        (*T)->numChild++;
    }
}

MAKANAN getChild(node T, int idx) {
    MAKANAN child = T->listChild[idx]->info;
    return child;
}

ListStatik ableTo(int action, ListStatik listMakanan, ListTree listResep ) {
    ListStatik listAbleTo;
    CreateListStatik(&listAbleTo);
    for (int i = 0; i < Lengthlist(listMakanan); i++) {
        MAKANAN curMakanan = ELMTlist(listMakanan, i);
        // Jika makanan dibuat dengan cara action
        if (Action(curMakanan) == action ) { 
            for (int j = 0; j < Lengthlist(listResep); j++) {
                node curTree = ELMTListTree(listResep, j);
                if (ID(curTree->info) == ID(curMakanan)) {
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

void CreateListTree(ListTree * L) {
    ListTreeLength(*L) = 0;
}

void insertLastTree(ListTree * L, node T) {
    if (ListTreeLength(*L) < MAXTREE) {
        int i = ListTreeLength(*L);
        ELMTListTree(*L, i) = T;
        ListTreeLength(*L)++;
    }
}