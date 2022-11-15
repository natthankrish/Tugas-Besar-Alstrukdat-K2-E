#include <stdio.h>
#include "ListNotif.h"
#include "../boolean.h"
#include "../Makanan/makanan.h"

void CreateListNotif(ListNotif *l){
    l->length = 0; 
    l->tipenotif = 0;
}

notif createNotif(int tipe, MAKANAN m){
    notif notifikasi;
    notifikasi.contents[0] = tipe + '0'; /* int to char */
    for(int i=0;i<101;i++){ /* copy food name */
        notifikasi.contents[i+1] = m.name[i];
    }
    return notifikasi;
}

void pushNotif(ListNotif *l, MAKANAN m, int tipenotif){
    notif notifikasi = createNotif(tipenotif, m);
    if(l->length < CAPACITYNOTIF){
        int i = l->length;
        l->notifikasi[i] = notifikasi;
        l->length++;
    }
}

void printListNotifNormal(ListNotif l){
    int length = l.length;
    notif notifikasi;
    char tipenotif;
    for(int i=0;i<length;i++){
        printf("%d. ", i + 1);
        notifikasi = l.notifikasi[i];
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
        tipenotif = notifikasi.contents[0];
        if(tipenotif == '1'){
            printf("Membeli ");
        }else if(tipenotif == '2'){
            printf("Memotong ");
        }else if(tipenotif == '3'){
            printf("Menggoreng");
        }else if(tipenotif == '4'){
            printf("Merebus ");
        }else if(tipenotif == '5'){
            printf("Membuat ");
        }

        for(int i=1;i<102;i++){ /* print nama makanan */
            printf("%c", notifikasi.contents[i]);
        }

        if(tipenotif == '6'){
            printf(" sudah diterima");
        }else if(tipenotif == '7'){
            printf(" sudah kadaluwarsa");
        }

        printf("\n");
    }
}

void printListNotifUndo(ListNotif l){
    
    int length = l.length;
    notif notifikasi;
    char tipenotif;
    for(int i=0;i<length;i++){
        printf("%d. ", i + 1);
        notifikasi = l.notifikasi[i];
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
        tipenotif = notifikasi.contents[0];
        if(tipenotif == '1'){
            printf("Membeli ");
        }else if(tipenotif == '2'){
            printf("Memotong ");
        }else if(tipenotif == '3'){
            printf("Menggoreng");
        }else if(tipenotif == '4'){
            printf("Merebus ");
        }else if(tipenotif == '5'){
            printf("Membuat ");
        }

        for(int i=1;i<102;i++){ /* print nama makanan */
            printf("%c", notifikasi.contents[i]);
        }

        if(tipenotif-'0' < 6){
            printf(" dibatalkan");
        }

        if(tipenotif == '6'){
            printf(" dihapus dari inventory");
        }else if(tipenotif == '7'){
            printf(" dikembalikan ke inventory");
        }

        printf("\n");
    }
}

