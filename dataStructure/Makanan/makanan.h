/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../boolean.h"
#include "../Time/time.h"

#define BUY 1
#define CHOP 2
#define FRY 3
#define BOIL 4
#define MIX 5

typedef struct
{
  int height; /*Tinggi*/
  int width; /*Lebar*/
} DIMENSION;

typedef struct
{
   int idx;  /*ID makanan*/
   char name[101]; /*Nama makanan*/
   TIME expiry; /*Kadaluarsa makanan*/
   int action; /*Aksi makanan*/
   TIME deliveryTime; /*Waktu delivery makanan*/
   DIMENSION size; /*Ukuran makanan*/
} MAKANAN;

/* *** Selektor *** */
#define Height(M) (M).size.height
#define Width(M) (M).size.width
#define Expiry(M) TIMEToMinute((M).expiry) /*Dalam bentuk menit*/
#define DeliveryTime(M) TIMEToMinute((M).deliveryTime) /*Dalam bentuk menit*/
#define Action(M) (M).action
#define Name(M) (M).name
#define ID(M) (M).idx

void CreateFood(MAKANAN *M, int ID, char Nameinput[], TIME Expiry, int action, TIME deliverytime, DIMENSION size);
/*Register food baru berdasarkan input*/
/*Cuma buat testing*/

void CreateDimension (DIMENSION *D, int height, int width);

void copyString (char input[], char output[]);

const char* getAction(MAKANAN M, boolean caps);
/*Mengambil aksi makanan*/
/*Jika caps=true, maka akan dikembalikan dalam tulisan kapital*/
/*Jika caps=false, maka akan dikembalikan dalam tulisan biasa*/

void decreaseExpiry(MAKANAN *M);
/*Mengurangi waktu expiry sebanyak 1 menit*/
/*Tidak bisa kurang dari 0*/

void increaseExpiry(MAKANAN *M);
/*Menambah waktu expiry sebanyak 1 menit*/

void decreaseDelivery(MAKANAN *M);
/*Mengurangi waktu delivery sebanyak 1 menit*/
/*Tidak bisa kurang dari 0*/

void increaseDelivery(MAKANAN *M);
/*Menambah waktu delivery sebanyak 1 menit*/

boolean isExpired(MAKANAN M);
/*Menentukan apakah makanan sudah expired atau belum*/

boolean isDelivered(MAKANAN M);
/*Menentukan apakah makanan sudah expired atau belum*/

boolean isExpiryEQ(MAKANAN M1, MAKANAN M2);
/*Membandingkan apakah makanan M1 dan M2 memiliki expiry yang sama*/

boolean isDeliveryEQ(MAKANAN M1, MAKANAN M2);
/*Membandingkan apakah makanan M1 dan M2 memiliki delivery time yang sama*/

boolean ExpiryGT(MAKANAN M1, MAKANAN M2);
/*Menentukan apakah expiry M1 lebih panjang daripada M2*/

boolean ExpiryLT(MAKANAN M1, MAKANAN M2);
/*Menentukan apakah expiry M1 lebih pendek daripada M2*/

boolean DeliveryGT(MAKANAN M1, MAKANAN M2);
/*Menentukan apakah delivery time M1 lebih panjang daripada M2*/

boolean DeliveryLT(MAKANAN M1, MAKANAN M2);
/*Menentukan apakah delivery time M1 lebih pendek daripada M2*/

MAKANAN longestExpiry(MAKANAN M1, MAKANAN M2);
/*Menentukan makanan yang memiliki expiry lebih panjang diantara M1 dan M2*/

MAKANAN shortestExpiry(MAKANAN M1, MAKANAN M2);
/*Menentukan makanan yang memiliki expiry lebih pendek diantara M1 dan M2*/

MAKANAN longestDelivery(MAKANAN M1, MAKANAN M2);
/*Menentukan makanan yang memiliki delivery time lebih panjang diantara M1 dan M2*/

MAKANAN shortestDelivery(MAKANAN M1, MAKANAN M2);
/*Menentukan makanan yang memiliki delivery time lebih pendek diantara M1 dan M2*/

boolean isFit(MAKANAN M, int X, int Y);
/*Menentukan apakah ukuran makanan M muat pada tempat dengan lebar X dan tinggi Y*/

#endif