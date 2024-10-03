/*
strp.c
author: Rain Huang
*/
#include <stddef.h>
#include <assert.h>
#include "str.h"
size_t Str_getLength(const char* s) {
    const char *cur;
    assert(s != NULL);
    cur = s;
    while(*cur != '\0') { /*Increments pointer until we reach the end*/
        cur++;
    } 
    return (size_t)(cur - s);
}

char* Str_copy(char* copy, const char* original) {
    const char* originalCur;
    char* copyCur;
    assert(original != NULL);
    assert(copy != NULL);
    originalCur = original;
    copyCur = copy;
    while(*originalCur != '\0') {
        *copyCur = *originalCur; 
        originalCur++;
        copyCur++;
    }
    *copyCur = '\0'; /*Re-adds null terminator*/
    return (char*)copy;
}

char* Str_concat(char* copy, const char* original) {
    const char* originalCur;
    char* copyCur;
    assert(original != NULL);
    assert(copy != NULL);
    originalCur = original;
    copyCur = copy + (int)Str_getLength(copy); /*iteration starting pt*/
    while(*originalCur != '\0'){
        *copyCur = *originalCur;
        originalCur++;
        copyCur++;
    }
    *copyCur = '\0'; /*Re-adds null terminator*/
    return (char*)copy;
}

int Str_compare(const char* s1, const char* s2) {
    char* s1Cur;
    char* s2Cur;
    assert(s1 != NULL);
    assert(s2 != NULL);
    s1Cur = (char*)s1;
    s2Cur = (char*)s2;
    while(*s1Cur != '\0' && *s2Cur != '\0') {
        if((int)(*s1Cur - *s2Cur) != 0) {
            return (int)(*s1Cur - *s2Cur); /*returns correct sign int*/
        }
        s1Cur++;
        s2Cur++;
    }
    return (int)(*s1Cur - *s2Cur); /*comparing last character of
    shorter string out of s1 and s2*/
}

char* Str_search(const char* toSearch, const char* find) {
    int searchLength;
    int findLength;
    char* toSearchCur; /*current pointer for start of search*/
    char* toSearchComparator; /*to be compared to find*/
    char* findComparator; /*target character*/
    assert(toSearch != NULL);
    assert(find != NULL);
    searchLength = (int)Str_getLength(toSearch);
    findLength = (int)Str_getLength(find);
    toSearchCur = (char*)toSearch;
    if(findLength == 0) {
        return (char*)toSearch;
    }
    while(toSearchCur <= toSearch + searchLength - findLength) {
        int hasFound = 1; /*flag set to true*/
        toSearchComparator = toSearchCur;
        findComparator = (char*)find; /*initialize matching pointers*/
        while(findComparator < find + findLength) {
            if(*toSearchComparator != *findComparator) {
                hasFound = 0; /*discrepancy, flag is false*/
            }
            findComparator++;
            toSearchComparator++; /*increment to match next character*/
        }
        if(hasFound) {
            return (char*)toSearchCur; /*no discrepancy!*/
        }
        toSearchCur++;
    }
    return NULL; /*discrepancy means null*/
}
