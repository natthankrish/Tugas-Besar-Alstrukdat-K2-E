#include "../dataStructure/WordMachine/wordmachine.h"

int wordToInt(Word w){
    boolean valid = true;
    int value = 0;
    int pow10 = 1;
    for(int i=w.Length-1;i>=0;i--){
        if(w.TabWord[i]-'0' < 0 || w.TabWord[i]-'0' > 9){ // check if digit
            valid = false;
            break;
        }

        value += (w.TabWord[i]-'0') * pow10;
        pow10 *= 10;
    }
    if(valid)return value;
    else return -1;
}