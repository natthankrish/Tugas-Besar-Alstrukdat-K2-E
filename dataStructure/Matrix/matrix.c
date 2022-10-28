/* NIM : 13521162 */
/* Nama : Antonio Natthan Krishna */
/* Tanggal Pengerjaan : 21 September 2022 */
/* Topik Praktikum : ADT Matriks */
/* Deskripsi : Implementasi Matrix */
#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m) {
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return ((i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
    /* Mengirimkan Index baris terbesar m */
    return ((ROW_EFF(m) - 1));
}

IdxType getLastIdxCol(Matrix m) {
    /* Mengirimkan Index kolom terbesar m */
    return ((COL_EFF(m) - 1));
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return ((i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m)));
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    /* Mengirimkan elemen m(i,i) */
    return (ELMT(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    /* Melakukan assignment mOut <- mIn */
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (int i = 0; i < ROW_EFF(mIn); i++) {
        for (int j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i , j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
    /* I.S. isIdxValid(nRow,nCol) */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */
   createMatrix(nRow, nCol, m);
   for (int i = 0; i < ROW_EFF(*m); i++) {
        for (int j = 0; j < COL_EFF(*m); j++) {
            ElType input;
            scanf("%d", &input);
            ELMT (*m, i, j) = input;
        }
    }
}

void displayMatrix(Matrix m) {
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
   for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m)-1; j++) {
            printf("%c ", ELMT(m, i, j));
        }
        printf("%c\n", ELMT(m, i, COL_EFF(m) - 1));
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix mOut;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mOut);
    for (int i = 0; i < ROW_EFF(m1); i++) {
        for (int j = 0; j < COL_EFF(m1); j++) {
            ELMT(mOut, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return mOut;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix mOut;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mOut);
    for (int i = 0; i < ROW_EFF(m1); i++) {
        for (int j = 0; j < COL_EFF(m1); j++) {
            ELMT(mOut, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return mOut;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix mOut;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mOut);
    for (int i = 0; i < ROW_EFF(mOut); i++) {
        for (int j = 0; j < COL_EFF(mOut); j++) {
            int sum = 0;
            for (int k = 0, l = 0; k < COL_EFF(m1),  l < ROW_EFF(m2); k++, l++) {
                sum += ELMT(m1, i, k) * ELMT (m2, l, j);
            }
            ELMT(mOut, i, j) = sum;
        }
    }
    return mOut;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    /* Mengirim hasil perkalian setiap elemen m dengan x */
    Matrix mOut;
    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    for (int i = 0; i < ROW_EFF(mOut); i++) {
        for (int j = 0; j < COL_EFF(mOut); j++) {
            ELMT(mOut, i, j) = x * ELMT(m, i, j);
        }
    }
    return mOut;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    /* I.S. m terdefinisi, k terdefinisi */
    /* F.S. Mengalikan setiap elemen m dengan k */
    for (int i = 0; i < ROW_EFF(*m); i++) {
        for (int j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if (countElmt(m1) != countElmt(m2)) {
        return false;
    }

    for (int i = 0; i < ROW_EFF(m1); i++) {
        for (int j = 0; j < COL_EFF(m1); j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                return false;
            }
        }
    }

    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika m1 tidak sama dengan m2 */
    return (!isMatrixEqual(m1, m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return ((ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2)));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
    /* Mengirimkan banyaknya elemen m */
    return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    return ((ROW_EFF(m) == COL_EFF(m)));
}

boolean isSymmetric(Matrix m) {
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
    dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (!isSquare(m)) {
        return false;
    }

    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (i != j) {
                if (ELMT(m, i, j) != ELMT(m, j, i)) {
                    return false;
                }
            }
        }
    }

    return true;
}

boolean isIdentity(Matrix m) {
    /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
    setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (!isSquare(m)) {
        return false;
    }

    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (i != j) {
                if (ELMT(m, i, j) != 0) {
                    return false;
                }
            } else {
                if (ELMT(m, i, j) != 1) {
                    return false;
                }
            }
        }
    }

    return true;
}

boolean isSparse(Matrix m) {
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    double maxElement;
    maxElement = 0.05 * countElmt(m);
    
    int count = 0;
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) == 0) {
                count += 1;
            }
        }
    }

    int countElement;
    countElement = countElmt(m) - count;

    return (countElement <= maxElement);
};

Matrix negation(Matrix m) {
    /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    return multiplyByConst(m, -1);
}

void pNegation(Matrix *m) {
    /* I.S. m terdefinisi */
    /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m) {
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */
    int i, j, k,p, var=1;
    Matrix mFac;
    float det;
    if (countElmt(m) == 1){
        det = (float) ELMT(m,0,0);
    } else if (countElmt(m) == 4){
      det = (ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 1, 0) * ELMT(m, 0, 1));
      det = (float)(det);
    } else {
        // buat matrix lebih kecil untuk kofaktor
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mFac);
        det = 0;
        for (i = 0; i < ROW_EFF(m);i++){
            for (j = 1; j < ROW_EFF(m);j++){
                for (k = 0; k < COL_EFF(m);k++){
                    // jika kolom =  baris yg digunakan sbg var det, maka diabaikan
                    if (k==i) {
                        continue;
                    } else if(k<i)  {
                        p = k;
                    } else {
                    // jika k lebih besar dari nilai baris det, maka posisi k di matrix cofactor berkurang1
                    p = k - 1;
               }
               ELMT(mFac, j - 1, p) = ELMT(m, j, k);
            }
         }
         det += var * ELMT(m, 0, i) * determinant(mFac);
         var *= -1; //untuk penanda minus atau plus
      }
   }
   return det;
}

Matrix transpose(Matrix m) {
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix mOut;

    createMatrix(ROW_EFF(m), COL_EFF(m), &mOut);
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            ELMT(mOut, i, j) = ELMT(m, j, i);
        }
    }

    return mOut;
}

void pTranspose(Matrix *m) {
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix transposem;
    transposem = transpose(*m);

    copyMatrix(transposem, m);
}

float AvgRow(Matrix M, IdxType i) {
    /* Menghasilkan rata-rata dari elemen pada baris ke-i */
    /* Prekondisi: i adalah indeks baris efektif dari M */
    float sum = 0;
    for (int j = 0; j < COL_EFF(M); j++) {
        sum += ELMT(M, i, j);
    }
    sum /= COL_EFF(M);
    return sum;
}


float AvgCol(Matrix M, IdxType j) {
    /* Menghasilkan rata-rata dari elemen pada kolom ke-j */
    /* Prekondisi: j adalah indeks kolom efektif dari M */
    float sum = 0;
    for (int i = 0; i < ROW_EFF(M); i++) {
        sum += ELMT(M, i, j);
    }
    sum /= ROW_EFF(M);
    return sum;
}


void MinMaxRow(Matrix M, IdxType i, ElType * max, ElType * min) {
    /* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada baris i dari M
    min berisi elemen minimum pada baris i dari M */
    *max = ELMT(M, i, 0);
    *min = ELMT(M, i, 0);

    for (int j = 1; j < COL_EFF(M); j++) {
        if (ELMT(M, i, j) > *max) {
            *max = ELMT(M, i, j);
        }
        if (ELMT(M, i, j) < *min) {
            *min = ELMT(M, i, j);
        }
    }
}


void MinMaxCol(Matrix M, IdxType j, ElType * max, ElType * min) {
    /* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada kolom j dari M
    min berisi elemen minimum pada kolom j dari M */
    *max = ELMT(M, 0, j);
    *min = ELMT(M, 0, j);

    for (int i = 1; i < ROW_EFF(M); i++) {
        if (ELMT(M, i, j) > *max) {
            *max = ELMT(M, i, j);
        }
        if (ELMT(M, i, j) < *min) {
            *min = ELMT(M, i, j);
        }
    }
}

int CountNumRow(Matrix M, IdxType i, ElType X) {
    /* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    int count = 0;
    for (int j = 0; j < COL_EFF(M); j++) {
        if (ELMT(M, i, j) == X) {
            count += 1;
        }
    }
    return count;
}


int CountNumCol(Matrix M, IdxType j, ElType X) {
    /* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    int count = 0;
    for (int i = 0; i < ROW_EFF(M); i++) {
        if (ELMT(M, i, j) == X) {
            count += 1;
        }
    }
    return count;
}


void RotateMat(Matrix *m) {
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-rotasi" searah jarum jam
    untuk semua "lapisan" elemen mulai dari yang terluar
    Contoh matrix 3x3 sebelum dirotasi:
    1 2 3
    4 5 6
    7 8 9
    Contoh matrix 3x3 setelah dirotasi:
    4 1 2
    7 5 3
    8 9 6
    Contoh matrix 4x4 sebelum dirotasi:
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    Contoh matrix 4x4 setelah dirotasi:
    5 1 2 3
    9 10 6 4
    13 11 7 8
    14 15 16 12
    */

    if (ROW_EFF(*m) > 1) {
        //if (ROW_EFF(*m) % 2 == 0) {
            for (int lead_i = 0; lead_i < ROW_EFF(*m)/2; lead_i++) {
                int temp = ELMT(*m, lead_i, lead_i);
                int current_j = lead_i;
                int current_i = lead_i + 1;
                while (current_i < ROW_EFF(*m)-lead_i) {
                    ELMT(*m, current_i-1, current_j) = ELMT(*m, current_i, current_j);
                    current_i++;
                } // current_i == ROW_EFF(*m)-lead_i
                // Penyesuaian
                current_i--;
                current_j++;
                while (current_j < COL_EFF(*m)-lead_i) {
                    ELMT(*m, current_i, current_j-1) = ELMT(*m, current_i, current_j);
                    current_j++;
                } // current_j == COL_EFF(*m)-lead_i
                // Penyesuaian
                current_j--;
                current_i--;
                while (current_i >= lead_i) {
                    ELMT(*m, current_i+1, current_j) = ELMT(*m, current_i, current_j);
                    current_i--;
                } // current_i == lead_i
                // Penyesuaian
                current_j--;
                current_i++;
                while (current_j >= lead_i+1) {
                    ELMT(*m, current_i, current_j+1) = ELMT(*m, current_i, current_j);
                    current_j--;
                } // current_j == lead_i
                //printf("%d %d", current_i, current_j);
                ELMT(*m, current_i, current_j+1) = temp;
            }
       // } else {
            
        //}
    }
}

int getEast (Matrix m, POINT currentpoint) {
    if (isIdxEff(m, Absis(currentpoint), Ordinat(currentpoint)+1)) {
        if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)+1) == 'T') {
            return 1;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)+1) == 'C') {
            return 2;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)+1) == 'F') {
            return 3;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)+1) == 'B') {
            return 4;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)+1) == 'M') {
            return 5;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)+1) == '#') {
            return 0;
        } else {
            return 6;
        }
    } else {
        return -1;
    }
}

int getWest (Matrix m, POINT currentpoint) {
    if (isIdxEff(m, Absis(currentpoint), Ordinat(currentpoint)-1)) {
        if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)-1) == 'T') {
            return 1;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)-1) == 'C') {
            return 2;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)-1) == 'F') {
            return 3;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)-1) == 'B') {
            return 4;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)-1) == 'M') {
            return 5;
        } else if (ELMT(m, Absis(currentpoint), Ordinat(currentpoint)-1) == '#') {
            return 0;
        } else {
            return 6;
        }
    } else {
        return -1;
    }
}

int getNorth (Matrix m, POINT currentpoint) {
    if (isIdxEff(m, Absis(currentpoint)-1, Ordinat(currentpoint))) {
        if (ELMT(m, Absis(currentpoint)-1, Ordinat(currentpoint)) == 'T') {
            return 1;
        } else if (ELMT(m, Absis(currentpoint)-1, Ordinat(currentpoint)) == 'C') {
            return 2;
        } else if (ELMT(m, Absis(currentpoint)-1, Ordinat(currentpoint)) == 'F') {
            return 3;
        } else if (ELMT(m, Absis(currentpoint)-1, Ordinat(currentpoint)) == 'B') {
            return 4;
        } else if (ELMT(m, Absis(currentpoint)-1, Ordinat(currentpoint)) == 'M') {
            return 5;
        } else if (ELMT(m, Absis(currentpoint)-1, Ordinat(currentpoint)) == '#') {
            return 0;
        } else {
            return 6;
        }
    } else {
        return -1;
    }
}

int getSouth (Matrix m, POINT currentpoint) {
    if (isIdxEff(m, Absis(currentpoint)+1, Ordinat(currentpoint))) {
        if (ELMT(m, Absis(currentpoint)+1, Ordinat(currentpoint)) == 'T') {
            return 1;
        } else if (ELMT(m, Absis(currentpoint)+1, Ordinat(currentpoint)) == 'C') {
            return 2;
        } else if (ELMT(m, Absis(currentpoint)+1, Ordinat(currentpoint)) == 'F') {
            return 3;
        } else if (ELMT(m, Absis(currentpoint)+1, Ordinat(currentpoint)) == 'B') {
            return 4;
        } else if (ELMT(m, Absis(currentpoint)+1, Ordinat(currentpoint)) == 'M') {
            return 5;
        } else if (ELMT(m, Absis(currentpoint)+1, Ordinat(currentpoint)) == '#') {
            return 0;
        } else {
            return 6;
        }
    } else {
        return -1;
    }
}

POINT getSimulatorLocation (Matrix map) {
    int foundi, foundj;
    for (int i = 0; i < ROW_EFF(map); i++) {
        for (int j = 0; j < COL_EFF(map); j++) {
            if (ELMT(map, i, j) == 'S') {
                foundi = i;
                foundj = j;
            }
        }
    }
    return MakePOINT(foundi, foundj);
}

