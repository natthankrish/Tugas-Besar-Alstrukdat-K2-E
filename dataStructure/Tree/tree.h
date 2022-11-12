#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../ListStatik/liststatik.h"
#include "../Makanan/makanan.h"


/* *** Definisi TYPE TREE  *** */
#define MAXCHILD 10  /* jumlah maksimum anak yang dapat dimiliki tree */
typedef struct Tree* node;
typedef struct Tree{
    MAKANAN info; /* informasi makanan pada node sekarang */
    int numChild; /* jumlah anak dari TREE */
    node listChild[MAXCHILD]; /* list anak yang dimiliki TREE */
    node parent; // parent dari node sekarang, NULL apabila node adalah root
} TREE;

/* *** Notasi Akses: Selektor Tree *** */
/* misal T adalah node*/
#define Parent(T) (T)->parent
#define NumOfChild(T) (T)->numChild
#define Childlist(T) (T)->listChild
#define InfoTree(T) (T)->info

/* *** Definisi LIST TREE  *** */
#define MAXTREE 10 // jumlah maksimum tree yang dapat dimiliki listtree
typedef struct {
   node contents[MAXTREE]; // kumpulan root tree
   int length;
}ListTree;

#define ELMTListTree(l, i) (l).contents[i]
#define ListTreeLength(l) (l).length


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk TREE *** */
void CreateNode(node* T, MAKANAN food);
/* I.S. Sembarang */
/* F.S. Terbentuk node tree dengan jumlah anak 0 dan listChild kosong berukuran MAXCHILD
   dan parent menunjuk NULL (node adalah root) */

void setParent(node* T, node P);
/* I.S. T terdefinisi, parent terdefinisi */
/* F.S. T menjadi child dari P*/


void setChild (node* T, MAKANAN food);
/* I.S. T terdefinisi*/
/* F.S. membuat child baru dengan makanan food dan menjadi element di listChild pada T */

MAKANAN getChild(node T, int idx);
/* Mengembalikan anak ke-idx dari T */

/* *** Fungsi yang berguna *** */
ListStatik ableTo(int action, ListStatik listMakanan, ListTree listResep);
/* Mengembalikan list yang berisi bahan makanan yang
   diolah dengna cara action*/

ListStatik madeBy(int action, ListStatik listMakanan, ListTree listResep);
/* Mengembalikan list yang berisi bahan makanan yang
   dibuat dengan cara action*/

/* *** Fungsi List Tree *** */
void CreateListTree(ListTree * L);
/* I.S. l sembarang */
/* F.S. Terbentuk ListTree L kosong dengan kapasitas 100 */
/* dengan panjang 0*/

void insertLastTree(ListTree * L, node T);
/* I.S. L terdefinisi */
/* F.S. T menjadi elemen listchild terakhir */

ListStatik getListChildByFood(MAKANAN food, ListTree listResep);
/* Mengembalikan list of all child of food*/

#endif   