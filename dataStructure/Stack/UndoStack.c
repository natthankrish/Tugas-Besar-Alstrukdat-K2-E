#include "../boolean.h"
#include "../Simulator/simulator.h"
#include "UndoStack.h"

void CreateEmptyStack(Stack *S){
    Top(*S) = Nil;
}

boolean IsEmptyStack(Stack S){
    return Top(S) == Nil;
}

boolean IsFullStack(Stack S){
    return Top(S) == MaxElStack - 1;
}

boolean canUndo(Stack S){
    return S.currState != 0;
}
boolean canRedo(Stack S){
    return Top(S) != S.currState;
}

void Push(Stack * S, infotype X){
    if(Top(*S) == Nil){
        Top(*S) = 0;
        S->currState = 0;
        InfoTop(*S) = X;
    }else{
        Top(*S) = S->currState + 1;
        S->currState++;
        InfoTop(*S) = X;
    }
}

void Undo(Stack *S, boolean *isstart, boolean *isexit, Matrix *Peta, SIMULATOR *BNMO, TIME *waktu, PrioQueue *pesanan, ListNotif *notifikasi){
    if(!canUndo(*S)){
        printf("Anda sudah tidak bisa undo.\n");
    }else{
        printf("undo berhasil.\n");
        S->currState--;
        *isstart = S->T[S->currState].isstart;
        *isexit = S->T[S->currState].isexit;
        POINT lastlocation = getSimulatorLocation(*Peta);
        Peta->mem[lastlocation.X][lastlocation.Y] = '#';
        POINT newlocation = S->T[S->currState].bin.LOKASI;
        *waktu = S->T[S->currState].waktu;
        Peta->mem[newlocation.X][newlocation.Y] = 'S';
        *BNMO = S->T[S->currState].bin;
        *pesanan = S->T[S->currState].pesanan;
        *notifikasi = S->T[S->currState + 1].notifikasi;
        notifikasi->tipenotif = 1;
    }
}

void Redo(Stack *S, boolean *isstart, boolean *isexit, Matrix *Peta, SIMULATOR *BNMO, TIME *waktu, PrioQueue *pesanan, ListNotif *notifikasi){
    if(!canRedo(*S)){
        printf("Anda sudah tidak bisa redo.\n");
    }else{
        printf("redo berhasil.\n");
        S->currState++;
        *isstart = S->T[S->currState].isstart;
        *isexit = S->T[S->currState].isexit;
        POINT lastlocation = getSimulatorLocation(*Peta);
        Peta->mem[lastlocation.X][lastlocation.Y] = '#';
        POINT newlocation = S->T[S->currState].bin.LOKASI;
        Peta->mem[newlocation.X][newlocation.Y] = 'S';
        *waktu = S->T[S->currState].waktu;
        *BNMO = S->T[S->currState].bin;
        *pesanan = S->T[S->currState].pesanan;
        *notifikasi = S->T[S->currState].notifikasi;
        notifikasi->tipenotif = 0;
    }
}
