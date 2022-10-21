#include <stdio.h>
#include "../dataStructure/boolean.h"

boolean compareString (char a[], int lengthA, char b[], int lengthB) {
    int i = 0;
    boolean isSame = true;
    
    if (lengthA != lengthB) {
        return false;
    } else { //LengthA == LengthB
        while (i < lengthA && isSame) {
            if (a[i] != b[i]) {
                isSame = false;
            }
            i++;
        }
        if (isSame) {
            return true;
        }
        else {
            return false;
        }
    }
}

