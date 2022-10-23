#include <stdio.h>
#include "../boolean.h"
#include "makanan.h"
#include "../Time/time.c"

void CreateFood(MAKANAN *M){
/*Register food baru berdasarkan input*/
/*Cuma buat testing*/
    printf("Register food ID: ");
    scanf("%d", &ID(*M));
    printf("Register food name: ");
    scanf("%s", Name(*M));
    printf("Register expiry time\n");
    printf("Day(s): Hour(s): Minute(S): \n");
    scanf("%d %d %d", &(*M).expiry.D, &(*M).expiry.HH, &(*M).expiry.MM);
    printf("1.Buy 2.Chop 3.Fry 4.Boil 5.Mix\n");
    printf("Register cooking action from above options: ");
    scanf("%d", &Action(*M));
    printf("Register delivery time\n");
    printf("Day(s): Hour(s): Minute(S): \n");
    scanf("%d %d %d", &(*M).deliveryTime.D, &(*M).deliveryTime.HH, &(*M).deliveryTime.MM);
    printf("Register food size\n");
    printf("Width: Height:\n");
    scanf("%d %d", &Width(*M), &Height(*M));
    printf("FOOD HAS BEEN FULLY REGISTERED!\n");
}

const char* getAction(MAKANAN M, boolean caps){
/*Mengambil aksi makanan*/
/*Jika caps=true, maka akan dikembalikan dalam tulisan kapital*/
/*Jika caps=false, maka akan dikembalikan dalam tulisan biasa*/
    if(Action(M)==1){
        if(caps){
            return "BUY";
        }
        return "Buy";
    }else if(Action(M)==2){
        if(caps){
            return "CHOP";
        }
        return "Chop";
    }else if(Action(M)==3){
        if(caps){
            return "FRY";
        }
        return "Fry";
    }else if(Action(M)==4){
        if(caps){
            return "BOIL";
        }
        return "Boil";
    }else{
        if(caps){
            return "MIX";
        }
        return "Mix";
    }
}

void decreaseExpiry(MAKANAN *M){
/*Mengurangi waktu expiry sebanyak 1 menit*/
/*Tidak bisa kurang dari 0*/
    (*M).expiry=PrevMinute((*M).expiry);
    if(Expiry(*M)<0){
        (*M).expiry=MinuteToTIME(0);
    }
}

void increaseExpiry(MAKANAN *M){
/*Menambah waktu expiry sebanyak 1 menit*/
    (*M).expiry=NextMinute((*M).expiry);
}

void decreaseDelivery(MAKANAN *M){
/*Mengurangi waktu delivery sebanyak 1 menit*/
/*Tidak bisa kurang dari 0*/
    (*M).deliveryTime=PrevMinute((*M).deliveryTime);
    if(DeliveryTime(*M)<0){
        (*M).deliveryTime=MinuteToTIME(0);
    }
}

void increaseDelivery(MAKANAN *M){
/*Menambah waktu delivery sebanyak 1 menit*/
    (*M).deliveryTime=NextMinute((*M).deliveryTime);
}

boolean isExpired(MAKANAN M){
/*Menentukan apakah makanan sudah expired atau belum*/
    return (Expiry(M)==0);
}

boolean isDelivered(MAKANAN M){
/*Menentukan apakah makanan sudah expired atau belum*/
    return (DeliveryTime(M)==0);
}

boolean isExpiryEQ(MAKANAN M1, MAKANAN M2){
/*Membandingkan apakah makanan M1 dan M2 memiliki expiry yang sama*/
    return (Expiry(M1)==Expiry(M2));
}

boolean isDeliveryEQ(MAKANAN M1, MAKANAN M2){
/*Membandingkan apakah makanan M1 dan M2 memiliki delivery time yang sama*/
    return (DeliveryTime(M1)==DeliveryTime(M2));
}

boolean ExpiryGT(MAKANAN M1, MAKANAN M2){
/*Menentukan apakah expiry M1 lebih panjang daripada M2*/
    return (Expiry(M1)>Expiry(M2));
}

boolean ExpiryLT(MAKANAN M1, MAKANAN M2){
/*Menentukan apakah expiry M1 lebih pendek daripada M2*/
    return (Expiry(M1)<Expiry(M2));
}

boolean DeliveryGT(MAKANAN M1, MAKANAN M2){
/*Menentukan apakah delivery time M1 lebih panjang daripada M2*/
    return (DeliveryTime(M1)>DeliveryTime(M2));
}

boolean DeliveryLT(MAKANAN M1, MAKANAN M2){
/*Menentukan apakah delivery time M1 lebih pendek daripada M2*/
    return (DeliveryTime(M1)<DeliveryTime(M2));
}

MAKANAN longestExpiry(MAKANAN M1, MAKANAN M2){
/*Menentukan makanan yang memiliki expiry lebih panjang diantara M1 dan M2*/
    if(DeliveryGT(M1,M2)){
        return M1;
    }
    return M2;
}

MAKANAN shortestExpiry(MAKANAN M1, MAKANAN M2){
/*Menentukan makanan yang memiliki expiry lebih pendek diantara M1 dan M2*/
    if(DeliveryLT(M1,M2)){
        return M1;
    }
    return M2;
}

MAKANAN longestDelivery(MAKANAN M1, MAKANAN M2){
/*Menentukan makanan yang memiliki delivery time lebih panjang diantara M1 dan M2*/
    if(DeliveryGT(M1,M2)){
        return M1;
    }
    return M2;
}

MAKANAN shortestDelivery(MAKANAN M1, MAKANAN M2){
/*Menentukan makanan yang memiliki delivery time lebih pendek diantara M1 dan M2*/
    if(DeliveryLT(M1,M2)){
        return M1;
    }
    return M2;
}

boolean isFit(MAKANAN M, int X, int Y){
/*Menentukan apakah ukuran makanan M muat pada tempat dengan lebar X dan tinggi Y*/
    return (Height(M)<=Y && Width(M)<+X);
}

