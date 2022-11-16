#include <stdlib.h>
#include "set.h"

nodeAddress newSetNode(int x) {
    nodeAddress new = (nodeAddress) malloc(sizeof(SetNode));
    if (new != NULL) {
        InfoNode(new) = x;
        NextNode(new) = NULL;
    }
    return new;
}

void CreateEmptySet(Set* S, int numFoods){
    nodeAddress p = newSetNode(0);
    *S = p;
    for(int i=1;i<numFoods;i++){
        NextNode(p) = newSetNode(0);
        p = NextNode(p);
    }
}


void fillNode(Set* S, int idx) {
    nodeAddress p = *S;
    for (int i=0; i<idx; i++){
        p = NextNode(p);
    }
    InfoNode(p) = 1;
}

Set CreateFoodSet(MAKANAN food, ListStatik listMakanan,ListTree listResep) {
    Set foodSet;
    CreateEmptySet(&foodSet, Lengthlist(listMakanan));
    ListStatik childrenList = getListChildByFood(food, listResep);

    nodeAddress p = foodSet;
    for (int j=0; j<Lengthlist(childrenList); j++) {
        for (int i=0; i<Lengthlist(listMakanan); i++) {
            if (ID(ELMTlist(childrenList, j))==ID(ELMTlist(listMakanan, i))) {
                fillNode(&foodSet, i);
            }
        }
    }
    return foodSet;
}

Set CreateInventorySet(SIMULATOR S, ListStatik listMakanan, ListTree listResep) {
    Set inventorySet;
    CreateEmptySet(&inventorySet, Lengthlist(listMakanan));

    nodeAddress p=inventorySet;
    for(int i=0; i<Lengthlist(listMakanan); i++) {
        if(MakananDalamInventory(Inventory(S), ELMTlist(listMakanan, i))) {
            fillNode(&inventorySet, i);
        }
    }
    return inventorySet;
}

boolean isSubsetInventory(Set inventorySet, Set S, int numFoods) {
    nodeAddress p = inventorySet;
    nodeAddress q = S;
    for(int i=0; i<numFoods; i++){
        if (InfoNode(q) == 1) {
            if (InfoNode(p) == 0) {
                return false;
            }
        }
        p = NextNode(p);
        q = NextNode(q);
    }
    return true;
}

void displaySet(Set S, int numFoods) {
    printf("[");
    nodeAddress p = S;
    for (int i=0; i<numFoods; i++) {
        printf("%d, ", InfoNode(p));
        p = NextNode(p);
    }
    printf("]\n");
}
