// Pengguna dapat meminta BNMO untuk menyimpan makanan di kulkas. 
// Makanan yang ditaruh di kulkas akan dihilangkan dari PrioQueue/Inventory. 
// Expired Time Makanan selama di Kulkas tidak berkurang. 
// Peletakkan makanan pada kulkas harus diletakkan dalam sebuah matriks, lihat gambar referensi. 
// Untuk ukuran setiap makanan didefinisikan pada ADT Makanan dengan representasi dua buah integer (NxM). 
// Silakan mengubah file konfigurasi juga untuk perihal ukuran makanan. Makanan tidak bisa ditumpuk (gambar referensi ditumpuk ada tulisan angka amount, kalau kulkas BNMO tidak bisa). 
// Makanan yang dimasukkan posisinya tidak boleh saling beririsan pada sel yang sama. Ukuran kulkas minimal 10x20 (10 vertikal, 20 horizontal). 
// Untuk cara memasukkan dibebaskan kepada kelompok masing-masing, pastikan dijelaskan saat demo.
#include "../dataStructure/Inventory/inventory.h"
#include "../dataStructure/Kulkas/kulkas.h"

void fridge(Inventory I, KULKAS *Kulkas){
    printf("===============================================\n");
    printf("                      FRIDGE\n");
    printf("===============================================\n");
    printf("SELECT OPTION : \n");
    printf("1. Lihat Fridge\n");
    printf("2. Masukkan makanan ke Fridge\n");
    printf("3. Keluarkan makanan dari Fridge\n\n");
    printf("Kirim 0 untuk keluar\n\n");
    printf("Enter Command: ");
    STARTWORD();
    printf("\n");
    boolean keluar = false;
    while (!compareString(currentWord.TabWord, currentWord.Length, "0", 1) && !keluar) {
        if(compareString(currentWord.TabWord, currentWord.Length, "1", 1)){
            printf("Ini adalah Lihat Fridge\n");
            displayFridge(*Kulkas);
            keluar = true;
        }else if(compareString(currentWord.TabWord, currentWord.Length, "2", 1)){
            if(InventoryKosong(I)){
                printf("Inventory kosong!\n");
                keluar = true;
            }else{
                PrintInventory((I));
                printf("Enter Command: ");
                STARTWORD();
                printf("\n");
                for(int i = 0; i < NBElmt(I);i++){
                    int order = i + 1;
                    char orderString[2];
                    sprintf(orderString, "%d", order);
                    if (compareString(currentWord.TabWord, currentWord.Length,  orderString, countIntegerLength(order)) && currentChar == MARK){
                        printf("keyboard:%c listinv:%d\n",currentWord.TabWord, i);
                        if(MakananDalamInventory(I, Elmt(I,i))){
                            inToFridge(Kulkas, &Elmt(I,i));
                            // for(int j = 0; j < 101; j++){
                            //     printf("%c",Elmt(I,i).name[j]);
                            // }
                            AmbilMakanan(&I, Elmt(I,i));
                            displayFridge(*Kulkas);
                            // PrintInventory((I));
                            
                            // delElmtInventory(I, i);
                        }
                    }
                }
                keluar = true;
            }
        }else if(compareString(currentWord.TabWord, currentWord.Length, "3", 1)){
            if(isFridgeEmpty(*Kulkas)){
                // printf("Inventory kosong!\n");
                keluar = true;
            }else{
                displayFoodList(*Kulkas);
                printf("Enter Command: ");
                STARTWORD();
                printf("\n");
                for(int i = 0; i < FridgeListLength(*Kulkas);i++){
                    int order = i + 1;
                    char orderString[2];
                    sprintf(orderString, "%d", order);
                    if (compareString(currentWord.TabWord, currentWord.Length,  orderString, countIntegerLength(order)) && currentChar == MARK){
                        printf("keyboard:%c listinv:%d\n",currentWord.TabWord, i);
                        printf("%s", Name(FoodListELMT(*Kulkas,i)));
                        // outFromFridge(Kulkas, &Elmt(Kulkas->foodList,i));
                    }
                }
                keluar = true;
            }
        }else{
            while (!endWord) {
                ADVWORD();
            }
            printf("Command Salah! silakan masukkan nomor urut makanan yang ingin anda buat. Ketik HELP untuk bantuan.\n");
            printf("\nEnter Command: ");
            STARTWORD();
        }
    }
    // scanf
}
