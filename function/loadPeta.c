#include <stdio.h>
#include "../dataStructure/CharMachine/charmachinefile.c"
#include "../dataStructure/WordMachine/wordmachinefile.c"

Matrix loadPeta () {
    STARTWORDFILE("config/peta.txt");

    int row = 0;
    for (int i = 0; i < currentWordFile.Length; i++) {
        row = (row * 10) + (currentWordFile.TabWord[i] - 48); 
    }

    ADVWORDFILE();

    int col = 0;
    for (int i = 0; i < currentWordFile.Length; i++) {
        col = (col * 10) + (currentWordFile.TabWord[i] - 48); 
    }

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

