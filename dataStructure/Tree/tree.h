#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../ListStatik/liststatik.h"
#include "../Makanan/makanan.h"


/* *** Definisi TYPE TREE  *** */
typedef struct {
    MAKANAN parent; /* parent dari TREE */
    int numChild; /* jumlah anak dari TREE */
    ListStatik listChild;  /* list anak yang dimiliki TREE */
} TREE;

/* *** Notasi Akses: Selektor Tree *** */
#define Parent(T) (T).parent
#define NumOfChild(T) (T).numChild
#define Childlist(T) (T).listChild

/* *** Definisi LIST TREE  *** */
typedef struct {
   TREE contents[100];
   int length;
}ListTree;

#define ELMTListTree(l, i) (l).contents[i]
#define ListTreeLength(l) (l).length


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk TREE *** */
void CreateTree (TREE * T, MAKANAN parent, int jumlahAnak);
/* I.S. Sembarang */
/* F.S. Terbentuk TREE dengan jumlah anak 
   yang terdefinisi dan listChild kosong berukuran 10 */

void setChild (TREE * T, MAKANAN child);
/* I.S. TREE P terdefinisi*/
/* F.S. child menjadi element di listChild pada P*/

MAKANAN getChild(TREE T, int idx);
/* Mengembalikan anak ke-idx dari P */

/* *** Fungsi yang berguna *** */
ListStatik ableTo(int action, ListStatik listMakanan, ListTree listResep);
/* Mengembalikan list yang berisi bahan makanan yang
   diolah dengna cara action*/

/* *** Fungsi List Tree *** */
void CreateListTree(ListTree * L);
/* I.S. l sembarang */
/* F.S. Terbentuk ListTree L kosong dengan kapasitas 100 */
/* dengan panjang 0*/

void insertLastTree(ListTree * L, TREE T);
/* I.S. L terdefinisi */
/* F.S. T menjadi elemen listchild terakhir */


#endif   