#include <stdio.h>
#include "../dataStructure/Point/point.h"

int main(){
    /*Run Driver: gcc ./driver/driver_point.c  ./datastructure/Point/point.h -o main */
    POINT P1;
    POINT P2;

    int X1,Y1,X2,Y2;

    printf("Masukkan input nilai X Y dari P1: ");
    scanf("%d %d", &X1,&Y1);
    printf("Masukkan input nilai X Y dari P2: ");
    scanf("%d %d", &X2,&Y2);

    P1 = MakePOINT(X1,Y1);
    P2 = MakePOINT(X2,Y2);



    printf("Nilai P1: ");
    TulisPOINT(P1);
    printf("\n");
    printf("Nilai P2: ");
    TulisPOINT(P2);
    printf("\n");


    if(EQ(P1,P2)){
        printf("Titik P1 dan P2 sama\n");
    }
    else if(NEQ(P1,P2)){
        printf("Titik P1 dan P2 tidak sama\n");
    }

    if(IsOrigin(P1)){
        printf("P1 berada di titik origin\n");
    }
    if(IsOnSbX(P1)){
        printf("P1 berada di sumbu X\n");
    }

    if(IsOnSbY(P1)){
        printf("P1 berada di sumbu Y\n");
    }

    printf("P1 berada di kuadran %d\n", Kuadran(P1));

    printf("Geser P1 dalam sumbu X sebesar: ");
    scanf("%d",&X1);
    printf("Geser P1 dalam sumbu Y sebesar:  ");
    scanf("%d", &Y1);
    P1 = PlusDelta(P1, X1, Y2);

    printf("Nilai P1: ");
    TulisPOINT(P1);
    printf("\n");




    P1 = MirrorOf(P1, true);
    printf("Nilai P1 Setelah dicerminkan pada sumbu X: ");
    TulisPOINT(P1);
    printf("\n");

    float d1 = Jarak0(P1);

    printf("Jarak P1 terhadap titik origin: %f\n", d1);
    d1 = Panjang(P1,P2);
    printf("Jarak titik P1 dan P2 adaalah: %f\n", d1);




}