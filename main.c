#include <stdio.h>
#include "dataStructure/boolean.h"
#include "dataStructure/Matrix/matrix.c"
#include "dataStructure/ListStatik/liststatik.c"
#include "procedure/command.c"
#include "procedure/splashScreen.c"

int main () {
    boolean isStarted = false, isExit = false;
    Matrix mapconfig;
    ListStatik makananconfig;
    
    welcomePage();
    inputCommand(&isStarted, &isExit, &mapconfig, &makananconfig);
    while (!isExit) {
        inputCommand(&isStarted, &isExit, &mapconfig, &makananconfig);
    }

    
    return 0;
}