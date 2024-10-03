#ifndef STRING_H
#define STRING_H
#include <stddef.h>
size_t Str_getLength(const char s[]);
char* Str_copy(char copy[], const char original[]);
char* Str_concat(char copy[], const char original[]);
int Str_compare(const char s1[], const char s2[]);
char* Str_search(const char toSearch[], const char find[]);
#endif