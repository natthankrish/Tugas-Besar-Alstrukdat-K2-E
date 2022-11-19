#include <stdio.h>
#include "../dataStructure/Kulkas/kulkas.c"
#include "../dataStructure/Time/time.c"
#include "../dataStructure/Makanan/makanan.c"
#include "../dataStructure/Point/point.c"
#include "../dataStructure/Simulator/simulator.c"

int main(){
    KULKAS K;
    DIMENSION D;
    
    MAKANAN M1;
    TIME Expiry1;
    TIME delivery1;
    DIMENSION size1;

    CreateTime(&Expiry1,2,1,0); /*Expiry dengan waktu 2 hari 1 jam*/
    CreateTime(&delivery1,0,5,3); /*Deivery dengan waktu 5 jam 3 menit*/
    CreateDimension(&size1,5,5); /*Dimensi makanan dengan tinggi 5 dan lebar 5*/
    CreateFood(&M1,1,"Ayam",Expiry1,1,delivery1,size1);

    CreateDimension(&D,5,5);
    CreateFridge(&K,D);

    if(isFridgeFull(K)){
        printf("Kulkas penuh\n\n");
    }else{
        printf("Kulkas tidak penuh\n\n");
    }

    if(isFridgeEmpty(K)){
        printf("Kulkas kosong\n\n");
    }else{
        printf("Kulkas tidak kosong\n\n");
    }

    printf("\nJumlah petak kosong di kulkas: %d\n\n",SpaceLeft(K));

    inToFridge(&K,&M1);
    printf("Ayam telah dimasukkan ke dalam kulkas\n");

    displayFridge(K);

    printf("\n\nJumlah petak kosong di kulkas: %d\n\n",SpaceLeft(K));

    outFromFridge(&K,1,&M1);
    printf("Ayam telah dikeluarkan dari kulkas\n");

    displayFridge(K);

    printf("\n\nJumlah petak kosong di kulkas: %d\n\n",SpaceLeft(K));

    return 0;
}