#include <stdio.h>
#include "kulkas.h"
#include "../Matrix/matrix.c"
#include "../ListStatik/liststatik.c"

#define Contents(K) (K).contents  /*Isi kulkas dalam Matrix*/
#define FoodList(K) (K).foodList /*Isi kulkas dalam list*/
#define FridgeListLength(K) Lengthlist((K).foodList)
#define FoodListELMT(K,N) (K).foodList.contents[N]  /*Elemen makanan dalam list kulkas*/
#define FridgeHeight(K) (K).capacity.height /*Tinggi kulkas*/
#define FridgeWidth(K) (K).capacity.width /*Lebar kulkas*/
#define FridgeELMT(K,i,j) ELMT((K).contents,i,j) /*Cell pada isi matrix kulkas*/

/*Konstruktor kulkas*/
void CreateFridge(KULKAS *K, DIMENSION D){
    (*K).capacity=D;
    createMatrix(D.height,D.width,&Contents(*K));
    for(int i=0;i<FridgeHeight(*K);i++){
        for(int j=0;j<FridgeWidth(*K);j++){
            FridgeELMT(*K,i,j)=0;
        }
    }
    CreateListStatik(&FoodList(*K));
}

/* Mengirimkan true jika kulkas K penuh */
boolean isFridgeFull(KULKAS K){
    boolean space = false;
    int i=0;
    while(i<FridgeHeight(K) && !space){
        int j=0;
        while(j<FridgeWidth(K) && !space){
            if(FridgeELMT(K,i,j)==0){
                space=true;
            }
        }
    }
    return !space;
}

/* Mengirimkan true jika kulkas K kosong */
boolean isFridgeEmpty(KULKAS K){
    boolean zero = true;
    int i=0;
    while(i<FridgeHeight(K) && zero){
        int j=0;
        while(j<FridgeWidth(K) && zero){
            if(FridgeELMT(K,i,j)!=0){
                zero=false;
            }
        }
    }
    return zero;
}

/* Mengirimkan jumlah cell kosong pada kulkas K (bisa tersebar) */
int SpaceLeft(KULKAS K){
    int zero = 0;
    int i=0;
    while(i<FridgeHeight(K)){
        int j=0;
        while(j<FridgeWidth(K)){
            if(FridgeELMT(K,i,j)==0){
                zero++;
            }
            j++;
        }
        i++;
    }
    //printf("Space left: %d\n", zero);
    return zero;
}

/* Mengirimkan true jika jumlah cell kosong cukup untuk memasukkan Makanan M ke dalam Kulkas K (hanya berdasarkan jumlah cell) */
boolean isFitFirstGlance(KULKAS K, MAKANAN M){
    return (SpaceLeft(K)>=Height(M)*Width(M));
}


/* Mengirimkan true jika Makanan M dapat muat ke dalam Kulkas K */
boolean isFitFinal(KULKAS K, MAKANAN M){
    printf("---Detail Kulkas---\nTinggi Kulkas: %d\nLebar Kulkas: %d\n",ROW_EFF(Contents(K)),COL_EFF(Contents(K)));
    if(isFitFirstGlance(K,M)){
        Matrix food;
        createMatrix(Height(M),Width(M),&food);
        printf("---Detail Makanan---\nTinggi Makanan: %d\nLebar Makanan: %d\n", ROW_EFF(food),COL_EFF(food));
        int possibleSpace=0;
        for(int i=0;i<FridgeHeight(K);i++){
            for(int j=0;j<FridgeWidth(K);j++){
                boolean valid=true;
                int k=0;
                while(k<ROW_EFF(food) && valid){
                    int l=0;
                    while(l<COL_EFF(food) && valid){
                        if(!isIdxEff(Contents(K),i+k,j+l) || FridgeELMT(K,i,j)!=0){
                            valid=false;
                        }
                        l++;
                    }
                    k++;

                }

                if(valid){
                    //printf("Posisi (%d,%d) valid\n",i,j);
                    possibleSpace++;
                }else{
                    //printf("Posisi (%d,%d) tidak valid\n",i,j);
                }
            }
        }
        /*Jika posisi awal makanan tidak memungkinkan muat, maka dicoba jika diputar*/
        if(possibleSpace==0){
            Matrix rotatedFood;
            createMatrix(COL_EFF(food),ROW_EFF(food),&rotatedFood);
            for(int i=0;i<FridgeHeight(K);i++){
                for(int j=0;j<FridgeWidth(K);j++){
                    boolean valid=true;
                    int k=0;
                    while(k<ROW_EFF(rotatedFood) && valid){
                        int l=0;
                        while(l<COL_EFF(rotatedFood) && valid){
                            if(!isIdxEff(Contents(K),i+k,j+l) || FridgeELMT(K,i,j)!=0){
                                valid=false;
                            }
                            l++;
                        }
                        k++;
                    }
                    if(valid){
                        //printf("Posisi (%d,%d) valid\n",i,j);
                        possibleSpace++;
                    }else{
                        //printf("Posisi (%d,%d) tidak valid\n",i,j);
                    }
                }
            }
        }

        printf("Possible Spaces: %d\n",possibleSpace);

        return (possibleSpace>0);
    }
    return false;
}

/* Menampilkan list makanan yang ada di dalam Kulkas K */
void displayFoodList(KULKAS K){
    printf("List Makanan di Kulkas\n(nama - waktu sisa kadaluwarsa)\n");
    if(FridgeListLength(K)!=0){
        for(int i=0;i<FridgeListLength(K);i++){
            printf("%d. %s - %d jam\n",i+1,Name(FoodListELMT(K,i)),FoodList(K).contents[i].expiry.HH);
        }
    }
    else{
        printf("-----Tidak ada makanan dalam kulkas-----\n");
    }
    
}

/* Menampilkan isi Kulkas K beserta list makanan yang ada di dalamnya*/
void displayFridge(KULKAS K){
    for(int i=0;i<FridgeWidth(K)+1;i++){
        printf("*");
    }
    printf("*\n");
    for(int i=0;i<FridgeHeight(K);i++){
        printf("*");
        for(int j=0;j<FridgeWidth(K);j++){
            printf("%d",FridgeELMT(K,i,j));
        }
        printf("*\n");
    }
    for(int i=0;i<FridgeWidth(K)+1;i++){
        printf("*");
    }
    printf("*\n");
    //displayMatrix(Contents(K));
    displayFoodList(K);
}

/* Memasukkan Makanan M ke dalam Kulkas K*/
void inToFridge(KULKAS *K, MAKANAN *M){
    if(isFitFinal(*K,*M)){
        Matrix food;
        Matrix rotatedFood;
        createMatrix(Height(*M),Width(*M),&food);
        
        /*Mencari lokasi yang pas*/
        boolean foundPos = false;
        boolean rotated = false;
        int xPos,yPos;
        for(int i=0;i<FridgeHeight(*K);i++){
            for(int j=0;j<FridgeWidth(*K);j++){
                boolean valid=true;
                int k=0;
                while(k<ROW_EFF(food) && valid){
                    int l=0;
                    while(l<COL_EFF(food) && valid){
                        if(!isIdxEff(Contents(*K),i+k,j+l) || FridgeELMT(*K,i,j)!=0){
                            valid=false;
                        }
                        l++;
                    }
                    k++;

                }
                if(valid){
                    foundPos=true;
                    xPos=i;
                    yPos=j;
                    break;
                }
            }
            if(foundPos){
                break;
            }
        }
        /*Jika tidak menemukan tempat yang pas, dirotasi lalu dicoba kembali*/
        if(!foundPos){
            rotated = true;
            createMatrix(COL_EFF(food),ROW_EFF(food),&rotatedFood);
            for(int i=0;i<FridgeHeight(*K);i++){
                for(int j=0;j<FridgeWidth(*K);j++){
                    boolean valid=true;
                    int k=0;
                    while(k<ROW_EFF(rotatedFood) && valid){
                        int l=0;
                        while(l<COL_EFF(rotatedFood) && valid){
                            if(!isIdxEff(Contents(*K),i+k,j+l) || FridgeELMT(*K,i,j)!=0){
                                valid=false;
                            }
                            l++;
                        }
                        k++;
                    }
                    if(valid){
                        foundPos=true;
                        xPos=i;
                        yPos=j;
                        break;
                    }
                }
                if(foundPos){
                    break;
                }
            }
        }
        
        /*Memasukkan nilai makanan ke dalam matrix kulkas*/
        if(!rotated){
            for(int i=0;i<ROW_EFF(food);i++){
                for(int j=0;j<COL_EFF(food);j++){
                    FridgeELMT(*K,xPos+i,yPos+j)=FridgeListLength(*K)+1;
                }
            }
        }else{
            for(int i=0;i<ROW_EFF(rotatedFood);i++){
                for(int j=0;j<COL_EFF(rotatedFood);j++){
                    FridgeELMT(*K,xPos+i,yPos+j)=FridgeListLength(*K)+1;
                }
            }
        }

        /*Memasukkan makanan ke dalam list kulkas*/
        insertLast(&FoodList(*K),*M);
        

    }
    else{
        printf("MAKANAN TIDAK MUAT!\n");
    }
    
}

/* Mengelurakan makanan urutan ke FoodNum pada Kulkas K dan memasukkan nilainya ke Makanan M*/
void outFromFridge(KULKAS *K, int FoodNum,MAKANAN *M){
    /*Dikeluarkan dari list kulkas*/
    deleteAt(&FoodList(*K),M,FoodNum-1);
    Matrix food;
    Matrix rotatedFood;
    createMatrix(Height(*M),Width(*M),&food);
    
    /*Mencari lokasi dimasukannya makanan*/
    boolean foundPos = false;
    boolean rotated = false;
    int xPos,yPos;
    for(int i=0;i<FridgeHeight(*K);i++){
        for(int j=0;j<FridgeWidth(*K);j++){
            boolean valid = false;
            if(FridgeELMT(*K,i,j)==FoodNum){
                valid=true;
                int k=0;
                while(k<ROW_EFF(food) && valid){
                    int l=0;
                    while(l<COL_EFF(food) && valid){
                        if(!isIdxEff(Contents(*K),i+k,j+l) || FridgeELMT(*K,i,j)!=FoodNum){
                            valid=false;
                        }
                        l++;
                    }
                    k++;
                }
            }
            if(valid){
                foundPos=true;
                xPos=i;
                yPos=j;
                break;
            }
        }
        if(foundPos){
            break;
        }
    }

    /*Jika tidak menemukan tempat yang pas, dirotasi lalu dicoba kembali*/
    if(!foundPos){
        rotated = true;
        createMatrix(COL_EFF(food),ROW_EFF(food),&rotatedFood);
        for(int i=0;i<FridgeHeight(*K);i++){
            for(int j=0;j<FridgeWidth(*K);j++){
                boolean valid = false;
                if(FridgeELMT(*K,i,j)==FoodNum){
                    valid=true;
                    int k=0;
                    while(k<ROW_EFF(rotatedFood) && valid){
                        int l=0;
                        while(l<COL_EFF(rotatedFood) && valid){
                            if(!isIdxEff(Contents(*K),i+k,j+l) || FridgeELMT(*K,i,j)!=FoodNum){
                                valid=false;
                            }
                            l++;
                        }
                        k++;
                    }
                }
                if(valid){
                    foundPos=true;
                    xPos=i;
                    yPos=j;
                    break;
                }
            }
            if(foundPos){
                break;
            }
        }
    }

    /*Mengubah kembali matrix kulkas menjadi 0 (kosong) pada bagian makanan yang dikeluarkan*/
    if(!rotated){
        for(int i=0;i<ROW_EFF(food);i++){
            for(int j=0;j<COL_EFF(food);j++){
                FridgeELMT(*K,xPos+i,yPos+j)=0;
            }
        }
    }else{
        for(int i=0;i<ROW_EFF(rotatedFood);i++){
            for(int j=0;j<COL_EFF(rotatedFood);j++){
                FridgeELMT(*K,xPos+i,yPos+j)=0;
            }
        }
    }

    /*Mengurangi semua nilai makanan pada matrix dengan 1*/
    for(int i=0;i<FridgeHeight(*K);i++){
        for(int j=0;j<FridgeWidth(*K);j++){
            if(FridgeELMT(*K,i,j)!=0){
                FridgeELMT(*K,i,j)--;
            }
        }
    }


}