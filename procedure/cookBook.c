#include <stdio.h>
#include "../dataStructure/Tree/tree.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Makanan/makanan.h"

void printCatalog(ListTree listResep, ListStatik listMakanan){
    printf("List Resep\n");
    printf("  ( aksi yang diperlukan - bahan... )\n");
    int i, j, k;
    for(i = 0; i < ListTreeLength(listResep); i++){
        printf("    %d. ", i);
        for(j = 0; j < 101; i++){
            printf("%c", ELMTListTree(listResep,i).parent.name[j]);
        }
        printf("\n");
        printf("        ");
        if (ELMTListTree(listResep,i).parent.action == 1) {
            printf(" BUY");
        } else if (ELMTListTree(listResep,i).parent.action == 2) {
            printf(" CHOP");
        } else if (ELMTListTree(listResep,i).parent.action == 3) {
            printf(" FRY");
        } else if (ELMTListTree(listResep,i).parent.action == 4) {
            printf(" BOIL");
        } else if (ELMTListTree(listResep,i).parent.action == 5) {
            printf(" MIX");
        }

        for(j = 0; j < ELMTListTree(listResep,i).numChild; j++){
            printf(" - ");
            for(k = 0; k < 101; k++){
                printf("%c", ELMTListTree(listResep,i).listChild.contents[j].name[k])
            }
        }

        printf("\n");
    }

}