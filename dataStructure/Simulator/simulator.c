#include "simulator.h"
#include <stdio.h>



/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSIMULATOR (SIMULATOR * S, char X[], POINT P, PrioQueue I){
    copySimulatorName(X, Nama(*S));
    Lokasi(*S) = P;
    Inventory(*S) = I;
}

void copySimulatorName (char input[], char output[]) {
    for (int i = 0; i < 101; i++) {
        if (input[i] != '\n') {
            output[i] = input[i];
        }
    }
}

/* I.S. Sembarang */
/* F.S. S terdefinisi */

/* *** Kelompok Primitif *** */

POINT getPoint(SIMULATOR S){
    return Lokasi(S);
}
/* Mendapatkan lokasi simulator pada map pada saat ini*/

PrioQueue getInventory(SIMULATOR S){
    return Inventory(S);
}
/* Mendapatkan inventory simulator saat ini*/

/* I.S. Sembarang */
/* F.S. Nilai NAMA pada S diset sesuai input */

void setPoint(SIMULATOR * S, POINT P){
    Lokasi(*S) = P;
}
/* I.S. Sembarang */
/* F.S. Nilai LOKASI pada S diset sesuai input */

void setInventory(SIMULATOR * S, PrioQueue I){
    Inventory(*S) = I;
}
/* I.S. Sembarang */
/* F.S. Nilai INVENTORY pada S diset sesuai input */
