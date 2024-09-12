#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct 
{
    int* elems;
    int count;
    int max;
} Set;

// typdef char Set;

Set createSet(int max) {
    Set newSet;

    newSet.max = max;
    newSet.elems = (int*)calloc(sizeof(int), newSet.max);

    return newSet;
}
bool addElement(Set *s, int item) {
    if (item <= s->max || s->elems[item] != 1) {
        s->elems[item] = 1;
        return true;
    } else {
        return false;   
    }
}
bool revomeItem(Set* s, int item) {
       if (item <= s->max || s->elems[item] == 1) {
        s->elems[item] = 0;
        return true;
    } else {
        return false;   
    }
}
void display(Set s) {
    for (int i = 0; i < s.max; i++) {
        if (s.elems[i] == 1) {
            printf("%d ",i);
        }
    }
    printf("\n");
}
bool isElement(Set s, int item) {
     return (s.elems[item] == 1) ? true:false;
}
bool isSubset(Set a, Set b) {
    int size = (a.max > b.max) ? a.max: b.max;
    for (int i = 0; i < size; ++i) {
        if (b.elems[i] == 1 && a.elems[i] != b.elems[i]) {
            return false;   
        }
    }
    return true;
}
int cardinality(Set a) {
    int counter = 0;
    for(int i = 0; i < a.max; ++i) {
        if (a.elems[i] == 1) {
            counter++;
        }
    }
    return counter;
}

Set unionSet(Set a, Set b) {
    int size = (a.max > b.max) ? a.max: b.max;
    Set newSet = createSet(size);
    for (int i = 0; i < size; ++i) {
        if (a.elems[i] == 1 || b.elems[i] == 1) {
            newSet.elems[i] = 1;
        }
    }

    return newSet;
}
Set intersectionSet(Set a, Set b) {
    int size = (a.max > b.max) ? a.max: b.max;
    Set newSet = createSet(size);
    for (int i = 0; i < size; ++i) {
        if (a.elems[i] == 1 && b.elems[i] == 1) {
            if (a.elems[i] == b.elems[i]) {
                newSet.elems[i] = 1;
            }
        }
    }

    return newSet;
}
Set difference(Set a, Set b) {
    for (int i = 0; i < a.max; ++i) {
        if (a.elems[i] == b.elems[i] && b.elems[i] == 1) {
            a.elems[i] = 0;
        }
    } 
    return a;
}

Set symmentricalDifference(Set a, Set b) {
    return unionSet(difference(a, b), difference(b, a));
}


#endif 