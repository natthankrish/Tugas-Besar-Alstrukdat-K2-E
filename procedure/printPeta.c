#include <stdio.h>
#include "../dataStructure/Matrix/matrix.h"

void printStatus (Matrix mapconfig, TIME time, SIMULATOR simulator) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    char simName[101];
    copySimulatorName(Nama(simulator), simName);
    int i = 0;    
    for (int i = 0; i < 101; i++) {
        printf("%c", simName[i]);
    }
    printf(" ada di posisi: ");
    TulisPOINT(getPoint(simulator));
    printf("\n");
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