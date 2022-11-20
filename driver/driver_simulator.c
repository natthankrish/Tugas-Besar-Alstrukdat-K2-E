#include <stdio.h>
#include "../dataStructure/Simulator/simulator.h"

int main(){
    /*Run Driver: gcc ./driver/driver_simulator.c  ./datastructure/Simulator/simulator.h -o main */
    SIMULATOR S;
    char X[10];
    X = "BNMO";
    POINT P = MakePOINT(3,4);

    PrioQueue pq;
    MAKANAN tmp;
    tmp.name[0] = 'h';
    tmp.name[1] = 'e';
    tmp.name[2] = 'h';
    tmp.name[3] = 'e';
    tmp.deliveryTime = MinuteToTIME(10);
    Enqueue(&pq, tmp);


    
    CreateSIMULATOR(S, X, P, pq);
    
    POINT PE = getPoint(P);
    TulisPOINT(PE);
    printf("\n");

    char Y[10];
    copySimulatorName(X,Y);
    printf("%s", Y);

    PrioQueue pqtemp;
    pqtemp = getInventory(S);

    
}