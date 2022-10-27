#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "../boolean.h"
#include "../Point/point.h"
#include "../PrioQueue/prioqueue.h"
#include "../WordMachine/wordmachine.h"

typedef struct { 
	Word NAMA; /* nama pengguna   */
	POINT LOKASI; /* lokasi pada map */
    PrioQueue INVENTORY; /* inventory */
} SIMULATOR;

/* *** Notasi Akses: Selektor SIMULATOR *** */
#define Nama(S) (S).NAMA
#define Lokasi(S) (S).LOKASI
#define Inventory(S) (S).INVENTORY
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
SIMULATOR CreateSIMULATOR (Word X, POINT Y, PrioQueue Z);
/* Membentuk SIMULATOR sebgai output funsi */

/* *** Kelompok Primitif *** */
Word getName(SIMULATOR S);
/* Mendapatkan nama pengguna*/

POINT getPoint(SIMULATOR S);
/* Mendapatkan lokasi simulator pada map pada saat ini*/

PrioQueue getInventory(SIMULATOR S);
/* Mendapatkan inventory simulator saat ini*/

void setName(SIMULATOR * S, Word X);
/* Mengubah nama pengguna pada simulator sesuai masukan yang diberikan pada parameter*/

void setPoint(SIMULATOR * S, POINT P);
/* Mengubah lokasi simulator pada peta sesuai dengna masukan yang diberikan pada paraeter*/

void setInventory(SIMULATOR * S, PrioQueue I);
/* Mengubah inventory sesuai dengan masukan yang diberikan pada parameter*/



/* *** Kelompok ----*/

#endif