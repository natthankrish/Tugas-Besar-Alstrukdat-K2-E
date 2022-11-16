#include <stdio.h>

void PrintCatalog (ListStatik makananconfig){
    for (int i = 0; i < makananconfig.length; i++) {
        printf ("%d. ", i+1);
        for (int j = 0; j < 101; j++) {
            printf("%c", makananconfig.contents[i].name[j]);
        }
        printf("\n");
        printf("   ID Makanan: %d\n", makananconfig.contents[i].idx);
        printf("   Durasi Sebelum Kadaluarsa:");

        if (makananconfig.contents[i].expiry.D != 0) {
            printf(" %d Hari", makananconfig.contents[i].expiry.D);
        }

        if (makananconfig.contents[i].expiry.HH != 0) {
            printf(" %d Jam", makananconfig.contents[i].expiry.HH);
        }

        if (makananconfig.contents[i].expiry.MM != 0) {
            printf(" %d Menit", makananconfig.contents[i].expiry.MM);
        }

        printf("\n");

        printf("   Waktu Delivery:");

        if (makananconfig.contents[i].deliveryTime.D != 0) {
            printf(" %d Hari", makananconfig.contents[i].deliveryTime.D);
        }

        if (makananconfig.contents[i].deliveryTime.HH != 0) {
            printf(" %d Jam", makananconfig.contents[i].deliveryTime.HH);
        }

        if (makananconfig.contents[i].deliveryTime.MM != 0) {
            printf(" %d Menit", makananconfig.contents[i].deliveryTime.MM);
        }

        if (makananconfig.contents[i].deliveryTime.D == 0 && makananconfig.contents[i].deliveryTime.HH == 0 && makananconfig.contents[i].deliveryTime.MM == 0) {
            printf(" Langsung tersedia");
        }

        printf("\n");

        printf("   Command untuk Mendapatkan:"); 

        if (makananconfig.contents[i].action == 1) {
            printf(" BUY");
        } else if (makananconfig.contents[i].action == 2) {
            printf(" CHOP");
        } else if (makananconfig.contents[i].action == 3) {
            printf(" FRY");
        } else if (makananconfig.contents[i].action == 4) {
            printf(" BOIL");
        } else if (makananconfig.contents[i].action == 5) {
            printf(" MIX");
        }

        printf("\n");

        printf("   Ukuran (PxL): %d x %d\n", makananconfig.contents[i].size.width, makananconfig.contents[i].size.height);
    }
}