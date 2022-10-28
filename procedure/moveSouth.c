#include <stdio.h>

void moveSouth(SIMULATOR *S, Matrix *peta){
    
    boolean stat = false;
    int i = 0, j = 0;
    while (i < ROW_EFF(*peta) && !stat) {
        j = 0;
        while (j < COL_EFF(*peta) && !stat) {
            if (ELMT(*peta, i, j) == 'S') {
                ELMT(*peta, i, j) = '#';
                ELMT(*peta, i+1, j) = 'S';
                stat = true;
            }
            j++;
        }
        i++;
    }
    
    Lokasi(*S) = getSimulatorLocation(*peta);
}