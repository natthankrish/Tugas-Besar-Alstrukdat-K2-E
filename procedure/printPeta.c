#include <stdio.h>
#include "../dataStructure/Matrix/matrix.h"
#include "../dataStructure/ListStatik/ListNotif.h"

void printStatus (Matrix mapConfig, TIME time, SIMULATOR simulator, ListNotif notifikasi) {
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
    if(notifikasi.tipenotif == 1){
        printListNotifUndo(notifikasi);
    }else{
        printListNotifNormal(notifikasi);
    }

    for (int i = 0; i < mapConfig.colEff+2; i++) {
        printf("* ");
    }
    printf("\n");

    for (int i = 0; i < mapConfig.rowEff; i++) {
        printf("* ");
        for (int j = 0; j < mapConfig.colEff; j++) {
            if (ELMT(mapConfig, i, j) == '#') {
                printf("  ");
            } else {
                printf("%c ", ELMT(mapConfig, i, j));
            }
        }
        printf("*\n");
    }

    for (int i = 0; i < mapConfig.colEff+2; i++) {
        printf("* ");
    }
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}