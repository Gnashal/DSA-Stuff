#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions.h"

int main () {   
    String string1, string2;
    char* newS1, *newS2;

    printf("Enter strings here: ");
    if ( scanf("%19s %19s", string1, string2) != 2) {
        printf("Scanf failed");
        return 1;
    }

   newS1 = my_toLower(string1);
   newS2 = my_toLower(string2);

    printf("%10s %10s\n", newS1, newS2);

    char* reversed = reverseString(newS1, newS2);
    if (reversed) {
        printf("Originial String: %s\n", newS2);
        printf("Reversed String: %s\n", reversed);
    } else {
        printf("Strings not compatible\n");
    }

    

    return 0;
}