#include <stdio.h>
#include "../dataStructure/Time/time.h"
#include "../dataStructure/Makanan/makanan.h"
#include "../dataStructure/PrioQueue/prioqueue.h"
#include "../dataStructure/Simulator/simulator.h"

void printKadaluwarsa(MAKANAN m){
    for(int i=0;i<101;i++){
        printf("%c", m.name[i]);
    }
    printf(" kadaluwarsa...\n");
}

void printDelivery(MAKANAN m){
    for(int i=0;i<101;i++){
        printf("%c", m.name[i]);
    }
    printf(" sudah diterima...\n");
}

void wait(int h, int m, PrioQueue *pesanan, SIMULATOR *BNMO, TIME *machinetime){
    int waiting = h*60 + m;
    int machtime = TIMEToMinute(*machinetime);
    int newtime = machtime + waiting;
    *machinetime = MinuteToTIME(newtime);

    int notifcount = 1;
    printf("Notifikasi: \n");

    if(!IsEmpty(BNMO->INVENTORY)){
        printf("test");
        for(int i=(BNMO->INVENTORY.HEAD);i<=(BNMO->INVENTORY.HEAD + NBElmt(BNMO->INVENTORY));i++){
            int expirytime = TIMEToMinute(BNMO->INVENTORY.T[i%MaxEl(BNMO->INVENTORY)].expiry);
            int newexpiry = expirytime - waiting;
            BNMO->INVENTORY.T[i%MaxEl(BNMO->INVENTORY)].expiry = MinuteToTIME(newexpiry);
        }
    }

    if(!IsEmpty(*pesanan)){
        for(int i=(pesanan->HEAD);i<=(pesanan->HEAD + NBElmt(*pesanan));i++){
            int deliverytime = TIMEToMinute(pesanan->T[i%MaxEl(*pesanan)].deliveryTime);
            int newdelivery = deliverytime - waiting;
            if(newdelivery > 0){
                pesanan->T[i%MaxEl(*pesanan)].expiry = MinuteToTIME(newdelivery);
            }else{
                MAKANAN tmp;
                Dequeue(pesanan, &tmp);
                printf("%d. ", notifcount++);
                printDelivery(tmp);
                tmp.deliveryTime = MinuteToTIME(0);
                int expirytime = TIMEToMinute(tmp.expiry);
                int newexpiry = expirytime - newdelivery;
                tmp.expiry = MinuteToTIME(newexpiry);
                Enqueue(&(BNMO->INVENTORY), tmp);
            }
        }
    }

    while(!IsEmpty(BNMO->INVENTORY) && TIMEToMinute(InfoHead(BNMO->INVENTORY).expiry) <= 0){
        MAKANAN tmp;
        Dequeue(&(BNMO->INVENTORY), &tmp);
        printf("%d. ", notifcount++);
        printKadaluwarsa(tmp);
    }
}