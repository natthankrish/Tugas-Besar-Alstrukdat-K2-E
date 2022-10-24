#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (PrioQueue Q){
  return (Head(Q) == Nil) && (Tail(Q)==Nil);
}

boolean IsFull (PrioQueue Q){
  return NBElmt(Q) == MaxEl(Q);
}

int NBElmt (PrioQueue Q){
  if (IsEmpty(Q)){
    return 0;
  } else {
    if (Tail(Q) >= Head(Q)) {
      return Tail(Q) - Head(Q) + 1;
    } else {
      return MaxEl(Q) - Head(Q) + Tail(Q) + 1;
    }
  }
}

void MakeEmpty (PrioQueue * Q, int Max){
  (*Q).T = (MAKANAN *)malloc((Max) * sizeof(MAKANAN));
  MaxEl(*Q) = Max;
  Head(*Q) = Nil;
  Tail(*Q) = Nil;
}

void DeAlokasi(PrioQueue * Q){
  free((*Q).T);
  MaxEl(*Q) = 0;
}

void Enqueue (PrioQueue * Q, MAKANAN X){
  MAKANAN temp;
  if (IsEmpty(*Q)) {
    Head(*Q) = 0;
    Tail(*Q) = 0;
    InfoTail(*Q) = X;
  } else {
    Tail(*Q) = (Tail(*Q)+1) % MaxEl(*Q);
    InfoTail(*Q) = X;
    int i = Tail(*Q) == 0 ? NBElmt(*Q) - 1 : Tail(*Q) - 1;
    while (i != Head(*Q) && TLT(X.expiry , Elmt(*Q,i).expiry)) {
      temp = Elmt(*Q,i);
      Elmt(*Q,i) = X;
      Elmt(*Q, i+1) = temp;

      if (i == 0) {
        i = MaxEl(*Q) - 1;
      } else {
        i-- ;
      }
    }

    if (i == Head(*Q) && TLT(X.expiry , Elmt(*Q, i).expiry)) {
      temp = Elmt(*Q,i);
      Elmt(*Q,i) = X;
      Elmt(*Q, i+1) = temp;
    }

  }
}

void Dequeue (PrioQueue * Q, MAKANAN * X){
  *X = InfoHead(*Q);
  if (NBElmt(*Q) == 1) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
  } else {
    Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
  }
}

void PrintPrioQueue (PrioQueue Q){ // belum selesai bagian print name
  if (IsEmpty(Q)) {
    printf("#\n");
  } else {
    for (int i = Head(Q); i < (NBElmt(Q) + Head(Q)); i++){
      printf("%d %c\n", Elmt(Q, i % MaxEl(Q)).expiry, Elmt(Q, i % MaxEl(Q)).name);
    }
    printf("#\n");
  }
}

