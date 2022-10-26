#ifndef SET_H
#define SET_H

#include "../boolean.h"
#include "../Makanan/makanan.h"
#include "../ListStatik/liststatik.h"

#define AllFoods 6

typedef struct
{
    int ID[AllFoods];
} Set;

#define IDset(S,i) (S).ID[i]

/*Isi set sesuai jumlah makanan di file makanan dan berurut membesar berdasarkan ID makanan*/
//IDset(S,0)= Tepung (ID:10)
//IDset(S,1)= Ayam mentah (ID:11)
//IDset(S,2)= Minyak goreng (ID:15)
//IDset(S,3)= Ayam potong (ID:21)
//IDset(S,4)= Ayam tepung (ID:31)
//IDset(S,5)= Ayam goreng (ID:37)


void CreateEmptySet(Set *S);

void CreateSetFromList(Set *S, ListStatik l);

Set Union(Set S1, Set S2);

Set Intersection(Set S1, Set S2);

Set Negasi(Set S);

Set Substraction(Set S1, Set S2);

int Ones(Set S);

int Zeroes(Set S);

boolean isAllZero(Set S);

boolean isAllOne(Set S);

#endif