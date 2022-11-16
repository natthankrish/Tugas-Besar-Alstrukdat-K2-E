#include "../dataStructure/Set/set.h"
#include "../dataStructure/simulator/simulator.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/Time/time.h"
#include "../dataStructure/Makanan/makanan.h"

void foodRecom(SIMULATOR S, ListStatik listMakanan, ListTree listResep) {
    printf("--------------------------------------------------------------\n");
    printf("                      REKOMENDASI MAKANAN\n");
    printf("--------------------------------------------------------------\n");
    Set inventorySet = CreateInventorySet(S, listMakanan, listResep);
    int number = 1;
    for(int i=0; i<Lengthlist(listMakanan); i++) {
        Set foodSet = CreateFoodSet(ELMTlist(listMakanan, i), listMakanan, listResep);
        if (isSubsetInventory(inventorySet, foodSet, Lengthlist(listMakanan)) && Action(ELMTlist(listMakanan, i)) != 1) {
            printf("    %d. %s\n", number, Name(ELMTlist(listMakanan, i)));
            number++;

            printf("       Durasi Sebelum Kadaluarsa:");
            if (Day((ELMTlist(listMakanan, i)).expiry) != 0) {
                printf(" %d Hari", Day((ELMTlist(listMakanan, i)).expiry));
            }
            if (Hour((ELMTlist(listMakanan, i)).expiry) != 0) {
                printf(" %d Jam", Hour((ELMTlist(listMakanan, i)).expiry));
            }
            if (Minute((ELMTlist(listMakanan, i)).expiry) != 0) {
                printf(" %d Menit", Minute((ELMTlist(listMakanan, i)).expiry));
            }

            printf("\n       Command untuk Mendapatkan:"); 

            if (Action(ELMTlist(listMakanan, i)) == 2) {
                printf(" CHOP");
            } else if (Action(ELMTlist(listMakanan, i)) == 3) {
                printf(" FRY");
            } else if (Action(ELMTlist(listMakanan, i)) == 4) {
                printf(" BOIL");
            } else if (Action(ELMTlist(listMakanan, i)) == 5) {
                printf(" MIX");
            }

            printf("\n       Ukuran (PxL): %d x %d\n", Width(ELMTlist(listMakanan, i)), Height(ELMTlist(listMakanan, i)));
        }
    }
    if (number == 1) {
        printf("\nYah, belum ada yang bisa diolah dari makanan yang kamu miliki \n");
        printf("           command BUY untuk membeli makanan!\n\n");
    }
    printf("--------------------------------------------------------------\n");
}