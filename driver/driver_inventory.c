#include "../dataStructure/Inventory/inventory.h"
#include "../dataStructure/PrioQueue/prioqueue.h"
#include "../dataStructure/Makanan/makanan.h"
#include "../dataStructure/Time/time.h"
#include <stdio.h>

int main(){
    /*Run Driver: gcc ./driver/driver_inventory.c  ./datastructure/Inventory/inventory.c ./datastructure/PrioQueue/prioqueue.c ./datastructure/Makanan/makanan.c ./datastructure/Time/time.c -o main */
    
    Inventory inv;
    MAKANAN tmp;
    for(int i=0;i<101;i++)tmp.name[i] = '.';
    tmp.name[0] = 'h';
    tmp.name[1] = 'e';
    tmp.name[2] = 'h';
    tmp.name[3] = 'e';
    tmp.expiry = MinuteToTIME(10);

    MAKANAN tmp2;
    for(int i=0;i<101;i++)tmp2.name[i] = '.';
    tmp2.name[0] = 'l';
    tmp2.name[1] = 'a';
    tmp2.name[2] = 'h';
    tmp2.expiry = MinuteToTIME(20);

    MakeInventoryKosong(&inv, 5);
    printf("maximum element in inventory : %d\n", inv.MaxEl);
    printf("number element in inventory : %d\n", JumlahInventory(inv));
    printf("inventory empty : %d\n", InventoryKosong(inv));
    printf("inventory full : %d\n", InventoryPenuh(inv));
    printf("\n");

    InsertMakanan(&inv, tmp);
    printf("number element in inventory : %d\n", JumlahInventory(inv));
    PrintInventory(inv);
    printf("inventory empty : %d\n", InventoryKosong(inv));
    printf("inventory full : %d\n", InventoryPenuh(inv));
    printf("\n");
    
    InsertMakanan(&inv, tmp2);
    InsertMakanan(&inv, tmp);
    InsertMakanan(&inv, tmp2);
    InsertMakanan(&inv, tmp);
    printf("number element in inventory : %d\n", JumlahInventory(inv));
    PrintInventory(inv);
    printf("inventory empty : %d\n", InventoryKosong(inv));
    printf("inventory full : %d\n", InventoryPenuh(inv));
    printf("\n");

    AmbilMakananTeratas(&inv, &tmp);
    printf("number element in inventory : %d\n", JumlahInventory(inv));
    PrintInventory(inv);
    printf("inventory empty : %d\n", InventoryKosong(inv));
    printf("inventory full : %d\n", InventoryPenuh(inv));
    printf("\n");

    AmbilMakananTeratas(&inv, &tmp);
    AmbilMakananTeratas(&inv, &tmp);
    AmbilMakananTeratas(&inv, &tmp2);
    AmbilMakananTeratas(&inv, &tmp2);
    printf("number element in inventory : %d\n", JumlahInventory(inv));
    printf("inventory empty : %d\n", InventoryKosong(inv));
    printf("inventory full : %d\n", InventoryPenuh(inv));
    printf("\n");

    InsertMakanan(&inv, tmp2);
    InsertMakanan(&inv, tmp);
    InsertMakanan(&inv, tmp2);
    InsertMakanan(&inv, tmp);
    printf("%s ada dalam inventory : %d\n\n", tmp.name, MakananDalamInventory(inv, tmp));
    PerbesarInventory(&inv, 10);
    printf("maximum element in inventory : %d\n", inv.MaxEl);
    printf("number element in inventory : %d\n", JumlahInventory(inv));
    PrintInventory(inv);
    printf("inventory empty : %d\n", InventoryKosong(inv));
    printf("inventory full : %d\n", InventoryPenuh(inv));
    printf("\n");

    AmbilMakanan(&inv, tmp2);
    PrintInventory(inv);
    printf("\n");
    AmbilMakanan(&inv, tmp2);
    PrintInventory(inv);
    printf("\n");
    AmbilMakanan(&inv, tmp2);
    PrintInventory(inv);
    printf("\n");

}