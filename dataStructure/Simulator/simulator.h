#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "../boolean.h"
#include "../Point/point.h"
#include "../PrioQueue/prioqueue.h"


typedef struct { 
	char * NAMA; /* nama pengguna   */
	POINT LOKASI; /* lokasi pada map */
    PrioQueue INVENTORY; /* inventory */
} SIMULATOR;

/* *** Notasi Akses: Selektor SIMULATOR *** */
#define Nama(S) (S).NAMA
#define Lokasi(S) (S).LOKASI
#define Inventory(S) (S).INVENTORY
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSIMULATOR (SIMULATOR * S, char * X, POINT Y, PrioQueue Z);
/* Membentuk SIMULATOR dari input parameteter prosedur */

/* *** Kelompok Primitif *** */
char * getName(SIMULATOR S);
/* Mendapatkan nama pengguna*/

POINT getPoint(SIMULATOR S);
/* Mendapatkan lokasi simulator pada map pada saat ini*/

PrioQueue getInventory(SIMULATOR S);
/* Mendapatkan inventory simulator saat ini*/

void setName(SIMULATOR * S, char * X);
/* Mengubah nama pengguna pada simulator sesuai masukan yang diberikan pada parameter*/

void setPoint(SIMULATOR * S, POINT P);
/* Mengubah lokasi simulator pada peta sesuai dengna masukan yang diberikan pada paraeter*/

void setInventory(SIMULATOR * S, PrioQueue I);
/* Mengubah inventory sesuai dengan masukan yang diberikan pada parameter*/



/* *** Kelompok ----*/

#endif