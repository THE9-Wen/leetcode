//
// Created by Wenhao on 2023/7/15.
//

#include <string.h>
#include "leetcode345.h"

#ifndef LEETCODE_LEETCODE1456_H
#define LEETCODE_LEETCODE1456_H

#endif //LEETCODE_LEETCODE1456_H

int maxVowels(char * s, int k){
    int fast = 0;
    int slow = 0;
    int length = strlen(s);
    int count = 0;
    while (fast < k) {
        if (isVowel(s[fast])) {
            count++;
        }
        fast++;
    }
    int max = count;
    while (fast < length) {
        if (isVowel(s[fast])) {
            count++;
        }
        if (isVowel(s[slow])) {
            count--;
        }
        max = max < count ? count : max;
        fast++;
        slow++;
    }
    return max;
}