#include <stdio.h>
#include <stdlib.h>
#include "problem-1.h"

typedef char String[20];

int main () {
    NQueue q;
    initNQueue(&q, 10);
    String fnames[10] = {"Yousif", "Carl", "Sam", "Uriel", "John", "Ivan","Nino", "Jay", "Clark"};
    String lnames[10] = {"Baker", "Baker", "Baker", "Cayon", "Gerozaga", "Jayme", "Cruz", "Basilgo", "Ceballos"};
    Name names[10];

    for (int i = 0; i < q.max; ++i) {
        names[i] = createName(fnames[i], lnames[i]);
        enqueue(&q, names[i]);
    }

    displayQueue(q);

    Name *filteredNames = filterNames(&q, "Baker");

    printf("Filtered Names: \n");
    for (int i = 0; strcmp(filteredNames[i].lname, "") != 0; ++i) {
        printf("{%s, %s}\n", filteredNames[i].fname,filteredNames[i].lname);
    }
    displayQueue(q);

    free(filteredNames);
    return 0;
}