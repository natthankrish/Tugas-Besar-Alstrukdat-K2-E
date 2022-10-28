#include <stdio.h>
#include "dataStructure/boolean.h"
#include "dataStructure/Point/point.c"
#include "dataStructure/Simulator/simulator.c"
#include "dataStructure/Matrix/matrix.c"
#include "dataStructure/ListStatik/liststatik.c"
#include "dataStructure/PrioQueue/prioqueue.c"
#include "dataStructure/Time/time.c"
#include "procedure/command.c"
#include "procedure/splashScreen.c"
#include "procedure/printPeta.c"

int main () {
    boolean isStarted = false, isExit = false;
    Matrix mapconfig;
    ListStatik makananconfig;
    SIMULATOR BNMO;

    TIME machinetime;
    setClockZero(&machinetime);

    welcomePage();
    inputCommand(&isStarted, &isExit, &mapconfig, &makananconfig, &machinetime, &BNMO);
    while (!isExit) {
        if (isStarted) {
            printStatus(mapconfig, machinetime, BNMO);
        }
        inputCommand(&isStarted, &isExit, &mapconfig, &makananconfig, &machinetime, &BNMO);
    }

    return 0;
}