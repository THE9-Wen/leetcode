#include <stdio.h>
#include <malloc/_malloc.h>
#include <string.h>

//
// Created by Wenhao on 2023/7/12.
//
char * mergeAlternately(char * word1, char * word2){
    char* result = malloc((strlen(word1) + strlen(word2) + 1) * sizeof(char));
    memset(result, '\0', (strlen(word1) + strlen(word2) + 1));
    int index = 0;
    while (*word1 != '\0' && *word2 != '\0') {
        result[index] = index % 2 ? *word2++ : *word1++;
        index++;
    }
    while (*word1 != '\0') {
        result[index++] = *word1++;
    }
    while (*word2 != '\0') {
        result[index++] = *word2++;
    }
    return result;
}

char * mergeAlternately_v2(char * word1, char * word2){
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    char* result = malloc( (length1 + length2 + 1) * sizeof(char));
    int index1 = 0, index2 = 0;
    while (index1 != length1 || index2 != length2) {
        if (index1 != length1) {
            result[index1 + index2] = word1[index1];
            index1++;
        }
        if (index2 != length2) {
            result[index1 + index2] = word2[index2];
            index2++;
        }
    }
    result[length1 + length2] = '\0';
    return result;
}

int main() {
    char * result = mergeAlternately_v2("hello", "world");
    printf("%s\n", result);
    return 0;
}
