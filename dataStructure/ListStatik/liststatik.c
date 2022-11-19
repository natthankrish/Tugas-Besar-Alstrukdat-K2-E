#include <stdio.h>
#include "liststatik.h"
#include "../boolean.h"
#include "../Makanan/makanan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    Lengthlist(*l)=0;
}

//Mengambil elemen pertama
MAKANAN getFirstElmt(ListStatik l){
    return ELMTlist(l,0);
}

//Mengambil elemen terakhir
MAKANAN getLastElmt(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return ELMTlist(l,Lengthlist(l)-1);
    
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, int i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i>=IDX_MIN && i<CAPACITY);
}

boolean isIdxListEff(ListStatik l, int i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..Lengthlist(l)-1 */
    return (i>=0 && i<Lengthlist(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return (Lengthlist(l)==0);
}
/* *** Test List penuh *** */
boolean isListFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return (Lengthlist(l)==CAPACITY);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    if(Lengthlist(l1)==Lengthlist(l2)){
        for(int i=0;i<Lengthlist(l1);i++){
            if(ID(ELMTlist(l1,i))!=ID(ELMTlist(l2,i))){
                return false;
            }
        }
        return true;
    }
    return false;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfID(ListStatik l, int val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMTlist(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i=0;
    while(i<Lengthlist(l)){
       if(ID(ELMTlist(l,i))==val){
        break;
       }
       i++; 
    }
    if(Lengthlist(l)==0 || i==Lengthlist(l)){
        return IDX_UNDEF;
    }else{
        return i;
    }
}

boolean isNameEQ(char name1[101],char name2[101]){
    int i=0;
    int len1=0;
    while(name1[i]!='\0'){
        len1++;
        i++;
    }
    i=0;
    int len2=0;
    while(name2[i]!='\0'){
        len2++;
        i++;
    }
    if(len1==len2){
        i=0;
        while(i<len1){
            if(name1[i]!=name2[i]){
                return false;
            }
            i++;
        }
        return true;
    }
    return false;
}

int indexOfFood(ListStatik l, char val[101]){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMTlist(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i=0;
    while(i<Lengthlist(l)){
       if(isNameEQ(Name(ELMTlist(l,i)),val)){
        break;
       }
       i++; 
    }
    if(Lengthlist(l)==0 || i==Lengthlist(l)){
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
        while(i<Lengthlist(l)){
            if(i==0){
                *min=ELMTlist(l,i);
                *max=ELMTlist(l,i);
            }else{
                if(Expiry(ELMTlist(l,i))<=Expiry(*min)){
                    *min=ELMTlist(l,i);
                }
                if(Expiry(ELMTlist(l,i))>=Expiry(*max)){
                    *max=ELMTlist(l,i);
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
        while(i<Lengthlist(l)){
            if(i==0){
                *min=ELMTlist(l,i);
                *max=ELMTlist(l,i);
            }else{
                if(DeliveryTime(ELMTlist(l,i))<=DeliveryTime(*min)){
                    *min=ELMTlist(l,i);
                }
                if(DeliveryTime(ELMTlist(l,i))>=DeliveryTime(*max)){
                    *max=ELMTlist(l,i);
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
    if(Lengthlist(*l)<CAPACITY){
        int i = Lengthlist(*l);
        if(i!=0){
            while(i>0){
                ELMTlist(*l,i)=ELMTlist(*l,i-1);
                i--;
            }
        }
        ELMTlist(*l,0)=val;
        Lengthlist(*l)++;
        return;
    }
    
}

/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, MAKANAN val, int idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
    if(Lengthlist(*l)!=0 && Lengthlist(*l)<CAPACITY && isIdxValid(*l, idx)){
        int i = Lengthlist(*l);
        while(i>idx){
            ELMTlist(*l,i)=ELMTlist(*l,i-1);
            i--;
        }
        ELMTlist(*l, idx)=val;
        Lengthlist(*l)++;
    }
}

void insertLast(ListStatik *l, MAKANAN val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    //KALAU MISALNYA JUMLAH ELEMEN PAS KAPASITAS DAN DITAMBAH VAL MALAH KELEBIHAN GIMANA?
    if(Lengthlist(*l)<CAPACITY){
        int i = Lengthlist(*l);
        ELMTlist(*l,i)=val;
        Lengthlist(*l)++;
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
        *val = ELMTlist(*l,i);
        while(i<Lengthlist(*l)){
            ELMTlist(*l,i)=ELMTlist(*l,i+1);
            i++;
        }
        Lengthlist(*l)--;
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
        *val = ELMTlist(*l, idx);
        while(i<Lengthlist(*l)-1){
            // printf("test\n");
            MAKANAN temp = ELMTlist(*l,i+1);
            ELMTlist(*l,i)=temp;
            i++;
        }
        Lengthlist(*l)--;
    }
    
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, MAKANAN *val){
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    if(!isEmpty(*l)){
        int i = Lengthlist(*l)-1;
        *val = ELMTlist(*l, i);
        Lengthlist(*l)--;
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
        while(i<Lengthlist(*l)-1){
            j=i+1;
            min = ELMTlist(*l,i);
            int minidx=i;
            while(j<Lengthlist(*l)){
                if(Expiry(ELMTlist(*l,j))<=Expiry(min)){
                    min=ELMTlist(*l, j);
                    minidx=j;
                }
                j++;
            }
            MAKANAN val1;
            deleteAt(l, &val1, minidx);
            insertAt(l, min, i); //min
            i++;
        }
    }else{
        int i,j;
        MAKANAN max;
        i=0;
        while(i<Lengthlist(*l)-1){
            j=i+1;
            max = ELMTlist(*l,i);
            int maxidx=i;
            while(j<Lengthlist(*l)){
                if(Expiry(ELMTlist(*l,j))>=Expiry(max)){
                    max=ELMTlist(*l, j);
                    maxidx=j;
                }
                j++;
            }
            MAKANAN val1;      
            insertAt(l, max, i);
            deleteAt(l, &val1, maxidx+1);
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
        while(i<Lengthlist(*l)-1){
            j=i+1;
            min = ELMTlist(*l,i);
            int minidx=i;
            while(j<Lengthlist(*l)){
                if(DeliveryTime(ELMTlist(*l,j))<=DeliveryTime(min)){
                    min=ELMTlist(*l, j);
                    minidx=j;
                }
                j++;
            }
            MAKANAN val1;
            deleteAt(l, &val1, minidx);
            insertAt(l, min, i); //min
            i++;
        }
    }else{
        int i,j;
        MAKANAN max;
        i=0;
        while(i<Lengthlist(*l)-1){
            j=i+1;
            max = ELMTlist(*l,i);
            int maxidx=i;
            while(j<Lengthlist(*l)){
                if(DeliveryTime(ELMTlist(*l,j))>=DeliveryTime(max)){
                    max=ELMTlist(*l, j);
                    maxidx=j;
                }
                j++;
            }
            MAKANAN val1;     
            insertAt(l, max, i);
            deleteAt(l, &val1, maxidx+1);
            i++;
        }
    }
}