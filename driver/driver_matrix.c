#include "stdio.h"
#include "../dataStructure/Matrix/matrix.h"
#include "../dataStructure/Point/point.h"

int main() {
    /*Run Driver: gcc ./driver/driver_matrix.c  ./datastructure/Matrix/Matrix.c ./datastructure/Point/point.c -o main */
    Matrix M;

    /*Testing CreateMatrix*/
    createMatrix(3, 4, &M);

    /*Inisialisasi nilai*/
    ELMT(M, 0, 0) = '#';
    ELMT(M, 0, 1) = '#';
    ELMT(M, 0, 2) = '#';
    ELMT(M, 0, 3) = '#';
    ELMT(M, 1, 0) = 'F';
    ELMT(M, 1, 1) = 'S';
    ELMT(M, 1, 2) = 'T';
    ELMT(M, 1, 3) = '#';
    ELMT(M, 2, 0) = '#';
    ELMT(M, 2, 1) = 'M';
    ELMT(M, 2, 2) = '#';
    ELMT(M, 2, 3) = '#';
    printf("%d %d\n", M.rowEff, M.colEff);

    /*Testing isMatrixIdxValid*/
    printf("%d\n", isMatrixIdxValid(0, 99));
    printf("%d\n", isMatrixIdxValid(0, 100));

    /*Testing getLastIdxRow*/
    printf("%d\n", getLastIdxRow(M));

    /*Testing getLastIdxCol*/
    printf("%d\n", getLastIdxCol(M));

    /*Testing isIdxEff*/
    /*Corner case benar*/
    printf("%d\n", isIdxEff(M, 0, 3));
    printf("%d\n", isIdxEff(M, 2, 3));
    printf("%d\n", isIdxEff(M, 0, 0));
    printf("%d\n", isIdxEff(M, 2, 0));

    /*Corner case salah*/
    printf("%d\n", isIdxEff(M, -1, 3));
    printf("%d\n", isIdxEff(M, 0, 4));
    printf("%d\n", isIdxEff(M, -1, 4));

    /*Testing copyMatrix dan displayMatrix*/
    Matrix M2;
    displayMatrix(M);
    copyMatrix(M, &M2);
    displayMatrix(M2);

    /*Testing countElement*/
    printf("%d\n", countElmt(M));

    /*Testing getEast, getNorth, getSouth, getWest*/
    POINT p;
    p = MakePOINT(1, 1);

    printf("%d\n", getEast(M, p));
    printf("%d\n", getNorth(M, p));
    printf("%d\n", getSouth(M, p));
    printf("%d\n", getWest(M, p));

    /*Testing getSimulatorLocation*/
    p = getSimulatorLocation(M);

    /*Testing getLegendaLocation*/
    p = getLegendaLocation(M, 'F');
    TulisPOINT(p);

    return 0;
}