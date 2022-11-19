#include <stdio.h>
#include "dataStructure/boolean.h"
#include "dataStructure/Point/point.c"
#include "dataStructure/Makanan/makanan.c"
#include "dataStructure/Simulator/simulator.c"
#include "dataStructure/Matrix/matrix.c"
#include "dataStructure/ListStatik/liststatik.c"
#include "dataStructure/ListStatik/ListNotif.c"
#include "dataStructure/PrioQueue/prioqueue.c"
#include "dataStructure/Stack/UndoStack.c"
#include "dataStructure/Time/time.c"
#include "dataStructure/Tree/tree.c"
#include "dataStructure/Inventory/inventory.c"
#include "dataStructure/Set/set.c"
#include "procedure/command.c"
#include "procedure/splashScreen.c"
#include "procedure/printPeta.c"


int main () {
    boolean isStarted = false, isExit = false;
    Matrix mapconfig;
    ListStatik makananconfig;
    SIMULATOR BNMO;
    ListTree resepconfig;
    PrioQueue pesanan;
    Stack UndoStack;
    ListNotif Notifikasi;

    CreateEmptyStack(&UndoStack);
    MakeEmpty(&pesanan, 101);
    pesanan.sortBy = 1; /* pesanan sort by delivery time */
    CreateListTree(&resepconfig);

    TIME machinetime;
    setClockZero(&machinetime);

    welcomePage();
    inputCommand(&isStarted, &isExit, &mapconfig, &makananconfig, &machinetime, &BNMO, &resepconfig, &pesanan, &UndoStack, &Notifikasi);
    while (!isExit) {
        if (isStarted) {
            printStatus(mapconfig, machinetime, BNMO, Notifikasi);
        }
        inputCommand(&isStarted, &isExit, &mapconfig, &makananconfig, &machinetime, &BNMO, &resepconfig, &pesanan, &UndoStack, &Notifikasi);
    }

    return 0;
}