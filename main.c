#include <stdio.h>
#include "dataStructure/boolean.h"
#include "dataStructure/Matrix/matrix.c"
#include "procedure/command.c"
#include "procedure/splashScreen.c"

int main () {
    boolean isStarted = false, isExit = false;
    Matrix map;
    
    welcomePage();
    inputCommand(&isStarted, &isExit, &map);
    displayMatrix(map);
    while (!isExit) {
        inputCommand(&isStarted, &isExit, &map);
    }

    
    return 0;
}