#include "../dataStructure/Simulator/simulator.h"
#include "../dataStructure/Point/point.h"
#include "../dataStructure/Matrix/matrix.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Inventory/inventory.h"
#include <math.h>

POINT getFryLoc (Matrix peta) {
    POINT fryLoc;
    for (int i = 0; i < ROW_EFF(peta); i++) {
        for (int j = 0; j < COL_EFF(peta); j++) {
            if (ELMT(peta, i, j) == 'F') {
                fryLoc = MakePOINT(i, j);
            }
        }
    }
}

boolean isFryValid(POINT simLoc, POINT fryLoc) {
    return (Panjang(simLoc, fryLoc) == 1.0);
}

void showFry (SIMULATOR S, Matrix peta, ListStatik listMakanan, ListTree listResep) {
    if (isFryValid(Lokasi(S), getFryLoc(peta))) {
        printf("==============================\n");
        printf("==========    FRY   ==========\n");
        printf("==============================\n");
        
        ListStatik madeByFry = madeBy(FRY, listMakanan, listResep);
        printf("List Bahan Makanan yang dapat dibuat: \n");
        for (int i = 0; i < Lengthlist(madeByFry); i++) {
            printf("    %d. %s\n", i+1, Name(ELMTlist(madeByFry, i)));
        }
        printf("Kirim 0 untuk exit.\n");

    } else {
        printf("Simulator belum berada di tempat penggorengan !\n")
    }
}

boolean inventoryCheck (MAKANAN foodToCheck, ListStatik listMakanan, ListTree listResep, SIMULATOR S) {
    ListStatik childrenList = getListChildByFood(foodToCheck, listResep); 
    
    for (int i = 0; i < Lengthlist(childrenList); i++) {
        if (!MakananDalamInventory(Inventory(S), childrenList[i])) {
            return false;
        }
    }
    return true;
}

/* I.S. simulator di tempat penggorengan*/
/* F.S. */
void doFry (ListStatik listMakanan, ListTree listResep, SIMULATOR S, POINT fryLoc, int command) {
    ListStatik canNotFry = inventoryCheck(listMakanan, listResep, S);
    ListStatik madeByFry = madeBy(FRY, listMakanan, listResep);

    if (0 < command && command <= Lengthlist(madeByFry)) {
        for (int i = 0; i < Lengthlist(madeByFry); i++) {
            if (command == i) {
                for(int j = 0; j < ListTreeLength)
            }
        }
    }
}