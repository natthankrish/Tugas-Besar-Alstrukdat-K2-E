#include <stdio.h>
#include "../dataStructure/Makanan/makanan.h"
#include "../dataStructure/Time/time.h"

int main(){
    /*Run Driver: gcc ./driver/driver_makanan.c  ./datastructure/Time/time.h ./dataStructure/Makanan/makanan.h -o main */
    MAKANAN M1;
    TIME Expiry1;
    TIME delivery1;
    DIMENSION size1;

    CreateTime(&Expiry1,2,1,0); /*Expiry dengan waktu 2 hari 1 jam*/
    CreateTime(&delivery1,0,5,3); /*Deivery dengan waktu 5 jam 3 menit*/
    CreateDimension(&size1,5,5); /*Dimensi makanan dengan tinggi 5 dan lebar 5*/
    CreateFood(&M1,1,"Ayam",Expiry1,1,delivery1,size1);

    MAKANAN M2;
    TIME Expiry2;
    TIME delivery2;
    DIMENSION size2;

    CreateTime(&Expiry2,3,1,0); /*Expiry dengan waktu 2 hari 1 jam*/
    CreateTime(&delivery2,0,5,3); /*Deivery dengan waktu 5 jam 3 menit*/
    CreateDimension(&size2,4,2); /*Dimensi makanan dengan tinggi 5 dan lebar 5*/
    CreateFood(&M2,2,"Sapi",Expiry2,2,delivery2,size2);

    printf("Deskripsi Makanan 1\n");
    printf("ID: %d\n", ID(M1));
    printf("Nama: %s\n",Name(M1));
    printf("Waktu expiry: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(M1)));
    printf("\n");
    printf("Waktu delivery: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(M1)));
    printf("\n");
    printf("Aksi yang bisa dilakukan: %s\n",getAction(M1,false));
    printf("Ukuran: %d x %d\n",Height(M1),Width(M1));
    printf("\n");

    printf("Deskripsi Makanan 2\n");
    printf("ID: %d\n", ID(M2));
    printf("Nama: %s\n",Name(M2));
    printf("Waktu expiry: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(M2)));
    printf("\n");
    printf("Waktu delivery: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(M2)));
    printf("\n");
    printf("Aksi yang bisa dilakukan: %s\n",getAction(M2,false));
    printf("Ukuran: %d x %d\n",Height(M2),Width(M2));

    printf("------------------------------------------------------------\n");
    decreaseExpiry(&M1);
    printf("Expiry Makanan 1 setelah dikurang 1 menit: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(M1)));
    printf("\n");
    increaseExpiry(&M1);
    printf("Expiry Makanan 1 setelah ditambah 1 menit: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(M1)));
    printf("\n");
    decreaseDelivery(&M1);
    printf("Delivery Makanan 1 setelah dikurang 1 menit: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(M1)));
    printf("\n");
    increaseDelivery(&M1);
    printf("Delivery Makanan 1 setelah ditambah 1 menit: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(M1)));
    printf("\n");

    if(isExpired(M1)){
        printf("Makanan 1 sudah expired\n");
    }else{
        printf("Makanan 1 belum expired\n");
    }
    printf("\n");
    if(isDelivered(M1)){
        printf("Makanan 1 sudah delivered\n");
    }else{
        printf("Makanan 1 belum delivered\n");
    }
    printf("\n");
    if (isExpiryEQ(M1,M2)){
        printf("Waktu expiry kedua makanan sama\n");
    }else{
        printf("Waktu expiry kedua makanan tidak sama\n");
    }
    printf("\n");
    if (isDeliveryEQ(M1,M2)){
        printf("Waktu delivery kedua makanan sama\n");
    }else{
        printf("Waktu delivery kedua makanan tidak sama\n");
    }
    printf("\n");
    if(ExpiryGT(M1,M2)){
        printf("Waktu expiry Makanan 1 lebih lama dari Makanan 2\n");
    }else{
        printf("Waktu expiry Makanan 1 tidak lebih lama dari Makanan 2\n");
    }
    printf("\n");
    if(ExpiryLT(M1,M2)){
        printf("Waktu expiry Makanan 1 lebih pendek dari Makanan 2\n");
    }else{
        printf("Waktu expiry Makanan 1 tidak lebih pendek dari Makanan 2\n");
    }
    printf("\n");
    if(DeliveryGT(M1,M2)){
        printf("Waktu delivery Makanan 1 lebih lama dari Makanan 2\n");
    }else{
        printf("Waktu delivery Makanan 1 tidak lebih lama dari Makanan 2\n");
    }
    printf("\n");
    if(ExpiryLT(M1,M2)){
        printf("Waktu delivery Makanan 1 lebih pendek dari Makanan 2\n");
    }else{
        printf("Waktu delivery Makanan 1 tidak lebih pendek dari Makanan 2\n");
    }
    printf("\n");


    if(isFit(M1,6,5)){
        printf("Makanan muat pada tempat ukutan 6x5\n");
    }else{
        printf("Makanan tidak muat pada tempat ukutan 6x5\n");
    }

    return 0;
}