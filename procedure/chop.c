#include "../dataStructure/Simulator/simulator.h"
#include "../dataStructure/Point/point.h"
#include "../dataStructure/Matrix/matrix.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Inventory/inventory.h"
#include <math.h>


void doChop (MAKANAN ** buatNotif, ListStatik listMakanan, ListTree listResep, SIMULATOR * S, ListStatik madeByChop, boolean* haveCooked) {
    boolean done = false;
    for (int i = 0; i < Lengthlist(madeByChop); i++) {
        int order = i + 1;
        char orderString [2];
        sprintf(orderString, "%d", order);
        if (compareString(currentWord.TabWord, currentWord.Length, orderString, countIntegerLength(order)) && currentChar == MARK) {
            // cek ketersedian bahan di inventory
            ListStatik notAvailable = inventoryCheck(ELMTlist(madeByChop, i), listMakanan, listResep, *S);
            // jika semua bahan tersedia
            if (Lengthlist(notAvailable) == 0) {
                ListStatik childrenOfFood = getListChildByFood(ELMTlist(madeByChop, i), listResep);
                for(int j=0; j < Lengthlist(childrenOfFood); j++) {
                    AmbilMakanan(&Inventory(*S), ELMTlist(childrenOfFood, j));
                }
                printf("%s berhasil dipotong!\n", Name(ELMTlist(madeByChop, i)));
                *haveCooked = true;
                *buatNotif = &ELMTlist(madeByChop, i);
                printf("Sudah melakukan command chop, silahkan lakukan command 0 sebelum melakukan chop bahan lain.");
                printf("\nEnter Command: ");
                STARTWORD();
            } else {
                printf("Gagal membuat %s karena  kamu tidak memiliki bahan berikut:\n", Name(ELMTlist(madeByChop, i)));
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

MAKANAN* Chop (ListStatik listMakanan, ListTree listResep, SIMULATOR * S) {
    printf("===============================\n");
    printf("==========    CHOP   ==========\n");
    printf("===============================\n");

    // inisialisasi list
    ListStatik madeByChop = madeBy(CHOP, listMakanan, listResep);
    MAKANAN * buatNotif = NULL;
    // menampilkan makanan yang bisa di goreng
    printf("List Bahan Makanan yang dapat dibuat: \n");
    for (int i = 0; i < Lengthlist(madeByChop); i++) {
        printf("    %d. %s\n", i+1, Name(ELMTlist(madeByChop, i)));
    }
    printf("\nKirim 0 untuk exit.\n");
    printf("Enter Command: ");
    STARTWORD();

    boolean langsungExit = true;
    boolean haveCooked = false;
    while (!compareString(currentWord.TabWord, currentWord.Length, "0", 1) && currentChar == MARK) {
        if (!haveCooked) {
            doChop(&buatNotif, listMakanan, listResep, S, madeByChop, &haveCooked);
            langsungExit = false;
        } else {
            printf("Sudah melakukan command chop, silahkan lakukan command 0 sebelum melakukan chop bahan lain.");
            printf("\nEnter Command: ");
            STARTWORD();
        }
    }

    if (!langsungExit) {
        ADVWORD();
    }
    return buatNotif;
}