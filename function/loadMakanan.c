#include <stdio.h>

ListStatik loadMakanan () {
    ListStatik listMakanan;
    CreateListStatik(&listMakanan);

    STARTWORDFILE("config/makanan.txt");

    int countmakanan;
    copyIntegerFromWordMachine(&countmakanan, currentWordFile);
    ADVWORDFILE();
    
    for (int count = 0; count < countmakanan; count++) {
        int ID;
        copyIntegerFromWordMachine(&ID, currentWordFile);

        ADVFILE();
        
        char Name[101];
        int idx = 0;
        char temp;

        while (currentCharFile != MARK) {
            if (idx < 101) {
                Name[idx] = currentCharFile;
                idx++;
            } 
            ADVFILE();
        }

        ADVWORDFILE();

        TIME Expiry;
        int HH, MM, SS;
        copyIntegerFromWordMachine(&HH, currentWordFile);
        ADVWORDFILE();
        copyIntegerFromWordMachine(&MM, currentWordFile);
        ADVWORDFILE();
        copyIntegerFromWordMachine(&SS, currentWordFile);

        CreateTime(&Expiry, HH, MM, SS);
        ADVWORDFILE();

        TIME Delivery;
        copyIntegerFromWordMachine(&HH, currentWordFile);
        ADVWORDFILE();
        copyIntegerFromWordMachine(&MM, currentWordFile);
        ADVWORDFILE();
        copyIntegerFromWordMachine(&SS, currentWordFile);

        CreateTime(&Delivery, HH, MM, SS);
        ADVWORDFILE();

        int actionnum;

        if (compareString(currentWordFile.TabWord, currentWordFile.Length, "Buy", 3)) {
            actionnum = 1;
        } else if (compareString(currentWordFile.TabWord, currentWordFile.Length, "Chop", 4)) {
            actionnum = 2;
        } else if (compareString(currentWordFile.TabWord, currentWordFile.Length, "Fry", 3)) {
            actionnum = 3;
        } else if (compareString(currentWordFile.TabWord, currentWordFile.Length, "Boil", 4)) {
            actionnum = 4;
        } else if (compareString(currentWordFile.TabWord, currentWordFile.Length, "Mix", 3)) {
            actionnum = 5;
        } 

        ADVWORDFILE();

        int height, width;
        DIMENSION size;
        copyIntegerFromWordMachine(&height, currentWordFile);
        ADVWORDFILE();
        copyIntegerFromWordMachine(&width, currentWordFile);
        ADVWORDFILE();

        CreateDimension(&size, height, width);

        MAKANAN makanan;
        CreateFood(&makanan, ID, Name, Expiry, actionnum, Delivery, size);

        insertLast(&listMakanan, makanan);

        for (int i = 0; i < 101; i++) {
            Name[i] = '\0';
        }
    }

    return listMakanan;
}