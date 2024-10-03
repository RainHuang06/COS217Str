/*
stra.c
Author: Rain Huang
*/
#include <stddef.h>
#include <assert.h>
#include "str.h"
size_t Str_getLength(const char s[]) {
    size_t length = 0;
    assert(s != NULL);
    while(s[length] != '\0') {
        length++;
    } 
    return length;
}

char* Str_copy(char copy[], const char original[]) {
    int i = 0;
    assert(original != NULL);
    assert(copy != NULL);
    while(original[i] != '\0') {
        copy[i] = original[i];
        i++;
    }
    copy[i] = '\0'; /*Ending string*/
    return (char*)copy;
}

char* Str_concat(char copy[], const char original[]) {
    int copyStart;
    int i;
    assert(original != NULL);
    assert(copy != NULL);
    copyStart = (int)Str_getLength(copy);
    i = copyStart;
    while(original[i - copyStart] != '\0') { /*Copies until end of string*/
        copy[i] = original[i - copyStart];
        i++;
    }
    copy[i] = '\0';
    return (char*)copy;
}

int Str_compare(const char s1[], const char s2[]) {
    int i;
    assert(s1 != NULL);
    assert(s2 != NULL);
    for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if((int)(s1[i] - s2[i]) != 0) {
            return (int)(s1[i] - s2[i]); /*Comparison of unequal character value of correct sign*/
        }
    }
    return (int)(s1[i] - s2[i]); /*Comparison of unequal character value of correct sign*/
    
}

char* Str_search(const char toSearch[], const char find[]) {
    int searchLength;
    int findLength;
    int i, j; 
    assert(toSearch != NULL);
    assert(find != NULL);
    searchLength = (int)Str_getLength(toSearch);
    findLength = (int)Str_getLength(find);
    if(findLength == 0) {
        return (char*)toSearch;
    }
    for(i = 0; i <= searchLength - findLength; i++) {
        int hasFound = 1; /*Flag defining if match found*/
        for(j = 0; j < findLength; j++) {
            if(toSearch[i + j] != find[j]) {
                hasFound = 0; /*Discrepancy means we must set a flag*/
            }
        }
        if(hasFound) {
            return (char*)&toSearch[i]; /*Runs when no discrepancy is discovered*/
        }
    }
    return NULL;
}