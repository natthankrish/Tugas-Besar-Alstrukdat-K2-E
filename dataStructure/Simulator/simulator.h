#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "../boolean.h"
#include "../Point/point.h"
#include "../PrioQueue/prioqueue.h"


typedef struct simulator { 
	char NAMA[101]; /* nama pengguna   */
	POINT LOKASI; /* lokasi pada map */
    PrioQueue INVENTORY; /* inventory */
} SIMULATOR;

/* *** Notasi Akses: Selektor SIMULATOR *** */
#define Nama(S) (S).NAMA
#define Lokasi(S) (S).LOKASI
#define Inventory(S) (S).INVENTORY
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk SIMULATOR *** */
void CreateSIMULATOR (SIMULATOR * S, char X[], POINT Y, PrioQueue Z);
/* I.S. Sembarang */
/* F.S. S terdefinisi */

/* *** Kelompok Primitif *** */

void copySimulatorName (char input[], char output[]);

POINT getPoint(SIMULATOR S);
/* Mendapatkan lokasi simulator pada map pada saat ini*/

PrioQueue getInventory(SIMULATOR S);
/* Mendapatkan inventory simulator saat ini*/

void setPoint(SIMULATOR * S, POINT P);
/* I.S. Sembarang */
/* F.S. Nilai LOKASI pada S diset sesuai input */

void setInventory(SIMULATOR * S, PrioQueue I);
/* I.S. Sembarang */
/* F.S. Nilai INVENTORY pada S diset sesuai input */



#endif