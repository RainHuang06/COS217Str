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
    while(*cur != '\0') {
        cur++;
    } 
    return (size_t)(cur - s);
}

char* Str_copy(char* copy, const char* original) {
    /*int i = 0;
    assert(original != NULL);
    assert(copy != NULL);
    while(original[i] != '\0') {
        copy[i] = original[i];
        i++;
    }
    copy[i] = '\0'; /*Ending string
    return (char*)copy;*/
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
    return (char*)copy;
}

char* Str_concat(char* copy, const char* original) {
    /*int copyStart = (int)Str_getLength(copy);
    int i = copyStart;
    assert(original != NULL);
    assert(copy != NULL);
    while(original[i - copyStart] != '\0') { 
        copy[i] = original[i - copyStart];
        i++;
    }
    copy[i] = '\0';
    return (char*)copy;*/
    const char* originalCur;
    char* copyCur;
    assert(original != NULL);
    assert(copy != NULL);
    originalCur = original;
    copyCur = copy + (int)Str_getLength(copy);
    while(*originalCur != '\0'){
        *copyCur = *originalCur;
        originalCur++;
        copyCur++;
    }
    *copyCur = '\0';
    return (char*)copy;
}

int Str_compare(const char* s1, const char* s2) {
    /*int i;
    assert(s1 != NULL);
    assert(s2 != NULL);
    for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if((int)(s1[i] - s2[i]) != 0) {
            return (int)(s1[i] - s2[i]); /
        }
    }
    if(s1[i] == '\0' && s2[i] == '\0') { 
        return 0; 
    } else if(s1[i] == '\0') {
        return -1; 
    } else {
        return 1;
    }*/
    char* s1Cur;
    char* s2Cur;
    assert(s1 != NULL);
    assert(s2 != NULL);
    s1Cur = (char*)s1;
    s2Cur = (char*)s2;
    while(*s1Cur != '\0' && *s2Cur != '\0') {
        if((int)(*s1Cur - *s2Cur) != 0) {
            return (int)(*s1Cur - *s2Cur);
        }
        s1Cur++;
        s2Cur++;
    }
    return (int)(*s1Cur - *s2Cur);
}

char* Str_search(const char* toSearch, const char* find) {
    /*int searchLength = (int)Str_getLength(toSearch);
    int findLength = (int)Str_getLength(find);
    int i, j; 
    assert(toSearch != NULL);
    assert(find != NULL);
    if(findLength == 0) {
        return (char*)toSearch;
    }
    for(i = 0; i <= searchLength - findLength; i++) {
        int hasFound = 1; /*Flag defining if match found
        for(j = 0; j < findLength; j++) {
            if(toSearch[i + j] != find[j]) {
                hasFound = 0; /*Discrepancy means we must set a flag
            }
        }
        if(hasFound) {
            return (char*)&toSearch[i]; /*Runs when no discrepancy is discovered
        }
    }
    return NULL;*/
    int searchLength;
    int findLength;
    int i, j;
    char* toSearchCur;
    char* toSearchComparator;
    char* findComparator;
    assert(toSearch != NULL);
    assert(find != NULL);
    searchLength = (int)Str_getLength(toSearch);
    findLength = (int)Str_getLength(find);
    while(toSearchCur <= toSearch + searchLength - findLength) {
        int hasFound = 1;
        toSearchComparator = toSearchCur;
        findComparator = (char*)find;
        while(findComparator < find + findLength) {
            if(*toSearchComparator == *findComparator) {
                hasFound = 0;
            }
            findComparator++;
            toSearchComparator++;
        }
        if(hasFound) {
            return (char*)toSearchCur;
        }
        toSearchCur++;
    }
}