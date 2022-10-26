#include <stdio.h>
#include "time.h"
#include "math.h"

boolean IsTIMEValid (int D, int H, int M){
/* Mengirim true jika D,H,M dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return (D>=0 && H>=0 && M>=0);
}

boolean IsCLOCKValid (int D, int H, int M){
/* Mengirim true jika D,H,M dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    return (H>=0 && H<24 && M>=0 && M<60);
}

void CreateTime (TIME *T, int D, int HH, int MM){
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
    if(IsTIMEValid(D, HH, MM)){
        Day(*T) = D;
        Hour(*T) = HH;
        Minute(*T) = MM;
    }
    
}

void setClockZero(TIME *T){
/*Mensetting clock menjadi pukul 00.00*/
    Hour(*T)=0;
    Minute(*T)=0;
}

void setClock(TIME *T, int HH, int MM){
/*Mensetting clock menjadi pukul tertentu*/
    Hour(*T)=HH;
    Minute(*T)=MM;
}

void SetTIME (TIME * T){
    scanf("%d %d %d", &Day(*T), &Hour(*T), &Minute(*T));
}

void displayCLOCK(TIME T){
/*Menampilkan jam*/
/*Pastikan time yang dimasukkan merupakan time clock dan bukan time biasa*/
    printf("%d.%d", Hour(T), Minute(T));
}

void DisplayExpiryTIME (TIME T){
    if(Day(T)>0){
        printf("%d hari ", Day(T));
    }
    if(Hour(T)>0){
        printf("%d jam ", Hour(T));
    }
    if(Hour(T)>0){
        printf("%d menit", Minute(T));
    }
    printf("\n");
}

long TIMEToMinute (TIME T){
    long sum = Day(T)*1440 + Hour(T)*60 + Minute(T);
    return sum;
}


TIME MinuteToTIME (long N){
    TIME time;
    Day(time) = N/1440;
    Hour(time) = (N%1440)/60;
    Minute(time) = (N%1440)%60;
    return time;
}

boolean TEQ (TIME T1, TIME T2){
    return (Day(T1)==Day(T2) || Hour(T1)==Hour(T2) || Minute(T1)==Minute(T2));
}

boolean TNEQ (TIME T1, TIME T2){
    return !TEQ(T1,T2);
}

boolean TLT (TIME T1, TIME T2){
    if(TIMEToMinute(T1)<TIMEToMinute(T2)){
        return true;
    }
    return false;
}

boolean TGT (TIME T1, TIME T2){
    if(TIMEToMinute(T1)>TIMEToMinute(T2)){
        return true;
    }
    return false;
}

TIME Longest(TIME T1, TIME T2){
    if(TGT(T1, T2)){
        return T1;
    }
    if(TEQ(T1,T2)){
        return T1;
    }
    return T2;
}

TIME NextMinute (TIME T){
    long minute = TIMEToMinute(T);
    minute= minute+1;
    TIME Ti = MinuteToTIME(minute);
    return Ti;
}

TIME NextNMinute (TIME T, int N){
    long minute = TIMEToMinute(T);
    minute=minute+N;
    TIME Ti = MinuteToTIME(minute);
    return Ti;
}

void PrevMinute (TIME *T){
    long minute = TIMEToMinute(*T);
    if(minute-N<0){
        Hour(*T)--;
        Minute(*T) = 60;
    }
    Minute(*T)--;
}

void PrevNMinute (TIME *T, int N){
    long minute = TIMEToMinute(*T);
    if(minute-N<0){
        Hour(*T)--;
        Minute(*T) = Minute(*T)+60;
    }
    Minute(*T)-=N;
}

long MinuteDuration(TIME Tbegin, TIME Tend){
    return TIMEToMinute(Tend) - TIMEToMinute(Tbegin);
}

TIME Duration(TIME Tbegin, TIME Tend){
    return MinuteToTIME(MinuteDuration(Tbegin,Tend));
}