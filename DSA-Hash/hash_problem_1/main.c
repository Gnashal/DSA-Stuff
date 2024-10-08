#include "functions.h"
#include <stdlib.h>

int main()
{
    Stack productStack;
    initStack(&productStack);

    Product products[] = {
        createProduct(104, "WidgetA", 100, 19.99),
        createProduct(rand() % 100, "GadgetB", 150, 29.99),
        createProduct(rand() % 100, "WOOWW", 200, 9.99),
        createProduct(rand() % 100, "DoohickeyD", 75, 49.99),
        createProduct(rand() % 100, "ContraptionE", 30, 39.99),
        createProduct(104, "WidgetA", 50, 19.99), // Duplicate ID with different quantity
        createProduct(rand() % 100, "GizmoF", 120, 25.99),
        createProduct(rand() % 100, "DoodadG", 80, 15.49),
        createProduct(rand() % 100, "GadgetB", 60, 29.99), // Duplicate product name with different quantity
        createProduct(rand() % 100, "WidgetH", 40, 22.50),
        createProduct(rand() % 100, "AccessoryI", 200, 11.99),
        createProduct(rand() % 100, "ItemJ", 150, 33.33),
        createProduct(rand() % 100, "ToolK", 90, 45.00),
        createProduct(rand() % 100, "GizmoL", 45, 12.99),
        createProduct(rand() % 100, "ContraptionM", 10, 20.00),
        createProduct(rand() % 100, "DeviceN", 30, 5.50),
        createProduct(rand() % 100, "WidgetO", 25, 75.00),
        createProduct(rand() % 100, "GadgetP", 55, 19.95),
        createProduct(rand() % 100, "ThingQ", 85, 15.00),
        createProduct(rand() % 100, "ItemR", 60, 27.50),
        createProduct(rand() % 100, "ToolS", 100, 10.00)};

    for (int i = 0; i < sizeof(products) / sizeof(products[0]); i++)
    {
        push(&productStack, products[i]);
    }

    visualizeStack(productStack);

    ProdDict dict = createDict(20);
    convertStack(&productStack, &dict);
    vissualizeDict(dict);
    visualizeStack(productStack);

    
    // Freeing the data
    for (int i = 0; i < dict.max; ++i)
    {
        if (dict.data[i])
        {
            free(dict.data[i]);
        }
    }
    free(dict.data);
    
    // Freeing dump stack
    // while (!isEmpty(dumpStack))
    // {
    //     hardPop(&dumpStack);
    // }

    return 0;
}
