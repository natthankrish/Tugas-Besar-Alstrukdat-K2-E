#include "inventory.h"
#include <stdlib.h>
#include <stdio.h>

typedef PrioQueue Inventory;

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
        AmbilMakananTeratas(I, *TempMakanan);
        InsertMakanan(*TempInventory, TempMakanan);
    }

    MakeInventoryKosong(I, newcapacity);
    while(!InventoryKosong(TempInventory)){
        AmbilMakananTeratas(*TempInventory, *TempMakanan);
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

void PrintInventory(Inventory I){ // belum selesai print nama
    if (IsEmpty(I)) {
        printf("Inventory Kosong\n");
    } else {
        for (int i = Head(I); i < (NBElmt(I) + Head(I)); i++){
            printf("%d %c\n", Elmt(I, i % MaxEl(I)).expiry, Elmt(I, i % MaxEl(I)).name);
        }
        printf("#\n");
    }
}