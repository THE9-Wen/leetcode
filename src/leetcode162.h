//
// Created by Wenhao on 2023/7/16.
//

#ifndef LEETCODE_LEETCODE162_H
#define LEETCODE_LEETCODE162_H

#endif //LEETCODE_LEETCODE162_H

int findPeakElement(int* nums, int numsSize){
    if (numsSize == 1 || nums[0] > nums[1]) {
        return 0;
    }
    for (int i = 1;i < numsSize - 1;i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            return i;
        }
    }
    if (nums[numsSize - 1] > nums[numsSize - 2]) {
        return numsSize - 1;
    }
    return -1;
}

/**
 * 如果是上升趋势则上升的那一侧一定有峰
 * @param nums
 * @param numsSize
 * @return
 */
int findPeakElement_v2(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}