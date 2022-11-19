#include "../dataStructure/Simulator/simulator.h"
#include "../dataStructure/Point/point.h"
#include "../dataStructure/Matrix/matrix.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Inventory/inventory.h"
#include <math.h>




void doFry(MAKANAN ** buatNotif, ListStatik listMakanan, ListTree listResep, SIMULATOR * S, ListStatik madeByFry, PrioQueue * pesanan) {
    boolean done = false;
    for (int i = 0; i < Lengthlist(madeByFry); i++) {
        int order = i + 1;
        char orderString [2];
        sprintf(orderString, "%d", order);
        if (compareString(currentWord.TabWord, currentWord.Length, orderString, countIntegerLength(order)) && currentChar == MARK) {
            // cek ketersedian bahan di inventory
            ListStatik notAvailable = inventoryCheck(ELMTlist(madeByFry, i), listMakanan, listResep, *S);
            // jika semua bahan tersedia
            if (Lengthlist(notAvailable) == 0) {
                ListStatik childrenOfFood = getListChildByFood(ELMTlist(madeByFry, i), listResep);
                for(int j=0; j < Lengthlist(childrenOfFood); j++) {
                    AmbilMakanan(&Inventory(*S), ELMTlist(childrenOfFood, j));
                }
                // InsertMakanan(&Inventory(*S), ELMTlist(madeByFry, i));
                Enqueue(pesanan, ELMTlist(madeByFry, i));
                printf("%s sedang digoreng! Mohon ditunggu!\n", Name(ELMTlist(madeByFry, i)));
                *buatNotif = &ELMTlist(madeByFry, i);
                printf("\nEnter Command: ");
                STARTWORD();
            } else {
                printf("Gagal membuat %s karena  kamu tidak memiliki bahan berikut:\n", Name(ELMTlist(madeByFry, i)));
                for (int j=0; j<Lengthlist(notAvailable); j++) {
                    printf("    %d. %s\n", j+1, Name(ELMTlist(notAvailable, j)));
                }
                printf("\nEnter Command: ");
                STARTWORD();
            }
            done = true;
        }
    }

    if (!done) {
        while (!endWord) {
            ADVWORD();
        }
        printf("Command Salah! silakan masukkan nomor urut makanan yang ingin anda buat. Ketik HELP untuk bantuan.\n");
        printf("\nEnter Command: ");
        STARTWORD();
    }
}

MAKANAN* Fry (ListStatik listMakanan, ListTree listResep, SIMULATOR * S, PrioQueue * pesanan) {
    printf("==============================\n");
    printf("==========    FRY   ==========\n");
    printf("==============================\n");

    // inisialisasi list
    ListStatik madeByFry = madeBy(FRY, listMakanan, listResep);
    MAKANAN * buatNotif = NULL;
    // menampilkan makanan yang bisa di goreng
    printf("List Bahan Makanan yang dapat dibuat: \n");
    for (int i = 0; i < Lengthlist(madeByFry); i++) {
        printf("    %d. %s\n", i+1, Name(ELMTlist(madeByFry, i)));
    }
    printf("\nKirim 0 untuk exit.\n");
    printf("Enter Command: ");
    STARTWORD();
    boolean langsungExit = true;
    while (!compareString(currentWord.TabWord, currentWord.Length, "0", 1) && currentChar == MARK) {
        doFry(&buatNotif, listMakanan, listResep, S, madeByFry, pesanan);
        langsungExit = false;
    }

    if (!langsungExit) {
        ADVWORD();
    }
    return buatNotif;
}