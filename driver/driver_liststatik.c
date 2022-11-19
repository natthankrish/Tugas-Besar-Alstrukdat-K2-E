#include <stdio.h>
#include "../dataStructure/ListStatik/liststatik.h"
#include "../dataStructure/Makanan/makanan.h"
#include "../dataStructure/Time/time.h"

int main(){
    /*Run Driver: gcc ./driver/driver_liststatik.c  ./datastructure/Time/time.h ./dataStructure/Makanan/makanan.h ./dataStructure/ListStatik/liststatik.h -o main */
    ListStatik L;
    CreateListStatik(&L);
    ListStatik L2;
    CreateListStatik(&L2);

    MAKANAN M1;
    TIME Expiry1;
    TIME delivery1;
    DIMENSION size1;

    CreateTime(&Expiry1,2,1,0);
    CreateTime(&delivery1,0,5,3); 
    CreateDimension(&size1,5,5); 
    CreateFood(&M1,1,"Ayam",Expiry1,1,delivery1,size1);

    MAKANAN M2;
    TIME Expiry2;
    TIME delivery2;
    DIMENSION size2;

    CreateTime(&Expiry2,3,1,0);
    CreateTime(&delivery2,0,5,3);
    CreateDimension(&size2,4,2);
    CreateFood(&M2,2,"Sapi",Expiry2,2,delivery2,size2);

    MAKANAN M3;
    TIME Expiry3;
    TIME delivery3;
    DIMENSION size3;

    CreateTime(&Expiry3,3,1,0);
    CreateTime(&delivery3,0,5,3);
    CreateDimension(&size3,4,2);
    CreateFood(&M3,3,"Ikan",Expiry3,2,delivery3,size3);
    
    insertFirst(&L,M1);
    insertLast(&L,M2);
    insertAt(&L,M3,1);

    insertFirst(&L2,M3);
    insertLast(&L2,M2);
    insertAt(&L2,M3,1);

    printf("Elemen pertama: %s\n", Name(getFirstElmt(L)));
    printf("Elemen kedua: %s\n", Name(ELMTlist(L,1)));
    printf("Elemen ketiga: %s\n", Name(getLastElmt(L)));

    if(isIdxValid(L,105)){
        printf("Idx valid\n\n");
    }else{
        printf("Idx tidak valid\n\n");
    }

    if(isIdxListEff(L,2)){
        printf("Idx efektif\n\n");
    }else{
        printf("Idx tidak efektif\n\n");
    }

    if(isEmpty(L)){
        printf("List kosong\n\n");
    }else{
        printf("List tidak kosong\n\n");
    }

    if(isListFull(L)){
        printf("List penuh\n\n");
    }else{
        printf("List tidak penuh\n\n");
    }

    MAKANAN MAX,MIN;
    extremeValuesExpiry(L,&MAX,&MIN);
    printf("Makanan dengan ID 2 berada di idx: %d\n",indexOfID(L,2));
    printf("Makanan Ayam berada di idx: %d\n",indexOfFood(L,"Ayam"));
    
    printf("Elemen dengan expiry terpanjang: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(MAX)));
    printf("\n");
    printf("Elemen dengan expiry terpendek: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(MIN)));
    printf("\n");

    extremeValuesDelivery(L,&MAX,&MIN);
    printf("Elemen dengan delivery terpanjang: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(MAX)));
    printf("\n");
    printf("Elemen dengan delivery terpendek: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(MIN)));
    printf("\n");
    
    sortListExpiry(&L,true);
    printf("List telah diurutkan membesar berdasarkan expiry\n");
    printf("Expiry elemen pertama: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(getFirstElmt(L))));
    printf("\n");
    printf("Expiry elemen kedua: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(ELMTlist(L,1))));
    printf("\n");
    printf("Expiry elemen ketiga: ");
    DisplayExpiryTIME(MinuteToTIME(Expiry(getLastElmt(L))));
    printf("\n");

    sortListDelivery(&L,true);
    printf("List telah diurutkan membesar berdasarkan delivery\n");
    printf("Delivery elemen pertama: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(getFirstElmt(L))));
    printf("\n");
    printf("Delivery elemen kedua: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(ELMTlist(L,1))));
    printf("\n");
    printf("Delivery elemen ketiga: ");
    DisplayExpiryTIME(MinuteToTIME(DeliveryTime(getLastElmt(L))));
    printf("\n");

    if(isListEqual(L,L2)){
        printf("Kedua list sama\n\n");
    }else{
        printf("Kedua list berbeda\n\n");
    }

    MAKANAN temp;
    deleteAt(&L,&temp,1);
    printf("ID makanan yang dihapus pada elemen index ke-1: %d\n",ID(temp));
    deleteFirst(&L,&temp);
    printf("ID makanan yang dihapus pada elemen pertama: %d\n",ID(temp));
    deleteLast(&L,&temp);
    printf("ID makanan yang dihapus pada elemen terakhir: %d\n",ID(temp));

    if(isEmpty(L)){
        printf("List telah kosong\n\n");
    }else{
        printf("List tidak kosong\n\n");
    }


    return 0;
}