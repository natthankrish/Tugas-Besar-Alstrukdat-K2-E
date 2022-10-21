/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATAFILE_H__
#define __MESINKATAFILE_H__

#include "../boolean.h"
#include "../CharMachine/charmachinefile.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} WordFile;

/* State Mesin Word */
extern boolean endWordFile;
extern WordFile currentWordFile;

void IgnoreBlanksFile();
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORDFILE(char path[]);
    /* I.S. : currentChar sembarang
    F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDFILE();
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordFile();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif