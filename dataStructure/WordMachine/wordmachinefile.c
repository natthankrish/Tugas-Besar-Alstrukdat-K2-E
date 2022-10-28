/* NIM : 13521162 */
/* Nama : Antonio Natthan Krishna */
/* Tanggal Pengerjaan : 28 September 2022 */
/* Topik Praktikum : Word Machine */
/* Deskripsi : wordmachine.c */

#include <stdio.h>
#include "wordmachinefile.h"

boolean endWordFile;
WordFile currentWordFile;

void IgnoreBlanksFile() {
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentCharFile == BLANK) {
        ADVFILE();
    }
}

void STARTWORDFILE(char path[]) {
    /* I.S. : currentChar sembarang
    F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */
    STARTFILE(path);
    IgnoreBlanksFile();
    if (currentCharFile == MARK) {
        endWordFile= true;
    } else {
        endWordFile = false;
        CopyWordFile();
    }
    
}

void ADVWORDFILE() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanksFile();
    if (currentCharFile == MARK) {
        endWordFile = true;
        ADVFILE();
        CopyWordFile();
    } else {
        endWordFile = false;
        CopyWordFile();
        IgnoreBlanksFile();
    }
}

void CopyWordFile() {
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    
    while (currentCharFile != MARK && currentCharFile != BLANK) {
        if (i < NMax) {
            currentWordFile.TabWord[i] = currentCharFile;
        }
        ADVFILE();
        i++;
    }
    if (i < NMax) {
        currentWordFile.Length = i;
    } else {
        currentWordFile.Length = NMax;
    }
}

void LowerCaseFile() {
    /* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
    /* F.S. currentword menjadi lowercase di setiap karakternya */
    for (int i = 0; i < currentWordFile.Length; i++) {
        if (currentWordFile.TabWord[i] >= 65 && currentWordFile.TabWord[i] <= 90) {
            currentWordFile.TabWord[i] += 32;
        }
    }
}

void copyIntegerFromWordMachine(int *num, WordFile word){
    *num = 0;
    for (int i = 0; i < word.Length; i++) {
        *num = (*num * 10) + (word.TabWord[i] - 48); 
    }
}

