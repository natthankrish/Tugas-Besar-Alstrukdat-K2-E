#include <stdio.h>
#include "../dataStructure/Time/time.h"

int main(){
    /*Run Driver: gcc ./driver/driver_time.c  ./datastructure/Time/time.h -o main */
    TIME T1;
    TIME T2;

    CreateTime(&T1,1,2,3);
    CreateTime(&T2,3,2,1);

    printf("Tampilan waktu T1: ");
    DisplayExpiryTIME(T1);
    printf("\n");
    printf("Tampilan waktu T1 dalam bentuk jam: ");
    displayCLOCK(T1);
    printf("\n");

    printf("Tampilan waktu T2: ");
    DisplayExpiryTIME(T2);
    printf("\n");
    printf("Tampilan waktu T2 dalam bentuk jam: ");
    displayCLOCK(T2);
    printf("\n");

    printf("Waktu T1 dalam satuan menit: %ld\n\n", TIMEToMinute(T1));

    if(TEQ(T1,T2)){
        printf("Waktu T1 sama dengan Waktu T2\n\n");
    }else{
        printf("Waktu T1 tidak sama dengan Waktu T2\n\n");
    }

    if(TGT(T1,T2)){
        printf("Waktu T1 lebih besar dari T2\n\n");
    }else{
        printf("Waktu T1 tidak lebih besar dari T2\n\n");
    }

    if(TLT(T1,T2)){
        printf("Waktu T1 lebih kecil dari T2\n\n");
    }else{
        printf("Waktu T1 tidak lebih kecil dari T2\n\n");
    }

    printf("Selisih antara T1 dengan T2: ");
    DisplayExpiryTIME(Duration(T1,T2));
    printf("\n");

    setClockZero(&T1);
    printf("Clock telah di set ke 0\n");
    displayCLOCK(T1);
    printf("\n");

    setClock(&T1,2,3);
    printf("Clock telah di set seperti semula\n");
    displayCLOCK(T1);
    printf("\n");

    NextMinute(&T1);
    printf("Waktu setelah ditambah 1 menit: ");
    DisplayExpiryTIME(T1);
    printf("\n");
    NextNMinute(&T1,5);
    printf("Waktu setelah ditambah 5 menit: ");
    DisplayExpiryTIME(T1);
    printf("\n");

    PrevMinute(&T1);
    printf("Waktu setelah dikurang 1 menit: ");
    DisplayExpiryTIME(T1);
    printf("\n");
    PrevNMinute(&T1,5);
    printf("Waktu detelah dikurang 5 menit: ");
    DisplayExpiryTIME(T1);
    printf("\n");

    return 0;
}