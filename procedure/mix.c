#include "../dataStructure/Simulator/simulator.h"
#include "../dataStructure/Point/point.h"
#include "../dataStructure/Matrix/matrix.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Inventory/inventory.h"
#include <math.h>


void doMix (ListStatik listMakanan, ListTree listResep, SIMULATOR * S, ListStatik madeByMix) {
    boolean done = false;
    for (int i = 0; i < Lengthlist(madeByMix); i++) {
        int order = ELMTlist(madeByMix, i) + 1;
        if (compareString(currentWord.TabWord, currentWord.Length, (char)order, 1) && currentChar == MARK) {
            // cek ketersedian bahan di inventory
            ListStatik notAvailable = inventoryCheck(madeByMix[i], listMakanan, listResep, *S);
            // jika semua bahan tersedia
            if (Lengthlist(notAvailable) == 0) {
                InsertMakanan(&Inventory(*S), madeByMix[i]);
                printf("%s selesai dibuat dan sudah masuk ke inventory!\n", Name(madeByMix[i]));
            } else {
                printf("Gagal membuat %s karena  kamu tidak memiliki bahan berikut:\n", Name(madeByMix[i]));
                for (int j=0; j<Lengthlist(notAvailable); j++) {
                    printf("    %d. %s\n", j+1, Name(ELMTlist(notAvailable, j)))
                }
                printf("\nEnter Command: ");
                ADVWORD();
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
        ADVWORD();
    }

}

void Mix (ListStatik listMakanan, ListTree listResep, SIMULATOR * S) {
    printf("==============================\n");
    printf("==========    MIX   ==========\n");
    printf("==============================\n");

    // inisialisasi list
    ListStatik madeByMix = madeBy(MIX, listMakanan, listResep);

    // menampilkan makanan yang bisa di goreng
    printf("List Bahan Makanan yang dapat dibuat: \n");
    for (int i = 0; i < Lengthlist(madeByMix); i++) {
        printf("    %d. %s\n", i+1, Name(ELMTlist(madeByMix, i)));
    }
    printf("\nKirim 0 untuk exit.\n");
    printf("Enter Command: ");
    ADVWORD();

    boolean langsungExit = true;
    while (!compareString(currentWord.TabWord, currentWord.Length, "0", 1) && currentChar == MARK) {
        doFry(listMakanan, listResep, S, madeByMix);
        langsungExit = false;
    }

    if (!langsungExit) {
        ADVWORD();
    }
}