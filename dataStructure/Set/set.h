#ifndef SET_H
#define SET_H

#include "../boolean.h"
#include "../Makanan/makanan.h"
#include "../ListStatik/liststatik.h"
#include "../Tree/tree.h"
#include "../Simulator/simulator.h"

typedef struct Node* nodeAddress;
typedef struct Node {
    int infoNode;
    nodeAddress nextNode;
} SetNode;

typedef nodeAddress Set;

/* SELEKTOR SET */
/* misal S adalah Set*/
#define InfoNode(S) (S)->infoNode
#define NextNode(S) (S)->nextNode


nodeAddress newSetNode(int x);

void CreateEmptySet(Set *S, int numFoods);

void fillNode(Set* S, int idx);

Set CreateFoodSet(MAKANAN food, ListStatik listMakanan,ListTree listResep);

Set CreateInventorySet(SIMULATOR S, ListStatik listMakanan, ListTree listResep);

boolean isSubsetInventory(Set inventorySet, Set S, int numFoods);


void displaySet(Set S, int numFoods);
// Set Union(Set S1, Set S2);

// Set Intersection(Set S1, Set S2);

// Set Negasi(Set S);

// Set Substraction(Set S1, Set S2);

// int Ones(Set S);

// int Zeroes(Set S);

// boolean isAllZero(Set S);

// boolean isAllOne(Set S);

#endif