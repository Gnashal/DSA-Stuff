#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products.h"

int main () {
    Product prodList[5];
    Product readList;
    prodList[0] = createProd("Sword", 200.67);
    prodList[1] = createProd("Axe", 464.2);
    prodList[2] = createProd("Mace", 333.23);
    prodList[3] = createProd("Spear", 123.23);
    prodList[4] = createProd("Dagger", 50.50);

    FILE *fp = fopen("products.txt", "wb");


    if (fp != NULL) {
        fwrite(prodList, sizeof(Product), 5, fp);
        fclose(fp);
    }

    fp = fopen("products.txt", "rb");
    if (fp) {
        for (int i = 0; i < 5; ++i) {
            if (fread(&readList, sizeof(Product), 1,fp) == 1) {
                displayProd(readList);
            } else {
                return EXIT_FAILURE;
            }        
        }
        fclose(fp);
    }

    return 0;
}