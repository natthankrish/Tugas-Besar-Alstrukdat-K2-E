#include "simulator.h"
#include <stdio.h>



/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSIMULATOR (SIMULATOR * S, char * X, POINT P, PrioQueue I){
    Nama(*S) = X;
    Lokasi(*S) = P;
    Inventory(*S) = I;
    

}
/* Membentuk SIMULATOR dari input parameter yang diberikan */

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

void setName(SIMULATOR * S, char * X){
    Nama(*S) = X;
}
/* Mengubah nama pengguna pada simulator sesuai masukan yang diberikan pada parameter*/

void setPoint(SIMULATOR * S, POINT P){
    Lokasi(*S) = P;
}
/* Mengubah lokasi simulator pada peta sesuai dengna masukan yang diberikan pada paraeter*/

void setInventory(SIMULATOR * S, PrioQueue I){
    Inventory(*S) = I;
}
/* Mengubah inventory sesuai dengan masukan yang diberikan pada parameter*/

