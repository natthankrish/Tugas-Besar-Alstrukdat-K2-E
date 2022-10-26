#include <stdio.h>
#include "../dataStructure/CharMachine/charmachine.c"
#include "../dataStructure/WordMachine/wordmachine.c"
#include "../function/compareString.c"
#include "catalog.c"
#include "loadConfig.c"


void inputCommand (boolean *isStarted, boolean *isExit, Matrix *peta, ListStatik *makanan, TIME *machinetime, SIMULATOR *BNMO) {
    printf("Enter Command: ");
    STARTWORD();

    if (compareString(currentWord.TabWord, currentWord.Length, "START", 5)) {
        if (currentChar == MARK) {
            if (*isStarted) {
                printf("Program sudah berjalan, silahkan lakukan command yang lain, ketik HELP untuk bantuan.\n");
                //inputCommand(isStarted, isExit, peta, makanan);
            } else {
                *isStarted = true;
                printf("LOADING...\n");
                loadConfig(peta, makanan);
                POINT p = getSimulatorLocation(*peta);
                printf("%d %d\n", p.X, p.Y);
                printf("Masukkan nama pengguna: ");
                START();
                char BNMOName[100];
                int idx = 0;
                while (idx < 100 && currentChar != MARK) {
                    BNMOName[idx] = currentChar;
                    ADV();
                    idx++;
                }
                while (idx < 100){
                    BNMOName[idx] = '\0';
                    idx++;
                }
                PrioQueue I;
                CreateSIMULATOR(BNMO, BNMOName, p, I);
                printf("Konfigurasi berhasil dimuat.\n");
                printf("Halo, ");
                for (int i = 0; i < 100; i++) {
                    printf("%c", BNMOName[i]);
                }
                printf(". Selamat Memasak!\n");
            }
        } else {
            while (!endWord) {
                ADVWORD();
            }
            printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
        }
    } else if (compareString(currentWord.TabWord, currentWord.Length, "EXIT", 4) && currentChar == MARK) {
        if (currentChar == MARK) {
            *isExit = true;
            printf("TERIMA KASIH TELAH MENGGUNAKAN BNMO, SAMPAI JUMPA KEMBALI!\n");
        } else {
            while (!endWord) {
                ADVWORD();
            }
            printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
        }
    } else if (compareString(currentWord.TabWord, currentWord.Length, "CATALOG", 7) && currentChar == MARK) {
        if (currentChar == MARK) {
            if (!(*isStarted)) {
                printf("Program belum dimulai. silahkan jalankan command START terlebih dahulu.\n");
            } else {
                printf("-----------------------------------------------\n");
                printf("KATALOG MAKANAN\n");
                PrintCatalog(*makanan);
                printf("-----------------------------------------------\n");
            }
        } else {
            while (!endWord) {
                ADVWORD();
            }
            printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
        }
    } else if (compareString(currentWord.TabWord, currentWord.Length, "HELP", 4) && currentChar == MARK) {
        if (currentChar == MARK) {
            printf("-----------------------------------------------\n");
            printf("PUSAT BANTUAN BNMO\n");
            printf("-----------------------------------------------\n");
        } else {
            while (!endWord) {
                ADVWORD();
            }
            printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
        }
    } else if (compareString(currentWord.TabWord, currentWord.Length, "MOVE", 4)) {
        ADVWORD();
        if (compareString(currentWord.TabWord, currentWord.Length, "NORTH", 5)) {
            if (currentChar == MARK) {
                if (!(*isStarted)) {
                    printf("Program belum dimulai. silahkan jalankan command START terlebih dahulu.\n");
                } else {
                    printf("north");
                }
            } else {
                while (!endWord) {
                    ADVWORD();
                }
                printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
            }
        } else if (compareString(currentWord.TabWord, currentWord.Length, "SOUTH", 5)) {
            if (currentChar == MARK) {
                if (!(*isStarted)) {
                    printf("Program belum dimulai. silahkan jalankan command START terlebih dahulu.\n");
                } else {
                    
                    printf("south");
                }
            } else {
                while (!endWord) {
                    ADVWORD();
                }
                printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
            }
        } else if (compareString(currentWord.TabWord, currentWord.Length, "EAST", 4)) {
            if (currentChar == MARK) {
                if (!(*isStarted)) {
                    printf("Program belum dimulai. silahkan jalankan command START terlebih dahulu.\n");
                } else {
                    printf("east");
                }
            } else {
                while (!endWord) {
                    ADVWORD();
                }
                printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
            }
        } else if (compareString(currentWord.TabWord, currentWord.Length, "WEST", 4)) {
            if (currentChar == MARK) {
                if (!(*isStarted)) {
                    printf("Program belum dimulai. silahkan jalankan command START terlebih dahulu.\n");
                } else {
                    printf("west");
                }
            } else {
                while (!endWord) {
                    ADVWORD();
                }
                printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
            }
        } else {
            printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
        }
    } else {
        while (!endWord) {
            ADVWORD();
        } 
        printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
    }
    
}