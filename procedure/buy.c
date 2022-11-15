#include "../dataStructure/Simulator/simulator.h"
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/PrioQueue/prioqueue.h"
#include "../dataStructure/CharMachine/charmachine.h"
#include "../dataStructure/WordMachine/wordmachine.h"
#include <stdio.h>

MAKANAN* buy(ListStatik makanan, PrioQueue *pesanan){
    int num = 0;
    int urutanDapatBuy[101];
    int inputBuy;
    printf("===============================================\n");
    printf("                      BUY\n");
    printf("===============================================\n");
    printf("List Bahan Makanan :\n");
    for(int i = 0; i < makanan.length; i++){
        if(makanan.contents[i].action == 1){
            urutanDapatBuy[num] = i;
            num++;
            printf("    %d.",num);
            for(int j = 0; j < 101; j++){
                printf("%c", makanan.contents[i].name[j]);
            }
            printf("\n");
            printf("      Waktu Delivery: ");
            if (makanan.contents[i].deliveryTime.D != 0) {
                printf(" %d Hari", makanan.contents[i].deliveryTime.D);
            }

            if (makanan.contents[i].deliveryTime.HH != 0) {
                printf(" %d Jam", makanan.contents[i].deliveryTime.HH);
            }

            if (makanan.contents[i].deliveryTime.MM != 0) {
                printf(" %d Menit", makanan.contents[i].deliveryTime.MM);
            }
            printf("\n\n");
        }
        

    }
    printf("Kirim 0 untuk keluar dari BUY\n\n");
    printf("Enter command: ");
    STARTWORD();
    printf("\n");
    if (!compareString(currentWord.TabWord, currentWord.Length, "0", 1)) {
        if (currentChar == MARK) {
            
            inputBuy = (int)currentWord.TabWord[0] - 49;
            if(makanan.contents[urutanDapatBuy[inputBuy]].action == 1){
            printf("Berhasil memesan ");
            for(int i = 0; i < 101; i++){
                printf("%c",makanan.contents[urutanDapatBuy[inputBuy]].name[i]);
            }
            printf(" !\n");
            printf("Pesanan akan diantar dalam : ");
            if (makanan.contents[urutanDapatBuy[inputBuy]].deliveryTime.D != 0) {
                printf(" %d Hari", makanan.contents[urutanDapatBuy[inputBuy]].deliveryTime.D);
            }

            if (makanan.contents[urutanDapatBuy[inputBuy]].deliveryTime.HH != 0) {
                printf(" %d Jam", makanan.contents[urutanDapatBuy[inputBuy]].deliveryTime.HH);
            }

            if (makanan.contents[urutanDapatBuy[inputBuy]].deliveryTime.MM != 0) {
                printf(" %d Menit", makanan.contents[urutanDapatBuy[inputBuy]].deliveryTime.MM);
            }
            printf("\n");

            Enqueue(pesanan, makanan.contents[urutanDapatBuy[inputBuy]]);
            MAKANAN *ret = &makanan.contents[urutanDapatBuy[inputBuy]];
            return ret;

        }
        } else {
            while (!endWord) {
                ADVWORD();
            }
            printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
        }
    }

    return NULL; // ngecek berhasil beli atau tidak
}