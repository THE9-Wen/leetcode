#include <string.h>
#include <malloc/_malloc.h>

//
// Created by Wenhao on 2023/7/12.
//
int gcd(int a, int b) {
    int remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}

char * gcdOfStrings(char * str1, char * str2){
    int lenght1 = strlen(str1);
    int length2 = strlen(str2);
    char *s1 = malloc(sizeof (char) * (lenght1 + length2 + 1));
    char *s2 = malloc(sizeof (char) * (lenght1 + length2 + 1));
    char *result = malloc(sizeof (char) * (lenght1 + length2 + 1));
    int i;
    strcpy(s1, str1);
    strcat(s1, str2);
    strcpy(s2, str2);
    strcpy(s2, str1);
    if (strcmp(s1, s2)) {
        return "";
    }
    int n = gcd(lenght1, length2);
    for (i = 0; i < n; i++) {
        result[i] = str1[i];
    }
    result[i] = '\0';
    return result;
}

int main() {
    return 0;
}
