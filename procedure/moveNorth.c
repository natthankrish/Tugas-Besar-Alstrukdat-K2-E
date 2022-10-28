#include <stdio.h>

void moveNorth(SIMULATOR *S, Matrix *peta){
    for (int i = 0; i < ROW_EFF(*peta); i++ ) {
        for (int j = 0; j < COL_EFF(*peta); j++) {
            if (ELMT(*peta, i, j) == 'S') {
                ELMT(*peta, i-1, j) = 'S';
                ELMT(*peta, i, j) = '#';
            }
        }
    }
    Lokasi(*S) = getSimulatorLocation(*peta);
}