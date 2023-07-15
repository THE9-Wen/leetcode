//
// Created by Wenhao on 2023/7/15.
//

#include <stdlib.h>

#ifndef LEETCODE_LEETCODE1679_H
#define LEETCODE_LEETCODE1679_H

#endif //LEETCODE_LEETCODE1679_H

void swap(int * value1, int * value2) {
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

/**
 * 使用自己实现的快排可能会超时
 * @param nums
 * @param start
 * @param end
 */
void quickSort(int *nums, int start, int end) {
    if (start >= end) {
        return;
    }
    int left = start;
    int right = end;
    int r = rand() % (end - start + 1) + start;
    swap(&nums[r], &nums[start]);
    int polar = nums[start];
    while (left < right) {
        // 从右边开始找到第一个严格小于polar的值
        while (left < right && polar <= nums[right]) {
            right--;
        }
        nums[left] = nums[right];
        // 从左边开始找到第一个严格大于polar的值
        while (left < right && polar >= nums[left]) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = polar;
    quickSort(nums, start, left - 1);
    quickSort(nums, right + 1, end);
}

int maxOperations(int* nums, int numsSize, int k){
    quickSort(nums, 0, numsSize - 1);
    int left = 0;
    int right = numsSize - 1;
    int result = 0;
    while (left < right) {
        if (nums[left] + nums[right] == k) {
            result++;
            left++;
            right--;
        } else if (nums[left] + nums[right] < k) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}