#ifndef KULKAS_H
#define KULKAS_H

#include "../Makanan/makanan.h"
#include "../Time/time.h"
#include "../Matrix/matrix.h"
#include "../ListStatik/liststatik.h"
#include "../boolean.h"

typedef struct
{
   DIMENSION capacity;
   Matrix contents;
   ListStatik foodList;
} KULKAS;
/*Pengurutan list makanan pada kulkas berdasarkan urutan masuknya*/

/* Selektor */
#define Contents(K) (K).contents  /*Isi kulkas dalam Matrix*/
#define FoodList(K) (K).foodList /*Isi kulkas dalam list*/
#define FridgeListLength(K) Lengthlist((K).foodList)
#define FoodListELMT(K,N) (K).foodList.contents[N]  /*Elemen makanan dalam list kulkas*/
#define FridgeHeight(K) (K).capacity.height /*Tinggi kulkas*/
#define FridgeWidth(K) (K).capacity.width /*Lebar kulkas*/
#define FridgeELMT(K,i,j) ELMT((K).contents,i,j) /*Cell pada isi matrix kulkas*/

/*Konstruktor kulkas*/
void CreateFridge(KULKAS *K, DIMENSION D);

/* Mengirimkan true jika kulkas K penuh */
boolean isFridgeFull(KULKAS K);

/* Mengirimkan true jika kulkas K kosong */
boolean isFridgeEmpty(KULKAS K);

/* Mengirimkan jumlah cell kosong pada kulkas K (bisa tersebar) */
int SpaceLeft(KULKAS K);

/* Mengirimkan true jika jumlah cell kosong cukup untuk memasukkan Makanan M ke dalam Kulkas K (hanya berdasarkan jumlah cell) */
boolean isFitFirstGlance(KULKAS K, MAKANAN M);

/* Mengirimkan true jika Makanan M dapat muat ke dalam Kulkas K */
boolean isFitFinal(KULKAS K, MAKANAN M);

/* Menampilkan list makanan yang ada di dalam Kulkas K */
void displayFoodList(KULKAS K);

/* Menampilkan isi Kulkas K beserta list makanan yang ada di dalamnya*/
void displayFridge(KULKAS K);

/* Memasukkan Makanan M ke dalam Kulkas K*/
void inToFridge(KULKAS *K, MAKANAN *M);

/* Mengelurakan makanan urutan ke FoodNum pada Kulkas K dan memasukkan nilainya ke Makanan M*/
void outFromFridge(KULKAS *K, int FoodNum,MAKANAN *M);

/* Mengcopy kulkas Kcopy menjadi kulkas baru Ktarget */
void copyFridge(KULKAS Kcopy, KULKAS *Ktarget);

#endif