#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

//
// Created by Wenhao on 2023/7/13.
//
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize) {
    *returnSize = candiesSize;
    bool *result = (bool *) malloc(sizeof(bool) * candiesSize);
    int max = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies < max) {
            result[i] = false;
        } else {
            result[i] = true;
        }
    }
    return result;
}


