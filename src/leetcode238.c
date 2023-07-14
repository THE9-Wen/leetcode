//
// Created by Wenhao on 2023/7/14.
//

#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int left[numsSize];
    left[0] = 1;
    int right[numsSize];
    right[numsSize - 1] = 1;
    for (int i = 1;i < numsSize;i++) {
        left[i] = left[i - 1] * nums[i - 1];
        right[numsSize - i - 1] = right[numsSize - i] * nums[numsSize - i];
    }
    for (int i = 0;i < numsSize;i++) {
        nums[i] = left[i] * right[i];
    }
    *returnSize = numsSize;
    return nums;
}

int main() {
    return 0;
}
