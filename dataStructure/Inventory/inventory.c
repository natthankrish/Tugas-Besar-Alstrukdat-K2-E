#include "inventory.h"
#include <stdlib.h>
#include <stdio.h>


boolean InventoryKosong(Inventory I){
    return IsEmpty(I);
}

boolean InventoryPenuh(Inventory I){
    return IsFull(I);
}

int JumlahInventory(Inventory I){
    return NBElmt(I);
}

void MakeInventoryKosong(Inventory *I, int capacity){
    MakeEmpty(I, capacity);
}

void PerbesarInventory(Inventory *I, int newcapacity){
    Inventory TempInventory;
    MakeInventoryKosong(&TempInventory, I->MaxEl);
    MAKANAN TempMakanan;
    while(!InventoryKosong(*I)){
        AmbilMakananTeratas(I, &TempMakanan);
        InsertMakanan(&TempInventory, TempMakanan);
    }

    DealokasiInventory(I);
    MakeInventoryKosong(I, newcapacity);
    while(!InventoryKosong(TempInventory)){
        AmbilMakananTeratas(&TempInventory, &TempMakanan);
        InsertMakanan(I, TempMakanan);
    }
}

void DealokasiInventory(Inventory *I){
    DeAlokasi(I);
}

boolean MakananDalamInventory(Inventory I, MAKANAN X){
    boolean found = false;
    if (!InventoryKosong(I)) {
        for (int i = Head(I); i < (NBElmt(I) + Head(I)); i++){
            if (ID(X) == ID(Elmt(I, i%MaxEl(I)))) {
                found = true;
            }
        }
    }
    return found;
}

void InsertMakanan(Inventory *I, MAKANAN X){
    Enqueue(I, X);
}

void AmbilMakanan(Inventory *I, MAKANAN X){
    if(!MakananDalamInventory(*I, X)){
        printf("Makanan tidak ada dalam inventory\n");
    }else{
        int idx = 0; // index keberapa dari head
        
        for (int i = Head(*I); i < (NBElmt(*I) + Head(*I)); i++){
            if (ID(X) == ID(Elmt(*I, i%MaxEl(*I)))) {
                break;
            }else{
                idx++;
            }
        }
        if(idx == 0){
            Dequeue(I, &X);
        }else{
            for(int i=Head(*I) + idx;i < (NBElmt(*I) + Head(*I));i++){
                I->T[i%MaxEl(*I)] = I->T[(i+1)%MaxEl(*I)];
            }
            Tail(*I) = (Tail(*I) + MaxEl(*I) - 1) % MaxEl(*I);
        }
    }
}

void AmbilMakananTeratas(Inventory *I, MAKANAN *X){
    Dequeue(I, X);
}

void PrintInventory(Inventory I){
    printf("List Makanan dalam Inventory :\n\n");
    if (IsEmpty(I)) {
        printf("Inventory Kosong!\n");
    } else {
        for(int i = 0; i < NBElmt(I);i++){
            int idx = (i + Head(I))%MaxEl(I);
            printf("    %d. ",i+1);
            for(int j = 0; j < 101; j++){
                printf("%c",Elmt(I,idx).name[j]);
            }
            printf("\n      Waktu sisa kadaluwarsa : ");
            if (Elmt(I,idx).expiry.D != 0) {
                printf(" %d Hari", Elmt(I,idx).expiry.D);
            }

            if (Elmt(I,idx).expiry.HH != 0) {
                printf(" %d Jam", Elmt(I,idx).expiry.HH);
            }

            if (Elmt(I,idx).expiry.MM != 0) {
                printf(" %d Menit", Elmt(I,idx).expiry.MM);
            }
            printf("\n\n");
        }
    }
}