#include <stddef.h>
size_t Str_getLength(const char s[]) {
    size_t length = 0;
    assert(s != NULL);
    while(s[length] != '\0') {
        length++;
    }
    return length;
}
char* Str_copy(char copy[], char original[]) {
    assert(original != NULL);
    int length = Str_getLength(original);
    int i;
    for(i = 0; i <= length; i++) {
        copy[i] = original[i];
    }
    return copy;
}
char* Str_concat(char copy[], char original[]) {
    assert(original != NULL);
    int copyStart = Str_getLength(copy);
    int length = Str_getLength(original);
    int i;
    for(i = copyStart; i <= copyStart + length; i++) {
        copy[i] = original[i - copyStart];
    }
    return copy;
}
int Str_compare(const char s1[], const char s2[]) {
    assert(s1 != NULL);
    assert(s2 != NULL);
    int s1Length = Str_getLength(s1);
    int s2Length = Str_getLength(s2);
    int lesserLength = s1Length < s2Length ? s1Length : s2Length;
    int i;
    for(i = 0; i <= lesserLength; i++) {
        if(s1[i] < s2[i]) {
            return 1;
        } else if(s1[i] > s2[i]) {
            return -1;
        }
    }
    return 0;
}
char* Str_search(const char toSearch[], const char find[]) {
    assert(toSearch != NULL);
    assert(find != NULL);
    int searchLength = Str_getLength(toSearch);
    int findLength = Str_getLength(find);
    if(findLength == 0) {
        return toSearch;
    }
    int i, j;
    for(i = 0; i <= searchLength - findLength; i++) {
        int hasFound = 1;
        for(j = 0; j < findLength; j++) {
            if(toSearch[i + j] != find[j]) {
                hasFound = 0;
            }
        }
        if(hasFound) {
            return &toSearch[i];
        }
    }
    return NULL;
}
/*int main(int argc, char* argv[]) {
    printf("%zd", Str_getLength(""));
    char nullTerminatorTest[] = {'\0', 'a', '\0', '\0'};
    printf("%zd", strlen(nullTerminatorTest));
    printf("%zd", Str_getLength(nullTerminatorTest));
    printf("\n");
    char destination[10];
    char original[] = "abcdefghi";
    char compEqual[] = "abcdefghi";
    char compLessThanOriginalNormal[] = "aaaaaaaaa";
    char compLessThanOriginalShort[] = "abc";
    char compMoreThanOriginal[] = "zzzzzzzzz";
    char concatenator[] = "jklm";
    char dest2[13] = "abcdefghi";
    char toFind[] = "def";
    Str_copy(destination, original);
    printf(destination);
    Str_concat(concatenator, dest2);
    printf("\n");
    printf(concatenator);
    printf("\n");
    printf("%d", Str_compare(original, compEqual));
    printf("%d", Str_compare(original, compLessThanOriginalNormal));
    printf("%d", Str_compare(original, compLessThanOriginalShort));
    printf("%d", Str_compare(original, compMoreThanOriginal));
    printf("\n");
    printf("%c", *Str_search(original, toFind));
    printf("%p", Str_search(original, "qazzawazza"));
    printf("%c", *Str_search(original, "ghi"));
    printf("%c", *Str_search(original, "abc"));
    printf("%c", *Str_search(original, ""));
    printf("%c", *strstr(original, ""));
}*/
