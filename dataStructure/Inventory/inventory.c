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

void PerbesarInventory(Inventory *I, int newcapacity){ // belum di tes
    Inventory TempInventory;
    MAKANAN TempMakanan;
    while(!InventoryKosong(*I)){
        AmbilMakananTeratas(I, &TempMakanan);
        InsertMakanan(&TempInventory, TempMakanan);
    }

    MakeInventoryKosong(I, newcapacity);
    while(!InventoryKosong(TempInventory)){
        AmbilMakananTeratas(&TempInventory, &TempMakanan);
        InsertMakanan(I, TempMakanan);
    }
}

void DealokasiInventory(Inventory *I){
    DeAlokasi(I);
}

boolean MakananDalamInventory(Inventory I, MAKANAN X){ // belum selesai
    boolean found = false;

    for (int i = Head(I); i < (NBElmt(I) + Head(I)); i++){
        if (ID(X) == ID(Elmt(I, i%MaxEl(I)))) {
            found = true;
        }
    }

    return found;
}

void InsertMakanan(Inventory *I, MAKANAN X){
    Enqueue(I, X);
}

void AmbilMakanan(Inventory *I, MAKANAN X){ // belum selesai

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
            printf("    %d. ",i+1);
            for(int j = 0; j < 101; j++){
                printf("%c",Elmt(I,i).name[j]);
            }
            printf("\n      Waktu sisa kadaluwarsa : ");
            if (Elmt(I,i).expiry.D != 0) {
                printf(" %d Hari", Elmt(I,i).expiry.D);
            }

            if (Elmt(I,i).expiry.HH != 0) {
                printf(" %d Jam", Elmt(I,i).expiry.HH);
            }

            if (Elmt(I,i).expiry.MM != 0) {
                printf(" %d Menit", Elmt(I,i).expiry.MM);
            }
            printf("\n\n");
        }
    }
}