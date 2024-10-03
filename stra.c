/*
stra.c
Author: Rain Huang
*/
#include <stddef.h>
#include <assert.h>
#include "str.h"
/*
Takes one argument, const char s[]. Returns the length of the string up to the first null terminator. Errors
if argument is null.
*/
size_t Str_getLength(const char s[]) {
    size_t length = 0;
    assert(s != NULL);
    while(s[length] != '\0') {
        length++;
    } 
    return length;
}
/*
Takes two arguments, char copy[] and const char original[]. Copies values of original to copy and then returns
the characters copied.
*/
char* Str_copy(char copy[], const char original[]) {
    int i;
    assert(original != NULL);
    assert(copy != NULL);
    while(original[i] != '\0') {
        copy[i] = original[i];
        i++;
    }
    return (char*)copy;
}
/*
Takes two arguments, char copy[] and const char original[]. Concatenates values of original to the end of copy[],
then returns the resulting string.
*/
char* Str_concat(char copy[], const char original[]) {
    int copyStart = (int)Str_getLength(copy);
    int i = copyStart;
    assert(original != NULL);
    assert(copy != NULL);
    while(original[i - copyStart] != '\0') { /*Copies until end of string*/
        copy[i] = original[i - copyStart];
        i++;
    }
    copy[i] = '\0';
    return (char*)copy;
}
/*
Takes two arguments, const char s1[] and const char s2[]. Compares the lexicographical value
ie alphabetical order, then returns -1 if s1 is smaller than s2.
*/
int Str_compare(const char s1[], const char s2[]) {
    int i;
    assert(s1 != NULL);
    assert(s2 != NULL);
    for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if(s1[i] - s2[i] != 0) {
            return s1[i] - s2[i]; /*Comparison of unequal character value of correct sign*/
        }
    }
    if(s1[i] == '\0' && s2[i] == '\0') { /*Handles end-of-string cases*/
        return 0; /*Are the strings of equal length?*/
    } else if(s1[i] == '\0') {
        return -1; /*Shorter string comes first*/
    } else {
        return 1;
    }
    
}
/*
Takes two arguments, const char toSearch[] and const char find[].
If searching for an empty string, returns toSearch.
If nothing was found, returns a null pointer.
*/
char* Str_search(const char toSearch[], const char find[]) {
    int searchLength = (int)Str_getLength(toSearch);
    int findLength = (int)Str_getLength(find);
    int i, j;
    assert(toSearch != NULL);
    assert(find != NULL);
    if(findLength == 0) {
        return (char*)toSearch;
    }
    for(i = 0; i <= searchLength - findLength; i++) {
        int hasFound = 1;
        for(j = 0; j < findLength; j++) {
            if(toSearch[i + j] != find[j]) {
                hasFound = 0;
            }
        }
        if(hasFound) {
            return (char*)&toSearch[i];
        }
    }
    return NULL;
}