#include <stdio.h>
#include "set.h"
#include "../ListStatik/liststatik.c"

void CreateEmptySet(Set *S){
    for(int i=0;i<AllFoods;i++){
        IDset(*S,i)=0;
    }
}

void CreateSetFromList(Set *S, ListStatik l){
    CreateEmptySet(S);
    for(int i=0;i<Lengthlist(l);i++){
        if(ID(ELMTlist(l,i))==10){ /*Tepung*/
            IDset(*S,0)=1;
        }
        if(ID(ELMTlist(l,i))==11){ /*Ayam mentah*/
            IDset(*S,1)=1;
        }
        if(ID(ELMTlist(l,i))==15){ /*Minyak goreng*/
            IDset(*S,2)=1;
        }
        if(ID(ELMTlist(l,i))==21){ /*Ayam potong*/
            IDset(*S,3)=1;
        }
        if(ID(ELMTlist(l,i))==31){ /*Ayam tepung*/
            IDset(*S,4)=1;
        }
        if(ID(ELMTlist(l,i))==37){ /*Ayam goreng*/
            IDset(*S,5)=1;
        }
    }
}

Set Union(Set S1, Set S2){
    Set S3;
    CreateEmptySet(&S3);
    for(int i=0;i<AllFoods;i++){
        if(IDset(S1,i)==1 || IDset(S2,i)==1){
            IDset(S3,i)==1;
        }
    }
    return S3;
}

Set Intersection(Set S1, Set S2){
    Set S3;
    CreateEmptySet(&S3);
    for(int i=0;i<AllFoods;i++){
        if(IDset(S1,i)==1 && IDset(S2,i)==1){
            IDset(S3,i)==1;
        }
    }
    return S3;
}

Set Negasi(Set S){
    Set Neg;
    CreateEmptySet(&Neg);
    for(int i=0;i<AllFoods;i++){
        if(IDset(S,i)==1){
            IDset(Neg,i)==0;
        }else{
            IDset(Neg,i)==1;
        }
    }
    return Neg;
}

Set Substraction(Set S1, Set S2){
    Set S3;
    CreateEmptySet(&S3);
    for(int i=0;i<AllFoods;i++){
        if(IDset(S1,i)==1 && IDset(S2,i)==1){
            IDset(S3,i)==0;
        }
    }
    return S3;
}

int Ones(Set S){
    int one=0;
    for(int i=0;i<AllFoods;i++){
        if(IDset(S,i)==1){
            one++;
        }
    }
    return one;
}

int Zeroes(Set S){
    int zero=0;
    for(int i=0;i<AllFoods;i++){
        if(IDset(S,i)==0){
            zero++;
        }
    }
    return zero;
}

boolean isAllZero(Set S){
    boolean allZero=true;
    for(int i=0;i<AllFoods;i++){
        if(IDset(S,i)==1){
            allZero = false;
            break;
        }
    }
    return allZero;
}

boolean isAllOne(Set S){
    boolean allOne = true;
    for(int i=0;i<AllFoods;i++){
        if(IDset(S,i)==0){
            allOne = false;
            break;
        }
    }
    return allOne;
}