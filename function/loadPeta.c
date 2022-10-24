#include <stdio.h>
//#include "copyIntegerFromFile.c"

Matrix loadPeta () {
    STARTWORDFILE("config/peta.txt");

    int row;
    copyIntegerFromWordMachine(&row, currentWordFile);

    ADVWORDFILE();

    int col;
    copyIntegerFromWordMachine(&col, currentWordFile);

    Matrix Peta;
    createMatrix(row, col, &Peta);

    ADVWORDFILE();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ELMT(Peta, i, j) = currentWordFile.TabWord[j];
        }
        ADVWORDFILE();
    }
    
    return Peta;
}

