#include <stdbool.h>

//
// Created by Wenhao on 2023/7/14.
//
/**
 * 超时
 * @param nums
 * @param numsSize
 * @return
 */
bool increasingTriplet(int* nums, int numsSize){
    for (int i = 0;i < numsSize;i++) {
        for (int j = i; j < numsSize;j++) {
            for (int k = j;k < numsSize;k++) {
                if (nums[i] < nums[j] && nums[j] < nums[k]) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * 依然超时
 * @param nums
 * @param numsSize
 * @return
 */
bool increasingTriplet_v2(int* nums, int numsSize){
    for (int i = 0;i < numsSize;i++) {
        for (int j = i; j < numsSize;j++) {
            if (nums[j] <= nums[i]) {
                continue;
            }
            for (int k = j;k < numsSize;k++) {
                if (nums[j] < nums[k]) {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 *
 * @param nums
 * @param numsSize
 * @return
 */
bool increasingTriplet_v3(int* nums, int numsSize){
    int max = nums[numsSize - 1];
    int min = nums[0];
    int minNums[numsSize];
    int maxNums[numsSize];
    for (int i = 1;i < numsSize;i++) {
        minNums[i] = min;
        min = nums[i] < min ? nums[i] : min;
    }
    for (int i = numsSize - 2;i > -1;i--) {
        maxNums[i] = max;
        max = max < nums[i] ? nums[i] : max;
    }
    for (int i = 1;i < numsSize - 1;i++) {
        if (nums[i] > minNums[i] && nums[i] < maxNums[i]) {
            return true;
        }
    }
    return false;
}

/**
 *
 * @param nums
 * @param numsSize
 * @return
 */
bool increasingTriplet_v4(int* nums, int numsSize){
    if (numsSize < 3) {
        return false;
    }
    int first = nums[0];
    int second = 2147483647;
    for (int i = 0;i < numsSize;i++) {
        if (nums[i] > second) {
            return true;
        }
        if (nums[i] > first) {
            second = nums[i];
        } else {
            first = nums[i];
        }
    }
    return false;
}

int main() {
    return 0;
}
