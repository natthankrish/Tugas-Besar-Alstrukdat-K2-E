#include "simulator.h"
#include <stdio.h>



/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSIMULATOR (SIMULATOR * S, char X[], POINT P, PrioQueue I){
    Nama(*S) = X;
    Lokasi(*S) = P;
    Inventory(*S) = I;
    

}
/* I.S. Sembarang */
/* F.S. S terdefinisi */

/* *** Kelompok Primitif *** */
char * getName(SIMULATOR S){
    return Nama(S);
}
/* Mendapatkan nama pengguna*/

POINT getPoint(SIMULATOR S){
    return Lokasi(S);
}
/* Mendapatkan lokasi simulator pada map pada saat ini*/

PrioQueue getInventory(SIMULATOR S){
    return Inventory(S);
}
/* Mendapatkan inventory simulator saat ini*/

void setName(SIMULATOR * S, char X[]){
    Nama(*S) = X;
}
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
