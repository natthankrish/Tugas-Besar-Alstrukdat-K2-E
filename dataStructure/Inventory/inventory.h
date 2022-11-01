/* File : inventory.h */
/* Definisi ADT Inventory dengan menggunakan ADT Priority queue dengan menggunakan array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen expiry makanan */

#ifndef inventory_H
#define inventory_H

#include "../boolean.h"
#include "../Makanan/makanan.h"
#include "../Time/time.h"
#include "../PrioQueue/prioqueue.h"

typedef PrioQueue Inventory;

boolean InventoryKosong(Inventory I);
// Mengirim true jika inventory kosong

boolean InventoryPenuh(Inventory I);
// Mengirim true jika inventory penuh

int JumlahInventory(Inventory I);
// Mengirim banyaknya elemen dalam inventory

void MakeInventoryKosong(Inventory *I, int capacity);
// Membuat inventory baru dengan isi kosong dan kapasitas maximum MaxEl

void PerbesarInventory(Inventory *I, int newcapacity);
// mengubah ukuran inventory dengan elemen lama inventory di copy

void DealokasiInventory(Inventory *I);
// Men-dealokasi inventory

boolean MakananDalamInventory(Inventory I, MAKANAN X);
// Mengirim true apabila makanan terdapat dalam inventory

void InsertMakanan(Inventory *I, MAKANAN X);
// Memasukkan makanan kedalam inventory
// inventory mungkin penuh dan makanan tidak dapat di insert

void AmbilMakanan(Inventory *I, MAKANAN X);
// mengambil makanan dalam inventory
// makanan mungkin tidak berada dalam inventory

void AmbilMakananTeratas(Inventory *I, MAKANAN *X);
// mengambil makanan teratas di inventory (kadaluwarsa ter)
// inventory mungkin kosong dan tidak dapat mengambil makanan

void PrintInventory(Inventory I);
// Mencetak isi inventory ke layar
// I.S. I terdefinisi, mungkin kosong
// F.S. I tercetak ke layar dengan format
/*
List Makanan di Inventory
(nama - waktu sisa kedaluwarsa)
1. <makanan-1> - <time-1>
...
n. <makanan-n> - <time-n>
*/

#endif
