#include <stdio.h>
#include "../dataStructure/Matrix/matrix.h"

void printStatus (Matrix mapconfig, TIME time) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("BNMO ada di posisi: \n");
    printf("Waktu: ");
    displayCLOCK(time);
    printf("\n");
    printf("Notifikasi: \n");
    for (int i = 0; i < mapconfig.colEff+2; i++) {
        printf("* ");
    }
    printf("\n");

    for (int i = 0; i < mapconfig.rowEff; i++) {
        printf("* ");
        for (int j = 0; j < mapconfig.colEff; j++) {
            if (ELMT(mapconfig, i, j) == '#') {
                printf("  ");
            } else {
                printf("%c ", ELMT(mapconfig, i, j));
            }
        }
        printf("*\n");
    }

    for (int i = 0; i < mapconfig.colEff+2; i++) {
        printf("* ");
    }
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}