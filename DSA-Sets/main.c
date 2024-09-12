#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"


int main () {
    Set s1 = createSet(10);
    Set s2 = createSet(15);
    addElement(&s1, 9);
    addElement(&s1, 8);
    addElement(&s1, 1);
    addElement(&s1, 4);
    addElement(&s1, 7);
    display(s1);
    addElement(&s2, 9);
    addElement(&s2, 8);
    addElement(&s2, 1);
    addElement(&s2, 4);
    display(s2);
    if (isSubset(s1, s2)) {
        printf("s2 is a subset of s1\n\n");
    } else {
        printf("NO\n");
    }
    Set uSet = intersectionSet(s1 ,s2);
    display(uSet);
    return 0;
}