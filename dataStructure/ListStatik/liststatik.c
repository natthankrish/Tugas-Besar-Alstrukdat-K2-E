#include <stdio.h>
#include "liststatik.h"
#include "../boolean.h"
#include "../Makanan/makanan.c"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    Length(*l)=0;
    return;
}

//Mengambil elemen pertama
MAKANAN getFirstElmt(ListStatik l){
    return ELMT(l,0);
}

//Mengambil elemen terakhir
MAKANAN getLastElmt(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return ELMT(l,Length(l)-1);
    
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=IDX_MIN && i<CAPACITY);
}

boolean isIdxEff(ListStatik l, int i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    return (i>=0 && i<Length(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (Length(l)==0);
}
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (Length(l)==CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
    int i,n;
    scanf("%d", &n);
    while(n<0 || n>CAPACITY){
        scanf("%d", &n);
    }
    CreateListStatik(l);
    if(n!=0){
        i=0;
        MAKANAN temp;
        while(i<n){
            Length(*l)++;
            scanf("%d",&temp);
            ELMT(*l,i)=temp;
            i++;
        }
    }
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    return (Length(l1)==Length(l2));
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfID(ListStatik l, int val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i=0;
    while(i<Length(l)){
       if(ELMT(l,i).idx==val){
        break;
       }
       i++; 
    }
    if(Length(l)==0 || i==Length(l)){
        return IDX_UNDEF;
    }else{
        return i;
    }
}

int indexOfFood(ListStatik l, char val[101]){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i=0;
    while(i<Length(l)){
       if(Name(ELMT(l,i))==val){
        break;
       }
       i++; 
    }
    if(Length(l)==0 || i==Length(l)){
        return IDX_UNDEF;
    }else{
        return i;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValuesExpiry(ListStatik l, MAKANAN *max, MAKANAN *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    if(!isEmpty(l)){
        int i = 0;
        while(i<Length(l)){
            if(i==0){
                *min=ELMT(l,i);
                *max=ELMT(l,i);
            }else{
                if(Expiry(ELMT(l,i))<=Expiry(*min)){
                    *min=ELMT(l,i);
                }
                if(Expiry(ELMT(l,i))>=Expiry(*max)){
                    *max=ELMT(l,i);
                }
            }
            i++;
        }
    }
}

void extremeValuesDelivery(ListStatik l, MAKANAN *max, MAKANAN *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    if(!isEmpty(l)){
        int i = 0;
        while(i<Length(l)){
            if(i==0){
                *min=ELMT(l,i);
                *max=ELMT(l,i);
            }else{
                if(DeliveryTime(ELMT(l,i))<=DeliveryTime(*min)){
                    *min=ELMT(l,i);
                }
                if(DeliveryTime(ELMT(l,i))>=DeliveryTime(*max)){
                    *max=ELMT(l,i);
                }
            }
            i++;
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, MAKANAN val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
    if(Length(*l)<CAPACITY){
        int i = Length(*l);
        if(i!=0){
            while(i>0){
                ELMT(*l,i)=ELMT(*l,i-1);
                i--;
            }
        }
        ELMT(*l,0)=val;
        Length(*l)++;
        return;
    }
    
}

/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, MAKANAN val, int idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
    if(Length(*l)!=0 && Length(*l)<CAPACITY && isIdxValid(*l, idx)){
        int i = Length(*l);
        while(i>idx){
            ELMT(*l,i)=ELMT(*l,i-1);
            i--;
        }
        ELMT(*l, idx)=val;
        Length(*l)++;
    }
}

void insertLast(ListStatik *l, MAKANAN val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    //KALAU MISALNYA JUMLAH ELEMEN PAS KAPASITAS DAN DITAMBAH VAL MALAH KELEBIHAN GIMANA?
    if(Length(*l)<CAPACITY){
        int i = Length(*l);
        ELMT(*l,i)=val;
        Length(*l)++;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, MAKANAN *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    if(!isEmpty(*l)){
        int i = 0;
        *val = ELMT(*l,i);
        while(i<Length(*l)){
            ELMT(*l,i)=ELMT(*l,i+1);
            i++;
        }
        Length(*l)--;
    }
    
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, MAKANAN *val, int idx){
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    if(!isEmpty(*l)){
        int i = idx;
        *val = ELMT(*l, idx);
        while(i<Length(*l)-1){
            // printf("test\n");
            MAKANAN temp = ELMT(*l,i+1);
            ELMT(*l,i)=temp;
            i++;
        }
        Length(*l)--;
    }
    
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, MAKANAN *val){
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    if(!isEmpty(*l)){
        int i = Length(*l)-1;
        *val = ELMT(*l, i);
        Length(*l)--;
    }
}

/* ********** SORTING ********** */
//Sort by Expiry
void sortListExpiry(ListStatik *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    if(asc){
        int i,j;
        MAKANAN min;
        i=0;
        while(i<Length(*l)-1){
            j=i+1;
            min = ELMT(*l,i);
            int minidx=i;
            while(j<listLength(*l)){
                if(Expiry(ELMT(*l,j))<=Expiry(min)){
                    min=ELMT(*l, j);
                    minidx=j;
                }
                j++;
            }
            int val1;
            int *val1p = &val1;
            deleteAt(l, val1p, minidx);
            insertAt(l, min, i); //min
            i++;
        }
    }else{
        int i,j;
        MAKANAN max;
        i=0;
        while(i<Length(*l)-1){
            j=i+1;
            max = ELMT(*l,i);
            int maxidx=i;
            while(j<Length(*l)){
                if(Expiry(ELMT(*l,j))>=Expiry(max)){
                    max=ELMT(*l, j);
                    maxidx=j;
                }
                j++;
            }
            int val1;
            int *val1p = &val1;       
            insertAt(l, max, i);
            deleteAt(l, val1p, maxidx+1);
            i++;
        }
    }
}

//Sort by Delivery Time
void sortListDelivery(ListStatik *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
    if(asc){
        int i,j;
        MAKANAN min;
        i=0;
        while(i<Length(*l)-1){
            j=i+1;
            min = ELMT(*l,i);
            int minidx=i;
            while(j<listLength(*l)){
                if(DeliveryTime(ELMT(*l,j))<=DeliveryTime(min)){
                    min=ELMT(*l, j);
                    minidx=j;
                }
                j++;
            }
            int val1;
            int *val1p = &val1;
            deleteAt(l, val1p, minidx);
            insertAt(l, min, i); //min
            i++;
        }
    }else{
        int i,j;
        MAKANAN max;
        i=0;
        while(i<Length(*l)-1){
            j=i+1;
            max = ELMT(*l,i);
            int maxidx=i;
            while(j<Length(*l)){
                if(DeliveryTime(ELMT(*l,j))>=DeliveryTime(max)){
                    max=ELMT(*l, j);
                    maxidx=j;
                }
                j++;
            }
            int val1;
            int *val1p = &val1;       
            insertAt(l, max, i);
            deleteAt(l, val1p, maxidx+1);
            i++;
        }
    }
}