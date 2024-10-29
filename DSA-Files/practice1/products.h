#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char prodName[20];
    float prodPrice;
} Product;

Product createProd(char* name, float price) {
    Product newProd;
    strcpy(newProd.prodName, name);
    newProd.prodPrice = price;
    return newProd;
}
void displayProd(Product p) {
    printf("%15s - Php %.2f", p.prodName, p.prodPrice);
}


#endif