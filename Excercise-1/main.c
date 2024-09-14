#include <stdio.h>
#include <stdlib.h>
#include "problem-1.h"

typedef char String[20];

int main () {
    NQueue q;
    initNQueue(&q, 10);
    String fnames[10] = {"Yousif", "Carl", "Sam", "Uriel", "John", "Ivan","Nino", "Jay", "Clark", "JP"};
    String lnames[10] = {"Ceballos", "Horlador", "Baker", "Cayon", "Gerozaga", "Jayme", "Cruz", "Basilgo", "Rence", "Medico"};
    Name names[10];

    for (int i = 0; i < q.max; ++i) {
        names[i] = createName(fnames[i], lnames[i]);
        enqueue(&q, names[i]);
    }

    displayQueue(q);

    Name *filteredNames = filterNames(&q, "Ceballos");

    printf("Filtered Names: \n");
    for (int i = 0; filteredNames[i].fname != "" && filteredNames[i].lname != ""; ++i) {
        printf("%s, %s\n", filteredNames[i].fname,filteredNames[i].lname);
    }

    return 0;
}