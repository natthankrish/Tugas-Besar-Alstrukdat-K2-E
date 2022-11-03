#include <stdio.h>
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Makanan/makanan.h"

void printCookBook(ListTree listResep){
    int i, j, k;
    for(i = 0; i < ListTreeLength(listResep); i++){
        printf("%d. ", i+1);
        for(j = 0; j < 101; j++){
            printf("%c", ELMTListTree(listResep,i)->info.name[j]);
        }
        printf("\n");

        printf("   Command:");
        if (ELMTListTree(listResep,i)->info.action == 1) {
            printf(" BUY");
        } else if (ELMTListTree(listResep,i)->info.action == 2) {
            printf(" CHOP");
        } else if (ELMTListTree(listResep,i)->info.action == 3) {
            printf(" FRY");
        } else if (ELMTListTree(listResep,i)->info.action == 4) {
            printf(" BOIL");
        } else if (ELMTListTree(listResep,i)->info.action == 5) {
            printf(" MIX");
        }
        printf("\n");

        printf("   Bahan: ");
        for(j = 0; j < ELMTListTree(listResep,i)->numChild; j++){
            for(k = 0; k < 101; k++){
                printf("%c", ELMTListTree(listResep,i)->listChild[j]->info.name[k]);
            }
            if(j+1 != ELMTListTree(listResep, i)->numChild)printf(", ");
        }
        printf("\n");

    }

}