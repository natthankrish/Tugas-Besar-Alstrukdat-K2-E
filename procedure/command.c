#include <stdio.h>
#include "../dataStructure/CharMachine/charmachine.c"
#include "../dataStructure/WordMachine/wordmachine.c"
#include "../dataStructure/Matrix/matrix.h"
#include "../function/compareString.c"
#include "moveNorth.c"
#include "moveSouth.c"
#include "moveEast.c"
#include "moveWest.c"
#include "catalog.c"
#include "cookBook.c"
#include "loadConfig.c"


void inputCommand (boolean *isStarted, boolean *isExit, Matrix *peta, ListStatik *makanan, TIME *machinetime, SIMULATOR *BNMO, ListTree *resep) {
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
                loadConfig(peta, makanan, resep);
                POINT p = getSimulatorLocation(*peta);
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
    } else if (compareString(currentWord.TabWord, currentWord.Length, "COOKBOOK", 8) && currentChar == MARK) {
        if (currentChar == MARK) {
            if (!(*isStarted)) {
                printf("Program belum dimulai. silahkan jalankan command START terlebih dahulu.\n");
            } else {
                printf("-----------------------------------------------\n");
                printf("DAFTAR RESEP\n");
                printCookBook(*resep);
                printf("-----------------------------------------------\n");
            }
        } else {
            while (!endWord) {
                ADVWORD();
            }
            printf("Command Salah! Masukkan command yang benar. Ketik HELP untuk bantuan.\n");
        }
    }else if (compareString(currentWord.TabWord, currentWord.Length, "HELP", 4) && currentChar == MARK) {
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
                    int movestatus = getNorth(*peta, Lokasi(*BNMO));
                    if (movestatus == 0) {
                        moveNorth(BNMO, peta);
                    } else {
                        printf("Tidak bisa bergerak ke utara. ");
                        if (movestatus == 1) {
                            printf("Ada kios telepon.\n");
                        } else if (movestatus == 2) {
                            printf("Ada kios pemotongan makanan.\n");
                        } else if (movestatus == 3) {
                            printf("Ada kios penggorengan makanan.\n");
                        } else if (movestatus == 4) {
                            printf("Ada kios perebusan makanan.\n");
                        } else if (movestatus == 5) {
                            printf("Ada kios pencampuran makanan.\n");
                        } else if (movestatus == 6) {
                            printf("Ada tembok.\n");
                        } else {
                            printf("Ada batas peta.\n");
                        }
                    }
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
                    int movestatus = getSouth(*peta, Lokasi(*BNMO));
                    if (movestatus == 0) {
                        moveSouth(BNMO, peta);
                    } else {
                        printf("Tidak bisa bergerak ke selatan. ");
                        if (movestatus == 1) {
                            printf("Ada kios telepon.\n");
                        } else if (movestatus == 2) {
                            printf("Ada kios pemotongan makanan.\n");
                        } else if (movestatus == 3) {
                            printf("Ada kios penggorengan makanan.\n");
                        } else if (movestatus == 4) {
                            printf("Ada kios perebusan makanan.\n");
                        } else if (movestatus == 5) {
                            printf("Ada kios pencampuran makanan.\n");
                        } else if (movestatus == 6) {
                            printf("Ada tembok.\n");
                        } else {
                            printf("Ada batas peta.\n");
                        }
                    }
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
                    int movestatus = getEast(*peta, Lokasi(*BNMO));
                    if (movestatus == 0) {
                        moveEast(BNMO, peta);
                    } else {
                        printf("Tidak bisa bergerak ke timur. ");
                        if (movestatus == 1) {
                            printf("Ada kios telepon.\n");
                        } else if (movestatus == 2) {
                            printf("Ada kios pemotongan makanan.\n");
                        } else if (movestatus == 3) {
                            printf("Ada kios penggorengan makanan.\n");
                        } else if (movestatus == 4) {
                            printf("Ada kios perebusan makanan.\n");
                        } else if (movestatus == 5) {
                            printf("Ada kios pencampuran makanan.\n");
                        }  else if (movestatus == 6) {
                            printf("Ada tembok.\n");
                        } else {
                            printf("Ada batas peta.\n");
                        }
                    }
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
                    int movestatus = getWest(*peta, Lokasi(*BNMO));
                    if (movestatus == 0) {
                        moveWest(BNMO, peta);
                    } else {
                        printf("Tidak bisa bergerak ke barat. ");
                        if (movestatus == 1) {
                            printf("Ada kios telepon.\n");
                        } else if (movestatus == 2) {
                            printf("Ada kios pemotongan makanan.\n");
                        } else if (movestatus == 3) {
                            printf("Ada kios penggorengan makanan.\n");
                        } else if (movestatus == 4) {
                            printf("Ada kios perebusan makanan.\n");
                        } else if (movestatus == 5) {
                            printf("Ada kios pencampuran makanan.\n");
                        }  else if (movestatus == 6) {
                            printf("Ada tembok.\n");
                        } else {
                            printf("Ada batas peta.\n");
                        }
                    }
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