/* MODUL LIST Notifikasi statik */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef ListNotif_H
#define ListNotif_H

#include "../boolean.h"
#include "../Makanan/makanan.h"

/*  Kamus Umum */
#define CAPACITYNOTIF 20 /* biar memorynya gak meledak */
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

typedef struct {
    char contents[102]; /* idnex 0 untuk tipe notifikasi, sisanya untuk nama makanan */
}notif;

/* Definisi elemen dan koleksi objek */
typedef struct {
    notif notifikasi[CAPACITYNOTIF];
    int tipenotif; // 1 = undo / 0 = normal
   int length;
} ListNotif;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListNotif, cara deklarasi dan akses: */
/* Deklarasi : l : ListNotif */
/* Maka cara akses: 
   ELMTlist(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMTlist(l,i) dengan i=0 */


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListNotif(ListNotif *l);

notif createNotif(int tipe, MAKANAN m);
/* 
tipe notif
BUY 1
CHOP 2
FRY 3
BOIL 4
MIX 5
MAKANAN SAMPAI 6
MAKANAN KADALUWARSA 7
 */

void pushNotif(ListNotif *l, MAKANAN m, int tipenotif);

void printListNotifNormal(ListNotif l);

void printListNotifUndo(ListNotif l);


#endif