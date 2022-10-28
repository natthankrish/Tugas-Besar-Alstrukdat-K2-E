#include <stdio.h>

void moveWest(SIMULATOR *S, Matrix *peta){
    boolean stat = false;
    int i = 0, j = 0;
    while (i < ROW_EFF(*peta) && !stat) {
        j = 0;
        while (j < COL_EFF(*peta) && !stat) {
            if (ELMT(*peta, i, j) == 'S') {
                ELMT(*peta, i, j) = '#';
                ELMT(*peta, i, j-1) = 'S';
                stat = true;
            }
            j++;
        }
        i++;
    }
    
    Lokasi(*S) = getSimulatorLocation(*peta);
}