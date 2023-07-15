//
// Created by Wenhao on 2023/7/15.
//

#include <stdbool.h>
#include <string.h>

#ifndef LEETCODE_LEETCODE392_H
#define LEETCODE_LEETCODE392_H

#endif //LEETCODE_LEETCODE392_H

bool isSubsequence(char * s, char * t){
    int lengthS = strlen(s);
    int lengthT = strlen(t);
    if (lengthS == 0) {
        return true;
    }
    int index = 0;
    for (int i = 0;i < lengthT;i++) {
        if (s[index] == t[i]) {
            index++;
        }
        if (index == lengthS) {
            return true;
        }
    }
    return false;
}

bool isSubsequence_v2(char * s, char * t){
    int m = strlen(s);
    int n = strlen(t);
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == m;
}