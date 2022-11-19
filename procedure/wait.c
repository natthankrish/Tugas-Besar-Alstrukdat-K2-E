#include <stdio.h>
#include "../dataStructure/Time/time.h"
#include "../dataStructure/Makanan/makanan.h"
#include "../dataStructure/PrioQueue/prioqueue.h"
#include "../dataStructure/Simulator/simulator.h"
#include "../dataStructure/ListStatik/ListNotif.h"

void wait(int h, int m, PrioQueue *pesanan, SIMULATOR *BNMO, TIME *machinetime, ListNotif *notifikasi){
    int waiting = h*60 + m;
    int machtime = TIMEToMinute(*machinetime);
    int newtime = machtime + waiting;
    *machinetime = MinuteToTIME(newtime);

    if(!IsEmpty(BNMO->INVENTORY)){
        for(int i=(BNMO->INVENTORY.HEAD);i<(BNMO->INVENTORY.HEAD + NBElmt(BNMO->INVENTORY));i++){
            int expirytime = TIMEToMinute(BNMO->INVENTORY.T[i%MaxEl(BNMO->INVENTORY)].expiry);
            int newexpiry = expirytime - waiting;
            BNMO->INVENTORY.T[i%MaxEl(BNMO->INVENTORY)].expiry = MinuteToTIME(newexpiry);
        }
    }

    if(!IsEmpty(*pesanan)){
        for(int i=(pesanan->HEAD);i<(pesanan->HEAD + NBElmt(*pesanan));i++){
            int deliverytime = TIMEToMinute(pesanan->T[i%MaxEl(*pesanan)].deliveryTime);
            int newdelivery = deliverytime - waiting;
            if(newdelivery > 0){
                pesanan->T[i%MaxEl(*pesanan)].deliveryTime = MinuteToTIME(newdelivery);
            }else{
                MAKANAN tmp = pesanan->T[i%MaxEl(*pesanan)];
                if(ID(tmp) == ID(pesanan->T[Head(*pesanan)])){
                    Dequeue(pesanan, &tmp);
                }else{
                    AmbilMakanan(pesanan, tmp);
                    i--;
                }
                pushNotif(notifikasi, tmp, 6);
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
        pushNotif(notifikasi, tmp, 7);
    }
}