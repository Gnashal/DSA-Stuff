#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char String[20];

char* my_toLower(String string) {
    int length = strlen(string);
    char* returnS = (char*)malloc((length + 1) * sizeof(char));
    for (int i = 0; string[i] != '\0'; i++) {
        returnS[i] =tolower((unsigned char)string[i]);
    }
    returnS[length] = '\0';

    return returnS;
}

char* reverseString(String string1, String string2) {
    int length = strlen(string2);
    char* reversedString = (char*)malloc((length + 1) * sizeof(char));
    int index = 0;
    for (int i = length - 1; i >= 0; i--) {
        reversedString[index++] = string2[i];
    }
     reversedString[index] = '\0';


    return strcmp(string1, reversedString) == 0 ? reversedString : NULL;
}



#endif