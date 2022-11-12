#include "../dataStructure/PrioQueue/prioqueue.h"
#include <stdio.h>

void delivery(PrioQueue pesanan){
    printf("List Makanan di Perjalanan :\n\n");
    if(IsEmpty(pesanan)){
        printf("Tidak ada makanan yang sedang diantar !\n");
    } else{
        for(int i = 0; i < NBElmt(pesanan);i++){
            printf("    %d. ",i+1);
            for(int j = 0; j < 101; j++){
                printf("%c",Elmt(pesanan,i).name[j]);
            }
            printf("\n      Waktu sisa delivery : ");
            if (Elmt(pesanan,i).deliveryTime.D != 0) {
                printf(" %d Hari", Elmt(pesanan,i).deliveryTime.D);
            }

            if (Elmt(pesanan,i).deliveryTime.HH != 0) {
                printf(" %d Jam", Elmt(pesanan,i).deliveryTime.HH);
            }

            if (Elmt(pesanan,i).deliveryTime.MM != 0) {
                printf(" %d Menit", Elmt(pesanan,i).deliveryTime.MM);
            }
            printf("\n\n");
        }
    }

    
}