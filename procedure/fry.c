#include "../dataStructure/Simulator/simulator.h"
#include "../dataStructure/Point/point.h"
#include "../dataStructure/Matrix/matrix.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Inventory/inventory.h"
#include <math.h>


void doFry(ListStatik listMakanan, ListTree listResep, SIMULATOR * S, ListStatik madeByFry) {
    if (!compareString(currentWord.TabWord, currentWord.Length, "0", 1) && currentChar == MARK) {
        for (int i = 0; i < Lengthlist(madeByFry); i++) {
            int order = ELMTlist(madeByFry, i) + 1;
            if (compareString(currentWord.TabWord, currentWord.Length, (char)order, 1) && currentChar == MARK) {
                // cek ketersedian bahan di inventory
                ListStatik notAvailable = inventoryCheck(madeByFry[i], listMakanan, listResep, *S);
                // jika semua bahan tersedia
                if (Lengthlist(notAvailable) == 0) {
                    InsertMakanan(&Inventory(*S), madeByFry[i]);
                    printf("%s selesai dibuat dan sudah masuk ke inventory!\n", Name(madeByFry[i]));
                } else {
                    printf("Gagal membuat %s karena  kamu tidak memiliki bahan berikut:\n", Name(madeByFry[i]));
                    for (int j=0; j<Lengthlist(notAvailable); j++) {
                        printf("    %d. %s\n", j+1, Name(ELMTlist(notAvailable, j)))
                    }
                    printf("\nEnter Command: ");
                    ADVWORD();
                }
            }
        }
    }
}

void Fry (ListStatik listMakanan, ListTree listResep, SIMULATOR * S) {
    printf("==============================\n");
    printf("==========    FRY   ==========\n");
    printf("==============================\n");

    // inisialisasi list
    ListStatik madeByFry = madeBy(FRY, listMakanan, listResep);

    // menampilkan makanan yang bisa di goreng
    printf("List Bahan Makanan yang dapat dibuat: \n");
    for (int i = 0; i < Lengthlist(madeByFry); i++) {
        printf("    %d. %s\n", i+1, Name(ELMTlist(madeByFry, i)));
    }
    printf("\nKirim 0 untuk exit.\n");
    printf("Enter Command: ");
    ADVWORD();

    while (!compareString(currentWord.TabWord, currentWord.Length, "0", 1) && currentChar == MARK) {
        doFry(listMakanan, listResep, S, madeByFry);
    }
}