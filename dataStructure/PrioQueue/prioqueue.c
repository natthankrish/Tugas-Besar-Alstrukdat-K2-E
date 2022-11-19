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
  Q->sortBy = 0;
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
    if(Q->sortBy == 0){ /* sort by expiry */
      while (i != Head(*Q) && ExpiryLT(X, Elmt(*Q,i))) {
        temp = Elmt(*Q,i);
        Elmt(*Q,i) = X;
        Elmt(*Q, i+1) = temp;

        if (i == 0) {
          i = MaxEl(*Q) - 1;
        } else {
          i-- ;
        }
      }
      if (i == Head(*Q) && ExpiryLT(X, Elmt(*Q,i))) {
        temp = Elmt(*Q,i);
        Elmt(*Q,i) = X;
        Elmt(*Q, i+1) = temp;
      }
    }else{ /* sort by delivery */
      while (i != Head(*Q) && DeliveryLT(X, Elmt(*Q,i))) {
        temp = Elmt(*Q,i);
        Elmt(*Q,i) = X;
        Elmt(*Q, i+1) = temp;

        if (i == 0) {
          i = MaxEl(*Q) - 1;
        } else {
          i-- ;
        }
      }
      if (i == Head(*Q) && DeliveryLT(X, Elmt(*Q,i))) {
        temp = Elmt(*Q,i);
        Elmt(*Q,i) = X;
        Elmt(*Q, i+1) = temp;
      }
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

void CopyQueue(PrioQueue *Qcopy, PrioQueue *Qtarget){
  // DeAlokasi(Qtarget);
  MakeEmpty(Qtarget, Qcopy->MaxEl);
  Qtarget->sortBy = Qcopy->sortBy;
  for(int i=Qcopy->HEAD;i<(Qcopy->HEAD + NBElmt(*Qcopy));i++){
    Enqueue(Qtarget, Qcopy->T[i%MaxEl(*Qcopy)]);
  }
}