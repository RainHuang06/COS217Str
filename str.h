/*
str.h
Author: Rain Huang
*/
#ifndef STRING_H
#define STRING_H
#include <stddef.h>
/*Returns the length of string s, EXCLUDING null terminator*/
size_t Str_getLength(const char s[]);
/*Copies original to copy, then returns copy*/
char* Str_copy(char copy[], const char original[]);
/*Concatenates original to the end of copy, then returns copy.
Overwrites the null terminator.*/
char* Str_concat(char copy[], const char original[]);
/*Compares s1 and s2 by lexicographical order, returning a negative
integer value if s1 is lexicographically less than s2,
a positive value if s1 is lexicographically more than s2,
and 0 if they are equivalent.*/
int Str_compare(const char s1[], const char s2[]);
/*Searches for string find in string toSearch, and returns pointer to
first occurrence. Returns a null pointer if
there is no ocurrences of find in toSearch, and returns 
toSearch if find is empty string.*/
char* Str_search(const char toSearch[], const char find[]);
#endif