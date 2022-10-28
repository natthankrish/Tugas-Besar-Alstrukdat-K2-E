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

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk TREE *** */
void CreateTree (TREE * T, int jumlahAnak);
/* I.S. Sembarang */
/* F.S. Terbentuk TREE dengan jumlah anak 
   yang terdefinisi dan listChild kosong berukuran 10 */

void setChild (TREE * T, MAKANAN child);
/* I.S. TREE P terdefinisi*/
/* F.S. child menjadi element di listChild pada P*/

MAKANAN getChild(TREE T, int idx);
/* Mengembalikan anak ke-idx dari P */

/* *** Fungsi yang berguna *** */

ListStatik ableTo(int action, ListStatik listMakanan );
/* Mengembalikan list yang berisi bahan makanan yang
   diolah dengna cara action*/

#endif